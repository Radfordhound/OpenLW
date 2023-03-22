// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include "ReferencedObject.h"
#include "Singleton.h"
#include <csl/fnd/tick.h>

namespace app
{
class SyncTimer : public fnd::ReferencedObject, public csl::fnd::Singleton<SyncTimer>
{
OPENLW_PRIVATE
    DECLARE_SINGLETON

    bool field_0xc;
    // TODO: Any data members here? Or is it just padding?
    float m_fps;
    unsigned int field_0x14;
    csl::fnd::Tick field_0x18;
    float field_0x20;
    float field_0x24;
    float field_0x28;
    float field_0x2c;
    // TODO: Data Members
    float field_0x13c;

public:
    LWAPI(0x021ca1a4, 0x004acc40)
    ~SyncTimer();

    LWAPI(0x021ca2a8, TODO)
    void CalcFps();

    LWAPI(0x021ca208, NONE)
    long long GetDiff();

    LWAPI(0x021ca094, 0x004acc70)
    void Reset();

    LWAPI(0x021ca100, NONE)
    void SetFPS(float fps);

    LWAPI(0x021ca398, 0x004ace10)
    float Sync();

    LWAPI(0x021ca10c, 0x004acff0)
    SyncTimer();
};
}
