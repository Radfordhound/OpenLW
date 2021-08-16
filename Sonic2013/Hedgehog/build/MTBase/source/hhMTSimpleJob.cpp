#include "Hedgehog/MTBase/hhMTSimpleJob.h"
#include "Hedgehog/MTBase/hhListExecutor.h"
#include "Hedgehog/MTBase/hhMTJobMemorySystemUtil.h"
#include "Hedgehog/MTBase/Thread/hhMTJobThreadFactory.h"
#include <Hedgehog/Base/System/hhSharedString.h>
#include <Hedgehog/Rsdx/System/RsdxThread.h>
#include <cstring>

#ifdef __WIIU__
#include <gx2/displaylist.h>
#endif

using namespace hh::base;
using namespace hh::rsdx;

namespace hh
{
namespace MTBase
{
static const std::size_t MTBaseThreadCount = 2;

// Wii U: 0x102c7780, PC: TODO
static const int MTBaseThreadCPUIDs[MTBaseThreadCount] =
{
    0,
    2
};

// Wii U: 0x1031f924, PC: TODO
static const char* const MTBaseThreadNames[MTBaseThreadCount] =
{
    "MTBase0",
    "MTBase2"
};

struct CMTSimpleJobInternal : public CObject // size == 20
{
    unsigned int field_0x0;
    CListExecutor<8, CMTJobMemorySystemUtilLocal>* field_0x4;
    CMTExecutorThread* field_0x8[MTBaseThreadCount];

    // Wii U: 0x036e67d0, PC: 0x00c2a5f0
    CMTSimpleJobInternal(std::size_t param_1);

    // Wii U: 0x036e6988, PC: 0x00c2a880
    virtual ~CMTSimpleJobInternal();

    // Wii U: 0x036e6b18, PC: 0x00c2a430
    void* MTExecuteJobOneNow(unsigned int signal);

