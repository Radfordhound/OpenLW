#include "Singleton.h"
#include "csl/ut/InplaceMoveArray.h"

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
            SingletonInitNode* psvar1 = *it;
            void* inst = psvar1->Init();

            if (!inst)
            {
                ++it;
                continue;
            }

            void** ppvVar3 = psvar1->InstPtr;
            *nodes = psvar1;
            nodes = &psvar1->PrevNode;
            *ppvVar3 = inst;

            it = singletonInitNodes.erase(it);
        }
    }
}

void DestroySingletons()
{
    // Get all SingletonInitNodes
    csl::ut::InplaceMoveArray<SingletonInitNode*, 128> singletonInitNodes;
    SingletonInitNode* node = SingletonInitNode::CurNode;
    
    while (node)
    {
        singletonInitNodes.push_back(node);
        node = node->PrevNode;
    }

    // Destroy all Singletons
    for (auto it = singletonInitNodes.rbegin(); it != singletonInitNodes.rend(); it++)
    {
        if ((*it)->Destroy && *(*it)->InstPtr)
        {
            (*it)->Destroy(*(*it)->InstPtr);
            *(*it)->InstPtr = nullptr;
        }
    }
}
}
}
