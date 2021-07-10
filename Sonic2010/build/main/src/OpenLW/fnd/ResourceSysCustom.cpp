#include "ResourceSysCustom.h"
#include "ResourceManager.h"
#include "../gfx/RenderManager.h"
#include <Hedgehog/Base/File/hhPackfile.h>

using namespace hh;
using namespace ut;
using namespace mr;

namespace app
{
using namespace gfx;

namespace fnd
{
struct ResourceCustomDefLoader : IResourceCustomLoader
{
    // Wii U: 0x021b10cc, PC: TODO
    ~ResourceCustomDefLoader() {}

    // Wii U: 0x021b10f0, PC: TODO
    void Setup(void* param_1, const ResourceArgsData& args)
    {
        ResourceManager* resMgr = static_cast<ResourceManager*>(param_1);
        ResRawData res = resMgr->Get<ResRawData>(args.Name);
        
        if (res.IsValid() && !res.GetAddress())
        {
            res.SetData(args);
        }
    }
};

// Wii U: 0x021b0f84, PC: TODO
static IResourceCustomLoader* CreateDefResourceCustomLoader()
{
    return new ResourceCustomDefLoader();
}

struct ResourceCustomPacLoader : IResourceCustomLoader
{
    // Wii U: 0x021b1158, PC: TODO
    ~ResourceCustomPacLoader() {}

    // Wii U: 0x021b116c, PC: TODO
    void Setup(void* param_1, const ResourceArgsData& args)
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
};

// Wii U: 0x021b0fbc, PC: TODO
static IResourceCustomLoader* CreatePacResourceCustomLoader()
{
    return new ResourceCustomPacLoader();
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
