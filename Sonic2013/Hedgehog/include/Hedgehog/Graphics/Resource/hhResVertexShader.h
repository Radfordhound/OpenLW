#pragma once
#include "hhResShaderCommonData.h"
#include <Hedgehog/Utility/hhResource.h>

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

    // Wii U: 0x0367bc9c, PC: TODO
    ResCommon<ResNameData> GetName();

    // Wii U: 0x0367bd44, PC: 0x00c0aa10
    void* Replace(std::size_t* size, csl::fnd::IAllocator* allocator);

    // Wii U: 0x0367beac, PC: TODO
    bool Setup(unsigned int param_1, csl::fnd::IAllocator* allocator);

    // Wii U: 0x0367bf80, PC: TODO
    bool Setup(unsigned int param_1, csl::fnd::IAllocator* allocator, ut::Packfile pac);

    // Wii U: 0x0367c314, PC: TODO
    void Unbind();

    // Wii U: 0x0367c41c, PC: TODO
    void Cleanup(unsigned int param_1);

    inline ResVertexShader(const void* data) :
        ResCommon<ResShaderCommonData>(data) {}

    inline ResVertexShader(void* data = nullptr) :
        ResCommon<ResShaderCommonData>(data) {}
};
}
}
}