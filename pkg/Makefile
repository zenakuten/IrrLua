# Copyright (C) 2002-2005 Josh Turpen, Nikolaus Gebhardt
# This file is part of the "Irrlicht Engine".
# For conditions of distribution and use, see copyright notice in Irrlicht.h

TOLUA=../bin/tolua++
TARGET=IrrLua
# OUTPUT=../../../../lib/Linux
INCLUDES=-I../lua/include -I../tolua++/include -I../../include -I../include
CC=gcc
AR=ar
MYCFLAGS=-fPIC  -O3 -fomit-frame-pointer -ffast-math -DIRRLUA_API="" -DLUA_VERSION_NUM=501

PKGS=aabbox3d.pkg dimension2d.pkg EDriverTypes.pkg heapsort.pkg IAnimatedMeshMD2.pkg IAnimatedMeshMS3D.pkg IAnimatedMesh.pkg \
IAnimatedMeshSceneNode.pkg IAnimatedMeshX.pkg IBillboardSceneNode.pkg ICameraSceneNode.pkg ICursorControl.pkg IDummyTransformationSceneNode.pkg \
IEventReceiver.pkg IFileList.pkg IFileSystem.pkg IGPUProgrammingServices.pkg IGUIButton.pkg IGUICheckBox.pkg IGUIComboBox.pkg IGUIContextMenu.pkg \
IGUIEditBox.pkg IGUIElement.pkg IGUIEnvironment.pkg IGUIFileOpenDialog.pkg IGUIFont.pkg IGUIImage.pkg IGUIInOutFader.pkg IGUIListBox.pkg \
IGUIMeshViewer.pkg IGUIScrollBar.pkg IGUISkin.pkg IGUIStaticText.pkg IGUITabControl.pkg IGUIToolbar.pkg IGUIWindow.pkg IImageLoader.pkg \
IImage.pkg ILightSceneNode.pkg ILogger.pkg IMaterialRenderer.pkg IMeshBuffer.pkg IMeshLoader.pkg IMeshManipulator.pkg IMesh.pkg \
IMetaTriangleSelector.pkg IOSOperator.pkg IParticleAffector.pkg IParticleEmitter.pkg IParticleSystemSceneNode.pkg IQ3LevelMesh.pkg \
IReadFile.pkg irrArray.pkg IrrlichtDevice.pkg irrList.pkg IrrLuaCast.pkg IrrLuaEventReceiver.pkg IrrLua.pkg irrMath.pkg irrString.pkg irrTypes.pkg \
irrXML.pkg ISceneCollisionManager.pkg ISceneManager.pkg ISceneNodeAnimatorCollisionResponse.pkg ISceneNodeAnimator.pkg ISceneNode.pkg \
IShaderConstantSetCallBack.pkg IShadowVolumeSceneNode.pkg IStringParameters.pkg ITerrainSceneNode.pkg ITextSceneNode.pkg ITexture.pkg \
ITimer.pkg ITriangleSelector.pkg IUnknown.pkg IVideoDriver.pkg IVideoModeList.pkg IWriteFile.pkg IXMLReader.pkg IXMLWriter.pkg \
Keycodes.pkg line3d.pkg matrix4.pkg plane3d.pkg position2d.pkg quaternion.pkg rect.pkg S3DVertex.pkg SAnimatedMesh.pkg \
SColor.pkg SExposedVideoData.pkg SIrrCreationParameters.pkg SKeyMap.pkg SLight.pkg SMaterialHelper.pkg SMaterial.pkg SMeshBufferLightMap.pkg \
SMeshBuffer.pkg SMeshBufferTangents.pkg SMesh.pkg SParticle.pkg SViewFrustrum.pkg triangle3d.pkg vector2d.pkg vector3d.pkg

all: $(TARGET)_imp.o IrrLua.o


IrrLua.o: IrrLua.cpp IrrLuaAux.cpp
	$(CC) -c  $(INCLUDES) $(MYCFLAGS) $(CFLAGS) -D_PKG_ IrrLua.cpp IrrLuaAux.cpp

$(TARGET)_imp.o : $(TARGET).pkg  $(PKGS)
	$(TOLUA) -1 -H $(TARGET)_imp.h -o $(TARGET)_imp.cpp $(TARGET).pkg
	$(CC) -I../lua/include -I../tolua++/include -I../../include -I../include $(MYCFLAGS) $(CFLAGS) -D_PKG_ -c $(TARGET)_imp.cpp

#lib$(TARGET).a: 
#	$(TOLUA) -H $(TARGET)_imp.h -o $(TARGET)_imp.cpp $(TARGET).pkg
#	$(CC) -c  $(INCLUDES) $(MYCFLAGS) $(CFLAGS) -D_PKG_ $(TARGET)_imp.cpp
#	$(AR) rc lib$(TARGET).a $(TARGET)_imp.o IrrLua.o
#	$(RANLIB) lib$(TARGET).a 
#
#	$(CP) lib$(TARGET).a $(OUTPUT)

clean:
	rm -f $(TARGET)_imp.o $(TARGET)_imp.cpp $(TARGET)_imp.h IrrLua.o

