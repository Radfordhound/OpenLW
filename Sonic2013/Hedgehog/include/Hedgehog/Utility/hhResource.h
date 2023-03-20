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
    LWAPI(NONE, TODO)
    virtual ~IResourceLoader();
    
    LWAPI(NONE, TODO)
    virtual bool PrepareReplaceLoadedResource(void* data,
        unsigned int typeHash, SLoadedResourceParameter* args);
    
    LWAPI(NONE, TODO)
    virtual void* ReplaceLoadedResource(const char* name, void* data,
        std::size_t* size, csl::fnd::IAllocator* allocator);

    LWAPI(NONE, TODO)
    virtual bool FinishLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator);

    LWAPI(NONE, TODO)
    virtual bool BindLoadedResource(void* data, std::size_t size,
        csl::fnd::IAllocator* allocator, Packfile packfile);

    LWAPI(NONE, TODO)
    virtual void CleanupLoadedResource(void* data, std::size_t size);
};

struct ResourceTypeInfo
{
    typedef IResourceLoader* (*CreateLoaderFunc)();

    const char* Type;
    CreateLoaderFunc CreateLoader;
    IResourceLoader* Loader;
    unsigned int Hash;

    LWAPI(0x036953dc, TODO)
    static void* GetLoadedResourceHeaderByName(unsigned int version,
        const char* type, Packfile pac, const char* name);

    LWAPI(0x03695500, TODO)
    static void* FindLoadedResourceByName(unsigned int version,
        const char* type, Packfile pac, const char* name,
        std::size_t* size = nullptr);

    LWAPI(0x03695588, TODO)
    static void* GetLoadedResourceHeaderByIndex(unsigned int version,
        const char* type, Packfile pac, int index);

    LWAPI(0x03695654, TODO)
    static void* FindLoadedResourceByIndex(unsigned int version,
        const char* type, Packfile pac, int index,
        std::size_t* size = nullptr);

    LWAPI(0x036956e0, TODO)
    static std::size_t GetLoadedResourceCount(unsigned int version,
        const char* type, Packfile pac);
};
}
}
