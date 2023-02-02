#include "SyncTimer.h"
#include "fnd/Allocators.h"
#include "csl/fnd/thread.h"
#include "csl/math/algorithm.h"

namespace app
{
SyncTimer::~SyncTimer()
{
    csl::fnd::Tick::Finalize();
}

void SyncTimer::CalcFps()
{
    // TODO
}

long long SyncTimer::GetDiff()
{
    csl::fnd::Tick newTick = csl::fnd::Tick::Sample();
    csl::fnd::Tick oldTick = field_0x18;

    field_0x18 = newTick;

    csl::fnd::Tick diff = (newTick.Value - oldTick.Value);
    return diff.ToMicroseconds();
}

void SyncTimer::Reset()
{
    csl::fnd::Tick tick = csl::fnd::Tick::Sample();

    // TODO

    field_0x18 = tick;

    // TODO
}

void SyncTimer::SetFPS(float fps)
{
    m_fps = fps;
    field_0x13c = fps;
    Reset();
}

float SyncTimer::Sync()
{
    float deltaTime = static_cast<float>(1.0 / m_fps);
    field_0x24 = (static_cast<float>(GetDiff()) * 0.00000100f);
    
    float dVar5 = csl::math::Max(0.0f, deltaTime - field_0x24);
    if (!field_0xc)
    {
        field_0x20 = 0.0f;
        if (field_0x24 < deltaTime)
        {
            float fVar1 = (dVar5 * 1000.0f);
            if (fVar1 >= 2147483600.0f)
            {
                csl::fnd::ThreadSleep(static_cast<unsigned int>(
                    fVar1 - 2147483600.0f) + 0x80000000U);
                
                field_0x24 += dVar5;
            }
            else
            {
                csl::fnd::ThreadSleep(static_cast<unsigned int>(fVar1));
                field_0x24 += dVar5;
            }
        }

        GetDiff();
        CalcFps();
        return field_0x24;
    }
    else
    {
        float fVar2 = (dVar5 * 1000.0f);
        if (fVar2 >= 2147483600.0f)
        {
            csl::fnd::ThreadSleep(static_cast<unsigned int>(
                fVar2 - 2147483600.0f) + 0x80000000U);

            GetDiff();

            field_0x2c += deltaTime;
            field_0x28 += dVar5;
            field_0x20 = 0.0f;

            if (1.0 < fVar2)
            {
                field_0x20 = field_0x28;
                field_0x28 = 0.0f;
                field_0x2c = 0.0f;
            }
        }
        else
        {
            csl::fnd::ThreadSleep(static_cast<unsigned int>(fVar2));
            GetDiff();

            field_0x2c += deltaTime;
            field_0x28 += dVar5;
            field_0x20 = 0.0f;

            if (1.0 < fVar2)
            {
                field_0x20 = field_0x28;
                field_0x28 = 0.0f;
                field_0x2c = 0.0f;
            }
        }

        field_0x24 = deltaTime;
        CalcFps();
        return field_0x24;
    }
}

SyncTimer::SyncTimer() : // TODO: This initilization is probably completely wrong lol, please look into it and rewrite.
    field_0xc(1),
    field_0x14(1),
    field_0x20(0.0f),
    field_0x24(0.0f),
    field_0x28(0.0f),
    field_0x2c(0.0f)
{
    csl::fnd::Tick::Initialize();
    SetFPS(60.0f);
}

// Wii U: 0x021ca5c0, PC: 0x004ad090
static void* SyncTimer_init()
{
    csl::fnd::IAllocator* allocator = fnd::GetSingletonAllocator();
    SyncTimer* timer = new (allocator) SyncTimer();
    timer->AddRef();
    return timer;
}

// Wii U: 0x021ca610, PC: TODO
static void SyncTimer_destroy(void* ptr)
{
    static_cast<SyncTimer*>(ptr)->Release();
}

DEFINE_SINGLETON(SyncTimer, SyncTimer_init, SyncTimer_destroy);
}
