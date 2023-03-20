#pragma once
#include "hhResNameData.h"

namespace hh
{
namespace gfx
{
namespace res
{
struct ResShaderConstantUsageData
{
    unsigned int RegFirstIndex;
    unsigned int RegCount;
    ResNameData Name;
};

struct ResShaderConstantUsage : public ut::ResCommon<ResShaderConstantUsageData>
{
    LWAPI(0x0367bbf4, TODO)
    ResName GetName();

    inline ResShaderConstantUsage(std::nullptr_t) :
        ResCommon<ResShaderConstantUsageData>() {}

    inline ResShaderConstantUsage(const void* data) :
        ResCommon<ResShaderConstantUsageData>(data) {}

    inline ResShaderConstantUsage(void* data = nullptr) :
        ResCommon<ResShaderConstantUsageData>(data) {}
};
}
}
}
