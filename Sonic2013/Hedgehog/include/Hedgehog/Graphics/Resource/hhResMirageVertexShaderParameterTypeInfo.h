#pragma once
#include <Hedgehog/Utility/hhResource.h>

namespace hh
{
namespace gfx
{
namespace res
{
struct ResMirageVertexShaderParameterLoader : ut::IResourceLoader
{
    LWAPI(0x03687bbc, TODO)
    ~ResMirageVertexShaderParameterLoader();

    LWAPI(0x03687bd0, 0x00c0b8a0)
    void* ReplaceLoadedResource(const char* name, void* data,
        std::size_t* size, csl::fnd::IAllocator* allocator);

    LWAPI(0x03687c20, TODO)
    bool FinishLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator);

    LWAPI(0x03687c6c, TODO)
    bool BindLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator, ut::Packfile packfile);

    LWAPI(0x03687cd4, TODO)
    void CleanupLoadedResource(void* data, std::size_t size);
};

LWAPI(0x10401400, TODO)
extern ut::ResourceTypeInfo ResMirageVertexShaderParameterTypeInfo;
}
}
}
