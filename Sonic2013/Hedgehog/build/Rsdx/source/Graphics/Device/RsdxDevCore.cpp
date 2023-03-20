#include "pch.h"
#include "Hedgehog/Rsdx/Graphics/Device/RsdxDevCore.h"

namespace hh
{
namespace rsdx
{
#ifndef _WIN32
RSDXRESULT RsdxDevCore::CreateDevice(unsigned int Adapter,
    RSDXDEVTYPE DeviceType, void* hFocusWindow,
    int BehaviorFlags, _RSDXPRESENTPARAM* pPresentationParameters,
    RsdxDevice** ppReturnedDeviceInterface, unsigned int param_7)
{
    // TODO
}

RsdxDevCore* RsdxCreate(unsigned long long param_1)
{
    // TODO
    return nullptr;
}
#endif
}
}
