// Copyright (C) 2005-2006 Josh Turpen
// This file is part of the IrrLua Lua binding for Irrlicht.
// For conditions of distribution and use, see copyright notice in IrrLua.h

#ifndef _IRRLUAIPARTICLEAFFECTOR_H_
#define _IRRLUAIPARTICLEAFFECTOR_H_

#include "IrrLua.h"
#include "IrrLuaProxy.h"

static const char *g_IParticleAffectorTable = "__iparticleaffectorproxy";

namespace irr
{
namespace scene
{

class IrrLuaIParticleAffector : public IParticleAffector, public IrrLuaProxy
{
public:
	IrrLuaIParticleAffector() : IrrLuaProxy(g_IParticleAffectorTable) {Proxy = this;}
	virtual ~IrrLuaIParticleAffector() {}

	virtual void affect(u32 now, SParticle* particlearray, u32 count)
	{
		GetNode(L, "affect");						
		if(lua_isnil(L, -1))						
		{
			warn("IrrLua: pure virtual function 'affect' undefined.\n");
			lua_pop(L, 1);
			return;
		}

		GetNode(L);										
		lua_pushnumber(L, (lua_Number) now);			
		tolua_pushusertype(L, (void *) particlearray, "irr::scene::SParticle");			
		lua_pushnumber(L, (lua_Number) count);
		if(lua_pcall(L, 4, 0, 0) != 0)					
		{
			HandleError(L);
		}
	}

	//! Get emitter type
	virtual irr::scene::E_PARTICLE_AFFECTOR_TYPE getType()
	{
		GetNode(L, "getType");				
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return irr::scene::EPAT_NONE;
		}

		GetNode(L);									
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return irr::scene::EPAT_NONE;
		}

		irr::scene::E_PARTICLE_AFFECTOR_TYPE type = (irr::scene::E_PARTICLE_AFFECTOR_TYPE) ((int)tolua_tonumber(L, -1, 0));
		lua_pop(L, 1);
		return  type;
	}



	virtual void grab()
	{
		GetNode(L, "grab");				
		if(lua_isnil(L, -1))						
		{
			lua_pop(L, 1);
			IParticleAffector::grab();
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
			return IParticleAffector::drop();
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return IParticleAffector::drop();
		}

		bool ret =  lua_toboolean(L, -1) != 0;
		lua_pop(L, 1);
		return  ret;
	}
};

} // end namespace scene
} // end namespace irr

#endif /* _IRRLUAIPARTICLEAFFECTOR_H_ */
