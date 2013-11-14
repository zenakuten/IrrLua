--[[
Using ODE with Irrlicht 
I strongly suggest reading the ODE documentation at
http://opende.sourceforge.net/ode-latest-userguide.html

convert to Lua by jjt
--]] 

require "IrrLua"
require "odelua"

module bounce 
{
	-- gravitation force y-direction
	GRAVITY = -75.0
	QUBE_SPACING = 50.0
	LIVETIME = 5000
	QUBE_INITHEIGHT = 7000

	QUBE_SIZE = 150.0
	-- maximum number of qubes in the simulation
	MAX_QUBES = 200

	--[[	stress test
		check out dBodyEnable() dBodyDisable() or dGeomEnable() dGeomDisable()
		you might want to disable non moving bodies/geoms to save collision overhead
		stack overflow may occure when to many bodies overlap at initial positioning!!!!!
	--]]

	MAX_CONTACTS 10

	MyEventReceiver = {}
	function MyEventReceiver:OnEvent(e)
		if e.EventType == irr.EET_KEY_INPUT_EVENT then
			if e.KeyInput.Key == irr.KEY_ESCAPE and e.KeyInput.PressedDown then
				self.End = true
			elseif e.KeyInput.Key == irr.KEY_TAB and not e.KeyInput.PressedDown then
				self.Simulate = not self.Simulate
			elseif e.KeyInput.Key == irr.KEY_RETURN and not e.KeyInput.PressedDown then
				self.Reanimate = true
			end
		end
	end


	--[[ 
	the main class 
	holds information about the body, mass and geometry for ODE
	and has a reference to the scenenode which visualizes the object
	--]]

	Bounceable = 
	{
		bounceables = {} 		--  a list of all object contained in the simulation
		theWorld = nil 			--  just one world for now 
		theSpace = nil			--  and one space for all objects
		theJointGroup = nil		--  the group to which all contact joint are added

		world = nil				-- the world to which the object will belong to
		space = nil				-- the objects space
		body = nil				-- body data of the object
		geom = nil				-- geometry data of the object
		mass = nil				-- mass of the object
		node = nil				--  visualizing node
		mesh = nil				-- mesh of the visualizing node

		vertices = {}			-- vertex array for trimesh geom
		indices = {}			-- index array for trimesh geom

		timetolive = 0
	}

	--[[	
	Bounceable constructor
	a bounceable object belongs to a world and a collision space 
	param w, the world this object will belong to (ODE stuff)
	param s, the collision space the object belongs to (ODE stuff)
	param b, the ODE body reference
	param g, the ODE geometry reference
	param n, the irrlicht scene node
	param m, the irrlicht mesh used to construct the scenenode
	param o, optional object to inherit from
	--]]	
	
	function Bounceable:new(w, s, b, g, n, m, o)

		o = o or {}
		o.__index = self
		setmetatable(o,o)

		o.world = w
		o.space = s
		o.body = b
		o.geom = g
		o.node = n
		o.mesh = m

		if o.node then n:grab() end
		if o.mesh then m.grab() end

		return o
	end

	function Bounceable:delete()
		if self.node then self.node:drop() end
		if self.mesh then self.mesh:drop() end
		self.vertices = nil
		self.indicies = nil
	end

	--[[ 
	Set the Position of the scenenode
	param pos, vector which holds the new position
	--]]
	
	function Bounceable:setPosition(pos)
		if self.node then 
			node:setPosition(pos)
		end
	end

	--[[
	Set the Rotation angles of the scenenode. 
	Note that the angles we are talking about are euler angles and are supposed to be in degrees.
	param rot, vector holding the angles (rot.X - rotation around the x-axis,...)
	--]]
	
	function Bounceable:setRotation(rot)
		if self.node then
			node:setRotation(rot) 
		end
	end

	--[[
	Then main function for this tutorial
	--]]
	function Bounceable:RunApplication()

		self:CreateWorld()

		local bounce
		local bounceTerrain

		local End=false
		local simulate=true
		local reanimate=false

		local receiver = irr.createIEventReceiver(self.MyEventReceiver)

		receiver.End=End
		receiver.simulate=simulate
		receiver.reanimate=reanimate

		local device = irr.createDevice(irr.video.EDT_DIRECTX8, irr.core.dimension2d(640, 480), 32, false, true, receiver)

		local driver = device:getVideoDriver()
		local smgr =  device:getSceneManager()
		local guienv= device:getGUIEnvironment()

		-- some help
		local elem=guienv:addStaticText("[Enter] reset height of qubes, [TAB] pause the simulation, [Esc] end", irr.core.rect(0,0,300,100))
		elem:setOverrideColor(irr.video.SColor(255,255,255,255))

