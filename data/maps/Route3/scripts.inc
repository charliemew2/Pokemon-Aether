Route3_MapScripts::
	.byte 0

@TRAINERS ROUTE 3

Route3_EventScript_Nixon::
	trainerbattle_single TRAINER_BLACKBELTNIXON, Route3_Text_NixonIntro, Route3_Text_NixonDefeated
	msgbox Route3_Text_NixonPostBattle, MSGBOX_AUTOCLOSE
	release
	end

Route3_Text_NixonIntro::
	.string "I am training to prepare myself\n"
	.string "for my climb up Mt. Aeon!\p"
	.string "Our eyes met, so let me show you\n"
	.string "the fruits of my training!$"

Route3_Text_NixonDefeated::
	.string "I was beaten down by reality! My\n"
	.string "training is not yet complete!$"

Route3_Text_NixonPostBattle::
	.string "What!? You're telling me you have\n"
	.string "already climbed over Mt. Aeon!?\p"
	.string "Ah the lower summit! No no no. I am\n"
	.string "aiming to reach the peak no man\l"
	.string "or woman has ever reached!\p"
	.string "The highest summit will be beaten\n"
	.string "down by my determination!$"

Route3_EventScript_TwinsLilyAndLeia::
	trainerbattle_single TRAINER_TWINSLILYANDLEIA, Route3_Text_TwinsLilyAndLeiaIntro, Route3_Text_TwinsLilyAndLeiaDefeated
	msgbox Route3_Text_TwinsLilyAndLeiaPostBattle, MSGBOX_AUTOCLOSE
	release
	end

Route3_Text_TwinsLilyAndLeiaIntro::
	.string "My sister and I got this really\n"
	.string "cool combo strategy from our\l"
	.string "older brother!\p"
	.string "Time for us to show it off!$"

Route3_Text_TwinsLilyAndLeiaDefeated::
	.string "We're sorry big bro! We couldn't\n"
	.string "use the combo right...$"

Route3_Text_TwinsLilyAndLeiaPostBattle::
	.string "Our big brother is a trainer too!\l"
	.string "He usually hangs out around the\n"
	.string "city up ahead, we usually play here\l"
	.string "until he comes to pick us up!$"

Route3_EventScript_AromaLadyChristina::
	trainerbattle_single TRAINER_AROMALADYCHRISTINA, Route3_Text_AromaLadyChristinaIntro, Route3_Text_AromaLadyChristinaDefeated
	msgbox Route3_Text_AromaLadyChristinaPostBattle, MSGBOX_AUTOCLOSE
	release
	end

Route3_Text_AromaLadyChristinaIntro::
	.string "Flowers cannot bloom without the\n"
	.string "rain...\p"
	.string "Let me show you the storm I've\n"
	.string "created to create the perfect\l"
	.string "bloom!$"

Route3_Text_AromaLadyChristinaDefeated::
	.string "Too much! Too much! They'll wilt!$"

Route3_Text_AromaLadyChristinaPostBattle::
	.string "Too much of anything sometimes\n"
	.string "isn't a good thing.\p"
	.string "Plants that get overwatered can't\n"
	.string "grow properly.\p"
	.string "They respond to greed much more\n"
	.string "powerfully than humans...$"

Route3_EventScript_GourmetHank::
	trainerbattle_single TRAINER_GOURMET_HANK, Route3_Text_GourmetHankIntro, Route3_Text_GourmetHankDefeated
	msgbox Route3_Text_GourmetHankPostBattle, MSGBOX_AUTOCLOSE
	release
	end

Route3_Text_GourmetHankIntro::
	.string "You know what every Pokémon has\n"
	.string "to have before a battle?\p"
	.string "A good meal!\l"
	.string "Feel the power of a full belly!$"

Route3_Text_GourmetHankDefeated::
	.string "We overate and were too sluggish\n"
	.string "to win...!$"

