#pragma once
#include "csl/fnd/IAllocator.h"

namespace app
{
namespace fnd
{
/* <b>Wii U: 0x0219f9f0, PC: TODO</b> */
csl::fnd::IAllocator* GetTempAllocator();

/* <b>Wii U: 0x02185818, PC: TODO</b> */
csl::fnd::IAllocator* GetSingletonAllocator();

/* <b>Wii U: 0x0219fb7c, PC: TODO</b> */
csl::fnd::IAllocator* getDebugAllocator();
}
}
