
require "IrrLua"

--[[
This Tutorial shows how to do 2d graphics with the Irrlicht Engine.
It shows how to draw images, keycolor based sprites,
transparent rectangles and different fonts. You will may consider
this useful if you want to make a 2d game with the engine, or if 
you want to draw a cool interface or head up display for your 3d game.
--]]

--[[
At first, we let the user select the driver type, then 
start up the engine, set a caption, and get a pointer
to the video driver.
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
	local device = irr.createDevice(driverType, irr.core.dimension2d(512, 384))

	if device == nil then
		return 1   -- could not create selected driver.
	end

	device:setWindowCaption("Irrlicht Engine - 2D Graphics Demo")

	local driver = device:getVideoDriver()

	--[[
	All 2d graphics in this example are put together into one texture,
	2ddemo.bmp. Because we want to draw colorkey based sprites, we need 
	to load this texture and tell the engine, which
	part of it should be transparent based on a colorkey. In this example,
	we don't tell it the color directly, we just say "Hey Irrlicht Engine, 
	you'll find the color I want at position (0,0) on the texture.".
	Instead, it would be also possible to call 
	driver->makeColorKeyTexture(images, video::SColor(0,0,0,0)), to make
	e.g. all black pixels transparent. Please note, that makeColorKeyTexture
	just creates an alpha channel based on the color. 
	--]]

	local images = driver:getTexture(installPath .. "media/2ddemo.bmp")
	driver:makeColorKeyTexture(images, irr.core.position2d(0,0))
	
	--[[
	To be able to draw some text with two different fonts, we load them.
	Ok, we load just one, as first font we just use the default font which is
	built into the engine.
	Also, we define two rectangles, which specify the position of the
	images of the red imps (little flying creatures) in the texture.
	--]]

	font = device:getGUIEnvironment():getBuiltInFont()
	font2 = device:getGUIEnvironment():getFont(installPath .. "media/fonthaettenschweiler.bmp")

	local imp1 = irr.core.rect(349,15,385,78)
	local imp2 = irr.core.rect(387,15,423,78)
	local imp3

	--[[
	Everything is prepared, now we can draw everything in the draw loop,
	between the begin scene and end scene calls. In this example, we 
	are just doing 2d graphics, but it would be no problem to mix them
	with 3d graphics. Just try it out, and draw some 3d vertices or set
	up a scene with the scene manager and draw it.
	--]]

	while device:run() and driver ~= nil do
		if device:isWindowActive() then
			local time = device:getTimer():getTime()

			driver:beginScene(true, true, irr.video.SColor(0,120,102,136))

			--[[	
			First, we draw 3 sprites, using the alpha channel we created with
			makeColorKeyTexture. The last parameter specifiys that the drawing
			method should use thiw alpha channel. The parameter before the last
			one specifies a color, with wich the sprite should be colored.
			(255,255,255,255) is full white, so the sprite will look like the 
			original. The third sprite is drawed colored based on the time.
			--]]
	
			-- draw fire & dragons background world
			driver:draw2DImage(images, irr.core.position2d(50,50),
				irr.core.rect(0,0,342,224), nil, 
				irr.video.SColor(255,255,255,255), true)

			if (math.mod((time / 500) , 2)) < 0.5 then imp3 = imp1 else imp3 = imp2 end

			-- draw flying imp 
			driver:draw2DImage(images, irr.core.position2d(164,125), imp3, nil, 
					irr.video.SColor(255,255,255,255), true)

			-- draw second flying imp with colorcylce
			driver:draw2DImage(images, irr.core.position2d(270,105), imp3, nil, 
					irr.video.SColor(255,math.mod(time, 255),255,255), true)

			--[[	
			Drawing text is really simple. The code should be self explanatory.
			--]]	

			-- draw some text
			if font ~= nil then
			font:draw("This demo shows that Irrlicht is also capable of drawing 2D graphics.", 
				irr.core.rect(130,10,300,50), irr.video.SColor(255,255,255,255))
			end

			-- draw some other text
			if font2 ~= nil then
				font2:draw("Also mixing with 3d graphics is possible.", 
				irr.core.rect(130,20,300,60),
				irr.video.SColor(255,math.mod(time, 255), math.mod(time,255),255))

				--[[
				At last, we draw the Irrlicht Engine logo (without using a color or
				an alpha channel) and a transparent 2d Rectangle at the position of 
				the mouse cursor.
				--]]

				-- draw logo
				driver:draw2DImage(images, irr.core.position2d(10,10), irr.core.rect(354,87,442,118))

				-- draw transparent rect under cursor
				m = device:getCursorControl():getPosition()
				driver:draw2DRectangle(irr.video.SColor(100,255,255,255),
					irr.core.rect(m.X - 20, m.Y - 20, 
								  m.X + 20, m.Y + 20))

				driver:endScene()
			end
		end
	end	

	--[[	
	That's all, it was not really difficult, I hope.
	--]]	

	device:drop()
	return 0
end

main()

