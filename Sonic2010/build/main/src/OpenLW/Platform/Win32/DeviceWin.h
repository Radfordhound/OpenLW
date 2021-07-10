#pragma once
#include "DeviceTouchWin.h"
#include "../../hid/DeviceBase.h"
#include "../../fnd/Singleton.h"
#include "csl/ut/array.h"

namespace app
{
namespace hid
{
class DeviceWin : public DeviceBase, public csl::fnd::Singleton<DeviceWin>
{
    DECLARE_SINGLETON

    csl::ut::InplaceMoveArray<DevicePlatformBase*, MAX_DEVICE_PORTS> m_platforms;
    std::size_t m_portMax;

public:
    // Wii U: N/A, PC: 0x00fd9fac
    static DeviceTouchWin* TouchDevice;

    // Wii U: N/A, PC: 0x004439d0
    std::size_t GetPortMax() const;

    // Wii U: N/A, PC: 0x004f7d60
    void GetDeviceData(ResDeviceData* devices, std::size_t deviceCount);

    // Wii U: N/A, PC: 0x004f7c50
    void Setup(void* instHandle, void* surfaceHandle);

    // Wii U: N/A, PC: Inlined
    DeviceWin();
};
}
}
