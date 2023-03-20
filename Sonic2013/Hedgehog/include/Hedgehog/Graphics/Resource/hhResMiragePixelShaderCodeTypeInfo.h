#pragma once
#include <Hedgehog/Utility/hhResource.h>

namespace hh
{
namespace gfx
{
namespace res
{
struct ResMiragePixelShaderCodeLoader : ut::IResourceLoader
{
    LWAPI(0x03680b1c, TODO)
    ~ResMiragePixelShaderCodeLoader();

    LWAPI(0x03680b30, TODO)
    void* ReplaceLoadedResource(const char* name, void* data,
        std::size_t* size, csl::fnd::IAllocator* allocator);

    LWAPI(0x03680b80, TODO)
    bool FinishLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator);

    LWAPI(0x03680bcc, TODO)
    bool BindLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator, ut::Packfile packfile);

    LWAPI(0x03680c34, TODO)
    void CleanupLoadedResource(void* data, std::size_t size);
};

LWAPI(TODO, TODO)
extern ut::ResourceTypeInfo ResMiragePixelShaderCodeTypeInfo;
}
}
}
