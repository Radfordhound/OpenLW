// TODO: Both the name of this file and its path were guessed!
#pragma once

namespace Extra
{
namespace fx
{
struct SScheduleParameter;
struct SRenderParamInitializeParameter;
}
}

namespace app
{
namespace gfx
{
class CRenderSceneViewImpl;

struct IRenderScheduler
{
    virtual void OnBuildSchedule(Extra::fx::SScheduleParameter* param_1,
        unsigned int param_2) = 0;

    virtual unsigned int OnRenderInitializeParameter(
        Extra::fx::SRenderParamInitializeParameter* param_1,
        unsigned int param_2) = 0;

    virtual CRenderSceneViewImpl* GetSceneView() = 0; // TODO: Is the return type correct?

    virtual ~IRenderScheduler() = 0;

    virtual void WaitUntilNotbusy() = 0;

    virtual void OnUpdatedPlayerFrustum() = 0;
};
}
}
