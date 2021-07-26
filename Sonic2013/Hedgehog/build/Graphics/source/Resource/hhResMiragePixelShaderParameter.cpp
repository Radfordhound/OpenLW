#include "Hedgehog/Graphics/Resource/hhResMiragePixelShaderParameter.h"
#include "Hedgehog/Graphics/Resource/hhResMiragePixelShaderParameterTypeInfo.h"
#include <Hedgehog/MirageCore/Resource/hhShaderResource.h>
#include <Hedgehog/Database/hhSampleChunk.h>
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
const ut::ResourceTypeInfo& ResMiragePixelShaderParameter::staticTypeInfo()
{
    return ResMiragePixelShaderParameterTypeInfo;
}

// Wii U: 0x03684214, PC: TODO
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

// Wii U: 0x0368429c, PC: TODO
static void MakeSamplerUsage(ResShaderSamplerUsageData* output,
    const CShaderSamplerUsageResource* input)
{
    for (std::size_t i = 0; i < input->GetCount(); ++i)
    {
        const CShaderSamplerResource* curSamplerRes = input->GetSampler(i);
        output[i].RegIndex = (curSamplerRes->GetRegIndex() & 15);
        output[i].field_0x1 = (curSamplerRes->GetRegIndex() / 16);

        InitResNameData(&output[i].Name, GetUniqueString(curSamplerRes->GetName()));
    }
}

// Wii U: 0x03684328, PC: TODO
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

// Wii U: 0x036843a4, PC: TODO
static void MakeMirageSamplerUsage(CShaderSamplerUsageData* output,
    const CShaderSamplerUsageResource* input)
{
    for (std::size_t i = 0; i < input->GetCount(); ++i)
    {
        const CShaderSamplerResource* curSamplerRes = input->GetSampler(i);
        auto& curSamplerData = (*output)[curSamplerRes->GetName()];
        bool bVar1 = false;

        for (std::size_t i2 = 0; i2 < curSamplerData.size(); ++i2)
        {
            if (curSamplerData[i2] == (curSamplerRes->GetRegIndex() & 15))
            {
                bVar1 = true;
                break;
            }
        }

        curSamplerData.push_back(curSamplerRes->GetRegIndex());
    }
}

// Wii U: 0x03684468, PC: TODO
static void MakeMirageConstantName(CPixelShaderParameterData* output,
    const CPixelShaderParameterResource* input)
{
    MakeMirageConstantName(&output->GetFloatConstants(), &input->GetFloatConstants());
    MakeMirageConstantName(&output->GetIntConstants(), &input->GetIntConstants());
    MakeMirageConstantName(&output->GetBoolConstants(), &input->GetBoolConstants());
    MakeMirageSamplerUsage(&output->GetTextureSamplers(), &input->GetTextureSamplers());
}

void* ResMiragePixelShaderParameter::Replace(std::size_t* size,
    csl::fnd::IAllocator* allocator)
{
    // Resolve sample chunk resource pointers.
    CSampleChunkResource* res = reinterpret_cast<CSampleChunkResource*>(ptr());
    res->ResolvePointer();

    // Get pixel shader parameter resource data.
    auto pixelShaderParamData = res->GetData<CPixelShaderParameterResource>();

    // Compute total size of parameter data + constant usage data + constant name data.
    *size = (sizeof(ResMiragePixelShaderParameterData) + sizeof(CPixelShaderParameterData) +
        (pixelShaderParamData->GetTotalConstantCount() * sizeof(ResShaderConstantUsageData)) +
        (pixelShaderParamData->GetTotalSamplerCount() * sizeof(ResShaderSamplerUsageData)));

    // Allocate buffer to hold parameter data + constant usage data + constant name data.
    auto pixelShaderParams = static_cast<ResMiragePixelShaderParameterData*>(
        allocator->Alloc(*size));

    // Setup parameter data.
    pixelShaderParams->FloatConstants = nullptr;
    pixelShaderParams->FloatConstantCount = pixelShaderParamData->GetFloatConstants().GetCount();
    pixelShaderParams->IntConstants = nullptr;
    pixelShaderParams->IntConstantCount = pixelShaderParamData->GetIntConstants().GetCount();
    pixelShaderParams->BoolConstants = nullptr;
    pixelShaderParams->BoolConstantCount = pixelShaderParamData->GetBoolConstants().GetCount();
    pixelShaderParams->TexSamplers = nullptr;
    pixelShaderParams->TexSamplerCount = pixelShaderParamData->GetTextureSamplers().GetCount();

    // Setup constant usage data.
    std::size_t curOff = sizeof(ResMiragePixelShaderParameterData);
    if (pixelShaderParams->FloatConstantCount != 0)
    {
        pixelShaderParams->FloatConstants = PtrAdd<ResShaderConstantUsageData>(
            pixelShaderParams, curOff);

        MakeConstantName(pixelShaderParams->FloatConstants,
            &pixelShaderParamData->GetFloatConstants());

        curOff += (pixelShaderParamData->GetFloatConstants().GetCount() *
            sizeof(ResShaderConstantUsageData));
    }

    if (pixelShaderParams->IntConstantCount != 0)
    {
        pixelShaderParams->IntConstants = PtrAdd<ResShaderConstantUsageData>(
            pixelShaderParams, curOff);

        MakeConstantName(pixelShaderParams->IntConstants,
            &pixelShaderParamData->GetIntConstants());

        curOff += (pixelShaderParamData->GetIntConstants().GetCount() *
            sizeof(ResShaderConstantUsageData));
    }

    if (pixelShaderParams->BoolConstantCount != 0)
    {
        pixelShaderParams->BoolConstants = PtrAdd<ResShaderConstantUsageData>(
            pixelShaderParams, curOff);

        MakeConstantName(pixelShaderParams->BoolConstants,
            &pixelShaderParamData->GetBoolConstants());

        curOff += (pixelShaderParamData->GetBoolConstants().GetCount() *
            sizeof(ResShaderConstantUsageData));
    }

    if (pixelShaderParams->TexSamplerCount != 0)
    {
        pixelShaderParams->TexSamplers = PtrAdd<ResShaderSamplerUsageData>(
            pixelShaderParams, curOff);

        MakeSamplerUsage(pixelShaderParams->TexSamplers,
            &pixelShaderParamData->GetTextureSamplers());

        curOff += (pixelShaderParamData->GetTextureSamplers().GetCount() *
            sizeof(ResShaderSamplerUsageData));
    }

    // Setup constant name data.
    pixelShaderParams->field_0x0 = ::new(PtrAdd<void>(pixelShaderParams,
        curOff)) CPixelShaderParameterData();

    MakeMirageConstantName(pixelShaderParams->field_0x0, pixelShaderParamData);

    // Set allocator.
    pixelShaderParams->Allocator = allocator;
    return pixelShaderParams;
}

bool ResMiragePixelShaderParameter::Setup(std::size_t size,
    csl::fnd::IAllocator* allocator)
{
    return false;
}

bool ResMiragePixelShaderParameter::Setup(std::size_t size,
    csl::fnd::IAllocator* allocator, ut::Packfile pac)
{
    return false;
}
}
}
}
