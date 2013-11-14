// Copyright (C) 2005-2006 Josh Turpen
// This file is part of the IrrLua Lua binding for Irrlicht.
// For conditions of distribution and use, see copyright notice in IrrLua.h

#ifndef _IRRLUAIANIMATEDMESHSCENENODE_H_
#define _IRRLUAIANIMATEDMESHSCENENODE_H_

#include "IrrLua.h"
#include "IrrLuaProxy.h"

static const char *g_IAnimatedMeshSceneNodeTable = "__ianimatedmeshscenenodeproxy";

namespace irr
{
namespace scene
{
class IrrLuaIAnimationEndCallBack : public IAnimationEndCallBack, public IrrLuaProxy 
{
public:
	IrrLuaIAnimationEndCallBack() : IrrLuaProxy(g_IAnimatedMeshSceneNodeTable) {Proxy = this;}
	virtual ~IrrLuaIAnimationEndCallBack() {}
	virtual void OnAnimationEnd(IAnimatedMeshSceneNode* node)
	{
		GetNode(L, "OnAnimationEnd");						
		if(lua_isnil(L, -1))						
		{
			warn("IrrLua: pure virtual function 'OnAnimationEnd' undefined.\n");
			lua_pop(L, 1);
			return;
		}

		GetNode(L);										
		tolua_pushusertype(L, (void *) node, "irr::scene:IAnimatedMeshSceneNode");
		if(lua_pcall(L, 2, 0, 0) != 0)					
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
			IAnimationEndCallBack::grab();
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
			return IAnimationEndCallBack::drop();
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return IAnimationEndCallBack::drop();
		}

		bool ret =  lua_toboolean(L, -1) != 0;
		lua_pop(L, 1);
		return  ret;
	}
};

class IrrLuaIAnimatedMeshSceneNode : public IAnimatedMeshSceneNode, public IrrLuaProxy
{
public:
	IrrLuaIAnimatedMeshSceneNode(ISceneNode *parent, ISceneManager *mgr, s32 id) : IAnimatedMeshSceneNode(parent, mgr, id), IrrLuaProxy(g_IAnimatedMeshSceneNodeTable) { Proxy = this;}
	~IrrLuaIAnimatedMeshSceneNode() {}

	virtual void setCurrentFrame(s32 frame)
	{
		GetNode(L, "setCurrentFrame");						
		if(lua_isnil(L, -1))						
		{
			warn("IrrLua: pure virtual function 'setCurrentFrame' undefined.\n");
			lua_pop(L, 1);
			return;
		}

		GetNode(L);										
		lua_pushnumber(L, (lua_Number) frame);			
		if(lua_pcall(L, 2, 0, 0) != 0)					
		{
			HandleError(L);
		}
	}

	virtual bool setFrameLoop(s32 begin, s32 end)
	{
		GetNode(L, "setFrameLoop");				
		if(lua_isnil(L, -1))									
		{
			warn("IrrLua: pure virtual function 'setFrameLoop' undefined.\n");
			lua_pop(L, 1);
			return false;
		}

		GetNode(L);									
		lua_pushnumber(L, (lua_Number) begin);
		lua_pushnumber(L, (lua_Number) end);
		if(lua_pcall(L, 3, 1, 0) != 0)				
		{
			HandleError(L);
			return false;
		}

		bool ret =  lua_toboolean(L, -1) != 0;
		lua_pop(L, 1);
		return  ret;
	}

	virtual void setAnimationSpeed(s32 framesPerSecond)
	{
		GetNode(L, "setAnimationSpeed");						
		if(lua_isnil(L, -1))						
		{
			warn("IrrLua: pure virtual function 'setAnimationSpeed' undefined.\n");
			lua_pop(L, 1);
			return;
		}

		GetNode(L);										
		lua_pushnumber(L, (lua_Number) framesPerSecond);			
		if(lua_pcall(L, 2, 0, 0) != 0)					
		{
			HandleError(L);
		}
	}
	
