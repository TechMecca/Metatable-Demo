#pragma once
#include "Hooks.h"
#include "Windows.h"
#include "Metatable.h"
#include "detours.h" 


static void(*Lua_OpenFrameXMLApi_orig)() = (decltype(Lua_OpenFrameXMLApi_orig))0x00530F85;
void Lua_OpenFrameXMlApi_bulk()
{
    lua_State* L = GetLuaState();
    Meta::MetaDemo(L);
}

void Hooks::OpenFrame()
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach(&(PVOID&)Lua_OpenFrameXMLApi_orig, Lua_OpenFrameXMlApi_bulk);
    DetourTransactionCommit();
}
