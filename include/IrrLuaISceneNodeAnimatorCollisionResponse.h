// Copyright (C) 2005-2006 Josh Turpen
// This file is part of the IrrLua Lua binding for Irrlicht.
// For conditions of distribution and use, see copyright notice in IrrLua.h

#ifndef _IRRLUAISCENENODEANIMATORCOLLISIONRESPONSE_H_
#define _IRRLUAISCENENODEANIMATORCOLLISIONRESPONSE_H_

#include "IrrLua.h"
#include "IrrLuaProxy.h"

static const char *g_ISceneNodeAnimatorCollisionResponseTable = "__iscenenodeanimatorcollisionresponseproxy";

namespace irr
{
namespace scene
{

	class IrrLuaISceneNodeAnimatorCollisionResponse : public ISceneNodeAnimatorCollisionResponse, public IrrLuaProxy
	{
	public:

		IrrLuaISceneNodeAnimatorCollisionResponse() :  IrrLuaProxy(g_ISceneNodeAnimatorCollisionResponseTable) {Proxy = this;}
		virtual ~IrrLuaISceneNodeAnimatorCollisionResponse() {}

		virtual bool isFalling()
		{
			GetNode(L, "isFalling");				
			if(lua_isnil(L, -1))									
			{
				warn("IrrLua: pure virtual function 'isFalling' undefined.\n");
				lua_pop(L, 1);
				return false;
			}

			GetNode(L);									
			if(lua_pcall(L, 1, 1, 0) != 0)				
			{
				HandleError(L);
				return false;
			}

			bool ret =  lua_toboolean(L, -1) != 0;
			lua_pop(L, 1);
			return  ret;
		}

		virtual void setEllipsoidRadius(const core::vector3df& radius)
		{
			GetNode(L, "setEllipsoidRadius");			
			if(lua_isnil(L, -1))									
			{
				warn("IrrLua: pure virtual function 'setEllipsoidRadius' undefined.\n");
				lua_pop(L, 1);
				return;
			}

			GetNode(L);							
			tolua_pushusertype(L, (void *) &radius, "irr::core::vector3d<f32>");					
			if(lua_pcall(L, 2, 0, 0) != 0)				
			{
				HandleError(L);
			}
		}

		virtual core::vector3df getEllipsoidRadius() const
		{
			GetNode(L, "getEllipsoidRadius");			
			if(lua_isnil(L, -1))									
			{
				warn("IrrLua: pure virtual function 'getEllipsoidRadius' undefined.\n");
				lua_pop(L, 1);
				return ret_vector3df;
			}

			GetNode(L);		
			if(lua_pcall(L, 1, 1, 0) != 0)					
			{
				HandleError(L);
				return ret_vector3df;
			}

			core::vector3df *ret = (core::vector3df *) tolua_tousertype(L, -1, (void *) &ret_vector3df);
			lua_pop(L, 1);
			return  *ret;
		}

		virtual void setGravity(const core::vector3df& gravity)
		{
			GetNode(L, "setGravity");			
			if(lua_isnil(L, -1))									
			{
				warn("IrrLua: pure virtual function 'setGravity' undefined.\n");
				lua_pop(L, 1);
				return;
			}

			GetNode(L);							
			tolua_pushusertype(L, (void *) &gravity, "irr::core::vector3d<f32>");					
			if(lua_pcall(L, 2, 0, 0) != 0)				
			{
				HandleError(L);
			}
		}

		virtual core::vector3df getGravity() const
		{
			GetNode(L, "getGravity");			
			if(lua_isnil(L, -1))									
			{
				warn("IrrLua: pure virtual function 'getGravity' undefined.\n");
				lua_pop(L, 1);
				return ret_vector3df;
			}

			GetNode(L);		
			if(lua_pcall(L, 1, 1, 0) != 0)					
			{
				HandleError(L);
				return ret_vector3df;
			}

			core::vector3df *ret = (core::vector3df *) tolua_tousertype(L, -1, (void *) &ret_vector3df);
			lua_pop(L, 1);
			return  *ret;
		}

		virtual void setEllipsoidTranslation(core::vector3df translation)
		{
			GetNode(L, "setEllipsoidTranslation");			
			if(lua_isnil(L, -1))									
			{
				warn("IrrLua: pure virtual function 'setEllipsoidTranslation' undefined.\n");
				lua_pop(L, 1);
				return;
			}

			GetNode(L);							
			tolua_pushusertype(L, (void *) &translation, "irr::core::vector3d<f32>");					
			if(lua_pcall(L, 2, 0, 0) != 0)				
			{
				HandleError(L);
			}
		}

		virtual core::vector3df getEllipsoidTranslation() const
		{
			GetNode(L, "getEllipsoidTranslation");			
			if(lua_isnil(L, -1))									
			{
				warn("IrrLua: pure virtual function 'getEllipsoidTranslation' undefined.\n");
				lua_pop(L, 1);
				return ret_vector3df;
			}

			GetNode(L);		
			if(lua_pcall(L, 1, 1, 0) != 0)					
			{
				HandleError(L);
				return ret_vector3df;
			}

			core::vector3df *ret = (core::vector3df *) tolua_tousertype(L, -1, (void *) &ret_vector3df);
			lua_pop(L, 1);
			return  *ret;
		}

		virtual void setWorld(ITriangleSelector* newWorld)
		{
			GetNode(L, "setWorld");			
			if(lua_isnil(L, -1))									
			{
				warn("IrrLua: pure virtual function 'setWorld' undefined.\n");
				lua_pop(L, 1);
				return;
			}

			GetNode(L);							
			tolua_pushusertype(L, (void *) newWorld, "irr::scene::ITriangleSelector");					
			if(lua_pcall(L, 2, 0, 0) != 0)				
			{
				HandleError(L);
			}
		}

		virtual ITriangleSelector* getWorld() const
		{
			GetNode(L, "getWorld");			
			if(lua_isnil(L, -1))									
			{
				warn("IrrLua: pure virtual function 'getWorld' undefined.\n");
				lua_pop(L, 1);
				return NULL;
			}

			GetNode(L);							
			if(lua_pcall(L, 1, 1, 0) != 0)				
			{
				HandleError(L);
				return NULL;
			}

			scene::ITriangleSelector *ret = (scene::ITriangleSelector *) tolua_tousertype(L, -1, NULL);
			lua_pop(L, 1);
			return  ret;	
		}

		//ISceneNodeAnimator
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
				ISceneNodeAnimatorCollisionResponse::grab();
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
				return ISceneNodeAnimatorCollisionResponse::drop();
			}

			GetNode(L);							
			if(lua_pcall(L, 1, 1, 0) != 0)				
			{
				HandleError(L);
				return ISceneNodeAnimatorCollisionResponse::drop();
			}

			bool ret =  lua_toboolean(L, -1) != 0;
			lua_pop(L, 1);
			return  ret;
		}
	
		private:
			core::vector3df ret_vector3df;

	};
} // end namespace scene
} // end namespace irr

#endif /* _IRRLUAISCENENODEANIMATORCOLLISIONRESPONSE_H_  */

