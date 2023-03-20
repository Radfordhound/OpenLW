#include "pch.h"
#include "Hedgehog/Utility/hhComPtr.h"
#include <Hedgehog/MirageCore/Misc/hhRenderingInfrastructure.h>

using namespace hh::mr;

void hhComPtr_Release(hh::rsdx::RsdxResource* res)
{
    CRenderingInfrastructure::ReleaseD3DRenderResource(res);
}
