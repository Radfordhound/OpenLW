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
    // Wii U: 0x03688ed8, PC: TODO
    ~ResMaterialLoader();

    // Wii U: 0x03688eec, PC: TODO
    void* ReplaceLoadedResource(const char* name, void* data,
        std::size_t* size, csl::fnd::IAllocator* allocator);

    // Wii U: 0x03688f4c, PC: TODO
    bool FinishLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator);

    // Wii U: 0x03688f98, PC: TODO
    bool BindLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator, ut::Packfile packfile);

    // Wii U: 0x03689000, PC: TODO
    void CleanupLoadedResource(void* data, std::size_t size);
};

// Wii U: 0x104014b4, PC: TODO
extern ut::ResourceTypeInfo ResMaterialTypeInfo;
}
}
}
