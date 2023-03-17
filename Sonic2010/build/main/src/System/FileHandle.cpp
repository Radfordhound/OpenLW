// TODO: The name of this file is correct, but the path was guessed!
#include "FileHandle.h"

namespace app
{
namespace fnd
{
bool FileHandleObj::IsValid() const
{
    return (field_0x1c != 0);
}

void FileHandleObj::Replace(void* buffer, std::size_t fileSize,
    std::size_t bufSize, bool param_4)
{
    if ((field_0x9c & 1) == 0 && Buffer)
    {
        Allocator->Free(Buffer); // TODO: Is this right? It looks like it's also passing in other parameters???
    }

    FileSize = fileSize;
    BufferSize = bufSize;
    Buffer = buffer;

    if (param_4)
    {
        field_0x9c |= 1;
    }

    field_0x9c &= 0xfffffffe;
}

void FileHandleObj::Destroy()
{
    if (IsValid())
    {
        if ((field_0x9c & 1) == 0 && Buffer)
        {
            Allocator->Free(Buffer); // TODO: Is this right?
        }

        Buffer = nullptr;
        BufferSize = 0;
        FileSize = 0;
        field_0x20[0] = '\0';
        field_0x60[0] = '\0';
        Binder = nullptr;
        field_0x1c = 0;
    }
}
}
}
