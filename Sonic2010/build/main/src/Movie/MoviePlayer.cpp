#include "pch.h"
#include "MoviePlayer.h"
#include "MovieSystem.h"
#include "Render/RenderManager.h"
#include "HUD/SurfRidePlatformMIRAGE.h"

using namespace app::gfx;
using namespace app::HUD;
using namespace hh::rsdx;
using namespace hh::mr;
using namespace csl::ut;

namespace app
{
namespace fnd
{
hh::rsdx::D3DVERTEXELEMENT9 MovieVertexElements[] =
{
    {
        0,                                                              // Stream
        0,                                                              // Offset
        D3DDECLTYPE_FLOAT3,                                             // Type
        D3DDECLMETHOD_DEFAULT,                                          // Method
        D3DDECLUSAGE_POSITION,                                          // Usage
        0                                                               // UsageIndex
    },

    {
        0,                                                              // Stream
        12,                                                             // Offset
        D3DDECLTYPE_FLOAT2,                                             // Type
        D3DDECLMETHOD_DEFAULT,                                          // Method
        D3DDECLUSAGE_TEXCOORD,                                          // Usage
        0                                                               // UsageIndex
    },

    {
        255,                                                            // Stream
        0,                                                              // Offset
        D3DDECLTYPE_UNUSED,                                             // Type
        D3DDECLMETHOD_DEFAULT,                                          // Method
        D3DDECLUSAGE_POSITION,                                          // Usage
        0                                                               // UsageIndex
    }
};

#define MovieVertexStride 20

CMoviePlayer* CMoviePlayer::Create(const char* movieResName,
    int param_2, bool param_3, bool param_4, bool param_5)
{
    CMoviePlayer* player = CMovieSystem::GetInstance().CreatePlayer();
    if (movieResName)
    {
        player->Play(movieResName, param_2, param_3, param_4, param_5);
    }
    
    return player;
}

void CMoviePlayer::Play(const char* movieResName, int param_2,
    bool param_3, bool param_4, bool param_5)
{
    field_0xc = StringBuf<256>(movieResName);
    field_0x194 = param_2;
    field_0x1f4 = 1;
    field_0x1f8.Set(MOVIE_PLAYER_FLAG_UNKNOWN1, param_3);
    field_0x1f8.Set(MOVIE_PLAYER_FLAG_UNKNOWN2, param_4);
    field_0x1f8.Set(MOVIE_PLAYER_FLAG_UNKNOWN7, true);
}

void CMoviePlayer::DestroyImmediately()
{
    if (m_playerHandle)
    {
        criManaPlayer_StopAndWaitCompletion(m_playerHandle);
        if (field_0x190)
        {
            criManaPlayer_FreePlaybackWork(m_playerHandle);
            m_allocator->Free(field_0x190);
            field_0x190 = nullptr;
        }

        criManaPlayer_Destroy(m_playerHandle);
        m_playerHandle = nullptr;
        field_0x1f4 = 12;
    }
}

hh::rsdx::RsdxBaseTexture9* CMoviePlayer::GetTexture(int index)
{
    return field_0x1d0[field_0x1f0 * 4 + index];
}

void CMoviePlayer::DrawPrepare()
{
    if (!field_0x1f8.Test(MOVIE_PLAYER_FLAG_UNKNOWN5))
    {
        field_0x1f8.Set(MOVIE_PLAYER_FLAG_PREPARED, true);
        m_vtxShader = CreateGetVertexShaderData("MovieYuv");
        m_pixelShader = CreateGetPixelShaderData("MovieYuv");
        m_alphaPixelShader = CreateGetPixelShaderData("MovieYuvAlpha");

        RenderManager& renderMgr = RenderManager::GetInstance();
        CRenderingInfrastructure* renderInfra = renderMgr.GetRenderingDevice();

        m_renderInfra = renderInfra;
        renderInfra->CreateVertexDeclaration(MovieVertexElements, &field_0x134, nullptr);
    }
}

void CMoviePlayer::Draw(bool param_1)
{
    if (field_0x1f8.Test(MOVIE_PLAYER_FLAG_UNKNOWN5))
        return;

    if (!field_0x1f8.Test(MOVIE_PLAYER_FLAG_PREPARED))
    {
        DrawPrepare();
    }

    if (!param_1)
    {
        // TODO
    }
    else
    {
        // TODO
    }

    if (m_renderInfra && m_renderInfra->GetDevice())
    {
        CRenderingDevice* device = m_renderInfra->GetDevice();
        device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
        
        // Set shader.
        CVertexShaderData* vtxShader = m_vtxShader.get();
        CPixelShaderData* pixelShader =
            (!field_0x1f8.Test(MOVIE_PLAYER_FLAG_HAS_ALPHA)) ?
            m_pixelShader.get() : m_alphaPixelShader.get();

        if (vtxShader && pixelShader && vtxShader->IsMadeAll() &&
            pixelShader->IsMadeAll())
        {
            device->SetShader(m_vtxShader, m_pixelShader);
        }

        // Set vertex declaration.
        device->SetVertexDeclaration(field_0x134.GetVertexDeclaration());

        // Set render state.
        device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
        device->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
        device->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
        device->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
        device->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
        device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
        device->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_NOTEQUAL);
        device->SetRenderState(D3DRS_ALPHAREF, 0);
        device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
        device->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
        device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
        device->SetRenderState(D3DRS_SRCBLENDALPHA, D3DBLEND_ONE);
        device->SetRenderState(D3DRS_BLENDOPALPHA, D3DBLENDOP_ADD);
        device->SetRenderState(D3DRS_DESTBLENDALPHA, D3DBLEND_ZERO);

        // Set sampler states.
        device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
        device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
        device->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);