Route3_Text_GourmetHankPostBattle::
	.string "Hmm...I should experiment with\n"
	.string "feeding different berries to my\l"
	.string "team.\p"
	.string "Maybe I had the wrong ones ready\n"
	.string "for the battle.\p"
	.string "Some berries are very rare, so use\n"
	.string "them wisely!$"

Route3_EventScript_TriathleteSheldon::
	trainerbattle_single TRAINER_TRIATHLETESHELDON, Route3_Text_TriathleteSheldonIntro, Route3_Text_TriathleteSheldonDefeated
	msgbox Route3_Text_TriathleteSheldonPostBattle, MSGBOX_AUTOCLOSE
	release
	end

Route3_Text_TriathleteSheldonIntro::
	.string "Huff Puff... Gotta... Hustle...\n"
	.string "Not... gonna... beat... my... time...\p"
	.string "You! Keep up with me! Let's see\n"
	.string "your hustle and bustle!$"

Route3_Text_TriathleteSheldonDefeated::
	.string "Stop!... Huff... Out of... breath...\n"
	.string "Puff... Huff..$"

Route3_Text_TriathleteSheldonPostBattle::
	.string "I've been training to run across\n"
	.string "the entire Kusho Region.\p"
	.string "Guess my body isn't ready... And\n"
	.string "not like there isn't a rush!\p"
	.string "Hustling isn't that good. Slow and\n"
	.string "steady can win a race too!$"

@NPCS

Route3_EventScript_BoyWanderingGrass::
	lock
	faceplayer
	msgbox Route3_Text_BoyWanderingGrass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route3_Text_BoyWanderingGrass::
	.string "I'm out here picking berries!\n"
	.string "Sometimes I find rare and fresh\l"
	.string "ones that have dropped onto the\l"
	.string "ground.\p"
	.string "If nobody picked them up, they'd\n"
	.string "just regrow eventually!\p"
	.string "Nature is so cool!$"

Route3_EventScript_CyclingGirl::
	lock
	faceplayer
	msgbox Route3_Text_CyclingGirl, MSGBOX_DEFAULT
	closemessage
	release
	end

Route3_Text_CyclingGirl::
	.string "I'm so miffed!\l"
	.string "They told me I couldn't bike on the\n"
	.string "road up there.\p"
	.string "I mean I get it, they don't want\n"
	.string "anyone getting hit by a truck...\p"
	.string "But also it's not like it's so busy\n"
	.string "that it's bumper to bumper!\p"
	.string "We should get a Cycling Road built\n"
	.string "in Kusho!$"

Route3_EventScript_RunningMan::
	lock
	faceplayer
	msgbox Route3_Text_RunningMan, MSGBOX_DEFAULT
	closemessage
	release
	end

Route3_Text_RunningMan::
	.string "It's not too long of a trek up to\n"
	.string "CITYONE from here.\p"
	.string "Just go up Route 4 and then you'll\n"
	.string "pass through the gate.\p"
	.string "I live there and come to run down\n"
	.string "both Routes 3 and 4 every day!$"

Route3_EventScript_Fisherman::
	lock
	faceplayer
	msgbox Route3_Text_Fisherman, MSGBOX_DEFAULT
	closemessage
	release
	end

Route3_Text_Fisherman::
	.string "You see that big rock in the middle\n"
	.string "of this pond?\p"
	.string "I'd love to swim out and explore it.\n"
	.string "But I can't swim!\p"
	.string "Isn't that ironic?$"

@SIGNS 

Route3_EventScript_SignToRoute5::
	msgbox Route3_Text_SignToRoute5, MSGBOX_SIGN
	end

Route3_Text_SignToRoute5::
	.string "{LEFT_ARROW} Route 5$"

Route3_EventScript_SignToRoute4::
	msgbox Route3_Text_SignToRoute4, MSGBOX_SIGN
	end

Route3_Text_SignToRoute4::
	.string "{UP_ARROW} Route 4$"
