#pragma once
#include <Hedgehog/Utility/hhResource.h>

namespace hh
{
namespace gfx
{
namespace res
{
struct ResMiragePixelShaderParameterLoader : ut::IResourceLoader
{
    LWAPI(0x03684808, TODO)
    ~ResMiragePixelShaderParameterLoader();

    LWAPI(0x0368481c, TODO)
    void* ReplaceLoadedResource(const char* name, void* data,
        std::size_t* size, csl::fnd::IAllocator* allocator);

    LWAPI(TODO, TODO)
    bool FinishLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator);

    LWAPI(TODO, TODO)
    bool BindLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator, ut::Packfile packfile);

    LWAPI(TODO, TODO)
    void CleanupLoadedResource(void* data, std::size_t size);
};

LWAPI(TODO, TODO)
extern ut::ResourceTypeInfo ResMiragePixelShaderParameterTypeInfo;
}
}
}
