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
    LWAPI(0x03680878, TODO)
    static const ut::ResourceTypeInfo& staticTypeInfo();

    LWAPI(0x03680930, TODO)
    void* Replace(std::size_t* size, csl::fnd::IAllocator* allocator);

    LWAPI(0x036809a8, TODO)
    bool Setup(std::size_t size, csl::fnd::IAllocator* allocator);

    LWAPI(0x036809b0, TODO)
    bool Setup(std::size_t size, csl::fnd::IAllocator* allocator, ut::Packfile packfile);

    inline ResMiragePixelShaderCode(const void* data) :
        ResCommon<ResMiragePixelShaderCodeData>(data) {}

    inline ResMiragePixelShaderCode(void* data = nullptr) :
        ResCommon<ResMiragePixelShaderCodeData>(data) {}
};
}
}
}
