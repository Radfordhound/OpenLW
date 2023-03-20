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
    LWAPI(0x021c7a04, NONE)
    static void* operator new(std::size_t size);

    LWAPI(0x021c7a08, NONE)
    ApplicationPropertyImpl(csl::fnd::IAllocator* allocator);

    // TODO: Is this correct?
    LWAPI(0x021c7ae8, TODO)
    static void operator delete(void* ptr);

    LWAPI(0x021c7e90, TODO)
    void getMultiLanguageName(const char* param_1, unsigned int param_2, csl::ut::String* result);
};
}
