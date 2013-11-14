//
// Adapted from Emil Halim's 2D code "http://www.irrforge.org/index.php/Playing_2D_Animation_with_Irrlicht"
// added 'loop' and 'resetLoop' options
// fixed 3d problem
// jjt 

#ifndef _TANIMSPRITESCENENODE_H_
#define _TANIMSPRITESCENENODE_H_

#include "irrlicht.h"

namespace irr
{
namespace scene
{

class TAnimSpriteSceneNode : public ISceneNode
 {
	private:
	core::aabbox3d<f32> Box; 
	video::S3DVertex    Vertices[4];
	u16                 Indices[12]; 
	video::SMaterial    Material; 
	video::ITexture*    Texture;
	f32                 fWidth,fHeight;
	s32                 crntFrm,TotalFrm;
	s32                 stepww,stephh;
	bool                forward;
	bool				loop;
	u32                 Time;
	u32                 oldtick;
	s32                 startFrame,endFrame; 
	f32                 xCoord,yCoord;
	core::matrix4       Ortho;
	ITimer			  *Timer;
	core::dimension2d<s32> Size;
	core::dimension2d<s32> FrameSize;
	f32					Z;

	public: 
	TAnimSpriteSceneNode(ISceneNode* parent, ISceneManager* mgr, s32 id, ITimer *timer):ISceneNode(parent, mgr, id), Timer(timer), Time(50), loop(true), Z(0)
	{
		setVisible(false);
		Material.Wireframe = false;
		Material.Lighting = false;

		u16 ind[] = { 0,1,3, 3,1,2, 1,0,2, 2,0,3 };
		memcpy(Indices,ind,sizeof(u16)*12);

		video::IVideoDriver* driver = SceneManager->getVideoDriver();   
		core::dimension2d<s32> Screensize = driver->getScreenSize(); 

		Ortho(0,0) = (f32) ((double)2/(double)Screensize.Width);
		Ortho(1,0) = 0;
		Ortho(2,0) = 0;
		Ortho(3,0) = 0;

		Ortho(0,1) = 0;
		Ortho(1,1) = (f32) ((double)2/(double)Screensize.Height);
		Ortho(2,1) = 0;
		Ortho(3,1) = 0;

		Ortho(0,2) = 0;
		Ortho(1,2) = 0;
		Ortho(2,2) = 1;
		Ortho(3,2) = 0;

		Ortho(0,3) = 0;
		Ortho(1,3) = 0;
		Ortho(2,3) = 0;
		Ortho(3,3) = 1;
	}     
         
                
	virtual bool Load(char* filename,s32 Ax,s32 Ay,s32 Aw,s32 Ah,s32 frmWidth,s32 frmHeight,bool useClrKey=false)
	{
		video::IVideoDriver* driver = SceneManager->getVideoDriver();   
		core::dimension2d<s32> Screensize = driver->getScreenSize(); 
		float x = (float)frmWidth/2.0f;
		float y = (float)frmHeight/2.0f;
		Vertices[0] = video::S3DVertex(-x,-y,Z, 0,0,0,video::SColor(255,255,255,255),0,1);
		Vertices[1] = video::S3DVertex( x,-y,Z, 0,0,0,video::SColor(255,255,255,255),1,1); 
		Vertices[2] = video::S3DVertex( x, y,Z, 0,0,0,video::SColor(255,255,255,255),1,0);
		Vertices[3] = video::S3DVertex(-x, y,Z, 0,0,0,video::SColor(255,255,255,255),0,0);

		Box.reset(Vertices[0].Pos);
		for (s32 i=1; i<4; ++i)  Box.addInternalPoint(Vertices[i].Pos);
		    
		Texture = driver->getTexture(filename);
		
		if(!Texture)
			return false;

		if (useClrKey==true)
			driver->makeColorKeyTexture(Texture,core::position2d<s32>(0,0));

		Material.MaterialType = video::EMT_TRANSPARENT_ALPHA_CHANNEL;  
		//Material.MaterialType = video::EMT_SOLID;

		Material.Texture1 = Texture;

		Size = Texture->getOriginalSize();
		fWidth  = (float)frmWidth/(float)Size.Width;
		fHeight = (float)frmHeight/(float)Size.Height;
		FrameSize = core::dimension2d<s32>(frmWidth,frmHeight);
		crntFrm = 0;
		stepww = Aw / frmWidth;
		stephh = Ah / frmHeight;
		TotalFrm = stepww * stephh;
		forward = true;
		startFrame = 0; 
		endFrame   = TotalFrm;
		xCoord = (float)Ax/(float)Size.Width;
		yCoord = (float)Ay/(float)Size.Height;
		                
		Vertices[0].TCoords.X = xCoord + 0; 
		Vertices[0].TCoords.Y = yCoord + fHeight;
		Vertices[1].TCoords.X = xCoord + fWidth; 
		Vertices[1].TCoords.Y = yCoord + fHeight;
		Vertices[2].TCoords.X = xCoord + fWidth; 
		Vertices[2].TCoords.Y = yCoord + 0;
		Vertices[3].TCoords.X = xCoord + 0; 
		Vertices[3].TCoords.Y = yCoord + 0; 

		return true;
	}
         
