// TODO: Both the name of this file and its path were guessed!
#pragma once
namespace csl
{
namespace fnd
{
template<typename T>
class Singleton
{
OPENLW_PROTECTED
    static T* m_instance;
    inline Singleton() {};

public:
    inline static T& GetInstance()
    {
        return *m_instance;
    }

    inline static void ReplaceInstance(T* inst)
    {
        if (m_instance) delete m_instance;
        m_instance = inst;
    }

    inline static bool IsInitialized()
    {
        return (m_instance != nullptr);
    }
};

template<typename T>
T* Singleton<T>::m_instance;
} // fnd
} // csl
