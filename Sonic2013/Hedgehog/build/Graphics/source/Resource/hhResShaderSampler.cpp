#include "pch.h"
#include "Hedgehog/Graphics/Resource/hhResShaderSampler.h"

namespace hh
{
namespace gfx
{
namespace res
{
ResTexture ResShaderSampler::GetResTexture() const
{
    return ResTexture(ptr()->Texture);
}

ResShaderSamplerUsage ResShaderSampler::GetUsage(std::size_t index) const
{
    return (index < HH_COUNT_OF(ptr()->Usages)) ?
        ResShaderSamplerUsage(ptr()->Usages[index]) :
        ResShaderSamplerUsage();
}

ResName ResShaderSampler::GetTexName()
{
    return ResName(&ptr()->TexName);
}

ResName ResShaderSampler::GetUsageName()
{
    return ResName(&ptr()->UsageName);
}

ResName ResShaderSampler::GetTexSlotName()
{
    return ResName(&ptr()->TexSlotName);
}
}
}
}
