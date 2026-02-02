Route1_MapScripts::
	.byte 0

Route1_EventScript_GuyBlockingSpring::
	lock
	faceplayer
	msgbox Route1_Text_GuyBlockingSpringDialogue, MSGBOX_DEFAULT
	closemessage
	release
	end

Route1_Text_GuyBlockingSpringDialogue::
	.string "Sorry, no letting anyone through.\l"
	.string "Just waiting for my buddy to be\n"
	.string "done collecting some water\l"
	.string "samples from the pond in this\l"
	.string "spring.\p"
	.string "We should be done soon, then you\n"
	.string "can go in. Sorry!$"
