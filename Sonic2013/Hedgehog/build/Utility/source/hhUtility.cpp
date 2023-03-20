#include "pch.h"
#include "Hedgehog/Utility/hhUtility.h"
#include "Hedgehog/Utility/hhResourceTypeInfoRegistry.h"

namespace hh
{
namespace ut
{
void InitializeHHUtility(const SInitializeHHUtilitySetting* setting)
{
    ResourceTypeInfoRegistry::ReplaceInstance(new ResourceTypeInfoRegistry());
}
}
}
