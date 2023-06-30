// TODO: Both the name of this file and its path were guessed!
#pragma once
#include "System/ReferencedObject.h"

namespace app
{
namespace Player
{
class CBasePosture;

class CPostureFactoryBase : public fnd::ReferencedObject
{
public:
    LWAPI(0x0292B074, TODO)
    ~CPostureFactoryBase();
};

template<class T>
class TPostureFactory : public CPostureFactoryBase
{
OPENLW_PROTECTED
    std::size_t m_postureSize;
    const char* m_postureGroupID;

public:
    // TODO: Are these functions actually part of CPostureFactoryBase?
    // There seems to be no symbols for them, which suggests that they are not.

    virtual CBasePosture* CreatePosture(unsigned char* postureMemoryBuffer)
    {
        return new (postureMemoryBuffer) T();
    }

    virtual void DeletePosture(CBasePosture* posture)
    {
        delete posture;
    }

    TPostureFactory(std::size_t postureSize = sizeof(T), const char* postureGroupID = T::GroupID) :
        m_postureSize(postureSize),
        m_postureGroupID(postureGroupID) {}
};
} // Player
} // app
