#pragma once
#include "ResourceCustom.h"
#include "ReferencedObject.h"
#include "Singleton.h"
#include "File.h"
#include <Hedgehog/Utility/hhPackfile.h>
#include <csl/ut/array.h>
#include <csl/ut/string_map.h>

namespace app
{
namespace fnd
{
struct ResourceCallbackBase;

template<typename T>
struct ResRawBase : public hh::ut::ResCommon<T> // TODO: Is this correct?
{
    const char* GetName() const
    {
        return m_ptr->Name;
    }

    void* GetAddress() const
    {
        return m_ptr->Address;
    }

    std::size_t GetSize() const
    {
        return m_ptr->Size;
    }

    int GetCategory() const
    {
        return m_ptr->Category;
    }

    void SetData(const ResourceArgsData& args)
    {
        m_ptr->Size = args.Size;
        m_ptr->field_0x4 = args.Address;
        m_ptr->Address = args.Address;
        m_ptr->Name = args.Name;
        m_ptr->Category = args.Category;
    }

    void SetResolvedData(void* param_1)
    {
        m_ptr->Address = param_1;
    }

    ResRawBase(const void* data) :
        hh::ut::ResCommon<T>(data) {}

    ResRawBase(void* data) :
        hh::ut::ResCommon<T>(data) {}
};

struct ResRawDataData // size == 20
{
    const char* Name;
    void* field_0x4;
    void* Address;
    std::size_t Size;
    int Category;
};

struct ResRawData : public ResRawBase<ResRawDataData>
{
    inline ResRawData(const void* data) :
        ResRawBase<ResRawDataData>(data) {}

    inline ResRawData(void* data) :
        ResRawBase<ResRawDataData>(data) {}
};

struct ResourceCallbackData // size == 8
{
    unsigned int Value;
    ResourceCallbackBase* Callback;
};

class ResourceManager : public ReferencedObject, public csl::fnd::Singleton<ResourceManager> // size == 0xc0
{
    DECLARE_SINGLETON

    struct ResourceData // size == 20
    {
        const char* Name;
        IResourceCustomLoader* Loader;
        void* Data;
        csl::fnd::com_ptr<FileHandleObj> FileHandle;
        unsigned int Flags;

        inline ResourceData() :
            Name(nullptr),
            Loader(nullptr),
            Data(nullptr),
            FileHandle(nullptr),
            Flags(0) {}
    };

    const ResourceCustomInfo* const* m_resourceCustomInfoList;
    // TODO: Data members
    IResourceCustomLoader* m_defaultLoader;
    csl::ut::StringMap<IResourceCustomLoader*> m_resourceLoaders;
    csl::ut::MoveArray<ResourceData*> m_resourceData;
    csl::ut::StringMap<ResourceData*> m_resourceNames;
    csl::ut::MoveArray<ResourceCallbackData> m_resourceCallbackData;
    // TODO: Data members

    // Wii U: 0x021ae38c, PC: TODO
    void RegisterList(const ResourceCustomInfo* const* resCustomInfoList);

public:
    // Wii U: 0x021ae44c, PC: TODO
    ResourceManager();

    // Wii U: 0x021aed1c, PC: TODO
    IResourceCustomLoader* GetResourceLoader(const char* name);

    // Wii U: 0x021aeef0, PC: TODO
    bool AddResourceName(const char* name, csl::fnd::com_ptr<FileHandleObj> fileHandle);

    // Wii U: 0x021af160, PC: TODO
    void CreateResource(const char* name, csl::fnd::IAllocator* allocator,
        void* data, std::size_t size, int category, unsigned int param_6);

    // Wii U: 0x021b0a5c, PC: TODO
    static int ResouceCallbackSort(ResourceCallbackData a, ResourceCallbackData b);

    // Wii U: 0x021b0a74, PC: TODO
    void AddCallback(ResourceCallbackBase* callback, unsigned int value);

    // Wii U: 0x021b0c38, PC: TODO
    void SetupCallback(hh::ut::Packfile pac, csl::fnd::IAllocator* allocator);

    // Wii U: 0x021b0d8c, PC: TODO
    void* GetResource(const char* name, std::size_t size);

    template<typename T>
    T Get(const char* name)
    {
        return T(GetResource(name, sizeof(typename T::value_type)));
    }
};
}
}
