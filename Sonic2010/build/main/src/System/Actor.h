// TODO: The name of this file is correct, but the path was guessed!
#pragma once
#include "UpdateInfo.h"
#include <csl/ut/bitset.h>
#include <boost/noncopyable.hpp>

#ifdef SendMessage
#undef SendMessage
#endif

namespace app
{
namespace fnd
{
struct Message;
class MessageManager;
class CActorTraverser;

enum UpdatingPhase
{
    PHASE_ONE = 0,
    PHASE_TWO = 1,
    PHASE_THREE = 2,
    PHASE_COUNT
};

class CActor : public boost::noncopyable // size == 0x1c
{
LWAPI_PROTECTED
    unsigned int m_ID;
    MessageManager* m_msgMgr;
    CActor* m_parent;
    csl::ut::Bitset<unsigned char> m_updateFlags;
    bool field_0xd;
    bool field_0xe;
    bool field_0xf;
    int field_0x10; // TODO: Is this type correct?
    void* field_0x14; // TODO: Is this type correct?

public:
    // TODO: Is this function actually a thing?
    inline unsigned int GetID() const
    {
        return m_ID;
    }

    // TODO: Is this function actually a thing?
    inline bool GetField0xE() const
    {
        return field_0xe;
    }

    // TODO: Is this function actually a thing?
    inline int GetField0x10() const
    {
        return field_0x10;
    }

    LWAPI(0x021a002c, TODO)
    void SetUpdateFlag(UpdatingPhase phase, bool isUpdating);

    LWAPI(0x021a0034, 0x0049a5c0)
    CActor();

    LWAPI(0x021a00c8, TODO)
    void RemoveFromAllParents();

    LWAPI(0x021a011c, TODO)
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

    LWAPI(0x021a02e4, TODO)
    bool SendMessageImm(unsigned int receiverID, Message& msg);

    virtual bool ForEach(CActorTraverser& traverser) = 0;

    LWAPI(0x021a0440, TODO)
    bool GetUpdateFlag(UpdatingPhase phase) const;

    LWAPI(0x021a0448, TODO)
    virtual bool PreProcessMessage(Message& msg);

    LWAPI(0x021a0450, TODO)
    virtual bool ProcessMessage(Message& msg);

    LWAPI(0x021a0460, TODO)
    virtual void Update(const SUpdateInfo& updateInfo);

    virtual bool ActorProc(int param_1, void* param_2) = 0;

    LWAPI(0x021a0464, TODO)
    void BeginProfile(int param_1);

    LWAPI(0x021a04a4, TODO)
    void EndProfile(int param_1);
};
}
}
