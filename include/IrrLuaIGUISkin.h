// Copyright (C) 2002-2005, 2006 Josh Turpen, Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef _IRRLUAIGUISKIN_H_
#define _IRRLUAIGUISKIN_H_

#include "IrrLua.h"
#include "IrrLuaProxy.h"

static const char *g_IGUISkinProxyTable = "__iguiskinproxy";

namespace irr
{
namespace gui
{

	//! A skin modifies the look of the GUI elements.
	class IrrLuaIGUISkin : public IGUISkin, public IrrLuaProxy
	{
		public:

		IrrLuaIGUISkin() : IrrLuaProxy(g_IGUISkinProxyTable) {Proxy = this;}
		~IrrLuaIGUISkin() {}

		virtual video::SColor getColor(EGUI_DEFAULT_COLOR color) 
		{
			GetNode(L, "getColor");			
			if(lua_isnil(L, -1))									
			{
				lua_pop(L, 1);
				return ret_color;
			}

			GetNode(L);		
			lua_pushnumber(L, (lua_Number) color);
			if(lua_pcall(L, 2, 1, 0) != 0)					
			{
				HandleError(L);
				return ret_color;
			}

			video::SColor *ret = (video::SColor *) tolua_tousertype(L, -1, (void *) &ret_color);
			lua_pop(L, 1);
			return  *ret;
		}

		virtual void setColor(EGUI_DEFAULT_COLOR which, video::SColor newColor)
		{
			GetNode(L, "setColor");			
			if(lua_isnil(L, -1))									
			{
				lua_pop(L, 1);
				return;
			}

			GetNode(L);		
			lua_pushnumber(L, (lua_Number) which);
			tolua_pushusertype(L, (void *) &newColor, "irr::video::SColor");
			if(lua_pcall(L, 3, 0, 0) != 0)					
			{
				HandleError(L);
				return;
			}
		}		 

		virtual s32 getSize(EGUI_DEFAULT_SIZE size) 
		{
			GetNode(L, "getSize");			
			if(lua_isnil(L, -1))									
			{
				lua_pop(L, 1);
				return 0;
			}

			GetNode(L);		
			lua_pushnumber(L, (lua_Number) size);
			if(lua_pcall(L, 2, 1, 0) != 0)					
			{
				HandleError(L);
				return 0;
			}

			s32 ret = (s32) lua_tonumber(L, -1);
			lua_pop(L, 1);
			return  ret;
		}

		virtual const wchar_t* getDefaultText(EGUI_DEFAULT_TEXT text) 
		{
			GetNode(L, "getDefaultText");			
			if(lua_isnil(L, -1))									
			{
				lua_pop(L, 1);
				return NULL;
			}

			GetNode(L);		
			lua_pushnumber(L, (lua_Number) text);
			if(lua_pcall(L, 2, 1, 0) != 0)					
			{
				HandleError(L);
				return NULL;
			}

			wchar_t *ret = (wchar_t *) tolua_tousertype(L, -1, NULL);
			lua_pop(L, 1);
			return  ret;
		}

		virtual void setDefaultText(EGUI_DEFAULT_TEXT which, const wchar_t* newText) 
		{
			GetNode(L, "setDefaultText");			
			if(lua_isnil(L, -1))									
			{
				lua_pop(L, 1);
				return;
			}

			GetNode(L);		
			lua_pushnumber(L, (lua_Number) which);
			tolua_pushusertype(L, (void *) newText, "wchar_t");
			if(lua_pcall(L, 3, 0, 0) != 0)					
			{
				HandleError(L);
				return;
			}
		}

		virtual void setSize(EGUI_DEFAULT_SIZE which, s32 size) 
		{
			GetNode(L, "setSize");			
			if(lua_isnil(L, -1))									
			{
				lua_pop(L, 1);
				return;
			}

			GetNode(L);		
			lua_pushnumber(L, (lua_Number) which);
			lua_pushnumber(L, (lua_Number) size);
			if(lua_pcall(L, 3, 0, 0) != 0)					
			{
				HandleError(L);
				return;
			}
		}

