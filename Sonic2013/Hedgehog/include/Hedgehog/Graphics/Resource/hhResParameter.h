#pragma once
#include "hhResUserData.h"

namespace hh
{
namespace gfx
{
namespace res
{
struct ResShaderSamplerData; // TODO: Move this to its own header!!!

struct ResParameterData // size == 32
{
    ResUserDataItemData* field_0x0;
    std::size_t field_0x4;
    std::size_t field_0x8;
    ResShaderSamplerData* ShaderSamplers;
    std::size_t field_0x10;
    std::size_t field_0x14;
    std::size_t field_0x18;
    std::size_t NumSamplers;
};

struct ResParameter : public ut::ResCommon<ResParameterData>
{
    inline ResParameter(const void* data) :
        ResCommon<ResParameterData>(data) {}

    inline ResParameter(void* data = nullptr) :
        ResCommon<ResParameterData>(data) {}
};
}
}
}
