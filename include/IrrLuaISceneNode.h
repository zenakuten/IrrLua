// Copyright (C) 2005-2006 Josh Turpen
// This file is part of the IrrLua Lua binding for Irrlicht.
// For conditions of distribution and use, see copyright notice in IrrLua.h

#ifndef _IRRLUAISCENENODE_H_
#define _IRRLUAISCENENODE_H_

#include "IrrLua.h"
#include "IrrLuaProxy.h"

static const char *g_SceneNodeTable = "__scenenodeproxy";

namespace irr
{
namespace scene
{

class IrrLuaISceneNode : public ISceneNode, public IrrLuaProxy {

public:
	IrrLuaISceneNode(ISceneNode *parent, ISceneManager *mgr, s32 id) : ISceneNode(parent, mgr, id), IrrLuaProxy(g_SceneNodeTable) 
	{
		Proxy = this;
	}
	virtual ~IrrLuaISceneNode() {}


	virtual void OnPreRender()
	{
		GetNode(L, "OnPreRender");					
		if(lua_isnil(L, -1))						
		{
			lua_pop(L, 1);
			ISceneNode::OnPreRender();
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
			ISceneNode::OnPostRender(timeMs);
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
			return ISceneNode::getName();
		}

		GetNode(L);		
		if(lua_pcall(L, 1, 1, 0) != 0)					
		{
			HandleError(L);
			return NULL;
		}

		char *ret = (char *) tolua_tousertype(L, -1, (void *) ISceneNode::getName());
		lua_pop(L, 1);
		return ret;
	}


	virtual void setName(const char* name)
	{
		GetNode(L, "setName");					
		if(lua_isnil(L, -1))						
		{
			lua_pop(L, 1);
			ISceneNode::setName(name);
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

	core::aabbox3d<f32> getTransformedBoundingBox() 
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
			//((core::aabbox3d<f32>)ret_box) = ISceneNode::getTransformedBoundingBox();
			//return ISceneNode::getTransformedBoundingBox();
			return ret_box;
		}

		core::aabbox3d<f32> *ret = (core::aabbox3d<f32> *) tolua_tousertype(L, -1, &ret_box);
		lua_pop(L, 1);
		return *ret;
	}

	core::matrix4& getAbsoluteTransformation()
	{
		GetNode(L,  "getAbsoluteTransformation");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			ret_matrix4 = ISceneNode::getAbsoluteTransformation();
			return ret_matrix4;
		}

		GetNode(L);									
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			ret_matrix4 = ISceneNode::getAbsoluteTransformation();
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
			return ISceneNode::getRelativeTransformation();
		}

		GetNode(L);		
		if(lua_pcall(L, 1, 1, 0) != 0)					
		{
			HandleError(L);
			return ISceneNode::getRelativeTransformation();
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
			return ISceneNode::isVisible();
		}

		GetNode(L);									
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return ISceneNode::isVisible();
		}

		bool ret = lua_toboolean(L, -1) != 0;
		lua_pop(L, 1);
		return  ret;
	}

	virtual void setVisible(bool isVisible)
	{
		GetNode(L, "setVisible");					
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return ISceneNode::setVisible(isVisible);
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
			return ISceneNode::getID();
		}

		GetNode(L);									
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return ISceneNode::getID();
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
			return ISceneNode::setID(ID);
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
			return ISceneNode::addChild(child);
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
			return ISceneNode::removeChild(child);
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
			ISceneNode::removeAll();
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
			ISceneNode::remove();
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
			return ISceneNode::removeAnimator(animator);
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
			ISceneNode::removeAnimators();
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
			ret_smaterial = ISceneNode::getMaterial(i);
			return ret_smaterial;
		}

		GetNode(L);									
		lua_pushnumber(L, i);						
		if(lua_pcall(L, 2, 1, 0) != 0)				
		{
			HandleError(L);
			ret_smaterial = ISceneNode::getMaterial(i);
			return ret_smaterial;
		}

		video::SMaterial &ret = *((video::SMaterial *) tolua_tousertype(L, -1, &ret_smaterial));
		//video::SMaterial *ret = (video::SMaterial *) tolua_tousertype(L, -1, &ret_smaterial);
		lua_pop(L, 1);
		return ret;
	}

	virtual s32 getMaterialCount()
	{
		GetNode(L, "getMaterialCount");				
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return ISceneNode::getMaterialCount();
		}

		GetNode(L);									
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return ISceneNode::getMaterialCount();
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
			return ISceneNode::setMaterialFlag(flag, newvalue);
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
			return ISceneNode::setMaterialTexture(textureLayer, texture);
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
			return ISceneNode::setMaterialType(newType);
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
			return ISceneNode::getScale();
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return ISceneNode::getScale();
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
			return ISceneNode::setScale(scale);
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
			return ISceneNode::getRotation();
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return ISceneNode::getRotation();
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
			return ISceneNode::setRotation(rotation);
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
			return ISceneNode::setPosition(newpos);
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
			return ISceneNode::getAbsolutePosition();
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return ISceneNode::getAbsolutePosition();
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
			return ISceneNode::setAutomaticCulling(enabled);
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
			return ISceneNode::setDebugDataVisible(visible);
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
			return ISceneNode::isDebugDataVisible();
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return ISceneNode::isDebugDataVisible();
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
			return ISceneNode::getChildren();
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return ISceneNode::getChildren();
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
			ISceneNode::setParent(newParent);
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
			return ISceneNode::getTriangleSelector();
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return ISceneNode::getTriangleSelector();
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
			return ISceneNode::setTriangleSelector(selector);
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
			ISceneNode::updateAbsolutePosition();
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
			return ISceneNode::getParent();
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return ISceneNode::getParent();
		}

		scene::ISceneNode *ret = (scene::ISceneNode *) tolua_tousertype(L, -1, (void *) ISceneNode::getParent());
		lua_pop(L, 1);
		return  ret;	
	}
	
	virtual void grab()
	{
		GetNode(L, "grab");				
		if(lua_isnil(L, -1))						
		{
			lua_pop(L, 1);
			ISceneNode::grab();
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
			return ISceneNode::drop();
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)				
		{
			HandleError(L);
			return IUnknown::drop();
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
