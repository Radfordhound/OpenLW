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
class CMeasuredMemory; // TODO

struct SLoadedResourceParameter
{
    CAllocationMeasure* field_0x0;
    CMeasuredMemory* field_0x4;
    csl::fnd::IAllocator* Allocator;
    const char* Name;
};

struct IResourceLoader
{
    // Wii U: MULTIPLE ADDRESSES, PC: TODO
    virtual ~IResourceLoader();
    
    // Wii U: MULTIPLE ADDRESSES, PC: TODO
    virtual bool PrepareReplaceLoadedResource(void* data,
        unsigned int typeHash, SLoadedResourceParameter* args);
    
    // Wii U: MULTIPLE ADDRESSES, PC: TODO
    virtual void* ReplaceLoadedResource(const char* name, void* data,
        std::size_t* size, csl::fnd::IAllocator* allocator);

    // Wii U: MULTIPLE ADDRESSES, PC: TODO
    virtual bool FinishLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator);

    // Wii U: MULTIPLE ADDRESSES, PC: TODO
    virtual bool BindLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator, Packfile packfile);

    // Wii U: MULTIPLE ADDRESSES, PC: TODO
    virtual void CleanupLoadedResource(void* data, std::size_t size);
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
        const char* type, Packfile pac, const char* name);

    // Wii U: 0x03695500, PC: TODO
    static void* FindLoadedResourceByName(unsigned int version,
        const char* type, Packfile pac, const char* name,
        std::size_t* size = nullptr);

    // Wii U: 0x03695588, PC: TODO
    static void* GetLoadedResourceHeaderByIndex(unsigned int version,
        const char* type, Packfile pac, int index);

    // Wii U: 0x03695654, PC: TODO
    static void* FindLoadedResourceByIndex(unsigned int version,
        const char* type, Packfile pac, int index,
        std::size_t* size = nullptr);

    // Wii U: 0x036956e0, PC: TODO
    static std::size_t GetLoadedResourceCount(unsigned int version,
        const char* type, Packfile pac);
};
}
}
