// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the IRRLUA_DLL_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// IRRLUA_DLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

/*
#ifdef IRRLUA_DLL_EXPORTS
#define IRRLUA_DLL_API __declspec(dllexport)
#define LUA_API __declspec(dllexport)
#error "IRRLUA_DLL_EXPORTS defined"
#define TOLUA_API __declspec(dllexport)
#else
#error "IRRLUA_DLL_EXPORTS not defined"
#define IRRLUA_DLL_API __declspec(dllimport)
#define LUA_API __declspec(dllimport)
#define TOLUA_API __declspec(dllimport)
#endif
*/

#include "IrrLua.h"

/*
class __declspec(dllexport) CIrrLua_DLL {
public:
	CIrrLua_DLL(void);
	// TODO: add your methods here.
};

*/