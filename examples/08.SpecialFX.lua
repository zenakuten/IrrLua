
require "IrrLua"

--[[
 This tutorials describes how to do special effects. It shows how to use stencil
buffer shadows, the particle system, billboards, dynamic light and the water
surface scene node. 

We start like in some tutorials before. Please note that this time, the 'shadows' flag in
createDevice() is set to true, for we want to have a dynamic shadow casted from
an animated character. If your this example runs to slow, set it to false. 
The Irrlicht Engine checks if your hardware doesn't support the stencil 
buffer, and disables shadows by itself, but just in case the demo runs slow
on your hardware.
--]]


function main()

	-- ask if user would like shadows

	print("Please press 'y' if you want to use realtime shadows.")
	local shadows = io.read("*line")

	-- let user select driver type
	local installPath = "../../../"

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
	
	-- create device

	local device = irr.createDevice(type, irr.core.dimension2d(640, 480), 16, false, (shadows == "y") or (shadows == "yes"))

	if device == nil then
		return 1   -- could not create selected driver.
	end

	local driver = device:getVideoDriver()
	local smgr = device:getSceneManager()

	--[[	
	For our environment, we load a .3ds file. It is a small room I modelled
	with Anim8or and exported it into the 3ds format because the Irrlicht Engine
	did not support the .an8 format when I wrote this tutorial. I am a very bad
	3d graphic artist, and so the texture mapping is not very nice in this model.
	Luckily I am a better programmer than artist, and so the Irrlicht Engine
	is able to create a cool texture mapping for me: Just use the mesh manipulator
	and create a planar texture mapping for the mesh. If you want to see the mapping
	I made with Anim8or, uncomment this line. I also did not figure out how to
	set the material right in Anim8or, it has an emissive light color which I don't really
	like. I'll switch it off too with this code.
	--]]

	local mesh = smgr:getMesh(installPath ..  "media/room.3ds")

	smgr:getMeshManipulator():makePlanarTextureMapping(mesh:getMesh(0), 0.004)

	local node = smgr:addAnimatedMeshSceneNode(mesh)
	node:setMaterialTexture(0,	driver:getTexture(installPath .. "media/wall.jpg"))
	node:getMaterial(0).SpecularColor:set(0,0,0,0)

	--[[
	Now, for the first special effect: Animated water. It works like this: The
	WaterSurfaceSceneNode takes a mesh as input and makes
	it wave like a water surface. And if we let this scene node use a nice 
	material like the EMT_REFLECTION_2_LAYER, it looks really cool. We are
	doing this with the next few lines of code. As input mesh, we create a hill
	plane mesh, without hills. But any other mesh could be used for this, you could
	even use the room.3ds (which would look really strange) if you wanted to.
	--]]

	-- add animated water

	mesh = smgr:addHillPlaneMesh("myHill",
		irr.core.dimension2d(20,20),
		irr.core.dimension2d(40,40), nil, 0,
		irr.core.dimension2d(0,0),
		irr.core.dimension2d(10,10))

	node = smgr:addWaterSurfaceSceneNode(mesh:getMesh(0), 3, 300, 30)
	node:setPosition(irr.core.vector3d(0,7,0))

	node:setMaterialTexture(0,	driver:getTexture(installPath .. "media/water.jpg"))
	node:setMaterialTexture(1,	driver:getTexture(installPath .. "media/stones.jpg"))

	node:setMaterialType(irr.video.EMT_REFLECTION_2_LAYER)

	--[[
	The second special effect is very basic, I bet you saw it already in some 
	Irrlicht Engine demos: A transparent billboard combined with a dynamic light. 
	We simply create a light scene node, let it fly around, an to make it look
	more cool, we attach a billboard scene node to it.
	--]]

	-- create light

	
	node = smgr:addLightSceneNode(nil, irr.core.vector3d(0,0,0), 
		irr.video.SColorf(1.0, 0.6, 0.7, 1.0), 600.0)

	local anim = smgr:createFlyCircleAnimator(irr.core.vector3d(0,150,0),250.0)
	
	node:addAnimator(anim)
	anim:drop()

	-- attach billboard to light

	node = smgr:addBillboardSceneNode(node, irr.core.dimension2d(50, 50))
	node:setMaterialFlag(irr.video.EMF_LIGHTING, false)
	node:setMaterialType(irr.video.EMT_TRANSPARENT_ADD_COLOR)
	node:setMaterialTexture(0,	driver:getTexture(installPath .. "media/particlewhite.bmp"))

	--[[
	The next special effect is a lot more interesting: A particle system. The particle
	system in the Irrlicht Engine is quit modular and extensible and yet easy to use.
	There is a particle system scene node into which you can put particle emitters, which
	make particles come out of nothing. These emitters are quite flexible and usually have
	lots of parameters like direction, amount and color of the particles they should create.
	There are different emitters, for example a point emitter which lets particles pop out
	at a fixed point. If the particle emitters available in the engine are not enough for
	you, you can easily create your own ones, you'll simply have to create a class derived
	from the IParticleEmitter interface and attach it to the particle system using setEmitter().
	In this example we create a box particle emitter, which creates particles randomly
	inside a box. The parameters define the box, direction of the particles, minimal and
	maximal new particles per second, color and minimal and maximal livetime of the particles.

	Because only with emitters particle system would be a little bit boring,
	there are particle affectors, which modify particles during they fly around. They can
	be added to the particle system, simulating additional effects like gravity or wind.
	The particle affector we use in this example is an affector, which modifies the color
	of the particles: It lets them fade out. Like the particle emitters, additional
	particle affectors can also be implemented by you, simply derive a class from
	IParticleAffector and add it with addAffector().

	After we set a nice material to the particle system, we have a cool looking camp fire.
	By adjusting material, texture, particle emitter and affector parameters, it is also 
	easily possible to create smoke, rain, explosions, snow, and so on.
	--]]

	-- create a particle system

	local ps = smgr:addParticleSystemSceneNode(false) 
	ps:setPosition(irr.core.vector3d(-70,60,40))
	ps:setScale(irr.core.vector3d(2,2,2))

	ps:setParticleSize(irr.core.dimension2d(20.0, 20.0))

	local em = ps:createBoxEmitter(
		irr.core.aabbox3d(-7,0,-7,7,1,7), 
		irr.core.vector3d(0.0,0.06,0.0),
		80,100, 
		irr.video.SColor(0,255,255,255), irr.video.SColor(0,255,255,255),
		800,2000)

	ps:setEmitter(em)
	em:drop()

	local paf = ps:createFadeOutParticleAffector()

	ps:addAffector(paf)
	paf:drop()

	ps:setMaterialFlag(irr.video.EMF_LIGHTING, false)
	ps:setMaterialTexture(0, driver:getTexture(installPath .. "media/fire.bmp"))
	ps:setMaterialType(irr.video.EMT_TRANSPARENT_VERTEX_ALPHA)

	--[[
	As our last special effect, we want a dynamic shadow be casted from an animated
	character. For this we load a quake 2 .md2 model and place it into our world.
	For creating the shadow, we simply need to call addShadowVolumeSceneNode().
	The color of shadows is only adjustable globally for all shadows, by calling 
	ISceneManager::setShadowColor(). Voila, here is our dynamic shadow.
	--]]

	-- add animated character

	mesh = smgr:getMesh(installPath .. "media/dwarf.x")

	local anode = smgr:addAnimatedMeshSceneNode(mesh)
	anode:setPosition(irr.core.vector3d(-50,20,-60))
	anode:setScale(irr.core.vector3d(2,2,2))
	anode:setAnimationSpeed(20)

	anode:addShadowVolumeSceneNode()	
	smgr:setShadowColor(irr.video.SColor(150,0,0,0))

	-- make the model a little bit bigger and normalize its normals 
	-- because of this for correct lighting
	anode:setScale(irr.core.vector3d(2,2,2))
	anode:setMaterialFlag(irr.video.EMF_NORMALIZE_NORMALS, true)

	--[[
	Finally we simply have to draw everything, that's all.
	--]]

	local camera = smgr:addCameraSceneNodeFPS()
	camera:setPosition(irr.core.vector3d(-50,50,-150))

	-- disable mouse cursor
	device:getCursorControl():setVisible(false)

	local lastFPS = -1

	while device:run() do
		if device:isWindowActive() then
			driver:beginScene(true, true, nil)
			smgr:drawAll()
			driver:endScene()

			local fps = driver:getFPS()
			if lastFPS ~= fps then
				local str = "Irrlicht Engine - SpecialFX example ["
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


