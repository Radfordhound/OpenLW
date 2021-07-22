#include "../xgame/ResourceCustomOrca.h"

using namespace app::fnd;
using namespace app::xgame;

// Wii U: 0x02b2c150, PC: TODO
static IResourceCustomLoader* CreateOrcaResourceCustomLoader()
{
    return new ResourceCustomOrcaLoader();
}

// Wii U: 0x02b2c188, PC: TODO
static IResourceCustomLoader* CreateCriAcfResourceCustomLoader()
{
    return nullptr; // TODO
}

// Wii U: 0x02b2c1c0, PC: TODO
static IResourceCustomLoader* CreateCriAcbResourceCustomLoader()
{
    return nullptr; // TODO
}

namespace app
{
namespace fnd
{
ResourceCustomInfo OrcaResourceCustomInfo =
{
    "orc",                                                              // Extension
    CreateOrcaResourceCustomLoader,                                     // CreateLoader
    nullptr                                                             // Loader
};

ResourceCustomInfo CriAcfResourceCustomInfo =
{
    "acf",                                                              // Extension
    CreateCriAcfResourceCustomLoader,                                   // CreateLoader
    nullptr                                                             // Loader
};

ResourceCustomInfo CriAcbResourceCustomInfo =
{
    "acb",                                                              // Extension
    CreateCriAcbResourceCustomLoader,                                   // CreateLoader
    nullptr                                                             // Loader
};
}
}
