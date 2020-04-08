#include "LuaScript.h"
#include "csl/math/Math.h"
#include "lua/lua.hpp"
#include <cstring>

namespace app
{
namespace game
{
namespace detail
{
/* <b>Wii U: 0x022548d8, PC: [Inlined into my_alloc]</b> */
void my_free(csl::fnd::IAllocator* allocator, void* ptr)
{
    allocator->Free(ptr);
}

/* <b>Wii U: 0x02254910, PC: [Inlined into my_alloc]</b> */
void* my_realloc(csl::fnd::IAllocator* allocator, void* ptr,
    std::size_t osize, std::size_t nsize)
{
    // Allocate requested memory
    void* buf = nullptr;
    if (nsize)
    {
        buf = allocator->Alloc(nsize, 0x10);
    }

    // If reallocating, copy data from existing buffer into new buffer and free old buffer
    if (ptr)
    {
        if (buf)
        {
            std::memcpy(buf, ptr, csl::math::Min(osize, nsize));
        }
        
        allocator->Free(ptr);
    }

    return buf;
}

/* <b>Wii U: 0x022549c4, PC: 0x004dec40</b> */
void* my_alloc(void* ud, void* ptr, std::size_t osize, std::size_t nsize)
{
    csl::fnd::IAllocator* allocator = static_cast<LuaScript*>(ud)->Allocator;
    if (!nsize)
    {
        my_free(allocator, ptr);
        return nullptr;
    }

    return my_realloc(allocator, ptr, osize, nsize);
}
}

int LuaScript::get_field(const char* name)
{
    return lua_getfield(state, (!uk2Count) ? -0x2712 : -1, name);
}

int LuaScript::get_table(const char* name)
{
    get_field(name);
    if (lua_type(state, -1) != LUA_TTABLE)
    {
        lua_settop(state, -2);
        return 0;
    }

    return 1;
}

void LuaScript::run_gc()
{
    if (is_gc_paused)
    {
        lua_gc(state, 1, 0);
        is_gc_paused = false;
    }
}

void LuaScript::stop_gc()
{
    if (!is_gc_paused)
    {
        lua_gc(state, 0, 0);
        is_gc_paused = true;
    }
}

LuaScript::LuaScript(csl::fnd::IAllocator* alloc) : Allocator(alloc),
    uk2Count(0), is_gc_paused(false), top(0)
{
    if (!alloc)
    {
        // TODO: Use allocator properly
        //alloc = GetAllocator(2);
    }
        
    state = lua_newstate(detail::my_alloc, this);
}

LuaScript::~LuaScript()
{
    if (state) lua_close(state);
}

void LuaScript::CloseNode()
{
    --uk2Count;
    lua_settop(state, -2);
}

int LuaScript::ConvertString(char* dst, int param_2)
{
    // TODO
    return 0;
}

int LuaScript::ForEach(const char* name, void (*callback)(char const*,
    app::game::LuaScript&, void*), void* param_3)
{
    int index = get_table(name);
    if (index)
    {
        stop_gc();

        ++uk2Count;
        index = lua_gettop(state);
        lua_pushnil(state);

        while (lua_next(state, index))
        {
            const char* pcVar2 = (lua_type(state, -2) == LUA_TSTRING) ?
                lua_tolstring(state, -2, nullptr) : nullptr;

            callback(pcVar2, *this, param_3);
            lua_settop(state, -2);
        }

        --uk2Count;
        lua_settop(state, -2);
        return 1;
    }

    return 0;
}

int LuaScript::ForEach(void (*callback)(char const*,
    app::game::LuaScript&, void*), void* param_2)
{
    ++uk2Count;
    int index = lua_gettop(state);
    lua_pushnil(state);

    while (lua_next(state, index))
    {
        const char* pcVar2 = (lua_type(state, -2) == LUA_TSTRING) ?
            lua_tolstring(state, -2, nullptr) : nullptr;

        callback(pcVar2, *this, param_2);
        lua_settop(state, -2);
    }

    --uk2Count;
    return 1;
}

int LuaScript::GetBool(const char* name, bool& v)
{
    run_gc();
    get_field(name);

    int type = lua_type(state, -1);
    if (type == LUA_TBOOLEAN)
    {
        v = lua_toboolean(state, -1);
    }

    lua_settop(state, -2);
    return (type == LUA_TBOOLEAN);
}

int LuaScript::GetBool(bool& v)
{
    int type = lua_type(state, -1);
    if (type == LUA_TBOOLEAN)
    {
        v = lua_toboolean(state, -1);
    }

    return (type == LUA_TBOOLEAN);
}

int LuaScript::GetColor(const char* name, csl::ut::Color8& v)
{
    // TODO
    return 0;
}

int LuaScript::GetFloat(const char* name, float& v)
{
    // TODO
    return 0;
}

int LuaScript::GetFloatArray(const char* name, csl::ut::MoveArray<float>& v)
{
    // TODO
    return 0;
}

int LuaScript::GetInt(const char* name, int& v)
{
    // TODO
    return 0;
}

int LuaScript::GetIntArray(const char* name, csl::ut::MoveArray<int>& v)
{
    // TODO
    return 0;
}

int LuaScript::GetString(const char* name, const char*& v)
{
    // TODO
    return 0;
}

int LuaScript::GetString(const char*& v)
{
    // TODO
    return 0;
}

int LuaScript::GetString(const char* name, csl::ut::MoveArray<const char*>& v)
{
    // TODO
    return 0;
}

int LuaScript::GetVector3(const char* name, csl::math::Vector3& v)
{
    // TODO
    return 0;
}

int LuaScript::Load(const char* buf, std::size_t size)
{
    if (state && !luaL_loadbuffer(state, buf, size, nullptr))
    {
        int r = lua_pcall(state, 0, 0, 0);
        top = lua_gettop(state);
        return !r;
    }

    return 0;
}

int LuaScript::LoadFromHost(const char* filePath)
{
    // TODO
    return 0;
}

int LuaScript::OpenNode(const char* name)
{
    get_field(name);
    if (lua_type(state, -1) != LUA_TTABLE)
    {
        lua_settop(state, -2);
        return 0;
    }

    ++uk2Count;
    return 1;
}

void LuaScript::SetTop()
{
    uk2Count = 0;
    lua_settop(state, top);
}
}
}
