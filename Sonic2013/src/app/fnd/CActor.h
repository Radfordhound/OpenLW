#pragma once
#include "SUpdateInfo.h"
#include "CActorTraverser.h"
#include "csl/ut/Bitset.h"
#include "boost/core/noncopyable.hpp"

namespace app
{
namespace fnd
{
struct Message;
struct MessageManager;

enum class UpdatingPhase
{
    Normal = 0
    // TODO
};

class CActor : public boost::noncopyable
{
    void* fx00 = nullptr;
    MessageManager* msgMgr = nullptr;
    CActor* parent = nullptr;
    csl::ut::Bitset<unsigned char> updateFlags;
    bool fx0D = false;
    bool fx0E = true;
    bool fx0F = true;
    int fx10 = -1;
    void* fx14 = nullptr;

public:
    /*
        @brief Destructor for CActor.
        <b>Wii U: TODO, PC: TODO</b>
    */
    virtual ~CActor();

    virtual bool ForEach(CActorTraverser& traverser) = 0;

    /* <b>Wii U: TODO, PC: TODO</b> */
    // TODO: Is return type correct?
    virtual unsigned int PreProcessMessage(Message& msg);

    /* <b>Wii U: TODO, PC: TODO</b> */
    // TODO: Is return type correct?
    virtual unsigned int ProcessMessage(Message& msg);

    /* <b>Wii U: TODO, PC: TODO</b> */
    virtual void Update(const SUpdateInfo& updateInfo);

    virtual bool ActorProc(int param_1, void* param_2) = 0;

    /*
        @brief Constructor for CActor.
        <b>Wii U: TODO, PC: TODO</b>
    */
    CActor();

    /* <b>Wii U: TODO, PC: TODO</b> */
    void BeginProfile(int param_1);

    /* <b>Wii U: TODO, PC: TODO</b> */
    void BroadcastMessage(unsigned int param_1, Message& msg);

    /* <b>Wii U: TODO, PC: TODO</b> */
    void BroadcastMessage(Message& msg);

    /* <b>Wii U: TODO, PC: TODO</b> */
    void BroadcastMessageImm(unsigned int param_1, Message& msg);

    /* <b>Wii U: TODO, PC: TODO</b> */
    void EndProfile(int param_1);

    /* <b>Wii U: TODO, PC: TODO</b> */
    bool GetUpdateFlag(UpdatingPhase phase) const;

    /* <b>Wii U: TODO, PC: TODO</b> */
    void MessageSetup(unsigned int param_1, Message& msg);

    /* <b>Wii U: TODO, PC: TODO</b> */
    void RemoveFromAllParents();

    /* <b>Wii U: TODO, PC: TODO</b> */
    bool SendMessage(Message& msg);

    /* <b>Wii U: TODO, PC: TODO</b> */
    void SendMessage(unsigned int param_1, Message& msg);

    /* <b>Wii U: TODO, PC: TODO</b> */
    bool SendMessageImm(unsigned int param_1, Message& msg);

    /* <b>Wii U: TODO, PC: TODO</b> */
    void SetParent(CActor* parent);

    /* <b>Wii U: TODO, PC: TODO</b> */
    void SetUpdateFlag(UpdatingPhase phase, bool isUpdating);
};
}
}
