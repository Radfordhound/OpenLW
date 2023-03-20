// TODO: The name of this file is correct, but the path was guessed!
#include "pch.h"
#include "ResourceSysCustom.h"
#include "ResourceManager.h"
#include "Render/RenderManager.h"
#include <Hedgehog/Utility/hhPackfile.h>

using namespace app::fnd;
using namespace app::gfx;
using namespace hh::ut;
using namespace hh::mr;

LWAPI(0x021b0f84, TODO)
static IResourceCustomLoader* CreateDefResourceCustomLoader()
{
    return new ResourceCustomDefLoader();
}

LWAPI(0x021b0fbc, TODO)
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
        RenderManager& renderMgr = RenderManager::GetInstance();
        CRenderingInfrastructure* renderInfra = renderMgr.GetRenderingDevice();

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
