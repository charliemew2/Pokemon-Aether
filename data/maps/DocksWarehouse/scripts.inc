DocksWarehouse_MapScripts::
	.byte 0

DocksWarehouse_EventScript_PostExplosionConversation::
	lock
	msgbox DocksWarehouse_Text_TalktoGrunt1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_WAREHOUSE_GRUNT, Common_Movement_FaceLeft
	waitmovement 0
	msgbox DocksWarehouse_Text_TalktoGrunt2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_WAREHOUSE_WORKER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox DocksWarehouse_Text_TalktoGrunt3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_WAREHOUSE_GRUNT, Common_Movement_FaceDown
	applymovement LOCAL_ID_WAREHOUSE_WORKER, Common_Movement_FaceUp
	waitmovement 0
	setflag FLAG_SPOKETOGRUNTAT_DOCKS
	release
	end

DocksWarehouse_Text_TalktoGrunt1::
	.string "Shady Guy: You idiots! What do you\n"
	.string "mean it escaped?\p"
	.string "Worker: I'm sorry man. When the\n"
	.string "generator blew out, the power\l"
	.string "surged and it activated on its own\l"
	.string "and...\p"
	.string "Shady Guy: I don't need your\n"
	.string "excuses! What the hell am I gonna\l"
	.string "tell my boss?!$"

DocksWarehouse_Text_TalktoGrunt2::
	.string "Kid! Don't easedrop!\l"
	.string "Didn't your parents teach you any\n"
	.string "manners growing up?!$"

DocksWarehouse_Text_TalktoGrunt3::
	.string "Hey sorry kid. Is that your friend\n"
	.string "who went into the basement?\p"
	.string "I'm a bit busy trying to calm this\n"
	.string "guy down...\p"
	.string "Can you get your friend and leave?$"

DocksWarehouse_EventScript_SetRepelforCharlieCutscene::
	setflag FLAG_REPELTOGGLE
	end

DocksWarehouse_EventScript_WarehouseWorkerPostCutscene::
	lock
	faceplayer
	msgbox DocksWarehouse_Text_WarehouseWorkerPostCutsceneDialogue, MSGBOX_DEFAULT
	closemessage
	release
	end

DocksWarehouse_Text_WarehouseWorkerPostCutsceneDialogue::
	.string "The generator will be easy enough\n"
	.string "to repair.\p"
	.string "Fixing the wall will be a whole\n"
	.string "different story.\p"
	.string "We're going to have wild Pokémon\n"
	.string "getting through any barrier we\l"
	.string "put up.\p"
	.string "Hopefully we can fix it soon.\l"
	.string "I have a headache. That guy who\n"
	.string "was here earlier was supposed to\l"
	.string "pick up his cargo.\p"
	.string "Honestly between you and me, he\n"
	.string "seemed kinda shady.\p"
	.string "But his name was on the order and\n"
	.string "everything.\p"
	.string "My boss is gonna kill me. This has\n"
	.string "been a miserable week already.$"
