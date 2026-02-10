IceMountainSummit_MapScripts::
	.byte 0

IceMountainSummit_EventScript_KristineBossFightPreperation::
	lock
	msgbox IceMountainSummit_Text_KristineBossFightPreperation, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, IceMountainSummit_EventScript_RetreatToPrepareKristine
	case YES, IceMountainSummit_EventScript_KristineBossFight
	release
	end

IceMountainSummit_Text_KristineBossFightPreperation::
	.string "A cold wind washes over your body.\n"
	.string "You see someone up ahead.\p"
	.string "Confront them?$"

IceMountainSummit_EventScript_RetreatToPrepareKristine::
	msgbox IceMountainSummit_Text_YouShouldPrepareBeforeKristine, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	release
	end

IceMountainSummit_Text_YouShouldPrepareBeforeKristine::
	.string "You decide to take a moment to\n"
	.string "better prepare...$"

IceMountainSummit_EventScript_KristineBossFight::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, IceMountainSummit_Movement_PlayerApproachesKristine
	waitmovement 0
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, IceMountainSummit_Movement_CameraPanUp
	waitmovement 0
	msgbox IceMountainSummit_Text_KristineText1, MSGBOX_DEFAULT
	closemessage
	delay 16
	applymovement LOCAL_ID_KRISTINE_ICEMOUNTAIN, IceMountainSummit_Movement_KristinePacesNoticesPlayer
	waitmovement 0
	delay 8
	playse SE_PIN
	applymovement LOCAL_ID_KRISTINE_ICEMOUNTAIN, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox IceMountainSummit_Text_KristineText2, MSGBOX_DEFAULT
	applymovement LOCAL_ID_KRISTINE_ICEMOUNTAIN, IceMountainSummit_Movement_KristineStartled
	closemessage
	waitmovement 0
	delay 8
	msgbox IceMountainSummit_Text_KristineText3, MSGBOX_DEFAULT
	closemessage
	delay 8
	applymovement LOCAL_ID_KRISTINE_ICEMOUNTAIN, Common_Movement_WalkDown
	applymovement LOCALID_CAMERA, IceMountainSummit_Movement_CameraPanDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement LOCALID_CAMERA
	special RemoveCameraObject
	delay 8
	msgbox IceMountainSummit_Text_KristineText4, MSGBOX_DEFAULT
	closemessage
	addvar VAR_ICEMOUNTAIN_EVENTS, 1
	trainerbattle_no_intro TRAINER_KRISTINEICEMOUNTAIN, IceMountainSummit_Text_KristineDefeat
	delay 8
	applymovement LOCAL_ID_KRISTINE_ICEMOUNTAIN, IceMountainSummit_Movement_KristineStartled
	waitmovement 0
	msgbox IceMountainSummit_Text_KristineTextPost1, MSGBOX_DEFAULT
	closemessage
	delay 16
	delay 16
	applymovement LOCAL_ID_KRISTINE_ICEMOUNTAIN, Common_Movement_FaceLeft
	waitmovement 0
	delay 16
	delay 16
	applymovement LOCAL_ID_KRISTINE_ICEMOUNTAIN, Common_Movement_WalkDown
	waitmovement 0
	delay 8
	msgbox IceMountainSummit_Text_KristineTextPost2, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_KRISTINE_ESCORT
	warp MAP_ICE_MOUNTAIN_TOWN, 12, 5
	release
	end

IceMountainSummit_Movement_PlayerApproachesKristine::
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

IceMountainSummit_Movement_CameraPanUp::
	walk_up
	walk_up
	step_end

IceMountainSummit_Text_KristineText1::
	.string "...Sigh...\l"
	.string "Why will she just not understand?\p"
	.string "There's so much out there that I\n"
	.string "want to see but...$"

IceMountainSummit_Movement_KristinePacesNoticesPlayer::
	walk_left
	walk_right
	walk_right
	walk_left
	walk_left
	walk_right
	face_up
	delay_16
	delay_16
	face_down
	step_end

IceMountainSummit_Movement_KristineStartled::
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	step_end

IceMountainSummit_Text_KristineText2::
	.string "ACK!$"

IceMountainSummit_Text_KristineText3::
	.string "Oh, hello. Um, who are you?\l"
	.string "...\l"
	.string "You're a trainer!\l"
	.string "...Oh. Jenny sent you?\l"
	.string "...\l"
	.string "Um, do you mind helping me out with\n"
	.string "a little problem I've been having?\p"
	.string "I assume Jenny told you to tell\n"
	.string "me she's sorry. And that she told\l"
	.string "you we had an argument.\p"
	.string "Well, I'll explain.\l"
	.string "I want to leave this mountain.\l"
	.string "I've lived here my whole life, and\n"
	.string "I love my sister dearly.\p"
	.string "So I told her I was going to leave.\l"
	.string "We both have done everything\n"
	.string "together, always. But...I want to\l"
	.string "see the world. There's so much of\l"
	.string "Kusho I want to see...\p"
	.string "But, she's worried I can't handle\n"
	.string "myself. She's wrong!\p"
	.string "What is your er...name?\l"
	.string "...\l"
	.string "{PLAYER}. Mkay. So {PLAYER}, I\n"
	.string "need to battle with you.\p"
	.string "You're a trainer, so you've been\n"
	.string "battling, and have experience\l"
	.string "traveling.\p"
	.string "If I can beat someone like you,\n"
	.string "that my sister trusted to send\l"
	.string "after me...\p"
	.string "Then she'll see that I'm ready to\n"
	.string "get the heck out of here.$"

