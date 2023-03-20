#pragma once
#include <Hedgehog/Utility/hhResource.h>

namespace hh
{
namespace gfx
{
namespace res
{
struct ResMirageVertexShaderCodeLoader : ut::IResourceLoader
{
    LWAPI(0x03685944, TODO)
    ~ResMirageVertexShaderCodeLoader();

    LWAPI(0x03685944, 0x00c0bea0)
    void* ReplaceLoadedResource(const char* name, void* data,
        std::size_t* size, csl::fnd::IAllocator* allocator);

    LWAPI(0x036859a8, TODO)
    bool FinishLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator);

    LWAPI(0x036859f4, TODO)
    bool BindLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator, ut::Packfile packfile);

    LWAPI(0x03685a5c, TODO)
    void CleanupLoadedResource(void* data, std::size_t size);
};

LWAPI(0x104013e8, TODO)
extern ut::ResourceTypeInfo ResMirageVertexShaderCodeTypeInfo;
}
}
}
