// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#ifdef USE_CRIWARE
#include "FileSystem.h"
#include "FileBinderCri.h"

namespace app
{
namespace fnd
{
struct FileSystemCri : FileSystem
{
    FileBinderCri* Binder;

    LWAPI(0x021932d8, TODO)
    ~FileSystemCri();

    LWAPI(0x02193394, TODO)
    void Update();

    LWAPI(0x0219338c, TODO)
    FileBinder* GetDefaultBinder() const;

    LWAPI(0x021932a4, TODO)
    static FileSystemCri* Create(csl::fnd::IAllocator* allocator);

    LWAPI(0x0219320c, 0x004940d0)
    FileSystemCri();
};
}
}
#endif
