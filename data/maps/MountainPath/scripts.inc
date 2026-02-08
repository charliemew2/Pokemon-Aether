MountainPath_MapScripts::
	.byte 0

MountainPath_EventScript_RangerDallas::
	trainerbattle_single TRAINER_DALLAS, MountainPath_Text_DallasIntro, MountainPath_Text_DallasDefeat
	msgbox MountainPath_Text_DallasPostBattle, MSGBOX_AUTOCLOSE
	end

MountainPath_Text_DallasIntro::
	.string "On the mountain paths, its safety\n"
	.string "first!\p"
	.string "Are your Pokémon capable of\n"
	.string "protecting you in case of an emergency?!$"

MountainPath_Text_DallasDefeat::
	.string "Yours are more than capable!\n"
	.string "Mine need some more training!$"

MountainPath_Text_DallasPostBattle::
	.string "The nearest Pokémon Center is\n"
	.string "quite far away.\p"
	.string "It's very dangerous out here\n"
	.string "because of that. Only skilled\l"
	.string "trainers explore this route.$"

MountainPath_EventScript_RangerKatrina::
	trainerbattle_single TRAINER_KATRINA, MountainPath_Text_KatrinaIntro, MountainPath_Text_KatrinaDefeat
	msgbox MountainPath_Text_KatrinaPostBattle, MSGBOX_AUTOCLOSE
	end

MountainPath_Text_KatrinaIntro::
	.string "I think you'll find that if you\n"
	.string "want to scale this mountain...\p"
	.string "You'll have to plant yourself in\n"
	.string "reality, and take every challenge!$"

MountainPath_Text_KatrinaDefeat::
	.string "I've been uprooted!$"

MountainPath_Text_KatrinaPostBattle::
	.string "Losing...winning, all different\n"
	.string "branches of battles.\p"
	.string "Some grow fruit, some drop off\n"
	.string "and wither!$"

MountainPath_EventScript_FishermanDirk::
	trainerbattle_single TRAINER_DIRK, MountainPath_Text_DirkIntro, MountainPath_Text_DirkDefeat
	msgbox MountainPath_Text_DirkPostBattle, MSGBOX_AUTOCLOSE
	end

MountainPath_Text_DirkIntro::
	.string "I heard there's a spring in this\n"
	.string "mountain.\p"
	.string "Imagine the catch that awaits me\n"
	.string "down there!$"

MountainPath_Text_DirkDefeat::
	.string "The only thing I've caught is a\n"
	.string "strong trainer in the valley!$"

MountainPath_Text_DirkPostBattle::
	.string "Can you believe this? Some guys\n"
	.string "wouldn't let me into the spring!\p"
	.string "Rumor has it there's another way\n"
	.string "in from higher up in the caves...!$"
