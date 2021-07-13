#pragma once
#include "ResourceCustom.h"

namespace app
{
namespace fnd
{
// Wii U: 0x1032c3b0, PC: TODO
extern ResourceCustomInfo DefResourceCustomInfo;

// Wii U: 0x1032c3bc, PC: TODO
extern ResourceCustomInfo PacResourceCustomInfo;

struct ResourceCustomDefLoader : IResourceCustomLoader
{
    // Wii U: 0x021b10cc, PC: TODO
    ~ResourceCustomDefLoader();

    // Wii U: 0x021b10f0, PC: TODO
    void Setup(void* param_1, const ResourceArgsData& args);
};

struct ResourceCustomPacLoader : IResourceCustomLoader
{
    // Wii U: 0x021b1158, PC: TODO
    ~ResourceCustomPacLoader();

    // Wii U: 0x021b116c, PC: TODO
    void Setup(void* param_1, const ResourceArgsData& args);
};
}
}
