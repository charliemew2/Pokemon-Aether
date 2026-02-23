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
	delay 16
	applymovement LOCAL_ID_EVE_CRYSTAL_LAKE, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
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
	.string "Mew: Uh huh! I had to. Those creeps\n"
	.string "from EVILTEAM had been chasing me\l"
	.string "for months!\p"
	.string "What better way to fool them? I\n"
	.string "needed to know why they were\l"
	.string "after me!\p"
	.string "Diancie: I assumed as much. They\n"
	.string "must be after the Pure Essence.\p"
	.string "Mew: That's what I was afraid of...\l"
	.string "Diancie: They were after Shaymin?\l"
	.string "Mew: How did you know?!\l"
	.string "Diancie: My Carbink have eyes and\n"
	.string "ears all over this cave, silly!\p"
	.string "That woman known as Loch kept\n"
	.string "murmuring to herself about the\l"
	.string "Gracedia.\p"
	.string "Mew: ...\l"
	.string "Diancie: You there, human!\l"
	.string "You're probably wondering what we\n"
	.string "are talking about.\p"
	.string "I'm happy to explain, since Mew\n"
	.string "clearly trusts you!\p"
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
	.string "you... {PLAYER}, your name was?\p"
	.string "Come speak to me when you are\n"
	.string "ready.$"

CrystalLake_Text_EveExplainsTrueForm::
	.string "Mew: Surprise!\l"
	.string "...\l"
	.string "HUH?\l"
	.string "You had a feeling that I was Mew?\l"
	.string "Yeah right! My disguise was the\n"
	.string "best! Transform is the best move\l"
	.string "in the world! Heehee!\p"
	.string "Diancie: I don't think it matters\n"
	.string "much...Mew.\p"
	.string "So, you were disguised as a human?$"

CrystalLake_Text_EveAndDiancieConvo::
	.string "Eve: Diancie! You're ok! I was so\n"
	.string "worried!\p"
	.string "Diancie: Hmm... Your voice is one I\n"
	.string "recognize, but not your body.\p"
	.string "So, is this a friend of yours?\l"
	.string "Eve: Yes! This is {PLAYER}! They've\n"
	.string "been really helpful, and fun!$"

CrystalLake_Text_DiancieArrives::
	.string "???: I know that voice!\l"
	.string "It's been a while!$"

CrystalLake_Text_EveThanksPlayer::
	.string "{PLAYER} Oh my gosh! Thank you!\l"
	.string "Thankyouthankyouthankyou!\l"
	.string "My friend is safe for sure now!\l"
	.string "Huh? You want to know where she\n"
	.string "is? Well silly, she's right here!\p"
	.string "It looks like we lucked out.\l"
	.string "EVILTEAM had the right info, they\n"
	.string "just didn't know what she was\l"
	.string "capable of.\p"
	.string "We both can do the same trick!\l"
	.string "Um, Player, I promised I'd tell you\n"
	.string "everything, but it's probably a\l"
	.string "bit easier for me to show you.$"

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
	.string "Not you.$"

CrystalLake_Text_LochBossFight2::
	.string "Certainly not you.$"

CrystalLake_Text_LochBossFight3::
	.string "None of you! Not one of you is the\n"
	.string "Earth Guardian!$"

CrystalLake_Text_LochBossFight4::
	.string "Hmm? What's this? Another child?$"

CrystalLake_Text_LochBossFight5::
	.string "Well this is RICH! Here to avenge\n"
	.string "your friend, kid?\p"
	.string "Hehe... At least I assume they're\n"
	.string "your friend.\p"
	.string "Eh. Not like it matters to me.\l"
	.string "You've actually caught me when I'm\n"
	.string "in a rather bad mood!\p"
	.string "You see I had to dirty myself by\n"
	.string "walking through this valley with\l"
	.string "a group of weak underlings...\p"
	.string "...But then! Some kid showed up and\n"
	.string "challenged me to a Pokémon battle!\p"
	.string "Not sure where the hell they came\n"
	.string "from, almost like they just came\l"
	.string "outta thin air.\p"
	.string "But eh, beating them up sure did\n"
	.string "make me feel better!\p"
	.string "The problem is... I'm where I'm\n"
	.string "supposed to be, but there is no\l"
	.string "Earth Guardian here!\p"
	.string "So I'm angry again! You! Kid!\l"
	.string "You want to play hero like that\n"
	.string "last one?\p"
	.string "Hehe... Don't make me laugh. Gaia is\n"
	.string "always so formal and proper.\p"
	.string "There's a reason I, Loch, am the\n"
	.string "Admin that cuts right to the\l"
	.string "heart of the matter!\p"
	.string "Feel my wrath kid!$"

