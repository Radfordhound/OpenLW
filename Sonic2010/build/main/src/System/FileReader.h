// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include "FileHandle.h"
#include "Singleton.h"
#include <csl/ut/array.h>

namespace app
{
// TODO: Move all of this "dbg" stuff into its own header please!!!
namespace dbg
{
struct FileInfo
{
    struct Data
    {
        // TODO
    };

    // TODO
};
}
// ================================================================

namespace fnd
{
class FileBinder;

class FileReader : public ReferencedObject, public csl::fnd::Singleton<FileReader>
{
LWAPI_PRIVATE
    DECLARE_SINGLETON

    // TODO: Are there any data members?

public:
    LWAPI(0x0218fa6c, TODO)
    ~FileReader();

    LWAPI(0x0218fac0, TODO)
    virtual void Update();

    LWAPI(0x0218fac4, TODO)
    virtual csl::fnd::com_ptr<FileHandleObj> GetFileHandle(const char* registName);

    LWAPI(0x0218fad4, TODO)
    virtual bool IsFileExist(const char* filePath, FileBinder* binder);

    LWAPI(0x0218fadc, TODO)
    virtual std::size_t GetFileSize(const char* filePath, FileBinder* binder);

    LWAPI(0x0218fae4, TODO)
    virtual csl::fnd::com_ptr<FileHandleObj> LoadFile(const char* filePath,
        const char* param_2, csl::fnd::IAllocator* allocator,
        void* param_4, unsigned int param_5, FileBinder* binder);

    LWAPI(0x0218faf4, TODO)
    virtual void StopFile(csl::fnd::com_ptr<FileHandleObj> fileHandle);

    LWAPI(0x0218faf8, TODO)
    virtual void StopFileAll();

    LWAPI(0x0218fafc, TODO)
    virtual bool UnloadFile(csl::fnd::com_ptr<FileHandleObj> fileHandle);

    LWAPI(0x0218fb04, TODO)
    virtual bool IsSyncComplete(csl::fnd::com_ptr<FileHandleObj> fileHandle);

    LWAPI(0x0218fb0c, TODO)
    virtual bool IsSyncCompleteAll();

    LWAPI(0x0218fb14, TODO)
    virtual void WaitSync(csl::fnd::com_ptr<FileHandleObj> fileHandle);

    LWAPI(0x0218fb18, TODO)
    virtual void WaitSyncAll();

    LWAPI(0x0218fb1c, TODO)
    virtual bool DbgGet(csl::ut::MoveArray<dbg::FileInfo::Data>& param_1, bool param_2);

    LWAPI(0x0218fb24, TODO)
    virtual csl::fnd::com_ptr<FileHandleObj> CreateHandle(const char* filePath,
        const char* param_2, csl::fnd::IAllocator* allocator,
        void* param_4, unsigned int param_5, fnd::FileBinder* binder);

    LWAPI(0x0218fb34, TODO)
    virtual void AddRequest(const csl::fnd::com_ptr<FileHandleObj>& fileHandle,
        void* param_2, unsigned int param_3);

    LWAPI(0x0218fb38, TODO)
    virtual void AddRequest(const csl::fnd::com_ptr<FileHandleObj>& fileHandle);

    // TODO: Non-virtual member functions
};
}
}
