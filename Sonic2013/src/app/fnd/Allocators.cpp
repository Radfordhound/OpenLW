#include "Allocators.h"
#include "../game/GlobalAllocator.h"

namespace app
{
namespace fnd
{
csl::fnd::IAllocator* GetTempAllocator()
{
    // TODO
    return nullptr;
}

csl::fnd::IAllocator* GetSingletonAllocator()
{
    return game::GlobalAllocator::GetAllocator(csl::fnd::AllocatorID::UkTwo);
}

csl::fnd::IAllocator* getDebugAllocator()
{
    return game::GlobalAllocator::GetAllocator(csl::fnd::AllocatorID::Debug);
}
}
}
