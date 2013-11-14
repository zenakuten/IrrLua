require "IrrLua"

--[[
This Tutorial shows how to move and animate SceneNodes. The
basic concept of SceneNodeAnimators is shown as well as manual
movement of nodes using the keyboard.
--]]



MyEventReceiver = {}

function MyEventReceiver:OnEvent(Event)
	if Event.EventType == irr.EET_KEY_INPUT_EVENT then
		return self:OnKeyEvent(Event.KeyInput.Key, Event.KeyInput.PressedDown, Event.KeyInput.Control, Event.KeyInput.Shift)
	end
	return false
end

function MyEventReceiver:OnKeyEvent(Key, PressedDown, Shift, Control)

	if node and not PressedDown then

		local v = node:getPosition()

		if Key == irr.KEY_KEY_W then
			 v.Y = v.Y + 2
			 node:setPosition(v)
			return true
			end

		if Key == irr.KEY_KEY_S then
			 v.Y = v.Y - 2
			 node:setPosition(v)
			return true
			end

		end

	return false
end


--[[
The event receiver for moving a scene node is ready. So lets just create
an Irrlicht Device and the scene node we want to move. We also create some
other additional scene nodes, to show that there are also some different 
possibilities to move and animate scene nodes.
--]]

function main()

	local installPath = "../../../"

	local receiver = irr.createIEventReceiver(MyEventReceiver)
	local device = irr.createDevice(irr.video.EDT_OPENGL, irr.core.dimension2d(640, 480), 16, false, false, false, receiver)

	local driver = device:getVideoDriver()
	local smgr = device:getSceneManager()

	--[[	
	Create the node for moving it with the 'W' and 'S' key. We create a
	'test node', which is a cube built in into the engine for testing 
	purposes. We place the node a (0,0,30) and we	assign a texture to it
	to let it look a little bit more interesting.

	In Lua, a variable is global by default, and is only local 
	if you specify that it's local.  This is important to note here
	because the event receivers can only access global variables.
	--]]

	-- node is declared globally
	node = {}
	node = smgr:addSphereSceneNode()

	node:setPosition(irr.core.vector3d(0,0,30))
	node:setMaterialTexture(0, driver:getTexture(installPath .. "media/wall.bmp"))
	node:setMaterialFlag(irr.video.EMF_LIGHTING, false)

	--[[ 
	Now we create another node, moving using a scene node animator. Scene node
	animators modify scene nodes and can be attached to any scene node like
	mesh scene nodes, billboards, lights and even camera scene nodes. Scene node
	animators are not only able to modify the position of a scene node, they can
	also animate the textures of an object for example.
	We create a test scene node again an attach a 'fly circle' scene node to it, letting
	this node fly around our first test scene node.
	]]--

	local n = smgr:addCubeSceneNode()
	n:setMaterialTexture(0, driver:getTexture(installPath .. "media/t351sml.jpg"))

	local anim = smgr:createFlyCircleAnimator( irr.core.vector3d(0,0,30) , 20)
	n:addAnimator(anim)
	anim:drop()


	--[[
	The last scene node we add to show possibilities of scene node animators is 
	a md2 model, which uses a 'fly straight' animator to run between to points.
	--]]

	local anms = smgr:addAnimatedMeshSceneNode(smgr:getMesh(installPath .. "media/sydney.md2"))

	if n then 
		n:setMaterialFlag(irr.video.EMF_LIGHTING, false)

		anim = smgr:createFlyStraightAnimator(
						irr.core.vector3d(100,0,60), 
						irr.core.vector3d(-100,0,60), 10000, true)
		anms:addAnimator(anim)
		anim:drop()

		--[[
		To make to model look better, we disable lighting (we have created no lights,
		and so the model would be black), set the frames between which the animation
		should loop, rotate the model around 180 degrees, and adjust the animation speed
		and the texture.
		To set the right animation (frames and speed), we would also be able to just
		call "anms->setMD2Animation(scene::EMAT_RUN)" for the 'run' animation 
		instead of "setFrameLoop" and "setAnimationSpeed",
		but this only works with MD2 animations, and so you know how to start other animations.
		--]]

		anms:setMaterialFlag(irr.video.EMF_LIGHTING, false)
		anms:setFrameLoop(320, 360)
		anms:setAnimationSpeed(30)
		anms:setRotation(irr.core.vector3d(0,180,0))
		anms:setMaterialTexture(0, driver:getTexture(installPath .. "media/sydney.bmp"))
	end	

	--[[
	To be able to look at and move around in this scene, 
	we create a first person shooter style camera and make the 
	mouse cursor invisible.
	--]]

	 smgr:addCameraSceneNodeFPS(nil, 100, 100)
	 device:getCursorControl():setVisible(false)

	--[[
	We have done everything, so lets draw it. We also write the current
	frames per second and the name of the driver to the caption of the
	window.
	--]]

	local lastFPS = -1
	local text = ""

	while device:run() do

		driver:beginScene(true, true, irr.video.SColor(255,113,113,133))
		smgr:drawAll()
		driver:endScene()

		local fps = driver:getFPS()

		 if lastFPS ~= fps then
			text = "Movement Example - Irrlicht Engine ["
			text = text .. driver:getName()
			text = text .. "] fps:" .. fps

			device:setWindowCaption(text)
			lastFPS = fps
			end
		end

	--[[
	In the end, delete the Irrlicht device.
	--]]

	device:drop()
	return 0
end

main()


