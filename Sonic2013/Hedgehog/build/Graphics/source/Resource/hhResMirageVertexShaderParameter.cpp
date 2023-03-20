#include "pch.h"
#include "Hedgehog/Graphics/Resource/hhResMirageVertexShaderParameter.h"
#include "Hedgehog/Graphics/Resource/hhResMirageVertexShaderParameterTypeInfo.h"
#include <Hedgehog/MirageCore/Resource/hhShaderResource.h>
#include <Hedgehog/Database/hhSampleChunk.h>
#include <csl/fnd/memory.h>
#include <new>

using namespace hh::mr;
using namespace hh::db;
using namespace hh::gfx::internal;
using namespace hh::gfx::res::detail;

namespace hh
{
namespace gfx
{
namespace res
{
const ut::ResourceTypeInfo& ResMirageVertexShaderParameter::staticTypeInfo()
{
    return ResMirageVertexShaderParameterTypeInfo;
}

LWAPI(0x03687784, TODO)
static void MakeConstantName(ResShaderConstantUsageData* output,
    const CShaderConstantNameResource* input)
{
    for (std::size_t i = 0; i < input->GetCount(); ++i)
    {
        const CShaderConstantResource* curConstRes = input->GetConstant(i);
        output[i].RegFirstIndex = curConstRes->GetRegFirstIndex();
        output[i].RegCount = curConstRes->GetRegCount();
        
        InitResNameData(&output[i].Name, GetUniqueString(curConstRes->GetName()));
    }
}

LWAPI(0x0368780c, TODO)
static void MakeMirageConstantName(CShaderConstantNameData* output,
    const CShaderConstantNameResource* input)
{
    for (std::size_t i = 0; i < input->GetCount(); ++i)
    {
        const CShaderConstantResource* curConstRes = input->GetConstant(i);
        CShaderConstantData& curConstData = (*output)[curConstRes->GetName()];
        
        curConstData.SetRegFirstIndex(curConstRes->GetRegFirstIndex());
        curConstData.SetRegCount(curConstRes->GetRegCount());
    }
}

LWAPI(0x03687888, TODO)
static void MakeMirageConstantName(CVertexShaderParameterData* output,
    const CVertexShaderParameterResource* input)
{
    MakeMirageConstantName(&output->Floats, &input->GetFloatConstants());
    MakeMirageConstantName(&output->Ints, &input->GetIntConstants());
    MakeMirageConstantName(&output->Bools, &input->GetBoolConstants());
}

void* ResMirageVertexShaderParameter::Replace(std::size_t* size,
    csl::fnd::IAllocator* allocator)
{
    // Resolve sample chunk resource pointers.
    CSampleChunkResource* res = reinterpret_cast<CSampleChunkResource*>(ptr());
    res->ResolvePointer();

    // Get vertex shader parameter resource data.
    auto vtxShaderParamData = res->GetData<CVertexShaderParameterResource>();

    // Compute total size of parameter data + constant usage data + constant name data.
    *size = (sizeof(ResMirageVertexShaderParameterData) + sizeof(CVertexShaderParameterData) +
        ((vtxShaderParamData->GetTotalConstantCount() * sizeof(ResShaderConstantUsageData))));

    // Allocate buffer to hold parameter data + constant usage data + constant name data.
    auto vtxShaderParams = static_cast<ResMirageVertexShaderParameterData*>(
        allocator->Alloc(*size));

    // Setup parameter data.
    vtxShaderParams->FloatConstants = nullptr;
    vtxShaderParams->FloatConstantCount = vtxShaderParamData->GetFloatConstantCount();
    vtxShaderParams->IntConstants = nullptr;
    vtxShaderParams->IntConstantCount = vtxShaderParamData->GetIntConstantCount();
    vtxShaderParams->BoolConstants = nullptr;
    vtxShaderParams->BoolConstantCount = vtxShaderParamData->GetBoolConstantCount();

    // Setup constant usage data.
    std::size_t curOff = sizeof(ResMirageVertexShaderParameterData);
    if (vtxShaderParams->FloatConstantCount != 0)
    {
        vtxShaderParams->FloatConstants = PtrAdd<ResShaderConstantUsageData>(
            vtxShaderParams, curOff);

        MakeConstantName(vtxShaderParams->FloatConstants,
            &vtxShaderParamData->GetFloatConstants());

        curOff += (vtxShaderParamData->GetFloatConstants().GetCount() *
            sizeof(ResShaderConstantUsageData));
    }

    if (vtxShaderParams->IntConstantCount != 0)
    {
        vtxShaderParams->IntConstants = PtrAdd<ResShaderConstantUsageData>(
            vtxShaderParams, curOff);

        MakeConstantName(vtxShaderParams->IntConstants,
            &vtxShaderParamData->GetIntConstants());

        curOff += (vtxShaderParamData->GetIntConstants().GetCount() *
            sizeof(ResShaderConstantUsageData));
    }

    if (vtxShaderParams->BoolConstantCount != 0)
    {
        vtxShaderParams->BoolConstants = PtrAdd<ResShaderConstantUsageData>(
            vtxShaderParams, curOff);

        MakeConstantName(vtxShaderParams->BoolConstants,
            &vtxShaderParamData->GetBoolConstants());

        curOff += (vtxShaderParamData->GetBoolConstants().GetCount() *
            sizeof(ResShaderConstantUsageData));
    }

    // Setup constant name data.
    vtxShaderParams->field_0x0 = ::new(PtrAdd<void>(vtxShaderParams,
        curOff)) CVertexShaderParameterData();

    MakeMirageConstantName(vtxShaderParams->field_0x0, vtxShaderParamData);

    // Set allocator.
    vtxShaderParams->Allocator = allocator;
    return vtxShaderParams;
}

bool ResMirageVertexShaderParameter::Setup(std::size_t size,
    csl::fnd::IAllocator* allocator)
{
    return false;
}

bool ResMirageVertexShaderParameter::Setup(std::size_t size,
    csl::fnd::IAllocator* allocator, ut::Packfile pac)
{
    return false;
}
}
}
}
