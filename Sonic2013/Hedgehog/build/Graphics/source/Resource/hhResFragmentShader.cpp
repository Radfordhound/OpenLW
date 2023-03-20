#include "pch.h"
#include "Hedgehog/Graphics/Resource/hhResFragmentShader.h"
#include "Hedgehog/Graphics/Resource/hhResMiragePixelShaderParameter.h"
#include "Hedgehog/Graphics/Resource/hhResShaderAcTypeInfo.h"
#include <Hedgehog/MirageCore/Resource/hhShaderResource.h>
#include <Hedgehog/Database/hhSampleChunk.h>
#include <csl/fnd/memory.h>

using namespace csl::fnd;
using namespace hh::mr;
using namespace hh::ut;
using namespace hh::db;
using namespace hh::rsdx;
using namespace hh::gfx::internal;
using namespace hh::gfx::res::detail;

namespace hh
{
namespace gfx
{
namespace res
{
const ResourceTypeInfo& ResFragmentShader::staticTypeInfo()
{
    return ResFragmentShaderTypeInfo;
}

ResName ResFragmentShader::GetName()
{
    return ResName(&ptr()->CodeResName);
}

ResUserData ResFragmentShader::GetResUserData()
{
    return ResUserData(&ptr()->UserData);
}

void* ResFragmentShader::Replace(std::size_t* size, csl::fnd::IAllocator* allocator)
{
    // Resolve sample chunk resource pointers.
    CSampleChunkResource* res = reinterpret_cast<CSampleChunkResource*>(ptr());
    res->ResolvePointer();

    // Get vertex shader resource data.
    CPixelShaderV2Resource* pixelShaderData = res->GetData<CPixelShaderV2Resource>();

    // Compute total size of shader common data + user data items.
    *size = (sizeof(ResShaderCommonData) + (sizeof(ResUserDataItemData) *
        (pixelShaderData->ParamsCount() + 1)));
    
    // Allocate buffer to hold shader common data + user data items.
    ResShaderCommonData* shader = static_cast<ResShaderCommonData*>(allocator->Alloc(*size));

    // Setup common shader data.
    std::memset(shader, 0, sizeof(ResShaderCommonData));

    // Initialize shader code resource name.
    ResName aRStack32 = InitResNameData(&shader->CodeResName,
        GetUniqueString(pixelShaderData->CodeResName()));

    // Initialize shader user data.
    shader->UserData.Items = reinterpret_cast<ResUserDataItemData*>(shader + 1);
    shader->UserData.ItemCount = (pixelShaderData->ParamsCount() + 1);
    
    // Initialize user data for shader allocator.
    shader->UserData.Items[0].Index = 0;
    shader->UserData.Items[0].Size = sizeof(csl::fnd::IAllocator*);
    shader->UserData.Items[0].Count = 1;
    shader->UserData.Items[0].Data = allocator;

    ResName RStack28 = InitResNameData(&shader->UserData.Items[0].Name,
        GetUniqueString("allocator"));

    // Initialize user data for shader usages.
    char* usageStr = GetUniqueString("usage");
    unsigned int usageStrHash = CalcHashKey("usage", std::strlen("usage"));

    for (u32 i = 0; i < pixelShaderData->ParamsCount(); ++i)
    {
        ResUserDataItemData& curUserData = shader->UserData.Items[i + 1];
        const char* curParamResName = pixelShaderData->ParamResNames()[i];

        curUserData.Index = (i + 1);
        curUserData.Size = sizeof(char);
        curUserData.Count = std::strlen(curParamResName);
        curUserData.Data = GetUniqueString(curParamResName);
        curUserData.Name.Hash = usageStrHash;
        curUserData.Name.String = usageStr;
    }

    return shader;
}

bool ResFragmentShader::Setup(std::size_t size, csl::fnd::IAllocator* allocator)
{
    return false;
}

bool ResFragmentShader::Setup(std::size_t size,
    csl::fnd::IAllocator* allocator, ut::Packfile pac)
{
    ResName codeResName = GetName();
    ResMiragePixelShaderCode pixelShaderCode = pac.Get<ResMiragePixelShaderCode>(codeResName);
    ptr()->Shader = pixelShaderCode.ptr()->CodeData->Handle.get();

    if (ptr()->Shader)
    {
        ptr()->Shader->AddRef();
    }

    ResUserData userData = GetResUserData();
    if (userData.ptr()->ItemCount > 1)
    {
        std::size_t floatConstantCount = 0;
        std::size_t intConstantCount = 0;
        std::size_t boolConstantCount = 0;
        std::size_t samplerCount = 0;
        std::size_t usageCount = 0;

        for (std::size_t i = 1; i < userData.ptr()->ItemCount; ++i)
        {
            ResUserDataItem usageItem = userData.GetResUserDataItem(i);
            auto pixelShaderParam = pac.Get<ResMiragePixelShaderParameter>(
                usageItem.GetDataPtr<const char>());

            if (pixelShaderParam.IsValid())
            {
                ResMiragePixelShaderParameterData* pixelShaderParamData = pixelShaderParam.ptr();
                intConstantCount += pixelShaderParamData->Int4UsageCount;
                floatConstantCount += pixelShaderParamData->Float4UsageCount;
                boolConstantCount += pixelShaderParamData->Bool4UsageCount;
                samplerCount += pixelShaderParamData->SamplerUsageCount;
                ++usageCount;
            }
        }

        if (usageCount == 0)
        {
            return false;
        }

        ptr()->Float4UsageCount = floatConstantCount;
        ptr()->Int4UsageCount = intConstantCount;
        ptr()->Bool4UsageCount = boolConstantCount;
        ptr()->SamplerUsageCount = samplerCount;

        IAllocator* shaderAllocator = static_cast<IAllocator*>(ptr()->UserData.Items->Data);
        
        // Allocate buffer for constant usage data.
        auto constUsageData = static_cast<ResShaderConstantUsageData*>(shaderAllocator->Alloc(
            ((floatConstantCount + intConstantCount + boolConstantCount) * sizeof(ResShaderConstantUsageData)) +
            (samplerCount * sizeof(ResShaderSamplerUsageData))));

        // Setup float usages pointer.
        ptr()->Float4Usages = (ptr()->Float4UsageCount != 0) ?
            constUsageData : nullptr;

        constUsageData += (ptr()->Float4UsageCount);

        // Setup int usages pointer.
        ptr()->Int4Usages = (ptr()->Int4UsageCount != 0) ?
            constUsageData : nullptr;

        constUsageData += (ptr()->Int4UsageCount);

        // Setup bool usages pointer.
        ptr()->Bool4Usages = (ptr()->Bool4UsageCount != 0) ?
            constUsageData : nullptr;

        constUsageData += (ptr()->Bool4UsageCount);

        // Setup texture sampler usages pointer.
        ptr()->SamplerUsages = (ptr()->SamplerUsageCount != 0) ?
            reinterpret_cast<ResShaderSamplerUsageData*>(constUsageData) : nullptr;

        floatConstantCount = 0;
        intConstantCount = 0;
        boolConstantCount = 0;
        samplerCount = 0;

        for (std::size_t i = 1; i < userData.ptr()->ItemCount; ++i)
        {
            ResUserDataItem usageItem = userData.GetResUserDataItem(i);
            auto pixelShaderParam = pac.Get<ResMiragePixelShaderParameter>(
                usageItem.GetDataPtr<const char>());
            
            if (pixelShaderParam.IsValid())
            {
                ResMiragePixelShaderParameterData* pixelShaderParamData = pixelShaderParam.ptr();
                if (pixelShaderParamData->Float4UsageCount != 0)
                {
                    std::memcpy(ptr()->Float4Usages + floatConstantCount,
                        pixelShaderParamData->Float4Usages,
                        pixelShaderParamData->Float4UsageCount *
                        sizeof(ResShaderConstantUsageData));

                    floatConstantCount += pixelShaderParamData->Float4UsageCount;
                }

                if (pixelShaderParamData->Int4UsageCount != 0)
                {
                    std::memcpy(ptr()->Int4Usages + intConstantCount,
                        pixelShaderParamData->Int4Usages,
                        pixelShaderParamData->Int4UsageCount *
                        sizeof(ResShaderConstantUsageData));

                    intConstantCount += pixelShaderParamData->Int4UsageCount;
                }

                if (pixelShaderParamData->Bool4UsageCount != 0)
                {
                    std::memcpy(ptr()->Bool4Usages + boolConstantCount,
                        pixelShaderParamData->Bool4Usages,
                        pixelShaderParamData->Bool4UsageCount *
                        sizeof(ResShaderConstantUsageData));

                    boolConstantCount += pixelShaderParamData->Bool4UsageCount;
                }

                if (pixelShaderParamData->SamplerUsageCount != 0)
                {
                    std::memcpy(ptr()->SamplerUsages + samplerCount,
                        pixelShaderParamData->SamplerUsages,
                        pixelShaderParamData->SamplerUsageCount *
                        sizeof(ResShaderSamplerUsageData));

                    samplerCount += pixelShaderParamData->SamplerUsageCount;
                }
            }
        }
    }

    return true;
}

void ResFragmentShader::Unbind()
{
    // TODO
}

void ResFragmentShader::Cleanup(std::size_t size)
{
    Unbind();
    // TODO
}
}
}
}
