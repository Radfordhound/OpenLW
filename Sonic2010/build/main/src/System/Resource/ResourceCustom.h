// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include <cstddef>

namespace csl
{
namespace fnd
{
struct IAllocator;
}
}

namespace app
{
namespace fnd
{
struct ResRawData;

struct ResourceArgsData // size == 20?
{
    csl::fnd::IAllocator* Allocator;
    const char* Name;
    void* Address;
    std::size_t Size;
    int Category;
};

struct IResourceCustomLoader
{
    LWAPI(NONE, TODO)
    virtual ~IResourceCustomLoader() {}

    virtual void Setup(void* param_1, const ResourceArgsData& args) = 0;

    LWAPI(NONE, TODO)
    virtual void Cleanup(void* param_1, const ResRawData& rawData) {}
};

struct ResourceCustomInfo // size == 12?
{
    typedef IResourceCustomLoader* (*CreateLoaderFunc)();

    const char* Extension;
    CreateLoaderFunc CreateLoader;
    IResourceCustomLoader* Loader;
};

LWAPI(0x10360d90, TODO)
extern ResourceCustomInfo OrcaResourceCustomInfo;

LWAPI(0x10360d9c, TODO)
extern ResourceCustomInfo CriAcfResourceCustomInfo;

LWAPI(0x10360da8, TODO)
extern ResourceCustomInfo CriAcbResourceCustomInfo;
}

namespace xgame
{
struct ResourceCustomOrcaLoader : fnd::IResourceCustomLoader
{
    LWAPI(0x02b2c30c, TODO)
    ~ResourceCustomOrcaLoader();

    LWAPI(0x02b2c330, TODO)
    void Setup(void* param_1, const fnd::ResourceArgsData& args);
};
}
}
