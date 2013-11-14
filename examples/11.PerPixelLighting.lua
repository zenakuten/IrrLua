require "IrrLua"

--[[

This tutorial shows how to use one of the built in more complex materials in irrlicht:
Per pixel lighted surfaces using normal maps and parallax mapping. It will also show 
how to use fog and moving particle systems. And don't panic: You dont need any 
experience with shaders to use these materials in Irrlicht.

For this example, we need an event receiver, to make it possible for the user
to switch between the three available material types. In addition, the event
receiver will create some small GUI window which displays what material is 
currently being used. There is nothing special done in this class, so maybe
you want to skip reading it.

--]]

function setMaterial()
	local type = irr.video.EMT_SOLID
	local selected = ListBox:getSelected()
	if selected == 0 then type = irr.video.EMT_SOLID
		elseif selected == 1 then type = irr.video.EMT_NORMAL_MAP_SOLID
		elseif selected == 2 then type = irr.video.EMT_PARALLAX_MAP_SOLID
	end

	room:setMaterialType(type)
	local renderer = driver:getMaterialRenderer(type)
	if not renderer or renderer:getRenderCapability() ~= 0 then
		ProblemText:setVisible(true)
	else
		ProblemText:setVisible(false)
	end
end	

function InitEvents()

	local skin = env:getSkin()
	local font = env:getFont(installPath .. "media/fonthaettenschweiler.bmp")

	if font then
		skin:setFont(font)
	end

	local window = env:addWindow(irr.core.rect(490,390,630,470),false, "Use 'E' + 'R' to change")
	ListBox = env:addListBox(irr.core.rect(2,22,135,78), window)
	
	ListBox:addItem("Diffuse")
	ListBox:addItem("Bump mapping")
	ListBox:addItem("Parallax mapping")

	ListBox:setSelected(1)

	ProblemText = env:addStaticText("Your hardware or this renderer is not able to use the " ..
										  "needed shaders for this material.   Using fallback materials.",
										  irr.core.rect(150,20,470,60))

	local renderer = driver:getMaterialRenderer(irr.video.EMT_PARALLAX_MAP_SOLID)
	if renderer and renderer:getRenderCapability() == 0 then
		ListBox:setSelected(2)
	end

	setMaterial()
end

MyEventReceiver = {}

function MyEventReceiver:OnEvent(Event)
	if Event.EventType == irr.EET_KEY_INPUT_EVENT then
		return self:OnKeyEvent(Event.KeyInput.Key,Event.KeyInput.PressedDown, Event.KeyInput.Shift, Event.KeyInput.Control)
	end
	return false
end

function MyEventReceiver:OnKeyEvent(Key, PressedDown, Shift, Control)
	
	if room and ListBox and not PressedDown then

		local sel = ListBox:getSelected()

		if Key == irr.KEY_KEY_R then
			sel = sel + 1
		elseif Key == irr.KEY_KEY_E then
			sel = sel - 1
		else
			return false
		end

		if sel > 2 then sel = 2 end
		if sel < 0 then sel = 0 end
		ListBox:setSelected(sel)
		setMaterial()
	end
	
	return false
end


--[[
Now for the real fun. We create an Irrlicht Device and start to setup the scene.
--]]

