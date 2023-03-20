// TODO: The name of this file is correct, but the path was guessed!
#include "pch.h"
#ifdef USE_CRIWARE
#include "FileSystemCri.h"
#include "FileReaderCri.h"
#include <new>

namespace app
{
namespace fnd
{
FileSystemCri::~FileSystemCri()
{
    FileReader::ReplaceInstance(nullptr);

    if (Binder)
    {
        Binder->~FileBinderCri();
        m_allocator->Free(Binder);
        Binder = nullptr;
    }
}

void FileSystemCri::Update()
{
    FileReader::GetInstance().Update();
}

FileBinder* FileSystemCri::GetDefaultBinder() const
{
    return Binder;
}

FileSystemCri* FileSystemCri::Create(csl::fnd::IAllocator* allocator)
{
    return new (allocator) FileSystemCri();
}

FileSystemCri::FileSystemCri() :
    Binder(nullptr)
{
    // Allocate FileBinderCri.
    Binder = static_cast<FileBinderCri*>(m_allocator->Alloc(sizeof(FileBinderCri)));
    if (Binder)
    {
        new (Binder) FileBinderCri(m_allocator, 0x10);
    }

    // Create FileReaderCri and use it as the FileReader from now on.
    FileReader::ReplaceInstance(FileReaderCri::Create(m_allocator, 8, 256));
}
}
}
#endif
