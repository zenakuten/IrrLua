
#include "IrrLua.h"

#define IRRLUA_DOFILE_BUFFERSIZE	4096

namespace irr 
{

namespace io
{
	//mainly used to encapsulate chunkreader and buffer
	class IrrLuaDoFile 
	{
		public:
			IrrLuaDoFile() : File(NULL) { memset(buffer, 0, sizeof(buffer));}
		~IrrLuaDoFile() {}

		void dofile(irr::io::IReadFile *f)
		{
			lua_State *L = IrrLuaGetState();
			File = f;
			File->seek(0);

			int error = lua_load(L, Chunkreader, this, "irr.io.dofile");
			if(error)
			{
				if(lua_isstring(L, -1))
				{
					fprintf(stderr, "%s\n", lua_tostring(L, -1));
					lua_pop(L, 1);
				}

				return;
			}

			lua_pcall(L,0,0,0);
		}

		private:
		static const char *Chunkreader(lua_State *L, void *ud, size_t *sz)
		{
			IrrLuaDoFile *pThis = (IrrLuaDoFile *) ud;
			if(pThis)
			{
				*sz = pThis->File->read(pThis->buffer, sizeof(pThis->buffer));
				if( *sz == 0)
					return NULL;

				return pThis->buffer;
			}
			
			*sz = 0;
			return NULL;
		}

		irr::io::IReadFile *File;
		c8 buffer[IRRLUA_DOFILE_BUFFERSIZE];
	};

	void dofile(irr::io::IReadFile *f)
	{		
		IrrLuaDoFile DoFileObj;
		DoFileObj.dofile(f);
	}
}

namespace video
{
 bool IrrLuaSetVertexShaderConstant1(irr::video::IMaterialRendererServices *services, std::string name, s32 count, f32 *floats)
{
	return services->setVertexShaderConstant(name.c_str(), (f32 *)floats, (s32) count);
}

 bool IrrLuaSetPixelShaderConstant1(irr::video::IMaterialRendererServices *services, std::string name, s32 count, f32 *floats)
{
	return services->setPixelShaderConstant(name.c_str(), (f32 *)floats, (s32) count);
}

 void IrrLuaSetVertexShaderConstant2(irr::video::IMaterialRendererServices *services, s32 start, s32 ucount, s32 count, f32 *data)
{
	return services->setVertexShaderConstant(data, start, ucount);
}

 void IrrLuaSetPixelShaderConstant2(irr::video::IMaterialRendererServices *services, s32 start, s32 ucount, s32 count, f32 *data)
{
	return services->setPixelShaderConstant(data, start, ucount);
}

 void IrrLuaDrawIndexedTriangleList(IVideoDriver *drv, 
								s32 vertexCount, S3DVertex *vertices,
								s32 triangleCount, s16 *indexList)
{
	drv->drawIndexedTriangleList(vertices, vertexCount, (u16 *) indexList, triangleCount/3);
}

}

namespace scene
{
 ICameraSceneNode* IrrLuaAddCameraSceneNodeFPS(ISceneManager *mgr, ISceneNode* parent, f32 rotateSpeed , f32 moveSpeed , s32 id, s32 keyMapSize, SKeyMap* keyMapArray, bool noVerticalMovement)
{
	return mgr->addCameraSceneNodeFPS(parent, rotateSpeed, moveSpeed, id, keyMapArray, keyMapSize, noVerticalMovement);
}

}
}


//this shit is completely broken, a little help ariel & roberto!
int checkstack(lua_State *L)
{
	return 1;
}

