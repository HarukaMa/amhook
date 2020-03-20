
// ReSharper disable All
#include <stdio.h>
#include <windows.h>

int main() {
	STARTUPINFOA *startup_info = (STARTUPINFOA *)malloc(sizeof(STARTUPINFOA));
	memset(startup_info, 0, sizeof(STARTUPINFOA));
	PROCESS_INFORMATION *process_info = (PROCESS_INFORMATION *)malloc(sizeof(PROCESS_INFORMATION));
	BOOL create = CreateProcessA(
		"amdaemon.exe",
		NULL,
		NULL,
		NULL,
		0,
		CREATE_SUSPENDED,
		NULL,
		NULL,
		startup_info,
		process_info
	);
	printf("Create process: %d\n", create);
	if (create) {
		printf("handle: %p\n", process_info->hProcess);
		FARPROC load_library = GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA");
		const char* dll = "hook.dll";
		LPVOID ptr = VirtualAllocEx(process_info->hProcess, NULL, strlen(dll), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
		BOOL res = WriteProcessMemory(process_info->hProcess, ptr, dll, strlen(dll), NULL);
		HANDLE thread = CreateRemoteThread(process_info->hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)load_library, ptr, NULL, NULL);
		printf("Create thread: %p\n", thread);
		if (!thread) {
			int error = GetLastError();
			printf("Error: %d\n", error);
		}
		Sleep(100);
		ResumeThread(process_info->hThread);
		WaitForSingleObject(process_info->hProcess, INFINITE);
	} else {
		int error = GetLastError();
		printf("Error: %d\n", error);
	}
}