// Copyright (C) 2005-2006 Josh Turpen
// This file is part of the IrrLua Lua binding for Irrlicht.
// For conditions of distribution and use, see copyright notice in IrrLua.h

#ifndef _IRRLUASHADERSETCALLBACK_H_
#define _IRRLUASHADERSETCALLBACK_H_

#include "IrrLua.h"
#include "IrrLuaProxy.h"
#include "IMaterialRenderer.h"

static const char *g_ShaderProxyTable = "__shaderproxy";

namespace irr
{
namespace video
{
class IrrLuaIShaderConstantSetCallBack : public irr::video::IShaderConstantSetCallBack, public IrrLuaProxy {

	public:
	 IrrLuaIShaderConstantSetCallBack() : IrrLuaProxy(g_ShaderProxyTable) {Proxy = this; }
	virtual ~IrrLuaIShaderConstantSetCallBack() {}

	virtual void OnSetConstants(irr::video::IMaterialRendererServices *services, s32 userData)
	{
		GetNode(L, "OnSetConstants");	
		if(lua_isnil(L, -1))		
		{
			warn("IrrLua: pure virtual function 'OnSetConstants' not defined\n");
			lua_pop(L, 1);
			return;
		}

		GetNode(L);				
		tolua_pushusertype(L, services, "irr::video::IMaterialRendererServices");	// push arg1
		lua_pushnumber(L, (lua_Number) userData);	
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
			IShaderConstantSetCallBack::grab();
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
			return IShaderConstantSetCallBack::drop();
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return IShaderConstantSetCallBack::drop();
		}

		bool ret =  lua_toboolean(L, -1) != 0;
		lua_pop(L, 1);
		return  ret;
	}
};
}
}

#endif /* _IRRLUASHADERSETCALLBACK_H_ */
