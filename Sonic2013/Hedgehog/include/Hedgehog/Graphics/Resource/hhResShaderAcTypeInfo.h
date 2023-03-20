#pragma once
#include <Hedgehog/Utility/hhResource.h>

namespace hh
{
namespace gfx
{
namespace res
{
struct ResVertexShaderLoader : ut::IResourceLoader
{
    LWAPI(0x03689980, TODO)
    ~ResVertexShaderLoader();

    LWAPI(0x03689994, 0x00c0bea0)
    void* ReplaceLoadedResource(const char* name, void* data,
        std::size_t* size, csl::fnd::IAllocator* allocator);

    LWAPI(0x036899e4, TODO)
    bool FinishLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator);

    LWAPI(0x03689a30, 0x00c0bee0)
    bool BindLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator, ut::Packfile packfile);

    LWAPI(0x03689a98, TODO)
    void CleanupLoadedResource(void* data, std::size_t size);
};

struct ResFragmentShaderLoader : ut::IResourceLoader
{
    LWAPI(0x03689ad4, TODO)
    ~ResFragmentShaderLoader();

    LWAPI(0x03689ae8, TODO)
    void* ReplaceLoadedResource(const char* name, void* data,
        std::size_t* size, csl::fnd::IAllocator* allocator);

    LWAPI(0x03689b38, TODO)
    bool FinishLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator);

    LWAPI(0x03689b84, TODO)
    bool BindLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator, ut::Packfile packfile);

    // Wii U: 0x03689bec PC: TODO
    void CleanupLoadedResource(void* data, std::size_t size);
};

struct ResShaderLoader : ut::IResourceLoader
{
    LWAPI(0x03689c28, TODO)
    ~ResShaderLoader();

    LWAPI(0x03689c3c, TODO)
    void* ReplaceLoadedResource(const char* name, void* data,
        std::size_t* size, csl::fnd::IAllocator* allocator);

    LWAPI(0x03689c9c, TODO)
    bool FinishLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator);

    LWAPI(0x03689ce8, TODO)
    bool BindLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator, ut::Packfile packfile);

    LWAPI(0x03689d50, TODO)
    void CleanupLoadedResource(void* data, std::size_t size);
};

LWAPI(0x10401500, TODO)
extern ut::ResourceTypeInfo ResVertexShaderTypeInfo;

LWAPI(0x10401510, TODO)
extern ut::ResourceTypeInfo ResFragmentShaderTypeInfo;

LWAPI(0x10401520, TODO)
extern ut::ResourceTypeInfo ResShaderTypeInfo;
}
}
}
