IceMountainTown_MapScripts::
map_script MAP_SCRIPT_ON_FRAME_TABLE, DefeatedKristine_OnFrameTable
	.byte 0

@VAR_ICE_MOUNTAIN_EVENTS LISTING
	@0 - Triggers the first Sayo Fight on F3
	@1 - Unblocks the Avalanche in SnowCot to allow passage up the mountain
	@2 - Allows the Grunt to attack the player on the path
	@3 - Kristine defeated - activates Jenny and her make up Cutscene
	@4 - Increment during Kristine Cutscene to prevent crashing after warp to town
	@5 - Final Variable - Locks out Kristine Cutscenes/Hides all NPC's - FINAL VARIABLE - UNLOCKS CABLE CAR TO ROUTE 2

@AFTER DEFEATING KRISTINE, WALKS HER TO TALK TO JENNY AT THE CABLE CAR

DefeatedKristine_OnFrameTable:
	map_script_2 VAR_ICEMOUNTAIN_EVENTS, 4, DefeatedKristine_EventScript_GoBackToJenny
	.2byte 0

DefeatedKristine_EventScript_GoBackToJenny::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement LOCAL_ID_KRISTINE_POSTFIGHTWALKSAWAY, Common_Movement_FaceLeft
	waitmovement 0
	msgbox DefeatedKristine_Text_GoBackToJenny, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_KRISTINE_POSTFIGHTWALKSAWAY, DefeatedKristine_Movement_GobacktoJenny
	waitmovement 0
	removeobject LOCAL_ID_KRISTINE_POSTFIGHTWALKSAWAY
	addvar VAR_ICEMOUNTAIN_EVENTS, 1
	setflag FLAG_HIDE_KRISTINE_ESCORT
	setflag	FLAG_DEFEATED_KRISTINE
	clearflag FLAG_HIDE_KRISTINE_JENNY_LIFT_CONVO
	releaseall
	end

DefeatedKristine_Text_GoBackToJenny::
	.string "Phew, the hike down was a lot\n"
	.string "easier than the hike up.\p"
	.string "I honestly didn't even know that\n"
	.string "a snowdrift had blocked the path!\p"
	.string "Um...when I get mad, I kind of stew\n"
	.string "for a while, so I didn't even know\l"
	.string "I was gone for that long...\p"
	.string "Anyways...I'll see you by the east\n"
	.string "cable car! Mkay.\p"
	.string "Come over when you are ready!$"

DefeatedKristine_Movement_GobacktoJenny::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

@MAIN STORY JENNY/KRISTINE TRIGGERS

IceMountainTown_EventScript_JennyConversationFindKristine::
	lock
	goto_if_ge VAR_ICEMOUNTAIN_EVENTS, 2 IceMountainTown_EventScript_JennyAfterSheAskedToFindKristine
	msgbox IceMountainTown_Text_JennyConversationPleaseFindKristine1, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_TEMP_3, VAR_TEMP_4
	call_if_eq VAR_TEMP_4, 17, IceMountainTown_EventScript_JennyPacesBackandForthHorizontal
	call_if_eq VAR_TEMP_4, 19, IceMountainTown_EventScript_JennyPacesBackandForthHorizontal
	call_if_eq VAR_TEMP_3, 39, IceMountainTown_EventScript_JennyPacesBackandForthVertical
	call_if_eq VAR_TEMP_3, 41, IceMountainTown_EventScript_JennyPacesBackandForthVertical
	delay 60
	playse SE_PIN
	applymovement LOCAL_ID_JENNYICEMOUNTAIN, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	faceplayer
	msgbox IceMountainTown_Text_JennyConversationPleaseFindKristine2, MSGBOX_DEFAULT
	closemessage
	addvar VAR_ICEMOUNTAIN_EVENTS, 1
	setflag FLAG_AVALANCHE_CLEARED
	clearflag FLAG_SPOKETOJENNY
	release
	end

IceMountainTown_Text_JennyConversationPleaseFindKristine1::
	.string "Ohhh...Stupid STUPID!$"

