
require "IrrLua"
require "CustomSceneNode"

--[[
This Tutorial is a tutorial for more advanced developers.
If you are currently just playing around with the Irrlicht
engine, please look at other examples first. 
This tutorials shows how to create a custom scene node and
how to use it in the engine. A custom scene node is needed,
if you want to implement a render technique, the Irrlicht 
Engine is currently not supporting. For example you can write
a indoor portal based renderer or a advanced terrain scene 
node with it. With creating custom scene nodes, you can 
easily extend the Irrlicht Engine and adapt it to your
needs.

This example is provided to show how to extend IrrLua
using your own DLLs with tolua++.

--]]

function main()

	-- create engine and camera
	device = irr.createDevice(irr.video.EDT_OPENGL, irr.core.dimension2d(640, 480), 16, false)

	device:setWindowCaption("Custom Scene Node - Irrlicht Engine Demo")

	driver = device:getVideoDriver()
	smgr = device:getSceneManager()

	smgr:addCameraSceneNode(nil, irr.core.vector3d(0,-40,0), irr.core.vector3d(0,0,0) )

	--[[	
	Create our scene node. Note that it is dropped (->drop()) instantly after 
	we create it. This is possible because the scene manager now takes
	care of it. This is not nessecary, it would also be possible to drop it
	at the end of the program.

	Note that module loading requires that IrrLuaInterpreter be built against
	shared libraries.  If the module is loaded using the statically linked
	interpreter, the app may/will crash.

	check out the Makefiles for IrrLua to see how to build lua, tolua++, etc
	as shared library 'plugins'.

	--]]

	local myNode = MyProject.CSampleSceneNode:new(smgr:getRootSceneNode(), smgr, 666)
    myNode:drop()

	--[[	
	To animate something in this boring scene consisting only of one tetraeder,
	and to show, that you now can use your scene node like any other scene
	node in the engine, we add an animator to the scene node, which rotates
	the node a little bit.
	--]]

	anim = smgr:createRotationAnimator(irr.core.vector3d(0.8, 0, 0.8))

	myNode:addAnimator(anim)
	anim:drop()
	
	--[[
	Now draw everything and finish.
	--]]

	while device:run() do
 		driver:beginScene(true, true, irr.video.SColor(0,100,100,100))
 		smgr:drawAll()
 		driver:endScene()
 	end

	device:drop()
	
	return 0
end

main()

