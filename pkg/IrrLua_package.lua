-- Copyright (C) 2005-2006 Josh Turpen, Nikolaus Gebhardt
-- This file is part of the IrrLua Lua binding for Irrlicht.
-- For conditions of distribution and use, see copyright notice in IrrLua.h

-- gross, I know, but if you have a better/easier way, tell me :)
-- jjt

function _IrrLua_loadmodule()
	
	if _IrrLua_module then 
		return true
	end

	_IrrLua_module = loadlib("IrrLua", "IrrLua_open")
	if _IrrLua_module then
		return _IrrLua_module()
	end

	_IrrLua_module = loadlib("./libIrrLua.so", "IrrLua_open")
	if _IrrLua_module then
		return _IrrLua_module()
	end

	_IrrLua_module = loadlib("/usr/local/lib/libIrrLua.so", "IrrLua_open")
	if _IrrLua_module then
		return _IrrLua_module()
	end

	_IrrLua_module = loadlib("/usr/lib/libIrrLua.so", "IrrLua_open")
	if _IrrLua_module then
		return _IrrLua_module()
	end

	print("Error loading module")
	return false
end

_IrrLua_loadmodule()

