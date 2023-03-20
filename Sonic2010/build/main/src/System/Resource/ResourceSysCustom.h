// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include "ResourceCustom.h"

namespace app
{
namespace fnd
{
LWAPI(0x1032c3b0, TODO)
extern ResourceCustomInfo DefResourceCustomInfo;

LWAPI(0x1032c3bc, TODO)
extern ResourceCustomInfo PacResourceCustomInfo;

struct ResourceCustomDefLoader : IResourceCustomLoader
{
    LWAPI(0x021b10cc, TODO)
    ~ResourceCustomDefLoader();

    LWAPI(0x021b10f0, TODO)
    void Setup(void* param_1, const ResourceArgsData& args);
};

struct ResourceCustomPacLoader : IResourceCustomLoader
{
    LWAPI(0x021b1158, TODO)
    ~ResourceCustomPacLoader();

    LWAPI(0x021b116c, TODO)
    void Setup(void* param_1, const ResourceArgsData& args);
};
}
}
