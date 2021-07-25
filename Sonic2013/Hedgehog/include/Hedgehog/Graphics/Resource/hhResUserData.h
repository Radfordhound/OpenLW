#pragma once
#include "hhResNameData.h"

namespace hh
{
namespace gfx
{
namespace res
{
struct ResUserDataItemData
{
    std::size_t Index;
    std::size_t Size;
    std::size_t Count;
    void* Data;
    ResNameData Name;
};

struct ResUserDataItem : public ut::ResCommon<ResUserDataItemData>
{
    template<typename T>
    T* GetDataPtr(std::size_t index = 0) const
    {
        return (static_cast<T*>(m_ptr->Data) + index);
    }

    inline ResUserDataItem(const void* data) :
        ResCommon<ResUserDataItemData>(data) {}

    inline ResUserDataItem(void* data = nullptr) :
        ResCommon<ResUserDataItemData>(data) {}
};

struct ResUserDataData
{
    std::size_t ItemCount;
    ResUserDataItemData* Items;
};

struct ResUserData : public ut::ResCommon<ResUserDataData>
{
    // Wii U: 0x0367bec4, PC: TODO
    std::size_t GetNumResUserDataItems() const;

    // Wii U: 0x0367bee8, PC: TODO
    ResUserDataItem GetResUserDataItem(std::size_t index);

    inline ResUserData(const void* data) :
        ResCommon<ResUserDataData>(data) {}

    inline ResUserData(void* data = nullptr) :
        ResCommon<ResUserDataData>(data) {}
};
}
}
}
