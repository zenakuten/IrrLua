#ifndef _ANIMATEDSPRITESKIN_H_
#define _ANIMATEDSPRITESKIN_H_

#ifdef ANIMATEDSPRITESKIN_EXPORTS
#define ANIMATEDSPRITESKIN_API __declspec(dllexport)
#else
#define ANIMATEDSPRITESKIN_API __declspec(dllimport)
#endif

#include "irrlicht.h"

namespace irr
{
namespace gui
{
	class CAnimatedSpriteSkin;

	ANIMATEDSPRITESKIN_API irr::gui::CAnimatedSpriteSkin *createAnimatedSpriteSkin(irr::video::IVideoDriver *Driver, irr::scene::ISceneManager *Manager, irr::ITimer *Timer);
}
}
#endif _ANIMATEDSPRITESKIN_H_
