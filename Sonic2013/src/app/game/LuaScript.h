#pragma once
#include "csl/ut/MoveArray.h"
#include <cstddef>

struct lua_State;

namespace csl
{
namespace fnd
{
struct IAllocator;
}
namespace math
{
struct Vector3;
}
namespace ut
{
struct Color8;
}
}

namespace app
{
namespace game
{
class LuaScript
{
    lua_State* state;
    bool is_gc_paused; // TODO: Is this correct?
    int uk2Count; // TODO: Is this correct?
    int top; // TODO: Is this correct?

    /* <b>Wii U: TODO, PC: TODO</b> */
    int get_field(const char* name);

    /* <b>Wii U: TODO, PC: TODO</b> */
    int get_table(const char* name);

    /* <b>Wii U: TODO, PC: TODO</b> */
    void run_gc();

    /* <b>Wii U: TODO, PC: TODO</b> */
    void stop_gc();

public:
    csl::fnd::IAllocator* Allocator;

    /*
        @brief Constructor for LuaScript.
        <b>Wii U: TODO, PC: 0x004decc0</b>
    */
    LuaScript(csl::fnd::IAllocator* alloc = nullptr);

    /*
        @brief Destructor for LuaScript.
        <b>Wii U: TODO, PC: TODO</b>
    */
    ~LuaScript();

    /* <b>Wii U: TODO, PC: TODO</b> */
    void CloseNode();

    /* <b>Wii U: TODO, PC: TODO</b> */
    int ConvertString(char* dst, int param_2);

    /* <b>Wii U: TODO, PC: TODO</b> */
    int ForEach(const char* name, void (*callback)(char const*,
        app::game::LuaScript&, void*), void* param_3);

    /* <b>Wii U: TODO, PC: TODO</b> */
    int ForEach(void (*callback)(char const*,
        app::game::LuaScript&, void*), void* param_2);

    /* <b>Wii U: TODO, PC: TODO</b> */
    int GetBool(const char* name, bool& v);

    /* <b>Wii U: TODO, PC: TODO</b> */
    int GetBool(bool& v);

    /* <b>Wii U: TODO, PC: TODO</b> */
    int GetColor(const char* name, csl::ut::Color8& v);

    /* <b>Wii U: TODO, PC: TODO</b> */
    int GetFloat(const char* name, float& v);

    /* <b>Wii U: TODO, PC: TODO</b> */
    int GetFloatArray(const char* name, csl::ut::MoveArray<float>& v);

    /* <b>Wii U: TODO, PC: TODO</b> */
    int GetInt(const char* name, int& v);

    /* <b>Wii U: TODO, PC: TODO</b> */
    int GetIntArray(const char* name, csl::ut::MoveArray<int>& v);

    /* <b>Wii U: TODO, PC: TODO</b> */
    int GetString(const char* name, const char*& v);

    /* <b>Wii U: TODO, PC: TODO</b> */
    int GetString(const char*& v);

    /* <b>Wii U: TODO, PC: TODO</b> */
    int GetString(const char* name, csl::ut::MoveArray<const char*>& v);

    /* <b>Wii U: TODO, PC: TODO</b> */
    int GetVector3(const char* name, csl::math::Vector3& v);

    /* <b>Wii U: TODO, PC: TODO</b> */
    int Load(const char* buf, std::size_t size);

    /* <b>Wii U: TODO, PC: TODO</b> */
    int LoadFromHost(const char* filePath);

    /* <b>Wii U: TODO, PC: TODO</b> */
    int OpenNode(const char* name);

    /* <b>Wii U: TODO, PC: TODO</b> */
    void SetTop();
};
}
}
