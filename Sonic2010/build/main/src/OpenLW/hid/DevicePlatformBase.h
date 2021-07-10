#pragma once
#include "../fnd/ReferencedObject.h"
#include "ResDeviceData.h"
#include "ResSendDeviceData.h"

namespace app
{
namespace hid
{
class DevicePlatformBase : public fnd::ReferencedObject
{
    // TODO: Are there any data members?

public:
    // Wii U: TODO, PC: 0x00403fe0
    virtual void* GetRuntimeTypeInfo() const;

    // Wii U: TODO, PC: GENERIC RETURN VOID
    virtual float Poll(float param_1);

    // Wii U: TODO, PC: GENERIC RETURN 0
    virtual std::size_t GetPortMax() const;

    // Wii U: TODO, PC: TODO
    virtual void GetDeviceData(ResDeviceData* devices, std::size_t deviceCount); // TODO: Does this actually return a number on PC?

    // Wii U: TODO, PC: TODO
    virtual void SendDeviceData(unsigned int param_1, unsigned int param_2,  // TODO: Does this actually return a number on PC?
        const ResSendDeviceData* param_3);

    // Wii U: TODO, PC: GENERIC RETURN VOID
    virtual void ChangeDeviceData(ResDeviceData* param_1,
        const ResDeviceData* param_2, unsigned int param_3);

    // Wii U: TODO, PC: GENERIC RETURN TRUE
    virtual bool IsActive(std::size_t port) const;

    // TODO: On PC there's apparently another virtual function here?
};
}
}
