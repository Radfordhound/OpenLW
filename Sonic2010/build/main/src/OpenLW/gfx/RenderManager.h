#pragma once
#include "../fnd/SUpdateInfo.h"
#include "../fnd/ReferencedObject.h"
#include "../fnd/Singleton.h"
#include <Hedgehog/MirageCore/Misc/hhRenderingInfrastructure.h>
#include <Hedgehog/Utility/hhPackfile.h>

namespace app
{
namespace gfx
{
class RenderManager : public fnd::ReferencedObject, public csl::fnd::Singleton<RenderManager>
{
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

    // Wii U: 0x02258a98, PC: Inlined
    RenderManager();

    // Wii U: 0x02258b10, PC: 0x004e7f70
    static RenderManager* Create(csl::fnd::IAllocator* allocator);

    // Wii U: 0x02258ec0, PC: TODO
    void Setup(const SetupInfo& setupInfo);

    // Wii U: 0x02258fc8 (THUNK), PC: TODO
    void Shutdown();

    // Wii U: 0x02259eec, PC: TODO
    void Update(const fnd::SUpdateInfo& updateInfo, unsigned int param_2);

    // Wii U: 0x0225a014, PC: 0x004e1c10
    hh::mr::CRenderingInfrastructure* GetRenderingDevice() const;

    // Wii U: 0x02263c70, PC: TODO
    void RenderNoPresent();

    // Wii U: 0x02263cf4, PC: 0x004ee530
    void Render();

    // Wii U: 0x02263d28, PC: TODO
    void Present();

    // Wii U: 0x02264694, PC: TODO
    hh::ut::Packfile GetShaderFileResource() const;
};
}
}