		-- build the terrain
		local terrainTexture = device:getVideoDriver():getTexture("data/terr_tex.jpg")
		local lightTexture = device:getVideoDriver():getTexture("data/terr_light.jpg")
		local heightField = device:getVideoDriver():createImageFromFile("data/terr_height.jpg")

		if heightField ~= nil and terrainTexture ~= nil and lightTexture ~= nil then

			--[[
			Zola::FX::CTerrainSceneNode* terrain=new Zola::FX::CTerrainSceneNode(
				heightField, // heightfield
				16, // word scale 2^(n+1) units
				9, // heightfield data inserted at 2^n unit spacing
				32.0f, // scale
				true, // update ever 40 frames
				device->getSceneManager()->getRootSceneNode(),  // scenegraph root node
				device->getSceneManager(),  // scenemanager
				-1 // node id
				);
			--]]

			if terrain ~= nil then
				if terrainTexture ~= nil then terrain:setMaterialTexture(0,terrainTexture) end
				if lightTexture ~= nil then terrain:setMaterialTexture(1,lightTexture) end
				terrain:setVisible(true)
				local ext = terrain:getBoundingBox():getExtend()
				terrain:setPosition(irr.core.vector3d(-ext.X/2 ,0 ,-ext.Z/2) )
				-- create terrain mesh for ode collisions
				bounceTerrain = self:CreateBounceable(terrain,terrain:getMesh(),false)
				bounceTerrain.timetolive=0
			else 
				device:drop()
				return
			end
		end	

		-- for all other we just generate dummy nodes
		
		local sun=device:getVideoDriver():getTexture("data/sun.jpg")
		local node
		local pos = irr.core.vector3d()
		
		local now = device:getTimer():getTime()

		for i=0,self.MAX_QUBES do

			pos:set(-1000+self.MAX_QUBES*self.QUBE_SPACING*math.rand(),self.QUBE_INITHEIGHT,-1000+self.MAX_QUBES*self.QUBE_SPACING*math.frand())
			node=smgr:addTestSceneNode(self.QUBE_SIZE,0,-1,pos)
			node:setMaterialTexture(0,sun)
			node:setMaterialTexture(1,sun)
			node:setMaterialFlag(irr.video.EMF_FOG_ENABLE,true)
			local bounce=self:CreateBounceable(node,NULL,true)
			bounce.timetolive=now + self.LIVETIME*math.frand()
		end

		-- create a camera
		local camera 
		local keyMap = {}
		keyMap[0].Action = irr.EKA_MOVE_FORWARD
		keyMap[0].KeyCode = irr.KEY_UP
		keyMap[1].Action = irr.EKA_MOVE_FORWARD
		keyMap[1].KeyCode = irr.KEY_KEY_W

		keyMap[2].Action = irr.EKA_MOVE_BACKWARD
		keyMap[2].KeyCode = irr.KEY_DOWN
		keyMap[3].Action = irr.EKA_MOVE_BACKWARD
		keyMap[3].KeyCode = irr.KEY_KEY_S

		keyMap[4].Action = irr.EKA_STRAFE_LEFT
		keyMap[4].KeyCode = irr.KEY_LEFT
		keyMap[5].Action = irr.EKA_STRAFE_LEFT
		keyMap[5].KeyCode = irr.KEY_KEY_A

		keyMap[6].Action = irr.EKA_STRAFE_RIGHT
		keyMap[6].KeyCode = irr.KEY_RIGHT
		keyMap[7].Action = irr.EKA_STRAFE_RIGHT
		keyMap[7].KeyCode = irr.KEY_KEY_D 

		camera = smgr:addCameraSceneNodeFPS(0,100.0,2000.0,-1,keyMap,8)
		camera:setFarValue(100000.0)
		camera:setPosition(irr.core.vector3df(0,3000,0))
		device:getCursorControl():setVisible(false)
		local lastFPS = -1
		
		-- simulation step size
		local stepSize=0.1
		-- available simulation time
		local simtime=0.0

		local timer=device:getTimer()
		local lastFrame=0
		local thisFrame=0

		driver:setFog(irr.video.SColor(0,175,175,195), false, 10.0, 2000.0, 0.00007, false, false)

		while device:run() and not self.End do
			
			if device:isWindowActive() then 
				driver:beginScene(true, true, irr.video.SColor(0,175,175,195))
				driver:setAmbientLight(irr.video.SColor(255,255,255,255))
				smgr:drawAll()
				device:getGUIEnvironment():drawAll()
				driver:endScene()
			end

