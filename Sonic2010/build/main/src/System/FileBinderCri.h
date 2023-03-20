// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#ifdef USE_CRIWARE
#include "FileBinder.h"
#include <csl/ut/array.h>
#include <cri_file_system.h> // TODO: Replace Criware with an open-source library!!

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
LWAPI_PRIVATE
    csl::fnd::IAllocator* allocator;
    CriFsBinderHn binder;
    csl::ut::MoveArray<unsigned int> boundIDs;

public:
    LWAPI(0x0218ee60, 0x00492d10)
    ~FileBinderCri();

    LWAPI(0x0218eec8, 0x0049f980)
    void* GetBinderHn();

    LWAPI(0x0218ef20, 0x00492a70)
    unsigned int BindCpk(const char* filePath, int priority, bool isAbsolute);

    LWAPI(0x0218f00c, 0x00492b50)
    unsigned int BindDirectory(const char* filePath, int priority, bool isAbsolute);

    LWAPI(0x0218f0f8, 0x00492c30)
    unsigned int BindFile(const char* filePath, int priority, bool isAbsolute);
        
    LWAPI(0x0218f1e4, 0x00492730)
    bool IsSyncComplete(unsigned int id);

    LWAPI(0x0218f2d0, 0x004928a0)
    bool IsSyncCompleteAll();

    LWAPI(0x0218f3f0, 0x00492980)
    void WaitSync(unsigned int id);

    LWAPI(0x0218f478, 0x004929d0)
    void WaitSyncAll();

    LWAPI(0x0218f4f0, 0x00492780)
    void SetCurrentDirectory(unsigned int id, const char* path);

    LWAPI(0x0218f504, 0x004927a0)
    bool Unbind(unsigned int id);

    LWAPI(0x0218f538, 0x004927c0)
    bool IsFileExist(const char* filePath);

    LWAPI(0x0218f584, 0x00492800)
    std::size_t GetFileSize(const char* filePath);

    LWAPI(0x0218f5d8, 0x00492850)
    bool IsBind(unsigned int id) const;

    LWAPI(0x0218ed5c, 0x00492a10)
    FileBinderCri(csl::fnd::IAllocator* allocator, std::size_t maxBoundIds);
};

namespace file
{
/**
 * @brief Converts backslashes in the given path to forward slashes.
 *
 * NOTE: This function appears to be static, but it's been exposed in
 * this header anyway for LWAPI/modding purposes.
 *
 * @param[in] path     The path to convert.
*/
LWAPI(0x0218eed0, TODO)
void ConvertPath(char* path);
}
}
}
#endif
