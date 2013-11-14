/*
** Lua binding: CustomSceneNode
** Generated automatically by tolua++-1.0.92 on 08/23/06 22:46:45.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_CustomSceneNode_open (lua_State* tolua_S);

#include "CustomSceneNode.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_MyProject__CSampleSceneNode (lua_State* tolua_S)
{
 MyProject::CSampleSceneNode* self = (MyProject::CSampleSceneNode*) tolua_tousertype(tolua_S,1,0);
	delete self;
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"irr::scene::ISceneNode");
 tolua_usertype(tolua_S,"irr::core::aabbox3d<f32>");
 tolua_usertype(tolua_S,"scene::ISceneNode");
 tolua_usertype(tolua_S,"irr::video::SMaterial");
 tolua_usertype(tolua_S,"irr::scene::ISceneNodeAnimator");
 tolua_usertype(tolua_S,"irr::scene::ISceneManager");
 tolua_usertype(tolua_S,"MyProject::CSampleSceneNode");
}

/* method: new of class  MyProject::CSampleSceneNode */
#ifndef TOLUA_DISABLE_tolua_CustomSceneNode_MyProject_CSampleSceneNode_new00
static int tolua_CustomSceneNode_MyProject_CSampleSceneNode_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MyProject::CSampleSceneNode",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::scene::ISceneNode",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"irr::scene::ISceneManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::scene::ISceneNode* parent = ((irr::scene::ISceneNode*)  tolua_tousertype(tolua_S,2,0));
  irr::scene::ISceneManager* mgr = ((irr::scene::ISceneManager*)  tolua_tousertype(tolua_S,3,0));
  signed int id = (( signed int)  tolua_tonumber(tolua_S,4,0));
  {
   MyProject::CSampleSceneNode* tolua_ret = (MyProject::CSampleSceneNode*)  new MyProject::CSampleSceneNode(parent,mgr,id);
   tolua_pushusertype(tolua_S,(void*)tolua_ret,"MyProject::CSampleSceneNode");
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

/* method: new_local of class  MyProject::CSampleSceneNode */
#ifndef TOLUA_DISABLE_tolua_CustomSceneNode_MyProject_CSampleSceneNode_new00_local
static int tolua_CustomSceneNode_MyProject_CSampleSceneNode_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MyProject::CSampleSceneNode",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::scene::ISceneNode",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"irr::scene::ISceneManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  irr::scene::ISceneNode* parent = ((irr::scene::ISceneNode*)  tolua_tousertype(tolua_S,2,0));
  irr::scene::ISceneManager* mgr = ((irr::scene::ISceneManager*)  tolua_tousertype(tolua_S,3,0));
  signed int id = (( signed int)  tolua_tonumber(tolua_S,4,0));
  {
   MyProject::CSampleSceneNode* tolua_ret = (MyProject::CSampleSceneNode*)  new MyProject::CSampleSceneNode(parent,mgr,id);
   tolua_pushusertype_and_takeownership(tolua_S,(void *)tolua_ret,"MyProject::CSampleSceneNode");
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

/* method: delete of class  MyProject::CSampleSceneNode */
#ifndef TOLUA_DISABLE_tolua_CustomSceneNode_MyProject_CSampleSceneNode_delete00
static int tolua_CustomSceneNode_MyProject_CSampleSceneNode_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MyProject::CSampleSceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MyProject::CSampleSceneNode* self = (MyProject::CSampleSceneNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: OnPreRender of class  MyProject::CSampleSceneNode */
#ifndef TOLUA_DISABLE_tolua_CustomSceneNode_MyProject_CSampleSceneNode_OnPreRender00
static int tolua_CustomSceneNode_MyProject_CSampleSceneNode_OnPreRender00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MyProject::CSampleSceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MyProject::CSampleSceneNode* self = (MyProject::CSampleSceneNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnPreRender'",NULL);
#endif
  {
   self->OnPreRender();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnPreRender'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: render of class  MyProject::CSampleSceneNode */
#ifndef TOLUA_DISABLE_tolua_CustomSceneNode_MyProject_CSampleSceneNode_render00
static int tolua_CustomSceneNode_MyProject_CSampleSceneNode_render00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MyProject::CSampleSceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MyProject::CSampleSceneNode* self = (MyProject::CSampleSceneNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'render'",NULL);
#endif
  {
   self->render();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'render'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBoundingBox of class  MyProject::CSampleSceneNode */
#ifndef TOLUA_DISABLE_tolua_CustomSceneNode_MyProject_CSampleSceneNode_getBoundingBox00
static int tolua_CustomSceneNode_MyProject_CSampleSceneNode_getBoundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MyProject::CSampleSceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MyProject::CSampleSceneNode* self = (MyProject::CSampleSceneNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBoundingBox'",NULL);
#endif
  {
   irr::core::aabbox3d<f32>& tolua_ret = (irr::core::aabbox3d<f32>&)  self->getBoundingBox();
   tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::core::aabbox3d<f32>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBoundingBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMaterialCount of class  MyProject::CSampleSceneNode */
#ifndef TOLUA_DISABLE_tolua_CustomSceneNode_MyProject_CSampleSceneNode_getMaterialCount00
static int tolua_CustomSceneNode_MyProject_CSampleSceneNode_getMaterialCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MyProject::CSampleSceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MyProject::CSampleSceneNode* self = (MyProject::CSampleSceneNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMaterialCount'",NULL);
#endif
  {
   signed int tolua_ret = ( signed int)  self->getMaterialCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMaterialCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMaterial of class  MyProject::CSampleSceneNode */
#ifndef TOLUA_DISABLE_tolua_CustomSceneNode_MyProject_CSampleSceneNode_getMaterial00
static int tolua_CustomSceneNode_MyProject_CSampleSceneNode_getMaterial00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MyProject::CSampleSceneNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MyProject::CSampleSceneNode* self = (MyProject::CSampleSceneNode*)  tolua_tousertype(tolua_S,1,0);
  signed int i = (( signed int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMaterial'",NULL);
#endif
  {
   irr::video::SMaterial& tolua_ret = (irr::video::SMaterial&)  self->getMaterial(i);
   tolua_pushusertype(tolua_S,(void*)&tolua_ret,"irr::video::SMaterial");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMaterial'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: grab of class  MyProject::CSampleSceneNode */
#ifndef TOLUA_DISABLE_tolua_CustomSceneNode_MyProject_CSampleSceneNode_grab00
static int tolua_CustomSceneNode_MyProject_CSampleSceneNode_grab00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MyProject::CSampleSceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MyProject::CSampleSceneNode* self = (MyProject::CSampleSceneNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: drop of class  MyProject::CSampleSceneNode */
#ifndef TOLUA_DISABLE_tolua_CustomSceneNode_MyProject_CSampleSceneNode_drop00
static int tolua_CustomSceneNode_MyProject_CSampleSceneNode_drop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MyProject::CSampleSceneNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MyProject::CSampleSceneNode* self = (MyProject::CSampleSceneNode*)  tolua_tousertype(tolua_S,1,0);
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

/* method: addAnimator of class  MyProject::CSampleSceneNode */
#ifndef TOLUA_DISABLE_tolua_CustomSceneNode_MyProject_CSampleSceneNode_addAnimator00
static int tolua_CustomSceneNode_MyProject_CSampleSceneNode_addAnimator00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MyProject::CSampleSceneNode",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"irr::scene::ISceneNodeAnimator",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MyProject::CSampleSceneNode* self = (MyProject::CSampleSceneNode*)  tolua_tousertype(tolua_S,1,0);
  irr::scene::ISceneNodeAnimator* animator = ((irr::scene::ISceneNodeAnimator*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addAnimator'",NULL);
#endif
  {
   self->addAnimator(animator);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addAnimator'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_CustomSceneNode_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"MyProject",0);
  tolua_beginmodule(tolua_S,"MyProject");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CSampleSceneNode","MyProject::CSampleSceneNode","scene::ISceneNode",tolua_collect_MyProject__CSampleSceneNode);
   #else
   tolua_cclass(tolua_S,"CSampleSceneNode","MyProject::CSampleSceneNode","scene::ISceneNode",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CSampleSceneNode");
    tolua_function(tolua_S,"new",tolua_CustomSceneNode_MyProject_CSampleSceneNode_new00);
    tolua_function(tolua_S,"new_local",tolua_CustomSceneNode_MyProject_CSampleSceneNode_new00_local);
    tolua_function(tolua_S,".call",tolua_CustomSceneNode_MyProject_CSampleSceneNode_new00_local);
    tolua_function(tolua_S,"delete",tolua_CustomSceneNode_MyProject_CSampleSceneNode_delete00);
    tolua_function(tolua_S,"OnPreRender",tolua_CustomSceneNode_MyProject_CSampleSceneNode_OnPreRender00);
    tolua_function(tolua_S,"render",tolua_CustomSceneNode_MyProject_CSampleSceneNode_render00);
    tolua_function(tolua_S,"getBoundingBox",tolua_CustomSceneNode_MyProject_CSampleSceneNode_getBoundingBox00);
    tolua_function(tolua_S,"getMaterialCount",tolua_CustomSceneNode_MyProject_CSampleSceneNode_getMaterialCount00);
    tolua_function(tolua_S,"getMaterial",tolua_CustomSceneNode_MyProject_CSampleSceneNode_getMaterial00);
    tolua_function(tolua_S,"grab",tolua_CustomSceneNode_MyProject_CSampleSceneNode_grab00);
    tolua_function(tolua_S,"drop",tolua_CustomSceneNode_MyProject_CSampleSceneNode_drop00);
    tolua_function(tolua_S,"addAnimator",tolua_CustomSceneNode_MyProject_CSampleSceneNode_addAnimator00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);

  { /* begin embedded lua code */
   int top = lua_gettop(tolua_S);
   static unsigned char B[] = {
    10,102,117,110, 99,116,105,111,110, 32, 67, 83, 97,109,112,
    108,101, 83, 99,101,110,101, 78,111,100,101, 40,112, 97,114,
    101,110,116, 44, 32,109,103,114, 44, 32,105,100, 41, 10,105,
    100, 32, 61, 32,105,100, 32,111,114, 32, 45, 49, 10,108,111,
     99, 97,108, 32,114,101,116, 32, 61, 32, 77,121, 80,114,111,
    106,101, 99,116, 46, 67, 83, 97,109,112,108,101, 83, 99,101,
    110,101, 78,111,100,101, 58,110,101,119, 40,112, 97,114,101,
    110,116, 44, 32,109,103,114, 44, 32,105,100, 41, 10,116,111,
    108,117, 97, 46,116, 97,107,101,111,119,110,101,114,115,104,
    105,112, 40,114,101,116, 41, 10,114,101,116,117,114,110, 32,
    114,101,116, 10,101,110,100,32
   };
   tolua_dobuffer(tolua_S,(char*)B,sizeof(B),"tolua: embedded Lua code 1");
   lua_settop(tolua_S, top);
  } /* end of embedded lua code */

 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_CustomSceneNode (lua_State* tolua_S) {
 return tolua_CustomSceneNode_open(tolua_S);
};
#endif

