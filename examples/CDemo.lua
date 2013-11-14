-- This is a Demo of the Irrlicht Engine (c) 2005 by N.Gebhardt.
-- straight port to lua by Josh Turpen
-- This file is not documentated.

require "IrrLua"
dofile("CDemo.CMainMenu.lua")

CDemo = {

	fullscreen 	= false,
	music 		= false,
	shadows 	= false,
	additive 	= false,
	vsync 		= false,
	driverType 	= irr.gui.EDT_SOFTWARE,

	device 			= 0,

	currentScene 	= -2,
	backColor = irr.video.SColor(0,0,0,0),

	statusText 		= 0,
	inOutFader 		= 0,

	quakeLevelMesh 	= 0,
	quakeLevelNode 	= 0,
	skyboxNode 		= 0,
	model1 			= 0,
	model2 			= 0,
	campFire 		= 0,

	metaSelector 	= 0,
	mapSelector 	= 0,

	sceneStartTime 	= 0,
	timeForThisScene= 0,
	installPath = "../../../",

	Impacts = {}
} 

function CDemo:new(fullscreen, music, shadows, additive, vsync, driverType)
	local t = {}
	t = self

	t.fullscreen = fullscreen or false
	t.music = music or false
	t.shadows = shadows or false
	t.additive = additive or false 
	t.vsync = vsync or false
	t.driverType = driverType or irr.gui.EDT_SOFTWARE2

	return t
end

-- allows us to do 'local foo = CDemo()' to create a new object


function CDemo:run()

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
	self.device = irr.createDevice(self.driverType,
		irr.core.dimension2d(640, 480), 16, self.fullscreen, self.shadows, self.vsync, self.receiver)

	self.device:getFileSystem():addZipFileArchive(self.installPath .. "irrlicht.dat")
	self.device:getFileSystem():addZipFileArchive(self.installPath .. "media/irrlicht.dat")
	self.device:getFileSystem():addZipFileArchive(self.installPath .. "map-20kdm2.pk3")
	self.device:getFileSystem():addZipFileArchive(self.installPath .. "media/map-20kdm2.pk3")

	local driver = self.device:getVideoDriver()
	local smgr = self.device:getSceneManager()
	local guienv = self.device:getGUIEnvironment()

	self.device:setWindowCaption("Irricht Engine Demo (IrrLua) ")

	while self.device:run() and driver do

		if self.device:isWindowActive() then
			-- load next scene if necessary
			local now = self.device:getTimer():getTime()
			if (now - self.sceneStartTime > self.timeForThisScene) and (self.timeForThisScene ~=-1) then
				self:switchToNextScene()
			end

			self:createParticleImpacts()

			-- draw everything
			driver:beginScene(true, true, self.backColor)
			smgr:drawAll()
			guienv:drawAll()
			driver:endScene()

			-- write statistics
			self.statusText:setText(driver:getName() .. " fps:" .. driver:getFPS())
		end
	end

	self.device:drop()
end

function CDemo:OnEvent(Event)
	if Event.EventType == irr.EET_KEY_INPUT_EVENT then
		return self:OnKeyEvent(Event.KeyInput.Key, Event.KeyInput.PressedDown, Event.KeyInput.Shift, Event.KeyInput.Control)
	elseif Event.EventType == irr.EET_MOUSE_INPUT_EVENT then
		return self:OnMouseInputEvent(Event.MouseInput.Event, Event.MouseInput.X, Event.MouseInput.Y, Event.MouseInput.Wheel)
	end
	return false
end

function CDemo:OnKeyEvent(Key, PressedDown, Shift, Control)
	
	if self.owner.device == nil then
		return false
	end

	if Key == irr.KEY_ESCAPE and PressedDown == false then
		if self.owner.currentScene < 3 then
			self.owner.timeForThisScene = 0
		else
			self.owner.device:closeDevice()
		end
	end

	if Key == irr.KEY_SPACE and PressedDown == false and self.owner.currentScene == 3 then
		self.owner:shoot()
	end
		
	return false
end

