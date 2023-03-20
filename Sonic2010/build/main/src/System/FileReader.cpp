// TODO: The name of this file is correct, but the path was guessed!
#include "pch.h"
#include "FileReader.h"

namespace app
{
namespace fnd
{
FileReader::~FileReader() {}

void FileReader::Update() {}

csl::fnd::com_ptr<FileHandleObj> FileReader::GetFileHandle(const char* registName)
{
    return nullptr;
}

bool FileReader::IsFileExist(const char* filePath, FileBinder* binder)
{
    return false;
}

std::size_t FileReader::GetFileSize(const char* filePath, FileBinder* binder)
{
    return 0;
}

csl::fnd::com_ptr<FileHandleObj> FileReader::LoadFile(const char* filePath,
    const char* param_2, csl::fnd::IAllocator* allocator,
    void* param_4, unsigned int param_5, FileBinder* binder)
{
    return nullptr;
}

void FileReader::StopFile(csl::fnd::com_ptr<FileHandleObj> fileHandle) {}

void FileReader::StopFileAll() {}

bool FileReader::UnloadFile(csl::fnd::com_ptr<FileHandleObj> fileHandle)
{
    return false;
}

bool FileReader::IsSyncComplete(csl::fnd::com_ptr<FileHandleObj> fileHandle)
{
    return true;
}

bool FileReader::IsSyncCompleteAll()
{
    return true;
}

void FileReader::WaitSync(csl::fnd::com_ptr<FileHandleObj> fileHandle) {}

void FileReader::WaitSyncAll() {}

bool FileReader::DbgGet(csl::ut::MoveArray<dbg::FileInfo::Data>& param_1, bool param_2)
{
    return false;
}

csl::fnd::com_ptr<FileHandleObj> FileReader::CreateHandle(const char* filePath,
    const char* param_2, csl::fnd::IAllocator* allocator,
    void* param_4, unsigned int param_5, fnd::FileBinder* binder)
{
    return nullptr;
}

void FileReader::AddRequest(const csl::fnd::com_ptr<FileHandleObj>& fileHandle,
    void* param_2, unsigned int param_3) {}

void FileReader::AddRequest(const csl::fnd::com_ptr<FileHandleObj>& fileHandle) {}
}
}