CrystalLake_Text_LochDefeat::
	.string "WHAT?!\l"
	.string "I was...cut down?\l"
	.string "This...This just can't be!$"

CrystalLake_Text_LochBossFightPostBattle::
	.string "...\l"
	.string "Snrk...\l"
	.string "GRRRR...\l"
	.string "You.\l"
	.string "You dare...\l"
	.string "...\l"
	.string "Hmph.\l"
	.string "I don't have time for this.\l"
	.string "With no Pokémon, my chance of\n"
	.string "forcing you to submit is low.\p"
	.string "How... unfortunate.\l"
	.string "Fine. You win. What I'm looking for\n"
	.string "doesn't appear to even be here...\p"
	.string "Hmph. Kid. You seriously messed up\n"
	.string "by crossing me today. I showed you\l"
	.string "no mercy, and still lost.\p"
	.string "I take losing VERY personally.\l"
	.string "Next time, you'll be the loser. You\n"
	.string "will get off freely for now.\l"
	.string "Now OUT of my WAY!$"

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
	.string "{PLAYER}, I'm sorry I deceived you\n"
	.string "like I did. I just... I couldn't show\l"
	.string "myself as Mew in public.\p"
	.string "That's why I left the docks when I\n"
	.string "saw that grunt before.\p"
	.string "I got scared!\l"
	.string "I flew over the mountain ahead of\n"
	.string "you and that's how I saw those\l"
	.string "jerks in Blossomwood Town!\p"
	.string "But when you showed up, I felt like\n"
	.string "I could do anything! I felt brave!\p"
	.string "That morning at the shrine um...\n"
	.string "well... The reason I came to you...\p"
	.string "We can talk about it later. You're\n"
	.string "helping me now, and I appreciate\l"
	.string "it a lot!\p"
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
	.string "Diancie: Alright. I shall explain.\l"
	.string "{PLAYER}, do you believe in other worlds?\l"
	.string "Would you believe that there are\n"
	.string "many worlds just like our own?\p"
	.string "Some are alike, and some are not.\l"
	.string "But the important thing is they\n"
	.string "all share a common trend.\p"
	.string "They are made of Essence. Pure\n"
	.string "Essence, as a matter of fact.\p"
	.string "It is the energy that makes up...\n"
	.string "Everything. \p"
	.string "The ground you stand on, the water\n"
	.string "you drink, the air you breathe...\l"
	.string "So on and so on.\p"
	.string "Essence however, can sometimes\n"
	.string "crystalize, they can become truly\l"
	.string "tangible.\p"
	.string "Some worlds, it never does. They\n"
	.string "are rare, but those worlds will...\p"
	.string "They eventually crumble into a\n"
	.string "place of nothingness and despair.\p"
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
	.string "To protect the very root of our\n"
	.string "Essence, we stand as Guardians.\p"
	.string "I am the Earth Guardian.\l"
	.string "I possess the very nature of the\n"
	.string "Essence of Earth.$"

CrystalLake_Text_DianciePrelude2::
	.string "Mew: But those EVILTEAM jerks...\n"
	.string "They want the Essences? But why?\p"
	.string "Diancie: I cannot fathom why they\n"
	.string "would want them. For many many\l"
	.string "years, we Guardians have warded\l"
	.string "off those who hunt for them.\p"
	.string "But truthfully, my power has...\n"
	.string "gotten weaker.\p"
	.string "Mew: That's why I was so worried\n"
	.string "about you...$"

