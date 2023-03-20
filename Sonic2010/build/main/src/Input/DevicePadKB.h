// TODO: Both the name of this file and its path were guessed!
// TODO: Could be "DevicePadMapWin.h"?
#pragma once
#include "DevicePlatformBase.h"

namespace app
{
namespace hid
{
enum KBACTION // TODO: This name was guessed.
{
#define KBACTION_DEF(lbl) KBACTION_##lbl,
#include "KBACTION.inl"
#undef KBACTION_DEF

    KBACTION_COUNT
};

/**
 * @brief Gets a string representation of the given KBACTION value.
 *
 * NOTE: This function appears to be static, but it's been exposed in
 * this header anyway for LWAPI/modding purposes.
 *
 * @param[in] action The KBACTION enum value to get a string representation of.
 *
 * @return A string representation of the given KBACTION value.
*/
LWAPI(NONE, 0x00404090)
const char* GetKBActionRegKeyName(KBACTION action);

class DevicePadKB : public DevicePlatformBase // sizeof == 0x420
{
LWAPI_PRIVATE
    // TODO: Data Members

public:
    // TODO

    LWAPI(NONE, 0x004044e0)
    DevicePadKB(void* instHandle, void* surfaceHandle);
};
}
}
