#include "Hedgehog/Base/Platform/D3d9/hhBaseD3D9.h"
#include <cstring>

namespace hh
{
namespace base
{
// Wii U: 0x104015b4, PC: 0x011d701c
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