CrystalLake_Text_DianciePrelude3::
	.string "Mew: {PLAYER}, I've known many of\n"
	.string "the guardians for a long time.\p"
	.string "A lot of them are really nice!\l"
	.string "Though a couple of them are very\n"
	.string "scary...\p"
	.string "Some are just jerks!\l"
	.string "But... They're all really powerful!\l"
	.string "If something was to happen to\n"
	.string "them, and the Essences were taken\l"
	.string "then...Kusho...\p"
	.string "I don't know what would happen...\l"
	.string "{PLAYER}, you might not believe me\n"
	.string "but... I'm not actually that strong.\p"
	.string "That's why I needed help.\l"
	.string "And I chose you. Because...you...\l"
	.string "...\l"
	.string "Diancie: Mew!$"

CrystalLake_Text_DianciePrelude4::
	.string "This human. You clearly think that\n"
	.string "they can help us.\p"
	.string "Mew: I need to save Kusho!\l"
	.string "I want to protect my friends!\l"
	.string "My home!\l"
	.string "But I need help!\l"
	.string "Humans and Pokémon can work side\n"
	.string "by side!\p"
	.string "That's also why, I've decided to\n"
	.string "become a trainer.\p"
	.string "I can get stronger in a different\n"
	.string "way.\p"
	.string "But I believe in {PLAYER}! I know\n"
	.string "they can help us! If they didn't,\l"
	.string "then they would have stayed home!\p"
	.string "Diancie: ...\l"
	.string "{PLAYER}\l"
	.string "I will be honest.\l"
	.string "I have weakened over the years,\n"
	.string "and I worry for the Earth Essence.\p"
	.string "My time as its guardian has been\n"
	.string "slowly coming to an end.\p"
	.string "Mew has been a trusted friend of\n"
	.string "mine for many years.\p"
	.string "So I will trust you as well. You\n"
	.string "shall take on the Essence of Earth\l"
	.string "in my steed!$"

CrystalLake_Text_DianciePrelude5::
	.string "Diancie: However! I must see if\n"
	.string "you can handle such a power!\p"
	.string "Step away Mew!\l"
	.string "Mew: {PLAYER}! Good luck! You can\n"
	.string "do it!$"

CrystalLake_Text_DianciePrelude6::
	.string "Diancie: I apologize for this, but\n"
	.string "I must test you here. I may be\l"
	.string "weaker, but don't think that means\l"
	.string "I'm a pushover!\p"
	.string "With my friends who have lived with\n"
	.string "me in this cavern of crystal...\p"
	.string "We shall see if you are worthy of\n"
	.string "taking on our mantle!\p"
	.string "Mew! Let me see if your faith was\n"
	.string "misplaced in this human!\p"
	.string "Let's battle!$"

CrystalLake_Text_DiancieDefeat::
	.string "Excellent!\l"
	.string "You're... strong.\l"
	.string "Not just in battle, but also in mind\n"
	.string "and heart.\p"
	.string "Mew was correct to trust a person\n"
	.string "like you!$"

CrystalLake_Text_DiancieAftermatch1::
	.string "Diancie: Well done {PLAYER}!\l"
	.string "...Ow...\l"
	.string "you're certainly strong...\p"
	.string "Oh don't worry about these little\n"
	.string "bruises! I'm as tough as diamond!\p"
	.string "Mew: I knew it {PLAYER}! I knew\n"
	.string "you were strong enough!\p"
	.string "But um... Diancie, I know you're a\n"
	.string "bit weaker but surely you were\l"
	.string "hol...\p"
	.string "Diancie: AHEM!\l"
	.string "While it is true I didn't exactly\n"
	.string "come at you with my full strength,\l"
	.string "it wasn't because I didn't want to.\p"
	.string "It's rather, I couldn't.\l"
	.string "Regardless, you have still beaten\n"
	.string "me.\p"
	.string "And besides Mew, if I thought this\n"
	.string "trainer demonstrated cruelty and\l"
	.string "callousness to our peers...\p"
	.string "Well I would not be dignifying them\n"
	.string "with this!\p"
	.string "Take it {PLAYER}. It will be safer\n"
	.string "with a trainer such as yourself.$"

