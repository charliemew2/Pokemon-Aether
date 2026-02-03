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

Route1_EventScript_CamperDavid::
	trainerbattle_single TRAINER_CAMPERDAVID, Route1_text_DavidIntro, Route1_text_DavidDefeated
	msgbox Route1_text_DavidPostBattle, MSGBOX_AUTOCLOSE
	release
	end

Route1_EventScript_CamperBenson::
	trainerbattle_single TRAINER_BENSON, Route1_text_BensonIntro, Route1_text_BensonDefeated
	msgbox Route1_text_BensonPostBattle, MSGBOX_AUTOCLOSE
	release
	end

Route1_EventScript_HikerYodel::
	trainerbattle_single TRAINER_YODEL, Route1_Text_YodelIntro, Route1_Text_YodelDefeat
	msgbox Route1_Text_YodelPostBattle, MSGBOX_AUTOCLOSE
	release
	end
