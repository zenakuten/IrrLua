-- IrrLua GUI Skin
-- Based on Niko's CGUISkin.cpp, Copyright (C) 2002-2005
-- Copyright (C) 2006, Josh Turpen

require "IrrLua"

CGUISkin = {}

function CGUISkin:init(driver)

	self.Driver = driver
	self.Colors = {}

	self.Colors[irr.gui.EGDC_3D_DARK_SHADOW] =	irr.video.SColor(101,50,50,50)
	self.Colors[irr.gui.EGDC_3D_SHADOW] =		irr.video.SColor(101,130,130,130)
	self.Colors[irr.gui.EGDC_3D_FACE] =			irr.video.SColor(101,210,210,210)
	self.Colors[irr.gui.EGDC_3D_HIGH_LIGHT] =	irr.video.SColor(101,255,255,255)
	self.Colors[irr.gui.EGDC_3D_LIGHT] =		irr.video.SColor(101,210,210,210)
	self.Colors[irr.gui.EGDC_ACTIVE_BORDER] =	irr.video.SColor(101,16,14,115)
	self.Colors[irr.gui.EGDC_ACTIVE_CAPTION] =	irr.video.SColor(101,255,255,255)
	self.Colors[irr.gui.EGDC_APP_WORKSPACE] =	irr.video.SColor(101,100,100,100)
	self.Colors[irr.gui.EGDC_BUTTON_TEXT] =		irr.video.SColor(101,0,0,0)
	self.Colors[irr.gui.EGDC_GRAY_TEXT] =		irr.video.SColor(101,130,130,130)
	self.Colors[irr.gui.EGDC_HIGH_LIGHT] =		irr.video.SColor(101,8,36,107)
	self.Colors[irr.gui.EGDC_HIGH_LIGHT_TEXT] =	irr.video.SColor(101,255,255,255)
	self.Colors[irr.gui.EGDC_INACTIVE_BORDER] =	irr.video.SColor(101,165,165,165)
	self.Colors[irr.gui.EGDC_INACTIVE_CAPTION] = irr.video.SColor(101,210,210,210)
	self.Colors[irr.gui.EGDC_TOOLTIP] =			irr.video.SColor(101,255,255,230)
	self.Colors[irr.gui.EGDC_SCROLLBAR] =		irr.video.SColor(101,230,230,230)
	self.Colors[irr.gui.EGDC_WINDOW] =			irr.video.SColor(101,255,255,255)

	self.Sizes = {}
	self.Sizes[irr.gui.EGDS_SCROLLBAR_SIZE] = 14
	self.Sizes[irr.gui.EGDS_MENU_HEIGHT] = 18
	self.Sizes[irr.gui.EGDS_WINDOW_BUTTON_WIDTH] = 15
	self.Sizes[irr.gui.EGDS_CHECK_BOX_WIDTH] = 18
	self.Sizes[irr.gui.EGDS_MESSAGE_BOX_WIDTH] = 500
	self.Sizes[irr.gui.EGDS_MESSAGE_BOX_HEIGHT] = 200
	self.Sizes[irr.gui.EGDS_BUTTON_WIDTH] = 80
	self.Sizes[irr.gui.EGDS_BUTTON_HEIGHT] = 30

	self.Texts = {}

	self.Texts[irr.gui.EGDT_MSG_BOX_OK] = "OK"
	self.Texts[irr.gui.EGDT_MSG_BOX_CANCEL] = "Cancel"
	self.Texts[irr.gui.EGDT_MSG_BOX_YES] = "Yes"
	self.Texts[irr.gui.EGDT_MSG_BOX_NO] = "No"
end


-- returns default color
function CGUISkin:getColor(color)
	return self.Colors[color]
end

-- sets a default color
function CGUISkin:setColor(which, newColor)
	if which >= 0 and which <= irr.gui.EGDC_COUNT then
		self.Colors[which] = irr.video.SColor(newColor:getAlpha(), newColor:getRed(), newColor:getGreen(), newColor:getBlue())
	end
end

-- returns default color
function CGUISkin:getSize(size)
	return self.Sizes[size]
end


