
INCLUDES=-I"../../include" -I"../../../include" -I"../../tolua++/include" -I"../../lua/include"
LIBS=-L../../bin/ -lIrrlicht -llua5.1 -ltolua++
CFLAGS=-DIRRLUA_API="" -DLUA_VERSION_NUM=501 -fPIC

all: CustomSceneNode.so

clean:
	rm -f CustomSceneNode.so CustomSceneNode.o CustomSceneNode_imp.o CustomSceneNode_imp.cpp CustomSceneNode_imp.h

CustomSceneNode.so: CustomSceneNode.o 
	gcc $(CFLAGS) -shared -fPIC -Wl,-E -Wl,-rpath,'$${ORIGIN}' -o CustomSceneNode.so CustomSceneNode.o $(INCLUDES) $(LIBS)
	cp CustomSceneNode.so ../../bin

CustomSceneNode.o: CustomSceneNode.cpp CustomSceneNode.h CustomSceneNode_imp.h CustomSceneNode_imp.cpp
	gcc $(CFLAGS) -c CustomSceneNode.cpp $(INCLUDES) 

CustomSceneNode_imp.o: CustomSceneNode_imp.cpp CustomSceneNode_imp.h
	gcc $(CFLAGS) -c CustomSceneNode_imp.cpp $(INCLUDES) 

CustomSceneNode_imp.h: CustomSceneNode.pkg
	../../bin/tolua++ -H CustomSceneNode_imp.h -o CustomSceneNode_imp.cpp CustomSceneNode.pkg

CustomSceneNode_imp.cpp: CustomSceneNode.pkg
	../../bin/tolua++ -H CustomSceneNode_imp.h -o CustomSceneNode_imp.cpp CustomSceneNode.pkg

