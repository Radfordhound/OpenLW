#pragma once
#include "hhResShaderCommonData.h"
#include "hhResMiragePixelShaderCode.h"
#include "hhResShaderConstantUsage.h"
#include "hhResShaderSamplerUsage.h"

namespace hh
{
namespace gfx
{
namespace res
{
struct ResFragmentShader : public ut::ResCommon<ResShaderCommonData>
{
    LWAPI(0x0367b7c8, TODO)
    static const ut::ResourceTypeInfo& staticTypeInfo();

    std::size_t GetNumFloat4Usages() const
    {
        return ptr()->Float4UsageCount;
    }

    ResShaderConstantUsage GetFloat4Usage(std::size_t index) const
    {
        return (index < GetNumFloat4Usages()) ?
            ResShaderConstantUsage(ptr()->Float4Usages + index) :
            ResShaderConstantUsage();
    }

    std::size_t GetNumInt4Usages() const
    {
        return ptr()->Int4UsageCount;
    }

    ResShaderConstantUsage GetInt4Usage(std::size_t index) const
    {
        return (index < GetNumInt4Usages()) ?
            ResShaderConstantUsage(ptr()->Int4Usages + index) :
            ResShaderConstantUsage();
    }

    std::size_t GetNumBoolUsages() const
    {
        return ptr()->Bool4UsageCount;
    }

    ResShaderConstantUsage GetBoolUsage(std::size_t index) const
    {
        return (index < GetNumBoolUsages()) ?
            ResShaderConstantUsage(ptr()->Bool4Usages + index) :
            ResShaderConstantUsage();
    }

    std::size_t GetNumSamplerUsages() const
    {
        return ptr()->SamplerUsageCount;
    }

    ResShaderSamplerUsage GetSamplerUsage(std::size_t index) const
    {
        return (index < GetNumSamplerUsages()) ?
            ResShaderSamplerUsage(ptr()->SamplerUsages + index) :
            ResShaderSamplerUsage();
    }

    LWAPI(0x0367c474, TODO)
    ResName GetName();

    LWAPI(0x0367c4c8, TODO)
    ResUserData GetResUserData();

    LWAPI(0x0367c51c, TODO)
    void* Replace(std::size_t* size, csl::fnd::IAllocator* allocator);

    LWAPI(0x0367c684, TODO)
    bool Setup(std::size_t size, csl::fnd::IAllocator* allocator);

    LWAPI(0x0367c684, TODO)
    bool Setup(std::size_t size, csl::fnd::IAllocator* allocator, ut::Packfile pac);

    LWAPI(0x0367ca8c, TODO)
    void Unbind();

    LWAPI(0x0367cb94, TODO)
    void Cleanup(std::size_t size);

    inline ResFragmentShader(std::nullptr_t) :
        ResCommon<ResShaderCommonData>() {}

    inline ResFragmentShader(const void* data) :
        ResCommon<ResShaderCommonData>(data) {}

    inline ResFragmentShader(void* data = nullptr) :
        ResCommon<ResShaderCommonData>(data) {}
};
}
}
}
