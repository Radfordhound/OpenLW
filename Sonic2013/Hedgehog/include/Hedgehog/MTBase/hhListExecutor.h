#pragma once
#include "hhJob.h"
#include <Hedgehog/Base/System/hhEventWait.h>
#include <boost/shared_ptr.hpp>
#include <cstring>

namespace hh
{
namespace MTBase
{
enum EListExecutorFlags // TODO: This name was guessed.
{
    LIST_EXECUTOR_FLAGS_NONE = 0,
    LIST_EXECUTOR_FLAGS_IS_FINALIZING = 2
};

template<unsigned int count, typename memory_util_t>
class CListExecutor
{
    SJobExecuteHeader field_0x0[count]; // TODO: Is this correct?
    SJobExecuteHeader m_pipe;
    rsdx::RsdxAtomic field_0x90;
    boost::shared_ptr<base::CEventWait> field_0x94;
    memory_util_t m_memoryUtil;
    unsigned int m_yieldMask;

public:
    CListExecutor() :
        field_0x94(base::CEventWait::MakeInstance(false)) {}

    inline void SetEventWait()
    {
        field_0x94->Set();
    }

    void SetYieldMask(unsigned int yieldMask)
    {
        m_yieldMask = yieldMask;
    }

    SJobExecuteHeader* GetPipe()
    {
        return &m_pipe;
    }

    void* PeekExecuteJob()
    {
        for (std::size_t i = 0; i < count; ++i)
        {
            void* peekedVal = memory_util_t::PeekListOne(field_0x0 + i);
            if (peekedVal)
            {
                return peekedVal;
            }
        }

        return nullptr;
    }

    void* PopExecuteJob()
    {
        for (std::size_t i = 0; i < count; ++i)
        {
            void* poppedVal;
            if (memory_util_t::PeekListOne(field_0x0 + i) &&
                (poppedVal = memory_util_t::PopListOne(field_0x0 + i)))
            {
                return poppedVal;
            }
        }
        
        return nullptr;
    }

    unsigned int ExecuteJob()
    {
        // If we don't currently have any job to do...
        SJobExecParam* jobExecParam = static_cast<SJobExecParam*>(PopExecuteJob());
        unsigned int uVar7 = field_0x90;

        if (!jobExecParam)
        {
            if (uVar7 == LIST_EXECUTOR_FLAGS_IS_FINALIZING)
            {
                field_0x94->Set();
            }
            else
            {
                field_0x94->Reset();

                if (!PeekExecuteJob())
                {
                    // TODO: Set thread priority on Wii U.

                    field_0x94->WaitOne();
                }
                else
                {
                    field_0x94->Set();
                }
            }

            return uVar7;
        }

        // If we have a job to do, do it!
        else
        {
            hhMTExecuteJob(jobExecParam, true);
            return 1;
        }
    }

    static unsigned int StaticFlushFunc(void* param_1)
    {
        auto executor = static_cast<CListExecutor<count, memory_util_t>*>(param_1);
        return executor->ExecuteJob();
    }

    void EntryJob(SJobExecParam* jobExecParam, unsigned int param_2)
    {
        memory_util_t::PushListOne(field_0x0 + param_2, jobExecParam);
    }

    void Initialize()
    {
        std::memset(field_0x0, 0, sizeof(field_0x0));
        memory_util_t::InitializeList(field_0x0);

        m_memoryUtil.field_0x4 = 0;
        
        m_pipe.field_0x4 = 0;
        m_pipe.JobFunc = &StaticFlushFunc;
        m_pipe.JobParam = this;

        m_yieldMask = 1;
        field_0x90 = LIST_EXECUTOR_FLAGS_NONE;
        // TODO: Why does the Wii U version set m_pipe.Next to 1 here?
    }

    void PrepareFinalize()
    {
        field_0x90 = LIST_EXECUTOR_FLAGS_IS_FINALIZING;
        field_0x94->Set();
    }

    void Finalize()
    {
        ExecuteJob();
        field_0x90 = LIST_EXECUTOR_FLAGS_NONE;
        m_pipe = SJobExecuteHeader();
    }
};
}
}
