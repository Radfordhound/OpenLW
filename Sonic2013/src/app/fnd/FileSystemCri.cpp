#include "FileSystemCri.h"
#include <new>

namespace app
{
namespace fnd
{
FileSystemCri::FileSystemCri()
{
    // Allocate FileBinderCri
    Binder = static_cast<FileBinderCri*>(allocator->Alloc(sizeof(FileBinderCri)));
    if (Binder)
    {
        new (Binder) FileBinderCri(allocator, 0x10);
    }

    // TODO
}

FileSystemCri::~FileSystemCri()
{
    // TODO
}

void FileSystemCri::Update()
{
    // TODO
}

FileBinder* FileSystemCri::GetDefaultBinder() const
{
    return Binder;
}
}
}
