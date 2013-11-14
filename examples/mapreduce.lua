-- Copyright (c) 2005  Josh Turpen

require "IrrLua"


Node = 
{
	ID=-1,
	node=nil
}

function Node:new(ID,smgr,mesh,texture) 
	local t = {} 
	t.__index = Node
	setmetatable(t,t)

	t.ID = ID
	t.node = smgr:addAnimatedMeshSceneNode( mesh )

	t.node:setMaterialFlag(irr.video.EMF_LIGHTING , false)
	t.node:setMD2Animation(irr.scene.EMAT_RUN)
	t.node:setMaterialTexture( 0, texture)
	t.node:setPosition(irr.core.vector3d(10*math.random(ID), 0, 10*math.random(ID)))

	return t
end


function Node:move()
	local n = self.node
	local p = n:getPosition()

	n:setPosition(irr.core.vector3d(p.X + math.random(5) - math.random(5), p.Y, p.Z + math.random(5) - math.random(5)))
	return self
end


function map(fn,t)
	for i = 1, #t do
		t[i]=fn(t[i])
	end
end

function reduce(fn, t, init)
	local r = init 
	for i = 1, #t do
		r = fn( r, t[i] )
	end
	return r
end 



function main()
	-- path to root Irrlicht directory so we can find the media files
	local installPath = "../../../"

	device = irr.createDevice(irr.video.EDT_SOFTWARE, irr.core.dimension2d(1024, 768), 16, false, false, false)

	device:setWindowCaption("fun with map()")
	
	driver = device:getVideoDriver()
	smgr = device:getSceneManager()


	mesh = smgr:getMesh(installPath .. "media/sydney.md2")
	texture = driver:getTexture(installPath .. "media/sydney.bmp")

	smgr:addCameraSceneNodeFPS()
	device:getCursorControl():setVisible(false)

	local nodes = {}
	local max = 50
	for i = 1,max do nodes[i]=i end -- no more table.setn :(

	map(function(a) return Node:new(a,smgr, mesh, texture) end, nodes)

	while device:run() do
	
		driver:beginScene(true, true, irr.video.SColor(0,200,200,200))
		smgr:drawAll()
		driver:endScene()

		-- move all the odd nodes
		map(Node.move, reduce(function(r,t) if math.mod(t.ID,2) ~= 0 then table.insert(r,t) end return r end, nodes, {}))
		

	end
	
	device:drop()
	return 0
end

main()

