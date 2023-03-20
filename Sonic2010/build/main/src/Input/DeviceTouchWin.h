// TODO: The name of this file is correct, but the path was guessed!
// NOTE: This file appears to be included in Wii U builds also, just disabled.
#pragma once
#ifdef _WIN32
#include "DevicePlatformBase.h"
#include <Windows.h>

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

namespace app
{
namespace hid
{
class DeviceTouchWin : public DevicePlatformBase // size == 0x34
{
LWAPI_PRIVATE
    struct InputWrapper // TODO: Is this a good name?
    {
        void* Handle;

        // TODO: Other functions, if any.

        LWAPI(NONE, 0x004f6920)
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

    LWAPI(NONE, 0x008f1360)
    std::size_t GetPortMax() const;

    LWAPI(NONE, 0x004f7a50)
    void GetDeviceData(ResDeviceData* devices, std::size_t deviceCount); // TODO: Does this actually return a number on PC?

    LWAPI(NONE, 0x004f7970)
    void* CreateDevice(const void* deviceInst);

    LWAPI(NONE, 0x004f7bd0)
    DeviceTouchWin(void* instHandle, void* surfaceHandle);
};

/**
 * @brief DirectInput8 callback to enumerate devices.
 *
 * NOTE: This function appears to be static, but it's been exposed in
 * this header anyway for LWAPI/modding purposes.
*/
LWAPI(NONE, 0x004f7b70)
BOOL CALLBACK EnumDevicesCallback(LPCDIDEVICEINSTANCE lpddi, LPVOID pvRef);
}
}
#endif
