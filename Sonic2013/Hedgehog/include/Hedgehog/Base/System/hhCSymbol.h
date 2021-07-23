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

// Wii U: 0x03698c04, PC: Inlined
bool IsSame(const SSymbolNode* node1, const SSymbolNode* node2);

// Wii U: 0x03698c5c, PC: Inlined
bool IsUpper(const SSymbolNode* node1, const SSymbolNode* node2);

// Wii U: 0x03698ca8, PC: 0x00c22680
SSymbolNode* SymbolNodeInsert(SSymbolNode* node, SSymbolNode* childNode);

// Wii U: 0x03698dc8, PC: 0x00c227b0
SSymbolNode* AddToNode(SSymbolNode* node);

// Wii U: 0x03698e64, PC: 0x00c22820
SSymbolNode* MakeStringSymbol(const char* param_1);

// Wii U: 0x03699054, PC: 0x00c22930
char* GetSetGlobalString(const char* param_1);
}
}
