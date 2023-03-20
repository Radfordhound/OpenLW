#pragma once
#include "hhResShaderCommonData.h"
#include "hhResMirageVertexShaderCode.h"
#include "hhResShaderConstantUsage.h"

namespace hh
{
namespace gfx
{
namespace res
{
struct ResVertexShader : public ut::ResCommon<ResShaderCommonData>
{
    LWAPI(0x0367b70c, TODO)
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

    LWAPI(0x0367bc9c, TODO)
    ResName GetName();

    LWAPI(0x0367bcf0, TODO)
    ResUserData GetResUserData();

    LWAPI(0x0367bd44, 0x00c0aa10)
    void* Replace(std::size_t* size, csl::fnd::IAllocator* allocator);

    LWAPI(0x0367beac, TODO)
    bool Setup(std::size_t size, csl::fnd::IAllocator* allocator);

    LWAPI(0x0367bf80, 0x00c0ab60)
    bool Setup(std::size_t size, csl::fnd::IAllocator* allocator, ut::Packfile pac);

    LWAPI(0x0367c314, TODO)
    void Unbind();

    LWAPI(0x0367c41c, TODO)
    void Cleanup(std::size_t size);

    inline ResVertexShader(std::nullptr_t) :
        ResCommon<ResShaderCommonData>() {}

    inline ResVertexShader(const void* data) :
        ResCommon<ResShaderCommonData>(data) {}

    inline ResVertexShader(void* data = nullptr) :
        ResCommon<ResShaderCommonData>(data) {}
};
}
}
}
