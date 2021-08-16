#include "Hedgehog/MTBase/hhMTJobMemorySystemUtil.h"
#include "Hedgehog/MTBase/hhJobJoint.h"
#include <Hedgehog/Base/System/hhMemory.h>
#include <Hedgehog/Rsdx/System/RsdxAtomic.h>
#include <cstring>

using namespace hh::rsdx;

namespace hh
{
namespace MTBase
{
SJobJoint* CMTJobMemorySystemUtil::DAT_1031f92c;
std::size_t CMTJobMemorySystemUtil::DAT_1031f930;
SJobJoint* CMTJobMemorySystemUtil::DAT_1031f934;
rsdx::RsdxSListHeader CMTJobMemorySystemUtil::EventHolders;

void CMTJobMemorySystemUtil::PushListOne(void* param_1, void* param_2)
{
    RsdxAtomicPushSList(static_cast<RsdxSListHeader*>(param_1),
        static_cast<RsdxSListEntry*>(param_2));
}

void* CMTJobMemorySystemUtil::PopListOne(void* param_1)
{
    return RsdxAtomicPopSList(static_cast<rsdx::RsdxSListHeader*>(param_1));
}

void CMTJobMemorySystemUtil::InitializeList(void* param_1)
{
    RsdxInitializeSListHead(static_cast<RsdxSListHeader*>(param_1));
}

RsdxSListEntry* CMTJobMemorySystemUtil::PeekListOne(void* param_1)
{
    return RsdxPeekSListOne(static_cast<RsdxSListHeader*>(param_1));
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
        PushListOne(DAT_1031f92c, DAT_1031f92c + i);
    }
}

void CMTJobMemorySystemUtil::FinalizeJobMemory()
{
    __HH_FREE(DAT_1031f92c);
    DAT_1031f92c = nullptr;
    DAT_1031f930 = 0;
    DAT_1031f934 = nullptr;
}

void* CMTJobMemorySystemUtil::Allocate(std::size_t size)
{
    return (size >= 256) ? PopListOne(DAT_1031f92c) : nullptr;
}

void CMTJobMemorySystemUtil::Free(void* param_1, std::size_t size)
{
    if (!param_1) return;
    PushListOne(DAT_1031f92c, param_1);
}

void CMTJobMemorySystemUtil::FreeEventHolder(SEventHolder* eventHolder)
{
    RsdxAtomicPushSList(&EventHolders, eventHolder);
}

void CMTJobMemorySystemUtil::InitializeEventHolder(std::size_t count)
{
    RsdxInitializeSListHead(&EventHolders);

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
    return static_cast<SEventHolder*>(RsdxAtomicPopSList(&EventHolders));
}

void CMTJobMemorySystemUtil::FinalizeEventHolder()
{
    SEventHolder* eventHolder;
    while ((eventHolder = AllocEventHolder()))
    {
        RsdxDestroyEvent(eventHolder->Event);
        __HH_FREE(eventHolder);
    }
}
}
}
