// TODO: The name of this file is correct, but the path was guessed!
// NOTE: Initial file was auto-generated by SymbolsDB.
#pragma once
#include "System/Handle.h"
#include "System/UpdateInfo.h"
#include <csl/ut/bitset.h>
#include <csl/ut/linklist.h>

namespace app
{
class GameObject;

namespace game
{
class GOCGravity;
} // game

namespace fnd
{
struct SUpdateInfo;
class GOComponentClass;
class Message;
class GameServiceClass;

class GOComponent : public RefByHandleObject
{
OPENLW_PRIVATE
    GameObject* m_activeObject;
    unsigned short m_unknown1;
    csl::ut::Bitset<char> m_flags;
    char m_componentType; // TODO: Is this an enum?
    unsigned int m_unknown2;
    csl::ut::LinkListNode m_visualComponentNode;
    csl::ut::LinkListNode m_physicsComponentNode;
    csl::ut::LinkListNode m_audibleComponentNode;

public:
    virtual const char* GetFamilyID() const = 0;

    LWAPI(0x02193fbc, TODO)
    virtual void Update(const UpdatingPhase param_1, SUpdateInfo& param_2);

    LWAPI(0x021a78e0, TODO)
    ~GOComponent();

    LWAPI(0x021a7964, TODO)
    void SetGameObject(GameObject* param_1);

    LWAPI(0x021a7970, TODO)
    static void Create(const GameObject* param_1, GOComponentClass& param_2);

    LWAPI(0x021a79c8, TODO)
    static void CreateSingle(const GameObject* param_1, GOComponentClass& param_2);

    LWAPI(0x021a7a48, TODO)
    static void BeginSetup(GameObject* param_1);

    LWAPI(0x021a7ae4, TODO)
    static void EndSetup(GameObject* param_1);

    LWAPI(0x021a7b80, TODO)
    void OpenDebugWindow();

    LWAPI(0x021a7ba8, TODO)
    virtual void OnGOCEvent(int param_1, GameObject& param_2, void* param_3);

    LWAPI(0x021a7bac, TODO)
    virtual bool ProcessMessage(Message& param_1);

    LWAPI(0x021a7bf4, TODO)
    GOComponent();

    LWAPI(0x021a7c88, TODO)
    void SendMessage(unsigned int param_1, Message& param_2);

    LWAPI(0x021a7c94, TODO)
    void SendMessageImm(unsigned int param_1, Message& param_2);

    LWAPI(0x021a7ca0, TODO)
    void GetServiceByClass(const GameServiceClass& param_1);

    LWAPI(0x021a7ca8, TODO)
    GOComponent* GetComponentByID(const char* id);

    LWAPI(0x021a7cb0, TODO)
    const GOComponent* GetComponentByID(const char* id) const;

    template<typename T>
    T* GetGOC()
    {
        return GetComponentByID(T::FamilyID);
    }

    template<typename T>
    const T* GetGOC() const
    {
        return GetComponentByID(T::FamilyID);
    }

    template<typename T>
    T* GetService()
    {
        return GetServiceByClass(T::staticClass());
    }
};
} // fnd
} // app
