#pragma once

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
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

// Wii U: 0x036a74d8, PC: Inlined
void RsdxAtomicPushSList(RsdxSListHeader* header, RsdxSListEntry* entry);

// Wii U: 0x036a7524, PC: Inlined
RsdxSListEntry* RsdxAtomicPopSList(RsdxSListHeader* header);

// Wii U: 0x036a754c, PC: Inlined
RsdxSListEntry* RsdxAtomicPopSListWhole(RsdxSListHeader* header, RsdxSListEntry* entry);

// Wii U: 0x036a7564, PC: Inlined
RsdxAtomic RsdxAtomicInc(RsdxAtomic* v);

// Wii U: 0x036a7598, PC: Inlined
RsdxAtomic RsdxAtomicInc2(RsdxAtomic* v);

// Wii U: 0x036a75e8, PC: TODO
RsdxAtomic RsdxAtomicDec2(RsdxAtomic* v);
}
}
