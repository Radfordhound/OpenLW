#pragma once
#include "hhStackAllocator.h"

namespace Extra
{
namespace fx
{
struct RenderScratchBuffer
{
    char Padding[8]; // TODO
    Extra::fx::SStackAllocator Allocator;
};
}
}
