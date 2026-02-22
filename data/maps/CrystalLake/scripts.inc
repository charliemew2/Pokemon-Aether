CrystalLake_MapScripts::
	.byte 0

@PREP FOR LOCH BOSS FIGHT

CrystalLake_EventScript_LochFightPreperation::
	lock
	msgbox CrystalLake_Text_LochFightPreperation, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, CrystalLake_EventScript_RetreatToPrepareLoch
	case YES, CrystalLake_EventScript_LochBossFight
	release
	end

CrystalLake_Text_LochFightPreperation::
	.string "You see someone up ahead.\l"
	.string "Confront them?$"

CrystalLake_EventScript_RetreatToPrepareLoch::
	msgbox CrystalLake_Text_YouShouldPrepareBeforeLoch, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	release
	end

CrystalLake_Text_YouShouldPrepareBeforeLoch::
	.string "You decide to take a moment to\n"
	.string "better prepare...$"

@LOCH BOSS FIGHT

CrystalLake_EventScript_LochBossFight::
	lock
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
	applymovement LOCAL_ID_CARBINK3, CrystalLake_Movement_MoveCarbink3
	applymovement LOCAL_ID_CARBINK4, CrystalLake_Movement_MoveCarbink4
	applymovement LOCAL_ID_CARBINK5, CrystalLake_Movement_MoveCarbink5
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
	release
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
	lock
	faceplayer
	playmoncry SPECIES_CARBINK, CRY_MODE_NORMAL
	msgbox CrystalLake_Text_CarbinkSpeaks1, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	release
	end

CrystalLake_EventScript_CarbinkSpeaks2::
	lock
	faceplayer
	playmoncry SPECIES_CARBINK, CRY_MODE_NORMAL
	msgbox CrystalLake_Text_CarbinkSpeaks2, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	release
	end

CrystalLake_EventScript_CarbinkSpeaks3::
	lock
	faceplayer
	playmoncry SPECIES_CARBINK, CRY_MODE_NORMAL
	msgbox CrystalLake_Text_CarbinkSpeaks3, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	release
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

