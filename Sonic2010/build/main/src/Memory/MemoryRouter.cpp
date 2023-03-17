// TODO: The name of this file is correct, but the path was guessed!
#include "MemoryRouter.h"
#include "GlobalAllocator.h"

namespace app
{
namespace fnd
{
csl::fnd::IAllocator* GetTempAllocator()
{
    // TODO
    return game::GlobalAllocator::GetAllocator(ALLOCATOR_UNK_TWO);
}
}
}
