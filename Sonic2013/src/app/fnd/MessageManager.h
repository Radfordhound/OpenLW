#pragma once
#include "csl/fnd/Singleton.h"
#include "ReferencedObject.h"

namespace app
{
namespace fnd
{
struct Message;
class CActor;

class MessageManager : public ReferencedObject, public csl::fnd::Singleton<MessageManager>
{
    // TODO: Data Members

    /*
        @brief Constructor for MessageManager.
        <b>Wii U: TODO, PC: TODO</b>
    */
    MessageManager();

public:
    /*
        @brief Destructor for MessageManager.
        <b>Wii U: TODO, PC: TODO</b>
    */
    ~MessageManager() override;

    /* <b>Wii U: TODO, PC: TODO</b> */
    bool Add(CActor* actor);

    /* <b>Wii U: TODO, PC: TODO</b> */
    void AddMessage(const Message& msg);

    /* <b>Wii U: TODO, PC: TODO</b> */
    unsigned int GenerateID();

    /* <b>Wii U: TODO, PC: TODO</b> */
    CActor* GetActor(unsigned int id) const;

    /* <b>Wii U: TODO, PC: TODO</b> */
    bool Remove(CActor* actor);

    /* <b>Wii U: TODO, PC: TODO</b> */
    void Update();
};
}
}
