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
    inline ResUserData(const void* data) :
        ResCommon<ResUserDataData>(data) {}

    inline ResUserData(void* data = nullptr) :
        ResCommon<ResUserDataData>(data) {}
};
}
}
}
