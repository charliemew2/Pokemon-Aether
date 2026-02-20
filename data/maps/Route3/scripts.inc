Route3_MapScripts::
	.byte 0


@NPCS

Route3_EventScript_BoyWanderingGrass::
	lock
	faceplayer
	msgbox Route3_Text_BoyWanderingGrass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route3_Text_BoyWanderingGrass::
	.string "FUCK DES!$"

Route3_EventScript_CyclingGirl::
	lock
	faceplayer
	msgbox Route3_Text_CyclingGirl, MSGBOX_DEFAULT
	closemessage
	release
	end

Route3_Text_CyclingGirl::
	.string "I like to bike!$"

Route3_EventScript_RunningMan::
	lock
	faceplayer
	msgbox Route3_Text_RunningMan, MSGBOX_DEFAULT
	closemessage
	release
	end

Route3_Text_RunningMan::
	.string "I like to run!$"

Route3_EventScript_Fisherman::
	lock
	faceplayer
	msgbox Route3_Text_Fisherman, MSGBOX_DEFAULT
	closemessage
	release
	end

Route3_Text_Fisherman::
	.string "I like to fish!$"

@SIGNS 

Route3_EventScript_SignToRoute5::
	msgbox Route3_Text_SignToRoute5, MSGBOX_SIGN
	end

Route3_Text_SignToRoute5::
	.string "{LEFT_ARROW} Route 5$"

Route3_EventScript_SignToRoute4::
	msgbox Route3_Text_SignToRoute4, MSGBOX_SIGN
	end

Route3_Text_SignToRoute4::
	.string "{UP_ARROW} Route 4$"
