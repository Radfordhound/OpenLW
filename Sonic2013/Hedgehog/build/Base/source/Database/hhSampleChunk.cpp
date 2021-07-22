#include "Hedgehog/Base/Database/hhSampleChunk.h"

namespace hh
{
namespace db
{
void CSampleChunkResource::ResolvePointer()
{
    u32* curOffAddr = PtrAdd<u32>(this, HH_ENDIAN_FIX_U32(m_offsetTableOff));
    u32* offTable = (curOffAddr + 1);
    u32* data = GetData<u32>();
    u32 offCount = HH_ENDIAN_FIX_U32(*curOffAddr);

    for (u32 i = 0; i < offCount; ++i)
    {
        // Get the current offset address.
        curOffAddr = &offTable[i];

        // "Fix" the current offset.
#if UINTPTR_MAX > UINT32_MAX
        Off32<void>* curOff = PtrAdd<Off32<void>>(data, (*curOffAddr + 0xFFFFFFFCU));
        curOff->set(PtrAdd<void>(data, curOff->get_val()));
#else
        *PtrAdd<u32>(data, (*curOffAddr + 0xFFFFFFFCU)) +=
            reinterpret_cast<u32>(data);
#endif
    }
}
}
}
