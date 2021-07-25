#pragma once
#include <Hedgehog/Base/System/hhObject.h>
#include <Hedgehog/Rsdx/System/RsdxResource.h>
#include <Hedgehog/Rsdx/Graphics/Device/RsdxDevice.h>
#include <Hedgehog/Rsdx/Graphics/Shader/RsdxDeviceShader.h>

namespace hh
{
namespace mr
{
class CRenderingInfrastructure : public base::CObject // size == 0xe40
{
    // TODO: Other data members

public:
    rsdx::RsdxDevice* Device;
    // TODO: Other data members

    // Wii U: 0x036caea4, PC: TODO
    static void ReleaseD3DRenderResource(rsdx::RsdxResource* res);

    // Wii U: 0x036d5bb0, PC: 0x00c2b200
    rsdx::RsdxVertexShader9* CreateVertexShader(const void* data);

    // Wii U: TODO, PC: 0x00c2be50
    CRenderingInfrastructure();

    // Wii U: 0x036d8d84, PC: 0x00c2b490
    void Present();
};
}
}
