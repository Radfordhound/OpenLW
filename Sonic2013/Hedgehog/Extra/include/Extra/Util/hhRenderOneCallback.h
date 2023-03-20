#pragma once

namespace Extra
{
namespace fx
{
struct SSceneRenderInfo;

struct IRenderOneCallback
{
    LWAPI(0x02276160, TODO)
    virtual void PrepareRenderOne(const SSceneRenderInfo* renderInfo);

    virtual void RenderOne(const SSceneRenderInfo* renderInfo,
        unsigned long long param_2, unsigned int param_3,
        unsigned int param_4, unsigned int param_5) = 0;

    // TODO: Is there an extra virtual function on PC?
};
}
}
