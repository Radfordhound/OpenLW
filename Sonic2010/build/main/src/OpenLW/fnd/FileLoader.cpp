#include "FileLoader.h"
#include "FileReader.h"
#include "FileSystem.h"
#include "Allocators.h"
#include "ResourceManager.h"
#include "../game/GlobalAllocator.h"
#include "../gfx/RenderManager.h"
#include <Hedgehog/Utility/hhPackfile.h>
#include <csl/fnd/thread.h>

using namespace app::gfx;
using namespace app::game;
using namespace hh::mr;
using namespace hh::ut;
using namespace csl::fnd;
using namespace csl::ut;

namespace app
{
namespace fnd
{
FileLoaderParam::FileLoaderParam() :
    field_0x0(0),
    field_0x4(nullptr),
    field_0x8(0),
    field_0xc(0x2000),
    field_0x10(nullptr),
    field_0x14(0) {}

FileLoader::LoadInfo::LoadInfo() :
    field_0x0(nullptr),
    field_0x4(nullptr),
    field_0x8(0),
    field_0xc(0),
    field_0x10(-1),
    field_0x14(0),
    field_0x18(0),
    field_0x1c(0),
    field_0x20(0) {}

void FileLoader::LoadBuffer::AddRef()
{
    if (++RefCount != 1)
        return;

    field_0x70 = true;
}

void FileLoader::LoadBuffer::Reset()
{
    field_0x70 = false;
    // TODO
}

FileLoader::LoadBuffer::LoadBuffer(std::size_t param_1,
    csl::fnd::IAllocator* allocator, unsigned int param_3)
{
    // TODO
}

FileLoader::LoadBuffer* FileLoader::GetLoadBuffer(std::size_t index)
{
    if (index != SIZE_MAX)
    {
        return (field_0x44 <= index) ? nullptr : (field_0x40 + index);
    }

    for (std::size_t i = 0; i < field_0x44; ++i)
    {
        if (!field_0x40[i].field_0x70)
        {
            return (field_0x40 + i);
        }
    }

    return nullptr;
}

FileLoader::~FileLoader()
{
    // TODO
}

void FileLoader::GetMultiLangResourceName(const char* name, csl::ut::String* result)
{
    StringBuf<128> stringBuf1(name, GetTempAllocator());
    FileSystem& fileSystem = FileSystem::GetInstance();
    StringBuf<128> ext(fileSystem.GetFileExtension(name), GetTempAllocator());

    if (!ext.empty())
    {
        StringBuf<128> stringBuf3(GetTempAllocator());
        fileSystem.GetFileNameNoExtension(name, &stringBuf3);

        StringBuf<128> stringBuf4(GetTempAllocator());
        stringBuf4.copyFrom(stringBuf3.c_str(), stringBuf3.length() - 2, 0, 0);

        stringBuf4 += ".";
        stringBuf4 += ext;
        stringBuf1 = stringBuf4;
    }

    *result = stringBuf1;
}

void FileLoader::ResourceJobMTExec(LoadInfo* loadInfo)
{
    ResourceManager& resMgr = ResourceManager::GetInstance();
    const char* name = loadInfo->field_0x4->field_0x60;
    StringBuf<128> stringBuf(name, GetTempAllocator());

    if ((loadInfo->field_0x20 & 1) != 0)
    {
        GetMultiLangResourceName(name, &stringBuf);
    }

    resMgr.CreateResource(stringBuf, loadInfo->field_0x0, loadInfo->field_0x4->Buffer,
        loadInfo->field_0x4->FileSize, loadInfo->field_0x8, loadInfo->field_0x20);

    if ((loadInfo->field_0xc & 2) != 0)
    {
        loadInfo->field_0xc |= 8;
    }

    if ((loadInfo->field_0xc & 4) != 0)
    {
        StringBuf<128> stringBuf2(GetTempAllocator());
        FileSystem& fileSystem = FileSystem::GetInstance();

        fileSystem.GetFileNameNoExtension(stringBuf, &stringBuf2);
        stringBuf2 += ".pac";

        Packfile pac1(resMgr.Get<ResRawData>(stringBuf2).GetAddress());
        Packfile pac2(loadInfo->field_0x4->Buffer);

        RenderManager& renderMgr = RenderManager::GetInstance();
        CRenderingInfrastructure* renderInfra = renderMgr.GetRenderingDevice();

        pac2.Setup(loadInfo->field_0x0, renderInfra);

        Packfile otherPac(pac2);
        __debugbreak(); // TODO: Un-comment the following code and remove this line
        /*pac1.Import(otherPac);
        pac2.Cleanup();*/

        if (pac1.IsImportCompleted() || pac1.GetNumberOfImport() == 0)
        {
            resMgr.SetupCallback(otherPac, loadInfo->field_0x0);
        }

        loadInfo->field_0xc |= 0x1000;
    }
}

bool FileLoader::ResourceJobMTStart(LoadInfo* loadInfo)
{
    if ((loadInfo->field_0xc & 1) == 0)
    {
        ResourceManager& resMgr = ResourceManager::GetInstance();
        const char* name = loadInfo->field_0x4->field_0x60;
        StringBuf<128> stringBuf(name, GetTempAllocator());

        if ((loadInfo->field_0x20 & 1) != 0)
        {
            GetMultiLangResourceName(name, &stringBuf);
        }

        if (resMgr.AddResourceName(stringBuf, loadInfo->field_0x4))
        {
            resMgr.CreateResource(stringBuf, loadInfo->field_0x0,
                loadInfo->field_0x4->Buffer, loadInfo->field_0x4->FileSize,
                loadInfo->field_0x8, loadInfo->field_0x20);
        }

        return false;
    }
    else if ((loadInfo->field_0xc & 16) == 0)
    {
        const char* name = loadInfo->field_0x4->field_0x60;
        StringBuf<128> stringBuf(name, GetTempAllocator());

        if ((loadInfo->field_0x20 & 1) != 0)
        {
            GetMultiLangResourceName(name, &stringBuf);
        }

        if (ResourceManager::GetInstance().AddResourceName(
            stringBuf, loadInfo->field_0x4))
        {
            loadInfo->field_0xc |= 2;
        }
    }
    else
    {
        loadInfo->field_0xc |= 4;
    }

    field_0x20.push_back_unchecked(loadInfo);
    // TODO
    __debugbreak(); ResourceJobMTExec(loadInfo); // TODO: REMOVE THIS AND DO THE STUFF REQUIRED TO EVENTUALLY CALL ResourceJobMTExec PROPERLY!!!
    return true;
}

void FileLoader::ResourceJobExec()
{
    if (!field_0x20.empty())
    {
        FileSystem& fileSystem = FileSystem::GetInstance();
        for (auto it = field_0x20.begin(); it != field_0x20.end(); ++it)
        {
            LoadInfo* loadInfo;
            while (true)
            {
                loadInfo = *it;

                if ((loadInfo->field_0xc & 2) == 0)
                    break;

                if ((loadInfo->field_0xc & 8) == 0)
                    goto LAB_0218d460;

                {
                    Packfile pac(loadInfo->field_0x4->Buffer);
                    if (!pac.IsImport() || pac.IsImportCompleted())
                    {
                        goto LAB_0218d418;
                    }

                    StringBuf<128> stringBuf(GetTempAllocator());
                    fileSystem.GetPathName(loadInfo->field_0x4->field_0x20, &stringBuf);

                    // TODO
                }

LAB_0218d424:
                m_allocator->Free(loadInfo);
                it = field_0x20.erase(it);

                if (it == field_0x20.end())
                {
                    goto LAB_0218d474;
                }
            }

            if ((loadInfo->field_0xc & 4) != 0 && ((loadInfo->field_0xc & 0x1000) != 0))
            {
                // TODO

LAB_0218d418:
                loadInfo->field_0x4.~com_ptr();
                goto LAB_0218d424;
            }

LAB_0218d460:;
        }

LAB_0218d474:
        LoadBufferRequestJobExec();
    }
}

void FileLoader::LoadBufferRequestJobExec()
{
    if (!field_0x30.empty())
    {
        FileReader& fileReader = FileReader::GetInstance();
        auto it = field_0x30.begin();
        bool bVar1 = true;

        if (it != field_0x30.end())
        {
            LoadBuffer* loadBuffer;
            while (!bVar1 || ((loadBuffer = GetLoadBuffer(SIZE_MAX))))
            {
                LoadInfo* loadInfo = *it;
                bVar1 = false;

                std::size_t uVar4 = RoundUp(loadInfo->field_0x4->FileSize, 64);
                // TODO

                loadBuffer->AddRef();

                // TODO: Un-comment this line:
                //loadInfo->field_0x14 = uVar5;
                loadInfo->field_0xc |= 0x800;
                loadInfo->field_0x10 = loadBuffer->field_0x68;
                loadInfo->field_0x18 = uVar4;

                fileReader.AddRequest(loadInfo->field_0x4); // TODO: Is this correct?

                field_0x10.push_back_unchecked(loadInfo);

                it = field_0x30.erase(it);
                if (it == field_0x30.end())
                {
                    return;
                }
            }
        }
    }
}

void FileLoader::LoadBufferReset()
{
    for (std::size_t i = 0; i < field_0x44; ++i)
    {
        GetLoadBuffer(i)->Reset();
    }
}

void FileLoader::Update()
{
    if (!field_0x10.empty() || !field_0x20.empty() || !field_0x30.empty())
    {
        for (auto it = field_0x10.begin(); it != field_0x10.end();)
        {
            com_ptr<FileHandleObj> tmpFileHandle((*it)->field_0x4);
            if (tmpFileHandle->field_0x1c == 4)
            {
                if (((*it)->field_0xc & 0x100000) == 0)
                {
                    if (!ResourceJobMTStart(*it))
                    {
                        (*it)->~LoadInfo();
                        m_allocator->Free(*it);
                    }
                }
                else
                {
                    FileReader& fileReader = FileReader::GetInstance();
                    fileReader.UnloadFile((*it)->field_0x4);

                    (*it)->~LoadInfo();
                    m_allocator->Free(*it);
                }

                it = field_0x10.erase(it);
            }
            else if (tmpFileHandle->field_0x1c == 6)
            {
                FileReader& fileReader = FileReader::GetInstance();
                fileReader.UnloadFile(tmpFileHandle);

                if (*it)
                {
                    (*it)->~LoadInfo();
                }

                m_allocator->Free(*it);

                it = field_0x10.erase(it);
            }
            else
            {
                ++it;
            }
        }

        ResourceJobExec();

        if (field_0x10.empty() && field_0x20.empty() && field_0x30.empty())
        {
            LoadBufferReset();
            m_isSyncCompleteAll = true;
        }
    }
}

bool FileLoader::CheckInfoListInHandle(csl::fnd::com_ptr<FileHandleObj> fileHandle)
{
    if (!field_0x10.empty())
    {
        for (std::size_t i = 0; i < field_0x10.size(); ++i)
        {
            if (fileHandle == field_0x10[i]->field_0x4)
            {
                return true;
            }
        }
    }

    if (!field_0x20.empty())
    {
        for (std::size_t i = 0; i < field_0x20.size(); ++i)
        {
            if (fileHandle == field_0x20[i]->field_0x4)
            {
                return true;
            }
        }
    }
    
    if (!field_0x30.empty())
    {
        for (std::size_t i = 0; i < field_0x30.size(); ++i)
        {
            if (fileHandle == field_0x30[i]->field_0x4)
            {
                return true;
            }
        }
    }

    return false;
}

bool FileLoader::IsSyncComplete(csl::fnd::com_ptr<FileHandleObj> fileHandle)
{
    FileReader& fileReader = FileReader::GetInstance();
    if (fileReader.IsSyncComplete(fileHandle))
    {
        if (!CheckInfoListInHandle(fileHandle))
        {
            return true;
        }
    }
    
    return false;
}

bool FileLoader::IsSyncCompleteAll()
{
    return m_isSyncCompleteAll;
}

void FileLoader::WaitSync(csl::fnd::com_ptr<FileHandleObj> fileHandle)
{
    FileReader& fileReader = FileReader::GetInstance();
    while (!IsSyncComplete(fileHandle))
    {
        fileReader.Update();
        Update();

        if (IsSyncComplete(fileHandle))
        {
            break;
        }

        ThreadSleep(1);
    }
}

bool FileLoader::SetHintCache(const char* param_1)
{
    FileSystem& fileSystem = FileSystem::GetInstance();
    return (fileSystem.Cache) ?
        fileSystem.Cache->SetHintCache(param_1) :
        false;
}

bool FileLoader::PreLoadFile(const char* filePath, int param_2)
{
    // TODO
    return false;
}

csl::fnd::com_ptr<FileHandleObj> FileLoader::LoadFileOne(
    const char* filePath, const char* param_2,
    unsigned int param_3, const FileLoaderParam& params)
{
    FileReader& fileReader = FileReader::GetInstance();
    com_ptr<FileHandleObj> fileHandle = fileReader.CreateHandle(
        filePath, param_2, field_0xc, params.field_0x4,
        params.field_0x8, params.field_0x10);

    if (fileHandle)
    {
        if ((params.field_0xc & 0x1000) == 0)
        {
            fileHandle->field_0x9c |= 0x40000000;
            if ((params.field_0xc & 0x4000) != 0)
            {
                fileHandle->field_0x9c |= 0x80000000;
            }
        }
        else
        {
            fileHandle->field_0x9c |= 0x20000000;
        }

        // Create file load info.
        LoadInfo* loadInfo = new (m_allocator) LoadInfo();

        loadInfo->field_0x0 = field_0xc;
        loadInfo->field_0x4 = fileHandle;
        loadInfo->field_0x8 = params.field_0xc;
        loadInfo->field_0xc = param_3;
        loadInfo->field_0x20 = params.field_0x14;

        if ((param_3 & 0x400) == 0)
        {
            fileReader.AddRequest(fileHandle);
            field_0x10.push_back_unchecked(loadInfo);
            m_isSyncCompleteAll = false;
        }
        else
        {
            field_0x30.push_back_unchecked(loadInfo);
            m_isSyncCompleteAll = false;
        }
    }

    return fileHandle;
}

csl::fnd::com_ptr<FileHandleObj> FileLoader::LoadFile(
    const char* filePath, const char* param_2,
    const FileLoaderParam& params)
{
    FileSystem& fileSystem = FileSystem::GetInstance();
    StringBuf<128> filePathStr(filePath, GetTempAllocator());

    if ((params.field_0x14 & 1) != 0)
    {
        // TODO
    }

    const char* ext = fileSystem.GetFileExtension(filePathStr.c_str());
    return LoadFileOne(filePathStr.c_str(), param_2,
        (std::strcmp(ext, "pac") == 0), params);
}

csl::fnd::com_ptr<FileHandleObj> FileLoader::LoadFile(
    const char* filePath, const FileLoaderParam& params)
{
    return LoadFile(filePath, nullptr, params);
}

void FileLoader::SetupEx(unsigned int param_1, std::size_t param_2)
{
    param_1 = RoundUp(param_1, 128);
    if (param_2 != 0 && param_1 != 0)
    {
        field_0x40 = static_cast<LoadBuffer*>(m_allocator->Alloc(
            sizeof(LoadBuffer) * param_2));

        for (std::size_t i = 0; i < field_0x44; ++i)
        {
            new (field_0x40 + i) LoadBuffer(i, m_allocator, param_1);
        }
    }
    
    field_0xc = GlobalAllocator::GetAllocator(ALLOCATOR_UNK_TWO);
}

FileLoader::FileLoader() :
    field_0x10(128, m_allocator),
    field_0x20(128, m_allocator),
    field_0x30(128, m_allocator),
    // TODO
    field_0x44(0),
    m_isSyncCompleteAll(true)
    // TODO
{
    SetupEx(0xb00000, 2);
}

// Wii U: 0x0218e380, PC: TODO
static void* FileLoader_init()
{
    FileLoader* fileLoader = new (GetSingletonAllocator()) FileLoader();
    fileLoader->AddRef();
    return fileLoader;
}

// Wii U: 0x0218e3cc, PC: TODO
static void FileLoader_destroy(void* ptr)
{
    static_cast<FileLoader*>(ptr)->Release();
}

DEFINE_SINGLETON(FileLoader, FileLoader_init, FileLoader_destroy);
}
}
