// dllmain.cpp : Defines the entry point for the DLL application.
#include <windows.h>

#include "log.h"

extern LRESULT switch_input_keyboard_proc(int code, WPARAM wparam, LPARAM lparam);
extern LRESULT switch_input_mouse_proc(int code, WPARAM wparam, LPARAM lparam);

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    static HHOOK kb_hhook;
    static HHOOK m_hhook;
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        log("DLL_PROCESS_ATTACH\n");
        kb_hhook = SetWindowsHookExA(WH_KEYBOARD, &switch_input_keyboard_proc, hModule, GetCurrentThreadId());
        m_hhook = SetWindowsHookExA(WH_MOUSE, &switch_input_mouse_proc, hModule, GetCurrentThreadId());
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        //log("DLL_PROCESS_DETACH\n");
        //UnhookWindowsHookEx(kb_hhook);
        //UnhookWindowsHookEx(m_hhook);
        break;
    }
    return TRUE;
}

