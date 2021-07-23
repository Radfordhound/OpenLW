#pragma once
#include "hhResUserData.h"

namespace hh
{
namespace gfx
{
namespace res
{
struct ResShaderConstantUsageData // size == 16
{
    // TODO
};

struct ResShaderCommonData
{
    // TODO: Other data members.

    ResShaderConstantUsageData* Float4Usages;
    ResShaderConstantUsageData* Int4Usages;
    ResShaderConstantUsageData* BoolUsages;
    // TODO: Other data members.

    std::size_t Float4UsageCount;
    std::size_t Int4UsageCount;
    std::size_t BoolUsageCount;
    // TODO: Other data members.

    ResNameData CodeResName;
    // TODO: Other data members.

    ResUserDataData UserData;
    ResUserDataItemData AllocatorData;
};
}
}
}
