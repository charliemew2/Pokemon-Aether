BlossomwoodTown_MapScripts::
map_script MAP_SCRIPT_ON_FRAME_TABLE, SavedFlowerShop_OnFrameTable
	.byte 0

SavedFlowerShop_OnFrameTable:
	map_script_2 VAR_BLOSSOMTOWN_EVENTS, 2, SavedFlowerShop_EventScript_TalkWithEve
	.2byte 0

SavedFlowerShop_EventScript_TalkWithEve::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, SavedFlowerShop_Movement_LeaveShop
	waitmovement 0
	clearflag FLAG_EVE_EXITS_FLOWERSHOP
	playse SE_EXIT
	addobject LOCAL_ID_EVE_POST_FLOWERSHOP
	applymovement LOCAL_ID_EVE_POST_FLOWERSHOP, SavedFlowerShop_Movement_EveLeaveShop
	waitmovement 0
	delay 16
	applymovement LOCAL_ID_EVE_POST_FLOWERSHOP, SavedFlowerShop_Movement_EveJumpsAfterLeaveShop
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	waitmovement 0
	delay 16
	msgbox SavedFlowerShop_Text_EveWorriesAboutGaia, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_EVE_POST_FLOWERSHOP, SavedFlowerShop_Movement_EveJumpsAfterLeaveShop
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	waitmovement 0
	delay 16
	applymovement LOCAL_ID_EVE_POST_FLOWERSHOP, SavedFlowerShop_Movement_EveLeavesPlayer
	waitmovement 0
	removeobject LOCAL_ID_EVE_POST_FLOWERSHOP
	setflag FLAG_EVE_EXITS_FLOWERSHOP
	clearflag FLAG_FLOWERSHOP_NORMAL_STATE
	clearflag FLAG_GAIA_GRUNTS_BLOCK_BLOSSOMWOODTOWN
	addvar VAR_BLOSSOMTOWN_EVENTS, 1
	release
	end

SavedFlowerShop_Movement_LeaveShop::
	walk_left
	walk_left
	face_right
	step_end

SavedFlowerShop_Movement_EveLeaveShop::
	walk_down
	walk_left
	step_end

SavedFlowerShop_Movement_EveJumpsAfterLeaveShop::
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	step_end

SavedFlowerShop_Text_EveWorriesAboutGaia::
	.string "That was scary! But I'm glad we\n"
	.string "jumped in and helped those people\p"
	.string "Huh?\l"
	.string "Why are you looking at me like that\n"
	.string "{PLAYER}?\p"
	.string "...\l"
	.string "Huh? That was dangerous?\l"
	.string "Well yeah! But I knew you were\n"
	.string "stronger than those people! So it\l"
	.string "was ok!\p"
	.string "I'm worried though about this Gaia\n"
	.string "person they mentioned...\p"
	.string "Could they be the boss?\l"
	.string "Can I be honest?\l"
	.string "You saw Mew back at the Peaceful\n"
	.string "Pond right?\p"
	.string "I saw it too!\l"
	.string "I think this EVILTEAM is after Mew\n"
	.string "for some reason!\p"
	.string "I'm not sure why, but I want to get\n"
	.string "to the bottom of this.\p"
	.string "And now they seem like they're\n"
	.string "after Shaymin too...\p"
	.string "{PLAYER} I think I'm going to go\n"
	.string "on ahead.\p"
	.string "There's more investigating I have\n"
	.string "to do! You'll help me right?\p"
	.string "There's an underground lake where\n"
	.string "we can meet one of my friends!\p"
	.string "They can help us for sure!\l"
	.string "It's to the West, so come and meet\n"
	.string "me there, past Route 3!\p"
	.string "Ok {PLAYER}! Seeya soon!$"

SavedFlowerShop_Movement_EveLeavesPlayer::
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

@MEETING EVE IN TOWN TO TRIGGER THE B2B

