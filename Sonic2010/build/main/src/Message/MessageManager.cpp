#include "MessageManager.h"
#include "Message.h"
#include "System/Actor.h"

namespace app
{
namespace fnd
{
MessageManager::~MessageManager()
{
    // TODO
}

bool MessageManager::Add(CActor* actor)
{
    // TODO
    return false;
}

void MessageManager::AddMessage(const Message& msg)
{
    if (m_msgQueue.size() < m_msgQueue.capacity())
    {
        Message* newMsg = msg.Clone();
        if (newMsg)
        {
            m_msgQueue.push_back_unchecked(newMsg);
        }
    }
}

unsigned int MessageManager::GenerateID()
{
    return m_curID++;
}

CActor* MessageManager::GetActor(unsigned int id) const
{
    // TODO
    return nullptr;
}

bool MessageManager::Remove(CActor* actor)
{
    // TODO
    return false;
}

void MessageManager::Update()
{
    if (!m_msgQueue.empty())
    {
        m_executingMessages.swap(m_msgQueue);
        for (auto it = m_executingMessages.begin(); it != m_executingMessages.end(); ++it)
        {
            Message* msg = *it;
            CActor* receiver = GetActor(msg->Receiver);

            if (receiver)
            {
                receiver->ActorProc(msg->Broadcasted, msg);
            }
            
            delete msg;
        }
        
        m_executingMessages.clear();
    }
}

MessageManager::MessageManager() :
    m_curID(1),
    // TODO
    m_msgQueue(m_allocator),
    m_executingMessages(m_allocator)
    // TODO
{
    // TODO
    m_msgQueue.reserve(512);
    m_executingMessages.reserve(512);
}

// Wii U: 0x021a18b8, PC: TODO
static void* MessageManager_init()
{
    MessageManager* msgMgr = new (GetSingletonAllocator()) MessageManager();
    msgMgr->AddRef();
    return msgMgr;
}

// Wii U: 0x021a1908, PC: TODO
static void MessageManager_destroy(void* ptr)
{
    static_cast<MessageManager*>(ptr)->Release();
}

DEFINE_SINGLETON(MessageManager, MessageManager_init, MessageManager_destroy);
}
}
