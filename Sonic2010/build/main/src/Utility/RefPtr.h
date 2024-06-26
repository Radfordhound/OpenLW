// TODO: Both the name of this file and its path were guessed!
#pragma once

namespace app
{
namespace ut
{
template<typename T>
class RefPtr
{
OPENLW_PRIVATE
    T* m_refObjPtr;

public:
    const T* get() const
    {
        return m_refObjPtr;
    }

    T* get()
    {
        return m_refObjPtr;
    }

    void reset()
    {
        if (m_refObjPtr)
        {
            m_refObjPtr->Release();
        }
        
        m_refObjPtr = nullptr;
    }

    void reset(T* refObjPtr)
    {
        if (refObjPtr)
        {
            refObjPtr->AddRef();
        }

        const auto oldRefObjPtr = m_refObjPtr;
        m_refObjPtr = refObjPtr;

        if (oldRefObjPtr)
        {
            oldRefObjPtr->Release();
        }
    }

    const T* operator->() const
    {
        return m_refObjPtr;
    }

    T* operator->()
    {
        return m_refObjPtr;
    }

    RefPtr<T>& operator=(T* refObjPtr)
    {
        if (refObjPtr)
        {
            refObjPtr->AddRef();
        }

        if (m_refObjPtr)
        {
            m_refObjPtr->Release();
        }

        m_refObjPtr = refObjPtr;
        return *this;
    }

    operator bool() const
    {
        return (m_refObjPtr != nullptr);
    }

	RefPtr() :
		m_refObjPtr(nullptr) {}

    RefPtr(T* refObjPtr, bool addRef = true) :
		m_refObjPtr(refObjPtr)
    {
        if (refObjPtr && addRef)
        {
            refObjPtr->AddRef();
        }
    }

    ~RefPtr()
    {
        if (m_refObjPtr)
        {
            m_refObjPtr->Release();
        }
    }
};
} // ut
} // app
