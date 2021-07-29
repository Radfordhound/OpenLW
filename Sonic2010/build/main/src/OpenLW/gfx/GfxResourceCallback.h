#pragma once
#include "../fnd/ResourceCallbackBase.h"

namespace app
{
namespace gfx
{
struct GfxResourceCallback : public fnd::ResourceCallbackBase // TODO: Also inherit from hh::gfx::GfxObject
{
    // Wii U: 0x02256638, PC: TODO
    void SetupCallback(hh::ut::Packfile pac, csl::fnd::IAllocator* allocator);

    // Wii U: 0x022566ac, PC: TODO
    void CleanupCallback(hh::ut::Packfile pac);

    // Wii U: 0x022566b0, PC: TODO
    GfxResourceCallback(csl::fnd::IAllocator* allocator);

    // Wii U: 0x02256148 (THUNK), PC: TODO
    ~GfxResourceCallback();
};
}
}
