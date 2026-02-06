MountainPath_MapScripts::
	.byte 0

MountainPath_EventScript_RangerDallas::
	trainerbattle_single TRAINER_DALLAS, MountainPath_Text_DallasIntro, MountainPath_Text_DallasDefeat
	msgbox MountainPath_Text_DallasPostBattle, MSGBOX_AUTOCLOSE
	end

MountainPath_Text_DallasIntro::
	.string "Intro!$"

MountainPath_Text_DallasDefeat::
	.string "Beaten!$"

MountainPath_Text_DallasPostBattle::
	.string "Yay!$"

MountainPath_EventScript_RangerKatrina::
	trainerbattle_single TRAINER_KATRINA, MountainPath_Text_KatrinaIntro, MountainPath_Text_KatrinaDefeat
	msgbox MountainPath_Text_KatrinaPostBattle, MSGBOX_AUTOCLOSE
	end

MountainPath_Text_KatrinaIntro::
	.string "Intro!$"

MountainPath_Text_KatrinaDefeat::
	.string "Beaten!$"

MountainPath_Text_KatrinaPostBattle::
	.string "Yay!$"

MountainPath_EventScript_FishermanDirk::
	trainerbattle_single TRAINER_DIRK, MountainPath_Text_DirkIntro, MountainPath_Text_DirkDefeat
	msgbox MountainPath_Text_DirkPostBattle, MSGBOX_AUTOCLOSE
	end

MountainPath_Text_DirkIntro::
	.string "Intro!$"

MountainPath_Text_DirkDefeat::
	.string "Beaten!$"

MountainPath_Text_DirkPostBattle::
	.string "Yay!$"
