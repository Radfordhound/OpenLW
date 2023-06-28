// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include "FileReader.h"
#include <csl/ut/string.h>
#include <csl/ut/string_map.h>

#if OPENLW_USE_CRIWARE == 1
#include <cri_file_system.h> // TODO: Replace Criware with an open-source library!!
#else

#ifndef CriFsLoaderHn
#define CriFsLoaderHn void*
#endif

#ifndef CRIAPI
#define CRIAPI
#endif

#endif

namespace app
{
namespace fnd
{
namespace file
{
/**
 * @brief Criware load end callback function.
 *
 * NOTE: This function appears to be static, but it's been exposed in
 * this header anyway for LWAPI/modding purposes.
*/
LWAPI(0x0218fb4c, TODO)
void CRIAPI CriLoadEndCbFunc(void* obj, CriFsLoaderHn loader);
} // file

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

        LWAPI(0x0218fb3c, TODO)
        static void LoadEndCbFunc(void* obj, CriFsLoaderHn loader);

        LWAPI(0x02190930, TODO)
        void Flush();

        LWAPI(0x0218fb50, TODO)
        Loader();

        LWAPI(0x021903a8, TODO)
        ~Loader();
    };

    struct Request
    {
        csl::fnd::com_ptr<FileHandleObj> field_0x0;
        unsigned int field_0x4;

        LWAPI(0x02192ff8, TODO)
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
    
    LWAPI(0x02190604, TODO)
    ~FileReaderCri();

    LWAPI(0x021909bc, 0x004934a0)
    void Update();

    LWAPI(0x02190f98, 0x004933d0)
    csl::fnd::com_ptr<FileHandleObj> GetFileHandle(const char* registName);

    LWAPI(0x02191074, TODO)
    bool IsFileExist(const char* filePath, FileBinder* binder);

    LWAPI(0x021910cc, TODO)
    std::size_t GetFileSize(const char* filePath, FileBinder* binder);

    LWAPI(0x02191124, TODO)
    csl::fnd::com_ptr<FileHandleObj> LoadFile(const char* filePath,
        const char* param_2, csl::fnd::IAllocator* allocator,
        void* param_4, unsigned int param_5, FileBinder* binder);

    LWAPI(0x0218faf4, TODO)
    void StopFile(csl::fnd::com_ptr<FileHandleObj> fileHandle);

    LWAPI(TODO, TODO)
    void StopFileAll();

    LWAPI(0x02191594, 0x00493fd0)
    bool UnloadFile(csl::fnd::com_ptr<FileHandleObj> fileHandle);

    LWAPI(0x02191678, TODO)
    bool IsSyncComplete(csl::fnd::com_ptr<FileHandleObj> fileHandle);

    LWAPI(0x021916f4, TODO)
    bool IsSyncCompleteAll();

    LWAPI(TODO, TODO)
    void WaitSync(csl::fnd::com_ptr<FileHandleObj> fileHandle);

    LWAPI(TODO, TODO)
    void WaitSyncAll();

    LWAPI(0x02192b40, TODO)
    bool DbgGet(csl::ut::MoveArray<dbg::FileInfo::Data>& param_1, bool param_2);

    LWAPI(0x02192dc4, 0x00493910)
    csl::fnd::com_ptr<FileHandleObj> CreateHandle(const char* filePath,
        const char* param_2, csl::fnd::IAllocator* allocator,
        void* param_4, unsigned int param_5, fnd::FileBinder* binder);

    LWAPI(0x0219309c, TODO)
    void AddRequest(const csl::fnd::com_ptr<FileHandleObj>& fileHandle,
        void* buffer, std::size_t bufSize);

    LWAPI(0x0219316c, TODO)
    void AddRequest(const csl::fnd::com_ptr<FileHandleObj>& fileHandle);

    LWAPI(0x02193070, TODO)
    void AddRequestList(Request* request);

    LWAPI(0x02192b48, TODO)
    void CreateRegistName(const char* filePath, const char* registName,
        csl::ut::String* result);

    LWAPI(0x02192ce8, 0x00493870)
    bool AddFileHnList(const csl::fnd::com_ptr<FileHandleObj>& fileHandle);

    LWAPI(0x021914a4, 0x00493ef0)
    bool RemoveFileHnList(const csl::fnd::com_ptr<FileHandleObj>& fileHandle);

    LWAPI(0x0219076c, TODO)
    Loader* GetFreeLoader();

    LWAPI(0x0218ff90, TODO)
    static FileReaderCri* Create(csl::fnd::IAllocator* allocator,
        std::size_t param_2, std::size_t param_3);

    LWAPI(0x0218fe58, TODO)
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
LWAPI(0x02192bc0, TODO)
FileHandleObj* CreateHandle(csl::fnd::IAllocator* allocator);
} // file
} // fnd
} // app
