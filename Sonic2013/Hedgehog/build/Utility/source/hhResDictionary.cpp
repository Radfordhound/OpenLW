#include "Hedgehog/Utility/hhResDictionary.h"
#include <cstring>

namespace hh
{
namespace ut
{
int ResDicLinear::GetIndex(const char* key) const
{
    if (IsValid() && key)
    {
        for (int i = 0; i < ref().Count; ++i)
        {
            if (std::strcmp(key, ref().Entries[i].Key) == 0)
            {
                return i;
            }
        }
    }

    return -1;
}

int ResDicLinear::GetIndex(const char* key, int startChar) const
{
    if (IsValid() && key)
    {
        const char* startPos = std::strchr(key, startChar);
        if (startPos)
        {
            key = (startPos + 1);
        }

        for (int i = 0; i < ref().Count; ++i)
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
