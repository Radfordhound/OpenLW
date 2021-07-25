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
    // Wii U: 0x03685944, PC: TODO
    ~ResMirageVertexShaderCodeLoader();

    // Wii U: 0x03685944, PC: 0x00c0bea0
    void* ReplaceLoadedResource(const char* name, void* data,
        std::size_t* size, csl::fnd::IAllocator* allocator);

    // Wii U: 0x036859a8, PC: TODO
    bool FinishLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator);

    // Wii U: 0x036859f4, PC: TODO
    bool BindLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator, ut::Packfile packfile);

    // Wii U: 0x03685a5c, PC: TODO
    void CleanupLoadedResource(void* data, std::size_t size);
};

// Wii U: 0x104013e8, PC: TODO
extern ut::ResourceTypeInfo ResMirageVertexShaderCodeTypeInfo;
}
}
}
