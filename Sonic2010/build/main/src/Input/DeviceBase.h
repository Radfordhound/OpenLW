// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include "System/ReferencedObject.h"

namespace app
{
namespace hid
{
struct ResDeviceData;
struct ResSendDeviceData;

class DeviceBase : public fnd::ReferencedObject
{
//protected:
//    inline DeviceBase() = default;

public:
    LWAPI(NONE, TODO)
    virtual float Poll(float param_1);

    LWAPI(NONE, TODO)
    virtual std::size_t GetPortMax() const;

    LWAPI(NONE, TODO)
    virtual void GetDeviceData(ResDeviceData* devices, std::size_t deviceCount);

    LWAPI(NONE, TODO)
    virtual void SendDeviceData(unsigned int param_1, unsigned int param_2,
        const ResSendDeviceData* param_3);

    LWAPI(0x022788d0, 0x004f5a70)
    static void DeviceDataClear(ResDeviceData* devices,
        std::size_t deviceCount, bool hasRepeat);
};
}
}
