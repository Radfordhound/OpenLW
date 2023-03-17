// TODO: The name of this file is correct, but the path was guessed!
#include "ResourceCustom.h"
#include "ResourceManager.h"

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
namespace xgame
{
ResourceCustomOrcaLoader::~ResourceCustomOrcaLoader() {}

void ResourceCustomOrcaLoader::Setup(void* param_1, const fnd::ResourceArgsData& args)
{
    ResourceManager* resMgr = static_cast<ResourceManager*>(param_1);
    ResRawData res = resMgr->Get<ResRawData>(args.Name);

    if (res.IsValid() && !res.GetAddress())
    {
        res.SetData(args);

        // TODO
        /*BinaryFile bin(res.GetAddress());
        res.SetResolvedData(bin.GetDataAddress(-1));*/
    }
}
}

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
