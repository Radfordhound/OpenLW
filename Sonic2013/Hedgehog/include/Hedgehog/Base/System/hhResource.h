#pragma once
#include "../File/hhPackfile.h"

namespace csl
{
namespace fnd
{
struct IAllocator;
}
}

namespace hh
{
namespace ut
{
struct SLoadedResourceParameter
{
    // TODO
};

struct IResourceLoader
{
    // Wii U: MULTIPLE ADDRESSES, PC: TODO
    virtual ~IResourceLoader();
    
    // Wii U: MULTIPLE ADDRESSES, PC: TODO
    virtual bool PrepareReplaceLoadedResource(void* param_1,
        std::size_t param_2, SLoadedResourceParameter* args);
    
    // Wii U: MULTIPLE ADDRESSES, PC: TODO
    virtual bool ReplaceLoadedResource(const char* param_1, void* param_2,
        std::size_t* param_3, csl::fnd::IAllocator* allocator);

    // Wii U: MULTIPLE ADDRESSES, PC: TODO
    virtual bool FinishLoadedResource(void* param_1, std::size_t param_2,
        csl::fnd::IAllocator* allocator);

    // Wii U: MULTIPLE ADDRESSES, PC: TODO
    virtual bool BindLoadedResource(void* param_1, std::size_t param_2,
        csl::fnd::IAllocator* allocator, Packfile packfile);

    // Wii U: MULTIPLE ADDRESSES, PC: TODO
    virtual void CleanupLoadedResource(void* param_1, std::size_t param_2);
};

struct ResourceTypeInfo
{
    typedef IResourceLoader* (*CreateLoaderFunc)();

    const char* Type;
    CreateLoaderFunc CreateLoader;
    IResourceLoader* Loader;
    unsigned int Hash;
};
}
}
