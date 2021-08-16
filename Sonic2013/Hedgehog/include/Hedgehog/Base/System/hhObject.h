#pragma once
#include "hhMemory.h"
#include <Hedgehog/Rsdx/System/RsdxAtomic.h>

namespace hh
{
namespace base
{
class CObject
{
public:
    // Wii U: 0x0369946c, PC: TODO
    static void* operator new(std::size_t size,
        const CHedgehogMemoryAllocatorFileLine& fileLineInfo,
        CHedgehogMemoryAllocatorHeap heap);

    // TODO: Is this function a thing?
    inline void operator delete(void* ptr,
        const CHedgehogMemoryAllocatorFileLine& fileLineInfo,
        CHedgehogMemoryAllocatorHeap heap)
    {
        return __HH_FREE(ptr);
    }

    // Wii U: 0x0369973c, PC: 0x00c1e780
    static void* operator new(std::size_t size);

    // Wii U: 0x0369981c (THUNK), PC: TODO
    static void operator delete(void* ptr);
};

class CRefCountObject
{
    rsdx::RsdxAtomic m_refCount;

public:
    // Wii U: 0x03699874, PC: 0x00442340
    virtual ~CRefCountObject();

    // Wii U: 0x036998f8, PC: TODO
    std::size_t RefCount() const;

    // Wii U: 0x03699900, PC: TODO
    bool IsUnique() const;

    // Wii U: 0x03699888, PC: TODO
    void AddRef();

    // Wii U: 0x0369988c, PC: TODO
    void Release();

    // Wii U: 0x0369982c, PC: TODO
    CRefCountObject();
};

inline void intrusive_ptr_add_ref(CRefCountObject* obj)
{
    obj->AddRef();
}

inline void intrusive_ptr_release(CRefCountObject* obj)
{
    obj->Release();
}
}
}
