// Copyright (C) 2005-2006 Josh Turpen
// This file is part of the IrrLua Lua binding for Irrlicht.
// For conditions of distribution and use, see copyright notice in IrrLua.h

#ifndef _IRRLUAIMESH_H_
#define _IRRLUAIMESH_H_

#include "IrrLua.h"
#include "IrrLuaProxy.h"

static const char *g_IMeshTable = "__imeshproxy";

namespace irr
{
namespace scene
{
class IrrLuaIMesh : public IMesh, public IrrLuaProxy {
	public:
	IrrLuaIMesh() : IrrLuaProxy(g_IMeshTable) {Proxy = this;}
	virtual ~IrrLuaIMesh(){}

	virtual s32 getMeshBufferCount()
	{
		GetNode(L, "getMeshBufferCount");						
		if(lua_isnil(L, -1))									
		{
			warn("IrrLua: Warning - pure virtual function 'getMeshBufferCount' undefined.\n");
			lua_pop(L, 1);
			return 0;
		}

		GetNode(L);									
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return 0;
		}

		s32 ret =  (s32) lua_tonumber(L, -1);
		lua_pop(L, 1);
		return  ret;
	}

	virtual IMeshBuffer* getMeshBuffer(s32 nr)
	{
		GetNode(L, "getMeshBuffer");			
		if(lua_isnil(L, -1))									
		{
			warn("IrrLua: Warning - pure virtual function 'getMeshBuffer' undefined.\n");
			lua_pop(L, 1);
			return NULL;
		}

		GetNode(L);							
		lua_pushnumber(L, (lua_Number) nr);
		if(lua_pcall(L, 2, 1, 0) != 0)				
		{
			HandleError(L);
			return NULL;
		}

		IMeshBuffer *ret = (IMeshBuffer *) tolua_tousertype(L, -1, NULL);
		lua_pop(L, 1);
		return  ret;	
	}

	virtual const core::aabbox3d<f32>& getBoundingBox() const 
	{
		GetNode(L, "getBoundingBox");			
		if(lua_isnil(L, -1))						
		{
			warn("IrrLua: pure virtual function 'getBoundingBox' not defined\n");
			lua_pop(L, 1);
			return ret_box;
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return ret_box;
		}

		const core::aabbox3d<f32>& ret = *((core::aabbox3d<f32> *) tolua_tousertype(L, -1, (void *) &ret_box));
		lua_pop(L, 1);
		return ret;
	}

	virtual core::aabbox3d<f32>& getBoundingBox() 
	{
		GetNode(L, "getBoundingBox");			
		if(lua_isnil(L, -1))						
		{
			warn("IrrLua: pure virtual function 'getBoundingBox' undefined\n");
			lua_pop(L, 1);
			return ret_box;
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return ret_box;
		}

		core::aabbox3d<f32>& ret = *((core::aabbox3d<f32> *) tolua_tousertype(L, -1, (void *) &ret_box));
		lua_pop(L, 1);
		return ret;
	}

	virtual void setMaterialFlag(video::E_MATERIAL_FLAG flag, bool newvalue) 
	{
		GetNode(L, "setMaterialFlag");				
		if(lua_isnil(L, -1))									
		{
			warn("IrrLua: pure virtual function 'setMaterialFlag' undefined\n");
			lua_pop(L, 1);
			return;
		}

		GetNode(L);									
		lua_pushnumber(L, (lua_Number) flag);		
		lua_pushboolean(L, newvalue);				
		if(lua_pcall(L, 3, 0, 0) != 0)				
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
			IMesh::grab();
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
			return IMesh::drop();
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return IMesh::drop();
		}

		bool ret =  lua_toboolean(L, -1) != 0;
		lua_pop(L, 1);
		return  ret;
	}

	private:
	//used for reference returns
	core::aabbox3d<f32> ret_box;

};
}
}

#endif /* _IRRLUAEVENTRECEIVER_H_ */