	virtual IShadowVolumeSceneNode* addShadowVolumeSceneNode(s32 id=-1,bool zfailmethod=true, f32 infinity=10000.0f)
	{
		GetNode(L, "addShadowVolumeSceneNode");			
		if(lua_isnil(L, -1))									
		{
			warn("IrrLua: pure virtual function 'addShadowVolumeSceneNode' undefined.\n");
			lua_pop(L, 1);
			return NULL;
		}

		GetNode(L);		
		lua_pushnumber(L, (lua_Number) id);
		lua_pushboolean(L, zfailmethod);
		lua_pushnumber(L, (lua_Number) infinity);
		if(lua_pcall(L, 4, 1, 0) != 0)				
		{
			HandleError(L);
			return NULL;
		}

		IShadowVolumeSceneNode *ret = (IShadowVolumeSceneNode *) tolua_tousertype(L, -1, NULL);
		lua_pop(L, 1);
		return  ret;	
	}
	
	virtual ISceneNode* getMS3DJointNode(const c8* jointName)
	{
		GetNode(L, "getMS3DJointNode");			
		if(lua_isnil(L, -1))									
		{
			warn("IrrLua: pure virtual function 'getMS3DJointNode' undefined.\n");
			lua_pop(L, 1);
			return NULL;
		}

		GetNode(L);		
		tolua_pushusertype(L, (void *) jointName, "irr::c8");
		if(lua_pcall(L, 2, 1, 0) != 0)				
		{
			HandleError(L);
			return NULL;
		}

		ISceneNode *ret = (ISceneNode *) tolua_tousertype(L, -1, NULL);
		lua_pop(L, 1);
		return  ret;	
	}
	
	virtual ISceneNode* getXJointNode(const c8* jointName)
	{
		GetNode(L, "getXJointNode");			
		if(lua_isnil(L, -1))									
		{
			warn("IrrLua: pure virtual function 'getXJointNode' undefined.\n");
			lua_pop(L, 1);
			return NULL;
		}

		GetNode(L);		
		tolua_pushusertype(L, (void *) jointName, "irr::c8");
		if(lua_pcall(L, 2, 1, 0) != 0)				
		{
			HandleError(L);
			return NULL;
		}

		ISceneNode *ret = (ISceneNode *) tolua_tousertype(L, -1, NULL);
		lua_pop(L, 1);
		return  ret;	
	}
	
	virtual bool setMD2Animation(EMD2_ANIMATION_TYPE anim)
	{
		GetNode(L, "setMD2Animation");				
		if(lua_isnil(L, -1))									
		{
			warn("IrrLua: pure virtual function 'setMD2Animation' undefined.\n");
			lua_pop(L, 1);
			return false;
		}

		GetNode(L);									
		lua_pushnumber(L, (lua_Number) anim);
		if(lua_pcall(L, 2, 1, 0) != 0)				
		{
			HandleError(L);
			return false;
		}

		bool ret =  lua_toboolean(L, -1) != 0;
		lua_pop(L, 1);
		return  ret;
	}
	
	virtual bool setMD2Animation(const c8* animationName)
	{
		GetNode(L, "setMD2Animation");				
		if(lua_isnil(L, -1))									
		{
			warn("IrrLua: pure virtual function 'setMD2Animation' undefined.\n");
			lua_pop(L, 1);
			return false;
		}

		GetNode(L);									
		tolua_pushusertype(L, (void *) animationName, "irr::c8");
		if(lua_pcall(L, 2, 1, 0) != 0)				
		{
			HandleError(L);
			return false;
		}

		bool ret =  lua_toboolean(L, -1) != 0;
		lua_pop(L, 1);
		return  ret;	}
	
