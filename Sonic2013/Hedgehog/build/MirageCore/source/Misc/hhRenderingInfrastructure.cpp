#include "Hedgehog/MirageCore/Misc/hhRenderingInfrastructure.h"
#include <Hedgehog/Rsdx/Graphics/Shader/RsdxDeviceShader.h>
#include <Hedgehog/Rsdx/System/RsdxResource.h>

using namespace hh::rsdx;

namespace hh
{
namespace mr
{
// TODO: Should this be moved somewhere else?
// Wii U: 0x1031f7ec, PC: TODO
static RsdxSListHeader DAT_1031f7ec;

// TODO: Should this be moved somewhere else?
// TODO: Is this type correct?
// Wii U: 0x1031f7f0, PC: TODO
static unsigned int DAT_1031f7f0 = 0;

// TODO: Should this be moved somewhere else?
// Wii U: 0x1031f824, PC: TODO
static RsdxAtomic DAT_1031f824 = 0;

struct UnknownStruct : public RsdxSListEntry // TODO: There seems to be no name for this struct in the symbols?
{
    RsdxResource* ResourcePtr;
};

void CRenderingInfrastructure::ReleaseD3DRenderResource(rsdx::RsdxResource* res)
{
    if (DAT_1031f7f0 != 0)
    {
        RsdxAtomicInc2(&DAT_1031f824);
        UnknownStruct* pRVar1 = new UnknownStruct();
        pRVar1->ResourcePtr = res;
        RsdxAtomicPushSList(&DAT_1031f7ec, pRVar1);
    }
    else
    {
        res->Release();
    }
}

rsdx::RsdxVertexShader9* CRenderingInfrastructure::CreateVertexShader(const void* data)
{
    rsdx::RsdxVertexShader9* shader;
    return (!Device->CreateVertexShader(static_cast<const unsigned long*>(
        data), &shader)) ? shader : nullptr;
}

CRenderingInfrastructure::CRenderingInfrastructure()
{
    // TODO
}

void CRenderingInfrastructure::Present()
{
    // TODO

    Device->Present(nullptr, nullptr, nullptr, nullptr);

    // TODO
}
}
}
