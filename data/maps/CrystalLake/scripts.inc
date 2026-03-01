CrystalLake_MapScripts::
map_script MAP_SCRIPT_ON_TRANSITION, CarbinkPositions_OnTransition
	.byte 0

CarbinkPositions_OnTransition:
	call_if_eq VAR_CRYSTAL_LAKE_SEQUENCE, 3, CrystalLake_EventScript_RetainCarbinkPosition
	end

CrystalLake_EventScript_RetainCarbinkPosition::
	setobjectxyperm LOCAL_ID_CARBINK2, 12, 15
	setobjectmovementtype LOCAL_ID_CARBINK2, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
	setobjectxyperm LOCAL_ID_CARBINK3, 11, 15
	setobjectmovementtype LOCAL_ID_CARBINK3, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
	setobjectxyperm LOCAL_ID_CARBINK5, 14, 15
	setobjectmovementtype LOCAL_ID_CARBINK5, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
	setobjectxyperm LOCAL_ID_CARBINK4, 15, 15
	setobjectmovementtype LOCAL_ID_CARBINK4, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
	return

@PREP FOR LOCH BOSS FIGHT

CrystalLake_EventScript_LochFightPreperation::
	callnative LockPlayerFieldControls
	msgbox CrystalLake_Text_LochFightPreperation, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, CrystalLake_EventScript_RetreatToPrepareLoch
	case YES, CrystalLake_EventScript_LochBossFight
	end

CrystalLake_Text_LochFightPreperation::
	.string "You see someone up ahead.\l"
	.string "Confront them?$"

CrystalLake_EventScript_RetreatToPrepareLoch::
	msgbox CrystalLake_Text_YouShouldPrepareBeforeLoch, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	callnative UnlockPlayerFieldControls
	end

CrystalLake_Text_YouShouldPrepareBeforeLoch::
	.string "You decide to take a moment to\n"
	.string "better prepare...$"

@LOCH BOSS FIGHT

