// dllmain.cpp : Defines the entry point for the DLL application.

#include "pch.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <SetupAPI.h>
#include <hidclass.h>
#include <winioctl.h>
#include <hidusage.h>

#include <detours.h>

LARGE_INTEGER qpcf;

HANDLE (*OriginalCreateFileW)(LPCWSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE) = NULL;
HANDLE (*OriginalCreateFileA)(LPCSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE) = NULL;
BOOL (*OriginalCloseHandle)(HANDLE) = NULL;
BOOL (*OriginalReadFile)(HANDLE, LPVOID, DWORD, LPDWORD, LPOVERLAPPED) = NULL;
BOOL (*OriginalWriteFile)(HANDLE, LPVOID, DWORD, LPDWORD, LPOVERLAPPED) = NULL;
BOOL (*OriginalGetOverlappedResult)(HANDLE, LPOVERLAPPED, LPDWORD, BOOL) = NULL;
BOOL (*OriginalDeviceIoControl)(HANDLE, DWORD, LPVOID, DWORD, LPVOID, DWORD, LPDWORD, LPOVERLAPPED) = NULL;

HANDLE fdd_driver_handle = (void*)0x10000001;
HANDLE hw_monitor_handle = (void*)0x10000002;
HANDLE usbio_handle = (void*)0x10000003;

HANDLE com1_handle = (void*)0x11000001;
HANDLE com2_handle = (void*)0x11000002;

HDEVINFO com_devinfo = (void*)0x20000001;

LPVOID com1_buffer = NULL;
unsigned int com1_length = 0;

#pragma pack (1)
struct usbio_state_st {
    uint8_t check;
    uint16_t analog;
    uint8_t unknown[26];
    uint8_t L1 : 1; // 29
    uint8_t R1 : 1;
    uint8_t system_switch_player_0_02 : 1;
    uint8_t system_switch_player_0_03 : 1;
    uint8_t L3 : 1;
    uint8_t L2 : 1;
    uint8_t SERVICE : 1;
    uint8_t system_switch_player_0_07 : 1;
    uint8_t system_switch_player_0_08 : 1; // 30
    uint8_t TEST : 1;
    uint8_t system_switch_player_0_10 : 1;
    uint8_t system_switch_player_0_11 : 1;
    uint8_t system_switch_player_0_12 : 1;
    uint8_t RMENU : 1;
    uint8_t RSIDE : 1;
    uint8_t R3 : 1;
    uint8_t unknown3[2];
    uint8_t system_status; // 33
    uint8_t usb_status; // 34
    uint8_t unknown2[29];
};

struct usbio_state_st usbio_state = {
    .check = 1,
    .analog = 0x8000,
    .RSIDE = 1,
};

LPVOID usbio_read_buffer = NULL;
LARGE_INTEGER usbio_request_time;

void dump_hex(void* buffer, const int size) {
    printf("        00 01 02 03 04 05 06 07  08 09 0A 0B 0C 0D 0E 0F\n");
    int i;
    char ascii[17] = {0};
    for (i = 0; i < size; i ++) {
        if (i % 16 == 0) {
            printf("0x%04X: ", i);
        }
        uint8_t value = *((uint8_t*)buffer + i);
        printf("%02hhX ", value);
        if (value >= 0x20 && value <= 0x7E) {
            ascii[i % 16] = value;
        } else {
            ascii[i % 16] = '.';
        }
        if (i % 16 == 7) {
            printf(" ");
        }
        if (i % 16 == 15) {
            printf(" %s\n", ascii);
            memset(ascii, 0, 16);
        }
    }
    if (i % 16 != 0) {
        while (i % 16 != 0) {
            printf("   ");
            if (i % 16 == 7) {
                printf(" ");
            }
            i++;
        }
        printf(" %s\n", ascii);
    }
}

