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
    // Wii U: 0x036926a8 (Multiple addresses?), PC: TODO
    const char* GetName(int index) const
    {
        if (IsValid() && index > -1 && index < ref().Count)
        {
            return ref().Entries[index].Key;
        }

        return nullptr;
    }

    // Wii U: 0x036968d4, PC: TODO
    int GetIndex(const char* key) const;

    // Wii U: 0x0369697c, PC: TODO
    int GetIndex(const char* key, int startChar) const;

    // Wii U: 0x03692748 (Multiple addresses?), PC: TODO
    const void* operator[](int index) const
    {
        if (IsValid() && index > -1 && index < ref().Count)
        {
            return ref().Entries[index].Value;
        }

        return nullptr;
    }

    // TODO: Is this function actually a thing?
    inline void* operator[](int index)
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
