#include "pch.h"
#include "Hedgehog/Base/Thread/hhThread.h"
#include "Hedgehog/Base/System/hhMemoryAllocator.h"

namespace hh
{
namespace base
{
CThread::CThread(boost::function0<void> param_1,
    const CSharedString& name, unsigned int cpuID,
    std::size_t stackSize, CThreadImp::IFactory* factory) :
    m_impl(),
    field_0x8(param_1),
    field_0x18(0)
{
    if (!factory)
    {
        m_impl.reset(new (__HH_DBG_INFO, hhGetHeapHandle(0)) // line: 31
            CThreadImp(name, cpuID, stackSize));
    }
    else
    {
        m_impl.reset(factory->MakeInstance(name, cpuID, stackSize));
    }

    m_impl->SetThread(this);
}

void CThread::Process()
{
    if (field_0x8)
    {
        // TODO
        field_0x8();
    }
}
}
}
