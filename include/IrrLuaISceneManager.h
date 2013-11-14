// Copyright (C) 2005-2006 Josh Turpen
// This file is part of the IrrLua Lua binding for Irrlicht.
// For conditions of distribution and use, see copyright notice in IrrLua.h

#ifndef _IRRLUA_ISCENEMANAGER_H_
#define _IRRLUA_ISCENEMANAGER_H_

#include "IrrLua.h"

namespace irr
{
	namespace scene
	{
		TOLUA_API ICameraSceneNode* IrrLuaAddCameraSceneNodeFPS(ISceneManager *mgr, ISceneNode* parent, f32 rotateSpeed , f32 moveSpeed , s32 id, s32 keyMapSize, SKeyMap* keyMapArray, bool noVerticalMovement);

	}
}


#endif /* _IRRLUA_ISCENEMANAGER_H_ */
