StartingTown_MapScripts::
	.byte 0



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
	addvar VAR_SPLIT1EVENTS, 1
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
	removeobject LOCAL_ID_JOHN_STARTINGTOWN_RIVAL1
	fadedefaultbgm
	addvar VAR_SPLIT1EVENTS, 1
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

@FUTURE SCRIPTS


