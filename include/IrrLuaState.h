#ifndef _IRRLUASTATE_H_
#define _IRRLUASTATE_H_

#include "lua.h"

lua_State *IrrLuaGetState();
void IrrLuaSetState(lua_State *L);

#endif /* _IRRLUASTATE_H_ */