		virtual IGUIFont* getFont() 
		{
			GetNode(L, "getFont");			
			if(lua_isnil(L, -1))									
			{
				lua_pop(L, 1);
				return NULL;
			}

			GetNode(L);		
			if(lua_pcall(L, 1, 1, 0) != 0)					
			{
				HandleError(L);
				return NULL;
			}

			IGUIFont *ret = (IGUIFont *) tolua_tousertype(L, -1, NULL);
			lua_pop(L, 1);
			return  ret;
		}

		virtual void setFont(IGUIFont* font) 
		{
			GetNode(L, "setFont");			
			if(lua_isnil(L, -1))									
			{
				lua_pop(L, 1);
				return;
			}

			GetNode(L);		
			tolua_pushusertype(L, (void *) font, "irr::gui::IGUIFont");
			if(lua_pcall(L, 2, 0, 0) != 0)					
			{
				HandleError(L);
				return;
			}
		}

		virtual void draw3DButtonPaneStandard(IGUIElement* element, const core::rect<s32>& rect, const core::rect<s32>* clip=0) 
		{
			GetNode(L, "draw3DButtonPaneStandard");			
			if(lua_isnil(L, -1))									
			{
				lua_pop(L, 1);
				return;
			}

			GetNode(L);		
			tolua_pushusertype(L, (void *) element, "irr::gui::IGUIElement");
			tolua_pushusertype(L, (void *) &rect, "irr::core::rect<s32>");
			tolua_pushusertype(L, (void *) clip, "irr::core::rect<s32>");
			if(lua_pcall(L, 4, 0, 0) != 0)					
			{
				HandleError(L);
				return;
			}
		}

		virtual void draw3DButtonPanePressed(IGUIElement* element, const core::rect<s32>& rect, const core::rect<s32>* clip=0)
		{
			GetNode(L, "draw3DButtonPanePressed");			
			if(lua_isnil(L, -1))									
			{
				lua_pop(L, 1);
				return;
			}

			GetNode(L);		
			tolua_pushusertype(L, (void *) element, "irr::gui::IGUIElement");
			tolua_pushusertype(L, (void *) &rect, "irr::core::rect<s32>");
			tolua_pushusertype(L, (void *) clip, "irr::core::rect<s32>");
			if(lua_pcall(L, 4, 0, 0) != 0)					
			{
				HandleError(L);
				return;
			}
		}

		virtual void draw3DSunkenPane(IGUIElement* element, video::SColor bgcolor, bool flat, bool fillBackGround, const core::rect<s32>& rect, const core::rect<s32>* clip=0)
		{
			GetNode(L, "draw3DSunkenPane");			
			if(lua_isnil(L, -1))									
			{
				lua_pop(L, 1);
				return;
			}

			GetNode(L);		
			tolua_pushusertype(L, (void *) element, "irr::gui::IGUIElement");
			tolua_pushusertype(L, (void *) &bgcolor, "irr::video::SColor");
			lua_pushboolean(L, flat);
			lua_pushboolean(L, fillBackGround);
			tolua_pushusertype(L, (void *) &rect, "irr::core::rect<s32>");
			tolua_pushusertype(L, (void *) clip, "irr::core::rect<s32>");
			if(lua_pcall(L, 7, 0, 0) != 0)					
			{
				HandleError(L);
				return;
			}
		}

