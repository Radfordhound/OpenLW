#pragma once
#include <Hedgehog/Base/System/hhMemory.h>
#include <Hedgehog/Rsdx/System/RsdxAtomic.h>
#include <cstddef>

namespace Extra
{
namespace fx
{
class CFxObject
{
public:
    static void* operator new(std::size_t size)
    {
        return __HH_ALLOCALIGN(size);
    }

    static void operator delete(void* ptr)
    {
        __HH_FREE(ptr);
    }
};

class CFxRefcountObject : public CFxObject // size == 8
{
    hh::rsdx::RsdxAtomic m_refCount;

public:
    LWAPI(0x03715b7c, TODO)
    CFxRefcountObject();

    LWAPI(0x03715bc4, 0x00c49720)
    virtual ~CFxRefcountObject();

    LWAPI(0x03715bd8, TODO)
    void AddRef();

    LWAPI(0x03715bdc, TODO)
    void Release();
};

inline void intrusive_ptr_add_ref(CFxRefcountObject* obj)
{
    obj->AddRef();
}

inline void intrusive_ptr_release(CFxRefcountObject* obj)
{
    obj->Release();
}
}
}
