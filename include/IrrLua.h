/* 
	IrrLua.h - IrrLua - The Lua binding for Irrlicht

	Copyright (C) 2005-2006 Josh Turpen

	This software is provided 'as-is', without any express or implied
	warranty.  In no event will the authors be held liable for any damages
	arising from the use of this software.

	Permission is granted to anyone to use this software for any purpose,
	including commercial applications, and to alter it and redistribute it
	freely, subject to the following restrictions:

	1. The origin of this software must not be misrepresented; you must not
	claim that you wrote the original software. If you use this software
	in a product, an acknowledgment in the product documentation would be
	appreciated but is not required.

	2. Altered source versions must be plainly marked as such, and must not be
    misrepresented as being the original software.

	3. This notice may not be removed or altered from any source distribution.

*/

#ifndef _IRRLUA_H_
#define _IRRLUA_H_

#include <string>

#include "irrlicht.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#include "tolua++.h"

IRRLUA_API int luaopen_IrrLua(lua_State* L);

/* Needed for tolua++ irrlua_imp.cpp file to work  */
#ifdef _PKG_

//used by pkg files for typecast of c8, u8, s8, etc..
using namespace irr;

//for irrXML.pkg
typedef char char_type;
#endif /* _PKG_ */

#include "IrrLuaCast.h"
#include "IrrLuaEventReceiver.h"
#include "IrrLuaISceneNode.h"
#include "IrrLuaIShaderConstantSetCallBack.h"
#include "IrrLuaIVideoDriver.h"
#include "IrrLuaISceneManager.h"
#include "IrrLuaIMaterialRenderer.h"
#include "IrrLuaIGUIElement.h"
#include "IrrLuaIGUISkin.h"
#include "IrrLuaIMesh.h"
#include "IrrLuaIAnimatedMesh.h"
#include "IrrLuaIAnimatedMeshSceneNode.h"
#include "IrrLuaIParticleAffector.h"
#include "IrrLuaIParticleEmitter.h"
#include "IrrLuaITriangleSelector.h"
#include "IrrLuaISceneNodeAnimator.h"
#include "IrrLuaISceneNodeAnimatorCollisionResponse.h"
#include "IrrLuaDoFile.h"
#include "IrrLuaAux.h"

#ifdef __cplusplus
}
#endif

#endif /* _IRRLUA_H_ */
