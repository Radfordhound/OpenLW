// TODO: Both the name of this file and its path were guessed!
#pragma once
#include "DeviceData.h"
#include "System/ReferencedObject.h"

namespace app
{
namespace hid
{
class DevicePlatformBase : public fnd::ReferencedObject
{
LWAPI_PRIVATE
    // TODO: Are there any data members?

public:
    LWAPI(NONE, 0x00403ff0)
    ~DevicePlatformBase();

    LWAPI(NONE, 0x00403fe0)
    virtual void* GetRuntimeTypeInfo() const;

    LWAPI(0x0227dbf8, 0x0085b2f0)
    virtual float Poll(float param_1);

    LWAPI(NONE, 0x00445190)
    virtual std::size_t GetPortMax() const;

    LWAPI(NONE, 0x0070a480)
    virtual void GetDeviceData(ResDeviceData* devices, std::size_t deviceCount); // TODO: Does this actually return a number on PC?

    LWAPI(NONE, 0x00ad1e10)
    virtual void SendDeviceData(unsigned int param_1, unsigned int param_2,  // TODO: Does this actually return a number on PC?
        const ResSendDeviceData* param_3);

    LWAPI(NONE, 0x00ca5570)
    virtual void ChangeDeviceData(ResDeviceData* param_1,
        const ResDeviceData* param_2, unsigned int param_3);

    LWAPI(NONE, 0x004b70d0)
    virtual bool IsActive(std::size_t port) const;

    // TODO: On PC there's apparently another virtual function here? Address: 0x00632a90
};
}
}
