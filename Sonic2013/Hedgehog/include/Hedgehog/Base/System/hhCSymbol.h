#pragma once
#include <cstddef>

namespace hh
{
namespace base
{
struct SSymbolNode
{
    SSymbolNode* field_0x0;
    SSymbolNode* field_0x4;
    std::size_t Hash;

    // TODO: Is this function a thing?
    inline const char* Name() const
    {
        return reinterpret_cast<const char*>(this + 1);
    }

    // TODO: Is this function a thing?
    inline char* Name()
    {
        return reinterpret_cast<char*>(this + 1);
    }
};

LWAPI(0x03698c04, NONE)
bool IsSame(const SSymbolNode* node1, const SSymbolNode* node2);

LWAPI(0x03698c5c, NONE)
bool IsUpper(const SSymbolNode* node1, const SSymbolNode* node2);

LWAPI(0x03698ca8, 0x00c22680)
SSymbolNode* SymbolNodeInsert(SSymbolNode* node, SSymbolNode* childNode);

LWAPI(0x03698dc8, 0x00c227b0)
SSymbolNode* AddToNode(SSymbolNode* node);

LWAPI(0x03698e64, 0x00c22820)
SSymbolNode* MakeStringSymbol(const char* param_1);

LWAPI(0x03699054, 0x00c22930)
char* GetSetGlobalString(const char* param_1);

class CStringSymbol
{
    SSymbolNode* field_0x0;

public:
    CStringSymbol(const char* str) :
        field_0x0(MakeStringSymbol(str)) {}

    inline bool operator<(const CStringSymbol& other) const
    {
        return (field_0x0 < other.field_0x0); // TODO: Is this correct?
    }
};
}
}
