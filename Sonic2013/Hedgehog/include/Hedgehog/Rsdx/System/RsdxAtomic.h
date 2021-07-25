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

inline void RsdxInitializeSListHead(RsdxSListHeader* header)
{
    InitializeSListHead(&header->_Impl);
}
#else
struct RsdxSListEntry
{
    RsdxSListEntry* Next;
};

struct RsdxSListHeader; // TODO

inline void RsdxInitializeSListHead(RsdxSListHeader* header)
{
    // TODO
}
#endif

// Wii U: 0x036a74d8, PC: Inlined
void RsdxAtomicPushSList(RsdxSListHeader* header, RsdxSListEntry* entry);

// Wii U: 0x036a7524, PC: Inlined
RsdxSListEntry* RsdxAtomicPopSList(RsdxSListHeader* header);

// Wii U: 0x036a7564, PC: Inlined
RsdxAtomic RsdxAtomicInc(RsdxAtomic* v);

// Wii U: 0x036a7598, PC: Inlined
RsdxAtomic RsdxAtomicInc2(RsdxAtomic* v);
}
}
