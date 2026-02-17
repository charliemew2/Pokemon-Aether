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
	msgbox BlossomwoodTown_Text_GaiaBossFight1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_GRUNT1M, BlossomwoodTown_Movement_GruntsMoveOutOfWay
	applymovement LOCAL_ID_GRUNT1F, BlossomwoodTown_Movement_GruntsMoveOutOfWay
	waitmovement 0
	delay 16
	applymovement LOCAL_ID_ADMIN_GAIA_BLOSSOMTOWN, BlossomwoodTown_Movement_GaiaApproachesPlayer
	waitmovement 0
	trainerbattle_no_intro TRAINER_ADMIN_GAIA_BLOSSOMTOWN, BlossomwoodTown_Text_GaiaBossFightDefeat
	removeobject LOCAL_ID_GRUNT1M
	removeobject LOCAL_ID_GRUNT1F
	removeobject LOCAL_ID_GRUNT2M
	removeobject LOCAL_ID_GRUNT2F
	removeobject LOCAL_ID_ADMIN_GAIA_BLOSSOMTOWN
	setflag FLAG_GAIA_GRUNTS_BLOCK_BLOSSOMWOODTOWN
	setflag FLAG_DEFEATED_GAIA
	addvar VAR_BLOSSOMTOWN_EVENTS, 1
	release
	end

BlossomwoodTown_EventScript_AlignPlayer::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	return

BlossomwoodTown_Text_GaiaBossFight1::
	.string "Test$"

BlossomwoodTown_Movement_GruntsMoveOutOfWay::
	walk_up
	face_down
	step_end

BlossomwoodTown_Movement_GaiaApproachesPlayer::
	walk_right
	walk_right
	step_end

BlossomwoodTown_Text_GaiaBossFightDefeat::
	.string "Unreal...!$"
