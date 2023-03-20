#include "pch.h"
#include "Extra/Schedule/hhFxPipelineScheduler.h"
#include <Hedgehog/MTBase/hhMTSimpleJob.h>

using namespace hh::MTBase;

namespace Extra
{
namespace fx
{
void ExecuteSceneRenderParam(const SRenderDevice* device,
    SDrawInstanceParam* param_2, const SResourceContext* param_3,
    const CRenderingPerfCounterContainer* param_4, bool param_5,
    bool param_6, SDebugParameters* debugParams,
    CMTJobJointEntity* param_8, CMTJobJointEntity* param_9)
{
    CMTJobJointEntity pCVar3 = *param_9;
    // TODO

    CMTJobJointEntity pSVar10 = *param_8;
    if (!pSVar10)
    {
        pSVar10 = hhMTSimpleJobJointDynamicCreate();
    }

    pSVar10.Lock();
    param_8->Unlock();

    CMTJobJointEntity pSVar4 = hhMTSimpleJobJointStaticCreate();
    // TODO

    if (!pSVar4)
    {
        pSVar4 = hhMTSimpleJobJointDynamicCreate();
    }

    pSVar4.Lock();

    if (!param_5)
    {
        hhMTSimpleJobJointUnlock(pSVar10);
        hhMTSimpleJobBlockUntilSignal(pSVar10, 0);
        hhMTSimpleJobJointLock(pSVar10);

        if (pCVar3)
        {
            hhMTSimpleJobJointUnlock(pCVar3);
            hhMTSimpleJobBlockUntilSignal(pCVar3, 0);
            hhMTSimpleJobJointLock(pCVar3);
        }
    }

    // TODO

    if (pCVar3)
    {
        hhMTSimpleJobJointUnlock(pCVar3);
        hhMTSimpleJobBlockUntilSignal(pCVar3, 0);
        hhMTSimpleJobJointLock(pCVar3);
    }

    hhMTSimpleJobJointUnlock(pSVar4);
    hhMTSimpleJobBlockUntilSignal(pSVar4, 0);
    hhMTSimpleJobJointLock(pSVar4);

    // TODO

    hhMTSimpleJobJointUnlock(pSVar4);
    pSVar4.BlockUntilSignal(); // TODO: Replace pSVar4 with (apSStack3096 + iVar7)
    hhMTSimpleJobJointRelease(pSVar4); // TODO: Replace pSVar4 with (apSStack3096 + iVar7)
    hhMTSimpleJobJointUnlock(pSVar10);
    hhMTSimpleJobJointLock(*param_8);
}
}
}
