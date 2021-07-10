#include "ReferencedObject.h"

namespace app
{
namespace fnd
{
void ReferencedObject::Release()
{
    if (m_size && --m_refCount == 0)
    {
        delete this;
    }
}

void* ReferencedObject::operator new(std::size_t size, void* ptr)
{
    // Construct the referenced object in-place and return.
    ReferencedObject* obj = static_cast<ReferencedObject*>(ptr);
    if (obj)
    {
        obj->m_size = 0;
        obj->m_allocator = nullptr;
    }

    return obj;
}

void* ReferencedObject::operator new(std::size_t size, csl::fnd::IAllocator* allocator)
{
    // Allocate a new ReferencedObject of the given size.
    ReferencedObject* obj = static_cast<ReferencedObject*>(
        allocator->Alloc(size, 0x20));

    // Construct the new ReferencedObject if allocation succeeded and return.
    if (obj)
    {
        obj->m_size = static_cast<unsigned short>(size);
        obj->m_allocator = allocator;
    }

    return obj;
}

void* ReferencedObject::operator new(std::size_t size, void* ptr,
    csl::fnd::IAllocator* allocator, std::size_t objSize)
{
    // Construct the referenced object in-place and return.
    ReferencedObject* obj = static_cast<ReferencedObject*>(ptr);
    if (obj)
    {
        obj->m_size = static_cast<unsigned short>(objSize);
        obj->m_allocator = allocator;
    }

    return obj;
}

void ReferencedObject::operator delete(void* ptr)
{
    // Free the given ReferencedObject using its assigned allocator.
    ReferencedObject* obj = static_cast<ReferencedObject*>(ptr);
    if (obj->m_allocator) obj->m_allocator->Free(ptr);
}
}
}
