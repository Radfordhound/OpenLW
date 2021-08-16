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
    // Wii U: 0x036bf8d8, PC: 0x00c25cb0
    CCriticalSectionD3D9();

    // Wii U: 0x036bf9c0 (THUNK), PC: TODO
    void Enter();

    // Wii U: 0x036bf9c8 (THUNK), PC: TODO
    void Leave();
};
}
}
