// TODO: Both the name of this file and its path were guessed!
#pragma once
#include <cstddef>

namespace csl
{
namespace fnd
{
struct IAllocator;
}

namespace ut
{
class String;
}
}

namespace app
{
struct ApplicationPropertyImpl // size == 16
{
    csl::fnd::IAllocator* Allocator;
    unsigned int field_0x4;
    unsigned int field_0x8;
    unsigned int field_0xc;

    // TODO: Is this correct?
    // Wii U: 0x021c7a04, PC: Inlined
    static void* operator new(std::size_t size);

    // Wii U: 0x021c7a08, PC: Inlined
    ApplicationPropertyImpl(csl::fnd::IAllocator* allocator);

    // TODO: Is this correct?
    // Wii U: 0x021c7ae8, PC: TODO
    static void operator delete(void* ptr);

    // Wii U: 0x021c7e90, PC: TODO
    void getMultiLanguageName(const char* param_1, unsigned int param_2, csl::ut::String* result);
};
}
