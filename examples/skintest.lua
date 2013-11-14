
require "IrrLua"
require "CGUISkin"

--[[
This tutorial shows how to use the built in User Interface of
the Irrlicht Engine. It will give a brief overview and show
how to create and use windows, buttons, scroll bars, static 
texts and list boxes.
--]]



--[[
The event handlers are not only capable of getting keyboard and
mouse input events, but also events of the graphical user interface 
(gui). There are events for almost everything: Button click, 
Listbox selection change, events that say that a element was hovered
and so on. To be able to react to some of these events, we create 
an event handler. 
We only react to gui events, and if it's such an event, we get the
id of the caller (the gui element which caused the event) and get 
the pointer to the gui environment.
--]]

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
	env:addButton(irr.core.rect(10,250,100,290), nil, 102, "New Window")
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

	-- local skin = env:getSkin()
	local skin = irr.gui.createIGUISkin(CGUISkin)
	skin:init(driver)
	env:setSkin(skin)

	local font = env:getFont(installPath .. "media/fonthaettenschweiler.bmp")

	if font ~= nil then 
		skin:setFont(font)
	end

	local img = env:addImage(driver:getTexture(installPath .. "media/irrlichtlogoalpha.tga") ,  irr.core.position2d(10,10))

	--[[
	That's all, we only have to draw everything.
	--]]

	while device:run() and driver ~= nil do
		if device:isWindowActive() then
			driver:beginScene(true, true, irr.video.SColor(0,200,200,200))
			env:drawAll()
			driver:endScene()
		end
	end

	device:drop()
	device = nil
	return 0
end

main()

