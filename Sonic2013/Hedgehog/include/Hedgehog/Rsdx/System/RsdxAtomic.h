#pragma once

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif

namespace hh
{
namespace rsdx
{
typedef volatile unsigned int RsdxAtomic;

#ifdef _WIN32
typedef SLIST_ENTRY RsdxSListEntry;
//typedef SLIST_HEADER RsdxSListHeader;

struct RsdxSListHeader
{
    SLIST_HEADER _Impl;
};

#define RsdxInitializeSListHead(header) InitializeSListHead(&(header)->_Impl)
#define RsdxPeekSListOne(header) ((header)->_Impl.Next.Next)
#else
struct RsdxSListEntry
{
    RsdxSListEntry* Next;
};

struct RsdxSListHeader
{
    RsdxSListEntry* Next;
}

#define RsdxInitializeSListHead(header) // TODO
#define RsdxPeekSListOne(header) // TODO
#endif

LWAPI(0x036a74d8, NONE)
void RsdxAtomicPushSList(RsdxSListHeader* header, RsdxSListEntry* entry);

LWAPI(0x036a7524, NONE)
RsdxSListEntry* RsdxAtomicPopSList(RsdxSListHeader* header);

LWAPI(0x036a754c, NONE)
RsdxSListEntry* RsdxAtomicPopSListWhole(RsdxSListHeader* header, RsdxSListEntry* entry);

LWAPI(0x036a7564, NONE)
RsdxAtomic RsdxAtomicInc(RsdxAtomic* v);

LWAPI(0x036a7598, NONE)
RsdxAtomic RsdxAtomicInc2(RsdxAtomic* v);

LWAPI(0x036a75e8, TODO)
RsdxAtomic RsdxAtomicDec2(RsdxAtomic* v);
}
}
