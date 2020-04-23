#pragma once
#include "FileBinder.h"
#include "csl/ut/MoveArray.h"

#include "cri_file_system.h" // TODO: Replace Criware with legit open-source library!!

namespace csl
{
namespace fnd
{
struct IAllocator;
}
}

namespace app
{
namespace fnd
{
class FileBinderCri : public FileBinder
{
    csl::fnd::IAllocator* allocator;
    CriFsBinderHn binder;
    csl::ut::MoveArray<unsigned int> boundIDs;

public:
    /*
        @brief Constructor for FileBinderCri.
        <b>Wii U: 0x0218ed5c, PC: 0x00492a10</b>
    */
    FileBinderCri(csl::fnd::IAllocator* allocator, std::size_t idCapacity);

    /*
        @brief Destructor for FileBinderCri.
        <b>Wii U: 0x0218ee60, PC: 0x00492d10</b>
    */
    ~FileBinderCri() override;

    /* <b>Wii U: 0x0218eec8, PC: 0x0049f980</b> */
    void* GetBinderHn() const override;

    /* <b>Wii U: 0x0218ef20, PC: 0x00492a70</b> */
    unsigned int BindCpk(const char* filePath, int priority, bool param_3) override;

    /* <b>Wii U: 0x0218f00c, PC: 0x00492b50</b> */
    unsigned int BindDirectory(const char* filePath, int priority, bool param_3) override;

    /* <b>Wii U: 0x0218f0f8, PC: 0x00492c30</b> */
    unsigned int BindFile(const char* filePath, int priority, bool param_3) override;
        
    /* <b>Wii U: 0x0218f1e4, PC: 0x00492730</b> */
    bool IsSyncComplete(unsigned int id) const override;

    /* <b>Wii U: 0x0218f2d0, PC: 0x004928a0</b> */
    bool IsSyncCompleteAll() const override;

    /* <b>Wii U: 0x0218f3f0, PC: 0x00492980</b> */
    void WaitSync(unsigned int id) override;

    /* <b>Wii U: 0x0218f478, PC: 0x004929d0</b> */
    void WaitSyncAll() override;

    /* <b>Wii U: 0x0218f4f0, PC: 0x00492780</b> */
    void SetCurrentDirectory(unsigned int param_1, const char* param_2) override;

    /* <b>Wii U: 0x0218f504, PC: 0x004927a0</b> */
    bool Unbind(unsigned int id) override;

    /* <b>Wii U: 0x0218f538, PC: 0x004927c0</b> */
    bool IsFileExist(const char* filePath) const override;

    /* <b>Wii U: 0x0218f584, PC: 0x00492800</b> */
    std::size_t GetFileSize(const char* filePath) const override;

    /* <b>Wii U: 0x0218f5d8, PC: 0x00492850</b> */
    bool IsBind(unsigned int id) const override;
};
}
}
