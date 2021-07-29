#include "RenderManagerImpl.h"

namespace app
{
namespace gfx
{
RenderManager::Impl::Impl(RenderManager& renderMgr)
{
    // TODO
    SkipPresent = true;
    UpdatePtr = &Impl::Update_Init;
    // TODO
    RenderMgr = &renderMgr;
    // TODO

    JobJoint1 = hh::MTBase::hhMTSimpleJobJointStaticCreate(
        "m_evehtJointSchedulerHandle");

    JobJoint2 = hh::MTBase::hhMTSimpleJobJointStaticCreate(
        "m_evehtJointPostFrameHandle");

    // TODO
    RenderingInfrastructure.reset(new hh::mr::CRenderingInfrastructure());
    // TODO
}

void RenderManager::Impl::LoadShader()
{
    fnd::FileLoader* fileLoader = fnd::FileLoader::GetInstance();

    fnd::FileLoaderParam fileLoadParams;
    fileLoadParams.field_0xc = 0x1000;

    field_0xac = fileLoader->LoadFile(Info.ShaderName, fileLoadParams);
}

void RenderManager::Impl::Initialize()
{
    hh::gfx::GfxInitParam gfxInitParam =
    {
        0,
        RenderMgr->m_allocator,
        RenderingInfrastructure.get()
    };

    hh::gfx::GfxInit(gfxInitParam);

    // TODO
    LoadShader();
    // TODO
}

void RenderManager::Impl::Setup(const SetupInfo& setupInfo)
{
    Info = setupInfo;
    Initialize();
}

void RenderManager::Impl::Finalize()
{
    // TODO
}

void RenderManager::Impl::Shutdown()
{
    Finalize();
}

void RenderManager::Impl::Update(const fnd::SUpdateInfo& updateInfo, unsigned int param_2)
{
    // TODO
    (this->*UpdatePtr)(updateInfo, param_2); // TODO: This isn't correct!!
}

hh::ut::Packfile RenderManager::Impl::GetShaderFileResource() const
{
    fnd::ResourceManager* resMgr = fnd::ResourceManager::GetInstance();
    return hh::ut::Packfile(resMgr->Get<fnd::ResRawData>(Info.ShaderName).GetAddress());
}

void RenderManager::Impl::PrepareRenderSchedule()
{
    hh::MTBase::hhMTSimpleJobBlockUntilSignal(JobJoint1, 0);
    hh::MTBase::hhMTSimpleJobBlockUntilSignal(JobJoint2, 0);
}

void RenderManager::Impl::Update_RunOnRenderInternal(
    const fnd::SUpdateInfo& updateInfo, unsigned int param_2)
{
    // TODO
    PrepareRenderSchedule();
    // TODO
}

void RenderManager::Impl::RenderNoPresent()
{
    if (SkipPresent) return;

    Update_RunOnRenderInternal(UpdateInfo, Unknown1);
    // TODO
}

void RenderManager::Impl::Present()
{
    if (!SkipPresent)
    {
        RenderingInfrastructure->Present();
    }
}

bool RenderManager::Impl::SetupShader()
{
    fnd::FileLoader* fileLoader = fnd::FileLoader::GetInstance();
    if (fileLoader->IsSyncComplete(field_0xac))
    {
        fileLoader->WaitSync(field_0xac);

        hh::ut::Packfile shaderPac = GetShaderFileResource();
        shaderPac.Bind(RenderMgr->m_allocator, shaderPac);

        // TODO
        return true;
    }

    return false;
}

void RenderManager::Impl::Update_Init(const fnd::SUpdateInfo& updateInfo, unsigned int param_2)
{
    if (SetupShader())
    {
        // TODO
        UpdatePtr = &Impl::Update_Run;
    }
}

void RenderManager::Impl::Update_Run(const fnd::SUpdateInfo& updateInfo, unsigned int param_2)
{
    // TODO
    SkipPresent = false;
    // TODO
}
}
}