    // Wii U: 0x036e6b3c, PC: 0x00c2a590
    void MTSimpleJobBlockUntilSignal(SEventHolder* param_1,
        bool param_2, unsigned int signal);
};

// Wii U: 0x1031f93c, PC: 0x011d7984
static CMTSimpleJobInternal* DAT_1031f93c = nullptr;

void hhMTSimpleJobJointUnlock(SJobJoint* jobJoint)
{
    RsdxAtomicDec2(&jobJoint->field_0xc);
    if (RsdxAtomicDec2(&jobJoint->field_0x4) == 0)
    {
        jobJointFinish(jobJoint);
    }
}

void hhMTSimpleJobJointRelease(SJobJoint* jobJoint)
{
    if (jobJoint->field_0x8)
    {
        CMTJobMemorySystemUtil::FreeEventHolder(jobJoint->field_0x8);
    }

    CMTJobMemorySystemUtil::Free(jobJoint, sizeof(SJobJoint));
}

void jobJointFinish(SJobJoint* jobJoint)
{
    bool uVar1 = (jobJoint->field_0x10 != 0);
    SEventHolder* p_Var2 = jobJoint->field_0x8;

    SJobExecParam* pSVar4 = static_cast<SJobExecParam*>(
        RsdxAtomicPopSListWhole(jobJoint, nullptr));

    if (p_Var2 != nullptr)
    {
        RsdxSetEvent(p_Var2->Event);
    }

    while (pSVar4)
    {
        SJobJoint* curJobJoint = pSVar4->JobJoint;
        SJobExecParam* pSVar7 = static_cast<SJobExecParam*>(pSVar4->Next);
        unsigned int iVar4 = pSVar4->field_0x8;

        if (curJobJoint)
        {
            curJobJoint->field_0x12 = 1;
        }

        DAT_1031f93c->field_0x4->EntryJob(pSVar4, iVar4);

        if (!pSVar7)
        {
            DAT_1031f93c->field_0x4->SetEventWait();
        }

        pSVar4 = pSVar7;

        if (curJobJoint)
        {
            hhMTSimpleJobJointUnlock(curJobJoint);
        }
    }

    if (!uVar1)
    {
        hhMTSimpleJobJointRelease(jobJoint);
    }
}

// Wii U: 0x036e6544, PC: TODO
void hhMTSimpleJobDestroyDefault(SJobType256* job)
{
    CMTJobMemorySystemUtil::Free(job, 256);
}

void hhMTExecuteJob(SJobExecParam* jobExecParam, bool param_2)
{
    SJobJoint* jobJoint = jobExecParam->JobJoint;
    jobExecParam->JobExec(jobExecParam);

    if (jobJoint && RsdxAtomicDec2(&jobJoint->field_0x4) == 0)
    {
        jobJointFinish(jobJoint);
    }

    if (param_2)
    {
        hhMTSimpleJobDestroyDefault(reinterpret_cast<SJobType256*>(jobExecParam));
    }
}

CMTSimpleJobInternal::CMTSimpleJobInternal(std::size_t param_1)
{
    CMTJobMemorySystemUtil::InitializeJobMemory(sizeof(SJobJoint) * 512);
    CMTJobMemorySystemUtil::InitializeEventHolder(32);

    field_0x4 = new (__HH_ALLOCALIGN(sizeof(*field_0x4), 128))
        CListExecutor<8, CMTJobMemorySystemUtilLocal>();

    field_0x4->Initialize();
    field_0x4->SetYieldMask(1);
        
    CCMTExecutorThreadFactory threadFactory(field_0x4->GetPipe());
    for (std::size_t i = 0; i < MTBaseThreadCount; ++i)
    {
        field_0x8[i] = threadFactory.MakeInstance(MTBaseThreadNames[i],
            MTBaseThreadCPUIDs[i], param_1);
            
        field_0x8[i]->SetPriority(THREAD_PRIORITY_UNKNOWN2);
        field_0x8[i]->Start();
    }
}

// Wii U: 0x036e6988, PC: 0x00c2a880
CMTSimpleJobInternal::~CMTSimpleJobInternal()
{
    field_0x4->PrepareFinalize();

    for (std::size_t i = 0; i < MTBaseThreadCount; ++i)
    {
        field_0x8[i]->Join();
        delete field_0x8[i];
    }

    field_0x4->Finalize();
    delete field_0x4;
    field_0x4 = nullptr;

    CMTJobMemorySystemUtil::FinalizeEventHolder();
    CMTJobMemorySystemUtil::FinalizeJobMemory();
}

// Wii U: 0x036e6b18, PC: 0x00c2a430
void* CMTSimpleJobInternal::MTExecuteJobOneNow(unsigned int signal)
{
    // TODO
    //return field_0x4.ExecuteJobOneNow(signal);
    __debugbreak();
    return nullptr;
}

// Wii U: 0x036e6b3c, PC: 0x00c2a590
void CMTSimpleJobInternal::MTSimpleJobBlockUntilSignal(SEventHolder* param_1,
    bool param_2, unsigned int signal)
{
    while (!RsdxCheckEvent(param_1->Event) &&
        ((param_2 && MTExecuteJobOneNow(signal)) ||
        !RsdxWaitEvent(param_1->Event, 1))) {}
}

class CMTSimpleJobPushEasyData // TODO: Inheritance?
{
    // TODO: Any data members?

public:
    // Wii U: 0x036e6be8, PC: 0x00c2a8b0
    static void JobExec(void* param_1)
    {
        SJobExecParam* jobExecParam = static_cast<SJobExecParam*>(param_1);
        jobExecParam->Job();
        jobExecParam->Job.~function<void()>(); // TODO: Is this correct?
    }
};

class CMTSimpleJobPushEasyData2 // TODO: Inheritance?
{
    // TODO: Any data members?

public:
    // Wii U: 0x036e6e28, PC: TODO
    static void JobExec(void* param_1)
    {
        SJobExecParam* jobExecParam = static_cast<SJobExecParam*>(param_1);
        auto& job2 = reinterpret_cast<boost::function<void(
            unsigned int, unsigned int)>&>(jobExecParam->Job);

        job2(jobExecParam->field_0x24, jobExecParam->field_0x20);
        job2.~function<void(unsigned int, unsigned int)>(); // TODO: Is this correct?
    }
};

void hhMTSimpleJobStart()
{
    if (!DAT_1031f93c)
    {
        DAT_1031f93c = new CMTSimpleJobInternal(0x20000);
    }

    ++DAT_1031f93c->field_0x0;
}

void hhMTSimpleJobEntry(SJobType256* job, unsigned int param_2)
{
    if (job->JobExecParam.JobJoint)
    {
        job->JobExecParam.JobJoint->field_0x12 = 1;
    }

    DAT_1031f93c->field_0x4->EntryJob(&job->JobExecParam, param_2);
    DAT_1031f93c->field_0x4->SetEventWait();
}

SJobType256* hhMTSimpleJobCreateDefault()
{
    SJobType256* job;
    while (!(job = static_cast<SJobType256*>(CMTJobMemorySystemUtil::Allocate(256))))
    {
        RsdxThreadSleep(1);
    }

    std::memset(job, 0, 256);
    return job;
}

SJobJoint* hhMTSimpleJobJointCreate()
{
    SJobJoint* jobJoint;
    while (!(jobJoint = static_cast<SJobJoint*>(CMTJobMemorySystemUtil::Allocate(256))))
    {
        RsdxThreadSleep(1);
    }

    std::memset(jobJoint, 0, 256);
    RsdxInitializeSListHead(jobJoint);

    return jobJoint;
}

SEventHolder* hhMTSimpleJobCreateFinishSignal()
{
    SEventHolder* eventHolder;
    while (!(eventHolder = CMTJobMemorySystemUtil::AllocEventHolder()))
    {
        RsdxThreadSleep(1);
    }

    return eventHolder;
}

SJobJoint* hhMTSimpleJobJointStaticCreate(const char* name)
{
    SEventHolder* eventHolder = hhMTSimpleJobCreateFinishSignal();
    SJobJoint* jobJoint = hhMTSimpleJobJointCreate();

    jobJoint->field_0x8 = eventHolder;
    jobJoint->field_0x10 = 1;
    jobJoint->Name = name;

    RsdxSetEvent(eventHolder->Event);
    return jobJoint;
}

SJobJoint* hhMTSimpleJobJointDynamicCreate(const char* name)
{
    SJobJoint* jobJoint = hhMTSimpleJobJointCreate();
    jobJoint->Name = name;
    return jobJoint;
}

void hhMTSimpleJobJointLock(SJobJoint* jobJoint)
{
    RsdxAtomicInc2(&jobJoint->field_0xc);
    if (RsdxAtomicInc2(&jobJoint->field_0x4) == 1 && jobJoint->field_0x8)
    {
        RsdxResetEvent(jobJoint->field_0x8->Event);
    }
}

void hhMTSimpleJobLinkNext(SJobExecParam* jobExecParam,
    SJobJoint* jobJoint, unsigned int param_3)
{
    jobExecParam->field_0x8 = param_3;
    if (jobExecParam->JobJoint)
    {
        hhMTSimpleJobJointLock(jobExecParam->JobJoint);
    }

    RsdxAtomicPushSList(jobJoint, jobExecParam);
}

void hhMTSimpleJobLinkNext(SJobType256* job,
    SJobJoint* jobJoint, unsigned int param_3)
{
    hhMTSimpleJobLinkNext(&job->JobExecParam, jobJoint, param_3);
}

void hhMTSimpleJobBind(SJobExecParam* jobExecParam, SJobJoint* jobJoint)
{
    if (jobJoint->field_0x4 == 0 && jobJoint->field_0x8)
    {
        RsdxResetEvent(jobJoint->field_0x8->Event);
    }

    jobExecParam->JobJoint = jobJoint;
    RsdxAtomicInc2(&jobJoint->field_0x4);
}

void hhMTSimpleJobBind(SJobType256* job, SJobJoint* jobJoint)
{
    hhMTSimpleJobBind(&job->JobExecParam, jobJoint);
}

void hhMTSimpleJobFunction(const boost::function<void()>& jobFunc,
    const SMTUpdateHint& updateHint)
{
    SJobType256* job = hhMTSimpleJobCreateDefault();
    if (updateHint.field_0x4)
    {
        hhMTSimpleJobBind(job, updateHint.field_0x4.get());
    }

    job->Name = updateHint.JobName;
    job->JobExecParam.JobExec = &CMTSimpleJobPushEasyData::JobExec;
    new (&job->JobExecParam.Job) boost::function<void()>(jobFunc);

    if (updateHint.field_0x8)
    {
        hhMTSimpleJobLinkNext(job, updateHint.field_0x8.get(), updateHint.field_0x0);
    }
    else
    {
        hhMTSimpleJobEntry(job, updateHint.field_0x0);
    }
}

void hhMTSimpleJobFunction2(
    const boost::function<void(unsigned int, unsigned int)>& jobFunc,
    unsigned int param_2, const SMTUpdateHint& updateHint)
{
    for (unsigned int i = 0; i < param_2; ++i)
    {
        SJobType256* job = hhMTSimpleJobCreateDefault();

        job->Name = updateHint.JobName;
        job->JobExecParam.JobExec = &CMTSimpleJobPushEasyData2::JobExec;
        new (&job->JobExecParam.Job) boost::function<void(unsigned int, unsigned int)>(jobFunc);
        job->JobExecParam.field_0x20 = param_2;
        job->JobExecParam.field_0x24 = i;

        if (updateHint.field_0x4)
        {
            hhMTSimpleJobBind(job, updateHint.field_0x4.get());
        }

        if (!updateHint.field_0x8)
        {
            if (job->JobExecParam.JobJoint)
            {
                job->JobExecParam.JobJoint->field_0x12 = 1;
            }

            DAT_1031f93c->field_0x4->EntryJob(&job->JobExecParam, updateHint.field_0x0);

            if (i == (param_2 - 1))
            {
                DAT_1031f93c->field_0x4->SetEventWait();
            }
        }
        else
        {
            hhMTSimpleJobLinkNext(job, updateHint.field_0x8.get(), 0);
        }
    }
}

void hhMTSimpleJobBlockUntilSignal(SJobJoint* jobJoint, unsigned int signal)
{
    // TODO: Is this ifdef block actually an inlined RSDX function?
#ifdef __WIIU__
    void* displayList;
    uint32_t displayListSize;
    bool makingCommandBuffer = GX2GetCurrentDisplayList(&displayList, &displayListSize);
#else
    bool makingCommandBuffer = true;
#endif

    DAT_1031f93c->MTSimpleJobBlockUntilSignal(
        jobJoint->field_0x8, !makingCommandBuffer, signal);

    while (jobJoint->field_0x4 != 0)
    {
        RsdxThreadSleep(1);
    }
}
}
}
