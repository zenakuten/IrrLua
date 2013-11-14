
require "IrrLua"

--[[
This tutorial shows how to render to a texture using Irrlicht. Render to texture is a feature with which
it is possible to create nice special effects. In addition, this tutorial shows how to enable specular
highlights.
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

	local device = irr.createDevice(type, irr.core.dimension2d(640, 480), 16, false, false)

	if device == nil then
		return 1   -- could not create selected driver.
	end


	local driver = device:getVideoDriver()
	local smgr = device:getSceneManager()
	local env = device:getGUIEnvironment()
	
	--[[
	Now, we load an animated mesh to be displayed. As in most examples,
	we'll take the fairy md2 model. The difference here: We set the shininess
	of the model to a value other than 0 which is the default value. This
	enables specular highlights on the model if dynamic lighting is on.
	The value influences the size of the highlights.
	--]]

	-- load and display animated fairy mesh

	local fairy = smgr:addAnimatedMeshSceneNode(
		smgr:getMesh(installPath .. "media/faerie.md2"));

	if fairy then
		fairy:setMaterialTexture(0, driver:getTexture(installPath .. "media/faerie2.bmp")) -- set diffuse texture
		fairy:setMaterialFlag(irr.video.EMF_LIGHTING, true) -- enable dynamic lighting
		fairy:getMaterial(0).Shininess = 20.0 -- set size of specular highlights
		fairy:setPosition(irr.core.vector3d(-10,0,-100))
	end
	
	--[[
	To make specular highlights appear on the model, we need a dynamic light in the scene.
	We add one directly in vicinity of the model. In addition, to make the model not that 
	dark, we set the ambient light to gray. 
	--]]

	-- add white light
	local light = smgr:addLightSceneNode(nil,
		irr.core.vector3d(-15,5,-105), irr.video.SColorf(1.0, 1.0, 1.0))

	-- set ambient light
	-- note: original example has a bug.  setAmbientLight takes an SColorf, 
	-- not SColor
	driver:setAmbientLight(irr.video.SColorf(60/255,60/255,60/255,0))
	
	--[[
	The next is just some standard stuff: Add a user controlled camera to the scene, disable
	mouse cursor, and add a test cube and let it rotate to make the scene more interesting.
	--]]

	-- add fps camera
	local fpsCamera = smgr:addCameraSceneNodeFPS()
	fpsCamera:setPosition(irr.core.vector3d(-50,50,-150))

	-- disable mouse cursor
	device:getCursorControl():setVisible(false)

	-- create test cube
	local test = smgr:addCubeSceneNode(60)

	-- let the cube rotate and set some light settings
	local anim = smgr:createRotationAnimator(
		irr.core.vector3d(0.3, 0.3,0))

	test:setPosition(irr.core.vector3d(-100,0,-100))
	test:setMaterialFlag(irr.video.EMF_LIGHTING, false) -- enable dynamic lighting
	test:addAnimator(anim)
	anim:drop()

	-- set window caption
	device:setWindowCaption("Irrlicht Engine - Render to Texture and Specular Highlights example")
	
	--[[
	To test out the render to texture feature, we need a render target texture. These are not 
	like standard textures, but need to be created first. To create one, we call 
	IVideoDriver::createRenderTargetTexture() and specify the size of the texture. Please
	don't use sizes bigger than the frame buffer for this, because the render target shares
	the zbuffer with the frame buffer. And because we want to render the scene not from the
	user camera into the texture, we add another, fixed camera to the scene. But before we
	do all this, we check if the current running driver is able to render to textures. If 
	it is not, we simply display a warning text.
	--]]

	-- create render target
	local rt 
	local fixedCam
	

	if driver:queryFeature(irr.video.EVDF_RENDER_TO_TARGET) then
		rt = driver:createRenderTargetTexture(irr.core.dimension2d(256,256))
		test:setMaterialTexture(0, rt) -- set material of cube to render target

		-- add fixed camera
		fixedCam = smgr:addCameraSceneNode(nil, irr.core.vector3d(10,10,-80),
 			irr.core.vector3d(-10,10,-100))
	else
		-- create problem text
		local skin = env:getSkin()
		local font = env:getFont(installPath .. "media/fonthaettenschweiler.bmp")
		if font then 
			skin:setFont(font)
		end

		local text = env:addStaticText(
			"Your hardware or this renderer is not able to use the " .. 
			"render to texture feature. RTT Disabled.",
			irr.core.rect(150,20,470,60))

		text:setOverrideColor(irr.video.SColor(100,255,255,255))
	end
	
	--[[
	Nearly finished. Now we need to draw everything. Every frame, we draw the scene twice.
	Once from the fixed camera into the render target texture and once as usual. When rendering
	into the render target, we need to disable the visibilty of the test cube, because it has
	the render target texture applied to it.
	That's, wasn't quite complicated I hope. :)
	--]]

	while device:run() do
		if device:isWindowActive() then
		
			driver:beginScene(true, true, nil)

			if rt then
				-- draw scene into render target
				-- set render target texture

				driver:setRenderTarget(rt, true, true, irr.video.SColor(0,0,0,255))

				-- make cube invisible and set fixed camera as active camera
				test:setVisible(false)
				smgr:setActiveCamera(fixedCam)

				-- draw whole scene into render buffer
				smgr:drawAll()

				-- set back old render target
				driver:setRenderTarget(nil, true, true)

				-- make the cube visible and set the user controlled camera as active one
				test:setVisible(true)
				smgr:setActiveCamera(fpsCamera)
			end
			
			-- draw scene normally
			smgr:drawAll()
			env:drawAll()

			driver:endScene()
		end
	end -- while

	if rt then
		rt:drop() -- drop render target because we created if with a create() method
	end

	device:drop() -- drop device
	return 0
end

main()