CrystalLake_EventScript_LochBossFight::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CrystalLake_Movement_PlayerApproachesLoch
	waitmovement 0
	delay 16
	applymovement LOCAL_ID_CRYSTAL_LAKE_LOCH, Common_Movement_WalkLeft
	waitmovement 0
	delay 16
	msgbox CrystalLake_Text_LochBossFight1, MSGBOX_DEFAULT
	closemessage
	delay 16
	applymovement LOCAL_ID_CRYSTAL_LAKE_LOCH, CrystalLake_Movement_LochApproachesRightCarbink
	waitmovement 0
	delay 16
	msgbox CrystalLake_Text_LochBossFight2, MSGBOX_DEFAULT
	closemessage
	delay 16
	applymovement LOCAL_ID_CRYSTAL_LAKE_LOCH, CrystalLake_Movement_LochApproachesMiddleCarbink
	waitmovement 0
	delay 16
	msgbox CrystalLake_Text_LochBossFight3, MSGBOX_DEFAULT
	closemessage
	delay 16
	delay 16
	applymovement LOCAL_ID_CRYSTAL_LAKE_LOCH, Common_Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCAL_ID_CRYSTAL_LAKE_LOCH, Common_Movement_ExclamationMark
	waitmovement 0
	delay 16
	delay 16
	msgbox CrystalLake_Text_LochBossFight4, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_CRYSTAL_LAKE_LOCH, CrystalLake_Movement_LochApproachesPlayer
	waitmovement 0
	msgbox CrystalLake_Text_LochBossFight5, MSGBOX_DEFAULT
	closemessage
	addvar VAR_CRYSTAL_LAKE_SEQUENCE, 1
	trainerbattle_no_intro TRAINER_ADMIN_LOCH_CRYSTAL_LAKE, CrystalLake_Text_LochDefeat
	delay 8
	msgbox CrystalLake_Text_LochBossFightPostBattle, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CrystalLake_Movement_PlayerPushedAway
	applymovement LOCAL_ID_CRYSTAL_LAKE_LOCH, CrystalLake_Movement_LochLeaves
	waitmovement 0
	removeobject LOCAL_ID_CRYSTAL_LAKE_LOCH
	setflag FLAG_DEFEATED_LOCH
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCAL_ID_CARBINK2, CrystalLake_Movement_MoveCarbink2
	setobjectmovementtype LOCAL_ID_CARBINK2, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
	applymovement LOCAL_ID_CARBINK3, CrystalLake_Movement_MoveCarbink3
	setobjectmovementtype LOCAL_ID_CARBINK3, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
	applymovement LOCAL_ID_CARBINK4, CrystalLake_Movement_MoveCarbink4
	setobjectmovementtype LOCAL_ID_CARBINK4, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
	applymovement LOCAL_ID_CARBINK5, CrystalLake_Movement_MoveCarbink5
	setobjectmovementtype LOCAL_ID_CARBINK5, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
	waitmovement 0
	delay 16
	playmoncry SPECIES_CARBINK, CRY_MODE_NORMAL
	waitmoncry
	delay 16
	clearflag FLAG_HIDEBEFOREDIANCIE
	addobject LOCAL_ID_EVE_CRYSTAL_LAKE
	applymovement LOCAL_ID_EVE_CRYSTAL_LAKE, CrystalLake_Movement_EveArrives
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	delay 8
	applymovement LOCAL_ID_EVE_CRYSTAL_LAKE, CrystalLake_Movement_EveJumpsUpandDownRight
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	waitmovement 0
	msgbox CrystalLake_Text_EveThanksPlayer, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_EVE_CRYSTAL_LAKE, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	msgbox CrystalLake_Text_EveThanksPlayer2, MSGBOX_DEFAULT
	closemessage
	delay 16
	waitmovement 0
	fadeScreen FADE_TO_WHITE
	delay 16
	clearflag FLAG_HIDEDIANCIE
	msgbox CrystalLake_Text_DiancieArrives, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_DIANCIE, CRY_MODE_NORMAL
	waitmoncry
	addobject LOCAL_ID_DIANCIE
	delay 16
	fadeScreen FADE_FROM_WHITE
	delay 16
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 16
	delay 16
	applymovement LOCAL_ID_EVE_CRYSTAL_LAKE, CrystalLake_Movement_EveJumpsUpandDownUp
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	waitmovement 0
	msgbox CrystalLake_Text_EveAndDiancieConvo, MSGBOX_DEFAULT
	closemessage
	fadeScreen FADE_TO_WHITE
	delay 16
	playmoncry SPECIES_MEW, CRY_MODE_NORMAL
	waitmoncry
	setflag FLAG_HIDEBEFOREDIANCIE
	removeobject LOCAL_ID_EVE_CRYSTAL_LAKE
	addobject LOCAL_ID_MEW_CRYSTALLAKE
	delay 16
	fadeScreen FADE_FROM_WHITE
	delay 16
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	delay 16
	delay 16
	applymovement LOCAL_ID_MEW_CRYSTALLAKE, Common_Movement_FaceRight
	waitmovement 0
	applymovement LOCAL_ID_MEW_CRYSTALLAKE, CrystalLake_Movement_EveJumpsUpandDownRight
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	waitmovement 0
	msgbox CrystalLake_Text_EveExplainsTrueForm, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_MEW_CRYSTALLAKE, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox CrystalLake_Text_MewAndDiancieConvo, MSGBOX_DEFAULT
	clearflag FLAG_HIDEMEW_CRYSTAL_LAKE
	closemessage
	setobjectmovementtype LOCAL_ID_MEW_CRYSTALLAKE, MOVEMENT_TYPE_WALK_IN_PLACE_UP
	callnative UnlockPlayerFieldControls
	end

CrystalLake_Text_MewAndDiancieConvo::
	.string "Mew: {PLAYER} is different! They\n"
	.string "live near my shrine! They tend to\l"
	.string "it every day without complaining.\p"
	.string "I could tell they were a good\n"
	.string "person, and I was right!\p"
	.string "But Diancie, these EVILTEAM guys\n"
	.string "were after the Gracedia..\p"
	.string "Diancie: And now they've come for\n"
	.string "me it seems. Could they be after\l"
	.string "the Pure Essence?\p"
	.string "Mew: It... seems likely. But why?\l"
	.string "The essence are really important\n"
	.string "to keeping the world together\l"
	.string "right?\p"
	.string "If someone took them away, that\n"
	.string "would be bad!\p"
	.string "Diancie: You said this human's name\n"
	.string "is {PLAYER}? They don't look like\l"
	.string "they have a clue of what's going\l"
	.string "on.\p"
	.string "Mew: I don't think they get out\n"
	.string "much. That's why I had to make\l"
	.string "them come play with me!\p"
	.string "Diancie: Then {PLAYER}, I'll take\n"
	.string "some time to explain.\p"
	.string "But, before I do, if you have any\n"
	.string "outstanding business you'd like\l"
	.string "to get done, go do it.\p"
	.string "We will wait here.\l"
	.string "I trust you won't bring us harm\n"
	.string "anyways. Not like you'd find us\l"
	.string "if you tried to betray us!\p"
	.string "We are good at hiding!\l"
	.string "Mew: {PLAYER} wouldn't do that!\l"
	.string "Diancie: Then we will wait here for\n"
	.string "you...\p"
	.string "Come speak to me when you are\n"
	.string "ready.$"

