#include "SyncTimer.h"
#include "csl/fnd/Tick.h"

namespace app
{
SyncTimer::SyncTimer()
{
    // TODO
    SetFPS(60.0f);
}

SyncTimer::~SyncTimer()
{
    // TODO
}

void SyncTimer::CalcFps()
{
    // TODO
}

void SyncTimer::GetDiff()
{
    // TODO
}

void SyncTimer::Reset()
{
    csl::fnd::Tick tick;
    csl::fnd::Tick::Sample(&tick);
    // TODO
}

void SyncTimer::SetFPS(float fps)
{
    // TODO
}

float SyncTimer::Sync()
{
    // TODO
    return 0;
}

static void* SyncTimer_init()
{
    // TODO
    return nullptr;
}

static void SyncTimer_destroy()
{
    // TODO
}

DEFINE_SINGLETON(SyncTimer);
}
