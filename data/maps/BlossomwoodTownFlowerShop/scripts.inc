BlossomwoodTownFlowerShop_MapScripts::
map_script MAP_SCRIPT_ON_FRAME_TABLE, Back2BackEvilTeamFlowerShop_OnFrameTable
	.byte 0

Back2BackEvilTeamFlowerShop_OnFrameTable:
	map_script_2 VAR_BLOSSOMTOWN_EVENTS, 1, BlossomwoodTownFlowerShop_EventScript_BacktoBack_Cutscene
	.2byte 0

BlossomwoodTownFlowerShop_EventScript_BacktoBack_Cutscene::
	lock
	delay 16
	playbgm MUS_ENCOUNTER_AQUA, TRUE
	delay 16
	playse SE_EXIT 
	addobject LOCAL_ID_EVE_FLOWERSHOP
	waitse
	playse SE_PIN
	applymovement LOCAL_ID_GRUNT_1_FEMALE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCAL_ID_GRUNT_1_FEMALE, Common_Movement_FaceDown
	waitmovement 0
	delay 16
	delay 16
	msgbox BlossomwoodTownFlowerShop_Text_BacktoBackCutscene1, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, BlossomwoodTownFlowerShop_Movement_PlayerEveWalkIn
	applymovement LOCAL_ID_EVE_FLOWERSHOP, BlossomwoodTownFlowerShop_Movement_PlayerEveWalkIn
	waitmovement 0
	delay 16
	playse SE_PIN
	applymovement LOCAL_ID_GRUNT_1_MALE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCAL_ID_GRUNT_1_MALE, Common_Movement_FaceDown
	waitmovement 0
	delay 16
	delay 16
	applymovement LOCAL_ID_GRUNT_1_MALE, BlossomwoodTownFlowerShop_Movement_Grunt1MPositions
	waitmovement 0
	delay 16
	msgbox BlossomwoodTownFlowerShop_Text_BacktoBackCutscene2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_GRUNT_1_FEMALE, Common_Movement_FaceRight
	waitmovement 0
	msgbox BlossomwoodTownFlowerShop_Text_BacktoBackCutscene3, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_GRUNT_1_FEMALE, Common_Movement_FaceDown
	waitmovement 0
	applymovement LOCAL_ID_GRUNT_1_MALE, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 16
	msgbox BlossomwoodTownFlowerShop_Text_BacktoBackCutscene4, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_CASHIER, Common_Movement_FaceDown
	waitmovement 0
	delay 8
	msgbox BlossomwoodTownFlowerShop_Text_BacktoBackCutscene5, MSGBOX_DEFAULT
	closemessage	
	applymovement LOCAL_ID_GRUNT_1_FEMALE, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox BlossomwoodTownFlowerShop_Text_BacktoBackCutscene6, MSGBOX_DEFAULT
	closemessage 	
	delay 8
	applymovement LOCAL_ID_EVE_FLOWERSHOP, Common_Movement_FaceRight
	waitmovement 0
	msgbox BlossomwoodTownFlowerShop_Text_BacktoBackCutscene7, MSGBOX_DEFAULT
	closemessage 
	applymovement LOCAL_ID_EVE_FLOWERSHOP, BlossomwoodTownFlowerShop_Movement_EveRunsToCashier
	waitmovement 0
	applymovement LOCAL_ID_GRUNT_2_FEMALE, Common_Movement_FaceDown
	waitmovement 0
	msgbox BlossomwoodTownFlowerShop_Text_BacktoBackCutscene8, MSGBOX_DEFAULT
	closemessage 	
	trainerbattle_no_intro TRAINER_FLOWER_SHOP_GRUNT_1, BlossomwoodTownFlowerShop_Text_Grunt1DefeatB2B
	delay 16
	applymovement LOCAL_ID_GRUNT_1_FEMALE, BlossomwoodTownFlowerShop_Movement_Grunt1FDefeated
	waitmovement 0
	playse SE_PIN
	applymovement LOCAL_ID_GRUNT_2_MALE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCAL_ID_GRUNT_2_MALE, Common_Movement_FaceLeft
	waitmovement 0
	delay 16
	delay 16
	msgbox BlossomwoodTownFlowerShop_Text_BacktoBackCutscene9, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_GRUNT_1_MALE, BlossomwoodTownFlowerShop_Movement_Grunt1MWalksUptoGrunt1F
	waitmovement 0
	applymovement LOCAL_ID_GRUNT_1_FEMALE, Common_Movement_FaceRight
	waitmovement 0
	msgbox BlossomwoodTownFlowerShop_Text_BacktoBackCutscene10, MSGBOX_DEFAULT
	closemessage
	delay 16
	delay 16
	applymovement LOCAL_ID_GRUNT_2_MALE, BlossomwoodTownFlowerShop_Movement_Grunt2MApproachesPlayer
	waitmovement 0
	msgbox BlossomwoodTownFlowerShop_Text_BacktoBackCutscene11, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_GRUNT_1_FEMALE, Common_Movement_FaceDown
	applymovement LOCAL_ID_GRUNT_1_MALE, Common_Movement_FaceDown
	waitmovement 0
	trainerbattle_no_intro TRAINER_FLOWER_SHOP_GRUNT_2, BlossomwoodTownFlowerShop_Text_Grunt2DefeatB2B
	delay 8
	playse SE_PIN
	applymovement LOCAL_ID_GRUNT_2_MALE, Common_Movement_ExclamationMark
	msgbox BlossomwoodTownFlowerShop_Text_BacktoBackCutscene12, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCAL_ID_GRUNT_1_MALE
	removeobject LOCAL_ID_GRUNT_1_FEMALE
	removeobject LOCAL_ID_GRUNT_2_MALE
	removeobject LOCAL_ID_GRUNT_2_FEMALE
	PLAYSE SE_EXIT
	setflag FLAG_GRUNTS_LEAVE_FLOWERSHOP
	delay 16
	delay 16
	fadedefaultbgm
	fadescreenswapbuffers FADE_FROM_BLACK
	applymovement LOCAL_ID_EVE_FLOWERSHOP, BlossomwoodTown_Movement_EveWalksBacktoPlayer
	delay 8
	applymovement LOCAL_ID_FLOWERSHOP_GIRL_2 BlossomwoodTown_Movement_Girl2ApproachesPlayer
	applymovement LOCAL_ID_FLOWERSHOP_GIRL_1 BlossomwoodTown_Movement_Girl1ApproachesPlayer
	waitmovement LOCAL_ID_FLOWERSHOP_GIRL_2
	delay 16
	msgbox BlossomwoodTownFlowerShop_Text_BacktoBackCutscene13, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_FLOWERSHOP_GIRL_1 Common_Movement_WalkDown
	waitmovement 0
	giveitem ITEM_SERIOUS_MINT
	msgbox BlossomwoodTownFlowerShop_Text_BacktoBackCutscene14, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_EVE_FLOWERSHOP, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox BlossomwoodTownFlowerShop_Text_BacktoBackCutscene15, MSGBOX_DEFAULT
	closemessage
	applymovement LOCAL_ID_EVE_FLOWERSHOP, BlossomwoodTownFlowerShop_Movement_EvePlayerLeave
	applymovement OBJ_EVENT_ID_PLAYER, BlossomwoodTownFlowerShop_Movement_EvePlayerLeave
	waitmovement 0
	warp MAP_BLOSSOMWOOD_TOWN, 26, 7
	addvar VAR_BLOSSOMTOWN_EVENTS, 1
	setflag FLAG_SAVED_FLOWERSHOP
	setflag FLAG_EVESTANDSOUTSIDESHOP
	release
	end

