ForestShrine_MapScripts::
	.byte 0

ForestShrine_EventScript_starter_choose::
	lock
	faceplayer
	fadescreen FADE_TO_BLACK
	special ChooseStarter
	waitstate
	release
	end
	