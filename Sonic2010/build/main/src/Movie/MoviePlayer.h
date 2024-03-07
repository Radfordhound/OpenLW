#pragma once
#include "System/ReferencedObject.h"
#include "Input/DeviceManager.h"
#include "Input/ResDevice.h"
#include <Hedgehog/MirageCore/Resource/hhShaderResource.h>
#include <Hedgehog/MirageCore/Misc/hhRenderingInfrastructure.h>
#include <csl/ut/string.h>
#include <csl/ut/bitset.h>

#if OPENLW_USE_CRIWARE == 1
#include <cri_mana.h>
#else

#ifndef CriManaPlayerHn
#define CriManaPlayerHn void*
#endif

#endif

/**
 * @brief Whether or not the user is outputting audio to headphones.
 *
 * NOTE: This function appears to be static, but it's been exposed in
 * this header anyway for LWAPI/modding purposes.
*/
LWAPI(0x021a1a1c, NONE)
inline bool IsHeadPhone()
{
    auto& deviceManager = app::hid::DeviceManager::GetInstance();
    auto device = deviceManager.GetDevice<app::hid::ResPadDevice>(0);
    return device.ref().field_0x2d;
}

namespace app
{
namespace fnd
{
/**
 * @brief Vertex elements to be used for rendering movies.
 *
 * NOTE: This data appears to be static, but it's been exposed in
 * this header anyway for LWAPI/modding purposes.
 * 
 * TODO: This name was guessed.
*/
LWAPI(0x1002df30, 0x00eb2f04)
extern hh::rsdx::D3DVERTEXELEMENT9 MovieVertexElements[];

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
OPENLW_PRIVATE
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
    hh::rsdx::RsdxBaseTexture9* field_0x1d0[2][4];
    std::size_t field_0x1f0;
    unsigned int field_0x1f4;
    csl::ut::Bitset<unsigned int> field_0x1f8;

public:
    LWAPI(0x021a1ce0, TODO)
    static CMoviePlayer* Create(const char* movieResName, int param_2,
        bool param_3, bool param_4, bool param_5);

    LWAPI(0x021a1c24, TODO)
    void Play(const char* movieResName, int param_2,
        bool param_3, bool param_4, bool param_5);

    LWAPI(0x021a1e70, 0x0049b110)
    CMoviePlayer();

    LWAPI(0x021a30b8, TODO)
    void DestroyImmediately();

    LWAPI(0x021a32b8, TODO)
    hh::rsdx::RsdxBaseTexture9* GetTexture(int index);

    LWAPI(0x021a34cc, 0x0049bef0)
    void DrawPrepare();

    LWAPI(0x021a399c, 0x0049c030)
    void Draw(bool param_1);
};
} // fnd
} // app
