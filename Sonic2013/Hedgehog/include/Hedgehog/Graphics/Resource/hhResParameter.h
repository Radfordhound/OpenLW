#pragma once
#include "hhResUserData.h"

namespace hh
{
namespace gfx
{
namespace res
{
struct ResShaderConstantData;
struct ResShaderSamplerData;

struct ResParameterData // size == 32
{
    ResShaderConstantData* Float4Constants;
    ResShaderConstantData* Int4Constants;
    ResShaderConstantData* Bool4Constants;
    ResShaderSamplerData* Samplers;
    std::size_t Float4ConstantCount;
    std::size_t Int4ConstantCount;
    std::size_t Bool4ConstantCount;
    std::size_t SamplerCount;
};

struct ResParameter : public ut::ResCommon<ResParameterData>
{
    inline ResParameter(std::nullptr_t) :
        ResCommon<ResParameterData>() {}

    inline ResParameter(const void* data) :
        ResCommon<ResParameterData>(data) {}

    inline ResParameter(void* data = nullptr) :
        ResCommon<ResParameterData>(data) {}
};
}
}
}
