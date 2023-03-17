// TODO: Both the name of this file and its path were guessed!
// TODO: Could be "DevicePadMapWin.h"?
#pragma once
#include "DevicePlatformBase.h"

namespace app
{
namespace hid
{
class DevicePadKB : public DevicePlatformBase // sizeof == 0x420
{
    // TODO: Data Members

public:
    // TODO

    // Wii U: N/A, PC: 0x004044e0
    DevicePadKB(void* instHandle, void* surfaceHandle);
};
}
}
