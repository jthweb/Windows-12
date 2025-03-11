-----------------------------------------------------------------------
-----------------------------------------------------------------------
---						RAINCOLORS.LUA						  v1.2	---
---	 		 A color manipulation library for Rainmeter				---
---					 Follow the discussion at:						---
---	   https://forum.rainmeter.net/viewtopic.php?t=43717#p222042	---
-----------------------------------------------------------------------
-----------------------------------------------------------------------
--- Important Note: Brightness here refers to Relative Luminance,	---
--- DO NOT confuse with Lightness on HSL.							---
--- HSB is forbidden here, don't even dare to mention it.			---
-----------------------------------------------------------------------
-----------------------------------------------------------------------
--- 						HOW TO USE								---
--- --------------------------------------------------------------- ---
--- All functions that have "color" accept both HEX and RGB.		---
--- Colors have to be entered with '' like '255,170,0' or 'FFAA00'	---
--- e.g. RGB2HSL('255,170,0') or RGB2HSL('FFAA00')					---
--- All the other parameters have to be entered without ''			---
--- eg. shiftSat('255,170,0', 50) or shiftSat('FFAA00', 50)	or		---
--- rgb2hsl(255,170,0).												---
--- 																---
--- Decimals are allowed. Most returns are rounded to 2 decimal 	---
--- places for better accuracy. Except for "Color Theory" and 		---
--- "Generation" sections which return whole numbers.				---
--- To always return whole numbers, replace "2" with "0" -			---
--- ---	on lines 100 and 128.										---
-----------------------------------------------------------------------
-----------------------------------------------------------------------
-----------------------------------------------------------------------
---						 	INTERNAL USE							---
---		These are used internally by all the other functions		---
---	 It is recommended to use those on Conversion section instead	---
-----------------------------------------------------------------------
-----------------------------------------------------------------------
---	 rounds a number to any optional number of decimal places (ndp)	---
---	---------------------------------------------------------------	---
---	input number,ndp 												---
---	return number													---
-----------------------------------------------------------------------
function round(number, ndp)
	local mult = 10 ^ (ndp or 0)
	if number >= 0 then
		return math.floor(number * mult + 0.5) / mult
	else
		return math.ceil(number * mult - 0.5) / mult
	end
end

-----------------------------------------------------------------------
---	Converts HEX to RGB	(internal use)								---
---	---------------------------------------------------------------	---
---	input 'hex'			'#cccccc' or 'cccccc'						---
---	return r,g,b				[0,255]								---
-----------------------------------------------------------------------
function hex2rgb(HEX)
		HEX = HEX:gsub('#','')
	if(string.len(HEX) == 3) then
		return tonumber('0x'..HEX:sub(1,1)) * 17, tonumber('0x'..HEX:sub(2,2)) * 17, tonumber('0x'..HEX:sub(3,3)) * 17
	elseif(string.len(HEX) == 6) then
		return tonumber('0x'..HEX:sub(1,2)), tonumber('0x'..HEX:sub(3,4)), tonumber('0x'..HEX:sub(5,6))
	else
		return 0, 0, 0
	end
end
-----------------------------------------------------------------------
---	Converts RGB to HEX	(internal use)								---
---	---------------------------------------------------------------	---
---	input 'r,g,b'				  [0,255]							---
---	return HEX			   		  cccccc							---
-----------------------------------------------------------------------
function rgb2hex(color)
	local r, g, b = split(color)
	return string.upper(string.format('%.2x%.2x%.2x', r, g, b))
end
-----------------------------------------------------------------------
---	Converts RGB to HSL	(internal use)								---
---	---------------------------------------------------------------	---
---	input r, g, b					[0,255]							---
---	return h, s, l					[0,1]							---
-----------------------------------------------------------------------
function rgb2hsl(r, g, b)
	local ndp = 4
    local r, g, b = r / 255, g / 255, b / 255
    local max, min = math.max(r, g, b), math.min(r, g, b)
    local h, s, l
    local l = (max + min) / 2
		if max == min then
        h, s = 0, 0
		else
        local d = max - min
        s = l > 0.5 and d / (2 - max - min) or d / (max + min)
        if max == r then
            h = (g - b) / d + (g < b and 6 or 0)
        elseif max == g then
            h = (b - r) / d + 2
        else
            h = (r - g) / d + 4
        end
        h = h / 6
    end
	local h, s, l = round(h*360, ndp), round(s*100, ndp), round(l*100, ndp)
    return h, s, l