CrystalLake_Text_EveExplainsTrueForm::
	.string "Heehee! Being able to fly is a bit\n"
	.string "of a cheat code! That's how I was\l"
	.string "able to get over Mt. Aeon with the\l"
	.string "lifts down!\p"
	.string "I'm not much of a fighter, is all...\n"
	.string "So that's why I took the name and\l"
	.string "look of 'Eve'.\p"
	.string "Diancie: I'm surprised to see you\n"
	.string "with a human, Mew! I thought you\l"
	.string "didn't trust them!$"

CrystalLake_Text_EveAndDiancieConvo::
	.string "Eve: Diancie! You're ok!\l"
	.string "Diancie: I'd recognize that voice\n"
	.string "anywhere, but you look different.\p"
	.string "Any reason for the disguise?\l"
	.string "Eve: Oh! Sorry! I haven't exactly\n"
	.string "told my friend here though about\l"
	.string "what I look like.\p"
	.string "I guess I can show them now!$"

CrystalLake_Text_DiancieArrives::
	.string "???: I know that voice!\l"
	.string "It's been a while!$"

CrystalLake_Text_EveThanksPlayer::
	.string "{PLAYER}! You did it! Oh my gosh!\n"
	.string "Thankyouthankyouthankyou!\p"
	.string "I saw that Loch lady storm out of\n"
	.string "the cave! She got really mad at\l"
	.string "her underlings and they all left in\l"
	.string "a rage!\p"
	.string "I just hid and then slipped inside\n"
	.string "after they all left.\p"
	.string "Huh? Where is my friend?\l"
	.string "She's just hiding! Thank goodness\n"
	.string "they didn't know how to get her to\l"
	.string "come out.$"

CrystalLake_Text_EveThanksPlayer2::
	.string "Hey! It's me! You can come out!\l"
	.string "I have a friend with me! Those\n"
	.string "bad people are gone now!$"

CrystalLake_Movement_EveJumpsUpandDownRight::
	jump_in_place_right
	jump_in_place_right
	jump_in_place_right
	step_end

CrystalLake_Movement_EveJumpsUpandDownUp::
	jump_in_place_up
	jump_in_place_up
	jump_in_place_up
	step_end

CrystalLake_Movement_MoveCarbink2::
	walk_up
	walk_up
	walk_right
	face_down
	step_end

CrystalLake_Movement_MoveCarbink3::
	walk_up
	walk_up
	walk_up
	walk_right
	face_down
	step_end

CrystalLake_Movement_MoveCarbink4::
	walk_up
	walk_up
	walk_up
	walk_left
	face_down
	step_end

CrystalLake_Movement_MoveCarbink5::
	walk_up
	walk_up
	walk_left
	face_down
	step_end

CrystalLake_Movement_EveArrives::
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	face_right
	step_end

CrystalLake_Movement_PlayerApproachesLoch::
	walk_up
	walk_up
	step_end

CrystalLake_Movement_LochApproachesRightCarbink::
	walk_right
	walk_right
	step_end

CrystalLake_Movement_LochApproachesMiddleCarbink::
	walk_left
	walk_up
	step_end

CrystalLake_Movement_LochApproachesPlayer::
	walk_down
	walk_down
	step_end

CrystalLake_Text_LochBossFight1::
	.string "It's not you.$"

CrystalLake_Text_LochBossFight2::
	.string "Certainly not you.$"

CrystalLake_Text_LochBossFight3::
	.string "None of you! Not one of you is the\n"
	.string "Earth Guardian!\p"
	.string "Was our intel wrong? It was surely\n"
	.string "supposed to be here...\p"
	.string "But all that is here are these\n"
	.string "worthless Carbink!$"

