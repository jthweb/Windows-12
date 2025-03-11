;Version=1.2
;This file is the heart of all search bars. Do not modify.
[Rainmeter]
Update=-1
AccurateText=1
DynamicWindowSize=1

;Mouse Actions
RightMouseUpAction=[!SetVariable contextType "All"][!SkinCustomMenu]
LeftMouseUpAction=[!CommandMeasure BarOpener[#enableList] "Execute 1"]
MiddleMouseUpAction=[!SetVariable contextType "Bar"][!SkinCustomMenu]
MouseScrollDownAction=[!FadeDuration [#fadeDuration]][!SetVariable engineNumber ((([#totalEngines]+[#engineNumber]-1+1)%[#totalEngines])+1)][!ActivateConfig "[#CurrentConfig]" "[#Engine[#engineNumber]].ini"]
MouseScrollUpAction=[!FadeDuration [#fadeDuration]] [!SetVariable engineNumber ((([#totalEngines]+[#engineNumber]-1-1)%[#totalEngines])+1)][!ActivateConfig "[#CurrentConfig]" "[#Engine[#engineNumber]].ini"]

;Context Menu
ContextTitle=[#context[#contextType]Title1]
ContextAction=[#context[#contextType]Action1]
ContextTitle2=[#context[#contextType]Title2]
ContextAction2=[#context[#contextType]Action2]
ContextTitle3=[#context[#contextType]Title3]
ContextAction3=[#context[#contextType]Action3]
ContextTitle4=[#context[#contextType]Title4]
ContextAction4=[#context[#contextType]Action4]
contextTitle5=[#context[#contextType]Title5]
contextAction5=[#context[#contextType]Action5]
contextTitle6=[#context[#contextType]Title6]
contextAction6=[#context[#contextType]Action6]
contextTitle7=[#context[#contextType]Title7]
contextAction7=[#context[#contextType]Action7]
contextTitle8=[#context[#contextType]Title8]
contextAction8=[#context[#contextType]Action8]
contextTitle9=[#context[#contextType]Title9]
contextAction9=[#context[#contextType]Action9]
contextTitle10=[#context[#contextType]Title10]
contextAction10=[#context[#contextType]Action10]
contextTitle11=[#context[#contextType]Title11]
contextAction11=[#context[#contextType]Action11]
contextTitle12=[#context[#contextType]Title12]
contextAction12=[#context[#contextType]Action12]
contextTitle13=[#context[#contextType]Title13]
contextAction13=[#context[#contextType]Action13]
contextTitle14=[#context[#contextType]Title14]
contextAction14=[#context[#contextType]Action14]
contextTitle15=[#context[#contextType]Title15]
contextAction15=[#context[#contextType]Action15]
contextTitle16=[#context[#contextType]Title16]
contextAction16=[#context[#contextType]Action16]
contextTitle17=[#context[#contextType]Title17]
contextAction17=[#context[#contextType]Action17]
contextTitle18=[#context[#contextType]Title18]
contextAction18=[#context[#contextType]Action18]
contextTitle19=[#context[#contextType]Title19]
contextAction19=[#context[#contextType]Action19]
contextTitle20=[#context[#contextType]Title20]
contextAction20=[#context[#contextType]Action20]
contextTitle21=[#context[#contextType]Title21]
contextAction21=[#context[#contextType]Action21]
contextTitle22=[#context[#contextType]Title22]
contextAction22=[#context[#contextType]Action22]
contextTitle23=[#context[#contextType]Title23]
contextAction23=[#context[#contextType]Action23]
contextTitle24=[#context[#contextType]Title24]
contextAction24=[#context[#contextType]Action24]
contextTitle25=[#context[#contextType]Title25]
contextAction25=[#context[#contextType]Action25]

[Variables]
iconPath=#@#Icons\[#engineName].[#IconFileType]
HSLidersPath=[#ROOTCONFIGPATH]HSLidersSTD\HSLiders.ini
HSLidersConfig=[#ROOTCONFIG]\HSLidersSTD

FontFace=DM Sans 14pt 

Width=[#*Height*]
Height=40
strokeWidth=0
Corners=([#*Height*]/2)
itemHeight=(round([#*Height*]/2.5))
itemCorners=([#*Corners*]/2.5)
searchHeight=([#*Height*]/2)
Margin=([#*Height*]/2.5)
vWidth=0
maxWidth=300
vHeight=0
maxHeight=([#*itemHeight*]*[#*Items*])
scaleSearchText=1
scaleItemText=1
scaleTitleText=1

contrastList=1.2
contrastListText=5
contrastText=8
contrastItem=1.2
colorBackground=028,028,028
colorStroke=043,043,043
colorText=[&*C:adjustContrast('[#*colorBackground*]','128,128,128',[#*contrastText*])*]
colorList=[&*C:adjustContrast('[#*colorBackground*]','[#*colorBackground*]',[#*contrastList*])*]
colorListText=[&*C:adjustContrast('[#*colorList*]','128,128,128',[#*contrastListText*])*]
colorItem=[&*C:adjustContrast('[#*colorList*]','[#*colorList*]',[#*contrastItem*])*]
alphaBackground=255
alphaInputText=255
alphaIcon=255
alphaText=255
alphaStroke=255
alphaList=255

ListY=0
listTitle=List Title
Items=5
itemsTotal=10
item1Title=item 1
item1=
item2Title=item 2
item2=
item3Title=item 3
item3=
item4Title=item 4
item4=
item5Title=item 5
item5=
item6Title=item 6
item6=
item7Title=item 7
item7=
item8Title=item 8
item8=
item9Title=item 9
item9=
item10Title=item 10
item10=

animationWait=16
animationSteps=8
barOpenAnimation=outBack
barCloseAnimation=outBack
listOpenAnimation=outBack
ListCloseAnimation=outBack

actionRunSearch=[!EnableMeasure Run][!UpdateMeasure Run]

contextType=All
; General Menu
ContextAllTitle1=[#ROOTCONFIG]
ContextAllAction1=["[#ROOTCONFIGPATH]"]
ContextAllTitle2=-
ContextAllTitle3=Bar Selection							[\x27A4]
ContextAllAction3=[!SetVariable contextType "Bar"][!SkinCustomMenu]
ContextAllTitle4=Change Color							[\x27A4]
ContextAllAction4=[!SetVariable contextType "Color"][!SkinCustomMenu]
ContextAllTitle5=List									[\x27A4]
ContextAllAction5=[!SetVariable contextType "List"][!SkinCustomMenu]
ContextAllTitle6=-
ContextAllTitle7=Change Anchor							[\x27A4]
ContextAllAction7=[!SetVariable contextType "Anchor"][!SkinCustomMenu]
ContextAllTitle8=Preferences...
ContextAllAction8=["#@#User.inc"]
ContextAllTitle9=-
ContextAllTitle10=Check for updates
ContextAllAction10=[https://forum.rainmeter.net/viewtopic.php?t=43934]
ContextAllTitle11=-
ContextAllTitle12=Skin Menu							[\x27A4]
ContextAllAction12=[!SkinMenu]
ContextAllTitle13=Edit Skin
ContextAllAction13=[!EditSkin]
ContextAllTitle14=Refresh Skin
ContextAllAction14=[!Refresh]
ContextAllTitle15=Refresh All
ContextAllAction15=[!RefreshApp]
ContextAllTitle16=-
ContextAllTitle17=Unload Skin
ContextAllAction17=[!DeactivateConfig "[#CurrentConfig]"]
ContextAllTitle18=

;Color Menu
ContextColorTitle1=Background
ContextColorAction1=[!WriteKeyValue variables varName "colorBackground" "[#HSLidersPath]"][!WriteKeyValue variables varColor "[#colorBackground]" "[#HSLidersPath]"][!WriteKeyValue variables filePath "[#***ROOTCONFIGPATH***][#CURRENTFILE]" "[#HSLidersPath]"][!Refresh "[#HSLidersConfig]"][!ActivateConfig "[#HSLidersConfig]"]
ContextColorTitle2=Stroke
ContextColorAction2=[!WriteKeyValue variables varName "colorStroke" "[#HSLidersPath]"][!WriteKeyValue variables varColor "[#colorStroke]" "[#HSLidersPath]"][!WriteKeyValue variables filePath "[#***ROOTCONFIGPATH***][#CURRENTFILE]" "[#HSLidersPath]"][!Refresh "[#HSLidersConfig]"][!ActivateConfig "[#HSLidersConfig]"]
ContextColorTitle3=List
ContextColorAction3=[!WriteKeyValue variables varName "colorList" "[#HSLidersPath]"][!WriteKeyValue variables varColor "[#colorList]" "[#HSLidersPath]"][!WriteKeyValue variables filePath "[#***ROOTCONFIGPATH***][#CURRENTFILE]" "[#HSLidersPath]"][!Refresh "[#HSLidersConfig]"][!ActivateConfig "[#HSLidersConfig]"]
ContextColorTitle4=

;Anchor Menu
ContextAnchorTitle1=Top Left
ContextAnchorAction1=[!SetAnchor "0%" "0%"]
ContextAnchorTitle2=Top Right
ContextAnchorAction2=[!SetAnchor "100%" "0%"]
ContextAnchorTitle3=Top Center
ContextAnchorAction3=[!SetAnchor "50%" "0%"]
ContextAnchorTitle4=-
ContextAnchorTitle5=Bottom Left
ContextAnchorAction5=[!SetAnchor "0%" "100%"]
ContextAnchorTitle6=Bottom Right
ContextAnchorAction6=[!SetAnchor "100%" "100%"]
ContextAnchorTitle7=Bottom Center
ContextAnchorAction7=[!SetAnchor "50%" "100%"]
ContextAnchorTitle8=

; Bar Selection Menu: 
ContextBarTitle1=[#Engine1]
ContextBarAction1=[!ActivateConfig "[#CurrentConfig]" "[#Engine1].ini"]
ContextBarTitle2=[#Engine2]
ContextBarAction2=[!ActivateConfig "[#CurrentConfig]" "[#Engine2].ini"]
ContextBarTitle3=[#Engine3]
ContextBarAction3=[!ActivateConfig "[#CurrentConfig]" "[#Engine3].ini"]
ContextBarTitle4=[#Engine4]
ContextBarAction4=[!ActivateConfig "[#CurrentConfig]" "[#Engine4].ini"]
ContextBarTitle5=[#Engine5]
ContextBarAction5=[!ActivateConfig "[#CurrentConfig]" "[#Engine5].ini"]
ContextBarTitle6=[#Engine6]
ContextBarAction6=[!ActivateConfig "[#CurrentConfig]" "[#Engine6].ini"]
ContextBarTitle7=[#Engine7]
ContextBarAction7=[!ActivateConfig "[#CurrentConfig]" "[#Engine7].ini"]
ContextBarTitle8=[#Engine8]
ContextBarAction8=[!ActivateConfig "[#CurrentConfig]" "[#Engine8].ini"]
ContextBarTitle9=[#Engine9]
ContextBarAction9=[!ActivateConfig "[#CurrentConfig]" "[#Engine9].ini"]
ContextBarTitle10=[#Engine10]
ContextBarAction10=[!ActivateConfig "[#CurrentConfig]" "[#Engine10].ini"]
ContextBarTitle11=[#Engine11]
ContextBarAction11=[!ActivateConfig "[#CurrentConfig]" "[#Engine11].ini"]
ContextBarTitle12=[#Engine12]
ContextBarAction12=[!ActivateConfig "[#CurrentConfig]" "[#Engine12].ini"]
ContextBarTitle13=[#Engine13]
ContextBarAction13=[!ActivateConfig "[#CurrentConfig]" "[#Engine13].ini"]
ContextBarTitle14=[#Engine14]
ContextBarAction14=[!ActivateConfig "[#CurrentConfig]" "[#Engine14].ini"]
ContextBarTitle15=[#Engine15]
ContextBarAction15=[!ActivateConfig "[#CurrentConfig]" "[#Engine15].ini"]
ContextBarTitle16=[#Engine16]
ContextBarAction16=[!ActivateConfig "[#CurrentConfig]" "[#Engine16].ini"]
ContextBarTitle17=[#Engine17]
ContextBarAction17=[!ActivateConfig "[#CurrentConfig]" "[#Engine17].ini"]
ContextBarTitle18=[#Engine18]
ContextBarAction18=[!ActivateConfig "[#CurrentConfig]" "[#Engine18].ini"]
ContextBarTitle19=[#Engine19]
ContextBarAction19=[!ActivateConfig "[#CurrentConfig]" "[#Engine19].ini"]
ContextBarTitle20=[#Engine20]
ContextBarAction20=[!ActivateConfig "[#CurrentConfig]" "[#Engine20].ini"]
ContextBarTitle21=[#Engine21]
ContextBarAction21=[!ActivateConfig "[#CurrentConfig]" "[#Engine21].ini"]
ContextBarTitle22=[#Engine22]
ContextBarAction22=[!ActivateConfig "[#CurrentConfig]" "[#Engine22].ini"]
ContextBarTitle23=[#Engine23]
ContextBarAction23=[!ActivateConfig "[#CurrentConfig]" "[#Engine23].ini"]
ContextBarTitle24=[#Engine24]
ContextBarAction24=[!ActivateConfig "[#CurrentConfig]" "[#Engine24].ini"]
ContextBarTitle25=[#Engine25]
ContextBarAction25=[!ActivateConfig "[#CurrentConfig]" "[#Engine25].ini"]

;List Menu
ContextListTitle1=Enable
ContextListAction1=[!WriteKeyValue variables enableList 1][!SetVariable enableList 1][!Update] 
ContextListTitle2=Disable
ContextListAction2=[!WriteKeyValue variables enableList 0][!SetVariable enableList 0][!Update]
ContextListTitle3=

encodeQuery=1

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;Measures;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;										  	  Scripts 	                                    ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
[C]
;raincolors.lua script measure.
Disabled=1
Measure=Script
ScriptFile=#@#Content\Scripts\raincolors.lua

[E]
;Easing animations script.
Measure=Script
ScriptFile=#@#Content\Scripts\easings.lua
Disabled=1

[Encode]
Measure=Calc
IfCondition=[#EncodeQuery] = 1
IfTrueAction=[!SetOption Run OnUpdateAction """[!SetVariable Query "[*Run:EncodeURL*]"]["[#*engineURL*]"][!DisableMeasure [#*CurrentSection*]]"""][!DisableMeasure [#CurrentSection]]
IfFalseAction=[!SetOption Run OnUpdateAction """["[#*engineURL*]"][!DisableMeasure [#*CurrentSection*]]"""][!DisableMeasure [#CurrentSection]]
DynamicVariables=1

[Run]
Disabled=1
Measure=String
String=[#Query]
DynamicVariables=1

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;Measures;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;										  	  Animation 	                                ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
[BarOpener0]
Disabled=1
;Open/Close Bar animation.
measure=Plugin
Plugin=ActionTimer
ActionList1=setCounter | Repeat barOpen, [#animationWait], [#animationSteps] |Finish
setCounter=[!ShowMeter TextCntnr][!SetVariable counter 0][!SetVariable counter2 0]
barOpen=[!SetVariable counter "([#counter] + 1)"][!SetVariable vWidth [&E:[#barOpenAnimation](([#counter]/[#animationSteps]),0,([#maxWidth]))]][!UpdateMeasure [#CURRENTSECTION]][!UpdateMeter *][!Redraw]
Finish=[!DisableMouseAction Rainmeter "*"][!SetOption Text Text ""][!UpdateMeter Text][!Redraw][!CommandMeasure SearchInput "ExecuteBatch ALL"]
ActionList2=setCounter2 | Repeat barClose, [#animationWait], [#animationSteps] |barCloseFinish
setCounter2=[!SetVariable counter [#animationSteps]]
barClose=[!SetVariable counter "([#counter] - 1)"][!SetVariable vWidth [&E:[#barCloseAnimation](([#counter]/[#animationSteps]),0,[#maxWidth])]][!UpdateMeasure [#CURRENTSECTION]][!UpdateMeter *][!Redraw]
barCloseFinish=[!EnableMouseAction Rainmeter "*"][!HideMeter TextCntnr]
DynamicVariables=1

[BarOpener1]
Disabled=1
;Open/Close Bar and List animation.
measure=Plugin
Plugin=ActionTimer
ActionList1=setCounter | Repeat barOpen, [#animationWait], [#animationSteps]|barOpenFinish |Repeat listOpen, [#animationWait], [#animationSteps]|listOpenFinish
setCounter=[!ShowMeter TextCntnr][!SetVariable counter 0][!SetVariable counter2 0]
barOpen=[!SetVariable counter "([#counter] + 1)"][!SetVariable vWidth [&E:[#barOpenAnimation](([#counter]/[#animationSteps]),0,([#maxWidth]))]][!UpdateMeasure [#CURRENTSECTION]][!UpdateMeter *][!Redraw]
listOpen=[!SetVariable counter2 "([#counter2] + 1)"][!SetVariable vHeight [&E:[#listOpenAnimation](([#counter2]/[#animationSteps]),0,([#maxHeight]+[#itemHeight]*2+[#Margin]/2+[#strokeWidth]/2))]][!UpdateMeasure [#CURRENTSECTION]][!UpdateMeter *][!Redraw]
barOpenFinish=[!ShowMeterGroup List][!DisableMouseAction Rainmeter "*"]
listOpenFinish=[!SetOption SearchBar LeftMouseUpAction "[]"][!SetOption Text Text ""][!UpdateMeter Text][!Redraw][!CommandMeasure SearchInput "ExecuteBatch ALL"]
ActionList2=setCounter2 | Repeat listClose, [#animationWait], [#animationSteps] |listCloseFinish | Repeat barClose, [#animationWait], [#animationSteps] |barCloseFinish
setCounter2=[!SetVariable counter [#animationSteps]][!SetVariable counter2 [#animationSteps]]
barClose=[!SetVariable counter "([#counter] - 1)"][!SetVariable vWidth [&E:[#barCloseAnimation](([#counter]/[#animationSteps]),0,[#maxWidth])]][!UpdateMeasure [#CURRENTSECTION]][!UpdateMeter *][!Redraw]
listClose=[!SetVariable counter2 "([#counter2] - 1)"][!SetVariable vHeight [&E:[#listCloseAnimation](([#counter2]/[#animationSteps]),0,([#maxHeight]+[#itemHeight]*2+[#Margin]/2+[#strokeWidth]/2))]][!UpdateMeasure [#CURRENTSECTION]][!UpdateMeter *][!Redraw]
listCloseFinish=[!SetOption SearchBar LeftMouseUpAction ""][!HideMeterGroup List]
barCloseFinish=[!EnableMouseAction Rainmeter "*"][!HideMeter TextCntnr]
DynamicVariables=1

;;;;;;;;Measures;;;;;;;;
;	   InputText 	   ;
;;;;;;;;;;;;;;;;;;;;;;;;
[SearchInput]
;Text input measure
Disabled=1
Measure=Plugin
Plugin=InputText
FocusDismiss=1
X=[TextCntnr:X]
Y=([TextCntnr:Y]+[TextCntnr:H]/10)
H=[TextCntnr:H]
W=([TextCntnr:W])
SolidColor=[#colorBackground],[#alphaInputText]
FontFace=[#FontFace]
FontSize=(([#searchHeight]/2)*[#scaleSearchText])
FontColor=[#colorText],[#alphaText]
StringAlign=LeftCenter
AntiAlias=1
DynamicVariables=1
OnDismissAction=[!SetOption Text Text "Search..."][!UpdateMeter Text][!Redraw][!CommandMeasure BarOpener[#EnableList] "Execute 2"]
Command1=[!SetOption Text Text "Search..."][!SetVariable query "$UserInput$"][#actionRunSearch][!UpdateMeter Text][!Redraw][!CommandMeasure BarOpener[#EnableList] "Execute 2"]

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;										  	Meter Styles                                    ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
[msFormat]
;Text MeterStyle
StringAlign=LeftCenter
FontFace=[#FontFace]
FontColor=[#colorText],[#alphaText]
H=[#itemHeight]
AntiAlias=1
ClipString=1
DynamicVariables=1

[msItemShape]
;Item Containers Meter Style
Hidden=1
Container=ListCntnr
Group=List
Shape=rectangle 0,0,([#Width]+[#vWidth]-[#strokeWidth]-[#Margin]),([#itemHeight]),([#itemCorners])| Extend Fill | StrokeWidth 0 | StrokeColor [#colorStroke],[#alphaStroke]
Fill=Fill Color [#colorList],1
y=([#StrokeWidth]+[#Height]+[#itemHeight]+[#listY])
MouseOverAction=[!SetOption [#CurrentSection] Fill "Fill Color [#*colorItem*],[#*alphaList*]"][!UpdateMeter [#CurrentSection]][!Redraw]
MouseLeaveAction=[!SetOption [#CurrentSection] Fill "Fill Color [#*colorList*],1"][!UpdateMeter [#CurrentSection]][!Redraw]
MouseActionCursor=0
DynamicVariables=1

[msItems]
Container=ListCntnr
Group=List
Hidden=1
FontSize=(([#itemHeight]/2)*[#scaleItemText])
Text=[#[#CurrentSection]Title]
fontColor=[#colorListText],[#alphaText]
x=([[#CurrentSection]Shape:X]-[#strokeWidth])
Y=([[#CurrentSection]Shape:Y]+[#itemHeight]/2)
W=([#Width]+[#vWidth]-[#Margin]*2-[#strokeWidth])

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;Meters;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;										  	   	 List 	                                    ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
[List]
;List BG
Hidden=1
Group=List
Meter=Shape
Shape=Rectangle ([#strokeWidth]/2),([#strokeWidth]/2),([#Width]+[#vWidth]),([#Height]+[#vHeight]+[#Margin]/2-[#itemHeight]*1.5+[#strokeWidth]/2),([#Corners]) | Fill Color [#colorList],[#alphaList] | StrokeWidth [#strokeWidth] | StrokeColor [#colorStroke],[#alphaStroke]
DynamicVariables=1

[ListCntnr]
;List Container
Hidden=1
Group=List
Meter=Shape
Shape=Rectangle 0,0,([#Width]+[#vWidth]-[#strokeWidth]-[#Margin]),([#Height]+[#vHeight]+[#strokeWidth]/2-[#itemHeight]-[#Margin]/2),0 | Fill Color 0,0,0,[#alphaList] | StrokeWidth 0 | StrokeColor [#colorStroke],[#alphaStroke]
X=([#strokeWidth]+[#Margin]/2)
MouseScrollUpAction=[!SetVariable ListY (min(clamp([#ListY]+[#itemHeight],(-[#itemHeight]*([#itemsTotal]-[#items])),0),0))][!UpdateMeterGroup List][!Redraw]
MouseScrollDownAction=[!SetVariable ListY (min(clamp([#ListY]-[#itemHeight],(-[#itemHeight]*([#itemsTotal]-[#items])),0),0))][!UpdateMeterGroup List][!Redraw]
DynamicVariables=1

@IncludeUser=#@#User.inc

[itemTitleShape]
Meter=Shape
meterStyle=msItemShape
x=0
y=([#StrokeWidth]+[#Height])
Fill=Fill Color [#colorList],[#alphaList]
LeftMouseUpAction=[]
MouseOverAction=[]
MouseLeaveAction=[]

[itemTitle]
Meter=String
meterStyle=msFormat|msItems
StringStyle=Bold
Text=[#ListTitle]
FontSize=([#itemHeight]/2)*[#scaleTitleText]
W=([#Width]+[#vWidth]-[#Margin])
x=([[#CurrentSection]Shape:X]-[#Margin]/2-[#strokeWidth])

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;Meters;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;										  	  Search Bar 	                                ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
[SearchBar]
;Search Bar Background
Meter=Shape
Shape=Rectangle ([#strokeWidth]/2),([#strokeWidth]/2),([#Width]+[#vWidth]),([#Height]),([#Corners]) | Fill Color [#colorBackground],[#alphaBackground] | StrokeWidth [#strokeWidth] | StrokeColor [#colorStroke],[#alphaStroke]
MouseActionCursor=0
DynamicVariables=1

[EngineIcon]
;Icon
Meter=Image
ImageName="[#iconPath]"
X=(([#strokewidth]+[#Width]-[EngineIcon:H])/2)
Y=(([SearchBar:H]-[EngineIcon:H])/2)
H=(([SearchBar:H]/1.8)*[#iconScale])
imageAlpha=[#alphaIcon]
PreserveAspectRatio=1
MouseActionCursor=0
DynamicVariables=1

[TextCntnr]
;Search Text Box
Hidden=1
Meter=Shape
Shape=Rectangle 0,0,[TextCntnr:W],[TextCntnr:H] | Fill Color 0,0,0,[#alphaBackground] | StrokeWidth 0
X=([#strokeWidth]+[#Width])
Y=([#strokeWidth]+[#Height]-[#searchHeight])/2
W=([SearchBar:W]-[#Width]-[#Margin]/2-[#StrokeWidth]*2)
H=([#searchHeight])
DynamicVariables=1
MouseActionCursorName=Text

[Text]
;Search Text
Container=TextCntnr
Meter=String
MeterStyle=msFormat
Text=Search...
Y=([#searchHeight]/2)
W=([#vWidth]+[#Margin]*2-[#strokeWidth]/2)
H=([#searchHeight])
FontSize=(([#searchHeight]/2)*[#scaleSearchText])

[Center]
;Guides
Hidden=1
Meter=Shape
Shape=Line 0,([#Height]+[#strokeWidth])/2,([#width]+[#strokeWidth]),([#Height]+[#strokeWidth])/2 | StrokeColor 255,255,255
Shape2=Line ([#Width]+[#strokeWidth])/2,0,([#Width]+[#strokeWidth])/2,([#Height]+[#strokeWidth]) | StrokeColor 255,255,255
DynamicVariables=1


