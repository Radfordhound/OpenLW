#pragma once
#include "hhResUserData.h"
#include "hhResShaderConstantUsage.h"
#include "hhResShaderSamplerUsageData.h"
#include <Hedgehog/Rsdx/System/RsdxObject.h>

namespace hh
{
namespace gfx
{
namespace res
{
struct ResShaderCommonData
{
    rsdx::RsdxRefcountObject* Shader;
    ResShaderConstantUsageData* Float4Usages;
    ResShaderConstantUsageData* Int4Usages;
    ResShaderConstantUsageData* BoolUsages;
    ResShaderSamplerUsageData* TexSamplerUsages;
    std::size_t Float4UsageCount;
    std::size_t Int4UsageCount;
    std::size_t BoolUsageCount;
    std::size_t TexSamplerCount;
    ResNameData CodeResName;
    // TODO: Other data members.
    ResUserDataData UserData;
};
}
}
}
