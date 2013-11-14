
LIBPATH=-L/usr/X11R6/lib -L../bin 
LIBRARIES= -lm -llua5.1  -ltolua++ -lIrrlicht 
MYCFLAGS=-shared -fPIC -Wl,-E -Wl,-rpath,'$${ORIGIN}'

all: ../bin/IrrLua.so ../bin/CustomSceneNode.so 

../bin/CustomSceneNode.so:
	make -C CustomSceneNode -f Makefile

../bin/IrrLua.so: ../pkg/IrrLua_imp.o ../pkg/IrrLua.o ../pkg/IrrLuaAux.o
	gcc $(MYCFLAGS)  ../pkg/IrrLua.o ../pkg/IrrLuaAux.o $(LIBPATH) $(LIBRARIES) -o ../bin/IrrLua.so

../pkg/IrrLua_imp.o:
	make -C ../pkg -f Makefile

clean:
	rm -f ../bin/IrrLua.so
	make -C CustomSceneNode -f Makefile clean

