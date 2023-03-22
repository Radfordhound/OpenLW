// TODO: The name of this file is correct, but the path was guessed!
// NOTE: This file appears to be included in Wii U builds also, just disabled.
#pragma once
#ifdef _WIN32
#include "DeviceTouchWin.h"
#include "DeviceBase.h"
#include "System/Singleton.h"
#include <csl/ut/array.h>

namespace app
{
namespace hid
{
class DeviceWin : public DeviceBase, public csl::fnd::Singleton<DeviceWin>
{
OPENLW_PRIVATE
    DECLARE_SINGLETON

    csl::ut::InplaceMoveArray<DevicePlatformBase*, MAX_DEVICE_PORTS> m_platforms;
    std::size_t m_portMax;

public:
    LWAPI(NONE, 0x00fd9fac)
    static DeviceTouchWin* TouchDevice;

    LWAPI(NONE, 0x004439d0)
    std::size_t GetPortMax() const;

    LWAPI(NONE, 0x004f7d60)
    void GetDeviceData(ResDeviceData* devices, std::size_t deviceCount);

    LWAPI(NONE, 0x004f7c50)
    void Setup(void* instHandle, void* surfaceHandle);

    DeviceWin();
};

/**
 * @brief Initializes the DeviceWin Singleton.
 *
 * NOTE: This function appears to be static, but it's been exposed in
 * this header anyway for LWAPI/modding purposes.
*/
LWAPI(NONE, 0x004f7f40)
void* DeviceWin_init();

/**
 * @brief Destroys the DeviceWin Singleton.
 *
 * NOTE: This function appears to be static, but it's been exposed in
 * this header anyway for LWAPI/modding purposes.
 *
 * @param[in] ptr The pointer to the Singleton.
*/
LWAPI(NONE, 0x0095fa00)
void DeviceWin_destroy(void* ptr);
}
}
#endif
