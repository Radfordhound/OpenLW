#pragma once
#include "../Platform/D3d9/hhThreadImpD3D9.h"
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>

namespace hh
{
namespace base
{
class CThread // TODO: Inheritance? // size == 0x1c
{
    boost::shared_ptr<CThreadImp> m_impl;
    boost::function0<void> field_0x8;
    unsigned short field_0x18;
    // TODO: Other data members?

public:
    // Wii U: 0x03a040e0, PC: TODO
    CThread(boost::function0<void> param_1,
        const CSharedString& name, unsigned int cpuID,
        std::size_t stackSize, CThreadImp::IFactory* factory);

    // Wii U: 0x03a0436c, PC: TODO
    void Process();
};
}
}
