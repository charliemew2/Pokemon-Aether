Route4_MapScripts::
	.byte 0

@TRAINERS 

Route4_EventScript_YoungsterTaylor::
	trainerbattle_single TRAINER_YOUNGSTERTAYLOR, Route4_Text_YoungerTaylorIntro, Route4_Text_YoungerTaylorDefeated
	msgbox Route4_Text_YoungerTaylorPostBattle, MSGBOX_AUTOCLOSE
	release
	end

Route4_Text_YoungerTaylorIntro::
	.string "Hey are you a newer trainer?\n"
	.string "We're both beginners!\p"
	.string "Let me show you how a rookie who\n"
	.string "works hard battles!!$"

Route4_Text_YoungerTaylorDefeated::
	.string "Oh no! We're both newbies, but \n"
	.string "you're ahead of me...!$"

Route4_Text_YoungerTaylorPostBattle::
	.string "Some people are just born to be\n"
	.string "better trainers.\p"
	.string "I need a mentor to help me improve\n"
	.string "at a faster rate!$"

Route4_EventScript_YoungsterMikey::
	trainerbattle_single TRAINER_YOUNGSTERMIKEY, Route4_Text_YoungsterMikeyIntro, Route4_Text_YoungsterMikeyDefeated
	msgbox Route4_Text_YoungsterMikeyPostBattle, MSGBOX_AUTOCLOSE
	release
	end

Route4_Text_YoungsterMikeyIntro::
	.string "Have you gotten any fresh honey?\l"
	.string "You can find rare Pokémon with it!\n"
	.string "Let me show you my collection!!$"

Route4_Text_YoungsterMikeyDefeated::
	.string "Oh no! The Pokémon that like honey\n"
	.string "aren't very strong!!$"

Route4_Text_YoungsterMikeyPostBattle::
	.string "I heard its very rare to see a tree\n"
	.string "you can slather with Honey.\p"
	.string "On top of that, it's become much\n"
	.string "more dangerous with wild Ursaring\l"
	.string "running around...!$"

Route4_EventScript_YoungsterLaurenAndJack::
	trainerbattle_single TRAINER_YOUNGCOUPLELARAANDJACK, Route4_Text_YoungCoupleLaraAndJackIntro, Route4_Text_YoungCoupleLaraAndJackDefeated
	msgbox Route4_Text_YoungCoupleLaraAndJackPostBattle, MSGBOX_AUTOCLOSE
	release
	end

Route4_Text_YoungCoupleLaraAndJackIntro::
	.string "My boyfriend and I are good at\n"
	.string "battling together!\p"
	.string "That's what true love is!\l"
	.string "We can never lose when we work in\n"
	.string "harmony!!$"

Route4_Text_YoungCoupleLaraAndJackDefeated::
	.string "Our love wasn't strong enough to\n"
	.string "overpower you!!$"

Route4_Text_YoungCoupleLaraAndJackPostBattle::
	.string "We trained our combination both\n"
	.string "human and Pokémon together, but\l"
	.string "it wasn't enough.\p"
	.string "I guess strong feelings aren't the\n"
	.string "winning formula for battling!$"

@BIG CITY ROADBLOCK

Route4_EventScript_BlockingWayNPCDes::
	callnative LockPlayerFieldControls
	faceplayer
	msgbox Route4_Text_BlockingWayNPCDes, MSGBOX_AUTOCLOSE
	closemessage
	callnative UnlockPlayerFieldControls
	end

Route4_Text_BlockingWayNPCDes::
	.string "This guy is HORRIBLE!\l"
	.string "Dude it's so DISTURBING.\l"
	.string "Fuck Schmobots man...$"

Route4_EventScript_BlockingWayNPCNarth::
	callnative LockPlayerFieldControls
	faceplayer
	msgbox Route4_Text_BlockingWayNPCNarth, MSGBOX_AUTOCLOSE
	closemessage
	callnative UnlockPlayerFieldControls
	end

Route4_Text_BlockingWayNPCNarth::
	.string "This Des guy is F Tier!$"

@NPCS

Route4_EventScript_FatGuyPreTM::
	lock
	faceplayer
	goto_if_set FLAG_GIVES_TM03_SMART_STRIKE, Route4_EventScript_FatGuyPostTM
	msgbox Route4_Text_FatGuyPreSmartStrike, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_TM_SMART_STRIKE
	setflag FLAG_GIVES_TM03_SMART_STRIKE
	msgbox Route4_Text_FatGuyPostSmartStrike, MSGBOX_DEFAULT
	closemessage	
	release
	end

Route4_EventScript_FatGuyPostTM::
	lock
	faceplayer
	msgbox Route4_Text_FatGuyPostSmartStrike, MSGBOX_DEFAULT
	closemessage
	release
	end

Route4_Text_FatGuyPreSmartStrike::
	.string "You look like you have a good head\n"
	.string "on your shoulders, kid!\p"
	.string "Intelligence is the key to victory\n"
	.string "when you're in a Pokémon battles.\p"
	.string "With that said, you have to be\n"
	.string "analytical so you can check out\l"
	.string "your opponent's weak points.\p"
	.string "Thats when you strike!\l"
	.string "Hah! You get me! Take this!$"

Route4_Text_FatGuyPostSmartStrike::
	.string "That move is Smart Strike! It's a\n"
	.string "decent Steel Type move, but it will\l"
	.string "never miss its target!\p"
	.string "Use it wisely!$"

Route4_EventScript_BattleGirl::
	lock
	faceplayer
	msgbox Route4_Text_BattleGirl, MSGBOX_DEFAULT
	closemessage
	release
	end

Route4_Text_BattleGirl::
	.string "You know, living in the big city is\n"
	.string "really nice and convenient, and it\l"
	.string "sure is nice that it's easy to get\l"
	.string "around...\p"
	.string "But gosh darnit, the road is so\n"
	.string "noisy!\p"
	.string "Every time I come out here to\n"
	.string "train it's so distracting to hear\l"
	.string "the constant beeping and sound of\l"
	.string "them driving over us!\p"
	.string "Still, it's nice that cars aren't so\n"
	.string "common. You can walk and travel\l"
	.string "almost anywhere thanks to our\l"
	.string "relationships with Pokémon!$"
