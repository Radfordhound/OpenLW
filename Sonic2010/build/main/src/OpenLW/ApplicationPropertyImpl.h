#pragma once

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
    static void* operator new(std::size_t size)
    {
        // TODO: It doesn't seem to actually call GetSingletonAllocator here; it seems this value is passed
        // in via an argument or something instead? But the symbols say there is no allocator argument??
        csl::fnd::IAllocator* allocator = fnd::GetSingletonAllocator();
        ApplicationPropertyImpl* buf = static_cast<ApplicationPropertyImpl*>(
            allocator->Alloc(size + sizeof(allocator)));

        *reinterpret_cast<csl::fnd::IAllocator**>(buf + 1) = allocator;
        return buf;
    }

    // Wii U: 0x021c7a08, PC: Inlined
    ApplicationPropertyImpl(csl::fnd::IAllocator* allocator) :
        field_0x4(0),
        field_0x8(0),
        field_0xc(0) {}

    // TODO: Is this correct?
    // Wii U: 0x021c7ae8, PC: TODO
    static void operator delete(void* ptr)
    {
        if (ptr)
        {
            csl::fnd::IAllocator* allocator = reinterpret_cast<csl::fnd::IAllocator*>(
                static_cast<ApplicationPropertyImpl*>(ptr) + 1);

            allocator->Free(ptr);
        }
    }

    // Wii U: 0x021c7e90, PC: TODO
    void getMultiLanguageName(const char* param_1, unsigned int param_2, csl::ut::String* result)
    {
        // TODO
    }
};
}