	virtual s32 getFrameNr()
	{
		GetNode(L, "getFrameNr");						
		if(lua_isnil(L, -1))									
		{
			warn("IrrLua: pure virtual function 'getFrameNr' undefined.\n");
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

	virtual void setLoopMode(bool playAnimationLooped)
	{
		GetNode(L, "setLoopMode");			
		if(lua_isnil(L, -1))									
		{
			warn("IrrLua: pure virtual function 'setLoopMode' undefined.\n");
			lua_pop(L, 1);
			return;
		}

		GetNode(L);							
		lua_pushboolean(L, playAnimationLooped);				
		if(lua_pcall(L, 2, 0, 0) != 0)				
		{
			HandleError(L);
		}
	}

	virtual void setAnimationEndCallback(IAnimationEndCallBack* callback=0)
	{
		GetNode(L, "setAnimationEndCallback");			
		if(lua_isnil(L, -1))									
		{
			warn("IrrLua: pure virtual function 'setAnimationEndCallback' undefined.\n");
			lua_pop(L, 1);
			return;
		}

		GetNode(L);							
		tolua_pushusertype(L, (void *) callback, "irr::scene::IAnimationEndCallBack");				
		if(lua_pcall(L, 2, 0, 0) != 0)				
		{
			HandleError(L);
		}
	}

	///////////////////////////////////////////
	// ISceneNode

	virtual void OnPreRender()
	{
		GetNode(L, "OnPreRender");					
		if(lua_isnil(L, -1))						
		{
			lua_pop(L, 1);
			IAnimatedMeshSceneNode::OnPreRender();
			return;
		}

		GetNode(L);										
		if(lua_pcall(L, 1, 0, 0) != 0)					
		{
			HandleError(L);
		}
	}

	virtual void OnPostRender(u32 timeMs)
	{
		GetNode(L, "OnPostRender");						
		if(lua_isnil(L, -1))						
		{
			lua_pop(L, 1);
			IAnimatedMeshSceneNode::OnPostRender(timeMs);
			return;
		}

		GetNode(L);										
		lua_pushnumber(L, (lua_Number) timeMs);			
		if(lua_pcall(L, 2, 0, 0) != 0)					
		{
			HandleError(L);
		}
	}
	
	virtual void render()
	{
		GetNode(L, "render");						
		if(lua_isnil(L, -1))						
		{
			warn("IrrLua: pure virtual function 'render' not defined\n");
			lua_pop(L, 1);
			return;
		}

		GetNode(L);									
		if(lua_pcall(L, 1, 0, 0) != 0)				
		{
			HandleError(L);
		}
	}
	
	virtual const char* getName() const
	{
		GetNode(L, "getName");
		if(lua_isnil(L, -1))						
		{
			lua_pop(L, 1);
			return IAnimatedMeshSceneNode::getName();
		}

		GetNode(L);		
		if(lua_pcall(L, 1, 1, 0) != 0)					
		{
			HandleError(L);
			return NULL;
		}

		char *ret = (char *) tolua_tousertype(L, -1, (void *) IAnimatedMeshSceneNode::getName());
		lua_pop(L, 1);
		return ret;
	}

	virtual void setName(const char* name)
	{
		GetNode(L, "setName");					
		if(lua_isnil(L, -1))						
		{
			lua_pop(L, 1);
			IAnimatedMeshSceneNode::setName(name);
			return;
		}

		GetNode(L);												
		tolua_pushusertype(L, (void *) name, "c8");		
		if(lua_pcall(L, 2, 0, 0) != 0)							
		{
			HandleError(L);
			return;
		}
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

	virtual core::aabbox3d<f32>& getTransformedBoundingBox() 
	{
		GetNode(L, "getTransformedBoundingBox");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
		}

		GetNode(L);									
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			((core::aabbox3d<f32>)ret_box) = IAnimatedMeshSceneNode::getTransformedBoundingBox();
			return ret_box;
		}

		core::aabbox3d<f32> &ret = *((core::aabbox3d<f32> *) tolua_tousertype(L, -1, &ret_box));
		lua_pop(L, 1);
		return ret;
	}

	core::matrix4& getAbsoluteTransformation()
	{
		GetNode(L,  "getAbsoluteTransformation");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			ret_matrix4 = IAnimatedMeshSceneNode::getAbsoluteTransformation();
			return ret_matrix4;
		}

		GetNode(L);									
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			ret_matrix4 = IAnimatedMeshSceneNode::getAbsoluteTransformation();
			return ret_matrix4;
		}

		core::matrix4 &ret = *((core::matrix4 *) tolua_tousertype(L, -1, &ret_matrix4));
		lua_pop(L, 1);
		return ret;
	}
	
	virtual core::matrix4 getRelativeTransformation() const
	{
		GetNode(L, "getRelativeTransformation");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IAnimatedMeshSceneNode::getRelativeTransformation();
		}

		GetNode(L);		
		if(lua_pcall(L, 1, 1, 0) != 0)					
		{
			HandleError(L);
			return IAnimatedMeshSceneNode::getRelativeTransformation();
		}

