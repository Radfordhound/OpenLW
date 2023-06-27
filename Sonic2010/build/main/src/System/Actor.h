// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include "UpdateInfo.h"
#include <csl/ut/bitset.h>
#include <boost/noncopyable.hpp>

// Avoid name collisions on Windows.
#ifdef SendMessage
#undef SendMessage
#endif

namespace app
{
namespace fnd
{
class Message;
class MessageManager;
class CActorTraverser;

class CActor : public boost::noncopyable
{
OPENLW_PROTECTED
    unsigned int m_ID;
    MessageManager* m_msgMgr;
    CActor* m_parent;
    csl::ut::Bitset<unsigned char> m_updateFlags;
    bool field_0xd;
    unsigned char m_flags;
    bool m_enabled;
    unsigned int m_allowedMessageFlags; // TODO: Is this type correct?
    void* field_0x14; // TODO: Is this type correct?

public:
    // TODO: Is this function actually a thing?
    inline unsigned int GetID() const
    {
        return m_ID;
    }

    // TODO: Is this function actually a thing?
    inline unsigned char GetFlags() const
    {
        return m_flags;
    }

    // TODO: Is this function actually a thing?
    inline unsigned int GetAllowedMessageFlags() const
    {
        return m_allowedMessageFlags;
    }

    LWAPI(0x021a002c, TODO)
    void SetUpdateFlag(UpdatingPhase phase, bool isUpdating);

    LWAPI(0x021a0034, 0x0049a5c0)
    CActor();

    LWAPI(0x021a00c8, TODO)
    void RemoveFromAllParents();

    LWAPI(0x021a011c, 0x0049a520)
    virtual ~CActor();

    LWAPI(0x021a018c, TODO)
    void SetParent(CActor* parent);

    LWAPI(0x021a0194, TODO)
    void MessageSetup(unsigned int receiverID, Message& msg);

    LWAPI(0x021a01a4, TODO)
    void BroadcastMessageImm(unsigned int param_1, Message& msg);

    LWAPI(0x021a020c, TODO)
    void BroadcastMessage(unsigned int receiverID, Message& msg);

    LWAPI(0x021a0250, TODO)
    bool SendMessage(Message& msg);

    LWAPI(0x021a0280, TODO)
    void BroadcastMessage(Message& msg);

    LWAPI(0x021a02a8, TODO)
    void SendMessage(unsigned int receiverID, Message& msg);

    LWAPI(0x021a02e4, 0x0049a470)
    bool SendMessageImm(unsigned int receiverID, Message& msg);

    virtual bool ForEach(CActorTraverser& traverser) = 0;

    LWAPI(0x021a0440, TODO)
    bool GetUpdateFlag(UpdatingPhase phase) const;

    LWAPI(0x021a0448, 0x004a34e0)
    virtual bool PreProcessMessage(Message& msg);

    LWAPI(0x021a0450, 0x0049a330)
    virtual bool ProcessMessage(Message& msg);

    LWAPI(0x021a0460, 0x0085b2f0)
    virtual void Update(const SUpdateInfo& updateInfo);

    virtual bool ActorProc(int id, void* data) = 0;

    LWAPI(0x021a0464, TODO)
    void BeginProfile(int param_1);

    LWAPI(0x021a04a4, TODO)
    void EndProfile(int param_1);
};

LWAPI_STATIC_ASSERT_SIZE(CActor, 0x1c)
} // fnd
} // app
