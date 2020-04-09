#include "FileCache.h"

namespace app
{
namespace fnd
{
FileCache::FileCache()
{
    // TODO
}

FileCache::~FileCache()
{
    ReleaseCacheAll();
    // TODO
}

void FileCache::AddCache(const char* param_1, void* param_2,
    std::size_t param_3, bool param_4)
{
    // TODO
}

std::size_t FileCache::CalcFreeCache()
{
    // TODO
    return 0;
}

char* FileCache::CreateCache(char const* param_1, std::size_t* param_2, bool param_3)
{
    // TODO
    return nullptr;
}

char* FileCache::CreateCacheCore(char const* param_1, void* param_2, \
    std::size_t* param_3, bool param_4)
{
    // TODO
    return nullptr;
}

void* FileCache::GetCache(const char* param_1, std::size_t* param_2)
{
    // TODO
    return nullptr;
}

bool FileCache::IsCache(const char* param_1) const
{
    // TODO
    return false;
}

void FileCache::OnEnterCache()
{
    // TODO
}

void FileCache::OnLeaveCache()
{
    // TODO
}

void FileCache::ReleaseCache()
{
    // TODO
}

void FileCache::ReleaseCacheAll()
{
    // TODO
}

bool FileCache::SetHintCache(const char* param_1)
{
    // TODO
    return false;
}

void FileCache::Setup(std::size_t cacheSize)
{
    // TODO
}
}
}
