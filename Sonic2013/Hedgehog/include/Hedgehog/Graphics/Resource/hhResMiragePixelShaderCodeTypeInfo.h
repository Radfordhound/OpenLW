#pragma once
#include <Hedgehog/Utility/hhResource.h>

namespace hh
{
namespace gfx
{
namespace res
{
struct ResMiragePixelShaderCodeLoader : ut::IResourceLoader
{
    // Wii U: 0x03680b1c, PC: TODO
    ~ResMiragePixelShaderCodeLoader();

    // Wii U: 0x03680b30, PC: TODO
    void* ReplaceLoadedResource(const char* name, void* data,
        std::size_t* size, csl::fnd::IAllocator* allocator);

    // Wii U: 0x03680b80, PC: TODO
    bool FinishLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator);

    // Wii U: 0x03680bcc, PC: TODO
    bool BindLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator, ut::Packfile packfile);

    // Wii U: 0x03680c34, PC: TODO
    void CleanupLoadedResource(void* data, std::size_t size);
};

// Wii U: TODO, PC: TODO
extern ut::ResourceTypeInfo ResMiragePixelShaderCodeTypeInfo;
}
}
}
