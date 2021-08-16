#include "CRenderSceneViewImpl.h"
#include <Hedgehog/MirageCore/Misc/hhRenderingInfrastructure.h>
#include <Hedgehog/MTBase/hhMTSimpleJob.h>

using namespace app::fnd;
using namespace hh::mr;
using namespace hh::ut;
using namespace hh::MTBase;
using namespace Extra::fx;
using namespace csl::fnd;

namespace app
{
namespace gfx
{
void CRenderSceneViewImpl::Update_ComamndBufferPre(CRenderSceneViewImpl** param_1,
    unsigned int param_2, SGroupStartEndPair* param_3,
    unsigned int param_4, const SMTUpdateHint& param_5)
{
    // TODO
}

void CRenderSceneViewImpl::Update_ComamndBuffer(CRenderSceneViewImpl** param_1,
    unsigned int param_2, SGroupStartEndPair* param_3,
    unsigned int param_4, const SMTUpdateHint& param_5)
{
    // TODO

    //hhMTSimpleJobJointUnlock(param_5.field_0x4.get()); // TODO: REMOVE THIS LINE!!!
    //hhMTSimpleJobJointUnlock(param_5.field_0x4.get()); // TODO: REMOVE THIS LINE!!!
    //hhMTSimpleJobJointUnlock(param_5.field_0x4.get()); // TODO: REMOVE THIS LINE!!!
}

void CRenderSceneViewImpl::Update_FrameEndRenderContainerOne()
{
    // TODO
}

void CRenderSceneViewImpl::CollectCalcModelNodeDrawInfoFull()
{
    // TODO
}

void CRenderSceneViewImpl::CalcModeNodeVolumeMask(
    unsigned int param_1, unsigned int param_2)
{
    // TODO
}

void CRenderSceneViewImpl::CalcGazePointAndDrawingFrustum()
{
    // TODO
}

void CRenderSceneViewImpl::CalcModeNodeCullingMask(
    unsigned int param_1, unsigned int param_2)
{
    // TODO
}

void CRenderSceneViewImpl::CalcModeNodeCullingMaskNoNear(
    unsigned int param_1, unsigned int param_2)
{
    // TODO
}

void CRenderSceneViewImpl::Update_PrimitiveRenderable()
{
    // TODO
}

void CRenderSceneViewImpl::RenderOne(const SSceneRenderInfo* renderInfo,
    unsigned long long param_2, unsigned int param_3,
    unsigned int param_4, unsigned int param_5)
{
    // TODO
}

CRenderSceneViewImpl::CRenderSceneViewImpl()
{
    // TODO
}

CRenderSceneViewImpl::~CRenderSceneViewImpl()
{
    // TODO
}

CRenderSceneViewImpl* CRenderSceneViewImpl::GetSceneView()
{
    return this;
}

void CRenderSceneViewImpl::WaitUntilNotbusy()
{
    // TODO
}

void CRenderSceneViewImpl::Initialize(IAllocator* allocator,
    CRenderingInfrastructure* renderInfra,
    void* stackMemory, std::size_t stackSize)
{
    // TODO

    m_renderableContainer.reset(RenderableContainer::Create(allocator));
    
    // TODO
}

void CRenderSceneViewImpl::Finalize()
{
    // TODO
}

void CRenderSceneViewImpl::Setup(Packfile shaderPac,
    CRenderingInfrastructure* renderInfra)
{
    // TODO
}

unsigned int CRenderSceneViewImpl::OnRenderInitializeParameter(
    SRenderParamInitializeParameter* param_1, unsigned int param_2)
{
    // TODO
    return 0;
}

void CRenderSceneViewImpl::OnBuildSchedule(SScheduleParameter* param_1,
    unsigned int param_2)
{
    // TODO
}

void CRenderSceneViewImpl::OnUpdatedPlayerFrustum() {}

void CRenderSceneViewImpl::StartRenderContainerOne(
    const SUpdateInfo& updateInfo, unsigned int param_2,
    RenderScratchBuffer* param_3, CGPUInstanceMapper* param_4,
    const SFxPipelineCommonResource* param_5)
{
    // TODO
}
}
}
