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
    mr::CVertexShaderCodeData* CodeData;
    csl::fnd::IAllocator* Allocator;
};

struct ResMirageVertexShaderCode : public ut::ResCommon<ResMirageVertexShaderCodeData>
{
    LWAPI(0x036856a0, TODO)
    static const ut::ResourceTypeInfo& staticTypeInfo();

    LWAPI(0x03685758, TODO)
    void* Replace(std::size_t* size, csl::fnd::IAllocator* allocator);

    LWAPI(0x036857d0, TODO)
    bool Setup(std::size_t size, csl::fnd::IAllocator* allocator);

    LWAPI(0x036857d8, TODO)
    bool Setup(std::size_t size, csl::fnd::IAllocator* allocator, ut::Packfile packfile);

    inline ResMirageVertexShaderCode(const void* data) :
        ResCommon<ResMirageVertexShaderCodeData>(data) {}

    inline ResMirageVertexShaderCode(void* data = nullptr) :
        ResCommon<ResMirageVertexShaderCodeData>(data) {}
};
}
}
}
