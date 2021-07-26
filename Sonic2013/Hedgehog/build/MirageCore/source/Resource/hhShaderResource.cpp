#include "Hedgehog/MirageCore/Resource/hhShaderResource.h"
#include "Hedgehog/MirageCore/Misc/hhRenderingInfrastructure.h"

namespace hh
{
namespace mr
{
void CVertexShaderCodeData::Make(CVertexShaderCodeData* param_1,
    const u32* param_2, CRenderingInfrastructure* renderInfra)
{
    param_1->m_vtxShaderPtr.reset(renderInfra->CreateVertexShader(param_2));
    param_1->SetMadeOne();
}

void CPixelShaderCodeData::Make(CPixelShaderCodeData* param_1,
    const u32* param_2, CRenderingInfrastructure* renderInfra)
{
    param_1->m_pixelShaderPtr.reset(renderInfra->CreatePixelShader(param_2));
    param_1->SetMadeOne();
}

CShaderConstantNameData::CShaderConstantNameData() :
    map<base::CStringSymbol, CShaderConstantData>() {}

CVertexShaderParameterData::~CVertexShaderParameterData() {}
}
}