BlossomwoodTown_EventScript_MeetingEveAgain::
	lock
	applymovement LOCAL_ID_EVE_BLOSSOMWOODTOWNCUTSCENESTARTER, Common_Movement_FaceDown
	waitmovement 0
	delay 8
	playse SE_PIN
	applymovement LOCAL_ID_EVE_BLOSSOMWOODTOWNCUTSCENESTARTER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	applymovement LOCAL_ID_EVE_BLOSSOMWOODTOWNCUTSCENESTARTER, BlossomwoodTown_Movement_EveJumpInPlace
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	waitmovement 0
	delay 16
	delay 16
	applymovement LOCAL_ID_EVE_BLOSSOMWOODTOWNCUTSCENESTARTER, Common_Movement_WalkDown
	waitmovement 0
	getplayerxy VAR_TEMP_3, VAR_TEMP_4
	call_if_eq VAR_TEMP_3, 21, BlossomwoodTown_EventScript_AlignEve
	delay 16
	msgbox BlossomwoodTown_Text_EveSpotsPlayer, MSGBOX_DEFAULT
	closemessage
	delay 16
	applymovement LOCAL_ID_EVE_BLOSSOMWOODTOWNCUTSCENESTARTER, BlossomwoodTown_Movement_EveJumpInPlace
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	waitmovement 0
	delay 32
	applymovement LOCAL_ID_EVE_BLOSSOMWOODTOWNCUTSCENESTARTER, BlossomwoodTown_Movement_Evewalkstotheshop
	waitmovement 0
	removeobject LOCAL_ID_EVE_BLOSSOMWOODTOWNCUTSCENESTARTER
	setflag FLAG_EVE_GOES_TO_WAIT_AT_SHOP
	setflag FLAG_HIDE_AT_CUTSCENE_START_FLOWERSHOP
	setflag	FLAG_EVE_EXITS_FLOWERSHOP
	addvar VAR_BLOSSOMTOWN_EVENTS, 1
	release
	end

BlossomwoodTown_Movement_EveJumpInPlace::
	jump_in_place_down
	jump_in_place_down
	jump_in_place_down
	step_end

BlossomwoodTown_EventScript_AlignEve::
	applymovement LOCAL_ID_EVE_BLOSSOMWOODTOWNCUTSCENESTARTER, BlossomwoodTown_Movement_AlignEve
	waitmovement 0
	return

BlossomwoodTown_Movement_AlignEve::
	walk_right
	face_down
	step_end

BlossomwoodTown_Text_EveSpotsPlayer::
	.string "{PLAYER}! You made it! Yay!\l"
	.string "...Huh? Why do you have that wierd\n"
	.string "look on your face?\p"
	.string "Oh! You're wondering where I went\n"
	.string "earlier after the docks right?\p"
	.string "Well the truth is, there was a\n"
	.string "really suspicious looking man who\l"
	.string "left the docks before you came\l"
	.string "back...\p"
	.string "He was really scary! But, I just\n"
	.string "knew he was up to no good!\p"
	.string "So...I followed him to Mt. Aeon! But\n"
	.string "I lost track of him!\p"
	.string "But then I came here and I saw a\n"
	.string "person dressed just like him...\p"
	.string "Actually it was a few people.\l"
	.string "This is good! We can investigate!\l"
	.string "{PLAYER}, I saw them go into the\n"
	.string "building over there.\p"
	.string "I have a bad feeling! Can you come\n"
	.string "with me to make sure everything is\l"
	.string "ok?\p"
	.string "I'll wait outside!$"

BlossomwoodTown_Movement_Evewalkstotheshop::
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BlossomwoodTown_EventScript_EveWarnsPlayer::
	lock
	faceplayer
	msgbox BlossomwoodTown_Text_EveWarnsPlayer, MSGBOX_DEFAULT
	closemessage
	release
	end

BlossomwoodTown_Text_EveWarnsPlayer::
	.string "{PLAYER}! {PLAYER}! I see them!\n"
	.string "Through the window!\p"
	.string "Be ready just in case... I won't run\n"
	.string "this time! Cuz this time you're\l"
	.string "with me!$"

@ADMIN GAIA BOSS FIGHT

