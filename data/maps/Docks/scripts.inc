Docks_MapScripts::
	.byte 0

@VAR_DOCKS_CUTSCENE
	@0 - Triggers from talking to Eve and being escorted to Charlie and Dawn
	@1 - Triggers the Repel for the Basement before talking to Charlie and getting Pokeballs. Unsets when spoken to Charlie.
	@2 - Triggers Exterior Conversation with Charlie and Dawn - End of Variable trigger
	@3 - Allows Collection of the Super Rod

@START OF GAME PRE EXPLOSION CUTSCENE MEETING EVE AT DOCKS

SouthernDocks_EventScript_WalktoSideofEve::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement LOCAL_ID_EVESOUTHERNDOCKS, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCAL_ID_EVESOUTHERNDOCKS, Common_Movement_FaceUp
	waitmovement 0
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, SouthernDocks_Movement_PlayerAlignEve
	waitmovement 0
	applymovement LOCAL_ID_EVESOUTHERNDOCKS, Common_Movement_FaceLeft
	waitmovement 0
	goto SouthernDocks_EventScript_EveEscortToShip
	end

SouthernDocks_Movement_PlayerAlignEve::
	walk_left
	walk_down
	face_right
	step_end	

SouthernDocks_EventScript_EveEscortToShip::
	lock
	setflag FLAG_DOCKS_HIDENPCDURINGCUTSCENE
	setflag FLAG_DOCKS_HIDENPCAFTERDOCKSEVENTS
	applymovement LOCAL_ID_EVESOUTHERNDOCKS, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	msgbox SouthernDocks_Text_PlayerMeetsEveAtDocks, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_EVESOUTHERNDOCKS, SouthernDocks_Movement_EveJumpsUpandDown
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	waitmovement 0
	applymovement LOCAL_ID_EVESOUTHERNDOCKS, SouthernDocks_Movement_EveWalkswithPlayerToShip
	applymovement OBJ_EVENT_ID_PLAYER, SouthernDocks_Movement_PlayerWalkswithEveToShip
	waitmovement 0
	waitmovement 0
	msgbox SouthernDocks_Text_PlayerEveSpotCharlieDawn, MSGBOX_DEFAULT
	closemessage
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SouthernDocks_Movement_CameraPanDown
	waitmovement 0
	msgbox SouthernDocks_Text_DawnCharlieConversationDocks1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAMERA, SouthernDocks_Movement_CameraPanUp
	applymovement LOCAL_ID_CHARLIEDOCKS, SouthernDocks_Movement_CharlieWalksUptoPlayerEve
	applymovement LOCAL_ID_DAWNDOCKS, SouthernDocks_Movement_DawnWalksUptoPlayerEve
	applymovement LOCAL_ID_EVESOUTHERNDOCKS, SouthernDocks_Movement_EveMovesOutofCharlieWay
	waitmovement LOCAL_ID_DAWNDOCKS
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	special RemoveCameraObject
	msgbox SouthernDocks_Text_DawnCharlieConversationPlayerEve1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_EVESOUTHERNDOCKS, SouthernDocks_Movement_EveJumpsUpandDown2
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	playse SE_LEDGE
	delay 16
	waitmovement 0
	msgbox SouthernDocks_Text_EveAsksCharlieDawnIfTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_CHARLIEDOCKS, SouthernDocks_Movement_CharlieBegsDawn
	waitmovement 0
	msgbox SouthernDocks_Text_CharlieAndDawnArgueStartGame1, MSGBOX_DEFAULT 
	closemessage
	applymovement LOCAL_ID_DAWNDOCKS, Common_Movement_FaceUp
	waitmovement 0
	msgbox SouthernDocks_Text_CharlieAndDawnArgueStartGame2, MSGBOX_DEFAULT
	closemessage
	fadeoutbgm 0
	playse SE_M_EARTHQUAKE
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 32  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	applymovement LOCAL_ID_CHARLIEDOCKS, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	applymovement LOCAL_ID_EVESOUTHERNDOCKS, Common_Movement_FaceUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCAL_ID_CHARLIEDOCKS, Common_Movement_ExclamationMark
	applymovement LOCAL_ID_EVESOUTHERNDOCKS, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCAL_ID_DAWNDOCKS, Common_Movement_ExclamationMark
	waitmovement 0
	waitstate
	waitse
	playbgm MUS_BIRCH_LAB, TRUE
	msgbox SouthernDocks_Text_CharlieInvestigatesExplosion, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_CHARLIEDOCKS, SouthernDocks_Movement_CharlieInvestigatesExplosion
	waitmovement 0
	msgbox SouthernDocks_Text_EveDawnInvestigatesExplosion, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_DAWNDOCKS, SouthernDocks_Movement_DawnInvestigatesExplosion
	applymovement LOCAL_ID_EVESOUTHERNDOCKS, SouthernDocks_Movement_EveInvestigatesExplosion
	waitmovement 0
	removeobject LOCAL_ID_EVESOUTHERNDOCKS
	removeobject LOCAL_ID_DAWNDOCKS
	removeobject LOCAL_ID_CHARLIEDOCKS
	addvar VAR_DOCKS_CUTSCENE 1
	clearflag FLAG_DOCKS_HIDENPCDURINGCUTSCENE
	clearflag FLAG_DOCKS_HIDENPCAFTERDOCKSEVENTS
	setflag FLAG_DOCKS_BLOCKDOCKS
	setflag FLAG_DOCKS_HIDECHARLIEDAWNDOCKSCONVO
	release
	end

