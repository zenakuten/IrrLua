require "IrrLua" 

-- This is entirely a hack.  Use the wxLua interpreter to run it.  
-- Since event handling is not accessible through wxLua, we cannot 
-- create a custom message loop and instead rely on refresh tricks.  

function main()
	
	if wx == nil then
		print("Sorry, you must use the wxLua interpreter to run this example")
		return 1
	end

    local Close_ID  = 4  
    local Text_ID    = 5
    local dialog = wx.wxDialog(wx.wxNull, 
                               -1, 
                               "IrrLua - wxLua example", 
                               wx.wxPoint(0, 0), 
                               wx.wxSize(230, 250))
    
    local win = wx.wxWindow(dialog, -1, wx.wxPoint(30,50), wx.wxSize(150,150), 0, "Irrlicht")
    local dlgTxt = wx.wxStaticText(dialog,  Text_ID,  "This is IrrLua running in a wxLua window",    wx.wxPoint(10,  12))

    dialog:ConnectEvent(wx.wxEVT_CLOSE_WINDOW,
                       function (event)
                            dialog:Destroy()
                            event:Skip()
                       end)


	-- Create irrlicht stuff

	local installPath = "../../../"	
	local param = irr.SIrrlichtCreationParameters()

	param.WindowId = irr.cast.void_to_Number(win:GetHandle())
	param.DriverType = irr.video.EDT_OPENGL
	param.WindowSize = irr.core.dimension2d(200,200)
	device = irr.createDeviceEx(param)

	-- setup a simple 3d scene
	smgr = device:getSceneManager()
	driver = device:getVideoDriver()

	local cam = smgr:addCameraSceneNode()
	cam:setTarget(irr.core.vector3d(0,0,0))

	local anim = smgr:createFlyCircleAnimator(irr.core.vector3d(0,10,0), 30)
	cam:addAnimator(anim)
	anim:drop()

	local cube = smgr:addTestSceneNode()
	
	cube:setMaterialTexture(0, driver:getTexture(installPath .. "media/rockwall.bmp"))

	smgr:addSkyBoxSceneNode(
	driver:getTexture(installPath .. "media/irrlicht2_up.jpg"),
	driver:getTexture(installPath .. "media/irrlicht2_dn.jpg"),
	driver:getTexture(installPath .. "media/irrlicht2_lf.jpg"),
	driver:getTexture(installPath .. "media/irrlicht2_rt.jpg"),
	driver:getTexture(installPath .. "media/irrlicht2_ft.jpg"),
	driver:getTexture(installPath .. "media/irrlicht2_bk.jpg"))
	
    dialog:Centre()
    dialog:Show(wx.TRUE)
    
    -- From wxLua event.i source
    --///////////////////////////////////////////////////////////////////////////////
    --// wxEvtHandler - event handling is not accessible through wxLua

	while device:run() do
		dialog:Refresh()
		driver:beginScene(true, true, nil)
		smgr:drawAll()
		driver:endScene()
	end		
end

main()

