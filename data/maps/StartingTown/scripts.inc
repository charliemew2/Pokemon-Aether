StartingTown_MapScripts::
	.byte 0

@VAR_STARTER_CUTSCENE
	@0 - Triggers from leaving your house and seeing Mew escort you to the FOREST
	@1 - Triggers Mew seeing you in ForestShrine and guiding you to pick your Starter (Needed to trigger 1st Eve fight)
	@2 - Triggers first Eve Rival Battle (From either tile)
	@3 - Triggers from meeting Eve at the Docks + doing the Warehouse  with Charlie and Dawn and getting the Pokedex/SuperRod/Balls
			@-Final Increment. Completing sequence unlocks the way forward and allows access to the first John fight

@VAR_JOHN_MEETING_TRIGGER
	@0 - First Rival Battle with John - Triggers after the Docks Events clear the blockers after Eve

@SCRIPTS FOR OPENING CUTSCENE WHERE MEW BRINGS PLAYER TO THE FOREST TO GET STARTER

StartingTown_EventScript_MewSpotted::
	lock
	playse SE_PIN
	applymovement LOCAL_ID_MEW_STARTGAME, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCAL_ID_MEW_STARTGAME, Common_Movement_ExclamationMark
	waitmovement 0
	playmoncry SPECIES_MEW, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCAL_ID_MEW_STARTGAME, StartingTown_Movement_MewMovementP1
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	waitmovement 0
	msgbox StartingTown_Text_MewPromptToForest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_MEW_STARTGAME, StartingTown_Movement_MewMovementP2
	waitmovement 0
	removeobject LOCAL_ID_MEW_STARTGAME
	addvar VAR_STARTER_CUTSCENE, 1
	release
	end

StartingTown_Movement_MewMovementP1::
	jump_in_place_right
	jump_in_place_right
	jump_in_place_right
	step_end

StartingTown_Text_MewPromptToForest::
	.string "Mew seems to want to play!\n"
	.string "You should follow it.$"

StartingTown_Movement_MewMovementP2::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

StartingTown_EventScript_YouMustGetStarter::
	msgbox StartingTown_Text_YouShallNotPassTillYouHaveStarter, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_TEMP_3, VAR_TEMP_4
	call_if_eq VAR_TEMP_4, 15, StartingTown_EventScript_KickPlayerbackLeft
	call_if_eq VAR_TEMP_4, 16, StartingTown_EventScript_KickPlayerbackUp
	release
	end

StartingTown_EventScript_KickPlayerbackLeft::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	return

StartingTown_EventScript_KickPlayerbackUp::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	return
	
StartingTown_Text_YouShallNotPassTillYouHaveStarter::
	.string "You probably should follow Mew...$"

@JOHN RIVAL BATTLE

StartingTown_EventScript_JohnAmbush1::
	lock
	addobject LOCAL_ID_JOHN_STARTINGTOWN_RIVAL1
	playbgm MUS_ENCOUNTER_ELITE_FOUR, TRUE
	msgbox StartingTown_Text_JohnCallOutForFirstBattle, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCAL_ID_JOHN_STARTINGTOWN_RIVAL1, StartingTown_Movement_JohnApproachesFirstRivalBattle
	waitmovement 0
	getplayerxy VAR_TEMP_3, VAR_TEMP_4
	call_if_eq VAR_TEMP_4, 13, StartingTown_EventScript_JohnAlignPlayer
	msgbox StartingTown_Text_JohnFirstRivalBattleIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_RIVAL_JOHN_1, StartingTown_Text_JohnFirstRivalBattleDefeat
	msgbox StartingTown_Text_JohnFirstRivalBattlePostBattle, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_TEMP_3, VAR_TEMP_4
	call_if_eq VAR_TEMP_4, 13, StartingTown_EventScript_JohnLeavesAfterRival1TopTile
	getplayerxy VAR_TEMP_3, VAR_TEMP_4
	call_if_eq VAR_TEMP_4, 14, StartingTown_EventScript_JohnLeavesAfterRival1BottomTile
	applymovement LOCAL_ID_JOHN_STARTINGTOWN_RIVAL1, StartingTown_Movement_JohnLeavesAfterRival1
	waitmovement 0
	removeobject LOCAL_ID_JOHN_STARTINGTOWN_RIVAL1
	fadedefaultbgm
	addvar VAR_JOHN_MEETING_TRIGGER, 1
	release
	end

