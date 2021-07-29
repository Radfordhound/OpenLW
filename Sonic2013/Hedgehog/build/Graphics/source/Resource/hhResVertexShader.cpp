#include "Hedgehog/Graphics/Resource/hhResVertexShader.h"
#include "Hedgehog/Graphics/Resource/hhResMirageVertexShaderParameter.h"
#include "Hedgehog/Graphics/Resource/hhResShaderAcTypeInfo.h"
#include <Hedgehog/Database/hhSampleChunk.h>
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
const ResourceTypeInfo& ResVertexShader::staticTypeInfo()
{
    return ResVertexShaderTypeInfo;
}

ResName ResVertexShader::GetName()
{
    return ResName(&ptr()->CodeResName);
}

ResUserData ResVertexShader::GetResUserData()
{
    return ResUserData(&ptr()->UserData);
}

void* ResVertexShader::Replace(std::size_t* size, csl::fnd::IAllocator* allocator)
{
    // Resolve sample chunk resource pointers.
    CSampleChunkResource* res = reinterpret_cast<CSampleChunkResource*>(ptr());
    res->ResolvePointer();

    // Get vertex shader resource data.
    CVertexShaderV2Resource* vtxShaderData = res->GetData<CVertexShaderV2Resource>();

    // Compute total size of shader common data + user data items.
    *size = (sizeof(ResShaderCommonData) + (sizeof(ResUserDataItemData) *
        (vtxShaderData->ParamsCount() + 1)));
    
    // Allocate buffer to hold shader common data + user data items.
    ResShaderCommonData* shader = static_cast<ResShaderCommonData*>(allocator->Alloc(*size));

    // Setup common shader data.
    std::memset(shader, 0, sizeof(ResShaderCommonData));

    // Initialize shader code resource name.
    ResName aRStack32 = InitResNameData(&shader->CodeResName,
        GetUniqueString(vtxShaderData->CodeResName()));

    // Initialize shader user data.
    shader->UserData.Items = reinterpret_cast<ResUserDataItemData*>(shader + 1);
    shader->UserData.ItemCount = (vtxShaderData->ParamsCount() + 1);
    
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

    for (u32 i = 0; i < vtxShaderData->ParamsCount(); ++i)
    {
        ResUserDataItemData& curUserData = shader->UserData.Items[i + 1];
        const char* curParamResName = vtxShaderData->ParamResNames()[i];

        curUserData.Index = (i + 1);
        curUserData.Size = sizeof(char);
        curUserData.Count = std::strlen(curParamResName);
        curUserData.Data = GetUniqueString(curParamResName);
        curUserData.Name.Hash = usageStrHash;
        curUserData.Name.String = usageStr;
    }

    return shader;
}

bool ResVertexShader::Setup(std::size_t size, csl::fnd::IAllocator* allocator)
{
    return false;
}

bool ResVertexShader::Setup(std::size_t size,
    csl::fnd::IAllocator* allocator, ut::Packfile pac)
{
    ResName codeResName = GetName();
    ResMirageVertexShaderCode vtxShaderCode = pac.Get<ResMirageVertexShaderCode>(codeResName);
    ptr()->Shader = vtxShaderCode.ptr()->CodeData->GetVertexShader();

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
        std::size_t usageCount = 0;

        for (std::size_t i = 1; i < userData.ptr()->ItemCount; ++i)
        {
            ResUserDataItem usageItem = userData.GetResUserDataItem(i);
            auto vtxShaderParam = pac.Get<ResMirageVertexShaderParameter>(
                usageItem.GetDataPtr<const char>());

            if (vtxShaderParam.IsValid())
            {
                ResMirageVertexShaderParameterData* vtxShaderParamData = vtxShaderParam.ptr();
                intConstantCount += vtxShaderParamData->IntConstantCount;
                floatConstantCount += vtxShaderParamData->FloatConstantCount;
                boolConstantCount += vtxShaderParamData->BoolConstantCount;
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

        IAllocator* shaderAllocator = static_cast<IAllocator*>(ptr()->UserData.Items->Data);
        
        // Allocate buffer for constant usage data.
        auto constUsageData = static_cast<ResShaderConstantUsageData*>(shaderAllocator->Alloc(
            (floatConstantCount + intConstantCount + boolConstantCount) *
            sizeof(ResShaderConstantUsageData)));

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

        floatConstantCount = 0;
        intConstantCount = 0;
        boolConstantCount = 0;

        for (std::size_t i = 1; i < userData.ptr()->ItemCount; ++i)
        {
            ResUserDataItem usageItem = userData.GetResUserDataItem(i);
            auto vtxShaderParam = pac.Get<ResMirageVertexShaderParameter>(
                usageItem.GetDataPtr<const char>());
            
            if (vtxShaderParam.IsValid())
            {
                ResMirageVertexShaderParameterData* vtxShaderParamData = vtxShaderParam.ptr();
                if (vtxShaderParamData->FloatConstantCount != 0)
                {
                    std::memcpy(ptr()->Float4Usages + floatConstantCount,
                        vtxShaderParamData->FloatConstants,
                        vtxShaderParamData->FloatConstantCount *
                        sizeof(ResShaderConstantUsageData));

                    floatConstantCount += vtxShaderParamData->FloatConstantCount;
                }

                if (vtxShaderParamData->IntConstantCount != 0)
                {
                    std::memcpy(ptr()->Int4Usages + intConstantCount,
                        vtxShaderParamData->IntConstants,
                        vtxShaderParamData->IntConstantCount *
                        sizeof(ResShaderConstantUsageData));

                    intConstantCount += vtxShaderParamData->IntConstantCount;
                }

                if (vtxShaderParamData->BoolConstantCount != 0)
                {
                    std::memcpy(ptr()->Bool4Usages + boolConstantCount,
                        vtxShaderParamData->BoolConstants,
                        vtxShaderParamData->BoolConstantCount *
                        sizeof(ResShaderConstantUsageData));

                    boolConstantCount += vtxShaderParamData->BoolConstantCount;
                }
            }
        }

        ptr()->SamplerUsages = nullptr;
        ptr()->SamplerUsageCount = 0;
    }

    return true;
}

void ResVertexShader::Unbind()
{
    // TODO
}

void ResVertexShader::Cleanup(std::size_t size)
{
    Unbind();
    // TODO
}
}
}
}
