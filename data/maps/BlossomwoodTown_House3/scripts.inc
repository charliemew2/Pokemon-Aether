BlossomwoodTown_House3_MapScripts::
	.byte 0

BlossomwoodTown_House3_EventScript_GamerKid::
	lock
	faceplayer
	msgbox BlossomwoodTown_House3_Text_GamerKid, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_GAMER_KID_BLOSSOMTOWN, Common_Movement_FaceDown
	waitmovement 0
	release
	end

BlossomwoodTown_House3_Text_GamerKid::
	.string "My older sisters are both so into\n"
	.string "plants.\p"
	.string "I'd much rather just stay inside\n"
	.string "and play video games truthfully.\p"
	.string "Living here isn't for me...I want\n"
	.string "to do something with technology\l"
	.string "when I get older and can leave.\p"
	.string "Still, at least it always smells\n"
	.string "nice!$"
