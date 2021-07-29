#include "RenderManagerImpl.h"
#include "../fnd/ResourceManager.h"
#include <Hedgehog/Graphics/hhGraphics.h>
#include <Hedgehog/Graphics/Resource/hhResShaderAc.h>

using namespace app::fnd;
using namespace hh::mr;
using namespace hh::ut;
using namespace hh::gfx;
using namespace hh::gfx::res;
using namespace hh::MTBase;

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

    JobJoint1 = hhMTSimpleJobJointStaticCreate("m_evehtJointSchedulerHandle");
    JobJoint2 = hhMTSimpleJobJointStaticCreate("m_evehtJointPostFrameHandle");

    // TODO
    RenderingInfrastructure.reset(new CRenderingInfrastructure());
    // TODO
}

void RenderManager::Impl::LoadShader()
{
    FileLoader* fileLoader = FileLoader::GetInstance();

    FileLoaderParam fileLoadParams;
    fileLoadParams.field_0xc = 0x1000;

    field_0xac = fileLoader->LoadFile(Info.ShaderName, fileLoadParams);
}

void RenderManager::Impl::Initialize()
{
    GfxInitParam gfxInitParam =
    {
        0,
        RenderMgr->m_allocator,
        RenderingInfrastructure.get()
    };

    GfxInit(gfxInitParam);

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
    ResourceManager* resMgr = ResourceManager::GetInstance();
    return Packfile(resMgr->Get<ResRawData>(Info.ShaderName).GetAddress());
}

void RenderManager::Impl::PrepareRenderSchedule()
{
    hhMTSimpleJobBlockUntilSignal(JobJoint1, 0);
    hhMTSimpleJobBlockUntilSignal(JobJoint2, 0);
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
    FileLoader* fileLoader = FileLoader::GetInstance();
    if (fileLoader->IsSyncComplete(field_0xac))
    {
        fileLoader->WaitSync(field_0xac);

        Packfile shaderPac = GetShaderFileResource();
        shaderPac.Bind(RenderMgr->m_allocator, shaderPac);

        for (std::size_t i = 0; i < shaderPac.GetCount<ResShader>(); ++i)
        {
            ResShader shader = shaderPac.Get<ResShader>(i);
            if (shader.IsValid())
            {
                shader.FinalInitialization();
            }
        }

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