function CDemo:OnMouseInputEvent(Event, X, Y, Wheel)
	if Event == irr.EMIE_LMOUSE_LEFT_UP and self.owner.currentScene == 3 then
		self.owner:shoot()
	end
	return false
end


function CDemo:switchToNextScene()

	self.currentScene = self.currentScene + 1

	if self.currentScene > 3 then 
		self.currentScene = 1
	end


	local sm = self.device:getSceneManager()
	local sa = 0
	local camera = 0

	camera = sm:getActiveCamera()

	if camera then
		sm:setActiveCamera(nil)
		camera:remove()
	end

	if self.currentScene == -1 then
		-- loading screen
		self.timeForThisScene = 0
		self:createLoadingScreen()


	elseif self.currentScene == 0 then
		-- load scene
		self.timeForThisScene = 0
		self:loadSceneData()


	elseif self.currentScene == 1 then
		self.currentScene = self.currentScene + 1
		camera = sm:addCameraSceneNode(nil, irr.core.vector3d(0,0,0), irr.core.vector3d(-586, 708, 52))
		camera:setTarget(irr.core.vector3d(0,400,0))

		local points = {}

		-- alternatively you can just do points = {irr.core.vector3d(), irr.core.vector3d(), ... } 
		-- table.insert is used here to reflect the c++ program from which this app is ported

		table.insert(points, irr.core.vector3d(-931.473755, 138.300003, 987.279114)) -- -49873
		table.insert(points, irr.core.vector3d(-847.902222, 136.757553, 915.792725)) -- -50559
		table.insert(points, irr.core.vector3d(-748.680420, 152.254501, 826.418945)) -- -51964
		table.insert(points, irr.core.vector3d(-708.428406, 213.569580, 784.466675)) -- -53251
		table.insert(points, irr.core.vector3d(-686.217651, 288.141174, 762.965576)) -- -54015
		table.insert(points, irr.core.vector3d(-679.685059, 365.095612, 756.551453)) -- -54733
		table.insert(points, irr.core.vector3d(-671.317871, 447.360107, 749.394592)) -- -55588
		table.insert(points, irr.core.vector3d(-669.468445, 583.335632, 747.711853)) -- -56178
		table.insert(points, irr.core.vector3d(-667.611267, 727.313232, 746.018250)) -- -56757
		table.insert(points, irr.core.vector3d(-665.853210, 862.791931, 744.436096)) -- -57859
		table.insert(points, irr.core.vector3d(-642.649597, 1026.047607, 724.259827))-- -59705
		table.insert(points, irr.core.vector3d(-517.793884, 838.396790, 490.326050)) -- -60983
		table.insert(points, irr.core.vector3d(-474.387299, 715.691467, 344.639984)) -- -61629
		table.insert(points, irr.core.vector3d(-444.600250, 601.155701, 180.938095)) -- -62319
		table.insert(points, irr.core.vector3d(-414.808899, 479.691406, 4.866660))   -- -63048
		table.insert(points, irr.core.vector3d(-410.418945, 429.642242, -134.332687))-- -63757
		table.insert(points, irr.core.vector3d(-399.837585, 411.498383, -349.350983))-- -64418
		table.insert(points, irr.core.vector3d(-390.756653, 403.970093, -524.454407))-- -65005
		table.insert(points, irr.core.vector3d(-334.864227, 350.065491, -732.397400))-- -65701
		table.insert(points, irr.core.vector3d(-195.253387, 349.577209, -812.475891))-- -66335
		table.insert(points, irr.core.vector3d(16.255573, 363.743134, -833.800415))  -- -67170
		table.insert(points, irr.core.vector3d(234.940964, 352.957825, -820.150696)) -- -67939
		table.insert(points, irr.core.vector3d(436.797668, 349.236450, -816.914185)) -- -68596
		table.insert(points, irr.core.vector3d(575.236206, 356.244812, -719.788513)) -- -69166
		table.insert(points, irr.core.vector3d(594.131042, 387.173828, -609.675598)) -- -69744
		table.insert(points, irr.core.vector3d(617.615234, 412.002899, -326.174072)) -- -70640
		table.insert(points, irr.core.vector3d(606.456848, 403.221954, -104.179291)) -- -71390
		table.insert(points, irr.core.vector3d(610.958252, 407.037750, 117.209778))  -- -72085
		table.insert(points, irr.core.vector3d(597.956909, 395.167877, 345.942200))  -- -72817
		table.insert(points, irr.core.vector3d(587.383118, 391.444519, 566.098633))  -- -73477
		table.insert(points, irr.core.vector3d(559.572449, 371.991333, 777.689453))  -- -74124
		table.insert(points, irr.core.vector3d(423.753204, 329.990051, 925.859741))  -- -74941
		table.insert(points, irr.core.vector3d(247.520050, 252.818954, 935.311829))  -- -75651
		table.insert(points, irr.core.vector3d(114.756012, 199.799759, 805.014160))
		table.insert(points, irr.core.vector3d(96.783348, 181.639481, 648.188110))
		table.insert(points, irr.core.vector3d(97.865623, 138.905975, 484.812561))
		table.insert(points, irr.core.vector3d(99.612457, 102.463669, 347.603210))
		table.insert(points, irr.core.vector3d(99.612457, 102.463669, 347.603210))
		table.insert(points, irr.core.vector3d(99.612457, 102.463669, 347.603210))

		self.timeForThisScene = (table.getn(points) - 3) * 1000
		local array = irr.core.array(points)
		sa = sm:createFollowSplineAnimator(self.device:getTimer():getTime(), array)
		
		camera:addAnimator(sa)
		sa:drop()

		self.model1:setVisible(false)
		self.model2:setVisible(false)
		self.campFire:setVisible(false)
		self.inOutFader:fadeIn(7000)


	elseif self.currentScene == 2 then

		camera = sm:addCameraSceneNode(0, irr.core.vector3d(100,40,-80), irr.core.vector3d(844,670,-885))
		sa = sm:createFlyStraightAnimator(irr.core.vector3d(94, 1002, 127),
			irr.core.vector3d(108, 15, -60), 10000, true)
		camera:addAnimator(sa)
		self.timeForThisScene = 9900
		self.model1:setVisible(true)
		self.model2:setVisible(false)
		self.campFire:setVisible(false)
		sa:drop()


	elseif self.currentScene == 3 then

		-- interactive, go around

		self.model1:setVisible(true)
		self.model2:setVisible(true)
		self.campFire:setVisible(true)
		self.timeForThisScene = -1

		local keyMap = {}
		for i = 1,8 do keyMap[i] = irr.SKeyMap() end
	
		keyMap[1].Action  = irr.EKA_MOVE_FORWARD
		keyMap[1].KeyCode = irr.KEY_UP
		keyMap[2].Action  = irr.EKA_MOVE_FORWARD
		keyMap[2].KeyCode = irr.KEY_KEY_W
		
		keyMap[3].Action  = irr.EKA_MOVE_BACKWARD
		keyMap[3].KeyCode = irr.KEY_DOWN
		keyMap[4].Action  = irr.EKA_MOVE_BACKWARD
		keyMap[4].KeyCode = irr.KEY_KEY_S
		
		keyMap[5].Action  = irr.EKA_STRAFE_LEFT
		keyMap[5].KeyCode = irr.KEY_LEFT
		keyMap[6].Action  = irr.EKA_STRAFE_LEFT
		keyMap[6].KeyCode = irr.KEY_KEY_A
		
		keyMap[7].Action  = irr.EKA_STRAFE_RIGHT
		keyMap[7].KeyCode = irr.KEY_RIGHT
		keyMap[8].Action  = irr.EKA_STRAFE_RIGHT
		keyMap[8].KeyCode = irr.KEY_KEY_D

		camera = sm:addCameraSceneNodeFPS(nil, 100.0, 300.0, -1, keyMap, 8)
		camera:setPosition(irr.core.vector3d(108,140,-140))
		
		local y = 0
		if self.quakeLevelMesh then
			y = -3
		end

		local collider = 
			sm:createCollisionResponseAnimator(
			self.metaSelector, camera, irr.core.vector3d(30,50,30), 
			irr.core.vector3d(0,y,0), 
				irr.core.vector3d(0,40,0), 0.0005)
		
		camera:addAnimator(collider)
		collider:drop()
	end

	self.sceneStartTime = self.device:getTimer():getTime()

	-- if we've got a new created camera, we call OnPostRender to let all animators
	-- set the right position of the camera, otherwise the camera would
	-- be at a wrong position in the first frame
	if self.device:getSceneManager():getActiveCamera() then
		self.device:getSceneManager():getActiveCamera():OnPostRender(self.sceneStartTime)
	end
