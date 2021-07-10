#pragma once
#include "hhMemoryAllocator.h"

namespace hh
{
namespace base
{
class CObject
{
    // TODO: Data Members?

public:
    // Wii U: 0x0369973c, PC: 0x00c1e780
    static void* operator new(std::size_t size);

    // Wii U: TODO, PC: TODO
    static void operator delete(void* ptr);
};

class CRefCountObject
{
    std::size_t m_refCount; // TODO: Change the type of this to an RsdxAtomic

public:
    // Wii U: 0x03699874, PC: 0x00442340
    virtual ~CRefCountObject();

    // Wii U: 0x036998f8, PC: TODO
    std::size_t RefCount() const;

    // Wii U: 0x03699900, PC: TODO
    bool IsUnique() const;

    // Wii U: 0x03699888, PC: TODO
    void AddRef();

    // TODO: Change the return type to an RsdxAtomic
    // Wii U: 0x0369988c, PC: TODO
    std::size_t Release();

    // Wii U: 0x0369982c, PC: TODO
    CRefCountObject();
};

inline void intrusive_ptr_add_ref(CRefCountObject* obj)
{
    obj->AddRef();
}

inline void intrusive_ptr_release(CRefCountObject* obj)
{
    obj->Release();
}
}
}
