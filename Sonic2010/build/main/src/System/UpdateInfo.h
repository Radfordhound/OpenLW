// TODO: Both the name of this file and its path were guessed!
#pragma once
namespace app
{
namespace fnd
{
enum UpdatingPhase
{
    PHASE_ONE = 0,
    PHASE_TWO = 1,
    PHASE_THREE = 2,
    PHASE_COUNT
};

struct SUpdateInfo
{
    float DeltaTime;
    unsigned int CurFrameIndex;
    unsigned int field_0x8; // TODO: Is this correct?
    unsigned int field_0xc; // TODO: Is this correct?
    
    // TODO: Does this struct contain any additional data members?
};
}
}