end

function CDemo:loadSceneData()

	-- load quake level
	local driver = self.device:getVideoDriver()
	local sm = self.device:getSceneManager()

	self.quakeLevelMesh = sm:getMesh("20kdm2.bsp")
	
	if self.quakeLevelMesh then
		self.quakeLevelNode = sm:addOctTreeSceneNode(self.quakeLevelMesh)
		if self.quakeLevelNode then
			self.quakeLevelNode:setPosition(irr.core.vector3d(-1300,-70,-1249))
			self.quakeLevelNode:setVisible(true)
			
			-- create map triangle selector
			self.mapSelector = sm:createOctTreeTriangleSelector(self.quakeLevelMesh:getMesh(0),
				self.quakeLevelNode, 128)

			-- set additive blending if wanted
			if self.additive then
				self.quakeLevelNode:setMaterialType(irr.video.EMT_LIGHTMAP_ADD)
			end
		end
	end




	-- load sydney model and create 2 instances

	local mesh = sm:getMesh(self.installPath .. "media/sydney.md2")
	if mesh then

		self.model1 = sm:addAnimatedMeshSceneNode(mesh)
		if self.model1 then
			self.model1:setMaterialTexture(0, driver:getTexture(self.installPath .. "media/spheremap.jpg"))
			self.model1:setPosition(irr.core.vector3d(100,40,-80))
			self.model1:setScale(irr.core.vector3d(2,2,2))
			self.model1:setMD2Animation(irr.scene.EMAT_SALUTE)
			self.model1:setMaterialFlag(irr.video.EMF_LIGHTING, false)
			self.model1:setMaterialType(irr.video.EMT_SPHERE_MAP)
			self.model1:addShadowVolumeSceneNode()
		end

		self.model2 = sm:addAnimatedMeshSceneNode(mesh)
		if self.model2 then
			self.model2:setPosition(irr.core.vector3d(180,15,-60))
			self.model2:setScale(irr.core.vector3d(2,2,2))
			self.model2:setMD2Animation(irr.scene.EMAT_RUN)
			self.model2:setAnimationSpeed(70)
			self.model2:setMaterialTexture(0, self.device:getVideoDriver():getTexture(self.installPath .. "media/sydney.bmp"))
			self.model2:setMaterialFlag(irr.video.EMF_LIGHTING, true)
			self.model2:addShadowVolumeSceneNode()
		end
	end

	local anim = 0

	-- create sky box

	self.skyboxNode = sm:addSkyBoxSceneNode(
		driver:getTexture(self.installPath .. "media/irrlicht2_up.jpg"),
		driver:getTexture(self.installPath .. "media/irrlicht2_dn.jpg"),
		driver:getTexture(self.installPath .. "media/irrlicht2_lf.jpg"),
		driver:getTexture(self.installPath .. "media/irrlicht2_rt.jpg"),
		driver:getTexture(self.installPath .. "media/irrlicht2_ft.jpg"),
		driver:getTexture(self.installPath .. "media/irrlicht2_bk.jpg"))


	-- create walk-between-portals animation

	local waypoint = { irr.core.vector3d(-150,40,100), irr.core.vector3d(350,40,100) }

	if self.model2 then
		anim = self.device:getSceneManager():createFlyStraightAnimator(waypoint[1], 
			waypoint[2], 2000, true)
		self.model2:addAnimator(anim)
		anim:drop()
	end

	-- create animation for portals

	local textures = {}
	for g=1,7 do 
		textures[g] = driver:getTexture(self.installPath .. "media/portal" .. g .. ".bmp")
	end

	local array = irr.core.array(textures)
	anim = sm:createTextureAnimator(array, 100)

	-- create portals

	local bill	

	for r=1,2 do
		bill = sm:addBillboardSceneNode(nil, irr.core.dimension2d(100,100),
			waypoint[r] + irr.core.vector3d(0,20,0))
		bill:setMaterialFlag(irr.video.EMF_LIGHTING, false)
		bill:setMaterialTexture(0, driver:getTexture(self.installPath .. "media/portal1.bmp"))
		bill:setMaterialType(irr.video.EMT_TRANSPARENT_ADD_COLOR)
		bill:addAnimator(anim)
	end


	anim:drop()

	-- create cirlce flying dynamic light with transparent billboard attached


	local light = self.device:getSceneManager():addLightSceneNode(nil,
		irr.core.vector3d(0,0,0),	irr.video.SColorf(1.0, 0.5, 0.5, 1.0), 1500)

	anim = self.device:getSceneManager():createFlyCircleAnimator(
		irr.core.vector3d(100,150,80), 80.0, 0.0005)

	light:addAnimator(anim)
	anim:drop()

	bill = self.device:getSceneManager():addBillboardSceneNode(
		light, irr.core.dimension2d(40,40))
	bill:setMaterialFlag(irr.video.EMF_LIGHTING, false)
	bill:setMaterialTexture(0, driver:getTexture(self.installPath .. "media/particlewhite.bmp"))
	bill:setMaterialType(irr.video.EMT_TRANSPARENT_ADD_COLOR)

	-- create meta triangle selector with all triangles selectors in it.
	self.metaSelector = sm:createMetaTriangleSelector()
	self.metaSelector:addTriangleSelector(self.mapSelector)

	-- create camp fire

	self.campFire = sm:addParticleSystemSceneNode(false, nil, -1, 
		irr.core.vector3d(100,120,600), irr.core.vector3d(0,0,0),
		irr.core.vector3d(2,2,2))

	self.campFire:setParticleSize(irr.core.dimension2d(20.0, 10.0))

	local em = self.campFire:createBoxEmitter(
		irr.core.aabbox3d(-7,0,-7,7,1,7), 
		irr.core.vector3d(0.0,0.03,0.0),
		80,100, irr.video.SColor(0,255,255,255),irr.video.SColor(0,255,255,255), 800,2000)

	self.campFire:setEmitter(em)
	em:drop()

	local paf = self.campFire:createFadeOutParticleAffector()
	self.campFire:addAffector(paf)
	paf:drop()

	self.campFire:setMaterialFlag(irr.video.EMF_LIGHTING, false)
	self.campFire:setMaterialTexture(0, driver:getTexture(self.installPath .. "media/fireball.bmp"))
	self.campFire:setMaterialType(irr.video.EMT_TRANSPARENT_VERTEX_ALPHA)


	-- set background color

	self.backColor:set(0,0,0,0)
