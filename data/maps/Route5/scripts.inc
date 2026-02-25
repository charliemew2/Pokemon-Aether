Route5_MapScripts::
	.byte 0

@VAR ADMIN 2 EVENTS CRYSTAL LAKE

@0 - Eve spots the player
@1 - Triggers Eve vs Loch Cutscenes
@2 - Admin Loch Boss Fight Cutscene


@EVE SPOTS PLAYER

Route5_EventScript_EveSpotsPlayer::
	lock
	applymovement LOCAL_ID_EVE_STANDINGWAITING, Common_Movement_FaceDown
	waitmovement 0
	delay 16
	playse SE_PIN
	applymovement LOCAL_ID_EVE_STANDINGWAITING, Common_Movement_ExclamationMark
	waitmovement 0
	delay 16
	applymovement LOCAL_ID_EVE_STANDINGWAITING, Route5_Movement_EveJumpsAfterSeeingPlayer
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	waitmovement 0	
	getplayerxy VAR_TEMP_3, VAR_TEMP_4
	call_if_eq VAR_TEMP_3, 39, Route5_EventScript_EveAlignsPlayerLeft
	call_if_eq VAR_TEMP_3, 40, Route5_EventScript_EveAlignsPlayerRight
	delay 16
	msgbox Route5_Text_EveSpotsPlayer, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_EVE_STANDINGWAITING, Route5_Movement_EveGoesToFight
	waitmovement 0
	removeobject LOCAL_ID_EVE_STANDINGWAITING
	addvar VAR_CRYSTAL_LAKE_SEQUENCE, 1
	setflag FLAG_HIDEEVE_INTRO_ROUTE5
	release
	end

Route5_Movement_EveJumpsAfterSeeingPlayer::
	jump_in_place_down
	jump_in_place_down
	jump_in_place_down
	step_end

Route5_EventScript_EveAlignsPlayerLeft::
	applymovement LOCAL_ID_EVE_STANDINGWAITING, Route5_Movement_EveAlignsPlayerLeft
	waitmovement 0
	return

Route5_EventScript_EveAlignsPlayerRight::
	applymovement LOCAL_ID_EVE_STANDINGWAITING, Route5_Movement_EveAlignsPlayerRight
	waitmovement 0
	return

Route5_Movement_EveAlignsPlayerLeft::
	walk_right
	walk_down
	walk_down
	step_end

Route5_Movement_EveAlignsPlayerRight::
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

Route5_Text_EveSpotsPlayer::
	.string "{PLAYER}! You made it!\l"
	.string "More of those EVILTEAM creeps are\n"
	.string "around here...\p"
	.string "What!? You ran into that Gaia guy\n"
	.string "on the way here?\p"
	.string "Well I didn't see him! I was flying\n"
	.string "here...er...on foot, as fast as I\l"
	.string "could manage!\p"
	.string "My friend lives at the Crystal\n"
	.string "Lake in a cave under this valley!\p"
	.string "If those EVILTEAM grunts are\n"
	.string "around here, maybe they're trying\l"
	.string "to capture her!\p"
	.string "This is bad {PLAYER}! We have to\n"
	.string "save her if she's in trouble!\p"
	.string "Please help me save her {PLAYER}!\l"
	.string "I'm going to beeline for their\n"
	.string "boss! No time to waste!\p"
	.string "Charge!$"

Route5_Movement_EveGoesToFight::
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

@EVE VS ADMIN LOCH

Route5_EventScript_MeetingLoch::
	lock
	addvar VAR_CRYSTAL_LAKE_SEQUENCE, 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0	
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 16
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, Route5_Movement_CameraPanLeft
	waitmovement 0
	delay 16
	applymovement LOCAL_ID_EVEFIGHTINGLOCH, Route5_Movement_EveLoses
	waitmovement 0
	playse SE_PIN
	applymovement LOCAL_ID_EVEFIGHTINGLOCH, Common_Movement_ExclamationMark
	waitmovement 0
	delay 16
	msgbox Route5_Text_LochPreBossFightCutscene1 MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_LOCH_ROUTE5, Common_Movement_WalkUp
	waitmovement 0
	playse SE_EXIT
	removeobject LOCAL_ID_LOCH_ROUTE5
	setflag FLAG_HIDELOCH_GOESINTOCAVE
	delay 16
	applymovement LOCALID_CAMERA, Route5_Movement_CameraPanRight
	waitmovement 0
	special RemoveCameraObject
	msgbox Route5_Text_LochPreBossFightCutscene2 MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_EVEFIGHTINGLOCH, Common_Movement_FaceRight
	waitmovement 0
	msgbox Route5_Text_LochPreBossFightCutscene3 MSGBOX_DEFAULT
	closemessage
	release
	end

Route5_Movement_CameraPanLeft::
	walk_left
	walk_left
	walk_left
	step_end

Route5_Text_LochPreBossFightCutscene1::
	.string "Eve: Oh no! You're...you're too\n"
	.string "strong...\p"
	.string "Female Admin: Hehe!\l"
	.string "This is a laugh! Kids these days.\l"
	.string "Everyone thinks they can just\n"
	.string "waltz up to some gang and take\l"
	.string "them on one versus a thousand\l"
	.string "ever since that one kid took on\l"
	.string "the mob in Kanto.\p"
	.string "Get real!\l"
	.string "Now go on and cry home to your\n"
	.string "family while us adults get our work\l"
	.string "done.\p"
	.string "I don't know how you snuck past\n"
	.string "our guards, but I guess it doesn't\l"
	.string "matter.\p"
	.string "Now then...\l"
	.string "Hmmm...A hostage would be a lot of\n"
	.string "work.\p"
	.string "With no Pokémon, you're no threat.\l"
	.string "My guards will handle you.\l"
	.string "Later kiddo.\l"
	.string "Hehe... Now then... If you'll excuse\n"
	.string "me... I have an appointment with\l"
	.string "the Earth Guardian of Kusho.$"

