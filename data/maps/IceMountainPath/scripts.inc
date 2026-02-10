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

@REGULAR TRAINERS 

IceMountainPath_EventScript_Tristian::
	trainerbattle_single TRAINER_TRISTIAN, IceMountainPath_Text_TristianIntro, IceMountainPath_Text_TristianDefeat
	msgbox IceMountainPath_Text_TristianPostBattle, MSGBOX_AUTOCLOSE
	end

IceMountainPath_Text_TristianIntro::
	.string "Man! I hiked up here from Route 2\n"
	.string "and then was stuck here for hours!\p"
	.string "I'm annoyed...so you're gonna help\n"
	.string "me vent my frustration!$"

IceMountainPath_Text_TristianDefeat::
	.string "Hey hey take it easy! I didn't mean\n"
	.string "to make you so mad!$"

IceMountainPath_Text_TristianPostBattle::
	.string "The path is finally clear?\l"
	.string "Thank goodness...when I catch my\n"
	.string "breath, I can finally hike home...$"

IceMountainPath_EventScript_Nicki::
	trainerbattle_single TRAINER_NICKI, IceMountainPath_Text_NickiIntro, IceMountainPath_Text_NickiDefeat
	msgbox IceMountainPath_Text_NickiPostBattle, MSGBOX_AUTOCLOSE
	end

IceMountainPath_Text_NickiIntro::
	.string "I perform maintenance on the\n"
	.string "power lines up here.\p"
	.string "What, you think the town down\n"
	.string "south just magically has that?$"

IceMountainPath_Text_NickiDefeat::
	.string "Power down!$"

IceMountainPath_Text_NickiPostBattle::
	.string "I have to travel up here every\n"
	.string "month! I should consider moving\l"
	.string "here at this point!$"

IceMountainPath_EventScript_Poodle::
	trainerbattle_single TRAINER_POODLE, IceMountainPath_Text_PoodleIntro, IceMountainPath_Text_PoodleDefeat
	msgbox IceMountainPath_Text_PoodlePostBattle, MSGBOX_AUTOCLOSE
	end

IceMountainPath_Text_PoodleIntro::
	.string "Oh...I came for a walk but got a\n"
	.string "little bit lost...\p"
	.string "Mind if I let my puppies off their\n"
	.string "leashes for a bit?$"

IceMountainPath_Text_PoodleDefeat::
	.string "Oh no! I was all bark no bite!$"

IceMountainPath_Text_PoodlePostBattle::
	.string "The walk home will be quite the\n"
	.string "trip for my poor little guys...\p"
	.string "Thank goodness for the clinic\n"
	.string "in SnowCot!$"

@SIGNS

IceMountainPath_EventScript_Sign1::
	msgbox IceMountainPath_Text_Sign1, MSGBOX_SIGN
	end

IceMountainPath_Text_Sign1::
	.string "Be wary of snow drifts!\l"
	.string "On windy days, stick to the middle\n"
	.string "of the path$"

IceMountainPath_EventScript_Sign2::
	msgbox IceMountainPath_Text_Sign2, MSGBOX_SIGN
	end

IceMountainPath_Text_Sign2::
	.string "{UP_ARROW} Summit ahead."

IceMountainPath_EventScript_Sign3::
	msgbox IceMountainPath_Text_Sign3, MSGBOX_SIGN
	end

IceMountainPath_Text_Sign3::
	.string "{DOWN_ARROW} SnowCot Town."
