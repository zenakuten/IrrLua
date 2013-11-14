
require "IrrLua"

--[[
This tutorial shows how to use shaders for D3D8, D3D9 and OpenGL 
with the engine and how to create new material types with them. It also
shows how to disable the generation of mipmaps at texture loading, and
how to use text scene nodes.

This tutorial does not explain how shaders work. I would recommend to read the D3D
or OpenGL  documentation, to search a tutorial, or to read a book about this.

Because we want to use some interesting shaders in this tutorials, we
need to set some data for them to make them able to compute nice
colors. In this example, we'll use a simple vertex shader which will 
calculate the color of the vertex based on the position of the camera.
For this, the shader needs the following data: The inverted world matrix
for transforming the normal, the clip matrix for transforming the position,
the camera position and the world position of the object for the calculation
of the angle of light, and the color of the light. To be able to tell the
shader all this data every frame, we have to derive a class from the
IShaderConstantSetCallBack interface and override its only method, 
namely OnSetConstants(). This method will be called every time the material
is set. 
The method setVertexShaderConstant() of the IMaterialRendererServices interface
is used to set the data the shader needs. If the user chose to use a High Level shader
language like HLSL instead of Assembler in this example, you have to set the 
variable name as parameter instead of the register index.
--]]

device = 0
UseHighLevelShaders = false

MyShaderCallBack = {}

function MyShaderCallBack:OnSetConstants(services, userData)

	
	local driver = services:getVideoDriver()

	-- set inverted world matrix
	-- if we are using highlevel shaders (the user can select this when
	-- starting the program), we must set the constants by name.
	local invWorld = driver:getTransform(irr.video.ETS_WORLD)
	invWorld:makeInverse()

	-- set clip matrix
	local worldViewProj
	worldViewProj = driver:getTransform(irr.video.ETS_PROJECTION)		
	worldViewProj = worldViewProj * driver:getTransform(irr.video.ETS_VIEW)
	worldViewProj = worldViewProj * driver:getTransform(irr.video.ETS_WORLD)
	
	-- set camera position
	local pos = device:getSceneManager():getActiveCamera():getAbsolutePosition()

	-- set light color 
	local col = irr.video.SColorf(0,1,1,0)

	-- set transposed world matrix
	
	local world = driver:getTransform(irr.video.ETS_WORLD)
	world = world:getTransposed()
				
	if UseHighLevelShaders then
		services:setVertexShaderConstant("mInvWorld", invWorld.M, 16)
		services:setVertexShaderConstant("mWorldViewProj", worldViewProj.M, 16)
		-- *Note* 
		-- DirectX breaks here due to irrlicht bug, must use patched irrlicht
	 	services:setVertexShaderConstant("mLightPos", { pos.X, pos.Y, pos.Z })
		services:setVertexShaderConstant("mLightColor", {col.r, col.g, col.b, col.a} )
	 	services:setVertexShaderConstant("mTransWorld",  world.M, 16  )
	 else
		services:setVertexShaderConstant(invWorld.M, 0, 4)
	 	services:setVertexShaderConstant(worldViewProj.M, 4, 4)		
	  	services:setVertexShaderConstant({ pos.X, pos.Y, pos.Z }, 8, 1)
	 	services:setVertexShaderConstant({ col.r, col.g, col.b, col.a }, 9, 1)
	 	services:setVertexShaderConstant(world.M, 10, 4)
	end
end


