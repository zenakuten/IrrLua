-- Copyright (c) 2005  Josh Turpen, Nikolaus Gebhardt

require "IrrLua"

--[[

This Tutorial shows how to write a simple HelloWorld
program. The program will show how to use the 
basics of the VideoDriver, the GUIEnvironment and the
SceneManager. 

--]]

--[[
In the Irrlicht Engine, everything can be found in the namespace
'irr'. So if you want to use a class of the engine, you have to
write an irr. before the name of the class. For example to use
the IrrlichtDevice write: irr.IrrlichtDevice. 
--]]

--[[
There are 5 sub namespaces in the Irrlicht Engine. Take a look 
at them, you can read a detailed description of them in the 
documentation by clicking on the top menu item 'Namespace List'
or using this link: http://irrlicht.sourceforge.net/docu/namespaces.html.
--]]


function main()

	--[[
	
	The most important function of the engine is the 'createDevice'
	function. The Irrlicht Device can be created with it, which is the
	root object for doing everything with the engine.
	createDevice() has 7 paramters:

	deviceType: Type of the device. This can currently be the Null-device,
	   the Software device, Direct3D8, Direct3D9, or OpenGL. In this example we use
	   EDT_SOFTWARE, but to try out, you might want to change it to
	   EDT_NULL, EDT_DIRECT3D8 , EDT_DIRECT3D9, or EDT_OPENGL. 

		IrrLua Note: device types are part of irr.video, i.e irr.video.EDT_SOFTWARE

	windowSize: Size of the Window or FullscreenMode to be created. In this 
	   example we use 640x480.

	bits: Amount of bits per pixel when in fullscreen mode. This should 
	   be 16 or 32. This parameter is ignored when running in windowed mode.

	fullscreen: Specifies if we want the device to run in fullscreen mode
	   or not.

	stencilbuffer: Specifies if we want to use the stencil buffer for drawing shadows.

	vsync: Specifies if we want to have vsync enabled, this is only useful in fullscreen
	  mode.


	--]]

	-- path to root Irrlicht directory so we can find the media files
	local installPath = "../../../"
	local device = irr.createDevice(irr.video.EDT_SOFTWARE2, irr.core.dimension2d(640, 480), 16, false, false, false)

	--[[
	Set the caption of the window to some nice text. 
	--]]

	device:setWindowCaption("Hello from IrrLua!")

	--[[
	Get a pointer to the video driver, the SceneManager and the
	graphical user interface environment, so that
	we do not always have to write device:getVideoDriver(),
	device:getSceneManager() and device:getGUIEnvironment().
	--]]
	
	local driver = device:getVideoDriver()
	local smgr = device:getSceneManager()
	local guienv = device:getGUIEnvironment()

	--[[
	We get a pointer to the video driver, the SceneManager and then
	We add a hello world label to the window, using the GUI environment.
	--]]

	guienv:addStaticText("Hello World", irr.core.rect(0,0,100,100), true)
	
	--[[
	To display something interesting, we load a Quake 2 model 
	and display it. We only have to get the Mesh from the Scene 
	Manager (getMesh()) and add a SceneNode to display the mesh.
	(addAnimatedMeshSceneNode()). Instead of writing the filename
	sydney.md2, it would also be possible to load a Maya object file
	(.obj), a complete Quake3 map (.bsp) or a Milshape file (.ms3d).
	By the way, that cool Quake 2 model called sydney was modelled
	by Brian Collins.
	--]]

	local mesh = smgr:getMesh(installPath .. "media/sydney.md2")	
	node = smgr:addAnimatedMeshSceneNode( mesh )

	--[[
	To let the mesh look a little bit nicer, we change its material a
	little bit: We disable lighting because we do not have a dynamic light
	in here, and the mesh would be totally black. Then we set the frame
	loop, so that the animation is looped between the frames 0 and 310.
	And at last, we apply a texture to the mesh. Without it the mesh
	would be drawn using only a color.
	--]]

	node:setMaterialFlag(irr.video.EMF_LIGHTING , false)
	node:setFrameLoop(0, 310)
	texture = driver:getTexture(installPath .. "media/sydney.bmp")
	node:setMaterialTexture( 0, texture)

	--[[
	To look at the mesh, we place a camera into 3d space at the position
	(0, 30, -40). The camera looks from there to (0,5,0).
	--]]
	
	smgr:addCameraSceneNode(nil, irr.core.vector3d(0,30,-40), irr.core.vector3d(0,5,0), 0 )

	--[[
	Ok, now we have set up the scene, lets draw everything:
	We run the device in a while() loop, until the device does not
	want to run any more. This would be when the user closed the window
	or pressed ALT+F4 in windows.
	--]]
	

	while device:run() do
	
		--[[
		Anything can be drawn between a beginScene() and an endScene()
		call. The beginScene clears the screen with a color and also the
		depth buffer if wanted. Then we let the Scene Manager and the
		GUI Environment draw their content. With the endScene() call
		everything is presented on the screen.
		--]]
	    
		driver:beginScene(true, true, irr.video.SColor(255,100,101,140))

		smgr:drawAll()
		guienv:drawAll()

		driver:endScene()
	end

	--[[
	After we are finished, we have to delete the Irrlicht Device
	created before with createDevice(). In the Irrlicht Engine, 
	you will have to delete all objects you created with a method or 
	function which starts with 'create'. The object is simply deleted
	by calling ->drop().
	See the documentation at 
	http://irrlicht.sourceforge.net//docu/classirr_1_1IUnknown.html#a3
	for more information.
	--]]
	
	device:drop()

	return 0
end

main()
