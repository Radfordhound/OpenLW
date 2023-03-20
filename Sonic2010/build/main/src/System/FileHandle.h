// TODO: The name of this file is correct, but the path was guessed!
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

    LWAPI(0x0218b6a4, TODO)
    bool IsValid() const;

    LWAPI(0x0218b6b4, TODO)
    void Replace(void* buffer, std::size_t fileSize,
        std::size_t bufSize, bool param_4);

    LWAPI(0x0218b754, 0x004901e0)
    void Destroy();
};
}
}
