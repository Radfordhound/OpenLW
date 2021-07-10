#pragma once
#include "fnd/ReferencedObject.h"
#include "fnd/CBranchActor.h"

namespace app
{
struct Application;

struct GameBase : public fnd::ReferencedObject, public fnd::CBranchActor // size == 104
{
    // TODO: Does GameBase need an explicit destructor?

    // Wii U: 0x021c8800, PC: TODO
    virtual void Config(Application& app);

    // Wii U: 0x021c8804, PC: TODO
    virtual void OnSetup(Application& app);

    // Wii U: 0x021c8808, PC: TODO
    virtual void OnShutdown(Application& app);

    // Wii U: 0x021c880c, PC: TODO
    virtual void Tick(Application& app);

    // Wii U: 0x021c8810, PC: TODO
    virtual void Draw(Application& app);

    // TODO: Other functions?
};
}
