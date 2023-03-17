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
    csl::fnd::IAllocator* allocator;
    CriFsBinderHn binder;
    csl::ut::MoveArray<unsigned int> boundIDs;

public:
    // Wii U: 0x0218ee60, PC: 0x00492d10
    ~FileBinderCri();

    // Wii U: 0x0218eec8, PC: 0x0049f980
    void* GetBinderHn();

    // Wii U: 0x0218ef20, PC: 0x00492a70
    unsigned int BindCpk(const char* filePath, int priority, bool isAbsolute);

    // Wii U: 0x0218f00c, PC: 0x00492b50
    unsigned int BindDirectory(const char* filePath, int priority, bool isAbsolute);

    // Wii U: 0x0218f0f8, PC: 0x00492c30
    unsigned int BindFile(const char* filePath, int priority, bool isAbsolute);
        
    // Wii U: 0x0218f1e4, PC: 0x00492730
    bool IsSyncComplete(unsigned int id);

    // Wii U: 0x0218f2d0, PC: 0x004928a0
    bool IsSyncCompleteAll();

    // Wii U: 0x0218f3f0, PC: 0x00492980
    void WaitSync(unsigned int id);

    // Wii U: 0x0218f478, PC: 0x004929d0
    void WaitSyncAll();

    // Wii U: 0x0218f4f0, PC: 0x00492780
    void SetCurrentDirectory(unsigned int id, const char* path);

    // Wii U: 0x0218f504, PC: 0x004927a0
    bool Unbind(unsigned int id);

    // Wii U: 0x0218f538, PC: 0x004927c0
    bool IsFileExist(const char* filePath);

    // Wii U: 0x0218f584, PC: 0x00492800
    std::size_t GetFileSize(const char* filePath);

    // Wii U: 0x0218f5d8, PC: 0x00492850
    bool IsBind(unsigned int id) const;

    // Wii U: 0x0218ed5c, PC: 0x00492a10
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
// Wii U: 0x0218eed0, PC: TODO
void ConvertPath(char* path);
}
}
}
#endif