BlossomwoodTown_EventScript_GaiaBossFight::
	lock
	getplayerxy VAR_TEMP_3, VAR_TEMP_4
	call_if_eq VAR_TEMP_4, 5, BlossomwoodTown_EventScript_AlignPlayer
	delay 16
	applymovement LOCAL_ID_ADMIN_GAIA_BLOSSOMTOWN, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox BlossomwoodTown_Text_GaiaBossFight1, MSGBOX_DEFAULT
	closemessage
	delay 16
	applymovement LOCAL_ID_GRUNT1M, Common_Movement_FaceRight
	waitmovement 0
	playbgm MUS_ENCOUNTER_AQUA, TRUE
	playse SE_PIN
	applymovement LOCAL_ID_GRUNT1M, Common_Movement_ExclamationMark
	delay 16
	delay 16
	msgbox BlossomwoodTown_Text_GaiaBossFight2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_GRUNT1F, Common_Movement_FaceRight
	applymovement LOCAL_ID_GRUNT2F, Common_Movement_FaceRight
	applymovement LOCAL_ID_GRUNT2M, Common_Movement_FaceRight
	waitmovement 0
	delay 16
	msgbox BlossomwoodTown_Text_GaiaBossFight3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_GRUNT1M, BlossomwoodTown_Movement_GruntsMoveOutOfWay
	applymovement LOCAL_ID_GRUNT1F, BlossomwoodTown_Movement_GruntsMoveOutOfWay
	applymovement LOCAL_ID_GRUNT2M, Common_Movement_FaceUp
	applymovement LOCAL_ID_GRUNT2F, Common_Movement_FaceUp
	waitmovement 0
	delay 16
	applymovement LOCAL_ID_ADMIN_GAIA_BLOSSOMTOWN, BlossomwoodTown_Movement_GaiaApproachesPlayer
	waitmovement 0
	msgbox BlossomwoodTown_Text_GaiaBossFight4, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_ADMIN_GAIA_BLOSSOMTOWN, BlossomwoodTown_Text_GaiaBossFightDefeat
	msgbox BlossomwoodTown_Text_GaiaBossFight5, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_ADMIN_GAIA_BLOSSOMTOWN, BlossomwoodTown_Movement_GaiaRetreat
	waitmovement 0
	delay 16
	applymovement LOCAL_ID_GRUNT1M, BlossomwoodTown_Movement_EvilTeamRetreat
	applymovement LOCAL_ID_GRUNT1F, BlossomwoodTown_Movement_EvilTeamRetreat
	applymovement LOCAL_ID_GRUNT2M, BlossomwoodTown_Movement_EvilTeamRetreat
	applymovement LOCAL_ID_GRUNT2F, BlossomwoodTown_Movement_EvilTeamRetreat
	waitmovement 0
	removeobject LOCAL_ID_GRUNT1M
	removeobject LOCAL_ID_GRUNT1F
	removeobject LOCAL_ID_GRUNT2M
	removeobject LOCAL_ID_GRUNT2F
	removeobject LOCAL_ID_ADMIN_GAIA_BLOSSOMTOWN
	setflag FLAG_GAIA_GRUNTS_BLOCK_BLOSSOMWOODTOWN
	setflag FLAG_DEFEATED_GAIA
	addvar VAR_BLOSSOMTOWN_EVENTS, 1
	fadedefaultbgm
	release
	end

BlossomwoodTown_EventScript_AlignPlayer::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	return

BlossomwoodTown_Text_GaiaBossFight1::
	.string "Gaia: So. In front of me, I see four\n"
	.string "very sorry looking grunts.\p"
	.string "...And no Gracedia?\l"
	.string "Shady Woman 1: Admin Gaia... We're\n"
	.string "so sorry! They said they didn't\l"
	.string "have the seeds, and we were gonna\l"
	.string "case the place but...\p"
	.string "Shady Man 1: Some kids showed up\n"
	.string "and took us out!\p"
	.string "Gaia: Hmmm...? Children? You lost to\n"
	.string "children?\p"
	.string "...\l"
	.string "It seems, speaking of children,\n"
	.string "that we have one in our midst.$"

BlossomwoodTown_Text_GaiaBossFight2::
	.string "Shady Man 1: YOU AGAIN!? Don't you\n"
	.string "ever quit?$"

BlossomwoodTown_Text_GaiaBossFight3::
	.string "Shady Woman 1: And he's all alone?\l"
	.string "Well this makes it easier! Let's\n"
	.string "get em by force this time!\p"
	.string "Gaia: Halt. Are you daft?\l"
	.string "This is a peaceful town and you're\n"
	.string "going to make a scene in broad\l"
	.string "daylight?\p"
	.string "You are all already in hot water\n"
	.string "for the stunt you just pulled.\p"
	.string "What if the CITYONE police had\n"
	.string "been patrolling here and ran\l"
	.string "across you all in the middle of the\l"
	.string "hold up?\p"
	.string "Then we'd be down four, admittedly\n"
	.string "useless men and women, AND have\l"
	.string "police on our backs.\p"
	.string "Move.$"

