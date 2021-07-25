#pragma once
#include <Hedgehog/MirageCore/Resource/hhShaderResource.h>
#include <Hedgehog/Utility/hhResource.h>

namespace hh
{
namespace gfx
{
namespace res
{
struct ResMirageVertexShaderCodeData
{
    mr::CVertexShaderCodeData* CodeDataPtr;
    csl::fnd::IAllocator* Allocator;
    mr::CVertexShaderCodeData CodeData;
    
    // TODO: Other data members
};

struct ResMirageVertexShaderCode : public ut::ResCommon<ResMirageVertexShaderCodeData>
{
    // Wii U: 0x036856a0, PC: TODO
    static const ut::ResourceTypeInfo& staticTypeInfo();

    // Wii U: 0x03685758, PC: TODO
    void* Replace(std::size_t* size, csl::fnd::IAllocator* allocator);

    // Wii U: 0x036857d0, PC: TODO
    bool Setup(std::size_t size, csl::fnd::IAllocator* allocator);

    // Wii U: 0x036857d8, PC: TODO
    bool Setup(std::size_t size, csl::fnd::IAllocator* allocator, ut::Packfile packfile);

    inline ResMirageVertexShaderCode(const void* data) :
        ResCommon<ResMirageVertexShaderCodeData>(data) {}

    inline ResMirageVertexShaderCode(void* data = nullptr) :
        ResCommon<ResMirageVertexShaderCodeData>(data) {}
};
}
}
}
