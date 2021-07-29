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
    // Wii U: 0x03689980, PC: TODO
    ~ResVertexShaderLoader();

    // Wii U: 0x03689994, PC: 0x00c0bea0
    void* ReplaceLoadedResource(const char* name, void* data,
        std::size_t* size, csl::fnd::IAllocator* allocator);

    // Wii U: 0x036899e4, PC: TODO
    bool FinishLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator);

    // Wii U: 0x03689a30, PC: 0x00c0bee0
    bool BindLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator, ut::Packfile packfile);

    // Wii U: 0x03689a98, PC: TODO
    void CleanupLoadedResource(void* data, std::size_t size);
};

struct ResFragmentShaderLoader : ut::IResourceLoader
{
    // Wii U: 0x03689ad4, PC: TODO
    ~ResFragmentShaderLoader();

    // Wii U: 0x03689ae8, PC: TODO
    void* ReplaceLoadedResource(const char* name, void* data,
        std::size_t* size, csl::fnd::IAllocator* allocator);

    // Wii U: 0x03689b38, PC: TODO
    bool FinishLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator);

    // Wii U: 0x03689b84, PC: TODO
    bool BindLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator, ut::Packfile packfile);

    // Wii U: 0x03689bec PC: TODO
    void CleanupLoadedResource(void* data, std::size_t size);
};

struct ResShaderLoader : ut::IResourceLoader
{
    // Wii U: 0x03689c28, PC: TODO
    ~ResShaderLoader();

    // Wii U: 0x03689c3c, PC: TODO
    void* ReplaceLoadedResource(const char* name, void* data,
        std::size_t* size, csl::fnd::IAllocator* allocator);

    // Wii U: 0x03689c9c, PC: TODO
    bool FinishLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator);

    // Wii U: 0x03689ce8, PC: TODO
    bool BindLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator, ut::Packfile packfile);

    // Wii U: 0x03689d50, PC: TODO
    void CleanupLoadedResource(void* data, std::size_t size);
};

// Wii U: 0x10401500, PC: TODO
extern ut::ResourceTypeInfo ResVertexShaderTypeInfo;

// Wii U: 0x10401510, PC: TODO
extern ut::ResourceTypeInfo ResFragmentShaderTypeInfo;

// Wii U: 0x10401520, PC: TODO
extern ut::ResourceTypeInfo ResShaderTypeInfo;
}
}
}
