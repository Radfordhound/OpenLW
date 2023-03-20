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
LWAPI_PRIVATE
    DECLARE_SINGLETON

    unsigned int m_curID;
    // TODO: Data Members
    csl::ut::MoveArray<fnd::Message*> m_msgQueue;
    csl::ut::MoveArray<fnd::Message*> m_executingMessages;
    // TODO: Data Members

public:
    LWAPI(0x021a1218, TODO)
    ~MessageManager();

    LWAPI(0x021a13c4, 0x0049a8e0)
    bool Add(CActor* actor);

    LWAPI(0x021a16d0, TODO)
    void AddMessage(const Message& msg);

    LWAPI(0x021a1350, TODO)
    unsigned int GenerateID();

    LWAPI(0x021a15d4, 0x0049a950)
    CActor* GetActor(unsigned int id) const;

    LWAPI(0x021a149c, TODO)
    bool Remove(CActor* actor);

    LWAPI(0x021a17e8, TODO)
    void Update();

    LWAPI(0x021a0f24, 0x0049a6c0)
    MessageManager();
};

/**
 * @brief Initializes the MessageManager Singleton.
 *
 * NOTE: This function appears to be static, but it's been exposed in
 * this header anyway for LWAPI/modding purposes.
*/
LWAPI(0x021a18b8, TODO)
void* MessageManager_init();

/**
 * @brief Destroys the MessageManager Singleton.
 *
 * NOTE: This function appears to be static, but it's been exposed in
 * this header anyway for LWAPI/modding purposes.
 *
 * @param[in] ptr The pointer to the Singleton.
*/
LWAPI(0x021a1908, TODO)
void MessageManager_destroy(void* ptr);
}
}