			local fps = driver:getFPS()
			if lastFPS ~= fps then
				device:setWindowCaption("Using ODE with Irrlicht (Lua) fps:" .. fps .. " triangles:" .. driver:getPrimitiveCountDrawn())
				lastFPS = fps
			end
			
			-- run the simulation
			if self.simulate then
				--updateEntitiesBeforePhysics(); 
				--we do nothing here since there are no user controlled objects in the simulation

				-- build the collision joints for all objects in 'theSpace'
				ode.dSpaceCollide(theSpace,0,self.nearCollisionCallback)
				-- make a simulation step for 'theWorld'
				--dWorldStep(theWorld,0.1f); 
				--optionally use dWorldStepFast1 instead of dWorldStep 
				--when stack overflows occure or speed is important
				ode.dWorldStepFast1(theWorld,self.stepSize,5)
				-- clean up joints from collisions;
				ode.dJointGroupEmpty(theJointGroup)

				-- apply the new positions and rotations to the scenenodes
				self:updateEntitiesAfterPhysics()

				now=device:getTimer():getTime()

				for i,bounce in pairs(self.bounceables) do
					if bounce.body ~= nil and bounce.timetolive < now then
						pos:set(-2000+self.MAX_QUBES*self.QUBE_SPACING*math.frand(),self.QUBE_INITHEIGHT,-2000+self.MAX_QUBES*self.QUBE_SPACING*math.frand())
						--pos.set(7500+1000.0f*frand(),camera->getPosition().Y,7500+1000.0f*frand());
						--
						-- don't let it rotate
						ode.dBodySetAngularVel(bounce.body,0,0,0)

						-- dont't let it move
						ode.dBodySetLinearVel(bounce.body,0,0,0)

						--set new position
						dBodySetPosition(bounce.body,pos.X,pos.Y,pos.Z)
						
						bounce.timetolive=now + self.LIVETIME*math.rand()
					end	
				end
			end	

			if self.reanimate ~= nil then

				for i,bounce in pairs(self.bounceables) do

					-- first lets make sure that we don't reanimate the terrain
					if self.bounceTerrain ~= bounce then
						pos:set(-1000+self.MAX_QUBES*self.QUBE_SPACING*math.rand(),self.QUBE_INITHEIGHT,-1000+self.MAX_QUBES*self.QUBE_SPACING*math.rand())
						-- don't let it rotate
						dBodySetAngularVel(bounce.body,0,0,0)
						-- dont't let it move
						dBodySetLinearVel(bounce.body,0,0,0)
						-- set new position
						dBodySetPosition(bounce.body,pos.X,pos.Y,pos.Z)
					end
				end	
			end
					
			self.reanimate=false
		end

		self:DestroyWorld()
		device:drop()
	end

	--[[
	let all bouncables have the new position and rotation after 
	physics have been applied
	--]]
	void Bounceable::updateEntitiesAfterPhysics(){
		
		irr::core::vector3df pos;
		irr::core::vector3df rot;
		std::list<Bounceable*>::iterator iter=NULL;
		for(iter=bounceables.begin();iter!=bounceables.end();++iter){
			Bounceable* entity=(*iter);
			dGeomID geom=entity->geom;
			if(geom!=0){
				// get the new position of the ODE geometry
				dReal* ode_pos=(dReal*)dGeomGetPosition(geom);
				// set the position at the scenenode
				pos.set((irr::f32)ode_pos[0],(irr::f32)ode_pos[1],(irr::f32)ode_pos[2]);
				entity->node->setPosition(pos);
		
		// get the rotation quaternion
				dQuaternion result;
				dGeomGetQuaternion(geom, result);
				// convert it to eulerangles
				QuaternionToEuler(result,rot);
				// set the rotation 
				entity->node->setRotation(rot);			
			}
		}
	}
	--[[
	Create the global world-space and set some ODE parameters
	--]]

	void Bounceable::CreateWorld(){
		bounceables.clear();
		theWorld=dWorldCreate();
		//dVector3 center={0,0,0};
		//dVector3 extents={64000,2000,64000};
		//theSpace=dQuadTreeSpaceCreate(0,center,extents,4);
		theSpace=dSimpleSpaceCreate(0);
		theJointGroup=dJointGroupCreate(0);
		// play around with these settings
		dWorldSetGravity(theWorld,0,GRAVITY,0);
		
	}
	--[[
	Destroy the global world-space. 
	Attention: if the world and the space are destroied all geoms and bodies still contained are also 
			   destroied. Make shure all Bounceable object are deleted before the world-space is destroied.
	--]]
	void Bounceable::DestroyWorld(){
		// destroy all objects
		std::list<Bounceable*>::iterator iter=NULL;
		for(iter=bounceables.begin();iter!=bounceables.end();++iter){
			Bounceable* bounce=(*iter);
			delete bounce;
		}
		bounceables.clear();
		dJointGroupDestroy(theJointGroup);
		dSpaceDestroy(theSpace);
		dWorldDestroy(theWorld);
		dCloseODE();
	}


