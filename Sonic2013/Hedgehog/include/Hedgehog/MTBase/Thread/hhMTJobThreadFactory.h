#pragma once
#include "../hhJob.h"
#include <Hedgehog/Base/Thread/hhThread.h>

namespace hh
{
namespace base
{
class CSharedString;
}

struct SJobExecuteHeader;

namespace MTBase
{
class CMTExecutorThread : public base::CThreadImp // size == 16
{
    SJobExecuteHeader* m_jobExecHeader;

public:
    LWAPI(0x036e77b4, TODO)
    CMTExecutorThread(SJobExecuteHeader* jobExecHeader,
        const base::CSharedString& name, unsigned int cpuID,
        std::size_t stackSize);

    LWAPI(0x036e7828, TODO)
    ~CMTExecutorThread();

    LWAPI(0x036e787c, TODO)
    void Process();
};

class CCMTExecutorThreadFactory : public base::CThreadImp::IFactory // size == 8
{
    SJobExecuteHeader* m_jobExecHeader;

public:
    LWAPI(0x036e78c8, TODO)
    CCMTExecutorThreadFactory(SJobExecuteHeader* jobExecHeader);

    LWAPI(0x036e7918, 0x00c33380)
    CMTExecutorThread* MakeInstance(const base::CSharedString& name,
        int cpuID, std::size_t stackSize);
};
}
}
