// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <cstdio>

void __stdcall local_debug_log_w(LPCWSTR str) {
    wprintf(L"%ls", str);
}

void __stdcall log_version(char* version) {
    printf("%s", version);
}

void patch_winapi(const char *library, const char *proc, void (*func)) {
    FARPROC addr = GetProcAddress(LoadLibraryA(library), proc);
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
    DWORD unused;
    VirtualProtect(module + offset, 14, prot, &unused);
}

void enable_log(HMODULE module, int offset) {
    printf("+%X: %d\n", offset, *(int*)((char*)module + offset));
    *(int*)((char*)module + offset) = 1;
    printf("+%X: %d\n", offset, *(int*)((char*)module + offset));
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
    enable_log(module, 0x8283F0);
    enable_log(module, 0x828430);
    printf("Patching null logs...\n");
    patch_log(module, 0x274080, &log_version);
    printf("Patching Windows API...\n");
    patch_winapi("kernel32.dll", "OutputDebugStringW", &local_debug_log_w);
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