int tolua_IrrLua_irr_video_IrrLuaSetVertexShaderConstant100(lua_State* tolua_S)
{
	tolua_Error tolua_err;
	signed int count = (( signed int)  tolua_tonumber(tolua_S,3,0));

	if (!tolua_isnumberarray(tolua_S,4,count,0,&tolua_err))
	{
		tolua_error(tolua_S,"#ferror in function 'IrrLuaSetVertexShaderConstant1'.",&tolua_err);
		return 0;
	}

	checkstack(tolua_S);


	if (!tolua_isusertype(tolua_S,1,"irr::video::IMaterialRendererServices",0,&tolua_err) ||
		!tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
		!tolua_isnumber(tolua_S,3,0,&tolua_err) ||
		!tolua_istable(tolua_S,4,0,&tolua_err) ||
		!tolua_isnoobj(tolua_S,5,&tolua_err))
	{
		tolua_error(tolua_S,"#ferror in function 'IrrLuaSetVertexShaderConstant1'.",&tolua_err);
		return 0;
	}

	checkstack(tolua_S);

	irr::video::IMaterialRendererServices* services = ((irr::video::IMaterialRendererServices*)  tolua_tousertype(tolua_S,1,0));
	std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
	//signed int count = (( signed int)  tolua_tonumber(tolua_S,3,0));
	checkstack(tolua_S);
	if (!tolua_isnumberarray(tolua_S,4,count,0,&tolua_err))
	{
		tolua_error(tolua_S,"#ferror in function 'IrrLuaSetVertexShaderConstant1'.",&tolua_err);
		return 0;
	}

	float* floats = new float[count];
	checkstack(tolua_S);
    for(int i=0; i<count;i++)
	{
		checkstack(tolua_S);
		floats[i] = ((float)  tolua_tofieldnumber(tolua_S,4,i+1,0));
	}
	checkstack(tolua_S);
	bool tolua_ret = (bool)  irr::video::IrrLuaSetVertexShaderConstant1(services,name,count,floats);
	checkstack(tolua_S);
	tolua_pushboolean(tolua_S,(bool)tolua_ret);
	checkstack(tolua_S);
	for(int i=0; i<count;i++)
	{
		tolua_pushfieldnumber(tolua_S,4,i+1,(lua_Number) floats[i]);
		checkstack(tolua_S);
	}
	
	checkstack(tolua_S);
	delete [] floats;

	return 1;
}

int tolua_IrrLua_irr_video_IrrLuaSetPixelShaderConstant100(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"irr::video::IMaterialRendererServices",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_istable(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  irr::video::IMaterialRendererServices* services = ((irr::video::IMaterialRendererServices*)  tolua_tousertype(tolua_S,1,0));
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  signed int count = (( signed int)  tolua_tonumber(tolua_S,3,0));
   float* floats = new float[count];
  {
   if (!tolua_isnumberarray(tolua_S,4,count,0,&tolua_err))
    goto tolua_lerror;
   else
   {
    int i;
    for(i=0; i<count;i++)
    floats[i] = ((float)  tolua_tofieldnumber(tolua_S,4,i+1,0));
   }
  }
  {
   bool tolua_ret = (bool)  irr::video::IrrLuaSetPixelShaderConstant1(services,name,count,floats);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
  {
   int i;
   for(i=0; i<count;i++)
    tolua_pushfieldnumber(tolua_S,4,i+1,(lua_Number) floats[i]);
  }
  delete [] floats;
 }
 return 1;
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IrrLuaSetPixelShaderConstant1'.",&tolua_err);
 return 0;
}


IRRLUA_API int luaopen_IrrLuaAux(lua_State *L)
{
	tolua_open(L);
	 tolua_usertype(L,"irr::video::IMaterialRendererServices");
	tolua_module(L,NULL,0);
	tolua_beginmodule(L,NULL);

	tolua_module(L,"irr",0);
	tolua_beginmodule(L,"irr");
	tolua_module(L,"video",0);
	tolua_beginmodule(L,"video");
	tolua_function(L,"IrrLuaSetVertexShaderConstant1",tolua_IrrLua_irr_video_IrrLuaSetVertexShaderConstant100);
	tolua_function(L,"IrrLuaSetPixelShaderConstant1",tolua_IrrLua_irr_video_IrrLuaSetPixelShaderConstant100);
	tolua_endmodule(L);
	tolua_endmodule(L);
	tolua_endmodule(L);
  
	return 1;
}
