// TODO: Both the name of this file and its path were guessed!
// TODO: Could be "DevicePadMapWin.cpp"?
#include "pch.h"
#include "DevicePadKB.h"

namespace app
{
namespace hid
{
const char* GetKBActionRegKeyName(KBACTION action)
{
    switch (action)
    {
#define KBACTION_DEF(lbl) case KBACTION_##lbl: return "KBACTION_" #lbl;
#include "KBACTION.inl"
#undef KBACTION_DEF

    default:
        return nullptr;
    }
}

DevicePadKB::DevicePadKB(void* instHandle, void* surfaceHandle)
{
    // TODO

    HKEY hkey;
    DWORD disposition;

    if (RegCreateKeyExA(HKEY_CURRENT_USER, "Software\\SEGA\\SLW\\", 0, nullptr, 0,
        KEY_READ, nullptr, &hkey, &disposition) == ERROR_SUCCESS)
    {
        BYTE data[20];
        DWORD dataLen = 10;

        for (std::size_t action = 0; action < KBACTION_COUNT; ++action)
        {
            if (RegQueryValueExA(hkey, GetKBActionRegKeyName(static_cast<KBACTION>(action)),
                NULL, nullptr, data, &dataLen) == ERROR_SUCCESS)
            {
                // TODO
            }

            // TODO
        }

        // TODO
        RegCloseKey(hkey);
    }
}
}
}
