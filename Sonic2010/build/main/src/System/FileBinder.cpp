#include "OpenLW/pch.h"
#include "FileBinder.h"

namespace app
{
namespace fnd
{
void* FileBinder::GetBinderHn()
{
    return nullptr;
}

unsigned int FileBinder::BindCpk(const char* filePath, int priority, bool isAbsolute)
{
    return 0;
}

unsigned int FileBinder::BindDirectory(const char* filePath, int priority, bool isAbsolute)
{
    return 0;
}

unsigned int FileBinder::BindFile(const char* filePath, int priority, bool isAbsolute)
{
    return 0;
}

bool FileBinder::IsSyncComplete(unsigned int id)
{
    return true;
}

bool FileBinder::IsSyncCompleteAll()
{
    return true;
}

void FileBinder::WaitSync(unsigned int id) {}

void FileBinder::WaitSyncAll() {}

void FileBinder::SetCurrentDirectory(unsigned int param_1, const char* param_2) {}

bool FileBinder::Unbind(unsigned int id)
{
    return true;
}

bool FileBinder::UnbindAll()
{
    return true;
}

bool FileBinder::IsFileExist(const char* filePath)
{
    return false;
}

std::size_t FileBinder::GetFileSize(const char* filePath)
{
    return 0;
}

bool FileBinder::IsBind(unsigned int id) const
{
    return false;
}
}
}
