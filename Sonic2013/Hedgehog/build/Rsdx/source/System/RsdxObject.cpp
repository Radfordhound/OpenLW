#include "pch.h"
#include "Hedgehog/Rsdx/System/RsdxObject.h"
#include "Hedgehog/Rsdx/HeapMemory/Allocator/hhRsdxMemoryMain.h"

namespace hh
{
namespace rsdx
{
void* RsdxObject::operator new(std::size_t size)
{
    return RsdxAllocateDefaultMemory(0, size);
}

void* RsdxObject::operator new(std::size_t size, void* ptr)
{
    return ptr;
}

void RsdxObject::operator delete(void* ptr)
{
    // TODO
}

#ifndef _WIN32
RsdxAtomic RsdxRefcountObject::AddRef()
{
    // TODO
    return 0; // TODO
}

RsdxAtomic RsdxRefcountObject::Release()
{
    // TODO: Un-comment the following:
    /*RsdxAtomic refCount = RsdxAtomicDec2(&m_refCount);
    if ((refCount & 0x3fffffff) == 0)
    {
        ReleaseInternal(this, refCount);
    }

    return (refCount & 0x3fffffff);*/
    return 0; // TODO
}
#endif

bool RsdxSystemResource::DeleteThis()
{
    bool r = CloseSystemResource();
    delete this;
    return r;
}

RsdxSystemResource::~RsdxSystemResource() {}
}
}