		virtual core::rect<s32> draw3DWindowBackground(IGUIElement* element, bool drawTitleBar, video::SColor titleBarColor, const core::rect<s32>& rect, const core::rect<s32>* clip=0)
		{
			GetNode(L, "draw3DWindowBackground");			
			if(lua_isnil(L, -1))									
			{
				lua_pop(L, 1);
				return ret_rect;
			}

			GetNode(L);		
			tolua_pushusertype(L, (void *) element, "irr::gui::IGUIElement");
			lua_pushboolean(L, drawTitleBar);
			tolua_pushusertype(L, (void *) &titleBarColor, "irr::video::SColor");
			tolua_pushusertype(L, (void *) &rect, "irr::core::rect<s32>");
			tolua_pushusertype(L, (void *) clip, "irr::core::rect<s32>");
			if(lua_pcall(L, 6, 1, 0) != 0)					
			{
				HandleError(L);
				return ret_rect;
			}

			core::rect<s32> *ret = (core::rect<s32> *) tolua_tousertype(L, -1, (void *) &ret_rect);
			lua_pop(L, 1);
			return  *ret;
		}

		virtual void draw3DMenuPane(IGUIElement* element, const core::rect<s32>& rect, const core::rect<s32>* clip=0)
		{
			GetNode(L, "draw3DMenuPane");			
			if(lua_isnil(L, -1))									
			{
				lua_pop(L, 1);
				return;
			}

			GetNode(L);		
			tolua_pushusertype(L, (void *) element, "irr::gui::IGUIElement");
			tolua_pushusertype(L, (void *) &rect, "irr::core::rect<s32>");
			tolua_pushusertype(L, (void *) clip, "irr::core::rect<s32>");
			if(lua_pcall(L, 4, 0, 0) != 0)					
			{
				HandleError(L);
				return;
			}
		}

		virtual void draw3DToolBar(IGUIElement* element, const core::rect<s32>& rect, const core::rect<s32>* clip=0)
		{
			GetNode(L, "draw3DToolBar");			
			if(lua_isnil(L, -1))									
			{
				lua_pop(L, 1);
				return;
			}

			GetNode(L);		
			tolua_pushusertype(L, (void *) element, "irr::gui::IGUIElement");
			tolua_pushusertype(L, (void *) &rect, "irr::core::rect<s32>");
			tolua_pushusertype(L, (void *) clip, "irr::core::rect<s32>");
			if(lua_pcall(L, 4, 0, 0) != 0)					
			{
				HandleError(L);
				return;
			}
		}

		virtual void draw3DTabButton(IGUIElement* element, bool active, const core::rect<s32>& rect, const core::rect<s32>* clip=0)
		{
			GetNode(L, "draw3DTabButton");			
			if(lua_isnil(L, -1))									
			{
				lua_pop(L, 1);
				return;
			}

			GetNode(L);		
			tolua_pushusertype(L, (void *) element, "irr::gui::IGUIElement");
			lua_pushboolean(L, active);
			tolua_pushusertype(L, (void *) &rect, "irr::core::rect<s32>");
			tolua_pushusertype(L, (void *) clip, "irr::core::rect<s32>");
			if(lua_pcall(L, 5, 0, 0) != 0)					
			{
				HandleError(L);
				return;
			}
		}

		virtual void draw3DTabBody(IGUIElement* element, bool border, bool background, const core::rect<s32>& rect, const core::rect<s32>* clip=0)
		{
			GetNode(L, "draw3DTabBody");			
			if(lua_isnil(L, -1))									
			{
				lua_pop(L, 1);
				return;
			}

			GetNode(L);		
			tolua_pushusertype(L, (void *) element, "irr::gui::IGUIElement");
			lua_pushboolean(L, border);
			lua_pushboolean(L, background);
			tolua_pushusertype(L, (void *) &rect, "irr::core::rect<s32>");
			tolua_pushusertype(L, (void *) clip, "irr::core::rect<s32>");
			if(lua_pcall(L, 6, 0, 0) != 0)					
			{
				HandleError(L);
				return;
			}
		}

		//////////////////////////////////
		//IUnknown
		
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
				return;
			}
			
		}

		virtual bool drop()
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

			bool ret = lua_toboolean(L, -1) != 0;
			lua_pop(L, 1);
			return ret;
		}

	private:
		irr::video::SColor ret_color;
		irr::core::rect<s32> ret_rect;

	};


} // end namespace gui
} // end namespace irr

#endif