IceMountainTown_EventScript_JennyPacesBackandForthHorizontal::
	lock
	applymovement LOCAL_ID_JENNYICEMOUNTAIN, IceMountainTown_Movement_JennyPacesBackAndForthHorizontal
	waitmovement 0
	return

IceMountainTown_Movement_JennyPacesBackAndForthHorizontal::
	walk_right
	walk_left
	walk_left
	walk_right
	walk_right
	walk_left
	step_end

IceMountainTown_EventScript_JennyPacesBackandForthVertical::
	lock
	applymovement LOCAL_ID_JENNYICEMOUNTAIN, IceMountainTown_Movement_JennyPacesBackAndForthVertical
	waitmovement 0
	return

IceMountainTown_Movement_JennyPacesBackAndForthVertical::
	walk_up
	walk_down
	walk_down
	walk_up
	walk_up
	walk_down
	step_end

IceMountainTown_Text_JennyConversationPleaseFindKristine2::
	.string "Hey! Are you a trainer? I'm in a bit\n"
	.string "of a bind and I need some help.\p"
	.string "My name is Jenny!\l"
	.string "My sister Kristine and I each \n"
	.string "manage one of the two chairlifts \l"
	.string "here in town.\p"
	.string "This town is situated on the lower\n" 
	.string "peak of ICEMOUNTAIN, so we're \l"
	.string "safe from avalanches, but there\l"
	.string "are occasional snow drifts that\l"
	.string "block the road.\p"
	.string "There was an avalanche the other\n"
	.string "day that buried the cable car\l"
	.string "route Kristine manages, so we've\l"
	.string "been taking turns running mine in \l"
	.string "shifts the last few days.\p"
	.string "Um...we got into an argument today\n"
	.string "though, and she ran off towards\l"
	.string "the lower summit and took her\l"
	.string "key with her.\p"
	.string "I have one too, but I lost it in the\n"
	.string "snow so neither lift is able to\l"
	.string "be used, which is a problem.\p"
	.string "My sister has been gone for a few\n"
	.string "hours and while I would love to go\l"
	.string "after her...I'm not a trainer.\p"
	.string "She's a capable trainer herself,\n"
	.string "the only one in town actually.\p"
	.string "Before the road was blocked, some\n"
	.string "shady looking guy came through\l"
	.string "town and went up the way Kristine\l"
	.string "left. It's north of here...\p"
	.string "I didn't think much of him but then\n"
	.string "when the road was blocked I got\l"
	.string "more and more worried...!\p"
	.string "Argh! I'm so stupid!\l"
	.string "Trainer, they should be done\n"
	.string "clearing the snow off the road.\p"
	.string "Can you find Kristine and tell her\n"
	.string "to come back here? And make sure\l"
	.string "she's ok?\p"
	.string "...And tell her that...I'm sorry.\l"
	.string "...\l"
	.string "You will? Thank you so much!\l"
	.string "My sister has blonde hair, just\n"
	.string "like me. You can't miss her.\p"
	.string "I still need to find my key so\n"
	.string "we can keep the lift running.\p"
	.string "It'll be a big problem for the\n"
	.string "town if they won't run after all!$"

IceMountainTown_EventScript_JennyAfterSheAskedToFindKristine::
	lock
	faceplayer
	msgbox IceMountainTown_Text_JennyAfterSheAskedToFindKristine, MSGBOX_DEFAULT
	closemessage
	release
	end

IceMountainTown_Text_JennyAfterSheAskedToFindKristine::
	.string "Sorry to dump all of this on you so\n"
	.string "suddenly. Today's just been so\l"
	.string "terrible already.\p"
	.string "I would have asked this girl with\n"
	.string "purple hair who was here earlier\l"
	.string "but she ran off so fast I didn't\l"
	.string "get a chance.\p"
	.string "Huh? Did I see someone with a pink\n"
	.string "shirt come through town earlier?\p"
	.string "Um...Let me wrack my brain. If I\n"
	.string "remember them I'll tell you.\p"
	.string "They couldn't have gotten far\n"
	.string "though given the avalanche.\p"
	.string "Friend of yours?$"

@KRISTINE AND JENNY CONVERSATION  

