-- Copyright (C) 2006 Josh Turpen
-- Adapted from Emil Halim's 'TAnimSpriteSceneNode' 
-- http://www.irrforge.org/index.php/Playing_2D_Animation_with_Irrlicht

require "IrrLua"

CAnimSpriteSceneNode = {}

function CAnimSpriteSceneNode:init(device)

	self.Box = irr.core.aabbox3d(-1,-1,-1,1,1,1)
	self.Material = irr.video.SMaterial()
	self.Ortho = irr.core.matrix4()

	self.Vertices = {}
	self.Indices = 
	{
		0,1,3, 3,1,2, 1,0,2, 2,0,3 
	}

	self.Texture = nil
	self.fWidth = 0
	self.fHeight = 0
	self.crntFrm = 0
	self.TotalFrm = 0
	self.stepww = 0
	self.stephh = 0
	self.forward = true
	self.time = 0
	self.oldtick = 0
	self.startFrame = 0
	self.endFrame = 0
	self.xCoord = 0
	self.yCoord = 0
	
	self.device = device -- used for GetTickCount() functionality
	local driver = self.SceneManager:getVideoDriver()
	self.Material.Wireframe = false
	self.Material.Lighting = false

	local Screensize = driver:getScreenSize()

	local rc = function(r,c) return 1 + r + c * 4 end

	self.Ortho.M[rc(0,0)] = 2/Screensize.Width
	self.Ortho.M[rc(1,0)] = 0
	self.Ortho.M[rc(2,0)] = 0
	self.Ortho.M[rc(3,0)] = 0

	self.Ortho.M[rc(0,1)] = 0
	self.Ortho.M[rc(1,1)] = 2/Screensize.Height
	self.Ortho.M[rc(2,1)] = 0
	self.Ortho.M[rc(3,1)] = 0

	self.Ortho.M[rc(0,2)] = 0
	self.Ortho.M[rc(1,2)] = 0
	self.Ortho.M[rc(2,2)] = 1
	self.Ortho.M[rc(3,2)] = 0

	self.Ortho.M[rc(0,3)] = 0
	self.Ortho.M[rc(1,3)] = 0
	self.Ortho.M[rc(2,3)] = 0
	self.Ortho.M[rc(3,3)] = 1
	return 
end

function CAnimSpriteSceneNode:Load(filename,Ax,Ay,Aw,Ah,frmWidth,frmHeight,useClrKey)
	useClrKey = useClrKey or false

	local driver = self.SceneManager:getVideoDriver()
	local Screensize = driver:getScreenSize()
	local x = frmWidth/2.0
	local y = frmHeight/2.0

	self.Vertices[1] = irr.video.S3DVertex(-x,-y,0, 0,0,0,irr.video.SColor(255,255,255,255),0,1)
	self.Vertices[2] = irr.video.S3DVertex( x,-y,0, 0,0,0,irr.video.SColor(255,255,255,255),1,1) 
	self.Vertices[3] = irr.video.S3DVertex( x, y,0, 0,0,0,irr.video.SColor(255,255,255,255),1,0)
	self.Vertices[4] = irr.video.S3DVertex(-x, y,0, 0,0,0,irr.video.SColor(255,255,255,255),0,0)

	self.Box:reset(self.Vertices[1].Pos)
	for i=2,4 do 
		self.Box:addInternalPoint(self.Vertices[i].Pos) 
	end
	 
	local Texture = driver:getTexture(filename)
	if not Texture then 
		print("could not load file " .. filename)
		return false 
	end
	if useClrKey then
		driver:makeColorKeyTexture(Texture,irr.core.position2d(0,0))
	end

	self.Material.MaterialType = irr.video.EMT_TRANSPARENT_ALPHA_CHANNEL
	self.Material.Texture1 = Texture
	self.Material.Texture2 = nil

	local size = Texture:getOriginalSize()
	self.frmWidth = frmWidth
	self.frmHeight = frmHeight
	self.fWidth  = frmWidth/size.Width
	self.fHeight = frmHeight/size.Height
	self.crntFrm = 0
	self.stepww = Aw / frmWidth
	self.stephh = Ah / frmHeight
	self.TotalFrm = self.stepww * self.stephh
	self.forward = true
	self.startFrame = 0 
	self.endFrame   = self.TotalFrm
	self.xCoord = Ax/size.Width
	self.yCoord = Ay/size.Height
				 
	self.Vertices[1].TCoords.X = self.xCoord + 0
	self.Vertices[1].TCoords.Y = self.yCoord + self.fHeight
	self.Vertices[2].TCoords.X = self.xCoord + self.fWidth 
	self.Vertices[2].TCoords.Y = self.yCoord + self.fHeight
	self.Vertices[3].TCoords.X = self.xCoord + self.fWidth 
	self.Vertices[3].TCoords.Y = self.yCoord + 0
	self.Vertices[4].TCoords.X = self.xCoord + 0 
	self.Vertices[4].TCoords.Y = self.yCoord + 0 
	
	self.filename = filename

	return true
end
         

function CAnimSpriteSceneNode:PlayForward()
	self.forward = true
end

function CAnimSpriteSceneNode:PlayBackward()
	self.forward = false
end

function CAnimSpriteSceneNode:setSpeed(spd)
	self.time = spd
end

function CAnimSpriteSceneNode:OnPreRender()
	if self.IsVisible then
		self.SceneManager:registerNodeForRendering(self)
	end
end
          
