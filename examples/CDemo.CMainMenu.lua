-- This is a Demo of the Irrlicht Engine (c) 2005 by N.Gebhardt.
-- This file is not documentated.
-- ported to lua (c) 2005 by Josh Turpen 

CMainMenu = {

	startButton 	= 0,
	device 			= 0,
	selected 		= 2,
	StartUp			= false,
	fullscreen 		= true,
	music 			= true,
	shadows 		= false,
	additive 		= false,
	transparent 	= true,
	vsync 			= true,
	installPath 	= "../../../"
}

function CMainMenu:new()
	local t = {}
	t = self
	return t
end

function CMainMenu:run()

	self.device = irr.createDevice(irr.video.EDT_SOFTWARE,
		irr.core.dimension2d(512, 384), 16, false, false, false)


	self.device:getFileSystem():addZipFileArchive("irrlicht.dat")
	self.device:getFileSystem():addZipFileArchive(self.installPath .. "media/irrlicht.dat")

	local driver = self.device:getVideoDriver()
	local smgr = self.device:getSceneManager()
	local guienv = self.device:getGUIEnvironment()

	self.device:setWindowCaption("Irrlicht Engine Demo (IrrLua) v" .. self.device:getVersion())

	-- load font

	local ii = 1

	local font = guienv:getFont(self.installPath .. "media/fonthaettenschweiler.bmp")
	if font then
		guienv:getSkin():setFont(font)
	end

	-- add images

	local img = guienv:addImage(irr.core.rect(0,0,512,384))
	img:setImage(driver:getTexture(self.installPath .. "media/demoback.bmp"))

    local leftX = 260

	-- add tab control
	local tabctrl = guienv:addTabControl(irr.core.rect(leftX,10,512-10,384-10))
	local optTab = tabctrl:addTab("Demo")
	local aboutTab = tabctrl:addTab("About")

	-- add list box

	local box = guienv:addListBox(irr.core.rect(10,10,220,75), optTab, 1)
	box:addItem("OpenGL 1.2")
	box:addItem("Direct3D 8.1")
	box:addItem("Direct3D 9.0b")	
	box:addItem("Apfelbaum Software Renderer 1.0")
	box:addItem("Irrlicht Software Renderer 1.0")
	box:setSelected(self.selected)

	-- add button

	self.startButton = guienv:addButton(irr.core.rect(30,295,200,324), optTab, 2, "Start Demo")

	-- add checkbox

	guienv:addCheckBox(self.fullscreen, irr.core.rect(20,85,130,110), 
		optTab, 3, "Fullscreen")
	guienv:addCheckBox(self.music, irr.core.rect(20,110,130,135), 
		optTab, 4, "Music & Sfx")
	guienv:addCheckBox(self.shadows, irr.core.rect(20,135,230,160), 
		optTab, 5, "Realtime shadows")
	guienv:addCheckBox(self.additive, irr.core.rect(20,160,230,185),
		optTab, 6, "Old HW compatible blending")
	guienv:addCheckBox(self.vsync, irr.core.rect(20,185,230,210),
		optTab, 7, "Vertical synchronisation")

	-- add text

	local text = "Welcome to the Irrlicht Engine. Please select " ..
		"the settings you prefer and press 'Start Demo'. " ..
		"Right click for changing menu style."

	guienv:addStaticText(text, irr.core.rect(10, 220, 220, 280),
		true, true, optTab)

	-- add about text

	local text2 = "This is the tech demo of the IrrLua binding to the Irrlicht engine. To start, " ..
		"select a device which works best with your hardware and press 'start demo'. " ..
		"What you currently see is displayed using the Software Renderer, but this would be too slow " ..
		"for the demo. The Irrlicht Engine was written by, Nikolaus Gebhardt. The models, " ..
		"maps and textures were placed at my disposal by B.Collins, M.Cook and J.Marton. The music was created by " ..
		"M.Rohde and is played back by Audiere.\n" ..
		"The Lua language binding for Irrlicht was written by Josh Turpen.\n" ..
		"For more informations, please visit the homepage of the Irrlicht engine:\nhttp://www.irrlicht.sourceforge.net"

	guienv:addStaticText(text2, irr.core.rect(20, 20, 220, 300),
		true, true, aboutTab)
	
	-- add md2 model

	local mesh = smgr:getMesh(self.installPath .. "media/faerie.md2")
	local node = smgr:addAnimatedMeshSceneNode(mesh)
	if node then
		node:setMaterialTexture(0, driver:getTexture(self.installPath .. "media/faerie2.bmp"))
		node:setMaterialFlag(irr.video.EMF_LIGHTING, false)
		node:setFrameLoop(0, 310)
	end

	smgr:addCameraSceneNode(nil, irr.core.vector3d(45,0,0), irr.core.vector3d(0,0,20))

	-- irrlicht logo
	local irrlichtLogo = driver:getTexture(self.installPath .. "media/irrlichtlogo.bmp")

	-- set transparency
	self:setTransparency()

	-- wait till everything is created before setting the event receiver
	self.receiver = irr.createIEventReceiver(self)

	--[[ 
	receiver is a 'deep copy' of self, so in order for the receiver 
	to access the real variables you must also have an 'owner' field 
	to access the clone's variables

	This is required for a few reasons, mostly because we are trying
	to do multiple inheritence and not following the 'init()' methodology

	See 03.CustomSceneNode.lua and CAnimSprite.lua for the 'normal' way
	of using the 'create*' functions for virtual classes.  Normally you
	do not need to use the 'owner' trick
	--]]
	self.receiver.owner = self 
	self.device:setEventReceiver(self.receiver)

	-- draw all
	while self.device:run() do
	
		if self.device:isWindowActive() then
			driver:beginScene(false, true, irr.video.SColor(0,0,0,0))
			guienv:drawAll()
			smgr:drawAll()

			if irrlichtLogo then
				driver:draw2DImage(irrlichtLogo, irr.core.position2d(10,10))
			end

		driver:endScene()
		end
	end

	self.device:drop()

	local drivers = {irr.video.EDT_OPENGL, irr.video.EDT_DIRECT3D8, irr.video.EDT_DIRECT3D9, irr.video.EDT_SOFTWARE2, irr.video.EDT_SOFTWARE}
	outDriver = drivers[self.selected+1]

	return self.StartUp, self.fullscreen, self.music, self.shadows, self.additive, self.vsync, outDriver
