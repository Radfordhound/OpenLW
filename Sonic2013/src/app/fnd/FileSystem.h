#pragma once
#include "ReferencedObject.h"
#include "csl/fnd/Singleton.h"
#include "FileBinder.h"
#include "FileCache.h"

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

class FileSystem : public ReferencedObject, public csl::fnd::Singleton<FileSystem>
{
public:
    char RootDirectory[256];

    // TODO: Data Members
    
    FileCache* Cache = nullptr;
    FILE_SYSTEM_FLAG Flags = static_cast<FILE_SYSTEM_FLAG>(
        FILE_SYSTEM_FLAG_USE_CPK | FILE_SYSTEM_FLAG_UK2);

    // TODO: Data Members (Actually I think there aren't any more here)

    struct Info // size == 8
    {
        const char* RootDirectory = nullptr;
        bool fx05 = true;
        bool fx06 = true;

        // TODO: Are the remaining 2 bytes for sure just padding?
    };

    /*
        @brief Constructor for FileSystem.
        <b>Wii U: 0x0218eb24, PC: TODO</b>
    */
    FileSystem();

    /*
        @brief Destructor for FileSystem.
        <b>Wii U: TODO, PC: TODO</b>
    */
    ~FileSystem() override;

    /* <b>Wii U: TODO, PC: TODO</b> */
    virtual void Update();

    /* <b>Wii U: TODO, PC: TODO</b> */
    virtual FileBinder* GetDefaultBinder() const;

    /* <b>Wii U: 0x0218ead0, PC: TODO</b> */
    void SetFileCacheSize(std::size_t cacheSize);

    /* <b>Wii U: 0x0218e5c8, PC: TODO</b> */
    void SetRootDirectory(const char* rootDir);

    /* <b>Wii U: TODO, PC: TODO</b> */
    void Setup(Info& info);

    // TODO
};
}
}
