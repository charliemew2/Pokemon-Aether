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
	setflag FLAG_DOCKS_EVENTS_FINISHED_GET_POKEDEX
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
	goto_if_ge VAR_DOCKS_CUTSCENE, 3 SouthernDocks_EventScript_DocksSailorWarehouseNPCDialogue
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
	.string "What is the Professor gonna say?\l"
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
	.string "Kusho is really far away from\n"
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
	goto_if_set FLAG_DOCKS_BASEMENT_CUTSCENE_DONE, SouthernDocks_Text_GuybyBoxesPostCutscene
	msgbox SouthernDocks_Text_GuyByBoxesSeesBoom, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_SOUTHERNDOCKSGUYBYBOXESCUTSCENE, Common_Movement_FaceUp
	waitmovement 0
	release
	end

SouthernDocks_EventScript_GuybyBoxesPostCutscene::
	lock
	faceplayer
	msgbox SouthernDocks_Text_GuybyBoxesPostCutscene, MSGBOX_DEFAULT
	closemessage
	release
	end

SouthernDocks_Text_GuyByBoxesSeesBoom::
	.string "It's rare that they have any\n"
	.string "huge accidents here at the port.\p"
	.string "I hope everyone's ok!$"

SouthernDocks_Text_GuybyBoxesPostCutscene::
	.string "This dock is normally really busy.\l"
	.string "There's accidents every so often\n"
	.string "so what just happened isn't too \l"
	.string "out of the ordinary, I suppose.\p"
	.string "Hopefully the generator can be\n"
	.string "fixed and shipments can keep on\l"
	.string "moving!$"

SouthernDocks_EventScript_BeautyVendorNPCSeesBoom::
	lock
	faceplayer
	msgbox SouthernDocks_Text_BeautyVendorNPCPostBoomPreShopGiveBerries, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_SOUTHERNDOCKSBEAUTYVENDORNPCCUTSCENE, Common_Movement_FaceDown
	waitmovement 0
	release
	end

SouthernDocks_Text_BeautyVendorNPCSeesBoom::
	.string "I come here to sell flowers from \n"
	.string "Blossomwood Town every day!\p"
	.string "This kind of thing is rare, but\n"
	.string "its a fright when it happens!$"

SouthernDocks_EventScript_BeautyVendorNPCPostBoomPreShop::
	lock
	faceplayer
	goto_if_set FLAG_FLOWER_GIRL_DOCKS_SHOP, SouthernDocks_EventScript_BeautyVendorNPCSettingUpShop
	msgbox SouthernDocks_Text_BeautyVendorNPCPostBoomPreShopGiveBerries, MSGBOX_DEFAULT
	call Docks_giveitem_Berries
	closemessage 
	msgbox SouthernDocks_Text_BeautyVendorNPCPostBoomPreShopPostBerries, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_FLOWER_GIRL_DOCKS_SHOP
	release
	end

SouthernDocks_EventScript_BeautyVendorNPCSettingUpShop::
	msgbox SouthernDocks_Text_BeautyVendorNPCPostBoomPreShopPostBerries, MSGBOX_DEFAULT
	closemessage
	release
	end

SouthernDocks_Text_BeautyVendorNPCPostBoomPreShopGiveBerries::
	.string "That big accident was more than\n"
	.string "enough excitement for me today!\p"
	.string "Ah! Would you like to buy any\n"
	.string "flowers?\p"
	.string "Is what I would say, but I'm still\n"
	.string "getting my stall set up.\p"
	.string "Oh! You look like a trainer.\l"
	.string "It's berry season in Blossomwood\n" 
	.string "Town where I'm from. I picked some\l"
	.string "fresh today.\p"
	.string "You can have some!$"

Docks_giveitem_Berries::
	giveitem ITEM_ORAN_BERRY, 40
	giveitem ITEM_CHERI_BERRY, 5
	giveitem ITEM_PECHA_BERRY, 5
	giveitem ITEM_CHESTO_BERRY, 2
	giveitem ITEM_PERSIM_BERRY, 1
	return