CrystalLake_Text_LochBossFight4::
	.string "What the...Another child?$"

CrystalLake_Text_LochBossFight5::
	.string "Well this is just rich! Where there\n"
	.string "is one rat, another is always sure\l"
	.string "to follow!\p"
	.string "Are you here to avenge that little\n"
	.string "brat outside?\p"
	.string "Hehe... You shoulda seen their face\n"
	.string "as I clobbered their team.\p"
	.string "'No no! Please leave!' they cried.\n"
	.string "How pathetic!\p"
	.string "But guess what? There's a whole\n"
	.string "lot of nothing here!\p"
	.string "No Earth Guardian! What a waste of\n"
	.string "my precious time!\p"
	.string "Grrr...I'm PISSED!\l"
	.string "I hate children. I hate weaklings.\n"
	.string "If you made it here, surely that\l"
	.string "means those worthless grunts\l"
	.string "outside failed to stop you.\p"
	.string "Useless! USELESS!\l"
	.string "You know, today is getting worse\n"
	.string "and worse by the moment. It's your\l"
	.string "fault kid!\p"
	.string "So you know what? I'm going to\n"
	.string "take it all out on you!\p"
	.string "Once I've pulverized your team, I'll\n"
	.string "be taking you out next!\p"
	.string "Feel the wrath of the roaring seas\n"
	.string "captained by Admiral Loch!$"

CrystalLake_Text_LochDefeat::
	.string "WHAT?!\l"
	.string "I was washed away!\l"
	.string "This...This just can't be!$"

CrystalLake_Text_LochBossFightPostBattle::
	.string "...GRRRRRRRR!\l"
	.string "How DARE you! You couldn't have\n"
	.string "possibly beaten me...! You just\l"
	.string "couldn't have! It's inconcievable!\p"
	.string "With no Pokémon, I have no chance\n"
	.string "of overpowering you! What a shame.\p"
	.string "I was looking forward to ripping\n"
	.string "every hair off your head and every\l"
	.string "tooth from your mouth.\p"
	.string "A shame.\l"
	.string "But know this, you got lucky. If\n"
	.string "you ever meet my cohort Gaia, he\l"
	.string "will show you no mercy.\p"
	.string "He may act all prim and proper, but\n"
	.string "he is a human without an ounce of\l"
	.string "mercy.\p"
	.string "This is your only warning. Never\n"
	.string "cross EVILTEAM again.\p"
	.string "Hmph, there's no guardian here\n"
	.string "anyways. What a waste of my time!\p"
	.string "You'll wish you knew what mercy\n"
	.string "was kid if you ever get in my line\l"
	.string "of sight again.\p"
	.string "Out of my way!$"

CrystalLake_Movement_PlayerPushedAway::
	walk_right
	face_left
	delay_8
	face_down
	step_end

CrystalLake_Movement_LochLeaves::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

@CARBINK DIALOGUE

CrystalLake_EventScript_CarbinkSpeaks::
	callnative LockPlayerFieldControls
	faceplayer
	playmoncry SPECIES_CARBINK, CRY_MODE_NORMAL
	msgbox CrystalLake_Text_CarbinkSpeaks1, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	callnative UnlockPlayerFieldControls
	end

CrystalLake_EventScript_CarbinkSpeaks2::
	callnative LockPlayerFieldControls
	faceplayer
	playmoncry SPECIES_CARBINK, CRY_MODE_NORMAL
	msgbox CrystalLake_Text_CarbinkSpeaks2, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	callnative UnlockPlayerFieldControls
	end

CrystalLake_EventScript_CarbinkSpeaks3::
	callnative LockPlayerFieldControls
	faceplayer
	playmoncry SPECIES_CARBINK, CRY_MODE_NORMAL
	msgbox CrystalLake_Text_CarbinkSpeaks3, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	callnative UnlockPlayerFieldControls
	end

CrystalLake_Text_CarbinkSpeaks1::
	.string "Car! Bink!$"

CrystalLake_Text_CarbinkSpeaks2::
	.string "Bin! Car...!$"

CrystalLake_Text_CarbinkSpeaks3::
	.string "BinkBink!$"

@MEW DIALOGUE

CrystalLake_EventScript_MewDialogue::
	lock
	faceplayer
	msgbox CrystalLake_Text_MewDialogue, MSGBOX_DEFAULT
	closemessage
	release
	end

