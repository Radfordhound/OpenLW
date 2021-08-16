#pragma once
#include "CRenderSceneViewImpl.h"

namespace app
{
namespace gfx
{
class CRMSceneViewImpl : public CRenderSceneViewImpl
{
    // TODO: Data members?

public:
    // NOTE: The IRenderOneCallback version of this function is thunked at 0x022573ac on Wii U.
    // Wii U: 0x02257298, PC: 0x004e5a40
    void RenderOne(const Extra::fx::SSceneRenderInfo* renderInfo,
        unsigned long long param_2, unsigned int param_3,
        unsigned int param_4, unsigned int param_5);

    // Wii U: 0x0226b78c, PC: 0x004e0eb0
    ~CRMSceneViewImpl();

    // Wii U: 0x0226b7ec, PC: 0x004dfba0
    void WaitUntilNotbusy();

    // Wii U: 0x0226b7f0, PC: 0x004dfbb0
    void OnUpdatedPlayerFrustum();

    // Wii U: 0x0226b878, PC: 0x004dfc00
    void OnBuildSchedule(Extra::fx::SScheduleParameter* param_1,
        unsigned int param_2);
};
}
}
