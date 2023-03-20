// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include "System/Resource/ResourceCallbackBase.h"

namespace app
{
namespace gfx
{
struct GfxResourceCallback : public fnd::ResourceCallbackBase // TODO: Also inherit from hh::gfx::GfxObject
{
    LWAPI(0x02256638, TODO)
    void SetupCallback(hh::ut::Packfile pac, csl::fnd::IAllocator* allocator);

    LWAPI(0x022566ac, TODO)
    void CleanupCallback(hh::ut::Packfile pac);

    LWAPI(0x022566b0, TODO)
    GfxResourceCallback(csl::fnd::IAllocator* allocator);

    LWAPI(0x02256148, TODO)
    ~GfxResourceCallback();
};
}
}
