#pragma once
#include "Utility/RefPtr.h"
#include "System/ReferencedObject.h"
#include "System/Component/TinyFsm.h"

namespace app
{
struct GameDocument;
class CGame;

namespace fnd
{
struct SUpdateInfo;
struct Message;
struct FileLoaderParam;
}

namespace GameModeUtil // TODO: Is this actually a class?
{
template<typename T>
struct Event : public TTinyFsmEvent<T, Event<T>>
{
    union
    {
        int m_integer;
        float m_float;
        fnd::Message* m_message;
        // TODO: m_object??
    };

    // TODO: Is this constructor actually a thing?
    inline Event(int signal) :
        TTinyFsmEvent<T, Event<T>>(signal) {}

    // TODO: Is this constructor actually a thing?
    inline Event(int signal, float deltaTime) :
        TTinyFsmEvent<T, Event<T>>(signal), m_float(deltaTime) {}

    // TODO: Is this constructor actually a thing?
    inline Event(int signal, fnd::Message& msg) :
        TTinyFsmEvent<T, Event<T>>(signal), m_message(&msg) {}

public:
    typedef Event<T> this_t;

    // TODO: Is this function actually a thing?
    inline int getInt() const
    {
        return m_integer;
    }

    // TODO: Is this function actually a thing?
    inline float getDeltaTime() const
    {
        return m_float;
    }

    // TODO: Is this function actually a thing?
    inline fnd::Message& getMessage() const
    {
        return *m_message;
    }

    // TODO: Is this function actually a thing?
    inline static this_t CreateSignal(int signal)
    {
        return this_t(signal);
    }

    // TODO: Is this function actually a thing?
    inline static this_t CreateSuper()
    {
        return CreateSignal(SIGNAL_SUPER);
    }

    // TODO: Is this function actually a thing?
    inline static this_t CreateInit()
    {
        return CreateSignal(SIGNAL_INIT);
    }

    // TODO: Is this function actually a thing?
    inline static this_t CreateEnter()
    {
        return CreateSignal(SIGNAL_ENTER);
    }

    // TODO: Is this function actually a thing?
    inline static this_t CreateLeave()
    {
        return CreateSignal(SIGNAL_LEAVE);
    }

    inline static this_t CreateUpdate(float deltaTime)
    {
        return this_t(SIGNAL_UPDATE, deltaTime);
    }

    inline static this_t CreateMessage(fnd::Message& msg)
    {
        return this_t(SIGNAL_MESSAGE, msg);
    }
};
}

struct GameMode : public fnd::ReferencedObject // size == 32
{
    // TODO: Also inherit from DisplaySwitchListener after inheriting from ReferencedObject!!!
    struct MyDisplaySwitchListener : public fnd::ReferencedObject
    {
        // TODO
    };

    CGame* Game;
    unsigned int field_0x10; // TODO: Get the type right.
    const char* Name;
    GameDocument* GameDoc;
    ut::RefPtr<MyDisplaySwitchListener> SwitchListener;

    LWAPI(0x021c9460, 0x004ac630)
    static void* operator new(std::size_t size);

    LWAPI(0x021c953c, 0x004ac770)
    GameMode();

    LWAPI(0x021c960c, 0x004acab0)
    ~GameMode();

    LWAPI(0x021c96c8, 0x004ac800)
    virtual void OnEnter(CGame& game);

    LWAPI(0x021c9718, 0x004ac820)
    virtual void OnLeave(CGame& game);

    LWAPI(0x021c989c, 0x004acc30)
    virtual void Update(CGame& game, const fnd::SUpdateInfo& updateInfo);

    LWAPI(0x021c98a4, 0x005dd780)
    virtual bool ProcessMessage(CGame& game, fnd::Message& msg);

    LWAPI(0x021c98b4, 0x005dd780)
    virtual bool PreProcessMessage(CGame& game, fnd::Message& msg);

    LWAPI(0x021c98f8, TODO)
    void AdvanceSequence();

    LWAPI(0x021c9a30, TODO)
    bool LoadFile(const char* filePath, const fnd::FileLoaderParam& loaderParams);

    LWAPI(0x021c9a88, TODO)
    bool PreLoadFile(const char* filePath, int param_2);

    LWAPI(0x021c9aac, TODO)
    bool IsLoadEnd();

    LWAPI(0x021c9e38, TODO)
    void InitializeGameMode(CGame& game);

    LWAPI(0x021c9f48, 0x004ac4f0)
    void ReleaseGameMode(CGame& game);

    LWAPI(0x021c9f64, 0x004ac7c0)
    void Destroy(CGame& game);
};
}
