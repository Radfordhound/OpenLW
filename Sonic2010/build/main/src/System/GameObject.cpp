#include "OpenLW/pch.h"
#include "GameObject.h"

namespace app
{
bool GameObject::ProcessMessage(fnd::Message& param_1)
{
    // TODO
    return false;
}

bool GameObject::ActorProc(int param_1, void* param_2)
{
    // TODO
    return false;
}

void GameObject::operator delete(void* ptr)
{
    // TODO
}

GameObject::~GameObject()
{
    // TODO
}

GameObject::GameObject() :
    m_name(nullptr) // TODO: Pass in dbg::GetMemoryAllocator() instead of nullptr!!!
{
    // TODO
}

fnd::GOComponent* GameObject::GetGOC(const char* id)
{
    // TODO
    return nullptr;
}

const fnd::GOComponent* GameObject::GetGOC(const char* id) const
{
    // TODO
    return nullptr;
}
} // app
