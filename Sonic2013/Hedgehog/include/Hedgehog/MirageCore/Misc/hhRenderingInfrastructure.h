#pragma once
#include "hhRenderingDevice.h"
#include <Hedgehog/Base/System/hhObject.h>
#include <Hedgehog/Rsdx/System/RsdxResource.h>
#include <Hedgehog/Rsdx/Graphics/Shader/RsdxDeviceShader.h>

namespace hh
{
namespace mr
{
class CRenderingInfrastructure;
class CRenderingInfrastructureInternal;

class CVertexDeclarationPtr : public base::CObject // size == 8 // TODO: Move this to its own header?
{
    rsdx::RsdxVertexDeclaration9* m_vtxDecl;
    CRenderingInfrastructure* m_renderInfra;

public:
    // TODO: Is this function a thing?
    inline rsdx::RsdxVertexDeclaration9* GetVertexDeclaration()
    {
        return m_vtxDecl;
    }

    // Wii U: 0x036c7a4c, PC: TODO
    void clear();

    // Wii U: 0x036c7a90, PC: TODO
    void reset(CRenderingInfrastructure* renderInfra,
        rsdx::RsdxVertexDeclaration9** vtxDecl, bool addRef);
};

struct SVertexDecl
{
    std::size_t VertexElementCount;
    rsdx::D3DVERTEXELEMENT9 VertexElements[MAXD3DDECLLENGTH + 1];
    unsigned int Hash;

    // Wii U: 0x036d5d14, PC: TODO
    bool operator==(const SVertexDecl& other) const;

    // Wii U: 0x036d6430, PC: 0x00c2aa50
    bool InitializeDecl(const rsdx::D3DVERTEXELEMENT9* vtxElements,
        std::size_t param_2, const u8* param_3);
};

inline std::size_t hash_value(const SVertexDecl& vtxDecl)
{
    return vtxDecl.Hash; // TODO: Is this correct?
}

class CRenderingInfrastructure : public base::CObject // size == 0xe40
{
    // TODO: Other data members.
    CRenderingDevice m_device;
    // TODO: Other data members.
    std::size_t m_renderFence; // TODO: Is this type correct?
    // TODO: Other data members.
    CRenderingInfrastructureInternal* field_0x534;

public:
    // TODO: Is this function a thing?
    inline CRenderingDevice* GetDevice()
    {
        return &m_device;
    }

    // Wii U: 0x036caea4, PC: TODO
    static void ReleaseD3DRenderResource(rsdx::RsdxResource* res);

    // Wii U: 0x036d4f14, PC: TODO
    void Initwork1st();

    // Wii U: 0x036d4ff0, PC: 0x00c2be50
    CRenderingInfrastructure();

    // Wii U: 0x036d5bb0, PC: 0x00c2b200
    rsdx::RsdxVertexShader9* CreateVertexShader(const void* data);

    // Wii U: 0x036d5bf4, PC: TODO
    rsdx::RsdxPixelShader9* CreatePixelShader(const void* data);

    // Wii U: 0x036d6970, PC: 0x00c2bed0
    void CreateVertexDeclaration(const rsdx::D3DVERTEXELEMENT9* param_1,
        CVertexDeclarationPtr* param_2, const u8* param_3);

    // Wii U: 0x036d6cbc, PC: TODO
    void ReleaseVertexDeclaration(rsdx::RsdxVertexDeclaration9** vtxDecl);

    // Wii U: 0x036d6e28, PC: TODO
    void BlockUntilAsyncNotBusy();

    // Wii U: 0x036d8c0c, PC: TODO
    bool BeginScene();

    // Wii U: 0x036d8c7c, PC: TODO
    void EndScene();

    // Wii U: 0x036d8d84, PC: 0x00c2b490
    void Present();
};
}
}
