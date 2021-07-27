#pragma once
#include "hhResource.h"

namespace hh
{
namespace ut
{
struct ResVertexShaderLoader : IResourceLoader
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
        csl::fnd::IAllocator* allocator, Packfile packfile);

    // Wii U: 0x03689a98, PC: TODO
    void CleanupLoadedResource(void* data, std::size_t size);
};

struct ResFragmentShaderLoader : IResourceLoader
{
    // Wii U: TODO, PC: TODO
    ~ResFragmentShaderLoader();

    // Wii U: 0x03689ae8, PC: TODO
    void* ReplaceLoadedResource(const char* name, void* data,
        std::size_t* size, csl::fnd::IAllocator* allocator);

    // Wii U: TODO, PC: TODO
    bool FinishLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator);

    // Wii U: TODO, PC: TODO
    bool BindLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator, Packfile packfile);

    // Wii U: TODO, PC: TODO
    void CleanupLoadedResource(void* data, std::size_t size);
};

struct ResShaderLoader : IResourceLoader
{
    // TODO
};

// Wii U: 0x10401500, PC: TODO
extern ResourceTypeInfo ResVertexShaderTypeInfo;

// Wii U: 0x10401510, PC: TODO
extern ResourceTypeInfo ResFragmentShaderTypeInfo;

// Wii U: 0x10401520, PC: TODO
extern ResourceTypeInfo ResShaderTypeInfo;
}
}
