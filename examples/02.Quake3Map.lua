
require "IrrLua"

--[[
This Tutorial shows how to load a Quake 3 map into the
engine, create a SceneNode for optimizing the speed of
rendering and how to create a user controlled camera.

Lets start like the HelloWorld example: We include
the irrlicht header files and an additional file to be able
to ask the user for a driver type using the console.
--]]


function main()

	--[[
	Like in the HelloWorld example, we create an IrrlichtDevice with
	createDevice(). The difference now is that we ask the user to select 
	which hardware accelerated driver to use. The Software device would be
	too slow to draw a huge Quake 3 map, but just for the fun of it, we make
	this decision possible too.
	]]--

	local installPath = "../../../"
	-- ask user for driver

	print("Please select the driver you want for this example:\n" ..
		" (a) Direct3D 9.0c\n (b) Direct3D 8.1\n (c) OpenGL 1.2\n" ..
		" (d) Software Renderer\n (e) Apfelbaum Software Renderer\n (f) NullDevice\n (otherKey) exit\n\n")

	local answer = io.read("*line")
	local driverTypes = {["a"] = irr.video.EDT_DIRECT3D9,
						 ["b"] = irr.video.EDT_DIRECT3D8,
						 ["c"] = irr.video.EDT_OPENGL,
						 ["d"] = irr.video.EDT_SOFTWARE,
						 ["e"] = irr.video.EDT_SOFTWARE2,
						 ["f"] = irr.video.EDT_NULL }


	local type = driverTypes[answer]
	if type == nil then 
		return 0
		end 

	-- create device and exit if creation failed
	local device = irr.createDevice(type, irr.core.dimension2d(640, 480) )

	if device == nil then 
		print("Error creating device with type" .. answer)
		return 1 
	end

	--[[
	Get a pointer to the video driver and the SceneManager so that
	we do not always have to write device:getVideoDriver() and
	device:getSceneManager().
	]]--

	local driver = device:getVideoDriver()
	local smgr = device:getSceneManager()

	--[[
	To display the Quake 3 map, we first need to load it. Quake 3 maps
	are packed into .pk3 files wich are nothing other than .zip files.
	So we add the .pk3 file to our FileSystem. After it was added,
	we are able to read from the files in that archive as they would
	directly be stored on disk.
	]]--


	device:getFileSystem():addZipFileArchive(installPath .. "media/map-20kdm2.pk3")

	--[[
	Now we can load the mesh by calling getMesh(). We get a pointer returned
	to a IAnimatedMesh. As you know, Quake 3 maps are not really animated,
	they are only a huge chunk of static geometry with some materials
	attached. Hence the IAnimated mesh consists of only one frame,
	so we get the "first frame" of the "animation", which is our quake level
	and create an OctTree scene node with it, using addOctTreeSceneNode().
	The OctTree optimizes the scene a little bit, trying to draw only geometry
	which is currently visible. An alternative to the OctTree would be a 
	AnimatedMeshSceneNode, which would draw always the complete geometry of 
	the mesh, without optimization. Try it out: Write addAnimatedMeshSceneNode
	instead of addOctTreeSceneNode and compare the primitives drawed by the
	video driver. (There is a getPrimitiveCountDrawed() method in the 
	IVideoDriver class). Note that this optimization with the Octree is only
	useful when drawing huge meshes consiting of lots of geometry.
	--]]

	local mesh = smgr:getMesh("20kdm2.bsp")
	local node = smgr:addOctTreeSceneNode(mesh)

	--[[
	Because the level was modelled not around the origin (0,0,0), we translate
	the whole level a little bit.
	--]]

	node:setPosition(irr.core.vector3d(-1300,-144,-1249))

	--[[
	Now we only need a Camera to look at the Quake 3 map.
	And we want to create a user controlled camera. There are some
	different cameras available in the Irrlicht engine. For example the 
	Maya Camera which can be controlled compareable to the camera in Maya:
	Rotate with left mouse button pressed, Zoom with both buttons pressed,
	translate with right mouse button pressed. This could be created with
	addCameraSceneNodeMaya(). But for this example, we want to create a 
	camera which behaves like the ones in first person shooter games (FPS).
	--]]

	smgr:addCameraSceneNodeFPS()

	--[[
	The mouse cursor needs not to be visible, so we make it invisible.
	--]]

	 local cursor = device:getCursorControl()
	 cursor:setVisible(false)

	--[[
	We have done everything, so lets draw it. We also write the current
	frames per second and the drawn primitives to the caption of the
	window. The 'if (device->isWindowActive())' line is optional, but 
	prevents the engine render to set the position of the mouse cursor 
	after task switching when other program are active.
	--]]

	local lastFPS = -1
	local text = "IrrLua - Quake 3 Map example [" .. driver:getName() .. "] FPS:"


	while device:run() do
		if device:isWindowActive() then 
			driver:beginScene(true, true, irr.video.SColor(0,200,200,200))
			smgr:drawAll()
			driver:endScene()

			fps = driver:getFPS()

			if lastFPS ~= fps then 
				device:setWindowCaption(text .. fps)
				lastFPS = fps
			end
		end
	end

	--[[
	In the end, delete the Irrlicht device.
	--]]

	device:drop()
	
	return 0
end

main()

