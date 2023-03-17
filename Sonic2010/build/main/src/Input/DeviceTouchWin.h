// TODO: The name of this file is correct, but the path was guessed!
// NOTE: This file appears to be included in Wii U builds also, just disabled.
#pragma once
#ifdef _WIN32
#include "DevicePlatformBase.h"

namespace app
{
namespace hid
{
class DeviceTouchWin : public DevicePlatformBase // size == 0x34
{
    struct InputWrapper // TODO: Is this a good name?
    {
        void* Handle;

        // TODO: Other functions, if any.

        // Wii U: N/A, PC: 0x004f6920
        InputWrapper(void* instHandle);
    };

    unsigned int field_0xc;
    InputWrapper m_hinput;
    void* m_surfaceHandle;
    int m_maxX, m_maxY;
    void* m_device;
    void* field_0x24;
    void* field_0x28;
    void* field_0x2c;

public:
    std::size_t DeviceCount;

    // Wii U: N/A, PC: 0x008f1360
    std::size_t GetPortMax() const;

    // Wii U: N/A, PC: 0x004f7a50
    void GetDeviceData(ResDeviceData* devices, std::size_t deviceCount); // TODO: Does this actually return a number on PC?

    // Wii U: N/A, PC: 0x004f7970
    void* CreateDevice(const void* deviceInst);

    // Wii U: N/A, PC: 0x004f7bd0
    DeviceTouchWin(void* instHandle, void* surfaceHandle);
};
}
}
#endif
