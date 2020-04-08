#pragma once
#include "fnd/Singleton.h"
#include "fnd/ReferencedObject.h"

namespace app
{
class SyncTimer : public fnd::ReferencedObject, public csl::fnd::Singleton<SyncTimer>
{
    DECLARE_SINGLETON

    // TODO: Data Members

public:

    /*
        @brief Constructor for SyncTimer.
        <b>Wii U: 0x021ca10c, PC: TODO</b>
    */
    SyncTimer();

    /*
        @brief Destructor for SyncTimer.
        <b>Wii U: 0x021ca1a4, PC: TODO</b>
    */
    ~SyncTimer() override;

    /* <b>Wii U: 0x021ca2a8, PC: TODO</b> */
    void CalcFps();

    /* <b>Wii U: 0x021ca208, PC: TODO</b> */
    void GetDiff();

    /* <b>Wii U: 0x021ca094, PC: 0x004acc70</b> */
    void Reset();

    /* <b>Wii U: 0x021ca100, PC: TODO</b> */
    void SetFPS(float fps);

    /* <b>Wii U: 0x021ca398, PC: TODO</b> */
    float Sync();
};
}