BlossomwoodTown_Movement_GruntsMoveOutOfWay::
	walk_up
	face_down
	step_end

BlossomwoodTown_Movement_GaiaApproachesPlayer::
	walk_right
	walk_right
	step_end

BlossomwoodTown_Text_GaiaBossFight4::
	.string "Gaia: Forgive my rather brutish\n"
	.string "underlings for their rather unjust\l"
	.string "methodology of disposing of\l"
	.string "pests in our operation.\p"
	.string "My name is Gaia. You have willingly\n"
	.string "involved yourself in the affairs\l"
	.string "of EVILTEAM, so I am doing you a\l"
	.string "courtesy of introducing myself.\p"
	.string "I'll be blunt. We are not a group of\n"
	.string "thugs, despite what the people\l"
	.string "surrounding me may lead you to\l"
	.string "believe.\p"
	.string "This is a failing on my part as the\n"
	.string "administrator responsible for\l"
	.string "this branch.\p"
	.string "For this, you have my apologies.\l"
	.string "However...\l"
	.string "You have proven yourself already\n"
	.string "to be obstructing our work, and\l"
	.string "for this, you will need to be dealt\l"
	.string "with accordingly.\p"
	.string "In broad daylight, a Pokémon\n"
	.string "battle is a quite normal sight for\l"
	.string "people yes?\p"
	.string "Far more than the rather heinous\n"
	.string "idea of physically beating you in\l"
	.string "the middle of public I would say!\p"
	.string "Then, we shall partake in such an\n"
	.string "affair right now.\p"
	.string "But be warned. I shall beat your\n"
	.string "team to within an inch of its life.\p"
	.string "After such a defeat, you will know\n"
	.string "why you should not cross us!\p"
	.string "This is the consequence for\n"
	.string "interfering with our affairs.\p"
	.string "Whether you are a child or not...\n"
	.string "You will pay the price!$"

BlossomwoodTown_Text_GaiaBossFightDefeat::
	.string "Inconceivable!\l"
	.string "That a child could be so strong...\n"
	.string "It defies all logical belief!$"

BlossomwoodTown_Text_GaiaBossFight5::
	.string "Shady Woman 1: No...no way...!\l"
	.string "Shady Woman 2: That kid actually\n"
	.string "beat Admin Gaia!?\p"
	.string "Gaia: ...\l"
	.string "Shady Man 2: This isn't possible...\l"
	.string "Shady Man 1: Um... So... are we off\n"
	.string "the hook for losing now?\p"
	.string "Gaia: You...Child.\l"
	.string "Tell me your name.\l"
	.string "No?\l"
	.string "A shame. You would be very useful\n"
	.string "if you were to join us.\p"
	.string "We have already had quite the\n"
	.string "number of interruptions in our\l"
	.string "plans the last few days.\p"
	.string "Hmm...Didn't you all tell me that\n"
	.string "there were children, plural, who\l"
	.string "meddled earlier?\p"
	.string "Shady Man 1: The other one ain't\n"
	.string "anywhere to be found! We didn't\l"
	.string "see em leave town!\p"
	.string "Gaia: Child who will not share their\n"
	.string "name, I am going to tell you this\l"
	.string "one time.\p"
	.string "I respect your strength, and this\n"
	.string "is why I am offering you peace.\p"
	.string "Stay out of our way.\l"
	.string "What happened today was a stroke\n"
	.string "of luck, and it will not happen\l"
	.string "again.\p"
	.string "If we meet in a place where nobody\n"
	.string "could lift a finger to save you,\l"
	.string "the mercy I showed you today will\l"
	.string "not be repeated.\p"
	.string "You are digging into affairs that\n"
	.string "no child should be anywhere near.\p"
	.string "Consider this your only warning.\l"
	.string "My cohort Loch is not anywhere\n"
	.string "near as generous as myself.\p"
	.string "If you meet her, my advice is to\n"
	.string "run far away.\p"
	.string "But you will not meet her, because\n"
	.string "you will heed my warning.\p"
	.string "I hope your friend heeds it too.\l"
	.string "Farewell.\l"
	.string "Men, Women, follow. We are leaving.\l"
	.string "The other branch is likely at work\n"
	.string "as we speak.\p"
	.string "Grunts: SIR YES SIR!$"

BlossomwoodTown_Movement_GaiaRetreat::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

BlossomwoodTown_Movement_EvilTeamRetreat::
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

