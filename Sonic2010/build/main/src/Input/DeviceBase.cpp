// TODO: The name of this file is correct, but the path was guessed!
#include "pch.h"
#include "DeviceBase.h"
#include "DeviceData.h"

namespace app
{
namespace hid
{
float DeviceBase::Poll(float param_1)
{
    return param_1;
}

std::size_t DeviceBase::GetPortMax() const
{
    return 0;
}

void DeviceBase::GetDeviceData(ResDeviceData* devices, std::size_t deviceCount) {}

void DeviceBase::SendDeviceData(unsigned int param_1, unsigned int param_2,
    const ResSendDeviceData* param_3) {}

void DeviceBase::DeviceDataClear(ResDeviceData* devices,
    std::size_t deviceCount, bool hasRepeat)
{
    if (deviceCount)
    {
        for (std::size_t i = 0; i < deviceCount; ++i)
        {
            devices->Init(hasRepeat);
        }
    }
}
}
}
