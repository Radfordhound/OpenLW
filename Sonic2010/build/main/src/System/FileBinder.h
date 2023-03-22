// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include <cstddef>

namespace app
{
namespace fnd
{
class FileBinder
{
OPENLW_PRIVATE
    // TODO: Data Members

public:
    LWAPI(0x0218ec40, 0x00492870)
	virtual ~FileBinder() {}

    LWAPI(0x0218ec54, 0x00445190)
    virtual void* GetBinderHn();

    LWAPI(0x0218ec5c, TODO)
    virtual unsigned int BindCpk(const char* filePath,
        int priority, bool isAbsolute);

    LWAPI(0x0218ec64, TODO)
    virtual unsigned int BindDirectory(const char* filePath,
        int priority, bool isAbsolute);

    LWAPI(0x0218ec6c, TODO)
    virtual unsigned int BindFile(const char* filePath,
        int priority, bool isAbsolute);
    
    LWAPI(0x0218ec74, TODO)
    virtual bool IsSyncComplete(unsigned int id);

    LWAPI(0x0218ec7c, TODO)
    virtual bool IsSyncCompleteAll();

    LWAPI(0x0218ec84, TODO)
    virtual void WaitSync(unsigned int id);

    LWAPI(0x0218ec88, TODO)
    virtual void WaitSyncAll();

    LWAPI(0x0218ec8c, TODO)
    virtual void SetCurrentDirectory(unsigned int id, const char* path);

    LWAPI(0x0218ec90, TODO)
    virtual bool Unbind(unsigned int id);

    LWAPI(0x0218ec98, TODO)
    virtual bool UnbindAll();

    LWAPI(0x0218eca0, TODO)
    virtual bool IsFileExist(const char* filePath);

    LWAPI(0x0218eca8, TODO)
    virtual std::size_t GetFileSize(const char* filePath);

    LWAPI(0x0218ecb0, TODO)
    virtual bool IsBind(unsigned int id) const;
};
}
}
