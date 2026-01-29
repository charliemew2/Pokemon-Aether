ForestShrine_MapScripts::
	.byte 0

ForestShrine_EventScript_starter_choose::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, ForestShrine_EventScript_StarterChosen
	fadescreen FADE_TO_BLACK
	setflag FLAG_SYS_POKEMON_GET
	special ChooseStarter
	waitstate
	release
	end
	
ForestShrine_EventScript_StarterChosen::
	msgbox ForestShrine_Text_StarterChosenText, MSGBOX_DEFAULT
	closemessage
	release
	end

ForestShrine_Text_StarterChosenText::	
	.string "The shrine sits calmly. You decide\n"
	.string "to leave the remaining Pokéballs.$"