BlossomwoodTown_EventScript_KeepPlayerFromLeaving::
	msgbox BlossomwoodTown_Text_KeepPlayerFromLeaving, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_TEMP_3, VAR_TEMP_4
	call_if_eq VAR_TEMP_3, 2, BlossomwoodTown_EventScript_KeepPlayerFromLeavingMovement
	release
	end

BlossomwoodTown_Text_KeepPlayerFromLeaving::
	.string "Eve is waiting for you at the shop!\n"
	.string "Don't keep them waiting!$"

BlossomwoodTown_EventScript_KeepPlayerFromLeavingMovement::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	return

@NPCS AROUND TOWN

BlossomWoodTown_EventScript_HoneyGirl::
	lock
	faceplayer
	msgbox BlossomWoodTown_Text_HoneyGirl, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_HONEYGIRL_BLOSSOMWOOD, Common_Movement_FaceRight
	waitmovement 0
	release
	end

BlossomWoodTown_Text_HoneyGirl::
	.string "My Combee harvests fresh honey\n"
	.string "occasionally.\p"
	.string "It's a bit dangerous, sometimes\n"
	.string "wild Ursaring will try to surprise\l"
	.string "us for it!\p"
	.string "Ursaring that eat enough Honey\n"
	.string "can evolve into Ursaluna.\p"
	.string "I heard though that there is a\n"
	.string "rare stone that can evolve it into\l"
	.string "a different form...\p"
	.string "Pokémon are so mysterious!\l"
	.string "Combee and I will stick to our\n"
	.string "casual gathering of Honey.\p"
	.string "My sister sells flowers at the\n"
	.string "Southern Docks, sometimes she\l"
	.string "sells my honey too!$"

BlossomWoodTown_EventScript_Combee::
	lock
	faceplayer
	playmoncry SPECIES_COMBEE, CRY_MODE_NORMAL
	msgbox BlossomWoodTown_Text_Combee, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	applymovement LOCAL_ID_COMBEE_BLOSSOMWOOD, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

BlossomWoodTown_Text_Combee::
	.string "Com! Bee!$"

BlossomWoodTown_EventScript_Runner::
	lock
	faceplayer
	msgbox BlossomWoodTown_Text_Runner, MSGBOX_DEFAULT
	closemessage
	release
	end

BlossomWoodTown_Text_Runner::
	.string "I swear, the fresh air of this town\n"
	.string "is so invigorating!\p"
	.string "Blossomwood being right on the\n"
	.string "ocean is so fortunate.\p"
	.string "It's lovely weather for most of\n"
	.string "the year. Makes me feel so alive!$"

BlossomWoodTown_EventScript_OldLadyWatering::
	lock
	faceplayer
	msgbox BlossomWoodTown_Text_OldLadyWatering, MSGBOX_DEFAULT
	closemessage
	release
	end

BlossomWoodTown_Text_OldLadyWatering::
	.string "Our town is famous for its flowers.\l"
	.string "Its a community effort that we\n"
	.string "keep Blossomwood as vibrant as it\l"
	.string "is throughout the year.\p"
	.string "Have you heard of the Flower\n"
	.string "Paradise?\p"
	.string "It's to the west of Mt. Aeon and\n"
	.string "we can take the lifts through\l"
	.string "SnowCot to get to it.\p"
	.string "Most of our flowers germinated\n"
	.string "from seeds the people who founded\l"
	.string "this town brought from there!$"

BlossomWoodTown_EventScript_LadyInGrass::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, BlossomWoodTown_EventScript_LadyInGrassAfterMiracleSeed
	msgbox BlossomWoodTown_Text_LadyInGrass, MSGBOX_DEFAULT
	closemessage
	call BlossomWoodTown_giveitem_MiracleSeed
	msgbox BlossomWoodTown_Text_LadyInGrassAfterMiracleSeed, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

BlossomWoodTown_Text_LadyInGrass::
	.string "Everyone in Blossomwood Town has\n"
	.string "their own gardens!\p"
	.string "I don't have the biggest green\n"
	.string "thumb myself, but it's fun to\l"
	.string "learn and improve my gardening!\p"
	.string "However I have this one seed that\n"
	.string "won't be fit for growing, so maybe\l"
	.string "it's better in the hands of a\l"
	.string "trainer!\p"
	.string "You seem like a trainer, so I'll\n"
	.string "entrust it to you!$"