function main()

	installPath = "../../../"
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

	device = irr.createDevice(type, irr.core.dimension2d(640, 480))
	
	if device == nil then
		print("Error creating device")
		return 1
	end

	
	--[[
	Before we start with the interesting stuff, we do some simple things: 
	Store pointers to the most important parts of the engine (video driver,
	scene manager, gui environment) to safe us from typing too much, 
	add an irrlicht engine logo to the window and a user controlled 
	first person shooter style camera. Also, we let the engine now 
	that it should store all textures in 32 bit. This necessary because
	for parallax mapping, we need 32 bit textures.
	--]]

	driver = device:getVideoDriver()
	smgr = device:getSceneManager()
	env = device:getGUIEnvironment()


	driver:setTextureCreationFlag(irr.video.ETCF_ALWAYS_32_BIT, true)

	-- add irrlicht logo
	env:addImage(driver:getTexture(installPath .. "media/irrlichtlogoalpha2.tga"),
		irr.core.position2d(10,10))
		
	-- add camera
	local camera = smgr:addCameraSceneNodeFPS(nil,100.0,300.0)
	camera:setPosition(irr.core.vector3d(-200,200,-200))

	-- disable mouse cursor
	device:getCursorControl():setVisible(false)


	--[[
	Because we want the whole scene to look a little bit scarier, we add some fog 
	to it. This is done by a call to IVideoDriver::setFog(). There you can set
	various fog settings. In this example, we use pixel fog, because it will
	work well with the materials we'll use in this example.
	Please note that you will have to set the material flag EMF_FOG_ENABLE
	to 'true' in every scene node which should be affected by this fog.
	--]]

	driver:setFog(irr.video.SColor(0,138,125,81), true, 250, 1000, 0, true)

	--[[
	To be able to display something interesting, we load a mesh from a .3ds file
	which is a room I modeled with anim8or. It is the same room as 
	from the specialFX example. Maybe you remember from that tutorial,
	I am no good modeler at all and so I totally messed up the texture
	mapping in this model, but we can simply repair it with the
	IMeshManipulator::makePlanarTextureMapping() method.
	--]]

	local roomMesh = smgr:getMesh(installPath .. "media/room.3ds")

	if roomMesh then
	
		smgr:getMeshManipulator():makePlanarTextureMapping(
				roomMesh:getMesh(0), 0.003)

		--[[
		Now for the first exciting thing: If we successfully loaded the mesh
		we need to apply textures to it. Because we want this room to be 
		displayed with a very cool material, we have to do a little bit more
		than just set the textures. Instead of only loading a color map as usual,
		we also load a height map which is simply a grayscale texture. From this
		height map, we create a normal map which we will set as second texture of the
		room. If you already have a normal map, you could directly set it, but I simply
		didn´t find a nice normal map for this texture.
		The normal map texture is being generated by the makeNormalMapTexture method
		of the VideoDriver. The second parameter specifies the height of the heightmap.
		If you set it to a bigger value, the map will look more rocky.
		--]]

		local colorMap = driver:getTexture(installPath .. "media/rockwall.bmp")
		local normalMap = driver:getTexture(installPath .. "media/rockwall_height.bmp")
		
		driver:makeNormalMapTexture(normalMap, 9.0)

		--[[
		But just setting color and normal map is not everything. The material we want to
		use needs some additional informations per vertex like tangents and binormals.
		Because we are too lazy to calculate that information now, we let Irrlicht do
		this for us. That's why we call IMeshManipulator::createMeshWithTangents(). It
		creates a mesh copy with tangents and binormals from any other mesh. 
		After we've done that, we simply create a standard mesh scene node with this
		mesh copy, set color and normal map and adjust some other material settings.
		Note that we set EMF_FOG_ENABLE to true to enable fog in the room.
		--]]

		local tangentMesh = smgr:getMeshManipulator():createMeshWithTangents(roomMesh:getMesh(0))
		room = smgr:addMeshSceneNode(tangentMesh)

			
		room:setMaterialTexture(0,	colorMap)
		room:setMaterialTexture(1,	normalMap)

		room:getMaterial(0).SpecularColor:set(0,0,0,0)

		room:setMaterialFlag(irr.video.EMF_FOG_ENABLE, true)
		room:setMaterialType(irr.video.EMT_PARALLAX_MAP_SOLID)
		room:getMaterial(0).MaterialTypeParam = 0.035 -- adjust height for parallax effect

		-- drop mesh because we created it with a create.. call.
		tangentMesh:drop()
	end

	--[[
	After we've created a room shaded by per pixel lighting, we add a sphere
	into it with the same material, but we'll make it transparent. In addition,
	because the sphere looks somehow like a familiar planet, we make it rotate.
	The procedure is similar as before. The difference is that we are loading 
	the mesh from an .x file which already contains a color map so we do not 
	need to load it manually. But the sphere is a little bit too small for our
	needs, so we scale it by the factor 50.
	--]]

	-- add earth sphere
	local earthMesh = smgr:getMesh(installPath .. "media/earth.x")
	if earthMesh then
		-- create mesh copy with tangent informations from original earth.x mesh
		local tangentSphereMesh = smgr:getMeshManipulator():createMeshWithTangents(earthMesh:getMesh(0))

		-- set the alpha value of all vertices to 200
		smgr:getMeshManipulator():setVertexColorAlpha(tangentSphereMesh, 200)
		
		-- scale the mesh by factor 50
		smgr:getMeshManipulator():scaleMesh(
			tangentSphereMesh, irr.core.vector3d(50,50,50))

		-- create mesh scene node
		local sphere = smgr:addMeshSceneNode(tangentSphereMesh)
		sphere:setPosition(irr.core.vector3d(-70,130,45))

		-- load heightmap, create normal map from it and set it
		local earthNormalMap = driver:getTexture(installPath .. "media/earthbump.bmp")
		driver:makeNormalMapTexture(earthNormalMap, 20.0)
		sphere:setMaterialTexture(1, earthNormalMap)

		-- adjust material settings
		sphere:setMaterialFlag(irr.video.EMF_FOG_ENABLE, true)
		sphere:setMaterialType(irr.video.EMT_NORMAL_MAP_TRANSPARENT_VERTEX_ALPHA)

		-- add rotation animator
		local anim = smgr:createRotationAnimator(irr.core.vector3d(0,0.1,0))	
		sphere:addAnimator(anim)
		anim:drop()

		-- drop mesh because we created it with a create.. call.
		tangentSphereMesh:drop()
	end

	--[[
	Per pixel lighted materials only look cool when there are moving lights. So we
	add some. And because moving lights alone are so boring, we add billboards 
	to them, and a whole particle system to one of them. 
	We start with the first light which is red and has only the billboard attached.
	--]]

	-- add light 1 (nearly red)
	local light1 = smgr:addLightSceneNode(nil, irr.core.vector3d(0,0,0), 
		irr.video.SColorf(0.5, 1.0, 0.5, 0.0), 200.0)

	-- add fly circle animator to light 1
	local anim = 
		smgr:createFlyCircleAnimator(irr.core.vector3d(50,300,0),190.0, -0.003)
	light1:addAnimator(anim)
	anim:drop()

	-- attach billboard to the light
	local bill = smgr:addBillboardSceneNode(light1, irr.core.dimension2d(60, 60))

	bill:setMaterialFlag(irr.video.EMF_LIGHTING, false)
	bill:setMaterialType(irr.video.EMT_TRANSPARENT_ADD_COLOR)
	bill:setMaterialTexture(0, driver:getTexture(installPath .. "media/particlered.bmp"))

	--[[
	Now the same again, with the second light. The difference is that we add a particle
	system to it too. And because the light moves, the particles of the particlesystem
	will follow. If you want to know more about how particle systems are created in 
	Irrlicht, take a look at the specialFx example.
	Maybe you will have noticed that we only add 2 lights, this has a simple reason: The
	low end version of this material was written in ps1.1 and vs1.1, which doesn't allow 
	more lights. You could add a third light to the scene, but it won't be used to 
	shade the walls. But of course, this will change in future versions of Irrlicht were
	higher versions of pixel/vertex shaders will be implemented too.
	--]]

	-- add light 2 (gray)
	local light2 = smgr:addLightSceneNode(nil, irr.core.vector3d(0,0,0), 
		irr.video.SColorf(1.0, 0.2, 0.2, 0.0), 200.0)

	-- add fly circle animator to light 2
	anim = smgr:createFlyCircleAnimator (irr.core.vector3d(0,150,0),200.0) 
	light2:addAnimator(anim)
	anim:drop()

	-- attach billboard to light
	bill = smgr:addBillboardSceneNode(light2, irr.core.dimension2d(120, 120))
	bill:setMaterialFlag(irr.video.EMF_LIGHTING, false)
	bill:setMaterialType(irr.video.EMT_TRANSPARENT_ADD_COLOR)
	bill:setMaterialTexture(0, driver:getTexture(installPath .. "media/particlewhite.bmp"))

	-- add particle system
	local ps = smgr:addParticleSystemSceneNode(false, light2)

	ps:setParticleSize(irr.core.dimension2d(30.0, 40.0))

	-- create and set emitter
	local em = ps:createBoxEmitter(
		irr.core.aabbox3d(-3,0,-3,3,1,3), 
		irr.core.vector3d(0.0,0.03,0.0),
		80,100, 
		irr.video.SColor(0,255,255,255), irr.video.SColor(0,255,255,255),
		400,1100)
	ps:setEmitter(em)
	em:drop()

	-- create and set affector
	local paf = ps:createFadeOutParticleAffector()
	ps:addAffector(paf)
	paf:drop()

	-- adjust some material settings
	ps:setMaterialFlag(irr.video.EMF_LIGHTING, false)
	ps:setMaterialTexture(0, driver:getTexture(installPath .. "media/fireball.bmp"))
	ps:setMaterialType(irr.video.EMT_TRANSPARENT_VERTEX_ALPHA)

	--[[ 
	here we need to set the event receiver after some globals have been
	created
	--]]

	InitEvents()
	local receiver = irr.createIEventReceiver(MyEventReceiver)
	device:setEventReceiver(receiver)

	--[[
	Finally, draw everything. That's it.
	--]]

	local lastFPS = -1

	while device:run() do
		if device:isWindowActive() then
			driver:beginScene(true, true, nil)

			smgr:drawAll()
			env:drawAll()

			driver:endScene()

			local fps = driver:getFPS()

			if lastFPS ~= fps then
				local str = "Per pixel lighting example - Irrlicht Engine ["
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



