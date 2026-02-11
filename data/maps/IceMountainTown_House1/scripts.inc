IceMountainTown_House1_MapScripts::
	.byte 0

IceMountainTown_EventScript_OldWomen::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_ASPEAR_BERRY_SNOWCOT, IceMountainTown_EventScript_OldWomenGivesAspear
	msgbox IceMountainTown_Text_OldWomenGaveAspearBerry, MSGBOX_DEFAULT
	closemessage
	release
	end

IceMountainTown_EventScript_OldWomenGivesAspear::
	msgbox IceMountainTown_Text_OldWomenGivesAspearBerry, MSGBOX_DEFAULT
	closemessage
	call IceMountainTown_giveitem_Aspear_Berry
	setflag FLAG_RECEIVED_ASPEAR_BERRY_SNOWCOT
	msgbox IceMountainTown_Text_OldWomenGaveAspearBerry, MSGBOX_DEFAULT
	closemessage	
	release
	end

IceMountainTown_giveitem_Aspear_Berry::
	giveitem ITEM_ASPEAR_BERRY
	return

IceMountainTown_Text_OldWomenGivesAspearBerry::
	.string "Oh! You're going to go to the\n"
	.string "lower summit?\p"
	.string "Mt. Aeon gets quite cold at this\n"
	.string "time of year. Freezing even!\p"
	.string "My husband and I grow these over\n"
	.string "the warm seasons. Take one!$"

IceMountainTown_Text_OldWomenGaveAspearBerry::
	.string "An Aspear Berry will prevent your\n"
	.string "Pokémon from being frozen.\p"
	.string "You would never not have one of\n"
	.string "these on hand before a fight that\l"
	.string "can freeze you, yes?$"

IceMountainTown_EventScript_OldMan::
	lock
	faceplayer
	msgbox IceMountainTown_Text_OldMan, MSGBOX_DEFAULT
	closemessage
	release
	end

IceMountainTown_Text_OldMan::
	.string "My wife and I chose to retire here\n"
	.string "ten years ago.\p"
	.string "It's been a peaceful life, even\n"
	.string "with the snowfalls causing the\l"
	.string "occasional problem!$"
