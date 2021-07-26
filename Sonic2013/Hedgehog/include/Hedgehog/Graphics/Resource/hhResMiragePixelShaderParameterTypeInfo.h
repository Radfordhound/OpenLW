#pragma once
#include <Hedgehog/Utility/hhResource.h>

namespace hh
{
namespace gfx
{
namespace res
{
struct ResMiragePixelShaderParameterLoader : ut::IResourceLoader
{
    // Wii U: 0x03684808, PC: TODO
    ~ResMiragePixelShaderParameterLoader();

    // Wii U: 0x0368481c, PC: TODO
    void* ReplaceLoadedResource(const char* name, void* data,
        std::size_t* size, csl::fnd::IAllocator* allocator);

    // Wii U: TODO, PC: TODO
    bool FinishLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator);

    // Wii U: TODO, PC: TODO
    bool BindLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator, ut::Packfile packfile);

    // Wii U: TODO, PC: TODO
    void CleanupLoadedResource(void* data, std::size_t size);
};

// Wii U: TODO, PC: TODO
extern ut::ResourceTypeInfo ResMiragePixelShaderParameterTypeInfo;
}
}
}
