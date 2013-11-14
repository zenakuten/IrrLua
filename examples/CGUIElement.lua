

require "IrrLuaSpriteSkin"
require "IrrLua"


function loadSkin(Skin, skinNum)

	if skinNum < 0 or skinNum > 2 or Skin == nil then
		return
	end

	--Bubbly blue
	if skinNum == 0 then
		--Here we load a nice glass button image to use when drawing all 3D button faces
		--The skin supports animated images, so we specify * 1 indicating there is only one frame
		Skin:Load(irr.gui.EGEIT_BUTTON_PANE_STANDARD, "../media/skins/bb1.tga", 0,0,114*1,114,114,114,false)
		
		--Here we load an image used for animating the button when it's pressed
		--The animation has 8 frames laid out horizontally, so we specify that as *8 in the Ax parameter
		--If the animation was laid out vertically, you would specify *8 in the Ay parameter
		Skin:Load(irr.gui.EGEIT_BUTTON_PANE_PRESSED, "../media/skins/bbp2.tga", 0,0,114*8,114,114,114,false)

		--There are 8 frames, so we want them to animate pretty quickly on a button press
		Skin:setAnimationSpeed(irr.gui.EGEIT_BUTTON_PANE_PRESSED, 10)

		--We only want the animation to happen once, so we turn looping off.
		--To make the animation happen again, skin->resetAnimation() must be called when the 
		--mouse button is clicked. Check the event receiver for info on how to do that.
		Skin:setLoop(irr.gui.EGEIT_BUTTON_PANE_PRESSED, false)

		--Here we load an animated image for the window titles
		--4 frames, laid out horizontally.
		Skin:Load(irr.gui.EGEIT_WINDOW_BACKGROUND_TITLEBAR, "../media/skins/fireline_e0.tga", 0,0,600*4,50,600,50,false)
		Skin:setAnimationSpeed(irr.gui.EGEIT_WINDOW_BACKGROUND_TITLEBAR, 70)	
		
		--Finally, load the image to be used for window backgrounds.
		--It's a simple 2 frame animation of some lighting flickering
		Skin:Load(irr.gui.EGEIT_WINDOW_BACKGROUND, "../media/skins/bg4.tga", 0,0,232*1,232,232,232,false)

		Skin:Load(irr.gui.EGEIT_TAB_BODY, "../media/skins/bg4.tga", 0,0,232*1,232,232,232,false)
		Skin:Load(irr.gui.EGEIT_TAB_BUTTON, "../media/skins/bb1.tga", 0,0,114*1,114,114,114,false)
		Skin:Load(irr.gui.EGEIT_MENU_PANE, "../media/skins/bg4.tga", 0,0,232*1,232,232,232,false)
		Skin:Load(irr.gui.EGEIT_TOOLBAR, "../media/skins/bg4.tga", 0,0,232*1,232,232,232,false)
	elseif skinNum == 1 then
		-- Aero Glass
		-- Here we load a nice glass button image to use when drawing all 3D button faces
		-- The skin supports animated images, so we specify * 1 indicating there is only one frame
		Skin:Load(irr.gui.EGEIT_BUTTON_PANE_STANDARD, "../media/skins/blackbsq.tga", 0,0,145*1,145,145,145,false)
		

		--Here we load an image used for animating the button when it's pressed
		--The animation has 8 frames laid out horizontally, so we specify that as *8 in the Ax parameter
		--If the animation was laid out vertically, you would specify *8 in the Ay parameter
		Skin:Load(irr.gui.EGEIT_BUTTON_PANE_PRESSED, "../media/skins/blackbsqpush.tga", 0,0,145*8,145,145,145,false)

		--There are 8 frames, so we want them to animate pretty quickly on a button press
		Skin:setAnimationSpeed(irr.gui.EGEIT_BUTTON_PANE_PRESSED, 10)

		--We only want the animation to happen once, so we turn looping off.
		--To make the animation happen again, skin->resetAnimation() must be called when the 
		--mouse button is clicked. Check the event receiver for info on how to do that.
		Skin:setLoop(irr.gui.EGEIT_BUTTON_PANE_PRESSED, false)

		--Here we load a 'blank' image so we don't have titles 
		Skin:Load(irr.gui.EGEIT_WINDOW_BACKGROUND_TITLEBAR, "../media/skins/blank.tga", 0,0,32*1,32,32,32,false)
		
		Skin:Load(irr.gui.EGEIT_WINDOW_BACKGROUND, "../media/skins/bg5.tga", 0,0,399*1,399,399,399,false)
		
		Skin:Load(irr.gui.EGEIT_TAB_BODY, "../media/skins/bg5.tga", 0,0,399*1,399,399,399,false)
		Skin:Load(irr.gui.EGEIT_TAB_BUTTON, "../media/skins/blackbsq.tga", 0,0,145*1,145,145,145,false)
		Skin:Load(irr.gui.EGEIT_MENU_PANE, "../media/skins/bg5.tga", 0,0,399*1,399,399,399,false)
		Skin:Load(irr.gui.EGEIT_TOOLBAR, "../media/skins/bg5.tga", 0,0,399*1,399,399,399,false)
	end
