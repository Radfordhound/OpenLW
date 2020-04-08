#pragma once
#include "csl/fnd/Singleton.h"
#include "../fnd/ReferencedObject.h"

namespace app
{
namespace gfx
{
struct RenderManager : public fnd::ReferencedObject, public csl::fnd::Singleton<RenderManager>
{
    // TODO: Data Members

    class SetupInfo
    {
        const char* ShaderName;
        float AspectRatio;

    public:
        inline void SetAspect(float aspectRatio)
        {
            AspectRatio = aspectRatio;
        }

        inline void SetShaderName(const char* shaderName)
        {
            ShaderName = (shaderName) ? shaderName : "shader.pac";
        }
    };

    struct Impl;

    void Setup(const SetupInfo& setupInfo);
    // TODO: Other Functions
};
}
}
