// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#ifdef USE_CRIWARE
#include "FileReader.h"
#include <csl/ut/string.h>
#include <csl/ut/string_map.h>
#include <cri_file_system.h> // TODO: Replace Criware with an open-source library!!

namespace app
{
namespace fnd
{
class FileReaderCri : public FileReader
{
public:
    struct Loader // size == 0x18
    {
        CriFsLoaderHn Handle;
        csl::fnd::com_ptr<FileHandleObj> field_0x4;
        unsigned int field_0x8;
        // TODO: Other data members
        unsigned int field_0x10;
        unsigned int field_0x14;

        // Wii U: 0x0218fb3c, PC: TODO
        static void LoadEndCbFunc(void* obj, CriFsLoaderHn loader);

        // Wii U: 0x02190930, PC: TODO
        void Flush();

        // Wii U: 0x0218fb50, PC: TODO
        Loader();

        // Wii U: 0x021903a8, PC: TODO
        ~Loader();
    };

    struct Request
    {
        csl::fnd::com_ptr<FileHandleObj> field_0x0;
        unsigned int field_0x4;

        // Wii U: 0x02192ff8, PC: TODO
        Request();
    };

    csl::ut::ObjectMoveArray<csl::fnd::com_ptr<FileHandleObj>> field_0xc;
    csl::ut::StringMap<FileHandleObj*> field_0x1c;
    csl::ut::MoveArray<Loader*> field_0x34;
    csl::ut::MoveArray<Loader*> field_0x44;
    std::size_t field_0x54;
    csl::ut::MoveArray<Request*> field_0x58;
    Loader* field_0x68;
    // TODO
    
    // Wii U: 0x02190604, PC: TODO
    ~FileReaderCri();

    // Wii U: 0x021909bc, PC: 0x004934a0
    void Update();

    // Wii U: 0x02190f98, PC: 0x004933d0
    csl::fnd::com_ptr<FileHandleObj> GetFileHandle(const char* registName);

    // Wii U: 0x02191074, PC: TODO
    bool IsFileExist(const char* filePath, FileBinder* binder);

    // Wii U: 0x021910cc, PC: TODO
    std::size_t GetFileSize(const char* filePath, FileBinder* binder);

    // Wii U: 0x02191124, PC: TODO
    csl::fnd::com_ptr<FileHandleObj> LoadFile(const char* filePath,
        const char* param_2, csl::fnd::IAllocator* allocator,
        void* param_4, unsigned int param_5, FileBinder* binder);

    // Wii U: 0x0218faf4, PC: TODO
    void StopFile(csl::fnd::com_ptr<FileHandleObj> fileHandle);

    // Wii U: TODO, PC: TODO
    void StopFileAll();

    // Wii U: 0x02191594, PC: 0x00493fd0
    bool UnloadFile(csl::fnd::com_ptr<FileHandleObj> fileHandle);

    // Wii U: 0x02191678, PC: TODO
    bool IsSyncComplete(csl::fnd::com_ptr<FileHandleObj> fileHandle);

    // Wii U: 0x021916f4, PC: TODO
    bool IsSyncCompleteAll();

    // Wii U: TODO, PC: TODO
    void WaitSync(csl::fnd::com_ptr<FileHandleObj> fileHandle);

    // Wii U: TODO, PC: TODO
    void WaitSyncAll();

    // Wii U: 0x02192b40, PC: TODO
    bool DbgGet(csl::ut::MoveArray<dbg::FileInfo::Data>& param_1, bool param_2);

    // Wii U: 0x02192dc4, PC: 0x00493910
    csl::fnd::com_ptr<FileHandleObj> CreateHandle(const char* filePath,
        const char* param_2, csl::fnd::IAllocator* allocator,
        void* param_4, unsigned int param_5, fnd::FileBinder* binder);

    // Wii U: 0x0219309c, PC: TODO
    void AddRequest(const csl::fnd::com_ptr<FileHandleObj>& fileHandle,
        void* buffer, std::size_t bufSize);

    // Wii U: 0x0219316c, PC: TODO
    void AddRequest(const csl::fnd::com_ptr<FileHandleObj>& fileHandle);

    // Wii U: 0x02193070, PC: TODO
    void AddRequestList(Request* request);

    // Wii U: 0x02192b48, PC: TODO
    void CreateRegistName(const char* filePath, const char* registName,
        csl::ut::String* result);

    // Wii U: 0x02192ce8, PC: 0x00493870
    bool AddFileHnList(const csl::fnd::com_ptr<FileHandleObj>& fileHandle);

    // Wii U: 0x021914a4, PC: 0x00493ef0
    bool RemoveFileHnList(const csl::fnd::com_ptr<FileHandleObj>& fileHandle);

    // Wii U: 0x0219076c, PC: TODO
    Loader* GetFreeLoader();

    // Wii U: 0x0218ff90, PC: TODO
    static FileReaderCri* Create(csl::fnd::IAllocator* allocator,
        std::size_t param_2, std::size_t param_3);

    // Wii U: 0x0218fe58, PC: TODO
    FileReaderCri(std::size_t param_1, std::size_t param_2);
};

namespace file
{
/**
 * @brief Creates a FileHandle.
 *
 * NOTE: This function appears to be static, but it's been exposed in
 * this header anyway for LWAPI/modding purposes.
 *
 * @param[in] allocator The allocator to use to create the object.
*/
// Wii U: 0x02192bc0, PC: TODO
FileHandleObj* CreateHandle(csl::fnd::IAllocator* allocator);
}
}
}
#endif
