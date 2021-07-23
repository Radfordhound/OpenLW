#include "Hedgehog/Graphics/Resource/hhResVertexShader.h"
#include "Hedgehog/Graphics/Resource/hhResNameData.h"
#include <Hedgehog/Database/hhSampleChunk.h>
#include <Hedgehog/Utility/hhResShaderAcTypeInfo.h>
#include <Hedgehog/MirageCore/Resource/hhShaderResource.h>
#include <csl/fnd/memory.h>
#include <cstring> // TODO: REMOVE THIS LINE

using namespace hh::mr;
using namespace hh::ut;
using namespace hh::db;
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

ResCommon<ResNameData> ResVertexShader::GetName()
{
    return ResCommon<ResNameData>(&ptr()->CodeResName);
}

void* ResVertexShader::Replace(std::size_t* size, csl::fnd::IAllocator* allocator)
{
    // Resolve sample chunk resource pointers.
    CSampleChunkResource* res = reinterpret_cast<CSampleChunkResource*>(ptr());
    res->ResolvePointer();

    // Get vertex shader resource data.
    CVertexShaderV2Resource* vtxShader = res->GetData<CVertexShaderV2Resource>();

    // Compute total size of shader common data + user data items.
    *size = (sizeof(ResShaderCommonData) + (sizeof(ResUserDataItemData) *
        vtxShader->ParamsCount()));
    
    // Allocate buffer to hold shader common data + user data items.
    ResShaderCommonData* shaderData = static_cast<ResShaderCommonData*>(allocator->Alloc(*size));
    std::memset(shaderData, 0, 0x38); // TODO: Replace this with the constructor for ResShaderCommonData!!!

    // Initialize shader code resource name.
    ResName aRStack32 = InitResNameData(&shaderData->CodeResName,
        GetUniqueString(vtxShader->CodeResName()));

    // Initialize shader user data.
    shaderData->UserData.Items = &shaderData->AllocatorData;
    shaderData->UserData.ItemCount = (vtxShader->ParamsCount() + 1);
    
    // Initialize user data for shader allocator.
    shaderData->AllocatorData.Index = 0;
    shaderData->AllocatorData.Size = sizeof(csl::fnd::IAllocator*);
    shaderData->AllocatorData.Count = 1;
    shaderData->AllocatorData.Data = allocator;

    ResName RStack28 = InitResNameData(&shaderData->AllocatorData.Name,
        GetUniqueString("allocator"));

    // Initialize user data for shader usages.
    const char* usageStr = GetUniqueString("usage");
    unsigned int usageStrHash = CalcHashKey("usage", std::strlen("usage"));

    for (u32 i = 0; i < vtxShader->ParamsCount(); ++i)
    {
        ResUserDataItemData& curUserData = shaderData->UserData.Items[i + 1];
        const char* curParamResName = vtxShader->ParamResNames()[i];

        curUserData.Index = (i + 1);
        curUserData.Size = sizeof(char);
        curUserData.Count = std::strlen(curParamResName);
        curUserData.Data = GetUniqueString(curParamResName);
        curUserData.Name.Hash = usageStrHash;
        curUserData.Name.String = usageStr;
    }

    return shaderData;
}

bool ResVertexShader::Setup(std::size_t size, csl::fnd::IAllocator* allocator)
{
    return false;
}

bool ResVertexShader::Setup(std::size_t size,
    csl::fnd::IAllocator* allocator, ut::Packfile pac)
{
    ResCommon<ResNameData> name = GetName();

    // TODO
    return false;
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