end



function CDemo:createLoadingScreen()

	local size = self.device:getVideoDriver():getScreenSize()

	self.device:getCursorControl():setVisible(false)

	-- setup loading screen

	self.backColor:set(255,90,90,156)

	-- create in fader

	self.inOutFader = self.device:getGUIEnvironment():addInOutFader()
	self.inOutFader:setColor(self.backColor)

	-- irrlicht logo

	local img = self.device:getGUIEnvironment():addImage(
		irr.core.rect(10,10,98,41))

	img:setImage(
		self.device:getVideoDriver():getTexture(self.installPath .. "media/irrlichtlogoaligned.jpg"))

	-- loading text

	local lwidth = 120
	local lheight = 15

	local pos = irr.core.rect(10, size.Height-lheight-10, 10+lwidth, size.Height-10)
	
	self.device:getGUIEnvironment():addImage(pos)
	self.statusText = self.device:getGUIEnvironment():addStaticText("Loading...",	pos, true)
	self.statusText:setOverrideColor(irr.video.SColor(255,205,200,200))

	-- load bigger font

	self.device:getGUIEnvironment():getSkin():setFont(
		self.device:getGUIEnvironment():getFont(self.installPath .. "media/fonthaettenschweiler.bmp"))

	-- set new font color

	self.device:getGUIEnvironment():getSkin():setColor(irr.gui.EGDC_BUTTON_TEXT,
		irr.video.SColor(255,100,100,100))
