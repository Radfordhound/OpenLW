#include "pch.h"
#include "Hedgehog/Rsdx/System/RsdxAtomic.h"

namespace hh
{
namespace rsdx
{
void RsdxAtomicPushSList(RsdxSListHeader* header, RsdxSListEntry* entry)
{
#ifdef _WIN32
    InterlockedPushEntrySList(&header->_Impl, entry);
#elif defined(__WIIU__)
    // TODO
#endif
}

RsdxSListEntry* RsdxAtomicPopSList(RsdxSListHeader* header)
{
#ifdef _WIN32
    return InterlockedPopEntrySList(&header->_Impl);
#elif defined(__WIIU__)
    // TODO
    return nullptr;
#endif
}

RsdxSListEntry* RsdxAtomicPopSListWhole(RsdxSListHeader* header, RsdxSListEntry* entry)
{
#ifdef _WIN32
    // TODO: Do we do anything with the second argument?
    return InterlockedFlushSList(&header->_Impl);
#else
    // TODO
#endif
}

RsdxAtomic RsdxAtomicInc(RsdxAtomic* v)
{
    // TODO!!!
    return 0;
}

RsdxAtomic RsdxAtomicInc2(RsdxAtomic* v)
{
#ifdef _WIN32
    return InterlockedIncrement(v);
#else
    // TODO
#endif
}

RsdxAtomic RsdxAtomicDec2(RsdxAtomic* v)
{
#ifdef _WIN32
    return InterlockedDecrement(v);
#else
    // TODO
#endif
}
}
}
