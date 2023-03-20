#pragma once
#include "hhResVertexShader.h"
#include "hhResFragmentShader.h"

namespace hh
{
namespace gfx
{
namespace res
{
struct ResTechniqueData
{
    ResVertexShader VertexShader;
    ResFragmentShader PixelShader;
    ResNameData VertexShaderName;
    ResNameData PixelShaderName;
    // TODO: Other data members??
};

struct ResTechnique : public ut::ResCommon<ResTechniqueData>
{
    LWAPI(0x0367cbec, TODO)
    ResName GetVSName();

    LWAPI(0x0367cc40, TODO)
    ResName GetFSName();

    inline ResTechnique(const void* data) :
        ResCommon<ResTechniqueData>(data) {}

    inline ResTechnique(void* data = nullptr) :
        ResCommon<ResTechniqueData>(data) {}
};
}
}
}
