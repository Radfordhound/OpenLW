// NOTE: Initial file was auto-generated by SymbolsDB.
#pragma once
#include "LeafActor.h"
#include "Property.h"
#include "Component/GOComponent.h"
#include <Hedgehog/Base/System/hhObject.h>
#include <csl/ut/array.h>
#include <csl/ut/linklist.h>
#include <csl/ut/variablestring.h>

namespace app
{
class GameDocument;
class GameObject;

namespace xgame
{
class MsgKill;
} // xgame

struct GameObjectTableEntry
{
    std::size_t field_0x0;
    GameObject* field_0x4;
};

class GameObject : public hh::base::CRefCountObject, public fnd::CLeafActor
{
OPENLW_PRIVATE
    csl::ut::Bitset<unsigned char> m_statusFlags;
    unsigned char m_category;
    GameDocument* m_owner;
    std::size_t field_0x24;
    GameObjectTableEntry m_objTableEntry;
    csl::ut::InplaceMoveArray<fnd::GOComponent*, 8> m_components;
    csl::ut::VariableString* m_name;
    csl::fnd::IAllocator* m_objAllocator;
    csl::ut::InplaceMoveArray<fnd::Property, 2> m_properties;
    unsigned int m_componentFlags;
    csl::ut::LinkList<fnd::GOComponent> m_visualComponents;
    csl::ut::LinkList<fnd::GOComponent> m_physicsComponents;
    csl::ut::LinkList<fnd::GOComponent> m_audibleComponents;

public:
    template<typename T>
    inline T* GetGOC()
    {
        return static_cast<T*>(GetGOC(T::FamilyID));
    }

    template<typename T>
    inline const T* GetGOC() const
    {
        return static_cast<const T*>(GetGOC(T::FamilyID));
    }

    LWAPI(0x02001604, TODO)
    bool ProcessMessage(fnd::Message& param_1);

    LWAPI(0x020017A4, TODO)
    bool ActorProc(int param_1, void* param_2);

    LWAPI(0x020017AC, TODO)
    void AddCallback(GameDocument* param_1);

    LWAPI(0x020017B0, TODO)
    void RemoveCallback(GameDocument* param_1);

    LWAPI(0x020017B4, TODO)
    void UpdatePhase(const fnd::SUpdateInfo& param_1, fnd::UpdatingPhase param_2);

    template<typename T>
    inline T* GetService()
    {
        return static_cast<T*>(GetServiceByClass(T::staticClass()));
    }

    LWAPI(0x02195BE0, TODO)
    void GetProperty(unsigned int param_1) const;

    LWAPI(0x021A4D4C, TODO)
    static void operator delete(void* ptr);

    LWAPI(0x021A4E94, TODO)
    ~GameObject();

    LWAPI(0x021A4EAC, TODO)
    void IsKilled() const;

    LWAPI(0x021A4ED0, TODO)
    void Kill();

    LWAPI(0x021A4F0C, TODO)
    void ProcMsgKill(xgame::MsgKill& param_1);

    LWAPI(0x021A50E0, TODO)
    static void UpdateComponents(const csl::ut::LinkList<fnd::GOComponent>& param_1, fnd::UpdatingPhase param_2, fnd::SUpdateInfo& param_3);

    LWAPI(0x021A51D4, TODO)
    void UpdateSetEditor(const fnd::SUpdateInfo& param_1);

    LWAPI(0x021A527C, TODO)
    void SetObjectEdited();

    LWAPI(0x021A5318, TODO)
    void PositionUpdatedFromSetEditor();

    LWAPI(0x021A53B4, TODO)
    void NotifyOnStartSetEditor();

    LWAPI(0x021A57C8, TODO)
    static void* operator new(std::size_t size);

    LWAPI(0x021A5804, TODO)
    static void* operator new(const std::size_t size, CHedgehogMemoryAllocatorFileLine& param_2, CHedgehogMemoryAllocatorHeap param_3);

    LWAPI(0x021A58DC, TODO)
    void GetAllocator() const;

    LWAPI(0x021A59B4, TODO)
    GameObject();

    LWAPI(0x021A5AAC, TODO)
    void GetServiceByClass(const fnd::GameServiceClass& param_1);

    LWAPI(0x021A5D48, TODO)
    void AddComponent(fnd::GOComponent* param_1);

    LWAPI(0x021A5EC0, TODO)
    void RemoveComponent(fnd::GOComponent* param_1);

    LWAPI(0x021A5FE8, TODO)
    void Sleep();

    LWAPI(0x021A600C, TODO)
    void Resume();

    LWAPI(0x021A6174, TODO)
    void AddProperty(unsigned int param_1, fnd::PropertyValue param_2);

    LWAPI(0x021A6238, TODO)
    void RemoveProperty(unsigned int param_1);

    LWAPI(0x021A62C8, TODO)
    void SetProperty(unsigned int param_1, fnd::PropertyValue param_2);

    LWAPI(0x021A6354, TODO)
    void PassMessageImm(unsigned int param_1, fnd::Message& param_2);

    LWAPI(0x021A636C, TODO)
    void SendMessageToGame(fnd::Message& param_1);

    LWAPI(0x021A6380, TODO)
    void SendMessageImmToGame(fnd::Message& param_1);

    LWAPI(0x021A6394, TODO)
    void BroadcastMessageImmToGroup(unsigned int param_1, fnd::Message& param_2);

    LWAPI(0x021A63E4, TODO)
    void SendMessageImmToGameObject(GameObject* param_1, fnd::Message& param_2);

    LWAPI(0x021A63F8, TODO)
    void SetObjectCategory(int param_1);

    LWAPI(0x021A6404, 0x0049D430)
    fnd::GOComponent* GetGOC(const char* id);

    LWAPI(0x021A64F8, 0x0049D430)
    const fnd::GOComponent* GetGOC(const char* id) const;

    LWAPI(0x021A65A8, TODO)
    void SetupUpdateFlags();

    LWAPI(0x021A66D8, TODO)
    void NotifyDestroy();

    LWAPI(0x02360A74, TODO)
    bool HasProperty(unsigned int param_1) const;
};
} // app
