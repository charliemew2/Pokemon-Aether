ForestShrine_MapScripts::
	.byte 0

ForestShrine_EventScript_MewLeadsPlayer::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCAL_ID_MEWFORESTSHRINESTARTGAME, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCAL_ID_MEWFORESTSHRINESTARTGAME, Common_Movement_ExclamationMark
	waitmovement 0
	delay 4
	playmoncry SPECIES_MEW, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCAL_ID_MEWFORESTSHRINESTARTGAME, ForestShrine_Movement_MewJumps1
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	waitmovement 0
	delay 16
	msgbox ForestShrine_Text_MewLeadsPlayertoShrine, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_MEW, CRY_MODE_NORMAL
	waitmoncry
	delay 16
	applymovement LOCAL_ID_MEWFORESTSHRINESTARTGAME, ForestShrine_Movement_MewLeadPlayer1
	applymovement OBJ_EVENT_ID_PLAYER, ForestShrine_Movement_PlayerFollowsMew1
	waitmovement 0
	waitmovement 0
	msgbox ForestShrine_Text_MewatShrineStarterSelect, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_MEWFORESTSHRINESTARTGAME, ForestShrine_Movement_MewMovesAwayFromShrine
	waitmovement 0
	delay 24
	applymovement OBJ_EVENT_ID_PLAYER, ForestShrine_Movement_PlayerWalksUpToBag
	waitmovement 0
	release
	end

ForestShrine_Text_MewLeadsPlayertoShrine::
	.string "Mew wants you to follow it!$"

ForestShrine_Text_MewatShrineStarterSelect::
	.string "It appears that Mew wants you to\n"
	.string "look inside of the old shrine...?$"

ForestShrine_Movement_MewLeadPlayer1::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	face_down
	step_end

ForestShrine_Movement_PlayerFollowsMew1::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	face_up
	step_end

ForestShrine_Movement_MewMovesAwayFromShrine::
	walk_left
	face_right
	step_end

ForestShrine_Movement_PlayerWalksUpToBag::
	walk_up
	walk_up
	step_end

@ SELECTING STARTER POKEMON

ForestShrine_EventScript_starter_choose::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, ForestShrine_EventScript_StarterChosen
	fadescreen FADE_TO_BLACK
	removeobject LOCAL_ID_MEWFORESTSHRINESTARTGAME
	setflag FLAG_SYS_POKEMON_GET
	special ChooseStarter
	waitstate
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 16
	msgbox ForestShrine_Text_MewGoneStartGame, MSGBOX_DEFAULT
	addvar VAR_SPLIT1EVENTS, 1
	release
	end

ForestShrine_EventScript_CheckShrine::
	lock
	applymovement LOCAL_ID_MEWFORESTSHRINESTARTGAME, ForestShrine_Movement_MewJumps2
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	waitmovement 0
	playmoncry SPECIES_MEW, CRY_MODE_NORMAL
	waitmoncry
	msgbox ForestShrine_Text_TalkToMewStartGame, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_TEMP_3, VAR_TEMP_4
	call_if_eq VAR_TEMP_4, 11, StartingTown_EventScript_KickPlayerbackUp
	release
	end

ForestShrine_EventScript_KickPlayerbackUp::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	return

ForestShrine_EventScript_StarterChosen::
	msgbox ForestShrine_Text_StarterChosenText, MSGBOX_DEFAULT
	closemessage
	release
	end

ForestShrine_Text_StarterChosenText::	
	.string "The shrine sits calmly. You decide\n"
	.string "to leave the remaining Pokéballs.$"

ForestShrine_Text_MewGoneStartGame::
.string "Mew appears to have left...$"

ForestShrine_EventScript_ShrineMewNPCStartGame::
	lock
	applymovement LOCAL_ID_MEWFORESTSHRINESTARTGAME, Common_Movement_FaceRight
	playmoncry SPECIES_MEW, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCAL_ID_MEWFORESTSHRINESTARTGAME, ForestShrine_Movement_MewJumps1
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	waitmovement 0
	msgbox ForestShrine_Text_TalkToMewStartGame, MSGBOX_DEFAULT
	closemessage
	release
	end

ForestShrine_Text_TalkToMewStartGame::
	.string "Mew! Mew!\l"
	.string "It appears that Mew wants you to\n"
	.string "look inside of the old shrine...?$"

ForestShrine_Movement_MewJumps1::
	jump_in_place_right
	jump_in_place_right
	jump_in_place_right
	step_end

ForestShrine_Movement_MewJumps2::
	jump_in_place_down
	jump_in_place_down
	jump_in_place_down
	step_end
