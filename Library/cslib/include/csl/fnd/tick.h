// TODO: Both the name of this file and its path were guessed!
#pragma once

namespace csl
{
namespace fnd
{
struct Tick
{
    long long Value;

    LWAPI(TODO, TODO)
    long long ToMicroseconds() const;

    // TODO

    LWAPI(TODO, 0x00969130)
    static void Initialize();

    LWAPI(0x02caa1d4, TODO)
    static void Finalize();

    LWAPI(0x02caa164, 0x009690f0)
    static Tick Sample();

    inline Tick() : Value(0LL) {}

    inline Tick(long long value) : Value(value) {}
};
} // fnd
} // csl
