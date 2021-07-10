#pragma once

namespace csl
{
namespace fnd
{
struct Tick
{
    long long Value;

    // Wii U: TODO, PC: TODO
    long long ToMicroseconds() const;

    // TODO

    // Wii U: TODO, PC: 0x00969130
    static void Initialize();

    // Wii U: 0x02caa1d4, PC: TODO
    static void Finalize();

    // Wii U: 0x02caa164, PC: 0x009690f0
    static Tick Sample();

    inline Tick() : Value(0LL) {}

    inline Tick(long long value) : Value(value) {}
};
}
}