end
-----------------------------------------------------------------------
--- Converts HSL to RGB	(internal use)								---
---	---------------------------------------------------------------	---
---	param h,s,l						[0,1]							---
---	return r,g,b					[0,255]							---
-----------------------------------------------------------------------
function hsl2rgb(h, s, l)
	local ndp = 4
	local h, s, l = h / 360, s / 100, l / 100
    if s == 0 then
        local gray = round(l * 255)
        return gray, gray, gray
    end
    local function hue2rgb(p, q, t)
        if t < 0 then t = t + 1 end
        if t > 1 then t = t - 1 end
        if t < 1/6 then return p + (q - p) * 6 * t end
        if t < 1/2 then return q end
        if t < 2/3 then return p + (q - p) * (2/3 - t) * 6 end
        return p
    end
    local q = l < 0.5 and l * (1 + s) or l + s - l * s
    local p = 2 * l - q
    local r = hue2rgb(p, q, h + 1/3)
    local g = hue2rgb(p, q, h)
    local b = hue2rgb(p, q, h - 1/3)
	local r, g, b = round(r*255, ndp), round(g*255, ndp), round(b*255, ndp)
    return r, g, b
end
-----------------------------------------------------------------------
---	Splits rgb string into r,g,b (internal use)						---
---	---------------------------------------------------------------	---
---	input 'r,g,b'		[0,255]										---
---	return r,g,b		[0,255]										---
-----------------------------------------------------------------------
function split(color)
    local colorType = rgbORhex(color)
    if colorType == 'HEX' then
        r, g, b = hex2rgb(color)
    else
        color = string.gsub(color, ' ', '')
        r, g, b = string.match(color, '([%d.]+),([%d.]+),([%d.]+)')
    end
    return tonumber(r), tonumber(g), tonumber(b)
end
-----------------------------------------------------------------------
---	Returns "RGB" or "HEX"	(internal use)							---
---	---------------------------------------------------------------	---
---	input 'r,g,b' or 'HEX'		[0,255]								---
---	return RGB or HEX				N/A								---
-----------------------------------------------------------------------
function rgbORhex(color)
    if color:match('^#?[A-Fa-f0-9]+$') then
        return 'HEX'
    elseif color:match('^%d+,%s*%d+,%s*%d+$') then
        return 'RGB'
    else
        return 'Not a supported color'
    end
end
-----------------------------------------------------------------------
---	Returns color brightness										---
---	---------------------------------------------------------------	---
---	Brightness refers to "Relative luminance"						---
--- https://www.w3.org/TR/WCAG20/relative-luminance.xml				---
---	input 'r,g,b'			[0,255]									---
---	return Brightness  		[0,1]									---
-----------------------------------------------------------------------
function brightness(color)
	local r, g, b = split(color)
    local R, G, B = tonumber(r) / 255, tonumber(g) / 255, tonumber(b) / 255
    local adjust = function(c)
        if c <= 0.03928 then
            return c / 12.92
        else
            return ((c + 0.055) / 1.055) ^ 2.4
        end
    end   
    local brightness = round(0.2126 * adjust(R) + 0.7152 * adjust(G) + 0.0722 * adjust(B), 4)
    return brightness
end
-----------------------------------------------------------------------
---	Returns contrast ratio between 2 colors							---
---	---------------------------------------------------------------	---
---	more info:														---
---  https://www.w3.org/TR/2016/NOTE-WCAG20-TECHS-20161007/G18		---
---	input 'r,g,b','r,g,b'	[0,255]									---
---	return contrastRatio	[1,21]									---
-----------------------------------------------------------------------
function contrastRatio(color1,color2)
	local L1 = brightness(color1)
	local L2 = brightness(color2)
	local contrastRatio
		if L1 > L2 then 
			contrastRatio = (L1+0.05)/(L2+0.05)
		else 
			contrastRatio = (L2+0.05)/(L1+0.05) 
		end
	return round(contrastRatio,4)
