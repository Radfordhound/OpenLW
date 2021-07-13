#pragma once
#include <csl/fnd/singleton.h>

#define DECLARE_SINGLETON static ::app::fnd::SingletonInitNode __singletonInitNode;

#define DEFINE_SINGLETON(type, initFunc, destroyFunc)\
    ::app::fnd::SingletonInitNode type::__singletonInitNode = \
    fnd::SingletonInitNode(initFunc, destroyFunc, (void**)(&m_instance))

namespace app
{
namespace fnd
{
typedef void* (*SingletonInitFunc)();
typedef void (*SingletonDestroyFunc)(void* singleton);

struct SingletonInitNode
{
    SingletonInitFunc Init;
    SingletonDestroyFunc Destroy;
    SingletonInitNode* PrevNode;
    void** InstPtr;

    // Wii U: 0x102e78f0, PC: 0x00fd4218
    static SingletonInitNode* CurNode;

	SingletonInitNode() {}

    SingletonInitNode(SingletonInitFunc initPtr,
        SingletonDestroyFunc destroyPtr, void** instPtr) :
        PrevNode(CurNode)
    {
        CurNode = this;
        Init = initPtr;
        Destroy = destroyPtr;
        InstPtr = instPtr;
    }
};

// Wii U: 0x02185574, PC: 0x0048d520
void InitSingletons();

// Wii U: 0x0218570c, PC: 0x0048d6c0
void DestroySingletons();
}
}
