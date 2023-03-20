#pragma once
#include <csl/fnd/singleton.h>

namespace csl
{
namespace fnd
{
struct IAllocator;
}
}

namespace hh
{
namespace mr
{
class CRenderingInfrastructure;
}

namespace gfx
{
struct GfxInitParam
{
    unsigned char field_0x0;
    csl::fnd::IAllocator* Allocator;
    mr::CRenderingInfrastructure* RenderInfra;
};

namespace internal
{
// TODO: Should this go in its own file?
class VertexDeclarationRegistry : public csl::fnd::Singleton<VertexDeclarationRegistry>
{
    void* field_0x0;

public:
    LWAPI(0x0366ddf8, TODO)
    VertexDeclarationRegistry();

    LWAPI(0x0366e004, TODO)
    void Initialize(csl::fnd::IAllocator* allocator, bool param_2);
};

LWAPI(0x036654ec, 0x00c0fff0)
mr::CRenderingInfrastructure* GetRenderingInfrastructure();
}

LWAPI(0x036654fc, 0x00c100f0)
void GfxInit(const GfxInitParam& params);
}
}
