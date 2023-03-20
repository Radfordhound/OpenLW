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
    LWAPI(0x036a7d28, NONE)
    void* operator new(std::size_t size);

    LWAPI(0x036a8280, TODO)
    void* operator new(std::size_t size, void* ptr);

    LWAPI(0x036a7d48, NONE)
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
    LWAPI(0x036a7fa4, NONE)
    RsdxAtomic AddRef();

    LWAPI(0x036a7fa8, NONE)
    RsdxAtomic Release();

    // TODO

    LWAPI(TODO, TODO)
    RsdxRefcountObject() :
        m_refCount(0) {}
};
#endif

struct RsdxSystemResource : public RsdxObject
{
    void* Handle;

    virtual bool CloseSystemResource() = 0;

    virtual bool WaitSystemResource() = 0;

    LWAPI(0x036a7ff4, 0x00c24fd0)
    virtual bool DeleteThis();

    LWAPI(0x036a806c, TODO)
    virtual ~RsdxSystemResource();
};
}
}
