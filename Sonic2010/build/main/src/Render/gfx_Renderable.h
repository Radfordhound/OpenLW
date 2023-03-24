// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include "gfx_RenderableEvent.h"
#include <Hedgehog/Base/System/hhObject.h>
#include <csl/ut/linklist.h>

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

    LWAPI(0x02255c18, TODO)
    Renderable();

    LWAPI(0x02255cdc, TODO)
    ~Renderable();

    LWAPI(0x02255d5c, TODO)
    virtual bool GetMTSync();

    // TODO: Is this the function that is supposed to be here?
    virtual void Render(const hh::gfx::RenderEventParam* params) = 0;

    LWAPI(0x02255d64, TODO)
    virtual void CalcView();

    LWAPI(0x02255d68, TODO)
    virtual void UpdateFrame(float param_1);

    LWAPI(0x02255d6c, TODO)
    virtual bool CheckEnable();

    LWAPI(0x02255d74, TODO)
    void SetPriorityDrawOpa(int priorityDrawOpa);

    LWAPI(0x02255d84, TODO)
    void SetOption(unsigned int opt);

    LWAPI(0x02255d9c, TODO)
    void SetName(const char* name);
};
}
}
