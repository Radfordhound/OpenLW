// TODO: Both the name of this file and its path were guessed!
#pragma once
#include "RenderSceneViewImpl.h"

namespace app
{
namespace gfx
{
class CRMSceneViewImpl : public CRenderSceneViewImpl
{
LWAPI_PRIVATE
    // TODO: Data members?

public:
    // NOTE: The IRenderOneCallback version of this function is thunked at 0x022573ac on Wii U.
    LWAPI(0x02257298, 0x004e5a40)
    void RenderOne(const Extra::fx::SSceneRenderInfo* renderInfo,
        unsigned long long param_2, unsigned int param_3,
        unsigned int param_4, unsigned int param_5);

    LWAPI(0x0226b78c, 0x004e0eb0)
    ~CRMSceneViewImpl();

    LWAPI(0x0226b7ec, 0x004dfba0)
    void WaitUntilNotbusy();

    LWAPI(0x0226b7f0, 0x004dfbb0)
    void OnUpdatedPlayerFrustum();

    LWAPI(0x0226b878, 0x004dfc00)
    void OnBuildSchedule(Extra::fx::SScheduleParameter* param_1,
        unsigned int param_2);
};
}
}