BlossomWoodTown_giveitem_MiracleSeed::
	giveitem ITEM_MIRACLE_SEED
	return

BlossomWoodTown_EventScript_LadyInGrassAfterMiracleSeed::
	lock
	faceplayer
	msgbox BlossomWoodTown_Text_LadyInGrassAfterMiracleSeed, MSGBOX_DEFAULT
	closemessage
	release
	end

BlossomWoodTown_Text_LadyInGrassAfterMiracleSeed::
	.string "The Miracle Seed is an item for\n"
	.string "grass type Pokémon!\p"
	.string "It will make their attacks much\n"
	.string "stronger.\p"
	.string "But...it doesn't grow into a plant!\l"
	.string "Isn't that kind of sad?\l"
	.string "Flowers should always be in bloom!$"

BlossomWoodTown_EventScript_Fisherman::
	lock
	faceplayer
	goto_if_set FLAG_GIVE_BOTTLE_CAP_BLOSSOMWOOD_TOWN, BlossomWoodTown_EventScript_FishermanAfterBottleCap
	msgbox BlossomWoodTown_Text_Fisherman, MSGBOX_DEFAULT
	closemessage
	call BlossomWoodTown_giveitem_BottleCap
	msgbox BlossomWoodTown_Text_FishermanAfterBottleCap, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_BLOSSOMWOOD_FISHERMAN, Common_Movement_FaceRight
	waitmovement 0
	setflag FLAG_GIVE_BOTTLE_CAP_BLOSSOMWOOD_TOWN
	release
	end

BlossomWoodTown_giveitem_BottleCap::
	giveitem ITEM_BOTTLE_CAP
	return

BlossomWoodTown_Text_Fisherman::
	.string "This is one of the most peaceful\n"
	.string "places I've ever fished!\p"
	.string "Though recently there have been\n"
	.string "some wierd looking people in\l"
	.string "strange uniforms coming to and\l"
	.string "from town the last few days.\p"
	.string "Eh, probably nothing. As long as\n"
	.string "they don't scare away the fish!\p"
	.string "Well today all I've caught is some\n"
	.string "trash, unfortunately.\p"
	.string "Still, even that's a win. It makes\n"
	.string "the ocean a little cleaner!\p"
	.string "But you know, one man's trash is\n"
	.string "another person's treasure.\p"
	.string "I'll share this with you!$"

BlossomWoodTown_EventScript_FishermanAfterBottleCap::
	lock
	faceplayer
	msgbox BlossomWoodTown_Text_FishermanAfterBottleCap, MSGBOX_DEFAULT
	closemessage
	release
	end

BlossomWoodTown_Text_FishermanAfterBottleCap::
	.string "I heard that some services collect\n"
	.string "those Bottle Caps.\p"
	.string "Fishing improves the world. We\n"
	.string "pick out trash, catch new friends,\l"
	.string "improve the sea, it's a cycle!\p"
	.string "The ocean calls to me!$"

BlossomWoodTown_EventScript_Beauty::
	lock
	faceplayer
	goto_if_set FLAG_SAVED_FLOWERSHOP, BlossomWoodTown_EventScript_BeautyAfterFlower
	msgbox BlossomWoodTown_Text_Beauty, MSGBOX_DEFAULT
	closemessage
	release
	end

BlossomWoodTown_Text_Beauty::
	.string "Ugh, people are so wierd nowadays.\l"
	.string "We get a lot of travelers to our\n"
	.string "beautiful town, but recently we've\l"
	.string "been getting these wierdos from\l"
	.string "EVILTEAM.\p"
	.string "They haven't caused any issues\n"
	.string "but I feel uncomfortable when\l"
	.string "they... interrogate people.\p"
	.string "Maybe I'm just too sensitive.$"

BlossomWoodTown_EventScript_BeautyAfterFlower::
	lock
	faceplayer
	msgbox BlossomWoodTown_Text_BeautyAfterFlower, MSGBOX_DEFAULT
	closemessage
	release
	end

BlossomWoodTown_Text_BeautyAfterFlower::
	.string "Oh my gosh!\l"
	.string "Those EVILTEAM people tried to\n"
	.string "rob the flower shop?\p"
	.string "And you stopped them?\p"
	.string "Thank goodness for good people\n"
	.string "like you... And you're so young!\p"
	.string "The next generation is looking\n"
	.string "bright if we have kind souls like\l"
	.string "you in the midst!$"
