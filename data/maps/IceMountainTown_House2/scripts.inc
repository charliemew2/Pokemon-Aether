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
	goto_if_set FLAG_ITEM_LITTLE_BOY_GIVES_FIRE_STONE, IceMountainTown_EventScript_SnowCotYoungerBrotherGaveFireStone
	msgbox IceMountainTown_Text_SnowCotLittleBoyDialogue, MSGBOX_DEFAULT
	special	ChoosePartyMon
	call IceMountainTown_giveitem_FireStone
	setflag FLAG_ITEM_LITTLE_BOY_GIVES_FIRE_STONE
	msgbox IceMountainTown_Text_YoungerBrotherGaveFireStone, MSGBOX_DEFAULT
	closemessage
	release
	end

IceMountainTown_Text_SnowCotLittleBoyDialogue::
	.string "Hey! Have you seen the Pokémon\n"
	.string "Capsakid?\p"
	.string "It's so cool! It's a grass type\n"
	.string "that evolves into a fire type!\p"
	.string "I'm too young to be a trainer, but\n"
	.string "I found this Fire Stone that could\l"
	.string "evolve one.\p"
	.string "You can have it!$"

IceMountainTown_giveitem_FireStone::
	giveitem ITEM_FIRE_STONE
	return

IceMountainTown_EventScript_SnowCotYoungerBrotherGaveFireStone::
	lock
	faceplayer
	msgbox IceMountainTown_Text_YoungerBrotherGaveFireStone, MSGBOX_DEFAULT
	closemessage
	release
	end

IceMountainTown_Text_YoungerBrotherGaveFireStone::
	.string "We're from Savvie City! It's warm\n"
	.string "there, and the mountain over it\l"
	.string "never has snow...\p"
	.string "I love coming here! It's cold but\n"
	.string "always really fun!$"
