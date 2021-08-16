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
    // Wii U: 0x0367b70c, PC: TODO
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

    // Wii U: 0x0367bc9c, PC: TODO
    ResName GetName();

    // Wii U: 0x0367bcf0, PC: TODO
    ResUserData GetResUserData();

    // Wii U: 0x0367bd44, PC: 0x00c0aa10
    void* Replace(std::size_t* size, csl::fnd::IAllocator* allocator);

    // Wii U: 0x0367beac, PC: TODO
    bool Setup(std::size_t size, csl::fnd::IAllocator* allocator);

    // Wii U: 0x0367bf80, PC: 0x00c0ab60
    bool Setup(std::size_t size, csl::fnd::IAllocator* allocator, ut::Packfile pac);

    // Wii U: 0x0367c314, PC: TODO
    void Unbind();

    // Wii U: 0x0367c41c, PC: TODO
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
