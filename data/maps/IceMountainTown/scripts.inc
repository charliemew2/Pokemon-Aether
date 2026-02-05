IceMountainTown_MapScripts::
	.byte 0

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
