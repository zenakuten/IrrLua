// Copyright (C) 2005-2006 Josh Turpen
// This file is part of the IrrLua Lua binding for Irrlicht.
// For conditions of distribution and use, see copyright notice in IrrLua.h

#ifndef _IRRLUAIGUIELEMENT_H_
#define _IRRLUAIGUIELEMENT_H_

#include "IrrLua.h"
#include "IrrLuaProxy.h"

static const char *g_GuiElementTable = "__iguielementproxy";

namespace irr
{
namespace gui
{
	class IrrLuaIGUIElement : public IGUIElement, public IrrLuaEventReceiverBase {
	public:
	IrrLuaIGUIElement(EGUI_ELEMENT_TYPE type, IGUIEnvironment* environment, IGUIElement* parent,
		s32 id, core::rect<s32> rectangle) : IGUIElement(type, environment, parent, id, rectangle), IrrLuaEventReceiverBase(g_GuiElementTable) { Proxy = this; }
	virtual ~IrrLuaIGUIElement() {}

	IGUIElement* getParent()
	{
		GetNode(L, "getParent");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IGUIElement::getParent();
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)		
		{
			HandleError(L);
			return IGUIElement::getParent();
		}

		gui::IGUIElement *ret = (gui::IGUIElement *) tolua_tousertype(L, -1, (void *) IGUIElement::getParent());
		lua_pop(L, 1);
		return  ret;	
	}

	core::rect<s32> getRelativePosition()
	{
		GetNode(L, "getRelativePosition");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IGUIElement::getRelativePosition();
		}

		GetNode(L);		
		if(lua_pcall(L, 1, 1, 0) != 0)					
		{
			HandleError(L);
			return IGUIElement::getRelativePosition();
		}

		core::rect<s32> def = IGUIElement::getRelativePosition();
		core::rect<s32> *ret = (core::rect<s32> *) tolua_tousertype(L, -1, &def);
		lua_pop(L, 1);
		return  *ret;
	}

	void setRelativePosition(const core::rect<s32>& r)
	{
		GetNode(L, "setRelativePosition");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IGUIElement::setRelativePosition(r);
		}