CrystalLake_Text_MewDialogue::
	.string "{PLAYER} I'm sorry I lied to you\n"
	.string "about being a human! I hope you\l"
	.string "aren't mad!\p"
	.string "It's just that, I needed to sell\n"
	.string "the bit that I was a human is all,\l"
	.string "and ya know, if you didn't know,\l"
	.string "then less chance of giving it away!\p"
	.string "...\l"
	.string "HUH?! I didn't fool you at all?\l"
	.string "You thought it was really obvious?\l"
	.string "Well... I guess I did take that ball\n"
	.string "when you were right next to me.\p"
	.string "I guess nothing gets past you!\l"
	.string "Well if you aren't mad, that's ok!\l"
	.string "You're a good friend {PLAYER}!\l"
	.string "Talk to Diancie when you are ready\n"
	.string "to hear about the Pure Essence.\p"
	.string "She can explain it better than me\n"
	.string "anyways...!$"

@DIANCIE BOSS FIGHT

CrystalLake_EventScript_DiancieBossFight::
	callnative LockPlayerFieldControls
	goto_if_set FLAG_DEFEATED_DIANCIE, CrystalLake_EventScript_DianciePostFightDialogue
	applymovement LOCAL_ID_MEW_CRYSTALLAKE, CrystalLake_Movement_MewWalksUp
	waitmovement 0
	msgbox CrystalLake_Text_DianciePrelude1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_MEW_CRYSTALLAKE, CrystalLake_Movement_EveJumpsUpandDownUp
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	waitmovement 0
	msgbox CrystalLake_Text_DianciePrelude2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_MEW_CRYSTALLAKE, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox CrystalLake_Text_DianciePrelude3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_MEW_CRYSTALLAKE, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox CrystalLake_Text_DianciePrelude4, MSGBOX_DEFAULT
	closemessage
	fadeScreen FADE_TO_WHITE
	delay 16
	clearflag FLAG_HIDEDIANCIETEAM
	addobject LOCAL_ID_ORTHWORM
	addobject LOCAL_ID_AZUMARILL
	addobject LOCAL_ID_SABLEYE
	addobject LOCAL_ID_SLIGGOO_HISUI
	addobject LOCAL_ID_DUOSION
	delay 16
	fadeScreen FADE_FROM_WHITE
	delay 16
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCAL_ID_MEW_CRYSTALLAKE, Common_Movement_FaceRight
	waitmovement 0
	delay 16
	delay 16
	msgbox CrystalLake_Text_DianciePrelude5, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_MEW_CRYSTALLAKE, CrystalLake_Movement_MewWalksAway
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox CrystalLake_Text_DianciePrelude6, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_DIANCIE, CRY_MODE_NORMAL
	waitmoncry
	trainerbattle_no_intro TRAINER_DIANCIE, CrystalLake_Text_DiancieDefeat
	delay 8
	fadeScreen FADE_TO_WHITE
	delay 16
	setflag FLAG_HIDEDIANCIETEAM
	removeobject LOCAL_ID_ORTHWORM
	removeobject LOCAL_ID_AZUMARILL
	removeobject LOCAL_ID_SABLEYE
	removeobject LOCAL_ID_SLIGGOO_HISUI
	removeobject LOCAL_ID_DUOSION
	delay 16
	fadeScreen FADE_FROM_WHITE
	delay 16
	applymovement LOCAL_ID_MEW_CRYSTALLAKE, CrystalLake_Movement_MewWalksUpAfterWinning
	waitmovement 0
	applymovement LOCAL_ID_MEW_CRYSTALLAKE, CrystalLake_Movement_EveJumpsUpandDownLeft
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	waitmovement 0
	applymovement LOCAL_ID_MEW_CRYSTALLAKE, Common_Movement_FaceUp
	waitmovement 0
	msgbox CrystalLake_Text_DiancieAftermatch1, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_EARTH_ESSENCE
	msgbox CrystalLake_Text_DiancieAftermatch2, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement LOCAL_ID_MEW_CRYSTALLAKE, Common_Movement_FaceLeft
	waitmovement 0
	msgbox CrystalLake_Text_DiancieAftermatch3, MSGBOX_DEFAULT
	closemessage	
	applymovement LOCAL_ID_MEW_CRYSTALLAKE, CrystalLake_Movement_EveJumpsUpandDownUp
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox CrystalLake_Text_DiancieAftermatch4, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_HEART_SCALE
	giveitem ITEM_FAIRY_GEM
	fadeScreen FADE_TO_WHITE
	delay 16
	clearflag FLAG_HIDEBEFOREDIANCIE
	setflag FLAG_HIDEMEW_CRYSTAL_LAKE
	removeobject LOCAL_ID_MEW_CRYSTALLAKE
	addobject LOCAL_ID_EVE_CRYSTAL_LAKE
	setobjectxy LOCAL_ID_EVE_CRYSTAL_LAKE, 14, 17
	applymovement LOCAL_ID_EVE_CRYSTAL_LAKE, Common_Movement_FaceLeft
	waitmovement 0
	delay 16
	fadeScreen FADE_FROM_WHITE
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox CrystalLake_Text_DiancieAftermatch5, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_EVE_CRYSTAL_LAKE, CrystalLake_Movement_EveLeaves
	waitmovement 0
	removeobject LOCAL_ID_EVE_CRYSTAL_LAKE
	setflag FLAG_HIDEBEFOREDIANCIE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox CrystalLake_Text_DiancieAftermatch6, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_DEFEATED_DIANCIE
	addvar VAR_CRYSTAL_LAKE_SEQUENCE, 1
	callnative UnlockPlayerFieldControls
	end

