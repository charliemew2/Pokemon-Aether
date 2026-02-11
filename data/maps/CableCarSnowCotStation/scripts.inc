CableCarSnowCotStation_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SnowCotStation_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SnowCotStation_OnFrame
	.byte 0

SnowCotStation_OnTransition:
	setescapewarp MAP_ICE_MOUNTAIN_TOWN, 40, 14
	call_if_eq VAR_CABLE_CAR_STATION_STATE, 1, SnowCotStation_EventScript_MoveAttendantAside
	end

SnowCotStation_EventScript_MoveAttendantAside::
	setobjectxyperm LOCAL_ID_JENNY_AT_WORK, 7, 4
	setobjectmovementtype LOCAL_ID_JENNY_AT_WORK, MOVEMENT_TYPE_FACE_LEFT
	return

SnowCotStation_OnFrame:
	map_script_2 VAR_CABLE_CAR_STATION_STATE, 1, SnowCotStation_EventScript_ExitCableCar
	.2byte 0

SnowCotStation_EventScript_ExitCableCar::
	lockall
	applymovement LOCALID_PLAYER, SnowCotStation_Movement_ExitCableCar
	applymovement LOCAL_ID_JENNY_AT_WORK, SnowCotStation_Movement_FollowPlayerOutFromCableCar
	waitmovement 0
	setvar VAR_CABLE_CAR_STATION_STATE, 0
	setobjectxyperm LOCAL_ID_JENNY_AT_WORK, 6, 7
	setobjectmovementtype LOCAL_ID_JENNY_AT_WORK, MOVEMENT_TYPE_FACE_DOWN
	releaseall
	end

SnowCotStation_EventScript_Attendant::
	lock
	faceplayer
	msgbox SnowCotStation_Text_CableCarReadyGetOn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SnowCotStation_EventScript_RideCableCar
	goto_if_eq VAR_RESULT, NO, SnowCotStation_EventScript_DeclineRide
	end

SnowCotStation_EventScript_RideCableCar::
	msgbox SnowCotStation_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_JENNY_AT_WORK, SnowCotStation_Movement_LeadPlayerToCableCar
	applymovement LOCALID_PLAYER, SnowCotStation_Movement_BoardCableCar
	waitmovement 0
	setvar VAR_0x8004, TRUE  @ Going down
	setvar VAR_CABLE_CAR_STATION_STATE, 2
	incrementgamestat GAME_STAT_RODE_CABLE_CAR
	special CableCarWarp
	special CableCar
	waitstate
	release
	end

SnowCotStation_EventScript_DeclineRide::
	msgbox SnowCotStation_Text_RideAnotherTime, MSGBOX_DEFAULT
	release
	end

SnowCotStation_Movement_LeadPlayerToCableCar:
	walk_up
	walk_up
	walk_left
	walk_in_place_faster_right
	step_end

SnowCotStation_Movement_FollowPlayerOutFromCableCar:
	delay_16
	walk_left
	walk_down
	walk_down
	step_end

SnowCotStation_Movement_BoardCableCar:
	walk_up
	walk_up
	walk_up
	delay_16
	step_end

SnowCotStation_Movement_ExitCableCar:
	walk_down
	walk_down
	walk_down
	delay_16
	step_end

SnowCotStation_Text_CableCarReadyGetOn:
	.string "Oh heya {PLAYER}! Good to see you!\n"
	.string "Want me to get you down to Route\l"
	.string "2? I'll getcha going in a jiffy!$"

SnowCotStation_Text_StepThisWay:
	.string "Step right up to the car and I'll\n"
	.string "getcha down there lickity split!$"

SnowCotStation_Text_RideAnotherTime:
	.string "Maybe next time! I'll be here!$"
