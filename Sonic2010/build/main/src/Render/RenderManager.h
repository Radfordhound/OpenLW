#pragma once
#include "RenderSceneView.h"
#include "System/UpdateInfo.h"
#include "System/Singleton.h"
#include <Hedgehog/MirageCore/Misc/hhRenderingInfrastructure.h>
#include <Hedgehog/Utility/hhPackfile.h>

namespace app
{
namespace gfx
{
struct Renderable;

class RenderManager : public fnd::ReferencedObject, public csl::fnd::Singleton<RenderManager>
{
OPENLW_PRIVATE
    struct Impl;
    Impl* m_impl;

public:
    struct SetupInfo
    {
        const char* ShaderName;
        float AspectRatio;

        inline void SetAspect(float aspectRatio)
        {
            AspectRatio = aspectRatio;
        }

        inline void SetShaderName(const char* shaderName)
        {
            ShaderName = (shaderName) ? shaderName : "shader.pac";
        }

        // TODO: Is this actually a thing?
        inline SetupInfo() :
            ShaderName(nullptr),
            AspectRatio(0) {}
    };

    LWAPI(0x02258a98, NONE)
    RenderManager();

    LWAPI(0x02258b10, 0x004e7f70)
    static RenderManager* Create(csl::fnd::IAllocator* allocator);

    LWAPI(0x02258ec0, TODO)
    void Setup(const SetupInfo& setupInfo);

    LWAPI(0x02258fc8, TODO)
    void Shutdown();

    LWAPI(0x02259eec, TODO)
    void Update(const fnd::SUpdateInfo& updateInfo, unsigned int param_2);

    LWAPI(0x0225a014, 0x004e1c10)
    hh::mr::CRenderingInfrastructure* GetRenderingDevice() const;

    LWAPI(0x02263c70, TODO)
    void RenderNoPresent();

    LWAPI(0x02263cf4, 0x004ee530)
    void Render();

    LWAPI(0x02263d28, TODO)
    void Present();

    LWAPI(0x02263d4c, TODO)
    CRenderSceneView* GetDefaultScene() const;

    LWAPI(0x02264694, TODO)
    hh::ut::Packfile GetShaderFileResource() const;

    LWAPI(0x022646c0, TODO)
    void AddRenderable(Renderable* renderable);
};
}
}
