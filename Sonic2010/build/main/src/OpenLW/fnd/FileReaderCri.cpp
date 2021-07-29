#ifdef USE_CRIWARE
#include "FileReaderCri.h"
#include "FileSystem.h"
#include "Allocators.h"

using namespace app::fnd::file;
using namespace csl::fnd;
using namespace csl::ut;

namespace app
{
namespace fnd
{
namespace file
{
// TODO: Should this be moved to another header?
// Wii U: 0x0218fb4c (THUNK), PC: TODO
static void CRIAPI CriLoadEndCbFunc(void* obj, CriFsLoaderHn loader)
{
    FileReaderCri::Loader::LoadEndCbFunc(obj, loader);
}
}

void FileReaderCri::Loader::LoadEndCbFunc(void* obj, CriFsLoaderHn loader)
{
    static_cast<FileReaderCri::Loader*>(obj)->field_0x8 |= 2;
}

void FileReaderCri::Loader::Flush()
{
    field_0x4 = nullptr;
    field_0x8 &= 0xfffffffc;
}

FileReaderCri::Loader::Loader() :
    Handle(nullptr),
    field_0x4(nullptr),
    field_0x8(0),
    field_0x10(0),
    field_0x14(0)
{
    criFsLoader_Create(&Handle);
    criFsLoader_SetLoadEndCallback(Handle, CriLoadEndCbFunc, this);
}

FileReaderCri::Loader::~Loader()
{
    criFsLoader_Destroy(Handle);
}

FileReaderCri::Request::Request() :
    field_0x0(nullptr),
    field_0x4(0) {}

FileReaderCri::~FileReaderCri()
{
    StopFileAll();
    WaitSyncAll();

    field_0x1c.clear();

    while (!field_0xc.empty())
    {
        field_0xc.pop_back();
    }

    field_0xc.clear();

    if (field_0x68)
    {
        for (auto it = field_0x44.begin(); it != field_0x44.end(); ++it)
        {
            (*it)->~Loader();
        }

        field_0x44.clear();
        m_allocator->Free(field_0x68);
    }
}

void FileReaderCri::Update()
{
    if (!field_0x58.empty())
    {
        FileSystem& fileSystem = FileSystem::GetInstance();
        auto it = field_0x58.begin();

        while (it != field_0x58.end())
        {
            Request* req;
            FileHandleObj* fileHandle;
            Loader* loader;

            while (true)
            {
                req = *it;
                fileHandle = req->field_0x0.get();

                while (true)
                {
                    if ((fileHandle->field_0x9c & 2) == 0)
                    {
                        break;
                    }

                    fileHandle->field_0x1c = 6;
                    req->~Request();
                    m_allocator->Free(req);

                    it = field_0x58.erase(it);
                    if (it == field_0x58.end()) goto LAB_02190c3c;
                }

                loader = GetFreeLoader();
                if (!loader) goto LAB_02190c3c;

                if ((fileHandle->field_0x9c & 1) == 0)
                {
                    fileHandle->Buffer = fileHandle->Allocator->Alloc(
                        fileHandle->BufferSize, ((fileHandle->field_0x9c & 0x20000000) != 0) ?
                        -64 : 64);
                }

                if (fileSystem.Cache && ((fileHandle->field_0x9c & 0x40000000) != 0))
                {
                    break;
                }

LAB_02190b60:
                fileHandle->field_0x1c = 3;
                fileHandle->field_0x94 = loader;
                loader->field_0x4 = req->field_0x0;
                
                // TODO: The original code is actually the commented-out code below:
                /*criFsLoader_Load(loader->Handle, static_cast<CriFsBinderHn>(
                    fileHandle->Binder->GetBinderHn()), fileHandle->field_0x20,
                    fileHandle->BufferSize, 0, nullptr, 0, fileHandle->FileSize, fileHandle->Buffer);*/

                criFsLoader_Load(loader->Handle, static_cast<CriFsBinderHn>(
                    fileHandle->Binder->GetBinderHn()), fileHandle->field_0x20,
                    0, fileHandle->FileSize, fileHandle->Buffer,
                    fileHandle->BufferSize);

                req->~Request();
                m_allocator->Free(req);

                it = field_0x58.erase(it);

                field_0x34.push_back_unchecked(loader);

                if (it == field_0x58.end()) goto LAB_02190c3c;
            }

            std::size_t local_2c = 0;
            void* pvVar2 = fileSystem.Cache->GetCache(fileHandle->field_0x60, &local_2c);
            if (!pvVar2) goto LAB_02190b60;

            // TODO: FastMemCopy

            fileHandle->field_0x1c = 4;

            req->~Request();
            m_allocator->Free(req);

            it = field_0x58.erase(it);

            loader->Flush();
        }
    }

LAB_02190c3c:
    if (!field_0x34.empty())
    {
        FileSystem& fileSystem = FileSystem::GetInstance();
        auto it = field_0x34.begin();

        while (it != field_0x34.end())
        {
            Loader* loader;
            FileHandleObj* fileHandle;
            CriFsLoaderStatus status;

            while (true)
            {
                while (true)
                {
                    while (loader = *it, (loader->field_0x8 & 2) == 0)
                    {
                        if (++it == field_0x34.end())
                        {
                            return;
                        }
                    }

                    fileHandle = loader->field_0x4.get();
                    fileHandle->field_0x94 = nullptr;

                    criFsLoader_GetStatus(loader->Handle, &status);
                    if (status != CRIFSLOADER_STATUS_STOP) break;

                    fileHandle->field_0x1c = 6;
                    loader->Flush();

                    it = field_0x34.erase(it);
                    if (it == field_0x34.end())
                    {
                        return;
                    }
                }

                if (status == CRIFSLOADER_STATUS_COMPLETE)
                {
                    break;
                }
                else if (status == CRIFSLOADER_STATUS_ERROR)
                {
                    fileHandle->field_0x1c = 5;
LAB_02190d8c:
                    loader->Flush();

                    it = field_0x34.erase(it);
                    if (it == field_0x34.end())
                    {
                        return;
                    }
                }
                else
                {
                    loader->Flush();

                    it = field_0x34.erase(it);
                    if (it == field_0x34.end())
                    {
                        return;
                    }
                }
            }

            fileHandle->field_0x1c = 4;

            // TODO: Un-comment this on Wii U:
            //DCFlushRange(fileHandle->Buffer, fileHandle->BufferSize);

            if (!fileSystem.Cache || (fileHandle->field_0x9c & 0x40000000) == 0)
            {
                goto LAB_02190d8c;
            }

            fileSystem.Cache->AddCache(fileHandle->field_0x60,
                fileHandle->Buffer, fileHandle->FileSize,
                fileHandle->field_0x9c >> 31);

            loader->Flush();

            it = field_0x34.erase(it);
            if (it == field_0x34.end())
            {
                return;
            }
        }
    }
}

csl::fnd::com_ptr<FileHandleObj> FileReaderCri::GetFileHandle(const char* registName)
{
    if (!field_0x1c.empty())
    {
        auto it = field_0x1c.find(registName);
        if (it != field_0x1c.end())
        {
            return field_0x1c.GetValue(it);
        }
    }
    
    return nullptr;
}

bool FileReaderCri::IsFileExist(const char* filePath, FileBinder* binder)
{
    if (!binder)
    {
        binder = FileSystem::GetInstance().GetDefaultBinder();
    }
    
    return binder->IsFileExist(filePath);
}

std::size_t FileReaderCri::GetFileSize(const char* filePath, FileBinder* binder)
{
    if (!binder)
    {
        binder = FileSystem::GetInstance().GetDefaultBinder();
    }

    return binder->GetFileSize(filePath);
}

csl::fnd::com_ptr<FileHandleObj> FileReaderCri::LoadFile(const char* filePath,
    const char* param_2, csl::fnd::IAllocator* allocator,
    void* param_4, unsigned int param_5, FileBinder* binder)
{
    com_ptr<FileHandleObj> fileHandle = CreateHandle(
        filePath, param_2, allocator, param_4, param_5, binder);

    AddRequest(fileHandle);
    return fileHandle;
}

void FileReaderCri::StopFile(csl::fnd::com_ptr<FileHandleObj> fileHandle)
{
    // TODO
}

void FileReaderCri::StopFileAll()
{
    // TODO
}

bool FileReaderCri::UnloadFile(csl::fnd::com_ptr<FileHandleObj> fileHandle)
{
    if (fileHandle && fileHandle->IsValid())
    {
        StopFile(fileHandle);
        WaitSync(fileHandle);
        return RemoveFileHnList(fileHandle);
    }

    return false;
}

bool FileReaderCri::IsSyncComplete(csl::fnd::com_ptr<FileHandleObj> fileHandle)
{
    if (fileHandle && fileHandle->IsValid())
    {
        return (fileHandle->field_0x1c > 3);
    }

    return true;
}

bool FileReaderCri::IsSyncCompleteAll()
{
    if (!field_0xc.empty())
    {
        for (std::size_t i = 0; i < field_0xc.size(); ++i)
        {
            if (field_0xc[i]->field_0x1c < 4)
            {
                return false;
            }
        }
    }

    return true;
}

void FileReaderCri::WaitSync(csl::fnd::com_ptr<FileHandleObj> fileHandle)
{
    // TODO
}

void FileReaderCri::WaitSyncAll()
{
    // TODO
}

bool FileReaderCri::DbgGet(csl::ut::MoveArray<dbg::FileInfo::Data>& param_1, bool param_2)
{
    return false;
}

csl::fnd::com_ptr<FileHandleObj> FileReaderCri::CreateHandle(const char* filePath,
    const char* param_2, csl::fnd::IAllocator* allocator,
    void* param_4, unsigned int param_5, fnd::FileBinder* binder)
{
    com_ptr<FileHandleObj> fileHandle;
    
    // Create regist name.
    StringBuf<128> registName(GetTempAllocator());
    CreateRegistName(filePath, param_2, &registName);

    // If we already have a handle to this file open, just return it.
    fileHandle = GetFileHandle(registName);
    if (fileHandle) return fileHandle;

    // Get the default binder.
    if (!binder)
    {
        binder = FileSystem::GetInstance().GetDefaultBinder();
    }

    // This file is not currently open; create a new file handle for it.
    std::size_t fileSize = binder->GetFileSize(filePath);
    if (fileSize)
    {
        // Create new file handle.
        fileHandle = file::CreateHandle(m_allocator);
        if (!param_4)
        {
            param_5 = RoundUp(fileSize, 64);
        }

        fileHandle->Buffer = param_4;
        fileHandle->BufferSize = param_5;
        fileHandle->FileSize = fileSize;
        fileHandle->field_0x1c = 1;
        fileHandle->Binder = binder;
        fileHandle->field_0x94 = 0;
        fileHandle->Allocator = allocator;
        fileHandle->field_0x9c = (param_4 != nullptr);

        StrLcpy(fileHandle->field_0x20, filePath, 64);
        StrLcpy(fileHandle->field_0x60, registName, 48);

        // Add the new handle to the list.
        AddFileHnList(fileHandle);
    }

    return fileHandle;
}

void FileReaderCri::AddRequest(const csl::fnd::com_ptr<FileHandleObj>& fileHandle,
    void* buffer, std::size_t bufSize)
{
    if (fileHandle && fileHandle->IsValid() && fileHandle->field_0x1c == 1)
    {
        fileHandle->field_0x1c = 2;
        if (buffer)
        {
            fileHandle->Replace(buffer, fileHandle->FileSize, bufSize, true);
        }

        Request* request = new (m_allocator) Request();
        request->field_0x0 = fileHandle;
        AddRequestList(request);
    }
}

void FileReaderCri::AddRequest(const csl::fnd::com_ptr<FileHandleObj>& fileHandle)
{
    AddRequest(fileHandle, nullptr, 0);
}

void FileReaderCri::AddRequestList(Request* request)
{
    field_0x58.push_back_unchecked(request);
}

void FileReaderCri::CreateRegistName(const char* filePath, const char* registName,
    csl::ut::String* result)
{
    FileSystem& fileSystem = FileSystem::GetInstance();
    *result = (registName) ? registName : fileSystem.GetFileName(filePath);
}

bool FileReaderCri::AddFileHnList(const csl::fnd::com_ptr<FileHandleObj>& fileHandle)
{
    if (field_0x1c.find(fileHandle->field_0x60) == field_0x1c.end())
    {
        field_0xc.push_back_unchecked(fileHandle);
        field_0x1c.insert(fileHandle->field_0x60, fileHandle.get());
        return true;
    }

    return false;
}

bool FileReaderCri::RemoveFileHnList(const csl::fnd::com_ptr<FileHandleObj>& fileHandle)
{
    auto it = field_0x1c.find(fileHandle->field_0x60);
    if (it != field_0x1c.end())
    {
        field_0x1c.erase(it);
        fileHandle->Destroy();
        field_0xc.erase_find(fileHandle);
        return true;
    }

    return false;
}

FileReaderCri::Loader* FileReaderCri::GetFreeLoader()
{
    if (!field_0x44.empty())
    {
        std::size_t loaderIndex = field_0x54;
        for (std::size_t i = 0; i < field_0x44.size(); ++i)
        {
            ++loaderIndex;
            if (loaderIndex > field_0x44.size())
            {
                loaderIndex = 0;
            }

            Loader* loader = field_0x44.at(loaderIndex);
            if ((loader->field_0x8 & 1) == 0)
            {
                loader->field_0x8 |= 1;
                field_0x54 = loaderIndex;
                return loader;
            }
        }
    }

    return nullptr;
}

FileReaderCri* FileReaderCri::Create(csl::fnd::IAllocator* allocator,
    std::size_t param_2, std::size_t param_3)
{
    return new (allocator) FileReaderCri(param_2, param_3);
}

FileReaderCri::FileReaderCri(std::size_t param_1, std::size_t param_2) :
    field_0xc(256, m_allocator),
    field_0x1c(512, m_allocator),
    field_0x34(param_1, m_allocator),
    field_0x44(param_1, m_allocator),
    field_0x54(0),
    field_0x58(param_2, m_allocator),
    field_0x68(nullptr)
{
    field_0x68 = static_cast<Loader*>(m_allocator->Alloc(
        sizeof(Loader) * param_1));

    for (std::size_t i = 0; i < field_0x44.capacity(); ++i)
    {
        field_0x44.push_back_unchecked(new (field_0x68 + i) Loader());
    }
}
}
}
#endif