end



function CDemo:shoot()

	local sm = self.device:getSceneManager()
	local camera = sm:getActiveCamera()

	if not camera or not self.mapSelector then
		return
	end


	local imp = {when = 0}
	-- get line of camera

	local Start = camera:getPosition()
	local End = (camera:getTarget() - Start)
	End:normalize()
	Start = Start + End * irr.core.vector3d(5.0,5.0,5.0)
	local farval = camera:getFarValue()
	End = Start + (End * irr.core.vector3d(farval, farval, farval))
	

	local triangle = irr.core.triangle3d()
	local line = irr.core.line3d(Start, End)


	-- get intersection point with map

	if sm:getSceneCollisionManager():getCollisionPoint( line, self.mapSelector, End, triangle) then
		-- collides with wall
		local out = triangle:getNormal()
		out:setLength(0.03)

		imp.when = 1
		imp.outVector = out
		imp.pos = End
	else
		-- doesnt collide with wall
		End = (camera:getTarget() - Start)
		End:normalize()
		End = Start + (End * irr.core.vector3d(1000,1000,1000))
	end

	-- create fire ball
	local node = sm:addBillboardSceneNode(nil, irr.core.dimension2d(25,25), Start)

	node:setMaterialFlag(irr.video.EMF_LIGHTING, false)
	node:setMaterialTexture(0, self.device:getVideoDriver():getTexture(self.installPath .. "media/fireball.bmp"))
	node:setMaterialType(irr.video.EMT_TRANSPARENT_ADD_COLOR)
		
	local length = (End - Start):getLength()
	local speed = 0.6
	local time = length / speed

	-- set flight line

	local anim = sm:createFlyStraightAnimator(Start, End, time)
	node:addAnimator(anim)	
	anim:drop()

	anim = sm:createDeleteAnimator(time)
	node:addAnimator(anim)
	anim:drop()

	if imp.when then 
		imp.when = self.device:getTimer():getTime() + (time - 100)
		table.insert(self.Impacts, imp)
	end

