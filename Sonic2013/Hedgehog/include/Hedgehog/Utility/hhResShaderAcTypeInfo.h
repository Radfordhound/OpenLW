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
    void* ReplaceLoadedResource(const char* param_1, void* param_2,
        std::size_t* param_3, csl::fnd::IAllocator* allocator);

    // Wii U: 0x036899e4, PC: TODO
    bool FinishLoadedResource(void* param_1, std::size_t param_2,
        csl::fnd::IAllocator* allocator);

    // Wii U: 0x03689a30, PC: TODO
    bool BindLoadedResource(void* param_1, std::size_t param_2,
        csl::fnd::IAllocator* allocator, Packfile packfile);

    // Wii U: 0x03689a98, PC: TODO
    void CleanupLoadedResource(void* param_1, std::size_t param_2);
};

struct ResFragmentShaderLoader : IResourceLoader
{
    // TODO
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
