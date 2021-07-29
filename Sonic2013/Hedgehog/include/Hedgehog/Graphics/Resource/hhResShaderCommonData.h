#pragma once
#include "hhResUserData.h"
#include <Hedgehog/Rsdx/System/RsdxObject.h>

namespace hh
{
namespace gfx
{
namespace res
{
struct ResShaderConstantUsageData;
struct ResShaderSamplerUsageData;

struct ResShaderCommonData
{
    rsdx::RsdxRefcountObject* Shader;
    ResShaderConstantUsageData* Float4Usages;
    ResShaderConstantUsageData* Int4Usages;
    ResShaderConstantUsageData* Bool4Usages;
    ResShaderSamplerUsageData* SamplerUsages;
    std::size_t Float4UsageCount;
    std::size_t Int4UsageCount;
    std::size_t Bool4UsageCount;
    std::size_t SamplerUsageCount;
    ResNameData CodeResName;
    // TODO: Other data members.
    ResUserDataData UserData;
};
}
}
}
