#pragma once
#include <Hedgehog/Utility/hhResource.h>
#include <Hedgehog/MirageCore/Resource/hhShaderResource.h>

namespace hh
{
namespace gfx
{
namespace res
{
struct ResShaderConstantUsageData;
struct ResShaderSamplerUsageData;

struct ResMiragePixelShaderParameterData
{
    mr::CPixelShaderParameterData* field_0x0;
    ResShaderConstantUsageData* Float4Usages;
    ResShaderConstantUsageData* Int4Usages;
    ResShaderConstantUsageData* Bool4Usages;
    ResShaderSamplerUsageData* SamplerUsages;
    std::size_t Float4UsageCount;
    std::size_t Int4UsageCount;
    std::size_t Bool4UsageCount;
    std::size_t SamplerUsageCount;
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

    inline ResMiragePixelShaderParameter(std::nullptr_t) :
        ResCommon<ResMiragePixelShaderParameterData>() {}

    inline ResMiragePixelShaderParameter(const void* data) :
        ResCommon<ResMiragePixelShaderParameterData>(data) {}

    inline ResMiragePixelShaderParameter(void* data = nullptr) :
        ResCommon<ResMiragePixelShaderParameterData>(data) {}
};
}
}
}
