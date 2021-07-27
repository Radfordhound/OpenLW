#include "Hedgehog/Graphics/Resource/hhResFragmentShader.h"
#include "Hedgehog/Graphics/Resource/hhResMiragePixelShaderParameter.h"
#include <Hedgehog/Database/hhSampleChunk.h>
#include <Hedgehog/Utility/hhResShaderAcTypeInfo.h>
#include <Hedgehog/MirageCore/Resource/hhShaderResource.h>
#include <csl/fnd/memory.h>
#include <cstring>

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
    ptr()->Shader = pixelShaderCode.ptr()->CodeData->GetPixelShader();

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
                intConstantCount += pixelShaderParamData->IntConstantCount;
                floatConstantCount += pixelShaderParamData->FloatConstantCount;
                boolConstantCount += pixelShaderParamData->BoolConstantCount;
                samplerCount += pixelShaderParamData->TexSamplerCount;
                ++usageCount;
            }
        }

        if (usageCount == 0)
        {
            return false;
        }

        ptr()->Float4UsageCount = floatConstantCount;
        ptr()->Int4UsageCount = intConstantCount;
        ptr()->BoolUsageCount = boolConstantCount;
        ptr()->TexSamplerCount = samplerCount;

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
        ptr()->BoolUsages = (ptr()->BoolUsageCount != 0) ?
            constUsageData : nullptr;

        constUsageData += (ptr()->BoolUsageCount);

        // Setup texture sampler usages pointer.
        ptr()->TexSamplerUsages = (ptr()->TexSamplerCount != 0) ?
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
                if (pixelShaderParamData->FloatConstantCount != 0)
                {
                    std::memcpy(ptr()->Float4Usages + floatConstantCount,
                        pixelShaderParamData->FloatConstants,
                        pixelShaderParamData->FloatConstantCount *
                        sizeof(ResShaderConstantUsageData));

                    floatConstantCount += pixelShaderParamData->FloatConstantCount;
                }

                if (pixelShaderParamData->IntConstantCount != 0)
                {
                    std::memcpy(ptr()->Int4Usages + intConstantCount,
                        pixelShaderParamData->IntConstants,
                        pixelShaderParamData->IntConstantCount *
                        sizeof(ResShaderConstantUsageData));

                    intConstantCount += pixelShaderParamData->IntConstantCount;
                }

                if (pixelShaderParamData->BoolConstantCount != 0)
                {
                    std::memcpy(ptr()->BoolUsages + boolConstantCount,
                        pixelShaderParamData->BoolConstants,
                        pixelShaderParamData->BoolConstantCount *
                        sizeof(ResShaderConstantUsageData));

                    boolConstantCount += pixelShaderParamData->BoolConstantCount;
                }

                if (pixelShaderParamData->TexSamplerCount != 0)
                {
                    std::memcpy(ptr()->TexSamplerUsages + samplerCount,
                        pixelShaderParamData->TexSamplers,
                        pixelShaderParamData->TexSamplerCount *
                        sizeof(ResShaderSamplerUsageData));

                    samplerCount += pixelShaderParamData->TexSamplerCount;
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
