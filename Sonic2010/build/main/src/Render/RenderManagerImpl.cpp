#include "OpenLW/pch.h"
#include "RenderManagerImpl.h"
#include "System/Resource/ResourceManager.h"
#include <Hedgehog/Graphics/hhGraphics.h>
#include <Hedgehog/Graphics/Resource/hhResShaderAc.h>
#include <Extra/Util/hhGPUInstanceMapper.h>
#include <Extra/Util/hhRenderParam.h>
#include <boost/bind.hpp>

#include <Hedgehog/Rsdx/System/RsdxThread.h> // TODO: REMOVE THIS

using namespace app::fnd;
using namespace hh::mr;
using namespace hh::ut;
using namespace hh::gfx;
using namespace hh::gfx::res;
using namespace hh::MTBase;
using namespace Extra::fx;

LWAPI(0x022570c0, TODO)
void DummyJointJob(void* param_1) {}

namespace app
{
namespace gfx
{
void RenderManager::Impl::WaitJoint()
{
    hhMTSimpleJobBlockUntilSignal(m_evehtJointSchedulerHandle, 0);
    hhMTSimpleJobBlockUntilSignal(m_evehtJointPostFrameHandle, 0);

    if (!HasRenderSchedule())
    {
        hhMTSimpleJobJointUnlock(m_MTRenderableUpJoint);
    }

    hhMTSimpleJobBlockUntilSignal(m_MTRenderableUpJoint, 0);

    if (!HasRenderSchedule())
    {
        hhMTSimpleJobJointLock(m_MTRenderableUpJoint);
    }

    hhMTSimpleJobJointUnlock(m_evehtJointHandle);
    hhMTSimpleJobBlockUntilSignal(m_evehtJointHandle, 0);
    hhMTSimpleJobJointLock(m_evehtJointHandle);
}

void RenderManager::Impl::WaitUntilNotbusy()
{
    WaitJoint();
}

void RenderManager::Impl::LockWorkerJoint()
{
    hhMTSimpleJobJointLock(m_evehtJointHandle);
    hhMTSimpleJobJointLock(m_MTRenderableUpJoint);
}

std::size_t RenderManager::Impl::EntryRenderScheduler(IRenderScheduler* scheduler)
{
    for (std::size_t i = 0; i < HH_COUNT_OF(RenderSchedulers); ++i)
    {
        if (!RenderSchedulers[i])
        {
            RenderSchedulers[i] = scheduler;
            return (i + 1);
        }
    }

    return 0;
}

RenderManager::Impl::Impl(RenderManager& renderMgr) :
    // TODO
    SkipPresent(true),
    UpdatePtr(&Impl::Update_Init),
    // TODO
    RenderMgr(&renderMgr),
    // TODO
    m_evehtJointHandle(hhMTSimpleJobJointStaticCreate("m_evehtJointHandle")),
    m_MTRenderableUpJoint(hhMTSimpleJobJointStaticCreate()),
    m_evehtJointSchedulerHandle(hhMTSimpleJobJointStaticCreate("m_evehtJointSchedulerHandle")),
    m_evehtJointPostFrameHandle(hhMTSimpleJobJointStaticCreate("m_evehtJointPostFrameHandle")),
    // TODO
    DefaultSceneView(new (&field_0xe0) CRMSceneViewImpl(), false),
    // TODO
    RenderSchedulers()
    // TODO
{
    // TODO
    RenderingInfrastructure.reset(new CRenderingInfrastructure());
    // TODO
    LockWorkerJoint();
    // TODO
    EntryRenderScheduler(&field_0xe0);
}

void RenderManager::Impl::LoadShader()
{
    FileLoader& fileLoader = FileLoader::GetInstance();

    FileLoaderParam fileLoadParams;
    fileLoadParams.field_0xc = 0x1000;

    field_0xac = fileLoader.LoadFile(Info.ShaderName, fileLoadParams);
}

void RenderManager::Impl::Initialize()
{
    // Initialize Hedgehog Engine Graphics module.
    GfxInitParam gfxInitParam =
    {
        0,
        RenderMgr->m_allocator,
        RenderingInfrastructure.get()
    };

    GfxInit(gfxInitParam);

    // Allocate "stack" memory.
    const std::size_t stackSize = 0x800000;
    StackSize = stackSize;
    StackMemory = RenderMgr->m_allocator->Alloc(stackSize, 128);

    // TODO

    ScratchBuffer.Allocator.field_0x0 = nullptr;
    ScratchBuffer.Allocator.Top = nullptr;

    // TODO
    LoadShader();
    // TODO

    field_0xe0.Initialize(RenderMgr->m_allocator,
        RenderingInfrastructure.get(),
        StackMemory, StackSize);
}

void RenderManager::Impl::Setup(const SetupInfo& setupInfo)
{
    Info = setupInfo;
    Initialize();
}

void RenderManager::Impl::Finalize()
{
    // TODO

    if (StackMemory)
    {
        RenderMgr->m_allocator->Free(StackMemory);
    }

    StackMemory = nullptr;
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
    ResourceManager& resMgr = ResourceManager::GetInstance();
    return Packfile(resMgr.Get<ResRawData>(Info.ShaderName).GetAddress());
}

void RenderManager::Impl::PrepareRenderSchedule()
{
    hhMTSimpleJobBlockUntilSignal(m_evehtJointSchedulerHandle, 0);
    hhMTSimpleJobBlockUntilSignal(m_evehtJointPostFrameHandle, 0);
}

void RenderManager::Impl::Update_RunOnRenderInternal(
    const fnd::SUpdateInfo& updateInfo, unsigned int param_2)
{
    // TODO
    PrepareRenderSchedule();

    // TODO

    ScratchBuffer.Allocator.field_0x0 = StackMemory;
    ScratchBuffer.Allocator.Top = StackMemory;

    // TODO

    // Get scene views.
    CRenderSceneViewImpl** sceneViews = static_cast<CRenderSceneViewImpl**>(
        ScratchBuffer.Allocator.AllocateMemory(sizeof(CRenderSceneViewImpl*) * 3));

    std::size_t sceneViewCount = 0;

    for (std::size_t i = 0; i < 3; ++i)
    {
        if (RenderSchedulers[i])
        {
            CRenderSceneViewImpl* sceneView = RenderSchedulers[i]->GetSceneView();
            if (sceneView)
            {
                sceneViews[sceneViewCount++] = sceneView;
            }
        }
    }

    // Get group start end pairs.
    SGroupStartEndPair* pSVar4 = static_cast<SGroupStartEndPair*>(
        ScratchBuffer.Allocator.AllocateMemory(sizeof(SGroupStartEndPair) *
            sceneViewCount * 2));

    for (std::size_t i = 0; i < sceneViewCount; ++i)
    {
        sceneViews[i]->StartRenderContainerOne(updateInfo, param_2,
            &ScratchBuffer, field_0x68.get(), GetCommonResource());
    }

    SJobJoint* jointAfterPostTraverse = hhMTSimpleJobJointDynamicCreate("jointAfterPostTraverse");
    hhMTSimpleJobJointLock(jointAfterPostTraverse);
    
    // TODO

    SJobJoint* pSVar7 = m_evehtJointHandle;
    if (!pSVar7)
    {
        pSVar7 = hhMTSimpleJobJointDynamicCreate();
    }

    hhMTSimpleJobJointLock(pSVar7);

    // TODO

    SJobJoint* local_r30_1692 = m_MTRenderableUpJoint;
    if (!local_r30_1692)
    {
        local_r30_1692 = hhMTSimpleJobJointDynamicCreate();
    }

    hhMTSimpleJobJointLock(local_r30_1692);

    SJobJoint* jointAfterCullNoNear = hhMTSimpleJobJointDynamicCreate("jointAfterCullNoNear");
    hhMTSimpleJobJointLock(jointAfterCullNoNear);
    hhMTSimpleJobJointUnlock(m_MTRenderableUpJoint);

    SJobJoint* jointAfterTraverse = hhMTSimpleJobJointDynamicCreate("jointAfterTraverse");
    hhMTSimpleJobJointLock(jointAfterTraverse);

    SJobJoint* jointAfterTransform = hhMTSimpleJobJointDynamicCreate("jointAfterTransform");
    hhMTSimpleJobJointLock(jointAfterTransform);

    SJobJoint* jointAfterGazePointFrustum = m_evehtJointSchedulerHandle;
    if (!jointAfterGazePointFrustum)
    {
        jointAfterGazePointFrustum = hhMTSimpleJobJointDynamicCreate(
            "jointAfterGazePointFrustum");
    }

    hhMTSimpleJobJointLock(jointAfterGazePointFrustum);

    SJobJoint* jointPreFinish = hhMTSimpleJobJointDynamicCreate("jointPreFinish");
    hhMTSimpleJobJointLock(jointPreFinish);

    for (std::size_t i = 0; i < sceneViewCount; ++i)
    {
        hhMTSimpleJobFunction(boost::bind(&CRenderSceneViewImpl::CollectCalcModelNodeDrawInfoFull,
            sceneViews[i]), SMTUpdateHint(0, jointAfterTraverse, jointAfterPostTraverse));

        hhMTSimpleJobFunction2(boost::bind(&CRenderSceneViewImpl::CalcModeNodeVolumeMask,
            sceneViews[i], _1, _2), 8, SMTUpdateHint(0, jointAfterTransform,
            jointAfterTraverse, "CalcModeNodeVolumeMask"));

        hhMTSimpleJobFunction(boost::bind(&CRenderSceneViewImpl::CalcGazePointAndDrawingFrustum,
            sceneViews[i]), SMTUpdateHint(0, jointAfterGazePointFrustum,
            jointAfterTransform, "CalcGazePointAndDrawingFrustum"));
        
        hhMTSimpleJobFunction2(boost::bind(&CRenderSceneViewImpl::CalcModeNodeCullingMask,
            sceneViews[i], _1, _2), 8, SMTUpdateHint(0, local_r30_1692,
            jointAfterGazePointFrustum, "CalcModeNodeCullingMask"));
    }

    SJobJoint* jointAfterCullingPre = hhMTSimpleJobJointDynamicCreate("jointAfterCullingPre");
    hhMTSimpleJobJointLock(jointAfterCullingPre);

    for (std::size_t i = 0; i < sceneViewCount; ++i)
    {
        hhMTSimpleJobFunction2(boost::bind(&CRenderSceneViewImpl::CalcModeNodeCullingMaskNoNear,
            sceneViews[i], _1, _2), 8, SMTUpdateHint(1, jointAfterCullingPre,
            jointAfterPostTraverse, "CalcModeNodeCullingMaskNoNear"));
    }

    hhMTSimpleJobFunction(boost::bind(&CRenderSceneViewImpl::Update_ComamndBufferPre,
        sceneViews, sceneViewCount, pSVar4, 2, SMTUpdateHint(2, jointPreFinish, nullptr,
        "Update_ComamndBufferPre")), SMTUpdateHint(1, local_r30_1692, jointAfterCullingPre));

    hhMTSimpleJobJointUnlock(jointAfterCullingPre);

    hhMTSimpleJobFunction(boost::bind(&CRenderSceneViewImpl::Update_ComamndBuffer,
        sceneViews, sceneViewCount, pSVar4 + 1, 2, SMTUpdateHint(2, jointPreFinish)),
        SMTUpdateHint(0, jointPreFinish, local_r30_1692, "Update_ComamndBuffer"));

    hhMTSimpleJobFunction(boost::bind(&Impl::Update_BufferFixup, this, sceneViews,
        sceneViewCount, pSVar4, 2, SMTUpdateHint(0, pSVar7)),
        SMTUpdateHint(0, pSVar7, jointPreFinish, "Update_BufferFixup"));

    for (std::size_t i = 0; i < sceneViewCount; ++i)
    {
        hhMTSimpleJobFunction(boost::bind(&CRenderSceneViewImpl::Update_PrimitiveRenderable,
            sceneViews[i]), SMTUpdateHint(2, pSVar7));
    }

    hhMTSimpleJobJointUnlock(jointPreFinish); // TODO: This is supposed to be 5 and 4 before this unlock.
    hhMTSimpleJobJointUnlock(jointAfterGazePointFrustum); // TODO: This is supposed to be 3 and 2 before this unlock.
    hhMTSimpleJobJointUnlock(jointAfterTransform);
    hhMTSimpleJobJointUnlock(jointAfterTraverse);
    hhMTSimpleJobJointUnlock(jointAfterCullNoNear);
    hhMTSimpleJobJointUnlock(local_r30_1692); // TODO: This is supposed to be 19 and 10 before this unlock.
    hhMTSimpleJobJointUnlock(pSVar7); // TODO: This is supposed to be 5 and 4 before this unlock.
    hhMTSimpleJobJointUnlock(jointAfterPostTraverse); // TODO: This is supposed to be 1 and 1 before this unlock.
}

void RenderManager::Impl::InitUpdated()
{
    Unknown1 = 0;
    UpdateInfo = SUpdateInfo();
}

void RenderManager::Impl::PrepareRenderOne()
{
    // TODO
}

void RenderManager::Impl::RenderNoPresent()
{
    if (SkipPresent) return;

    Update_RunOnRenderInternal(UpdateInfo, Unknown1);
    InitUpdated();

    // TODO

    CMTJobJointEntity CVar16 = hhMTSimpleJobJointStaticCreate();
    if (!CVar16)
    {
        CVar16 = hhMTSimpleJobJointDynamicCreate();
    }

    CVar16.Lock();

    CMTJobJointEntity* local_1250[64];
    std::size_t uVar13 = 1;

    local_1250[0] = &m_evehtJointHandle;

    for (std::size_t i = 0; i < 3; ++i)
    {
        if (RenderSchedulers[i])
        {
            CRenderSceneViewImpl* sceneView = RenderSchedulers[i]->GetSceneView();
            if (sceneView)
            {
                // TODO
            }
        }
    }

    for (std::size_t i = 0; i < uVar13; ++i)
    {
        local_1250[i]->Lock();
    }

    for (std::size_t i = 0; i < uVar13; ++i)
    {
        SJobType256* job = hhMTSimpleJobCreateDefault();
        job->JobExecParam.JobExecFunc = &DummyJointJob;

        hhMTSimpleJobBind(job, CVar16);
        hhMTSimpleJobLinkNext(job, *local_1250[i], 0);
    }

    for (std::size_t i = 0; i < uVar13; ++i)
    {
        local_1250[i]->Unlock();
    }

    PrepareRenderSchedule();
    RenderingInfrastructure->BeginScene();

    // TODO

    SRenderDevice device =
    {
        RenderingInfrastructure.get(),
        RenderingInfrastructure->GetDevice()
    };

    uVar13 = 0;

    // TODO

    SRenderParamInitializeParameter aSStack4432[64];
    for (std::size_t i = 0; i < 3; ++i)
    {
        if (RenderSchedulers[i])
        {
            uVar13 += RenderSchedulers[i]->OnRenderInitializeParameter(
                aSStack4432 + uVar13, sizeof(*aSStack4432) - uVar13);
        }
    }

    // TODO

    field_0xc = 0;
    RenderScheduled(aSStack4432, uVar13, &device, &m_evehtJointHandle, &CVar16);
    RenderingInfrastructure->EndScene();

    SJobJoint* pSVar17 = m_evehtJointPostFrameHandle;
    if (!pSVar17)
    {
        pSVar17 = hhMTSimpleJobJointDynamicCreate();
    }

    hhMTSimpleJobJointLock(pSVar17);

    // TODO
    
    for (std::size_t i = 0; i < 3; ++i)
    {
        if (RenderSchedulers[i])
        {
            CRenderSceneViewImpl* sceneView = RenderSchedulers[i]->GetSceneView();
            if (sceneView)
            {
                hhMTSimpleJobFunction(boost::bind(
                    &CRenderSceneViewImpl::Update_FrameEndRenderContainerOne,
                    sceneView), SMTUpdateHint(0, pSVar17));
            }
        }
    }

    hhMTSimpleJobJointUnlock(pSVar17);
    hhMTSimpleJobJointLock(m_MTRenderableUpJoint);
    EndRenderSchedule();
    hhMTSimpleJobJointUnlock(CVar16);
    //CVar16.BlockUntilSignal(); // TODO: Un-comment this line
    hhMTSimpleJobJointRelease(CVar16);

    // TODO: This line of code isn't in the original game but removing it causes a sort of memory leak. Block like the original game does and remove this!
    hh::rsdx::RsdxThreadSleep(250);
}

void RenderManager::Impl::Present()
{
    if (!SkipPresent)
    {
        RenderingInfrastructure->Present();
    }
}

RenderManager::Impl::~Impl()
{
    PrepareRenderOne();

    // TODO

    field_0xe0.Finalize();

    // TODO
}

bool RenderManager::Impl::SetupShader()
{
    FileLoader& fileLoader = FileLoader::GetInstance();
    if (fileLoader.IsSyncComplete(field_0xac))
    {
        fileLoader.WaitSync(field_0xac);

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

        field_0xd4 = new (RenderMgr->m_allocator) GfxResourceCallback(RenderMgr->m_allocator);
        ResourceManager::GetInstance().AddCallback(field_0xd4.get(), 0);

        // TODO
        return true;
    }

    return false;
}

void RenderManager::Impl::Update_Init(const fnd::SUpdateInfo& updateInfo, unsigned int param_2)
{
    if (SetupShader())
    {
        // Setup Render Scene View.
        Packfile shaderPac = GetShaderFileResource();
        field_0xe0.Setup(shaderPac, RenderingInfrastructure.get());

        UpdatePtr = &Impl::Update_Run; // TODO: The other stuff above/below this line is just weird Wii U function pointer stuff generated from this line, right?
    }
}

void RenderManager::Impl::Update_Run(const fnd::SUpdateInfo& updateInfo, unsigned int param_2)
{
    Unknown1 = param_2;
    UpdateInfo = updateInfo;
    SkipPresent = false;
}

void RenderManager::Impl::Update_BufferFixup(CRenderSceneViewImpl** param_1,
    unsigned int param_2, const SGroupStartEndPair* param_3,
    unsigned int param_4, const SMTUpdateHint& param_5)
{
    // TODO
}
}
}
