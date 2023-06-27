// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include "Actor.h"

namespace app
{
namespace fnd
{
class CLeafActor : public CActor
{
public:
    LWAPI(0x02183c84, 0x0048d3f0)
    bool ForEach(CActorTraverser& param_1);

    LWAPI(0x02183ca0, 0x0048d410)
    bool ActorProc(int id, void* data);

    LWAPI(0x02183d30, 0x0049caf0)
    ~CLeafActor();
};

LWAPI_STATIC_ASSERT_SIZE(CLeafActor, 0x1c)
} // fnd
} // app
