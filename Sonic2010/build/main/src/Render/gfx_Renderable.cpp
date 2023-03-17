// TODO: The name of this file is correct, but the path was guessed!
#include "gfx_Renderable.h"
#include "RenderableContainer.h"
#include <cstring>

namespace app
{
namespace gfx
{
Renderable::Renderable() :
    PriorityDrawOpa(0x80),
    Scene(0xFF),
    Option(1),
    SubScene(0xFF),
    PriorityDrawXlu(0x80),
    Container(nullptr)
{
    field_0x48.field_0x8 = this;
    field_0x58 = 0x80;
    field_0x54 = 1;
    field_0x3c.field_0x4 = 1;
    field_0x48.field_0x4 = 0;
    field_0x3c.field_0x8 = this;
}

Renderable::~Renderable()
{
    if (Container)
    {
        Container->RemoveObject(this);
    }
}

bool Renderable::GetMTSync()
{
    return false;
}

void Renderable::CalcView() {}

void Renderable::UpdateFrame(float param_1) {}

bool Renderable::CheckEnable()
{
    return true;
}

void Renderable::SetPriorityDrawOpa(int priorityDrawOpa)
{
    PriorityDrawOpa = static_cast<unsigned char>(priorityDrawOpa);
}

void Renderable::SetOption(unsigned int opt)
{
    Option = static_cast<unsigned short>(opt);
}

void Renderable::SetName(const char* name)
{
    std::strcpy(Name, name);
}
}
}
