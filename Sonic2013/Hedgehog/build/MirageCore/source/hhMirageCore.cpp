#include "Hedgehog/MirageCore/hhMirageCore.h"
#include <Hedgehog/MTBase/Thread/hhMTJobThreadFactory.h>

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
