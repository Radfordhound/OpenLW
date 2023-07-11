// TODO: The name of this file is correct, but the path was guessed!
#include "OpenLW/pch.h"
#include "SoundHandle.h"
#include "SoundPlayer.h"

namespace app
{
namespace fnd
{
SoundHandle::SoundHandle() :
    m_player(nullptr) {}

SoundHandle::SoundHandle(const SoundHandleObj* param_1) :
    m_player(&SoundPlayer::GetInstance()) {}
} // fnd
} // app