end



-- create custom GUI element
CGUIButtonEx = {}


-- implement draw routine
function CGUIButtonEx:draw()

	local rect = self:getAbsolutePosition()
	
	local a = 0
	local Color = irr.video.SColor(255,175,175,175)
	local Outline = irr.video.SColor(255,0,0,0)
	
	if self.MouseDown then 
		a = 2 
		Color = irr.video.SColor(255,125,125,125)
	end
	
	if self.MouseOver then
		Outline = irr.video.SColor(255,255,255,255)
	end
	
	local r = irr.core.rect(rect.UpperLeftCorner.X + a, rect.UpperLeftCorner.Y + a, 
							   rect.LowerRightCorner.X - a, rect.LowerRightCorner.Y - a)


	-- draw drop shadow
	self.Environment:getVideoDriver():draw2DRectangle( irr.video.SColor(128,0,0,0) , 
					irr.core.rect(rect.UpperLeftCorner.X  + 5, rect.UpperLeftCorner.Y  + 5, 
		            			  rect.LowerRightCorner.X + 5, rect.LowerRightCorner.Y + 5), nil)
	

	-- draw black outline
	self.Environment:getVideoDriver():draw2DRectangle(Outline, r, nil)
	
	
	-- draw rect background
	self.Environment:getVideoDriver():draw2DRectangle( Color , 
					irr.core.rect(r.UpperLeftCorner.X  + 1, r.UpperLeftCorner.Y  + 1, 
		            			  r.LowerRightCorner.X - 1, r.LowerRightCorner.Y - 1), nil)

	
	if string.len(self.Text) > 0 then
		-- draw text
		self.Environment:getSkin():getFont():draw(self.Text,
					irr.core.rect(rect.UpperLeftCorner.X  + 1, rect.UpperLeftCorner.Y  + 1, 
		            	rect.LowerRightCorner.X + 1, rect.LowerRightCorner.Y + 1), irr.video.SColor(225, 0, 0, 0), true, true)

	    -- give text a drop shadow
		self.Environment:getSkin():getFont():draw(self.Text, rect, irr.video.SColor(255, 255, 255, 255), true, true)
	end
	
	if self.Tooltip and self.MouseOver then
		self.TooltipFontSize = self.TooltipFontSize or 6
		local toolrect  = irr.core.rect(rect.UpperLeftCorner.X + 20, rect.UpperLeftCorner.Y + 5, rect.UpperLeftCorner.X + 20 + self.TooltipFontSize*string.len(self.Tooltip), rect.UpperLeftCorner.Y + 5 + 16)
		
		self.Environment:getVideoDriver():draw2DRectangle( irr.video.SColor(128,0,0,0), 
					irr.core.rect(toolrect.UpperLeftCorner.X  + 5, toolrect.UpperLeftCorner.Y  + 5, 
		            			  toolrect.LowerRightCorner.X + 5, toolrect.LowerRightCorner.Y + 5), nil)
		
		self.Environment:getVideoDriver():draw2DRectangle(irr.video.SColor(255,0,0,0), toolrect, nil)

		self.Environment:getVideoDriver():draw2DRectangle( irr.video.SColor(255,255,255,225), 
					irr.core.rect(toolrect.UpperLeftCorner.X  + 1, toolrect.UpperLeftCorner.Y  + 1, 
		            			  toolrect.LowerRightCorner.X - 1, toolrect.LowerRightCorner.Y - 1), nil)

		self.TooltipFont = self.TooltipFont or self.Environment:getSkin():getFont()			
		self.TooltipFont:draw(self.Tooltip, toolrect, irr.video.SColor(255, 0, 0, 0), true, true)
	end

	
	if self.ProgressBar and self.MouseDown then
		
		-- reset progress on click
		self.ProgressBar.Value = 0
	end

	if self.OnClick and self.MouseDown then
		self.ProgressBar.Tooltip = "Working..."
		self.ClickThread = self.OnClick
	end	
