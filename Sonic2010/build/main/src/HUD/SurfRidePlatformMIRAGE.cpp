#include "pch.h"
#include "SurfRidePlatformMIRAGE.h"
#include "Render/RenderManager.h"
#include <Hedgehog/Graphics/Resource/hhResVertexShader.h>
#include <Hedgehog/Graphics/Resource/hhResFragmentShader.h>

using namespace app::gfx;
using namespace hh;
using namespace hh::base;
using namespace hh::mr;
using namespace hh::ut;
using namespace hh::rsdx;
using namespace hh::gfx::res;

namespace app
{
namespace HUD
{
boost::shared_ptr<hh::mr::CVertexShaderData>
    CreateGetVertexShaderData(char* param_1)
{
    RenderManager& renderMgr = RenderManager::GetInstance();
    Packfile shaderPac = renderMgr.GetShaderFileResource();

    // TODO: Allocate this using the CHedgehogMemoryAllocatorHeap variant instead!!!
    boost::shared_ptr<CVertexShaderData> vtxShaderData(::new
        (__HH_ALLOC_DBG(sizeof(CVertexShaderData))) CVertexShaderData()); // line: 156

    ResVertexShader RStack112 = shaderPac.Get<ResVertexShader>(param_1);

    // TODO: Allocate this using the CHedgehogMemoryAllocatorHeap variant instead!!!
    vtxShaderData->Code.reset(::new (__HH_ALLOC_DBG(sizeof(
        CVertexShaderCodeData))) CVertexShaderCodeData()); // line: 176

    vtxShaderData->Code->Handle.resetaddref(
        static_cast<RsdxVertexShader9*>(RStack112.ptr()->Shader));

    // TODO: Allocate this using the CHedgehogMemoryAllocatorHeap variant instead!!!
    vtxShaderData->field_0x18.push_back(boost::shared_ptr<CVertexShaderParameterData>(::new
        (__HH_ALLOC_DBG(sizeof(CVertexShaderParameterData))) CVertexShaderParameterData())); // line: 179

    auto& lastParamData = vtxShaderData->field_0x18.back();
    for (std::size_t i = 0; i < RStack112.ptr()->Float4UsageCount; ++i)
    {
        ResShaderConstantUsage curUsage = RStack112.GetFloat4Usage(i);
        CShaderConstantData& curConstant = lastParamData->Floats[
            CStringSymbol(curUsage.GetName())];

        curConstant.SetRegFirstIndex(curUsage.ptr()->RegFirstIndex);
        curConstant.SetRegCount(curUsage.ptr()->RegCount);
    }

    for (std::size_t i = 0; i < RStack112.ptr()->Int4UsageCount; ++i)
    {
        ResShaderConstantUsage curUsage = RStack112.GetInt4Usage(i);
        CShaderConstantData& curConstant = lastParamData->Ints[
            CStringSymbol(curUsage.GetName())];

        curConstant.SetRegFirstIndex(curUsage.ptr()->RegFirstIndex);
        curConstant.SetRegCount(curUsage.ptr()->RegCount);
    }

    for (std::size_t i = 0; i < RStack112.ptr()->Bool4UsageCount; ++i)
    {
        ResShaderConstantUsage curUsage = RStack112.GetBoolUsage(i);
        CShaderConstantData& curConstant = lastParamData->Bools[
            CStringSymbol(curUsage.GetName())];

        curConstant.SetRegFirstIndex(curUsage.ptr()->RegFirstIndex);
        curConstant.SetRegCount(curUsage.ptr()->RegCount);
    }

    vtxShaderData->SetMadeAllFlag();
    return vtxShaderData;
}

boost::shared_ptr<hh::mr::CPixelShaderData>
    CreateGetPixelShaderData(char* param_1)
{
    RenderManager& renderMgr = RenderManager::GetInstance();
    Packfile shaderPac = renderMgr.GetShaderFileResource();

    // TODO: Allocate this using the CHedgehogMemoryAllocatorHeap variant instead!!!
    boost::shared_ptr<CPixelShaderData> pixelShaderData(::new
        (__HH_ALLOC_DBG(sizeof(CPixelShaderData))) CPixelShaderData()); // line: 212

    ResFragmentShader RStack128 = shaderPac.Get<ResFragmentShader>(param_1);

    // TODO: Allocate this using the CHedgehogMemoryAllocatorHeap variant instead!!!
    pixelShaderData->Code.reset(::new (__HH_ALLOC_DBG(sizeof(
        CPixelShaderCodeData))) CPixelShaderCodeData()); // line: 232

    pixelShaderData->Code->Handle.resetaddref(
        static_cast<RsdxPixelShader9*>(RStack128.ptr()->Shader));

    // TODO: Allocate this using the CHedgehogMemoryAllocatorHeap variant instead!!!
    pixelShaderData->field_0x18.push_back(boost::shared_ptr<CPixelShaderParameterData>(::new
        (__HH_ALLOC_DBG(sizeof(CPixelShaderParameterData))) CPixelShaderParameterData())); // line: 235

    auto& lastParamData = pixelShaderData->field_0x18.back();
    for (std::size_t i = 0; i < RStack128.ptr()->Float4UsageCount; ++i)
    {
        ResShaderConstantUsage curUsage = RStack128.GetFloat4Usage(i);
        CShaderConstantData& curConstant = lastParamData->Floats[
            CStringSymbol(curUsage.GetName())];

        curConstant.SetRegFirstIndex(curUsage.ptr()->RegFirstIndex);
        curConstant.SetRegCount(curUsage.ptr()->RegCount);
    }

    for (std::size_t i = 0; i < RStack128.ptr()->Int4UsageCount; ++i)
    {
        ResShaderConstantUsage curUsage = RStack128.GetInt4Usage(i);
        CShaderConstantData& curConstant = lastParamData->Ints[
            CStringSymbol(curUsage.GetName())];

        curConstant.SetRegFirstIndex(curUsage.ptr()->RegFirstIndex);
        curConstant.SetRegCount(curUsage.ptr()->RegCount);
    }

    for (std::size_t i = 0; i < RStack128.ptr()->Bool4UsageCount; ++i)
    {
        ResShaderConstantUsage curUsage = RStack128.GetBoolUsage(i);
        CShaderConstantData& curConstant = lastParamData->Bools[
            CStringSymbol(curUsage.GetName())];

        curConstant.SetRegFirstIndex(curUsage.ptr()->RegFirstIndex);
        curConstant.SetRegCount(curUsage.ptr()->RegCount);
    }

    for (std::size_t i = 0; i < RStack128.ptr()->SamplerUsageCount; ++i)
    {
        ResShaderSamplerUsage curUsage = RStack128.GetSamplerUsage(i);
        std::vector<u8>& curSampler = lastParamData->Textures[
            CStringSymbol(curUsage.GetName())];

        bool uVar12 = false;
        for (std::size_t i2 = 0; i2 < curSampler.size(); ++i2)
        {
            if (curSampler[i2] == ((curUsage.ptr()->RegIndex & 0xf) << 4))
            {
                uVar12 = true;
            }
        }

        if (!uVar12)
        {
            curSampler.push_back(
                ((curUsage.ptr()->RegIndex & 0xf) << 4) |
                curUsage.ptr()->field_0x1);
        }
    }

    pixelShaderData->SetMadeAllFlag();
    return pixelShaderData;
}
}
}
