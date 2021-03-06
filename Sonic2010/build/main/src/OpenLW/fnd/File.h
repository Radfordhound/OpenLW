#pragma once
#include "ReferencedObject.h"

namespace app
{
namespace fnd
{
class FileBinder;

struct FileHandleObj : public ThreadSafeReferencedObject // size == 0xa0
{
    void* Buffer;
    std::size_t BufferSize;
    std::size_t FileSize;
    unsigned int field_0x1c;
    char field_0x20[64];
    char field_0x60[48];
    FileBinder* Binder;
    void* field_0x94;
    csl::fnd::IAllocator* Allocator;
    unsigned int field_0x9c;

    // Wii U: 0x0218b6a4, PC: TODO
    bool IsValid() const;

    // Wii U: 0x0218b6b4, PC: TODO
    void Replace(void* buffer, std::size_t fileSize,
        std::size_t bufSize, bool param_4);

    // Wii U: 0x0218b754, PC: 0x004901e0
    void Destroy();
};

namespace file
{
// Wii U: 0x02192bc0, PC: TODO
FileHandleObj* CreateHandle(csl::fnd::IAllocator* allocator);

/*
    @brief Converts backslashes in the given path to forward slashes.
    @param[in] path     The path to convert.
    
    Wii U: 0x0218eed0, PC: TODO
*/
void ConvertPath(char* path);
}
}
}
