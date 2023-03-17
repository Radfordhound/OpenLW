// TODO: The name of this file is correct, but the path was guessed!
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
    // Wii U: 0x0218ec40, PC: 0x00492870
	virtual ~FileBinder() {}

    // Wii U: 0x0218ec54, PC: 0x00445190
    virtual void* GetBinderHn();

    // Wii U: 0x0218ec5c, PC: TODO
    virtual unsigned int BindCpk(const char* filePath,
        int priority, bool isAbsolute);

    // Wii U: 0x0218ec64, PC: TODO
    virtual unsigned int BindDirectory(const char* filePath,
        int priority, bool isAbsolute);

    // Wii U: 0x0218ec6c, PC: TODO
    virtual unsigned int BindFile(const char* filePath,
        int priority, bool isAbsolute);
    
    // Wii U: 0x0218ec74, PC: TODO
    virtual bool IsSyncComplete(unsigned int id);

    // Wii U: 0x0218ec7c, PC: TODO
    virtual bool IsSyncCompleteAll();

    // Wii U: 0x0218ec84, PC: TODO
    virtual void WaitSync(unsigned int id);

    // Wii U: 0x0218ec88, PC: TODO
    virtual void WaitSyncAll();

    // Wii U: 0x0218ec8c, PC: TODO
    virtual void SetCurrentDirectory(unsigned int id, const char* path);

    // Wii U: 0x0218ec90, PC: TODO
    virtual bool Unbind(unsigned int id);

    // Wii U: 0x0218ec98, PC: TODO
    virtual bool UnbindAll();

    // Wii U: 0x0218eca0, PC: TODO
    virtual bool IsFileExist(const char* filePath);

    // Wii U: 0x0218eca8, PC: TODO
    virtual std::size_t GetFileSize(const char* filePath);

    // Wii U: 0x0218ecb0, PC: TODO
    virtual bool IsBind(unsigned int id) const;
};
}
}
