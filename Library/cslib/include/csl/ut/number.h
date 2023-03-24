// TODO: Both the name of this file and its path were guessed!
#pragma once
#include <limits>

#ifndef _MSC_VER
#include <cstdint>
#endif

/* Bit helper macros. */
#define CSL_BIT_COUNT(type)         (sizeof(type) * CHAR_BIT)
#define CSL_HIGH_BITMASK(type)      (1 << (CSL_BIT_COUNT(type) - 1))
#define CSL_HIGH_BIT(val)           ((val) & CSL_HIGH_BITMASK(val))

/* Endian-order macros. */
#ifndef CSL_IS_BIG_ENDIAN
#ifdef __ORDER_BIG_ENDIAN__ // TODO: Does this work on devkitpro Wii U builds?
#define CSL_IS_BIG_ENDIAN
#endif
#endif

/* Endian-swap macros. */
#if defined(_MSC_VER) && _MSC_VER >= 1310 
#include <stdlib.h>
#define CSL_SWAP_U16(v) _byteswap_ushort(v)
#define CSL_SWAP_U32(v) _byteswap_ulong(v)
#define CSL_SWAP_U64(v) _byteswap_uint64(v)
#else
#define CSL_SWAP_U16(v) __builtin_bswap16(v)
#define CSL_SWAP_U32(v) __builtin_bswap32(v)
#define CSL_SWAP_U64(v) __builtin_bswap64(v)
#endif

namespace csl
{
#ifdef _MSC_VER
typedef __int8 s8;
typedef unsigned __int8 u8;
typedef __int16 s16;
typedef unsigned __int16 u16;
typedef __int32 s32;
typedef unsigned __int32 u32;
typedef __int64 s64;
typedef unsigned __int64 u64;
#else
typedef std::int8_t s8;
typedef std::uint8_t u8;
typedef std::int16_t s16;
typedef std::uint16_t u16;
typedef std::int32_t s32;
typedef std::uint32_t u32;
typedef std::int64_t s64;
typedef std::uint64_t u64;
#endif

namespace ut
{
template<typename T>
const T& Min(const T& a, const T& b)
{
    return (b < a) ? b : a;
}

template<typename T>
T RoundUp(const T& val, unsigned int multiple)
{
    return (((val + multiple) - 1) & ~(multiple - 1));
}

LWAPI(0x02ca6da8, 0x00969760)
void NativeFromBig32(void* output, void* input, int count);

LWAPI(0x02ca6dd4, TODO)
void NativeFromLittle32(void* param_1, void* param_2, int count);
} // ut
} // csl
