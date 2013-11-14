// CustomSceneNode.cpp : Defines the entry point for the DLL application.
//
#ifdef MSVC
#define WIN32_LEAN_AND_MEAN		
#include <windows.h>
#endif

#include "CustomSceneNode.h"
using namespace MyProject;

#include "CustomSceneNode_imp.cpp"

#ifdef MSVC
BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    return TRUE;
}
#endif



