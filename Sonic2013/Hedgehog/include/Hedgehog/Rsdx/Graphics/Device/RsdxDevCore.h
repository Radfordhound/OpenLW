#pragma once
#include "../../System/RsdxObject.h"

#ifdef _WIN32
#include <d3d9.h>
#endif

namespace hh
{
namespace rsdx
{
#ifdef _WIN32
typedef IDirect3D9Ex RsdxDevCore;
typedef IDirect3DDevice9Ex RsdxDevice;
typedef HRESULT RSDXRESULT; // TODO: Is this name correct?
#else
class RsdxDevice;

// TODO: Move this somewhere else!
typedef long RSDXRESULT; // TODO: Is this name/value correct?

enum RSDXDEVTYPE // TODO: Is this name correct?
{
    // TODO: Are these values correct?
    RSDXDEVTYPE_HAL = 1,
    RSDXDEVTYPE_NULLREF = 4,
    RSDXDEVTYPE_REF = 2,
    RSDXDEVTYPE_SW = 3,
    RSDXDEVTYPE_FORCE_DWORD = 0xffffffff
}

typedef struct _RSDXPRESENTPARAM
{
    // TODO
}
RSDXPRESENTPARAM;

class RsdxDevCore : public RsdxRefcountObject
{
    // TODO

public:
    LWAPI(0x036b33ac, NONE)
    RSDXRESULT CreateDevice(unsigned int Adapter,
        RSDXDEVTYPE DeviceType, void* hFocusWindow,
        int BehaviorFlags, _RSDXPRESENTPARAM* pPresentationParameters,
        RsdxDevice** ppReturnedDeviceInterface,
        unsigned int param_7 = static_cast<unsigned int>(-1));

    // TODO
};

LWAPI(0x036b34ec, NONE)
RsdxDevCore* RsdxCreate(unsigned long long param_1);
#endif
}
}