-- sets a default size
function CGUISkin:setSize(which, size)
	if which >= 0 and which <= irr.gui.EGDS_COUNT then
		self.Sizes[which] = size
	end
end

-- returns the default font
function CGUISkin:getFont()
	return self.Font
end


-- sets a default font
function CGUISkin:setFont(font)
	if self.Font then
		self.Font:drop()
	end

	self.Font = font

	if self.Font then
		self.Font:grab()
	end
end

-- Returns a default text. For example for Message box button captions:
-- "OK", "Cancel", "Yes", "No" and so on.
function CGUISkin:getDefaultText(text)
	return self.Texts[text]
end


-- Sets a default text. For example for Message box button captions:
-- "OK", "Cancel", "Yes", "No" and so on.
function CGUISkin:setDefaultText(which, newText)
	self.Texts[which] = newText
end

-- draws a standard 3d button pane
--[[	Used for drawing for example buttons in normal state. 
It uses the colors EGDC_3D_DARK_SHADOW, EGDC_3D_HIGH_LIGHT, EGDC_3D_SHADOW and
EGDC_3D_FACE for this. See EGUI_DEFAULT_COLOR for details. 
\param rect: Defining area where to draw.
\param clip: Clip area.
\param element: Pointer to the element which whiches to draw this. This parameter
is usually not used by ISkin, but can be used for example by more complex 
implementations to find out how to draw the part exactly. 
--]] 
function CGUISkin:draw3DButtonPaneStandard(element, r, clip)

	if not self.Driver then
		return
	end

	local rect = irr.core.rect(r.UpperLeftCorner.X, r.UpperLeftCorner.Y, r.LowerRightCorner.X, r.LowerRightCorner.Y)
	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_DARK_SHADOW), rect, clip)

	rect.LowerRightCorner.X = rect.LowerRightCorner.X - 1
	rect.LowerRightCorner.Y = rect.LowerRightCorner.Y - 1

	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_HIGH_LIGHT), rect, clip)

	rect.UpperLeftCorner.X = rect.UpperLeftCorner.X + 1
	rect.UpperLeftCorner.Y = rect.UpperLeftCorner.Y + 1

	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_SHADOW), rect, clip)

	rect.LowerRightCorner.X = rect.LowerRightCorner.X - 1
	rect.LowerRightCorner.Y = rect.LowerRightCorner.Y - 1

	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_FACE), rect, clip)
end


-- draws a pressed 3d button pane
--[[	Used for drawing for example buttons in pressed state. 
It uses the colors EGDC_3D_DARK_SHADOW, EGDC_3D_HIGH_LIGHT, EGDC_3D_SHADOW and
EGDC_3D_FACE for this. See EGUI_DEFAULT_COLOR for details. 
\param rect: Defining area where to draw.
\param clip: Clip area.
\param element: Pointer to the element which whiches to draw this. This parameter
is usually not used by ISkin, but can be used for example by more complex 
implementations to find out how to draw the part exactly. 
--]]

function CGUISkin:draw3DButtonPanePressed(element, r, clip)

	if not self.Driver then
		return
	end

	local rect = irr.core.rect(r.UpperLeftCorner.X, r.UpperLeftCorner.Y, r.LowerRightCorner.X, r.LowerRightCorner.Y)
	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_HIGH_LIGHT), rect, clip)

	rect.LowerRightCorner.X = rect.LowerRightCorner.X - 1
	rect.LowerRightCorner.Y = rect.LowerRightCorner.Y - 1

	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_DARK_SHADOW), rect, clip)

	rect.UpperLeftCorner.X = rect.UpperLeftCorner.X + 1
	rect.UpperLeftCorner.Y = rect.UpperLeftCorner.Y + 1

	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_SHADOW), rect, clip)

	rect.UpperLeftCorner.X = rect.UpperLeftCorner.X + 1
	rect.UpperLeftCorner.Y = rect.UpperLeftCorner.Y + 1

	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_FACE), rect, clip)
end

