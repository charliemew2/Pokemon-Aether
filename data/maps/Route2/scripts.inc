Route2_MapScripts::
	.byte 0

Route2_EventScript_WorkerMarty::
	trainerbattle_single TRAINER_WORKER_MARTY, Route2_Text_MartyIntro, Route2_Text_MartyDefeated
	msgbox Route2_Text_MartyPostBattle, MSGBOX_AUTOCLOSE
	release
	end

Route2_Text_MartyIntro::
	.string "Hey! You got the cable car up and\n"
	.string "running again?\p"
	.string "Dangit! Now I have to go back to\n"
	.string "work today!\p"
	.string "Time to distract myself with a\n"
	.string "battle on the clock!$"

Route2_Text_MartyDefeated::
	.string "Oh no! My pay is going to get\n"
	.string "docked for this!$"

Route2_Text_MartyPostBattle::
	.string "It takes a lot of work to maintain\n"
	.string "the cable car.\p"
	.string "They're supposedly going to have\n"
	.string "us install one close to the docks\l"
	.string "down south in a few months!$"

Route2_EventScript_AromaLadyDeliah::
	trainerbattle_single TRAINER_AROMALADY_DELIAH, Route2_Text_DeliahIntro, Route2_Text_DeliahDefeated
	msgbox Route2_Text_DeliahPostBattle, MSGBOX_AUTOCLOSE
	release
	end

Route2_Text_DeliahIntro::
	.string "Oh hello! You've caught me in the\n"
	.string "middle of tending to the flowers.\p"
	.string "Might I offer you a battle with\n"
	.string "the Pokémon that I use to keep\l"
	.string "them so beautifully in bloom?$"

Route2_Text_DeliahDefeated::
	.string "Like pollen, I've been scattered\n"
	.string "to the winds...$"

Route2_Text_DeliahPostBattle::
	.string "I'm from Blossomwood Town, a bit\n"
	.string "to the east!\p"
	.string "We have different flowers in bloom\n"
	.string "year round!$"

Route2_EventScript_BeautyLaurie::
	trainerbattle_single TRAINER_BEAUTY_LAURIE, Route2_Text_LaurieIntro, Route2_Text_LaurieDefeated
	msgbox Route2_Text_LauriePostBattle, MSGBOX_AUTOCLOSE
	release
	end

Route2_Text_LaurieIntro::
	.string "The countryside ain't for a dame\n"
	.string "like me!\p"
	.string "Soon I'll make myself known all\n"
	.string "over the world. Me, and my singing\l"
	.string "troupe of Pokémon!$"

Route2_Text_LaurieDefeated::
	.string "Ah...Makin it big sure ain't as easy\n"
	.string "as the TV makes it outta' be...\p"

Route2_Text_LauriePostBattle::
	.string "It's peaceful here in the Kusho\n"
	.string "countryside, yeppers!\p"
	.string "But I crave the city life up north!\l"
	.string "The hustle'n bustlin life of the\n"
	.string "night. The stage will be mine!$"

Route2_EventScript_LassDalia::
	trainerbattle_single TRAINER_LASS_DALIA, Route2_Text_DaliaIntro, Route2_Text_DaliaDefeated
	msgbox Route2_Text_DaliaPostBattle, MSGBOX_AUTOCLOSE
	release
	end

Route2_Text_DaliaIntro::
	.string "Hey! Trainer, I have a little test!\l"
	.string "Which one of these Pokémon is the\n"
	.string "absolute best?$"

Route2_Text_DaliaDefeated::
	.string "Uh...looks like the answer was -\n"
	.string "your Pokémon! Not mine!$"

Route2_Text_DaliaPostBattle::
	.string "I've never seen people argue over\n"
	.string "starter Pokémon more than this\l"
	.string "trio.\p"
	.string "They're the starters you get in\n"
	.string "Sinnoh, and everyone adores them\l"
	.string "it seems.\p"
	.string "Maybe...they're all good in their\n"
	.string "own ways...?$"

Route2_EventScript_FishermanTimothy::
	trainerbattle_single TRAINER_FISHERMAN_TIMOTHY, Route2_Text_TimothyIntro, Route2_Text_TimothyDefeated
	msgbox Route2_Text_TimothyPostBattle, MSGBOX_AUTOCLOSE
	release
	end

Route2_Text_TimothyIntro::
	.string "Blossomwood Town is bordering the\n"
	.string "ocean.\p"
	.string "Let me show you what I reeled in\n"
	.string "for today's haul!$"

Route2_Text_TimothyDefeated::
	.string "Argh! I got tangled in my Spidops\n"
	.string "net!$"

Route2_Text_TimothyPostBattle::
	.string "Fishing is so relaxing. You never\n"
	.string "know what you are gonna get, but\l"
	.string "you always enjoy the wait!$"

@NPC Dialogue

Route2_EventScript_LittleBoy::
	lock
	faceplayer
	msgbox Route2_Text_LittleBoy, MSGBOX_DEFAULT
	closemessage
	release
	end

Route2_Text_LittleBoy::
	.string "Did you come from far away?\l"
	.string "Wow! You climbed over Mt. Aeon?\l"
	.string "People don't ever come up from the\n"
	.string "south end unless they take the\l"
	.string "cargo road!$"

Route2_EventScript_RegularBoy::
	lock
	faceplayer
	msgbox Route2_Text_RegularBoy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_BOYLOOKINGATTREEROUTE2, Common_Movement_FaceUp
	release
	end

Route2_Text_RegularBoy::
	.string "I had a really good idea for a way\n"
	.string "to make secret hideouts!\p"
	.string "You could use a move on one of\n"
	.string "these pine trees...\p"
	.string "...And then use the space cleared\n"
	.string "out to make a Secret Base!\p"
	.string "Genius right?\l"
	.string "I should patent this idea once I\n"
	.string "spread it worldwide!$"
