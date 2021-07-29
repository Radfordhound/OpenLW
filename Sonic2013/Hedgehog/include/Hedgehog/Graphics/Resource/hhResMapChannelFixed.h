#pragma once
#include "hhResNameData.h"

namespace hh
{
namespace gfx
{
namespace res
{
struct ResMapChannelFixedData // size == 12
{
    ResNameData SlotName;
    unsigned int field_0x8;
};

struct ResMapChannelFixed : public ut::ResCommon<ResMapChannelFixedData>
{
    // Wii U: 0x0367cc94, PC: TODO
    ResName GetSlotName();

    inline ResMapChannelFixed(const void* data) :
        ResCommon<ResMapChannelFixedData>(data) {}

    inline ResMapChannelFixed(void* data = nullptr) :
        ResCommon<ResMapChannelFixedData>(data) {}
};
}
}
}
