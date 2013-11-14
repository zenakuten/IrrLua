#ifndef _IRRLUASPRITESKIN_H_
#define _IRRLUASPRITESKIN_H_

#ifdef IRRLUASPRITESKIN_EXPORTS
#define IRRLUASPRITESKIN_API __declspec(dllexport)
#else
#define IRRLUASPRITESKIN_API __declspec(dllimport)
#endif

#include "irrlicht.h"

extern "C"
{
#include "lua.h"
IRRLUASPRITESKIN_API int luaopen_IrrLuaSpriteSkin (lua_State* tolua_S);
}


using namespace irr;

#include "CAnimatedSpriteSkin.h"
#include "AnimatedSpriteSkin.h"

#endif /* _IRRLUASPRITESKIN_H_*/