BlossomwoodTown_House1_MapScripts::
	.byte 0

BlossomwoodTown_House1_EventScript_Father::
	lock
	faceplayer
	msgbox BlossomwoodTown_House1_Text_Father, MSGBOX_DEFAULT
	closemessage
	release
	end

BlossomwoodTown_House1_Text_Father::
	.string "When my wife passed, my son and I\n"
	.string "planted a garden in her memory\l"
	.string "with the Gracedia we grow yearly.\p"
	.string "We've both dealt with her passing\n"
	.string "in our own ways, but seeing the\l"
	.string "Gracedia every year helps us feel\l"
	.string "grateful for the time she was in\l"
	.string "our lives.\p"
	.string "Flowers bloom, die, and regrow.\l"
	.string "Humans cannot regrow, but they\n"
	.string "can live on in memories.$"

BlossomwoodTown_House1_EventScript_Son::
	lock
	faceplayer
	msgbox BlossomwoodTown_House1_Text_Son, MSGBOX_DEFAULT
	closemessage
	release
	end

BlossomwoodTown_House1_Text_Son::
	.string "I've decided to make a pilgrimage\n"
	.string "one day when I become a strong\l"
	.string "Pokémon Trainer.\p"
	.string "I'd like to plant my mother's\n"
	.string "favorite flowers all over Kusho.\p"
	.string "She would have loved to see how\n"
	.string "they bloomed all over the world!$"
