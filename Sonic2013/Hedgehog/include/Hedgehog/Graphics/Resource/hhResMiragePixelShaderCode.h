#pragma once
#include <Hedgehog/MirageCore/Resource/hhShaderResource.h>
#include <Hedgehog/Utility/hhResource.h>

namespace hh
{
namespace gfx
{
namespace res
{
struct ResMiragePixelShaderCodeData
{
    mr::CPixelShaderCodeData* CodeData;
    csl::fnd::IAllocator* Allocator;
};

struct ResMiragePixelShaderCode : public ut::ResCommon<ResMiragePixelShaderCodeData>
{
    // Wii U: 0x03680878, PC: TODO
    static const ut::ResourceTypeInfo& staticTypeInfo();

    // Wii U: 0x03680930, PC: TODO
    void* Replace(std::size_t* size, csl::fnd::IAllocator* allocator);

    // Wii U: 0x036809a8, PC: TODO
    bool Setup(std::size_t size, csl::fnd::IAllocator* allocator);

    // Wii U: 0x036809b0, PC: TODO
    bool Setup(std::size_t size, csl::fnd::IAllocator* allocator, ut::Packfile packfile);

    inline ResMiragePixelShaderCode(const void* data) :
        ResCommon<ResMiragePixelShaderCodeData>(data) {}

    inline ResMiragePixelShaderCode(void* data = nullptr) :
        ResCommon<ResMiragePixelShaderCodeData>(data) {}
};
}
}
}
