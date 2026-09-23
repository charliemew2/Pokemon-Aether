Sayo_BattleGround_MapScripts::
	.byte 0

Sayo_BattleGround_EventScript_SayoEliteFour::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Sayo_BattleGround_Movement_PlayerAlignstoSayo
	waitmovement 0
	delay 24
	playse SE_EXIT
	addobject LOCAL_ID_SAYOELITEFOURBATTLE
	delay 24
	playbgm MUS_ENCOUNTER_ELITE_FOUR, TRUE
	applymovement LOCAL_ID_SAYOELITEFOURBATTLE, Sayo_BattleGround_Movement_SayoAlignstoPlayer
	waitmovement 0
	delay 24
	msgbox Sayo_BattleGround_Text_SayoPrelude, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SAYO_E4, Sayo_BattleGround_Text_SayoDefeat
	msgbox Sayo_BattleGround_Text_SayoPostBattle, MSGBOX_DEFAULT
	closemessage
	delay 5
	fadedefaultbgm
	release
	end

Sayo_BattleGround_Movement_PlayerAlignstoSayo::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Sayo_BattleGround_Movement_SayoAlignstoPlayer::
	walk_down
	walk_down
	step_end

Sayo_BattleGround_Text_SayoPrelude::
	.string "Hehehe...{PLAYER}! I figured it would be\n"
	.string "you I'd be seeing here over Metalhead!\p"
	.string "I never did get to properly thank you,\n"
	.string "you know? For everything you've done!\p"
	.string "Not just for me, but for my grandpa.\l"
	.string "You know, it's really funny!\l"
	.string "We met in that freezing cold cave as I\n"
	.string "was on my way to meet the three other\l"
	.string "people on this mountain.\p"
	.string "Mew has brought all of us together, in\n"
	.string "one way or another.\p"
	.string "But {PLAYER}! I have a goal, a dream!\l"
	.string "And right now, no matter how friendly we\n"
	.string "may be with one another, we agreed I\l"
	.string "wouldn't be going further up this\l"
	.string "mountain until I defeated whoever came\l"
	.string "up the slope.\p"
	.string "So come on {PLAYER}! Show me that\n"
	.string "fighting spirit that I've come to\l"
	.string "expect from you over this journey!\p"
	.string "Our last battle, I wasn't myself. So now\n"
	.string "you get to witness the new and\l"
	.string "improved Sayo at full power!\p"
	.string "After all, you weren't the only one who\n"
	.string "trained in Ultra Space!\p"
	.string "PREPARE YOURSELF!!$"

Sayo_BattleGround_Text_SayoDefeat::
	.string "...Sigh...\l"
	.string "{PLAYER}...\l"	
	.string "You win fair and square!\l"
	.string "I'm proud to be your rival!$"

Sayo_BattleGround_Text_SayoPostBattle::
	.string "Go on Now!$"
