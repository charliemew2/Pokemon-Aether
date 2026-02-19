BlossomwoodTown_House2_MapScripts::
	.byte 0

BlossomwoodTown_House2_EventScript_Bugcatcher::
	lock
	faceplayer
	msgbox BlossomwoodTown_House2_Text_Bugcatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

BlossomwoodTown_House2_Text_Bugcatcher::
	.string "Some bug Pokémon help our flowers\n"
	.string "grow when they travel through.\p"
	.string "Some eat them and some pollinate\n"
	.string "them, some spread more plants or\l"
	.string "help us water them.\p"
	.string "The relationship between humans,\n"
	.string "Pokémon, and the earth is really\l"
	.string "magical.$"
