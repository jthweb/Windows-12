[Rainmeter]
ContextTitle=Edit variables...
ContextAction=["#CONFIGEDITOR#" "#@#Bvariables.inc"]
MiddleMouseUpAction=!Refresh
Group=MD3 Windows

; ===== STYLES

[Long]
Shape=Rectangle 0,0,(#IconSize#*4.5),(#IconSize#*1.9),18 | StrokeWidth 0  


[Bar]
W=[#CURRENTSECTION#Container:W]
H=[#CURRENTSECTION#Container:H]
Container=#CURRENTSECTION#Container
SolidColor=[&MeterialYou:GetToken("OnSecondary")]
BarColor=[&MeterialYou:GetToken("PrimaryContainer")]
BarOrientation=HORIZONTAL
DynamicVariables=1
Flip=0

[Start]
X=9
Y=9

[Next]
X=9
Y=9







