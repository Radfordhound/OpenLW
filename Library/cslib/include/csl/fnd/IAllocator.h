#pragma once
#include <cstddef>

namespace csl
{
namespace fnd
{
enum class AllocatorID
{
    UkZero = 0,
    UkOne = 1,
    UkTwo = 2,
    Debug = 3 // TODO: Is this right??
};

struct IAllocator
{
    /*
        @brief Destructor for IAllocator.
        <b>Wii U: [Inlined], PC: 0x00445a00</b>
    */
    virtual inline ~IAllocator() = default;

    /*
        @brief Allocates the requested amount of memory with the requested alignment.
        @param[in] size         The amount of memory to allocate.
        @param[in] alignment    The alignment the allocated memory should have.
        @return A pointer to the allocated memory, or nullptr if allocation failed.
    */
    virtual void* Alloc(std::size_t size, int alignment = 16) = 0;

    /*
        @brief Frees the given memory.
        @param[in] ptr  A pointer to the memory to free. Must have been allocated using Alloc.
        @remarks Calling Free on memory not allocated using this allocator's Alloc is undefined behavior.
    */
    virtual void Free(void* ptr) = 0;
};
}
}
