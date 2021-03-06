#include "ResourceSysCustom.h"
#include "ResourceManager.h"
#include "../gfx/RenderManager.h"
#include <Hedgehog/Base/File/hhPackfile.h>

using namespace app::fnd;
using namespace app::gfx;
using namespace hh::ut;
using namespace hh::mr;

// Wii U: 0x021b0f84, PC: TODO
static IResourceCustomLoader* CreateDefResourceCustomLoader()
{
    return new ResourceCustomDefLoader();
}

// Wii U: 0x021b0fbc, PC: TODO
static IResourceCustomLoader* CreatePacResourceCustomLoader()
{
    return new ResourceCustomPacLoader();
}

namespace app
{
namespace fnd
{
ResourceCustomDefLoader::~ResourceCustomDefLoader() {}

void ResourceCustomDefLoader::Setup(void* param_1, const ResourceArgsData& args)
{
    ResourceManager* resMgr = static_cast<ResourceManager*>(param_1);
    ResRawData res = resMgr->Get<ResRawData>(args.Name);

    if (res.IsValid() && !res.GetAddress())
    {
        res.SetData(args);
    }
}

ResourceCustomPacLoader::~ResourceCustomPacLoader() {}

void ResourceCustomPacLoader::Setup(void* param_1, const ResourceArgsData& args)
{
    ResourceManager* resMgr = static_cast<ResourceManager*>(param_1);
    ResRawData res = resMgr->Get<ResRawData>(args.Name);

    if (res.IsValid() && !res.GetAddress())
    {
        res.SetData(args);

        Packfile pac(res.GetAddress());
        RenderManager* renderMgr = RenderManager::GetInstance();
        CRenderingInfrastructure* renderInfra = renderMgr->GetRenderingDevice();

        pac.Setup(args.Allocator, renderInfra);
        if (pac.IsImportCompleted())
        {
            resMgr->SetupCallback(pac, args.Allocator);
        }
    }
}

ResourceCustomInfo DefResourceCustomInfo =
{
    "*",                                                                // Extension
    CreateDefResourceCustomLoader,                                      // CreateLoader
    nullptr                                                             // Loader
};

ResourceCustomInfo PacResourceCustomInfo =
{
    "pac",                                                              // Extension
    CreatePacResourceCustomLoader,                                      // CreateLoader
    nullptr                                                             // Loader
};
}
}
