require "IrrLua"

--[[
 This tutorial show how to create a more complex application with the engine. We construct
 a simple mesh viewer using the user interface API and the scenemanagement of Irrlicht.
 The tutorial show how to create and use Buttons, Windows, Toolbars, Menus, ComboBoxes,
 Tabcontrols, Editboxes, Images, MessageBoxes, SkyBoxes, and how to parse XML files
 with the integrated XML reader of the engine.

 We start like in most other tutorials: Include all nesessary header files, add a
 comment to let the engine be linked with the right .lib file in Visual Studio,
 and deklare some global variables. We also add two 'using namespece' statements, so
 we do not need to write the whole names of all classes. In this tutorial, we use a
 lot stuff from the gui namespace.
--]]


-- Globals
Device = nil
StartUpModelFile = ""
MessageText = ""
Caption = ""
Model = nil
SkyBox = nil

--[[
The three following functions do several stuff used by the mesh viewer. 
The first function showAboutText() simply displays a messagebox with a caption
and a message text. The texts will be stored in the MessageText and 
Caption variables at startup.
--]]

function showAboutText()
	-- create modal message box with the text
	-- loaded from the xml file.
	Device:getGUIEnvironment():addMessageBox(Caption, MessageText)
end

--[[
The second function loadModel() loads a model and displays it using an
addAnimatedMeshSceneNode and the scene manager. Nothing difficult. It also
displays a short message box, if the model could not be loaded.
--]]

function loadModel(fn)
	-- modify the name if it a .pk3 file

	local filename = fn
	local found = string.sub(filename, -4, -1) == ".pk3"
	if found then
		Device:getFileSystem():addZipFileArchive(filename)
		-- strcpy(found +1, "bsp");
	end

	-- load a model into the engine

	if Model ~= nil then
		Model:remove()
	end

	Model = nil

	local m = Device:getSceneManager():getMesh(filename)

	if m == nil then
		-- model could not be loaded

		if StartUpModelFile ~= filename then
			Device:getGUIEnvironment():addMessageBox(
			Caption, "The model could not be loaded. " ..
			"Maybe it is not a supported file format.")
			return
		end	
	end

	-- set default material properties

	Model = Device:getSceneManager():addAnimatedMeshSceneNode(m)

	if Model ~= nil then
		if not found then
			Model:setMaterialType(irr.video.EMT_TRANSPARENT_ADD_COLOR)
		end
		Model:setMaterialFlag(irr.video.EMF_LIGHTING, false)
		Model:setDebugDataVisible(true)
		Model:setAnimationSpeed(20)
	end
end

--[[
Finally, the third function creates a toolbox window. In this simple mesh viewer,
this toolbox only contains a tab control with three edit boxes for changing
the scale of the displayed model.
--]]

function createToolBox()
	-- remove tool box if already there
	local env = Device:getGUIEnvironment()
	local root = env:getRootGUIElement()
	local e = root:getElementFromId(5000, true)
	if e ~= nil then e:remove() end

	-- create the toolbox window
	local wnd = env:addWindow(irr.core.rect(450,25,640,480),
		false, "Toolset", nil, 5000)

	-- create tab control and tabs
	local tab = env:addTabControl(
		irr.core.rect(2,20,640-452,480-7), wnd, true, true)

	local t1 = tab:addTab("Scale")
	local t2 = tab:addTab("Empty Tab")

	-- add some edit boxes and a button to tab one
	env:addEditBox("1.0", irr.core.rect(40,50,130,70), true, t1, 901)
	env:addEditBox("1.0", irr.core.rect(40,80,130,100), true, t1, 902)
	env:addEditBox("1.0", irr.core.rect(40,110,130,130), true, t1, 903)

	env:addButton(irr.core.rect(10,150,100,190), t1, 1101, "set")

	-- add senseless checkbox
	env:addCheckBox(true, irr.core.rect(10,220,200,240), t1, -1, "Senseless Checkbox")

	-- add undocumentated transparent control
	env:addStaticText("Transparent Control:", irr.core.rect(10,240,150,260), true, false, t1)
	local scrollbar = env:addScrollBar(true, irr.core.rect(10,260,150,275), t1, 104)
	scrollbar:setMax(255)

	-- bring irrlicht engine logo to front, because it
	-- now may be below the newly created toolbox
	root:bringToFront(root:getElementFromId(666, true))
