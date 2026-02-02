MountainSpring_MapScripts::
	.byte 0

MountainSpring_EventScript_ToggleConstructionGuardOutFront::
	addvar VAR_MOVE_GUY_ROUTE_1, 1
	setflag FLAG_HIDE_SPRING_GUARD
	end
