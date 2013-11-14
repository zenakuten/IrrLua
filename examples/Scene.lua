
require "IrrLua"

--[[
This tutorial will briefly show how to use the terrain renderer of Irrlicht. It will also
show the terrain renderer triangle selector to be able to do collision detection with
terrain.

Note that the Terrain Renderer in Irrlicht is based on Spintz' GeoMipMapSceneNode, lots 
of thanks go to him.
In the beginning there is nothing special. We include the needed header files and create
an event listener to listen if the user presses the 'W' key so we can switch to wireframe
mode.
--]]

MyEventReceiver = {}

function MyEventReceiver:OnEvent(Event)
	if Event.EventType == irr.EET_KEY_INPUT_EVENT then
		return self:OnKeyEvent(Event.KeyInput.Key,Event.KeyInput.PressedDown, Event.KeyInput.Shift, Event.KeyInput.Control)
	end
	return false
end

function MyEventReceiver:OnKeyEvent(Key, PressedDown, Shift, Control)
	if Key == irr.KEY_KEY_W and not PressedDown then
		-- swith wire frame mode
		terrain:setMaterialFlag(irr.video.EMF_WIREFRAME, not terrain:getMaterial(0).Wireframe)
		return true
	elseif Key == irr.KEY_KEY_D and not PressedDown then
		-- swith wire frame mode
		if terrain:getMaterial(0).MaterialType == irr.video.EMT_SOLID then
			terrain:setMaterialType(irr.video.EMT_DETAIL_MAP)
		else
			terrain:setMaterialType(irr.video.EMT_SOLID)
		end
		return true
	end
	return false
end

MyShaderCallBack = {}

function MyShaderCallBack:OnSetConstants(services, userData)

	local driver = services:getVideoDriver()

	-- set inverted world matrix
	-- if we are using highlevel shaders (the user can select this when
	-- starting the program), we must set the constants by name.
	local invWorld = driver:getTransform(irr.video.ETS_WORLD)
	invWorld:makeInverse()

	-- set clip matrix
	local worldViewProj
	worldViewProj = driver:getTransform(irr.video.ETS_PROJECTION)		
	worldViewProj = worldViewProj * driver:getTransform(irr.video.ETS_VIEW)
	worldViewProj = worldViewProj * driver:getTransform(irr.video.ETS_WORLD)

	-- set camera position
	local pos = device:getSceneManager():getActiveCamera():getAbsolutePosition()

	
	-- set transposed world matrix
	local world = driver:getTransform(irr.video.ETS_WORLD)
	world = world:getTransposed()

	services:setVertexShaderConstant("mInvWorld", invWorld.M, 16)
	services:setVertexShaderConstant("mWorldViewProj", worldViewProj.M, 16)
	services:setVertexShaderConstant("mLightPos", { pos.X, pos.Y, pos.Z } )

	-- set light color to time 
	local time = device:getTimer():getTime()/1000
	services:setVertexShaderConstant("mLightColor", {time, time, time, time} )
    services:setPixelShaderConstant("mLightColor", {time, time, time, time} )
	services:setVertexShaderConstant("mTransWorld",  world.M, 16  )
end


--[[
The start of the main function starts like in most other example. We ask the user
for the desired renderer and start it up.
--]]

