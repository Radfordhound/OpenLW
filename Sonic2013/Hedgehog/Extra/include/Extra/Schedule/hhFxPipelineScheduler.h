#pragma once
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
struct SDrawInstanceParam;
struct SResourceContext;
class CRenderingPerfCounterContainer;
struct SDebugParameters;

// Wii U: 0x036f45e8, PC: TODO
void ExecuteSceneRenderParam(const SRenderDevice* device,
    SDrawInstanceParam* param_2, const SResourceContext* param_3,
    const CRenderingPerfCounterContainer* param_4, bool param_5,
    bool param_6, SDebugParameters* debugParams,
    hh::MTBase::CMTJobJointEntity* param_8,
    hh::MTBase::CMTJobJointEntity* param_9);
}
}