BlossomwoodTownFlowerShop_Text_BacktoBackCutscene1::
	.string "Shady Woman: Eh? Hey! This shop\n"
	.string "is closed! Didn'tcha see the sign?\p"
	.string "Eve: But...the door was open!\l"
	.string "Female Grunt 1: Eh? Really? We\n"
	.string "didn't lock it after we came in?$"

BlossomwoodTownFlowerShop_Movement_PlayerEveWalkIn::
	walk_up
	walk_up
	step_end

BlossomwoodTownFlowerShop_Movement_Grunt1MPositions::
	walk_left
	walk_down
	face_down
	step_end

BlossomwoodTownFlowerShop_Text_BacktoBackCutscene2::
	.string "Shady Guy: YOU!\l"
	.string "You're that kid from the peak! I\n"
	.string "told you to stop following me and\l"
	.string "to stay out of EVILTEAM's\l"
	.string "business! Ya hear me?$"

BlossomwoodTownFlowerShop_Text_BacktoBackCutscene3::
	.string "Shady Woman: Oh? So this is the\n"
	.string "kid that Gaia gave you a verbal\l"
	.string "lashing over losing to?\p"
	.string "They don't exactly look so tough.$"

BlossomwoodTownFlowerShop_Text_BacktoBackCutscene4::
	.string "Shady Guy: Because of you, I got\n"
	.string "the scolding of a lifetime!\p"
	.string "And now you've brought a friend?\l"
	.string "Eve: You guys don't look like you\n"
	.string "are here to just buy flowers...\p"
	.string "The employees look terrified!\l"
	.string "Shady Woman: Easy easy. It's just\n"
	.string "a lil transaction for a rare item.\l"
	.string "None of your business, kids!$"