function main()

	local installPath = "../../../../"

	-- ask user for driver

	
	local receiver = irr.createIEventReceiver(MyEventReceiver)

	device = irr.createDevice(irr.video.EDT_OPENGL, irr.core.dimension2d(640, 480), 16, false, false, false, receiver)
	
	if device == nil then
		print("Error creating device")
		return 1
	end

	
	--[[
	First, we add standard stuff to the scene: A nice irrlicht engine
	logo, a small help text, a user controlled camera, and we disable
	the mouse cursor.
	--]]

	local driver = device:getVideoDriver()
	local smgr = device:getSceneManager()
	local env = device:getGUIEnvironment()

	driver:setTextureCreationFlag(irr.video.ETCF_ALWAYS_32_BIT, true)

	-- add irrlicht logo
	env:addImage(driver:getTexture(installPath .. "media/irrlichtlogoalpha.tga"),
		irr.core.position2d(10,10))

	-- add some help text
    local text = env:addStaticText( "Press 'W' to change wireframe mode \n Press 'D' to toggle detail map", irr.core.rect(10,465,200,475), true)
	text:setOverrideColor(irr.video.SColor(100,255,255,255))

	-- add camera
	local camera = smgr:addCameraSceneNodeFPS(nil,100.0,1200.0)

	camera:setPosition(irr.core.vector3d(1900*2,255*2,3700*2))
	camera:setTarget(irr.core.vector3d(2397*2,343*2,2700*2))
	camera:setFarValue(12000.0)

	-- disable mouse cursor
	device:getCursorControl():setVisible(false)

	--[[
	Here comes the terrain renderer scene node: We add it just like any 
	other scene node to the scene using ISceneManager::addTerrainSceneNode(). 
	The only parameter we use is a file name to the heightmap we use. A heightmap
	is simply a gray scale texture. The terrain renderer loads it and creates 
	the 3D terrain from it.
	To make the terrain look more big, we change the scale factor of it to (40, 4.4, 40).
	Because we don't have any dynamic lights in the scene, we switch off the lighting,
	and last, we set the file terrain-texture.jpg as texture for the terrain. In this
	example, the texture is not repeated over the whole terrain. But if you want this you
	can call ITerrainSceneNode::scaleTexture() and make the texture scale.
	--]]

	-- add terrain scene node
	terrain = smgr:addTerrainSceneNode( installPath .. "media/terrain-heightmap.bmp")
	terrain:setScale(irr.core.vector3d(40, 4.4, 40))
	terrain:setMaterialFlag(irr.video.EMF_LIGHTING, false)

	terrain:setMaterialTexture(0, driver:getTexture(installPath .. "media/terrain-texture.jpg"))
	terrain:setMaterialTexture(1, driver:getTexture(installPath .. "media/detailmap3.jpg"))

	terrain:setMaterialType(irr.video.EMT_DETAIL_MAP)

	terrain:scaleTexture(1, 20)

	--[[
	 terrain:scaleTexture(1.0)
	--]]

	--[[
	To be able to do collision with the terrain, we create a triangle selector.
	If you want to know what triangle selectors do, just take a look into the 
	collision tutorial. The terrain triangle selector works together with the
	terrain. To demonstrate this, we create a collision response animator 
	and attach it to the camera, so that the camera will not be able to fly 
	through the terrain.
	--]]

	-- create triangle selector for the terrain	
	local selector = smgr:createTerrainTriangleSelector(terrain, 0)
	terrain:setTriangleSelector(selector)
	selector:drop()


	-- create collision response animator and attach it to the camera

 	local anim = smgr:createCollisionResponseAnimator(
		selector, camera, irr.core.vector3d(60,100,60),
		irr.core.vector3d(0,0,0), 
		irr.core.vector3d(0,50,0))

	camera:addAnimator(anim)
	anim:drop()


	local	psFileName = "d3d9.hlsl"
	local	vsFileName = psFileName
	

	local gpu = driver:getGPUProgrammingServices()
	local newMaterialType = 0
	
	local mc = irr.video.createIShaderConstantSetCallBack(MyShaderCallBack)
	if gpu ~= nil then
			newMaterialType = gpu:addHighLevelShaderMaterialFromFiles(
				vsFileName,	"vertexMain", irr.video.EVST_VS_1_1,
				psFileName, "pixelMain", irr.video.EPST_PS_2_0,
				mc, irr.video.EMT_TRANSPARENT_ADD_COLOR)

		mc:drop()
	end

	local rt = driver:createRenderTargetTexture(irr.core.dimension2d(100,100))
	local cam = smgr:addCameraSceneNodeFPS(nil, 100.0, 100.0)
	--cam:setPosition(irr.core.vector3d(-100,50,100))
	-- cam:setTarget(irr.core.vector3d(0,0,0))
	cam:setPosition(irr.core.vector3d(1900*2,255*2,3700*2))
	cam:setTarget(irr.core.vector3d(2397*2,343*2,2700*2))
	cam:setFarValue(12000.0)

	

	local mesh = smgr:addHillPlaneMesh("myHill",
		irr.core.dimension2d(100,100),
		irr.core.dimension2d(100,100), nil, 0,
		irr.core.dimension2d(00,00),
		irr.core.dimension2d(1,1))

	local node = smgr:addWaterSurfaceSceneNode(mesh:getMesh(0), 3, 300, 30)
	node:setPosition(irr.core.vector3d(5500,280,5100))
	node:setMaterialFlag(irr.video.EMF_LIGHTING, false)
	node:setMaterialFlag(irr.video.EMF_NORMALIZE_NORMALS, true)

	-- node:setMaterialTexture(1,	driver:getTexture(installPath .. "media/water.jpg"))
    -- node:setMaterialTexture(0,	driver:getTexture(installPath .. "media/stones.jpg"))
	 node:setMaterialTexture(1,driver:getTexture(installPath .. "media/irrlicht2_up.jpg"))
	 node:setMaterialTexture(0,driver:getTexture("noise.bmp"))
	-- node:setMaterialTexture(0,rt)
	node:setMaterialType(newMaterialType)
	-- node:setMaterialType(irr.video.EMT_TRANSPARENT_REFLECTION_2_LAYER)

	--[[
	To make the user be able to switch between normal and wireframe mode, we create
	an instance of the event reciever from above and let Irrlicht know about it. In 
	addition, we add the skybox which we already used in lots of Irrlicht examples.
	--]]


   	-- create skybox
	driver:setTextureCreationFlag(irr.video.ETCF_CREATE_MIP_MAPS, false)

	smgr:addSkyBoxSceneNode(
		driver:getTexture(installPath .. "media/irrlicht2_up.jpg"),
		driver:getTexture(installPath .. "media/irrlicht2_dn.jpg"),
		driver:getTexture(installPath .. "media/irrlicht2_lf.jpg"),
		driver:getTexture(installPath .. "media/irrlicht2_rt.jpg"),
		driver:getTexture(installPath .. "media/irrlicht2_ft.jpg"),
		driver:getTexture(installPath .. "media/irrlicht2_bk.jpg"))

	driver:setTextureCreationFlag(irr.video.ETCF_CREATE_MIP_MAPS, true)

	--[[
	That's it, draw everything. Now you know how to use terrain in Irrlicht.
	--]]

	local lastFPS = -1

	while device:run() do
		if device:isWindowActive() then
			driver:beginScene(true, true, nil )
			driver:setRenderTarget(tolua.cast(rt, "irr::video::ITexture"), true,true, irr.video.SColor(0,0,0,255))
			node:setVisible(false)
			smgr:setActiveCamera(cam)
			smgr:drawAll()
			driver:setRenderTarget(nil)
			node:setVisible(true)
			smgr:setActiveCamera(cam)

			smgr:drawAll()
			env:drawAll()

			driver:endScene()

			-- display frames per second in window title
			local fps = driver:getFPS()
			if lastFPS ~= fps then
				local str = "Terrain Renderer - Irrlicht Engine ["
				str = str .. driver:getName()
				str = str .. "] FPS:"
				str = str .. fps

				device:setWindowCaption(str)
				lastFPS = fps
			end
		end
	end


	device:drop()
	return 0
end

main()


