IceMountain2F_MapScripts::
	.byte 0

IceMountain2F_EventScript_CamperBrianna::
	trainerbattle_single TRAINER_BRIANNA, IceMountain2F_Text_BriannaIntro, IceMountain2F_Text_BriannaDefeat
	msgbox IceMountain2F_Text_BriannaPostBattle, MSGBOX_AUTOCLOSE
	end

IceMountain2F_Text_BriannaIntro::
	.string "Know what's more fun than having\n"
	.string "a one on one Pokémon battle?\p"
	.string "Having a two on two Pokémon\n"
	.string "battle!$"

IceMountain2F_Text_BriannaDefeat::
	.string "Ah! But losing two on two means\n"
	.string "double the sadness...!$"

IceMountain2F_Text_BriannaPostBattle::
	.string "Double battles are pretty fun to\n"
	.string "figure out once you get used to\l"
	.string "them, in my opinion.$"
