// Copyright (C) 2005-2006 Josh Turpen
// This file is part of the IrrLua Lua binding for Irrlicht.
// For conditions of distribution and use, see copyright notice in IrrLua.h

#ifndef _IRRLUACAST_H_
#define _IRRLUACAST_H_

#include "irrTypes.h"
#include "vector3d.h"
#include <math.h>
#include <string>


namespace irr
{
namespace video
{
typedef ITexture *PITexture;
}
}

#if _MSC_VER > 1300
//C Linkage in C++ is OK
#pragma warning(disable:4190)
//pointer truncation is Ok for 'void to number' function with flat memory model and IA32
#pragma warning(disable:4311)
#endif

namespace irr
{
	namespace cast
	{
		inline irr::video::PITexture to_pitexture(irr::video::ITexture *p)
		{
			return p;
		}

		/*
		inline s32 void_to_Number(void *num)
		{
			return (s32) num;
		}
		*/

		inline irr::core::stringw to_stringw(std::string s)
		{
			return irr::core::stringw(s.c_str());
		}

		inline wchar_t *to_wchar_t_ptr(std::string s) 
		{
			size_t size = s.size();
			wchar_t *text = new wchar_t[size+2];
			const char *data = &s[0];
			mbsrtowcs(text, &data, size, NULL);
			text[size] = L'\0';

			return text;
		}
		inline const wchar_t *to_const_wchar_t_ptr(std::string s) 
		{
			return (const wchar_t *) to_wchar_t_ptr(s);
		}

		inline c8 *to_c8_ptr(std::string s) 
		{ 
			size_t size = s.size();
			c8 *t = new c8[size+2];
			strncpy(t,&s[0], size);
			t[size] = '\0';

			return t;
		}

		inline const c8 *to_const_c8_ptr(std::string s) 
		{ 
			return (const c8 *) to_c8_ptr(s);
		}

		inline std::string c8_ptr_to_std_string(c8 *s) { return std::string(s); }
		inline std::string const_wchar_t_ptr_to_std_string(const wchar_t *w) 
		{ 
			if(w)
			{
				size_t size = wcslen(w);
				c8 *c = new c8[size+1];
				wcstombs((char *) c, w, size);	
				c[size] = '\0';
				std::string ret = std::string(c);
				delete [] c;
				return ret;
			}
			
			return std::string("");
		}

		inline std::string wchar_t_ptr_to_std_string(wchar_t *w) 
		{ 
			if(w)
			{
				size_t size = wcslen(w);
				c8 *c = new c8[size+1];
				wcstombs((char *) c, w, size);	
				c[size] = '\0';
				std::string ret = std::string(c);
				delete [] c;
				return ret;
			}
			
			return std::string("");
		}

		inline void delete_wchar_t_ptr(wchar_t *w) {  delete [] w;  }
		inline void delete_const_wchar_t_ptr(const wchar_t *w) {  delete [] (wchar_t *) w;  }
		inline void delete_c8_ptr(c8 *c) {   delete [] c;   }
		inline void delete_const_c8_ptr(const c8 *c) {    delete [] (c8 *) c;   }

	}
}
#if _MSC_VER > 1300
#pragma warning(default:4190)
#pragma warning(disable:4311)
#endif

#endif
