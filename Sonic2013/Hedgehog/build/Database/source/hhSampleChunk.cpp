#include "Hedgehog/Database/hhSampleChunk.h"

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
        Off32<void>* curOff = PtrAdd<Off32<void>>(data,
            (HH_ENDIAN_FIX_U32(*curOffAddr) & 0xFFFFFFFCU));

        curOff->set(PtrAdd<void>(data, HH_ENDIAN_FIX_U32(curOff->get_val())));
#else
        u32* curOff = PtrAdd<u32>(data, (HH_ENDIAN_FIX_U32(*curOffAddr) & 0xFFFFFFFCU));
        *curOff = (HH_ENDIAN_FIX_U32(*curOff) + reinterpret_cast<u32>(data));
#endif
    }
}
}
}
