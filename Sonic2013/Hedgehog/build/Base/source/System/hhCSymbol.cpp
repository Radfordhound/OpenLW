#include "Hedgehog/Base/System/hhCSymbol.h"
#include <cstring>

namespace hh
{
namespace base
{
// Wii U: 0x1031f2c8, PC: TODO
static SSymbolNode* PTR_1031f2c8 = nullptr;

// Wii U: 0x1031f2cc, PC: TODO
static SSymbolNode DAT_1031f2cc = {};

bool IsSame(const SSymbolNode* node1, const SSymbolNode* node2)
{
    return (node1->field_0x8 == node2->field_0x8 &&
        std::strcmp(node1->Name(), node2->Name()) == 0);
}

bool IsUpper(const SSymbolNode* node1, const SSymbolNode* node2)
{
    if (node1->field_0x8 <= node2->field_0x8)
    {
        return (std::strcmp(node1->Name(), node2->Name()) > 0); // TODO: Is this correct??
        //return ((-iVar2 & static_cast<unsigned int>(~iVar2)) >> 31);
    }
    
    return true;
}

SSymbolNode* SymbolNodeInsert(SSymbolNode* node, SSymbolNode* childNode)
{
    if (IsUpper(childNode, node))
    {
        if (!node->field_0x0)
        {
            node->field_0x0 = childNode;
            return childNode;
        }

        return (IsSame(node->field_0x0, childNode)) ? node->field_0x0 :
            SymbolNodeInsert(node->field_0x0, childNode);
    }
    else
    {
        if (!node->field_0x4)
        {
            node->field_0x4 = childNode;
            return childNode;
        }

        return (IsSame(node->field_0x4, childNode)) ? node->field_0x4 :
            SymbolNodeInsert(node->field_0x4, childNode);
    }
}

SSymbolNode* AddToNode(SSymbolNode* node)
{
    if (!PTR_1031f2c8)
    {
        PTR_1031f2c8 = node;
        return node;
    }

    if (IsSame(node, PTR_1031f2c8))
    {
        return PTR_1031f2c8;
    }

    return SymbolNodeInsert(PTR_1031f2c8, node);
}

SSymbolNode* MakeStringSymbol(const char* param_1)
{
    std::size_t len = std::strlen(param_1);
    std::size_t uVar1 = ((len + 19) & 0xFFFFFFFCU); // Is this hex value okay on x64??

    // TODO

    // TODO

    return nullptr; // TODO: REMOVE THIS
}

const char* GetSetGlobalString(const char* param_1)
{
    return MakeStringSymbol(param_1)->Name();
}
}
}
