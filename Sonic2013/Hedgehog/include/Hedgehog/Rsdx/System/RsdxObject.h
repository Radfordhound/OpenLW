#pragma once
#include <cstddef>

namespace hh
{
namespace rsdx
{
struct RsdxObject
{
    // Wii U: 0x036a7d28, PC: N/A
    void* operator new(std::size_t size);

    // Wii U: 0x036a8280, PC: TODO
    void* operator new(std::size_t size, void* ptr);

    // Wii U: 0x036a7d48, PC: N/A
    void operator delete(void* ptr);

    // TODO: Is this function actually a thing?
    void operator delete(void* ptr1, void* ptr2)
    {
        // TODO
    }
};

class RsdxRefcountObject : public RsdxObject
{
    unsigned long m_refCount;

public:
    // Wii U: 0x036a7fa4 (THUNK), PC: N/A
    unsigned long AddRef();

    // TODO

    // Wii U: TODO, PC: TODO
    RsdxRefcountObject() :
        m_refCount(0) {}
};

struct RsdxSystemResource : public RsdxObject
{
    virtual bool CloseSystemResource() = 0;

    virtual bool WaitSystemResource() = 0;

    // Wii U: 0x036a7ff4, PC: 0x00c24fd0
    virtual bool DeleteThis();

    // Wii U: 0x036a806c, PC: TODO
    virtual ~RsdxSystemResource();
};
}
}