-- draws a sunken 3d pane
--[[
 Used for drawing the background of edit, combo or check boxes.
\param element: Pointer to the element which whiches to draw this. This parameter
is usually not used by ISkin, but can be used for example by more complex 
implementations to find out how to draw the part exactly. 
\param bgcolor: Background color.
\param flat: Specifies if the sunken pane should be flat or displayed as sunken 
 deep into the ground.
\param rect: Defining area where to draw.
\param clip: Clip area.	
--]]
function CGUISkin:draw3DSunkenPane(element, bgcolor, flat, fillBackGround, r, clip)
	if not self.Driver then
		return
	end

	local rect = irr.core.rect(r.UpperLeftCorner.X, r.UpperLeftCorner.Y, r.LowerRightCorner.X, r.LowerRightCorner.Y)

	if flat then
		-- draw flat sunken pane
		if fillBackGround then
			
			self.Driver:draw2DRectangle(bgcolor, r, clip)
		end

		rect.LowerRightCorner.Y = rect.UpperLeftCorner.Y + 1
		self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_SHADOW), rect, clip)

		rect.LowerRightCorner.Y = r.LowerRightCorner.Y
		rect.LowerRightCorner.X = rect.UpperLeftCorner.X + 1
		self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_SHADOW), rect, clip)

		rect = irr.core.rect(r.UpperLeftCorner.X, r.UpperLeftCorner.Y, r.LowerRightCorner.X, r.LowerRightCorner.Y)
		rect.UpperLeftCorner.X = rect.LowerRightCorner.X - 1
		self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_HIGH_LIGHT), rect, clip)

		rect = irr.core.rect(r.UpperLeftCorner.X, r.UpperLeftCorner.Y, r.LowerRightCorner.X, r.LowerRightCorner.Y)
		rect.UpperLeftCorner.Y = r.LowerRightCorner.Y - 1
		rect.LowerRightCorner.Y = r.LowerRightCorner.Y
		self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_HIGH_LIGHT), rect, clip)
	else
		-- draw deep sunken pane
		if fillBackGround then
			self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_HIGH_LIGHT), rect, clip)
		end

		rect.LowerRightCorner.X = rect.LowerRightCorner.X - 1
		rect.LowerRightCorner.Y = rect.LowerRightCorner.Y - 1

		self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_SHADOW), rect, clip)

		rect.UpperLeftCorner.X = rect.UpperLeftCorner.X + 1
		rect.UpperLeftCorner.Y = rect.UpperLeftCorner.Y + 1

		self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_LIGHT), rect, clip)

		rect.LowerRightCorner.X = rect.LowerRightCorner.X - 1
		rect.LowerRightCorner.Y = rect.LowerRightCorner.Y - 1

		self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_DARK_SHADOW), rect, clip)

		rect.UpperLeftCorner.X = rect.UpperLeftCorner.X + 1
		rect.UpperLeftCorner.Y = rect.UpperLeftCorner.Y + 1

		self.Driver:draw2DRectangle(bgcolor, rect, clip)
	end
end


