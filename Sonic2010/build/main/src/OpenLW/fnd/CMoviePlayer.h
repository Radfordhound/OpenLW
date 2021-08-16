#pragma once
#include "ReferencedObject.h"
#include <Hedgehog/MirageCore/Resource/hhShaderResource.h>
#include <Hedgehog/MirageCore/Misc/hhRenderingInfrastructure.h>
#include <csl/ut/string.h>
#include <csl/ut/bitset.h>
#include <cri_mana.h>

namespace app
{
namespace fnd
{
enum CMoviePlayerFlags
{
    MOVIE_PLAYER_FLAG_PREPARED = 0,
    MOVIE_PLAYER_FLAG_UNKNOWN1 = 1,
    MOVIE_PLAYER_FLAG_UNKNOWN2 = 2,
    MOVIE_PLAYER_FLAG_HAS_ALPHA = 4,
    MOVIE_PLAYER_FLAG_UNKNOWN5 = 5,
    MOVIE_PLAYER_FLAG_UNKNOWN7 = 7
};

class CMoviePlayer : public ReferencedObject // size == 0x1fc
{
    csl::ut::StringBuf<256> field_0xc;
    CriManaPlayerHn m_playerHandle;
    boost::shared_ptr<hh::mr::CVertexShaderData> m_vtxShader;
    boost::shared_ptr<hh::mr::CPixelShaderData> m_pixelShader;
    boost::shared_ptr<hh::mr::CPixelShaderData> m_alphaPixelShader;
    hh::mr::CVertexDeclarationPtr field_0x134;
    hh::mr::CRenderingInfrastructure* m_renderInfra;
    float m_vtxData[20];
    void* field_0x190; // TODO: Use correct data type.
    int field_0x194;
    // TODO: Other data members.
    float m_maxPosX;
    float m_maxPosY;
    float m_width;
    float m_height;
    float m_posX;
    float m_posY;
    // TODO: Other data members.
    hh::rsdx::RsdxBaseTexture9* field_0x1d0[8];
    std::size_t field_0x1f0;
    unsigned int field_0x1f4;
    csl::ut::Bitset<unsigned int> field_0x1f8;

public:
    // Wii U: 0x021a1ce0, PC: TODO
    static CMoviePlayer* Create(const char* movieResName, int param_2,
        bool param_3, bool param_4, bool param_5);

    // Wii U: 0x021a1c24, PC: TODO
    void Play(const char* movieResName, int param_2,
        bool param_3, bool param_4, bool param_5);

    // Wii U: 0x021a30b8, PC: TODO
    void DestroyImmediately();

    // Wii U: 0x021a32b8, PC: TODO
    hh::rsdx::RsdxBaseTexture9* GetTexture(int index);

    // Wii U: 0x021a34cc, PC: 0x0049bef0
    void DrawPrepare();

    // Wii U: 0x021a399c, PC: 0x0049c030
    void Draw(bool param_1);
};
}
}
