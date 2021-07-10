#include "Hedgehog/MirageCore/hhMirageCore.h"
#include <Hedgehog/MTBase/Thread/hhMTJobThreadFactory.h>

namespace hh
{
using namespace MTBase;

namespace mr
{
void InitializeHHMirage()
{
    hhMTSimpleJobStart();
}
}
}
