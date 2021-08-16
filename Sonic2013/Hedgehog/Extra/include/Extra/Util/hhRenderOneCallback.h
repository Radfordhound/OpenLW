#pragma once

namespace Extra
{
namespace fx
{
struct SSceneRenderInfo;

struct IRenderOneCallback
{
    // Wii U: 0x02276160, PC: (GENERIC)
    virtual void PrepareRenderOne(const SSceneRenderInfo* renderInfo);

    virtual void RenderOne(const SSceneRenderInfo* renderInfo,
        unsigned long long param_2, unsigned int param_3,
        unsigned int param_4, unsigned int param_5) = 0;
};
}
}