SouthernDocks_Text_BeautyVendorNPCPostBoomPreShopPostBerries::
	.string "I'm still setting up shop for the\n"
	.string "day, so take those as an apology\l"
	.string "for the delay.\p"
	.string "I should be set up later!\l"
	.string "Come by again some other time!$"

SouthernDocks_EventScript_OldWomenNPCSeesBoom::
	lock
	faceplayer
	goto_if_set FLAG_DOCKS_BASEMENT_CUTSCENE_DONE, SouthernDocks_EventScript_Pokemart
	msgbox SouthernDocks_Text_OldWomenNPCSeesBoom, MSGBOX_DEFAULT
	closemessage
	release
	end

SouthernDocks_Text_OldWomenNPCSeesBoom::
	.string "I was in the middle of setting up\n"
	.string "my shop for the day when that\l"
	.string "dreadful BOOM lit up my old\l"
	.string "eardrums!\p"
	.string "Come back and see me later ok\n"
	.string "dearie? I should be open then.$"
	
@ CUTSCENE WITH CHARLIE AND DAWN - RECIEVE POKEDEX - ALLOWS PROGRESSION NORTHWARD

SouthernDocks_EventScript_PostBasementCutscene::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 16
	delay 16
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, SouthernDocks_Movement_PlayerWalksUptoDawnCharlie
	waitmovement 0
	delay 16
	applymovement LOCAL_ID_DAWNDOCKSAFTERBASEMENT, Common_Movement_FaceUp
	applymovement LOCAL_ID_CHARLIEDOCKSAFTERBASEMENT, Common_Movement_FaceUp
	waitmovement 0
	msgbox SouthernDocks_Text_CharlieDawnPostBasement1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_DAWNDOCKSAFTERBASEMENT, SouthernDocks_Movement_DawnGivesItem
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	delay 8
	msgbox SouthernDocks_Text_CharlieDawnPostBasement2, MSGBOX_DEFAULT
	call SouthernDocks_giveitem_TownMap
	msgbox SouthernDocks_Text_CharlieDawnPostBasement3, MSGBOX_DEFAULT
	delay 8
	call SouthernDocks_giveitem_POKEDEX
	closemessage
	delay 8
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement LOCAL_ID_DAWNDOCKSAFTERBASEMENT, SouthernDocks_Movement_DawnGoesBacktoSpotAfterPokedex
	waitmovement 0
	msgbox SouthernDocks_Text_CharlieDawnPostBasement4, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_CHARLIEDOCKSAFTERBASEMENT, Common_Movement_FaceRight
	applymovement LOCAL_ID_DAWNDOCKSAFTERBASEMENT, Common_Movement_FaceLeft
	waitmovement 0
	clearflag FLAG_REPELTOGGLE
	addvar VAR_STARTER_CUTSCENE 1
	addvar VAR_DOCKS_CUTSCENE 1
	release
	end

SouthernDocks_Movement_PlayerWalksUptoDawnCharlie::
	walk_down
	walk_down
	walk_down
	step_end

SouthernDocks_Text_CharlieDawnPostBasement1::
	.string "Charlie: Oh hey {PLAYER}! Your\n" 
	.string "friend seems to have left.\p"
	.string "Dawn: They seemed like they were\n"
	.string "nervous about something. \p"
	.string "Their face got real pale when this\n"
	.string "guy came storming out of the\l"
	.string "warehouse a few moments ago.\p"
	.string "Charlie: You know...I just realized\n"
	.string "that in all the crazyness, I forgot\l"
	.string "to introduce myself!\p"
	.string "I'm Charlie. I'm a Pokemon Trainer.\l"
	.string "I'm from Olivine City in Johto, but\n"
	.string "I've lived in Hoenn for the last\l"
	.string "several years.\p"
	.string "Dawn: And I'm Dawn. I'm from Sinnoh,\n"
	.string "as I said before, but I've taken\l"
	.string "residence in Kalos as of late.\p"
	.string "I'm a fashion designer and trainer.\l"
	.string "Your name is {PLAYER} yes? And\n"
	.string "your friend is?...Eve. I see.\p"
	.string "Charlie: Are you going to go catch\n"
	.string "up with your friend?\p"
	.string "I heard them mutter something about\n"
	.string "the ICEMOUNTAIN before they ran\l"
	.string "off in a hurry.\p"
	.string "...\l"
	.string "Charlie: Huh? You don't know how to\n"
	.string "get there?\p"
	.string "Dawn: Oh I see...you've never really\n"
	.string "gotten to travel before.$"

