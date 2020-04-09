#pragma once
#include "ReferencedObject.h"
#include "csl/fnd/Singleton.h"

namespace app
{
namespace fnd
{
struct FileCache : public ReferencedObject, public csl::fnd::Singleton<FileCache>
{
    // TODO: Data Members

    /*
        @brief Constructor for FileCache.
        <b>Wii U: TODO, PC: TODO</b>
    */
    FileCache();

    /*
        @brief Destructor for FileCache.
        <b>Wii U: TODO, PC: TODO</b>
    */
    ~FileCache() override;

    /* <b>Wii U: 0x0218b224, PC: TODO</b> */
    void AddCache(const char* param_1, void* param_2,
        std::size_t param_3, bool param_4);

    /* <b>Wii U: 0x0218acf8, PC: TODO</b> */
    std::size_t CalcFreeCache();

    /* <b>Wii U: 0x0218b498, PC: TODO</b> */
    // TODO: Is this return type right?
    char* CreateCache(char const* param_1, std::size_t* param_2, bool param_3);

    /* <b>Wii U: 0x0218afac, PC: TODO</b> */
    // TODO: Is this return type right?
    char* CreateCacheCore(char const* param_1, void* param_2, \
        std::size_t* param_3, bool param_4);

    /* <b>Wii U: 0x0218a938, PC: TODO</b> */
    // TODO: Get return type right
    void* GetCache(const char* param_1, std::size_t* param_2);

    /* <b>Wii U: 0x0218ab00, PC: TODO</b> */
    bool IsCache(const char* param_1) const;

    /* <b>Wii U: 0x0218b28c, PC: TODO</b> */
    void OnEnterCache();

    /* <b>Wii U: 0x0218b29c, PC: TODO</b> */
    void OnLeaveCache();

    /* <b>Wii U: 0x0218b2d8, PC: TODO</b> */
    void ReleaseCache();

    /* <b>Wii U: 0x0218a49c, PC: TODO</b> */
    void ReleaseCacheAll();

    /* <b>Wii U: 0x0218b3fc, PC: TODO</b> */
    bool SetHintCache(const char* param_1);

    /* <b>Wii U: 0x0218a72c, PC: TODO</b> */
    void Setup(std::size_t cacheSize);
};
}
}
