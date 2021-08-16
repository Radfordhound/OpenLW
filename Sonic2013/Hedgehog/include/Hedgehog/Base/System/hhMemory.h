#pragma once
#include <cstddef>

#define __HH_DBG_INFO ::CHedgehogMemoryAllocatorFileLine(__LINE__, __FILE__)
#define __HH_ALLOC_DBG(size) __HH_ALLOC((size), __HH_DBG_INFO)

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

class CHedgehogMemoryAllocatorHeap // TODO: Inheritance?
{
    // TODO
};

// Wii U: 0x036984E8, PC: TODO
void __HH_FREE(void* ptr);

// Wii U: 0x03698554, PC: TODO
void* __HH_ALLOC(std::size_t size);

// Wii U: 0x036985c8, PC: TODO
void* __HH_ALLOC(std::size_t size, const CHedgehogMemoryAllocatorFileLine& fileLineInfo);

// Wii U: 0x036986b0, PC: TODO
void* __HH_ALLOC(std::size_t size, const CHedgehogMemoryAllocatorFileLine& fileLineInfo,
    CHedgehogMemoryAllocatorHeap heap);

// Wii U: 0x03698724, PC: 0x00c1b230
void* __HH_ALLOCALIGN(std::size_t size, std::size_t alignment = 16);