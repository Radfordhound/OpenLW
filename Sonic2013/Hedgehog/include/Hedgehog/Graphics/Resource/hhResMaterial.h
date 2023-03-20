#pragma once
#include "hhResParameter.h"
#include <Hedgehog/Utility/hhResource.h>

namespace hh
{
namespace gfx
{
namespace res
{
enum ResMaterialDataFlags
{
    MAT_FLAG_USE_GRASS = 0x20,
    MAT_FLAG_EXTN_AABB = 0x40,
    MAT_FLAG_USE_PRIOR = 0x80
};

struct ResShaderData; // TODO: Move this to its own header!!!

struct ResMaterialData // size == 0x128
{
    ResShaderData* Shader;
    ResParameterData Params;
    std::size_t TextureCount;
    float Diffuse[4]; // TODO: Is this the right type?
    float Ambient[4]; // TODO: Is this the right type?
    float Specular[4]; // TODO: Is this the right type?
    float Emissive[4]; // TODO: Is this the right type?
    float PowerGlossLevel[4]; // TODO: Is this the right type?
    float OpacityReflectionRefractionSpectype[4]; // TODO: Is this the right type?
    // TODO: Other data members.
    unsigned char Flags1;
    bool BackfaceCulling;
    bool UseAdditiveBlending;
    unsigned char TransPriority;
    unsigned int Flags2;
    ResNameData ShaderName;
    ResNameData Name;
    ResUserDataData UserData;
};

struct ResMaterial : public ut::ResCommon<ResMaterialData>
{
    LWAPI(TODO, TODO)
    static const ut::ResourceTypeInfo& staticTypeInfo();

    LWAPI(0x03674284, TODO)
    ResName GetName();

    LWAPI(0x036742D8, TODO)
    ResUserData GetResUserData();

    LWAPI(0x03674344, TODO)
    void* Replace(const char* param_1, std::size_t* size, csl::fnd::IAllocator* allocator);

    LWAPI(0x03674f04, TODO)
    bool Setup(std::size_t size, csl::fnd::IAllocator* allocator);

    LWAPI(0x03674f9c, TODO)
    bool Setup(std::size_t size, csl::fnd::IAllocator* allocator, ut::Packfile pac);

    LWAPI(TODO, TODO)
    void Unbind();

    LWAPI(0x036758e0, TODO)
    void Cleanup(std::size_t size);

    inline ResMaterial(std::nullptr_t) :
        ResCommon<ResMaterialData>() {}

    inline ResMaterial(const void* data) :
        ResCommon<ResMaterialData>(data) {}

    inline ResMaterial(void* data = nullptr) :
        ResCommon<ResMaterialData>(data) {}
};
}
}
}
