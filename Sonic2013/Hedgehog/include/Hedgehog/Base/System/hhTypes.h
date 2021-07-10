#pragma once

#ifndef _MSC_VER
#include <cstdint>
#endif

namespace hh
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
}
