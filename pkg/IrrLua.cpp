// Copyright (C) 2005-2006 Josh Turpen, Nikolaus Gebhardt
// This file is part of the IrrLua Lua binding for Irrlicht.
// For conditions of distribution and use, see copyright notice in IrrLua.h


//TODO: clean this file up :)




#if _MSC_VER > 1300

//using c linkage with c++ stuff is OK 
#pragma warning(disable:4910)
//stupid compiler limit line number warning
#pragma warning(disable:4049)
//bool performance warnings in auto-generated file, i can't fix those
#pragma warning(disable:4800)

//trunc f32 ok
#pragma warning(disable:4244)
#endif

#include "IrrLua.h"
#include "IrrLua_imp.h"

#define TMP_VERSION LUA_VERSION_NUM

// need to force tolua to not create luaopen_IrrLua() for us
#undef LUA_VERSION_NUM 
#include "IrrLua_imp.cpp"

#define LUA_VERSION_NUM TMP_VERSION
#if _MSC_VER > 1300
#pragma warning(default:4244)
#pragma warning(default:4800)
#pragma warning(default:4910)
#pragma warning(default:4049)
#endif



lua_State *_IrrLuaGlobalState = NULL;
lua_State *IrrLuaGetState()
{
	return _IrrLuaGlobalState;
}
void IrrLuaSetState(lua_State *L)
{
	_IrrLuaGlobalState = L;
}

//create custom luaopen_IrrLua
//see IrrLua.cpp 
IRRLUA_API int luaopen_IrrLua(lua_State *L)
{
	IrrLuaSetState(L);
	tolua_open(L);
	luaopen_IrrLuaAux(L);
	tolua_IrrLua_open(L);
	return 1;
}
