// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the CUSTOMSCENENODE_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// CUSTOMSCENENODE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifndef _CUSTOMSCENENODE_H_
#define _CUSTOMSCENENODE_H_
#ifdef _WIN32
#ifdef CUSTOMSCENENODE_EXPORTS
#define CUSTOMSCENENODE_API __declspec(dllexport)
#else
#define CUSTOMSCENENODE_API __declspec(dllimport)
#endif
#else
#define CUSTOMSCENENODE_API
#endif

#include "irrlicht.h"
using namespace irr;

#include "IrrLua.h"


extern "C" {
CUSTOMSCENENODE_API int luaopen_CustomSceneNode(lua_State *l);
}


/*
Here comes the most sophisticated part of this tutorial: 
The class of our very own custom scene node. To keep it simple,
our scene node will not be an indoor portal renderer nor a terrain
scene node, but a simple tetraeder, a 3d object consiting of 4
connected vertices, which only draws itself and does nothing more.

To let our scene node be able to be inserted into the Irrlicht 
Engine scene, the class we create needs only be derived from the
ISceneNode class and has to override some methods.
*/

/*

When importing libraries into IrrLua, it is recommended that you
always use a namespace.  When the library is loaded, the classes
end up polluting the global namespace.  If the classes are inside a 
namespace, tolua++ puts all the classes into a lua table with the same
name as the namespace. 

For an example of good/proper namespacing, see the Irrlicht
engine header files.  

*/

namespace MyProject
{

class CSampleSceneNode : public scene::ISceneNode
{

	/*
	First, we declare some member variables. Some space to
	hold data for our tetraeder: The bounding box, 4 vertices, and
	the material of the tetraeder.
	*/
	core::aabbox3d<f32> Box;
	video::S3DVertex Vertices[4];
	video::SMaterial Material;


	/*
	The parameters of the constructor specify the parent of the scene node,
	a pointer to the scene manager, and an id of the scene node.
	In the constructor itself, we call the parent classes constructor,
	set some properties of the material we use to draw the scene nodem and 
	create the 4 vertices of the tetraeder we will draw later.
	*/

public:

	CSampleSceneNode(scene::ISceneNode* parent, scene::ISceneManager* mgr, s32 id)
		: scene::ISceneNode(parent, mgr, id)
	{
		Material.Wireframe = false;
		Material.Lighting = false;

		Vertices[0] = video::S3DVertex(0,0,10, 1,1,0, video::SColor(255,0,255,255), 0, 1);
		Vertices[1] = video::S3DVertex(10,0,-10, 1,0,0, video::SColor(255,255,0,255), 1, 1);
		Vertices[2] = video::S3DVertex(0,20,0, 0,1,1, video::SColor(255,255,255,0), 1, 0);
		Vertices[3] = video::S3DVertex(-10,0,-10, 0,0,1, video::SColor(255,0,255,0), 0, 0);

	/*
	The Irrlicht Engine needs to know the bounding box of your scene node. 
	It will use it for doing automatic culling and other things. Hence we
	need to create a bounding box from the 4 vertices we use. 
	If you do not want the engine to use the box for automatic culling, 
	and/or don't want to create the box, you could also write
	AutomaticCullingEnabled = false;.
	*/
		Box.reset(Vertices[0].Pos);
		for (s32 i=1; i<4; ++i)
			Box.addInternalPoint(Vertices[i].Pos);
	}


	/*
	Before it is drawn, the OnPreRender() method of every scene node in the scene 
	is called by the scene manager. If the scene node wishes to draw itself,
	it may register itself in the scene manager to be drawn. This is necessary to
	tell the scene manager when it should call the ::render method. For example
	normal scene nodes render their content one after another, while
	stencil buffer shadows would like to be drawn after all other scene nodes. And
	camera or light scene nodes need to be rendered before all other scene 
	nodes (if at all).
	So here we simply register the scene node to get render normally. If we would like
	to let it be rendered like cameras or light, we would have to call
	SceneManager->registerNodeForRendering(this, SNRT_LIGHT_AND_CAMERA);
	After this, we call the OnPreRender-method of the base class ISceneNode,
	which simply lets also all the child scene nodes of this node register themselves.
	*/
	virtual void OnPreRender()
	{
		if (IsVisible)
			SceneManager->registerNodeForRendering(this);

		ISceneNode::OnPreRender();
	}

	/*
	In the render() method most of the interesting stuff happenes: The
	Scene node renders itself. We override this method and draw the
	tetraeder.
	*/
	virtual void render()
	{
		u16 indices[] = {	0,2,3, 2,1,3, 1,0,3, 2,0,1	};
		video::IVideoDriver* driver = SceneManager->getVideoDriver();

		driver->setMaterial(Material);
		driver->setTransform(video::ETS_WORLD, AbsoluteTransformation);
		driver->drawIndexedTriangleList(&Vertices[0], 4, &indices[0], 4);
	}

	/*
	At least, we create three small additional methods.
	GetBoundingBox() returns the bounding box of this scene node, 
	GetMaterialCount() returns the amount of materials in this scene node
	(our tetraeder only has one material), and getMaterial() returns the
	material at an index. Because we have only one material here, we can
	return the only one meterial, assuming that no one ever calls getMaterial()
	with an index greater than 0.
	*/
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
};

} /* MyProject namespace */

#endif /* _CUSTOMSCENENODE_H_ */
