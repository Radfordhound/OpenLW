#pragma once
#include <cstddef>

namespace csl
{
namespace fnd
{
struct IAllocator
{
    LWAPI(NONE, 0x00445a00)
    virtual ~IAllocator() {} // Wii U VTABLE OFF: 8

    /*
        @brief Allocates the requested amount of memory with the requested alignment.
        @param[in] size         The amount of memory to allocate.
        @param[in] alignment    The alignment the allocated memory should have.
        @return A pointer to the allocated memory, or nullptr if allocation failed.
    */
    virtual void* Alloc(std::size_t size, std::size_t alignment = 16) = 0; // Wii U VTABLE OFF: 0x10

    /*
        @brief Frees the given memory.
        @param[in] ptr  A pointer to the memory to free. Must have been allocated using Alloc.
        @remarks Calling Free on memory not allocated using this allocator's Alloc is undefined behavior.
    */
    virtual void Free(void* ptr) = 0; // Wii U VTABLE OFF: 0x18

    // TODO: Is this function actually a thing?
    /*template<typename T>
    inline T* Create()
    {
        void* ptr = Alloc(sizeof(T));
        if (ptr)
        {
            new (ptr) T();
        }

        return ptr;
    }*/

    //template<typename T>
    //inline void Delete(T* obj) // TODO: Does this function even actually exist??
    //{
    //    if (obj)
    //    {
    //        obj->~T();
    //        Free(obj);
    //    }
    //}
};

struct DefaultAllocator : IAllocator
{
    LWAPI(NONE, 0x00445a30)
    void* Alloc(std::size_t size, std::size_t alignment = 16)
    {
        return (size) ? ::operator new(size) : nullptr;
    }

    LWAPI(NONE, 0x00445a50)
    void Free(void* ptr)
    {
        ::operator delete(ptr);
    }
};

template<typename T>
class com_ptr
{
    T* m_ptr;

public:
    T* get() const
    {
        return m_ptr;
    }

    operator bool() const
    {
        return (m_ptr != nullptr);
    }

    T* operator->() const
    {
        return m_ptr;
    }

    com_ptr<T>& operator=(const com_ptr<T>& other)
    {
        if (other.m_ptr)
        {
            other.m_ptr->AddRef();
        }

        if (m_ptr)
        {
            m_ptr->Release();
        }

        m_ptr = other.m_ptr;
        return *this;
    }

    com_ptr<T>& operator=(T* ptr)
    {
        if (ptr)
        {
            ptr->AddRef();
        }

        if (m_ptr)
        {
            m_ptr->Release();
        }

        m_ptr = ptr;
        return *this;
    }

    // TODO

    com_ptr() :
        m_ptr(nullptr) {}

    com_ptr(T* ptr, bool addRef = true) :
        m_ptr(ptr)
    {
        if (ptr && addRef)
        {
            ptr->AddRef();
        }
    }

    com_ptr(const com_ptr<T>& other) :
        m_ptr(other.m_ptr)
    {
        if (other.m_ptr)
        {
            other.m_ptr->AddRef();
        }
    }

    ~com_ptr()
    {
        if (m_ptr)
        {
            m_ptr->Release();
        }
    }
};

LWAPI(0x02c995b8, 0x00968aa0)
std::size_t StrLcpy(char* dst, const char* src, std::size_t len);
}
}

// TODO: Is this function actually a thing?
inline void* operator new(std::size_t size, csl::fnd::IAllocator* allocator)
{
    return allocator->Alloc(size);
}

// TODO: Is this function actually a thing?
inline void operator delete(void* ptr, csl::fnd::IAllocator* allocator)
{
    allocator->Free(ptr);
}

// TODO: Is this function actually a thing?
inline void* operator new[](std::size_t size, csl::fnd::IAllocator* allocator)
{
    return allocator->Alloc(size);
}

// TODO: Is this function actually a thing?
inline void operator delete[](void* ptr, csl::fnd::IAllocator* allocator)
{
    allocator->Free(ptr);
}

// TODO: Is this function actually a thing?
inline void* operator new(std::size_t size,
    csl::fnd::IAllocator* allocator, std::size_t alignment)
{
    return allocator->Alloc(size, alignment);
}

// TODO: Is this function actually a thing?
inline void operator delete(void* ptr,
    csl::fnd::IAllocator* allocator, std::size_t alignment)
{
    allocator->Free(ptr);
}
