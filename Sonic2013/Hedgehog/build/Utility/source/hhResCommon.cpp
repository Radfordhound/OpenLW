#include "pch.h"
#include "Hedgehog/Utility/hhPackfile.h"
#include "Hedgehog/Utility/hhResDictionary.h"
#include <csl/ut/number.h>

namespace hh
{
namespace ut
{
void ResFileCommon::ChangeEndian32(bool doSwap, const u32* input, u32* output)
{
    if (doSwap)
    {
#ifdef CSL_IS_BIG_ENDIAN
        csl::ut::NativeFromLittle32(output, const_cast<u32*>(input), 1);
#else
        csl::ut::NativeFromBig32(output, const_cast<u32*>(input), 1);
#endif
    }
    else
    {
        *output = *input;
    }
}

u32 ResFileCommon::GetReverseBigEndian(u32 val)
{
    u32 result;
    csl::ut::NativeFromBig32(&result, &val, 1);
    return result;
}

void ResFileCommon::ReplacePof0(void* baseAddress,
    void* pof0Address, u32 pof0Size, bool doSwap)
{
    u8* curPof0Address = static_cast<u8*>(pof0Address);
    u32 curOffRelPos = 0;
    u8 curPof0[4];

    // TODO: Did they *actually* use memcpy throughout this function?
    // Or was this just a weird thing done by the compiler?

    while (pof0Size)
    {
        // Get a byte from the POF0 table.
        curPof0[0] = *(curPof0Address++);
        --pof0Size;

        switch (curPof0[0] & POF0_SIZE_MASK)
        {
        case POF0_SIZE_SIX_BIT:
            // Increase current offset relative position.
            curOffRelPos += ((curPof0[0] & POF0_DATA_MASK) * sizeof(u32));
            break;

        case POF0_SIZE_FOURTEEN_BIT:
            // Get another byte from the POF0 table.
            curPof0[1] = *(curPof0Address++);
            --pof0Size;

            // Increase current offset relative position.
            curOffRelPos += ((((static_cast<u32>(curPof0[0]) & POF0_DATA_MASK) << 8) |
                curPof0[1]) * sizeof(u32));
            break;

        case POF0_SIZE_THIRTY_BIT:
            // Get another three bytes from the POF0 table.
            curPof0[1] = *(curPof0Address++);
            curPof0[2] = *(curPof0Address++);
            curPof0[3] = *(curPof0Address++);
            pof0Size -= 3;

            // Increase current offset relative position.
            curOffRelPos += ((((static_cast<u32>(curPof0[0]) & POF0_DATA_MASK) << 24) |
                (curPof0[1] << 16) | (curPof0[2] << 8) | curPof0[3]) * sizeof(u32));
            break;

        default:
            continue;
        }

        // Get the address of the current offset.
        u32* curOffAddress = reinterpret_cast<u32*>(
            static_cast<u8*>(baseAddress) + curOffRelPos);

        // Endian-swap the current offset and get its value.
        ChangeEndian32(doSwap, curOffAddress, curOffAddress);
        u32 curOffVal = *curOffAddress;

        // "Fix" the current offset (that is, turn it into a pointer) if it's not NULL.
        if (curOffVal != 0)
        {
            *reinterpret_cast<OFF32(void)*>(curOffAddress) = reinterpret_cast<void*>(
                (reinterpret_cast<std::uintptr_t>(baseAddress) + curOffVal));
        }
    }
}

void ResFileCommon::ReplaceDic(unsigned int version, void* param_2,
    void* param_3, unsigned int depth, bool doSwap)
{
    unsigned int nextDepth = depth;
    if (depth != 0)
    {
        nextDepth = (depth - 1);
    }

    ResDicLinear dic(param_3);
    ChangeEndian32(doSwap, &dic.ref().Count, &dic.ref().Count);

    if (dic.ref().Count > 0)
    {
        if (version < 2)
        {
            // TODO
        }

        for (s32 i = 0; i < dic.ref().Count; ++i)
        {
            ResDicLinearEntry& curEntry = dic.ptr()->Entries[i];
            if (version < 2)
            {
                // TODO
            }

            if (depth != 0)
            {
                ReplaceDic(version, param_2, curEntry.Value, nextDepth, doSwap);
            }
        }
    }
}
}
}
