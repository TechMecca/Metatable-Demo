#pragma once
#include "LuaDefine.h"
#include "Lua.h"
#include <WinUser.h>

lua_State* GetLuaState() {
    return reinterpret_cast<lua_State * (*)()>(0x00817DB0)();
}

char* lua_tostring(lua_State* state, int n_param) {
    return reinterpret_cast<char* (__cdecl*)(lua_State*, int, int)>(0x0084E0E0)(state, n_param, 0);
}

int lua_pushnil(lua_State* state) {
    return reinterpret_cast<int(__cdecl*)(lua_State*)>(0x0084E280)(state);
}

void lua_pushcclosure(lua_State* L, lua_CFunction fn, int n)
{
    reinterpret_cast<void(__cdecl*)(lua_State*, lua_CFunction, int)>(0x0084E400)(L, fn, n);
}

void lua_setfield(lua_State* L, int idx, const char* key) {
    return ((decltype(&lua_setfield))0x0084E900)(L, idx, key);
}

void lua_pushstring(lua_State* L, const char* val) {
    reinterpret_cast<int(__cdecl*)(lua_State*, const char*)>(0x0084E350)(L, val);
}

double lua_tonumber(lua_State* L, int idx) {
    return reinterpret_cast<double(__cdecl*)(lua_State*, int)>(0x0084E030)(L, idx);
}

void lua_pushboolean(lua_State* L, bool val) {
    reinterpret_cast<void(__cdecl*)(lua_State*, bool)>(0x0084E4D0)(L, val);
}

void lua_pushnumber(lua_State* L, double val) {
    reinterpret_cast<void(__cdecl*)(lua_State*, double)>(0x0084E2A0)(L, val);
}

void lua_pushinteger(lua_State* L, int val) {
    reinterpret_cast<void(__cdecl*)(lua_State*, int)>(0x0084E2D0)(L, val);
}

int lua_isstring(lua_State* L, int idx) {
    return reinterpret_cast<int(__cdecl*)(lua_State*, int)>(0x0084DF60)(L, idx);
}

int lua_tointeger(lua_State* L, int idx) {
    return reinterpret_cast<int(__cdecl*)(lua_State*, int)>(0x0084E070)(L, idx);
}

void lua_createtable(lua_State* L, int narray, int nrec) {
    reinterpret_cast<void(__cdecl*)(lua_State*, int, int)>(0x0084E6E0)(L, narray, nrec);
}

void lua_pushlightuserdata(lua_State* L, void* p) {
    reinterpret_cast<void(__cdecl*)(lua_State*, void*)>(0x0084E500)(L, p);
}

int lua_ref(lua_State* L, int t) {
    return reinterpret_cast<int(__cdecl*)(lua_State*, int)>(0x0084F6C0)(L, t);
}

void luaL_unref(lua_State* L, int t, int ref) {
    reinterpret_cast<void(__cdecl*)(lua_State*, int, int)>(0x0084F7A0)(L, t, ref);
}

int lua_settable(lua_State* L, int number) {
    return reinterpret_cast<int(__cdecl*)(lua_State*, int)>(0x0084E8D0)(L, number);
}

int lua_gettop(lua_State* L) {
    return reinterpret_cast<int(__cdecl*)(lua_State*)>(0x0084DBD0)(L);
}

void* lua_newuserdata(lua_State* L, size_t size) {
    return reinterpret_cast<void* (__cdecl*)(lua_State*, size_t)>(0x0084F0F0)(L, size);
}

int lua_getfield(lua_State* L, int a1, const char* a2) {
    return ((int(__cdecl*)(lua_State*, int, const char*))0x0084E590)(L, a1, a2);
}

void lua_settop(lua_State* L, int a1) {
    reinterpret_cast<void(__cdecl*)(lua_State*, int)>(0x0084DBF0)(L, a1);
}

void lua_pushvalue(lua_State* L, int a1) {
    ((void(__cdecl*)(lua_State*, int))0x84DE50)(L, a1);
}

int lua_touserdata(lua_State* L, int a1) {
    return reinterpret_cast<int(__cdecl*)(lua_State*, int)>(0x0084E210)(L, a1);
}

int lua_setmetatable(lua_State* L, int a1) {
    return reinterpret_cast<int(__cdecl*)(lua_State*, int)>(0x0084EA90)(L, a1);
}

int lua_error(lua_State* L, const char* format, ...) {
    return reinterpret_cast<int(__cdecl*)(lua_State*, const char*)>(0x0084F280)(L, format);
}

void lua_rawseti(lua_State* L, int idx, int n) {
    reinterpret_cast<void(__cdecl*)(lua_State*, int, int)>(0x0084EA00)(L, idx, n);
}

void lua_rawget(lua_State* L, int idx) {
    reinterpret_cast<void(__cdecl*)(lua_State*, int)>(0x0084E600)(L, idx);
}

int lua_getmetatable(lua_State* L, int idx)
{
    return reinterpret_cast<int(__cdecl*)(lua_State*, int)>(0x0084E730)(L, idx);
}

int lua_rawequal(lua_State* L, int idx1, int idx2) {
    return reinterpret_cast<int(__cdecl*)(lua_State*, int, int)>(0x0084DF90)(L, idx1, idx2);
}

