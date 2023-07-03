// TODO: The name of this file is correct, but the path was guessed!
#include "OpenLW/pch.h"
#include "PlayerStateUtilSound.h"
#include "Player/Base/PlayerState.h"

namespace app
{
namespace Player
{
namespace StateUtil
{
#ifndef LWAPI_EXPOSE_INTERNAL_LINKAGE
namespace
{
#endif
void GetVoiceName(VoiceID param_1)
{
    // TODO
}
#ifndef LWAPI_EXPOSE_INTERNAL_LINKAGE
} // <unnamed>
#endif

fnd::SoundHandle PlaySE(CStateGOC& goc, const char* soundName)
{
    return fnd::SoundHandle(); // TODO: Remove this line and un-comment the below!
    //return goc.PlaySE(soundName, false);
}

void PlaySE3D(CStateGOC& param_1, const char* param_2)
{
    // TODO
}

void StopSE(CStateGOC& param_1, const fnd::SoundHandle& param_2)
{
    // TODO
}

void PlayVoice(CStateGOC& param_1, const char* param_2, bool param_3)
{
    // TODO
}

void PlayVoice(CStateGOC& param_1, VoiceID param_2)
{
    // TODO
}
} // StateUtil
} // Player
} // app
