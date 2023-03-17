// TODO: Both the name of this file and its path were guessed!
#pragma once
#include <Hedgehog/Utility/hhPackfile.h>
#include <csl/fnd/memory.h>

namespace app
{
namespace fnd
{
struct ResourceCallbackBase
{
    unsigned int RefCount;
    csl::fnd::IAllocator* Allocator;

    // TODO: Does this constructor actually exist?
    inline ResourceCallbackBase(unsigned int initialRefCount, csl::fnd::IAllocator* allocator) :
        RefCount(initialRefCount),
        Allocator(allocator) {}

    virtual void SetupCallback(hh::ut::Packfile pac, csl::fnd::IAllocator* allocator) {}
    
    virtual void CleanupCallback(hh::ut::Packfile pac) {}
};

// TODO: Is this correct?
inline void intrusive_ptr_add_ref(ResourceCallbackBase* callback)
{
    ++callback->RefCount;
}

// TODO: Is this correct?
inline void intrusive_ptr_release(ResourceCallbackBase* callback)
{
    --callback->RefCount;
}
}
}
