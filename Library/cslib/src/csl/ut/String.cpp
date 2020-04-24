#include "csl/ut/String.h"

namespace csl
{
namespace ut
{
std::size_t String::copyFrom(const char* src, std::size_t srcLen,
    std::size_t srcOff, std::size_t dstOff)
{
    // Resize string if necessary
    if ((static_cast<std::size_t>(capacityAndFlags) & CapacityMaskSizeT) <= (srcLen + dstOff))
    {
        resize(srcLen + dstOff + 1);
    }

    // Copy data and set null terminator
    std::strncpy(data + dstOff, src + srcOff, srcLen);
    data[dstOff + srcLen] = '\0';

    // Set length and return
    len = static_cast<unsigned short>(dstOff + srcLen);
    return static_cast<std::size_t>(len);
}

void String::resize(std::size_t len)
{
    // Only resize if the string's size doesn't already match the requested size
    if ((static_cast<std::size_t>(capacityAndFlags) & CapacityMaskSizeT) != len)
    {
        // Allocate a new buffer of the requested size
        char* newBuf = static_cast<char*>(allocator->Alloc(len));
        if (data)
        {
            // Copy over the data from the previous buffer and set the null terminator
            std::strncpy(newBuf, data, static_cast<std::size_t>(this->len));
            newBuf[this->len] = '\0';

            // Free the previous buffer if necessary
            if (!(capacityAndFlags & NoFreeFlag))
            {
                allocator->Free(data);
            }
        }

        // Set pointer to the new buffer and new capacity
        data = newBuf;
        capacityAndFlags = static_cast<unsigned short>(len);
    }
}
}
}