	--[[
	Create a new Bounceable
	param n, scenennode for visualisation
	param m, mesh holding the surface of the visual object
	param box, if true the bouncable will have the bounding box as collision geometry,
			   otherwise the mesh will be used to create the collision data.
	--]]

	function Bounceable:CreateBounceable(n,  m, box)

		local b= self:new(theWorld,theSpace,0,0,n,m)

		if not box then
			b:setGeomData(m)
		else
			b:setGeomData()
		end	

		table.insert(self.bounceables, b)
		return b
	end

	--[[
	Set ODE geometry data using the bounding box of the scenenode
	--]]
	function Bounceable:setGeomData()
	
		local box=self.node:getBoundingBox()
		local extend=self.box:getExtend()
		local pos=node:getPosition()
		self.geom=ode.dCreateBox(self.space,extend.X,extend.Y,extend.Z)
		ode.dGeomSetData(self.geom,self)
		ode.dGeomSetPosition(self.geom,pos.X,pos.Y,pos.Z)
		-- create a body for this object
		self.body=ode.dBodyCreate(self.world)
		-- set mass shape
		ode.dMassSetBox(self.mass,1.0,extend.X,extend.Y,extend.Z)
		-- adjust mass weight
		ode.dMassAdjust(self.mass,0.25)
		-- make the body have a mass
		ode.dBodySetMass(self.body,self.mass)
		-- add the body to the geom
		ode.dGeomSetBody(self.geom,self.body)

		ode.dBodySetPosition(self.body,pos.X,pos.Y,pos.Z)
		ode.dBodySetData(self.body,self)
	end

	--[[
	Set ODE geometry data using the mesh structure
	--]]
	
	void Bounceable::setGeomData(irr::scene::IMesh* m){
		if(mesh==NULL || node==NULL) return; // do nothing if the mesh or node is NULL
		int i,j,ci,cif,cv;
		indexcount=0;
		vertexcount=0;
		// count vertices and indices
		for(i=0;i<mesh->getMeshBufferCount();i++){
			irr::scene::IMeshBuffer* mb=mesh->getMeshBuffer(i);
			indexcount+=mb->getIndexCount();
			vertexcount+=mb->getVertexCount();
		}
		// build structure for ode trimesh geom
		vertices=new dVector3[vertexcount];
		indices=new int[indexcount];
		// fill trimesh geom
		ci=0;
		cif=0;
		cv=0;
		for(i=0;i<mesh->getMeshBufferCount();i++){
			irr::scene::IMeshBuffer* mb=mesh->getMeshBuffer(i);
			// fill indices
			irr::u16* mb_indices=mb->getIndices();
			for(j=0;j<mb->getIndexCount();j++){
				indices[ci]=cif+mb_indices[j];
				ci++;
			}
			cif=cif+mb->getVertexCount();
			// fill vertices
			if(mb->getVertexType()==irr::video::EVT_STANDARD){
				irr::video::S3DVertex* mb_vertices=(irr::video::S3DVertex*)mb->getVertices();
				for(j=0;j<mb->getVertexCount();j++){
					vertices[cv][0]=mb_vertices[j].Pos.X;
					vertices[cv][1]=mb_vertices[j].Pos.Y;
					vertices[cv][2]=mb_vertices[j].Pos.Z;
					cv++;
				}	
			}else if(mb->getVertexType()==irr::video::EVT_2TCOORDS){
				irr::video::S3DVertex2TCoords* mb_vertices=(irr::video::S3DVertex2TCoords*)mb->getVertices();
				for(j=0;j<mb->getVertexCount();j++){
					vertices[cv][0]=mb_vertices[j].Pos.X;
					vertices[cv][1]=mb_vertices[j].Pos.Y;
					vertices[cv][2]=mb_vertices[j].Pos.Z;
					cv++;
				}				
			}	
		}
		irr::core::vector3df pos=node->getPosition();
		// build the trimesh data
		dTriMeshDataID data=dGeomTriMeshDataCreate();
		dGeomTriMeshDataBuildSimple(data,(dReal*)vertices,vertexcount,indices,indexcount);
		// build the trimesh geom 
		geom=dCreateTriMesh(space,data,0,0,0);
		// set the geom position 
		dGeomSetPosition(geom,pos.X,pos.Y,pos.Z);
		// lets have a pointer to our bounceable, we could need this in the collision callback
		dGeomSetData(geom,(void*)this); 
		-- in our application we don't want geoms constructed with meshes (the terrain) to have a body
		dGeomSetBody(geom,0); 
	}


