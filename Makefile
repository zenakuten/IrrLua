# Copyright (C) 2005-2006 Josh Turpen, Nikolaus Gebhardt
# This file is part of the IrrLua Lua binding for Irrlicht.
# For conditions of distribution and use, see copyright notice in IrrLua.h

all:  bin/tolua++ bin/libIrrLua.so

bin/tolua++: 
	make -C tolua++ -f Makefile

bin/libIrrLua.so: bin/tolua++
	make -C pkg -f Makefile
	make -C src -f Makefile

clean:
	make -C pkg -f Makefile clean
	make -C tolua++ -f Makefile clean
	make -C src -f Makefile clean



