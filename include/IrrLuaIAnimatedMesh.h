// Copyright (C) 2005-2006 Josh Turpen
// This file is part of the IrrLua Lua binding for Irrlicht.
// For conditions of distribution and use, see copyright notice in IrrLua.h

#ifndef _IRRLUAIANIMATEDMESH_H_
#define _IRRLUAIANIMATEDMESH_H_

#include "IrrLua.h"
#include "IrrLuaProxy.h"

static const char *g_IAnimatedMeshTable = "__ianimatedmeshproxy";

namespace irr
{
namespace scene
{
class IrrLuaIAnimatedMesh : public IAnimatedMesh, public IrrLuaProxy {
	public:
	IrrLuaIAnimatedMesh() : IrrLuaProxy(g_IAnimatedMeshTable) {Proxy = this;}
	virtual ~IrrLuaIAnimatedMesh(){}

	virtual s32 getFrameCount()
	{
		GetNode(L, "getFrameCount");						
		if(lua_isnil(L, -1))									
		{
			warn("IrrLua: Warning - pure virtual function 'getFrameCount' undefined.\n");
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

	virtual IMesh* getMesh(s32 frame, s32 detailLevel=255, s32 startFrameLoop=-1, s32 endFrameLoop=-1)
	{
		GetNode(L, "getMesh");			
		if(lua_isnil(L, -1))									
		{
			warn("IrrLua: Warning - pure virtual function 'getMesh' undefined.\n");
			lua_pop(L, 1);
			return NULL;
		}

		GetNode(L);							
		lua_pushnumber(L, (lua_Number) frame);
		lua_pushnumber(L, (lua_Number) detailLevel);
		lua_pushnumber(L, (lua_Number) startFrameLoop);
		lua_pushnumber(L, (lua_Number) endFrameLoop);
		if(lua_pcall(L, 5, 1, 0) != 0)				
		{
			HandleError(L);
			return NULL;
		}

		IMesh* ret = (IMesh *) tolua_tousertype(L, -1, NULL);
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

	virtual E_ANIMATED_MESH_TYPE getMeshType() const
	{
		GetNode(L, "getMeshType");			
		if(lua_isnil(L, -1))						
		{
			lua_pop(L, 1);
			return IAnimatedMesh::getMeshType();
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return IAnimatedMesh::getMeshType();
		}

		s32 ret = (s32) lua_tonumber(L, -1);
		lua_pop(L, 1);
		return (E_ANIMATED_MESH_TYPE) ret;
	}
	///////////////////
	//IUnknown

	virtual void grab()
	{
		GetNode(L, "grab");				
		if(lua_isnil(L, -1))						
		{
			lua_pop(L, 1);
			IAnimatedMesh::grab();
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
			return IAnimatedMesh::drop();
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return IAnimatedMesh::drop();
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
