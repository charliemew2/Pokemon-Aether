IceMountainTown_Kristine_JennyHouse_2F_MapScripts::
	.byte 0

IceMountainTown_EventScript_KristineAtHome::
	lock
	faceplayer
	msgbox IceMountainTown_Text_KristineAtHome, MSGBOX_DEFAULT
	closemessage
	release
	end

IceMountainTown_Text_KristineAtHome::
	.string "Oh! Hi {PLAYER}! I'm just packing\n"
	.string "before I leave.\p"
	.string "Our parents used to run the\n"
	.string "lifts but they retired a few\l"
	.string "years ago and moved to Unova.\p"
	.string "That's why only my sister and I\n"
	.string "live here.\p"
	.string "Why didn't I go?\l"
	.string "I like mountains. Not cities.\l"
	.string "And plus, Jenny wouldn't wanna\n"
	.string "go either.\p"
	.string "Plus... uh... We had to take\n"
	.string "over the business.\p"
	.string "Mkay, enough chatting. I gotta\n"
	.string "get back to it.\p"
	.string "Good luck on your own journey!$"