StartingTown_Text_JohnCallOutForFirstBattle::
	.string "Scanning Surroundings...$"

StartingTown_Text_JohnFirstRivalBattleIntro::
	.string "Lifeform detected.\n"
	.string "Species: Human.\p"
	.string "Human is in possession of a\n"
	.string "Pokémon. Occupation: Trainer.\p"
	.string "Trainer: Name given to Humans who\n"
	.string "capture and battle with Pokémon.\p"
	.string "Systems currently possess one\n"
	.string "Pokémon. Combat systems loading...\p"
	.string "Engaging combat with human. Will\n"
	.string "analyze data from battle. Begin.$"

StartingTown_Text_JohnFirstRivalBattleDefeat::
	.string "Initial Observation from combat:\n"
	.string "Humans are strong trainers.\p"
	.string "Solution: Will need to more data in\n"
	.string "order to surpass human trainers.\p"
	.string "Victory is yours.$"

StartingTown_Text_JohnFirstRivalBattlePostBattle::
	.string "That was a splendid battle, human.\l"
	.string "I am a Journey Operational Human\n"
	.string "Droid. A Prototype Mach III.\p"
	.string "My duty is to collect and record\n"
	.string "record human behavior to Pokémon.\p"
	.string "This data will be highly useful in\n"
	.string "my mission.\p"
	.string "Might I record your name in my\n"
	.string "internal database?\p"
	.string "{PLAYER}.\l"
	.string "Opponent registered as: {PLAYER}\l"
	.string "Continue operations elsewhere.\n"
	.string "Farewell.$"

StartingTown_Movement_JohnApproachesFirstRivalBattle::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

StartingTown_EventScript_JohnAlignPlayer::
	applymovement LOCAL_ID_JOHN_STARTINGTOWN_RIVAL1, StartingTown_Movement_AlignJohnPlayer
	waitmovement 0
	return

StartingTown_Movement_AlignJohnPlayer::
	walk_up
	face_right
	step_end

StartingTown_EventScript_JohnLeavesAfterRival1TopTile::
	applymovement LOCAL_ID_JOHN_STARTINGTOWN_RIVAL1, StartingTown_Movement_JohnWalksAroundPlayerAfterRival1TopTile
	waitmovement 0
	return

StartingTown_Movement_JohnWalksAroundPlayerAfterRival1TopTile::
	walk_down
	walk_right
	walk_right
	walk_up
	walk_right
	step_end

StartingTown_EventScript_JohnLeavesAfterRival1BottomTile::
	applymovement LOCAL_ID_JOHN_STARTINGTOWN_RIVAL1, StartingTown_Movement_JohnWalksAroundPlayerAfterRival1BottomTile
	waitmovement 0
	return

StartingTown_Movement_JohnWalksAroundPlayerAfterRival1BottomTile::
	walk_up
	walk_right
	walk_right
	step_end

StartingTown_Movement_JohnLeavesAfterRival1::
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

@ MEW NPC BATTLE

StartingTown_EventScript_EveMeetsPlayerForBattle1::
	lock
	applymovement LOCAL_ID_EVESTARTINGTOWN, Common_Movement_FaceUp
	waitmovement 0
	delay 16
	applymovement LOCAL_ID_EVESTARTINGTOWN, Common_Movement_FaceDown
	waitmovement 0
	delay 16
	applymovement LOCAL_ID_EVESTARTINGTOWN, Common_Movement_FaceLeft
	waitmovement 0
	delay 16
	playse SE_PIN
	applymovement LOCAL_ID_EVESTARTINGTOWN, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	applymovement LOCAL_ID_EVESTARTINGTOWN, StartingTown_Movement_EveJumpsUpandDown
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	waitmovement 0
	delay 32
	getplayerxy VAR_TEMP_3, VAR_TEMP_4
	call_if_eq VAR_TEMP_4, 27, StartingTown_EventScript_EveWalksToPlayerTopTile
	getplayerxy VAR_TEMP_3, VAR_TEMP_4
	call_if_eq VAR_TEMP_4, 28, StartingTown_EventScript_EveWalksToPlayerBottomTile
	msgbox StartingTown_Text_EvePreBattle1, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, StartingTown_EventScript_BattleEveDratini
	case 1, StartingTown_EventScript_BattleEveFrigibax
	case 2, StartingTown_EventScript_BattleEveJangmo_o
	end

