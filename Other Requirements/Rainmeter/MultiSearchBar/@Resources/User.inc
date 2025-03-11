;Version=1.2
;This is your file. You can and should modify anything here.
[Variables]
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	            GENERAL		 	          ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;These variables affect all Search Bars.
;Tip: you can copy and paste any of these variables on any search bar file so they only affect that bar.
;And you can copy any variable from any search bar file and paste it here so they affect all bars.

;Font 
FontFace=DM Sans 14pt

; Size
Height=48
Width=([#*Height*])
maxWidth=250
Corners=([#*Height*]/6)
;Circle: Corners=([#*Height*]/2) | Rounded Square: Corners=([#*Height*]/6) | Sharp Square: Corners=0
strokeWidth=2

;Caution, setting input text alpha too low will make text invisible.
alphaBackground=255
alphaInputText=255
alphaIcon=255
alphaText=255
alphaStroke=255
alphaList=255

;Text Scale | Use deciamls. Example: 0.8 1.2 1.5
scaleSearchText=1.0
scaleItemText=1.0
scaleTitleText=1.0

; Fade when switching between bars in ms | Disable = 0
fadeDuration=150

;;;;;;;;;;;;;;;;ENGINES;;;;;;;;;;;;;;;;;;;;
;	         INSTRUCTIONS	 	          ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; To add a new Engine:
; Fill Engine6 variable with your new engine name, avoid using spaces.
; Replace totalEngines with totalEngines=6
; Right Click on the bar > MultiSearchBar and duplicate any search bar file.ini and name it the same as the Engine6 variable. 
; Modify the variables in the file.
; engineNumber has to correspond to the EngineN variable number, which would be 6.
; engineName has to correspond to the name you typed on the Engine6 variable.
; Add the icon/logo image to #@#resources\Icons. (Right Click > MultiSearchBar > #@#resources\Icons)
; The image name also has to be the same.
; In other words: The EngineN variable, the engineName variable, the file name and the image name have to be the same.
; When done, save the files then Right Click > Refresh All.
; You should now see your new bar on the bar selection menu, and scrolling on the bar.
; totalEngines variable has to equal the amount of Engines being used.
totalEngines=5

Engine1=Google
Engine2=GoogleImages
Engine3=Youtube
Engine4=Reddit
Engine5=Edge
Engine6=
Engine7=
Engine8=
Engine9=
Engine10=
Engine11=
Engine12=
Engine13=
Engine14=
Engine15=
Engine16=
Engine17=
Engine18=
Engine19=
Engine20=
Engine21=
Engine22=
Engine23=
Engine24=
Engine25=

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	            ANIMATION	 	          ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Wait is like latency, Steps is the amount of iterations.
; Lower wait means faster but more cpu usage.
; Lower steps means faster but less "frames".
; The idea is to find an equilibrium between performance and flow.
; Low wait + high steps means low performance, but better "frames".
; low steps + high wait means good performance but less "frames".
animationWait=8
animationSteps=16

; Open/Close Animation
barOpenAnimation=outBack
barCloseAnimation=outBack
listOpenAnimation=outBack
ListCloseAnimation=outBack

;List of Animations:
; Linear
;   in	 |	  out	 |	in and out
; inSine	outSine		inoutSine
; inQuad	outQuad		inoutQuad
; inCubic	outCubic	inoutCubic	
; inQuart	outQuart	inoutQuart
; inQuint	outQuint	inoutQuint
; inExpo	outExpo		inoutExpo
; inCirc	outCirc		inoutCirc
; inBack	outBack		inoutBack
; inElastic	outElastic	inoutElastic
; inBounce	outBounce	inoutBounce

;Note: They are all case sensitive.

;;;;;;;;;;;;;;;;;;ITEMS;;;;;;;;;;;;;;;;;;;;
;	          INSTRUCTIONS	 	          ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; An item is a line on the list.
; Items consist of 2 meters, a shape meter [itemNShape] 
; and a string meter [itemN].
; All engines have access to the same number of items.
; But each engine has its own items. An can display a different amount of them.
; There's 10 items by default.
;
; To add more items:
; Simply duplicate [item10Shape] and name it [item11Shape],
; then replace [#item10] with [#item11] on the LeftMouseUpAction option.
; Duplicate [Item10] meter and name it [Item11].
; Save this file, then Right Click > Edit Skin.
; Add item11 and item11Title variables as described on that file instructions.
; Right Click > Refresh Skin. Repeat last step for all search bars.
 
;;;;;;;;;;;;;;;;;;;Meters;;;;;;;;;;;;;;;;;
;	        	   Shapes   	         ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
[item1Shape]
Meter=Shape
MeterStyle=msItemShape
LeftMouseUpAction=[!SetVariable Query [#item1]][#actionRunSearch]

[item2Shape]
Meter=Shape
meterStyle=msItemShape
x=r
Y=R
LeftMouseUpAction=[!SetVariable Query [#item2]][#actionRunSearch]

[item3Shape]
Meter=Shape
meterStyle=msItemShape
x=r
Y=R
LeftMouseUpAction=[!SetVariable Query [#item3]][#actionRunSearch]

[item4Shape]
Meter=Shape
meterStyle=msItemShape
x=r
Y=R
LeftMouseUpAction=[!SetVariable Query [#item4]][#actionRunSearch]

[item5Shape]
Meter=Shape
meterStyle=msItemShape
x=r
Y=R
LeftMouseUpAction=[!SetVariable Query [#item5]][#actionRunSearch]

[item6Shape]
Meter=Shape
meterStyle=msItemShape
x=r
Y=R
LeftMouseUpAction=[!SetVariable Query [#item6]][#actionRunSearch]

[item7Shape]
Meter=Shape
meterStyle=msItemShape
x=r
Y=R
LeftMouseUpAction=[!SetVariable Query [#item7]][#actionRunSearch]

[item8Shape]
Meter=Shape
meterStyle=msItemShape
x=r
Y=R
LeftMouseUpAction=[!SetVariable Query [#item8]][#actionRunSearch]

[item9Shape]
Meter=Shape
meterStyle=msItemShape
x=r
Y=R
LeftMouseUpAction=[!SetVariable Query [#item9]][#actionRunSearch]

[item10Shape]
Meter=Shape
meterStyle=msItemShape
x=r
Y=R
LeftMouseUpAction=[!SetVariable Query [#item10]][#actionRunSearch]

;;;;;;;;;;;;;;;;;;;Meters;;;;;;;;;;;;;;;;;
;	        	   Strings   	         ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
[item1]
Meter=String
meterStyle=msFormat|msItems

[item2]
meter=String
meterStyle=msFormat|msItems

[item3]
meter=String
meterStyle=msFormat|msItems

[item4]
meter=String
meterStyle=msFormat|msItems

[item5]
meter=String
meterStyle=msFormat|msItems

[item6]
meter=String
meterStyle=msFormat|msItems

[item7]
meter=String
meterStyle=msFormat|msItems

[item8]
meter=String
meterStyle=msFormat|msItems

[item9]
meter=String
meterStyle=msFormat|msItems

[item10]
meter=String
meterStyle=msFormat|msItems
