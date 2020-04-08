#pragma once
#include "fnd/ReferencedObject.h"
#include "fnd/CBranchActor.h"

namespace app
{
class Application;
struct GameBase : public fnd::ReferencedObject, public fnd::CBranchActor
{
    // TODO: Data Members (if any)
    // TODO: Does GameBase need an explicit destructor?

    /* <b>Wii U: TODO, PC: TODO</b> */
    virtual void Config(Application& app);

    /* <b>Wii U: TODO, PC: TODO</b> */
    virtual void OnSetup(Application& app);

    /* <b>Wii U: TODO, PC: TODO</b> */
    virtual void OnShutdown(Application& app);

    /* <b>Wii U: TODO, PC: TODO</b> */
    virtual void Tick(Application& app);

    /* <b>Wii U: TODO, PC: TODO</b> */
    virtual void Draw(Application& app);

    // TODO: Other functions?
};
}
