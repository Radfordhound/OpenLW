#include "FileBinder.h"

namespace app
{
namespace fnd
{
void* FileBinder::GetBinderHn() const
{
    return nullptr;
}

unsigned int FileBinder::BindCpk(const char* filePath, int priority, bool param_3)
{
    return 0;
}

unsigned int FileBinder::BindDirectory(const char* filePath, int priority, bool param_3)
{
    return 0;
}

unsigned int FileBinder::BindFile(const char* filePath, int priority, bool param_3)
{
    return 0;
}

bool FileBinder::IsSyncComplete(unsigned int id) const
{
    return true;
}

bool FileBinder::IsSyncCompleteAll() const
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

bool FileBinder::IsFileExist(const char* filePath) const
{
    return false;
}

std::size_t FileBinder::GetFileSize(const char* filePath) const
{
    return 0;
}

bool FileBinder::IsBind(unsigned int id) const
{
    return false;
}
}
}