StartingTown_EventScript_EvePostBattle1::
	msgbox StartingTown_Text_EvePostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_EVESTARTINGTOWN, StartingTown_Movement_EveJumpsUpandDown
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	waitmovement 0
	applymovement LOCAL_ID_EVESTARTINGTOWN, StartingTown_Movement_EveLeavesForDocks
	waitmovement 0
	removeobject LOCAL_ID_EVESTARTINGTOWN
	addvar VAR_STARTER_CUTSCENE, 1
	release
	end

StartingTown_EventScript_BattleEveDratini::
	trainerbattle_no_intro TRAINER_EVE_STARTINGTOWN_DRATINI, StartingTown_Text_EveDefeat1
	goto StartingTown_EventScript_EvePostBattle1 
	end

StartingTown_EventScript_BattleEveFrigibax::
	trainerbattle_no_intro TRAINER_EVE_STARTINGTOWN_FRIGIBAX, StartingTown_Text_EveDefeat1
	goto StartingTown_EventScript_EvePostBattle1 
	end

StartingTown_EventScript_BattleEveJangmo_o::
	trainerbattle_no_intro TRAINER_EVE_STARTINGTOWN_JANGMO_O, StartingTown_Text_EveDefeat1
	goto StartingTown_EventScript_EvePostBattle1 
	end

StartingTown_Text_EvePreBattle1::
	.string "Hi!\l"
	.string "And you are?\l"
	.string "...\l"
	.string "{PLAYER}! Thats a nice name! My\n"
	.string "name is Eve! Are you a trainer?\p"
	.string	"You are? Me too! I'm kind of new to\n"
	.string "all of this though!\p"
	.string	"Well...Do you wanna play? Battle, I\n"
	.string "mean, hahaha! It'll be fun!\p"
	.string	"Get ready! Here I come!$"

StartingTown_Text_EveDefeat1::
	.string "Woah hang on a second!\l"
	.string "You didn't tell me you were\n"
	.string "this good at battling...\p"
	.string "Hehe...That was fun!$"

StartingTown_Text_EvePostBattle::
	.string "Oof...You got me...\l"
	.string "Thanks for playing with me!\n"
	.string "You're pretty strong {PLAYER}!\p"
	.string "You know, I saw a boat come in at\n"
	.string "the docks down south earlier!\p"
	.string "Rumor has it some really strong\n"
	.string "trainers have come to MYREGION!\p"
	.string "Why don't we go see them?\n"
	.string "It'll be fun! Come on!\p"
	.string "I'll race you there!$"

StartingTown_EventScript_EveWalksToPlayerTopTile::
	applymovement LOCAL_ID_EVESTARTINGTOWN, StartingTown_Movement_EveWalksToPlayerTopTile
	waitmovement 0
	return

StartingTown_Movement_EveWalksToPlayerTopTile::
	walk_left
	walk_down
	walk_left
	step_end

StartingTown_EventScript_EveWalksToPlayerBottomTile::
	applymovement LOCAL_ID_EVESTARTINGTOWN, StartingTown_Movement_EveWalksToPlayerBottomTile
	waitmovement 0
	return

StartingTown_Movement_EveWalksToPlayerBottomTile::
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

StartingTown_Movement_EveLeavesForDocks::
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

StartingTown_Movement_EveJumpsUpandDown::
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	step_end

@ NO PASSING UNTIL DOCKS EVENTS ARE COMPLETED

StartingTown_EventScript_KickPlayerTillDocks::
	msgbox StartingTown_Text_YouShallNotPassTillFinishDocks, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_TEMP_3, VAR_TEMP_4
	call_if_eq VAR_TEMP_4, 26, StartingTown_EventScript_KickPlayerbackDown
	call_if_eq VAR_TEMP_3, 27, StartingTown_EventScript_KickPlayerbackLeft
	release
	end

StartingTown_EventScript_KickPlayerbackDown::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	return
	
StartingTown_Text_YouShallNotPassTillFinishDocks::
	.string "Eve is waiting for you!\n"
	.string "Better hurry to the docks...$"

@FUTURE SCRIPTS
