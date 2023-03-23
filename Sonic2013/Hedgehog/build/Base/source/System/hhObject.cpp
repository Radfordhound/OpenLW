#include "pch.h"
#include "Hedgehog/Base/System/hhObject.h"

using namespace hh::rsdx;

namespace hh
{
namespace base
{
void* CObject::operator new(std::size_t size,
    const CHedgehogMemoryAllocatorFileLine& fileLineInfo,
    CHedgehogMemoryAllocatorHeap heap)
{
    return __HH_ALLOC(size, fileLineInfo, heap);
}

void* CObject::operator new(std::size_t size)
{
    return __HH_ALLOC(size);
}

void CObject::operator delete(void* ptr)
{
    return __HH_FREE(ptr);
}

CRefCountObject::~CRefCountObject() {}

std::size_t CRefCountObject::RefCount() const
{
    return m_refCount;
}

bool CRefCountObject::IsUnique() const
{
    return (RefCount() == 1);
}

void CRefCountObject::AddRef()
{
    RsdxAtomicInc2(&m_refCount);
}

void CRefCountObject::Release()
{
    if (RsdxAtomicDec2(&m_refCount) == 0)
    {
        delete this;
    }
}
}
}
