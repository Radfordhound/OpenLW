#pragma once
#include <Hedgehog/Base/hhBase.h>
#include <Hedgehog/Base/hhMap.h>
#include <Hedgehog/Base/System/hhCSymbol.h>
#include <Hedgehog/Base/Platform/D3d9/hhCCriticalSectionD3D9.h>
#include <Hedgehog/Database/hhCDatabaseData.h>
#include <Hedgehog/Utility/hhScopedComPtr.h>
#include <Hedgehog/Utility/hhComRefcounterStrategyForRendering.h>
#include <Hedgehog/Rsdx/Graphics/Shader/RsdxDeviceShader.h>
#include <boost/shared_array.hpp>
#include <boost/shared_ptr.hpp>
#include <vector>

namespace hh
{
namespace mr
{
class CRenderingInfrastructure;

class CVertexShaderCodeData : public db::CDatabaseData
{
    ut::ScopedComPtr<rsdx::RsdxVertexShader9, ut::ComRefcounterStrategyForRendering> m_vtxShaderPtr;
    boost::shared_array<unsigned char> field_0x10;
    boost::shared_ptr<base::CCriticalSectionD3D9> field_0x18;

public:
    // Wii U: 0x036e2e4c, PC: 0x00c33050
    void Make(CVertexShaderCodeData* param_1, const u32* param_2,
        CRenderingInfrastructure* renderInfra);

    // TODO: Is this function actually a thing?
    inline rsdx::RsdxVertexShader9* GetVertexShader()
    {
        return m_vtxShaderPtr.get();
    }

    inline CVertexShaderCodeData() :
        CDatabaseData(),
        m_vtxShaderPtr(),
        field_0x10(),
        field_0x18() {}
};

class CPixelShaderCodeData : public db::CDatabaseData
{
    ut::ScopedComPtr<rsdx::RsdxPixelShader9, ut::ComRefcounterStrategyForRendering> m_pixelShaderPtr;
    boost::shared_array<unsigned char> field_0x10;
    boost::shared_ptr<base::CCriticalSectionD3D9> field_0x18;

public:
    // Wii U: 0x036da84c, PC: TODO
    void Make(CPixelShaderCodeData* param_1, const u32* param_2,
        CRenderingInfrastructure* renderInfra);

    // TODO: Is this function actually a thing?
    inline rsdx::RsdxPixelShader9* GetPixelShader()
    {
        return m_pixelShaderPtr.get();
    }

    inline CPixelShaderCodeData() :
        CDatabaseData(),
        m_pixelShaderPtr(),
        field_0x10(),
        field_0x18() {}
};

class CShaderConstantResource // TODO: This name was guessed; is it correct??
{
    OFF32(char) m_name;
    u8 m_regFirstIndex;
    u8 m_regCount;

public:
    // TODO: Is this function actually a thing?
    inline const char* GetName() const
    {
        return m_name;
    }

    // TODO: Is this function actually a thing?
    inline unsigned int GetRegFirstIndex() const
    {
        return m_regFirstIndex;
    }

    // TODO: Is this function actually a thing?
    inline unsigned int GetRegCount() const
    {
        return m_regCount;
    }
};

class CShaderConstantData // size == 24
{
    u8 m_regFirstIndex;
    u8 m_regCount;
    // TODO: Other data members

public:
    // TODO: Is this function actually a thing?
    inline void SetRegFirstIndex(u8 val)
    {
        m_regFirstIndex = val;
    }

    // TODO: Is this function actually a thing?
    inline void SetRegCount(u8 val)
    {
        m_regCount = val;
    }
};

class CShaderConstantNameResource
{
    u32 m_count;
    OFF32(OFF32(CShaderConstantResource)) m_data;
    
public:
    // TODO: Is this function actually a thing?
    inline std::size_t GetCount() const
    {
        return HH_ENDIAN_FIX_U32(m_count);
    }

    // TODO: Is this function actually a thing?
    inline const CShaderConstantResource* GetConstant(std::size_t index) const
    {
        return m_data[index];
    }
};

class CShaderConstantNameData : public map<base::CStringSymbol, CShaderConstantData>
{
public:
    CShaderConstantNameData() :
        map<base::CStringSymbol, CShaderConstantData>() {}
};

class CShaderSamplerResource // TODO: This name was guessed; is it correct??
{
    OFF32(char) m_name;
    u8 m_regIndex;
    u8 field_0x5;

public:
    // TODO: Is this function actually a thing?
    inline const char* GetName() const
    {
        return m_name;
    }

    // TODO: Is this function actually a thing?
    inline unsigned int GetRegIndex() const
    {
        return m_regIndex;
    }
};

class CShaderSamplerUsageResource
{
    u32 m_count;
    OFF32(OFF32(CShaderSamplerResource)) m_data;

public:
    // TODO: Is this function actually a thing?
    inline std::size_t GetCount() const
    {
        return HH_ENDIAN_FIX_U32(m_count);
    }

    // TODO: Is this function actually a thing?
    inline const CShaderSamplerResource* GetSampler(std::size_t index) const
    {
        return m_data[index];
    }
};

class CShaderSamplerUsageData : public map<base::CStringSymbol, std::vector<unsigned char>>
{
public:
    CShaderSamplerUsageData() :
        map<base::CStringSymbol, std::vector<unsigned char>>() {}
};

class CVertexShaderParameterData : public db::CDatabaseData // size == 48
{
    CShaderConstantNameData Floats;
    CShaderConstantNameData Ints;
    CShaderConstantNameData Bools;

public:
    inline CVertexShaderParameterData() :
        CDatabaseData(),
        Floats(),
        Ints(),
        Bools() {}

