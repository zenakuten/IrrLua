// Copyright (C) 2005-2006 Josh Turpen
// This file is part of the IrrLua Lua binding for Irrlicht.
// For conditions of distribution and use, see copyright notice in IrrLua.h

#ifndef _IRRLUAITRIANGLESELECTOR_H_
#define _IRRLUAITRIANGLESELECTOR_H_

#include "IrrLua.h"
#include "IrrLuaProxy.h"

static const char *g_ITriangleSelectorTable = "__itriangleselectorproxy";

namespace irr
{
namespace scene
{

class IrrLuaITriangleSelector : public ITriangleSelector, public IrrLuaProxy
{
public:

	IrrLuaITriangleSelector() : IrrLuaProxy(g_ITriangleSelectorTable) {Proxy = this;}
	virtual ~IrrLuaITriangleSelector() {}

	virtual s32 getTriangleCount() const
	{
		GetNode(L, "getTriangleCount");			
		if(lua_isnil(L, -1))						
		{
			warn("IrrLua: pure virtual function 'getTriangleCount' undefined\n");
			lua_pop(L, 1);
			return 0;
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return 0;
		}

		s32 ret = (s32) lua_tonumber(L, -1);
		lua_pop(L, 1);
		return ret;
	}
	virtual void getTriangles(core::triangle3df* triangles, s32 arraySize, s32& outTriangleCount, const core::matrix4* transform=0)
	{
		GetNode(L, "getTriangles");					
		if(lua_isnil(L, -1))						
		{
			lua_pop(L, 1);
			warn("IrrLua: pure virtual function 'getTriangles' undefined\n");
			return;
		}

		GetNode(L);						
		tolua_pushusertype(L, (void *) triangles, "irr::core::triangle3d<f32>");
		lua_pushnumber(L, (lua_Number) arraySize);
		lua_pushnumber(L, (lua_Number) outTriangleCount);
		tolua_pushusertype(L, (void *) transform, "irr::core::matrix4");
		if(lua_pcall(L, 5, 0, 0) != 0)					
		{
			HandleError(L);
		}
	}
	virtual void getTriangles(core::triangle3df* triangles, s32 arraySize, s32& outTriangleCount, const core::aabbox3d<f32>& box, const core::matrix4* transform=0)
	{
		GetNode(L, "getTriangles");					
		if(lua_isnil(L, -1))						
		{
			lua_pop(L, 1);
			warn("IrrLua: pure virtual function 'getTriangles' undefined\n");
			return;
		}

		GetNode(L);						
		tolua_pushusertype(L, (void *) triangles, "irr::core::triangle3d<f32>");
		lua_pushnumber(L, (lua_Number) arraySize);
		lua_pushnumber(L, (lua_Number) outTriangleCount);
		tolua_pushusertype(L, (void *) &box, "irr::core::aabbox3d<f32>");
		tolua_pushusertype(L, (void *) transform, "irr::core::matrix4");
		if(lua_pcall(L, 6, 0, 0) != 0)					
		{
			HandleError(L);
		}
	}
	virtual void getTriangles(core::triangle3df* triangles, s32 arraySize, s32& outTriangleCount, const core::line3d<f32>& line, const core::matrix4* transform=0)
	{
		GetNode(L, "getTriangles");					
		if(lua_isnil(L, -1))						
		{
			lua_pop(L, 1);
			warn("IrrLua: pure virtual function 'getTriangles' undefined\n");
			return;
		}

		GetNode(L);						
		tolua_pushusertype(L, (void *) triangles, "irr::core::triangle3d<f32>");
		lua_pushnumber(L, (lua_Number) arraySize);
		lua_pushnumber(L, (lua_Number) outTriangleCount);
		tolua_pushusertype(L, (void *) &line, "irr::core::line3d<f32>");
		tolua_pushusertype(L, (void *) transform, "irr::core::matrix4");
		if(lua_pcall(L, 6, 0, 0) != 0)					
		{
			HandleError(L);
		}
	}


	///////////////////
	//IUnknown

	virtual void grab()
	{
		GetNode(L, "grab");				
		if(lua_isnil(L, -1))						
		{
			lua_pop(L, 1);
			ITriangleSelector::grab();
			return;
		}

		GetNode(L);								
		if(lua_pcall(L, 1, 0, 0) != 0)					
		{
			HandleError(L);
		}
	}

	virtual bool drop()
	{
		GetNode(L, "drop");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return ITriangleSelector::drop();
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return ITriangleSelector::drop();
		}

		bool ret =  lua_toboolean(L, -1) != 0;
		lua_pop(L, 1);
		return  ret;
	}

};

} 
} 


#endif

