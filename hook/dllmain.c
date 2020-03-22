// dllmain.cpp : Defines the entry point for the DLL application.

#include "pch.h"
#include <stdio.h>

HANDLE(*OriginalCreateFileW)(LPCWSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE) = NULL;
BOOL(*OriginalDeviceIoControl)(HANDLE, DWORD, LPVOID, DWORD, LPVOID, DWORD, LPDWORD, LPOVERLAPPED) = NULL;

HANDLE fdd_driver_handle = (void *)0x80000001;
HANDLE hw_monitor_handle = (void *)0x80000002;

HANDLE __stdcall ProxyCreateFileW(LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile) {    
	if (!wcscmp(lpFileName, L"\\??\\FddDriver")) {
        wprintf(L"Returning fake handle for access of %ls\n", lpFileName);
        return fdd_driver_handle;
	} else if (!wcscmp(lpFileName, L"\\\\.\\sghwmonitor")) {
        wprintf(L"Returning fake handle for access of %ls\n", lpFileName);
        return hw_monitor_handle;
	}
	return OriginalCreateFileW(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
}

BOOL __stdcall ProxyDeviceIoControl(HANDLE hDevice, DWORD dwIoControlCode, LPVOID lpInBuffer, DWORD nInBufferSize, LPVOID lpOutBuffer, DWORD nOutBufferSize, LPDWORD lpBytesReturned, LPOVERLAPPED lpOverlapped) {
	if (hDevice == fdd_driver_handle) {
        printf("Received IO Control for FddDriver, code 0x%lx, input size %ld, output size %ld\n", dwIoControlCode, nInBufferSize, nOutBufferSize);
        SetEvent(lpOverlapped->hEvent);
        if (lpBytesReturned) {
            *lpBytesReturned = 0;
        }
        SetLastError(ERROR_IO_PENDING);
        return 0;
	} else if (hDevice == hw_monitor_handle) {
		printf("Received IO Control for sghwmonitor, code 0x%lx, input size %ld, output size %ld\n", dwIoControlCode, nInBufferSize, nOutBufferSize);
        *(int*)lpOutBuffer = 42;
        *lpBytesReturned = 4;
        return 1;
	}
    return OriginalDeviceIoControl(hDevice, dwIoControlCode, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesReturned, lpOverlapped);
}

BOOL __stdcall main_serial(LPSTR lpBuffer, LPDWORD nSize) {
    *nSize = 15;
    strcpy(lpBuffer, "ACAE01234567890");
    return 1;
}

void __stdcall local_debug_log_w(LPCWSTR str) {
    wprintf(L"%ls", str);
}

void __stdcall log_version(char* version) {
    printf("%s", version);
}

void patch_winapi(const char *module, const char *proc, void (*func)) {
    FARPROC addr = GetProcAddress(LoadLibraryA(module), proc);
    DWORD prot;
    VirtualProtect(addr, 14, PAGE_EXECUTE_READWRITE, &prot);
    *((char*)addr) = '\x68';
    *(int*)((char*)addr + 1) = (int)func;
    *((char*)addr + 5) = '\xc7';
    *((char*)addr + 6) = '\x44';
    *((char*)addr + 7) = '\x24';
    *((char*)addr + 8) = '\x04';
    *(int*)((char*)addr + 9) = (int)((long long)func >> 32);
    *((char*)addr + 0x0D) = '\xc3';
    printf("+%llX: ", addr);
    for (int i = 0; i < 16; i++) {
        printf("%02hhX ", *((char*)addr + i));
    }
    printf("\n");
    VirtualProtect(addr, 14, prot, &prot);
}

void patch_log(HMODULE module, int offset, void(*func)) {
    DWORD prot;
    VirtualProtect(module + offset / 4, 14, PAGE_EXECUTE_READWRITE, &prot);
    *((char*)module + offset) = '\x68';
    *(int*)((char*)module + offset + 1) = (int)func;
    *((char*)module + offset + 5) = '\xc7';
    *((char*)module + offset + 6) = '\x44';
    *((char*)module + offset + 7) = '\x24';
    *((char*)module + offset + 8) = '\x04';
    *(int*)((char*)module + offset + 9) = (int)((long long)func >> 32);
    *((char*)module + offset + 0x0D) = '\xc3';
    printf("+%X: ", offset);
	for (int i = 0; i < 16; i ++) {
        printf("%02hhX ", *((char*)module + offset + i));
	}
    printf("\n");
    VirtualProtect(module + offset, 14, prot, &prot);
}

void enable_log(HMODULE module, int offset) {
    printf("+%X: %d\n", offset, *(int*)((char*)module + offset));
    *(int*)((char*)module + offset) = 1;
    printf("+%X: %d\n", offset, *(int*)((char*)module + offset));
}

void hook_import(HMODULE self, const char *module, const char *proc, void (*func), void *(*original)) {
    int import_dir_offset = 0x74F7AC;
    int import_desc_size = sizeof(struct _IMAGE_IMPORT_DESCRIPTOR);
    int import_count = 0x1CC / import_desc_size;
	for (int i = 0; i < import_count; i ++) {
        struct _IMAGE_IMPORT_DESCRIPTOR* descriptor = (struct _IMAGE_IMPORT_DESCRIPTOR*)((char*)self + import_dir_offset + i * import_desc_size);
		if (!strcmp((char *)self + descriptor->Name, module)) {
            void* oft = (void *)((char *)self + descriptor->OriginalFirstThunk);
            int order = 0;
			while (*((long long *)oft + order) != 0) {
				if (*((long long*)oft + order) >> 63) {
                    continue;
				}
				if (!strcmp((char*)self + *((long long*)oft + order) + 2, proc)) {
                    void** orig = (void **)((char *)self + descriptor->FirstThunk + order * 8);
                    *original = *orig;
                    DWORD prot;
                    VirtualProtect(orig, 8, PAGE_EXECUTE_READWRITE, &prot);
                    *orig = func;
                    VirtualProtect(orig, 8, prot, &prot);
                    printf("Hooked %s\n", proc);
                    return;
				}
                order += 1;
			}
            printf("Failed to find %s in %s!\n", proc, module);
		}
	}
    printf("Failed to find import %s!\n", module);
}

void run() {
    HMODULE module = GetModuleHandleA("amdaemon.exe");
    printf("Module: %p\n", module);
    printf("Patching log flags...\n");
    for (int i = 0x8A06E0; i <= 0x8A072C; i += 4) {
    	if (i == 0x8A06FC) {
            continue; // don't load amsTimer
    	}
        enable_log(module, i);
    }
    enable_log(module, 0x827E08);
    enable_log(module, 0x827E0C);
    enable_log(module, 0x828080);
    enable_log(module, 0x8283F0);
    enable_log(module, 0x828430);
    printf("Patching null logs...\n");
    patch_log(module, 0x274080, &log_version);
    printf("Patching Windows API...\n");
    patch_winapi("kernel32.dll", "OutputDebugStringW", &local_debug_log_w);
    patch_winapi("kernel32.dll", "GetComputerNameA", &main_serial);
    printf("Hooking Windows API...\n");
    hook_import(module, "KERNEL32.dll", "CreateFileW", &ProxyCreateFileW, &OriginalCreateFileW);
    hook_import(module, "KERNEL32.dll", "DeviceIoControl", &ProxyDeviceIoControl, &OriginalDeviceIoControl);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        printf("Hook DLL Loaded\n");
        run();
        break;
    case DLL_THREAD_ATTACH:
        // printf("DLL_THREAD_ATTACH\n");
        // break;
    case DLL_THREAD_DETACH:
        // printf("DLL_THREAD_DETACH\n");
        // break;
    case DLL_PROCESS_DETACH:
        // printf("DLL_PROCESS_DETACH\n");
        break;
    }
    return TRUE;
}