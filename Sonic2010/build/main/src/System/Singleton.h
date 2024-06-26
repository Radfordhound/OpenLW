// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include <csl/fnd/singleton.h>
#include <csl/fnd/memory.h>

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

    LWAPI(0x102e78f0, 0x00fd4218)
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

LWAPI(0x02185574, 0x0048d520)
void InitSingletons();

LWAPI(0x0218570c, 0x0048d6c0)
void DestroySingletons();

LWAPI(0x02185818, 0x0048d510)
csl::fnd::IAllocator* GetSingletonAllocator();
} // fnd
} // app
