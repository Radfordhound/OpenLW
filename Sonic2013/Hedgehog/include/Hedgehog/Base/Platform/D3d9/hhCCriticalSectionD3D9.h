#pragma once
#include <Hedgehog/Rsdx/System/RsdxMutex.h>

namespace hh
{
namespace base
{
class CCriticalSectionD3D9 // TODO: Inheritance?
{
    rsdx::RsdxMutex2 m_mutex;

public:
    LWAPI(0x036bf8d8, 0x00c25cb0)
    CCriticalSectionD3D9();

    LWAPI(0x036bf9c0, TODO)
    void Enter();

    LWAPI(0x036bf9c8, TODO)
    void Leave();
};
}
}
