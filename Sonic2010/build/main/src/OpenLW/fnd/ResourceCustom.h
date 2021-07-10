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
    virtual ~IResourceCustomLoader() {}

    virtual void Setup(void* param_1, const ResourceArgsData& args) = 0;

    virtual void Cleanup(void* param_1, const ResRawData& rawData) {}
};

struct ResourceCustomInfo // size == 12?
{
    typedef IResourceCustomLoader* (*CreateLoaderFunc)();

    const char* Extension;
    CreateLoaderFunc CreateLoader;
    IResourceCustomLoader* Loader;
};
}
}
