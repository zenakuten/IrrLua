/*
** Lua binding: IrrLuaSpriteSkin
** Generated automatically by tolua++-1.0.92 on 08/23/06 21:56:23.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_IrrLuaSpriteSkin_open (lua_State* tolua_S);

#include "IrrLuaSpriteSkin.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_irr__gui__CAnimatedSpriteSkin (lua_State* tolua_S)
{
 irr::gui::CAnimatedSpriteSkin* self = (irr::gui::CAnimatedSpriteSkin*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_irr__gui__IGUISkin (lua_State* tolua_S)
{
 irr::gui::IGUISkin* self = (irr::gui::IGUISkin*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_irr__core__rect_s32_ (lua_State* tolua_S)
{
 irr::core::rect<s32>* self = (irr::core::rect<s32>*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}

static int tolua_collect_irr__video__SColor (lua_State* tolua_S)
{
 irr::video::SColor* self = (irr::video::SColor*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"irr::gui::IGUIElement");
 tolua_usertype(tolua_S,"irr::IUnknown");
 tolua_usertype(tolua_S,"irr::video::SColor");
 tolua_usertype(tolua_S,"irr::ITimer");
 tolua_usertype(tolua_S,"irr::gui::IGUISkin");
 tolua_usertype(tolua_S,"irr::core::rect<s32>");
 tolua_usertype(tolua_S,"irr::scene::ISceneManager");
 tolua_usertype(tolua_S,"c8");
 tolua_usertype(tolua_S,"irr::video::IVideoDriver");
 tolua_usertype(tolua_S,"irr::gui::IGUIFont");
 tolua_usertype(tolua_S,"irr::gui::CAnimatedSpriteSkin");
 tolua_usertype(tolua_S,"wchar_t");
}

/* method: delete of class  irr::gui::IGUISkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_delete00
static int tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::IGUISkin",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::IGUISkin* self = (irr::gui::IGUISkin*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getColor of class  irr::gui::IGUISkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_getColor00
static int tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_getColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::IGUISkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::IGUISkin* self = (irr::gui::IGUISkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::EGUI_DEFAULT_COLOR color = ((irr::gui::EGUI_DEFAULT_COLOR) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColor'",NULL);
#endif
  {
   irr::video::SColor tolua_ret = (irr::video::SColor)  self->getColor(color);
   {
#ifdef __cplusplus
    void* tolua_obj = new irr::video::SColor(tolua_ret);
    tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"irr::video::SColor");
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::video::SColor));
    tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"irr::video::SColor");
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColor of class  irr::gui::IGUISkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_setColor00
static int tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::IGUISkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"irr::video::SColor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::IGUISkin* self = (irr::gui::IGUISkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::EGUI_DEFAULT_COLOR which = ((irr::gui::EGUI_DEFAULT_COLOR) (int)  tolua_tonumber(tolua_S,2,0));
  irr::video::SColor newColor = *((irr::video::SColor*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColor'",NULL);
#endif
  {
   self->setColor(which,newColor);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSize of class  irr::gui::IGUISkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_getSize00
static int tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_getSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::IGUISkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::IGUISkin* self = (irr::gui::IGUISkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::EGUI_DEFAULT_SIZE size = ((irr::gui::EGUI_DEFAULT_SIZE) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSize'",NULL);
#endif
  {
   signed int tolua_ret = ( signed int)  self->getSize(size);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDefaultText of class  irr::gui::IGUISkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_getDefaultText00
static int tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_getDefaultText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::IGUISkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::IGUISkin* self = (irr::gui::IGUISkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::EGUI_DEFAULT_TEXT text = ((irr::gui::EGUI_DEFAULT_TEXT) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDefaultText'",NULL);
#endif
  {
   wchar_t* tolua_ret = (wchar_t*)  self->getDefaultText(text);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"wchar_t");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDefaultText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDefaultText of class  irr::gui::IGUISkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_setDefaultText00
static int tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_setDefaultText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::IGUISkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wchar_t",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::IGUISkin* self = (irr::gui::IGUISkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::EGUI_DEFAULT_TEXT which = ((irr::gui::EGUI_DEFAULT_TEXT) (int)  tolua_tonumber(tolua_S,2,0));
  wchar_t* newText = ((wchar_t*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDefaultText'",NULL);
#endif
  {
   self->setDefaultText(which,newText);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDefaultText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSize of class  irr::gui::IGUISkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_setSize00
static int tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_setSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::IGUISkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::IGUISkin* self = (irr::gui::IGUISkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::EGUI_DEFAULT_SIZE which = ((irr::gui::EGUI_DEFAULT_SIZE) (int)  tolua_tonumber(tolua_S,2,0));
  signed int size = (( signed int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSize'",NULL);
#endif
  {
   self->setSize(which,size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFont of class  irr::gui::IGUISkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_getFont00
static int tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_getFont00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::IGUISkin",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::IGUISkin* self = (irr::gui::IGUISkin*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFont'",NULL);
#endif
  {
   irr::gui::IGUIFont* tolua_ret = (irr::gui::IGUIFont*)  self->getFont();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::gui::IGUIFont");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFont'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFont of class  irr::gui::IGUISkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_setFont00
static int tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_setFont00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::IGUISkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::IGUIFont",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::IGUISkin* self = (irr::gui::IGUISkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::IGUIFont* font = ((irr::gui::IGUIFont*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFont'",NULL);
#endif
  {
   self->setFont(font);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFont'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw3DButtonPaneStandard of class  irr::gui::IGUISkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_draw3DButtonPaneStandard00
static int tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_draw3DButtonPaneStandard00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::IGUISkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::IGUIElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::IGUISkin* self = (irr::gui::IGUISkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::IGUIElement* element = ((irr::gui::IGUIElement*)  tolua_tousertype(tolua_S,2,0));
  irr::core::rect<s32>* rect = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,3,0));
  irr::core::rect<s32>* clip = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw3DButtonPaneStandard'",NULL);
#endif
  {
   self->draw3DButtonPaneStandard(element,*rect,clip);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw3DButtonPaneStandard'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw3DButtonPanePressed of class  irr::gui::IGUISkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_draw3DButtonPanePressed00
static int tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_draw3DButtonPanePressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::IGUISkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::IGUIElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::IGUISkin* self = (irr::gui::IGUISkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::IGUIElement* element = ((irr::gui::IGUIElement*)  tolua_tousertype(tolua_S,2,0));
  irr::core::rect<s32>* rect = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,3,0));
  irr::core::rect<s32>* clip = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw3DButtonPanePressed'",NULL);
#endif
  {
   self->draw3DButtonPanePressed(element,*rect,clip);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw3DButtonPanePressed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw3DSunkenPane of class  irr::gui::IGUISkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_draw3DSunkenPane00
static int tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_draw3DSunkenPane00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::IGUISkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::IGUIElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"irr::video::SColor",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,6,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,7,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::IGUISkin* self = (irr::gui::IGUISkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::IGUIElement* element = ((irr::gui::IGUIElement*)  tolua_tousertype(tolua_S,2,0));
  irr::video::SColor bgcolor = *((irr::video::SColor*)  tolua_tousertype(tolua_S,3,0));
  bool flat = ((bool)  tolua_toboolean(tolua_S,4,0));
  bool fillBackGround = ((bool)  tolua_toboolean(tolua_S,5,0));
  irr::core::rect<s32>* rect = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,6,0));
  irr::core::rect<s32>* clip = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw3DSunkenPane'",NULL);
#endif
  {
   self->draw3DSunkenPane(element,bgcolor,flat,fillBackGround,*rect,clip);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw3DSunkenPane'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw3DWindowBackground of class  irr::gui::IGUISkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_draw3DWindowBackground00
static int tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_draw3DWindowBackground00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::IGUISkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::IGUIElement",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"irr::video::SColor",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,6,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::IGUISkin* self = (irr::gui::IGUISkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::IGUIElement* element = ((irr::gui::IGUIElement*)  tolua_tousertype(tolua_S,2,0));
  bool drawTitleBar = ((bool)  tolua_toboolean(tolua_S,3,0));
  irr::video::SColor titleBarColor = *((irr::video::SColor*)  tolua_tousertype(tolua_S,4,0));
  irr::core::rect<s32>* rect = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,5,0));
  irr::core::rect<s32>* clip = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw3DWindowBackground'",NULL);
#endif
  {
   irr::core::rect<s32> tolua_ret = (irr::core::rect<s32>)  self->draw3DWindowBackground(element,drawTitleBar,titleBarColor,*rect,clip);
   {
#ifdef __cplusplus
    void* tolua_obj = new irr::core::rect<s32>(tolua_ret);
    tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"irr::core::rect<s32>");
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::rect<s32>));
    tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"irr::core::rect<s32>");
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw3DWindowBackground'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw3DMenuPane of class  irr::gui::IGUISkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_draw3DMenuPane00
static int tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_draw3DMenuPane00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::IGUISkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::IGUIElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::IGUISkin* self = (irr::gui::IGUISkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::IGUIElement* element = ((irr::gui::IGUIElement*)  tolua_tousertype(tolua_S,2,0));
  irr::core::rect<s32>* rect = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,3,0));
  irr::core::rect<s32>* clip = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw3DMenuPane'",NULL);
#endif
  {
   self->draw3DMenuPane(element,*rect,clip);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw3DMenuPane'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw3DToolBar of class  irr::gui::IGUISkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_draw3DToolBar00
static int tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_draw3DToolBar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::IGUISkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::IGUIElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::IGUISkin* self = (irr::gui::IGUISkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::IGUIElement* element = ((irr::gui::IGUIElement*)  tolua_tousertype(tolua_S,2,0));
  irr::core::rect<s32>* rect = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,3,0));
  irr::core::rect<s32>* clip = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw3DToolBar'",NULL);
#endif
  {
   self->draw3DToolBar(element,*rect,clip);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw3DToolBar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw3DTabButton of class  irr::gui::IGUISkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_draw3DTabButton00
static int tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_draw3DTabButton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::IGUISkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::IGUIElement",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::IGUISkin* self = (irr::gui::IGUISkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::IGUIElement* element = ((irr::gui::IGUIElement*)  tolua_tousertype(tolua_S,2,0));
  bool active = ((bool)  tolua_toboolean(tolua_S,3,0));
  irr::core::rect<s32>* rect = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,4,0));
  irr::core::rect<s32>* clip = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw3DTabButton'",NULL);
#endif
  {
   self->draw3DTabButton(element,active,*rect,clip);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw3DTabButton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw3DTabBody of class  irr::gui::IGUISkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_draw3DTabBody00
static int tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_draw3DTabBody00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::IGUISkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::IGUIElement",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,6,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::IGUISkin* self = (irr::gui::IGUISkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::IGUIElement* element = ((irr::gui::IGUIElement*)  tolua_tousertype(tolua_S,2,0));
  bool border = ((bool)  tolua_toboolean(tolua_S,3,0));
  bool background = ((bool)  tolua_toboolean(tolua_S,4,0));
  irr::core::rect<s32>* rect = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,5,0));
  irr::core::rect<s32>* clip = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw3DTabBody'",NULL);
#endif
  {
   self->draw3DTabBody(element,border,background,*rect,clip);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw3DTabBody'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: grab of class  irr::gui::IGUISkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_grab00
static int tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_grab00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::IGUISkin",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::IGUISkin* self = (irr::gui::IGUISkin*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'grab'",NULL);
#endif
  {
   self->grab();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'grab'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: drop of class  irr::gui::IGUISkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_drop00
static int tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_drop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::IGUISkin",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::IGUISkin* self = (irr::gui::IGUISkin*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'drop'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->drop();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'drop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDebugName of class  irr::gui::IGUISkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_getDebugName00
static int tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_getDebugName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::IGUISkin",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::IGUISkin* self = (irr::gui::IGUISkin*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDebugName'",NULL);
#endif
  {
   c8* tolua_ret = (c8*)  self->getDebugName();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"c8");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDebugName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  irr::gui::CAnimatedSpriteSkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_new00
static int tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::gui::CAnimatedSpriteSkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::video::IVideoDriver",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"irr::scene::ISceneManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"irr::ITimer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::video::IVideoDriver* driver = ((irr::video::IVideoDriver*)  tolua_tousertype(tolua_S,2,0));
  irr::scene::ISceneManager* scm = ((irr::scene::ISceneManager*)  tolua_tousertype(tolua_S,3,0));
  irr::ITimer* timer = ((irr::ITimer*)  tolua_tousertype(tolua_S,4,0));
  {
   irr::gui::CAnimatedSpriteSkin* tolua_ret = (irr::gui::CAnimatedSpriteSkin*)  new irr::gui::CAnimatedSpriteSkin(driver,scm,timer);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::gui::CAnimatedSpriteSkin");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  irr::gui::CAnimatedSpriteSkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_new00_local
static int tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::gui::CAnimatedSpriteSkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::video::IVideoDriver",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"irr::scene::ISceneManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"irr::ITimer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::video::IVideoDriver* driver = ((irr::video::IVideoDriver*)  tolua_tousertype(tolua_S,2,0));
  irr::scene::ISceneManager* scm = ((irr::scene::ISceneManager*)  tolua_tousertype(tolua_S,3,0));
  irr::ITimer* timer = ((irr::ITimer*)  tolua_tousertype(tolua_S,4,0));
  {
   irr::gui::CAnimatedSpriteSkin* tolua_ret = (irr::gui::CAnimatedSpriteSkin*)  new irr::gui::CAnimatedSpriteSkin(driver,scm,timer);
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"irr::gui::CAnimatedSpriteSkin");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  irr::gui::CAnimatedSpriteSkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_delete00
static int tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CAnimatedSpriteSkin",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CAnimatedSpriteSkin* self = (irr::gui::CAnimatedSpriteSkin*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  delete self;
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Load of class  irr::gui::CAnimatedSpriteSkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_Load00
static int tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_Load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CAnimatedSpriteSkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,10,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,11,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CAnimatedSpriteSkin* self = (irr::gui::CAnimatedSpriteSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::EGUI_ELEMENT_IMAGE_TYPE Type = ((irr::gui::EGUI_ELEMENT_IMAGE_TYPE) (int)  tolua_tonumber(tolua_S,2,0));
  std::string filename = ((std::string)  tolua_tocppstring(tolua_S,3,0));
  signed int Ax = (( signed int)  tolua_tonumber(tolua_S,4,0));
  signed int Ay = (( signed int)  tolua_tonumber(tolua_S,5,0));
  signed int Aw = (( signed int)  tolua_tonumber(tolua_S,6,0));
  signed int Ah = (( signed int)  tolua_tonumber(tolua_S,7,0));
  signed int frmWidth = (( signed int)  tolua_tonumber(tolua_S,8,0));
  signed int frmHeight = (( signed int)  tolua_tonumber(tolua_S,9,0));
  bool useClrKey = ((bool)  tolua_toboolean(tolua_S,10,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Load'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Load(Type,filename,Ax,Ay,Aw,Ah,frmWidth,frmHeight,useClrKey);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Load'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAnimationSpeed of class  irr::gui::CAnimatedSpriteSkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_getAnimationSpeed00
static int tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_getAnimationSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CAnimatedSpriteSkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CAnimatedSpriteSkin* self = (irr::gui::CAnimatedSpriteSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::EGUI_ELEMENT_IMAGE_TYPE Type = ((irr::gui::EGUI_ELEMENT_IMAGE_TYPE) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAnimationSpeed'",NULL);
#endif
  {
   signed int tolua_ret = ( signed int)  self->getAnimationSpeed(Type);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAnimationSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAnimationSpeed of class  irr::gui::CAnimatedSpriteSkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_setAnimationSpeed00
static int tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_setAnimationSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CAnimatedSpriteSkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CAnimatedSpriteSkin* self = (irr::gui::CAnimatedSpriteSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::EGUI_ELEMENT_IMAGE_TYPE Type = ((irr::gui::EGUI_ELEMENT_IMAGE_TYPE) (int)  tolua_tonumber(tolua_S,2,0));
  signed int spd = (( signed int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setAnimationSpeed'",NULL);
#endif
  {
   self->setAnimationSpeed(Type,spd);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAnimationSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLoop of class  irr::gui::CAnimatedSpriteSkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_setLoop00
static int tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_setLoop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CAnimatedSpriteSkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CAnimatedSpriteSkin* self = (irr::gui::CAnimatedSpriteSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::EGUI_ELEMENT_IMAGE_TYPE Type = ((irr::gui::EGUI_ELEMENT_IMAGE_TYPE) (int)  tolua_tonumber(tolua_S,2,0));
  bool l = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLoop'",NULL);
#endif
  {
   self->setLoop(Type,l);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLoop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLoop of class  irr::gui::CAnimatedSpriteSkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_getLoop00
static int tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_getLoop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CAnimatedSpriteSkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CAnimatedSpriteSkin* self = (irr::gui::CAnimatedSpriteSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::EGUI_ELEMENT_IMAGE_TYPE Type = ((irr::gui::EGUI_ELEMENT_IMAGE_TYPE) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLoop'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getLoop(Type);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLoop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: playForward of class  irr::gui::CAnimatedSpriteSkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_playForward00
static int tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_playForward00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CAnimatedSpriteSkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CAnimatedSpriteSkin* self = (irr::gui::CAnimatedSpriteSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::EGUI_ELEMENT_IMAGE_TYPE Type = ((irr::gui::EGUI_ELEMENT_IMAGE_TYPE) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'playForward'",NULL);
#endif
  {
   self->playForward(Type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'playForward'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: playBackward of class  irr::gui::CAnimatedSpriteSkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_playBackward00
static int tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_playBackward00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CAnimatedSpriteSkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CAnimatedSpriteSkin* self = (irr::gui::CAnimatedSpriteSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::EGUI_ELEMENT_IMAGE_TYPE Type = ((irr::gui::EGUI_ELEMENT_IMAGE_TYPE) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'playBackward'",NULL);
#endif
  {
   self->playBackward(Type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'playBackward'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resetAnimation of class  irr::gui::CAnimatedSpriteSkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_resetAnimation00
static int tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_resetAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CAnimatedSpriteSkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CAnimatedSpriteSkin* self = (irr::gui::CAnimatedSpriteSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::EGUI_ELEMENT_IMAGE_TYPE Type = ((irr::gui::EGUI_ELEMENT_IMAGE_TYPE) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resetAnimation'",NULL);
#endif
  {
   self->resetAnimation(Type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resetAnimation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getColor of class  irr::gui::CAnimatedSpriteSkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_getColor00
static int tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_getColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CAnimatedSpriteSkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CAnimatedSpriteSkin* self = (irr::gui::CAnimatedSpriteSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::EGUI_DEFAULT_COLOR color = ((irr::gui::EGUI_DEFAULT_COLOR) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getColor'",NULL);
#endif
  {
   irr::video::SColor tolua_ret = (irr::video::SColor)  self->getColor(color);
   {
#ifdef __cplusplus
    void* tolua_obj = new irr::video::SColor(tolua_ret);
    tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"irr::video::SColor");
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::video::SColor));
    tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"irr::video::SColor");
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColor of class  irr::gui::CAnimatedSpriteSkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_setColor00
static int tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CAnimatedSpriteSkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"irr::video::SColor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CAnimatedSpriteSkin* self = (irr::gui::CAnimatedSpriteSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::EGUI_DEFAULT_COLOR which = ((irr::gui::EGUI_DEFAULT_COLOR) (int)  tolua_tonumber(tolua_S,2,0));
  irr::video::SColor newColor = *((irr::video::SColor*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColor'",NULL);
#endif
  {
   self->setColor(which,newColor);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSize of class  irr::gui::CAnimatedSpriteSkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_getSize00
static int tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_getSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CAnimatedSpriteSkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CAnimatedSpriteSkin* self = (irr::gui::CAnimatedSpriteSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::EGUI_DEFAULT_SIZE size = ((irr::gui::EGUI_DEFAULT_SIZE) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSize'",NULL);
#endif
  {
   signed int tolua_ret = ( signed int)  self->getSize(size);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSize of class  irr::gui::CAnimatedSpriteSkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_setSize00
static int tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_setSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CAnimatedSpriteSkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CAnimatedSpriteSkin* self = (irr::gui::CAnimatedSpriteSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::EGUI_DEFAULT_SIZE which = ((irr::gui::EGUI_DEFAULT_SIZE) (int)  tolua_tonumber(tolua_S,2,0));
  signed int size = (( signed int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSize'",NULL);
#endif
  {
   self->setSize(which,size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFont of class  irr::gui::CAnimatedSpriteSkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_getFont00
static int tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_getFont00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CAnimatedSpriteSkin",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CAnimatedSpriteSkin* self = (irr::gui::CAnimatedSpriteSkin*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFont'",NULL);
#endif
  {
   irr::gui::IGUIFont* tolua_ret = (irr::gui::IGUIFont*)  self->getFont();
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::gui::IGUIFont");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFont'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setFont of class  irr::gui::CAnimatedSpriteSkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_setFont00
static int tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_setFont00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CAnimatedSpriteSkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::IGUIFont",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CAnimatedSpriteSkin* self = (irr::gui::CAnimatedSpriteSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::IGUIFont* font = ((irr::gui::IGUIFont*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setFont'",NULL);
#endif
  {
   self->setFont(font);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setFont'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDefaultText of class  irr::gui::CAnimatedSpriteSkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_getDefaultText00
static int tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_getDefaultText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CAnimatedSpriteSkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CAnimatedSpriteSkin* self = (irr::gui::CAnimatedSpriteSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::EGUI_DEFAULT_TEXT text = ((irr::gui::EGUI_DEFAULT_TEXT) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDefaultText'",NULL);
#endif
  {
   wchar_t* tolua_ret = (wchar_t*)  self->getDefaultText(text);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"wchar_t");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDefaultText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDefaultText of class  irr::gui::CAnimatedSpriteSkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_setDefaultText00
static int tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_setDefaultText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CAnimatedSpriteSkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wchar_t",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CAnimatedSpriteSkin* self = (irr::gui::CAnimatedSpriteSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::EGUI_DEFAULT_TEXT which = ((irr::gui::EGUI_DEFAULT_TEXT) (int)  tolua_tonumber(tolua_S,2,0));
  wchar_t* newText = ((wchar_t*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDefaultText'",NULL);
#endif
  {
   self->setDefaultText(which,newText);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDefaultText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw3DButtonPaneStandard of class  irr::gui::CAnimatedSpriteSkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_draw3DButtonPaneStandard00
static int tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_draw3DButtonPaneStandard00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CAnimatedSpriteSkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::IGUIElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CAnimatedSpriteSkin* self = (irr::gui::CAnimatedSpriteSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::IGUIElement* element = ((irr::gui::IGUIElement*)  tolua_tousertype(tolua_S,2,0));
  irr::core::rect<s32>* rect = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,3,0));
  irr::core::rect<s32>* clip = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw3DButtonPaneStandard'",NULL);
#endif
  {
   self->draw3DButtonPaneStandard(element,*rect,clip);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw3DButtonPaneStandard'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw3DButtonPanePressed of class  irr::gui::CAnimatedSpriteSkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_draw3DButtonPanePressed00
static int tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_draw3DButtonPanePressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CAnimatedSpriteSkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::IGUIElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CAnimatedSpriteSkin* self = (irr::gui::CAnimatedSpriteSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::IGUIElement* element = ((irr::gui::IGUIElement*)  tolua_tousertype(tolua_S,2,0));
  irr::core::rect<s32>* rect = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,3,0));
  irr::core::rect<s32>* clip = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw3DButtonPanePressed'",NULL);
#endif
  {
   self->draw3DButtonPanePressed(element,*rect,clip);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw3DButtonPanePressed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw3DSunkenPane of class  irr::gui::CAnimatedSpriteSkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_draw3DSunkenPane00
static int tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_draw3DSunkenPane00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CAnimatedSpriteSkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::IGUIElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"irr::video::SColor",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,5,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,6,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,7,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CAnimatedSpriteSkin* self = (irr::gui::CAnimatedSpriteSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::IGUIElement* element = ((irr::gui::IGUIElement*)  tolua_tousertype(tolua_S,2,0));
  irr::video::SColor bgcolor = *((irr::video::SColor*)  tolua_tousertype(tolua_S,3,0));
  bool flat = ((bool)  tolua_toboolean(tolua_S,4,0));
  bool fillBackGround = ((bool)  tolua_toboolean(tolua_S,5,0));
  irr::core::rect<s32>* rect = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,6,0));
  irr::core::rect<s32>* clip = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,7,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw3DSunkenPane'",NULL);
#endif
  {
   self->draw3DSunkenPane(element,bgcolor,flat,fillBackGround,*rect,clip);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw3DSunkenPane'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw3DWindowBackground of class  irr::gui::CAnimatedSpriteSkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_draw3DWindowBackground00
static int tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_draw3DWindowBackground00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CAnimatedSpriteSkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::IGUIElement",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"irr::video::SColor",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,6,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CAnimatedSpriteSkin* self = (irr::gui::CAnimatedSpriteSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::IGUIElement* element = ((irr::gui::IGUIElement*)  tolua_tousertype(tolua_S,2,0));
  bool drawTitleBar = ((bool)  tolua_toboolean(tolua_S,3,0));
  irr::video::SColor titleBarColor = *((irr::video::SColor*)  tolua_tousertype(tolua_S,4,0));
  irr::core::rect<s32>* rect = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,5,0));
  irr::core::rect<s32>* clip = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw3DWindowBackground'",NULL);
#endif
  {
   irr::core::rect<s32> tolua_ret = (irr::core::rect<s32>)  self->draw3DWindowBackground(element,drawTitleBar,titleBarColor,*rect,clip);
   {
#ifdef __cplusplus
    void* tolua_obj = new irr::core::rect<s32>(tolua_ret);
    tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"irr::core::rect<s32>");
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(irr::core::rect<s32>));
    tolua_pushusertype_and_takeownership(tolua_S,tolua_obj,"irr::core::rect<s32>");
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw3DWindowBackground'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw3DMenuPane of class  irr::gui::CAnimatedSpriteSkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_draw3DMenuPane00
static int tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_draw3DMenuPane00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CAnimatedSpriteSkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::IGUIElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CAnimatedSpriteSkin* self = (irr::gui::CAnimatedSpriteSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::IGUIElement* element = ((irr::gui::IGUIElement*)  tolua_tousertype(tolua_S,2,0));
  irr::core::rect<s32>* rect = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,3,0));
  irr::core::rect<s32>* clip = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw3DMenuPane'",NULL);
#endif
  {
   self->draw3DMenuPane(element,*rect,clip);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw3DMenuPane'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw3DToolBar of class  irr::gui::CAnimatedSpriteSkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_draw3DToolBar00
static int tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_draw3DToolBar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CAnimatedSpriteSkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::IGUIElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CAnimatedSpriteSkin* self = (irr::gui::CAnimatedSpriteSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::IGUIElement* element = ((irr::gui::IGUIElement*)  tolua_tousertype(tolua_S,2,0));
  irr::core::rect<s32>* rect = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,3,0));
  irr::core::rect<s32>* clip = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw3DToolBar'",NULL);
#endif
  {
   self->draw3DToolBar(element,*rect,clip);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw3DToolBar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw3DTabButton of class  irr::gui::CAnimatedSpriteSkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_draw3DTabButton00
static int tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_draw3DTabButton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CAnimatedSpriteSkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::IGUIElement",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CAnimatedSpriteSkin* self = (irr::gui::CAnimatedSpriteSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::IGUIElement* element = ((irr::gui::IGUIElement*)  tolua_tousertype(tolua_S,2,0));
  bool active = ((bool)  tolua_toboolean(tolua_S,3,0));
  irr::core::rect<s32>* rect = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,4,0));
  irr::core::rect<s32>* clip = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw3DTabButton'",NULL);
#endif
  {
   self->draw3DTabButton(element,active,*rect,clip);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw3DTabButton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: draw3DTabBody of class  irr::gui::CAnimatedSpriteSkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_draw3DTabBody00
static int tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_draw3DTabBody00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CAnimatedSpriteSkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::IGUIElement",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,6,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CAnimatedSpriteSkin* self = (irr::gui::CAnimatedSpriteSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::IGUIElement* element = ((irr::gui::IGUIElement*)  tolua_tousertype(tolua_S,2,0));
  bool border = ((bool)  tolua_toboolean(tolua_S,3,0));
  bool background = ((bool)  tolua_toboolean(tolua_S,4,0));
  irr::core::rect<s32>* rect = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,5,0));
  irr::core::rect<s32>* clip = ((irr::core::rect<s32>*)  tolua_tousertype(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'draw3DTabBody'",NULL);
#endif
  {
   self->draw3DTabBody(element,border,background,*rect,clip);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'draw3DTabBody'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: irr::gui::createAnimatedSpriteSkin */
