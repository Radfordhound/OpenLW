#pragma once
#include "SUpdateInfo.h"
#include "csl/ut/bitset.h"
#include <boost/core/noncopyable.hpp>

namespace app
{
namespace fnd
{
struct Message;
class MessageManager;
class CActorTraverser;

enum UpdatingPhase
{
    PHASE_NORMAL = 0,
    PHASE_UNK_ONE = 1,
    PHASE_UNK_TWO = 2
    // TODO
};

class CActor : public boost::noncopyable // size == 0x1c
{
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
    // Wii U: 0x021a011c, PC: TODO
    virtual ~CActor();

    virtual bool ForEach(CActorTraverser& traverser) = 0;

    // Wii U: 0x021a0448, PC: TODO
    virtual bool PreProcessMessage(Message& msg);

    // Wii U: 0x021a0450, PC: TODO
    virtual bool ProcessMessage(Message& msg);

    // Wii U: 0x021a0460, PC: TODO
    virtual void Update(const SUpdateInfo& updateInfo);

    virtual bool ActorProc(int param_1, void* param_2) = 0;

    // Wii U: 0x021a0464, PC: TODO
    void BeginProfile(int param_1);

    // Wii U: 0x021a020c, PC: TODO
    void BroadcastMessage(unsigned int receiverID, Message& msg);

    // Wii U: TODO, PC: TODO
    void BroadcastMessage(Message& msg);

    // Wii U: TODO, PC: TODO
    void BroadcastMessageImm(unsigned int param_1, Message& msg);

    // Wii U: TODO, PC: TODO
    void EndProfile(int param_1);

    // Wii U: TODO, PC: TODO
    bool GetUpdateFlag(UpdatingPhase phase) const;

    // Wii U: 0x021a0194, PC: TODO
    CActor* MessageSetup(unsigned int receiverID, Message& msg);

    // Wii U: TODO, PC: TODO
    void RemoveFromAllParents();

    // Wii U: 0x021a0250, PC: TODO
    bool SendMessage(Message& msg);

    // Wii U: 0x021a02a8, PC: TODO
    void SendMessage(unsigned int param_1, Message& msg);

    // Wii U: 0x021a02e4, PC: TODO
    bool SendMessageImm(unsigned int param_1, Message& msg);

    // Wii U: 0x021a018c, PC: TODO
    void SetParent(CActor* parent);

    // Wii U: 0x021a002c, PC: TODO
    void SetUpdateFlag(UpdatingPhase phase, bool isUpdating);

    // Wii U: 0x021a0034, PC: 0x0049a5c0
    CActor();
};
}
}
