#pragma once
#include "hhResShaderConstantUsage.h"
#include "hhResShaderSamplerUsageData.h"
#include <Hedgehog/Utility/hhResource.h>
#include <Hedgehog/MirageCore/Resource/hhShaderResource.h>

namespace hh
{
namespace gfx
{
namespace res
{
struct ResMiragePixelShaderParameterData
{
    mr::CPixelShaderParameterData* field_0x0;
    ResShaderConstantUsageData* IntConstants;
    ResShaderSamplerUsageData* TexSamplers;
    ResShaderConstantUsageData* BoolConstants;
    ResShaderConstantUsageData* FloatConstants;
    std::size_t FloatConstantCount;
    std::size_t IntConstantCount;
    std::size_t BoolConstantCount;
    std::size_t TexSamplerCount;
    csl::fnd::IAllocator* Allocator;
};

struct ResMiragePixelShaderParameter : ut::ResCommon<ResMiragePixelShaderParameterData>
{
    // Wii U: 0x03684208, PC: TODO
    static const ut::ResourceTypeInfo& staticTypeInfo();

    // Wii U: 0x036844c8, PC: TODO
    void* Replace(std::size_t* size, csl::fnd::IAllocator* allocator);

    // Wii U: 0x03684694, PC: TODO
    bool Setup(std::size_t size, csl::fnd::IAllocator* allocator);

    // Wii U: 0x0368469c, PC: TODO
    bool Setup(std::size_t size, csl::fnd::IAllocator* allocator, ut::Packfile pac);

    inline ResMiragePixelShaderParameter(const void* data) :
        ResCommon<ResMiragePixelShaderParameterData>(data) {}

    inline ResMiragePixelShaderParameter(void* data = nullptr) :
        ResCommon<ResMiragePixelShaderParameterData>(data) {}
};
}
}
}