end

function CMainMenu:OnEvent(Event)
	if Event.EventType == irr.EET_GUI_EVENT then
		return self:OnGuiEvent(Event.GUIEvent.EventType, Event.GUIEvent.Caller)
	elseif Event.EventType == irr.EET_GUI_EVENT then
		return self:OnMouseInputEvent(Event.MouseInput.X, Event.MouseInput.Y, Event.MouseInput.Wheel, Event.MouseInput.Event)
	end
	return false
end


function CMainMenu:OnMouseInputEvent(X, Y, Wheel, Event)
	if Event == EMIE_RMOUSE_LEFT_UP then
		local r = irr.core.rect(X, Y, 0, 0)
		local menu = self.owner.device:getGUIEnvironment():addContextMenu(r, 0, 45)
		menu:addItem("transparent menus", 666, transparent == false)
		menu:addItem("solid menus", 666, transparent == true)
		menu:addSeperator()
		menu:addItem("Cancel")
	end
end

function CMainMenu:OnGuiEvent(Event, Caller)
	local id = Caller:getID()

	if id == 45 then
		if Event == irr.gui.EGET_MENU_ITEM_SELECTED then	
			local contextMenu = tolua.cast(Caller, "irr::gui:IGUIContextMenu")
			local s = contextMenu:getSelectedItem()
			if s == 0 or s == 1 then
				self.owner.transparent = not self.owner.transparent
				self.owner:setTransparency()
			end
		end

	elseif id == 1 then

		if Event ==  irr.gui.EGET_LISTBOX_CHANGED then
			local listBox = tolua.cast(Caller, "irr::gui::IGUIListBox")
			self.owner.selected = listBox:getSelected()
			self.owner.startButton:setEnabled(self.owner.selected ~= nil)
		end

	elseif id == 2 then
		if Event == irr.gui.EGET_BUTTON_CLICKED then
			self.owner.StartUp = true
			self.owner.device:closeDevice()
		end

	elseif id == 3 then

		if Event == irr.gui.EGET_CHECKBOX_CHANGED then
			local checkBox = tolua.cast(Caller, "irr::gui::IGUICheckBox")
			self.owner.fullscreen = checkBox:isChecked()
		end

	elseif id == 4 then

		if Event == irr.gui.EGET_CHECKBOX_CHANGED then
			local checkBox = tolua.cast(Caller, "irr::gui::IGUICheckBox")
			self.owner.music = checkBox:isChecked()
		end

	elseif id == 5 then

		if Event == irr.gui.EGET_CHECKBOX_CHANGED then
			local checkBox = tolua.cast(Caller, "irr::gui::IGUICheckBox")
			self.owner.shadows = checkBox:isChecked()
		end

	elseif id == 6 then

		if Event == irr.gui.EGET_CHECKBOX_CHANGED then
			local checkBox = tolua.cast(Caller, "irr::gui::IGUICheckBox")
			self.owner.additive = checkBox:isChecked()
		end

	elseif id == 7 then

		if Event == irr.gui.EGET_CHECKBOX_CHANGED then
			local checkBox = tolua.cast(Caller, "irr::gui::IGUICheckBox")
			self.owner.vsync = checkBox:isChecked()
		end
	else

	end

	return false
end

function CMainMenu:setTransparency()

	for i=0,irr.gui.EGDC_COUNT-1 do
		local col = self.device:getGUIEnvironment():getSkin():getColor(i)

		local alpha = 255
		if self.transparent then alpha = 201 end

		col:setAlpha(alpha)
		self.device:getGUIEnvironment():getSkin():setColor(i, col)
	end
end


