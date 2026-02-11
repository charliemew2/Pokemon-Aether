IceMountainTown_House2_MapScripts::
	.byte 0

IceMountainTown_EventScript_BigSister::
	lock
	faceplayer
	msgbox IceMountainTown_Text_BigSister, MSGBOX_DEFAULT
	closemessage
	release
	end

IceMountainTown_Text_BigSister::
	.string "My family rents this cabin every\n"
	.string "so often here in SnowCot.\p"
	.string "It's fun to see how excited my\n"
	.string "little brother gets to see snow.$"

IceMountainTown_EventScript_YoungerBrother::
	lock
	faceplayer
	msgbox IceMountainTown_Text_YoungerBrother, MSGBOX_DEFAULT
	closemessage
	release
	end

IceMountainTown_Text_YoungerBrother::
	.string "We're from Savvie City! It's warm\n"
	.string "there, and the mountain over it\l"
	.string "never has snow...\p"
	.string "I love coming here! It's cold but\n"
	.string "always really fun!$"
