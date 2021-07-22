#pragma once
#include "../fnd/ResourceCustom.h"

namespace app
{
namespace xgame
{
struct ResourceCustomOrcaLoader : fnd::IResourceCustomLoader
{
    // Wii U: 0x02b2c30c, PC: TODO
    ~ResourceCustomOrcaLoader();

    // Wii U: 0x02b2c330, PC: TODO
    void Setup(void* param_1, const fnd::ResourceArgsData& args);
};
}
}
