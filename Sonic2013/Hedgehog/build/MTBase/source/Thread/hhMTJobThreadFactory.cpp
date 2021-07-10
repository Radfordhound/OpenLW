#include "Hedgehog/MTBase/Thread/hhMTJobThreadFactory.h"
#include <Hedgehog/Base/System/hhMemoryAllocator.h>
#include <Hedgehog/Rsdx/System/RsdxThread.h>
#include <Hedgehog/Rsdx/System/RsdxEvent.h>
#include <cstring>

namespace hh
{
using namespace rsdx;

namespace MTBase
{
SJobJoint* CMTJobMemorySystemUtil::DAT_1031f92c;
std::size_t CMTJobMemorySystemUtil::DAT_1031f930;
SJobJoint* CMTJobMemorySystemUtil::DAT_1031f934;
rsdx::RsdxSListHeader CMTJobMemorySystemUtil::EventHolder;

void CMTJobMemorySystemUtil::PushListOne(void* param_1, void* param_2)
{
    RsdxAtomicPushSList(static_cast<RsdxSListHeader*>(param_1),
        static_cast<RsdxSListEntry*>(param_2));
}

void* CMTJobMemorySystemUtil::PopListOne(rsdx::RsdxSListHeader* param_1)
{
    return RsdxAtomicPopSList(param_1);
}

void CMTJobMemorySystemUtil::InitializeList(void* param_1)
{
    RsdxInitializeSListHead(static_cast<RsdxSListHeader*>(param_1));
}

void CMTJobMemorySystemUtil::InitializeJobMemory(std::size_t param_1)
{
    DAT_1031f930 = (param_1 / sizeof(SJobJoint));
    DAT_1031f92c = static_cast<SJobJoint*>(__HH_ALLOCALIGN(param_1, 128));
    std::memset(DAT_1031f92c, 0, param_1);

    DAT_1031f934 = reinterpret_cast<SJobJoint*>(
        reinterpret_cast<char*>(DAT_1031f92c) + param_1);

    InitializeList(DAT_1031f92c);

    for (std::size_t i = 1; i < DAT_1031f930; ++i)
    {
        PushListOne(DAT_1031f92c, &DAT_1031f92c[i]);
    }
}

void* CMTJobMemorySystemUtil::Allocate(std::size_t size)
{
    return (size >= 256) ? PopListOne(DAT_1031f92c) : nullptr;
}

void CMTJobMemorySystemUtil::FreeEventHolder(SEventHolder* eventHolder)
{
    RsdxAtomicPushSList(&EventHolder, eventHolder);
}

void CMTJobMemorySystemUtil::InitializeEventHolder(std::size_t count)
{
    RsdxInitializeSListHead(&EventHolder);

    for (std::size_t i = 0; i < count; ++i)
    {
        RsdxEventHandle event = RsdxCreateEvent(1, 1);

        SEventHolder* eventHolder = static_cast<SEventHolder*>(
            __HH_ALLOCALIGN(sizeof(SEventHolder)));

        eventHolder->Event = event;

        FreeEventHolder(eventHolder);
    }
}

SEventHolder* CMTJobMemorySystemUtil::AllocEventHolder()
{
    return static_cast<SEventHolder*>(RsdxAtomicPopSList(&EventHolder));
}

CMTSimpleJobInternal::CMTSimpleJobInternal(std::size_t param_1)
{
    // TODO

    CMTJobMemorySystemUtil::InitializeJobMemory(0x20000);
    CMTJobMemorySystemUtil::InitializeEventHolder(0x20);

    // TODO
}

void CMTSimpleJobInternal::MTSimpleJobBlockUntilSignal(SEventHolder* param1,
    bool param2, unsigned int param3)
{
    // TODO
}

static CMTSimpleJobInternal* SimpleJob = nullptr;

void hhMTSimpleJobStart()
{
    if (!SimpleJob)
    {
        SimpleJob = new CMTSimpleJobInternal(0x20000);
    }

    // TODO
}

SJobType256* hhMTSimpleJobCreateDefault()
{
    SJobType256* job;
    while (!(job = static_cast<SJobType256*>(CMTJobMemorySystemUtil::Allocate())))
    {
        RsdxThreadSleep(1);
    }

    std::memset(job, 0, 256);
    return job;
}

SJobJoint* hhMTSimpleJobJointCreate()
{
    SJobJoint* jobJoint;
    while (!(jobJoint = static_cast<SJobJoint*>(CMTJobMemorySystemUtil::Allocate())))
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

void hhMTSimpleJobBlockUntilSignal(SJobJoint* jobJoint, unsigned int signal)
{
    // TODO

    while (jobJoint->field_0x4)
    {
        RsdxThreadSleep(1);
    }
}
}
}
