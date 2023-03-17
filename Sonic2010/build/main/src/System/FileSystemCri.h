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

    // Wii U: 0x021932d8, PC: TODO
    ~FileSystemCri();

    // Wii U: 0x02193394, PC: TODO
    void Update();

    // Wii U: 0x0219338c, PC: TODO
    FileBinder* GetDefaultBinder() const;

    // Wii U: 0x021932a4, PC: TODO
    static FileSystemCri* Create(csl::fnd::IAllocator* allocator);

    // Wii U: 0x0219320c, PC: 0x004940d0
    FileSystemCri();
};
}
}
#endif
