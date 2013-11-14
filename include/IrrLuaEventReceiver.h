// Copyright (C) 2005-2006 Josh Turpen
// This file is part of the IrrLua Lua binding for Irrlicht.
// For conditions of distribution and use, see copyright notice in IrrLua.h

#ifndef _IRRLUAEVENTRECEIVER_H_
#define _IRRLUAEVENTRECEIVER_H_

#include "IrrLua.h"
#include "IrrLuaProxy.h"

#include "IrrLuaEventReceiverBase.h"

static const char *g_EventReceiverTable = "__ieventreceiverproxy";

namespace irr
{
	class IrrLuaEventReceiver : public IrrLuaEventReceiverBase 
	{
		public:
		IrrLuaEventReceiver() : IrrLuaEventReceiverBase(g_EventReceiverTable) {Proxy = this; }
		virtual ~IrrLuaEventReceiver() {}

	};
}

#endif /* _IRRLUAEVENTRECEIVER_H_ */
