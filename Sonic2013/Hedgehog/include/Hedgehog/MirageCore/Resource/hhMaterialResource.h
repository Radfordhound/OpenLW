#pragma once
#include <Hedgehog/Base/hhBaseCommon.h>
#include <cstddef>

namespace hh
{
namespace mr
{
template<typename T>
class CMaterialParameterResource // TODO: This name was guessed; is it correct??
{
    u8 m_unknownFlag1;
    u8 m_unknownFlag2;
    u8 m_valueCount;
    u8 m_unknownFlag3;
    OFF32(char) m_name;
    OFF32(T) m_values;

public:
    // TODO: Is this function actually a thing?
    inline u8 GetValueCount() const
    {
        return m_valueCount;
    }

    // TODO: Is this function actually a thing?
    inline const char* GetName() const
    {
        return m_name;
    }

    // TODO: Is this function actually a thing?
    inline const T& GetValue(std::size_t index) const
    {
        return m_values[index];
    }
};

// TODO: This type is not in the actual game!!! What does the actual game use?
template<typename T>
struct vec4
{
    T x;
    T y;
    T z;
    T w;

    inline T operator[](std::size_t index) const
    {
        return HH_ENDIAN_FIX((&x)[index]);
    }
};

class CMaterialV3Resource
{
    OFF32(char) m_shaderName;
    OFF32(char) m_subShaderName; // TODO: Is this a good name for this?
    OFF32(OFF32(char)) m_textureNames;
    OFF32(OFF32(void)) m_textures; // TODO: Use correct data type!
    u8 m_flags;
    u8 m_noBackfaceCulling;
    u8 m_useAdditiveBlending;
    u8 m_unknownFlag1;
    u8 m_floatParamCount;
    u8 m_intParamCount;
    u8 m_boolParamCount;
    u8 m_textureCount;
    OFF32(OFF32(CMaterialParameterResource<vec4<float>>)) m_floatParams;
    OFF32(OFF32(CMaterialParameterResource<vec4<s32>>)) m_intParams;
    OFF32(OFF32(CMaterialParameterResource<vec4<u8>>)) m_boolParams;

public:
    // TODO: Is this function actually a thing?
    inline const char* GetShaderName() const
    {
        return (m_shaderName);
    }

    // TODO: Is this function actually a thing?
    inline u8 GetFlags() const
    {
        return m_flags;
    }

    // TODO: Is this function actually a thing?
    inline bool UseBackfaceCulling() const
    {
        return (m_noBackfaceCulling == 0);
    }

    // TODO: Is this function actually a thing?
    inline bool UseAdditiveBlending() const
    {
        return (m_useAdditiveBlending != 0);
    }

    // TODO: Is this function actually a thing?
    inline u8 GetFloatParamCount() const
    {
        return m_floatParamCount;
    }

    // TODO: Is this function actually a thing?
    inline const CMaterialParameterResource<vec4<float>>* GetFloatParam(unsigned int index) const
    {
        return m_floatParams[index];
    }

    // TODO: Is this function actually a thing?
    inline u8 GetIntParamCount() const
    {
        return m_intParamCount;
    }

    // TODO: Is this function actually a thing?
    inline const CMaterialParameterResource<vec4<s32>>* GetIntParam(unsigned int index) const
    {
        return m_intParams[index];
    }

    // TODO: Is this function actually a thing?
    inline u8 GetTextureCount() const
    {
        return m_textureCount;
    }
};
}
}
