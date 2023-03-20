#include "pch.h"
#include "Hedgehog/Rsdx/HeapMemory/Allocator/hhRsdxMemoryMain.h"
#include "Hedgehog/Rsdx/HeapMemory/hhRsdxMemoryUtil.h"

namespace hh
{
namespace rsdx
{
struct ALLOCATORFUNCTIONS // size == 32
{
    // TODO
};

LWAPI(0x1031f4d4, TODO)
static ALLOCATORFUNCTIONS AllocatorFunctions[4]; // TODO: This name was guessed. What's its actual name?

#ifdef __WIIU__
void* RsdxAllocateDefaultMemoryCafe(int allocID,
    std::size_t size, std::size_t alignment)
{
    // TODO
    return nullptr;
}
#endif

void* RsdxAllocateDefaultMemoryStandard(int allocID,
    std::size_t size, std::size_t alignment)
{
    // TODO

    //if ((alignment & -alignment) != alignment)
    if ((alignment & (alignment - 1)) == 0) // TODO: Does this achieve the correct result?
    {
        MemoryUtil::ThrowAssert();
    }

    ALLOCATORFUNCTIONS& allocFuncs = AllocatorFunctions[allocID];
    // TODO
    return nullptr; // TODO
}

void* RsdxAllocateDefaultMemory(int allocID,
    std::size_t size, std::size_t alignment)
{
    return RsdxAllocateDefaultMemoryStandard(
        allocID, size, alignment);
}

void RsdxFreeDefaultMemoryStandard(int allocID, void* ptr)
{
    if (ptr && ptr != reinterpret_cast<void*>(0xffff0000))
    {
        ALLOCATORFUNCTIONS& allocFuncs = AllocatorFunctions[allocID];
        // TODO
    }
}

void RsdxFreeDefaultMemory(int allocID, void* ptr)
{
    RsdxFreeDefaultMemoryStandard(allocID, ptr);
}
}
}
