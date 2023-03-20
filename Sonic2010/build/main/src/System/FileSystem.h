#pragma once
#include "ReferencedObject.h"
#include "FileBinder.h"
#include "FileCache.h"
#include "Singleton.h"
#include <csl/ut/string.h>

namespace app
{
namespace fnd
{
enum FILE_SYSTEM_FLAG : unsigned char
{
    FILE_SYSTEM_FLAG_USE_CPK = 1,
    FILE_SYSTEM_FLAG_UK2 = 2
    // TODO
};

struct FileSystem : public ReferencedObject, public csl::fnd::Singleton<FileSystem>
{
    struct Info // size == 8
    {
        const char* RootDirectory;
        bool field_0x5;
        bool field_0x6;

        // TODO: Are the remaining 2 bytes for sure just padding?

        LWAPI(TODO, TODO)
        Info() :
            RootDirectory(nullptr),
            field_0x5(true),
            field_0x6(true) {}
    };

    char RootDirectory[256];
    FileCache* Cache;
    FILE_SYSTEM_FLAG Flags;

    LWAPI(0x0218e570, TODO)
    ~FileSystem();

    LWAPI(0x0218e5c4, TODO)
    virtual void Update();

    LWAPI(0x0218e770, TODO)
    virtual FileBinder* GetDefaultBinder() const;

    LWAPI(0x0218e7e4, TODO)
    const char* GetFileExtension(const char* filePath);

    LWAPI(0x0218e778, TODO)
    const char* GetFileName(const char* filePath);

    LWAPI(0x0218e854, TODO)
    void GetFileNameNoExtension(const char* filePath, csl::ut::String* result);

    LWAPI(0x0218e974, TODO)
    void GetPathName(const char* filePath, csl::ut::String* result);

    LWAPI(0x0218ead0, TODO)
    void SetFileCacheSize(std::size_t cacheSize);

    LWAPI(0x0218e5c8, TODO)
    void SetRootDirectory(const char* rootDir);

    LWAPI(0x0218e760, TODO)
    void Setup(Info& info);

    LWAPI(0x0218eb24, 0x004926e0)
    FileSystem();
};
}
}
