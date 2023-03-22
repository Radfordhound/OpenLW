// TODO: The name of this file is correct, but the path was guessed!
#include "OpenLW/pch.h"
#include "PooledAllocator.h"
#include "GlobalAllocator.h"

namespace app
{
namespace fnd
{
csl::fnd::IAllocator* getDebugAllocator()
{
    return game::GlobalAllocator::GetAllocator(ALLOCATOR_DEBUG);
}
}
}
