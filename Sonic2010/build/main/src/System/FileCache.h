// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include "ReferencedObject.h"
#include <csl/fnd/singleton.h>
#include <csl/ut/string_map.h>

namespace app
{
namespace fnd
{
struct FileCache : public ReferencedObject, public csl::fnd::Singleton<FileCache>
{
    struct CacheDataTag
    {
        // TODO
    };

    // TODO: Data Members
    csl::ut::StringMap<CacheDataTag*> field_0x218;
    // TODO: Data Members

    // Wii U: TODO, PC: TODO
    ~FileCache();

    // Wii U: 0x0218b224, PC: TODO
    void AddCache(const char* param_1, void* param_2,
        std::size_t param_3, bool param_4);

    // Wii U: 0x0218acf8, PC: TODO
    std::size_t CalcFreeCache();

    // Wii U: 0x0218b498, PC: TODO
    // TODO: Is this return type right?
    char* CreateCache(char const* param_1, std::size_t* param_2, bool param_3);

    // Wii U: 0x0218afac, PC: TODO
    // TODO: Is this return type right?
    char* CreateCacheCore(char const* param_1, void* param_2, \
        std::size_t* param_3, bool param_4);

    // Wii U: 0x0218a938, PC: TODO
    // TODO: Get return type right
    void* GetCache(const char* param_1, std::size_t* param_2);

    // Wii U: 0x0218ab00, PC: TODO
    bool IsCache(const char* param_1) const;

    // Wii U: 0x0218b28c, PC: TODO
    void OnEnterCache(const char* param_1);

    // Wii U: 0x0218b29c, PC: TODO
    void OnLeaveCache();

    // Wii U: 0x0218b2d8, PC: TODO
    void ReleaseCache();

    // Wii U: 0x0218a49c, PC: TODO
    void ReleaseCacheAll();

    // Wii U: 0x0218b3fc, PC: TODO
    bool SetHintCache(const char* param_1);

    // Wii U: 0x0218a72c, PC: TODO
    void Setup(std::size_t cacheSize);

    // Wii U: 0x0218a2b8, PC: TODO
    FileCache();
};
}
}
