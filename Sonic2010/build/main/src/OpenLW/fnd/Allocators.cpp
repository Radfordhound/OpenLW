#include "Allocators.h"
#include "../game/GlobalAllocator.h"

namespace app
{
namespace fnd
{
csl::fnd::IAllocator* GetTempAllocator()
{
    // TODO
    return game::GlobalAllocator::GetAllocator(ALLOCATOR_UNK_TWO);
}

csl::fnd::IAllocator* GetSingletonAllocator()
{
	return game::GlobalAllocator::GetAllocator(ALLOCATOR_UNK_TWO);
}

csl::fnd::IAllocator* getDebugAllocator()
{
    return game::GlobalAllocator::GetAllocator(ALLOCATOR_DEBUG);
}
}
}
