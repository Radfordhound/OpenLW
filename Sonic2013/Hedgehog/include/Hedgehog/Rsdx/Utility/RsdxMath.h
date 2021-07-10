#pragma once

namespace hh
{
namespace rsdx
{
template<typename T>
T rsdx_min(T a, T b) noexcept
{
    return (a <= b) ? a : b;
}
}
}