HANDLE ProxyCreateFileW(LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode,
                        LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition,
                        DWORD dwFlagsAndAttributes, HANDLE hTemplateFile) {
    HANDLE fake_handle = NULL;
    if (!wcscmp(lpFileName, L"\\??\\FddDriver")) {
        fake_handle = fdd_driver_handle;
    } else if (!wcscmp(lpFileName, L"\\\\.\\sghwmonitor")) {
        fake_handle = hw_monitor_handle;
    } else if (!wcscmp(lpFileName, L"usb\\vid_0ca3&pid_0000")) {
        fake_handle = usbio_handle;
    }
    if (fake_handle) {
        wprintf(L"CreateFileW Returning fake handle for %ls\n", lpFileName);
        return fake_handle;
    }
    HANDLE handle = OriginalCreateFileW(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes,
                                        dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
    wprintf(L"CreateFileW Returning handle %p for %ls\n", handle, lpFileName);
    return handle;
}

HANDLE ProxyCreateFileA(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode,
                        LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition,
                        DWORD dwFlagsAndAttributes, HANDLE hTemplateFile) {
    HANDLE fake_handle = NULL;
    if (!strcmp(lpFileName, "\\\\.\\COM1")) {
        fake_handle = com1_handle;
    }
    if (!strcmp(lpFileName, "\\\\.\\COM2")) {
        fake_handle = com2_handle;
    }
    if (fake_handle) {
        printf("CreateFileA Returning fake handle for %s\n", lpFileName);
        return fake_handle;
    }
    HANDLE handle = OriginalCreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes,
                                        dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
    printf("CreateFileA Returning handle %p for %s\n", handle, lpFileName);
    return handle;
}

BOOL ProxyCloseHandle(HANDLE hObject) {
    if (hObject == fdd_driver_handle) {
        printf("Close fdd driver handle\n");
        return 1;
    }
    if (hObject == hw_monitor_handle) {
        printf("Close hw monitor handle\n");
        return 1;
    }
    if (hObject == usbio_handle) {
        printf("Close usbio handle\n");
        return 1;
    }
    if (hObject == com1_handle) {
        printf("Close COM1 handle\n");
        return 1;
    }
    if (hObject == com2_handle) {
        printf("Close COM2 handle\n");
        return 1;
    }
    // printf("Closing handle %p\n", hObject);
    return OriginalCloseHandle(hObject);
}

BOOL ProxyReadFile(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, LPDWORD lpNumberOfBytesRead,
                   LPOVERLAPPED lpOverlapped) {
    if (hFile == usbio_handle) {
        // printf("Read from usbio, size %lu\n", nNumberOfBytesToRead);
        if (lpOverlapped) {
            usbio_read_buffer = lpBuffer;
            QueryPerformanceCounter(&usbio_request_time);
            SetLastError(ERROR_IO_PENDING);
            return 0;
        }
        *lpNumberOfBytesRead = 0x40;
        uint8_t result[0x40] = {0};
        result[0] = 1;
        memcpy(lpBuffer, result, 0x40);
        return 1;
    }
    if (hFile == com1_handle) {
        // printf("Read from COM1, size %lu\n", nNumberOfBytesToRead);
        if (nNumberOfBytesToRead < com1_length) {
            SetLastError(ERROR_INSUFFICIENT_BUFFER);
            return 0;
        }
        *lpNumberOfBytesRead = com1_length;
        memcpy(lpBuffer, com1_buffer, com1_length);
        free(com1_buffer);
        com1_length = 0;
        return 1;
    }
    if (hFile == com2_handle) {
        printf("Read from COM2, size %lu\n", nNumberOfBytesToRead);
        *lpNumberOfBytesRead = nNumberOfBytesToRead;
        memset(lpBuffer, 0, nNumberOfBytesToRead);
        return 1;
    }
    return OriginalReadFile(hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped);
}

unsigned char com_checksum(unsigned char* buffer, int length) {
    unsigned char result = 0;
    for (int i = 0; i < length; i ++) {
        result += buffer[i];
    }
    return result;
}

void create_com_packet(unsigned char* buffer, int length) {
    unsigned char res[1024] = {0};
    res[0] = 0xE0;
    unsigned char* ptr = &res[1];
    for (int i = 0; i < length; i ++) {
        if (buffer[i] == 0xD0 || buffer[i] == 0xE0) {
            *ptr++ = 0xD0;
            *ptr++ = buffer[i] - 1;
        } else {
            *ptr++ = buffer[i];
        }
    }
    unsigned char checksum = com_checksum(buffer, length);
    if (checksum == 0xD0 || checksum == 0xE0) {
        *ptr++ = 0xD0;
        *ptr = checksum - 1;
    } else {
        *ptr = checksum;
    }
    com1_length = ptr - res + 1;
    com1_buffer = malloc(com1_length);
    memcpy(com1_buffer, res, com1_length);
}

BOOL ProxyWriteFile(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten,
                    LPOVERLAPPED lpOverlapped) {
    if (hFile == usbio_handle) {
        printf("Write to usbio, size %lu, ", nNumberOfBytesToWrite);
        *lpNumberOfBytesWritten = 0x40;
        switch (((uint8_t*)lpBuffer)[1]) {
        case 1:
            printf("SetCommTimeout %hhu\n", ((uint8_t*)lpBuffer)[2]);
            break;
        case 2:
            printf("SetSamplingCount %hhu\n", ((uint8_t*)lpBuffer)[2]);
            break;
        case 3:
            printf("ClearBoardStatus\n");
            break;
        case 4:
            printf("SetGeneralOutput\n");
            dump_hex(lpBuffer, nNumberOfBytesToWrite);
            break;
        case 5:
            printf("SetPwmOutput\n");
            dump_hex(lpBuffer, nNumberOfBytesToWrite);
            break;
        case 0x84:
            printf("RequestChangeBootMode\n");
            dump_hex(lpBuffer, nNumberOfBytesToWrite);
            break;
        case 0x85:
            printf("UpdateFirmware\n");
            dump_hex(lpBuffer, nNumberOfBytesToWrite);
            break;
        case 0x88:
            printf("Reset %hhu\n", ((uint8_t*)lpBuffer)[2]);
            break;
        default:
            printf("Unique Command %hhu\n", ((uint8_t*)lpBuffer)[1]);
        }
        return 1;
    }
    if (hFile == com1_handle) {
        // printf("Write to COM1, size %lu\n", nNumberOfBytesToWrite);
        *lpNumberOfBytesWritten = nNumberOfBytesToWrite;
        unsigned char recv[1024] = {0};
        unsigned char* ptr = recv;
        for (int i = 0; i < nNumberOfBytesToWrite; i ++) {
            if (((unsigned char*)lpBuffer)[i] == 0xD0) {
                *ptr++ = ((unsigned char*)lpBuffer)[i + 1] + 1;
                i++;
            } else {
                *ptr++ = ((unsigned char*)lpBuffer)[i];
            }
        }
        if (recv[2] == 0) {
            unsigned char cmd = recv[4];
            unsigned char buf[1024] = {0};
            switch (cmd) {
            case 0x30:
                dump_hex(lpBuffer, nNumberOfBytesToWrite);
                printf("Get FW version\n");
                buf[0] = 29;
                buf[1] = 0;
                buf[2] = recv[3];
                buf[3] = cmd;
                buf[4] = 0;
                buf[5] = 23;
                memcpy(&buf[6], "TN32MSEC003S F/W Ver1.2", 23);
                create_com_packet(buf, 29);
                break;
            case 0x32:
                dump_hex(lpBuffer, nNumberOfBytesToWrite);
                printf("Get HW version\n");
                buf[0] = 29;
                buf[1] = 0;
                buf[2] = recv[3];
                buf[3] = cmd;
                buf[4] = 0;
                buf[5] = 23;
                memcpy(&buf[6], "TN32MSEC003S H/W Ver3.0", 23);
                create_com_packet(buf, 29);
                break;
            case 0x50:
                dump_hex(lpBuffer, nNumberOfBytesToWrite);
                printf("Set Banapass key\n");
                buf[0] = 6;
                buf[1] = 0;
                buf[2] = recv[3];
                buf[3] = cmd;
                buf[4] = 0;
                buf[5] = 0;
                create_com_packet(buf, 6);
                break;
            case 0x54:
                dump_hex(lpBuffer, nNumberOfBytesToWrite);
                printf("Set Aime key\n");
                buf[0] = 6;
                buf[1] = 0;
                buf[2] = recv[3];
                buf[3] = cmd;
                buf[4] = 0;
                buf[5] = 0;
                create_com_packet(buf, 6);
                break;
            case 0x60:
                printf("Unknown NFC command 0x60!\n");
                buf[0] = 6;
                buf[1] = 0;
                buf[2] = recv[3];
                buf[3] = cmd;
                buf[4] = 0;
                buf[5] = 0;
                create_com_packet(buf, 6);
            case 0x61:
                printf("Flash firmware\n");
                buf[0] = 6;
                buf[1] = 0;
                buf[2] = recv[3];
                buf[3] = cmd;
                buf[4] = 0;
                buf[5] = 0;
                create_com_packet(buf, 6);
                break;
            case 0x62:
                printf("Reset\n");
                buf[0] = 6;
                buf[1] = 0;
                buf[2] = recv[3];
                buf[3] = cmd;
                buf[4] = 0;
                buf[5] = 0;
                create_com_packet(buf, 6);
                break;
            default:
                dump_hex(lpBuffer, nNumberOfBytesToWrite);
                printf("Unknown NFC command 0x%hhX!\n", cmd);
                buf[0] = 5;
                buf[1] = 0;
                buf[2] = recv[3];
                buf[3] = cmd;
                buf[4] = 1;
                buf[5] = 0;
                create_com_packet(buf, 6);
            }
        }

        return 1;
    }
    if (hFile == com2_handle) {
        printf("Write to COM2, size %lu\n", nNumberOfBytesToWrite);
        *lpNumberOfBytesWritten = nNumberOfBytesToWrite;
        dump_hex(lpBuffer, nNumberOfBytesToWrite);
        return 1;
    }
    return OriginalWriteFile(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, lpOverlapped);
}

BOOL ProxyGetOverlappedResult(HANDLE hFile, LPOVERLAPPED lpOverlapped, LPDWORD lpNumberOfBytesTransferred, BOOL bWait) {
    if (hFile == usbio_handle) {
        // printf("Get overlapped result from usbio\n");
        LARGE_INTEGER current_counter;
        QueryPerformanceCounter(&current_counter);
        if ((current_counter.QuadPart - usbio_request_time.QuadPart) * 1000 / qpcf.QuadPart < 3) {
            SetLastError(ERROR_IO_INCOMPLETE);
            return 0;
        }
        *lpNumberOfBytesTransferred = 0x40;
        memcpy(usbio_read_buffer, &usbio_state, 0x40);
        return 1;
    }
    return OriginalGetOverlappedResult(hFile, lpOverlapped, lpNumberOfBytesTransferred, bWait);
}

BOOL ProxyDeviceIoControl(HANDLE hDevice, DWORD dwIoControlCode, LPVOID lpInBuffer, DWORD nInBufferSize,
                          LPVOID lpOutBuffer, DWORD nOutBufferSize, LPDWORD lpBytesReturned,
                          LPOVERLAPPED lpOverlapped) {
    if (hDevice == fdd_driver_handle) {
        printf("Received IO Control for FddDriver, code 0x%lx, input size %ld, output size %ld\n", dwIoControlCode,
               nInBufferSize, nOutBufferSize);
        SetEvent(lpOverlapped->hEvent);
        if (lpBytesReturned) {
            *lpBytesReturned = 0;
        }
        SetLastError(ERROR_IO_PENDING);
        return 0;
    }
    if (hDevice == hw_monitor_handle) {
        printf("Received IO Control for sghwmonitor, code 0x%lx, input size %ld, output size %ld\n", dwIoControlCode,
               nInBufferSize, nOutBufferSize);
        *(int*)lpOutBuffer = 42;
        *lpBytesReturned = 4;
        return 1;
    }
    if (hDevice == usbio_handle) {
        printf("Received IO Control for usbio, code 0x%lx, input size %ld, output size %ld\n", dwIoControlCode,
               nInBufferSize, nOutBufferSize);
        if (dwIoControlCode == IOCTL_HID_GET_MANUFACTURER_STRING) {
            wcscpy_s(lpOutBuffer, nOutBufferSize / 2, L"SEGA");
            *lpBytesReturned = 10;
            SetLastError(ERROR_SUCCESS);
            return 1;
        }
        if (dwIoControlCode == IOCTL_HID_GET_PRODUCT_STRING) {
            wchar_t* product = L"I/O CONTROL BD;1;2;3;4;5;0;GOUT=14_PWMOUT=0_ADIN=1,A_ROTIN=0_COININ=1_SWIN=2,C";
            wcscpy_s(lpOutBuffer, nOutBufferSize / 2, product);
            *lpBytesReturned = wcslen(product) * 2;
            SetLastError(ERROR_SUCCESS);
            return 1;
        }
        SetLastError(ERROR_BAD_ARGUMENTS);
        return 0;
    }
    printf("Received IO Control for handle %p, code 0x%lx, input size %ld, output size %ld\n", hDevice, dwIoControlCode,
           nInBufferSize, nOutBufferSize);
    return OriginalDeviceIoControl(hDevice, dwIoControlCode, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize,
                                   lpBytesReturned, lpOverlapped);
}

BOOL FakeSetupDiEnumDeviceInterfaces(HDEVINFO DeviceInfoSet, PSP_DEVINFO_DATA DeviceInfoData,
                                     const GUID* InterfaceClassGuid, DWORD MemberIndex,
                                     PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData) {
    printf("SetupDiEnumDeviceInterfaces, index %lu\n", MemberIndex);
    if (MemberIndex > 0) {
        SetLastError(ERROR_NO_MORE_ITEMS);
        return 0;
    }
    DeviceInterfaceData->Flags = SPINT_ACTIVE;
    GUID guid;
    memcpy(&guid, InterfaceClassGuid, sizeof(GUID));
    DeviceInterfaceData->InterfaceClassGuid = guid;
    SetLastError(ERROR_SUCCESS);
    return 1;
}

BOOL FakeSetupDiGetDeviceInterfaceDetailW(HDEVINFO DeviceInfoSet, PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData,
                                          PSP_DEVICE_INTERFACE_DETAIL_DATA_W DeviceInterfaceDetailData,
                                          DWORD DeviceInterfaceDetailDataSize, PDWORD RequiredSize,
                                          PSP_DEVINFO_DATA DeviceInfoData) {
    printf("SetupDiGetDeviceInterfaceDetailW\n");
    if (DeviceInterfaceDetailData == NULL) {
        SetLastError(ERROR_INSUFFICIENT_BUFFER);
        *RequiredSize = 48;
        return 0;
    }
    wcscpy_s(DeviceInterfaceDetailData->DevicePath, 22, L"USB\\VID_0CA3&PID_0000\0");
    SetLastError(ERROR_SUCCESS);
    return 1;
}

HDEVINFO FakeSetupDiGetClassDevsA(const GUID* ClassGuid, PCSTR Enumerator, HWND hwndParent, DWORD Flags) {
    if (!memcmp(&GUID_DEVINTERFACE_COMPORT, ClassGuid, 16)) {
        printf("FakeSetupDiGetClassDevsA COMPORT\n");
        return com_devinfo;
    }
    printf("FakeSetupDiGetClassDevsA Unknown class!\n");
    return INVALID_HANDLE_VALUE;
}

BOOL FakeSetupComm(HANDLE hFile, DWORD dwInQueue, DWORD dwOutQueue) {
    if (hFile == com1_handle) {
        printf("SetupComm COM1, buffer in %lu, out %lu\n", dwInQueue, dwOutQueue);
        return 1;
    }
    if (hFile == com2_handle) {
        printf("SetupComm COM2, buffer in %lu, out %lu\n", dwInQueue, dwOutQueue);
        return 1;
    }
    printf("SetupComm %p but not handled!\n", hFile);
    return 0;
}

BOOL FakeGetCommState(HANDLE hFile, LPDCB lpDCB) {
    if (hFile == com1_handle) {
        printf("GetCommState COM1\n");
        lpDCB->BaudRate = 9600;
        lpDCB->fBinary = 1;
        lpDCB->fParity = 0;
        lpDCB->fOutxCtsFlow = 0;
        lpDCB->fOutxDsrFlow = 0;
        lpDCB->fDtrControl = DTR_CONTROL_DISABLE;
        lpDCB->ByteSize = 8;
        lpDCB->Parity = NOPARITY;
        lpDCB->StopBits = ONESTOPBIT;
        return 1;
    }
    if (hFile == com2_handle) {
        printf("GetCommState COM2\n");
        lpDCB->BaudRate = 9600;
        lpDCB->fBinary = 1;
        lpDCB->fParity = 0;
        lpDCB->fOutxCtsFlow = 0;
        lpDCB->fOutxDsrFlow = 0;
        lpDCB->fDtrControl = DTR_CONTROL_DISABLE;
        lpDCB->ByteSize = 8;
        lpDCB->Parity = NOPARITY;
        lpDCB->StopBits = ONESTOPBIT;
        return 1;
    }
    printf("GetCommState %p but not handled!\n", hFile);
    return 0;
}

BOOL FakeSetCommState(HANDLE hFile, LPDCB lpDCB) {
    if (hFile == com1_handle) {
        printf("SetCommState COM1\n");
        return 1;
    }
    if (hFile == com2_handle) {
        printf("SetCommState COM2\n");
        return 1;
    }
    printf("GetCommState %p but not handled!\n", hFile);
    return 0;
}

BOOL FakeSetCommTimeouts(HANDLE hFile, LPCOMMTIMEOUTS lpCommTimeouts) {
    if (hFile == com1_handle || hFile == com2_handle) {
        if (hFile == com1_handle) {
            printf("SetCommTimeouts COM1, ");
        } else if (hFile == com2_handle) {
            printf("SetCommTimeouts COM2, ");
        }
        printf("read interval %lu, read timeout %lu x %lu, write timeout %lu x %lu\n",
               lpCommTimeouts->ReadIntervalTimeout, lpCommTimeouts->ReadTotalTimeoutConstant,
               lpCommTimeouts->ReadTotalTimeoutMultiplier,
               lpCommTimeouts->WriteTotalTimeoutConstant, lpCommTimeouts->WriteTotalTimeoutMultiplier);
        return 1;
    }
    printf("SetCommTimeouts %p but not handled!\n", hFile);
    return 0;
}

BOOL FakePurgeComm(HANDLE hFile, DWORD dwFlags) {
    if (hFile == com1_handle) {
        printf("PurgeComm COM1, flags %lu\n", dwFlags);
        return 1;
    }
    if (hFile == com2_handle) {
        printf("PurgeComm COM2, flags %lu\n", dwFlags);
        return 1;
    }
    printf("PurgeComm %p but not handled!\n", hFile);
    return 0;
}

BOOL FakeClearCommError(HANDLE hFile, LPDWORD lpErrors, LPCOMSTAT lpStat) {
    if (hFile == com1_handle || hFile == com2_handle) {
        if (hFile == com1_handle) {
            // printf("ClearCommError COM1\n");
            lpStat->cbInQue = com1_length;
        } else if (hFile == com2_handle) {
            printf("ClearCommError COM2\n");
        }
        *lpErrors = 0;
        lpStat->fCtsHold = 0;
        lpStat->fDsrHold = 0;
        lpStat->fRlsdHold = 0;
        lpStat->fXoffHold = 0;
        lpStat->fXoffSent = 0;
        lpStat->fEof = 0;
        lpStat->fTxim = 0;
        lpStat->cbOutQue = 0;
        return 1;
    }
    printf("ClearCommError %p but not handled!\n", hFile);
    return 0;
}

BOOL main_serial(LPSTR lpBuffer, LPDWORD nSize) {
    *nSize = 15;
    strcpy(lpBuffer, "ACAE01234567890");
    return 1;
}

void local_debug_log_w(LPCWSTR str) {
    wprintf(L"%ls", str);
}

void log_version(char* version) {
    printf("%s", version);
}

int32_t null_int32_0() {
    return 0;
}

int32_t null_int32_3() {
    return 3;
}

void patch_winapi(const char* module, const char* proc, void (*func)) {
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
    /*printf("+%llX: ", addr);
    for (int i = 0; i < 16; i++) {
        printf("%02hhX ", *((char*)addr + i));
    }
    printf("\n");*/
    printf("Replaced %s\n", proc);
    VirtualProtect(addr, 14, prot, &prot);
}

void patch_func(HMODULE module, int offset, void (*func)) {
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
    int prev = *(int*)((char*)module + offset);
    *(int*)((char*)module + offset) = 3;
    printf("+%X: %d -> %d\n", offset, prev, *(int*)((char*)module + offset));
}

void hook_import(HMODULE self, const char* module, const char* proc, void (*func), void*(*original)) {
    int import_dir_offset = 0x74F7AC;
    int import_desc_size = sizeof(struct _IMAGE_IMPORT_DESCRIPTOR);
    int import_count = 0x1CC / import_desc_size;
    for (int i = 0; i < import_count; i ++) {
        struct _IMAGE_IMPORT_DESCRIPTOR* descriptor = (struct _IMAGE_IMPORT_DESCRIPTOR*)((char*)self + import_dir_offset
            + i * import_desc_size);
        if (!strcmp((char*)self + descriptor->Name, module)) {
            void* oft = (void*)((char*)self + descriptor->OriginalFirstThunk);
            int order = 0;
            while (*((long long*)oft + order) != 0) {
                if (*((long long*)oft + order) >> 63) {
                    continue;
                }
                if (!strcmp((char*)self + *((long long*)oft + order) + 2, proc)) {
                    void** orig = (void**)((char*)self + descriptor->FirstThunk + order * 8);
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

void detour_winapi(const char* module, const char* proc, void (*func), void*(*original)) {
    FARPROC addr = GetProcAddress(LoadLibraryA(module), proc);
    *original = addr;
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach(original, func);
    printf("Hooked %s\n", proc);
    DetourTransactionCommit();
}

void run() {
    QueryPerformanceFrequency(&qpcf);
    HMODULE module = GetModuleHandleA("amdaemon.exe");
    printf("Module: %p\n", module);
    printf("Patching log flags...\n");
    for (int i = 0x8A06E0; i <= 0x8A072C; i += 4) {
        if (i == 0x8A06FC) {
            continue; // don't load amsTimer
        }
        enable_log(module, i);
    }
    enable_log(module, 0x783530);
    enable_log(module, 0x784B24);
    enable_log(module, 0x81E868);
    enable_log(module, 0x81E8E4);
    enable_log(module, 0x827E08);
    enable_log(module, 0x827E0C);
    enable_log(module, 0x828080);
    enable_log(module, 0x828198);
    enable_log(module, 0x8283F0);
    enable_log(module, 0x828430);
    enable_log(module, 0x8A1BA4);
    enable_log(module, 0x8A1C90);
    enable_log(module, 0x8A2480);
    enable_log(module, 0x8A2488);
    enable_log(module, 0x8A2490);
    enable_log(module, 0x97C418);
    enable_log(module, 0x97C41C);
    printf("Patching null logs...\n");
    // patch_func(module, 0x274080, &log_version);
    printf("Patching am functions...\n");
    patch_func(module, 0x2914f0, &null_int32_0);
    patch_func(module, 0x1ca2a0, &null_int32_3);
    printf("Patching Windows API...\n");
    patch_winapi("kernel32.dll", "OutputDebugStringW", &local_debug_log_w);
    patch_winapi("kernel32.dll", "GetComputerNameA", &main_serial);
    patch_winapi("setupapi.dll", "SetupDiEnumDeviceInterfaces", &FakeSetupDiEnumDeviceInterfaces);
    patch_winapi("setupapi.dll", "SetupDiGetDeviceInterfaceDetailW", &FakeSetupDiGetDeviceInterfaceDetailW);
    patch_winapi("setupapi.dll", "SetupDiGetClassDevsA", &FakeSetupDiGetClassDevsA);
    patch_winapi("kernel32.dll", "SetupComm", &FakeSetupComm);
    patch_winapi("kernel32.dll", "GetCommState", &FakeGetCommState);
    patch_winapi("kernel32.dll", "SetCommState", &FakeSetCommState);
    patch_winapi("kernel32.dll", "SetCommTimeouts", &FakeSetCommTimeouts);
    patch_winapi("kernel32.dll", "PurgeComm", &FakePurgeComm);
    patch_winapi("kernel32.dll", "ClearCommError", &FakeClearCommError);
    printf("Hooking Windows API...\n");
    detour_winapi("KERNEL32.dll", "CreateFileW", &ProxyCreateFileW, &OriginalCreateFileW);
    detour_winapi("KERNEL32.dll", "CreateFileA", &ProxyCreateFileA, &OriginalCreateFileA);
    detour_winapi("KERNEL32.dll", "CloseHandle", &ProxyCloseHandle, &OriginalCloseHandle);
    detour_winapi("KERNEL32.dll", "ReadFile", &ProxyReadFile, &OriginalReadFile);
    detour_winapi("KERNEL32.dll", "WriteFile", &ProxyWriteFile, &OriginalWriteFile);
    detour_winapi("KERNEL32.dll", "GetOverlappedResult", &ProxyGetOverlappedResult, &OriginalGetOverlappedResult);
    detour_winapi("KERNEL32.dll", "DeviceIoControl", &ProxyDeviceIoControl, &OriginalDeviceIoControl);
}

LRESULT window_proc(_In_ HWND hwnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam) {
    switch (uMsg) {
    case WM_CREATE:
        {
            RAWINPUTDEVICE device[2];
            device[0].usUsagePage = HID_USAGE_PAGE_GENERIC;
            device[0].usUsage = HID_USAGE_GENERIC_KEYBOARD;
            device[0].dwFlags = RIDEV_NOLEGACY | RIDEV_INPUTSINK;
            device[0].hwndTarget = hwnd;
            device[1].usUsagePage = HID_USAGE_PAGE_GENERIC;
            device[1].usUsage = HID_USAGE_GENERIC_MOUSE;
            device[1].dwFlags = RIDEV_NOLEGACY | RIDEV_INPUTSINK;
            device[1].hwndTarget = hwnd;
            BOOL res = RegisterRawInputDevices(device, 2, sizeof(RAWINPUTDEVICE));
            if (!res) {
                printf("Failed to register raw input: %lu\n", GetLastError());
            }
            break;
        }
    case WM_INPUT:
        {
            unsigned int size;
            GetRawInputData(lParam, RID_INPUT, NULL, &size, sizeof(RAWINPUTHEADER));
            LPRAWINPUT input = malloc(size);
            GetRawInputData(lParam, RID_INPUT, input, &size, sizeof(RAWINPUTHEADER));
            if (input->header.dwType == RIM_TYPEKEYBOARD) {
                RAWKEYBOARD kb = input->data.keyboard;
                switch (kb.VKey) {
                case VK_F1:
                    usbio_state.TEST = kb.Flags == RI_KEY_BREAK ? 0 : 1;
                    break;
                case VK_F2:
                    usbio_state.SERVICE = kb.Flags == RI_KEY_BREAK ? 0 : 1;
                    break;
                case 'D':
                    usbio_state.L1 = kb.Flags == RI_KEY_BREAK ? 0 : 1;
                    break;
                case 'F':
                    usbio_state.L2 = kb.Flags == RI_KEY_BREAK ? 0 : 1;
                    break;
                case 'G':
                    usbio_state.L3 = kb.Flags == RI_KEY_BREAK ? 0 : 1;
                    break;
                case 'H':
                    usbio_state.R1 = kb.Flags == RI_KEY_BREAK ? 0 : 1;
                    break;
                case 'K':
                    usbio_state.R3 = kb.Flags == RI_KEY_BREAK ? 0 : 1;
                    break;
                case 'L':
                    usbio_state.RSIDE = kb.Flags == RI_KEY_BREAK ? 1 : 0;
                    break;
                case VK_F6:
                    usbio_state.RMENU = kb.Flags == RI_KEY_BREAK ? 0 : 1;
                    break;
                case 'Q':
                    ((char*)&usbio_state)[11] = kb.Flags == RI_KEY_BREAK ? 0 : 0xff;
                    break;
                case 'W':
                    ((char*)&usbio_state)[12] = kb.Flags == RI_KEY_BREAK ? 0 : 0xff;
                    break;
                case 'E':
                    ((char*)&usbio_state)[13] = kb.Flags == RI_KEY_BREAK ? 0 : 0xff;
                    break;
                case 'R':
                    ((char*)&usbio_state)[14] = kb.Flags == RI_KEY_BREAK ? 0 : 0xff;
                    break;
                case 'T':
                    ((char*)&usbio_state)[15] = kb.Flags == RI_KEY_BREAK ? 0 : 0xff;
                    break;
                case 'Y':
                    ((char*)&usbio_state)[16] = kb.Flags == RI_KEY_BREAK ? 0 : 0xff;
                    break;
                case 'U':
                    ((char*)&usbio_state)[17] = kb.Flags == RI_KEY_BREAK ? 0 : 0xff;
                    break;
                case 'I':
                    ((char*)&usbio_state)[18] = kb.Flags == RI_KEY_BREAK ? 0 : 0xff;
                    break;
                case 'O':
                    ((char*)&usbio_state)[19] = kb.Flags == RI_KEY_BREAK ? 0 : 0xff;
                    break;
                case 'P':
                    ((char*)&usbio_state)[20] = kb.Flags == RI_KEY_BREAK ? 0 : 0xff;
                    break;
                }
            } else if (input->header.dwType == RIM_TYPEMOUSE) {
                RAWMOUSE mouse = input->data.mouse;
                if (mouse.usFlags == MOUSE_MOVE_RELATIVE) {
                    int move = mouse.lLastX * 15;
                    if (usbio_state.analog < -move) {
                        usbio_state.analog = 0;
                    } else if (usbio_state.analog + move > 0xFFFF) {
                        usbio_state.analog = 0xFFFF;
                    } else {
                        usbio_state.analog += move;
                    }
                }
            }
            free(input);
            break;
        }
    }
    return 1;
}

DWORD msg_loop(LPVOID param) {
    WNDCLASSA wc = {
        .lpfnWndProc = &window_proc,
        .hInstance = GetModuleHandle(NULL) ,
        .lpszClassName = "Hook Message Window Class",
    };
    ATOM res = RegisterClassA(&wc);
    if (!res) {
        printf("Register window class failed: %lu\n", GetLastError());
    } else {
        printf("Registered window class %hu\n", res);
    }
    HWND window = CreateWindowExA(0, "Hook Message Window Class", "Hook Message Window", 0, 0, 0, 0, 0, HWND_MESSAGE,
        NULL, NULL, NULL);
    if (window == NULL) {
        printf("Failed to create window: %lu\n", GetLastError());
    }
    MSG msg;
    while (GetMessage(&msg, window, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD ul_reason_for_call,
                      LPVOID lpReserved
) {
    FILE* fp;
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        AllocConsole();
        freopen_s(&fp, "CONOUT$", "w", stdout); /* 標準出力(stdout)を新しいコンソールに向ける */
        freopen_s(&fp, "CONOUT$", "w", stderr); /* 標準エラー出力(stderr)を新しいコンソールに向ける */
        printf("Hook DLL Loaded\n");
        assert(sizeof(struct usbio_state_st) == 0x40);
        CreateThread(0, 0, &msg_loop, 0, 0, 0);

        run();
        break;
    case DLL_THREAD_ATTACH:
        // printf("DLL_THREAD_ATTACH\n");
        break;
    case DLL_THREAD_DETACH:
        // printf("DLL_THREAD_DETACH\n");
        break;
    case DLL_PROCESS_DETACH:
        printf("DLL_PROCESS_DETACH\n");
        break;
    }
    return TRUE;
}
