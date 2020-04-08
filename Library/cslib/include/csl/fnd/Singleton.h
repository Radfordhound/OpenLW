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
};

template <typename T>
T* Singleton<T>::instance;
}
}
