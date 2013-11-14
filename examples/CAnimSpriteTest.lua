
require "IrrLua"
require "CAnimSprite"


function main()

	local irrDevice = irr.createDevice(irr.video.EDT_OPENGL,irr.core.dimension2d(640,480),32,false,false,false,nil) 
	local irrVideo  = irrDevice:getVideoDriver()
	local irrSceneMgr = irrDevice:getSceneManager()
     
	local mf = "../media/images/"	
	local files = {mf .. "red.bmp", mf .. "blue.bmp", mf .. "orange.bmp", mf .. "yellow.bmp", mf .. "star.bmp"}
	local Sprites = {}
	for i,v in pairs(files) do
		Sprites[i] = irr.scene.createISceneNode(irrSceneMgr:getRootSceneNode(), irrSceneMgr, -1, CAnimSpriteSceneNode) 
		Sprites[i]:init(irrDevice)
		Sprites[i]:Load(v,0,0,40*5,40,40,40,true) 
		Sprites[i]:setSpeed(100)
		Sprites[i]:setPosition(irr.core.vector3d(-1 + i * 0.117,0.1,0)) 
		Sprites[i]:drop()
	end	
	
	local ts = irr.scene.createISceneNode(irrSceneMgr:getRootSceneNode(), irrSceneMgr, 666, CAnimSpriteSceneNode) 
	
	ts:init(irrDevice)
	ts:Load(mf .. "red.bmp",0,0,40*5,40,40,40,true)
	ts:setRotation(irr.core.vector3d(1,2,3))

	local msg = {}
	local v = ts:getRotation()
	msg["Rotation" ] = {v.X, v.Y, v.Z}
	ts:setName("test node")
	msg["Name"] = {ts:getName()}
	local b = ts:getBoundingBox()
	msg["BoundingBox"] = {b.MinEdge.X, b.MinEdge.Y, b.MinEdge.Z,":", b.MaxEdge.X, b.MaxEdge.Y, b.MaxEdge.Z}
	-- local tb = ts:getTransformedBoundingBox()
	-- msg["TransformedBoundingBox"] = {tb.MinEdge.X, tb.MinEdge.Y, tb.MinEdge.Z,":", tb.MaxEdge.X, tb.MaxEdge.Y, tb.MaxEdge.Z}
	local at = ts:getAbsoluteTransformation()
	msg["AbsoluteTransformation"] = { "\n",
										at.M[1], at.M[2], at.M[3], at.M[4], "\n",
									 at.M[5], at.M[6], at.M[7], at.M[8], "\n",
									 at.M[9], at.M[10], at.M[11], at.M[12], "\n",
									 at.M[13], at.M[14], at.M[15], at.M[16], "\n"}
									 
	local at = ts:getRelativeTransformation()
	msg["RelativeTransformation"] = { "\n",
										at.M[1], at.M[2], at.M[3], at.M[4], "\n",
									 at.M[5], at.M[6], at.M[7], at.M[8], "\n",
									 at.M[9], at.M[10], at.M[11], at.M[12], "\n",
									 at.M[13], at.M[14], at.M[15], at.M[16], "\n"}
									 
	msg["isVisble"] = { ts:isVisible() }									 
	local s = ts:getScale()
	msg["Scale"] = {s.X, s.Y, s.Z}
	msg["ID"] = {ts:getID()}
	--[[
	local mat = ts:getMaterial()
	print(mat, tolua.type(mat))
	msg["Material"] = 
	{
		"\n",
		"MaterialType:" .. tonumber(ts.MaterialType or 0),
		"AmbientColor:" .. ts.AmbientColor.R .. ts.AmbientColor.G .. ts.AmbientColor.B .. ts.AmbientColor.A,
		"EmissiveColor:" .. ts.EmissiveColor.R .. ts.EmissiveColor.G .. ts.EmissiveColor.B .. ts.EmissiveColor.A,
		"SpecularColor:" .. ts.SpecularColor.R .. ts.SpecularColor.G .. ts.SpecularColor.B .. ts.SpecularColor.A,
		"Shininess:" .. ts.Shininess,
		"MaterialTypeParam:" .. ts.MaterialTypeParam,
		"Texture1:" .. type(ts.Texture1),
		"Texture2:" .. type(ts.Texture2),
		"Texture3:" .. type(ts.Texture3),
		"Texture4:" .. type(ts.Texture4)
	}
	--]]
									 
	for i,v in pairs(msg) do print(i .. ":", unpack(v)) end		
	
	local rt = 0
	while irrDevice:run() do
		irrVideo:beginScene(true, true, irr.video.SColor(0,200,200,200))
		for i, Sprite in pairs(Sprites) do 
			-- Sprite:setRotation(irr.core.vector3d(0,0,rt))
			Sprite:Update() 
		end
		rt = rt + 0.01
		irrSceneMgr:drawAll() 
		irrVideo:endScene()
	 end
     irrDevice:drop()
     return 0
end
main()