IceMountainTown_EventScript_KristineJennyMakeUp::
	lock
	msgbox IceMountainTown_Text_KristineJennyMakeUp1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_KRISTINE_JENNY_CONVO, Common_Movement_FaceDown
	applymovement LOCAL_ID_JENNY_KRISTINE_CONVO, Common_Movement_FaceDown
	waitmovement 0
	msgbox IceMountainTown_Text_KristineJennyMakeUp2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_KRISTINE_JENNY_CONVO, Common_Movement_FaceRight
	applymovement LOCAL_ID_JENNY_KRISTINE_CONVO, Common_Movement_FaceLeft
	waitmovement 0
	msgbox IceMountainTown_Text_KristineJennyMakeUp3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_KRISTINE_JENNY_CONVO, Common_Movement_FaceDown
	applymovement LOCAL_ID_JENNY_KRISTINE_CONVO, Common_Movement_FaceDown
	waitmovement 0
	msgbox IceMountainTown_Text_KristineJennyMakeUp4, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_JENNY_KRISTINE_CONVO, IceMountainTown_Movement_JennyGoesBackToWork
	applymovement LOCAL_ID_KRISTINE_JENNY_CONVO, IceMountainTown_Movement_KristineWatchesJennyGoesBackToWork
	waitmovement LOCAL_ID_JENNY_KRISTINE_CONVO
	removeobject LOCAL_ID_JENNY_KRISTINE_CONVO
	playse SE_EXIT
	waitse
	delay 16
	getplayerxy VAR_TEMP_3, VAR_TEMP_4
	call_if_eq VAR_TEMP_3, 41, IceMountainTown_EventScript_AlignKristine
	delay 4
	applymovement LOCAL_ID_KRISTINE_JENNY_CONVO, Common_Movement_FaceDown
	waitmovement 0
	msgbox IceMountainTown_Text_KristineJennyMakeUp5, MSGBOX_DEFAULT
	closemessage
	call IceMountainTown_giveitem_TM02
	msgbox IceMountainTown_Text_KristineJennyMakeUp6, MSGBOX_DEFAULT
	closemessage	
	delay 8
	getplayerxy VAR_TEMP_3, VAR_TEMP_4
	call_if_eq VAR_TEMP_3, 40, IceMountainTown_EventScript_KristineLeaveLeft
	getplayerxy VAR_TEMP_3, VAR_TEMP_4
	call_if_eq VAR_TEMP_3, 41, IceMountainTown_EventScript_KristineLeaveRight
	removeobject LOCAL_ID_KRISTINE_JENNY_CONVO
	setflag FLAG_HIDE_KRISTINE_JENNY_LIFT_CONVO
	clearflag FLAG_HIDE_KRISTINE_AT_HOME
	release
	end

IceMountainTown_Text_KristineJennyMakeUp1::
	.string "Jenny: I'm so glad you aren't hurt!\l"
	.string "Kristine: I can't believe that some\n"
	.string "shady guy was right around me!\p"
	.string "Thank Arceus I never saw him...\l"
	.string "Jenny: Well uh...it's in the past\n"
	.string "now. I'm sorry we argued.\p"
	.string "I've just been worried about\n"
	.string "being here alone...\p"
	.string "Kristine: I know..\n"
	.string "I feel guilty. \p"
	.string "But...uh...so I met this trainer.\n"
	.string "Oh!$"

