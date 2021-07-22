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
    // Wii U: MULTIPLE ADDRESSES, PC: TODO
    virtual ~IResourceCustomLoader() {}

    virtual void Setup(void* param_1, const ResourceArgsData& args) = 0;

    // Wii U: MULTIPLE ADDRESSES, PC: TODO
    virtual void Cleanup(void* param_1, const ResRawData& rawData) {}
};

struct ResourceCustomInfo // size == 12?
{
    typedef IResourceCustomLoader* (*CreateLoaderFunc)();

    const char* Extension;
    CreateLoaderFunc CreateLoader;
    IResourceCustomLoader* Loader;
};

// Wii U: 0x10360d90, PC: TODO
extern ResourceCustomInfo OrcaResourceCustomInfo;

// Wii U: 0x10360d9c, PC: TODO
extern ResourceCustomInfo CriAcfResourceCustomInfo;

// Wii U: 0x10360da8, PC: TODO
extern ResourceCustomInfo CriAcbResourceCustomInfo;
}
}
