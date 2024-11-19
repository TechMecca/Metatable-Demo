#pragma once
#include <string>
#include <functional>
#include <sstream>
#include <variant>

/**
 * @brief Forward declaration of the Lua state structure.
 */
struct lua_State;

/**
 * @brief Retrieves the Lua state pointer.
 *
 * This function returns a pointer to the Lua state.
 *
 * @return lua_State* Pointer to the Lua state.
 */
lua_State* GetLuaState();


/**
 * @brief Definition of a Lua C function pointer type.
 */
using lua_CFunction = int(*)(lua_State*);

using lua_CppFunction = std::function<int(lua_State*)>;

/**
 * @brief Structure representing a Lua/LuaJIT registry entry.
 */
typedef struct luaL_Reg
{
    const char* name;   /**< Name of the function. */
    lua_CFunction func; /**< Pointer to the C function implementing the Lua function. */
} luaL_Reg;



/**
 * @brief Converts a Lua value at the given stack index to a string.
 *
 * This function converts a Lua value at the given stack index to a string.
 *
 * @param state Pointer to the Lua state.
 * @param n_param Index of the Lua value on the stack.
 * @return char* Pointer to the converted string.
 */
char* lua_tostring(lua_State* state, int n_param);

/**
 * @brief Pushes a nil value onto the Lua stack.
 *
 * This function pushes a nil value onto the Lua stack.
 *
 * @param state Pointer to the Lua state.
 * @return int The number of elements on the stack after the operation.
 */
int lua_pushnil(lua_State* state);

/**
 * @brief Pushes a C function onto the Lua stack as a closure.
 *
 * This function pushes a C function onto the Lua stack as a closure.
 *
 * @param L Pointer to the Lua state.
 * @param fn Pointer to the C function.
 * @param n Number of values to be closed.
 */
void lua_pushcclosure(lua_State* L, lua_CFunction fn, int n);

/**
 * @brief Sets the value at the top of the stack as the value of the field of the table at the given index.
 *
 * This function sets the value at the top of the stack as the value of the field of the table at the given index.
 *
 * @param L Pointer to the Lua state.
 * @param idx Index of the table on the stack.
 * @param key Name of the field to set.
 */
void lua_setfield(lua_State* L, int idx, const char* key);

/**
 * @brief Pushes a string onto the Lua stack.
 *
 * This function pushes a string onto the Lua stack.
 *
 * @param L Pointer to the Lua state.
 * @param val The string value to push.
 */
void lua_pushstring(lua_State* L, const char* val);

/**
 * @brief Converts the Lua value at the given stack index to a double-precision floating point number.
 *
 * This function converts the Lua value at the given stack index to a double-precision floating point number.
 *
 * @param L Pointer to the Lua state.
 * @param idx Index of the Lua value on the stack.
 * @return double The converted number.
 */
double lua_tonumber(lua_State* L, int idx);

/**
 * @brief Pushes a boolean value onto the Lua stack.
 *
 * This function pushes a boolean value onto the Lua stack.
 *
 * @param L Pointer to the Lua state.
 * @param val The boolean value to push.
 */
void lua_pushboolean(lua_State* L, bool val);

/**
 * @brief Pushes a number onto the Lua stack.
 *
 * This function pushes a number onto the Lua stack.
 *
 * @param L Pointer to the Lua state.
 * @param val The number to push.
 */
void lua_pushnumber(lua_State* L, double val);

/**
 * @brief Pushes an integer onto the Lua stack.
 *
 * This function pushes an integer onto the Lua stack.
 *
 * @param L Pointer to the Lua state.
 * @param val The integer to push.
 */
void lua_pushinteger(lua_State* L, int val);
/**
 * @brief Checks if the value at the given index is a string.
 *
 * This function checks if the value at the given index in the Lua stack is a string.
 *
 * @param L Pointer to the Lua state.
 * @param idx Index of the value on the stack.
 * @return int Returns 1 if the value is a string, 0 otherwise.
 */
