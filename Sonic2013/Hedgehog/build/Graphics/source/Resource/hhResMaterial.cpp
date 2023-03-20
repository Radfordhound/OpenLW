#include "pch.h"
#include "Hedgehog/Graphics/Resource/hhResMaterial.h"
#include "Hedgehog/Graphics/Resource/hhResMaterialAcTypeInfo.h"
#include "Hedgehog/Graphics/Resource/hhResShaderConstant.h"
#include "Hedgehog/Graphics/Resource/hhResShaderSampler.h"
#include <Hedgehog/MirageCore/Resource/hhMaterialResource.h>
#include <Hedgehog/Database/hhSampleChunk.h>
#include <csl/fnd/memory.h>
#include <csl/ut/number.h>

using namespace hh::db;
using namespace hh::mr;
using namespace hh::gfx::res::detail;
using namespace hh::gfx::internal;
using namespace csl::ut;

namespace hh
{
namespace gfx
{
namespace res
{
const ut::ResourceTypeInfo& ResMaterial::staticTypeInfo()
{
    return ResMaterialTypeInfo;
}

ResName ResMaterial::GetName()
{
    return ResName(&ptr()->Name);
}

ResUserData ResMaterial::GetResUserData()
{
    return ResUserData(ptr() + 1);
}

void* ResMaterial::Replace(const char* param_1, std::size_t* size, csl::fnd::IAllocator* allocator)
{
    // Resolve sample chunk resource pointers.
    CSampleChunkResource2* resV2 = reinterpret_cast<CSampleChunkResource2*>(ptr());
    CMaterialV3Resource* matRes = nullptr;
    unsigned int matFlags = 0;
    unsigned char transPriority = 0;

    if (resV2->IsV2())
    {
        resV2->ResolvePointer();
        CSampleChunkNode* curNode = resV2->GetData<CSampleChunkNode>();

        while (curNode)
        {
            if (curNode->NameEquals("Material") && !curNode->IsLeaf())
            {
                CSampleChunkNode* curMatNode = curNode->GetData<CSampleChunkNode>();
                while (curMatNode)
                {
                    if (curMatNode->NameEquals("Contexts"))
                    {
                        matRes = curMatNode->GetData<CMaterialV3Resource>();
                    }
                    else if (curMatNode->NameEquals("SCAParam") && !curMatNode->IsLeaf())
                    {
                        CSampleChunkNode* curSCAParam = curMatNode->GetData<CSampleChunkNode>();
                        while (curSCAParam)
                        {
                            if (curSCAParam->NameEquals("UseGrass"))
                            {
                                matFlags |= MAT_FLAG_USE_GRASS;
                            }
                            else if (curSCAParam->NameEquals("ExtnAABB"))
                            {
                                matFlags |= MAT_FLAG_EXTN_AABB;
                            }
                            else if (curSCAParam->NameEquals("TrnsPrio"))
                            {
                                transPriority = curSCAParam->GetValue();
                            }
                            else if (curSCAParam->NameEquals("UsePrior"))
                            {
                                if (curSCAParam->GetValue() != 0)
                                {
                                    matFlags |= MAT_FLAG_USE_PRIOR;
                                }
                            }
                            else if (curSCAParam->NameEquals("TrnsType"))
                            {
                                matFlags |= (curSCAParam->GetValue() & 0xFF); // TODO: Is this correct on PC?
                            }

                            curSCAParam = curSCAParam->GetNext();
                        }
                    }

                    curMatNode = curMatNode->GetNext();
                }
            }

            curNode = curNode->GetNext();
        }
    }
    else
    {
        CSampleChunkResource* resV1 = reinterpret_cast<CSampleChunkResource*>(resV2);
        resV1->ResolvePointer();
        matRes = resV1->GetData<CMaterialV3Resource>();
    }

    std::size_t unembeddedFloatParamCount = 0;
    std::size_t newSize = (sizeof(ResMaterialData) + sizeof(ResUserDataItemData));

    if (matRes->GetFloatParamCount() != 0)
    {
        for (unsigned int i = 0; i < matRes->GetFloatParamCount(); ++i)
        {
            const auto* curParam = matRes->GetFloatParam(i);
            const char* curParamName = curParam->GetName();
            
            if (std::strcmp(curParamName, "diffuse") != 0 &&
                std::strcmp(curParamName, "ambient") != 0 &&
                std::strcmp(curParamName, "specular") != 0 &&
                std::strcmp(curParamName, "emissive") != 0 &&
                std::strcmp(curParamName, "power_gloss_level") != 0 &&
                std::strcmp(curParamName, "opacity_reflection_refraction_spectype") != 0 &&
                std::strlen(curParamName) != 0)
            {
                ++unembeddedFloatParamCount;
                newSize += (sizeof(float[4]) * curParam->GetValueCount());
            }
        }

        if (unembeddedFloatParamCount != 0)
        {
            newSize += 15; // TODO: What are these extra 15 bytes for? Alignment??
        }
    }

    if (matRes->GetIntParamCount() != 0)
    {
        for (unsigned int i = 0; i < matRes->GetIntParamCount(); ++i)
        {
            const auto* curParam = matRes->GetIntParam(i);
            newSize += (sizeof(int[4]) * curParam->GetValueCount());
        }

        newSize += 15; // TODO: What are these extra 15 bytes for? Alignment??
    }

    *size = (newSize + (sizeof(ResShaderConstantData) * unembeddedFloatParamCount) +
        (sizeof(ResShaderConstantData) * matRes->GetIntParamCount()) +
        (sizeof(ResShaderSamplerData) * matRes->GetTextureCount()));

    ResMaterialData* matData = static_cast<ResMaterialData*>(allocator->Alloc(*size));

    // Setup material data.
    std::size_t curOff = sizeof(ResMaterialData);
    std::memset(matData, 0, sizeof(ResMaterialData));

    matData->Shader = nullptr;
    matData->Flags1 = matRes->GetFlags();
    matData->BackfaceCulling = matRes->UseBackfaceCulling();
    matData->UseAdditiveBlending = matRes->UseAdditiveBlending();
    matData->TransPriority = transPriority;
    matData->Flags2 = matFlags;

    if (!matRes->GetShaderName())
    {
        matData->ShaderName.Hash = 0;
        matData->ShaderName.String = nullptr;
    }
    else
    {
        InitResNameData(&matData->ShaderName,
            GetUniqueString(matRes->GetShaderName()));
    }

    if (!param_1)
    {
        matData->Name.Hash = 0;
        matData->Name.String = nullptr;
    }
    else
    {
        InitResNameData(&matData->Name,
            GetUniqueString(param_1));
    }

    matData->Params.Float4Constants = nullptr;
    matData->Params.Int4Constants = nullptr;
    matData->Params.Bool4Constants = nullptr;
    matData->Params.Samplers = nullptr;
    matData->Params.Float4ConstantCount = unembeddedFloatParamCount;
    matData->Params.Int4ConstantCount = matRes->GetIntParamCount();
    matData->Params.Bool4ConstantCount = 0;
    matData->Params.SamplerCount = matRes->GetTextureCount();

    if (unembeddedFloatParamCount != 0)
    {
        matData->Params.Float4Constants = reinterpret_cast<ResShaderConstantData*>(matData + 1);

        std::uintptr_t local_80 = reinterpret_cast<std::uintptr_t>(
            matData->Params.Float4Constants + unembeddedFloatParamCount);

        curOff = static_cast<std::size_t>(RoundUp(local_80, 16) -
            reinterpret_cast<std::uintptr_t>(matData));
    }

    for (std::size_t i = 0; i < matRes->GetFloatParamCount(); ++i)
    {
        const auto* curParam = matRes->GetFloatParam(i);
        const char* curParamName = curParam->GetName();

        if (std::strcmp(curParamName, "diffuse") == 0)
        {
            for (std::size_t i2 = 0; i2 < 3; ++i2)
            {
                matData->Diffuse[i2] = curParam->GetValue(0)[i2];
            }

            matData->Diffuse[3] = 1.0f;
        }

        // TODO
    }

    // TODO
    return matData;
}

bool ResMaterial::Setup(std::size_t size, csl::fnd::IAllocator* allocator)
{
    return false;
}

bool ResMaterial::Setup(std::size_t size, csl::fnd::IAllocator* allocator, ut::Packfile pac)
{
    // TODO
    return false;
}

void ResMaterial::Unbind()
{
    // TODO
}

void ResMaterial::Cleanup(std::size_t size)
{
    // TODO
}
}
}
}
