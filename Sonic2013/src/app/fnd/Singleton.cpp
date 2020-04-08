#include "Singleton.h"

namespace app
{
namespace fnd
{
SingletonInitNode* SingletonInitNode::CurNode = nullptr;

void InitSingletons()
{
    if (SingletonInitNode::CurNode)
    {
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
                    // TODO
                    nodes = &node->PrevNode;
                    node = *nodes;
                }
                else
                {
                    // TODO

                    node = node->PrevNode;
                    (*nodes)->PrevNode = nullptr;
                    *nodes = node;
                    // TODO
                }
            }
            else
            {
                nodes = &node->PrevNode;
                node = *nodes;
            }
        }

        // TODO
    }

    // TODO
}
}
}
