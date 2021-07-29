#ifdef USE_CRIWARE
#include "FileBinderCri.h"
#include "FileSystem.h"
#include "File.h"
#include "csl/fnd/thread.h"
#include "cri_framework.h" // TODO: Replace Criware with an open-source library!!
#include <cstring>
#include <cstdio> // TODO: REMOVE ME

using namespace app::fnd::file;
using namespace csl::fnd;

namespace app
{
namespace fnd
{
// TODO: REMOVE THIS FUNCTION; IT'S NOT IN THE ACTUAL GAME!!!
void user_error_callback_func(const CriChar8* errid, CriUint32 p1, CriUint32 p2, CriUint32* parray)
{
    const CriChar8* errmsg;
    errmsg = criErr_ConvertIdToMessage(errid, p1, p2);
    std::printf("%s\n", errmsg);
}

FileBinderCri::~FileBinderCri()
{
    criFsBinder_Destroy(binder);
}

void* FileBinderCri::GetBinderHn()
{
    return binder;
}

unsigned int FileBinderCri::BindCpk(const char* filePath, int priority, bool isAbsolute)
{
    CriFsBinderId bindID;
    char buf[256];
    FileSystem& fileSystem = FileSystem::GetInstance();

    if (!isAbsolute)
    {
        std::strcpy(buf, fileSystem.RootDirectory);
        std::strcat(buf, filePath);
    }
    else
    {
        std::strcpy(buf, filePath);
    }

    ConvertPath(buf);
    criFsBinder_BindCpk(binder, nullptr, buf, nullptr, 0, &bindID);

    if (bindID)
    {
        criFsBinder_SetPriority(bindID, priority);
        boundIDs.push_back_unchecked(static_cast<unsigned int>(bindID));
    }

    return static_cast<unsigned int>(bindID);
}

unsigned int FileBinderCri::BindDirectory(const char* filePath, int priority, bool isAbsolute)
{
    CriFsBinderId bindID;
    char buf[256];
    FileSystem& fileSystem = FileSystem::GetInstance();

    if (!isAbsolute)
    {
        std::strcpy(buf, fileSystem.RootDirectory);
        std::strcat(buf, filePath);
    }
    else
    {
        std::strcpy(buf, filePath);
    }

    ConvertPath(buf);
    criFsBinder_BindDirectory(binder, nullptr, buf, nullptr, 0, &bindID);

    if (bindID)
    {
        criFsBinder_SetPriority(bindID, priority);
        boundIDs.push_back_unchecked(static_cast<unsigned int>(bindID));
    }

    return static_cast<unsigned int>(bindID);
}

unsigned int FileBinderCri::BindFile(const char* filePath, int priority, bool isAbsolute)
{
    CriFsBinderId bindID;
    char buf[256];
    FileSystem& fileSystem = FileSystem::GetInstance();

    if (!isAbsolute)
    {
        std::strcpy(buf, fileSystem.RootDirectory);
        std::strcat(buf, filePath);
    }
    else
    {
        std::strcpy(buf, filePath);
    }

    ConvertPath(buf);
    criFsBinder_BindFile(binder, nullptr, buf, nullptr, 0, &bindID);

    if (bindID)
    {
        criFsBinder_SetPriority(bindID, priority);
        boundIDs.push_back_unchecked(static_cast<unsigned int>(bindID));
    }

    return static_cast<unsigned int>(bindID);
}

bool FileBinderCri::IsSyncComplete(unsigned int id)
{
    CriFsBinderStatus status;
    CriFsBindId criID = static_cast<CriFsBindId>(id);
    criFsBinder_GetStatus(criID, &status);

    // Unbind the given file if necessary
    if (status != CRIFSBINDER_STATUS_COMPLETE)
    {
        // Return false if sync is not complete
        if (status != CRIFSBINDER_STATUS_ERROR)
        {
            return false;
        }

        // Unbind the given file
        CriFsBinderInfo bindInfo;
        criFsBinder_GetBinderIdInfo(criID, &bindInfo);
        criFsBinder_Unbind(criID);
    }

    return true;
}

bool FileBinderCri::IsSyncCompleteAll()
{
    if (!boundIDs.empty())
    {
        auto it = boundIDs.begin();
        while (it != boundIDs.end())
        {
            CriFsBinderStatus status;
            criFsBinder_GetStatus(static_cast<CriFsBindId>(*it), &status);

            if (status == CRIFSBINDER_STATUS_COMPLETE)
            {
                it = boundIDs.erase(it);
            }
            else if (status == CRIFSBINDER_STATUS_ERROR)
            {
                CriFsBinderInfo idInfo;
                criFsBinder_GetBinderIdInfo(static_cast<CriFsBindId>(*it), &idInfo);
                criFsBinder_Unbind(static_cast<CriFsBindId>(*it));
                it = boundIDs.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }

    return boundIDs.empty();
}

void FileBinderCri::WaitSync(unsigned int id)
{
    CriFsBindId criID = static_cast<CriFsBindId>(id);
    bool isSyncComplete = IsSyncComplete(criID);

    while (!isSyncComplete)
    {
        FileSystem& fileSystem = FileSystem::GetInstance();
        fileSystem.Update();
        ThreadSleep(1);
        isSyncComplete = IsSyncComplete(criID);
    }
}

void FileBinderCri::WaitSyncAll()
{
    bool isSyncComplete = IsSyncCompleteAll();
    while (!isSyncComplete)
    {
        FileSystem& fileSystem = FileSystem::GetInstance();
        fileSystem.Update();
        ThreadSleep(1);
        isSyncComplete = IsSyncCompleteAll();
    }
}

void FileBinderCri::SetCurrentDirectory(unsigned int id, const char* path)
{
    criFsBinder_SetCurrentDirectory(static_cast<CriFsBindId>(id),
        reinterpret_cast<const CriChar8*>(path), nullptr, 0);
}

bool FileBinderCri::Unbind(unsigned int id)
{
    CriError err = criFsBinder_Unbind(static_cast<CriFsBindId>(id));
    return (err == CRIERR_OK);
}

bool FileBinderCri::IsFileExist(const char* filePath)
{
    CriBool exists = 0;
    if (filePath)
    {
        criFsBinder_Find(binder, filePath, nullptr, &exists);
    }

    return (exists == 1);
}

std::size_t FileBinderCri::GetFileSize(const char* filePath)
{
    if (filePath)
    {
        CriSint64 fileSize;
        criFsBinder_GetFileSize(binder, filePath, &fileSize);

        if (fileSize >= 0)
        {
            return static_cast<std::size_t>(fileSize);
        }
    }

    return 0;
}

bool FileBinderCri::IsBind(unsigned int id) const
{
    CriFsBinderStatus status;
    criFsBinder_GetStatus(static_cast<CriFsBindId>(id), &status);
    return (status == CRIFSBINDER_STATUS_COMPLETE);
}

FileBinderCri::FileBinderCri(csl::fnd::IAllocator* allocator, std::size_t maxBoundIds) :
    allocator(allocator),
    binder(nullptr),
    boundIDs(maxBoundIds, allocator)
{
    criErr_SetCallback(user_error_callback_func); // TODO: REMOVE THIS LINE!!! IT'S NOT IN THE ACTUAL GAME
    criFsBinder_Create(&binder);
}
}
}
#endif