CrystalLake_Movement_MewWalksUp::
	walk_up
	walk_right
	walk_up
	step_end

CrystalLake_Movement_MewWalksUpAfterWinning::
	walk_up
	walk_up
	face_left
	step_end

CrystalLake_Movement_MewWalksAway::
	walk_fast_down
	walk_fast_down
	face_up
	step_end

CrystalLake_Text_DianciePrelude1::
	.string "Diancie: I shall explain.\l"
	.string "{PLAYER}. You are not familiar\n"
	.string "with Pure Essence correct?\p"
	.string "It is the lifeblood of our planet.\l"
	.string "It is the energy that makes up...\n"
	.string "Everything. \p"
	.string "The ground you stand on, the water\n"
	.string "you drink, the air you breathe...\p"
	.string "Essence all have sources. Energy\n"
	.string "that springs boundlessly about\l"
	.string "our world.\p"
	.string "And so to keep these out of the\n"
	.string "hands of wrongdoing, and to keep\l"
	.string "the balance of nature, there are\l"
	.string "the ones called Guardians.\p"
	.string "Mew: ...\l"
	.string "Diancie: Our world is held together\n"
	.string "by five Essences.\p"
	.string "Earth. Which created our lands...\l"
	.string "Wind. Which created our air...\l"
	.string "Forest. Which created plants...\l"
	.string "Union. Which created life, emotion,\n"
	.string "humanity...\p"
	.string "And... Void. The one that creates...\n"
	.string "nothingness.\p"
	.string "For every something, there must be\n"
	.string "nothing.\p"
	.string "It is the counterbalance that\n"
	.string "glues them all together.\p"
	.string "And together, the five Essences\n"
	.string "flow into Purity, its complete\l"
	.string "form.\p"
	.string "I am the Guardian of the Earth\n"
	.string "Essence. It is from deep below\l"
	.string "this Crystal Lake that it flows.$"

CrystalLake_Text_DianciePrelude2::
	.string "Mew: The EVILTEAM jerkwads must\n"
	.string "have been after the Essence!\p"
	.string "But why?\l"
	.string "Diancie: I cannot fathom why. In\n"
	.string "fact, the removal of the Essence\l"
	.string "from this place is...Impossible.\p"
	.string "Mew: Really? Then what's there to\n"
	.string "worry about?!\p"
	.string "Diancie: Because while it is true,\n"
	.string "pure energy, which cannot be\l"
	.string "collected...\p"
	.string "...It can still exist in a physical\n"
	.string "form. Eventually, Essence can\l"
	.string "crystalize, excess of it spilling\l"
	.string "out like an overstuffed belly.\p"
	.string "Mew: Heehee... A full tummy sounds\n"
	.string "really nice...\p"
	.string "Diancie: Focus Mew! I'm explaining\n"
	.string "it to your friend!\p"
	.string "Anyways...\l"
	.string "If someone was to obtain a small\n"
	.string "fragment of all five Essences...\p"
	.string "...They would be able to create a\n"
	.string "Pure Essence.\p"
	.string "This would be an unlimited energy\n"
	.string "source, and in the hands of the\l"
	.string "wrong person, or even Pokémon...\p"
	.string "I shudder to think...$"
	
