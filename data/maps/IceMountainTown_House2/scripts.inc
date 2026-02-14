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
	closemessage
	checkspecies SPECIES_CAPSAKID
	goto_if_eq VAR_RESULT, FALSE, IceMountainTown_EventScript_SnowCotYoungerBrotherNoCapsakid
	msgbox IceMountainTown_Text_YoungerBrotherOhCapsakid, MSGBOX_DEFAULT
	call IceMountainTown_giveitem_FireStone
	setflag FLAG_ITEM_LITTLE_BOY_GIVES_FIRE_STONE
	msgbox IceMountainTown_Text_YoungerBrotherGaveFireStone, MSGBOX_DEFAULT
	closemessage
	release
	end

IceMountainTown_EventScript_SnowCotYoungerBrotherNoCapsakid::
	msgbox IceMountainTown_Text_SnowCotLittleBoyDialogueNoCapsakid, MSGBOX_DEFAULT
	closemessage
	release
	end

IceMountainTown_Text_SnowCotLittleBoyDialogue::
	.string "Hey! Have you seen the Pokémon\n"
	.string "Capsakid? It's a grass type that\l"
	.string "evolves into a fire type!\p"
	.string "They live around this mountain...\l"
	.string "If you showed me one I could give\n"
	.string "you something cool for it!$"

IceMountainTown_Text_SnowCotLittleBoyDialogueNoCapsakid::
	.string "Oh...you don't look like you have\n"
	.string "a Capsakid in your party?\p"
	.string "Well if you catch one, let me know!!$"

IceMountainTown_Text_YoungerBrotherOhCapsakid::
	.string "Oh! That's a Capsakid in your\n"
	.string "party right?\p"
	.string "Well a promise is a promise!\n"
	.string "Take this!$"

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
	.string "Capsakid only evolves with a Fire\n"
	.string "Stone! I'm not a trainer so it isn't\l"
	.string "useful to me to hold onto this.\p"
	.string "When I become a trainer one day, I\n"
	.string "want to get a Pokémon with a cool\l"
	.string "type!$"
