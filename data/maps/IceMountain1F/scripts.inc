IceMountain1F_MapScripts::
	.byte 0


IceMountain1F_EventScript_HikerRiley::
	trainerbattle_single TRAINER_HIKERRILEY, IceMountain1F_Text_RileyIntro, IceMountain1F_Text_RileyDefeat
	msgbox IceMountain1F_Text_RileyPostBattle, MSGBOX_AUTOCLOSE
	end

IceMountain1F_Text_RileyIntro::
	.string "I like me a good day in the caves.\l"
	.string "But spending too long in them will\n"
	.string "drive a guy batty!!$"

IceMountain1F_Text_RileyDefeat::
	.string "Oh bats...I mean rats!$"

IceMountain1F_Text_RileyPostBattle::
	.string "Listen, when you spend as long of\n"
	.string "a time caving as I have, you'd\l"
	.string "understand why I may be a bit\l"
	.string "batty at this point!!$"

IceMountain1F_EventScript_RangerBrent::
	trainerbattle_single TRAINER_RANGERBRENT, IceMountain1F_Text_BrentIntro, IceMountain1F_Text_BrentDefeat
	msgbox IceMountain1F_Text_BrentPostBattle, MSGBOX_AUTOCLOSE
	end

IceMountain1F_Text_BrentIntro::
	.string "Did you know? This mountain has\n"
	.string "two peaks!\p"
	.string "Race ya to the lower summit!!$"

IceMountain1F_Text_BrentDefeat::
	.string "Oh no! I got overtaken too quick...$"

IceMountain1F_Text_BrentPostBattle::
	.string "Did you know?\l"
	.string "Nobody has ever reached the\n"
	.string "highest peak of ICEMOUNTAIN!\p"
	.string "Why do you think that is?!$"