end
-----------------------------------------------------------------------
---					   		  CONVERSION							---
---	---------------------------------------------------------------	---
---	 				These Functions convert colors				 	---
---	   	  		All inputs are 'r,g,b', 'h,s,l' or 'HEX' 			---
---	   	  	All returns are rounded to 2 decimal places		 		---
-----------------------------------------------------------------------
-----------------------------------------------------------------------
-----------------------------------------------------------------------
---	Converts RGB or HEX to HSL										---
---	---------------------------------------------------------------	---
---	input 'r,g,b' or 'HEX'		 [0,255] or cccccc					---
---	return h,s,l			[0,360],[0,100]							---
-----------------------------------------------------------------------
function RGB2HSL(color,ndp)
	local ndp = ndp or 4
	local r, g, b = split(color)
	local h, s, l = rgb2hsl(r, g, b)
    return string.format('%s,%s,%s', round(h,ndp), round(s,ndp), round(l,ndp))
end
-----------------------------------------------------------------------
---	Converts HSL to RGB												---
---	---------------------------------------------------------------	---
---	input 'h,s,l'		cccccc										---
---	return r,g,b		[0,255]										---
-----------------------------------------------------------------------
function HSL2RGB(HSL, ndp)
	local ndp = ndp or 4
    local h, s, l = split(HSL)
    local r, g, b = hsl2rgb(h,s,l)
    return string.format('%s,%s,%s', round(r,ndp), round(g,ndp), round(b,ndp))
end
-----------------------------------------------------------------------
---	Converts RGB to HEX												---
---	---------------------------------------------------------------	---
---	input 'r,g,b'		[0,255]										---
---	return HEX			cccccc										---
-----------------------------------------------------------------------
function RGB2HEX(color)
    local colorType = rgbORhex(color)
	local HEX
    if colorType == 'HEX' then
        HEX = color
    else
        HEX = rgb2hex(color)
    end
    return HEX
end
-----------------------------------------------------------------------
---	Converts HEX to RGB												---
---	---------------------------------------------------------------	---
---	input 'HEX'			cccccc										---
---	return r,g,b		[0,255]										---
-----------------------------------------------------------------------
function HEX2RGB(HEX)
    local r, g, b = split(HEX)
    return string.format('%s,%s,%s', r, g, b)
end
-----------------------------------------------------------------------
---					   		 SPLITTING								---
---	---------------------------------------------------------------	---
---	 			These Functions return a single value. 				---
---	   	  			All inputs are 'r,g,b' or 'HEX'			 		---
---	   	  	All returns are rounded to 2 decimal places		 		---
-----------------------------------------------------------------------
-----------------------------------------------------------------------
-----------------------------------------------------------------------
---	Return h,s,l or r,g,b as single values							---
---	---------------------------------------------------------------	---
---	All functions below return only one value.						---
---	input 'r,g,b' or 'HEX'											---
---	return h,s,l or r,g,b		[0,360], [0,100] or [0,255]			---
-----------------------------------------------------------------------
---Returns hue
function h(color,ndp)
	local ndp = ndp or 4
	local r, g, b = split(color)
	local h,s,l = rgb2hsl(r, g, b)
	return round(h,ndp)
end
---Returns saturation
function s(color,ndp)
	local ndp = ndp or 4
	local r, g, b = split(color)
	local h,s,l = rgb2hsl(r, g, b)
	return round(s,ndp)
end

---Returns lightness
function l(color,ndp)
	local ndp = ndp or 4
	local r, g, b = split(color)
	local h,s,l = rgb2hsl(r, g, b)
	return round(l,ndp)
end
---Returns red
function red(color,ndp)
	local ndp = ndp or 4
	local r, g, b = split(color)
	return round(r,ndp)
end
---Returns green
function green(color,ndp)
	local ndp = ndp or 4
	local r, g, b = split(color)
	return round(g,ndp)
end
---Returns blue
function blue(color,ndp)
	local ndp = ndp or 4
	local r, g, b = split(color)
	return round(b,ndp)
