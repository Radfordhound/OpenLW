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

bool RsdxSystemResource::DeleteThis()
{
    bool r = CloseSystemResource();
    delete this;
    return r;
}

RsdxSystemResource::~RsdxSystemResource() {}
}
}
