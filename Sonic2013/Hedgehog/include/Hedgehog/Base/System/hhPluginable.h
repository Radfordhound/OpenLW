#pragma once
#include "hhMemoryAllocator.h"

namespace hh
{
namespace base
{
template<typename T>
struct TPluginable0
{
    struct IFactory
    {
        virtual T* MakeInstance() = 0;
    };

    static IFactory* Factory;

    static IFactory* SetAbstractFactory(IFactory* factory)
    {
        IFactory* prevFactory = Factory;
        Factory = factory;
        return prevFactory;
    }

    template<typename T2>
    struct TSimpleFactory : IFactory
    {
        T* MakeInstance()
        {
            return new (__HH_DBG_INFO, hhGetHeapHandle(0)) T2(); // line: 30
        }
    };

    static T* MakeInstance()
    {
        return Factory->MakeInstance();
    }
};

template<typename T>
typename TPluginable0<T>::IFactory* TPluginable0<T>::Factory = nullptr;

template<typename T, typename arg1>
struct TPluginable1
{
    struct IFactory
    {
        virtual T* MakeInstance(arg1 param_1) = 0;
    };

    static IFactory* Factory;

    static IFactory* SetAbstractFactory(IFactory* factory)
    {
        IFactory* prevFactory = Factory;
        Factory = factory;
        return prevFactory;
    }

    static T* MakeInstance(arg1 param_1)
    {
        return Factory->MakeInstance(param_1);
    }

    template<typename T2>
    struct TSimpleFactory : IFactory
    {
        T* MakeInstance(arg1 param_1)
        {
            return new (__HH_DBG_INFO, hhGetHeapHandle(0)) T2(param_1); // line: 115
        }
    };
};

template<typename T, typename arg1>
typename TPluginable1<T, arg1>::IFactory* TPluginable1<T, arg1>::Factory = nullptr;
}
}
