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
}
}
