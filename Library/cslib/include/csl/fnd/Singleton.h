#pragma once
namespace csl
{
namespace fnd
{
template<typename T>
class Singleton
{
protected:
    static T* instance;
    inline Singleton() {};

public:
    inline static T* GetInstance() noexcept
    {
        return instance;
    }

    inline void ReplaceInstance(T* inst) noexcept
    {
        if (instance) delete instance;
        instance = inst;
    }
};

template <typename T>
T* Singleton<T>::instance;
}
}
