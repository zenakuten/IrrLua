// IrrLuaSpriteSkin.cpp : Defines the entry point for the DLL application.
//

#include <windows.h>
#include <string>




#if _MSC_VER > 1300

//using c linkage with c++ stuff is OK 
#pragma warning(disable:4910)
//stupid compiler limit line number warning
#pragma warning(disable:4049)
//bool performance warnings in auto-generated file, i can't fix those
#pragma warning(disable:4800)

//dll linkage for ISkin, we don't care
#pragma warning(disable:4275)

#endif

#include "IrrLuaSpriteSkin.h"

#undef LUA_VERSION_NUM
#include "IrrLuaSpriteSkin_imp.cpp"

#if _MSC_VER > 1300
#pragma warning(default:4275)
#pragma warning(default:4800)
#pragma warning(default:4910)
#pragma warning(default:4049)
#endif


extern "C"
{
IRRLUASPRITESKIN_API int luaopen_IrrLuaSpriteSkin (lua_State* tolua_S) 
{
 return tolua_IrrLuaSpriteSkin_open(tolua_S);
};
}


BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