int lua_isstring(lua_State* L, int idx);

/**
 * @brief Converts the Lua value at the given index to an integer.
 *
 * This function converts the Lua value at the given index to an integer.
 *
 * @param L Pointer to the Lua state.
 * @param idx Index of the value on the stack.
 * @return int The converted integer value.
 */
int lua_tointeger(lua_State* L, int idx);

/**
 * @brief Creates a new empty table and pushes it onto the Lua stack.
 *
 * This function creates a new empty table and pushes it onto the Lua stack.
 *
 * @param L Pointer to the Lua state.
 * @param narray Number of array elements pre-allocated.
 * @param nrec Number of non-array elements pre-allocated.
 */
void lua_createtable(lua_State* L, int narray, int nrec);

/**
 * @brief Sets the value at the given stack index as the value of the table at the given index.
 *
 * This function sets the value at the given stack index as the value of the table at the given index.
 *
 * @param L Pointer to the Lua state.
 * @param number Index of the table on the stack.
 * @return int Returns 0 on success, or an error code otherwise.
 */
int lua_settable(lua_State* L, int number);

/**
 * @brief Returns the number of elements on the Lua stack.
 *
 * This function returns the number of elements on the Lua stack.
 *
 * @param L Pointer to the Lua state.
 * @return int Number of elements on the stack.
 */
int lua_gettop(lua_State* L);

/**
 * @brief Creates a new userdata and pushes it onto the Lua stack.
 *
 * This function creates a new userdata with the specified size and pushes it onto the Lua stack.
 *
 * @param L Pointer to the Lua state.
 * @param size Size of the userdata to allocate.
 * @return void* Pointer to the allocated userdata.
 */
void* lua_newuserdata(lua_State* L, size_t size);

/**
 * @brief Gets a value from a table and pushes it onto the Lua stack.
 *
 * This function gets a value from a table at the specified index and pushes it onto the Lua stack.
 *
 * @param L Pointer to the Lua state.
 * @param a1 Index of the table.
 * @param a2 Name of the field.
 * @return int Returns the type of the retrieved value.
 */
int lua_getfield(lua_State* L, int a1, const char* a2);

/**
 * @brief Returns the type of the Lua value at the specified index.
 *
 * This function returns the type of the Lua value at the specified index on the stack.
 *
 * @param L Pointer to the Lua state.
 * @param a1 Index of the value on the stack.
 * @return int Type of the Lua value.
 */
int lua_type(lua_State* L, int a1);

/**
 * @brief Sets the stack top to the specified index.
 *
 * This function sets the stack top to the specified index.
 *
 * @param L Pointer to the Lua state.
 * @param a1 New top index for the stack.
 */
void lua_settop(lua_State* L, int a1);

/**
 * @brief Pushes a copy of the value at the specified index onto the stack.
 *
 * This function pushes a copy of the value at the specified index onto the Lua stack.
 *
 * @param L Pointer to the Lua state.
 * @param a1 Index of the value to push.
 */
void lua_pushvalue(lua_State* L, int a1);

/**
 * @brief Converts the Lua value at the specified index to a userdata.
 *
 * This function converts the Lua value at the specified index to a userdata.
 *
 * @param L Pointer to the Lua state.
 * @param a1 Index of the value on the stack.
 * @return int The converted userdata.
 */
int lua_touserdata(lua_State* L, int a1);

/**
 * @brief Sets the metatable of the userdata at the specified index.
 *
 * This function sets the metatable of the userdata at the specified index.
 *
 * @param L Pointer to the Lua state.
 * @param a1 Index of the userdata on the stack.
 * @return int Returns 1 if successful, 0 otherwise.
 */
int lua_setmetatable(lua_State* L, int a1);

/**
 * @brief Raises an error with a formatted error message.
 *
 * This function raises an error with a formatted error message.
 *
 * @param L Pointer to the Lua state.
 * @param format Format string for the error message.
 * @return int Always returns 0.
 */