Route5_Movement_EveLoses::
	lock_anim
	walk_fast_right
	walk_fast_right
	unlock_anim
	step_end

Route5_Movement_CameraPanRight::
	walk_right
	walk_right
	walk_right
	step_end

Route5_Text_LochPreBossFightCutscene2::
	.string "Eve: Oh no... no no no... nonono...\l"
	.string "If she... If she finds it...\l"
	.string "...Sniff...$"

Route5_Text_LochPreBossFightCutscene3::
	.string "{PLAYER}!\l"
	.string "I'm sorry. I tried to stop her...\l"
	.string "There's no time!\l"
	.string "Please, you have to defeat that\n"
	.string "woman!\p"
	.string "She's really really strong though.\l"
	.string "Go! Go {PLAYER}! I know you can\n"
	.string "defeat her! Save my friend!\p"
	.string "I'll be right behind you!$"

Route5_EventScript_EveWaitsForPlayer::
	lock
	faceplayer
	msgbox Route5_Text_EveWaitsForPlayer, MSGBOX_DEFAULT
	closemessage
	release
	end

Route5_Text_EveWaitsForPlayer::
	.string "{PLAYER}! I'll be right behind you!\n"
	.string "Please save my friend!$"

@NPCS/TRAINERS PRE BOSS FIGHT

Route5_EventScript_AquaGruntEveBeatUp::
	lock
	faceplayer
	msgbox Route5_Text_AquaGruntEveBeatUp, MSGBOX_DEFAULT
	closemessage
	release
	end

Route5_Text_AquaGruntEveBeatUp::
	.string "Argh... I turned my back for one\n"
	.string "second and this kid with a pink\l"
	.string "shirt blitzed past me!\p"
	.string "It was like a mirage! I blinked and\n"
	.string "one second later he was gone...\p"
	.string "And my Pokémon got knocked out\n"
	.string "to boot!\p"
	.string "Ah well, the other grunts will make\n"
	.string "short work of you two.\p"
	.string "Hmph. You're lucky you didn't have\n"
	.string "to deal with me.\p"
	.string "But without Pokémon to fight with,\n"
	.string "I'm the gruntiest of grunts!$"

Route5_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT1_ROUTE5, Route5_Text_Grunt1Intro, Route5_Text_Grunt1Defeated
	msgbox Route5_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	release
	end

Route5_Text_Grunt1Intro::
	.string "Hey you! You aren't a member of\n"
	.string "EVILTEAM!\p"
	.string "This valley's under investigation\n"
	.string "right now.\p"
	.string "No outsiders allowed!$"

Route5_Text_Grunt1Defeated::
	.string "I've dug something up it seems...\n"
	.string "A tough trainer!$"

Route5_Text_Grunt1PostBattle::
	.string "GRK! Loch is gonna have my head\n"
	.string "for losing to a kid...\p"
	.string "I wonder how Gaia's crew is doin...$"

Route5_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT2_ROUTE5, Route5_Text_Grunt2Intro, Route5_Text_Grunt2Defeated
	msgbox Route5_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	release
	end

Route5_Text_Grunt2Intro::
	.string "Our branch leader Loch is digging\n"
	.string "up an entrance to some lake or\l"
	.string "something.\p"
	.string "You better go home. If you make\n"
	.string "her mad, you'll wish you never\l"
	.string "crossed us!\p"
	.string "No?\l"
	.string "Then I'll force you!$"

Route5_Text_Grunt2Defeated::
	.string "No way! You may actually be as\n"
	.string "strong as Loch...$"

Route5_Text_Grunt2PostBattle::
	.string "Gaia and Loch are both radically\n"
	.string "different people.\p"
	.string "They're both equally scary though!\n"
	.string "Kid I'm warning you. Turn back.$"

Route5_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT3_ROUTE5, Route5_Text_Grunt3Intro, Route5_Text_Grunt3Defeated
	msgbox Route5_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	release
	end

Route5_Text_Grunt3Intro::
	.string "Heh! I knew the two of us standing\n"
	.string "guard together would be useful!\p"
	.string "How do you feel about taking on\n"
	.string "two of us at once?!$"

Route5_Text_Grunt3Defeated::
	.string "Two heads weren't better than one\n"
	.string "after all...$"

Route5_Text_Grunt3PostBattle::
	.string "Dangit! The two of us spent ten\n"
	.string "whole hours getting this combo\l"
	.string "down...\p"
	.string "And then just for some kid to walk\n"
	.string "over it like that...\p"
	.string "Guess this is why we're just lowly\n"
	.string "grunts!$"

Route5_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT4_ROUTE5, Route5_Text_Grunt4Intro, Route5_Text_Grunt4Defeated
	msgbox Route5_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	release
	end

Route5_Text_Grunt4Intro::
	.string "Hah! Right you are! I don't know\n"
	.string "how a trainer got this far, but\l"
	.string "you're going down!\p"
	.string "That wasn't a choice by the way,\n"
	.string "it's a fact!$"

Route5_Text_Grunt4Defeated::
	.string "Oh... so that's how you got this far\n"
	.string "on your own...$"

Route5_Text_Grunt4PostBattle::
	.string "Well, at least having a partner\n"
	.string "means we won't be going down with\l"
	.string "the ship alone when Loch finds out\l"
	.string "we lost to some random trainer...$"
