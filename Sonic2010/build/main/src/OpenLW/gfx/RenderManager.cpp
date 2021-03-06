#include "RenderManager.h"

#ifdef _WIN32
#include "../Platform/Win32/RenderManagerImplWin.h"
#endif

namespace app
{
namespace gfx
{
RenderManager::RenderManager()
{
    m_impl = new (this + 1) Impl(*this);
    // TODO
}

hh::mr::CRenderingInfrastructure* RenderManager::GetRenderingDevice() const
{
    return m_impl->RenderingInfrastructure.get();
}

void RenderManager::Setup(const SetupInfo& setupInfo)
{
    m_impl->Setup(setupInfo);
}

void RenderManager::RenderNoPresent()
{
    // TODO
    m_impl->RenderNoPresent();
}

void RenderManager::Render()
{
    RenderNoPresent();
    m_impl->Present();
}

void RenderManager::Present()
{
    m_impl->Present();
}

void RenderManager::Update(const fnd::SUpdateInfo& updateInfo, unsigned int param_2)
{
    m_impl->Update(updateInfo, param_2);
}

void RenderManager::Shutdown()
{
    m_impl->Shutdown();
}

RenderManager* RenderManager::Create(csl::fnd::IAllocator* allocator)
{
    void* buf = allocator->Alloc(sizeof(RenderManager) + sizeof(Impl));
    return new (buf, allocator, sizeof(RenderManager)) RenderManager();
}
}
}