IceMountainTown_Text_KristineJennyMakeUp2::
	.string "Kristine: Hi {PLAYER}!\l"
	.string "Jenny: Oh! Its you! That trainer!\l"
	.string "Thank you so much for bringing\n"
	.string "Kristine back...\p"
	.string "Kristine: So. I've decided...um.\l"
	.string "I'm going to leave this mountain\n"
	.string "after all.\p"
	.string "Jenny: I'm the younger sibling and\n"
	.string "well, Kristine always has been\l"
	.string "around and protected me.\p"
	.string "But, she's always wanted to see\n"
	.string "what laid beyond out there.\p"
	.string "Kristine: Of course, Jenny and I\n"
	.string "have talked about this a lot more\l"
	.string "recently.\p"
	.string "But...After the avalanche, I saw...\l"
	.string "I saw it! I knew I saw it!\l"
	.string "Mew!\l"
	.string "The Legendary Pokémon...some even\n"
	.string "call it the parent of all Pokémon!\p"
	.string "It was a sign...the way it glanced\n"
	.string "back at me. \p"
	.string "Almost like it was inviting me to\n"
	.string "join it on an adventure.\p"
	.string "So I sat on it for a few days. I\n"
	.string "mean, maybe I was just seeing\l"
	.string "things...\p"
	.string "Jenny: But I know my sister. She\n"
	.string "knew what she saw.\p"
	.string "And when she's sure, there's no\n"
	.string "stopping her.\p"
	.string "So um, when she told me she wanted\n"
	.string "to leave...\p"
	.string "Even I thought it was ridiculous!\l"
	.string "So we argued and she got mad and\n"
	.string "well, you know the rest.\p"
	.string "Kristine: You trounced me in a fair\n"
	.string "fight. I have a lot to learn, and\l"
	.string "I'm not going to learn it here.$"

IceMountainTown_Movement_JennyGoesBackToWork::
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

IceMountainTown_Movement_KristineWatchesJennyGoesBackToWork::
	face_right
	delay_8
	face_up
	step_end

IceMountainTown_EventScript_AlignKristine::
	applymovement LOCAL_ID_KRISTINE_JENNY_CONVO, IceMountainTown_Movement_AlignKristine
	waitmovement 0
	return

IceMountainTown_Movement_AlignKristine::
	walk_right
	step_end

IceMountainTown_Text_KristineJennyMakeUp3::
	.string "Jenny: ...You're going to leave huh?\l"
	.string "...\l"
	.string "Haha! Well... I shouldn't stop you.\l"
	.string "You're the older sibling anyways.\p"
	.string "But when you're done seeing the\n"
	.string "world, you best come back here\l"
	.string "and tell me lots of cool stories.\p"
	.string "Kristine: Jenny...!\l"
	.string "Jenny: It's not fair for either of\n"
	.string "us to be glued here, staying in\l"
	.string "one place just 'because it's what\l"
	.string "we know'.\p"
	.string "I've...I've known this.\l"
	.string "It's just so BORING here!\l"
	.string "But. It'll be ok. You know what?\l"
	.string "I think I'll take up Pokémon\n"
	.string "training myself!\p"
	.string "So when you get back, I can leave\n"
	.string "and then have my own adventure!$"

IceMountainTown_Text_KristineJennyMakeUp4::
	.string "Trainer! Wait no! Your name is\n"
	.string "{PLAYER} right?\p"
	.string "Sorry we got you involved in our\n"
	.string "petty sibling disagreement.\p"
	.string "I think we both knew we were\n"
	.string "being stubborn. \p"
	.string "I found my key while you were out\n"
	.string "searching for Kristine, so I can\l"
	.string "get the cable car running again!\p"
	.string "You get free admission for life!$"

IceMountainTown_Text_KristineJennyMakeUp5::
	.string "Phew...that went so much better\n"
	.string "than I expected.\p"
	.string "I'm a bit salty that I lost to you,\n"
	.string "I won't lie...\p"
	.string "But maybe sometime we can battle\n"
	.string "again?\p"
	.string "...\l"
	.string "Huh? Mew?\l"
	.string "You...You saw it too?\l"
	.string "So you believe me...!\l"
	.string "{PLAYER}, I have no interest in\n"
	.string "searching for a living legend.\p"
	.string "I just want to experience all the\n"
	.string "world has to offer!\p"
	.string "Thank you for validating me.\l"
	.string "I have a gift for you.$"

