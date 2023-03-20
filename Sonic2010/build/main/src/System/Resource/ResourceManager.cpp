// TODO: The name of this file is correct, but the path was guessed!
#include "pch.h"
#include "ResourceManager.h"
#include "ResourceSysCustom.h"
#include "Memory/MemoryRouter.h"
#include "System/FileSystem.h"
#include <new>

using namespace csl::ut;

namespace app
{
namespace fnd
{
void ResourceManager::RegisterList(const ResourceCustomInfo* const* resCustomInfoList)
{
    ResourceCustomInfo* curResCustomInfo = const_cast<ResourceCustomInfo*>(*resCustomInfoList);
    std::size_t i = 0;

    m_resourceCustomInfoList = resCustomInfoList;
    m_defaultLoader = nullptr;

    while (curResCustomInfo)
    {
        if (curResCustomInfo->CreateLoader)
        {
            curResCustomInfo->Loader = curResCustomInfo->CreateLoader();
            if (std::strcmp(curResCustomInfo->Extension, "*") == 0)
            {
                m_defaultLoader = curResCustomInfo->Loader;
            }
            else
            {
                m_resourceLoaders.insert(curResCustomInfo->Extension,
                    curResCustomInfo->Loader);
            }
        }

        curResCustomInfo = const_cast<ResourceCustomInfo*>(resCustomInfoList[++i]);
    }
}

static ResourceCustomInfo* const ResourceCustomInfoList[] =
{
    &DefResourceCustomInfo,
    &PacResourceCustomInfo,
    /*&OrcaResourceCustomInfo,
    &CriAcfResourceCustomInfo,
    &CriAcbResourceCustomInfo,*/
    nullptr
};

ResourceManager::ResourceManager() :
    m_resourceCustomInfoList(nullptr),
    // TODO
    m_defaultLoader(nullptr),
    m_resourceLoaders(64, m_allocator),
    m_resourceData(512, m_allocator),
    m_resourceNames(1024, m_allocator),
    m_resourceCallbackData(32, m_allocator)
    // TODO
{
    RegisterList(ResourceCustomInfoList);
}

IResourceCustomLoader* ResourceManager::GetResourceLoader(const char* name)
{
    if (!m_resourceLoaders.empty())
    {
        FileSystem& fileSystem = FileSystem::GetInstance();
        const char* ext = fileSystem.GetFileExtension(name);
        auto it = m_resourceLoaders.find(ext);

        if (it != m_resourceLoaders.end())
        {
            return m_resourceLoaders.GetValue(it);
        }
    }

    return m_defaultLoader;
}

bool ResourceManager::AddResourceName(const char* name,
    csl::fnd::com_ptr<FileHandleObj> fileHandle)
{
    // TODO
    
    auto it = m_resourceNames.find(name);
    if (it == m_resourceNames.end())
    {
        // Allocate buffer large enough to hold ResourceData and resource name.
        std::size_t nameSize = RoundUp(std::strlen(name) + 1, 4);
        ResourceData* resData = static_cast<ResourceData*>(
            m_allocator->Alloc(sizeof(ResourceData) + nameSize));

        // Construct default ResourceData and copy name into buffer.
        new (resData) ResourceData(); // TODO: Is the null pointer check done automatically?
        std::strcpy(reinterpret_cast<char*>(resData + 1), name);
        
        // Construct proper ResourceData.
        resData->Name = reinterpret_cast<char*>(resData + 1);
        resData->Loader = GetResourceLoader(name);
        resData->FileHandle = fileHandle;
        resData->Flags = 0;
        resData->Data = m_allocator->Alloc(sizeof(ResourceData));

        std::memset(resData->Data, 0, sizeof(ResourceData));

        // Insert resource into resource manager.
        m_resourceData.push_back_unchecked(resData);
        m_resourceNames.insert(resData->Name, resData);

        // TODO
        return true;
    }

    // TODO
    return false;
}

void ResourceManager::CreateResource(const char* name, csl::fnd::IAllocator* allocator,
    void* data, std::size_t size, int category, unsigned int param_6)
{
    ResourceArgsData resArgs =
    {
        allocator,                                                      // Allocator
        name,                                                           // Name
        data,                                                           // Address
        size,                                                           // Size
        category                                                        // Category
    };

    // TODO
    
    if (!m_resourceNames.empty())
    {
        auto it = m_resourceNames.find(name);
        if (it != m_resourceNames.end())
        {
            ResourceData* resData = m_resourceNames.GetValue(it);
            resData->Loader->Setup(this, resArgs);
        }
    }
    
    // TODO
}

int ResourceManager::ResouceCallbackSort(ResourceCallbackData a, ResourceCallbackData b)
{
    return (a.Value < b.Value);
}

void ResourceManager::AddCallback(ResourceCallbackBase* callback, unsigned int value)
{
    // TODO

    ResourceCallbackData callbackData =
    {
        value,
        callback
    };

    m_resourceCallbackData.push_back_unchecked(callbackData);

    std::sort(m_resourceCallbackData.begin(), m_resourceCallbackData.end(),
        ResouceCallbackSort);

    // TODO
}

void ResourceManager::SetupCallback(hh::ut::Packfile pac, csl::fnd::IAllocator* allocator)
{
    // TODO

    for (std::size_t i = 0; i < m_resourceCallbackData.size(); ++i)
    {
        ResourceCallbackData& resCallbackData = m_resourceCallbackData.at(i);
        // TODO
    }

    // TODO
}

void* ResourceManager::GetResource(const char* name, std::size_t size)
{
    void* res = nullptr;
    // TODO

    if (!m_resourceNames.empty())
    {
        auto it = m_resourceNames.find(name);
        if (it != m_resourceNames.end())
        {
            ResourceData* resData = m_resourceNames.GetValue(it);
            if ((resData->Flags & 1) == 0)
            {
                if (size != sizeof(ResourceData))
                {
                    m_allocator->Free(resData->Data);
                    resData->Data = m_allocator->Alloc(size);
                    std::memset(resData->Data, 0, size);
                }

                resData->Flags |= 1;
            }

            res = resData->Data;
            // TODO ?
        }
    }

    // TODO
    return res;
}

LWAPI(0x021b0ec0, TODO)
static void* ResourceManager_init()
{
    ResourceManager* resMgr = new (GetSingletonAllocator()) ResourceManager();
    resMgr->AddRef();
    return resMgr;
}

LWAPI(0x021b0f10, TODO)
static void ResourceManager_destroy(void* ptr)
{
    static_cast<ResourceManager*>(ptr)->Release();
}

DEFINE_SINGLETON(ResourceManager, ResourceManager_init, ResourceManager_destroy);
}
}
