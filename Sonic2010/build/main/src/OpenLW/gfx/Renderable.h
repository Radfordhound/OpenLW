#pragma once
#include "RenderableEvent.h"
#include <Hedgehog/Base/System/hhObject.h>
#include <csl/ut/link_list.h>

namespace app
{
namespace Render // TODO: Move this stuff to another header.
{
struct SceneGroupType
{
enum _ESceneGroupType
{
    UNKNOWN_800 = 0x800
};
};
}

namespace gfx
{
struct RenderableContainer;

struct Renderable : public hh::base::CRefCountObject // size == 0x5c
{
    RenderableContainer* Container;
    csl::ut::LinkListNode Node;
    unsigned char PriorityDrawOpa;
    unsigned char PriorityDrawXlu;
    unsigned short Option;
    unsigned char Scene;
    unsigned char SubScene;
    char Name[32];
    RenderableEvent field_0x3c;
    RenderableEvent field_0x48;
    unsigned int field_0x54;
    unsigned char field_0x58;

    // Wii U: 0x02255c18, PC: TODO
    Renderable();

    // Wii U: 0x02255cdc, PC: TODO
    ~Renderable();

    // Wii U: 0x02255d5c, PC: TODO
    virtual bool GetMTSync();

    // TODO: Is this the function that is supposed to be here?
    virtual void Render(const hh::gfx::RenderEventParam* params) = 0;

    // Wii U: 0x02255d64, PC: TODO
    virtual void CalcView();

    // Wii U: 0x02255d68, PC: TODO
    virtual void UpdateFrame(float param_1);

    // Wii U: 0x02255d6c, PC: TODO
    virtual bool CheckEnable();

    // Wii U: 0x02255d74, PC: TODO
    void SetPriorityDrawOpa(int priorityDrawOpa);

    // Wii U: 0x02255d84, PC: TODO
    void SetOption(unsigned int opt);

    // Wii U: 0x02255d9c, PC: TODO
    void SetName(const char* name);
};
}
}
