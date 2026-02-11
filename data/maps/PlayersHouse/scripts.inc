PlayersHouse_MapScripts::
	.byte 0

PlayersHouse_EventScript_GrabCandyAndPortaPC::
	lock
	msgbox PlayersHouse_Text_GrabCandyAndPortaPC, MSGBOX_DEFAULT
	closemessage
	call PlayersHouse_giveitem_GrabCandyAndPortaPC
	removeobject LOCAL_ID_PLAYERSSTUFF
	setflag FLAG_GOTCANDIESANDPORTAPC
	release
	end

PlayersHouse_giveitem_GrabCandyAndPortaPC::
	giveitem ITEM_CANDY_BAG
	giveitem ITEM_SUPER_CANDY
	giveitem ITEM_POKEMON_BOX_LINK
	return

PlayersHouse_Text_GrabCandyAndPortaPC::
	.string "You decide to not go out without\n"
	.string "your laptop and your snacks.$"

PlayersHouse_EventScript_DoesPlayerHaveStuff::
	goto_if_unset FLAG_GOTCANDIESANDPORTAPC, PlayersHouse_EventScript_PreventPlayerFromLeaving
	end

PlayersHouse_EventScript_PreventPlayerFromLeaving::
	lock
	msgbox PlayersHouse_Texts_PreventPlayerFromLeaving, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_TEMP_3, VAR_TEMP_4
	call_if_eq VAR_TEMP_3, 5, PlayersHouse_EventScript_KickPlayerbackUp
	call_if_eq VAR_TEMP_3, 6, PlayersHouse_EventScript_KickPlayerbackUp
	release
	end

PlayersHouse_Texts_PreventPlayerFromLeaving::
	.string "You shouldn't leave without your\n"
	.string "laptop and snacks!$"

PlayersHouse_EventScript_KickPlayerbackUp::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	return
