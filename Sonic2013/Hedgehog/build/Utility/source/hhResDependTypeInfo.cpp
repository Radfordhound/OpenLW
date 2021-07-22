#include "Hedgehog/Utility/hhResDependTypeInfo.h"

using namespace hh::ut;

// Wii U: 0x03694470, PC: TODO
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
