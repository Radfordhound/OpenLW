// TODO: The name of this file is correct, but the path was guessed!
#include "pch.h"
#include "gfx_ResourceCallback.h"
#include "RenderManager.h"

namespace app
{
namespace gfx
{
void GfxResourceCallback::SetupCallback(hh::ut::Packfile pac,
    csl::fnd::IAllocator* allocator)
{
    pac.Bind(allocator, pac);
    
    RenderManager& renderMgr = RenderManager::GetInstance();
    pac.Bind(allocator, renderMgr.GetShaderFileResource());
}

void GfxResourceCallback::CleanupCallback(hh::ut::Packfile pac) {}

GfxResourceCallback::GfxResourceCallback(csl::fnd::IAllocator* allocator) :
    ResourceCallbackBase(1, allocator) {}

GfxResourceCallback::~GfxResourceCallback() {}
}
}
