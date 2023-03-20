#include "pch.h"
#include "FileSystem.h"
#include "Memory/MemoryRouter.h"

using namespace csl::fnd;
using namespace csl::ut;

namespace app
{
namespace fnd
{
FileSystem::~FileSystem() {}

void FileSystem::Update() {}

FileBinder* FileSystem::GetDefaultBinder() const
{
    return nullptr;
}

const char* FileSystem::GetFileExtension(const char* filePath)
{
    const char* ptr = GetFileName(filePath);
    const char* end = std::strchr(ptr, 0);

    while (ptr <= end && *ptr != '\\' && *ptr != '/')
    {
        if (*ptr++ == '.') return ptr;
    }

    return end;
}

const char* FileSystem::GetFileName(const char* filePath)
{
    for (const char* ptr = std::strchr(filePath, 0); ptr >= filePath; --ptr)
    {
        if (*ptr == '\\' || *ptr == '/')
            return (ptr + 1);
    }

    return filePath;
}

void FileSystem::GetFileNameNoExtension(const char* filePath, csl::ut::String* result)
{
    StringBuf<128> fileNameNoExt("", GetTempAllocator());

    const char* fileName = GetFileName(filePath);
    const char* ext = GetFileExtension(fileName);

    if (*ext != '\0') --ext;

    fileNameNoExt.copyFrom(fileName, static_cast<std::size_t>(ext - fileName));

    *result = fileNameNoExt;
}

void FileSystem::GetPathName(const char* filePath, csl::ut::String* result)
{
    StringBuf<128> str("", GetTempAllocator());
    for (const char* ptr = std::strchr(filePath, 0); ptr >= filePath; --ptr)
    {
        if (*ptr == '\\' || *ptr == '/')
        {
            str.copyFrom(filePath, static_cast<std::size_t>(ptr - filePath));
            break;
        }
    }

    *result = str;
}

void FileSystem::SetFileCacheSize(std::size_t cacheSize)
{
    if (cacheSize)
    {
        if (!FileCache::IsInitialized())
        {
            Cache = nullptr;
        }
        else
        {
            FileCache::GetInstance().Setup(cacheSize);
            Cache = &FileCache::GetInstance();
        }
    }
}

void FileSystem::SetRootDirectory(const char* rootDir)
{
    StringBuf<128> str(rootDir, GetTempAllocator());
    if (!str.empty())
    {
        StringBuf<128> str2("", GetTempAllocator());
        str2.copyFrom(str.c_str(), 1, str.length() - 1);
        
        if (str2 != "/" && str2 != "\\")
        {
            str.append("/");
        }
    }

    StrLcpy(RootDirectory, str.c_str(), 256);
}

void FileSystem::Setup(Info& info)
{
    if (info.RootDirectory)
    {
        SetRootDirectory(info.RootDirectory);
    }
}

FileSystem::FileSystem() :
    Cache(nullptr),
    Flags(static_cast<FILE_SYSTEM_FLAG>(FILE_SYSTEM_FLAG_USE_CPK | FILE_SYSTEM_FLAG_UK2))
{
    SetRootDirectory("");
}
}
}