end

function CGUIButtonEx:OnEvent(Event)

	if Event.EventType == irr.EET_MOUSE_INPUT_EVENT then
		return self:OnMouseInputEvent(Event.MouseInput.X, Event.MouseInput.Y, Event.MouseInput.Wheel, Event.MouseInput.Event)
	end

	if Event.EventType == irr.EET_GUI_EVENT then
		return self:OnGuiEvent(Event.GUIEvent.EventType, Event.GUIEvent.Caller)	
	end		

	return false
end

function CGUIButtonEx:OnMouseInputEvent(X, Y, Wheel, Event)
	if Event == irr.EMIE_LMOUSE_PRESSED_DOWN then
		self.MouseDown = true
		return true
	end	

	if Event == irr.EMIE_LMOUSE_LEFT_UP then
		self.MouseDown = false
		return true
	end	
	
	return false
end

function CGUIButtonEx:OnGuiEvent(Event, Caller)
	if Event == irr.gui.EGET_ELEMENT_HOVERED then
		self.MouseOver = true
		return true
	end
	
	if Event == irr.gui.EGET_ELEMENT_LEFT then
		self.MouseOver = false
		return true
	end
	
	return false
end

-- create custom GUI element
CGUIButtonEx2 = {}


-- implement draw routine
function CGUIButtonEx2:draw()
	if self.Node then
		self.Node:render()
	end
end

function CGUIButtonEx2:setPos(pos) 

	local viewport = self.Node.SceneManager:getVideoDriver():getViewPort()

	local X = 2 * (pos.X - viewport.UpperLeftCorner.X) / viewport.LowerRightCorner.X - 1
	local Y = 2 * (pos.Y - viewport.UpperLeftCorner.Y) / viewport.LowerRightCorner.Y - 1
	local Z = 0

	local v = irr.core.vector3d(X,-Y,Z)
	self.Node:setPosition(v)
end

function CGUIButtonEx2:hit(pos)
	local spritePosition = self.Node:getPos()
	local size = self.Node:getSize()
	local X = pos.X
	local Y = pos.Y

	if X > spritePosition.X and X < spritePosition.X + size.Width and 
	 Y > spritePosition.Y and Y < spritePosition.Y + size.Height then 
		return true
	end
		
	return false
end

function CGUIButtonEx2:setScaleToRect(rect)

	local Width = rect:getWidth()
	local Height = rect:getHeight()

	local v = irr.core.vector3d(Width/self.Node.frmWidth, Height/self.Node.frmHeight, 0)
	self.Node:setScale(v)

end



CGUIProgressBar = 
{
    MaxValue = 100,
    MinValue = 0,
    Value = 0
}

