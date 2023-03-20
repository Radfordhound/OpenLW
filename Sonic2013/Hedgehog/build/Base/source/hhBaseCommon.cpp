#include "pch.h"
#include "Hedgehog/Base/Platform/D3d9/hhBaseD3D9.h"

namespace hh
{
namespace base
{
LWAPI(0x104015b4, 0x011d701c)
static SInitializeHHBaseSetting BaseSetting;

SInitializeHHBaseSetting* GetHHBaseSetting()
{
    return &BaseSetting;
}

void InitializeHHBase(const SInitializeHHBaseSetting* baseSetting)
{
    BaseSetting = *baseSetting;
    InitializeHHD3D9(baseSetting);
}

void FinalizeHHBase()
{
    std::memset(&BaseSetting, 0, sizeof(BaseSetting));
}
}
}