	virtual void PlayForward() {forward = true;}
	virtual void PlayBackward() {forward = false;} 
	virtual void setSpeed(int spd)  {Time = spd;}
	virtual s32 getSpeed() {return Time; }
	virtual void setLoop(bool l)  {loop = l;}
	virtual bool getLoop() {return loop; }
	virtual void resetLoop() 
	{
		if(!loop)
		{
			if(forward)
			{
				crntFrm = startFrame;
			}
			else
			{
				crntFrm = endFrame-1;
			}
		}
	}

	virtual void OnPreRender()
	{ 
		if (IsVisible)    
		{
			SceneManager->registerNodeForRendering(this);
		}

		ISceneNode::OnPreRender();
	}
          
	virtual void setFrame(int n)
	{
		float x = (n % stepww)*fWidth;
		float y = (n / stepww)*fHeight; 
		Vertices[0].TCoords.X = xCoord + x; 
		Vertices[0].TCoords.Y = yCoord + y+fHeight;
		Vertices[1].TCoords.X = xCoord + x+fWidth; 
		Vertices[1].TCoords.Y = yCoord + y+fHeight;
		Vertices[2].TCoords.X = xCoord + x+fWidth; 
		Vertices[2].TCoords.Y = yCoord + y;
		Vertices[3].TCoords.X = xCoord + x; 
		Vertices[3].TCoords.Y = yCoord + y;
	}
         
	virtual void Update()
	{
		if(Timer->getRealTime() - oldtick > Time)
		{  
			oldtick = Timer->getRealTime();
			if (forward) 
			{
				crntFrm++; 
				if (crntFrm > endFrame-1)
				{
					if(loop)
					{
						crntFrm = startFrame;
					}
					else
					{
						crntFrm--;
					}
				}
			}
			else
			{
				crntFrm--;
				if (crntFrm < startFrame)
				{
					if(loop)
					{
						crntFrm = endFrame-1;
					}
					else
					{
						crntFrm++;
					}
				}
			} 
			    
			float x = (crntFrm % stepww)*fWidth;
			float y = (crntFrm / stepww)*fHeight; 
			Vertices[0].TCoords.X = xCoord + x; 
			Vertices[0].TCoords.Y = yCoord + y+fHeight;
			Vertices[1].TCoords.X = xCoord + x+fWidth; 
			Vertices[1].TCoords.Y = yCoord + y+fHeight;
			Vertices[2].TCoords.X = xCoord + x+fWidth; 
			Vertices[2].TCoords.Y = yCoord + y;
			Vertices[3].TCoords.X = xCoord + x; 
			Vertices[3].TCoords.Y = yCoord + y;
		}     
	}     
         
	virtual void setStartEndFrame( s32 st, s32 ed) 
	{ 
		startFrame = st; 
		endFrame   = ed; 
	}
          
	virtual s32 GetMaxFrames() { return TotalFrm; }
           
    virtual void render()
    {      
        video::IVideoDriver* driver = SceneManager->getVideoDriver();		
		core::matrix4 Trns,Scl,Rot,wrld;
        
		Trns.makeIdentity(); 
        Scl.makeIdentity();
        Rot.makeIdentity();
		wrld.makeIdentity();

		Scl.setScale(RelativeScale);
        Rot.setRotationRadians(RelativeRotation);
		Trns.setTranslation(RelativeTranslation);		

		driver->setTransform(video::ETS_VIEW, wrld);
		driver->setTransform(video::ETS_PROJECTION, wrld);
		
		wrld = Trns * Ortho * Rot * Scl;

		driver->setTransform(video::ETS_WORLD, wrld);
		driver->setMaterial(Material);  
        driver->drawIndexedTriangleList(&Vertices[0], 4, &Indices[0], 4);
    }

	virtual const core::aabbox3d<f32>& getBoundingBox() const 
    { 
        return Box; 
    }

    virtual s32 getMaterialCount()
    {
        return 1;
    }

	virtual video::SMaterial& getMaterial(s32 i)
    {
    return Material;
    }

	virtual void setPosition(const core::rect<s32> &rect) 
	{
		//BUG: need to adjust to scaled bitmap size
		//for now we just use square images and avoid the problem.
		//This can probably be done more efficiently using matrices but I'm 
		//a 3d math n00b
		core::position2d<s32> pos = rect.UpperLeftCorner;

		core::dimension2d<s32> dims = SceneManager->getVideoDriver()->getScreenSize();
		
		pos.X += (s32) ((f32)rect.getWidth())/2;
		pos.Y += (s32) ((f32)rect.getHeight())/2;

		f32 f1 = (pos.X  - (f32)dims.Width/2);
		f32 f2 = (pos.Y - (f32)dims.Height/2);

		f32 f3 = f1 / (dims.Width/2);
		f32 f4 = f2 / (dims.Height/2);

		core::vector3df v(f3,-f4,Z);
		ISceneNode::setPosition(v);
	}

	virtual void setScaleToRect(core::rect<s32> rect)
	{	
		s32 Width = rect.getWidth();
		s32 Height = rect.getHeight();

		core::vector3df v((f32)Width/(f32)FrameSize.Width, (f32)Height/(f32)FrameSize.Height, Z);
		ISceneNode::setScale(v);
	}

	virtual const core::dimension2d<s32> getSize()
	{
		return FrameSize;	
	}
 };  
}
}
#endif