IceMountainTown_Text_KristineJennyMakeUp6::
	.string "That TM contains the move Icy\n"
	.string "Wind. It's one of my favorites!\p"
	.string "...Oh? A person in a pink shirt?\l"
	.string "I'm sorry...I was on the peak for\n"
	.string "the last few hours remember?\p"
	.string "If they came through, I wouldn't\n"
	.string "have seen them.\p"
	.string "But they couldn't have gone\n"
	.string "anywhere with the lifts down\l"
	.string "no? Unless they climbed the\l"
	.string "mountain barehanded...\p"
	.string "Nobody is that reckless right?\l"
	.string "Maybe Jenny knows?\l"
	.string "I'm sorry I can't be more helpful...\n"
	.string "If I spot them sometime, I'll tell\l"
	.string "them you're looking for them!\p"
	.string "Ok. I've taken more than enough\n"
	.string "of your time. I should go get my\l"
	.string "bag packed...\p"
	.string "{PLAYER}! Let's meet again on\n"
	.string "the road someday!\p"
	.string "...Maybe\l"
	.string "Um...bye!$"

IceMountainTown_EventScript_KristineLeaveLeft::
	applymovement LOCAL_ID_KRISTINE_JENNY_CONVO, IceMountainTown_Movement_KristineLeaveLeft
	delay 16
	delay 16
	delay 16
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement LOCAL_ID_KRISTINE_JENNY_CONVO
	return

IceMountainTown_Movement_KristineLeaveLeft::
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

IceMountainTown_EventScript_KristineLeaveRight::
	applymovement LOCAL_ID_KRISTINE_JENNY_CONVO, IceMountainTown_Movement_KristineLeaveRight
	delay 16
	delay 16
	delay 16
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement LOCAL_ID_KRISTINE_JENNY_CONVO
	return

IceMountainTown_Movement_KristineLeaveRight::
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

IceMountainTown_giveitem_TM02::
	giveitem ITEM_TM02
	return

@AVALANCHE BLOCK GUY

IceMountainTown_EventScript_AvalancheCleanup::
	lock
	applymovement LOCAL_ID_AVALANCHEGUY, Common_Movement_FaceLeft
	waitmovement 0
	goto IceMountainTown_EventScript_AvalancheCleanupGuyStopsPlayer
	end

IceMountainTown_EventScript_AvalancheCleanupGuyStopsPlayer::
	lock
	faceplayer
	msgbox IceMountainTown_Text_AvalancheCleanupGuy, MSGBOX_DEFAULT
	closemessage
	getplayerxy VAR_TEMP_3, VAR_TEMP_4
	call_if_eq VAR_TEMP_4, 4, IceMountainTown_EventScript_PreventPlayerFromPassingGuy
	release
	end

IceMountainTown_EventScript_PreventPlayerFromPassingGuy::
	applymovement OBJ_EVENT_ID_PLAYER, IceMountainTown_Movement_PreventPlayerFromPassingGuy
	waitmovement 0
	end

IceMountainTown_Movement_PreventPlayerFromPassingGuy::
	walk_down
	step_end

IceMountainTown_Text_AvalancheCleanupGuy::
	.string "Hey! There was an avalanche on\n"
	.string "the mountain earlier.\p"
	.string "Most of it went down the west\n"
	.string "face but part of the path to the\l"
	.string "lower summit up here is blocked.\p"
	.string "We're almost done clearing it.\l"
	.string "Just be a little patient and enjoy\n"
	.string "the sights in our little town!$"

IceMountainTown_EventScript_AvalancheCleanupGuyPostAvalanche::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_KRISTINE, IceMountainTown_EventScript_AvalancheCleanupGuyPostAvalanchePostKristine
	goto_if_unset FLAG_DEFEATED_KRISTINE, IceMountainTown_EventScript_AvalancheCleanupGuyPostAvalanchePreKristine
	release
	end

IceMountainTown_EventScript_AvalancheCleanupGuyPostAvalanchePreKristine::
	msgbox IceMountainTown_Text_AvalancheCleanupGuyPostAvalanchePreKristine, MSGBOX_DEFAULT
	closemessage
	return

IceMountainTown_Text_AvalancheCleanupGuyPostAvalanchePreKristine::
	.string "The road gets blocked every so\n"
	.string "often by stray snow drifts.\p"
	.string "They do sometimes rarely fall on\n"
	.string "the town, but they're usually\l"
	.string "pretty quick to clean up.\p"
	.string "A few hours of shoveling and we're\n"
	.string "all good to go!\p"
	.string "Eh? Jenny is worried about her\n"
	.string "sister? That's normal\p"
	.string "Those two are always together.\l"
	.string "They're quite close!\l"
	.string "Still I did see them arguing about\n"
	.string "something earlier. I guess that's\l"
	.string "just siblings for you!$"

