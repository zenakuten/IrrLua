-- Copyright (C) 2005-2006 Josh Turpen, Nikolaus Gebhardt
-- This file is part of the IrrLua Lua binding for Irrlicht.
-- For conditions of distribution and use, see copyright notice in IrrLua.h

-- gross, I know, but if you have a better/easier way, tell me :)
--
-- This file is NOT needed when using Lua 5.1.  
--
-- jjt

function _IrrLua_loadmodule()

	local dlload = loadlib
	if _VERSION == "Lua 5.1" then
		dlload = package.loadlib
	end
	
	if _IrrLua_module then 
		return true
	end

	_IrrLua_module = dlload("IrrLua", "luaopen_IrrLua")
	if _IrrLua_module then
		return _IrrLua_module()
	end

	_IrrLua_module = dlload("./libIrrLua.so", "luaopen_IrrLua")
	if _IrrLua_module then
		return _IrrLua_module()
	end

	_IrrLua_module = dlload("/usr/local/lib/libIrrLua.so", "luaopen_IrrLua")
	if _IrrLua_module then
		return _IrrLua_module()
	end

	_IrrLua_module = dlload("/usr/lib/libIrrLua.so", "luaopen_IrrLua")
	if _IrrLua_module then
		return _IrrLua_module()
	end

	print("Error loading module")
	return false
end

_IrrLua_loadmodule()

