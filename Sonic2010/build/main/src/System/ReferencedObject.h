// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include "BaseObject.h"
#include "Atomic.h"
#include <csl/fnd/memory.h>

namespace app
{
namespace fnd
{
class ReferencedObject : public BaseObject
{
OPENLW_PROTECTED
    unsigned short m_size;
    unsigned short m_refCount;
    csl::fnd::IAllocator* m_allocator;

public:
    // TODO: Is this function actually a thing?
    inline void AddRef()
    {
        if (m_size) ++m_refCount;
    }

    LWAPI(0x02185188, 0x0048d460)
    void Release();

    LWAPI(0x0218521c, 0x0048d4d0)
    static void* operator new(std::size_t size, void* ptr);

    LWAPI(0x021851bc, 0x0048d4a0)
    static void* operator new(std::size_t size, csl::fnd::IAllocator* allocator);

    LWAPI(0x02185234, 0x0048d4f0)
    static void* operator new(std::size_t size, void* ptr,
        csl::fnd::IAllocator* allocator, std::size_t objSize);

    LWAPI(0x02185154, 0x0048d480)
    static void operator delete(void* ptr);

    // TODO: Is this function a thing?
    static void operator delete(void* ptr,
        csl::fnd::IAllocator* allocator)
    {
        allocator->Free(ptr);
    }

    // TODO: Is this function a thing?
    static void operator delete(void* ptr1, void* ptr2,
        csl::fnd::IAllocator* allocator, std::size_t objSize)
    {
        allocator->Free(ptr1);
    }

    // TODO: Is this function actually a thing?
    inline ReferencedObject() :
        m_refCount(0) {}
};

struct ThreadSafeReferencedObject : public ReferencedObject
{
    Atomic m_safeRefCount;
    // TODO: Are there any additional data members?

    // TODO: Is this function actually a thing?
    inline void AddRef()
    {
        if (m_size) AtomicInc(m_safeRefCount);
    }

    // TODO: Is this function actually a thing?
    inline void Release()
    {
        if (m_size && AtomicDec(m_safeRefCount) == 0)
        {
            delete this;
        }
    }

    // TODO: Is this function actually a thing?
    inline ThreadSafeReferencedObject() :
        m_safeRefCount(0) {} // TODO: uhh it seems the game doesn't actually initialize this to 0?? what
};

// TODO: Is this correct?
inline void intrusive_ptr_add_ref(ReferencedObject* obj)
{
    obj->AddRef();
}

// TODO: Is this correct?
inline void intrusive_ptr_release(ReferencedObject* obj)
{
    obj->Release();
}
} // fnd
} // app
