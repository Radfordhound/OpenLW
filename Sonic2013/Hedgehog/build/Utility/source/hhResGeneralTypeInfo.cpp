#include "pch.h"
#include "Hedgehog/Utility/hhResGeneralTypeInfo.h"

using namespace hh::ut;

LWAPI(0x0369492c, TODO)
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
