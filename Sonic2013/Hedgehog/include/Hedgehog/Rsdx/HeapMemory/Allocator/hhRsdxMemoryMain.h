#pragma once
#include <cstddef>

namespace hh
{
namespace rsdx
{
#ifdef __WIIU__
LWAPI(0x036adfc4, NONE)
void* RsdxAllocateDefaultMemoryCafe(int allocID,
    std::size_t size, std::size_t alignment = 16);
#endif

LWAPI(0x036adbc0, 0x00c1e1f0)
void* RsdxAllocateDefaultMemoryStandard(int allocID,
    std::size_t size, std::size_t alignment = 16);

LWAPI(0x02002748, 0x004025e0)
void* RsdxAllocateDefaultMemory(int allocID,
    std::size_t size, std::size_t alignment = 16);

LWAPI(TODO, 0x00c1b680)
void RsdxFreeDefaultMemoryStandard(int allocID, void* ptr);

LWAPI(TODO, 0x004025f0)
void RsdxFreeDefaultMemory(int allocID, void* ptr);

// TODO
}
}
