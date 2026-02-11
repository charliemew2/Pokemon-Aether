CableCarRoute2Station_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CableCarRoute2Station_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableCarRoute2Station_OnFrame
	.byte 0

CableCarRoute2Station_OnTransition:
	@setescapewarp MAP_ROUTE2, 4, 11
	call_if_eq VAR_CABLE_CAR_STATION_STATE, 2, CableCarRoute2Station_EventScript_MoveAttendantAside
	end

CableCarRoute2Station_EventScript_MoveAttendantAside::
	setobjectxyperm LOCAL_ID_ROUTE2ATTENDENT, 5, 4
	setobjectmovementtype LOCAL_ID_ROUTE2ATTENDENT, MOVEMENT_TYPE_FACE_RIGHT
	return

CableCarRoute2Station_OnFrame:
	map_script_2 VAR_CABLE_CAR_STATION_STATE, 2, CableCarRoute2Station_EventScript_ExitCableCar
	.2byte 0

CableCarRoute2Station_EventScript_ExitCableCar::
	lockall
	applymovement LOCALID_PLAYER, CableCarRoute2Station_Movement_ExitCableCar
	applymovement LOCAL_ID_ROUTE2ATTENDENT, CableCarRoute2Station_Movement_FollowPlayerOutFromCableCar
	waitmovement 0
	setvar VAR_CABLE_CAR_STATION_STATE, 0
	setobjectxyperm LOCAL_ID_ROUTE2ATTENDENT, 6, 7
	setobjectmovementtype LOCAL_ID_ROUTE2ATTENDENT, MOVEMENT_TYPE_FACE_DOWN
	releaseall
	end

CableCarRoute2Station_EventScript_Attendant::
	lock
	faceplayer
	msgbox CableCarRoute2Station_Text_CableCarReadyGetOn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CableCarRoute2Station_EventScript_RideCableCar
	goto_if_eq VAR_RESULT, NO, CableCarRoute2Station_EventScript_DeclineRide
	end

CableCarRoute2Station_EventScript_RideCableCar::
	msgbox CableCarRoute2Station_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_ROUTE2ATTENDENT, CableCarRoute2Station_Movement_LeadPlayerToCableCar
	applymovement LOCALID_PLAYER, CableCarRoute2Station_Movement_BoardCableCar
	waitmovement 0
	setvar VAR_0x8004, FALSE  @ Going up
	setvar VAR_CABLE_CAR_STATION_STATE, 1
	incrementgamestat GAME_STAT_RODE_CABLE_CAR
	special CableCarWarp
	special CableCar
	waitstate
	release
	end

CableCarRoute2Station_EventScript_DeclineRide::
	msgbox CableCarRoute2Station_Text_RideAnotherTime, MSGBOX_DEFAULT
	release
	end

CableCarRoute2Station_Movement_LeadPlayerToCableCar:
	walk_up
	walk_up
	walk_left
	walk_in_place_faster_right
	step_end

CableCarRoute2Station_Movement_FollowPlayerOutFromCableCar:
	delay_16
	walk_right
	walk_down
	walk_down
	step_end

CableCarRoute2Station_Movement_BoardCableCar:
	walk_up
	walk_up
	walk_up
	delay_16
	step_end

CableCarRoute2Station_Movement_ExitCableCar:
	walk_down
	walk_down
	walk_down
	delay_16
	step_end

CableCarRoute2Station_Text_CableCarReadyGetOn:
	.string "The CABLE CAR is ready to go up.\n"
	.string "Would you like to be on it?$"

CableCarRoute2Station_Text_StepThisWay:
	.string "Please step this way.$"

CableCarRoute2Station_Text_RideAnotherTime:
	.string "Please ride with us another time.$"

