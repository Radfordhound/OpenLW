#include "pch.h"
#include "Hedgehog/Utility/hhResDictionary.h"

namespace hh
{
namespace ut
{
s32 ResDicLinear::GetIndex(const char* key) const
{
    if (IsValid() && key)
    {
        for (s32 i = 0; i < ref().Count; ++i)
        {
            if (std::strcmp(key, ref().Entries[i].Key) == 0)
            {
                return i;
            }
        }
    }

    return -1;
}

s32 ResDicLinear::GetIndex(const char* key, int startChar) const
{
    if (IsValid() && key)
    {
        const char* startPos = std::strchr(key, startChar);
        if (startPos)
        {
            key = (startPos + 1);
        }

        for (s32 i = 0; i < ref().Count; ++i)
        {
            startPos = std::strchr(ref().Entries[i].Key, startChar);

            if ((!startPos && std::strcmp(key, ref().Entries[i].Key) == 0) ||
                (startPos && std::strcmp(key, startPos + 1) == 0))
            {
                return i;
            }
        }
    }

    return -1;
}
}
}
