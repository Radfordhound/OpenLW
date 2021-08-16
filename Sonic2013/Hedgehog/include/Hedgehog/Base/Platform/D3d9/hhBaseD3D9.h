#pragma once
#include "../../hhBaseCommon.h"

namespace hh
{
namespace base
{
// Wii U: 0x03696dcc, PC: TODO
void InitializeHHD3D9(const SInitializeHHBaseSetting* baseSetting);

// Wii U: 0x03696ecc, PC: TODO
void FinalizeHHD3D9();
}
}
