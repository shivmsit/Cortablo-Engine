// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "Lua.h"

Lua::Lua(const std::string& filePath) : m_FilePath(filePath)
{
	m_LUAState = luaL_newstate();
	luaL_openlibs(m_LUAState);
    
	if (CheckLua(m_LUAState, luaL_dofile(m_LUAState, m_FilePath.c_str())))
	{
		printf("[LUA] Lua script loaded!\n");
	}
	else
	{
		printf("[LUA] Error: Lua script could not be loaded!\n");
	}
}

Lua::~Lua()
{

}

bool Lua::CheckLua(lua_State* luaState, int r)
{
	if (r == LUA_OK)
	{
		printf("[LUA] Lua script has no errors!\n");
		return true;
	}
	printf("[LUA] Error: Lua script has errors!\n");
	std::string errorMessage = lua_tostring(luaState, -1);
	printf("[LUA] Error: %s\n", errorMessage.c_str());
	return false;
}
