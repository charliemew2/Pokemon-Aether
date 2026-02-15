MountainSpring_MapScripts::
	.byte 0

MountainSpring_EventScript_ToggleConstructionGuardOutFront::
	addvar VAR_MOVE_GUY_ROUTE_1, 1
	setflag FLAG_HIDE_SPRING_GUARD
	end

MountainSpring_EventScript_BlackBeltGiveSmackDownTM::
	lock
	goto_if_set FLAG_GIVES_TM01_SMACK_DOWN, MountainSpring_EventScript_BlackBeltGaveSmackDownTM
	faceplayer
	msgbox MountainSpring_Text_BlackBeltGiveSmackDownTM, MSGBOX_DEFAULT
	closemessage
	call MountainSpring_giveitem_TM01
	msgbox MountainSpring_Text_BlackBeltGaveSmackDownTM, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GIVES_TM01_SMACK_DOWN
	release
	end

MountainSpring_Text_BlackBeltGiveSmackDownTM::
	.string "Oh hey! I thought I saw you walk\n"
	.string "by earlier on Route 1.\p"
	.string "Sorry about blocking the way for\n"
	.string "so long. Take this as an apology!$"

MountainSpring_EventScript_BlackBeltGaveSmackDownTM::
	lock
	faceplayer
	msgbox MountainSpring_Text_BlackBeltGaveSmackDownTM, MSGBOX_DEFAULT
	closemessage
	release
	end

MountainSpring_giveitem_TM01::
	giveitem ITEM_TM01
	return

MountainSpring_Text_BlackBeltGaveSmackDownTM::
	.string "That right there is the TM for the\n"
	.string "move Smack Down!\p"
	.string "It'll send flying types straight to\n"
	.string "the ground.$"