-- draws a window background
--[[ Used for drawing the background of dialogs and windows.
\param element: Pointer to the element which whiches to draw this. This parameter
is usually not used by ISkin, but can be used for example by more complex 
implementations to find out how to draw the part exactly. 
\param titleBarColor: Title color.
\param drawTitleBar: True to enable title drawing.
\param rect: Defining area where to draw.
\param clip: Clip area.
\return Returns rect where to draw title bar text. 
--]]
function CGUISkin:draw3DWindowBackground(element, drawTitleBar, titleBarColor, r, cl)

	if not self.Driver then
		return r
	end


	local rect = irr.core.rect(r.UpperLeftCorner.X, r.UpperLeftCorner.Y, r.LowerRightCorner.X, r.LowerRightCorner.Y)

	rect.LowerRightCorner.Y = rect.UpperLeftCorner.Y + 1
	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_HIGH_LIGHT), rect, cl)
	
	rect.LowerRightCorner.Y = r.LowerRightCorner.Y
	rect.LowerRightCorner.X = rect.UpperLeftCorner.X + 1
	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_HIGH_LIGHT), rect, cl)

	rect.UpperLeftCorner.X = r.LowerRightCorner.X - 1
	rect.LowerRightCorner.X = r.LowerRightCorner.X
	rect.UpperLeftCorner.Y = r.UpperLeftCorner.Y
    rect.LowerRightCorner.Y = r.LowerRightCorner.Y
	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_DARK_SHADOW), rect, cl)

	rect.UpperLeftCorner.X = rect.UpperLeftCorner.X - 1
	rect.LowerRightCorner.X = rect.LowerRightCorner.X - 1
	rect.UpperLeftCorner.Y = rect.UpperLeftCorner.Y + 1
	rect.LowerRightCorner.Y = rect.LowerRightCorner.Y - 1
	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_SHADOW), rect, cl)

	rect.UpperLeftCorner.X = r.UpperLeftCorner.X
	rect.UpperLeftCorner.Y = r.LowerRightCorner.Y - 1
	rect.LowerRightCorner.Y = r.LowerRightCorner.Y
	rect.LowerRightCorner.X = r.LowerRightCorner.X
	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_DARK_SHADOW), rect, cl)

	rect.UpperLeftCorner.X = rect.UpperLeftCorner.X + 1
	rect.LowerRightCorner.X = rect.LowerRightCorner.X - 1
	rect.UpperLeftCorner.Y = rect.UpperLeftCorner.Y - 1
	rect.LowerRightCorner.Y = rect.LowerRightCorner.Y - 1
	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_SHADOW), rect, cl)

	rect = irr.core.rect(r.UpperLeftCorner.X, r.UpperLeftCorner.Y, r.LowerRightCorner.X, r.LowerRightCorner.Y)
	rect.UpperLeftCorner.X = rect.UpperLeftCorner.X + 1
	rect.UpperLeftCorner.Y = rect.UpperLeftCorner.Y + 1
	rect.LowerRightCorner.X = rect.LowerRightCorner.X - 2
	rect.LowerRightCorner.Y = rect.LowerRightCorner.Y- 2

	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_FACE), rect, cl)
	
	rect = irr.core.rect(r.UpperLeftCorner.X, r.UpperLeftCorner.Y, r.LowerRightCorner.X, r.LowerRightCorner.Y)
	rect.UpperLeftCorner.X = rect.UpperLeftCorner.X + 2
	rect.UpperLeftCorner.Y = rect.UpperLeftCorner.Y + 2
	rect.LowerRightCorner.X = rect.LowerRightCorner.X - 2
	rect.LowerRightCorner.Y = rect.UpperLeftCorner.Y + self:getSize(irr.gui.EGDS_WINDOW_BUTTON_WIDTH) + 2
	
	if drawTitleBar then
		local c = titleBarColor:getInterpolated(irr.video.SColor(255,0,0,0), 0.2)
		-- fix me
		-- self.Driver:draw2DRectangle(rect, titleBarColor, c, titleBarColor, c, cl)
		self.Driver:draw2DRectangle(irr.video.SColor(255,0,0,255), rect,  cl)
	end

	return rect
end


--! draws a standard 3d menu pane
--[[	Used for drawing for menus and context menus. 
It uses the colors EGDC_3D_DARK_SHADOW, EGDC_3D_HIGH_LIGHT, EGDC_3D_SHADOW and
EGDC_3D_FACE for this. See EGUI_DEFAULT_COLOR for details. 
\param element: Pointer to the element which whiches to draw this. This parameter
is usually not used by ISkin, but can be used for example by more complex 
implementations to find out how to draw the part exactly. 
\param rect: Defining area where to draw.
\param clip: Clip area.	
--]]

