#pragma once
#include "../Util/hhRenderOneCallback.h"
#include "../Util/hhRenderParam.h"

namespace hh
{
namespace MTBase
{
class CMTJobJointEntity;
}
}

namespace Extra
{
namespace fx
{
struct CFxPipelineExecutorInternal;

struct SFxPipelineCommonResource
{
    // TODO
};

class CFxPipelineExecutor : public IRenderOneCallback // size == 8
{
    CFxPipelineExecutorInternal* m_impl;

public:
    // Wii U: 0x0226c980, PC: Generic
    void PrepareRenderOne(const SSceneRenderInfo* renderInfo) {}

    // Wii U: 0x0226c984, PC: Generic
    void RenderOne(const SSceneRenderInfo* renderInfo,
        unsigned long long param_2, unsigned int param_3,
        unsigned int param_4, unsigned int param_5) {}

    // Wii U: 0x036fc410, PC: TODO
    CFxPipelineExecutor();

    // Wii U: 0x036fc570, PC: 0x00c50fe0
    virtual ~CFxPipelineExecutor();

    // Wii U: 0x036fc790, PC: TODO
    void EndRenderSchedule();

    // Wii U: 0x036fc7d0, PC: TODO
    bool HasRenderSchedule();

    // Wii U: 0x036fceb4, PC: TODO
    void RenderScheduled(const SRenderParamInitializeParameter* param_1,
        unsigned int param_2, const SRenderDevice* device,
        hh::MTBase::CMTJobJointEntity* param_4,
        hh::MTBase::CMTJobJointEntity* param_5);

    // Wii U: 0x036fd1bc, PC: TODO
    const SFxPipelineCommonResource* GetCommonResource() const;
};
}
}
