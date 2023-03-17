// TODO: Both the name of this file and its path were guessed!
#pragma once
#include "RenderScheduler.h"
#include "RenderableContainer.h"
#include <Hedgehog/Utility/hhPackfile.h>
#include <Extra/Util/hhRenderOneCallback.h>
#include <boost/scoped_ptr.hpp>

namespace hh
{
namespace mr
{
class CRenderingInfrastructure;
}

namespace MTBase
{
struct SMTUpdateHint;
}
}

namespace Extra
{
namespace fx
{
class CGPUInstanceMapper;
struct SGroupStartEndPair;
struct SFxPipelineCommonResource;
struct RenderScratchBuffer;
}
}

namespace app
{
namespace fnd
{
struct SUpdateInfo;
}

namespace gfx
{
class CRenderSceneView;

class CRenderSceneViewImpl : public IRenderScheduler, // size == 0x162e0
    public Extra::fx::IRenderOneCallback
{
    friend CRenderSceneView;

    // TODO: Other data members.
    boost::scoped_ptr<RenderableContainer> m_renderableContainer;
    // TODO: Other data members.

public:
    // Wii U: 0x0225cbc0, PC: TODO
    static void Update_ComamndBufferPre(CRenderSceneViewImpl** param_1,
        unsigned int param_2, Extra::fx::SGroupStartEndPair* param_3,
        unsigned int param_4, const hh::MTBase::SMTUpdateHint& param_5);

    // Wii U: 0x02261a1c, PC: TODO
    static void Update_ComamndBuffer(CRenderSceneViewImpl** param_1,
        unsigned int param_2, Extra::fx::SGroupStartEndPair* param_3,
        unsigned int param_4, const hh::MTBase::SMTUpdateHint& param_5);

    // Wii U: 0x0226a39c, PC: TODO
    void Update_FrameEndRenderContainerOne();

    // Wii U: 0x0226b5e4, PC: TODO
    void CollectCalcModelNodeDrawInfoFull();

    // Wii U: 0x0226b62c, PC: TODO
    void CalcModeNodeVolumeMask(unsigned int param_1, unsigned int param_2);

    // Wii U: 0x0226b63c, PC: TODO
    void CalcGazePointAndDrawingFrustum();

    // Wii U: 0x0226b6b8, PC: TODO
    void CalcModeNodeCullingMask(unsigned int param_1, unsigned int param_2);

    // Wii U: 0x0226b6dc, PC: TODO
    void CalcModeNodeCullingMaskNoNear(unsigned int param_1, unsigned int param_2);

    // Wii U: 0x0226b700, PC: TODO
    void Update_PrimitiveRenderable();

    // TODO: The following RenderOne function is marked virtual here because it's in
    // CRenderSceneViewImpl's IRenderScheduler vtable on Wii U. On PC, this is not
    // the case, however. Is it incorrect for this to be marked virtual?
    
    // NOTE: The IRenderOneCallback version of this function is thunked at 0x0226d128 on Wii U.
    // Wii U: 0x0226cf68, PC: 0x004eebc0
    virtual void RenderOne(const Extra::fx::SSceneRenderInfo* renderInfo,
        unsigned long long param_2, unsigned int param_3,
        unsigned int param_4, unsigned int param_5);

    // Wii U: 0x0226e284, PC: 0x004f4300
    CRenderSceneViewImpl();

    // Wii U: 0x0227411c, PC: 0x004f4930
    ~CRenderSceneViewImpl();

    // Wii U: 0x022742f0, PC: (GENERIC)
    CRenderSceneViewImpl* GetSceneView();

    // Wii U: 0x022742f4, PC: 0x004ef750
    void WaitUntilNotbusy();

    // Wii U: 0x02274550, PC: TODO
    void Initialize(csl::fnd::IAllocator* allocator,
        hh::mr::CRenderingInfrastructure* renderInfra,
        void* stackMemory, std::size_t stackSize);

    // Wii U: 0x022747e4, PC: TODO
    void Finalize();

    // Wii U: 0x02274988, PC: TODO
    void Setup(hh::ut::Packfile shaderPac,
        hh::mr::CRenderingInfrastructure* renderInfra);

    // Wii U: 0x02274ac0, PC: 0x004f1650
    unsigned int OnRenderInitializeParameter(
        Extra::fx::SRenderParamInitializeParameter* param_1,
        unsigned int param_2);

    // Wii U: 0x02274d40, PC: 0x004f39c0
    void OnBuildSchedule(Extra::fx::SScheduleParameter* param_1,
        unsigned int param_2);

    // Wii U: 0x02275214, PC: (GENERIC)
    void OnUpdatedPlayerFrustum();

    // Wii U: 0x022755f4, PC: TODO
    void StartRenderContainerOne(const fnd::SUpdateInfo& updateInfo,
        unsigned int param_2, Extra::fx::RenderScratchBuffer* param_3,
        Extra::fx::CGPUInstanceMapper* param_4,
        const Extra::fx::SFxPipelineCommonResource* param_5);
};
}
}