IceMountainTown_EventScript_AvalancheCleanupGuyPostAvalanchePostKristine::
	msgbox IceMountainTown_Text_AvalancheCleanupGuyPostAvalanchePostKristine, MSGBOX_DEFAULT
	closemessage
	return

IceMountainTown_Text_AvalancheCleanupGuyPostAvalanchePostKristine::
	.string "Thanks for helping Kristine!$"

@ CLOSED CHAIRLIFT

IceMountainTown_EventScript_ChairliftClosed::
	lock
	msgbox IceMountainTown_Text_ChairliftClosed, MSGBOX_DEFAULT
	closemessage
	release
	end

IceMountainTown_Text_ChairliftClosed::
	.string "We're very sorry.\l"
	.string "The chairlift is currently out of\n"
	.string "order due to the avalanche.\p"
	.string "The lower parts of the mountain\n"
	.string "that the lift goes through\l"
	.string "are covered in snow.\p"
	.string "We will reopen when it is cleared.\l"
	.string "We apologize for the inconvience!$"

@NURSE NPC

IceMountainTown_EventScript_NurseNPC::
	lock
	faceplayer
	msgbox IceMountainTown_Text_NurseNPC, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, IceMountainTown_EventScript_HealPkmn
	goto_if_eq VAR_RESULT, NO, IceMountainTown_EventScript_NurseByeBye
	end	

IceMountainTown_Text_NurseNPC::
	.string "Hi! Welcome to my little clinic in\n"
	.string "the cold.\p"
	.string "We don't get many trainers coming\n"
	.string "through this town, so we don't\l"
	.string "have a Pokémon Center.\p"
	.string "If you'd like, I can heal your\n"
	.string "Pokémon for you for free?$"

IceMountainTown_EventScript_HealPkmn::
	call IceMountainTown_EventScript_NurseHeals
	end

IceMountainTown_EventScript_NurseHeals::
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	msgbox IceMountainTown_Text_ByeByeNurseHealed, MSGBOX_DEFAULT
	closemessage
	return

IceMountainTown_EventScript_NurseByeBye::
	msgbox IceMountainTown_Text_ByeByeNurse, MSGBOX_DEFAULT
	closemessage
	return	

IceMountainTown_Text_ByeByeNurseHealed::
	.string "Stay warm out here! Come back\n"
	.string "whenever you need to!$"

IceMountainTown_Text_ByeByeNurse::
	.string "If you change your mind, I'm here\n"
	.string "all the time!$"

@SIGNS IN TOWN

IceMountainTown_EventScript_SignIceTownEntrance::
	lock
	msgbox IceMountainTown_Text_SignIceTownEntrance, MSGBOX_DEFAULT
	closemessage
	release
	end

IceMountainTown_Text_SignIceTownEntrance::
	.string "ICETOWN - The little town cradled\n"
	.string "in the snow of the peaks.$"

IceMountainTown_EventScript_SignKristineHouse::
	msgbox IceMountainTown_Text_SignKristineHouse, MSGBOX_SIGN
	end

IceMountainTown_Text_SignKristineHouse::
	.string "Kristine and Jenny's House$"

IceMountainTown_EventScript_SignEastChairlift::
	msgbox IceMountainTown_Text_SignEastChairlift, MSGBOX_SIGN
	end

IceMountainTown_Text_SignEastChairlift::
	.string "Eastern Lift\n"
	.string "Passage to Route 2$"

IceMountainTown_EventScript_SignWestChairlift::
	msgbox IceMountainTown_Text_SignWestChairlift, MSGBOX_SIGN
	end

IceMountainTown_Text_SignWestChairlift::
	.string "Western Lift\n"
	.string "Passage to Flower Paradise$"

