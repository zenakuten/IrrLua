/*
** Lua binding: CGUIImageSkin
** Generated automatically by tolua++-1.0.92 on 07/12/06 00:03:07.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_CGUIImageSkin_open (lua_State* tolua_S);

#include "IrrLuaSpriteSkin.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_irr__gui__CGUIImageSkin (lua_State* tolua_S)
{
 irr::gui::CGUIImageSkin* self = (irr::gui::CGUIImageSkin*) tolua_tousertype(tolua_S,1,0);
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
 tolua_usertype(tolua_S,"irr::scene::ISceneManager");
 tolua_usertype(tolua_S,"irr::ITimer");
 tolua_usertype(tolua_S,"irr::gui::IGUISkin");
 tolua_usertype(tolua_S,"irr::video::IVideoDriver");
 tolua_usertype(tolua_S,"irr::gui::EGUI_DEFAULT_COLOR");
 tolua_usertype(tolua_S,"irr::core::rect<s32>");
 tolua_usertype(tolua_S,"irr::gui::EGUI_DEFAULT_TEXT");
 tolua_usertype(tolua_S,"wchar_t");
 tolua_usertype(tolua_S,"irr::gui::CGUIImageSkin");
 tolua_usertype(tolua_S,"irr::gui::IGUIFont");
 tolua_usertype(tolua_S,"irr::gui::EGUI_DEFAULT_SIZE");
 tolua_usertype(tolua_S,"irr::video::SColor");
}

/* method: new of class  irr::gui::CGUIImageSkin */
#ifndef TOLUA_DISABLE_tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_new00
static int tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::gui::CGUIImageSkin",0,&tolua_err) ||
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
   irr::gui::CGUIImageSkin* tolua_ret = (irr::gui::CGUIImageSkin*)  new irr::gui::CGUIImageSkin(driver,scm,timer);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::gui::CGUIImageSkin");
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

/* method: new_local of class  irr::gui::CGUIImageSkin */
#ifndef TOLUA_DISABLE_tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_new00_local
static int tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"irr::gui::CGUIImageSkin",0,&tolua_err) ||
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
   irr::gui::CGUIImageSkin* tolua_ret = (irr::gui::CGUIImageSkin*)  new irr::gui::CGUIImageSkin(driver,scm,timer);
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"irr::gui::CGUIImageSkin");
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