function CGUIProgressBar:draw()

	local rect = self:getAbsolutePosition()

	local a = 0
	local Color = irr.video.SColor(255,175,175,175)
	local ValueColor = irr.video.SColor(255,0,0,255)
	local Outline = irr.video.SColor(255,0,0,0)
	
	if self.MouseDown then 
		a = 2 
		Color = irr.video.SColor(255,125,125,125)
	end
		
	local r = irr.core.rect(rect.UpperLeftCorner.X + a, rect.UpperLeftCorner.Y + a, 
							   rect.LowerRightCorner.X - a, rect.LowerRightCorner.Y - a)


	-- draw drop shadow
	self.Environment:getVideoDriver():draw2DRectangle( irr.video.SColor(128,0,0,0) , 
					irr.core.rect(rect.UpperLeftCorner.X  + 5, rect.UpperLeftCorner.Y  + 5, 
		            			  rect.LowerRightCorner.X + 5, rect.LowerRightCorner.Y + 5), nil)
	

	-- draw black outline
	self.Environment:getVideoDriver():draw2DRectangle(Outline, r, nil)
	
	
	-- draw rect background
	self.Environment:getVideoDriver():draw2DRectangle( Color , 
					irr.core.rect(r.UpperLeftCorner.X  + 1, r.UpperLeftCorner.Y  + 1, 
		            			  r.LowerRightCorner.X - 1, r.LowerRightCorner.Y - 1), nil)


	if self.Value > 0 then
		self.Text = string.format("%2d", self.Value/self.MaxValue * 100) .. "%"
		
		-- draw progress bar
		local Percent = self.Value/self.MaxValue
		local Width = (rect.LowerRightCorner.X - 3) - (rect.UpperLeftCorner.X + 3)
		self.Environment:getVideoDriver():draw2DRectangle( ValueColor , 
						irr.core.rect(rect.UpperLeftCorner.X  + 3, rect.UpperLeftCorner.Y  + 3, 
		            				(rect.UpperLeftCorner.X + 3) + Percent*Width,rect.LowerRightCorner.Y - 3), nil)
	end


	if string.len(self.Text) > 0 then
	    -- give text a black drop shadow
		self.Environment:getSkin():getFont():draw(self.Text,
					irr.core.rect(rect.UpperLeftCorner.X  + 1, rect.UpperLeftCorner.Y  + 1, 
		            	rect.LowerRightCorner.X + 1, rect.LowerRightCorner.Y + 1), irr.video.SColor(225, 0, 0, 0), true, true)

		-- draw text
		self.Environment:getSkin():getFont():draw(self.Text,rect, irr.video.SColor(225, 255, 255, 255), true, true)
	end
	
	if self.Tooltip and self.MouseOver then
		self.TooltipFontSize = self.TooltipFontSize or 6
		local toolrect  = irr.core.rect(rect.UpperLeftCorner.X + 20, rect.UpperLeftCorner.Y + 5, rect.UpperLeftCorner.X + 20 + self.TooltipFontSize*string.len(self.Tooltip), rect.UpperLeftCorner.Y + 5 + 16)
		
		self.Environment:getVideoDriver():draw2DRectangle( irr.video.SColor(128,0,0,0), 
					irr.core.rect(toolrect.UpperLeftCorner.X  + 5, toolrect.UpperLeftCorner.Y  + 5, 
		            			  toolrect.LowerRightCorner.X + 5, toolrect.LowerRightCorner.Y + 5), nil)
		
		self.Environment:getVideoDriver():draw2DRectangle(irr.video.SColor(255,0,0,0), toolrect, nil)

		self.Environment:getVideoDriver():draw2DRectangle( irr.video.SColor(255,255,255,225), 
					irr.core.rect(toolrect.UpperLeftCorner.X  + 1, toolrect.UpperLeftCorner.Y  + 1, 
		            			  toolrect.LowerRightCorner.X - 1, toolrect.LowerRightCorner.Y - 1), nil)

		self.TooltipFont = self.TooltipFont or self.Environment:getSkin():getFont()			
		self.TooltipFont:draw(self.Tooltip, toolrect, irr.video.SColor(255, 0, 0, 0), true, true)
	end
end

function CGUIProgressBar:OnEvent(Event)

	if Event.EventType == irr.EET_GUI_EVENT then
		return self:OnGuiEvent(Event.GUIEvent.EventType, Event.GUIEvent.Caller)	
	end		

	return false
end


function CGUIProgressBar:OnGuiEvent(Event, Caller)
	if Event == irr.gui.EGET_ELEMENT_HOVERED then
		self.MouseOver = true
		return true
	end
	
	if Event == irr.gui.EGET_ELEMENT_LEFT then
		self.MouseOver = false
		return true
	end
	
	return false
