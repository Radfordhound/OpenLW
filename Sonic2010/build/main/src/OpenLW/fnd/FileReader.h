#pragma once
#include "File.h"
#include "Singleton.h"
#include "csl/ut/array.h"

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
    DECLARE_SINGLETON

    // TODO: Are there any data members?

public:
    // Wii U: 0x0218fa6c, PC: TODO
    ~FileReader();

    // Wii U: 0x0218fac0, PC: TODO
    virtual void Update();

    // Wii U: 0x0218fac4, PC: TODO
    virtual csl::fnd::com_ptr<FileHandleObj> GetFileHandle(const char* registName);

    // Wii U: 0x0218fad4, PC: TODO
    virtual bool IsFileExist(const char* filePath, FileBinder* binder);

    // Wii U: 0x0218fadc, PC: TODO
    virtual std::size_t GetFileSize(const char* filePath, FileBinder* binder);

    // Wii U: 0x0218fae4, PC: TODO
    virtual csl::fnd::com_ptr<FileHandleObj> LoadFile(const char* filePath,
        const char* param_2, csl::fnd::IAllocator* allocator,
        void* param_4, unsigned int param_5, FileBinder* binder);

    // Wii U: 0x0218faf4, PC: TODO
    virtual void StopFile(csl::fnd::com_ptr<FileHandleObj> fileHandle);

    // Wii U: 0x0218faf8, PC: TODO
    virtual void StopFileAll();

    // Wii U: 0x0218fafc, PC: TODO
    virtual bool UnloadFile(csl::fnd::com_ptr<FileHandleObj> fileHandle);

    // Wii U: 0x0218fb04, PC: TODO
    virtual bool IsSyncComplete(csl::fnd::com_ptr<FileHandleObj> fileHandle);

    // Wii U: 0x0218fb0c, PC: TODO
    virtual bool IsSyncCompleteAll();

    // Wii U: 0x0218fb14, PC: TODO
    virtual void WaitSync(csl::fnd::com_ptr<FileHandleObj> fileHandle);

    // Wii U: 0x0218fb18, PC: TODO
    virtual void WaitSyncAll();

    // Wii U: 0x0218fb1c, PC: TODO
    virtual bool DbgGet(csl::ut::MoveArray<dbg::FileInfo::Data>& param_1, bool param_2);

    // Wii U: 0x0218fb24, PC: TODO
    virtual csl::fnd::com_ptr<FileHandleObj> CreateHandle(const char* filePath,
        const char* param_2, csl::fnd::IAllocator* allocator,
        void* param_4, unsigned int param_5, fnd::FileBinder* binder);

    // Wii U: 0x0218fb34, PC: TODO
    virtual void AddRequest(const csl::fnd::com_ptr<FileHandleObj>& fileHandle,
        void* param_2, unsigned int param_3);

    // Wii U: 0x0218fb38, PC: TODO
    virtual void AddRequest(const csl::fnd::com_ptr<FileHandleObj>& fileHandle);

    // TODO: Non-virtual member functions
};
}
}