IceMountainTown_EventScript_SignSummitAhead::
	msgbox IceMountainTown_Text_SignSummitAhead, MSGBOX_SIGN
	end

IceMountainTown_Text_SignSummitAhead::
	.string "{UP_ARROW} ICEMOUNTAIN Summit$"

IceMountainTown_EventScript_SignClinic::
	msgbox IceMountainTown_Text_SignClinic, MSGBOX_SIGN
	end

IceMountainTown_Text_SignClinic::
	.string "ICETOWN Clinic$"

@NPC DIALOGUE

IceMountainTown_EventScript_IceTownBoyDialogue::
	lock
	faceplayer
	msgbox IceMountainTown_Text_IceTownBoyDialogue, MSGBOX_DEFAULT
	closemessage
	release
	end

IceMountainTown_Text_IceTownBoyDialogue::
	.string "I really like living here. It's very\n"
	.string "quaint and quiet.\p"
	.string "The cold is a problem for some \n"
	.string "people, but most of us folks who\l"
	.string "live here are used to it.$"

IceMountainTown_EventScript_IceTownGirlDialogue::
	lock
	faceplayer
	msgbox IceMountainTown_Text_IceTownGirlDialogue, MSGBOX_DEFAULT
	closemessage
	release
	end

IceMountainTown_Text_IceTownGirlDialogue::
	.string "Kristine is the only trainer who\n"
	.string "lives here.\p"
	.string "Her parents were really against\n"
	.string "her becoming a trainer at first,\l"
	.string "but she convinced them.\p"
	.string "She's tough for sure, but I often\n"
	.string "wonder if life here isn't enough\l"
	.string "to satisfy her.\p"
	.string "She's really adventurous.$"

IceMountainTown_EventScript_IceTownHikerDialogue::
	lock
	faceplayer
	msgbox IceMountainTown_Text_IceTownHikerDialogue, MSGBOX_DEFAULT
	closemessage
	release
	end

IceMountainTown_Text_IceTownHikerDialogue::
	.string "I'm visiting this town from SECOND\n"
	.string "CITY. But with the chairlift being\l"
	.string "closed, it's going to take me a lot\l"
	.string "longer to get home.\p"
	.string "At least it's cozy here, if you're\n"
	.string "used to camping in the cold!$"

@GET NEVERMELTICE FROM LITTLE GIRL 


IceMountainTown_EventScript_IceTownLittleGirlDialogue::
	lock
	faceplayer
	goto_if_set FLAG_ITEM_LITTLE_GIRL_GIVES_NEVER_MELT_ICE, IceMountainTown_EventScript_IceTownLittleGirlDialogueGaveNeverMeltIce
	msgbox IceMountainTown_Text_IceTownLittleGirlDialogue, MSGBOX_DEFAULT
	call IceMountainTown_giveitem_NeverMeltIce
	setflag FLAG_ITEM_LITTLE_GIRL_GIVES_NEVER_MELT_ICE
	msgbox IceMountainTown_Text_IceTownLittleGirlDialogueGaveNeverMeltIce, MSGBOX_DEFAULT
	closemessage
	release
	end

IceMountainTown_Text_IceTownLittleGirlDialogue::
	.string "Icicles always form on the roof\n"
	.string "my house, and on the trees!\p"
	.string "Sometimes I snap them off and lick\n"
	.string "them like popsicles! They're cold!\p"
	.string "Here, I just found this next to my\n"
	.string "snowman! You can have it!$"

IceMountainTown_giveitem_NeverMeltIce::
	giveitem ITEM_NEVERMELTICE
	return

IceMountainTown_EventScript_IceTownLittleGirlDialogueGaveNeverMeltIce::
	lock
	faceplayer
	msgbox IceMountainTown_Text_IceTownLittleGirlDialogueGaveNeverMeltIce, MSGBOX_DEFAULT
	closemessage
	release
	end

IceMountainTown_Text_IceTownLittleGirlDialogueGaveNeverMeltIce::
	.string "That's a NeverMeltIce!\l"
	.string	"It makes Ice type moves stronger!\l"
	.string	"It doesn't taste as good as a\n"
	.string	"popsicle, so I don't want it!$"