end



cnt = 0
MyEventReceiver = {}

function MyEventReceiver:OnEvent(Event)
	if Event.EventType == irr.EET_GUI_EVENT then
		return self:OnGuiEvent(Event.GUIEvent.EventType, Event.GUIEvent.Caller)
	end
	return false
end


function MyEventReceiver:OnGuiEvent(Event, Caller)

	local id = Caller:getID()
	local env = device:getGUIEnvironment()

	--[[
	If a scrollbar changed its scroll position, and it is 'our'
	scrollbar (the one with id 104), then we change the 
	transparency of all gui elements. This is a very easy task:
	There is a skin object, in which all color settings are stored.
	We simply go through all colors stored in the skin and change
	their alpha value.
	--]]
	

	if Event == irr.gui.EGET_SCROLL_BAR_CHANGED and id == 104 then
		local ScrollBar = tolua.cast(Caller, "irr::gui::IGUIScrollBar")
		local pos = ScrollBar:getPos()
		for i=0,irr.gui.EGDC_COUNT-1 do
			col = env:getSkin():getColor(i)
			col:setAlpha(pos)
			env:getSkin():setColor(i, col)
		end
		return false
	end

	--[[
	If a button was clicked, it could be one of 'our'
	three buttons. If it is the first, we shut down the engine.
	If it is the second, we create a little window with some 
	text on it. We also add a string to the list box to log
	what happened. And if it is the third button, we create
	a file open dialog, and add also this as string to the list box.
	That's all for the event receiver.
	]]--

	if Event == irr.gui.EGET_BUTTON_CLICKED then

		if id == 101 then
			device:closeDevice()
			return true

		elseif id == 102 then
			listbox:addItem("Window created")
			cnt = cnt + 30

			if cnt > 200 then
				cnt = 0
			end
			
			local window = env:addWindow(
							irr.core.rect(100+cnt, 100+cnt, 300+cnt, 200+cnt), 
							false, 
							"Test Window")
			env:addStaticText("Please close me", irr.core.rect(35, 35, 140, 50), true, false, window)
			return true

		elseif id == 103 then
			listbox:addItem("File open")
			env:addFileOpenDialog("Please choose a file.")
			return true
		end
	end

	return false
end

--[[
Ok, now for the more interesting part. First, create the 
Irrlicht device. As in some examples before, we ask the user which
driver he wants to use for this example:
]]--

