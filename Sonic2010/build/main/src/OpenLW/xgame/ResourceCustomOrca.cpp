#include "ResourceCustomOrca.h"
#include "../fnd/ResourceManager.h"

using namespace app::fnd;
//using namespace hh::ut; // TODO

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
}
