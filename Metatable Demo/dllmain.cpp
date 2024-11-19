#include "Windows.h"
#include <process.h>
#include "Hooks.h"

DWORD OnAttach()
{
    *(int*)0x00D415B8 = 1;
    *(int*)0x00D415BC = 0xFFFFFFFF;
    Hooks::OpenFrame();
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
            _beginthreadex(nullptr, 0, (_beginthreadex_proc_type)OnAttach, nullptr, 0, nullptr);
            break;
    }

    return TRUE;
}

