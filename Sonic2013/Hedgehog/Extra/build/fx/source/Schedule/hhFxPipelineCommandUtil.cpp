#include "Extra/Schedule/hhFxPipelineCommandUtil.h"
#include "Extra/Schedule/hhFxPipelineScheduler.h"
#include <Hedgehog/Base/System/hhMemory.h>

using namespace hh::MTBase;

namespace Extra
{
namespace fx
{
struct SDrawInstanceParam;

struct CFxPipelineExecutorInternal // size == 0x158c
{
    SFxPipelineCommonResource CommonRes;
    // TODO: Other data members.
    bool field_0x1574;
    bool field_0x1575;
    // TODO: Other data members.
    SDrawInstanceParam* RenderSchedule;
    // TODO: Other data members.

    inline CFxPipelineExecutorInternal() :
        // TODO
        RenderSchedule(nullptr)
        // TODO
    {
        // TODO
    }

    inline ~CFxPipelineExecutorInternal()
    {
        // TODO
    }

    // Wii U: 0x036fccac, PC: TODO
    void Render(SDrawInstanceParam* param_1, const SRenderDevice* device,
        const SRenderParamInitializeParameter* param_3,
        unsigned int param_4, bool param_5, bool param_6,
        CMTJobJointEntity* param_7, CMTJobJointEntity* param_8);
};

CFxPipelineExecutor::CFxPipelineExecutor() :
    m_impl(new CFxPipelineExecutorInternal()) {}

CFxPipelineExecutor::~CFxPipelineExecutor()
{
    delete m_impl;
}

void CFxPipelineExecutor::EndRenderSchedule()
{
    if (m_impl->RenderSchedule)
    {
        __HH_FREE(m_impl->RenderSchedule);
        m_impl->RenderSchedule = nullptr;
    }
}

bool CFxPipelineExecutor::HasRenderSchedule()
{
    return (m_impl->RenderSchedule != nullptr);
}

void CFxPipelineExecutorInternal::Render(
    SDrawInstanceParam* param_1, const SRenderDevice* device,
    const SRenderParamInitializeParameter* param_3,
    unsigned int param_4, bool param_5, bool param_6,
    CMTJobJointEntity* param_7, CMTJobJointEntity* param_8)
{
    // TODO

    SDebugParameters SStack5476 = {};
    SStack5476.field_0x0 = param_1;

    // TODO: Un-comment this!
    //ExecuteSceneRenderParam(device, param_1, (SResourceContext*)this, // TODO: Instead of casting to SResourceContext*, do it like Sonic Team did it!
    //    nullptr, param_5, false, &SStack5476, param_7,
    //    param_8);

    // TODO
}

void CFxPipelineExecutor::RenderScheduled(
    const SRenderParamInitializeParameter* param_1,
    unsigned int param_2, const SRenderDevice* device,
    hh::MTBase::CMTJobJointEntity* param_4,
    hh::MTBase::CMTJobJointEntity* param_5)
{
    m_impl->Render(m_impl->RenderSchedule, device, param_1,
        param_2, m_impl->field_0x1574, m_impl->field_0x1575,
        param_4, param_5);
}

const SFxPipelineCommonResource* CFxPipelineExecutor::GetCommonResource() const
{
    return &m_impl->CommonRes;
}
}
}
