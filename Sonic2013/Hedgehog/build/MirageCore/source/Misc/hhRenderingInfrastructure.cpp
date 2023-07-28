#include "pch.h"
#include "Hedgehog/MirageCore/Misc/hhRenderingInfrastructure.h"
#include <Hedgehog/Base/Platform/D3d9/hhCCriticalSectionD3D9.h>
#include <Hedgehog/Rsdx/Graphics/Shader/RsdxDeviceShader.h>
#include <Hedgehog/Rsdx/System/RsdxResource.h>
#include <boost/unordered_map.hpp>

using namespace hh::base;
using namespace hh::rsdx;

namespace hh
{
namespace mr
{
class CRenderingInfrastructureInternal : public CObject // size == 0x98
{
    struct SVertexDeclHolder
    {
        std::size_t field_0x0;
        RsdxVertexDeclaration9* field_0x4;
        // TODO: Other data members?
    };

    CRenderingInfrastructure* m_renderInfra;
    // TODO: Other data members.
    boost::shared_ptr<CCriticalSectionD3D9> field_0x60;
    boost::unordered_map<SVertexDecl, SVertexDeclHolder> field_0x68;
    std::size_t field_0x8c;
    boost::shared_ptr<CCriticalSectionD3D9> field_0x90;

public:
    LWAPI(0x036d4d7c, 0x00c2dac0)
    CRenderingInfrastructureInternal(CRenderingInfrastructure* renderInfra);

    // TODO: Is this function really a thing?
    inline void Lock()
    {
        field_0x90->Enter();
    }

    // TODO: Is this function really a thing?
    inline void Unlock()
    {
        field_0x90->Leave();
    }

    LWAPI(0x036d67a8, 0x00c2e410)
    bool CreateVertexDeclaration(const rsdx::D3DVERTEXELEMENT9* vtxElements,
        CVertexDeclarationPtr* param_2, const u8* param_3);

    LWAPI(0x036d6b28, TODO)
    void ReleaseVertexDeclaration(RsdxVertexDeclaration9* vtxDecl);

