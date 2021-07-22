#include "Hedgehog/Utility/hhResGeneralTypeInfo.h"

using namespace hh::ut;

// Wii U: 0x0369492c, PC: TODO
static IResourceLoader* CreateResPacGeneralResourceLoader()
{
    return new ResPacGeneralResourceLoader();
}

namespace hh
{
namespace ut
{
ResourceTypeInfo ResRawDataTypeInfo =
{
    "ResRawData",                                                       // Type
    CreateResPacGeneralResourceLoader                                   // CreateLoader
};
}
}
