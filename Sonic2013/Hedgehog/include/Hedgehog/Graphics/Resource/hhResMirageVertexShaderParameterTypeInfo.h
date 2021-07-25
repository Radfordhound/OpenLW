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
    // Wii U: 0x03687bbc, PC: TODO
    ~ResMirageVertexShaderParameterLoader();

    // Wii U: 0x03687bd0, PC: 0x00c0b8a0
    void* ReplaceLoadedResource(const char* name, void* data,
        std::size_t* size, csl::fnd::IAllocator* allocator);

    // Wii U: 0x03687c20, PC: TODO
    bool FinishLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator);

    // Wii U: 0x03687c6c, PC: TODO
    bool BindLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator, ut::Packfile packfile);

    // Wii U: 0x03687cd4, PC: TODO
    void CleanupLoadedResource(void* data, std::size_t size);
};

// Wii U: 0x10401400, PC: TODO
extern ut::ResourceTypeInfo ResMirageVertexShaderParameterTypeInfo;
}
}
}
