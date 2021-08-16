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
    // Wii U: 0x036e77b4, PC: TODO
    CMTExecutorThread(SJobExecuteHeader* jobExecHeader,
        const base::CSharedString& name, unsigned int cpuID,
        std::size_t stackSize);

    // Wii U: 0x036e7828, PC: TODO
    ~CMTExecutorThread();

    // Wii U: 0x036e787c, PC: TODO
    void Process();
};

class CCMTExecutorThreadFactory : public base::CThreadImp::IFactory // size == 8
{
    SJobExecuteHeader* m_jobExecHeader;

public:
    // Wii U: 0x036e78c8, PC: TODO
    CCMTExecutorThreadFactory(SJobExecuteHeader* jobExecHeader);

    // Wii U: 0x036e7918, PC: 0x00c33380
    CMTExecutorThread* MakeInstance(const base::CSharedString& name,
        int cpuID, std::size_t stackSize);
};
}
}
