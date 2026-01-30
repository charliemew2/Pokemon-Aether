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
	addvar VAR_SPLIT1EVENTS, 1	
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
	.string "Hmmm...Oh? Hey hey! I did NOT think\n"
	.string "I'd meet anyone on the climb here.\p"
	.string "So you're heading for ICETOWN?\l"
	.string "It's pretty dang cold out there.\n"
	.string "Actually, it's chilly in here too...\p"
	.string "Oh yeah. My name's Sayo! You must\n"
	.string "be tough if you're climbing eh?\p"
	.string "I like tough people! Why don't we\n"
	.string "battle? It may warm me up! HI-YA!$"

IceMountain3F_Text_SayoDefeat:
	.string "Ugh...Losing really sucks!...\l"
	.string "Guess it was a bit more than a\n"
	.string "little warmup huh?\p"
	.string "Who are you? You're pretty good!$"

IceMountain3F_Text_SayoPostBattleBeforeGivingRepel:
	.string "...\l"
	.string "{PLAYER} huh? Ahaha...I was right!\l"
	.string "You really ARE tough! I knew my\n"
	.string "eyes never lie!\p"
	.string "I'm something of a treasure\n"
	.string "hunter ya see. \p"
	.string	"I'm searching for a rare Pokémon!\l"
	.string "Ugh I don't really wanna go back\n"
	.string "to the Pokémon center though.\p"
	.string "This is why I'm glad I have this!\n"
	.string "Actually you can have one too.$"

IceMountain3F_giveitem_InfiniteRepel:
	giveitem ITEM_REPELLENT
	return

IceMountain3F_Text_SayoPostBattleAfterGivingRepel:
	.string "That's an Infinite Repel.\l"
	.string "It'll keep Wild Pokémon away as\n"
	.string "long as you keep it activated!\p"
	.string "It's an explorer's best friend!\l"
	.string "I have a feeling we will be seeing each\n"
	.string "other again at some point.\p"
	.string "Stay warm ok? Seeya later!$"
