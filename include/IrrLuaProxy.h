// Copyright (C) 2005-2006 Josh Turpen
// This file is part of the IrrLua Lua binding for Irrlicht.
// For conditions of distribution and use, see copyright notice in IrrLua.h

#ifndef _IRRLUAPROXY_H_
#define _IRRLUAPROXY_H_

#include "lua.h"
#include "IrrLuaState.h"

class IrrLuaProxy {

	public:
	IrrLuaProxy(const char *c) : ProxyTable(c) {L = IrrLuaGetState(); Proxy = NULL;}
	virtual ~IrrLuaProxy() 
	{
		lua_getglobal(L, "irr");					// stack: irr
		lua_pushstring(L, ProxyTable);				// stack: irr   "ProxyTable"
		lua_rawget(L, -2);							// stack: irr   irr.ProxyTable
		lua_remove(L, -2);							// stack: irr.ProxyTable
		lua_pushlightuserdata(L, Proxy);			// stack: irr.ProxyTable   Key
		lua_pushnil(L);								// stack: irr.ProxyTable   Key nil
		lua_rawset(L, -3);
		lua_pop(L, 1);
	}
	void *GetProxy() const
	{
		return Proxy;
	}

	protected:
	void *Proxy;
	lua_State *L;
	
	lua_State *GetNode(lua_State *state, char *n=NULL) const
	{
		lua_getglobal(state, "irr");					// stack: irr
		lua_pushstring(state, ProxyTable);				// stack: irr   "ProxyTable"
		lua_rawget(state, -2);							// stack: irr   irr.ProxyTable
		lua_pushlightuserdata(state, Proxy);			// stack: irr   irr.ProxyTable   Key
		lua_rawget(state, -2);							// stack: irr   irr.ProxyTable   irr.ProxyTable[Key]
		lua_remove(state, -2);							// stack: irr   irr.ProxyTable[Key]
		lua_remove(state, -2);							// stack: irr.ProxyTable[Key]
		if(!lua_istable(state, -1))
		{
			lua_pop(L, 1);
			lua_pushstring(state, "Error in function GetNode(): invalid proxy");
			lua_error(state);
			return NULL; //unreachable
		}
		if(n)
		{
			lua_pushstring(state, n);					// irr.ProxyTable[Key]   n
			lua_rawget(state, -2);						// irr.ProxyTable[Key]   irr.ProxyTable[Key].n
			lua_remove(state, -2);						// irr.ProxyTable[Key].n
		}

		return state;
	}

	void HandleError(lua_State *state) const
	{
		if(lua_isstring(state, -1))
		{
			lua_error(state);
		}
		else
		{
			lua_pop(L, 1);
		}
	}
	
	void warn(char *m) const
	{
		fprintf(stderr, "%s", m);
	}

	private:
	const char *ProxyTable;
};

#endif /* _IRRLUAPROXY_H_ */