void lua_rawgeti(lua_State* L, int idx, int n) {
    reinterpret_cast<void(__cdecl*)(lua_State*, int, int)>(0x0084E670)(L, idx, n);
}

int lua_SetRow(lua_State* state, int RowNumber) {
    return reinterpret_cast<int(__cdecl*)(lua_State*, int)>(0x0084DAB0)(state, RowNumber);
}

bool lua_IsNumber(lua_State* state, int n_param) {
    return reinterpret_cast<bool(__cdecl*)(lua_State*, int)>(0x0084DF20)(state, n_param);
}

bool lua_toboolean(lua_State* L, int idx) {
    return reinterpret_cast<bool(__cdecl*)(lua_State*, int)>(0x0084E0B0)(L, idx);
}

int lua_type(lua_State* L, int a1) {
    return reinterpret_cast<int(__cdecl*)(lua_State*, int)>(0x0084DEB0)(L, a1);
}

int lua_argerror(lua_State* L, int idx, const char* msg) {
    return ((decltype(&lua_argerror))0x0084F8B0)(L, idx, msg);
}
inline ptrdiff_t luaL_checkinteger(lua_State* L, int idx) {
    return ((decltype(&luaL_checkinteger))0x0084FB60)(L, idx);
}



void lua_pushmethods(lua_State* L, const luaL_Reg methods[]) {
    // Iterate through the luaL_Reg array
    for (const luaL_Reg* method = methods; method->name != NULL; ++method) {
        lua_pushcfunction(L, method->func); // Push the C function onto the stack
        lua_setfield(L, -2, method->name);  // Set it as a field in the table
    }
}

int lua_newmetatable(lua_State* L, const char* tname)
{
    lua_getfield(L, LUA_REGISTRYINDEX, tname);  /* get registry.name */
    if (!lua_isnil(L, -1))  /* name already in use? */
        return 0;  /* leave previous value on top, but return 0 */
    lua_pop(L, 1);
    lua_createtable(L, 0, 0);  /* create metatable */
    lua_pushvalue(L, -1);
    lua_setfield(L, LUA_REGISTRYINDEX, tname);  /* registry.name = metatable */
    return 1;
}

template<typename T>
T lua_checkobject(lua_State* L, int pos, const char* Field)
{ // Check if the value at the given position is a table and has a metatable
    if (lua_type(L, pos) != LUA_TTABLE || !lua_getmetatable(L, pos))
    {
        return T(); // Return default value for T if not a table or no metatable
    }

    lua_getfield(L, LUA_REGISTRYINDEX, Field); // Retrieve the metatable from the registry

    // Check if the metatables are equal
    bool isSame = lua_rawequal(L, -1, -2);
    lua_settop(L, -2); // Pop both metatables off the stack

    if (!isSame)
        return T();

    lua_rawgeti(L, pos, -1); // Retrieve the user data from the table (assuming index 1)
    T* ptr = (T*)lua_touserdata(L, -1); // Get the userdata pointer as void*
    lua_settop(L, -1); // Pop Te userdata off the stack
    // Return the userdata casted to type T
    return *ptr;
}

template<typename T>
void lua_pushobject(lua_State* L, T value, const char* Field)
{
    lua_createtable(L, 0, 0); // Create a new table (tbl)

    // Allocate userdata of the appropriate size for type T
    T* ptr = reinterpret_cast<T*>(lua_newuserdata(L, sizeof(T))); // tbl, udata
    *ptr = value;

    lua_rawseti(L, -2, -1); // Set the userdata as the first element in the table (tbl[1])

    // Get the metatable from the registry using the given field
    lua_getfield(L, LUA_REGISTRYINDEX, Field); // tbl, mt

    // Set the metatable for the table
    lua_setmetatable(L, -2); // tbl
}

int lua_dumpstack(lua_State* L)
{
    int numArgs = lua_gettop(L); // Get the number of arguments on the stack

    printf("Number of arguments: %d\n", numArgs);

    for (int i = 1; i <= numArgs; ++i) {
        printf("Argument %d: ", i);

        int type = lua_type(L, i);
        switch (type) {
        case LUA_TNIL:
            printf("nil");
            break;
        case LUA_TBOOLEAN:
            printf(lua_toboolean(L, i) ? "true" : "false");
            break;
        case LUA_TNUMBER:
            printf("%f", lua_tonumber(L, i));
            break;
        case LUA_TSTRING:
            printf("%s", lua_tostring(L, i));
            break;
        case LUA_TTABLE:
            printf("table");
            break;
        case LUA_TFUNCTION:
            printf("function");
            break;
        case LUA_TUSERDATA:
            printf("userdata");
            break;
        case LUA_TTHREAD:
            printf("thread");
            break;
        case LUA_TLIGHTUSERDATA:
            printf("lightuserdata");
            break;
        default:
            printf("unknown");
            break;
        }

        // Print the value if applicable
        if (type == LUA_TSTRING || type == LUA_TNUMBER || type == LUA_TBOOLEAN) {
            printf(" (value: ");
            if (type == LUA_TSTRING)
                printf("%s", lua_tostring(L, i));
            else if (type == LUA_TNUMBER)
                printf("%f", lua_tonumber(L, i));
            else if (type == LUA_TBOOLEAN)
                printf(lua_toboolean(L, i) ? "true" : "false");
            printf(")");
        }

        printf("\n");
    }
    return 1;
}