function CGUISkin:draw3DMenuPane(element,  r,  clip)
	if not self.Driver then
		return
	end

	-- in this skin, this is exactly what non pressed buttons look like,
	-- so we could simply call
	-- draw3DButtonPaneStandard(element, rect, clip)	
	-- here.
	-- but if the skin is transparent, this doesn't look that nice. So
	-- We draw it a little bit better, with some more draw2DRectangle calls,
	-- but there aren't that much menus visible anyway.

	local rect = irr.core.rect(r.UpperLeftCorner.X, r.UpperLeftCorner.Y, r.LowerRightCorner.X, r.LowerRightCorner.Y)
	rect.LowerRightCorner.Y = rect.UpperLeftCorner.Y + 1
	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_HIGH_LIGHT), rect, clip)

	rect.LowerRightCorner.Y = r.LowerRightCorner.Y
	rect.LowerRightCorner.X = rect.UpperLeftCorner.X + 1
	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_HIGH_LIGHT), rect, clip)

	rect.UpperLeftCorner.X = r.LowerRightCorner.X - 1
	rect.LowerRightCorner.X = r.LowerRightCorner.X
	rect.UpperLeftCorner.Y = r.UpperLeftCorner.Y
    rect.LowerRightCorner.Y = r.LowerRightCorner.Y
	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_DARK_SHADOW), rect, clip)

	rect.UpperLeftCorner.X = rect.UpperLeftCorner.X - 1
	rect.LowerRightCorner.X = rect.LowerRightCorner.X - 1
	rect.UpperLeftCorner.Y = rect.UpperLeftCorner.Y + 1
	rect.LowerRightCorner.Y = rect.LowerRightCorner.Y - 1
	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_SHADOW), rect, clip)

	rect.UpperLeftCorner.X = r.UpperLeftCorner.X
	rect.UpperLeftCorner.Y = r.LowerRightCorner.Y - 1
	rect.LowerRightCorner.Y = r.LowerRightCorner.Y
	rect.LowerRightCorner.X = r.LowerRightCorner.X
	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_DARK_SHADOW), rect, clip)

	rect.UpperLeftCorner.X = rect.UpperLeftCorner.X + 1
	rect.LowerRightCorner.X = rect.LowerRightCorner.X - 1
	rect.UpperLeftCorner.Y = rect.UpperLeftCorner.Y - 1
	rect.LowerRightCorner.Y = rect.LowerRightCorner.Y - 1
	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_SHADOW), rect, clip)

	rect = irr.core.rect(r.UpperLeftCorner.X, r.UpperLeftCorner.Y, r.LowerRightCorner.X, r.LowerRightCorner.Y)
	rect.UpperLeftCorner.X = rect.UpperLeftCorner.X + 1
	rect.UpperLeftCorner.Y = rect.UpperLeftCorner.Y + 1
	rect.LowerRightCorner.X = rect.LowerRightCorner.X - 2
	rect.LowerRightCorner.Y = rect.LowerRightCorner.Y - 2

	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_FACE), rect, clip)
end


-- draws a standard 3d tool bar
--[[
	Used for drawing for toolbars and menus.
\param element: Pointer to the element which whiches to draw this. This parameter
is usually not used by ISkin, but can be used for example by more complex 
implementations to find out how to draw the part exactly. 
\param rect: Defining area where to draw.
\param clip: Clip area.	
--]]
function CGUISkin:draw3DToolBar(element, r,  clip)

	if not self.Driver then
		return
	end

	local rect = irr.core.rect(r.UpperLeftCorner.X, r.UpperLeftCorner.Y, r.LowerRightCorner.X, r.LowerRightCorner.Y)

	rect.UpperLeftCorner.X = r.UpperLeftCorner.X
	rect.UpperLeftCorner.Y = r.LowerRightCorner.Y - 1
	rect.LowerRightCorner.Y = r.LowerRightCorner.Y
	rect.LowerRightCorner.X = r.LowerRightCorner.X
	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_SHADOW), rect, clip)

	rect = irr.core.rect(r.UpperLeftCorner.X, r.UpperLeftCorner.Y, r.LowerRightCorner.X, r.LowerRightCorner.Y)
	rect.LowerRightCorner.Y = rect.LowerRightCorner.Y - 1

	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_FACE), rect, clip)
end

