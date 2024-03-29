// TODO: Both the name of this file and its path were guessed!
#pragma once
#include "RenderManager.h"
#include "RenderSceneView.h"
#include "RMSceneViewImpl.h"
#include "gfx_ResourceCallback.h"
#include "RenderSynchronizer.h"
#include "System/FileLoader.h"
#include <Hedgehog/MTBase/hhMTSimpleJob.h>
#include <Extra/Util/hhStackAllocator.h>
#include <Extra/Util/hhRenderScratchBuffer.h>
#include <Extra/Util/hhGroupStartEndPair.h>
#include <Extra/Schedule/hhFxPipelineCommandUtil.h>
#include <boost/scoped_ptr.hpp>
#include <boost/intrusive_ptr.hpp>

namespace app
{
class CRenderEffectUpdateEntityCasinoLight;

namespace gfx
{
struct IRenderScheduler;

struct RenderManager::Impl : public Extra::fx::CFxPipelineExecutor, // size == 0x16410
    public IRenderSynchronizer
{
    typedef void (Impl::*UpdateFunc)(const fnd::SUpdateInfo& updateInfo,
        unsigned int param_2);

    unsigned int field_0xc;

    // TODO: Other data members.

    boost::intrusive_ptr<Extra::fx::CGPUInstanceMapper> field_0x68;
    CRenderEffectUpdateEntityCasinoLight* field_0x6c;
    IRenderScheduler* RenderSchedulers[3];

    // TODO: Other data members.

    unsigned int Unknown1; // offset: 136 // TODO: Is this a uint?
    fnd::SUpdateInfo UpdateInfo; // offset: 140

    // TODO: Other Data Members

    UpdateFunc UpdatePtr; // offset: 160

    bool SkipPresent; // offset: 164 // TODO: Is this a good name for this?
    // TODO: Other Data Members
    RenderManager* RenderMgr; // offset: 168
    csl::fnd::com_ptr<fnd::FileHandleObj> field_0xac; // offset: 172
    boost::scoped_ptr<hh::mr::CRenderingInfrastructure> RenderingInfrastructure; // offset: 176
    // TODO: Other Data Members
    hh::MTBase::CMTJobJointEntity m_evehtJointHandle;
    hh::MTBase::SJobJoint* m_MTRenderableUpJoint; // offset: 188
    hh::MTBase::SJobJoint* m_evehtJointSchedulerHandle; // offset: 192
    hh::MTBase::SJobJoint* m_evehtJointPostFrameHandle; // offset: 196
    // TODO: Other Data Members
    SetupInfo Info; // offset: 204
    boost::intrusive_ptr<GfxResourceCallback> field_0xd4; // offset: 212
    // TODO: Other Data Members
    CRMSceneViewImpl field_0xe0;
    // TODO: Other data members.
    CRenderSceneView DefaultSceneView;
    void* StackMemory;
    std::size_t StackSize;
    Extra::fx::RenderScratchBuffer ScratchBuffer;
    // TODO: Other data members.

    LWAPI(0x022570c4, 0x004dfce0)
    void WaitJoint();

    LWAPI(0x0225715c, TODO)
    void WaitUntilNotbusy();

    LWAPI(0x0225878c, TODO)
    void LockWorkerJoint();

    LWAPI(0x022587c4, TODO)
    std::size_t EntryRenderScheduler(IRenderScheduler* scheduler);

    LWAPI(0x022587fc, 0x004e7a00)
    Impl(RenderManager& renderMgr);

    LWAPI(0x02258d20, TODO)
    void LoadShader();

    LWAPI(0x02258d94, TODO)
    void Initialize();

    LWAPI(0x02258eac, TODO)
    void Setup(const SetupInfo& setupInfo);

    LWAPI(0x02258f08, TODO)
    void Finalize();

    LWAPI(0x02258fc4, TODO)
    void Shutdown();

    LWAPI(0x02259ea8, TODO)
    void Update(const fnd::SUpdateInfo& updateInfo, unsigned int param_2);

    LWAPI(0x0225a020, TODO)
    hh::ut::Packfile GetShaderFileResource() const;

    LWAPI(0x0225a670, NONE)
    void PrepareRenderSchedule();

    LWAPI(0x02261fdc, 0x004eca50)
    void Update_RunOnRenderInternal(const fnd::SUpdateInfo& updateInfo,
        unsigned int param_2);

    LWAPI(0x02262fbc, TODO)
    void InitUpdated();

    LWAPI(0x02263324, TODO)
    void PrepareRenderOne();

    LWAPI(0x0226349c, 0x004edf40)
    void RenderNoPresent();

    LWAPI(0x02263cc0, TODO)
    void Present();

    LWAPI(0x0226b9d8, TODO)
    ~Impl();

    LWAPI(0x0226bd5c, 0x004e5d80)
    bool SetupShader();

    LWAPI(0x0226bf5c, 0x004e6c90)
    void Update_Init(const fnd::SUpdateInfo& updateInfo, unsigned int param_2);

    LWAPI(0x0226bfd0, TODO)
    void Update_Run(const fnd::SUpdateInfo& updateInfo, unsigned int param_2);

    LWAPI(0x0226c000, TODO)
    void Update_BufferFixup(CRenderSceneViewImpl** param_1,
        unsigned int param_2, const Extra::fx::SGroupStartEndPair* param_3,
        unsigned int param_4, const hh::MTBase::SMTUpdateHint& param_5);
};
}
}
