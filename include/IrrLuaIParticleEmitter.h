// Copyright (C) 2005-2006 Josh Turpen
// This file is part of the IrrLua Lua binding for Irrlicht.
// For conditions of distribution and use, see copyright notice in IrrLua.h

#ifndef _IRRLUAIPARTICLEEMITTER_H_
#define _IRRLUAIPARTICLEEMITTER_H_

#include "IrrLua.h"
#include "IrrLuaProxy.h"

static const char *g_IParticleEmitterTable = "__iparticleemitterproxy";

namespace irr
{
namespace scene
{

class IrrLuaIParticleEmitter : public IParticleEmitter, public IrrLuaProxy
{
public:

	IrrLuaIParticleEmitter() : IrrLuaProxy(g_IParticleEmitterTable) { Proxy = this;}
	virtual ~IrrLuaIParticleEmitter() {}

	virtual s32 emitt(u32 now, u32 timeSinceLastCall, SParticle*& outArray)
	{
		GetNode(L, "affect");						
		if(lua_isnil(L, -1))						
		{
			warn("IrrLua: pure virtual function 'affect' undefined.\n");
			lua_pop(L, 1);
			return 0;
		}

		GetNode(L);										
		lua_pushnumber(L, (lua_Number) now);			
		lua_pushnumber(L, (lua_Number) timeSinceLastCall);
		tolua_pushusertype(L, (void *) outArray, "irr::scene::SParticle");			
		if(lua_pcall(L, 4, 0, 0) != 0)					
		{
			HandleError(L);
			return 0;
		}

		s32 ret =  (s32) lua_tonumber(L, -1);
		lua_pop(L, 1);
		return  ret;
	}

	/////////////////////////
	// IUnknown
	virtual void grab()
	{
		GetNode(L, "grab");				
		if(lua_isnil(L, -1))						
		{
			lua_pop(L, 1);
			IParticleEmitter::grab();
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
			return IParticleEmitter::drop();
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return IParticleEmitter::drop();
		}

		bool ret =  lua_toboolean(L, -1) != 0;
		lua_pop(L, 1);
		return  ret;
	}

};

} // end namespace scene
} // end namespace irr


#endif /* _IRRLUAIPARTICLEEMITTER_H_ */

