DocksWarehouseBasement_MapScripts::
	.byte 0

DocksWarehouseBasement_EventScript_CharlieConversation::
	lock
	msgbox DocksWarehouseBasement_Text_CharlieConversation1, MSGBOX_DEFAULT
	closemessage
	delay 16
	playse SE_PIN
	applymovement LOCAL_ID_CHARLIE_BASEMENT, Common_Movement_ExclamationMark
	waitmovement
	applymovement LOCAL_ID_CHARLIE_BASEMENT, Common_Movement_FaceDown
	waitmovement 0
	delay 16
	delay 16
	msgbox DocksWarehouseBasement_Text_CharlieConversation2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_CHARLIE_BASEMENT, Common_Movement_FaceUp
	waitmovement 0
	delay 16
	delay 16
	delay 16
	msgbox DocksWarehouseBasement_Text_CharlieConversation3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_CHARLIE_BASEMENT, Common_Movement_FaceDown
	waitmovement 0
	delay 16
	msgbox DocksWarehouseBasement_Text_CharlieConversation4, MSGBOX_DEFAULT
	closemessage
	call DocksWarehouseBasement_giveitem_Pokeballs
	delay 8
	msgbox DocksWarehouseBasement_Text_CharlieConversation5, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, DocksWarehouseBasement_Movement_PlayerGetsOutofCharlieWay
	applymovement LOCAL_ID_CHARLIE_BASEMENT, DocksWarehouseBasement_Movement_CharlieLeavesBasement
	waitmovement 0
	removeobject LOCAL_ID_CHARLIE_BASEMENT
	addvar VAR_DOCKS_CUTSCENE 1
	clearflag FLAG_DOCKS_BLOCKDOCKS
	clearflag FLAG_DOCKS_EVENTS_FINISHED_GET_POKEDEX
	setflag FLAG_DOCKS_HIDENPCAFTERDOCKSEVENTS
	setflag FLAG_DOCKS_HIDENPCDURINGCUTSCENE
	setflag FLAG_DOCKS_BASEMENT_CUTSCENE_DONE
	release
	end

DocksWarehouseBasement_Text_CharlieConversation1::
	.string "Charlie: The generator's power \n"
	.string "surged by complete chance?...\p"
	.string "It was here! It really was...\l"
	.string "But if it really activated then...\l"
	.string "...\l"
	.string "Crap. What are the odds? Could\n"
	.string "someone else have been after\l"
	.string "the prototype?\p"
	.string "Great. And we're supposed to meet\n"
	.string "with the Professor's grandkid later.\l"
	.string "Now this happens...sigh\p"
	.string "What a great start to this trip...$"

DocksWarehouseBasement_Text_CharlieConversation2::
	.string "Ah! You again! Sorry. Did you\n"
	.string "overhear that?\p"
	.string "I have a bit of a bad habit of\n"
	.string "talking too much, and to myself.\p"
	.string "Oh Dawn was worried about me?\l"
	.string "She always says 'no need to worry'\n"
	.string "which is rich coming from her!\p"
	.string "I was just worried about...this...$"

DocksWarehouseBasement_Text_CharlieConversation3::
	.string "See uh...between you and me, Dawn\n"
	.string "and I were here for a delivery and\l"
	.string "well...the cargo isn't here anymore.\p"
	.string "We were bringing it from a mutual\n"
	.string "associate of ours to Kusho to\l"
	.string "bring to Professor Hazel.\p"
	.string "Someone must have tried to steal\n"
	.string "it by causing a power surge but...\p"
	.string "...$"

DocksWarehouseBasement_Text_CharlieConversation4::
	.string "I saw a few wild Pokémon around\n"
	.string "down here. They must be getting\l"
	.string "in through this hole in the wall.\p"
	.string "You're a new trainer so you should\n"
	.string "have a few of these.\p"
	.string "Take them! I insist!$"
	
DocksWarehouseBasement_giveitem_Pokeballs::
	giveitem ITEM_POKE_BALL 20
	return

DocksWarehouseBasement_Text_CharlieConversation5::
	.string "Throw one of those at a Pokémon\n"
	.string "and it'll get right in!\p"
	.string "They make these things a lot\n"
	.string "better than they used to.\p"
	.string "We should get out of here. I'll\n"
	.string "have to figure out what Dawn and\l"
	.string "I are going to do...\p"
	.string "Oh yeah whats your name? I didn't\n"
	.string "catch it before.\p"
	.string "...\l"
	.string "{PLAYER}! Got it!\l"
	.string "I'll seeya outside!$"

DocksWarehouseBasement_Movement_CharlieLeavesBasement::
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_right
	walk_down
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

DocksWarehouseBasement_Movement_PlayerGetsOutofCharlieWay::
	walk_left
	face_right
	delay_16
	face_down
	step_end

DocksWarehouseBasement_EventScript_HoleInWall::
	lock
	msgbox DocksWarehouseBasement_Text_HoleinWall, MSGBOX_DEFAULT
	closemessage
	release
	end

DocksWarehouseBasement_Text_HoleinWall::
	.string "A hole in the wall.\l"
	.string "Dim light is filtering through a\n"
	.string "tunnel up to the surface.\p"
	.string "What could have made this?$"