SouthernDocks_Movement_DawnGivesItem::
	walk_up
	face_left
	step_end

SouthernDocks_Movement_DawnGivesItem2::
	walk_in_place_left
	step_end

SouthernDocks_Text_CharlieDawnPostBasement2::
	.string "Dawn: Here. If you're going to be\n"
	.string "looking for your friend, you may\l"
	.string "want this to help you get around.\p"
	.string "They had these on the boat so I\n"
	.string "took a few for Charlie and I.\p"
	.string "You can have one!$"

SouthernDocks_giveitem_TownMap::
	applymovement LOCAL_ID_DAWNDOCKSAFTERBASEMENT, SouthernDocks_Movement_DawnGivesItem2
	waitmovement 0
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_TOWN_MAP
	waitfanfare
	return

SouthernDocks_Text_CharlieDawnPostBasement3::
	.string "Dawn: And...take one of these. No\n"
	.string "trainer would be caught dead \l"
	.string "without one.$"

SouthernDocks_giveitem_POKEDEX::
	applymovement LOCAL_ID_DAWNDOCKSAFTERBASEMENT, SouthernDocks_Movement_DawnGivesItem2
	waitmovement 0
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

SouthernDocks_Movement_DawnGoesBacktoSpotAfterPokedex::
	walk_down
	face_up
	step_end

SouthernDocks_Text_CharlieDawnPostBasement4::
	.string "Charlie: It was nice to meet you\n"
	.string "{PLAYER}! We're supposed to be\l"
	.string "staying at the Observatory to the\l"
	.string "northwest of MYREIGON.\p"
	.string "Dawn: I apologize that our meeting\n"
	.string "was a bit haphazard. Next time we\l"
	.string "will be a bit more relaxed - I hope!\p"
	.string "Charlie: We'll be waiting here until\n"
	.string "our escort arrives to guide us. In\l"
	.string "the mean time, you better go find\l"
	.string "your friend!\p"
	.string "Dawn: Good luck {PLAYER}!\l"
	.string "Charlie: And don't worry about\n"
	.string "what happened. We'll figure it out.\p"
	.string "We've both gotten out of more\n"
	.string "sticky situations than this!$"

@ STANDARD NPC DIALOGUE - UNCHANGED

SouthernDocks_EventScript_DocksLassNPCDialogue::
	lock
	faceplayer
	msgbox SouthernDocks_Text_DocksLassNPCDialogue, MSGBOX_DEFAULT
	closemessage
	release
	end

SouthernDocks_Text_DocksLassNPCDialogue::
	.string "Have you been to Savvie City?\l"
	.string "There's a ferry there that runs\n"
	.string "to this port every so often.\p"
	.string "Kusho is an archipelago, so it\n"
	.string "has a large dependance on boats.\p"
	.string "Savvie City is home to Vandelay\n"
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
	.string "Kusho has only three major\n"
	.string "cities throughout.\p"
	.string "CITYONE, Savvie City, and\n"
	.string "CITYTHREE.\p"
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
	.string "The biggest city in Kusho\n"
	.string "is called CITYONE.\p"
	.string "There's a highway east of the\n"
	.string "warehouse that trucks come to\l"
	.string "haul cargo to and from this port.\p"
	.string "This southernmost dock is the\n"
	.string "primary transport point for most\l"
	.string "international travel in Kusho.$"

SouthernDocks_EventScript_DocksSailorWarehouseNPCDialogue::
	lock
	faceplayer
	msgbox SouthernDocks_Text_DocksSailor4NPCDialogue, MSGBOX_DEFAULT
	closemessage
	release
	end