BlossomwoodTownFlowerShop_Text_BacktoBackCutscene5::
	.string "Cashier: Hey! These people are\n"
	.string "lying! They're trying to haggle us\l"
	.string "for a product we don't have!\p"
	.string "They got really scary when we said\n"
	.string "we didn't have the Gracedia...!\p"
	.string "Please help! You're trainers right?$"

BlossomwoodTownFlowerShop_Text_BacktoBackCutscene6::
	.string "Shady Woman: You really are going\n"
	.string "to keep butting into our affairs?\p"
	.string "That's cute. Laughable even.\l"
	.string "I'll make you regret this!\l"
	.string "My peer should take notes on how\n"
	.string "to handle annoying meddling kids\l"
	.string "like you!$"

BlossomwoodTownFlowerShop_Text_BacktoBackCutscene7::
	.string "Eve: {PLAYER}! I'll take on the\n"
	.string "other one! Chaaaaaarge!$"

BlossomwoodTownFlowerShop_Movement_EveRunsToCashier::
	walk_fast_up
	walk_fast_up
	step_end

BlossomwoodTownFlowerShop_Text_BacktoBackCutscene8::
	.string "Shady Woman: You meddling...!\n"
	.string "out of our way!$"

BlossomwoodTownFlowerShop_Text_Grunt1DefeatB2B::
	.string "W...what? You...You're tougher than\n"
	.string "you looked after all!$"

BlossomwoodTownFlowerShop_Movement_Grunt1FDefeated::
	lock_anim
	walk_fast_up
	walk_fast_up
	unlock_anim
	step_end

BlossomwoodTownFlowerShop_Text_BacktoBackCutscene9::
	.string "Shady Woman: This...this isn't good!\n"
	.string "Both of them are really tough!$"

BlossomwoodTownFlowerShop_Movement_Grunt1MWalksUptoGrunt1F::
	walk_up
	walk_up
	face_left
	step_end

BlossomwoodTownFlowerShop_Text_BacktoBackCutscene10::
	.string "Shady Man: I told you! Now Gaia's\n"
	.string "gonna let us have it!\p"
	.string "Shady Woman: Shut it you! I don't\n"
	.string "need lecturing! I don't see you\l"
	.string "stepping in to help. You'd probably\l"
	.string "just lose again anyways!\p"
	.string "You! Take care of this kid! I\n"
	.string "softened him up for you!\p"
	.string "Shady Man 2: Hmph. Fine. I was tired\n"
	.string "of babysitting these girls.\p"
	.string "They wouldn't cough up the\n"
	.string "Gracedia anyways.$"

