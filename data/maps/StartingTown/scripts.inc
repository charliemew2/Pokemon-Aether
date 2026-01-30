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

StartingTown_EventScript_JohnAmbush1
	

@FUTURE SCRIPTS


