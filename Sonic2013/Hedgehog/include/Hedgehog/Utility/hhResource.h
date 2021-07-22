#pragma once
#include "hhPackfile.h"

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
class CAllocationMeasure; // TODO

struct SLoadedResourceParameter
{
    CAllocationMeasure* field_0x0;
    unsigned int field_0x4;
    unsigned int field_0x8;
    const char* Name;
};

struct IResourceLoader
{
    // Wii U: MULTIPLE ADDRESSES, PC: TODO
    virtual ~IResourceLoader();
    
    // Wii U: MULTIPLE ADDRESSES, PC: TODO
    virtual bool PrepareReplaceLoadedResource(void* param_1,
        std::size_t param_2, SLoadedResourceParameter* args);
    
    // Wii U: MULTIPLE ADDRESSES, PC: TODO
    virtual void* ReplaceLoadedResource(const char* param_1, void* param_2,
        std::size_t* param_3, csl::fnd::IAllocator* allocator);

    // Wii U: MULTIPLE ADDRESSES, PC: TODO
    virtual void FinishLoadedResource(void* param_1, std::size_t param_2,
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

    // Wii U: 0x036953dc, PC: TODO
    static void* GetLoadedResourceHeaderByName(unsigned int version,
        const char* param_2, Packfile pac, const char* param_4);

    // Wii U: 0x03695500, PC: TODO
    static void* FindLoadedResourceByName(unsigned int version,
        const char* param_2, Packfile pac, const char* param_4,
        std::size_t* size);
};
}
}
