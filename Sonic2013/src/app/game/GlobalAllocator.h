#pragma once
#include "csl/fnd/IAllocator.h"

namespace app
{
namespace game
{
struct GlobalAllocator
{
    /* <b>Wii U: 0x02230294, PC: 0x004d0c90</b> */
    static csl::fnd::IAllocator* GetAllocator(csl::fnd::AllocatorID type);

    /* <b>Wii U: 0x022302a8, PC: TODO</b> */
    static void SetAllocator(csl::fnd::AllocatorID type,
        csl::fnd::IAllocator* allocator);
};
}
}