-- draws a tab button
--[[	Used for drawing for tab buttons on top of tabs.
\param element: Pointer to the element which whiches to draw this. This parameter
is usually not used by ISkin, but can be used for example by more complex 
implementations to find out how to draw the part exactly. 
\param active: Specifies if the tab is currently active.
\param rect: Defining area where to draw.
\param clip: Clip area.
--]]	
function CGUISkin:draw3DTabButton(element, active, frameRect, clip)
	if not self.Driver then
		return
	end

	local tr = frameRect

	tr.LowerRightCorner.X = tr.LowerRightCorner.X - 2
	tr.LowerRightCorner.Y = tr.UpperLeftCorner.Y + 1
	tr.UpperLeftCorner.X = tr.UpperLeftCorner.X + 1
	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_HIGH_LIGHT), tr, clip)

	-- draw left highlight
	tr = irr.core.rect(frameRect.UpperLeftCorner.X, frameRect.UpperLeftCorner.Y, frameRect.LowerRightCorner.X, frameRect.LowerRightCorner.Y)
	tr.LowerRightCorner.X = tr.UpperLeftCorner.X + 1
	tr.UpperLeftCorner.Y = tr.UpperLeftCorner.Y + 1
	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_HIGH_LIGHT), tr, clip)

	-- draw grey background
	tr = irr.core.rect(frameRect.UpperLeftCorner.X, frameRect.UpperLeftCorner.Y, frameRect.LowerRightCorner.X, frameRect.LowerRightCorner.Y)
	tr.UpperLeftCorner.X = tr.UpperLeftCorner.X + 1
	tr.UpperLeftCorner.Y = tr.UpperLeftCorner.Y + 1
	tr.LowerRightCorner.X = tr.LowerRightCorner.X - 2
	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_FACE), tr, clip)

	-- draw right middle gray shadow
	tr.LowerRightCorner.X = tr.LowerRightCorner.X + 1
	tr.UpperLeftCorner.X = tr.LowerRightCorner.X - 1
	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_SHADOW), tr, clip)

	tr.LowerRightCorner.X = tr.LowerRightCorner.X + 1
	tr.UpperLeftCorner.X = tr.UpperLeftCorner.X + 1
	tr.UpperLeftCorner.Y = tr.UpperLeftCorner.Y + 1
	self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_DARK_SHADOW), tr, clip)
end


-- draws a tab control body
--[[	\param element: Pointer to the element which whiches to draw this. This parameter
is usually not used by ISkin, but can be used for example by more complex 
implementations to find out how to draw the part exactly. 
\param border: Specifies if the border should be drawn.
\param background: Specifies if the background should be drawn.
\param rect: Defining area where to draw.
\param clip: Clip area.	
--]]
function CGUISkin:draw3DTabBody(element, border, background, rect, clip)

	if not self.Driver then
		return
	end

	local tr = rect

	-- draw border.
	if border then
		-- draw left hightlight
		tr.UpperLeftCorner.Y = tr.UpperLeftCorner.Y + self:getSize(irr.gui.EGDS_BUTTON_HEIGHT) + 2
		tr.LowerRightCorner.X = tr.UpperLeftCorner.X + 1
		self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_HIGH_LIGHT), tr, clip)

		-- draw right shadow
		tr.UpperLeftCorner.X = rect.LowerRightCorner.X - 1
		tr.LowerRightCorner.X = tr.UpperLeftCorner.X + 1
		self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_SHADOW), tr, clip)

		-- draw lower shadow
		tr = irr.core.rect(rect.UpperLeftCorner.X, rect.UpperLeftCorner.Y, rect.LowerRightCorner.X, rect.LowerRightCorner.Y)
		tr.UpperLeftCorner.Y = tr.LowerRightCorner.Y - 1
		self.Driver:draw2DRectangle(self:getColor(EGDC_3D_SHADOW), tr, clip)
	end

	if background then
		tr = irr.core.rect(rect.UpperLeftCorner.X, rect.UpperLeftCorner.Y, rect.LowerRightCorner.X, rect.LowerRightCorner.Y)
		tr.UpperLeftCorner.Y = tr.UpperLeftCorner.Y + self:getSize(irr.gui.EGDS_BUTTON_HEIGHT) + 2
		tr.LowerRightCorner.X =tr.LowerRightCorner.X - 1
		tr.UpperLeftCorner.X =tr.UpperLeftCorner.X + 1
		tr.LowerRightCorner.Y =tr.LowerRightCorner.Y - 1

		self.Driver:draw2DRectangle(self:getColor(irr.gui.EGDC_3D_FACE), tr, clip)
	end
end