		GetNode(L);							
		tolua_pushusertype(L, (void *) &r, "irr::core::rect<s32>");					
		if(lua_pcall(L, 2, 0, 0) != 0)			
		{
			HandleError(L);
		}
	}

	core::rect<s32> getAbsolutePosition()
	{
		GetNode(L, "getAbsolutePosition");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IGUIElement::getAbsolutePosition();
		}

		GetNode(L);		
		if(lua_pcall(L, 1, 1, 0) != 0)					
		{
			HandleError(L);
			return IGUIElement::getAbsolutePosition();
		}

		core::rect<s32> def = IGUIElement::getAbsolutePosition();
		core::rect<s32> *ret = (core::rect<s32> *) tolua_tousertype(L, -1, &def);
		lua_pop(L, 1);
		return  *ret;
	}

	virtual void updateAbsolutePosition()
	{
		GetNode(L, "updateAbsolutePosition");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IGUIElement::updateAbsolutePosition();
		}

		GetNode(L);		
		if(lua_pcall(L, 1, 0, 0) != 0)					
		{
			HandleError(L);
		}
	}

	IGUIElement* getElementFromPoint(const core::position2d<s32>& point)
	{
		GetNode(L, "getElementFromPoint");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IGUIElement::getElementFromPoint(point);
		}

		GetNode(L);	
		tolua_pushusertype(L, (void *) &point, "irr::core::position2d<s32>");					
		if(lua_pcall(L, 2, 1, 0) != 0)		
		{
			HandleError(L);
			return IGUIElement::getElementFromPoint(point);
		}

		gui::IGUIElement *ret = (gui::IGUIElement *) tolua_tousertype(L, -1, (void *) IGUIElement::getElementFromPoint(point));
		lua_pop(L, 1);
		return  ret;
	}

	virtual void addChild(IGUIElement* child)
	{
		GetNode(L, "addChild");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IGUIElement::addChild(child);
		}

		GetNode(L);		
		tolua_pushusertype(L, (void *) &child, "irr::gui::IGUIElement");					
		if(lua_pcall(L, 2, 0, 0) != 0)					
		{
			HandleError(L);
		}
	}

	virtual void removeChild(IGUIElement* child)
	{
		GetNode(L, "removeChild");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IGUIElement::removeChild(child);
		}

		GetNode(L);		
		tolua_pushusertype(L, (void *) &child, "irr::gui::IGUIElement");					
		if(lua_pcall(L, 2, 0, 0) != 0)					
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
			return IGUIElement::remove();
		}

		GetNode(L);		
		if(lua_pcall(L, 1, 0, 0) != 0)					
		{
			HandleError(L);
		}
	}

	virtual void draw()
	{
		GetNode(L, "draw");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IGUIElement::draw();
		}

		GetNode(L);		
		if(lua_pcall(L, 1, 0, 0) != 0)					
		{
			HandleError(L);
		}
	}

	virtual void move(core::position2d<s32> absoluteMovement)
	{
		GetNode(L, "move");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IGUIElement::move(absoluteMovement);
		}

		GetNode(L);		
		tolua_pushusertype(L, (void *) &absoluteMovement, "irr::core::position2d<s32>");					
		if(lua_pcall(L, 2, 0, 0) != 0)					
		{
			HandleError(L);
		}
	}

	virtual bool isVisible()
	{
		GetNode(L, "isVisible");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IGUIElement::isVisible();
		}

		GetNode(L);							
		if(lua_pcall(L, 1, 1, 0) != 0)		
		{
			HandleError(L);
			return IGUIElement::isVisible();
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
			return IGUIElement::setVisible(isVisible);
		}

		GetNode(L);					
		lua_pushboolean(L, isVisible);	
		if(lua_pcall(L, 2, 0, 0) != 0)	
		{
			HandleError(L);
		}
	}

	virtual bool isEnabled()
	{
		GetNode(L, "isEnabled");	
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IGUIElement::isEnabled();
		}

		GetNode(L);				
		if(lua_pcall(L, 1, 1, 0) != 0)		
		{
			HandleError(L);
			return IGUIElement::isEnabled();
		}

		bool ret =  lua_toboolean(L, -1) != 0;
		lua_pop(L, 1);
		return  ret;
	}

	virtual void setEnabled(bool enabled)
	{
		GetNode(L, "setEnabled");		
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IGUIElement::setEnabled(enabled);
		}

		GetNode(L);					
		lua_pushboolean(L, enabled);	
		if(lua_pcall(L, 2, 0, 0) != 0)	
		{
			HandleError(L);
		}
	}

	virtual void setText(const wchar_t* text)
	{
		GetNode(L, "setText");		
		if(lua_isnil(L, -1))						
		{
			lua_pop(L, 1);
			IGUIElement::setText(text);
			return;
		}

		GetNode(L);				
		tolua_pushusertype(L, (void *) text, "wchar_t");
		if(lua_pcall(L, 2, 0, 0) != 0)				
		{
			HandleError(L);
			return;
		}
	}

	virtual const wchar_t* getText()
	{
		GetNode(L, "getText");
		if(lua_isnil(L, -1))						
		{
			lua_pop(L, 1);
			return IGUIElement::getText();
		}

		GetNode(L);		
		if(lua_pcall(L, 1, 1, 0) != 0)
		{
			HandleError(L);
			return NULL;
		}

		wchar_t *ret = (wchar_t *) tolua_tousertype(L, -1, (void *) IGUIElement::getText());
		lua_pop(L, 1);
		return ret;
	}

	virtual s32 getID()
	{
		GetNode(L, "getID");		
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IGUIElement::getID();
		}

		GetNode(L);				
		if(lua_pcall(L, 1, 1, 0) != 0)	
		{
			HandleError(L);
			return IGUIElement::getID();
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
			return IGUIElement::setID(ID);
		}

		GetNode(L);				
		lua_pushnumber(L, ID);
		if(lua_pcall(L, 2, 0, 0) != 0)	
		{
			HandleError(L);
		}
	}
	virtual bool OnEvent(SEvent event)
	{
		return IrrLuaEventReceiverBase::OnEvent(event);
	}
	/*
	handled by base class now
	virtual bool OnEvent(SEvent event)
	{
		switch(event.EventType)
		{
			case irr::EET_KEY_INPUT_EVENT:
				return OnKeyEvent(event);
			case irr::EET_GUI_EVENT:
				return OnGuiEvent(event);
			case irr::EET_MOUSE_INPUT_EVENT:
				return OnMouseInputEvent(event);
			case irr::EET_LOG_TEXT_EVENT:
				return OnLogTextEvent(event);
			case irr::EET_USER_EVENT:
				return OnUserEvent(event);
		}

		return false;
	}

	bool OnKeyEvent(irr::SEvent event)
	{
		GetNode(L, "OnKeyEvent");
		if(lua_isnil(L, -1))
		{
			lua_pop(L, 1);
			return false;
		}
		
		GetNode(L);
		lua_pushnumber(L, (lua_Number) event.KeyInput.Key);
		lua_pushboolean(L, event.KeyInput.PressedDown);
		lua_pushboolean(L, event.KeyInput.Shift);
		lua_pushboolean(L, event.KeyInput.Control); 
		
		if(lua_pcall(L, 5, 1,0) != 0)
		{
			HandleError(L);
			return false;
		}

		if(!lua_isboolean(L,-1))
		{
			lua_pop(L, 1);
			return false;
		}

		bool ret = lua_toboolean(L, -1) != 0;
		lua_pop(L, 1);

		return ret;
	}

	bool OnGuiEvent(irr::SEvent event)
	{
		GetNode(L, "OnGuiEvent");
		if(lua_isnil(L, -1))
		{
			lua_pop(L, 1);
			return false;
		}
		
		GetNode(L);
		lua_pushnumber(L, (lua_Number) event.GUIEvent.EventType);
		tolua_pushusertype(L, (void *) event.GUIEvent.Caller, "irr::gui::IGUIElement");

		if(lua_pcall(L, 3, 1, 0) != 0)
		{
			HandleError(L);
			return false;
		}

		if(!lua_isboolean(L,-1))
		{
			lua_pop(L, 1);
			return false;
		}

		bool ret = lua_toboolean(L, -1) != 0;
		lua_pop(L, 1);

		return ret;
	}

	bool OnMouseInputEvent(irr::SEvent event)
	{
		GetNode(L, "OnMouseInputEvent");
		if(lua_isnil(L, -1))
		{
			lua_pop(L, 1);
			return false;
		}
	
		GetNode(L);
		lua_pushnumber(L, (lua_Number) event.MouseInput.Event);
		lua_pushnumber(L, (lua_Number) event.MouseInput.X);
		lua_pushnumber(L, (lua_Number) event.MouseInput.Y);
		lua_pushnumber(L, (lua_Number) event.MouseInput.Wheel);

		if(lua_pcall(L, 5, 1,0) != 0)
		{
			HandleError(L);
			return false;
		}

		if(!lua_isboolean(L,-1))
		{
			lua_pop(L, 1);
			return false;
		}

		bool ret = lua_toboolean(L, -1) != 0;
		lua_pop(L, 1);

		return ret;
	}

	bool OnLogTextEvent(irr::SEvent event)
	{
		GetNode(L, "OnLogTextEvent");
		if(lua_isnil(L, -1))
		{
			lua_pop(L, 1);
			return false;
		}
	
		GetNode(L);
		lua_pushnumber(L, (lua_Number) event.LogEvent.Level);
		lua_pushstring(L,  event.LogEvent.Text);

		if(lua_pcall(L, 3, 1, 0) != 0)
		{
			HandleError(L);
			return false;
		}

		if(!lua_isboolean(L,-1))
		{
			lua_pop(L, 1);
			return false;
		}

		bool ret = lua_toboolean(L, -1) != 0;
		lua_pop(L, 1);

		return ret;
	}

	bool OnUserEvent(irr::SEvent event)
	{
		GetNode(L, "OnUserEvent");
		if(lua_isnil(L, -1))
		{
			lua_pop(L, 1);
			return false;
		}

		GetNode(L);
		lua_pushnumber(L, (lua_Number) event.UserEvent.UserData1);
		lua_pushnumber(L, (lua_Number) event.UserEvent.UserData2);
		lua_pushnumber(L, (lua_Number) event.UserEvent.UserData3);

		if(lua_pcall(L, 4, 1, 0) != 0)
		{
			HandleError(L);
			return false;
		}

		if(!lua_isboolean(L,-1))
		{
			lua_pop(L, 1);
			return false;
		}

		bool ret = lua_toboolean(L, -1) != 0;
		lua_pop(L, 1);

		return ret;
	}

	*/

	virtual bool bringToFront(IGUIElement* element)
	{
		GetNode(L, "bringToFront");			
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IGUIElement::bringToFront(element);
		}

		GetNode(L);	
		tolua_pushusertype(L, (void *) &element, "irr::gui::IGUIElement");					
		if(lua_pcall(L, 2, 1, 0) != 0)		
		{
			HandleError(L);
			return IGUIElement::bringToFront(element);
		}

		bool ret = lua_toboolean(L, -1) != 0;
		lua_pop(L, 1);
		return  ret;
	}

	virtual const core::list<IGUIElement*>& getChildren() const
	{
		GetNode(L, "getChildren");		
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IGUIElement::getChildren();
		}

		GetNode(L);					
		if(lua_pcall(L, 1, 1, 0) != 0)		
		{
			HandleError(L);
			return IGUIElement::getChildren();
		}

		core::list<IGUIElement *> &ret = *((core::list<IGUIElement*> *) tolua_tousertype(L, -1, (void *) &(IGUIElement::getChildren())));
		lua_pop(L, 1);
		return ret;	
	}

	virtual IGUIElement* getElementFromId(s32 id, bool searchchildren=false) const
	{
		GetNode(L, "getElementFromId");
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IGUIElement::getElementFromId(id, searchchildren);
		}

		GetNode(L);					
		lua_pushnumber(L, (lua_Number) id);
		lua_pushboolean(L, searchchildren);
		if(lua_pcall(L, 3, 1, 0) != 0)			
		{
			HandleError(L);
			return IGUIElement::getElementFromId(id, searchchildren);
		}

		IGUIElement *ret = (IGUIElement *) tolua_tousertype(L, -1, (void *) IGUIElement::getElementFromId(id, searchchildren));
		lua_pop(L, 1);
		return ret;	
	}

	EGUI_ELEMENT_TYPE getType()
	{
		GetNode(L, "getType");				
		if(lua_isnil(L, -1))									
		{
			lua_pop(L, 1);
			return IGUIElement::getType();
		}

		GetNode(L);						
		if(lua_pcall(L, 1, 1, 0) != 0)	
		{
			HandleError(L);
			return IGUIElement::getType();
		}

		s32 ret = (s32) lua_tonumber(L, -1);
		lua_pop(L, 1);
		return  (EGUI_ELEMENT_TYPE) ret;
	}
	
	virtual void grab()
	{
		GetNode(L, "grab");				
		if(lua_isnil(L, -1))						
		{
			lua_pop(L, 1);
			IUnknown::grab();
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
			return IUnknown::drop();
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

	///////////////////////////////////////////////
	// Protected member access
	core::list<IGUIElement*> get_Children()
	{
		return Children;
	}

	void set_Children(core::list<IGUIElement*> c)
	{
		Children = c;
	}

	IGUIElement* get_Parent()
	{
		return Parent;
	}

	void set_Parent(IGUIElement *p)
	{
		Parent = p;
	}

	core::rect<s32> get_RelativeRect()
	{
		return RelativeRect;
	}

	void set_RelativeRect(core::rect<s32> r)
	{
		RelativeRect = r;
	}

	core::rect<s32> get_AbsoluteRect()
	{
		return AbsoluteRect;
	}

	void set_AbsoluteRect(core::rect<s32> r)
	{
		AbsoluteRect = r;
	}

	core::rect<s32> get_AbsoluteClippingRect()
	{
		return AbsoluteClippingRect;
	}

	void set_AbsoluteClippingRect(core::rect<s32> r)
	{
		AbsoluteClippingRect = r;
	}

	bool get_IsVisible()
	{
		return IsVisible;
	}

	void set_IsVisible(bool b)
	{
		IsVisible = b;
	}

	bool get_IsEnabled()
	{
		return IsEnabled;
	}

	void set_IsEnabled(bool b)
	{
		IsEnabled = b;
	}

	std::string get_Text()
	{
		return std::string(core::stringc(Text.c_str()).c_str());
	}

	void set_Text(std::string s)
	{
		Text = core::stringw(s.c_str());
	}

	s32 get_ID()
	{
		return ID;
	}

	void set_ID(s32 id)
	{
		ID = id;
	}

	IGUIEnvironment* get_Environment()
	{
		return Environment;
	}

	void set_Environment(IGUIEnvironment *e)
	{
		Environment = e;
	}

	EGUI_ELEMENT_TYPE get_Type()
	{
		return Type;
	}

	void set_Type(EGUI_ELEMENT_TYPE t)
	{
		Type = t;
	}

};

}
}

#endif /* _IRRLUAGUIELEMENT_H_ */