SouthernDocks_Text_DocksSailor4NPCDialogue::
	.string "Ugh, wild Pokemon are living in the\n"
	.string "basement already.\p"
	.string "It's going to take us ages to fix\n"
	.string "the damage done to the wall.\p"
	.string "It's like something blasted its\n"
	.string "way through the wall and dug\l"
	.string "right to the surface!\p"
	.string "What the heck was this cargo?\l"
	.string "Those two down there were really\n"
	.string "worried about it...but we always\l"
	.string "screen cargo and found nothing\l"
	.string "dangerous in the crate that\l"
	.string "contained it.\p"
	.string "Maybe someone tried to steal it by\n"
	.string "digging into the warehouse?\p"
	.string "Well, whatever. It's gone now, and\n"
	.string "nobody got hurt. Coulda just been\l"
	.string "nothing I guess.\p"
	.string "Jeez, I need a raise...$"

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
	.string "Hmm? I don't look like a dockhand?\n"
	.string "You are right!\p"
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
	.string "of Kusho!\p"
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
	.string "Kusho is directly in the path\n"
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


@ Charlie and Dawn Dialogue post Docks Cutscenes Start of GAME

SouthernDocks_EventScript_CharliePostDocksIntroText::
	lock
	faceplayer
	msgbox SouthernDocks_Text_CharliePostDocksIntroText, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_CHARLIEDOCKSAFTERBASEMENT, Common_Movement_FaceRight
	waitmovement 0
	release
	end

SouthernDocks_Text_CharliePostDocksIntroText::
	.string "We're going to ask around and try\n"
	.string "to get some help finding our\l"
	.string "lost cargo.\p"
	.string "Your friend said something about\n"
	.string "going towards SnowCot.\p"
	.string "Its north of here according\n"
	.string "to the map.\p"
	.string "Hey my advice? Enjoy your early\n"
	.string "days as a trainer.\p"
	.string "You'll never know what kinds of\n"
	.string "experiences you will have.\p"
	.string "Maybe we'll meet sometime again!\l"
	.string "Dawn and I were planning to stay\n"
	.string "here for quite a while!$"

SouthernDocks_EventScript_DawnPostDocksIntroText::
	lock
	faceplayer
	msgbox SouthernDocks_Text_DawnPostDocksIntroText, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_DAWNDOCKSAFTERBASEMENT, Common_Movement_FaceLeft
	waitmovement 0
	release
	end

SouthernDocks_Text_DawnPostDocksIntroText::
	.string "How old are you, {PLAYER}?\l"
	.string "15? Wow! You know, it's never\n"
	.string "too late to become a trainer.\p"
	.string "In Sinnoh, most kids become\n"
	.string "trainers at only 10 years old.\p"
	.string "Oh did I become a trainer that\n"
	.string "young?\p"
	.string "Sure did. I've been a trainer\n"
	.string "for a very long time now.\p"
	.string "Maybe once you get strong, we\n"
	.string "can have a battle.\p"
	.string "Hopefully all this business can\n"
	.string "get sorted out soon. There's a\l"
	.string "lot I want to see in Kusho.$"

@DOCKS MARKET SCRIPT

SouthernDocks_EventScript_Pokemart::
	lock
	faceplayer
	msgbox SouthernDocks_Text_PokemartOldLadyGreeting, MSGBOX_DEFAULT
	waitmessage
	pokemart SouthernDocks__Pokemart
	msgbox SouthernDocks_Text_PokemartOldLadyFarewell, MSGBOX_DEFAULT
	release
	end

	.align 2
SouthernDocks__Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte 
	pokemartlistend

SouthernDocks_Text_PokemartOldLadyGreeting::
	.string "Hello dearie!\l"
	.string "I run a meager shop here on the\n"
	.string "docks. I see you are a trainer?\p"
	.string "Would you care to purchase any of\n"
	.string "my wares? You may find them\l"
	.string "useful if you are going far away!$"

SouthernDocks_Text_PokemartOldLadyFarewell::
	.string "You go and have fun now, ok?$"
