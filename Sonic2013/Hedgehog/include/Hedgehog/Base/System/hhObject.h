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
    LWAPI(0x0369946c, TODO)
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

    LWAPI(0x0369973c, 0x00c1e780)
    static void* operator new(std::size_t size);

    LWAPI(0x0369981c, TODO)
    static void operator delete(void* ptr);
};

class CRefCountObject
{
    rsdx::RsdxAtomic m_refCount;

public:
    LWAPI(0x03699874, 0x00442340)
    virtual ~CRefCountObject();

    LWAPI(0x036998f8, TODO)
    std::size_t RefCount() const;

    LWAPI(0x03699900, TODO)
    bool IsUnique() const;

    LWAPI(0x03699888, 0x00c1e850)
    void AddRef();

    LWAPI(0x0369988c, TODO)
    void Release();

    LWAPI(0x0369982c, NONE)
    CRefCountObject() :
        m_refCount(0) {}
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
