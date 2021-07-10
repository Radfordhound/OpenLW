#pragma once
namespace app
{
namespace fnd
{
struct SUpdateInfo
{
    float DeltaTime;
    unsigned int CurFrameIndex;
    unsigned int field_0x8; // TODO: Is this correct?
    unsigned int field_0xc; // TODO: Is this correct?
    
    // TODO: Does this struct contain any additional data members?

    // TODO: Does this actually exist?
    inline SUpdateInfo() :
        DeltaTime(0),
        CurFrameIndex(0),
        field_0x8(0),
        field_0xc(0) {}
};
}
}
