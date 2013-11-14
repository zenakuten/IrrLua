// Copyright (C) 2005-2006 Josh Turpen
// This file is part of the IrrLua Lua binding for Irrlicht.
// For conditions of distribution and use, see copyright notice in IrrLua.h

#ifndef _IRRLUAIMATERIALRENDERER_H_
#define _IRRLUAIMATERIALRENDERER_H_

#include "IrrLua.h"

namespace irr
{
namespace video
{
	// the f32 * needs to be at the end of the declaration for tolua++ to work
	//HLSL/CG
	TOLUA_API bool IrrLuaSetVertexShaderConstant1(irr::video::IMaterialRendererServices *services, std::string name, s32 count, f32 *floats);
	TOLUA_API bool IrrLuaSetPixelShaderConstant1(irr::video::IMaterialRendererServices *services, std::string name, s32 count, f32 *floats);

	//ASM
	TOLUA_API void IrrLuaSetVertexShaderConstant2(irr::video::IMaterialRendererServices *services, s32 start, s32 ucount, s32 count, f32 *data);
	TOLUA_API void IrrLuaSetPixelShaderConstant2(irr::video::IMaterialRendererServices *services, s32 start, s32 ucount, s32 count, f32 *data);

}
}

#endif /* _IRRLUAIMATERIALRENDERER_H_ */