BlossomwoodTownFlowerShop_Movement_Grunt2MApproachesPlayer::
	walk_down
	walk_left
	walk_down
	walk_left
	face_down
	step_end

BlossomwoodTownFlowerShop_Text_BacktoBackCutscene11::
	.string "Shady Man 2: Hehe...Today's been\n"
	.string "such a bore.\p"
	.string "First bozo over there lets the\n"
	.string "prototype get away. Now we're\l"
	.string "stuck askin about stinkin flowers.\p"
	.string "You've messed with my cohorts, so\n"
	.string "now you're going to feel the\l"
	.string "consequences of messing with\l"
	.string "EVILTEAM! You're going down!$"

BlossomwoodTownFlowerShop_Text_Grunt2DefeatB2B::
	.string "There's just no way! No freaking\n"
	.string "way some kids just waltzed in here\l"
	.string "and beat us!\p"
	.string "We're so dead...$"

BlossomwoodTownFlowerShop_Text_BacktoBackCutscene12::
	.string "Shady Man 2: This is bad...Gaia's\n"
	.string "going to be here soon and we're\l"
	.string "all beat!\p"
	.string "Shady Woman 2: This other one is\n"
	.string "strong too! What are we going to\l"
	.string "tell him?\p"
	.string "Shady Man: Hah! Serves you losers\n"
	.string "right for making fun of me before!\p"
	.string "Shady Woman: Only one option for\n"
	.string "us then...\p"
	.string "Tactical Retreat!\n"
	.string "Regroup at the rendezvous!\p"
	.string "Kids! You're both on EVILTEAM's\n"
	.string "hit list now! When Gaia arrives,\l"
	.string "he'll pulverize you!$"

BlossomwoodTown_Movement_EveWalksBacktoPlayer::
	walk_down
	walk_down
	face_up
	step_end

BlossomwoodTown_Movement_Girl1ApproachesPlayer::
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

BlossomwoodTown_Movement_Girl2ApproachesPlayer::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

BlossomwoodTownFlowerShop_Text_BacktoBackCutscene13::
	.string "Flower Girl 1:  Oh my goodness! You\n"
	.string "two saved us!\p"
	.string "These people have been hanging\n"
	.string "around this town for a few days\l"
	.string "and haven't caused any trouble...\p"
	.string "But today they just rushed in and\n"
	.string "yelled at us 'We know you have the\l"
	.string "Gracedia seeds here!'\p"
	.string "Eve: Gracedia! That's...that's the\n"
	.string "flower of Shaymin!\p"
	.string "Why would something so special be\n"
	.string "sold in a shop in a little town like\l"
	.string "this?\p"
	.string "Flower Girl 2: Well you see...over on\n"
	.string "the West side of the mountain is\l"
	.string "the Flower Paradise.\p"
	.string "Once a year, we go there to get\n"
	.string "seeds for our seasonal sales.\p"
	.string "But there was an avalanche, so we\n"
	.string "have been unable to go get them.\p"
	.string "Eve: Oh...since they couldn't get\n"
	.string "to the Paradise over the mountain,\l"
	.string "they must have come here instead.\p"
	.string "Cashier: They were going to turn\n"
	.string "our whole shop upside down when\l"
	.string "we said we didn't have it.\p"
	.string "Flower Girl 1: You saved us, so let\n"
	.string "us thank you!\p"
	.string "We sell these in a limited stock,\n"
	.string "but you can have this one for free\l"
	.string "since you saved us!$"

BlossomwoodTownFlowerShop_Text_BacktoBackCutscene14::
	.string "Flower Girl 1: That's a Mint!\l"
	.string "You can use it to instantly change\n"
	.string "a Pokémon's nature.\p"
	.string "They're hard to come by, so we only\n"
	.string "sell them in limited stocks for\l"
	.string "limited times.\p"
	.string "Most vendors here in Kusho do, to\n"
	.string "be honest. They're quite sought\l"
	.string "after for trainers!\p"
	.string "Flower Girl 2: We'll have to clean\n"
	.string "up...um, so we're going to close for\l"
	.string "a bit.\p"
	.string "Thank you so much for the help!\l"
	.string "Eve: No problemo! Glad to assist!$"