SouthernDocks_Text_PlayerMeetsEveAtDocks::
	.string "You made it! Yay! Come with me!$"

SouthernDocks_Movement_EveJumpsUpandDown::
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	step_end

SouthernDocks_Movement_EveJumpsUpandDown2::
	jump_in_place_right
	jump_in_place_right
	jump_in_place_right
	step_end

SouthernDocks_Movement_EveWalkswithPlayerToShip::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

SouthernDocks_Movement_PlayerWalkswithEveToShip::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

SouthernDocks_Text_PlayerEveSpotCharlieDawn::
	.string "Oh! Those two...They look\n"
	.string "strong! Whatcha think {PLAYER}?$"

SouthernDocks_Movement_CameraPanDown::
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SouthernDocks_Text_DawnCharlieConversationDocks1::
	.string "Boy: ...So we're supposed to go to\n"
	.string "the observatory? It's far away...\p"
	.string "Girl: Yeah. We're supposed to meet\n"
	.string "the professor's grandkid here.\p"
	.string "They're supposed to take us to \n"
	.string "see him when they get here.\p"
	.string "The prototype supposedly\n"
	.string "arrived here yesterday on the \l"
	.string "cargo ship. Its in the warehouse.\p"
	.string "Boy: Well I'll tell you. Being on a\n"
	.string "boat for two weeks was something.\p"
	.string "I'm just glad to be on dry land!\l"
	.string "Still, this prototype must be\n"
	.string "really important if they needed\l"
	.string "both of us to make sure it was\l"
	.string "delivered safe.\p"
	.string "Girl: Well, there's a lot of cute\n"
	.string "shopping stalls around this port!\p"
	.string "Wanna check em out while we wait?\l"
	.string "Boy: Yeah sure! I'm down. Hopefully\n"
	.string "there's some food. I'm starved!$"

SouthernDocks_Movement_CameraPanUp::
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SouthernDocks_Movement_CharlieWalksUptoPlayerEve::
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end

SouthernDocks_Movement_DawnWalksUptoPlayerEve::
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end

SouthernDocks_Movement_EveMovesOutofCharlieWay::
	delay_16
	delay_16
	walk_up
	walk_left
	face_right
	step_end

SouthernDocks_Text_DawnCharlieConversationPlayerEve1::
	.string "Boy: Ah! Pardon us. Do you two know\n"
	.string "what stalls are worth seeing here?$"

SouthernDocks_Text_EveAsksCharlieDawnIfTrainers::
	.string "Eve: Nope! Never been to them! Are\n"
	.string "you from really really far away?\p"
	.string "Girl: Well you could say that. I'm\n"
	.string "from the Sinnoh Region.\p"
	.string "Boy: And I'm from Johto! You both\n"
	.string "seem like newbie trainers?\p"
	.string "Eve: Woah! You can tell?\l"
	.string "Boy: You both have only one\n"
	.string "Pokéball hanging on your belts.\p"
	.string "It's kind of a giveaway.\l"
	.string "Girl: If you were looking for a\n"
	.string "battle, I'm afraid we're busy.$"

SouthernDocks_Movement_CharlieBegsDawn::
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	face_down
	step_end

SouthernDocks_Text_CharlieAndDawnArgueStartGame1::
	.string "Boy: Aw come on Dawn. I'm kind of\n"
	.string "in the mood for a fight...\p"
	.string "There was almost nobody willing to\n"
	.string "battle either of us on the boat!$"

SouthernDocks_Text_CharlieAndDawnArgueStartGame2::
	.string "Dawn: And why do you think thats\n"
	.string "the case Charlie?\p"
	.string "I don't think anyone would be in\n"
	.string "the mood to battle trainers like...$"