	--[[
	The Collision callback gets called every time ODE decides that 2 geoms are close enough to 
	check for intersection points
	--]]
	void Bounceable::nearCollisionCallback(void* data, dGeomID o1, dGeomID o2){
		//CLog::GetSingleton().write(LOG_APP,"CControllerPhysics::nearCollisionCallback");
		int i=0;
		dBodyID b1=dGeomGetBody(o1);
		dBodyID b2=dGeomGetBody(o2);
		if(b1 && b2 && dAreConnectedExcluding(b1,b2,dJointTypeContact))return;

		dContact contact[MAX_CONTACTS];
		for(i=0;i<MAX_CONTACTS;i++){
			contact[i].surface.mode =dContactBounce |
				dContactSoftERP | dContactSoftCFM;
			contact[i].surface.mu = dInfinity;
			//contact[i].surface.slip1 = 0.1; // friction
			//contact[i].surface.slip2 = 0.1;
			contact[i].surface.bounce=0.2f;
			contact[i].surface.soft_erp = 0.5f;
			contact[i].surface.soft_cfm = 0.3f;
		}
		int numc=dCollide(o1,o2,MAX_CONTACTS,&contact[0].geom,sizeof(dContact));

		if(numc>0){
			/*
			// do something usefull with the colliding objects
			if(o1) {
				Bounceable* bounce1=(Bounceable*)dGeomGetData(o1);
			}
			if(o2) {
				Bounceable* bounce2=(Bounceable*)dGeomGetData(o2);
			}
			*/
			for(i=0;i<numc;i++){		
				dJointID c=dJointCreateContact(theWorld,theJointGroup,&contact[i]);
				dJointAttach(c,b1,b2);
			}
		}
	}

	--[[
		convert an ODE style quaternion to irrlicht euler angle rotation 
	   (angels are returned in degrees to match the ISceneNode::setRotation(vector3df &r) convention) 
	   adapted from
	   http://www.euclideanspace.com/maths/geometry/rotations/conversions/quaternionToEuler/index.htm
	--]]
	void Bounceable::QuaternionToEuler(const dQuaternion quaternion,irr::core::vector3df &euler){
		dReal w,x,y,z;
		w=quaternion[0];
		x=quaternion[1];
		y=quaternion[2];
		z=quaternion[3];
		double sqw = w*w;    
		double sqx = x*x;    
		double sqy = y*y;    
		double sqz = z*z; 
		// heading
		euler.Z = (irr::f32) (atan2(2.0 * (x*y + z*w),(sqx - sqy - sqz + sqw))*irr::core::GRAD_PI);
		// bank
		euler.X = (irr::f32) (atan2(2.0 * (y*z + x*w),(-sqx - sqy + sqz + sqw))*irr::core::GRAD_PI);  
		// attitude
		euler.Y = (irr::f32) (asin(-2.0 * (x*z - y*w))*irr::core::GRAD_PI);
	}

	--[[
		convert euler rotation angles to ODE style quaternions 
	   (angles are assumed to be in degrees to match the ISceneNode::getRotation() convention)
	   adapted from 
	   http://www.euclideanspace.com/maths/geometry/rotations/conversions/eulerToQuaternion/index.htm
	--]]
	void Bounceable::EulerToQuaternion(const irr::core::vector3df &euler, dQuaternion quaternion){
		double _heading=euler.Z*irr::core::GRAD_PI2/2.0;
		double _attitude=euler.Y*irr::core::GRAD_PI2/2.0;
		double _bank=euler.X*irr::core::GRAD_PI2/2.0;
		double c1 = cos(_heading);    
		double s1 = sin(_heading);    
		double c2 = cos(_attitude);    
		double s2 = sin(_attitude);    
		double c3 = cos(_bank);    
		double s3 = sin(_bank);
		double c1c2 = c1*c2;    
		double s1s2 = s1*s2;    
		//w
		quaternion[0]=(dReal) (c1c2*c3 + s1s2*s3);
		//x
		quaternion[1]=(dReal) (c1c2*s3 - s1s2*c3);
		//y
		quaternion[2]=(dReal) (c1*s2*c3 + s1*c2*s3);	
		//z
		quaternion[3]=(dReal) (s1*c2*c3 - c1*s2*s3);
	}


};