BlossomwoodTownFlowerShop_Text_BacktoBackCutscene15::
	.string "{PLAYER}, let's go outside and we\n"
	.string "can think of a plan!$"

BlossomwoodTownFlowerShop_Movement_EvePlayerLeave::
	walk_down
	walk_down
	step_end

@NPCS AND SHOP AFTER SAVING THE FLOWER SHOP

BlossomwoodTownFlowerShop_EventScript_EmployeeGirl1::
	lock
	faceplayer
	msgbox BlossomwoodTownFlowerShop_Text_EmployeeGirl1, MSGBOX_DEFAULT
	closemessage
	release
	end

BlossomwoodTownFlowerShop_Text_EmployeeGirl1::
	.string "Well look at this! Our hero came\n"
	.string "back to pay our lil shop a visit!\p"
	.string "...Though right now our stock's a\n"
	.string "bit run down admittedly.\p"
	.string "My sister's and I all started this\n"
	.string "shop as a way to spread the joy\l"
	.string "of flowers to travelers!\p"
	.string "If we had a Gracedia in stock, we\n"
	.string "would have gladly given it to you.\p"
	.string "Although if we did, maybe we would\n"
	.string "not have been in trouble to begin\l"
	.string "with... \p"
	.string "Come visit us any time!$"

BlossomwoodTownFlowerShop_EventScript_EmployeeGirl2::
	lock
	faceplayer
	msgbox BlossomwoodTownFlowerShop_Text_EmployeeGirl2, MSGBOX_DEFAULT
	closemessage
	release
	end

BlossomwoodTownFlowerShop_Text_EmployeeGirl2::
	.string "Kusho is an archipelago, but some\n"
	.string "of the Islands are connected by\l"
	.string "thin strands of land\p"
	.string "This Island is known as Shiro\n"
	.string "Island, likely because of Mt. Aeon\l"
	.string "being covered in white snow.\p"
	.string "Because of it's size, this is the\n"
	.string "largest Island in Kusho, which\l"
	.string "also has a predominant abundance\l"
	.string "of plant life!\p"
	.string "I'm grateful every day for the life\n"
	.string "we all live!\p"
	.string "The gratitude Pokémon Shaymin is\n"
	.string "the one that is said to have given\l"
	.string "life to plants in this region.\p"
	.string "Isn't that lovely?$"

BlossomwoodTownFlowerShop_EventScript_CashierSales::
	lock
	faceplayer
	msgbox BlossomwoodTownFlowerShop_Text_CashierSales, MSGBOX_DEFAULT
	waitmessage
	pokemart BlossomwoodTown__Pokemart
	msgbox BlossomwoodTownFlowerShop_Text_CashierSalesFarewell, MSGBOX_DEFAULT
	release
	end

BlossomwoodTownFlowerShop_Text_CashierSales::
	.string "Oh hello there! You're welcome to\n"
	.string "shop here anytime!\p"
	.string "Some of our stock will only be here\n"
	.string "for a limited time, and we only sell\l"
	.string "some of it at a limit per customer.\p"
	.string "As a thanks for saving us, we can\n"
	.string "offer you freshly picked berries\l"
	.string "for an extreme discount!\p"
	.string "Have a look at our merchandise!$"

	.align 2
BlossomwoodTown__Pokemart:
	.2byte ITEM_ORAN_BERRY
	.2byte ITEM_CHERI_BERRY
	.2byte ITEM_RAWST_BERRY
	.2byte ITEM_CHESTO_BERRY
	.2byte ITEM_PECHA_BERRY
	.2byte ITEM_LAX_MINT
	.2byte ITEM_GENTLE_MINT
	.2byte 
	pokemartlistend

BlossomwoodTownFlowerShop_Text_CashierSalesFarewell::
	.string "Please come again anytime!$"
