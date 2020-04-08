#pragma once
#include <cstdint>

namespace csl
{
namespace ut
{
struct Color8
{
    std::uint8_t R, G, B, A; // TODO: Is this order right?

    inline void SetARGB(std::uint32_t v)
    {
        B = static_cast<std::uint8_t>(v);
        R = static_cast<std::uint8_t>(v >> 0x10);
        A = static_cast<std::uint8_t>(v >> 0x18);
        G = static_cast<std::uint8_t>(v >> 8);
    }

    // TODO

    Color8* operator*(const Color8& v);
    //Color8* operator*=(const Color8& v);
    Color8* operator/(const Color8& v);
    //Color8* operator/=(const Color8& v);
};
}
}
