#include "Hedgehog/Base/Platform/D3d9/hhBaseD3D9.h"
#include "Hedgehog/Base/System/hhPluginable.h"

#ifdef _WIN32
#include "Hedgehog/Base/Platform/D3d9/hhEventWaitD3D9.h"
#endif

namespace hh
{
namespace base
{
static CEventWait::TSimpleFactory<CEventWaitD3D9> DAT_104015d0;
static unsigned int DAT_104015c8 = 0; // TODO: Is this correct?

void InitializeHHD3D9(const SInitializeHHBaseSetting* baseSetting)
{
    // TODO
    
    if (DAT_104015c8 == 0)
    {
        DAT_104015c8 = 1;
        DAT_104015d0 = CEventWait::TSimpleFactory<CEventWaitD3D9>();
    }

    CEventWait::SetAbstractFactory(&DAT_104015d0);

    // TODO
}

void FinalizeHHD3D9() {}
}
}
