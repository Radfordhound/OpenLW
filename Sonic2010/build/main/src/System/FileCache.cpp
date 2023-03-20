// TODO: The name of this file is correct, but the path was guessed!
#include "pch.h"
#include "FileCache.h"

namespace app
{
namespace fnd
{
FileCache::~FileCache()
{
    ReleaseCacheAll();
    // TODO
}

void FileCache::AddCache(const char* param_1, void* param_2,
    std::size_t param_3, bool param_4)
{
    if (!IsCache(param_1) && param_2)
    {
        CreateCacheCore(param_1, param_2, &param_3, param_4);
    }
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
    auto it = field_0x218.find(param_1);
    if (it != field_0x218.end())
    {
        CacheDataTag* dataTag = field_0x218.GetValue(it);
        // TODO
        return true;
    }

    return false;
}

void FileCache::OnEnterCache(const char* param_1)
{
    // TODO
}

void FileCache::OnLeaveCache() {}

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

FileCache::FileCache()
    // TODO
{
    // TODO

    field_0x218.Reset(nullptr, 0, m_allocator);
    field_0x218.reserve(2048);
}
}
}
