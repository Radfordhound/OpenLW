#pragma once
#include "ReferencedObject.h"
#include "FileBinder.h"
#include "FileCache.h"
#include "Singleton.h"
#include "csl/ut/string.h"

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

        // Wii U: TODO, PC: TODO
        Info() :
            RootDirectory(nullptr),
            field_0x5(true),
            field_0x6(true) {}
    };

    char RootDirectory[256];
    FileCache* Cache;
    FILE_SYSTEM_FLAG Flags;

    // Wii U: 0x0218e570, PC: TODO
    ~FileSystem();

    // Wii U: 0x0218e5c4, PC: TODO
    virtual void Update();

    // Wii U: 0x0218e770, PC: TODO
    virtual FileBinder* GetDefaultBinder() const;

    // Wii U: 0x0218e7e4, PC: TODO
    const char* GetFileExtension(const char* filePath);

    // Wii U: 0x0218e778, PC: TODO
    const char* GetFileName(const char* filePath);

    // Wii U: 0x0218e854, PC: TODO
    void GetFileNameNoExtension(const char* filePath, csl::ut::String* result);

    // Wii U: 0x0218e974, PC: TODO
    void GetPathName(const char* filePath, csl::ut::String* result);

    // Wii U: 0x0218ead0, PC: TODO
    void SetFileCacheSize(std::size_t cacheSize);

    // Wii U: 0x0218e5c8, PC: TODO
    void SetRootDirectory(const char* rootDir);

    // Wii U: 0x0218e760, PC: TODO
    void Setup(Info& info);

    // Wii U: 0x0218eb24, PC: 0x004926e0
    FileSystem();
};
}
}
