#pragma once
#include "hhResNameData.h"

namespace hh
{
namespace gfx
{
namespace res
{
struct ResShaderSamplerUsageData
{
    u8 RegIndex;
    u8 field_0x1;
    ResNameData Name;
};

struct ResShaderSamplerUsage : public ut::ResCommon<ResShaderSamplerUsageData>
{
    LWAPI(0x0367bc48, TODO)
    ResName GetName();

    inline ResShaderSamplerUsage(std::nullptr_t) :
        ResCommon<ResShaderSamplerUsageData>() {}

    inline ResShaderSamplerUsage(const void* data) :
        ResCommon<ResShaderSamplerUsageData>(data) {}

    inline ResShaderSamplerUsage(void* data = nullptr) :
        ResCommon<ResShaderSamplerUsageData>(data) {}
};
}
}
}
