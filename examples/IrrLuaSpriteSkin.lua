-- Copyright (C) 2005-2006 Josh Turpen, Nikolaus Gebhardt
-- This file is part of the IrrLua Lua binding for Irrlicht.
-- For conditions of distribution and use, see copyright notice in IrrLua.h

-- gross, I know, but if you have a better/easier way, tell me :)
--
-- This file is NOT needed when using Lua 5.1.  
--
-- jjt

function _IrrLuaSpriteSkin_loadmodule()

	local dlload = loadlib
	if _VERSION == "Lua 5.1" then
		dlload = package.loadlib
	end
	
	if _IrrLuaSpriteSkin_module then 
		return true
	end

	_IrrLuaSpriteSkin_module = dlload("IrrLuaSpriteSkin", "luaopen_IrrLuaSpriteSkin")
	if _IrrLuaSpriteSkin_module then
		return _IrrLuaSpriteSkin_module()
	end

	_IrrLuaSpriteSkin_module = dlload("./libIrrLuaSpriteSkin.so", "luaopen_IrrLuaSpriteSkin")
	if _IrrLuaSpriteSkin_module then
		return _IrrLuaSpriteSkin_module()
	end

	_IrrLuaSpriteSkin_module = dlload("/usr/local/lib/libIrrLuaSpriteSkin.so", "luaopen_IrrLuaSpriteSkin")
	if _IrrLuaSpriteSkin_module then
		return _IrrLuaSpriteSkin_module()
	end

	_IrrLuaSpriteSkin_module = dlload("/usr/lib/libIrrLuaSpriteSkin.so", "luaopen_IrrLuaSpriteSkin")
	if _IrrLuaSpriteSkin_module then
		return _IrrLuaSpriteSkin_module()
	end

	print("Error loading module")
	return false
end

_IrrLuaSpriteSkin_loadmodule()

