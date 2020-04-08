#include "FileBinderCri.h"

namespace app
{
namespace fnd
{
    FileBinderCri::FileBinderCri(csl::fnd::IAllocator* allocator, std::size_t param_2) :
        allocator(allocator), binder(nullptr), ids(param_2, allocator)
    {
        criFsBinder_Create(&binder);
    }

    FileBinderCri::~FileBinderCri()
    {
        criFsBinder_Destroy(binder);
    }

    void* FileBinderCri::GetBinderHn() const
    {
        return binder;
    }

    unsigned int FileBinderCri::BindCpk(const char* filePath, int priority, bool param_3)
    {
        // TODO
        return 0;
    }

    unsigned int FileBinderCri::BindDirectory(const char* filePath, int priority, bool param_3)
    {
        // TODO
        return 0;
    }

    unsigned int FileBinderCri::BindFile(const char* filePath, int priority, bool param_3)
    {
        // TODO
        return 0;
    }

    bool FileBinderCri::IsSyncComplete(unsigned int id) const
    {
        CriFsBinderStatus status;
        criFsBinder_GetStatus(static_cast<CriFsBindId>(id), &status);

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
            criFsBinder_GetBinderIdInfo(
                static_cast<CriFsBindId>(id), &bindInfo);

            criFsBinder_Unbind(static_cast<CriFsBindId>(id));
        }

        return true;
    }

    bool FileBinderCri::IsSyncCompleteAll() const
    {
        // TODO
        return true;
    }

    void FileBinderCri::WaitSync(unsigned int id)
    {
        //bool isSyncComplete = IsSyncComplete(id);
        //while (!isSyncComplete)
        //{

        //    // TODO
        //}
        // TODO
    }

    void FileBinderCri::WaitSyncAll()
    {
        // TODO
    }

    void FileBinderCri::SetCurrentDirectory(unsigned int param_1, const char* param_2)
    {
        criFsBinder_SetCurrentDirectory(param_1, param_2, nullptr, 0);
    }

    bool FileBinderCri::Unbind(unsigned int id)
    {
        CriError err = criFsBinder_Unbind(id);
        return (err == CRIERR_OK);
    }

    bool FileBinderCri::IsFileExist(const char* filePath) const
    {
        CriBool exists = 0;
        if (filePath)
        {
            criFsBinder_Find(binder, filePath, nullptr, &exists);
        }

        return (exists == 1);
    }

    std::size_t FileBinderCri::GetFileSize(const char* filePath) const
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
        criFsBinder_GetStatus(id, &status);
        return (status == CRIFSBINDER_STATUS_COMPLETE);
    }
}
}
