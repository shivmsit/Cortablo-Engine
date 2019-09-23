// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include <iostream>

#include "../CortabloEngine.h"

extern "C"
{
#include <lua/lua.h>
#include <lua/lauxlib.h>
#include <lua/lualib.h>
}

class Lua
{
private:
	lua_State* m_LUAState;
	std::string m_FilePath;

	bool CheckLua(lua_State* luaState, int r);
public:
	Lua(const std::string& filePath);
	~Lua();
};
