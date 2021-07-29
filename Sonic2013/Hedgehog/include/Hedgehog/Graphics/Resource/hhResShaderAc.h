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
    // Wii U: 0x0367cce8, PC: TODO
    static const ut::ResourceTypeInfo& staticTypeInfo();

    // Wii U: 0x0367ccf4, PC: TODO
    ResTechnique GetResTechnique(std::size_t index) const;

    // Wii U: 0x0367cd8c, PC: TODO
    ResParameter GetDefaultParameter();

    // Wii U: 0x0367cde0, PC: TODO
    ResMapChannelFixed GetResMapChannelFixed(std::size_t index);

    // Wii U: 0x0367ce78, PC: TODO
    ResName GetName();

    // Wii U: 0x0367cecc, PC: TODO
    ResUserData GetResUserData();

    // Wii U: 0x0367d4ac, PC: TODO
    void* Replace(const char* name, std::size_t* size, csl::fnd::IAllocator* allocator);

    // Wii U: 0x0367d518, PC: TODO
    bool Setup(std::size_t size, csl::fnd::IAllocator* allocator);

    // Wii U: 0x0367d5b0, PC: TODO
    bool Setup(std::size_t size, csl::fnd::IAllocator* allocator, ut::Packfile pac);

    // Wii U: 0x0367d978, PC: 0x0367d978
    void Cleanup(std::size_t index);

    // Wii U: 0x0367da28, PC: TODO
    bool FinalInitialization();

    inline ResShader(const void* data) :
        ResCommon<ResShaderData>(data) {}

    inline ResShader(void* data = nullptr) :
        ResCommon<ResShaderData>(data) {}
};
}
}
}
