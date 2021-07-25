#pragma once
#include "hhResUserData.h"
#include "hhResShaderConstantUsage.h"
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
    unsigned int field_0x10; // TODO: Is this type correct?
    std::size_t Float4UsageCount;
    std::size_t Int4UsageCount;
    std::size_t BoolUsageCount;
    unsigned int field_0x20; // TODO: Is this type correct?
    ResNameData CodeResName;
    // TODO: Other data members.
    ResUserDataData UserData;
};
}
}
}
