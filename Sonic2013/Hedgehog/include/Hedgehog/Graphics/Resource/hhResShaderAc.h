#pragma once
#include "hhResParameter.h"
#include "hhResMapChannelFixed.h"
#include "hhResTechnique.h"
#include <Hedgehog/Utility/hhPackfile.h>

namespace hh
{
namespace gfx
{
namespace res
{
struct ResShaderData
{
    ResTechniqueData* Techniques;
    std::size_t TechniqueCount;
    ResParameterData DefaultParameter;
    ResMapChannelFixedData* field_0x28;
    std::size_t field_0x2c;
    ResNameData Name;
    ResUserDataData UserData;
};

struct ResShader : public ut::ResCommon<ResShaderData>
{
    LWAPI(0x0367cce8, TODO)
    static const ut::ResourceTypeInfo& staticTypeInfo();

    LWAPI(0x0367ccf4, TODO)
    ResTechnique GetResTechnique(std::size_t index) const;

    LWAPI(0x0367cd8c, TODO)
    ResParameter GetDefaultParameter();

    LWAPI(0x0367cde0, TODO)
    ResMapChannelFixed GetResMapChannelFixed(std::size_t index);

    LWAPI(0x0367ce78, TODO)
    ResName GetName();

    LWAPI(0x0367cecc, TODO)
    ResUserData GetResUserData();

    LWAPI(0x0367d4ac, TODO)
    void* Replace(const char* name, std::size_t* size, csl::fnd::IAllocator* allocator);

    LWAPI(0x0367d518, TODO)
    bool Setup(std::size_t size, csl::fnd::IAllocator* allocator);

    LWAPI(0x0367d5b0, TODO)
    bool Setup(std::size_t size, csl::fnd::IAllocator* allocator, ut::Packfile pac);

    LWAPI(0x0367d978, 0x0367d978)
    void Cleanup(std::size_t index);

    LWAPI(0x0367da28, TODO)
    bool FinalInitialization();

    inline ResShader(const void* data) :
        ResCommon<ResShaderData>(data) {}

    inline ResShader(void* data = nullptr) :
        ResCommon<ResShaderData>(data) {}
};
}
}
}
