// TODO: Both the name of this file and its path were guessed!
#include "pch.h"
#include "DevicePlatformBase.h"

namespace app
{
namespace hid
{
DevicePlatformBase::~DevicePlatformBase() {}

void* DevicePlatformBase::GetRuntimeTypeInfo() const
{
    // TODO
    return nullptr;
}

float DevicePlatformBase::Poll(float param_1)
{
    return param_1;
}

std::size_t DevicePlatformBase::GetPortMax() const
{
    return 0;
}

void DevicePlatformBase::GetDeviceData(ResDeviceData* devices, std::size_t deviceCount) {}

void DevicePlatformBase::SendDeviceData(unsigned int param_1,
    unsigned int param_2, const ResSendDeviceData* param_3) {}

void DevicePlatformBase::ChangeDeviceData(ResDeviceData* param_1,
    const ResDeviceData* param_2, unsigned int param_3) {}

bool DevicePlatformBase::IsActive(std::size_t port) const
{
    return true;
}
}
}
