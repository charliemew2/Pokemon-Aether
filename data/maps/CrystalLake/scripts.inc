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
	release
	end

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
