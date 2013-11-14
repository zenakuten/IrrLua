
#include <windows.h>

#include "AnimatedSpriteSkin.h"
#include "CAnimatedSpriteSkin.h"

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    return TRUE;
}


namespace irr
{
namespace gui
{
	ANIMATEDSPRITESKIN_API irr::gui::CAnimatedSpriteSkin *createAnimatedSpriteSkin(irr::video::IVideoDriver *Driver, irr::scene::ISceneManager *Manager, irr::ITimer *Timer)
	{
		return new irr::gui::CAnimatedSpriteSkin(Driver, Manager, Timer);
	}
}
}