        device->SetSamplerState(1, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
        device->SetSamplerState(1, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
        device->SetSamplerState(1, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);

        device->SetSamplerState(2, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
        device->SetSamplerState(2, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
        device->SetSamplerState(2, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);

        device->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP);
        device->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP);
        device->SetSamplerState(0, D3DSAMP_ADDRESSW, D3DTADDRESS_CLAMP);

        device->SetSamplerState(1, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP);
        device->SetSamplerState(1, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP);
        device->SetSamplerState(1, D3DSAMP_ADDRESSW, D3DTADDRESS_CLAMP);

        device->SetSamplerState(2, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP);
        device->SetSamplerState(2, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP);
        device->SetSamplerState(2, D3DSAMP_ADDRESSW, D3DTADDRESS_CLAMP);

        // Set textures.
        device->SetTexture(0, GetTexture(0));
        device->SetTexture(1, GetTexture(1));
        device->SetTexture(2, GetTexture(2));
        
        // Set vertex data.
        float originX = (m_width * 0.5f);
        float fVar9 = (1.0f / m_maxPosX);
        float originY = (m_height * 0.5f);
        float fVar6 = (1.0f / m_maxPosY);
        float fVar5 = ((m_posX - originX) * fVar9);
        float fVar7 = ((m_posY + originY) * fVar6);

        fVar9 = ((originX + m_posX) * fVar9);
        fVar6 = ((m_posY - originY) * fVar6);

        m_vtxData[0] = fVar5;
        m_vtxData[1] = fVar7;
        m_vtxData[2] = 0.0f;

        m_vtxData[3] = 0.0f;
        m_vtxData[4] = 0.0f;

        m_vtxData[5] = fVar9;
        m_vtxData[6] = fVar7;
        m_vtxData[7] = 0.0f;

        m_vtxData[8] = 1.0f;
        m_vtxData[9] = 0.0f;

        m_vtxData[10] = fVar5;
        m_vtxData[11] = fVar6;
        m_vtxData[12] = 0.0f;

        m_vtxData[13] = 0.0f;
        m_vtxData[14] = 1.0f;

        m_vtxData[15] = fVar9;
        m_vtxData[16] = fVar6;
        m_vtxData[17] = 0.0f;

        m_vtxData[18] = 1.0f;
        m_vtxData[19] = 1.0f;

        // Draw primitive.
        device->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, m_vtxData, MovieVertexStride);
    }
}
}
}