    // Wii U: 0x03687700, PC: TODO
    ~CVertexShaderParameterData();

    // TODO: Is this function actually a thing?
    inline const CShaderConstantNameData& GetFloatConstants() const
    {
        return Floats;
    }

    // TODO: Is this function actually a thing?
    inline CShaderConstantNameData& GetFloatConstants()
    {
        return Floats;
    }

    // TODO: Is this function actually a thing?
    inline const CShaderConstantNameData& GetIntConstants() const
    {
        return Ints;
    }

    // TODO: Is this function actually a thing?
    inline CShaderConstantNameData& GetIntConstants()
    {
        return Ints;
    }

    // TODO: Is this function actually a thing?
    inline const CShaderConstantNameData& GetBoolConstants() const
    {
        return Bools;
    }

    // TODO: Is this function actually a thing?
    inline CShaderConstantNameData& GetBoolConstants()
    {
        return Bools;
    }
};

class CVertexShaderParameterResource
{
    CShaderConstantNameResource m_floatConstants;
    CShaderConstantNameResource m_intConstants;
    CShaderConstantNameResource m_boolConstants;
    CShaderSamplerUsageResource m_texSamplers;
    CShaderConstantNameResource field_0x20; // TODO: Is this type correct? It's probably CShaderResourceNameResource?

public:
    // TODO: Is this function actually a thing?
    inline const CShaderConstantNameResource& GetFloatConstants() const
    {
        return m_floatConstants;
    }

    // TODO: Is this function actually a thing?
    inline const CShaderConstantNameResource& GetIntConstants() const
    {
        return m_intConstants;
    }

    // TODO: Is this function actually a thing?
    inline const CShaderConstantNameResource& GetBoolConstants() const
    {
        return m_boolConstants;
    }

    // TODO: Is this function actually a thing?
    inline std::size_t GetTotalConstantCount() const
    {
        return (m_floatConstants.GetCount() +
            m_intConstants.GetCount() +
            m_boolConstants.GetCount());
    }
};

class CVertexShaderV2Resource
{
    OFF32(char) m_codeResName;
    u32 m_paramsCount;
    OFF32(OFF32(char)) m_paramResNames;

public:
    // TODO: Is this function actually a thing?
    inline const char* CodeResName() const
    {
        return m_codeResName;
    }

    // TODO: Is this function actually a thing?
    inline u32 ParamsCount() const
    {
        return HH_ENDIAN_FIX_U32(m_paramsCount);
    }

    // TODO: Is this function actually a thing?
    inline OFF32(const char) const* ParamResNames() const
    {
        return m_paramResNames;
    }
};

class CPixelShaderParameterData : public db::CDatabaseData // size == 60
{
    CShaderConstantNameData Floats;
    CShaderConstantNameData Ints;
    CShaderConstantNameData Bools;
    CShaderSamplerUsageData Textures;

public:
    inline CPixelShaderParameterData() :
        CDatabaseData(),
        Floats(),
        Ints(),
        Bools(),
        Textures() {}

    // Wii U: 0x0217885c, PC: TODO
    ~CPixelShaderParameterData();

    // TODO: Is this function actually a thing?
    inline const CShaderConstantNameData& GetFloatConstants() const
    {
        return Floats;
    }

    // TODO: Is this function actually a thing?
    inline CShaderConstantNameData& GetFloatConstants()
    {
        return Floats;
    }

    // TODO: Is this function actually a thing?
    inline const CShaderConstantNameData& GetIntConstants() const
    {
        return Ints;
    }

    // TODO: Is this function actually a thing?
    inline CShaderConstantNameData& GetIntConstants()
    {
        return Ints;
    }

    // TODO: Is this function actually a thing?
    inline const CShaderConstantNameData& GetBoolConstants() const
    {
        return Bools;
    }

    // TODO: Is this function actually a thing?
    inline CShaderConstantNameData& GetBoolConstants()
    {
        return Bools;
    }

    // TODO: Is this function actually a thing?
    inline const CShaderSamplerUsageData& GetTextureSamplers() const
    {
        return Textures;
    }

    // TODO: Is this function actually a thing?
    inline CShaderSamplerUsageData& GetTextureSamplers()
    {
        return Textures;
    }
};

class CPixelShaderParameterResource
{
    CShaderConstantNameResource m_floatConstants;
    CShaderConstantNameResource m_intConstants;
    CShaderConstantNameResource m_boolConstants;
    CShaderSamplerUsageResource m_texSamplers;
    CShaderConstantNameResource field_0x20; // TODO: Is this type correct? It's probably CShaderResourceNameResource?

public:
    // TODO: Is this function actually a thing?
    inline const CShaderConstantNameResource& GetFloatConstants() const
    {
        return m_floatConstants;
    }

    // TODO: Is this function actually a thing?
    inline const CShaderConstantNameResource& GetIntConstants() const
    {
        return m_intConstants;
    }

    // TODO: Is this function actually a thing?
    inline const CShaderConstantNameResource& GetBoolConstants() const
    {
        return m_boolConstants;
    }

    // TODO: Is this function actually a thing?
    inline const CShaderSamplerUsageResource& GetTextureSamplers() const
    {
        return m_texSamplers;
    }

    // TODO: Is this function actually a thing?
    inline std::size_t GetTotalConstantCount() const
    {
        return (m_floatConstants.GetCount() +
            m_intConstants.GetCount() +
            m_boolConstants.GetCount());
    }

    // TODO: Is this function actually a thing?
    inline std::size_t GetTotalSamplerCount() const
    {
        return (m_texSamplers.GetCount());
    }
};
}
}
