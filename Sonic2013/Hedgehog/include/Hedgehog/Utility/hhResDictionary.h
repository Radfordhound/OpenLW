#pragma once
#include "hhResCommon.h"

namespace hh
{
namespace ut
{
struct ResDicLinearEntry // TODO: This name was guessed!
{
    OFF32(char) Key;
    OFF32(void) Value;
};

struct ResDicLinearData
{
    s32 Count;
    OFF32(ResDicLinearEntry) Entries;
};

struct ResDicLinear : public ResCommon<ResDicLinearData>
{
    LWAPI(TODO, TODO)
    const char* GetName(s32 index) const
    {
        if (IsValid() && index > -1 && index < ref().Count)
        {
            return ref().Entries[index].Key;
        }

        return nullptr;
    }

    LWAPI(0x036968d4, TODO)
    s32 GetIndex(const char* key) const;

    LWAPI(0x0369697c, TODO)
    s32 GetIndex(const char* key, int startChar) const;

    LWAPI(TODO, TODO)
    const void* operator[](s32 index) const
    {
        if (IsValid() && index > -1 && index < ref().Count)
        {
            return ref().Entries[index].Value;
        }

        return nullptr;
    }

    // TODO: Is this function actually a thing?
    inline void* operator[](s32 index)
    {
        return const_cast<void*>(const_cast<const ResDicLinear*>(
            this)->operator[](index));
    }

    inline ResDicLinear(const void* data) :
        ResCommon<ResDicLinearData>(data) {}

    inline ResDicLinear(void* data = nullptr) :
        ResCommon<ResDicLinearData>(data) {}
};
}
}