#ifndef TOLUA_DISABLE_tolua_IrrLuaSpriteSkin_irr_gui_createAnimatedSpriteSkin00
static int tolua_IrrLuaSpriteSkin_irr_gui_createAnimatedSpriteSkin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::video::IVideoDriver",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::scene::ISceneManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"irr::ITimer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::video::IVideoDriver* Driver = ((irr::video::IVideoDriver*)  tolua_tousertype(tolua_S,1,0));
  irr::scene::ISceneManager* Manager = ((irr::scene::ISceneManager*)  tolua_tousertype(tolua_S,2,0));
  irr::ITimer* Timer = ((irr::ITimer*)  tolua_tousertype(tolua_S,3,0));
  {
   irr::gui::CAnimatedSpriteSkin* tolua_ret = (irr::gui::CAnimatedSpriteSkin*)  irr::gui::createAnimatedSpriteSkin(Driver,Manager,Timer);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::gui::CAnimatedSpriteSkin");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createAnimatedSpriteSkin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_IrrLuaSpriteSkin_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"irr",0);
  tolua_beginmodule(tolua_S,"irr");
   tolua_module(tolua_S,"gui",0);
   tolua_beginmodule(tolua_S,"gui");
    tolua_cclass(tolua_S,"IGUIFont","irr::gui::IGUIFont","",NULL);
    tolua_beginmodule(tolua_S,"IGUIFont");
    tolua_endmodule(tolua_S);
    tolua_constant(tolua_S,"EGST_WINDOWS_CLASSIC",irr::gui::EGST_WINDOWS_CLASSIC);
    tolua_constant(tolua_S,"EGST_WINDOWS_METALLIC",irr::gui::EGST_WINDOWS_METALLIC);
    tolua_constant(tolua_S,"EGDC_3D_DARK_SHADOW",irr::gui::EGDC_3D_DARK_SHADOW);
    tolua_constant(tolua_S,"EGDC_3D_SHADOW",irr::gui::EGDC_3D_SHADOW);
    tolua_constant(tolua_S,"EGDC_3D_FACE",irr::gui::EGDC_3D_FACE);
    tolua_constant(tolua_S,"EGDC_3D_HIGH_LIGHT",irr::gui::EGDC_3D_HIGH_LIGHT);
    tolua_constant(tolua_S,"EGDC_3D_LIGHT",irr::gui::EGDC_3D_LIGHT);
    tolua_constant(tolua_S,"EGDC_ACTIVE_BORDER",irr::gui::EGDC_ACTIVE_BORDER);
    tolua_constant(tolua_S,"EGDC_ACTIVE_CAPTION",irr::gui::EGDC_ACTIVE_CAPTION);
    tolua_constant(tolua_S,"EGDC_APP_WORKSPACE",irr::gui::EGDC_APP_WORKSPACE);
    tolua_constant(tolua_S,"EGDC_BUTTON_TEXT",irr::gui::EGDC_BUTTON_TEXT);
    tolua_constant(tolua_S,"EGDC_GRAY_TEXT",irr::gui::EGDC_GRAY_TEXT);
    tolua_constant(tolua_S,"EGDC_HIGH_LIGHT",irr::gui::EGDC_HIGH_LIGHT);
    tolua_constant(tolua_S,"EGDC_HIGH_LIGHT_TEXT",irr::gui::EGDC_HIGH_LIGHT_TEXT);
    tolua_constant(tolua_S,"EGDC_INACTIVE_BORDER",irr::gui::EGDC_INACTIVE_BORDER);
    tolua_constant(tolua_S,"EGDC_INACTIVE_CAPTION",irr::gui::EGDC_INACTIVE_CAPTION);
    tolua_constant(tolua_S,"EGDC_TOOLTIP",irr::gui::EGDC_TOOLTIP);
    tolua_constant(tolua_S,"EGDC_SCROLLBAR",irr::gui::EGDC_SCROLLBAR);
    tolua_constant(tolua_S,"EGDC_WINDOW",irr::gui::EGDC_WINDOW);
    tolua_constant(tolua_S,"EGDC_COUNT",irr::gui::EGDC_COUNT);
    tolua_constant(tolua_S,"EGDS_SCROLLBAR_SIZE",irr::gui::EGDS_SCROLLBAR_SIZE);
    tolua_constant(tolua_S,"EGDS_MENU_HEIGHT",irr::gui::EGDS_MENU_HEIGHT);
    tolua_constant(tolua_S,"EGDS_WINDOW_BUTTON_WIDTH",irr::gui::EGDS_WINDOW_BUTTON_WIDTH);
    tolua_constant(tolua_S,"EGDS_CHECK_BOX_WIDTH",irr::gui::EGDS_CHECK_BOX_WIDTH);
    tolua_constant(tolua_S,"EGDS_MESSAGE_BOX_WIDTH",irr::gui::EGDS_MESSAGE_BOX_WIDTH);
    tolua_constant(tolua_S,"EGDS_MESSAGE_BOX_HEIGHT",irr::gui::EGDS_MESSAGE_BOX_HEIGHT);
    tolua_constant(tolua_S,"EGDS_BUTTON_WIDTH",irr::gui::EGDS_BUTTON_WIDTH);
    tolua_constant(tolua_S,"EGDS_BUTTON_HEIGHT",irr::gui::EGDS_BUTTON_HEIGHT);
    tolua_constant(tolua_S,"EGDS_COUNT",irr::gui::EGDS_COUNT);
    tolua_constant(tolua_S,"EGDT_MSG_BOX_OK",irr::gui::EGDT_MSG_BOX_OK);
    tolua_constant(tolua_S,"EGDT_MSG_BOX_CANCEL",irr::gui::EGDT_MSG_BOX_CANCEL);
    tolua_constant(tolua_S,"EGDT_MSG_BOX_YES",irr::gui::EGDT_MSG_BOX_YES);
    tolua_constant(tolua_S,"EGDT_MSG_BOX_NO",irr::gui::EGDT_MSG_BOX_NO);
    tolua_constant(tolua_S,"EGDT_COUNT",irr::gui::EGDT_COUNT);
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"IGUISkin","irr::gui::IGUISkin","irr::IUnknown",tolua_collect_irr__gui__IGUISkin);
    #else
    tolua_cclass(tolua_S,"IGUISkin","irr::gui::IGUISkin","irr::IUnknown",NULL);
    #endif
    tolua_beginmodule(tolua_S,"IGUISkin");
     tolua_function(tolua_S,"delete",tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_delete00);
     tolua_function(tolua_S,"getColor",tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_getColor00);
     tolua_function(tolua_S,"setColor",tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_setColor00);
     tolua_function(tolua_S,"getSize",tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_getSize00);
     tolua_function(tolua_S,"getDefaultText",tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_getDefaultText00);
     tolua_function(tolua_S,"setDefaultText",tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_setDefaultText00);
     tolua_function(tolua_S,"setSize",tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_setSize00);
     tolua_function(tolua_S,"getFont",tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_getFont00);
     tolua_function(tolua_S,"setFont",tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_setFont00);
     tolua_function(tolua_S,"draw3DButtonPaneStandard",tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_draw3DButtonPaneStandard00);
     tolua_function(tolua_S,"draw3DButtonPanePressed",tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_draw3DButtonPanePressed00);
     tolua_function(tolua_S,"draw3DSunkenPane",tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_draw3DSunkenPane00);
     tolua_function(tolua_S,"draw3DWindowBackground",tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_draw3DWindowBackground00);
     tolua_function(tolua_S,"draw3DMenuPane",tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_draw3DMenuPane00);
     tolua_function(tolua_S,"draw3DToolBar",tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_draw3DToolBar00);
     tolua_function(tolua_S,"draw3DTabButton",tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_draw3DTabButton00);
     tolua_function(tolua_S,"draw3DTabBody",tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_draw3DTabBody00);
     tolua_function(tolua_S,"grab",tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_grab00);
     tolua_function(tolua_S,"drop",tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_drop00);
     tolua_function(tolua_S,"getDebugName",tolua_IrrLuaSpriteSkin_irr_gui_IGUISkin_getDebugName00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"irr",0);
  tolua_beginmodule(tolua_S,"irr");
   tolua_module(tolua_S,"gui",0);
   tolua_beginmodule(tolua_S,"gui");
    tolua_constant(tolua_S,"EGEIT_BUTTON_PANE_STANDARD",irr::gui::EGEIT_BUTTON_PANE_STANDARD);
    tolua_constant(tolua_S,"EGEIT_BUTTON_PANE_PRESSED",irr::gui::EGEIT_BUTTON_PANE_PRESSED);
    tolua_constant(tolua_S,"EGEIT_SUNKEN_PANE_FLAT",irr::gui::EGEIT_SUNKEN_PANE_FLAT);
    tolua_constant(tolua_S,"EGEIT_SUNKEN_PANE_SUNKEN",irr::gui::EGEIT_SUNKEN_PANE_SUNKEN);
    tolua_constant(tolua_S,"EGEIT_WINDOW_BACKGROUND",irr::gui::EGEIT_WINDOW_BACKGROUND);
    tolua_constant(tolua_S,"EGEIT_WINDOW_BACKGROUND_TITLEBAR",irr::gui::EGEIT_WINDOW_BACKGROUND_TITLEBAR);
    tolua_constant(tolua_S,"EGEIT_MENU_PANE",irr::gui::EGEIT_MENU_PANE);
    tolua_constant(tolua_S,"EGEIT_TOOLBAR",irr::gui::EGEIT_TOOLBAR);
    tolua_constant(tolua_S,"EGEIT_TAB_BUTTON",irr::gui::EGEIT_TAB_BUTTON);
    tolua_constant(tolua_S,"EGEIT_TAB_BODY",irr::gui::EGEIT_TAB_BODY);
    tolua_constant(tolua_S,"EGEIT_COUNT",irr::gui::EGEIT_COUNT);
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"CAnimatedSpriteSkin","irr::gui::CAnimatedSpriteSkin","irr::gui::IGUISkin",tolua_collect_irr__gui__CAnimatedSpriteSkin);
    #else
    tolua_cclass(tolua_S,"CAnimatedSpriteSkin","irr::gui::CAnimatedSpriteSkin","irr::gui::IGUISkin",NULL);
    #endif
    tolua_beginmodule(tolua_S,"CAnimatedSpriteSkin");
     tolua_function(tolua_S,"new",tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_new00);
     tolua_function(tolua_S,"new_local",tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_new00_local);
     tolua_function(tolua_S,".call",tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_new00_local);
     tolua_function(tolua_S,"delete",tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_delete00);
     tolua_function(tolua_S,"Load",tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_Load00);
     tolua_function(tolua_S,"getAnimationSpeed",tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_getAnimationSpeed00);
     tolua_function(tolua_S,"setAnimationSpeed",tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_setAnimationSpeed00);
     tolua_function(tolua_S,"setLoop",tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_setLoop00);
     tolua_function(tolua_S,"getLoop",tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_getLoop00);
     tolua_function(tolua_S,"playForward",tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_playForward00);
     tolua_function(tolua_S,"playBackward",tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_playBackward00);
     tolua_function(tolua_S,"resetAnimation",tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_resetAnimation00);
     tolua_function(tolua_S,"getColor",tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_getColor00);
     tolua_function(tolua_S,"setColor",tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_setColor00);
     tolua_function(tolua_S,"getSize",tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_getSize00);
     tolua_function(tolua_S,"setSize",tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_setSize00);
     tolua_function(tolua_S,"getFont",tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_getFont00);
     tolua_function(tolua_S,"setFont",tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_setFont00);
     tolua_function(tolua_S,"getDefaultText",tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_getDefaultText00);
     tolua_function(tolua_S,"setDefaultText",tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_setDefaultText00);
     tolua_function(tolua_S,"draw3DButtonPaneStandard",tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_draw3DButtonPaneStandard00);
     tolua_function(tolua_S,"draw3DButtonPanePressed",tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_draw3DButtonPanePressed00);
     tolua_function(tolua_S,"draw3DSunkenPane",tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_draw3DSunkenPane00);
     tolua_function(tolua_S,"draw3DWindowBackground",tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_draw3DWindowBackground00);
     tolua_function(tolua_S,"draw3DMenuPane",tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_draw3DMenuPane00);
     tolua_function(tolua_S,"draw3DToolBar",tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_draw3DToolBar00);
     tolua_function(tolua_S,"draw3DTabButton",tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_draw3DTabButton00);
     tolua_function(tolua_S,"draw3DTabBody",tolua_IrrLuaSpriteSkin_irr_gui_CAnimatedSpriteSkin_draw3DTabBody00);
    tolua_endmodule(tolua_S);
    tolua_function(tolua_S,"createAnimatedSpriteSkin",tolua_IrrLuaSpriteSkin_irr_gui_createAnimatedSpriteSkin00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_IrrLuaSpriteSkin (lua_State* tolua_S) {
 return tolua_IrrLuaSpriteSkin_open(tolua_S);
};
#endif