    LWAPI(0x036d6cb4, TODO)
    void ReleaseVertexDeclaration(RsdxVertexDeclaration9** vtxDecl);
};

void CVertexDeclarationPtr::clear()
{
    if (m_renderInfra)
    {
        m_renderInfra->ReleaseVertexDeclaration(&m_vtxDecl);
        m_renderInfra = nullptr;
    }
}

void CVertexDeclarationPtr::reset(CRenderingInfrastructure* renderInfra,
    rsdx::RsdxVertexDeclaration9** vtxDecl, bool addRef)
{
    clear();

    if (renderInfra)
    {
        m_vtxDecl = *vtxDecl;
        if (addRef && m_vtxDecl)
        {
            m_vtxDecl->AddRef();
        }
    }
    
    m_renderInfra = renderInfra;
}

// TODO: Should this be moved somewhere else?
LWAPI(0x1031f7ec, TODO)
static RsdxSListHeader DAT_1031f7ec;

// TODO: Should this be moved somewhere else?
// TODO: Is this type correct?
LWAPI(0x1031f7f0, TODO)
static unsigned int DAT_1031f7f0 = 0;

// TODO: Should this be moved somewhere else?
LWAPI(0x1031f824, TODO)
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

void CRenderingInfrastructure::Initwork1st()
{
    // TODO
    field_0x534 = new CRenderingInfrastructureInternal(this);
    // TODO
}

CRenderingInfrastructure::CRenderingInfrastructure()
{
    // TODO
    Initwork1st();
}

CRenderingInfrastructureInternal::CRenderingInfrastructureInternal(
    CRenderingInfrastructure* renderInfra) :
    // TODO
    m_renderInfra(renderInfra)
{
    field_0x60.reset(new CCriticalSectionD3D9());
    field_0x90.reset(new CCriticalSectionD3D9());
    // TODO
}

rsdx::RsdxVertexShader9* CRenderingInfrastructure::CreateVertexShader(const void* data)
{
    rsdx::RsdxVertexShader9* shader;
    return (!m_device.GetHandle()->CreateVertexShader(static_cast<
        const unsigned long*>(data), &shader)) ? shader : nullptr;
}

rsdx::RsdxPixelShader9* CRenderingInfrastructure::CreatePixelShader(const void* data)
{
    rsdx::RsdxPixelShader9* shader;
    return (!m_device.GetHandle()->CreatePixelShader(static_cast<
        const unsigned long*>(data), &shader)) ? shader : nullptr;
}

bool SVertexDecl::operator==(const SVertexDecl& other) const
{
    return (VertexElementCount == other.VertexElementCount &&
        std::memcmp(other.VertexElements, VertexElements,
            VertexElementCount * sizeof(rsdx::D3DVERTEXELEMENT9)) == 0);
}

LWAPI(0x036d6390, NONE)
static std::size_t MakePermedDeclaration(rsdx::D3DVERTEXELEMENT9* output,
    std::size_t* validInputCount, std::size_t inputCount, std::size_t param_4,
    const rsdx::D3DVERTEXELEMENT9* input, const u8* param_6)
{
    rsdx::D3DVERTEXELEMENT9* p_Var3 = output;
    const rsdx::D3DVERTEXELEMENT9* p_Var4 = input;

    while (p_Var4->Stream != 255 && inputCount-- > 1)
    {
        *(p_Var3++) = *(p_Var4++);
    }

    p_Var3->Stream = 255;
    p_Var3->Offset = 0;
    p_Var3->Type = D3DDECLTYPE_UNUSED;
    p_Var3->Method = D3DDECLMETHOD_DEFAULT;
    p_Var3->Usage = D3DDECLUSAGE_POSITION;
    p_Var3->UsageIndex = 0;

    *validInputCount = ((p_Var4 - input) / sizeof(rsdx::D3DVERTEXELEMENT9));
    return ((p_Var3 - output) / sizeof(rsdx::D3DVERTEXELEMENT9));
}

bool SVertexDecl::InitializeDecl(const rsdx::D3DVERTEXELEMENT9* vtxElements,
    std::size_t param_2, const u8* param_3)
{
    std::memset(VertexElements, 0, sizeof(VertexElements));

    std::size_t local_18;
    VertexElementCount = (MakePermedDeclaration(VertexElements,
        &local_18, MAXD3DDECLLENGTH + 1, param_2,
        vtxElements, param_3) + 1);

    unsigned int hash = 0;
    for (std::size_t i = 0; i < VertexElementCount; ++i)
    {
        rsdx::D3DVERTEXELEMENT9& curVtxElem = VertexElements[i];
        hash += ((static_cast<unsigned int>(curVtxElem.Stream) << 20) |
            (static_cast<unsigned int>(curVtxElem.Offset) << 12) |
            (static_cast<unsigned int>(curVtxElem.Type) << 8) |
            (static_cast<unsigned int>(curVtxElem.Usage) << 4) |
            static_cast<unsigned int>(curVtxElem.UsageIndex));
    }

    Hash = (hash + VertexElementCount * 0x10000000);
    return (VertexElementCount != (local_18 + 1));
}

bool CRenderingInfrastructureInternal::CreateVertexDeclaration(
    const rsdx::D3DVERTEXELEMENT9* vtxElements,
    CVertexDeclarationPtr* param_2, const u8* param_3)
{
    SVertexDecl vtxDecl;
    vtxDecl.InitializeDecl(vtxElements, 0, param_3);

    if (field_0x60)
    {
        field_0x60->Enter();
    }

    auto it = field_0x68.find(vtxDecl);
    RsdxVertexDeclaration9* vtxDeclPtr;

    if (it != field_0x68.end())
    {
        vtxDeclPtr = it->second.field_0x4;
        ++it->second.field_0x0;
    }
    else
    {
        RsdxDevice* device = m_renderInfra->GetDevice()->GetHandle();
        if (device->CreateVertexDeclaration(vtxDecl.VertexElements, &vtxDeclPtr) != D3D_OK)
        {
            vtxDeclPtr = nullptr;
            param_2->reset(m_renderInfra, &vtxDeclPtr, false);
            goto end;
        }

        auto& vtxDeclHolder = field_0x68[vtxDecl];
        vtxDeclHolder.field_0x0 = 1;
        vtxDeclHolder.field_0x4 = vtxDeclPtr;
        field_0x68.find(vtxDecl); // TODO: Is this correct? Why isn't the return value used?
    }

    if (vtxDeclPtr)
    {
        ++field_0x8c;
    }

    param_2->reset(m_renderInfra, &vtxDeclPtr, false);

end:
    if (field_0x60)
    {
        field_0x60->Leave();
    }

    return (vtxDeclPtr == nullptr);
}

bool CRenderingInfrastructure::CreateVertexDeclaration(
    const rsdx::D3DVERTEXELEMENT9* vtxElements,
    CVertexDeclarationPtr* param_2, const u8* param_3)
{
    return field_0x534->CreateVertexDeclaration(vtxElements, param_2, param_3);
}

void CRenderingInfrastructureInternal::ReleaseVertexDeclaration(
    RsdxVertexDeclaration9* vtxDecl)
{
    if (vtxDecl)
    {
        if (field_0x60)
        {
            field_0x60->Enter();
        }

        --field_0x8c;

        for (auto it = field_0x68.begin(); it != field_0x68.end(); ++it)
        {
            if (it->second.field_0x4 == vtxDecl)
            {
                if (--it->second.field_0x0 == 0)
                {
                    CRenderingInfrastructure::ReleaseD3DRenderResource(
                        it->second.field_0x4);

                    field_0x68.erase(it);
                }

                break;
            }
        }

        if (field_0x60)
        {
            field_0x60->Leave();
        }
    }
}

void CRenderingInfrastructureInternal::ReleaseVertexDeclaration(
    RsdxVertexDeclaration9** vtxDecl)
{
    ReleaseVertexDeclaration(*vtxDecl);
}

void CRenderingInfrastructure::ReleaseVertexDeclaration(
    rsdx::RsdxVertexDeclaration9** vtxDecl)
{
    field_0x534->ReleaseVertexDeclaration(vtxDecl);
}

void CRenderingInfrastructure::BlockUntilAsyncNotBusy()
{
    // TODO
}

bool CRenderingInfrastructure::BeginScene()
{
    field_0x534->Lock();
    BlockUntilAsyncNotBusy();

    ++m_renderFence;
    RSDXRESULT result = m_device.BeginScene();
    
    m_device.SetRenderState(D3DRS_COLORWRITEENABLE,
        (D3DCOLORWRITEENABLE_RED | D3DCOLORWRITEENABLE_GREEN |
        D3DCOLORWRITEENABLE_BLUE | D3DCOLORWRITEENABLE_ALPHA));

    return (result == D3D_OK);
}

void CRenderingInfrastructure::EndScene()
{
    BlockUntilAsyncNotBusy();

    m_device.EndScene();
    --m_renderFence;

    field_0x534->Unlock();
}

void CRenderingInfrastructure::Present()
{
    // TODO

    m_device.GetHandle()->Present(nullptr, nullptr, nullptr, nullptr);

    // TODO
}
}
}