end


function CDemo:createParticleImpacts()

	local now = self.device:getTimer():getTime()
	local sm = self.device:getSceneManager()

	local i = table.getn(self.Impacts)
	while i >= 1 do
		if now > self.Impacts[i].when then

			-- create smoke particle system
			local pas = sm:addParticleSystemSceneNode(false, nil, -1, self.Impacts[i].pos)

			pas:setParticleSize(irr.core.dimension2d(10.0, 10.0))

			local em = pas:createBoxEmitter(
				irr.core.aabbox3d(-5,-5,-5,5,5,5),
				self.Impacts[i].outVector, 20,40, irr.video.SColor(0,255,255,255),irr.video.SColor(0,255,255,255),
				1200,1600, 20)

			pas:setEmitter(em)
			em:drop()

			local paf = self.campFire:createFadeOutParticleAffector()
			pas:addAffector(paf)
			paf:drop()

			pas:setMaterialFlag(irr.video.EMF_LIGHTING, false)
			pas:setMaterialTexture(0, self.device:getVideoDriver():getTexture(self.installPath .. "media/smoke.bmp"))
			pas:setMaterialType(irr.video.EMT_TRANSPARENT_VERTEX_ALPHA)

			local anim = sm:createDeleteAnimator(2000)
			pas:addAnimator(anim)
			anim:drop()

			-- delete entry
			table.remove(self.Impacts, i)
			i = i - 1
		end
		i = i - 1
	end
end


function main()

	local Start = false
	local fullscreen = false
	local music = false
	local shadows = false
	local additive = false
	local vsync = false
	local driverType = irr.video.EDT_DIRECTX9

	local menu = CMainMenu:new()
	Start, fullscreen, music, shadows, additive, vsync, driverType = menu:run()	

	if Start then
		local demo = CDemo:new(fullscreen, music, shadows, additive, vsync, driverType)
		 demo:run()		
	end

	return 0
end


main()

