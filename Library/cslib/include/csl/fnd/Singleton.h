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

    inline static void ReplaceInstance(T* inst) noexcept
    {
        if (instance) delete instance;
        instance = inst;
    }

    inline static bool IsInitialized() const noexcept
    {
        return (instance != nullptr);
    }
};

template <typename T>
T* Singleton<T>::instance;
}
}
