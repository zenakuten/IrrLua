// Copyright (C) 2005-2006 Josh Turpen
// This file is part of the IrrLua Lua binding for Irrlicht.
// For conditions of distribution and use, see copyright notice in IrrLua.h

#ifndef _IRRLUAIVIDEODRIVER_H_
#define _IRRLUAIVIDEODRIVER_H_

#include "IrrLua.h"

namespace irr
{
namespace video
{

		TOLUA_API void IrrLuaDrawIndexedTriangleList(IVideoDriver *drv, 
											s32 vertexCount, S3DVertex *vertices,
											s32 triangleCount, s16 *indexList);
	

}
}

#endif /* _IRRLUAIVIDEODRIVER_H_ */
