#pragma once
#include "Lua.h"
/**
 * @brief Represents the special return value indicating multiple return values in Lua.
 */
#define LUA_MULTRET (-1)

 /**
 * @brief Index of the Lua registry.
 *
 * The Lua registry is a table used by the interpreter to store references to Lua values.
 */
#define LUA_REGISTRYINDEX (-10000)

 /**
 * @brief Index of the environment table.
 *
 * This index refers to the environment table, typically used for global variables.
 */
#define LUA_ENVIRONINDEX (-10001)

 /**
 * @brief Index of the global table.
 *
 * This index refers to the global table in the Lua environment.
 */
#define LUA_GLOBALSINDEX (-10002)

 /**
 * @brief Macro to calculate the index of an upvalue.
 *
 * This macro calculates the index of an upvalue based on its position.
 *
 * @param i Index of the upvalue.
 */
#define lua_upvalueindex(i) (LUA_GLOBALSINDEX - (i))

 /**
 * @brief Error code indicating a yield.
 */
#define LUA_YIELD 1

 /**
 * @brief Error code indicating a runtime error.
 */
#define LUA_ERRRUN 2

 /**
 * @brief Error code indicating a syntax error.
 */
#define LUA_ERRSYNTAX 3

 /**
 * @brief Error code indicating a memory allocation error.
 */
#define LUA_ERRMEM 4

 /**
 * @brief Error code indicating an error in the error handling function.
 */
#define LUA_ERRERR 5

 /**
 * @brief Lua type representing no value.
 */
#define LUA_TNONE (-1)

 /**
 * @brief Lua type representing nil.
 */
#define LUA_TNIL 0

 /**
 * @brief Lua type representing a boolean value.
 */
#define LUA_TBOOLEAN 1

 /**
 * @brief Lua type representing light userdata.
 */
#define LUA_TLIGHTUSERDATA 2

 /**
 * @brief Lua type representing a number.
 */
#define LUA_TNUMBER 3

 /**
 * @brief Lua type representing a string.
 */
#define LUA_TSTRING 4

 /**
 * @brief Lua type representing a table.
 */
#define LUA_TTABLE 5

 /**
 * @brief Lua type representing a function.
 */
#define LUA_TFUNCTION 6

 /**
 * @brief Lua type representing userdata.
 */
#define LUA_TUSERDATA 7

 /**
 * @brief Lua type representing a thread.
 */
#define LUA_TTHREAD 8

 /**
 * @brief Special reference value indicating no reference.
 */
#define LUA_NOREF (-2)

 /**
 * @brief Special reference value indicating a reference to nil.
 */
#define LUA_REFNIL (-1)

 /**
 * @brief Sets a global variable in the Lua environment.
 *
 * This macro sets a global variable in the Lua environment using a given name.
 *
 * @param L Pointer to the Lua state.
 * @param s Name of the global variable.
 */
#define lua_setglobal(L, s) lua_setfield(L, LUA_GLOBALSINDEX, (s))

 /**
 * @brief Retrieves a global variable from the Lua environment.
 *
 * This macro retrieves a global variable from the Lua environment using a given name.
 *
 * @param L Pointer to the Lua state.
 * @param s Name of the global variable.
 */
#define lua_getglobal(L, s) lua_getfield(L, LUA_GLOBALSINDEX, (s))

 /**
 * @brief Sets a local variable in the Lua registry.
 *
 * This macro sets a local variable in the Lua registry using a given name.
 *
 * @param L Pointer to the Lua state.
 * @param s Name of the local variable.
 */
#define lua_setLocal(L, s) lua_setfield(L, LUA_REGISTRYINDEX, (s))

 /**
 * @brief Retrieves a local variable from the Lua registry.
 *
 * This macro retrieves a local variable from the Lua registry using a given name.
 *
 * @param L Pointer to the Lua state.
 * @param s Name of the local variable.
 */
#define lua_getLocal(L, s) lua_getfield(L, LUA_REGISTRYINDEX, (s))


#define luaL_argcheck(L, cond,numarg,extramsg)	\
		((void)((cond) || lua_argerror(L, (numarg), (extramsg))))


#define luaL_checkint(L,n)	((int)luaL_checkinteger(L, (n)))

#define lua_registerfunction(L, n, f) (lua_pushcclosure(L, (f)), lua_setglobal(L, (n)))

#define lua_pushcfunction(L, f) lua_pushcclosure(L, (f), 0)

#define lua_register(L, name, f) (lua_pushcfunction(L, (f)), lua_setglobal(L, (name)))

#define luaL_getmetatable(L,n)  (lua_getfield(L, LUA_REGISTRYINDEX, (n)))

#define luaL_setmetatable(L,n)  (lua_setfield(L, LUA_REGISTRYINDEX, (n)))

#define lua_isnil(L,n)          (lua_type(L, (n)) == LUA_TNIL)

#define lua_pop(L, n) lua_settop(L, -(n)-1)
