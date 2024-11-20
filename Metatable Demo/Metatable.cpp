#include "Lua.h"
#include "LuaDefine.h"
#include <cstring>
#include <iostream>
#include "Metatable.h"
#include <WinUser.h>

// Example struct to be used as userdata
// This structure represents a userdata object in Lua, allowing Lua scripts to manipulate it.
struct MyStruct {
    int value; // A simple integer field, which Lua can get or set via defined methods.
};

// Method to get the value of MyStruct
int MyStruct_GetValue(lua_State* L) {
    // Retrieves the MyStruct userdata from Lua, ensuring it has the correct metatable.
    MyStruct* myStruct = lua_checkobject<MyStruct*>(L, 1, "MyStructMeta");

    // Pushes the 'value' field of the MyStruct instance onto the Lua stack.
    lua_pushinteger(L, myStruct->value);

    return 1; // Return 1 value (the integer) to Lua.
}

// Method to set the value of MyStruct
int MyStruct_SetValue(lua_State* L) {
    // Retrieves the MyStruct userdata from Lua, ensuring it has the correct metatable.
    MyStruct* myStruct = lua_checkobject<MyStruct*>(L, 1, "MyStructMeta");

    // Reads the second argument passed from Lua as an integer and assigns it to the 'value' field.
    int newValue = luaL_checkint(L, 2);
    myStruct->value = newValue; // Update the struct.

    return 0; // Return no values to Lua.
}

// Array of methods for MyStruct
// This array defines the methods associated with the "MyStructMeta" metatable.
// These methods will be available for Lua objects that represent MyStruct.
const luaL_Reg MyStructMethods[] = {
    {"GetValue", MyStruct_GetValue}, // Method to get the 'value' field.
    {"SetValue", MyStruct_SetValue}, // Method to set the 'value' field.
    {NULL, NULL} // Sentinel value indicating the end of the method list.
};

// Function to create a new MyStruct instance and push it to Lua
int CreateMyStruct(lua_State* L)
{
    // Allocates memory for a new userdata object of type MyStruct.
    MyStruct* myStruct = new MyStruct();

    // Initializes the 'value' field with the first argument passed from Lua.
    myStruct->value = static_cast<int>(lua_tonumber(L, 1));

    // Associates the userdata with the "MyStructMeta" metatable, enabling method calls.
    lua_pushobject<MyStruct*>(L, myStruct, "MyStructMeta");

    luaL_getmetatable(L, "MyStructMeta"); // Push the metatable onto the stack.
    lua_setmetatable(L, -2);              // Set the metatable for the userdata.

    return 1; // Return the userdata to Lua as a result.
}

int __GC(lua_State* L)
{
    // Retrieve the userdata (MyStruct) from Lua.
    // This ensures the object is of the correct type and has the expected metatable.
    MyStruct* myStruct = lua_checkobject<MyStruct*>(L, 1, "MyStructMeta");

    // Free the memory associated with the userdata.
    // Here, `delete` is used assuming MyStruct was allocated.
    delete myStruct;

    // Return 1 to indicate successful cleanup (Lua ignores this value for __gc).
    return 1;
}


// MetaDemo function to define and register everything
// This function sets up the "MyStructMeta" metatable and registers CreateMyStruct as a global function.
int Meta::MetaDemo(lua_State* L) {

    // Creates a new metatable for MyStruct if it doesn't already exist.
    if (lua_newmetatable(L, "MyStructMeta")) {
        // Registers methods (GetValue, SetValue) into the metatable.
        lua_pushmethods(L, MyStructMethods);

        // Sets the __index field of the metatable to itself.
        // This enables Lua to find methods for objects with this metatable.
        lua_pushvalue(L, -1);         // Duplicate the metatable on the stack.
        lua_setfield(L, -2, "__index"); // Assign __index to the metatable.

        // Set the __gc metamethod
        lua_pushcfunction(L, __GC);    // Push the __gc function onto the stack.
        lua_setfield(L, -2, "__gc");   // Assign the __gc field in the metatable.

        lua_pop(L, 1); // Clean up the stack by removing the metatable.
    }

    // Registers the CreateMyStruct function globally in Lua.
    lua_pushcfunction(L, CreateMyStruct);
    lua_setglobal(L, "CreateMyStruct");

    return 1; // Indicate successful registration.
}

