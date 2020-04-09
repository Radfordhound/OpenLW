#include "FileSystem.h"
#include "csl/fnd/String.h"

namespace app
{
namespace fnd
{
FileSystem::FileSystem()
{
    SetRootDirectory("");
}

FileSystem::~FileSystem()
{
    // TODO
}

void FileSystem::Update() {}

FileBinder* FileSystem::GetDefaultBinder() const
{
    return nullptr;
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
            FileCache::GetInstance()->Setup(cacheSize);
            Cache = FileCache::GetInstance();
        }
    }
}

void FileSystem::SetRootDirectory(const char* rootDir)
{
    // TODO
    csl::fnd::StrLcpy(RootDirectory, rootDir, 256);

    //if (rootDir)
    // TODO
}

void FileSystem::Setup(Info& info)
{
    if (info.RootDirectory)
    {
        SetRootDirectory(info.RootDirectory);
    }
}
}
}