SouthernDocks_Text_CharlieInvestigatesExplosion::
	.string  "Charlie: What WAS that?!\l"
	.string  "It sounded like it was from the\n"
	.string  "warehouse!\p"
	.string  "...!\l"
	.string  "Oh no! Could it have been damaged?$"

SouthernDocks_Movement_CharlieInvestigatesExplosion::
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

SouthernDocks_Movement_DawnInvestigatesExplosion::
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

SouthernDocks_Movement_EveInvestigatesExplosion::
	delay_16
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

SouthernDocks_Text_EveDawnInvestigatesExplosion::
	.string "Dawn: Wait up! Charlie!\l"
	.string "Eve: I wanna see! I wanna see!$"

@ NPC DIALOGUE POST EXPLOSION CUTSCENE

SouthernDocks_EventScript_TalkToDawnPostBoom::
	lock
	faceplayer
	msgbox SouthernDocks_Text_DawnPostBoomPreWarehouseNPC, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_DAWNDOCKSPOSTBOOMPREWAREHOUSE, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

SouthernDocks_EventScript_TalkToSailorPostBoom::
	lock
	faceplayer
	msgbox SouthernDocks_Text_SailorPostBoomTalkToDawn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_SAILORPOSTBOOMWAREHOUSETALKDAWN, Common_Movement_FaceRight
	waitmovement 0
	release
	end

SouthernDocks_EventScript_TalkToEvePostBoom::
	lock
	faceplayer
	msgbox SouthernDocks_Text_EvePostBoomPreWarehouseNPC, MSGBOX_DEFAULT
	closemessage
	release
	end

SouthernDocks_Text_EvePostBoomPreWarehouseNPC::
	.string "{PLAYER}...That quake was really\n"
	.string "scary...\p"
	.string "That wasn't fun at all!\l"
	.string "I really hope nobody is hurt!$"

SouthernDocks_Text_DawnPostBoomPreWarehouseNPC::
	.string "Ugh. This is not how I wanted to\n"
	.string "spend the first day of this trip...\p"
	.string "If anything happened to our stuff\n"
	.string "its gonna get really annoying!\p"
	.string "What is the Professor gonna say?l"
	.string "Hey, can you check on Charlie?\l"
	.string "He ran into the warehouse to\n"
	.string "see if our cargo was damaged.$"

SouthernDocks_Text_SailorPostBoomTalkToDawn::
	.string "The generator in the basement\n"
	.string "went completely haywire!\p"
	.string "All our cargo's gonna take\n"
	.string "even longer to unload now...\p"
	.string "That guy with the hat just ran\n"
	.string "right past me before I could blink!\p"
	.string "Said something about having to\n"
	.string "check his luggage?$"

SouthernDocks_EventScript_Sailor1NPCExplosion::
	lock
	faceplayer
	msgbox SouthernDocks_Text_Sailor1NPCExplosion, MSGBOX_DEFAULT
	closemessage
	release
	end

SouthernDocks_Text_Sailor1NPCExplosion::
	.string "When the power goes down here, it\n"
	.string "makes our work really difficult!\p"
	.string "MYREGION is really far away from\n"
	.string "other regions.\p"
	.string "Shipping cargo is really important\n"
	.string "for the people's lives here.$"

SouthernDocks_EventScript_Sailor2NPCExplosion::
	lock
	faceplayer
	msgbox SouthernDocks_Text_Sailor2NPCExplosion, MSGBOX_DEFAULT
	closemessage
	release
	end

SouthernDocks_Text_Sailor2NPCExplosion::
	.string "Aye! That old generator is always\n"
	.string "on the fritz.\p"
	.string "It was only a matter of time till\n"
	.string "she blew her top I guess.\p"
	.string "Hopefully nothing else was\n"
	.string "damaged...$"

SouthernDocks_EventScript_Sailor3NPCExplosion::
	lock
	faceplayer
	msgbox SouthernDocks_Text_Sailor3NPCExplosion, MSGBOX_DEFAULT
	closemessage
	release
	end

SouthernDocks_Text_Sailor3NPCExplosion::
	.string "We've had a lot of strange cargo\n"
	.string "recently. Unmarked I mean.\p"
	.string "There was also this wierd looking\n"
	.string "machine too that we had been\l"
	.string "keeping in the basement.\p"
	.string "Its suspicious but hey, I need to\n"
	.string "make a living, not ask questions!$"