end
-----------------------------------------------------------------------
---							MANIPULATION							---
---	---------------------------------------------------------------	---
---	 	These Functions manipulate colors to achieve any effect.	---
---	 				All inputs are 'r,g,b' or 'HEX'					---
-----------------------------------------------------------------------
-----------------------------------------------------------------------
-----------------------------------------------------------------------
---	Sets Hue to new Hue												---
---	---------------------------------------------------------------	---
---	input 'r,g,b', h		[0,255] , [0,360]						---
---	return r,g,b			[0,255]									---
-----------------------------------------------------------------------
function setHue(color, newHue)                                         
	local r, g, b = split(color)
	local h, s, l = rgb2hsl(r, g, b)
    local h = newHue
    local r, g, b = hsl2rgb(h, s, l)
    return string.format('%s,%s,%s', r, g, b)
end
-----------------------------------------------------------------------
---	Sets Saturation to new Saturation								---
---	---------------------------------------------------------------	---
---	input 'r,g,b', s		[0,255]	, [0,100]						---
---	return r,g,b			[0,255]									---
-----------------------------------------------------------------------
function setSat(color, newSat)
	local r, g, b = split(color)
	local h, s, l = rgb2hsl(r, g, b)
    local s = newSat
    local r, g, b = hsl2rgb(h, s, l)
    return string.format('%s,%s,%s', r, g, b)
end
-----------------------------------------------------------------------
---	Sets Lightness to new Lightness									---
---	---------------------------------------------------------------	---
---	input 'r,g,b', l		[0,255]	, [0,100]						---
---	return r,g,b			[0,255]									---
-----------------------------------------------------------------------
function setLight(color, newLight)
	local r, g, b = split(color)
	local h, s, l = rgb2hsl(r, g, b)
    local l = newLight
    local r, g, b = hsl2rgb(h, s, l)
    return string.format('%s,%s,%s', r, g, b)
end
-----------------------------------------------------------------------
---	Shifts Hue by a given angle or 60 if no angle specified			---
---	---------------------------------------------------------------	---
---	input 'r,g,b', angle 	[0,255],[-360,360]						---
---	return r,g,b 			[0,255]									---
-----------------------------------------------------------------------
function shiftHue(color, angle)
	local r, g, b = split(color)
	local h, s, l = rgb2hsl(r, g, b)
	local angle = angle or 60
	local h = (h + angle) % 360
	local r, g, b = hsl2rgb(h, s, l)
    return string.format('%s,%s,%s', r, g, b)
end
-----------------------------------------------------------------------
--- Shifts saturation by a given amount, or 30. 					---
---	---------------------------------------------------------------	---
---	input 'r,g,b', amount   [0,255], [-100,100]						---
---	return r,g,b			[0,255]									---
-----------------------------------------------------------------------
function shiftSat(color, amount)
	local r, g, b = split(color)
	local h, s, l = rgb2hsl(r, g, b)
	local amount = amount or 30
    local s = math.max(0, math.min(100, (s + amount)))
    local r, g, b = hsl2rgb(h, s, l)
    return string.format('%s,%s,%s', r, g, b)
end
-----------------------------------------------------------------------
--- Shifts lightness by a given amount, or 30.	 					---
---	---------------------------------------------------------------	---
---	input 'r,g,b', amount   [0,255], [-100,100]						---
---	return r,g,b			[0,255]									---
-----------------------------------------------------------------------
function shiftLight(color,amount)
	local r, g, b = split(color)
    local h, s, l = rgb2hsl(r, g, b)
	local  amount = amount or 30
     l = math.max(0, math.min(100, (l + amount)))
    local r,g,b = hsl2rgb(h, s, l)
    return string.format('%s,%s,%s', r, g, b)