CrystalLake_Text_DianciePrelude3::
	.string "Diancie: They will surely return to\n"
	.string "this place. I'm afraid the reprieve\l"
	.string "you have brought me is only a\l"
	.string "temporary one.\p"
	.string "There is another problem as well.\l"
	.string "I have lost my ability to Mega\n"
	.string "Evolve. Without that power, my\l"
	.string "ability to protect this place is\l"
	.string "limited.\p"
	.string "The Pokémon who live here look at\n"
	.string "me as their princess.\p"
	.string "I cannot allow harm to befall them.\n"
	.string "Mew: Hmm... Well...\l"
	.string "That does sound like a problem!$"

CrystalLake_Text_DianciePrelude4::
	.string "Diancie: Mew, you trust this human\n"
	.string "a lot it seems.\p"
	.string "Mew: A hundred percent!\l"
	.string "Diancie: {PLAYER}, you fought to\n"
	.string "defend this place admirably.\p"
	.string "I will choose to place my trust in\n"
	.string "you as well.\p"
	.string "But first...$"

CrystalLake_Text_DianciePrelude5::
	.string "Diancie: I must see your power\n"
	.string "first hand!\p"
	.string "I may be weaker, but I do not\n"
	.string "defend this place alone.\p"
	.string "My peers shall assist me in this\n"
	.string "examination of your character!\p"
	.string "Mew: {PLAYER}! Good luck! You can\n"
	.string "do it!$"

CrystalLake_Text_DianciePrelude6::
	.string "Diancie: If you are to know the\n"
	.string "secrets of this world, of Mew's\l"
	.string "secret, of my duty, then I must\l"
	.string "make sure you are of strong will.\p"
	.string "I shall see if you are indeed\n"
	.string "worthy of becoming one which that\l"
	.string "we Pokémon can put our faith in.\p"
	.string "Prepare youself {PLAYER}!\l"
	.string "For my resolve of pure diamond!$"

CrystalLake_Text_DiancieDefeat::
	.string "Excellent!\l"
	.string "You're... strong.\l"
	.string "Not just in battle, but also in mind\n"
	.string "and heart.\p"
	.string "Mew was correct to trust a person\n"
	.string "like you!$"

CrystalLake_Text_DiancieAftermatch1::
	.string "Diancie: Now then, I am sure you\n"
	.string "are wondering what the point of\l"
	.string "this battle was.\p"
	.string "I would like to bestow upon you...\n"
	.string "this.\p"
	.string "Take it. It will be safer with you,\n"
	.string "I can rest assured of it.$"

CrystalLake_Text_DiancieAftermatch2::
	.string "Diancie: {PLAYER}. That is a shard\n"
	.string "of the Essence of Earth.\p"
	.string "I know it is small...but...\l"
	.string "It is the result of all the energy\n"
	.string "that has flown freely from this\l"
	.string "Earth.\p"
	.string "I cannot leave this place, for I\n"
	.string "cannot abandon the Pokémon that\l"
	.string "lives here, nor can I abandon the\l"
	.string "spot where the energy flows out.\p"
	.string "But... this way, if the members of\n"
	.string "EVILTEAM return, they will be\l"
	.string "unable to take this piece of the\l"
	.string "Pure Essence away.\p"
	.string "Mew: But... Wait! Isn't this just as\n"
	.string "dangerous to give it to {PLAYER}?\p"
	.string "What if EVILTEAM hunts them down\n"
	.string "for what happened today?\p"
	.string "Diancie: This is why I tested their\n"
	.string "strength the way I did.\p"
	.string "I do not believe harm will befall\n"
	.string "this fragment in {PLAYER}'s hands.\p"
	.string "And besides, even if they were to\n"
	.string "encounter one another...\p"
	.string "They will have no reason to think\n"
	.string "that they are in possession of the\l"
	.string "Earth Essence.$"

