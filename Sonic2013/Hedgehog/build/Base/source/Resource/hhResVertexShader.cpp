#include "Hedgehog/Base/Resource/hhResVertexShader.h"
#include "Hedgehog/Base/Resource/hhResShaderAcTypeInfo.h"
#include <Hedgehog/MirageCore/Resource/hhShaderResource.h> // TODO: This doesn't seem right lol. Is the resource stuff even part of HH Base??
#include "Hedgehog/Base/System/hhCSymbol.h" // TODO: REMOVE THIS LINE
#include "Hedgehog/Base/Resource/hhResNameData.h"
#include "Hedgehog/Base/Database/hhSampleChunk.h"
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
    return ResCommon<ResNameData>(&ptr()->field_0x24);
}

void* ResVertexShader::Replace(std::size_t* size, csl::fnd::IAllocator* allocator)
{
    CSampleChunkResource* res = reinterpret_cast<CSampleChunkResource*>(ptr());
    res->ResolvePointer();

    CVertexShaderV2Resource* vtxShader = res->GetData<CVertexShaderV2Resource>();
    *size = (sizeof(ResShaderCommonData) + (vtxShader->ParamsCount() * 0x18)); // TODO: Replace 0x18 with sizeof(param)
    
    ResShaderCommonData* shaderData = static_cast<ResShaderCommonData*>(allocator->Alloc(*size));
    std::memset(shaderData, 0, 0x38); // TODO: Replace this with the constructor for ResShaderCommonData!!!

    ResCommon<ResNameData> aRStack32 = InitResNameData(&shaderData->field_0x24,
        GetUniqueString(vtxShader->CodeResName()));

    // TODO
    return nullptr; // TODO
}

bool ResVertexShader::Setup(unsigned int param_1, csl::fnd::IAllocator* allocator)
{
    return false;
}

bool ResVertexShader::Setup(unsigned int param_1,
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

void ResVertexShader::Cleanup(unsigned int param_1)
{
    Unbind();
    // TODO
}
}
}
}