end
-----------------------------------------------------------------------
--- Sets or shifts HSL values to or by a given amount.				---
---	---------------------------------------------------------------	---
---	input 'r,g,b','h','s','l' or '*'								---
---	'a'= absolute (sets value to given value).						---
---	'r'= relative (shifts value + or - a given amount	  			---
---	'p'= percentage (shifts value + or - a given percent			---
---	'*'= leave value unchanged						  				---
---	Example: set('86,129,127','*','50a','-25p')						---
---	return r,g,b			[0,255]									---
-----------------------------------------------------------------------
function set(color, h, s, l, ndp)
	local ndp = ndp or 4
    local r, g, b = split(color)
    local oldH, oldS, oldL = rgb2hsl(r, g, b)
    local function processValue(value, mode, oldValue, maxValue)
        if mode == 'a' then
            return value
        elseif mode == 'r' then
            return oldValue + value
        elseif mode == 'p' then
            return oldValue * (1 + value / 100)
        elseif mode == '*' then
            return oldValue
        end
        return math.max(0, math.min(maxValue, value))
    end
    if h ~= nil then
        local mode = string.sub(h, -1)
        local value = tonumber(string.sub(h, 1, -2))
        oldH = processValue(value, mode, oldH, 360)
    end
    if s ~= nil then
        local mode = string.sub(s, -1)
        local value = tonumber(string.sub(s, 1, -2))
        oldS = processValue(value, mode, oldS, 100)
    end
    if l ~= nil then
        local mode = string.sub(l, -1)
        local value = tonumber(string.sub(l, 1, -2))
        oldL = processValue(value, mode, oldL, 100)
    end
    local r, g, b = hsl2rgb(oldH, oldS, oldL)
    return string.format('%s,%s,%s', round(r, ndp), round(g, ndp), round(b, ndp))
end
-----------------------------------------------------------------------
---	Returns color on Color Matrix format							---
---	---------------------------------------------------------------	---
---	input 'r,g,b' or 'HEX'											---
--- return 	'0.5;0.5;0.5'      [0,1]								---
-----------------------------------------------------------------------
function matrix(color,ndp)
	local ndp = ndp or 5
	local r,g,b = split(color)
	local r,g,b = r/255, g/255, b/255
	return string.format('%s;%s;%s', round(r,ndp), round(g,ndp), round(b,ndp))
end
-----------------------------------------------------------------------
---	Returns black or white depending on color brightness.			---
---	---------------------------------------------------------------	---
---	Better for Text color, feed it with background color.			---
---	input 'r,g,b'													---
--- return '0,0,0' or '255,255,255									---
-----------------------------------------------------------------------
function blackORwhite(color)
	local brightness = brightness(color)
		if brightness > math.sqrt(1.05*0.05)-0.05
	  then color = shiftLight(color,-100)
	  else color = shiftLight(color,100) end
	return color
end
-----------------------------------------------------------------------
---	Brightens or darkens a color (2) based on another color (1)		---
---	---------------------------------------------------------------	---
---	input 'r,g,b','r,g,b',desiredContrast	[0,255],[1,21]	 		---
---	if desiredContrast its negative then it's forced inverted. 		---
---	return r,g,b							[0,255]					---
-----------------------------------------------------------------------
function adjustContrast(color1, color2, desiredContrast)
    local backColor = color1
    local foreColor = color2
    local contrast = contrastRatio(backColor, foreColor)
    local amount = 0
	local newColor = foreColor
    local backBrightness = brightness(backColor)
	if desiredContrast >= 0 then
		while contrast < desiredContrast and amount <= 100 do
			if backBrightness > math.sqrt(1.05 * 0.05) - 0.05 then
				newColor = shiftLight(foreColor, -amount)
			else
				newColor = shiftLight(foreColor, amount)
			end
			contrast = contrastRatio(backColor, newColor)
			if contrast >= desiredContrast then
				break
			end
			amount = amount + 1 ---<-- For better accuracy reduce this to 0.01 (heavy cpu usage, not for dynamic use)
		end
	elseif desiredContrast < 0 then
	local desiredContrast = desiredContrast*-1
		while contrast < desiredContrast and amount <= 100 do
			if backBrightness > math.sqrt(1.05 * 0.05) - 0.05 then
				newColor = shiftLight(foreColor, amount)
			else
				newColor = shiftLight(foreColor, -amount)
			end
			contrast = contrastRatio(backColor, newColor)
			if contrast >= desiredContrast then
				break
			end
			amount = amount + 1 ---<-- For better accuracy reduce this to 0.01 (heavy cpu usage, not for dynamic use)
		end
	end
    return newColor
end
-----------------------------------------------------------------------
---	Inverts a color by its rgb values.								---
---	---------------------------------------------------------------	---
---	input 'r,g,b' 			[0,255]									---
---	return r,g,b			[0,255]									---
-----------------------------------------------------------------------
function invert(color)
	local r, g, b = split(color)
	local r, g, b = 255 - r, 255 - g, 255 - b
	return string.format('%s,%s,%s', r, g, b)
end
-----------------------------------------------------------------------
---	Shifts hue by 30 degrees										---
---	---------------------------------------------------------------	---
---	input 'r,g,b', angle	[0,255],[0,360]							---
---	return r,g,b			[0,255]									---
-----------------------------------------------------------------------
function neighborR(color)
	local angle = 30
	local color = shiftHue(color, angle) 
	return color
end
-----------------------------------------------------------------------
---	Shifts hue by -30 degrees										---
---	---------------------------------------------------------------	---
---	input 'r,g,b', angle	[0,255],[0,360]							---
---	return r,g,b			[0,255]									---
-----------------------------------------------------------------------
function neighborL(color)
	local angle = 30
	local color = shiftHue(color, -angle) 
	return color
end
-----------------------------------------------------------------------
---					    COLOR THEORY								---
---	---------------------------------------------------------------	---
---	These Functions generate colors based on color harmony			---
--- Params are 'r,g,b' [0,255], amount [-100,100] angle [0,360] 	---
---			or 'HEX'												---
---	Returns are r,g,b [0,255]										---
---	They return more than one color and need to 					---
---	be separated using substitute in a measure e.g:					---
--- RegExpSubstitute=1												---
--- Substitute="(\d+,\d+,\d+);(\d+,\d+,\d+)":"\1"	and				---
--- Substitute="(\d+,\d+,\d+);(\d+,\d+,\d+)":"\2"<-a group for each ---
--- To make it easier to use substitute on rainmeter, all returns 	---
--- but complementary are rounded to whole numbers.					---
-----------------------------------------------------------------------
-----------------------------------------------------------------------
-----------------------------------------------------------------------
---	Returns complementary color										---
---	---------------------------------------------------------------	---
---	input 'r,g,b'			[0,255]									---
---	return r,g,b			[0,255]									---
-----------------------------------------------------------------------
function complementary(color)
	local color = shiftHue(color, 180) 
	return color
end
-----------------------------------------------------------------------
---	Generates split complementary, 2 colors based on 1				---
---	---------------------------------------------------------------	---
---	input 'r,g,b'			[0,255]									---
---	return r,g,b;r,g,b		[0,255]									---
-----------------------------------------------------------------------
function splitComplementary(color)
    local function shiftAndFormat(color, angle)
        local shiftedColor = shiftHue(color, angle)
        local r, g, b = split(shiftedColor)
        return string.format('%s,%s,%s', round(r), round(g), round(b))
    end
    local color1 = shiftAndFormat(color, 150)
    local color2 = shiftAndFormat(color, -150)
	return string.format('%s;%s',color1,color2)
end
-----------------------------------------------------------------------
---	Generates triadic, 2 colors based on 1							---
---	---------------------------------------------------------------	---
---	input 'r,g,b'			[0,255]									---
---	return r,g,b;r,g,b		[0,255]									---
-----------------------------------------------------------------------
function triadic(color)
    local function shiftAndFormat(color, angle)
        local shiftedColor = shiftHue(color, angle)
        local r, g, b = split(shiftedColor)
        return string.format('%s,%s,%s', round(r), round(g), round(b))
    end
    local color1 = shiftAndFormat(color, 120)
    local color2 = shiftAndFormat(color, -120)
	return string.format('%s;%s',color1,color2)
end
-----------------------------------------------------------------------
---	Generates analogous, 2 colors based on 1						---
---	---------------------------------------------------------------	---
---	input 'r,g,b'			[0,255]									---
---	return r,g,b;r,g,b		[0,255]									---
-----------------------------------------------------------------------
function analogous(color)
    local function shiftAndFormat(color, angle)
        local shiftedColor = shiftHue(color, angle)
        local r, g, b = split(shiftedColor)
        return string.format('%s,%s,%s', round(r), round(g), round(b))
    end
    local color1 = shiftAndFormat(color, 30)
    local color2 = shiftAndFormat(color, -30)
	return string.format('%s;%s',color1,color2)
end
-----------------------------------------------------------------------
---	Generates Tetradic, 3 colors based on 1							---
---	---------------------------------------------------------------	---
---	input 'r,g,b'			[0,255]									---
---	return r,g,b;r,g,b;+	[0,255]									---
-----------------------------------------------------------------------
function tetradic(color)
    local function shiftAndFormat(color, angle)
        local shiftedColor = shiftHue(color, angle)
        local r, g, b = split(shiftedColor)
        return string.format('%s,%s,%s', round(r), round(g), round(b))
    end
    local color1 = shiftAndFormat(color, 60)
    local color2 = shiftAndFormat(color, 180)
    local color3 = shiftAndFormat(color, 240) 
	return string.format('%s;%s;%s',color1,color2,color3)
end
-----------------------------------------------------------------------
---	Generates Square, 3 colors based on 1							---
---	---------------------------------------------------------------	---
---	input 'r,g,b'			[0,255]									---
---	return r,g,b;r,g,b;+	[0,255]									---
-----------------------------------------------------------------------
function square(color)
    local function shiftAndFormat(color, shift)
        local shiftedColor = shiftHue(color, shift)
        local r, g, b = split(shiftedColor)
        return string.format('%s,%s,%s', round(r), round(g), round(b))
    end
    local color1 = shiftAndFormat(color, 90)
    local color2 = shiftAndFormat(color, 180)
    local color3 = shiftAndFormat(color, 270)  
    return string.format('%s;%s;%s', color1, color2, color3)
end
-----------------------------------------------------------------------
---					    COLOR GENERATION							---
---	---------------------------------------------------------------	---
---	   	  These Functions generate shades, tones and tints.			---
---  Params are r,g,b [0,255], amount [-100,100], angle [-360,360]	---
---			  	 Returns are r,g,b [0,255]	(rounded)				---
-----------------------------------------------------------------------
-----------------------------------------------------------------------
-----------------------------------------------------------------------
---	Generates shades												---
---	---------------------------------------------------------------	---
---	input 'r,g,b', count, amount		[0,255],[1,+],[0,100]		---
---	return r,g,b;r,g,b; +				[0,255]						---
-----------------------------------------------------------------------
function shades(color, count, amount)
    local count = count or 2
    local amount = amount or 100
	local r, g, b = split(color)
    local h, s, l = rgb2hsl(r, g, b)
    local step = l / count
    local shades = {}
    for i = 1, count do
        local l = math.max(0, l - step * i * amount / 100)
        local r, g, b = hsl2rgb(h, s, l)
        shades[i] = string.format('%s,%s,%s', round(r), round(g), round(b))
    end
    return table.concat(shades, ';')
end
-----------------------------------------------------------------------
---	Generates tints													---
---	---------------------------------------------------------------	---
---	input 'r,g,b', count, amount		[0,255],[1,+],[0,100]			---
---	return r,g,b;r,g,b; +				[0,255]						---
-----------------------------------------------------------------------
function tints(color, count, amount)
    local count = count or 2
    local amount = amount or 100
    local r, g, b = split(color)
    local h, s, l = rgb2hsl(r, g, b)
    local step = (100 - l) / count
    local tints = {}
    for i = 1, count do
        l = l + step * amount / 100
        l = math.max(0, math.min(100, l))
        local r, g, b = hsl2rgb(h, s, l)
        tints[i] = string.format('%s,%s,%s', round(r), round(g), round(b))
    end
    return table.concat(tints, ';')
end
-----------------------------------------------------------------------
---	Generates tones													---
---	---------------------------------------------------------------	---
---	input 'r,g,b', count, amount		[0,255],[1,+],[0,100]			---
---	return r,g,b;r,g,b; +				[0,255]						---
-----------------------------------------------------------------------
function tones(color, count, amount)
    local count = count or 2
    local amount = amount or 100
	local r, g, b = split(color)
    local h, s, l = rgb2hsl(r, g, b)
    local step = s / count
    local tones = {}
    for i = 1, count do
        local s = math.max(0, s - (step * i * amount / 100))
        local r, g, b = hsl2rgb(h, s, l)
        tones[i] = string.format('%s,%s,%s', round(r), round(g), round(b))
    end
    return table.concat(tones, ';')
end
-----------------------------------------------------------------------
---							  CREDITS								---
-----------------------------------------------------------------------
---							by RicardoTM							---
---					 Inspired by colors.lua by yuri 				---
---					https://github.com/yuri/lua-colors				---
---					     hex2rgb by JSMorley						---
---				    Some tips and chunks by Yincognito				---
---			  Lots of stuff compiled from various sources			---
-----------------------------------------------------------------------
-----------------------------------------------------------------------
-----------------------------------------------------------------------

