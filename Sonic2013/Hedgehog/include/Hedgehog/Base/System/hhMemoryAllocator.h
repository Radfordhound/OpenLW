#pragma once
#include <csl/fnd/memory.h>

#define __HH_ALLOC_DBG(size) __HH_ALLOC((size), ::CHedgehogMemoryAllocatorFileLine(__LINE__, __FILE__))

class CHedgehogMemoryAllocatorFileLine
{
    unsigned int m_lineNum;
    const char* m_filePath;

public:
    inline CHedgehogMemoryAllocatorFileLine(
        unsigned int lineNum, const char* filePath) :
        m_lineNum(lineNum),
        m_filePath(filePath) {}
};

// Wii U: 0x036984E8, PC: TODO
void __HH_FREE(void* ptr);

// Wii U: 0x03698554, PC: TODO
void* __HH_ALLOC(std::size_t size);

// Wii U: 0x036985c8, PC: TODO
void* __HH_ALLOC(std::size_t size, const CHedgehogMemoryAllocatorFileLine& fileLineInfo);

// Wii U: 0x03698724, PC: 0x00c1b230
void* __HH_ALLOCALIGN(std::size_t size, std::size_t alignment = 16);

namespace hh
{
namespace base
{
class CMemoryAllocator
{
    // Wii U: 0x1031f2c0, PC: TODO
    static csl::fnd::IAllocator* Allocator;

public:
    // Wii U: 0x03698b1c, PC: TODO
    static csl::fnd::IAllocator* GetCSLAllocator();

    // Wii U: 0x03698b10, PC: TODO
    static void SetCSLAllocator(csl::fnd::IAllocator* allocator);
};
}
}
