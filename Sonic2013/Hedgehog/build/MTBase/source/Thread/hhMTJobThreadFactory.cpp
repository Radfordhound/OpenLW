#include "Hedgehog/MTBase/Thread/hhMTJobThreadFactory.h"
#include <Hedgehog/Base/System/hhMemoryAllocator.h>

using namespace hh::base;

namespace hh
{
namespace MTBase
{
CMTExecutorThread::CMTExecutorThread(SJobExecuteHeader* jobExecHeader,
    const base::CSharedString& name, unsigned int cpuID, std::size_t stackSize) :
    CThreadImp(name, cpuID, stackSize),
    m_jobExecHeader(jobExecHeader) {}

CMTExecutorThread::~CMTExecutorThread() {}

void CMTExecutorThread::Process()
{
    unsigned int result;

    do
    {
        result = m_jobExecHeader->Job(m_jobExecHeader->JobParam);
    }
    while (result == 0 || result == 1);
}

CCMTExecutorThreadFactory::CCMTExecutorThreadFactory(SJobExecuteHeader* jobExecHeader) :
    m_jobExecHeader(jobExecHeader) {}

CMTExecutorThread* CCMTExecutorThreadFactory::MakeInstance(
    const base::CSharedString& name, int cpuID, std::size_t stackSize)
{
    return new (__HH_DBG_INFO, hhGetHeapHandle(0)) // line: 77
        CMTExecutorThread(m_jobExecHeader, name, cpuID, stackSize);
}
}
}
