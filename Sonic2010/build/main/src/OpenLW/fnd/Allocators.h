#pragma once
#include "csl/fnd/memory.h"

namespace app
{
namespace fnd
{
// Wii U: 0x0219f9f0, PC: TODO
csl::fnd::IAllocator* GetTempAllocator();

// Wii U: 0x02185818, PC: 0x0048d510
csl::fnd::IAllocator* GetSingletonAllocator();

// Wii U: 0x0219fb7c, PC: TODO
csl::fnd::IAllocator* getDebugAllocator();
}
}
