IceMountainPath_MapScripts::
	.byte 0


IceMountainPath_EventScript_Grunt1Ambush::
	lock
	addobject LOCAL_ID_GRUNT1
	playbgm MUS_ENCOUNTER_AQUA, TRUE
	applymovement LOCAL_ID_GRUNT1, IceMountainPath_Grunt1Moves
	waitmovement 0
	delay 24
	msgbox IceMountainPath_Text_Grunt1Prelude, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BILLY, IceMountainPath_Text_Grunt1Defeat
	msgbox IceMountainPath_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, IceMountainPath_PushPlayer
	applymovement LOCAL_ID_GRUNT1, IceMountainPath_Grunt1leaves
	waitmovement 0
	waitmovement 0
	removeobject LOCAL_ID_GRUNT1
	delay 5
	fadedefaultbgm
	addvar VAR_SPLIT1EVENTS, 1	
	release
	end

IceMountainPath_Text_Grunt1Prelude:
	.string "Feh! This mountain is nothing\n"
	.string "but a disappointing waste of time!\p"
	.string "Wasn't there supposed to be a rare\n"
	.string "Pokémon around these parts?\p"
	.string "I'm already in a bad mood because of\n"
	.string "that blonde chick on the summit...\p"
	.string "She almost pulverized me! That shy\n"
	.string "attitude she has is an act!\p"
	.string "You!\l"
	.string "You're in my way! Get outta here\n"
	.string "before I MAKE you! We're battlin!$"


IceMountainPath_Text_Grunt1Defeat:
	.string "ARRRRGH!!!! What the heck?\l"
	.string "Since when did kids get so god\n"
	.string "damn strong!?$"


IceMountainPath_Text_Grunt1PostBattle:
	.string "You stay out of our way!$"

IceMountainPath_Grunt1Moves::
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

IceMountainPath_Grunt1leaves::
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

IceMountainPath_PushPlayer::
	walk_left
	face_right
	step_end
