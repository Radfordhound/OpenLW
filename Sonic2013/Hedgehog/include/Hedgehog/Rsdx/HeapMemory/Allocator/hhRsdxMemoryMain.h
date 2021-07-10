#pragma once
#include <cstddef>

namespace hh
{
namespace rsdx
{
#ifdef __WIIU__
// Wii U: 0x036adfc4, PC: N/A
void* RsdxAllocateDefaultMemoryCafe(int allocID,
    std::size_t size, std::size_t alignment = 16);
#endif

// Wii U: 0x036adbc0, PC: 0x00c1e1f0
void* RsdxAllocateDefaultMemoryStandard(int allocID,
    std::size_t size, std::size_t alignment = 16);

// Wii U: 0x02002748 (THUNK), PC: 0x004025e0 (THUNK)
void* RsdxAllocateDefaultMemory(int allocID,
    std::size_t size, std::size_t alignment = 16);

// Wii U: TODO, PC: 0x00c1b680
void RsdxFreeDefaultMemoryStandard(int allocID, void* ptr);

// Wii U: TODO, PC: 0x004025f0 (THUNK)
void RsdxFreeDefaultMemory(int allocID, void* ptr);

// TODO
}
}
