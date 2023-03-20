#include "pch.h"
#include "Hedgehog/Base/System/hhCSymbol.h"
#include "Hedgehog/Base/System/hhMemory.h"
#include "Hedgehog/Base/System/hhHash.h"
#include "Hedgehog/Base/hhBaseCommon.h"

namespace hh
{
namespace base
{
LWAPI(0x1031f2c8, TODO)
static SSymbolNode* PTR_1031f2c8 = nullptr;

LWAPI(0x1031f2cc, TODO)
static SSymbolNode* DAT_1031f2cc = nullptr;

LWAPI(0x1031f2d0, TODO)
static std::size_t DAT_1031f2d0 = 0;

LWAPI(0x1031f2d4, TODO)
static unsigned int DAT_1031f2d4 = 0;

bool IsSame(const SSymbolNode* node1, const SSymbolNode* node2)
{
    return (node1->Hash == node2->Hash &&
        std::strcmp(node1->Name(), node2->Name()) == 0);
}

bool IsUpper(const SSymbolNode* node1, const SSymbolNode* node2)
{
    if (node1->Hash <= node2->Hash)
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

    if (DAT_1031f2d0 < uVar1)
    {
        DAT_1031f2cc = static_cast<SSymbolNode*>(__HH_ALLOC_DBG(65536)); // Line: 514
        ++DAT_1031f2d4;
        DAT_1031f2d0 = 65536;
    }

    DAT_1031f2cc->field_0x4 = nullptr;
    DAT_1031f2cc->field_0x0 = nullptr;
    DAT_1031f2cc->Hash = hash_value_str(param_1);

    std::memcpy(DAT_1031f2cc->Name(), param_1, len + 1);

    SSymbolNode* local_r3_176 = AddToNode(DAT_1031f2cc);
    if (local_r3_176 == DAT_1031f2cc)
    {
        DAT_1031f2d0 -= uVar1;
        DAT_1031f2cc = PtrAdd<SSymbolNode>(DAT_1031f2cc, uVar1);
    }

    // TODO

    return local_r3_176;
}

char* GetSetGlobalString(const char* param_1)
{
    return MakeStringSymbol(param_1)->Name();
}
}
}
