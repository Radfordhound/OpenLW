#pragma once
#include <Hedgehog/Base/System/hhObject.h>
#include <Hedgehog/Rsdx/Graphics/Device/RsdxDevice.h>

namespace hh
{
namespace mr
{
class CRenderingInfrastructure : public base::CObject // size == 0xe40
{
    // TODO

public:
    rsdx::RsdxDevice* Device;
    // TODO

    // Wii U: TODO, PC: 0x00c2be50
    CRenderingInfrastructure();

    // Wii U: 0x036d8d84, PC: 0x00c2b490
    void Present();
};
}
}
