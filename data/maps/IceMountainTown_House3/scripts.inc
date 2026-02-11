IceMountainTown_House3_MapScripts::
	.byte 0

IceMountainTown_EventScript_HouseGuy::
	lock
	faceplayer
	msgbox IceMountainTown_Text_HouseGuy, MSGBOX_DEFAULT
	closemessage
	release
	end

IceMountainTown_Text_HouseGuy::
	.string "This town is situated on the lower\n"
	.string "peak of Mt. Aeon.\p"
	.string "Nobody has ever been able to climb\n"
	.string "to the higher peak on the western\l"
	.string "side of the mountain.\p"
	.string "Don't you think the mystery is so\n"
	.string "fascinating?\p"
	.string "Imagine what sits so high up that\n"
	.string "nobody can climb up there...\p"
	.string "That infinite sea of clouds that\n"
	.string "obscures the peak...$"