IceMountainSummit_Movement_CameraPanDown::
	walk_down
	step_end

IceMountainSummit_Text_KristineText4::
	.string "I'm warning you though. I'm the\n"
	.string "strongest trainer on this peak!\p"
	.string "Sometimes I get lucky and battle\n"
	.string "passerbys who come through on\l"
	.string "the lifts...\p"
	.string "...But they're always so weak!\l"
	.string "You...I kind of get the feeling you\n"
	.string "are the kind of challenge I need.\p"
	.string "Um...Well...Here we go...\l"
	.string "Prepare to be frozen by my icy\n"
	.string "prowess!... Did that sound cool?$"

IceMountainSummit_Text_KristineDefeat::
	.string "I...Lost...$"

IceMountainSummit_Text_KristineTextPost1::
	.string "D...Damnit...\l"
	.string "You...You're really strong...$"

IceMountainSummit_Text_KristineTextPost2::
	.string "Well...I'll go back to Jenny I guess.\l"
	.string "It's actually um...been a while\n"
	.string "since I lost a battle.\p"
	.string "Still, I think I held my own pretty\n"
	.string "well huh?\p"
	.string "I guess I have a lot more to learn.\l"
	.string "Mmm...This is even more motivating.\l"
	.string "Sorry. Sorry. Let's go back to\n"
	.string "town and talk to my sister.\p"
	.string "Oh, and um...thanks for the battle.$"

@ALL TRAINERS HERE DO NOT HAVE THE RESPECTIVE CLASSES/SPRITES THEY NEED. LAYLA SHOULD BE - MEDIUM AND OLD WOMAN, DESMOND AND JONAH
@SHOULD BE SKIER CLASS - ALL ARE CUSTOM

IceMountainSummit_EventScript_SkierDesmond::
	trainerbattle_single TRAINER_DESMOND, IceMountainSummit_Text_DesmondIntro, IceMountainSummit_Text_DesmondDefeat
	msgbox IceMountainSummit_Text_DesmondPostBattle, MSGBOX_AUTOCLOSE
	end

IceMountainSummit_Text_DesmondIntro::
	.string "This peak is one of the best spots\n"
	.string "to ski in the whole region!\p"
	.string "Lemme show you how I've trained\n"
	.string "on these slopes!$"

IceMountainSummit_Text_DesmondDefeat::
	.string "Oof! Right into a rock! That'll\n"
	.string "smart...$"

IceMountainSummit_Text_DesmondPostBattle::
	.string "Huh...guess I'll have to watch for\n"
	.string "strong trainers in addition to\l"
	.string "rocks on the way downhill...$"

IceMountainSummit_EventScript_SkierJonah::
	trainerbattle_single TRAINER_JONAH, IceMountainSummit_Text_JonahIntro, IceMountainSummit_Text_JonahDefeat
	msgbox IceMountainSummit_Text_JonahPostBattle, MSGBOX_AUTOCLOSE
	end

IceMountainSummit_Text_JonahIntro::
	.string "Cold winds...sharp ice, and the\n"
	.string "thrill of a fight!\p"
	.string "What more could you need on a\n"
	.string "beautiful day like today?$"

IceMountainSummit_Text_JonahDefeat::
	.string "A nice day...for you I guess.\n"
	.string "Not a nice day for me to lose...$"

IceMountainSummit_Text_JonahPostBattle::
	.string "Maybe tomorrow we'll have worse\n"
	.string "weather, and I'll win!$"

IceMountainSummit_EventScript_MediumLayla::
	trainerbattle_single TRAINER_LAYLA, IceMountainSummit_Text_LaylaIntro, IceMountainSummit_Text_LaylaDefeat
	msgbox IceMountainSummit_Text_LaylaPostBattle, MSGBOX_AUTOCLOSE
	end

IceMountainSummit_Text_LaylaIntro::
	.string "Some strange man was out here\n"
	.string "shivering with no warm attire\l"
	.string "yelling about some 'prototype'!\p"
	.string "Only the toughest of minds can\n"
	.string "handle this freezing weather!$"

IceMountainSummit_Text_LaylaDefeat::
	.string "Your mind is much stronger than I\n"
	.string "had originally expected!$"

IceMountainSummit_Text_LaylaPostBattle::
	.string "Robots, shady men, cold weather...\n"
	.string "And then some girl stewing ahead...\l"
	.string "What a day this has been!$"
