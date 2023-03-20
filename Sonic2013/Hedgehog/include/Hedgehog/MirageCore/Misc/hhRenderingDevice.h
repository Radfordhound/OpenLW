#pragma once
#include "Hedgehog/MirageCore/Resource/hhShaderResource.h"
#include <Hedgehog/Rsdx/Graphics/Device/RsdxDevice.h>

namespace hh
{
namespace mr
{
class CRenderingInfrastructure;

template<std::size_t count>
struct SRenderStateInfo // TODO: Move this to another header?
{
    struct StateInfo // TODO: This name was guessed; is this even in the correct namespace??
    {
        unsigned int Current;
        unsigned int field_0x4;
        unsigned int field_0x8;
    };

    unsigned char field_0x0[count];
    StateInfo State[count];

    bool IsLocked(std::size_t index)
    {
        return ((field_0x0[index] & 0xf0) != 0);
    }

    void Lock(std::size_t index)
    {
        field_0x0[index] += 0x10;
    }

    void Unlock(std::size_t index)
    {
        field_0x0[index] -= 0x10;
    }

    unsigned int get_current(std::size_t index) const
    {
        return State[index].Current;
    }

    void set_current(std::size_t index, unsigned int value)
    {
        State[index].Current = value;
    }

    bool empty(std::size_t index) const
    {
        return (field_0x0[index] & 0xf) == 0;
    }

    void pop_front(std::size_t index)
    {
        field_0x0[index] = (((field_0x0[index] & 0xf) - 1) |
            (field_0x0[index] & 0xf0));
    }

    void Initialize()
    {
        std::memset(State, 255, sizeof(State));
        for (std::size_t i = 0; i < count; ++i)
        {
            field_0x0[i] = 0;
        }
    }

    SRenderStateInfo()
    {
        Initialize();
    }
};

class CRenderingDevice // TODO: Inheritance? // size == 0x4AC
{
    CRenderingInfrastructure* m_renderInfra;
    rsdx::RsdxDevice* m_device;
    // TODO: Other data members.
    SRenderStateInfo<RSDX_RS_MAX> m_curStateInfo;
    rsdx::RsdxVertexDeclaration9* m_curVtxDecl;
    rsdx::RsdxVertexShader9* m_curVShader;
    rsdx::RsdxPixelShader9* m_curPShader;
    CVertexShaderData* m_curVShaderData;
    CPixelShaderData* m_curPShaderData;
    // TODO: Other data members.
    bool field_0x4a7;
    // TODO: Other data members.

public:
    // TODO: Is this function a thing?
    inline rsdx::RsdxDevice* GetHandle()
    {
        return m_device;
    }

    // TODO: Is this function a thing?
    inline void SetHandle(rsdx::RsdxDevice* device)
    {
        m_device = device;
    }

    inline rsdx::RSDXRESULT BeginScene()
    {
        return m_device->BeginScene();
    }

    inline rsdx::RSDXRESULT EndScene()
    {
        return m_device->EndScene();
    }

    LWAPI(NONE, 0x00488540)
    void SetVertexDeclaration(rsdx::RsdxVertexDeclaration9* vtxDecl)
    {
        if (m_curVtxDecl != vtxDecl)
        {
            if (!field_0x4a7)
            {
                m_curVtxDecl = vtxDecl;
            }

            m_device->SetVertexDeclaration(vtxDecl);
        }
    }

    void SetRenderStateRaw(rsdx::D3DRENDERSTATETYPE state, unsigned int value)
    {
        m_device->SetRenderState(state, value);
        m_curStateInfo.set_current(state, value);
    }

    void SetRenderState(rsdx::D3DRENDERSTATETYPE state, unsigned int value)
    {
        if (!m_curStateInfo.IsLocked(state) && (m_curStateInfo.empty(state) ||
            m_curStateInfo.get_current(state) == value))
        {
            SetRenderStateRaw(state, value);
        }
    }

    inline void SetSamplerState(unsigned int sampler,
        D3DSAMPLERSTATETYPE type, unsigned int value)
    {
        m_device->SetSamplerState(sampler, type, value);
    }

    inline rsdx::RSDXRESULT SetTexture(unsigned int stage, rsdx::RsdxBaseTexture9* texture)
    {
        return m_device->SetTexture(stage, texture);
    }

    void SetPShaderInternalDirect(rsdx::RsdxPixelShader9* shader)
    {
        m_device->SetPixelShader(shader);
    }

    void SetVShaderInternalDirect(rsdx::RsdxVertexShader9* shader)
    {
        m_device->SetVertexShader(shader);
    }

    void SetShaderIgnoreLock(
        const boost::shared_ptr<CVertexShaderData>& vtxShader,
        const boost::shared_ptr<CPixelShaderData>& pixelShader)
    {
        CPixelShaderData* pixelShaderData = pixelShader.get();
        if (m_curPShaderData != pixelShaderData)
        {
            m_curPShaderData = pixelShaderData;

            rsdx::RsdxPixelShader9* pixelShaderHandle = nullptr;
            if (pixelShaderData && pixelShaderData->Code)
            {
                pixelShaderHandle = pixelShaderData->Code->Handle.get();
            }

            if (pixelShaderHandle != m_curPShader)
            {
                m_curPShader = pixelShaderHandle;
                SetPShaderInternalDirect(pixelShaderHandle);
            }
        }

        CVertexShaderData* vtxShaderData = vtxShader.get();
        if (m_curVShaderData != vtxShaderData)
        {
            m_curVShaderData = vtxShaderData;

            rsdx::RsdxVertexShader9* vtxShaderHandle = nullptr;
            if (vtxShaderData && vtxShaderData->Code)
            {
                vtxShaderHandle = vtxShaderData->Code->Handle.get();
            }

            if (vtxShaderHandle != m_curVShader)
            {
                m_curVShader = vtxShaderHandle;
                SetVShaderInternalDirect(vtxShaderHandle);
            }
        }
    }

    void SetShader(
        const boost::shared_ptr<CVertexShaderData>& vtxShader,
        const boost::shared_ptr<CPixelShaderData>& pixelShader)
    {
        // TODO

        SetShaderIgnoreLock(vtxShader, pixelShader);
    }

    inline rsdx::RSDXRESULT DrawPrimitiveUP(rsdx::D3DPRIMITIVETYPE primType,
        unsigned int primCount, const void* vtxData, unsigned int vtxStride)
    {
        return m_device->DrawPrimitiveUP(primType, primCount, vtxData, vtxStride);
    }
};
}
}
