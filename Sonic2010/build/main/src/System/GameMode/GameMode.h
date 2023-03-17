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

    // Wii U: 0x021c9460, PC: 0x004ac630
    static void* operator new(std::size_t size);

    // Wii U: 0x021c953c, PC: 0x004ac770
    GameMode();

    // Wii U: 0x021c960c, PC: 0x004acab0
    ~GameMode();

    // Wii U: 0x021c96c8, PC: 0x004ac800
    virtual void OnEnter(CGame& game);

    // Wii U: 0x021c9718, PC: 0x004ac820
    virtual void OnLeave(CGame& game);

    // Wii U: 0x021c989c, PC: 0x004acc30
    virtual void Update(CGame& game, const fnd::SUpdateInfo& updateInfo);

    // Wii U: 0x021c98a4, PC: GENERIC RETURN FALSE
    virtual bool ProcessMessage(CGame& game, fnd::Message& msg);

    // Wii U: 0x021c98b4, PC: GENERIC RETURN FALSE
    virtual bool PreProcessMessage(CGame& game, fnd::Message& msg);

    // Wii U: 0x021c98f8, PC: TODO
    void AdvanceSequence();

    // Wii U: 0x021c9a30, PC: TODO
    bool LoadFile(const char* filePath, const fnd::FileLoaderParam& loaderParams);

    // Wii U: 0x021c9a88, PC: TODO
    bool PreLoadFile(const char* filePath, int param_2);

    // Wii U: 0x021c9aac, PC: TODO
    bool IsLoadEnd();

    // Wii U: 0x021c9e38, PC: TODO
    void InitializeGameMode(CGame& game);

    // Wii U: 0x021c9f48, PC: 0x004ac4f0
    void ReleaseGameMode(CGame& game);

    // Wii U: 0x021c9f64, PC: 0x004ac7c0
    void Destroy(CGame& game);
};
}
