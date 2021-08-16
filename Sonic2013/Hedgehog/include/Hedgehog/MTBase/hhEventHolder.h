#pragma once
#include <Hedgehog/Rsdx/System/RsdxEvent.h>
#include <Hedgehog/Rsdx/System/RsdxAtomic.h>

namespace hh
{
namespace MTBase
{
struct SEventHolder : public rsdx::RsdxSListEntry // size == 8
{
    rsdx::RsdxEventHandle Event;
};
}
}
