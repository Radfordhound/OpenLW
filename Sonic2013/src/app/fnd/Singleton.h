#pragma once
#include "csl/fnd/Singleton.h"

#define DECLARE_SINGLETON_INIT static fnd::SingletonInitNode singletonInitNode;
#define DEFINE_SINGLETON_INIT(type) fnd::SingletonInitNode type::singletonInitNode = \
    fnd::SingletonInitNode(type##_init, type##_destroy, reinterpret_cast<void**>(&instance))

namespace app
{
namespace fnd
{
struct SingletonInitNode
{
    void* (*Init)();
    void (*Destroy)(void* ptr);
    SingletonInitNode* PrevNode;
    void** InstPtr;

    /* <b>Wii U: 0x102e78f0, PC: 0x00fd4218</b> */
    static SingletonInitNode* CurNode;

    inline SingletonInitNode() = default;
    inline SingletonInitNode(void* (*init)(),
        void (*destroy)(void* ptr), void** instPtr) : PrevNode(CurNode)
    {
        CurNode = this;
        Init = init;
        Destroy = destroy;
        InstPtr = instPtr;
    }
};

void InitSingletons();
}
}
