// TODO: The name of this file is correct, but the path was guessed!
#include "Singleton.h"
#include "Memory/GlobalAllocator.h"
#include <csl/ut/array.h>

namespace app
{
namespace fnd
{
SingletonInitNode* SingletonInitNode::CurNode = nullptr;

void InitSingletons()
{
    csl::ut::InplaceMoveArray<SingletonInitNode*, 128> singletonInitNodes;
    SingletonInitNode** nodes = &SingletonInitNode::CurNode;
    SingletonInitNode* node = SingletonInitNode::CurNode;

    while (node)
    {
        if (*node->InstPtr == nullptr && node->Init)
        {
            void* inst = node->Init();
            if (inst)
            {
                *node->InstPtr = inst;
                nodes = &node->PrevNode;
                node = *nodes;
            }
            else
            {
                // TODO: Uncomment this line once no singleton functions return nullptr
                //singletonInitNodes.push_back(node);

                node = node->PrevNode;
                (*nodes)->PrevNode = nullptr;
                *nodes = node;
            }
        }
        else
        {
            nodes = &node->PrevNode;
            node = *nodes;
        }
    }

    while (!singletonInitNodes.empty())
    {
        for (auto it = singletonInitNodes.begin(); it != singletonInitNodes.end();)
        {
            SingletonInitNode* curNode = *it;
            void* inst = curNode->Init();

            if (!inst)
            {
                ++it;
                continue;
            }

            void** ppvVar3 = curNode->InstPtr;
            *nodes = curNode;
            nodes = &curNode->PrevNode;
            *ppvVar3 = inst;

            it = singletonInitNodes.erase(it);
        }
    }
}

void DestroySingletons()
{
    // Get all SingletonInitNodes.
    csl::ut::InplaceMoveArray<SingletonInitNode*, 128> singletonInitNodes;
    SingletonInitNode* node = SingletonInitNode::CurNode;

    while (node)
    {
        singletonInitNodes.push_back(node);
        node = node->PrevNode;
    }

    // Destroy all Singletons.
    for (auto it = singletonInitNodes.rbegin(); it != singletonInitNodes.rend(); it++)
    {
        SingletonInitNode* curNode = *it;
        if (curNode->Destroy && *curNode->InstPtr)
        {
            curNode->Destroy(*curNode->InstPtr);
            *curNode->InstPtr = nullptr;
        }
    }
}

csl::fnd::IAllocator* GetSingletonAllocator()
{
	return game::GlobalAllocator::GetAllocator(ALLOCATOR_UNK_TWO);
}
}
}