SouthernDocks_EventScript_GuyByBoxesSeesBoom::
	lock
	faceplayer
	msgbox SouthernDocks_Text_GuyByBoxesSeesBoom, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_SOUTHERNDOCKSGUYBYBOXESCUTSCENE, Common_Movement_FaceUp
	waitmovement 0
	release
	end

SouthernDocks_Text_GuyByBoxesSeesBoom::
	.string "It's rare that they have any\n"
	.string "huge accidents here at the port.\p"
	.string "I hope everyone's ok!$"
	
SouthernDocks_EventScript_BeautyVendorNPCSeesBoom::
	lock
	faceplayer
	msgbox SouthernDocks_Text_BeautyVendorNPCSeesBoom, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_SOUTHERNDOCKSBEAUTYVENDORNPCCUTSCENE, Common_Movement_FaceDown
	waitmovement 0
	release
	end

SouthernDocks_Text_BeautyVendorNPCSeesBoom::
	.string "I sell flowers here on the dock\n"
	.string "every single day.\p"
	.string "This kind of thing is rare, but\n"
	.string "its a fright when it happens!$"

SouthernDocks_EventScript_OldWomenNPCSeesBoom::
	lock
	faceplayer
	msgbox SouthernDocks_Text_OldWomenNPCSeesBoom, MSGBOX_DEFAULT
	closemessage
	release
	end

SouthernDocks_Text_OldWomenNPCSeesBoom::
	.string "Oh goodness. This harbor is always\n"
	.string "so lively!\p"
	.string "Did you come to see the boats?\l"
	.string "I used to bring my grandchild\n"
	.string "out here to watch them.$"

@ CUTSCENE WITH CHARLIE AND DAWN - RECIEVE POKEDEX - ALLOWS PROGRESSION NORTHWARD

SouthernDocks_EventScript_PostBasementCutscene::
	lock
	msgbox SouthernDocks_Text_CharlieDawnPostBasement1, MSGBOX_DEFAULT
	closemessage
	call SouthernDocks_giveitem_POKEDEX
	msgbox SouthernDocks_Text_CharlieDawnPostBasement2, MSGBOX_DEFAULT
	closemessage
	addvar VAR_STARTER_CUTSCENE 1
	addvar VAR_DOCKS_CUTSCENE 1
	release
	end

SouthernDocks_Text_CharlieDawnPostBasement1::
	.string "Test 1$"

SouthernDocks_giveitem_POKEDEX::
	playfanfare MUS_OBTAIN_ITEM
	msgbox SouthernDocks_Text_GotPokedex, MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	special SetUnlockedPokedexFlags
	return

SouthernDocks_Text_GotPokedex::
	.string "You recieved a Pokédex from Dawn!$"

SouthernDocks_Text_CharlieDawnPostBasement2::
	.string "Test 2$"


@ STANDARD NPC DIALOGUE - UNCHANGED

SouthernDocks_EventScript_DocksLassNPCDialogue::
	lock
	faceplayer
	msgbox SouthernDocks_Text_DocksLassNPCDialogue, MSGBOX_DEFAULT
	closemessage
	release
	end

SouthernDocks_Text_DocksLassNPCDialogue::
	.string "Have you been to SECONDCITY?\l"
	.string "There's a ferry there that runs\n"
	.string "to this port every so often.\p"
	.string "MYREGION is an archipelago, so it\n"
	.string "has a large dependance on boats.\p"
	.string "SECONDCITY is home to Vandelay\n"
	.string "Industries! It's a tech company\l"
	.string "run by a...motley crew.\p"
	.string "They ship their goods through\n"
	.string "this port to other regions!$"

SouthernDocks_EventScript_DocksArtistNPCDialogue::
	lock
	faceplayer
	msgbox SouthernDocks_Text_DocksArtistNPCDialogue, MSGBOX_DEFAULT
	closemessage
	release
	end

SouthernDocks_Text_DocksArtistNPCDialogue::
	.string "MYREGION has only three major\n"
	.string "cities throughout.\p"
	.string "CITYONE, CITYTWO, and CITYTHREE.\l"
	.string "Most settlements are small but\n"
	.string "dense and full of people.\p"
	.string "It's beautiful here. Inspiring\n"
	.string "even! I could paint the days\l"
	.string "away until the end of time!$"

SouthernDocks_EventScript_DocksManNPCDialogue::
	lock
	faceplayer
	msgbox SouthernDocks_Text_DocksManNPCDialogue, MSGBOX_DEFAULT
	closemessage
	release
	end

