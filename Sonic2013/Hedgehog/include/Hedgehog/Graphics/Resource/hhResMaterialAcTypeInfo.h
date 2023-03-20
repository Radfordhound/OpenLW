#pragma once
#include <Hedgehog/Utility/hhResource.h>

namespace hh
{
namespace gfx
{
namespace res
{
struct ResMaterialLoader : ut::IResourceLoader
{
    LWAPI(0x03688ed8, TODO)
    ~ResMaterialLoader();

    LWAPI(0x03688eec, TODO)
    void* ReplaceLoadedResource(const char* name, void* data,
        std::size_t* size, csl::fnd::IAllocator* allocator);

    LWAPI(0x03688f4c, TODO)
    bool FinishLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator);

    LWAPI(0x03688f98, TODO)
    bool BindLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator, ut::Packfile packfile);

    LWAPI(0x03689000, TODO)
    void CleanupLoadedResource(void* data, std::size_t size);
};

LWAPI(0x104014b4, TODO)
extern ut::ResourceTypeInfo ResMaterialTypeInfo;
}
}
}