--[[
The next few lines start up the engine. Just like in most other tutorials
before. But in addition, we ask the user if he wants this example to use
high level shaders if he selected a driver which is capable of doing so.
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

	-- ask the user if we should use high level shaders for this example
	if type == irr.video.EDT_DIRECT3D9 or type == irr.video.EDT_OPENGL then
		print("Please press 'y' if you want to use high level shaders.\n")
		local i = io.read("*line")
		if i == "y" then
			UseHighLevelShaders = true
		end
	end

	-- create device
	device = irr.createDevice(type, irr.core.dimension2d(640, 480))

	if device == nil then
		print("Error creating device\n")
		return 1 -- could not create selected driver.
	end

	local driver = device:getVideoDriver()
	local smgr = device:getSceneManager()
	local gui = device:getGUIEnvironment()

	--[[
	Now for the more interesting parts. 
	If we are using Direct3D, we want to load vertex and pixel shader programs, if we have
	OpenGL, we want to use ARB fragment and vertex programs. I wrote the 
	corresponding programs down into the files d3d8.ps, d3d8.vs, d3d9.ps, d3d9.vs, 
	opengl.ps and opengl.vs. We only need the right filenames now. This is done in the 
	following switch. Note, that it is not necessary to write the shaders into text
	files, like in this example. You can even write the shaders directly as strings
	into the cpp source file, and use later addShaderMaterial() instead of 
	addShaderMaterialFromFiles().
	--]]
	
	local psFileName = "" -- filename for the pixel shader
	local vsFileName = "" -- filename for the vertex shader

	mediaFiles = {	[irr.video.EDT_DIRECT3D8] = {ps = "d3d8.psh", vs = "d3d8.vsh"} , 
					[irr.video.EDT_DIRECT3D9] = {ps = "d3d9.psh", vs = "d3d9.vsh"} , 
					[irr.video.EDT_OPENGL] = {ps = "opengl.psh", vs = "opengl.vsh"} ,
					[irr.video.EDT_SOFTWARE] = {ps = "", vs = ""}, 
					[irr.video.EDT_SOFTWARE2] = {ps = "", vs = ""}} 


	psFileName = mediaFiles[type].ps
	vsFileName = mediaFiles[type].vs

	if UseHighLevelShaders then
		if type == irr.video.EDT_DIRECT3D9 then
			psFileName = "d3d9.hlsl"
			vsFileName = psFileName
		elseif type == irr.video.EDT_OPENGL then
			psFileName = "opengl.frag"
			vsFileName = "opengl.vert"
		end
	end

	psFileName = installPath .. "media/" .. psFileName
	vsFileName = installPath .. "media/" .. vsFileName

	--[[
	In addition, we check if the hardware and the selected renderer is capable 
	of executing the shaders we want. If not, we simply set the filename string
	to 0. This is not necessary, but useful in this example: For example, if 
	the hardware is able to execute vertex shaders but not pixel shaders, we create
	a new material which only uses the vertex shader, and no pixel shader. 
	Otherwise, if we would tell the engine to create this material and the engine
	sees that the hardware wouldn't be able to fullfill the request completely,
	it would not create any new material at all. So in this example you would see
	at least the vertex shader in action, without the pixel shader.
	--]]




	if (not driver:queryFeature(irr.video.EVDF_PIXEL_SHADER_1_1)) and
		(not driver:queryFeature(irr.video.EVDF_ARB_FRAGMENT_PROGRAM_1)) then
		device:getLogger():log("WARNING: Pixel shaders disabled because of missing driver/hardware support.")
		psFileName = nil
	end
	
	
	if ( not driver:queryFeature(irr.video.EVDF_VERTEX_SHADER_1_1)) and
		(not driver:queryFeature(irr.video.EVDF_ARB_VERTEX_PROGRAM_1)) then
	
		device:getLogger():log("WARNING: Vertex shaders disabled because of missing driver/hardware support.")
		vsFileName = nil
	end	

	--[[
	Now lets create the new materials.
	As you maybe know from previous examples, a material type in the Irrlicht engine
	is set by simply changing the MaterialType value in the SMaterial struct. And this
	value is just a simple 32 bit value, like video::EMT_SOLID. So we only need the 
	engine to create a new value for us which we can set there. 
	To do this, we get a pointer to the IGPUProgrammingServices and call 
	addShaderMaterialFromFiles(), which returns such a new 32 bit value. That's all.
	The parameters to this method are the following:
	First, the names of the files containing the code of the vertex and the pixel shader.
	If you would use addShaderMaterial() instead, you would not need file names, then you 
	could write the code of the shader directly as string.
	The following parameter is a pointer to the IShaderConstantSetCallBack class we wrote
	at the beginning of this tutorial. If you don't want to set constants, set this to 0.
	The last paramter tells the engine which material it should use as base material. 
	To demonstrate this, we create two materials with a different base material, one
	with EMT_SOLID and one with EMT_TRANSPARENT_ADD_COLOR.
	--]]

	-- create materials

	local gpu = driver:getGPUProgrammingServices()
	local newMaterialType1 = 0
	local newMaterialType2 = 0
	
	local mc = irr.video.createIShaderConstantSetCallBack(MyShaderCallBack)
	if gpu ~= nil then

		-- create the shaders depending on if the user wanted high level
		-- or low level shaders:

		if UseHighLevelShaders then
			-- create material from high level shaders (hlsl or glsl)

			newMaterialType1 = gpu:addHighLevelShaderMaterialFromFiles(
				vsFileName,	"vertexMain", irr.video.EVST_VS_1_1,
				psFileName, "pixelMain", irr.video.EPST_PS_1_1,
				mc, irr.video.EMT_SOLID)

			newMaterialType2 = gpu:addHighLevelShaderMaterialFromFiles(
				vsFileName,	"vertexMain", irr.video.EVST_VS_1_1,
				psFileName, "pixelMain", irr.video.EPST_PS_1_1,
				mc, irr.video.EMT_TRANSPARENT_ADD_COLOR)
		else
		
			-- create material from low level shaders (asm or arb_asm)

			newMaterialType1 = gpu:addShaderMaterialFromFiles(vsFileName,
				psFileName, mc, irr.video.EMT_SOLID)

			newMaterialType2 = gpu:addShaderMaterialFromFiles(vsFileName,
				psFileName, mc, irr.video.EMT_TRANSPARENT_ADD_COLOR)
		
		end

		mc:drop()

	end

	--[[
	Now time for testing out the materials. We create a test cube
	and set the material we created. In addition, we add a text scene node to
	the cube and a rotatation animator, to make it look more interesting and 
	important. 
	--]]

	-- create test scene node 1, with the new created material type 1

	
	local node1 = smgr:addCubeSceneNode(50)
	node1:setPosition(irr.core.vector3d(0,0,0))
	node1:setMaterialTexture(0, driver:getTexture(installPath .. "media/wall.bmp"))
	node1:setMaterialType(newMaterialType1)

	smgr:addTextSceneNode(gui:getBuiltInFont(), 
			"PS & VS & EMT_SOLID", 
			irr.video.SColor(255,255,255,255),	node1)

	local anim = smgr:createRotationAnimator(
			irr.core.vector3d(0,0.3,0))
	node1:addAnimator(anim)
	anim:drop()
	
	
	--[[
	Same for the second cube, but with the second material we created.
	--]]

	-- create cube scene node 2, with the new created material type 2

	local node2 = smgr:addCubeSceneNode(50)
	node2:setPosition(irr.core.vector3d(0,-10,50))
	node2:setMaterialTexture(0, driver:getTexture(installPath .. "media/wall.bmp"))
	node2:setMaterialType(newMaterialType2)

	smgr:addTextSceneNode(gui:getBuiltInFont(), 
			"PS & VS & EMT_TRANSPARENT", 
			irr.video.SColor(255,255,255,255),	node2)

	anim = smgr:createRotationAnimator(irr.core.vector3d(0,0.3,0))
	node2:addAnimator(anim)
	anim:drop()
	
	--[[
	Then we add a third cube without a shader on it, to be able to compare the
	cubes.
	--]]

	-- add a scene node with no shader 

	local node3 = smgr:addCubeSceneNode(50);
	node3:setPosition(irr.core.vector3d(0,50,25))
	node3:setMaterialTexture(0, driver:getTexture(installPath .. "media/wall.bmp"))
	node3:setMaterialFlag(irr.video.EMF_LIGHTING, false)
	smgr:addTextSceneNode(gui:getBuiltInFont(), "NO SHADER",
		irr.video.SColor(255,255,255,255), node3)
	
	--[[
	And last, we add a skybox and a user controlled camera to the scene.
	For the skybox textures, we disable mipmap generation, because we don't
	need mipmaps on it.
	--]]

	-- add a nice skybox

	driver:setTextureCreationFlag(irr.video.ETCF_CREATE_MIP_MAPS, false)

	smgr:addSkyBoxSceneNode(
		driver:getTexture(installPath .. "media/irrlicht2_up.jpg"),
		driver:getTexture(installPath .. "media/irrlicht2_dn.jpg"),
		driver:getTexture(installPath .. "media/irrlicht2_lf.jpg"),
		driver:getTexture(installPath .. "media/irrlicht2_rt.jpg"),
		driver:getTexture(installPath .. "media/irrlicht2_ft.jpg"),
		driver:getTexture(installPath .. "media/irrlicht2_bk.jpg"))

	driver:setTextureCreationFlag(irr.video.ETCF_CREATE_MIP_MAPS, true)
	-- add a camera and disable the mouse cursor

	local cam = smgr:addCameraSceneNodeFPS(nil, 100.0, 100.0)
	cam:setPosition(irr.core.vector3d(-100,50,100))
	cam:setTarget(irr.core.vector3d(0,0,0))
	device:getCursorControl():setVisible(false)

	--[[
	Now draw everything. That's all.
	--]]

	local lastFPS = -1

	local bgcolor = irr.video.SColor(255,0,0,0)
	while device:run() do
		if device:isWindowActive() then
	
			driver:beginScene(true, true, bgcolor)
			smgr:drawAll()
			driver:endScene()

			local fps = driver:getFPS()

			if lastFPS ~= fps then
		
				local str = "Irrlicht Engine - Vertex and pixel shader example ["
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



