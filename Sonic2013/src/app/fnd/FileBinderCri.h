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
        <b>Wii U: TODO, PC: TODO</b>
    */
    FileBinderCri(csl::fnd::IAllocator* allocator, std::size_t idCapacity);

    /*
        @brief Destructor for FileBinderCri.
        <b>Wii U: TODO, PC: TODO</b>
    */
    ~FileBinderCri() override;

    /* <b>Wii U: TODO, PC: TODO</b> */
    void* GetBinderHn() const override;

    /* <b>Wii U: TODO, PC: TODO</b> */
    unsigned int BindCpk(const char* filePath, int priority, bool param_3) override;

    /* <b>Wii U: TODO, PC: TODO</b> */
    unsigned int BindDirectory(const char* filePath, int priority, bool param_3) override;

    /* <b>Wii U: TODO, PC: TODO</b> */
    unsigned int BindFile(const char* filePath, int priority, bool param_3) override;
        
    /* <b>Wii U: TODO, PC: TODO</b> */
    bool IsSyncComplete(unsigned int id) const override;

    /* <b>Wii U: TODO, PC: TODO</b> */
    bool IsSyncCompleteAll() const override;

    /* <b>Wii U: TODO, PC: TODO</b> */
    void WaitSync(unsigned int id) override;

    /* <b>Wii U: TODO, PC: TODO</b> */
    void WaitSyncAll() override;

    /* <b>Wii U: TODO, PC: TODO</b> */
    void SetCurrentDirectory(unsigned int param_1, const char* param_2) override;

    /* <b>Wii U: TODO, PC: TODO</b> */
    bool Unbind(unsigned int id) override;

    /* <b>Wii U: TODO, PC: TODO</b> */
    bool IsFileExist(const char* filePath) const override;

    /* <b>Wii U: TODO, PC: TODO</b> */
    std::size_t GetFileSize(const char* filePath) const override;

    /* <b>Wii U: TODO, PC: TODO</b> */
    bool IsBind(unsigned int id) const override;
};
}
}
