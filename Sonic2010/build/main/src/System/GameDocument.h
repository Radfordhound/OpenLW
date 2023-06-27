#pragma once
#include "WorldHH.h"
#include "ReferencedObject.h"
#include "UpdateInfo.h"
#include <csl/ut/noncopyable.h>
#include <boost/scoped_ptr.hpp>

// Avoid name collisions on Windows.
#ifdef CreateService
#undef CreateService
#endif

namespace app
{
struct GameMode;
class GameObject;

namespace fnd
{
class GameServiceClass;
class GameService;
struct SUpdateInfo;
class GameDocumentListener;
} // fnd

class GameDocument : public fnd::ReferencedObject, // size == 0xDC
    public csl::ut::NonCopyable
{
public:
    GameMode* gameModePtr;
    unsigned int gameModeID;
    boost::scoped_ptr<CWorld> world;
    // TODO: Other data members.

    template<typename T>
    T* GetService()
    {
        return static_cast<T*>(GetServiceByClass(T::staticClass()));
    }

    LWAPI(0x02a7daf4, TODO)
    void InitShutdownPendingObjects();

    LWAPI(0x02a7dc48, TODO)
    void RemoveGameObject(GameObject* param_1);

    LWAPI(0x02a7dcb4, TODO)
    void FinishShutdownPendingObjects();

    LWAPI(0x02a7dd38, TODO)
    void ShutdownPendingObjects();

    LWAPI(0x02a7de10, TODO)
    void ClearAllGameObjects();

    LWAPI(0x02a7ded8, TODO)
    void ClearServices();

    LWAPI(0x02a7e158, 0x0090bc60)
    ~GameDocument();

    LWAPI(0x02a7e288, TODO)
    void GetServiceByName(const char* param_1) const;

    LWAPI(0x02a7e340, 0x0090B2E0)
    fnd::GameService* GetServiceByClass(const fnd::GameServiceClass& param_1) const;

    LWAPI(0x02a7e530, TODO)
    void AddService(fnd::GameService* param_1);

    LWAPI(0x02a7e618, TODO)
    void CreateService(const fnd::GameServiceClass& param_1, csl::fnd::IAllocator* param_2);

    LWAPI(0x02a7e674, TODO)
    void GetGroupActor(int param_1);

    LWAPI(0x02a7e6a8, TODO)
    void GetGroupActorID(unsigned int param_1) const;

    LWAPI(0x02a7e6d4, TODO)
    void SetLayerName(int param_1, const char* param_2);

    LWAPI(0x02a7e708, TODO)
    void AddGameObject(GameObject* param_1);

    LWAPI(0x02a7e7b0, TODO)
    void UpdateGlobalTime(const fnd::SUpdateInfo& param_1);

    LWAPI(0x02a7e7c4, TODO)
    void UpdateObjects(int param_1, fnd::UpdatingPhase param_2, const fnd::SUpdateInfo& param_3);

    LWAPI(0x02a7e968, TODO)
    void AddGameDocumentListener(fnd::GameDocumentListener* param_1);

    LWAPI(0x02a7ea04, TODO)
    void RemoveGameDocumentListener(fnd::GameDocumentListener* param_1);

    LWAPI(0x02a7ec20, TODO)
    GameDocument(GameMode* param_1);
};
} // app
