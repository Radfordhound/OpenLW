#pragma once
#include "csl/fnd/IAllocator.h"
#include "BaseObject.h"

namespace app
{
namespace fnd
{
class ReferencedObject : public BaseObject
{
protected:
    unsigned short size;
    unsigned short refCount = 0;
    csl::fnd::IAllocator* allocator;

public:
    // TODO: Does ReferencedObject have a constructor?
    inline ReferencedObject()
    {
        //++refCount;
    }

    /* <b>Wii U: TODO, PC: TODO</b> */
    inline void AddRef()
    {
        if (size) ++refCount;
    }

    /* <b>Wii U: 0x02185188, PC: 0x0048d460</b> */
    inline void Release()
    {
        if (size && --refCount == 0)
        {
            delete this;
        }
    }

    /* <b>Wii U: 0x021851bc, PC: 0x0048d4a0</b> */
    inline static void* operator new(std::size_t size, csl::fnd::IAllocator* allocator)
    {
        // Allocate a new ReferencedObject of the given size
        ReferencedObject* obj = static_cast<ReferencedObject*>(
            allocator->Alloc(size, 0x20));

        // Construct the new ReferencedObject if allocation succeeded and return
        if (obj)
        {
            obj->allocator = allocator;
            obj->size = static_cast<unsigned short>(size);
        }

        return obj;
    }

    /* <b>Wii U: 0x02185154, PC: 0x0048d480</b> */
    inline static void operator delete(void* ptr)
    {
        // Free the given ReferencedObject using its assigned allocator
        ReferencedObject* obj = static_cast<ReferencedObject*>(ptr);
        if (obj->allocator) obj->allocator->Free(ptr);
    }
};
}
}
