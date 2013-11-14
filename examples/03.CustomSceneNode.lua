
require "IrrLua"

--[[
This Tutorial is a tutorial for more advanced developers.
If you are currently just playing around with the Irrlicht
engine, please look at other examples first. 
This tutorials shows how to create a custom scene node and
how to use it in the engine. A custom scene node is needed,
if you want to implement a render technique, the Irrlicht 
Engine is currently not supporting. For example you can write
a indoor portal based renderer or a advanced terrain scene 
node with it. With creating custom scene nodes, you can 
easily extend the Irrlicht Engine and adapt it to your
needs.
--]]


-- Create our custom scene node in Lua
CMySceneNode = {}

function CMySceneNode:init()

	self.Box = irr.core.aabbox3d(-1,-1,-1,1,1,1)
	self.Vertices = {
		irr.video.S3DVertex(0,0,10, 1,1,0, irr.video.SColor(255,0,255,255), 0, 1),
		irr.video.S3DVertex(10,0,-10, 1,0,0, irr.video.SColor(255,255,0,255), 1, 1),
		irr.video.S3DVertex(0,20,0, 0,1,1, irr.video.SColor(255,255,255,0), 1, 0),
		irr.video.S3DVertex(-10,0,-10, 0,0,1, irr.video.SColor(255,0,255,0), 0, 0)
	}
	self.Material = irr.video.SMaterial()
	self.Material.Wireframe = false
	self.Material.Lighting = false	
	self.Box:reset(self.Vertices[1].Pos)
	for i=2,4 do 
		self.Box:addInternalPoint(self.Vertices[i].Pos) 
	end
	return self	
end


function CMySceneNode:OnPreRender()
	if self:isVisible() then
		self.SceneManager:registerNodeForRendering(self)
	end
end

-- You must implement render() (required)
function CMySceneNode:render()
	local indices = {0,2,3, 2,1,3, 1,0,3, 2,0,1}
	local driver = self.SceneManager:getVideoDriver()
	driver:setMaterial(self.Material)
	driver:setTransform(irr.video.ETS_WORLD, self:getAbsoluteTransformation())
	driver:drawIndexedTriangleList(self.Vertices, indices)
end

-- You must implement getBoundingBox() (required)
function CMySceneNode:getBoundingBox()
	return self.Box
end
function CMySceneNode:getMaterialCount()
	return 1
end

function CMySceneNode:getMaterial(i)
	return self.Material
end

function main()

	-- create engine and camera
	device = irr.createDevice(irr.video.EDT_OPENGL, irr.core.dimension2d(640, 480), 16, false)

	device:setWindowCaption("Custom Scene Node - Irrlicht Engine Demo")

	driver = device:getVideoDriver()
	smgr = device:getSceneManager()

	smgr:addCameraSceneNode(nil, irr.core.vector3d(0,-40,0), irr.core.vector3d(0,0,0) )


	-- local myNode = CMySceneNode:new()
	local myNode = irr.scene.createISceneNode(smgr:getRootSceneNode(), smgr, 666, CMySceneNode)
	myNode:init()

    myNode:drop()

	--[[	
	To animate something in this boring scene consisting only of one tetraeder,
	and to show, that you now can use your scene node like any other scene
	node in the engine, we add an animator to the scene node, which rotates
	the node a little bit.
	--]]

	anim = smgr:createRotationAnimator(irr.core.vector3d(0.8, 0, 0.8))

	myNode:addAnimator(anim)
	anim:drop()
	
	--[[
	Now draw everything and finish.
	--]]

	while device:run() do
 		driver:beginScene(true, true, irr.video.SColor(0,100,100,100))
 		smgr:drawAll()
 		driver:endScene()
 	end

	device:drop()
	return 0
end

main()

