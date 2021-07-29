#include "Hedgehog/Graphics/Resource/hhResShaderAc.h"
#include <Hedgehog/Database/hhSampleChunk.h>
#include <Hedgehog/MirageCore/Resource/hhShaderResource.h>

using namespace hh::db;
using namespace hh::mr;
using namespace hh::gfx::res::detail;
using namespace hh::gfx::internal;

namespace hh
{
namespace gfx
{
namespace res
{
ResTechnique ResShader::GetResTechnique(std::size_t index) const
{
    return (index < ptr()->TechniqueCount) ?
        ResTechnique(ptr()->Techniques + index) :
        ResTechnique();
}

ResParameter ResShader::GetDefaultParameter()
{
    return ResParameter(&ptr()->DefaultParameter);
}

ResMapChannelFixed ResShader::GetResMapChannelFixed(std::size_t index)
{
    return (index < ptr()->field_0x2c) ?
        ResMapChannelFixed(ptr()->field_0x28 + index) :
        ResMapChannelFixed();
}

ResName ResShader::GetName()
{
    return ResName(&ptr()->Name);
}

ResUserData ResShader::GetResUserData()
{
    return ResUserData(&ptr()->UserData);
}

// Wii U: 0x1031ec58, PC: TODO
static const char* const VertexShaderSubPermutations[] = // TODO: This name was guessed.
{
    "",
    "_ConstTexCoord"
};

// Wii U: 0x1031ec60, PC: TODO
static const char* const PixelShaderSubPermutations[] = // TODO: This name was guessed.
{
    "",
    "_ConstTexCoord",
    "_NoGI",
    "_NoGI_ConstTexCoord",
    "_NoLight",
    "_NoLight_ConstTexCoord",
    "_NoLight_NoGI",
    "_NoLight_NoGI_ConstTexCoord"
};

// Wii U: 0x0367cf38, PC: TODO
static void* ShaderList2ResShader(CShaderListV0Resource* shaderListRes,
    const char* name, std::size_t* size, csl::fnd::IAllocator* allocator)
{
    const char* vsNoneSubPermutationNames[HH_COUNT_OF(VertexShaderSubPermutations)];
    std::size_t vsNoneSubPermutationHashes[HH_COUNT_OF(VertexShaderSubPermutations)];
    const char* vsPSubPermutationNames[HH_COUNT_OF(VertexShaderSubPermutations)];
    std::size_t vsPSubPermutationHashes[HH_COUNT_OF(VertexShaderSubPermutations)];

    const char* psDefaultSubPermutationNames[HH_COUNT_OF(PixelShaderSubPermutations)];
    std::size_t psDefaultSubPermutationHashes[HH_COUNT_OF(PixelShaderSubPermutations)];

    char local_24c[512];

    const char* psDefaultShaderName = nullptr;
    const char* vsPShaderName = nullptr;
    const char* vsNoneShaderName = nullptr;
    std::size_t techniqueCount = 0;

    if (shaderListRes->GetPixelPermutationCount() != 0)
    {
        for (u32 i = 0; i < shaderListRes->GetPixelPermutationCount(); ++i)
        {
            auto pixelPermutation = shaderListRes->GetPixelPermutation(i);
            if (std::strcmp(pixelPermutation->GetName(), "default") == 0)
            {
                psDefaultShaderName = pixelPermutation->GetShaderName();
                if (pixelPermutation->GetVertexPermutationCount() != 0)
                {
                    for (u32 i2 = 0; i2 < pixelPermutation->GetVertexPermutationCount(); ++i2)
                    {
                        auto vertexPermutation = pixelPermutation->GetVertexPermutation(i2);

                        if (std::strcmp(vertexPermutation->GetName(), "none") == 0)
                        {
                            vsNoneShaderName = vertexPermutation->GetShaderName();
                            techniqueCount += HH_COUNT_OF(PixelShaderSubPermutations);
                        }
                        else if (std::strcmp(vertexPermutation->GetName(), "p") == 0)
                        {
                            vsPShaderName = vertexPermutation->GetShaderName();
                            techniqueCount += HH_COUNT_OF(PixelShaderSubPermutations);
                        }
                    }
                }
            }
        }
    }

    *size = (sizeof(ResShaderData) +
        (sizeof(ResTechniqueData) * techniqueCount) +
        // TODO: Account for whatever the second array of things in the shader list data is.
        (sizeof(ResMapChannelFixedData) * shaderListRes->GetMapChannelFixedCount()) +
        sizeof(ResUserDataItemData) // TODO: Account for the missing 15 bytes properly
        );

    ResShaderData* shaderData = static_cast<ResShaderData*>(allocator->Alloc(*size));
    std::memset(shaderData, 0, sizeof(ResShaderData));

    InitResNameData(&shaderData->Name, GetUniqueString(name));

    shaderData->TechniqueCount = techniqueCount;
    shaderData->Techniques = reinterpret_cast<ResTechniqueData*>(shaderData + 1);

    if (techniqueCount != 0)
    {
        for (std::size_t i = 0; i < techniqueCount; ++i)
        {
            shaderData->Techniques[i].VertexShader = nullptr;
            shaderData->Techniques[i].PixelShader = nullptr;
        }
    }

    shaderData->DefaultParameter.field_0x14 = 0;
    // TODO
    shaderData->DefaultParameter.field_0x8 = 0;
    shaderData->DefaultParameter.NumSamplers = 0;
    shaderData->DefaultParameter.field_0x18 = 0;
    shaderData->DefaultParameter.field_0x4 = 0;
    shaderData->DefaultParameter.ShaderSamplers = nullptr;

    std::size_t curOff = (sizeof(ResShaderData) +
        (sizeof(ResTechniqueData) * techniqueCount) +
        0 // TODO: Account for whatever the second array of things in the shader list data is.
        );

    // TODO

    shaderData->field_0x2c = shaderListRes->GetMapChannelFixedCount();
    shaderData->field_0x28 = PtrAdd<ResMapChannelFixedData>(shaderData, curOff);

    if (shaderListRes->GetMapChannelFixedCount() != 0)
    {
        for (std::size_t i = 0; i < shaderData->field_0x2c; ++i)
        {
            auto curMapChannelFixed = shaderListRes->GetMapChannelFixed(i);

            InitResNameData(&shaderData->field_0x28[i].SlotName,
                GetUniqueString(curMapChannelFixed->GetSlotName()));

            shaderData->field_0x28[i].field_0x8 = curMapChannelFixed->GetValue();
        }
    }

    ResUserDataItemData* allocatorUserData = PtrAdd<ResUserDataItemData>(
        shaderData, curOff + (sizeof(ResMapChannelFixedData) *
            shaderListRes->GetMapChannelFixedCount()));

    allocatorUserData->Index = 0;
    allocatorUserData->Size = sizeof(csl::fnd::IAllocator*);
    allocatorUserData->Count = 1;
    allocatorUserData->Data = allocator;

    InitResNameData(&allocatorUserData->Name,
        GetUniqueString("allocator"));

    shaderData->UserData.Items = allocatorUserData;
    shaderData->UserData.ItemCount = 1;

    if (!psDefaultShaderName)
    {
        for (std::size_t i = 0; i < HH_COUNT_OF(PixelShaderSubPermutations); ++i)
        {
            // Store sub-permutation name and index.
            psDefaultSubPermutationNames[i] = nullptr;
            psDefaultSubPermutationHashes[i] = 0;
        }
    }
    else
    {
        const std::size_t psDefaultShaderNameLen = std::strlen(psDefaultShaderName);
        for (std::size_t i = 0; i < HH_COUNT_OF(PixelShaderSubPermutations); ++i)
        {
            // Assemble full pixel shader name.
            std::strcpy(local_24c, psDefaultShaderName);
            std::strcpy(local_24c + psDefaultShaderNameLen, PixelShaderSubPermutations[i]);

            // Store sub-permutation name and index.
            psDefaultSubPermutationNames[i] = GetUniqueString(local_24c);
            psDefaultSubPermutationHashes[i] = CalcHashKey(local_24c, std::strlen(local_24c));
        }
    }

    if (vsNoneShaderName)
    {
        const std::size_t vsNoneShaderNameLen = std::strlen(vsNoneShaderName);
        for (std::size_t i = 0; i < HH_COUNT_OF(VertexShaderSubPermutations); ++i)
        {
            // Assemble full vertex shader name.
            std::strcpy(local_24c, vsNoneShaderName);
            std::strcpy(local_24c + vsNoneShaderNameLen, VertexShaderSubPermutations[i]);

            // Store sub-permutation name and index.
            vsNoneSubPermutationNames[i] = GetUniqueString(local_24c);
            vsNoneSubPermutationHashes[i] = CalcHashKey(local_24c, std::strlen(local_24c));
        }

        for (std::size_t i = 0; i < HH_COUNT_OF(PixelShaderSubPermutations); ++i)
        {
            ResTechniqueData& curTechnique = shaderData->Techniques[i];

            curTechnique.VertexShaderName.Hash = vsNoneSubPermutationHashes[
                i & HH_PS_SUB_PERMUTATION_NONE]; // TODO: Should we use HH_VS_SUB_PERMUTATION_NONE instead?

            curTechnique.VertexShaderName.String = vsNoneSubPermutationNames[
                i & HH_PS_SUB_PERMUTATION_NONE]; // TODO: Should we use HH_VS_SUB_PERMUTATION_NONE instead?

            curTechnique.PixelShaderName.Hash = psDefaultSubPermutationHashes[i];
            curTechnique.PixelShaderName.String = psDefaultSubPermutationNames[i];
        }
    }

    if (vsPShaderName)
    {
        const std::size_t vsPShaderNameLen = std::strlen(vsPShaderName);
        for (std::size_t i = 0; i < HH_COUNT_OF(VertexShaderSubPermutations); ++i)
        {
            // Assemble full vertex shader name.
            std::strcpy(local_24c, vsPShaderName);
            std::strcpy(local_24c + vsPShaderNameLen, VertexShaderSubPermutations[i]);

            // Store sub-permutation name and index.
            vsPSubPermutationNames[i] = GetUniqueString(local_24c);
            vsPSubPermutationHashes[i] = CalcHashKey(local_24c, std::strlen(local_24c));
        }

        for (std::size_t i = 0; i < HH_COUNT_OF(PixelShaderSubPermutations); ++i)
        {
            ResTechniqueData& curTechnique = shaderData->Techniques[i +
                HH_COUNT_OF(PixelShaderSubPermutations)];

            curTechnique.VertexShaderName.Hash = vsPSubPermutationHashes[
                i & HH_PS_SUB_PERMUTATION_NONE]; // TODO: Should we use HH_VS_SUB_PERMUTATION_NONE instead?

            curTechnique.VertexShaderName.String = vsPSubPermutationNames[
                i & HH_PS_SUB_PERMUTATION_NONE]; // TODO: Should we use HH_VS_SUB_PERMUTATION_NONE instead?

            curTechnique.PixelShaderName.Hash = psDefaultSubPermutationHashes[i];
            curTechnique.PixelShaderName.String = psDefaultSubPermutationNames[i];
        }
    }

    return shaderData;
}

void* ResShader::Replace(const char* name, std::size_t* size,
    csl::fnd::IAllocator* allocator)
{
    // Resolve sample chunk resource pointers.
    CSampleChunkResource* res = reinterpret_cast<CSampleChunkResource*>(ptr());
    res->ResolvePointer();

    // Get shader list resource data.
    CShaderListV0Resource* shaderListRes = res->GetData<CShaderListV0Resource>();

    // Replace resource.
    return ShaderList2ResShader(shaderListRes, name, size, allocator);
}

bool ResShader::Setup(std::size_t size, csl::fnd::IAllocator* allocator)
{
    return false;
}

bool ResShader::Setup(std::size_t size, csl::fnd::IAllocator* allocator, ut::Packfile pac)
{
    for (std::size_t i = 0; i < ptr()->TechniqueCount; ++i)
    {
        ResTechnique curTechnique = GetResTechnique(i);
        ResVertexShader local_68;
        ResVertexShader vtxShader = curTechnique.ptr()->VertexShader;

        if (!vtxShader.IsValid())
        {
            local_68 = pac.Get<ResVertexShader>(curTechnique.GetVSName());
            if (!local_68.IsValid())
            {
                ResTechnique fallbackTechnique = GetResTechnique(0);
                local_68 = pac.Get<ResVertexShader>(fallbackTechnique.GetVSName());
            }
        }

        ResFragmentShader local_6c;
        ResFragmentShader pixelShader = curTechnique.ptr()->PixelShader;

        if (!pixelShader.IsValid())
        {
            local_6c = pac.Get<ResFragmentShader>(curTechnique.GetFSName());

            for (std::size_t i2 = i; !local_6c.IsValid() && i2 != 0; --i2)
            {
                ResTechnique fallbackTechnique = GetResTechnique(i2 & i);
                local_6c = pac.Get<ResFragmentShader>(fallbackTechnique.GetFSName());
            }
        }

        if (local_68.IsValid())
        {
            curTechnique.ptr()->VertexShader = local_68.ptr();
            if (curTechnique.GetVSName() != local_68.GetName())
            {
                *curTechnique.GetVSName().ptr() = *local_68.GetName().ptr();
            }
        }

        if (local_6c.IsValid())
        {
            curTechnique.ptr()->PixelShader = local_6c.ptr();
            if (curTechnique.GetFSName() != local_6c.GetName())
            {
                *curTechnique.GetFSName().ptr() = *local_6c.GetName().ptr();
            }
        }
    }

    for (std::size_t i = 0; i < ptr()->TechniqueCount; ++i)
    {
        ResTechnique curTechnique = GetResTechnique(i);
        ResVertexShader RStack24 = curTechnique.ptr()->VertexShader;

        if (!RStack24.IsValid())
        {
            return false;
        }

        ResFragmentShader RStack20 = curTechnique.ptr()->PixelShader;
        if (!RStack20.IsValid())
        {
            return false;
        }
    }

    return true;
}

void ResShader::Cleanup(std::size_t index)
{
    if (ptr()->UserData.Items)
    {
        csl::fnd::IAllocator* allocator = static_cast<csl::fnd::IAllocator*>(
            ptr()->UserData.Items[0].Data);
        
        allocator->Free(this); // TODO: Is this correct?
    }
}
}
}
}
