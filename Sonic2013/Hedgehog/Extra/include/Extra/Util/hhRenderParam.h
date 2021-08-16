#pragma once

namespace hh
{
namespace mr
{
class CRenderingInfrastructure;
class CRenderingDevice;
}
}

namespace Extra
{
namespace fx
{
struct SDrawInstanceParam;

struct SRenderParamInitializeParameter // TODO: Inheritance? // size == 68
{
    // TODO
};

struct SDebugParameters // TODO: Move this to another header?
{
    SDrawInstanceParam* field_0x0;
    unsigned int field_0x4;
    // TODO: Other data members??
};

struct SRenderDevice // TODO: Move this to another header?
{
    hh::mr::CRenderingInfrastructure* RenderInfra;
    hh::mr::CRenderingDevice* RenderDevice;
    // TODO: Other data members??
};
}
}