/* method: delete of class  irr::gui::CGUIImageSkin */
#ifndef TOLUA_DISABLE_tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_delete00
static int tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CGUIImageSkin",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CGUIImageSkin* self = (irr::gui::CGUIImageSkin*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Load of class  irr::gui::CGUIImageSkin */
#ifndef TOLUA_DISABLE_tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_Load00
static int tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_Load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CGUIImageSkin",0,&tolua_err) ||
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
  irr::gui::CGUIImageSkin* self = (irr::gui::CGUIImageSkin*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getAnimationSpeed of class  irr::gui::CGUIImageSkin */
#ifndef TOLUA_DISABLE_tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_getAnimationSpeed00
static int tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_getAnimationSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CGUIImageSkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CGUIImageSkin* self = (irr::gui::CGUIImageSkin*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setAnimationSpeed of class  irr::gui::CGUIImageSkin */
#ifndef TOLUA_DISABLE_tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_setAnimationSpeed00
static int tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_setAnimationSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CGUIImageSkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CGUIImageSkin* self = (irr::gui::CGUIImageSkin*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setLoop of class  irr::gui::CGUIImageSkin */
#ifndef TOLUA_DISABLE_tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_setLoop00
static int tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_setLoop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CGUIImageSkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CGUIImageSkin* self = (irr::gui::CGUIImageSkin*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getLoop of class  irr::gui::CGUIImageSkin */
#ifndef TOLUA_DISABLE_tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_getLoop00
static int tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_getLoop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CGUIImageSkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CGUIImageSkin* self = (irr::gui::CGUIImageSkin*)  tolua_tousertype(tolua_S,1,0);
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

/* method: playForward of class  irr::gui::CGUIImageSkin */
#ifndef TOLUA_DISABLE_tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_playForward00
static int tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_playForward00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CGUIImageSkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CGUIImageSkin* self = (irr::gui::CGUIImageSkin*)  tolua_tousertype(tolua_S,1,0);
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

/* method: playBackward of class  irr::gui::CGUIImageSkin */
#ifndef TOLUA_DISABLE_tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_playBackward00
static int tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_playBackward00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CGUIImageSkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CGUIImageSkin* self = (irr::gui::CGUIImageSkin*)  tolua_tousertype(tolua_S,1,0);
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

/* method: resetAnimation of class  irr::gui::CGUIImageSkin */
#ifndef TOLUA_DISABLE_tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_resetAnimation00
static int tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_resetAnimation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CGUIImageSkin",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CGUIImageSkin* self = (irr::gui::CGUIImageSkin*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getColor of class  irr::gui::CGUIImageSkin */
#ifndef TOLUA_DISABLE_tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_getColor00
static int tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_getColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CGUIImageSkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::EGUI_DEFAULT_COLOR",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CGUIImageSkin* self = (irr::gui::CGUIImageSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::EGUI_DEFAULT_COLOR color = *((irr::gui::EGUI_DEFAULT_COLOR*)  tolua_tousertype(tolua_S,2,0));
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

/* method: setColor of class  irr::gui::CGUIImageSkin */
#ifndef TOLUA_DISABLE_tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_setColor00
static int tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CGUIImageSkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::EGUI_DEFAULT_COLOR",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"irr::video::SColor",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CGUIImageSkin* self = (irr::gui::CGUIImageSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::EGUI_DEFAULT_COLOR which = *((irr::gui::EGUI_DEFAULT_COLOR*)  tolua_tousertype(tolua_S,2,0));
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

/* method: getSize of class  irr::gui::CGUIImageSkin */
#ifndef TOLUA_DISABLE_tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_getSize00
static int tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_getSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CGUIImageSkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::EGUI_DEFAULT_SIZE",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CGUIImageSkin* self = (irr::gui::CGUIImageSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::EGUI_DEFAULT_SIZE size = *((irr::gui::EGUI_DEFAULT_SIZE*)  tolua_tousertype(tolua_S,2,0));
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

/* method: setSize of class  irr::gui::CGUIImageSkin */
#ifndef TOLUA_DISABLE_tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_setSize00
static int tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_setSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CGUIImageSkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::EGUI_DEFAULT_SIZE",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CGUIImageSkin* self = (irr::gui::CGUIImageSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::EGUI_DEFAULT_SIZE which = *((irr::gui::EGUI_DEFAULT_SIZE*)  tolua_tousertype(tolua_S,2,0));
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

/* method: getFont of class  irr::gui::CGUIImageSkin */
#ifndef TOLUA_DISABLE_tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_getFont00
static int tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_getFont00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CGUIImageSkin",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CGUIImageSkin* self = (irr::gui::CGUIImageSkin*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setFont of class  irr::gui::CGUIImageSkin */
#ifndef TOLUA_DISABLE_tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_setFont00
static int tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_setFont00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CGUIImageSkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::IGUIFont",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CGUIImageSkin* self = (irr::gui::CGUIImageSkin*)  tolua_tousertype(tolua_S,1,0);
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

/* method: getDefaultText of class  irr::gui::CGUIImageSkin */
#ifndef TOLUA_DISABLE_tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_getDefaultText00
static int tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_getDefaultText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CGUIImageSkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::EGUI_DEFAULT_TEXT",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CGUIImageSkin* self = (irr::gui::CGUIImageSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::EGUI_DEFAULT_TEXT text = *((irr::gui::EGUI_DEFAULT_TEXT*)  tolua_tousertype(tolua_S,2,0));
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

/* method: setDefaultText of class  irr::gui::CGUIImageSkin */
#ifndef TOLUA_DISABLE_tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_setDefaultText00
static int tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_setDefaultText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CGUIImageSkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::EGUI_DEFAULT_TEXT",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"wchar_t",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CGUIImageSkin* self = (irr::gui::CGUIImageSkin*)  tolua_tousertype(tolua_S,1,0);
  irr::gui::EGUI_DEFAULT_TEXT which = *((irr::gui::EGUI_DEFAULT_TEXT*)  tolua_tousertype(tolua_S,2,0));
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

/* method: draw3DButtonPaneStandard of class  irr::gui::CGUIImageSkin */
#ifndef TOLUA_DISABLE_tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_draw3DButtonPaneStandard00
static int tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_draw3DButtonPaneStandard00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CGUIImageSkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::IGUIElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CGUIImageSkin* self = (irr::gui::CGUIImageSkin*)  tolua_tousertype(tolua_S,1,0);
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

/* method: draw3DButtonPanePressed of class  irr::gui::CGUIImageSkin */
#ifndef TOLUA_DISABLE_tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_draw3DButtonPanePressed00
static int tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_draw3DButtonPanePressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CGUIImageSkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::IGUIElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CGUIImageSkin* self = (irr::gui::CGUIImageSkin*)  tolua_tousertype(tolua_S,1,0);
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

/* method: draw3DSunkenPane of class  irr::gui::CGUIImageSkin */
#ifndef TOLUA_DISABLE_tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_draw3DSunkenPane00
static int tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_draw3DSunkenPane00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CGUIImageSkin",0,&tolua_err) ||
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
  irr::gui::CGUIImageSkin* self = (irr::gui::CGUIImageSkin*)  tolua_tousertype(tolua_S,1,0);
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

/* method: draw3DWindowBackground of class  irr::gui::CGUIImageSkin */
#ifndef TOLUA_DISABLE_tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_draw3DWindowBackground00
static int tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_draw3DWindowBackground00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CGUIImageSkin",0,&tolua_err) ||
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
  irr::gui::CGUIImageSkin* self = (irr::gui::CGUIImageSkin*)  tolua_tousertype(tolua_S,1,0);
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

/* method: draw3DMenuPane of class  irr::gui::CGUIImageSkin */
#ifndef TOLUA_DISABLE_tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_draw3DMenuPane00
static int tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_draw3DMenuPane00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CGUIImageSkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::IGUIElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CGUIImageSkin* self = (irr::gui::CGUIImageSkin*)  tolua_tousertype(tolua_S,1,0);
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

/* method: draw3DToolBar of class  irr::gui::CGUIImageSkin */
#ifndef TOLUA_DISABLE_tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_draw3DToolBar00
static int tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_draw3DToolBar00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CGUIImageSkin",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::gui::IGUIElement",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"irr::core::rect<s32>",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::gui::CGUIImageSkin* self = (irr::gui::CGUIImageSkin*)  tolua_tousertype(tolua_S,1,0);
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

/* method: draw3DTabButton of class  irr::gui::CGUIImageSkin */
#ifndef TOLUA_DISABLE_tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_draw3DTabButton00
static int tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_draw3DTabButton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CGUIImageSkin",0,&tolua_err) ||
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
  irr::gui::CGUIImageSkin* self = (irr::gui::CGUIImageSkin*)  tolua_tousertype(tolua_S,1,0);
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

/* method: draw3DTabBody of class  irr::gui::CGUIImageSkin */
#ifndef TOLUA_DISABLE_tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_draw3DTabBody00
static int tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_draw3DTabBody00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::gui::CGUIImageSkin",0,&tolua_err) ||
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
  irr::gui::CGUIImageSkin* self = (irr::gui::CGUIImageSkin*)  tolua_tousertype(tolua_S,1,0);
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

/* function: irr::gui::createSkin */
#ifndef TOLUA_DISABLE_tolua_CGUIImageSkin_irr_gui_createSkin00
static int tolua_CGUIImageSkin_irr_gui_createSkin00(lua_State* tolua_S)
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
   irr::gui::CGUIImageSkin* tolua_ret = (irr::gui::CGUIImageSkin*)  irr::gui::createSkin(Driver,Manager,Timer);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"irr::gui::CGUIImageSkin");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createSkin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_CGUIImageSkin_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
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
    tolua_cclass(tolua_S,"CGUIImageSkin","irr::gui::CGUIImageSkin","irr::gui::IGUISkin",tolua_collect_irr__gui__CGUIImageSkin);
    #else
    tolua_cclass(tolua_S,"CGUIImageSkin","irr::gui::CGUIImageSkin","irr::gui::IGUISkin",NULL);
    #endif
    tolua_beginmodule(tolua_S,"CGUIImageSkin");
     tolua_function(tolua_S,"new",tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_new00);
     tolua_function(tolua_S,"new_local",tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_new00_local);
     tolua_function(tolua_S,".call",tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_new00_local);
     tolua_function(tolua_S,"delete",tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_delete00);
     tolua_function(tolua_S,"Load",tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_Load00);
     tolua_function(tolua_S,"getAnimationSpeed",tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_getAnimationSpeed00);
     tolua_function(tolua_S,"setAnimationSpeed",tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_setAnimationSpeed00);
     tolua_function(tolua_S,"setLoop",tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_setLoop00);
     tolua_function(tolua_S,"getLoop",tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_getLoop00);
     tolua_function(tolua_S,"playForward",tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_playForward00);
     tolua_function(tolua_S,"playBackward",tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_playBackward00);
     tolua_function(tolua_S,"resetAnimation",tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_resetAnimation00);
     tolua_function(tolua_S,"getColor",tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_getColor00);
     tolua_function(tolua_S,"setColor",tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_setColor00);
     tolua_function(tolua_S,"getSize",tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_getSize00);
     tolua_function(tolua_S,"setSize",tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_setSize00);
     tolua_function(tolua_S,"getFont",tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_getFont00);
     tolua_function(tolua_S,"setFont",tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_setFont00);
     tolua_function(tolua_S,"getDefaultText",tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_getDefaultText00);
     tolua_function(tolua_S,"setDefaultText",tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_setDefaultText00);
     tolua_function(tolua_S,"draw3DButtonPaneStandard",tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_draw3DButtonPaneStandard00);
     tolua_function(tolua_S,"draw3DButtonPanePressed",tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_draw3DButtonPanePressed00);
     tolua_function(tolua_S,"draw3DSunkenPane",tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_draw3DSunkenPane00);
     tolua_function(tolua_S,"draw3DWindowBackground",tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_draw3DWindowBackground00);
     tolua_function(tolua_S,"draw3DMenuPane",tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_draw3DMenuPane00);
     tolua_function(tolua_S,"draw3DToolBar",tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_draw3DToolBar00);
     tolua_function(tolua_S,"draw3DTabButton",tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_draw3DTabButton00);
     tolua_function(tolua_S,"draw3DTabBody",tolua_CGUIImageSkin_irr_gui_CGUIImageSkin_draw3DTabBody00);
    tolua_endmodule(tolua_S);
    tolua_function(tolua_S,"createSkin",tolua_CGUIImageSkin_irr_gui_createSkin00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_CGUIImageSkin (lua_State* tolua_S) {
 return tolua_CGUIImageSkin_open(tolua_S);
};
#endif

