#pragma once
#include <cstdint>

namespace csl
{
namespace fnd
{
struct Tick
{
    std::uint64_t Value;

    // TODO: Other functions

    /* <b>Wii U: 0x02caa164, PC: 0x009690f0</b> */
    static void Sample(Tick* tick);
};
    // TODO
}
}
