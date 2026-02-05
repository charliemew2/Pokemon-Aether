IceMountainPath_MapScripts::
	.byte 0

@VAR_ICE_MOUNTAIN_EVENTS LISTING
	@0 - Triggers the first Sayo Fight on F3
	@1 - Unblocks the Avalanche in ICYTOWN to allow passage up the mountain
	@2 - Allows the Grunt to attack the player on the path
	@3 - Kristine defeated - activates Jenny and her make up Cutscene - FINAL VARIABLE

IceMountainPath_EventScript_Grunt1Ambush::
	lock
	addobject LOCAL_ID_GRUNT1
	playbgm MUS_ENCOUNTER_AQUA, TRUE
	applymovement LOCAL_ID_GRUNT1, IceMountainPath_Grunt1Moves
	waitmovement 0
	delay 24
	msgbox IceMountainPath_Text_Grunt1Prelude, MSGBOX_DEFAULT
	goto_if_set FLAG_SPOKETOGRUNTAT_DOCKS, IceMountainPath_EventScript_GruntTextSpokeToPreviously
	goto_if_unset FLAG_SPOKETOGRUNTAT_DOCKS, IceMountainPath_EventScript_GruntTextDidNotSpeaktoBefore
	end

IceMountain_EventScript_StartFightGrunt1::
	trainerbattle_no_intro TRAINER_GRUNT_1, IceMountainPath_Text_Grunt1Defeat
	msgbox IceMountainPath_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, IceMountainPath_PushPlayer
	applymovement LOCAL_ID_GRUNT1, IceMountainPath_Grunt1leaves
	waitmovement 0
	waitmovement 0
	removeobject LOCAL_ID_GRUNT1
	delay 5
	fadedefaultbgm
	addvar VAR_ICEMOUNTAIN_EVENTS, 1	
	release
	end

IceMountainPath_Text_Grunt1Prelude::
	.string "Feh! This mountain has been\n"
	.string "nothing but a disappointing waste\l"
	.string "of my time!\p"
	.string "Today has sucked!\l"
	.string "First they screwed up our delivery\n"
	.string "at the port, now here I am on a wild\l"
	.string "goose chase for a dumb hunk of\l"
	.string "junk that's gone who knows where!$"

IceMountainPath_EventScript_GruntTextSpokeToPreviously::
	delay 16
	playse SE_PIN
	applymovement LOCAL_ID_GRUNT1, Common_Movement_ExclamationMark
	waitmovement 0
	delay 16
	msgbox IceMountainPath_Text_Grunt1PreludeTalkedToInDocks, MSGBOX_DEFAULT
	closemessage
	goto IceMountain_EventScript_StartFightGrunt1
	end

IceMountainPath_Text_Grunt1PreludeTalkedToInDocks::
	.string "Hey...\l"
	.string "Wait a sec.\l"
	.string "You're that eavesdropping kid\n"
	.string "from the harbor!\p"
	.string "Have you been following me?\n"
	.string "I'm not in the mood for this! Get\l"
	.string "the hell out of my way and leave\l"
	.string "me alone!\p"
	.string "You're about to learn that you\n"
	.string "shouldn't mess with EVILTEAM!$"

IceMountainPath_EventScript_GruntTextDidNotSpeaktoBefore::
	msgbox IceMountainPath_Text_Grunt1PreludeDidNotTalkToInDocks, MSGBOX_DEFAULT
	closemessage
	goto IceMountain_EventScript_StartFightGrunt1
	end

IceMountainPath_Text_Grunt1PreludeDidNotTalkToInDocks::
	.string "I'm in such a bad mood already...\n"
	.string "seeing you in front of me is making\l"
	.string "my blood BOIL!\p"
	.string "Get out of my way before I make\n"
	.string "you! We're battling!\p"
	.string "I'll show you how scary members\n"
	.string "of EVILTEAM can be, firsthand!$"

IceMountainPath_Text_Grunt1Defeat::
	.string "ARRRRGH!!!! What the heck?\l"
	.string "Why did you also have to be so\n"
	.string "Arceus-damn strong!?\p"
	.string "Just my luck...$"

IceMountainPath_Text_Grunt1PostBattle::
	.string "Man. I'm steamed. First I lose the\n"
	.string "package...Then I lose to some kid!\p"
	.string "Now I'm going to have to go explain\n"
	.string "to my boss why I'm coming back\l"
	.string "empty handed.\p"
	.string "This is your fault! I'll remember\n"
	.string "your face! EVILTEAM has big plans\l"
	.string "in the works.\p"
	.string "Stay out of our way!$"

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