CrystalLake_Text_DiancieAftermatch2::
	.string "Diancie: Hmm? You seem uneasy? I\n"
	.string "know I'm asking you a lot to take\l"
	.string "this.\p"
	.string "...\l"
	.string "Ah. You're worried that EVILTEAM\n"
	.string "will come after you?\p"
	.string "Mew: That's a good point. Um, we had\n"
	.string "to get really close to them to\l"
	.string "find out what they were planning...\p"
	.string "Maybe they'll us down!\l"
	.string "Oh no...this is my fault...\l"
	.string "Diancie: Oh? {PLAYER}, you look\n"
	.string "like you have an idea?\p"
	.string "...$"

CrystalLake_Text_DiancieAftermatch3::
	.string "Mew: Oh! Those trainers we met at\n"
	.string "the docks!\p"
	.string "Charlie and Dawn right?\l"
	.string "You think they can help us?\l"
	.string "...\l"
	.string "Huh!? The grunt from the flower\n"
	.string "shop mentioned a Prototype?\p"
	.string "That must mean they were the ones\n"
	.string "who were after the cargo...\p"
	.string "That makes sense! That means that\n"
	.string "Charlie and Dawn aren't working\l"
	.string "with EVILTEAM!\p"
	.string "We can trust them. If we can find\n"
	.string "them, then maybe we can help them\l"
	.string "in their search!\p"
	.string "Diancie: Gathering allies against\n"
	.string "a united cause?\p"
	.string "You are sure they are strong?\l"
	.string "Mew: Well to be fair, we haven't\n"
	.string "seen either of them battle...\p"
	.string "But they were both nice! And they\n"
	.string "helped {PLAYER} out!\p"
	.string "Isn't that right?\l"
	.string "Shoot, but they're probably long\n"
	.string "gone from the Docks by now.\p"
	.string "They said they were staying in\n"
	.string "CITYONE right?\p"
	.string "Wait! That's close by! That's north\n"
	.string "across Route 4!$"

CrystalLake_Text_DiancieAftermatch4::
	.string "Mew: Diancie! I'm going to try to\n"
	.string "meet with Shaymin!\p"
	.string "I think she may be in danger...!\l"
	.string "Diancie: And {PLAYER} will look\n"
	.string "for your friends?\p"
	.string "Mew: Sounds like a plan!\l"
	.string "Diancie: I wish I could be more\n"
	.string "help, but I fear without my ability\l"
	.string "to Mega Evolve, my power is limited.\p"
	.string "{PLAYER}, I will remain here. I look\n"
	.string "after all the Pokémon who live in\l"
	.string "this lake as their princess!\p"
	.string "I do have these I can give you.\n"
	.string "They may be useful.$"

CrystalLake_Text_DiancieAftermatch5::
	.string "Eve: I think I should probably try\n"
	.string "to stay like this when I can.\p"
	.string "Anything to lower suspicion.\l"
	.string "Diancie: Good luck you two!\l"
	.string "Eve: Chair! Lets meet again in the\n"
	.string "Flower Paradise after you meet\l"
	.string "the others!\p"
	.string "And... Thank you. Lets stop these\n"
	.string "jerks and keep Kusho safe!$"

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
	.string "If I regain my ability to unleash\n"
	.string "my true power, you will see me\l"
	.string "again soon.\p"
	.string "Best of luck. Um... Kusho is kind of\n"
	.string "in your hands for now!$"

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
	.string "I'm motivated to regain my power\n"
	.string "moreso than ever before.\p"
	.string "Keep an eye on Mew ok? Or um...Eve?\l"
	.string "They're a trusted friend. I don't\n"
	.string "get many visitors, and they come\l"
	.string "by enough to make me excited to\l"
	.string "see them.\p"
	.string "We all have things we wish to\n"
	.string "protect.\p"
	.string "Best of luck!$"
