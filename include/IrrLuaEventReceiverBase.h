// Copyright (C) 2005-2006 Josh Turpen
// This file is part of the IrrLua Lua binding for Irrlicht.
// For conditions of distribution and use, see copyright notice in IrrLua.h

#ifndef _IRRLUAEVENTRECEIVERBASE_H_
#define _IRRLUAEVENTRECEIVERBASE_H_

#include "IrrLua.h"
#include "IrrLuaProxy.h"

namespace irr
{
	class IrrLuaEventReceiverBase : public IEventReceiver, public IrrLuaProxy 
	{
		public:
		
		IrrLuaEventReceiverBase(const char *ProxyTableName) : IrrLuaProxy(ProxyTableName) {Proxy = NULL;} // Base should not be proxy 
		virtual ~IrrLuaEventReceiverBase() {}

		virtual bool OnEvent(irr::SEvent event)
		{
			GetNode(L, "OnEvent");	
			if(lua_isnil(L, -1))
			{
				return false;
			}

			//create table with event union/struct and pass to event handler
			GetNode(L);														// s:  self
			lua_newtable(L);												// s:  self {}
			lua_pushstring(L, "EventType");									// s:  self {} "EventType"
			lua_pushnumber(L, (lua_Number) event.EventType);				// s:  self {} "EventType" event.EventType
			lua_settable(L, -3);											// s:  self {EventType = event.EventType}

			switch(event.EventType)
			{
				case irr::EET_KEY_INPUT_EVENT:
					//t = {
					// EventType = event.EventType,
					// KeyInput = {
					//       Char = wchar_to_char(event.KeyInput.Char),
					//       Key = event.KeyInput.Key,
					//       PressedDown = event.KeyInput.PressedDown,
					//       Shift = event.KeyInput.Shift,
					//		 Control = event.KeyInput.Control
					//       }
					// }

					lua_pushstring(L, "KeyInput");							
					lua_newtable(L);										

					char buf[2];
					buf[0] = (char) (event.KeyInput.Char & 0xFF);
					buf[1] = '\0';

					lua_pushstring(L, "Char");								
					lua_pushstring(L, buf);									
					lua_settable(L, -3);									

					lua_pushstring(L, "Key");						        
					lua_pushnumber(L, (lua_Number) event.KeyInput.Key);		
					lua_settable(L, -3);									

					lua_pushstring(L, "PressedDown");						
					lua_pushboolean(L, event.KeyInput.PressedDown);	
					lua_settable(L, -3);								

					lua_pushstring(L, "Shift");						
					lua_pushboolean(L, event.KeyInput.Shift);	
					lua_settable(L, -3);								

					lua_pushstring(L, "Control");						
					lua_pushboolean(L, event.KeyInput.Control);	
					lua_settable(L, -3);	
					break;

				case irr::EET_GUI_EVENT:
					//t = {
					// EventType = event.EventType,
					// GUIEvent = {
					//       Caller = event.GUIEvent.Caller,
					//       EventType = event.GUIEvent.EventType
					//       }
					// }
					lua_pushstring(L, "GUIEvent");					
					lua_newtable(L);								

					lua_pushstring(L, "Caller");
					tolua_pushusertype(L, (void *) event.GUIEvent.Caller, "irr::gui::IGUIElement");
					lua_settable(L, -3);									

					lua_pushstring(L, "EventType");						        
					lua_pushnumber(L, (lua_Number) event.GUIEvent.EventType);		
					lua_settable(L, -3);									
					break;

				case irr::EET_MOUSE_INPUT_EVENT:
					//t = {
					// EventType = event.EventType,
					// MouseInput = {
					//       X = event.MouseInput.X,
					//       Y = event.MouseInput.Y, 
					//       Wheel = event.MouseInput.Wheel,
					//       Event = event.MouseInput.Event, 
					//       }
					// }
					lua_pushstring(L, "MouseInput");					
					lua_newtable(L);								

					lua_pushstring(L, "X");
					lua_pushnumber(L, (lua_Number) event.MouseInput.X);		
					lua_settable(L, -3);									

					lua_pushstring(L, "Y");
					lua_pushnumber(L, (lua_Number) event.MouseInput.Y);		
					lua_settable(L, -3);									

					lua_pushstring(L, "Wheel");
					lua_pushnumber(L, (lua_Number) event.MouseInput.Wheel);		
					lua_settable(L, -3);									

					lua_pushstring(L, "Event");
					lua_pushnumber(L, (lua_Number) event.MouseInput.Event);
					lua_settable(L, -3);									
					break;

				case irr::EET_LOG_TEXT_EVENT:
					//t = {
					// EventType = event.EventType,
					// LogEvent = {
					//       Text = event.LogEvent.Text,
					//       Level = event.LogEvent.Level
					//       }
					// }

					lua_pushstring(L, "LogEvent");					
					lua_newtable(L);								

					lua_pushstring(L, "Text");
					lua_pushstring(L, event.LogEvent.Text);
					lua_settable(L, -3);									

					lua_pushstring(L, "Level");
					lua_pushnumber(L, (lua_Number) event.LogEvent.Level);		
					lua_settable(L, -3);									
					break;

				case irr::EET_USER_EVENT:
					//t = {
					// EventType = event.EventType,
					// UserEvent = {
					//       UserData1 = event.UserEvent.UserData1,
					//       UserData2 = event.UserEvent.UserData2,
					//       UserData3 = event.UserEvent.UserData3
					//       }
					// }
					lua_pushstring(L, "UserEvent");					
					lua_newtable(L);								

					lua_pushstring(L, "UserData1");
					lua_pushnumber(L, (lua_Number) event.UserEvent.UserData1);
					lua_settable(L, -3);									

					lua_pushstring(L, "UserData2");
					lua_pushnumber(L, (lua_Number) event.UserEvent.UserData2);		
					lua_settable(L, -3);									

					lua_pushstring(L, "UserData3");
					lua_pushnumber(L, (lua_Number) event.UserEvent.UserData3);		
					lua_settable(L, -3);									
					break;
			}

			lua_settable(L, -3); // s:  self {EventType = event.EventType, KeyInput = {Char = event.KeyInput.Char, Key = event.KeyInput.Key, ...}}
			if(lua_pcall(L, 2, 1, 0) != 0)
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
	};
}

#endif /* _IRRLUAEVENTRECEIVERBASE_H_ */
