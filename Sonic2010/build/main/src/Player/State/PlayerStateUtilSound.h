// TODO: The name of this file is correct, but the path was guessed!
// NOTE: Initial file was auto-generated by SymbolsDB.
#pragma once

namespace app
{
namespace fnd
{
class SoundHandle;
} // fnd

namespace Player
{
class CStateGOC;

// TODO: Move this to another header?
enum VoiceID
{
    // TODO
};

namespace StateUtil
{
#ifdef LWAPI_EXPOSE_INTERNAL_LINKAGE
LWAPI(0x02a277d0, TODO)
void GetVoiceName(VoiceID param_1);
#endif

LWAPI(0x02a277e4, TODO)
void PlaySE(CStateGOC& param_1, const char* param_2);

LWAPI(0x02a277f8, TODO)
void PlaySE3D(CStateGOC& param_1, const char* param_2);

LWAPI(0x02a27808, TODO)
void StopSE(CStateGOC& param_1, const fnd::SoundHandle& param_2);

LWAPI(0x02a27858, TODO)
void PlayVoice(CStateGOC& param_1, const char* param_2, bool param_3);

LWAPI(0x02a2792c, TODO)
void PlayVoice(CStateGOC& param_1, VoiceID param_2);
} // StateUtil
} // Player
} // app
