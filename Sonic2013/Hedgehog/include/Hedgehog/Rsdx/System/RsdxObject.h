#pragma once
#include "RsdxAtomic.h"
#include <cstddef>

#ifdef _WIN32
#include <d3d9.h>
#endif

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

#ifdef _WIN32
typedef IUnknown RsdxRefcountObject;
#else
class RsdxRefcountObject : public RsdxObject
{
    RsdxAtomic m_refCount;

public:
    // Wii U: 0x036a7fa4 (THUNK), PC: N/A
    RsdxAtomic AddRef();

    // Wii U: 0x036a7fa8, PC: N/A
    RsdxAtomic Release();

    // TODO

    // Wii U: TODO, PC: TODO
    RsdxRefcountObject() :
        m_refCount(0) {}
};
#endif

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
