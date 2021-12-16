#pragma once
#include "File.h"
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

    // Wii U: 0x0218b83c, PC: TODO
    FileLoaderParam();

    // Wii U: 0x0218b890, PC: TODO
    void SetMultiLanguageAttr(bool param_1, unsigned int param_2);
};

class FileLoader : public ReferencedObject, public csl::fnd::Singleton<FileLoader> // size == 104
{
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

        // Wii U: 0x0218cd78, PC: TODO
        LoadInfo();
    };

    struct LoadBuffer // TODO: Extend from StackHeapBase, maybe more classes as well?
    {
        // TODO: Other data members
        int field_0x68;
        unsigned int RefCount;
        bool field_0x70;

        // Wii U: 0x0218cfdc, PC: TODO
        void AddRef();

        // Wii U: 0x0218cfb4, PC: TODO
        void Reset();

        // Wii U: 0x0218bbf8, PC: TODO
        LoadBuffer(std::size_t param_1, csl::fnd::IAllocator* allocator,
            unsigned int param_3);
    };

private:
    csl::fnd::IAllocator* field_0xc;
    csl::ut::MoveArray<LoadInfo*> field_0x10;
    csl::ut::MoveArray<LoadInfo*> field_0x20;
    csl::ut::MoveArray<LoadInfo*> field_0x30;
    LoadBuffer* field_0x40;
    std::size_t field_0x44;
    bool m_isSyncCompleteAll;
    // TODO: Other data members

    // Wii U: 0x0218be60, PC: TODO
    LoadBuffer* GetLoadBuffer(std::size_t index);

public:
    // Wii U: 0x0218c160, PC: TODO
    ~FileLoader();

    // Wii U: 0x0218c338, PC: TODO
    void GetMultiLangResourceName(const char* name, csl::ut::String* result);

    // Wii U: 0x0218c658, PC: 0x00491140
    void ResourceJobMTExec(LoadInfo* loadInfo);

    // Wii U: 0x0218c898, PC: TODO
    static void ResourceJobMT(void* data);

    // Wii U: 0x0218c8a4, PC: 0x004916b0
    bool ResourceJobMTStart(LoadInfo* loadInfo);

    // Wii U: 0x0218d14c, PC: TODO
    void ResourceJobExec();

    // Wii U: 0x0218cff8, PC: TODO
    void LoadBufferRequestJobExec();

    // Wii U: 0x0218d490, PC: TODO
    void LoadBufferReset();
    
    // Wii U: 0x0218d4f4, PC: 0x00491cc0
    void Update();

    // Wii U: 0x0218ddbc, PC: TODO
    bool CheckInfoListInHandle(csl::fnd::com_ptr<FileHandleObj> fileHandle);

    // Wii U: 0x0218deec, PC: TODO
    bool IsSyncComplete(csl::fnd::com_ptr<FileHandleObj> fileHandle);

    // Wii U: 0x0218e060, PC: TODO
    bool IsSyncCompleteAll();

    // Wii U: 0x0218e12c, PC: TODO
    void WaitSync(csl::fnd::com_ptr<FileHandleObj> fileHandle);

    // Wii U: 0x0218dd74, PC: TODO
    bool SetHintCache(const char* param_1);

    // Wii U: 0x0218d970, PC: TODO
    bool PreLoadFile(const char* filePath, int param_2);

    // Wii U: 0x0218cdfc, PC: TODO
    csl::fnd::com_ptr<FileHandleObj> LoadFileOne(const char* filePath,
        const char* param_2, unsigned int param_3,
        const FileLoaderParam& params);

    // Wii U: 0x0218d758, PC: TODO
    csl::fnd::com_ptr<FileHandleObj> LoadFile(const char* filePath,
        const char* param_2, const FileLoaderParam& params);

    // Wii U: 0x0218d864, PC: TODO
    csl::fnd::com_ptr<FileHandleObj> LoadFile(const char* filePath,
        const FileLoaderParam& params);

    // TODO

    // Wii U: 0x0218bcc0, PC: TODO
    void SetupEx(unsigned int param_1, std::size_t param_2);

    // Wii U: 0x0218bd98, PC: TODO
    FileLoader();
};
}
}
