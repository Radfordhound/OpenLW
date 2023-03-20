#include "pch.h"
#include "Hedgehog/Utility/hhResDependTypeInfo.h"

using namespace hh::ut;

LWAPI(0x03694470, TODO)
static IResourceLoader* CreateResDependResourceLoader()
{
    return new ResDependLoader();
}

namespace hh
{
namespace ut
{
ResourceTypeInfo ResDependTypeInfo =
{
    "ResPacDepend",                                                     // Type
    CreateResDependResourceLoader                                       // CreateLoader
};
}
}