int lua_error(lua_State* L, const char* format, ...);

/**
 * @brief Sets the value at the given index as the value of the array part of the table at the given index.
 *
 * This function sets the value at the given index as the value of the array part of the table at the given index.
 *
 * @param L Pointer to the Lua state.
 * @param idx Index of the table on the stack.
 * @param n The array index.
 */
void lua_rawseti(lua_State* L, int idx, int n);

/**
 * @brief Retrieves a value from the table at the given index without invoking metamethods.
 *
 * This function retrieves a value from the table at the given index without invoking metamethods.
 *
 * @param L Pointer to the Lua state.
 * @param idx Index of the table on the stack.
 */
void lua_rawget(lua_State* L, int idx);

/**
 * @brief Pushes the metatable of the value at the given index onto the stack.
 *
 * This function pushes the metatable of the value at the given index onto the stack.
 *
 * @param L Pointer to the Lua state.
 * @param idx Index of the value on the stack.
 * @return int Returns 0 if the value does not have a metatable.
 */
int lua_getmetatable(lua_State* L, int idx);

/**
 * @brief Checks whether the values at the given indices are equal without invoking metamethods.
 *
 * This function checks whether the values at the given indices are equal without invoking metamethods.
 *
 * @param L Pointer to the Lua state.
 * @param idx1 Index of the first value on the stack.
 * @param idx2 Index of the second value on the stack.
 * @return int Returns 1 if the values are equal, 0 otherwise.
 */
int lua_rawequal(lua_State* L, int idx1, int idx2);

/**
 * @brief Retrieves a value from the table at the given index with a non-numeric key.
 *
 * This function retrieves a value from the table at the given index with a non-numeric key.
 *
 * @param L Pointer to the Lua state.
 * @param idx Index of the table on the stack.
 * @param n The key index.
 */
void lua_rawgeti(lua_State* L, int idx, int n);

/**
 * @brief Sets the stack top to the given index, allowing to remove elements from the stack.
 *
 * This function sets the stack top to the given index, allowing to remove elements from the stack.
 *
 * @param state Pointer to the Lua state.
 * @param RowNumber New stack top index.
 * @return int Always returns 0.
 */
int lua_SetRow(lua_State* state, int RowNumber);

/**
 * @brief Checks if the value at the specified index is a number.
 *
 * This function checks if the value at the specified index is a number.
 *
 * @param state Pointer to the Lua state.
 * @param n_param Index of the value on the stack.
 * @return bool Returns true if the value is a number, false otherwise.
 */
bool lua_IsNumber(lua_State* state, int n_param);

/**
 * @brief Converts the Lua value at the given index to a boolean value.
 *
 * This function converts the Lua value at the given index to a boolean value.
 *
 * @param L Pointer to the Lua state.
 * @param idx Index of the value on the stack.
 * @return bool The converted boolean value.
 */
bool lua_toboolean(lua_State* L, int idx);

int lua_argerror(lua_State* L, int idx, const char* msg);

void lua_pushmethods(lua_State* L, const luaL_Reg methods[]);

ptrdiff_t luaL_checkinteger(lua_State* L, int idx);
/**
 * @brief Creates a new metatable and pushes it onto the Lua stack.
 *
 * This function creates a new metatable with the given name and pushes it onto the Lua stack.
 *
 * @param L Pointer to the Lua state.
 * @param tname Name of the metatable.
 * @param r Number of extra table slots to preallocate.
 * @return int Returns 1 if the metatable is successfully created and pushed onto the stack, 0 otherwise.
 */
int lua_newmetatable(lua_State* L, const char* tname);


template<typename T>
T lua_checkobject(lua_State* L, int pos, const char* Field);

template<typename T>
void lua_pushobject(lua_State* L, T value, const char* Field);

/**
 * @brief Dumps all datatype on the stack
 */
int lua_dumpstack(lua_State* L);
