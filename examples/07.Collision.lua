
require "IrrLua"

--[[
In this tutorial, I will show how to collision detection with the Irrlicht Engine. 
I will describe 3 methods: Automatic collision detection for moving through 3d worlds
with stair climbing and sliding, manual triangle picking and manual
scene node picking.

To start, we take the program from tutorial 2, which loaded and displayed a quake 3
level. We will use the level to walk in it and to pick triangles from it. In addition
we'll place 3 animated models into it for scene node picking. The following code 
starts up the engine and loads
a quake 3 level. I will not explain it, because it should already be known from tutorial
2.
--]]


function main()

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

	local device = irr.createDevice(type, irr.core.dimension2d(640, 480))

	if device == nil then
		return 1   -- could not create selected driver.
	end

	local driver = device:getVideoDriver()
	local smgr = device:getSceneManager()

	
	device:getFileSystem():addZipFileArchive(installPath .. "media/map-20kdm2.pk3")

	
	local q3levelmesh = smgr:getMesh("20kdm2.bsp")
	local q3node
	
	if q3levelmesh ~= nil then
		q3node = smgr:addOctTreeSceneNode(q3levelmesh)
	end

	--[[	
	So far so good, we've loaded the quake 3 level like in tutorial 2. Now, here
	comes something different: We create a triangle selector. A triangle selector
	is a class which can fetch the triangles from scene nodes for doing different
	things with them, for example collision detection. There are different triangle
	selectors, and all can be created with the ISceneManager. In this example,
	we create an OctTreeTriangleSelector, which optimizes the triangle output a l
	little bit by reducing it like an octree. This is very useful for huge meshes
	like quake 3 levels.
	Afte we created the triangle selector, we attach it to the q3node. This is not
	necessary, but in this way, we do not need to care for the selector, for example
	dropping it after we do not need it anymore.
	--]]

	local selector
	
	if q3node ~= nil then
		q3node:setPosition(irr.core.vector3d(-1370,-130,-1400))

		selector = smgr:createOctTreeTriangleSelector(q3levelmesh:getMesh(0), q3node, 128)
		q3node:setTriangleSelector(selector)
		selector:drop()
	end


	--[[
	We add a first person shooter camera to the scene for being able to move in the quake 3
	level like in tutorial 2. But this, time, we add a special animator to the 
	camera: A Collision Response animator. This thing modifies the scene node to which
	it is attached to in that way, that it may no more move through walls and is affected
	by gravity. The only thing we have to tell the animator is how the world looks like,
	how big the scene node is, how gravity and so on. After the collision response animator
	is attached to the camera, we do not have to do anything more for collision detection,
	anything is done automaticly, all other collision detection code below is for picking.
	And please note another cool feature: The collsion response animator can be attached
	also to all other scene nodes, not only to cameras. And it can be mixed with other
	scene node animators. In this way, collision detection and response in the Irrlicht
	engine is really, really easy.
	Now we'll take a closer look on the parameters of createCollisionResponseAnimator().
	The first parameter is the TriangleSelector, which specifies how the world, against
	collision detection is done looks like. The second parameter is the scene node, which
	is the object, which is affected by collision detection, in our case it is the camera.
	The third defines how big the object is, it is the radius of an ellipsoid. Try it out 
	and change the radius to smaller values, the camera will be able to move closer to walls
	after this. The next parameter is the direction and speed of gravity. You could
	set it to (0,0,0) to disable gravity. And the last value is just a translation: Without
	this, the ellipsoid with which collision detection is done would be around the camera,
	and the camera would be in the middle of the ellipsoid. But as human beings, we are 
	used to have our eyes on top of the body, with which we collide with our world, not
	in the middle of it. So we place the scene node 50 units over the center of the 
	ellipsoid with this parameter. And that's it, collision detection works now. 
	--]]

	local camera = smgr:addCameraSceneNodeFPS(nil,100,300)
	camera:setPosition(irr.core.vector3d(-100,50,-150))

	local anim = smgr:createCollisionResponseAnimator(
		selector, camera, irr.core.vector3d(30,50,30),
		irr.core.vector3d(0,-3,0), 
		irr.core.vector3d(0,50,0))

	camera:addAnimator(anim)
	anim:drop()

	--[[
	Because collision detection is no big deal in irrlicht, I'll describe how to
	do two different types of picking in the next section. But before this,
	I'll prepare the scene a little. I need three animated characters which we 
	could pick later, a dynamic light for lighting them,
	a billboard for drawing where we found an intersection,	and, yes, I need to
	get rid of this mouse cursor. :)
	--]]

	-- disable mouse cursor

	device:getCursorControl():setVisible(false)

	-- add billboard

	local bill = smgr:addBillboardSceneNode()
	bill:setMaterialType(irr.video.EMT_TRANSPARENT_ADD_COLOR )
	bill:setMaterialTexture(0, driver:getTexture(installPath .. "media/particle.bmp"))
	bill:setMaterialFlag(irr.video.EMF_LIGHTING, false)
	bill:setSize(irr.core.dimension2d(20.0, 20.0))

	-- add 3 animated faeries.

	local material = irr.video.SMaterial()

	material.Texture1 = driver:getTexture(installPath .. "media/faerie2.bmp")
	material.Lighting = true

	local node
	local faerie = smgr:getMesh(installPath .. "media/faerie.md2")

	if faerie ~= nil then
		node = smgr:addAnimatedMeshSceneNode(faerie)
		node:setPosition(irr.core.vector3d(-70,0,-90))
		node:setMD2Animation(irr.scene.EMAT_RUN)
		local ref1 = node:getMaterial(0) 
		ref1.Texture1 = material.Texture1
		ref1.Lighting = material.Lighting

		node = smgr:addAnimatedMeshSceneNode(faerie)
		node:setPosition(irr.core.vector3d(-70,0,-30))
		node:setMD2Animation(irr.scene.EMAT_SALUTE)
		local ref2 = node:getMaterial(0) 
		ref2.Texture1 = material.Texture1
		ref2.Lighting = material.Lighting

		node = smgr:addAnimatedMeshSceneNode(faerie)
		node:setPosition(irr.core.vector3d(-70,0,-60))
		node:setMD2Animation(irr.scene.EMAT_JUMP)
		local ref3 = node:getMaterial(0) 
		ref3.Texture1 = material.Texture1
		ref3.Lighting = material.Lighting
	end

	material.Texture1 = nil
	material.Lighting = false

	-- Add a light

	smgr:addLightSceneNode(nil, irr.core.vector3d(-60,100,400),
		irr.video.SColorf(1,1,1,1), 600)


	--[[
	For not making it to complicated, I'm doing picking inside the drawing loop.
	We take two pointers for storing the current and the last selected scene node and 
	start the loop.
	--]]


	local selectedSceneNode
	local lastSelectedSceneNode

	
	local lastFPS = -1

	while device:run() do
		if device:isWindowActive() then
			driver:beginScene(true, true, irr.video.SColor(0,0,0,0))
			smgr:drawAll()

			--[[
			After we've drawn the whole scene whit smgr->drawAll(), we'll do the first
			picking: We want to know which triangle of the world we are looking at. In addition,
			we want the exact point of the quake 3 level we are looking at.
			For this, we create a 3d line starting at the position of the camera and going 
			through the lookAt-target of it. Then we ask the collision manager if this line
			collides with a triangle of the world stored in the triangle selector. If yes,
			we draw the 3d triangle and set the position of the billboard to the intersection 
			point.
			--]]
			
			local line = irr.core.line3d() 
			line.start = camera:getPosition()

			-- *note*  line.end is a syntax error because 'end' is a reserved word
			-- in lua

			line["end"] = line.start + (camera:getTarget() - line.start):normalize() * irr.core.vector3d(1000,1000,1000)

			local intersection = irr.core.vector3d() 
			local tri = irr.core.triangle3d()

			if smgr:getSceneCollisionManager():getCollisionPoint(
				line, selector, intersection, tri) then

				bill:setPosition(intersection)
					
				driver:setTransform(irr.video.ETS_WORLD, irr.core.matrix4())
				driver:setMaterial(material)
				driver:draw3DTriangle(tri, irr.video.SColor(0,255,0,0))
			end	


			--[[
			Another type of picking supported by the Irrlicht Engine is scene node picking
			based on bouding boxes. Every scene node has got a bounding box, and because of
			that, it's very fast for example to get the scene node which the camera looks
			at. Again, we ask the collision manager for this, and if we've got a scene node,
			we highlight it by disabling Lighting in its material, if it is not the 
			billboard or the quake 3 level.
			--]]

			selectedSceneNode = smgr:getSceneCollisionManager():getSceneNodeFromCameraBB(camera, 0)

			if lastSelectedSceneNode ~= nil then
				lastSelectedSceneNode:setMaterialFlag(irr.video.EMF_LIGHTING, true)
			end

			if (selectedSceneNode == q3node) or (selectedSceneNode == bill) then
				selectedSceneNode = nil
			end

			if selectedSceneNode ~= nil then
				selectedSceneNode:setMaterialFlag(irr.video.EMF_LIGHTING, false)
			end

			lastSelectedSceneNode = selectedSceneNode

			--[[
			That's it, we just have to finish drawing.
			--]]


			local fps = driver:getFPS()

			if lastFPS ~= fps then
				local str = "Collision detection example - Irrlicht Engine ["
				str = str .. driver:getName()
				str = str .. "] FPS:"
				str = str .. fps

				device:setWindowCaption(str)
				lastFPS = fps
			end	
		end	

	driver:endScene()
	end

	device:drop()
	return 0
end

main()
