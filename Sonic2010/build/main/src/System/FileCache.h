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

    LWAPI(TODO, TODO)
    ~FileCache();

    LWAPI(0x0218b224, TODO)
    void AddCache(const char* param_1, void* param_2,
        std::size_t param_3, bool param_4);

    LWAPI(0x0218acf8, TODO)
    std::size_t CalcFreeCache();

    LWAPI(0x0218b498, TODO)
    // TODO: Is this return type right?
    char* CreateCache(char const* param_1, std::size_t* param_2, bool param_3);

    LWAPI(0x0218afac, TODO)
    // TODO: Is this return type right?
    char* CreateCacheCore(char const* param_1, void* param_2, \
        std::size_t* param_3, bool param_4);

    LWAPI(0x0218a938, TODO)
    // TODO: Get return type right
    void* GetCache(const char* param_1, std::size_t* param_2);

    LWAPI(0x0218ab00, TODO)
    bool IsCache(const char* param_1) const;

    LWAPI(0x0218b28c, TODO)
    void OnEnterCache(const char* param_1);

    LWAPI(0x0218b29c, TODO)
    void OnLeaveCache();

    LWAPI(0x0218b2d8, TODO)
    void ReleaseCache();

    LWAPI(0x0218a49c, TODO)
    void ReleaseCacheAll();

    LWAPI(0x0218b3fc, TODO)
    bool SetHintCache(const char* param_1);

    LWAPI(0x0218a72c, TODO)
    void Setup(std::size_t cacheSize);

    LWAPI(0x0218a2b8, TODO)
    FileCache();
};
}
}