function CAnimSpriteSceneNode:setFrame(n)
	local x = (math.mod(n ,self.stepww))*self.fWidth
	local y = (n / self.stepww)*self.fHeight 
	self.Vertices[1].TCoords.X = self.xCoord + x; 
	self.Vertices[1].TCoords.Y = self.yCoord + y+self.fHeight;
	self.Vertices[2].TCoords.X = self.xCoord + x+self.fWidth; 
	self.Vertices[2].TCoords.Y = self.yCoord + y+self.fHeight;
	self.Vertices[3].TCoords.X = self.xCoord + x+self.fWidth; 
	self.Vertices[3].TCoords.Y = self.yCoord + y;
	self.Vertices[4].TCoords.X = self.xCoord + x; 
	self.Vertices[4].TCoords.Y = self.yCoord + y;
end

         
function CAnimSpriteSceneNode:Update()

	local timer = self.device:getTimer()
	if timer:getRealTime() - self.oldtick > self.time then
		self.oldtick = timer:getRealTime()
		if self.forward  then
			self.crntFrm = self.crntFrm + 1 
			if self.crntFrm > self.endFrame-1 then 
				self.crntFrm = self.startFrame 
			end
		else
			self.crntFrm = self.crntFrm - 1 
			if self.crntFrm < self.startFrame then 
				self.crntFrm = self.endFrame-1 
			end
		end

		local x = (math.mod(self.crntFrm, self.stepww))*self.fWidth
		local y = (math.floor(self.crntFrm / self.stepww))*self.fHeight 
		self.Vertices[1].TCoords.X = self.xCoord + x 
		self.Vertices[1].TCoords.Y = self.yCoord + y+self.fHeight
		self.Vertices[2].TCoords.X = self.xCoord + x+self.fWidth 
		self.Vertices[2].TCoords.Y = self.yCoord + y+self.fHeight
		self.Vertices[3].TCoords.X = self.xCoord + x+self.fWidth 
		self.Vertices[3].TCoords.Y = self.yCoord + y
		self.Vertices[4].TCoords.X = self.xCoord + x 
		self.Vertices[4].TCoords.Y = self.yCoord + y
	end
end
         
function CAnimSpriteSceneNode:setStartEndFrame( st, ed) 
	self.startFrame = st 
	self.endFrame   = ed
end
          
function GetMaxFrames()  
	return self.TotalFrm 
end
           
function CAnimSpriteSceneNode:render()

	local driver = self.SceneManager:getVideoDriver()
	driver:setMaterial(self.Material)  

	local Trns = irr.core.matrix4()
	local Scl  = irr.core.matrix4()
	local Rot  = irr.core.matrix4()
	local wrld = irr.core.matrix4()

	Trns:makeIdentity()
	Scl:makeIdentity()
	Rot:makeIdentity()
	wrld:makeIdentity()

	Trns:setTranslation(self.RelativeTranslation)
	Scl:setScale(self.RelativeScale)
	Rot:setRotationRadians(self.RelativeRotation)

	driver:setTransform(irr.video.ETS_VIEW, wrld)
	driver:setTransform(irr.video.ETS_PROJECTION, wrld)

	-- wrld = Trns * self.Ortho * Rot * Scl
	wrld = Trns * self.Ortho * Rot * Scl
	
	driver:setTransform(irr.video.ETS_WORLD, wrld)
	driver:drawIndexedTriangleList(self.Vertices, self.Indices)
end

function CAnimSpriteSceneNode:getBoundingBox()
	return self.Box 
end
 
function CAnimSpriteSceneNode:getMaterialCount()
	return 1
end

function CAnimSpriteSceneNode:getMaterial(i)
	return self.Material
end

function CAnimSpriteSceneNode:setPos(pos) 

	pos.X = pos.X + self.frmWidth*self.RelativeScale.X/2
	pos.Y = pos.Y + self.frmHeight*self.RelativeScale.Y/2

	local viewport = self.SceneManager:getVideoDriver():getViewPort()

	local X = 2 * (pos.X - viewport.UpperLeftCorner.X) / viewport.LowerRightCorner.X - 1
	local Y = 2 * (pos.Y - viewport.UpperLeftCorner.Y) / viewport.LowerRightCorner.Y - 1
	local Z = 0

	local v = irr.core.vector3d(X,-Y,Z)
	self:setPosition(v)
end

function CAnimSpriteSceneNode:getPos() 

	local pos = self:getPosition()
	local viewport = self.SceneManager:getVideoDriver():getViewPort()

	local X = (pos.X * viewport.LowerRightCorner.X + 1)/2 + viewport:getWidth()/2 - self.frmWidth *self.RelativeScale.X/2
	local Y = (pos.Y * viewport.LowerRightCorner.Y + 1)/2 - viewport:getHeight()/2 + self.frmHeight*self.RelativeScale.Y/2

	return irr.core.position2d(X,Y)

end

function CAnimSpriteSceneNode:getSize()
	
	local width = self.frmWidth * self.RelativeScale.X
	local height = self.frmHeight * self.RelativeScale.Y
	return irr.core.dimension2d(width, height)

end

function CAnimSpriteSceneNode:hit(pos)
	local spritePosition = self:getPos()
	local size = self:getSize()
	local X = pos.X
	local Y = pos.Y

	if X > spritePosition.X and X < spritePosition.X + size.Width and 
	 Y > spritePosition.Y and Y < spritePosition.Y + size.Height then 
		return true
	end
		
	return false
end

function CAnimSpriteSceneNode:setScaleToRect(rect)
	
	local Width = rect:getWidth()
	local Height = rect:getHeight()

	local v = irr.core.vector3d(Width/self.frmWidth, Height/self.frmHeight, 0)
	self:setScale(v)

end

