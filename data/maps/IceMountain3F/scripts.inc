IceMountain3F_MapScripts::
	.byte 0


IceMountain3F_EventScript_SayoAmbush::
	lock
	playse SE_EXIT
	addobject LOCAL_ID_SAYOICEMOUNTAIN
	delay 24
	playbgm MUS_ENCOUNTER_MAY, TRUE
	applymovement LOCAL_ID_SAYOICEMOUNTAIN, Common_Movement_WalkDown
	waitmovement 0
	delay 24
	msgbox IceMountain3F_Text_SayoPrelude, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SAYO_1, IceMountain3F_Text_SayoDefeat
	msgbox IceMountain3F_Text_SayoPostBattleBeforeGivingRepel, MSGBOX_DEFAULT
	call IceMountain3F_giveitem_InfiniteRepel
	msgbox IceMountain3F_Text_SayoPostBattleAfterGivingRepel, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, IceMountain3F_Movement_PlayerPushedBySayo
	applymovement LOCAL_ID_SAYOICEMOUNTAIN, IceMountain3F_Movement_SayoLeaves
	waitmovement 0
	waitmovement 0
	playse SE_EXIT
	removeobject LOCAL_ID_SAYOICEMOUNTAIN
	delay 5
	fadedefaultbgm
	setflag FLAG_DOCKS_EVENTS_FINISHED_GET_POKEDEX
	addvar VAR_ICEMOUNTAIN_EVENTS, 1
	setflag	FLAG_DEFEATED_SAYO
	release
	end

IceMountain3F_Movement_PlayerPushedBySayo::
	walk_left
	face_right
	walk_right
	face_down
	step_end

IceMountain3F_Movement_SayoLeaves::
	walk_down
	walk_down
	lock_anim
	walk_fast_down
	walk_fast_down
	unlock_anim
	walk_in_place_fast_right
	lock_anim
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	unlock_anim
	walk_in_place_fast_up
	lock_anim
	walk_up
	unlock_anim
	walk_in_place_fast_left
	lock_anim
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	unlock_anim
	walk_in_place_fast_up
	lock_anim
	walk_up
	walk_up
	unlock_anim
	walk_in_place_fast_left
	lock_anim
	walk_fast_left
	step_end

IceMountain3F_Text_SayoPrelude:
	.string "Gangway! Coming through!\l"
	.string "Woah woah!\l"
	.string "Someone's actually coming up to\n"
	.string "this popsicle of a town?\p"
	.string "Ugh. I had to take the long way\n"
	.string "up this whole mountain because \l"
	.string "the chairlifts were down.\p"
	.string "Now I'm late for my rendezvous!\n"
	.string "What a day! What a day!\p"
	.string "...Mmmm?\l"
	.string "Hey! You have Pokéballs! You're a\n"
	.string "trainer yeah?\p"
	.string "I'm already super duper late so...\n"
	.string "to heck with it!\p"
	.string "What do you say to a quick battle\n"
	.string "with me?\p"
	.string "I'm already freezing cold, this\n"
	.string "may warm me up!\p"
	.string "The names Sayo! I'm a treasure\n"
	.string "hunter!...In training!\p"
	.string "There's nothing I like hunting for\n"
	.string "more than a battle!\p"
	.string "Come on! Lets do it! HI-YA!!! $"

IceMountain3F_Text_SayoDefeat:
	.string "Ugh...Losing really sucks!...\l"
	.string "Guess it was a bit more than a\n"
	.string "little warmup huh?$"

IceMountain3F_Text_SayoPostBattleBeforeGivingRepel:
	.string "Who are you? You're pretty good!\l"
	.string "...\l"
	.string "{PLAYER} huh? I  had a sneaking\n"
	.string "suspicion when I laid my eyes on\l"
	.string "you that you were tough.\p"
	.string "Ngh. I'm even more late, but it was\n"
	.string "worth it to have a battle with\l"
	.string "someone like you!\p"
	.string "See, I'm working with some folks to\n"
	.string "track down a rare Pokémon!\p"
	.string "Once I find it, I'll be able to\n"
	.string "fulfill my dream...\p"
	.string "Ok. This was fun and all, but I need\n"
	.string "to get going.\p"
	.string "Huh? I'm not going to go to the\n"
	.string "Pokémon Center to heal up?\p"
	.string "Nahhh. I got one of these babies!\l"
	.string "In fact, I have an extra one. Take\n"
	.string "it! Least I can do to repay you for\l"
	.string "your time battlin' with me and all!$"

IceMountain3F_giveitem_InfiniteRepel:
	giveitem ITEM_REPELLENT
	return

IceMountain3F_Text_SayoPostBattleAfterGivingRepel:
	.string "That's an Infinite Repel.\l"
	.string "It'll keep Wild Pokémon away as\n"
	.string "long as you keep it activated!\p"
	.string "It's an explorer's best friend!\l"
	.string "Ok enough dawdling. I gotta jet!\n"
	.string "{PLAYER}! Lets have a rematch\l"
	.string "sometime!\p"
	.string "Stay warm ok? Seeya later!$"
