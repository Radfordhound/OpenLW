#pragma once
#include "hhResShaderConstantUsage.h"

namespace hh
{
namespace gfx
{
namespace res
{
struct ResShaderConstantData // size == 28
{
    ResShaderConstantUsageData* Usages[2];
    unsigned int field_0x8;
    unsigned int field_0xc;
    void* Data;
    ResNameData UsageName;
};

struct ResShaderConstant : public ut::ResCommon<ResShaderConstantData>
{
    // Wii U: 0x0367b148, PC: TODO
    ResShaderConstantUsage GetUsage(std::size_t index) const;

    // Wii U: 0x0367b1c8, PC: TODO
    ResName GetUsageName();

    inline ResShaderConstant(std::nullptr_t) :
        ResCommon<ResShaderConstantData>() {}

    inline ResShaderConstant(const void* data) :
        ResCommon<ResShaderConstantData>(data) {}

    inline ResShaderConstant(void* data = nullptr) :
        ResCommon<ResShaderConstantData>(data) {}
};
}
}
}
