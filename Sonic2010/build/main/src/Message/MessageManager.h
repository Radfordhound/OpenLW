#pragma once
#include "System/ReferencedObject.h"
#include "System/Singleton.h"
#include <csl/ut/array.h>

namespace app
{
namespace fnd
{
struct Message;
class CActor;

class MessageManager : public ReferencedObject, public csl::fnd::Singleton<MessageManager> // size == 0x4c
{
    DECLARE_SINGLETON

    unsigned int m_curID;
    // TODO: Data Members
    csl::ut::MoveArray<fnd::Message*> m_msgQueue;
    csl::ut::MoveArray<fnd::Message*> m_executingMessages;
    // TODO: Data Members

public:
    // Wii U: 0x021a1218, PC: TODO
    ~MessageManager();

    // Wii U: 0x021a13c4, PC: 0x0049a8e0
    bool Add(CActor* actor);

    // Wii U: 0x021a16d0, PC: TODO
    void AddMessage(const Message& msg);

    // Wii U: 0x021a1350, PC: TODO
    unsigned int GenerateID();

    // Wii U: 0x021a15d4, PC: 0x0049a950
    CActor* GetActor(unsigned int id) const;

    // Wii U: 0x021a149c, PC: TODO
    bool Remove(CActor* actor);

    // Wii U: 0x021a17e8, PC: TODO
    void Update();

    // Wii U: 0x021a0f24, PC: 0x0049a6c0
    MessageManager();
};
}
}
