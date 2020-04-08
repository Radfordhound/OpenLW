#pragma once
#include <cstddef>

namespace app
{
namespace fnd
{
class FileBinder
{
    // TODO: Data Members

public:
    /*
        @brief Destructor for FileBinder.
        <b>Wii U: TODO, PC: 0x00492870</b>
    */
    virtual inline ~FileBinder() = default;

    /* <b>Wii U: TODO, PC: 0x00445190</b> */
    virtual void* GetBinderHn() const;

    /* <b>Wii U: TODO, PC: TODO</b> */
    virtual unsigned int BindCpk(const char* filePath, int priority, bool param_3);

    /* <b>Wii U: TODO, PC: TODO</b> */
    virtual unsigned int BindDirectory(const char* filePath, int priority, bool param_3);

    /* <b>Wii U: TODO, PC: TODO</b> */
    virtual unsigned int BindFile(const char* filePath, int priority, bool param_3);
    
    /* <b>Wii U: TODO, PC: TODO</b> */
    virtual bool IsSyncComplete(unsigned int id) const;

    /* <b>Wii U: TODO, PC: TODO</b> */
    virtual bool IsSyncCompleteAll() const;

    /* <b>Wii U: TODO, PC: TODO</b> */
    virtual void WaitSync(unsigned int id);

    /* <b>Wii U: TODO, PC: TODO</b> */
    virtual void WaitSyncAll();

    /* <b>Wii U: TODO, PC: TODO</b> */
    virtual void SetCurrentDirectory(unsigned int param_1, const char* param_2);

    /* <b>Wii U: TODO, PC: TODO</b> */
    virtual bool Unbind(unsigned int id);

    /* <b>Wii U: TODO, PC: TODO</b> */
    virtual bool UnbindAll();

    /* <b>Wii U: TODO, PC: TODO</b> */
    virtual bool IsFileExist(const char* filePath) const;

    /* <b>Wii U: TODO, PC: TODO</b> */
    virtual std::size_t GetFileSize(const char* filePath) const;

    /* <b>Wii U: TODO, PC: TODO</b> */
    virtual bool IsBind(unsigned int id) const;
};
}
}