CrystalLake_Text_DiancieAftermatch3::
	.string "Mew: Still! Are you sure you are ok\n"
	.string "with this {PLAYER}? I don't want\l"
	.string "to put you in any danger...\p"
	.string "I wish we knew more about what\n"
	.string "EVILTEAM's plans were!\p"
	.string "...\l"
	.string "Huh!? You have an idea?\l"
	.string "...\l"
	.string "So the grunt who was at the docks\n"
	.string "and the flower shop was talking\l"
	.string "about looking for a prototype...?\p"
	.string "Aaaaaaah!!! Those trainers from\n"
	.string "the docks! Charlie and Dawn!\p"
	.string "Come to think of it... they said\n"
	.string "something about a prototype when\l"
	.string "we met them!\p"
	.string "So EVILTEAM was after their cargo!\l"
	.string "Then that means that maybe if we\n"
	.string "can find those two, we can help\l"
	.string "each other!\p"
	.string "They were really nice, and they\n"
	.string "helped you right {PLAYER}?\p"
	.string "We can trust them!\l"
	.string "Diancie: Hmm... You may be being a\n"
	.string "bit naive Mew.\p"
	.string "I would request you refrain from\n"
	.string "telling these two about the shard\l"
	.string "of essence, regardless.\p"
	.string "This knowledge should remain with\n"
	.string "you two alone.\p"
	.string "Mew: You can count on me to keep a\n"
	.string "secret Diancie!\p"
	.string "I'm great at lying!\l"
	.string "Diancie: I somehow don't believe\n"
	.string "you on that front.\p"
	.string "What is concerning is that you\n"
	.string "mentioned they were after the\l"
	.string "Gracedia?\p"
	.string "Mew: Shaymin!$"

CrystalLake_Text_DiancieAftermatch4::
	.string "Shaymin may be in trouble!\l"
	.string "Diancie: Then why do you two not\n"
	.string "split up? {PLAYER} can locate\l"
	.string "these friends of yours.\p"
	.string "Meanwhile you can fly over Mt.Aeon\n"
	.string "and meet with Shaymin.\p"
	.string "Mew: That was just what I was\n"
	.string "thinking!\p"
	.string "Diancie: {PLAYER}, as I said, I\n"
	.string "must remain here.\p"
	.string "Without my ability to Mega Evolve,\n"
	.string "I would only be a hinderance.\p"
	.string "I can however, give you these to\n"
	.string "assist you.$"

CrystalLake_Text_DiancieAftermatch5::
	.string "Eve: I think I should probably try\n"
	.string "to stay like this when I can.\p"
	.string "Anything to lower suspicion.\l"
	.string "{PLAYER}! Lets meet again in the\n"
	.string "Flower Paradise!\p"
	.string "Lets stop these EVILTEAM jerks\n"
	.string "and keep Kusho safe!$"

CrystalLake_Movement_EveLeaves::
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

CrystalLake_Text_DiancieAftermatch6::
	.string "Diancie: {PLAYER}. I'm glad Mew met\n"
	.string "you.\p"
	.string "Hmm... they didn't mention why they\n"
	.string "chose you specifically.\p"
	.string "Well I suppose it doesn't matter.\l"
	.string "You have a good heart.\l"
	.string "Best of luck. Um... Kusho is kind of\n"
	.string "in your hands for now!\p"
	.string "Stay safe, and keep an eye on Mew.$"

CrystalLake_Movement_EveJumpsUpandDownLeft::
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	step_end

CrystalLake_EventScript_DianciePostFightDialogue::
	callnative LockPlayerFieldControls
	faceplayer
	msgbox CrystalLake_Text_DianciePostFightDialogue, MSGBOX_DEFAULT
	closemessage
	callnative UnlockPlayerFieldControls
	end

CrystalLake_Text_DianciePostFightDialogue::
	.string "Diancie: Oh hello again {PLAYER}!\n"
	.string "I hope all is going well.\p"
	.string "Do not worry about me. If those\n"
	.string "people come back, even if this\l"
	.string "place were to fall, they will never\l"
	.string "be able to retrieve the Essence.\p"
	.string "However, that will not happen.\l"
	.string "We Pokémon will fight our hardest\n"
	.string "to protect what is precious to us.\p"
	.string "I would like this to be over, so I\n"
	.string "can play with Mew again like we\l"
	.string "used to...\p"
	.string "Keep an eye on Mew ok? Or um...Eve?\l"
	.string "They're a trusted friend.\p"
	.string "We all have things we wish to\n"
	.string "protect.\p"
	.string "Best of luck!$"
