#pragma once
#include "fnd/ReferencedObject.h"
#include "fnd/Singleton.h"
#include "csl/fnd/tick.h"

namespace app
{
class SyncTimer : public fnd::ReferencedObject, public csl::fnd::Singleton<SyncTimer>
{
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
    // Wii U: 0x021ca1a4, PC: 0x004acc40
    ~SyncTimer();

    // Wii U: 0x021ca2a8, PC: TODO
    void CalcFps();

    // Wii U: 0x021ca208, PC: Inlined
    long long GetDiff();

    // Wii U: 0x021ca094, PC: 0x004acc70
    void Reset();

    // Wii U: 0x021ca100, PC: Inlined
    void SetFPS(float fps);

    // Wii U: 0x021ca398, PC: 0x004ace10
    float Sync();

    // Wii U: 0x021ca10c, PC: 0x004acff0
    SyncTimer();
};
}