		core::matrix4 *ret = (core::matrix4 *) tolua_tousertype(L, -1, (void *) &ret_matrix4);
		lua_pop(L, 1);
		return  *ret;
	}
	
	virtual bool isVisible()
	{
		GetNode(L, "isVisible");				
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IAnimatedMeshSceneNode::isVisible();
		}

		GetNode(L);									
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return IAnimatedMeshSceneNode::isVisible();
		}

		bool ret =  lua_toboolean(L, -1) != 0;
		lua_pop(L, 1);
		return  ret;
	}

	virtual void setVisible(bool isVisible)
	{
		GetNode(L, "setVisible");					
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IAnimatedMeshSceneNode::setVisible(isVisible);
		}

		GetNode(L);									
		lua_pushboolean(L, isVisible);				
		if(lua_pcall(L, 2, 0, 0) != 0)				
		{
			HandleError(L);
		}
	}

	virtual s32 getID()
	{
		GetNode(L, "getID");						
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IAnimatedMeshSceneNode::getID();
		}

		GetNode(L);									
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return IAnimatedMeshSceneNode::getID();
		}

		s32 ret =  (s32) lua_tonumber(L, -1);
		lua_pop(L, 1);
		return  ret;
	}

	virtual void setID(s32 ID)
	{
		GetNode(L, "setID");						
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IAnimatedMeshSceneNode::setID(ID);
		}

		GetNode(L);									
		lua_pushnumber(L, ID);						
		if(lua_pcall(L, 2, 0, 0) != 0)				
		{
			HandleError(L);
		}
	}
	
	virtual void addChild(ISceneNode* child)
	{
		GetNode(L,"addChild");						
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IAnimatedMeshSceneNode::addChild(child);
		}

		GetNode(L);									
		tolua_pushusertype(L, child, "irr::scene::ISceneNode");					
		if(lua_pcall(L, 2, 0, 0) != 0)				
		{
			HandleError(L);
		}
	}

	virtual bool removeChild(ISceneNode* child)
	{
		GetNode(L, "removeChild");				
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IAnimatedMeshSceneNode::removeChild(child);
		}

		GetNode(L);								
		tolua_pushusertype(L, child, "irr::scene::ISceneNode");					
		if(lua_pcall(L, 2, 1, 0) != 0)				
		{
			HandleError(L);
			return false;
		}

		bool ret =  lua_toboolean(L, -1) != 0;
		lua_pop(L, 1);
		return  ret;
	}

	virtual void removeAll()
	{
		GetNode(L, "removeAll");					
		if(lua_isnil(L, -1))						
		{
			lua_pop(L, 1);
			IAnimatedMeshSceneNode::removeAll();
			return;
		}

		GetNode(L);									
		if(lua_pcall(L, 1, 0, 0) != 0)				
		{
			HandleError(L);
		}
	}

	virtual void remove()
	{
		GetNode(L, "remove");						
		if(lua_isnil(L, -1))						
		{
			lua_pop(L, 1);
			IAnimatedMeshSceneNode::remove();
			return;
		}

		GetNode(L);									
		if(lua_pcall(L, 1, 0, 0) != 0)				
		{
			HandleError(L);
		}
	}

	virtual void removeAnimator(ISceneNodeAnimator* animator)
	{
		GetNode(L, "removeAnimator");				
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IAnimatedMeshSceneNode::removeAnimator(animator);
		}

		GetNode(L);									
		tolua_pushusertype(L, animator, "irr::scene::ISceneNodeAnimator");					
		if(lua_pcall(L, 2, 0, 0) != 0)				
		{
			HandleError(L);
		}
	}
	
	virtual void removeAnimators()
	{
		GetNode(L, "removeAnimators");
		if(lua_isnil(L, -1))
		{
			lua_pop(L, 1);
			IAnimatedMeshSceneNode::removeAnimators();
			return;
		}

		GetNode(L);										
		if(lua_pcall(L, 1, 0, 0) != 0)					
		{
			HandleError(L);
		}
	}

	virtual video::SMaterial& getMaterial(s32 i)
	{
		GetNode(L, "getMaterial");					
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			ret_smaterial = IAnimatedMeshSceneNode::getMaterial(i);
			return ret_smaterial;
		}

		GetNode(L);									
		lua_pushnumber(L, i);						
		if(lua_pcall(L, 2, 1, 0) != 0)				
		{
			HandleError(L);
			ret_smaterial = IAnimatedMeshSceneNode::getMaterial(i);
			return ret_smaterial;
		}

		video::SMaterial &ret = *((video::SMaterial *) tolua_tousertype(L, -1, &ret_smaterial));
		lua_pop(L, 1);
		return ret;
	}

	virtual s32 getMaterialCount()
	{
		GetNode(L, "getMaterialCount");				
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IAnimatedMeshSceneNode::getMaterialCount();
		}

		GetNode(L);									
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return IAnimatedMeshSceneNode::getMaterialCount();
		}

		s32 ret =  (s32) lua_tonumber(L, -1);
		lua_pop(L, 1);
		return  ret;
	}

	void setMaterialFlag(video::E_MATERIAL_FLAG flag, bool newvalue)
	{
		GetNode(L, "setMaterialFlag");				
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IAnimatedMeshSceneNode::setMaterialFlag(flag, newvalue);
		}

		GetNode(L);									
		lua_pushnumber(L, (lua_Number) flag);		
		lua_pushboolean(L, newvalue);				
		if(lua_pcall(L, 3, 0, 0) != 0)				
		{
			HandleError(L);
		}
	}

	void setMaterialTexture(s32 textureLayer, video::ITexture* texture)
	{
		GetNode(L, "setMaterialTexture");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IAnimatedMeshSceneNode::setMaterialTexture(textureLayer, texture);
		}

		GetNode(L);									
		lua_pushnumber(L, (lua_Number) textureLayer);		
		tolua_pushusertype(L, texture, "irr::video::ITexture");				
		if(lua_pcall(L, 3, 0, 0) != 0)				
		{
			HandleError(L);
		}
	}

	void setMaterialType(video::E_MATERIAL_TYPE newType)
	{
		GetNode(L, "setMaterialType");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IAnimatedMeshSceneNode::setMaterialType(newType);
		}

		GetNode(L);							
		lua_pushnumber(L, (lua_Number) newType);    
		if(lua_pcall(L, 2, 0, 0) != 0)				
		{
			HandleError(L);
		}
	}
	
	virtual core::vector3df getScale() const
	{
		GetNode(L, "getScale");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IAnimatedMeshSceneNode::getScale();
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return IAnimatedMeshSceneNode::getScale();
		}

		core::vector3df def = ISceneNode::getScale();
		core::vector3df *ret = (core::vector3df *) tolua_tousertype(L, -1, &def);
		lua_pop(L, 1);
		return  *ret;
	}
	
	virtual void setScale(const core::vector3df& scale)
	{
		GetNode(L, "setScale");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IAnimatedMeshSceneNode::setScale(scale);
		}

		GetNode(L);							
		tolua_pushusertype(L, (void *) &scale, "irr::core::vector3d<f32>");					
		if(lua_pcall(L, 2, 0, 0) != 0)				
		{
			HandleError(L);
		}
	}

	virtual const core::vector3df getRotation() const
	{
		GetNode(L, "getRotation");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IAnimatedMeshSceneNode::getRotation();
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return IAnimatedMeshSceneNode::getRotation();
		}

		core::vector3df def = ISceneNode::getRotation();
		core::vector3df *ret = (core::vector3df *) tolua_tousertype(L, -1, &def);
		lua_pop(L, 1);
		return  *ret;
	}

	virtual void setRotation(const core::vector3df& rotation)
	{
		GetNode(L, "setRotation");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IAnimatedMeshSceneNode::setRotation(rotation);
		}

		GetNode(L);							
		tolua_pushusertype(L, (void *) &rotation, "irr::core::vector3d<f32>");					
		if(lua_pcall(L, 2, 0, 0) != 0)				
		{
			HandleError(L);
		}
	}

	virtual const core::vector3df getPosition() const
	{
		GetNode(L, "getPosition");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return ISceneNode::getPosition();
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return ISceneNode::getPosition();
		}

		core::vector3df def = ISceneNode::getPosition();
		core::vector3df *ret = (core::vector3df *) tolua_tousertype(L, -1, &def);
		lua_pop(L, 1);
		return  *ret;
	}

	virtual void setPosition(const core::vector3df& newpos)
	{
		GetNode(L, "setPosition");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IAnimatedMeshSceneNode::setPosition(newpos);
		}

		GetNode(L);							
		tolua_pushusertype(L, (void *) &newpos, "irr::core::vector3d<f32>");					
		if(lua_pcall(L, 2, 0, 0) != 0)				
		{
			HandleError(L);
		}
	}

	virtual core::vector3df getAbsolutePosition() const
	{
		GetNode(L, "getAbsolutePosition");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IAnimatedMeshSceneNode::getAbsolutePosition();
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return IAnimatedMeshSceneNode::getAbsolutePosition();
		}

		core::vector3df def = ISceneNode::getAbsolutePosition();
		core::vector3df *ret = (core::vector3df *) tolua_tousertype(L, -1, &def);
		lua_pop(L, 1);
		return  *ret;
	}

	void setAutomaticCulling(bool enabled)
	{
		GetNode(L, "setAutomaticCulling");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IAnimatedMeshSceneNode::setAutomaticCulling(enabled);
		}

		GetNode(L);							
		lua_pushboolean(L, enabled);				
		if(lua_pcall(L, 2, 0, 0) != 0)				
		{
			HandleError(L);
		}
	}

	void setDebugDataVisible(bool visible)
	{
		GetNode(L, "setDebugDataVisible");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IAnimatedMeshSceneNode::setDebugDataVisible(visible);
		}

		GetNode(L);							
		lua_pushboolean(L, visible);				
		if(lua_pcall(L, 2, 0, 0) != 0)				
		{
			HandleError(L);
		}
	}

	bool isDebugDataVisible()
	{
		GetNode(L, "isDebugDataVisible");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IAnimatedMeshSceneNode::isDebugDataVisible();
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return IAnimatedMeshSceneNode::isDebugDataVisible();
		}

		bool ret =  lua_toboolean(L, -1) != 0;
		lua_pop(L, 1);
		return  ret;
	}

	const core::list<ISceneNode*>& getChildren() const
	{
		GetNode(L, "getChildren");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IAnimatedMeshSceneNode::getChildren();
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return IAnimatedMeshSceneNode::getChildren();
		}

		core::list<ISceneNode *> &ret = *((core::list<ISceneNode*> *) tolua_tousertype(L, -1, (void *) &(ISceneNode::getChildren())));
		lua_pop(L, 1);
		return ret;
	}

	virtual void setParent(ISceneNode* newParent)
	{
		GetNode(L, "setParent");				
		if(lua_isnil(L, -1))						
		{
			lua_pop(L, 1);
			IAnimatedMeshSceneNode::setParent(newParent);
			return;
		}

		GetNode(L);						
		tolua_pushusertype(L, (void *) newParent, "irr::scene::ISceneNode");   
		if(lua_pcall(L, 2, 0, 0) != 0)			
		{
			HandleError(L);
			return;
		}
	}

	virtual ITriangleSelector* getTriangleSelector() const
	{
		GetNode(L, "getTriangleSelector");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IAnimatedMeshSceneNode::getTriangleSelector();
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return IAnimatedMeshSceneNode::getTriangleSelector();
		}

		ITriangleSelector *ret = (ITriangleSelector *) tolua_tousertype(L, -1, (void *) ISceneNode::getTriangleSelector());
		lua_pop(L, 1);
		return  ret;
	}

	virtual void setTriangleSelector(ITriangleSelector* selector) 
	{
		GetNode(L, "setTriangleSelector");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IAnimatedMeshSceneNode::setTriangleSelector(selector);
		}

		GetNode(L);							
		tolua_pushusertype(L, selector, "irr::scene::ITriangleSelector");					
		if(lua_pcall(L, 2, 0, 0) != 0)				
		{
			HandleError(L);
		}
	}

	virtual void updateAbsolutePosition()
	{
		GetNode(L, "updateAbsolutePosition");
		if(lua_isnil(L, -1))
		{
			lua_pop(L, 1);
			IAnimatedMeshSceneNode::updateAbsolutePosition();
			return;
		}

		GetNode(L);								
		if(lua_pcall(L, 1, 0, 0) != 0)					
		{
			HandleError(L);
		}
	}

	scene::ISceneNode* getParent()
	{
		GetNode(L, "getParent");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IAnimatedMeshSceneNode::getParent();
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return IAnimatedMeshSceneNode::getParent();
		}

		scene::ISceneNode *ret = (scene::ISceneNode *) tolua_tousertype(L, -1, (void *) ISceneNode::getParent());
		lua_pop(L, 1);
		return  ret;	
	}

	virtual void setReadOnlyMaterials(bool readonly)
	{
		GetNode(L, "setReadOnlyMaterials");				
		if(lua_isnil(L, -1))						
		{
			lua_pop(L, 1);
			return;
		}

		GetNode(L);						
		tolua_pushboolean(L, readonly);
		if(lua_pcall(L, 2, 0, 0) != 0)			
		{
			HandleError(L);
			return;
		}
	}

	virtual bool isReadOnlyMaterials()
	{
		GetNode(L, "isReadOnlyMaterials");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return false;
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return false;
		}

		bool ret = tolua_toboolean(L, -1, 0) != 0;
		lua_pop(L, 1);
		return  ret;	
	}

	virtual void setMesh(IAnimatedMesh* mesh)
	{
		GetNode(L, "setMesh");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return ;
		}

		GetNode(L);							
		tolua_pushusertype(L, mesh, "irr::scene::IAnimatedMesh");					
		if(lua_pcall(L, 2, 0, 0) != 0)				
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
			IAnimatedMeshSceneNode::grab();
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
			return IAnimatedMeshSceneNode::drop();
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return IAnimatedMeshSceneNode::drop();
		}

		bool ret =  lua_toboolean(L, -1) != 0;
		lua_pop(L, 1);
		return  ret;
	}

	core::stringc get_Name()
	{
		return Name;
	}

	void set_Name(core::stringc n)
	{
		Name = n;
	}

	core::matrix4 get_AbsoluteTransformation()
	{
		return AbsoluteTransformation;
	}

	void set_AbsoluteTransformation(core::matrix4 m)
	{
		AbsoluteTransformation = m;
	}

	core::vector3df get_RelativeTranslation()
	{
		return RelativeTranslation;
	}

	void set_RelativeTranslation(core::vector3df v)
	{
		RelativeTranslation = v;
	}
	
	core::vector3df get_RelativeRotation()
	{
		return RelativeRotation;
	}

	void set_RelativeRotation(core::vector3df v)
	{
		RelativeRotation = v;
	}

	core::vector3df get_RelativeScale()
	{
		return RelativeScale;
	}

	void set_RelativeScale(core::vector3df v)
	{
		RelativeScale = v;
	}

	ISceneNode *get_Parent()
	{
		return Parent;
	}

	void set_Parent(ISceneNode *p)
	{
		Parent = p;
	}

	core::list<ISceneNode*> get_Children()
	{
		return Children;
	}

	void set_Children(core::list<ISceneNode*> c)
	{
		Children = c;
	}

	core::list<ISceneNodeAnimator*> get_Animators()
	{
		return Animators;
	}

	void set_Animators(core::list<ISceneNodeAnimator*> a)
	{
		Animators = a;
	}

	s32 get_ID()
	{
		return ID;
	}

	void set_ID(s32 id)
	{
		ID = id;
	}

	ISceneManager *get_SceneManager()
	{
		return SceneManager;
	}

	void set_SceneManager(ISceneManager *m)
	{
		SceneManager = m;
	}

	ITriangleSelector *get_TriangleSelector()
	{
		return TriangleSelector;
	}

	void set_TriangleSelector(ITriangleSelector *t)
	{
		TriangleSelector = t;
	}

	bool get_AutomaticCullingEnabled()
	{
		return AutomaticCullingEnabled;
	}

	void set_AutomaticCullingEnabled(bool b)
	{
		AutomaticCullingEnabled = b;
	}

	bool get_DebugDataVisible()
	{
		return DebugDataVisible;
	}

	void set_DebugDataVisible(bool b)
	{
		DebugDataVisible = b;
	}

	bool get_IsVisible()
	{
		return IsVisible;
	}

	void set_IsVisible(bool b)
	{
		IsVisible = b;
	}
	
	private:

	//used for reference returns
	core::aabbox3d<f32> ret_box;
	core::matrix4 ret_matrix4;
	video::SMaterial ret_smaterial;
	core::list<ISceneNode *> ret_children;

};

}
}


#endif /* _IRRLUAISCENENODE_H_ */