end


--[[
To get all the events sent by the GUI Elements, we need to create an event
receiver. This one is really simple. If an event occurs, it checks the id
of the caller and the event type, and starts an action based on these values.
For example, if a menu item with id 100 was selected, if opens a file-open-dialog.
--]]

MyEventReceiver = {}

function MyEventReceiver:OnEvent(Event)
	if Event.EventType == irr.EET_GUI_EVENT then
		return self:OnGuiEvent(Event.GUIEvent.EventType, Event.GUIEvent.Caller)
	end
	return false
end

function MyEventReceiver:OnGuiEvent(Event, Caller)
	local id = Caller:getID()
	local env = Device:getGUIEnvironment()

	if Event == irr.gui.EGET_MENU_ITEM_SELECTED then
		-- a menu item was clicked

		local menu = tolua.cast(Caller, "irr::gui::IGUIContextMenu")
		local id = menu:getItemCommandId(menu:getSelectedItem())
	
		if id == 100 then
			-- File -> Open Model
			env:addFileOpenDialog("Please select a model file to open")

		elseif id == 200 then
			-- File -> Quit
			Device:closeDevice()

		elseif id == 300 then
			-- View -> Skybox
			SkyBox:setVisible( not SkyBox:isVisible())

		elseif id == 400 then
			-- View -> Debug Information
			if Model ~= nil then
				Model:setDebugDataVisible(not Model:isDebugDataVisible())
			end

		elseif id == 500 then
			-- Help->About
			showAboutText()

		elseif id == 610 then
			-- View -> Material -> Solid
			if Model ~= nil then
				Model:setMaterialType(irr.video.EMT_SOLID)
			end

		elseif id == 620 then
			-- View -> Material -> Transparent
			if Model ~= nil then 
				Model:setMaterialType(irr.video.EMT_TRANSPARENT_ADD_COLOR)
			end

		elseif id == 630 then
			-- View -> Material -> Reflection
			if Model ~= nil then 
				Model:setMaterialType(irr.video.EMT_SPHERE_MAP)
				end
			end
		end
	
	if Event == irr.gui.EGET_FILE_SELECTED then
		-- load the model file, selected in the file open dialog
		local dialog = tolua.cast(Caller, "irr::gui::IGUIFileOpenDialog")
		loadModel(dialog:getFilename())
	end
	
	if Event == irr.gui.EGET_SCROLL_BAR_CHANGED then
		-- control skin transparency 
		if id == 104 then
			local scrollbar = tolua.cast(Caller, "irr::gui::IGUIScrollBar")
			local pos = scrollbar:getPos()
			for i=0,irr.gui.EGDC_COUNT-1 do
				local col = env:getSkin():getColor(i)
				col:setAlpha(pos)
				env:getSkin():setColor(i, col)
			end
		end
	end

	if Event == irr.gui.EGET_BUTTON_CLICKED then
		if id == 1101 then
			-- set scale
			local root = env:getRootGUIElement()
			local scale = irr.core.vector3d(0,0,0)
			
			-- dealing with inheritance in lua can be tricky
			-- here we cannot call IGUIElement:getText(), we must get the derived class's getText()
			scale.X = tolua.cast(root:getElementFromId(901, true), "irr::gui::IGUIEditBox" ):getText()
			scale.Y = tolua.cast(root:getElementFromId(902, true), "irr::gui::IGUIEditBox" ):getText()
			scale.Z = tolua.cast(root:getElementFromId(903, true), "irr::gui::IGUIEditBox" ):getText()

			if Model ~= nil then
				Model:setScale(scale)
			end
		elseif id == 1102 then
			env:addFileOpenDialog("Please select a model file to open")

		elseif id == 1103 then
			showAboutText()

		elseif id == 1104 then
			createToolBox()
		end
	end

	return false
