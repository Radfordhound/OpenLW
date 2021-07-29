#pragma once
#include "hhResShaderCommonData.h"
#include "hhResMiragePixelShaderCode.h"

namespace hh
{
namespace gfx
{
namespace res
{
struct ResFragmentShader : public ut::ResCommon<ResShaderCommonData>
{
    // Wii U: 0x0367b7c8, PC: TODO
    static const ut::ResourceTypeInfo& staticTypeInfo();

    // Wii U: 0x0367c474, PC: TODO
    ResName GetName();

    // Wii U: 0x0367c4c8, PC: TODO
    ResUserData GetResUserData();

    // Wii U: 0x0367c51c, PC: TODO
    void* Replace(std::size_t* size, csl::fnd::IAllocator* allocator);

    // Wii U: 0x0367c684, PC: TODO
    bool Setup(std::size_t size, csl::fnd::IAllocator* allocator);

    // Wii U: 0x0367c684, PC: TODO
    bool Setup(std::size_t size, csl::fnd::IAllocator* allocator, ut::Packfile pac);

    // Wii U: 0x0367ca8c, PC: TODO
    void Unbind();

    // Wii U: 0x0367cb94, PC: TODO
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
