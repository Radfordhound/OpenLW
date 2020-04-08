#include "MessageManager.h"

namespace app
{
namespace fnd
{
MessageManager::MessageManager()
{
    // TODO
}

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
    // TODO
}

unsigned int MessageManager::GenerateID()
{
    // TODO
    return 0;
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
    // TODO
}

static void* MessageManager_init()
{
    // TODO
    return nullptr;
}

static void MessageManager_destroy()
{
    // TODO
}

DEFINE_SINGLETON(MessageManager);
}
}
