// Copyright (C) 2005-2006 Josh Turpen
// This file is part of the IrrLua Lua binding for Irrlicht.
// For conditions of distribution and use, see copyright notice in IrrLua.h

#ifndef _IRRLUAISCENENODEANIMATOR_H_
#define _IRRLUAISCENENODEANIMATOR_H_

#include "IrrLua.h"
#include "IrrLuaProxy.h"

static const char *g_ISceneNodeAnimatorTable = "__iscenenodeanimatorproxy";

namespace irr
{
namespace scene
{
class IrrLuaISceneNodeAnimator : public ISceneNodeAnimator, public IrrLuaProxy
{
public:

	IrrLuaISceneNodeAnimator() : IrrLuaProxy(g_ISceneNodeAnimatorTable) { Proxy = this;}
	virtual ~IrrLuaISceneNodeAnimator() {}

	virtual void animateNode(ISceneNode* node, u32 timeMs)
	{
		GetNode(L, "animateNode");						
		if(lua_isnil(L, -1))						
		{
			warn("IrrLua: pure virtual function 'animateNode' undefined.\n");
			lua_pop(L, 1);
			return;
		}

		GetNode(L);										
		tolua_pushusertype(L, (void *) node, "irr::scene::ISceneNode");			
		lua_pushnumber(L, (lua_Number) timeMs);
		if(lua_pcall(L, 3, 0, 0) != 0)					
		{
			HandleError(L);
		}
	}

	virtual void grab()
	{
		GetNode(L, "grab");				
		if(lua_isnil(L, -1))						
		{
			lua_pop(L, 1);
			ISceneNodeAnimator::grab();
			return;
		}

		GetNode(L);								
		if(lua_pcall(L, 1, 0, 0) != 0)					
		{
			HandleError(L);
		}
	}

	bool drop()
	{
		GetNode(L, "drop");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return ISceneNodeAnimator::drop();
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return ISceneNodeAnimator::drop();
		}

		bool ret =  lua_toboolean(L, -1) != 0;
		lua_pop(L, 1);
		return  ret;
	}
		
};
}
}

#endif /* _IRRLUAISCENENODEANIMATOR_H_ */

