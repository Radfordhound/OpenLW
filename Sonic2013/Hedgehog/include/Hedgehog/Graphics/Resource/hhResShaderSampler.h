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
    // Wii U: 0x0367b21c, PC: TODO
    ResTexture GetResTexture() const;

    // Wii U: 0x0367b270, PC: TODO
    ResShaderSamplerUsage GetUsage(std::size_t index) const;

    // Wii U: 0x0367b2fc, PC: TODO
    ResName GetTexName();

    // Wii U: 0x0367b350, PC: TODO
    ResName GetUsageName();

    // Wii U: 0x0367b3a4, PC: TODO
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
