// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include "FileHandle.h"
#include "ReferencedObject.h"
#include "Singleton.h"
#include <csl/ut/array.h>
#include <csl/ut/string.h>

namespace app
{
namespace fnd
{
class FileBinder;

struct FileLoaderParam // size == 24
{
    unsigned int field_0x0;
    void* field_0x4;
    unsigned int field_0x8;
    unsigned int field_0xc;
    FileBinder* field_0x10;
    unsigned int field_0x14;

    LWAPI(0x0218b83c, TODO)
    FileLoaderParam();

    LWAPI(0x0218b890, TODO)
    void SetMultiLanguageAttr(bool param_1, unsigned int param_2);
};

class FileLoader : public ReferencedObject, public csl::fnd::Singleton<FileLoader> // size == 104
{
LWAPI_PRIVATE
    DECLARE_SINGLETON

public:
    struct LoadInfo // size == 0x24
    {
        csl::fnd::IAllocator* field_0x0;
        csl::fnd::com_ptr<FileHandleObj> field_0x4;
        int field_0x8;
        unsigned int field_0xc;
        int field_0x10;
        unsigned int field_0x14;
        unsigned int field_0x18;
        unsigned int field_0x1c;
        unsigned int field_0x20;

        LWAPI(0x0218cd78, TODO)
        LoadInfo();
    };

    struct LoadBuffer // TODO: Extend from StackHeapBase, maybe more classes as well?
    {
        // TODO: Other data members
        int field_0x68;
        unsigned int RefCount;
        bool field_0x70;

        LWAPI(0x0218cfdc, TODO)
        void AddRef();

        LWAPI(0x0218cfb4, TODO)
        void Reset();

        LWAPI(0x0218bbf8, TODO)
        LoadBuffer(std::size_t param_1, csl::fnd::IAllocator* allocator,
            unsigned int param_3);
    };

LWAPI_PRIVATE
    csl::fnd::IAllocator* field_0xc;
    csl::ut::MoveArray<LoadInfo*> field_0x10;
    csl::ut::MoveArray<LoadInfo*> field_0x20;
    csl::ut::MoveArray<LoadInfo*> field_0x30;
    LoadBuffer* field_0x40;
    std::size_t field_0x44;
    bool m_isSyncCompleteAll;
    // TODO: Other data members

    LWAPI(0x0218be60, TODO)
    LoadBuffer* GetLoadBuffer(std::size_t index);

public:
    LWAPI(0x0218c160, TODO)
    ~FileLoader();

    LWAPI(0x0218c338, TODO)
    void GetMultiLangResourceName(const char* name, csl::ut::String* result);

    LWAPI(0x0218c658, 0x00491140)
    void ResourceJobMTExec(LoadInfo* loadInfo);

    LWAPI(0x0218c898, TODO)
    static void ResourceJobMT(void* data);

    LWAPI(0x0218c8a4, 0x004916b0)
    bool ResourceJobMTStart(LoadInfo* loadInfo);

    LWAPI(0x0218d14c, TODO)
    void ResourceJobExec();

    LWAPI(0x0218cff8, TODO)
    void LoadBufferRequestJobExec();

    LWAPI(0x0218d490, TODO)
    void LoadBufferReset();
    
    LWAPI(0x0218d4f4, 0x00491cc0)
    void Update();

    LWAPI(0x0218ddbc, TODO)
    bool CheckInfoListInHandle(csl::fnd::com_ptr<FileHandleObj> fileHandle);

    LWAPI(0x0218deec, TODO)
    bool IsSyncComplete(csl::fnd::com_ptr<FileHandleObj> fileHandle);

    LWAPI(0x0218e060, TODO)
    bool IsSyncCompleteAll();

    LWAPI(0x0218e12c, TODO)
    void WaitSync(csl::fnd::com_ptr<FileHandleObj> fileHandle);

    LWAPI(0x0218dd74, TODO)
    bool SetHintCache(const char* param_1);

    LWAPI(0x0218d970, TODO)
    bool PreLoadFile(const char* filePath, int param_2);

    LWAPI(0x0218cdfc, TODO)
    csl::fnd::com_ptr<FileHandleObj> LoadFileOne(const char* filePath,
        const char* param_2, unsigned int param_3,
        const FileLoaderParam& params);

    LWAPI(0x0218d758, TODO)
    csl::fnd::com_ptr<FileHandleObj> LoadFile(const char* filePath,
        const char* param_2, const FileLoaderParam& params);

    LWAPI(0x0218d864, TODO)
    csl::fnd::com_ptr<FileHandleObj> LoadFile(const char* filePath,
        const FileLoaderParam& params);

    // TODO

    LWAPI(0x0218bcc0, TODO)
    void SetupEx(unsigned int param_1, std::size_t param_2);

    LWAPI(0x0218bd98, TODO)
    FileLoader();
};
}
}
