#include "pch.h"
#include "LWAPI.h"

namespace lwapi
{
namespace detail
{
PatchLinkedListNode* PatchLinkedListNode::_begin = nullptr;
}

void ApplyPatches()
{
    auto curPatch = detail::PatchLinkedListNode::Begin();
    while (curPatch)
    {
        curPatch->Install();
        curPatch = curPatch->Next();
    }
}
}

