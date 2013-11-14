// Copyright (C) 2002-2006 Nikolaus Gebhardt, Josh Turpen
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#include "CAnimatedSpriteSkin.h"
#include "IGUIFont.h"
#include "IVideoDriver.h"
#include <stdio.h>

using namespace irr::core;
using namespace irr::gui;

namespace irr
{
namespace gui
{

	CAnimatedSpriteSkin::CAnimatedSpriteSkin(video::IVideoDriver* driver, scene::ISceneManager *scm, irr::ITimer *timer): Font(0), Driver(driver), SceneManager(scm), Timer(timer)
{
	#ifdef _DEBUG
	setDebugName("CAnimatedSpriteSkin");
	#endif


	Colors[EGDC_3D_DARK_SHADOW] =	video::SColor(101,50,50,50);
	Colors[EGDC_3D_SHADOW] =		video::SColor(101,130,130,130);
	Colors[EGDC_3D_FACE] =			video::SColor(101,210,210,210);
	Colors[EGDC_3D_HIGH_LIGHT] =	video::SColor(101,255,255,255);
	Colors[EGDC_3D_LIGHT] =			video::SColor(101,210,210,210);
	Colors[EGDC_ACTIVE_BORDER] =	video::SColor(101,16,14,115);
	Colors[EGDC_ACTIVE_CAPTION] =	video::SColor(101,255,255,255);
	Colors[EGDC_APP_WORKSPACE] =	video::SColor(101,100,100,100);
	Colors[EGDC_BUTTON_TEXT] =		video::SColor(101,0,0,0);
	Colors[EGDC_BUTTON_TEXT] =		video::SColor(101,255,255,255);

	Colors[EGDC_GRAY_TEXT] =		video::SColor(101,130,130,130);
	Colors[EGDC_HIGH_LIGHT] =		video::SColor(101,8,36,107);
	Colors[EGDC_HIGH_LIGHT_TEXT] =	video::SColor(101,255,255,255);
	Colors[EGDC_INACTIVE_BORDER] =	video::SColor(101,165,165,165);
	Colors[EGDC_INACTIVE_CAPTION] = video::SColor(101,210,210,210);
	Colors[EGDC_TOOLTIP] =			video::SColor(101,255,255,230);
	Colors[EGDC_SCROLLBAR] =		video::SColor(101,230,230,230);
	Colors[EGDC_WINDOW] =			video::SColor(101,255,255,255);

	Sizes[EGDS_SCROLLBAR_SIZE] = 14;
	Sizes[EGDS_MENU_HEIGHT] = 18;
	Sizes[EGDS_WINDOW_BUTTON_WIDTH] = 15;
	Sizes[EGDS_CHECK_BOX_WIDTH] = 18;
	Sizes[EGDS_MESSAGE_BOX_WIDTH] = 500;
	Sizes[EGDS_MESSAGE_BOX_HEIGHT] = 200;
	Sizes[EGDS_BUTTON_WIDTH] = 80;
	Sizes[EGDS_BUTTON_HEIGHT] = 30;

	Texts[EGDT_MSG_BOX_OK] = L"OK";
	Texts[EGDT_MSG_BOX_CANCEL] = L"Cancel";
	Texts[EGDT_MSG_BOX_YES] = L"Yes";
	Texts[EGDT_MSG_BOX_NO] = L"No";

	Sprites[EGEIT_BUTTON_PANE_STANDARD] = NULL;
	Sprites[EGEIT_BUTTON_PANE_PRESSED] = NULL;
	Sprites[EGEIT_SUNKEN_PANE_FLAT] = NULL;
	Sprites[EGEIT_SUNKEN_PANE_SUNKEN] = NULL;
	Sprites[EGEIT_WINDOW_BACKGROUND] = NULL;
	Sprites[EGEIT_WINDOW_BACKGROUND_TITLEBAR] = NULL;
	Sprites[EGEIT_MENU_PANE] = NULL;
	Sprites[EGEIT_TOOLBAR] = NULL;
	Sprites[EGEIT_TAB_BUTTON] = NULL;
	Sprites[EGEIT_TAB_BODY] = NULL;
	
}


//! destructor
CAnimatedSpriteSkin::~CAnimatedSpriteSkin()
{
	if (Font)
		Font->drop();

}

bool CAnimatedSpriteSkin::Load(EGUI_ELEMENT_IMAGE_TYPE Type, std::string filename, s32 Ax,s32 Ay,s32 Aw,s32 Ah,s32 frmWidth,s32 frmHeight,bool useClrKey)
{
	if (!Driver)
		return false;

	if (Type < 0 || Type > EGEIT_COUNT)
		return false;
	
	if(Sprites[Type])
	{
		Sprites[Type]->remove();
		Sprites[Type] = NULL;
	}
	
	Sprites[Type] = new scene::TAnimSpriteSceneNode(SceneManager->getRootSceneNode(), SceneManager, -1, Timer);
	if(Sprites[Type]->Load((char *) filename.c_str(), Ax, Ay, Aw, Ah, frmWidth, frmHeight, useClrKey))
	{
		Sprites[Type]->drop();
		return true;
	}

	Sprites[Type]->drop();
	Sprites[Type] = NULL;
	return false;
}

//! returns default color
video::SColor CAnimatedSpriteSkin::getColor(EGUI_DEFAULT_COLOR color)
{
	return Colors[color];
}


//! sets a default color
void CAnimatedSpriteSkin::setColor(EGUI_DEFAULT_COLOR which, video::SColor newColor)
{
	if (which>=0 && which<= EGDC_COUNT)
		Colors[which] = newColor;
}


//! returns default color
s32 CAnimatedSpriteSkin::getSize(EGUI_DEFAULT_SIZE size)
{
	return Sizes[size];
}



//! sets a default size
void CAnimatedSpriteSkin::setSize(EGUI_DEFAULT_SIZE which, s32 size)
{
	if (which >= 0 && which <= EGDS_COUNT) 
		Sizes[which] = size;
}

s32 CAnimatedSpriteSkin::getAnimationSpeed(EGUI_ELEMENT_IMAGE_TYPE Type)
{
	if (Type < 0 || Type > EGEIT_COUNT)
		return 0;

	if(Sprites[Type])
		return Sprites[Type]->getSpeed();

	return 0;
}

void CAnimatedSpriteSkin::setAnimationSpeed(EGUI_ELEMENT_IMAGE_TYPE Type, s32 spd)
{
	if (Type < 0 || Type > EGEIT_COUNT)
		return;

	if(Sprites[Type])
		Sprites[Type]->setSpeed(spd);

}

void CAnimatedSpriteSkin::setLoop(EGUI_ELEMENT_IMAGE_TYPE Type, bool l)
{
	if (Type < 0 || Type > EGEIT_COUNT)
		return;

	if(Sprites[Type])
		Sprites[Type]->setLoop(l);

}

bool CAnimatedSpriteSkin::getLoop(EGUI_ELEMENT_IMAGE_TYPE Type)
{
	if (Type < 0 || Type > EGEIT_COUNT)
		return true;

	if(Sprites[Type])
		return Sprites[Type]->getLoop();

	return true;
}

void CAnimatedSpriteSkin::playForward(EGUI_ELEMENT_IMAGE_TYPE Type)
{
	if (Type < 0 || Type > EGEIT_COUNT)
		return;

	if(Sprites[Type])
		Sprites[Type]->PlayForward();

}

void CAnimatedSpriteSkin::playBackward(EGUI_ELEMENT_IMAGE_TYPE Type)
{
	if (Type < 0 || Type > EGEIT_COUNT)
		return;

	if(Sprites[Type])
		Sprites[Type]->PlayBackward();

}


void CAnimatedSpriteSkin::resetAnimation(EGUI_ELEMENT_IMAGE_TYPE Type)
{
	if (Type < 0 || Type > EGEIT_COUNT)
		return;

	if(Sprites[Type])
		Sprites[Type]->resetLoop();
}

//! returns the default font
IGUIFont* CAnimatedSpriteSkin::getFont()
{
	return Font;
}


//! sets a default font
void CAnimatedSpriteSkin::setFont(IGUIFont* font)
{
	if (Font)
		Font->drop();

	Font = font;

	if (Font)
		Font->grab();
}


//! Returns a default text. For example for Message box button captions:
//! "OK", "Cancel", "Yes", "No" and so on.
const wchar_t* CAnimatedSpriteSkin::getDefaultText(EGUI_DEFAULT_TEXT text)
{
	return Texts[text].c_str();
}


//! Sets a default text. For example for Message box button captions:
//! "OK", "Cancel", "Yes", "No" and so on.
void CAnimatedSpriteSkin::setDefaultText(EGUI_DEFAULT_TEXT which, const wchar_t* newText)
{
	Texts[which] = newText;
}

//! draws a standard 3d button pane
/**	Used for drawing for example buttons in normal state. 
It uses the colors EGDC_3D_DARK_SHADOW, EGDC_3D_HIGH_LIGHT, EGDC_3D_SHADOW and
EGDC_3D_FACE for this. See EGUI_DEFAULT_COLOR for details. 
\param rect: Defining area where to draw.
\param clip: Clip area.
\param element: Pointer to the element which whiches to draw this. This parameter
is usually not used by ISkin, but can be used for example by more complex 
implementations to find out how to draw the part exactly. */
void CAnimatedSpriteSkin::draw3DButtonPaneStandard(IGUIElement* element,
										const core::rect<s32>& r,
										const core::rect<s32>* clip)
{
	if (!Driver)
		return;

	core::rect<s32> rect = r;

	if(Sprites[EGEIT_BUTTON_PANE_STANDARD])
	{
		drawSprite(Sprites[EGEIT_BUTTON_PANE_STANDARD], rect);
	}
	else
	{
		//Draw normal skin if image not available
		Driver->draw2DRectangle(getColor(EGDC_3D_DARK_SHADOW), rect, clip);

		rect.LowerRightCorner.X -= 1;
		rect.LowerRightCorner.Y -= 1;
		Driver->draw2DRectangle(getColor(EGDC_3D_HIGH_LIGHT), rect, clip);

		rect.UpperLeftCorner.X += 1;
		rect.UpperLeftCorner.Y += 1;
		Driver->draw2DRectangle(getColor(EGDC_3D_SHADOW), rect, clip);

		rect.LowerRightCorner.X -= 1;
		rect.LowerRightCorner.Y -= 1;

		Driver->draw2DRectangle(getColor(EGDC_3D_FACE), rect, clip);
	}
}


//! draws a pressed 3d button pane
/**	Used for drawing for example buttons in pressed state. 
It uses the colors EGDC_3D_DARK_SHADOW, EGDC_3D_HIGH_LIGHT, EGDC_3D_SHADOW and
EGDC_3D_FACE for this. See EGUI_DEFAULT_COLOR for details. 
\param rect: Defining area where to draw.
\param clip: Clip area.
\param element: Pointer to the element which whiches to draw this. This parameter
is usually not used by ISkin, but can be used for example by more complex 
implementations to find out how to draw the part exactly. */
void CAnimatedSpriteSkin::draw3DButtonPanePressed(IGUIElement* element, 
	const core::rect<s32>& r,
	const core::rect<s32>* clip)
{
	if (!Driver)
		return;
	
	core::rect<s32> rect = r;

	if(Sprites[EGEIT_BUTTON_PANE_PRESSED])
	{
		drawSprite(Sprites[EGEIT_BUTTON_PANE_PRESSED], rect);
	}
	else
	{
		Driver->draw2DRectangle(getColor(EGDC_3D_HIGH_LIGHT), rect, clip);

		rect.LowerRightCorner.X -= 1;
		rect.LowerRightCorner.Y -= 1;
		Driver->draw2DRectangle(getColor(EGDC_3D_DARK_SHADOW), rect, clip);

		rect.UpperLeftCorner.X += 1;
		rect.UpperLeftCorner.Y += 1;
		Driver->draw2DRectangle(getColor(EGDC_3D_SHADOW), rect, clip);

		rect.UpperLeftCorner.X += 1;
		rect.UpperLeftCorner.Y += 1;

		Driver->draw2DRectangle(getColor(EGDC_3D_FACE), rect, clip);
	}
}


//! draws a sunken 3d pane
/** Used for drawing the background of edit, combo or check boxes.
\param element: Pointer to the element which whiches to draw this. This parameter
is usually not used by ISkin, but can be used for example by more complex 
implementations to find out how to draw the part exactly. 
\param bgcolor: Background color.
\param flat: Specifies if the sunken pane should be flat or displayed as sunken 
 deep into the ground.
\param rect: Defining area where to draw.
\param clip: Clip area.	*/
void CAnimatedSpriteSkin::draw3DSunkenPane(IGUIElement* element,
	video::SColor bgcolor, bool flat, bool fillBackGround,
	const core::rect<s32>& r,
	const core::rect<s32>* clip)
{
	if (!Driver)
		return;

	core::rect<s32> rect = r;

	if (flat)
	{
		if(Sprites[EGEIT_SUNKEN_PANE_FLAT])
		{
			drawSprite(Sprites[EGEIT_SUNKEN_PANE_FLAT], rect);
		}
		else
		{
			// draw flat sunken pane
			if (fillBackGround)
				Driver->draw2DRectangle(bgcolor, rect, clip);

			rect.LowerRightCorner.Y = rect.UpperLeftCorner.Y + 1;
			Driver->draw2DRectangle(getColor(EGDC_3D_SHADOW), rect, clip);

			rect.LowerRightCorner.Y = r.LowerRightCorner.Y;
			rect.LowerRightCorner.X = rect.UpperLeftCorner.X + 1;
			Driver->draw2DRectangle(getColor(EGDC_3D_SHADOW), rect, clip);

			rect = r;
			rect.UpperLeftCorner.X = rect.LowerRightCorner.X - 1;
			Driver->draw2DRectangle(getColor(EGDC_3D_HIGH_LIGHT), rect, clip);

			rect = r;
			rect.UpperLeftCorner.Y = r.LowerRightCorner.Y - 1;
			rect.LowerRightCorner.Y = r.LowerRightCorner.Y;
			Driver->draw2DRectangle(getColor(EGDC_3D_HIGH_LIGHT), rect, clip);
		}
	}
	else
	{
		if(Sprites[EGEIT_SUNKEN_PANE_SUNKEN])
		{
			drawSprite(Sprites[EGEIT_SUNKEN_PANE_SUNKEN], rect);
		}
		else
		{		
			// draw deep sunken pane
			if (fillBackGround)
				Driver->draw2DRectangle(getColor(EGDC_3D_HIGH_LIGHT), rect, clip);

			rect.LowerRightCorner.X -= 1;
			rect.LowerRightCorner.Y -= 1;
			Driver->draw2DRectangle(getColor(EGDC_3D_SHADOW), rect, clip);

			rect.UpperLeftCorner.X += 1;
			rect.UpperLeftCorner.Y += 1;
			Driver->draw2DRectangle(getColor(EGDC_3D_LIGHT), rect, clip);

			rect.LowerRightCorner.X -= 1;
			rect.LowerRightCorner.Y -= 1;
			Driver->draw2DRectangle(getColor(EGDC_3D_DARK_SHADOW), rect, clip);

			rect.UpperLeftCorner.X += 1;
			rect.UpperLeftCorner.Y += 1;
			Driver->draw2DRectangle(bgcolor, rect, clip);
		}
	}
}


//! draws a window background
/** Used for drawing the background of dialogs and windows.
\param element: Pointer to the element which whiches to draw this. This parameter
is usually not used by ISkin, but can be used for example by more complex 
implementations to find out how to draw the part exactly. 
\param titleBarColor: Title color.
\param drawTitleBar: True to enable title drawing.
\param rect: Defining area where to draw.
\param clip: Clip area.
\return Returns rect where to draw title bar text. */
core::rect<s32> CAnimatedSpriteSkin::draw3DWindowBackground(IGUIElement* element,
	bool drawTitleBar, video::SColor titleBarColor,
	const core::rect<s32>& r,
	const core::rect<s32>* cl)
{
	if (!Driver)
		return r;

	core::rect<s32> rect = r;

	if(Sprites[EGEIT_WINDOW_BACKGROUND])
	{
		rect = r;
		rect.UpperLeftCorner.X +=1;
		rect.UpperLeftCorner.Y +=1;
		rect.LowerRightCorner.X -= 2;
		rect.LowerRightCorner.Y -= 2;

		drawSprite(Sprites[EGEIT_WINDOW_BACKGROUND], rect);

		rect = r;
		
		rect.UpperLeftCorner.X += 2;
		rect.UpperLeftCorner.Y += 2;
		rect.LowerRightCorner.X -= 2;
		rect.LowerRightCorner.Y = rect.UpperLeftCorner.Y + getSize(EGDS_WINDOW_BUTTON_WIDTH) + 2;
	}
	else	
	{
		rect.LowerRightCorner.Y = rect.UpperLeftCorner.Y + 1;
		Driver->draw2DRectangle(getColor(EGDC_3D_HIGH_LIGHT), rect, cl);
		
		rect.LowerRightCorner.Y = r.LowerRightCorner.Y;
		rect.LowerRightCorner.X = rect.UpperLeftCorner.X + 1;
		Driver->draw2DRectangle(getColor(EGDC_3D_HIGH_LIGHT), rect, cl);

		rect.UpperLeftCorner.X = r.LowerRightCorner.X - 1;
		rect.LowerRightCorner.X = r.LowerRightCorner.X;
		rect.UpperLeftCorner.Y = r.UpperLeftCorner.Y;
		rect.LowerRightCorner.Y = r.LowerRightCorner.Y;
		Driver->draw2DRectangle(getColor(EGDC_3D_DARK_SHADOW), rect, cl);

		rect.UpperLeftCorner.X -= 1;
		rect.LowerRightCorner.X -= 1;
		rect.UpperLeftCorner.Y += 1;
		rect.LowerRightCorner.Y -= 1;
		Driver->draw2DRectangle(getColor(EGDC_3D_SHADOW), rect, cl);

		rect.UpperLeftCorner.X = r.UpperLeftCorner.X;
		rect.UpperLeftCorner.Y = r.LowerRightCorner.Y - 1;
		rect.LowerRightCorner.Y = r.LowerRightCorner.Y;
		rect.LowerRightCorner.X = r.LowerRightCorner.X;
		Driver->draw2DRectangle(getColor(EGDC_3D_DARK_SHADOW), rect, cl);

		rect.UpperLeftCorner.X += 1;
		rect.LowerRightCorner.X -= 1;
		rect.UpperLeftCorner.Y -= 1;
		rect.LowerRightCorner.Y -= 1;
		Driver->draw2DRectangle(getColor(EGDC_3D_SHADOW), rect, cl);

		rect = r;
		rect.UpperLeftCorner.X +=1;
		rect.UpperLeftCorner.Y +=1;
		rect.LowerRightCorner.X -= 2;
		rect.LowerRightCorner.Y -= 2;

		Driver->draw2DRectangle(getColor(EGDC_3D_FACE), rect, cl);
		
		rect = r;
		rect.UpperLeftCorner.X += 2;
		rect.UpperLeftCorner.Y += 2;
		rect.LowerRightCorner.X -= 2;
		rect.LowerRightCorner.Y = rect.UpperLeftCorner.Y + getSize(EGDS_WINDOW_BUTTON_WIDTH) + 2;
	}

	if (drawTitleBar)
	{
		if(Sprites[EGEIT_WINDOW_BACKGROUND_TITLEBAR])
		{						
			drawSprite(Sprites[EGEIT_WINDOW_BACKGROUND_TITLEBAR], rect);
		}
		else
		{
			video::SColor c = titleBarColor.getInterpolated(video::SColor(255,0,0,0), 0.2f);
			Driver->draw2DRectangle(rect, titleBarColor, c, titleBarColor, c, cl);
		}
	}

	return rect;
}


//! draws a standard 3d menu pane
/**	Used for drawing for menus and context menus. 
It uses the colors EGDC_3D_DARK_SHADOW, EGDC_3D_HIGH_LIGHT, EGDC_3D_SHADOW and
EGDC_3D_FACE for this. See EGUI_DEFAULT_COLOR for details. 
\param element: Pointer to the element which whiches to draw this. This parameter
is usually not used by ISkin, but can be used for example by more complex 
implementations to find out how to draw the part exactly. 
\param rect: Defining area where to draw.
\param clip: Clip area.	*/
void CAnimatedSpriteSkin::draw3DMenuPane(IGUIElement* element,
	const core::rect<s32>& r,
	const core::rect<s32>* clip)
{
	if (!Driver)
		return;

	core::rect<s32> rect = r;

	if(Sprites[EGEIT_MENU_PANE])
	{
		drawSprite(Sprites[EGEIT_MENU_PANE], rect);
	}
	else
	{
		// in this skin, this is exactly what non pressed buttons look like,
		// so we could simply call
		// draw3DButtonPaneStandard(element, rect, clip);	
		// here.
		// but if the skin is transparent, this doesn't look that nice. So
		// We draw it a little bit better, with some more draw2DRectangle calls,
		// but there aren't that much menus visible anyway.

		rect.LowerRightCorner.Y = rect.UpperLeftCorner.Y + 1;
		Driver->draw2DRectangle(getColor(EGDC_3D_HIGH_LIGHT), rect, clip);

		rect.LowerRightCorner.Y = r.LowerRightCorner.Y;
		rect.LowerRightCorner.X = rect.UpperLeftCorner.X + 1;
		Driver->draw2DRectangle(getColor(EGDC_3D_HIGH_LIGHT), rect, clip);

		rect.UpperLeftCorner.X = r.LowerRightCorner.X - 1;
		rect.LowerRightCorner.X = r.LowerRightCorner.X;
		rect.UpperLeftCorner.Y = r.UpperLeftCorner.Y;
		rect.LowerRightCorner.Y = r.LowerRightCorner.Y;
		Driver->draw2DRectangle(getColor(EGDC_3D_DARK_SHADOW), rect, clip);

		rect.UpperLeftCorner.X -= 1;
		rect.LowerRightCorner.X -= 1;
		rect.UpperLeftCorner.Y += 1;
		rect.LowerRightCorner.Y -= 1;
		Driver->draw2DRectangle(getColor(EGDC_3D_SHADOW), rect, clip);

		rect.UpperLeftCorner.X = r.UpperLeftCorner.X;
		rect.UpperLeftCorner.Y = r.LowerRightCorner.Y - 1;
		rect.LowerRightCorner.Y = r.LowerRightCorner.Y;
		rect.LowerRightCorner.X = r.LowerRightCorner.X;
		Driver->draw2DRectangle(getColor(EGDC_3D_DARK_SHADOW), rect, clip);

		rect.UpperLeftCorner.X += 1;
		rect.LowerRightCorner.X -= 1;
		rect.UpperLeftCorner.Y -= 1;
		rect.LowerRightCorner.Y -= 1;
		Driver->draw2DRectangle(getColor(EGDC_3D_SHADOW), rect, clip);

		rect = r;
		rect.UpperLeftCorner.X +=1;
		rect.UpperLeftCorner.Y +=1;
		rect.LowerRightCorner.X -= 2;
		rect.LowerRightCorner.Y -= 2;

		Driver->draw2DRectangle(getColor(EGDC_3D_FACE), rect, clip);
	}
}


//! draws a standard 3d tool bar
/**	Used for drawing for toolbars and menus.
\param element: Pointer to the element which whiches to draw this. This parameter
is usually not used by ISkin, but can be used for example by more complex 
implementations to find out how to draw the part exactly. 
\param rect: Defining area where to draw.
\param clip: Clip area.	*/
void CAnimatedSpriteSkin::draw3DToolBar(IGUIElement* element,
	const core::rect<s32>& r,
	const core::rect<s32>* clip)
{
	if (!Driver)
		return;

	core::rect<s32> rect = r;

	if(Sprites[EGEIT_TOOLBAR])
	{
		drawSprite(Sprites[EGEIT_TOOLBAR], rect);
	}
	else
	{
		rect.UpperLeftCorner.X = r.UpperLeftCorner.X;
		rect.UpperLeftCorner.Y = r.LowerRightCorner.Y - 1;
		rect.LowerRightCorner.Y = r.LowerRightCorner.Y;
		rect.LowerRightCorner.X = r.LowerRightCorner.X;
		Driver->draw2DRectangle(getColor(EGDC_3D_SHADOW), rect, clip);

		rect = r;
		rect.LowerRightCorner.Y -= 1;

		Driver->draw2DRectangle(getColor(EGDC_3D_FACE), rect, clip);
	}
}

//! draws a tab button
/**	Used for drawing for tab buttons on top of tabs.
\param element: Pointer to the element which whiches to draw this. This parameter
is usually not used by ISkin, but can be used for example by more complex 
implementations to find out how to draw the part exactly. 
\param active: Specifies if the tab is currently active.
\param rect: Defining area where to draw.
\param clip: Clip area.	*/
void CAnimatedSpriteSkin::draw3DTabButton(IGUIElement* element, bool active,
	const core::rect<s32>& frameRect, const core::rect<s32>* clip)
{
	if (!Driver)
		return;

	core::rect<s32> tr = frameRect;
	if(Sprites[EGEIT_TAB_BUTTON])
	{
		drawSprite(Sprites[EGEIT_TAB_BUTTON], tr);
	}
	else
	{
		tr.LowerRightCorner.X -= 2;
		tr.LowerRightCorner.Y = tr.UpperLeftCorner.Y + 1;
		tr.UpperLeftCorner.X += 1;
		Driver->draw2DRectangle(getColor(EGDC_3D_HIGH_LIGHT), tr, clip);

		// draw left highlight
		tr = frameRect;
		tr.LowerRightCorner.X = tr.UpperLeftCorner.X + 1;
		tr.UpperLeftCorner.Y += 1;
		Driver->draw2DRectangle(getColor(EGDC_3D_HIGH_LIGHT), tr, clip);

		// draw grey background
		tr = frameRect;
		tr.UpperLeftCorner.X += 1;
		tr.UpperLeftCorner.Y += 1;
		tr.LowerRightCorner.X -= 2;
		Driver->draw2DRectangle(getColor(EGDC_3D_FACE), tr, clip);

		// draw right middle gray shadow
		tr.LowerRightCorner.X += 1;
		tr.UpperLeftCorner.X = tr.LowerRightCorner.X - 1;
		Driver->draw2DRectangle(getColor(EGDC_3D_SHADOW), tr, clip);

		tr.LowerRightCorner.X += 1;
		tr.UpperLeftCorner.X += 1;
		tr.UpperLeftCorner.Y += 1;
		Driver->draw2DRectangle(getColor(EGDC_3D_DARK_SHADOW), tr, clip);
	}
}


//! draws a tab control body
/**	\param element: Pointer to the element which whiches to draw this. This parameter
is usually not used by ISkin, but can be used for example by more complex 
implementations to find out how to draw the part exactly. 
\param border: Specifies if the border should be drawn.
\param background: Specifies if the background should be drawn.
\param rect: Defining area where to draw.
\param clip: Clip area.	*/
void CAnimatedSpriteSkin::draw3DTabBody(IGUIElement* element, bool border, bool background,
	const core::rect<s32>& rect, const core::rect<s32>* clip)
{
	if (!Driver)
		return;

	core::rect<s32> tr = rect;
	if(Sprites[EGEIT_TAB_BODY])
	{
		tr = rect;
		tr.UpperLeftCorner.Y += getSize(gui::EGDS_BUTTON_HEIGHT) + 2;
		tr.LowerRightCorner.X -= 1;
		tr.UpperLeftCorner.X += 1;
		tr.LowerRightCorner.Y -= 1;
		
		drawSprite(Sprites[EGEIT_TAB_BODY], tr);
	}
	else
	{
		// draw border.
		if (border)
		{
			// draw left hightlight
			tr.UpperLeftCorner.Y += getSize(gui::EGDS_BUTTON_HEIGHT) + 2;
			tr.LowerRightCorner.X = tr.UpperLeftCorner.X + 1;
			Driver->draw2DRectangle(getColor(EGDC_3D_HIGH_LIGHT), tr, clip);

			// draw right shadow
			tr.UpperLeftCorner.X = rect.LowerRightCorner.X - 1;
			tr.LowerRightCorner.X = tr.UpperLeftCorner.X + 1;
			Driver->draw2DRectangle(getColor(EGDC_3D_SHADOW), tr, clip);

			// draw lower shadow
			tr = rect;
			tr.UpperLeftCorner.Y = tr.LowerRightCorner.Y - 1;
			Driver->draw2DRectangle(getColor(EGDC_3D_SHADOW), tr, clip);
		}

		if (background)
		{
			tr = rect;
			tr.UpperLeftCorner.Y += getSize(gui::EGDS_BUTTON_HEIGHT) + 2;
			tr.LowerRightCorner.X -= 1;
			tr.UpperLeftCorner.X += 1;
			tr.LowerRightCorner.Y -= 1;

			Driver->draw2DRectangle(getColor(EGDC_3D_FACE), tr, clip);
		}
	}
}

void CAnimatedSpriteSkin::drawSprite(scene::TAnimSpriteSceneNode *Sprite,  core::rect<s32> rect)
{
	if(Sprite)
	{
		Sprite->Update();
		Sprite->setScaleToRect(rect);
		Sprite->setPosition(rect);
		Sprite->render();
	}
}

} // end namespace gui
} // end namespace irr