end


--[[
Most of the hard work is done. We only need to create the Irrlicht Engine device
and all the buttons, menus and toolbars. 
We start up the engine as usual, using createDevice(). To make our application
catch events, we set our eventreceiver as parameter. The #ifdef WIN32 preprocessor
commands are not necesarry, but I included them to make the tutorial use DirectX on
Windows and OpenGL on all other platforms like Linux. 
As you can see, there is also a unusual call to IrrlichtDevice::setResizeAble(). 
This makes the render window resizeable, which is quite useful for a mesh viewer.
--]]

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
	create device and exit if creation failed
	note device is created global so event handlers can see it
	--]]
	local receiver = irr.createIEventReceiver(MyEventReceiver)

	Device = irr.createDevice(type, irr.core.dimension2d(640, 480) , 16, false, false, false, receiver)
	
	if Device == nil then
		print("Error creating device")
		return 1
	end


	Device:setResizeAble(true)
	Device:setWindowCaption("Irrlicht Engine - Loading...")

	local driver = Device:getVideoDriver()
	local env = Device:getGUIEnvironment()
	local smgr = Device:getSceneManager()

	driver:setTextureCreationFlag(irr.video.ETCF_ALWAYS_32_BIT, true)

	--[[
	The next step is to read the configuration file. It is stored in the xml 
	format and looks a little bit like this:

	<?xml version="1.0"?>
	<config>
		<startUpModel file="some filename" />
		<messageText caption="Irrlicht Engine Mesh Viewer">
			Hello!
		</messageText>
	</config>

	We need the data stored in there to be written into the global variables
	StartUpModelFile, MessageText and Caption. This is now done using the
	Irrlicht Engine integrated XML parser:
	--]]

	-- read configuration from xml file

	local xml = Device:getFileSystem():createXMLReader(installPath .. "media/config.xml")

	while ( xml~= nil and  xml:read()) do 
		local type = xml:getNodeType() 

		if type == irr.io.EXN_TEXT then
			-- in this xml file, the only text which occurs is the messageText
			MessageText = xml:getNodeData()
		end

		if type == irr.io.EXN_ELEMENT then
			if "startUpModel" == xml:getNodeName() then
				StartUpModelFile = string.sub(installPath,1,3) .. xml:getAttributeValue("file")
			end
			if "messageText" == xml:getNodeName() then
				Caption = xml:getAttributeValue("caption")
			end
		end
	end

	if xml ~= nil then
		xml:drop() -- don't forget to delete the xml reader 
	end

	--[[	
	That wasn't difficult. Now we'll set a nicer font and create the
	Menu. It is possible to create submenus for every menu item. The call
	menu->addItem(L"File", -1, true, true); for example adds a new menu
	Item with the name "File" and the id -1. The following parameter says
	that the menu item should be enabled, and the last one says, that
	there should be a submenu. The submenu can now be accessed with
	menu->getSubMenu(0), because the "File" entry is the menu item with
	index 0.
	--]]

	-- set a nicer font

	local skin = env:getSkin()
	local font = env:getFont(installPath .. "media/fonthaettenschweiler.bmp")
	if font ~= nil then
		skin:setFont(font)
	end

	-- create menu

	local menu = env:addMenu()
	menu:addItem("File", -1, true, true)
	menu:addItem("View", -1, true, true)
	menu:addItem("Help", -1, true, true)

	local submenu = menu:getSubMenu(0)
	submenu:addItem("Open Model File...", 100)
	submenu:addSeparator()
	submenu:addItem("Quit", 200)

	submenu = menu:getSubMenu(1)
	submenu:addItem("toggle sky box visibility", 300)
	submenu:addItem("toggle model debug information", 400)
	submenu:addItem("model material", -1, true, true )

	submenu = submenu:getSubMenu(2)
	submenu:addItem("Solid", 610)
	submenu:addItem("Transparent", 620)
	submenu:addItem("Reflection", 630)

	submenu = menu:getSubMenu(2)
	submenu:addItem("About", 500)

	--[[
	Below the toolbar, we want a toolbar, onto which we can place 
	colored buttons and important looking stuff like a senseless
	combobox.
	--]]

	-- create toolbar

	local bar = env:addToolBar()
	bar:addButton(1102, nil, driver:getTexture(installPath .. "media/open.bmp"))
	bar:addButton(1103, nil, driver:getTexture(installPath .. "media/help.bmp"))
	bar:addButton(1104, nil, driver:getTexture(installPath .. "media/tools.bmp"))

	-- create a combobox with some senseless texts

	local box = env:addComboBox(irr.core.rect(100,5,200,25), bar)
	box:addItem("Bilinear")
	box:addItem("Trilinear")
	box:addItem("Anisotropic")
	box:addItem("Isotropic")
	box:addItem("Psychedelic")
	box:addItem("No filtering")

	--[[
	To make the editor look a little bit better, we disable transparent
	gui elements, and add a Irrlicht Engine logo. In addition, a text,
	which will show the current frame per second value is created, and
	the window caption changed.
	--]]

	-- disable alpha

	for i=0,irr.gui.EGDC_COUNT-1 do
		col = env:getSkin():getColor(i)
		col:setAlpha(255)
		env:getSkin():setColor(i, col)
	end

	-- add a tabcontrol

	createToolBox()

	-- create fps text 

	local fpstext = env:addStaticText("", irr.core.rect(210,26,270,41), true)

	-- set window caption

	Caption = Caption .. " - [";
	Caption = Caption .. driver:getName()
	Caption = Caption .. "]"
	Device:setWindowCaption(Caption)

	--[[
	That's nearly the whole application. We simply show the about 
	message box at start up, and load the first model. To make everything
	look better, a skybox is created and a user controled camera,
	to make the application a little bit more interactive. Finally,
	everything is drawed in a standard drawing loop.
	--]]

	-- show about message box and load default model
	showAboutText()
	loadModel(StartUpModelFile)

	-- add skybox 

	SkyBox = smgr:addSkyBoxSceneNode(
		driver:getTexture(installPath .. "media/irrlicht2_up.jpg"),
		driver:getTexture(installPath .. "media/irrlicht2_dn.jpg"),
		driver:getTexture(installPath .. "media/irrlicht2_lf.jpg"),
		driver:getTexture(installPath .. "media/irrlicht2_rt.jpg"),
		driver:getTexture(installPath .. "media/irrlicht2_ft.jpg"),
		driver:getTexture(installPath .. "media/irrlicht2_bk.jpg"))

	-- add a camera scene node 

	smgr:addCameraSceneNodeMaya()

	-- load the irrlicht engine logo

	local irrLogo = 
		driver:getTexture(installPath .. "media/irrlichtlogoaligned.jpg")

	-- draw everything

	while(Device:run() and driver ~= nil) do
		if Device:isWindowActive() then
			driver:beginScene(true, true, irr.video.SColor(150,50,50,50))

			smgr:drawAll()
			env:drawAll()

			-- draw irrlicht engine logo
			driver:draw2DImage(irrLogo,
				irr.core.position2d(10, driver:getScreenSize().Height - 50),
				irr.core.rect(0,0,108-20,460-429))
		
			driver:endScene()

			local str = "FPS: "
			str = str .. driver:getFPS()
			fpstext:setText(str)
		end
	end

	Device:drop()
	return 0
end

main()


