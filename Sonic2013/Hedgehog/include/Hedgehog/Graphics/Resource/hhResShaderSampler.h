#pragma once
#include "hhResTexture.h"
#include "hhResShaderSamplerUsage.h"

namespace hh
{
namespace gfx
{
namespace res
{
struct ResShaderSamplerData // size == 48
{
    ResTextureData* Texture;
    ResShaderSamplerUsageData* Usages[2];
    // TODO: Other data members.
    ResNameData TexName;
    ResNameData UsageName;
    ResNameData TexSlotName;
};

struct ResShaderSampler : public ut::ResCommon<ResShaderSamplerData>
{
    LWAPI(0x0367b21c, TODO)
    ResTexture GetResTexture() const;

    LWAPI(0x0367b270, TODO)
    ResShaderSamplerUsage GetUsage(std::size_t index) const;

    LWAPI(0x0367b2fc, TODO)
    ResName GetTexName();

    LWAPI(0x0367b350, TODO)
    ResName GetUsageName();

    LWAPI(0x0367b3a4, TODO)
    ResName GetTexSlotName();

    inline ResShaderSampler(std::nullptr_t) :
        ResCommon<ResShaderSamplerData>() {}

    inline ResShaderSampler(const void* data) :
        ResCommon<ResShaderSamplerData>(data) {}

    inline ResShaderSampler(void* data = nullptr) :
        ResCommon<ResShaderSamplerData>(data) {}
};
}
}
}
