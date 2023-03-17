// TODO: The name of this file is correct, but the path was guessed!
// NOTE: This file appears to be included in Wii U builds also, just disabled.
#pragma once
#ifdef _WIN32
#include "DevicePlatformBase.h"

namespace app
{
namespace hid
{
class DevicePadWin : public DevicePlatformBase // sizeof == 0x308
{
    // TODO

public:
    // TODO

    // Wii U: N/A, PC: 0x004f7780
    ~DevicePadWin();

    // Wii U: N/A, PC: 0x00607470
    std::size_t GetPortMax() const;

    // Wii U: N/A, PC: 0x004f77b0
    void GetDeviceData(ResDeviceData* devices, std::size_t deviceCount); // TODO: Does this actually return a number on PC?

    // TODO: On PC there's apparently another virtual function that gets overridden here? 0x004f7440

    // Wii U: N/A, PC: 0x004f7620
    DevicePadWin(void* instHandle, void* surfaceHandle);
};
}
}
#endif