function main()
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
	

	--[[ 
	If we want events to be passed to scripts, we must pass in "true"
	as the 6th parameter to createDevice.  This tells IrrLua we want
	the IrrLua default script event handlers installed.   If you 
	implement your own event handler in c++, you can set the 6th 
	parameter to false and then set the 7th to your c++ object.

	create device and exit if creation failed
	note device is created global so event handlers can see it
	--]]
	
	local receiver = irr.createIEventReceiver(MyEventReceiver)

	device = irr.createDevice(type, irr.core.dimension2d(640, 480) , 16, false, false, false, receiver)
	
	if device == nil then
		print("Error creating device")
		return 1
		end

	device:setWindowCaption("Irrlicht Engine - User Inferface Demo")

	local driver = device:getVideoDriver()
	local env = device:getGUIEnvironment()

	--[[
	We add three buttons. The first one closes the engine. The second
	creates a window and the third opens a file open dialog. The third
	parameter is the id of the button, with which we can easily identify
	the button in the event receiver.
	--]]	

	env:addButton(irr.core.rect(10,210,100,240), nil, 101, "Quit")
	local button1 = env:addButton(irr.core.rect(10,250,100,290), nil, 102, "New Window")
	env:addButton(irr.core.rect(10,300,100,340), nil, 103, "File Open")

	--[[
	Now, we add a static text and a scrollbar, which modifies the
	transparency of all gui elements. We set the maximum value of
	the scrollbar to 255, because that's the maximal value for 
	a color value.
	Then we create an other static text and a list box.
	--]]

	env:addStaticText("Transparent Control:", irr.core.rect(150,20,350,40), true)
	local scrollbar = env:addScrollBar(true, irr.core.rect(150,45,350,60), nil, 104)
	scrollbar:setMax(255)


	env:addStaticText("Logging ListBox:", irr.core.rect(50,80,250,100), true)
	-- note listbox is global so event handler can see it
	listbox = env:addListBox(irr.core.rect(50, 110, 250, 180))


	--[[
	To make the font a little bit nicer, we load an external font
	and set it as new font in the skin. An at last, we create a 
	nice Irrlicht Engine logo in the top left corner.
	--]]

	local skin = env:getSkin()
	skin = irr.gui.createAnimatedSpriteSkin(driver, device:getSceneManager(), device:getTimer())
	loadSkin(skin, 0)

	env:setSkin(skin)

	local font = env:getFont(installPath .. "media/fonthaettenschweiler.bmp")

	if font ~= nil then 
		skin:setFont(font)
	end

	--[[
	create custom button
	--]]
		
	local Button = irr.gui.createIGUIElement(irr.gui.EGUIET_ELEMENT, env, nil, 123, irr.core.rect(), CGUIButtonEx)

	Button.Visible = true
	Button.Text = "New Element"
	
	Button:setRelativePosition(irr.core.rect(30,30,8*math.max(string.len(Button.Text),3) + 10,50))
	Button.Tooltip = "This is a new GUI element written in lua"
	-- Button.TooltipFont = env:getFont(installPath .. "media/fontcourier.bmp")
	-- Button.TooltipFontSize = 9
		
	env:getRootGUIElement():addChild(Button)


	
	local Button2 = irr.gui.createIGUIElement(irr.gui.EGUIET_ELEMENT, env, nil, 124, irr.core.rect(), CGUIButtonEx)

	Button2.Visible = true
	Button2.Node = device:getSceneManager():addCubeSceneNode(1, nil, 1234, irr.core.vector3d(0,0,0), irr.core.vector3d(0,0,0), irr.core.vector3d(1,1,1))
	Button2.Node.SceneManager = device:getSceneManager()
	Button2.Node.frmHeight = 480
	Button2.Node.frmWidth = 640
	
	anim = device:getSceneManager():createRotationAnimator(irr.core.vector3d(0.8, 0, 0.8))

	Button2.Node:addAnimator(anim)
	anim:drop()

	
	CGUIButtonEx2.setPos(Button2,irr.core.position2d(300,400))
	CGUIButtonEx2.setScaleToRect(Button2, irr.core.rect(0,0,30,30))

	env:getRootGUIElement():addChild(Button2)
	


	--[[
	create custom progress bar globally so coroutine can see it
	--]]
	
	
	local ProgressBar = irr.gui.createIGUIElement(irr.gui.EGUIET_ELEMENT, env, nil, 125, irr.core.rect(), CGUIProgressBar)
	ProgressBar.Visible = true
	ProgressBar:setRelativePosition(irr.core.rect(120,320,420,340))
	
	-- setup button to make progress bar move onclick
	Button.ProgressBar = ProgressBar	
	Button.OnClick = coroutine.create(				
			function(self)
					while true do 
						if self.ProgressBar.Value < self.ProgressBar.MaxValue then 
							self.ProgressBar.Value = self.ProgressBar.Value + 1 
						else
							self.ClickThread = nil
							self.ProgressBar.Value = 0
							self.ProgressBar.Tooltip = nil
							self.ProgressBar.Text = nil
						end
						coroutine.yield()
					end
				end
				)								


	env:getRootGUIElement():addChild(ProgressBar)
		
	
	
	--[[
	That's all, we only have to draw everything.
	--]]

	while device:run() and driver ~= nil do
		if device:isWindowActive() then
			driver:beginScene(true, true, irr.video.SColor(0,200,200,200))
			env:drawAll()
			driver:endScene()
			
			-- run coroutines
			if Button.ClickThread then coroutine.resume(Button.ClickThread, Button) end	
		end
	end

	device:drop()
	device = nil
	return 0
end

main()