SouthernDocks_Text_DocksManNPCDialogue::
	.string "The biggest city in MYREGION\n"
	.string "is called CITYONE.\p"
	.string "There's a highway east of the\n"
	.string "warehouse that trucks come to\l"
	.string "haul cargo to and from this port.\p"
	.string "This southernmost dock is the\n"
	.string "primary transport point for most\l"
	.string "international travel in MYREGION.$"


@ FISHERMAN GIVES SUPER ROD

SouthernDocks_EventScript_FishermanSuperRodGuy::
	lock
	goto_if_lt VAR_DOCKS_CUTSCENE, 3 SouthernDocks_EventScript_PreGivingSuperRodText
	goto_if_set FLAG_RECEIVED_SUPER_ROD, SouthernDocks_EventScript_FishermanAlreadyGaveSuperRod
	msgbox SouthernDocks_Text_FishermanGiveSuperRod, MSGBOX_DEFAULT
	call SouthernDocks_giveitem_SuperRod
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox SouthernDocks_Text_FishermanGiveSuperRod2, MSGBOX_DEFAULT
	closemessage
	end

SouthernDocks_EventScript_PreGivingSuperRodText::
	msgbox SouthernDocks_Text_PreGivingSuperRodText, MSGBOX_DEFAULT
	closemessage
	end

SouthernDocks_EventScript_FishermanAlreadyGaveSuperRod::
	msgbox SouthernDocks_Text_FishermanGaveSuperRodAlready, MSGBOX_DEFAULT
	closemessage
	release
	end

SouthernDocks_Text_PreGivingSuperRodText::
	.string "Wowzer! I hear stuff crash in the\n"
	.string "warehouse all the time...but this\l"
	.string "takes the cake!$"

SouthernDocks_Text_FishermanGiveSuperRod::
	.string "Hey you! Glad that nobody was\n"
	.string	"injured earlier.\p"
	.string "Hmm? I don't look like a dockhand.\l"
	.string "You are right!\l"
	.string "I'm a local fisherman.\l"
	.string "I catch and sell my goods seven\n"
	.string "days a week!\p"
	.string "Do you wanna become a fisherman?\l"
	.string "Take this! Then you can work for\n"
	.string "me one day! Wahaha!$"

SouthernDocks_giveitem_SuperRod::
	giveitem ITEM_SUPER_ROD
	return

SouthernDocks_Text_FishermanGiveSuperRod2::
	.string "That right there is the Super Rod!\l"
	.string "It can catch any fish in the seas\n"
	.string "of MYREGION!\p"
	.string "Just stand in front of water, and\n"
	.string "toss your line, and relax!\p"
	.string "If you get a bite, it won't be\n"
	.string "able to escape!\p"
	.string "Happy fishin!$"

SouthernDocks_Text_FishermanGaveSuperRodAlready::
	.string "Actually, have you heard of the\n"
	.string "Pokémon Phione?\p"
	.string "They're a mythical Pokémon that\n"
	.string "are followers of the Prince of\l"
	.string "Sea - Manaphy.\p"
	.string "MYREGION is directly in the path\n"
	.string "of the ocean currents that they\l"
	.string "drift down throughout the year.\p"
	.string "If you get lucky you may see one!\l"
	.string "My older brother lives really far\n"
	.string "north in CITYTHREE\p"
	.string "If you see a Phione and ever cross\n"
	.string "paths with him, show him!$"

@ NURSE JOY NPC SCRIPT

SouthernDocks_EventScript_NurseNPC::
	lock
	msgbox SouthernDocks_Text_NurseNPC, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SouthernDocks_EventScript_HealPkmn
	goto_if_eq VAR_RESULT, NO, SouthernDocks_EventScript_DocksNurseByeBye
	end	

SouthernDocks_Text_NurseNPC::
	.string "Oh dear. Accidents always happen.\l"
	.string "If you'd like, I can heal your\n"
	.string "Pokémon to full health for free?$"

SouthernDocks_EventScript_HealPkmn::
	call SouthernDocks_EventScript_NurseHeals
	end

SouthernDocks_EventScript_NurseHeals::
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	msgbox SouthernDocks_Text_ByeByeNurseHealed, MSGBOX_DEFAULT
	closemessage
	return

SouthernDocks_EventScript_DocksNurseByeBye::
	msgbox SouthernDocks_Text_ByeByeNurse, MSGBOX_DEFAULT
	closemessage
	return	

SouthernDocks_Text_ByeByeNurseHealed::
	.string "Be safe out there!$"

SouthernDocks_Text_ByeByeNurse::
	.string "Oh no worries! Good luck!\l"
	.string "Please stay safe out there!$"

@TEST FOR NPC XYZ PERM