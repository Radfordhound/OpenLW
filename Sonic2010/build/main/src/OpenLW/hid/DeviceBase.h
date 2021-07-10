#pragma once
#include "ResDeviceData.h"
#include "ResSendDeviceData.h"
#include "../fnd/ReferencedObject.h"

#ifndef MAX_DEVICE_PORTS
#define MAX_DEVICE_PORTS 8
#endif

namespace app
{
namespace hid
{
class DeviceBase : public fnd::ReferencedObject
{
//protected:
//    inline DeviceBase() = default;

public:
    // Wii U: Inlined, PC: TODO
    virtual float Poll(float param_1);

    // Wii U: Inlined, PC: TODO
    virtual std::size_t GetPortMax() const;

    // Wii U: Inlined, PC: TODO
    virtual void GetDeviceData(ResDeviceData* devices, std::size_t deviceCount);

    // Wii U: Inlined, PC: TODO
    virtual void SendDeviceData(unsigned int param_1, unsigned int param_2,
        const ResSendDeviceData* param_3);

    // Wii U: 0x022788d0, PC: 0x004f5a70
    static void DeviceDataClear(ResDeviceData* devices,
        std::size_t deviceCount, bool hasRepeat);
};
}
}
