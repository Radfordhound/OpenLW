// TODO: Both the name of this file and its path were guessed!
#pragma once
#include "ReferencedObject.h"
#include "BranchActor.h"

namespace app
{
struct Application;

struct GameBase : public fnd::ReferencedObject, public fnd::CBranchActor // size == 104
{
    // TODO: Does GameBase need an explicit destructor?

    LWAPI(0x021c8800, TODO)
    virtual void Config(Application& app);

    LWAPI(0x021c8804, TODO)
    virtual void OnSetup(Application& app);

    LWAPI(0x021c8808, TODO)
    virtual void OnShutdown(Application& app);

    LWAPI(0x021c880c, TODO)
    virtual void Tick(Application& app);

    LWAPI(0x021c8810, TODO)
    virtual void Draw(Application& app);

    // TODO: Other functions?
};
}
