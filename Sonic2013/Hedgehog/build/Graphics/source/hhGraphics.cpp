#include "pch.h"
#include "Hedgehog/Graphics/hhGraphics.h"
#include <csl/fnd/memory.h>

namespace hh
{
namespace gfx
{
namespace internal
{
LWAPI(0x104012e8, 0x011d6dac)
static GfxInitParam GfxParameters;

VertexDeclarationRegistry::VertexDeclarationRegistry() :
    field_0x0(nullptr) {}

void VertexDeclarationRegistry::Initialize(csl::fnd::IAllocator* allocator, bool param_2)
{
    // TODO
}

mr::CRenderingInfrastructure* GetRenderingInfrastructure()
{
    return GfxParameters.RenderInfra;
}
}

void GfxInit(const GfxInitParam& params)
{
    internal::GfxParameters = params;

    auto vtxDeclReg = new (params.Allocator, 1) internal::VertexDeclarationRegistry();
    // TODO
}
}
}
