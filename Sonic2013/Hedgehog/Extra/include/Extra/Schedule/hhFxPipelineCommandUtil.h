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
    LWAPI(0x0226c980, TODO)
    void PrepareRenderOne(const SSceneRenderInfo* renderInfo) {}

    LWAPI(0x0226c984, TODO)
    void RenderOne(const SSceneRenderInfo* renderInfo,
        unsigned long long param_2, unsigned int param_3,
        unsigned int param_4, unsigned int param_5) {}

    LWAPI(0x036fc410, TODO)
    CFxPipelineExecutor();

    LWAPI(0x036fc570, 0x00c50fe0)
    virtual ~CFxPipelineExecutor();

    LWAPI(0x036fc790, TODO)
    void EndRenderSchedule();

    LWAPI(0x036fc7d0, TODO)
    bool HasRenderSchedule();

    LWAPI(0x036fceb4, TODO)
    void RenderScheduled(const SRenderParamInitializeParameter* param_1,
        unsigned int param_2, const SRenderDevice* device,
        hh::MTBase::CMTJobJointEntity* param_4,
        hh::MTBase::CMTJobJointEntity* param_5);

    LWAPI(0x036fd1bc, TODO)
    const SFxPipelineCommonResource* GetCommonResource() const;
};
}
}
