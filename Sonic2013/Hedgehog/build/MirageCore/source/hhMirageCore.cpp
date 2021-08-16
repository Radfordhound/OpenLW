#include "Hedgehog/MirageCore/hhMirageCore.h"
#include <Hedgehog/MTBase/hhMTSimpleJob.h>

using namespace hh::MTBase;

namespace hh
{
namespace mr
{
void InitializeHHMirage()
{
    hhMTSimpleJobStart();
}
}
}
