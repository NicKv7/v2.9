/**********************
****[100% REVISADO]****
***********************/
#define PlayerFile "ServerData/Players/%s.ini"
#define HouseFile "ServerData/Houses/House%i.ini"
#define CameraFile "ServerData/Cameras/Camera%i.ini"
#define BusinessFile "ServerData/Business/Business%i.ini"
#define BankFile "ServerData/Bank/%s.ini"

#define VehicleFlatbed			455 // Truck: Flatbed
#define VehicleDFT30			578 // Truck: DFT-30
#define VehicleCementTruck		524 // Truck: Cementtruck
#define VehicleLineRunner		403 // Truck: LineRunner
#define VehicleTanker			514 // Truck: Tanker
#define VehicleRoadTrain		515 // Truck: RoadTrain
#define VehicleTrailerCargo		435 // Trailer: cargo
#define VehicleTrailerCargo2	591 // Trailer: cargo
#define VehicleTrailerOre		450 // Trailer: Ore
#define VehicleTrailerFluids	584 // Trailer: Fluids

#define VehicleCoach			437 // Bus

#define VehicleShamal           519 // Plane: Shamal
#define VehicleNevada           553 // Plane: Nevada
#define VehicleStuntPlane       513 // Plane: Stuntplane
#define VehicleDodo       		593 // Plane: Dodo
#define VehicleMaverick         487 // Helicopter: Maverick
#define VehicleCargobob         548 // Helicopter: Cargobob
#define VehicleAT400            577 // Plane: AT400
#define VehicleAndromada        592 // Plane: Andromada

#define VehiclePoliceLSPD       596 // Police Car Los Santos Police Department
#define VehiclePoliceSFPD       597 // Police Car San Fierro Police Department
#define VehiclePoliceLVPD       598 // Police Car Las Venturas Police Department
#define VehicleHPV1000          523 // Police motorcycle
#define VehiclePoliceRanger     599 // Police Ranger

#define VehicleSandKing			495 // Mafia-van: Sandking
#define VehicleMoonbeam         418 // Mafia-van: Moonbeam

#define VehicleBike             509 // Bike: Bike
#define VehicleBMX              481 // Bike: BMX
#define VehicleMountainBike     510 // Bike: Mountain Bike
#define VehicleFaggio           462 // Bike: Faggio
#define VehiclePizzaBoy         448 // Bike: Pizzaboy
#define VehicleBF400            581 // Bike: BF-400
#define VehicleNRG500           522 // Bike: NRG-500
#define VehiclePCJ600           461 // Bike: PCJ-600
#define VehicleFCR900           521 // Bike: FCR-900
#define VehicleFreeway          463 // Bike: Freeway
#define VehicleWayfarer         586 // Bike: Wayfarer
#define VehicleSanchez          468 // Bike: Sanchez
#define VehicleQuad             471 // Bike: Quad

#define VehicleCoastguard		472 // Boat: Coastguard
#define VehicleDinghy			473 // Boat: Dinghy
#define VehicleJetmax			493 // Boat: Jetmax
#define VehicleLaunch			595 // Boat: Launch
#define VehicleMarquis			484 // Boat: Marquis
#define VehiclePredator			430 // Boat: Predator
#define VehicleReefer			453 // Boat: Reefer
#define VehicleSpeeder			452 // Boat: Speeder
#define VehicleSquallo			446 // Boat: Squallo
#define VehicleTropic			454 // Boat: Tropic



#define VehicleRhino            432 // Tank: Rhino
#define VehiclePatriot          470 // Jeep: Patriot

#define VehicleTowTruck         525 // Towtruck
#define VehicleBurrito          482 // Van: Burrito
#define VehicleFaggio           462 // Bike: Faggio
#define VehicleBenson           499 // Truck: Benson

#define VehicleDozer            486 // Dozer
#define VehicleUtilityVan       552 // Utility Van
#define VehicleUtilityTrailer   611 // Utility trailer

#define PCV_TruckerOreTrailer			1
#define PCV_TruckerFluidsTrailer     	2
#define PCV_TruckerCargoTrailer      	3
#define PCV_TruckerCementTruck       	4
#define PCV_TruckerNoTrailer         	5
#define PCV_PilotPlane               	6
#define PCV_PilotHelicopter          	7
#define PCV_MafiaVan                 	8

#define ClassTruckDriver 1
#define ClassBusDriver 2
#define ClassPilot 3
#define ClassPolice 4
#define ClassMafia 5
#define ClassCourier 6
#define ClassAssistance 7
#define ClassRoadWorker 8

#define Job_TimeToFailMission   	60

#define ColorClassTruckDriver		0xFF8000FF // Orange
#define ColorClassBusDriver			0x80FFFFFF // Light blue
#define ColorClassPilot             0x008080FF // Dark blue
#define ColorClassPolice			0x0000FFFF // Blue
#define ColorClassMafia				0x8000FFFF // Purple
#define ColorClassCourier           0xFF0080FF // Pink
#define ColorClassAssistance        0x80FF00FF // Dark green
#define ColorClassRoadWorker        0xFFFF80FF // Light yellow

#define DialogRegister      		1
#define DialogLogin         		2
#define DialogStats                 3
#define DialogStatsOtherPlayer      4
#define DialogRules                 5
#define DialogReports               6
#define DialogStatsHouse          	7
#define DialogStatsGoHouse          8
#define DialogStatsGoBusiness       9

#define DialogRescue                11
#define DialogBuyLicenses           12
#define DialogRadios                13
#define DialogQ                     14

#define DialogTruckerJobMethod      21
#define DialogTruckerSelectLoad     22
#define DialogTruckerStartLoc       23
#define DialogTruckerEndLoc         24

#define DialogBusJobMethod          31
#define DialogBusSelectRoute        32

#define DialogCourierSelectQuant    41

#define DialogBike                  101
#define DialogCar                   102
#define DialogPlane                 103
#define DialogTrailer               104
#define DialogRentCarClass       	105
#define DialogRentCar	        	106
#define DialogBoat                  107
#define DialogNeon                  108

#define DialogWeather               201
#define DialogCarOption             202

#define DialogSelectConvoy          401
#define DialogConvoyMembers         402

#define DialogPlayerCommands        501
#define DialogPrimaryCarColor       502
#define DialogSedundaryCarColor     503

#define DialogHouseMenu             601
#define DialogUpgradeHouse          602
#define DialogGoHome                603
#define DialogHouseNameChange       604
#define DialogSellHouse             605
#define DialogBuyCarClass           606
#define DialogBuyCar                607
#define DialogSellCar               608
#define DialogBuyInsurance          609
#define DialogGetCarSelectHouse     610
#define DialogGetCarSelectCar       611
#define DialogUnclampVehicles       612

#define DialogCreateBusSelType      701
#define DialogBusinessMenu          702
#define DialogGoBusiness            703
#define DialogBusinessNameChange    704
#define DialogSellBusiness          705

#define DialogBankPasswordRegister  801
#define DialogBankPasswordLogin     802
#define DialogBankOptions           803
#define DialogBankDeposit           804
#define DialogBankWithdraw          805
#define DialogBankTransferMoney     806
#define DialogBankTransferName     	807
#define DialogBankCancel            808

#define DialogHelpItemChosen        901
#define DialogHelpItem              902

#define DialogOldPassword           1001
#define DialogNewPassword           1002
#define DialogConfirmPassword     	1003

#define DialogNoResponse            25000

#define MAX_CONVOYS					5
#define CONVOY_MAX_MEMBERS          25
#define CONVOY_EMPTY                0
#define CONVOY_OPEN                 1
#define CONVOY_FULL         	    2
#define CONVOY_CLOSED               3

#define ColorRed 0xFF0000FF
#define ColorGreen 0x00FF00FF
#define ColorBlue 0x0000FFFF

#define WORLD_JAIL 10254

#define AutoKickAfterWarn           1
#define AutoKickWarnings            3

#define ADMIN_SPEC_TYPE_NONE 0
#define ADMIN_SPEC_TYPE_PLAYER 1
#define ADMIN_SPEC_TYPE_VEHICLE 2

new DialogMsg5000[5000];
new LastVehicleID;
new LastObjectID;
new TotalHouses;
new TotalCameras;
new TotalBusiness;
new LastTimedMessage;
new ATimedMessages[][128] =
{
	{TXT_TimedRadio},
	{TXT_TimedComboio},
	{TXT_TimedIrParaCasa},
	{TXT_TimedNovidades},
	{TXT_TimedLicencas},
	{TXT_TimedRadares},
	{TXT_TimedIP},
    {TXT_TimedBlog}
};
enum TRandomBonusMission
{
	RandomLoad,
	RandomStartLoc,
	RandomEndLoc,
	bool:MissionFinished
}
new RandomBonusMission[TRandomBonusMission];
new AdminLevelName[7][24] =
{
	{"Civil"},         // Admin-level 0
	{"Moderador"},     // Admin-level 1
	{"Ajudante"},      // Admin-level 2
	{"Administrador"}, // Admin-level 3
	{"Organizador"},   // Admin-level 4
    {"Gerente"},       // Admin-level 5
	{"Dono"}           // Admin-level 6
};      
new Pickup_License;
enum TPickupData
{
	Float:pux,
	Float:puy,
	Float:puz,
	PickupID
}
new ARefuelPickups[50][TPickupData];
new ACarDealerPickups[3][TPickupData];
enum TTollGate
{
	GateID, // Holds the object-id of the gate
	TollPrice, // Holds the price for passing the gate
	GateStatus, // Holds the status of the gate (open = 1, closed = 0)
	Float:OpenX, // Holds the coordinates when the gate is opened
	Float:OpenY, // Holds the coordinates when the gate is opened
	Float:OpenZ, // Holds the coordinates when the gate is opened
	Float:CloseX, // Holds the coordinates when the gate is closed
	Float:CloseY, // Holds the coordinates when the gate is closed
	Float:CloseZ // Holds the coordinates when the gate is closed
}
new ATollGates[MAX_TOLLGATES][TTollGate];
enum TSpikeStrip
{
	SpikeTime, // This holds the time left when the spikestrip automatically disappears
	SpikeTimer, // This holds the reference to the timer for spikestrips
	SpikeObject, // This holds the ObjectID of the spikestrip object
	Float:SpikeX, // This holds the X coordinates of the spikestrip
	Float:SpikeY, // This holds the Y coordinates of the spikestrip
	Float:SpikeZ // This holds the Z coordinates of the spikestrip
}
new ASpikeStrips[MAX_SPIKESTRIPS][TSpikeStrip];
enum TSpeedCamera
{
	Float:CamX, // Holds the X-coordinate of the camera
	Float:CamY, // Holds the Y-coordinate of the camera
	Float:CamZ, // Holds the Z-coordinate of the camera
	Float:CamAngle, // Holds the Angle of the camera
	CamSpeed, // Holds the maximum speed allowed to pass this camera without being caught
	CamObj1, // Holds the reference to the first camera object
	CamObj2, // Holds the reference to the second camera object
    CamIcon
}
new ACameras[100][TSpeedCamera];
enum TConvoyData
{
	Members[CONVOY_MAX_MEMBERS], // This array holds the playerid's of all members (at index 0, the leader is stored), so a convoy can hold 1 leader and 9 members
	LoadID, // Holds the ID of the load
	Location1, // Holds the location-id of the start-location
	Location2, // Holds the location-id of the end-location
	Status, // Holds the status of the convoy (1 = open, 2 = full, 3 = closed, 0 = empty)
	ConvoyStep, // Holds the jobstep for the entire convoy
	TrailerModel, // Holds the trailer-model required by the convoy
	bool:LeaderInformedTrailers, // Is used to inform the leader ONCE if all members failed to have the same trailer
	Text:ConvoyTextLeader, // This is the textdraw for the leader of the convoy
	Text:ConvoyTextMember, // This is the textdraw for all members of the convoy
	ConvoyTimer // This convoy-timer checks everything for the whole convoy
}
// Setup an array which holds all data for every convoy
new AConvoys[MAX_CONVOYS][TConvoyData];
enum TVehicleData
{
	bool:MafiaLoad, // Holds True if the vehicle (or trailer) is carrying a mafia-wanted load
	Fuel, // Holds the amount of fuel for this vehicle
	BelongsToHouse, // Holds the HouseID to which this vehicle belongs
	bool:StaticVehicle, // Holds true if this is a static vehicle
	bool:Owned, // Holds true if the vehicle is owned by somebody
	Owner[24], // Holds the name of the owned of the vehicle
	Model, // Holds the vehicle-model of this vehicle
	PaintJob, // Holds the ID of the paintjob applied to the vehicle
	Components[14], // Holds all Component-ID's for all components on the vehicle
	Color1, // Holds the primary color for this vehicle
	Color2, // Holds the secundairy color for this vehicle
	NeonLeft, // Holds the neon-object on the left side
	NeonRight, // Holds the neon-object on the right side
	Float:SpawnX, // Holds the X-coordinate of the parking spot for this vehicle
	Float:SpawnY, // Holds the Y-coordinate of the parking spot for this vehicle
	Float:SpawnZ, // Holds the Z-coordinate of the parking spot for this vehicle
	Float:SpawnRot, // Holds the rotation of the parking spot for this vehicle
	bool:Clamped // Holds "true" if the vehicle is clamped by an admin
}
// Setup an array which holds all data for every vehicleid, max 2000 vehicles (server limit)
new AVehicleData[2000][TVehicleData];
enum TBusinessData
{
	PickupID, // Holds the pickup-id that is linked to this business
	Text3D:DoorText, // Holds the reference to the 3DText above the business's pickup
	MapIconID, // Holds the ID of the mapicon for the business

	BusinessName[100], // Holds the name of the business (this will be displayed above the pickup near the business when it's owned)
	Float:BusinessX, // Holds the X-coordinate of the pickup for the Business
	Float:BusinessY, // Holds the Y-coordinate of the pickup for the Business
	Float:BusinessZ, // Holds the Z-coordinate of the pickup for the Business
	BusinessType, // Holds the type of business (well stacked pizza, burger shot, ...), this defines which icon and interior to use
	BusinessLevel, // Holds the level of upgrades the business has
	LastTransaction, // Holds the amount of minutes when the last transaction took place (buying the business or retrieving the money by the owner)
	bool:Owned, // Holds true if the Business is owned by somebody
	Owner[24] // Holds the name of the owner of the Business
}
// Holds the data for all houses
new ABusinessData[MAX_BUSINESS][TBusinessData];
new BusinessTransactionTime;
enum THouseData
{
	PickupID, // Holds the pickup-id that is linked to this house
	Text3D:DoorText, // Holds the reference to the 3DText above the house's pickup
	MapIconID, // Holds the ID of the mapicon for the house

	HouseName[100], // Holds the name of the house (this will be displayed above the pickup near the house when it's owned)
	Insurance, // Holds "1" if the house has an insurance for the vehicles belonging to this house
	Float:HouseX, // Holds the X-coordinate of the pickup for the house
	Float:HouseY, // Holds the Y-coordinate of the pickup for the house
	Float:HouseZ, // Holds the Z-coordinate of the pickup for the house
	HouseLevel, // Holds the level of upgrades the house has (also defines how many vehicles can currently be added to the house)
	HouseMaxLevel, // Holds the maximum level this house can be upgraded to
	HousePrice, // Holds the price for buying the house, the same price applies when upgrading a house per level
	bool:Owned, // Holds true if the house is owned by somebody
	Owner[24], // Holds the name of the owner of the house
	bool:HouseOpened, // Holds true if the house is open to the public (anyone can enter), false means: only the owner can enter it
	VehicleIDs[10] // Holds the vehicle-id's of the vehicles linked to this house
}
new AHouseData[MAX_HOUSES][THouseData];
enum THouseInterior
{
	InteriorName[50], // Holds the name of the interior
	InteriorID, // Holds the interior-id
	Float:IntX, // Holds the X-coordinate of the spawn-location where you enter the house
	Float:IntY, // Holds the Y-coordinate of the spawn-location where you enter the house
	Float:IntZ // Holds the Z-coordinate of the spawn-location where you enter the house
}
new AHouseInteriors[][THouseInterior] =
{
	{"Dummy", 				0, 		0.0, 		0.0, 		0.0}, // Dummy interior (Level 0), as the house-level starts at 1
	{"Pequeno Quarto de Motel", 	10, 	2262.83, 	-1137.71, 	1050.63}, // Level 1
	{"Casa pequena 1", 		2, 		2467.36, 	-1698.38, 	1013.51}, // Level 2
	{"Casa pequena 2", 		1, 		223.00, 	1289.26, 	1082.20}, // Level 3
	{"Casa média 1", 		10, 	2260.76, 	-1210.45, 	1049.02}, // Level 4
	{"Casa média 2",		8, 		2365.42, 	-1131.85, 	1050.88}, // Level 5
	{"Casa duplex",		12, 	2324.33, 	-1144.79, 	1050.71}, // Level 6
	{"Casa grande", 			15, 	295.14, 	1474.47, 	1080.52}, // Level 7
	{"Casa grande duplex", 	3, 		235.50, 	1189.17, 	1080.34}, // Level 8
	{"Casa enorme", 			7, 		225.63, 	1022.48, 	1084.07}, // Level 9
	{"Mansão", 			5, 		1299.14, 	-794.77, 	1084.00} // Level 10
};
enum TBusinessType
{
	InteriorName[50], // Holds the name of the interior
	InteriorID, // Holds the interior-id
	Float:IntX, // Holds the X-coordinate of the spawn-location where you enter the business
	Float:IntY, // Holds the Y-coordinate of the spawn-location where you enter the business
	Float:IntZ, // Holds the Z-coordinate of the spawn-location where you enter the business
	BusPrice, // Holds the price for the business
	BusEarnings, // Holds the earnings for this type of business
	IconID // Holds the icon-id which represents the business
}
// Holds the data for all interiors for businesses
new ABusinessInteriors[][TBusinessType] =
{
	{"Dummy", 				0, 		0.0, 		0.0, 		0.0,		0,			0,		0}, // Dummy business (Type 0)
	{"24/7 (pequeno)", 		6, 		-26.75, 	-55.75, 	1003.6,		500000,		200,		52}, // Type 1 (earnings per day: $1200)
	{"24/7 (Medio)", 		18, 	-31.0, 		-89.5, 		1003.6,		750000,		250,		52}, // Type 2 (earnings per day: $1800)
	{"Bar", 				11, 	502.25, 	-69.75, 	998.8,		350000,		150,		49}, // Type 3 (earnings per day: $840)
	{"Barbearia (pequena)", 		2, 		411.5, 		-21.25, 	1001.8,		300000,		160,		7}, // Type 4 (earnings per day: $720)
	{"Barbearia (Medio)",		3, 		418.75, 	-82.5, 		1001.8,		350000,		180,		7}, // Type 5 (earnings per day: $840)
	{"Loja de apostas", 		3, 		833.25, 	7.0, 		1004.2,		1500000,	400,	52}, // Type 6 (earnings per day: $3600)
	{"Burger Shot", 		10, 	363.5, 		-74.5, 		1001.5,		750000,		300,		10}, // Type 7 (earnings per day: $1800)
	{"Casino (4 Dragons)", 	10, 	2017.25, 	1017.75, 	996.9,		2500000,	1000,	44}, // Type 8 (earnings per day: $6000)
	{"Casino (Caligula's)", 1, 		2234.0, 	1710.75, 	1011.3,		2500000,	1000,	25}, // Type 9 (earnings per day: $6000)
	{"Casino (Small)", 		12, 	1133.0, 	-9.5,	 	1000.7,		2000000,	900,	43}, // Type 10 (earnings per day: $4800)
	{"Loja de Roupas (Binco)", 	15, 	207.75, 	-109.0, 	1005.2,		850000,		300,		45}, // Type 11 (earnings per day: $2040)
	{"Loja de Roupas (Pro)", 		3, 		207.0, 		-138.75, 	1003.5,		850000,		300,		45}, // Type 12 (earnings per day: $2040)
	{"Loja de Roupas (Urban)", 	1, 		203.75, 	-48.5, 		1001.8,		850000,		300,		45}, // Type 13 (earnings per day: $2040)
	{"Loja de Roupas (Victim)", 	5, 		226.25, 	-7.5, 		1002.3,		850000,		300,		45}, // Type 14 (earnings per day: $2040)
	{"Loja de Roupas (ZIP)",		18, 	161.5, 		-92.25, 	1001.8,		850000,		300,		45}, // Type 15 (earnings per day: $2040)
	{"Cluckin' Bell",		9,		365.75, 	-10.75,  	1001.9,		750000,		180,		14}, // Type 16 (earnings per day: $1800)
	{"Disco (pequeno)", 		17, 	492.75,		-22.0, 		1000.7,		1000000,	250,	48}, // Type 17 (earnings per day: $2400)
	{"Disco (grande)", 		3, 		-2642.0, 	1406.5, 	906.5,		1200000,	350,	48}, // Type 18 (earnings per day: $2880)
	{"Academia (LS)", 			5, 		772.0, 		-3.0, 		1000.8,		500000,		350,		54}, // Type 19 (earnings per day: $1200)
	{"Academia (SF)", 			6, 		774.25, 	-49.0, 		1000.6,		500000,		350,		54}, // Type 20 (earnings per day: $1200)
	{"Academia (LV)", 			7, 		774.25, 	-74.0, 		1000.7,		500000,		350,		54}, // Type 21 (earnings per day: $1200)
	{"Motel", 				15, 	2216.25, 	-1150.5, 	1025.8,		1000000,	700,	37}, // Type 22 (earnings per day: $2400)
	{"RC shop", 			6, 		-2238.75, 	131.0, 		1035.5,		600000,		189,		46}, // Type 23 (earnings per day: $1440)
	{"Sex-shop", 			3, 		-100.25, 	-22.75, 	1000.8,		800000,		240,		38}, // Type 24 (earnings per day: $1920)
	{"Matadouro", 		1, 		933.75, 	2151.0, 	1011.1,		500000,		250,		50}, // Type 25 (earnings per day: $1200)
	{"Stadio (Bloodbowl)", 15, 	-1394.25, 	987.5, 		1024.0,		1750000,	350,	33}, // Type 26 (earnings per day: $4200)
	{"Stadio (Kickstart)", 14, 	-1410.75, 	1591.25, 	1052.6,		1750000,	350,	33}, // Type 27 (earnings per day: $4200)
	{"Stadio (8-Track)", 	7, 		-1396.0, 	-208.25, 	1051.2,		1750000,	350,	33}, // Type 28 (earnings per day: $4200)
	{"Stadio (Dirt Bike)", 4, 		-1425.0, 	-664.5, 	1059.9,		1750000,	350,	33}, // Type 29 (earnings per day: $4200)
	{"Clube de Strip (pequeno)",3, 1212.75,	-30.0, 1001.0, 750000, 120, 48},    // Tipo 30 (ganhos por dia: R$2880)
	{"Clube de Strip (grande)",2, 1204.75, -12.5, 1001.0, 900000, 150, 48},     // Tipo 31 (ganhos por dia: R$3600)
	{"Tattoo LS",16, -203.0, -24.25, 1002.3, 500000, 100, 39},                  // Tipo 32 (ganhos por dia: R$2400)
	{"Pizzaria",5, 372.25, -131.50, 1001.5, 650000, 200, 29},                   // Tipo 33 (ganhos por dia: R$4800)
    {"Posto",18, 1302.519897, -1.787510, 1001.028259, 800000, 500, 55},          // Tipo 34 (ganhos por dia: R$12000)      
    {"Hotel",18, 1710.433715, -1669.379272, 20.225049, 750000, 450, 32},         // Tipo 35 (ganhos por dia: R$10800)      
    {"Banco",0,2319.714843, -14.838361, 26.749565, 1000000, 800, 52},    
    {"Oficina",0,-1790.378295,1436.949829,7.187500, 600000, 350, 27},    
    {"Concessionária",0,-1790.378295,1436.949829,7.187500, 800000, 500, 27},
	{"Transportadora",1,1412.639892,-1.787510,1000.924377, 800000, 600, 51}
};
enum TReport
{
	bool:ReportUsed, // Holds true if this report-spot has been used
	ReportName[24], // Holds the name of the offender
	ReportReason[128] // Holds the reason why he's been reported
}
new AReports[50][TReport];
new ReportList[5000]; // Setup an array to holds the reports for the report-dialog

enum TPlayerData
{
	PlayerPassword[50], // Holds the password of the player's account
	PlayerNewPassword[50], // Holds the new password for the player
	PlayerLevel, // The admin-level of the player
    PlayerCommand, 
	PlayerJailed, // Holds jail-time left for this player
	PlayerJailedTimer, // Holds the reference to the jail-timer
	PlayerFrozen, // Holds the time this player is frozen
	PlayerFrozenTimer, // Holds the reference to the frozen-timer
	Warnings, // Holds the number of warnings for this player
	Bans, // Holds the number of bans for this player
	BanTime, // Holds the time where the player is unbanned automatically (when the ban is over)
	bool:LoggedIn, // Holds true if the player has properly logged in
	bool:Muted, // Holds "true" if the player is muted
	bool:RulesRead, // Holds "true" if the player accepted the rules
	AutoReportTime, // Used to prevent the anti-hack system reporting the player every half a second when the player uses hacks
	Logado,
 	TruckerLicense, // Holds "1" if the player has acquired his truckers-license
	BusLicense, // Holds "1" if the player has acquired his busdriver license
    WeaponLicense,
	PlayerMoney, // Holds the money of this player
	PlayerScore, // Holds the score of this player
	PlayerName[24], // Holds the name of the player

	Houses[MAX_HOUSESPERPLAYER], // Holds the HouseID's of the houses that the player owns (index of the AHouseData array)
    CurrentHouse, // Holds the HouseID to track in which house the player currently is (used when accessing the housemenu)
	Business[MAX_BUSINESSPERPLAYER], // Holds the BusinessID's of the business that the player owns
	CurrentBusiness, // Holds the BusinessID to track in which business the player currently is (used when accessing the businessmenu)

	PlayerClass, //Holds the Class that the player chose (1 = truckdriver, 2 = taxidriver, ... -> see DEFINES)

	SpectateID, // Holds the ID of the other player which this player is spectating
	SpectateVehicle, // If the target player is inside a vehicle, store it here
	SpectateType, // Holds the type of spectating (none, player or vehicle)

	Float:PreviousX, // Holds the previous X location of the player (used to detect airbreak hacks)
	Float:PreviousY, // Holds the previous Y location of the player (used to detect airbreak hacks)
	Float:PreviousZ, // Holds the previous Z location of the player (used to detect airbreak hacks)
	PreviousInt, // Holds the previous interior id (used to detect airbreak hacks)

	StatsTruckerJobs, // Holds the number of succesfully completed trucker-missions
	StatsConvoyJobs, // Holds the number of completed trucking-routes when in a convoy
	StatsBusDriverJobs, // Holds the number of completed busroutes
	StatsPilotJobs, // Holds the number of completed pilot-missions
	StatsMafiaJobs, // Holds the number of completed mafia-missions
	StatsMafiaStolen, // Holds the number of succesfully deliveries of stolen mafialoads
	StatsPoliceFined, // Holds the number of fined players for police
	StatsPoliceJailed, // Holds the number of jailed players for police
	StatsCourierJobs, // Holds the number of completed courier-jobs
	StatsAssistance, // Holds the number of player-vehicles that this player has repaired/refuelled
	StatsRoadworkerJobs, // Holds the number of completed roadworker jobs
	Float:StatsMetersDriven, // Holds the total kilometers that the player has driven already

	Text:SpeedometerText, // The TextDraw of the speedometer for this player
	Text:FuelGauge, // The textdraw of the fuel-gauge for this player
	SpeedometerTimer, // Holds the reference to the speedometer timer for this player
	PlayerSpeed, // Holds the speed of the player
	PlayerCaughtSpeeding, // This holds a value to prevent being caught multiple times by the same speedcamera

	Timer_PoliceCanJailMe, // This holds a reference to the timer which is started when the player got warned by a police player
	Value_PoliceCanJailMe, // This holds the remaining time for the Timer_PoliceCanJailPlayer timer
	bool:PoliceCanJailMe, // This holds "true" when the player was warned by a police player but didn't stop before the timer ran out
	bool:PoliceWarnedMe, // This holds "true" is the player got caught by a police player and got at least one warning

	bool:AssistanceNeeded, // Holds "true" is the player called for assistance

	bool:JobStarted, // States that the player has started a job or not
	Text:MissionText, // Displays the mission info at the bottom of the screen
	JobID, // Mission ID of the job (in the appropriate array, based on the PlayerClass), not used by truckers
	JobStep, // Current step of the job (for trucker: 1 = going to load, 2 = delivering goods to destination)
	Passengers, // Holds the number of passengers (used for busdriver, taxi classes)
	PlayerCheckTimer, // A special timer used by certain classes (police, mafia) to check players every second if they're wanted/carrying mafialoads
	LoadingTimer, // The timer used for loading and unloading during jobs
	VehicleTimerTime, // Holds the remaining seconds for the global vehicletimer
	VehicleID, // Holds the ID of the vehicle that the player is driving during his job
	TrailerID, // Holds the ID of the trailer that the player has attached during his job (is 0 if no trailer attached)
	LoadID, // Holds the ID of the load
	JobLoc1, // Holds the LocationID where to pickup the load (used in trucking missions)
	JobLoc2, // Holds the LocationID where to deliver the load (used in trucking missions)
	bool:Overloaded, // Holds True if the player's vehicle is overloaded (wanted level increases by 2)
	bool:MafiaLoad, // Holds True is the player's load is wanted by the mafia
	bool:MafiaLoadHijacked, // Holds true if the mafia-player has hijacked a mafia-load
	bool:InConvoy, // Holds true if the player has joined a convoy already
	ConvoyID, // Holds the ID of the convoy where this player is a member
	CourierHouses[11], // This holds up to 10 HouseID's for use during Courier-missions
	CourierMaxStep, // This holds the max number of houses to deliver packages to

	DialogFirstItem, // Holds the first array-index where a split dialog must start
	DialogCarFirstCar, // Holds the first array-index where the carlist should start when the player asks to choose a car to spawn ("/car")
	DialogPlaneFirstPlane, // Holds the first array-index where the planelist should start when the player asks to choose a plane to spawn ("/plane")
	DialogTrailerFirstTrailer, // Holds the first array-index where the trailerlist should start when the player asks to choose a trailer to spawn ("/trailer")

	DialogRentVClass, // Holds the ID of the chosen vehicle class to process when renting a vehicle
	DialogRentCarIndex, // Holds the index in the ABuyableVehicles array which vehicle the player chose to rent
	DialogBuyVClass, // Holds the ID of the chose vehicle class to process when buying a vehicle
	DialogBuyCarIndex, // Holds the index in the ABuyableVehicles array which vehicle the player chose to buy

	DialogGetCarHouseID, // Holds the HouseID from which to get a vehicle when using /getcar

	DialogOtherPlayer, // Holds the id of the other player when viewing that other player's stats
	DialogOtherPlayerHouse, // Holds the HouseID of the other player when viewing the stats for that house

	BankPassword[24], // Bank-system: Used to hold the password to your bank-account
	bool:BankLoggedIn, // Bank-system: Used to determine if you have logged in to your bank account
	BankMoney, // Bank-system: Used to hold the money in your bank-account
	UseMoney, // Bank-system: Used to hold the money you're be transferring to another player's account
	LastIntrestTime, // Bank-system: Used to hold the last time where your bank account has received intrest

	RentedVehicleID // Holds the vehicle-id of the rented vehicle (if any)
}
new APlayerData[MAX_PLAYERS][TPlayerData];

new CurrentIntrestTime;

enum TSpawnLocation
{
	Float:SpawnX,
	Float:SpawnY,
	Float:SpawnZ,
	Float:SpawnAngle
}
// Setup spawnlocations for each class (when selecting "Spawn" at class-selection, a random spawnlocation is selected)
new ASpawnLocationsTrucker[][TSpawnLocation] =
{
	{-525.0, -502.0, 26.0, 0.0}, // Fallen Tree Depot
	{-74.7, -1137.5, 4.5, 0.0}, // Flint Trucking Depot
	{1457.0, 975.5, 11.0, 0.0}, // LVA Freight Depot
	{-2136.0, -247.5, 36.5, 270.0}, // Doherty Depot
	{1766.5, -2040.7, 14.0, 270.0}, // El Corona Depot
	{-546.0, 2594.0, 54.0, 270.0}, // Las Payasdas Depot
	{332.0, 900.0, 25.0, 205.0}, // Quarry Top
	{-1575.0, -2724.0, 49.0, 146.0}, // Shady Creek Depot
    {638.1984, 1683.8347, 6.9922, 36.2610} //Posto LV 
};
new ASpawnLocationsBusDriver[][TSpawnLocation] =
{
	{1809.0, -1905.0, 13.6, 90.0}, // Los Santos busdepot
	{-1983.0, 110.0, 27.7, 180.0}, // San Fierro busdepot
	{1060.0, 1260.0, 11.0, 270.0} // Las Venturas busdepot
};
new ASpawnLocationsPilot[][TSpawnLocation] =
{
	{2010.0, -2345.0, 13.6, 90.0}, // Los Santos airport
	{-1211.0, -105.0, 14.2, 135.0}, // San Fierro airport
	{1630.0, 1615.0, 10.9, 90.0} // Las Venturas airport
};
new ASpawnLocationsPolice[][TSpawnLocation] =
{
	{1568.5, -1693.5, 6.0, 180.0}, // Los Santos police station
	{-1590.0, 716.25, -5.0, 270.0}, // San Fierro police station
	{2275.0, 2460.0, 10.9, 90.0} // Las Venturas police station
};
new ASpawnLocationsMafia[][TSpawnLocation] =
{
	{2822.5, 898.5, 10.8, 0.0} // Mafia hideout
};
new ASpawnLocationsCourier[][TSpawnLocation] =
{
	{798.0, -618.75, 16.4, 0.0}, // Los Santos
	{-1849.25, -135.0, 12.0, 90.0}, // San Fierro
	{1050.5, 1931.0, 10.9, 270.0} // Las Venturas
};
new ASpawnLocationsAssistance[][TSpawnLocation] =
{
	{211.25, 24.75, 2.6, 270.0}
};
new ASpawnLocationsRoadWorker[][TSpawnLocation] =
{
	{-1866.25, -1715.25, 22.7, 125.0} // Junkyard
};

new AVehicleModPrices[] =
{
	400, // ID 1000, Spoiler Pro								Certain Transfender cars
	550, // ID 1001, Spoiler Win								Certain Transfender cars
	200, // ID 1002, Spoiler Drag								Certain Transfender cars
	250, // ID 1003, Spoiler Alpha								Certain Transfender cars
	100, // ID 1004, Hood Champ Scoop							Certain Transfender cars
	150, // ID 1005, Hood Fury Scoop							Certain Transfender cars
	80, // ID 1006, Roof Roof Scoop								Certain Transfender cars
	500, // ID 1007, Sideskirt Right Sideskirt					Certain Transfender cars
	500, // ID 1008, Nitro 5 times								Most cars, Most planes and Most Helicopters
	200, // ID 1009, Nitro 2 times								Most cars, Most planes and Most Helicopters
	1000, // ID 1010, Nitro 10 times                 			Most cars, Most planes and Most Helicopters
	220, // ID 1011, Hood Race Scoop                			Certain Transfender cars
	250, // ID 1012, Hood Worx Scoop                			Certain Transfender cars
	100, // ID 1013, Lamps Round Fog                			Certain Transfender cars
	400, // ID 1014, Spoiler Champ                  			Certain Transfender cars
	500, // ID 1015, Spoiler Race                   			Certain Transfender cars
	200, // ID 1016, Spoiler Worx                   			Certain Transfender cars
	500, // ID 1017, Sideskirt Left Sideskirt       			Certain Transfender cars
	350, // ID 1018, Exhaust Upswept                			Most cars
	300, // ID 1019, Exhaust Twin                   			Most cars
	250, // ID 1020, Exhaust Large                  			Most cars
	200, // ID 1021, Exhaust Medium								Most cars
	150, // ID 1022, Exhaust Small								Most cars
	350, // ID 1023, Spoiler Fury                   			Certain Transfender cars
	50, // ID 1024, Lamps Square Fog							Certain Transfender cars
	1000, // ID 1025, Wheels Offroad							Certain Transfender cars
	480, // ID 1026, Sideskirt Right Alien Sideskirt			Sultan
	480, // ID 1027, Sideskirt Left Alien Sideskirt				Sultan
	770, // ID 1028, Exhaust Alien                      		Sultan
	680, // ID 1029, Exhaust X-Flow								Sultan
	370, // ID 1030, Sideskirt Left X-Flow Sideskirt    		Sultan
	370, // ID 1031, Sideskirt Right X-Flow Sideskirt   		Sultan
	170, // ID 1032, Roof Alien Roof Vent						Sultan
	120, // ID 1033, Roof X-Flow Roof Vent              		Sultan
	790, // ID 1034, Exhaust Alien								Elegy
	150, // ID 1035, Roof X-Flow Roof Vent						Elegy
	500, // ID 1036, SideSkirt Right Alien Sideskirt    		Elegy
	690, // ID 1037, Exhaust X-Flow								Elegy
	190, // ID 1038, Roof Alien Roof Vent						Elegy
	390, // ID 1039, SideSkirt Right X-Flow Sideskirt   		Elegy
	500, // ID 1040, SideSkirt Left Alien Sideskirt				Elegy
	390, // ID 1041, SideSkirt Right X-Flow Sideskirt   		Elegy
	1000, // ID 1042, SideSkirt Right Chrome Sideskirt			Broadway
	500, // ID 1043, Exhaust Slamin                     		Broadway
	500, // ID 1044, Exhaust Chrome								Broadway
	510, // ID 1045, Exhaust X-Flow								Flash
	710, // ID 1046, Exhaust Alien								Flash
	670, // ID 1047, SideSkirt Right Alien Sideskirt    		Flash
	530, // ID 1048, SideSkirt Right X-Flow Sideskirt			Flash
	810, // ID 1049, Spoiler Alien								Flash
	620, // ID 1050, Spoiler X-Flow                     		Flash
	670, // ID 1051, SideSkirt Left Alien Sideskirt     		Flash
	530, // ID 1052, SideSkirt Left X-Flow Sideskirt			Flash
	130, // ID 1053, Roof X-Flow								Flash
	210, // ID 1054, Roof Alien									Flash
	230, // ID 1055, Roof Alien									Stratum
	520, // ID 1056, Sideskirt Right Alien Sideskirt			Stratum
	430, // ID 1057, Sideskirt Right X-Flow Sideskirt			Stratum
	620, // ID 1058, Spoiler Alien								Stratum
	720, // ID 1059, Exhaust X-Flow								Stratum
	530, // ID 1060, Spoiler X-Flow								Stratum
	180, // ID 1061, Roof X-Flow								Stratum
	520, // ID 1062, Sideskirt Left Alien Sideskirt				Stratum
	430, // ID 1063, Sideskirt Left X-Flow Sideskirt			Stratum
	830, // ID 1064, Exhaust Alien								Stratum
	850, // ID 1065, Exhaust Alien								Jester
	750, // ID 1066, Exhaust X-Flow								Jester
	250, // ID 1067, Roof Alien									Jester
	200, // ID 1068, Roof X-Flow								Jester
	550, // ID 1069, Sideskirt Right Alien Sideskirt			Jester
	450, // ID 1070, Sideskirt Right X-Flow Sideskirt			Jester
	550, // ID 1071, Sideskirt Left Alien Sideskirt				Jester
	450, // ID 1072, Sideskirt Left X-Flow Sideskirt			Jester
	1100, // ID 1073, Wheels Shadow								Most cars
	1030, // ID 1074, Wheels Mega								Most cars
	980, // ID 1075, Wheels Rimshine							Most cars
	1560, // ID 1076, Wheels Wires								Most cars
	1620, // ID 1077, Wheels Classic							Most cars
	1200, // ID 1078, Wheels Twist								Most cars
	1030, // ID 1079, Wheels Cutter								Most cars
	900, // ID 1080, Wheels Switch								Most cars
	1230, // ID 1081, Wheels Grove								Most cars
	820, // ID 1082, Wheels Import								Most cars
	1560, // ID 1083, Wheels Dollar								Most cars
	1350, // ID 1084, Wheels Trance								Most cars
	770, // ID 1085, Wheels Atomic								Most cars
	100, // ID 1086, Stereo Stereo								Most cars
	1500, // ID 1087, Hydraulics Hydraulics						Most cars
	150, // ID 1088, Roof Alien									Uranus
	650, // ID 1089, Exhaust X-Flow								Uranus
	450, // ID 1090, Sideskirt Right Alien Sideskirt			Uranus
	100, // ID 1091, Roof X-Flow								Uranus
	750, // ID 1092, Exhaust Alien								Uranus
	350, // ID 1093, Sideskirt Right X-Flow Sideskirt			Uranus
	450, // ID 1094, Sideskirt Left Alien Sideskirt				Uranus
	350, // ID 1095, Sideskirt Right X-Flow Sideskirt			Uranus
	1000, // ID 1096, Wheels Ahab								Most cars
	620, // ID 1097, Wheels Virtual								Most cars
	1140, // ID 1098, Wheels Access								Most cars
	1000, // ID 1099, Sideskirt Left Chrome Sideskirt			Broadway
	940, // ID 1100, Bullbar Chrome Grill						Remington
	780, // ID 1101, Sideskirt Left `Chrome Flames` Sideskirt	Remington
	830, // ID 1102, Sideskirt Left `Chrome Strip` Sideskirt	Savanna
	3250, // ID 1103, Roof Convertible							Blade
	1610, // ID 1104, Exhaust Chrome							Blade
	1540, // ID 1105, Exhaust Slamin							Blade
	780, // ID 1106, Sideskirt Right `Chrome Arches`			Remington
	780, // ID 1107, Sideskirt Left `Chrome Strip` Sideskirt	Blade
	780, // ID 1108, Sideskirt Right `Chrome Strip` Sideskirt	Blade
	1610, // ID 1109, Rear Bullbars Chrome						Slamvan
	1540, // ID 1110, Rear Bullbars Slamin						Slamvan
	55, // ID 1111, Front Sign? Little Sign?					Slamvan         ???
	55, // ID 1112, Front Sign? Little Sign?					Slamvan         ???
	3340, // ID 1113, Exhaust Chrome							Slamvan
	3250, // ID 1114, Exhaust Slamin							Slamvan
	2130, // ID 1115, Front Bullbars Chrome						Slamvan
	2050, // ID 1116, Front Bullbars Slamin						Slamvan
	2040, // ID 1117, Front Bumper Chrome						Slamvan
	780, // ID 1118, Sideskirt Right `Chrome Trim` Sideskirt	Slamvan
	940, // ID 1119, Sideskirt Right `Wheelcovers` Sideskirt	Slamvan
	780, // ID 1120, Sideskirt Left `Chrome Trim` Sideskirt		Slamvan
	940, // ID 1121, Sideskirt Left `Wheelcovers` Sideskirt		Slamvan
	780, // ID 1122, Sideskirt Right `Chrome Flames` Sideskirt	Remington
	860, // ID 1123, Bullbars Bullbar Chrome Bars				Remington
	780, // ID 1124, Sideskirt Left `Chrome Arches` Sideskirt	Remington
	1120, // ID 1125, Bullbars Bullbar Chrome Lights			Remington
	3340, // ID 1126, Exhaust Chrome Exhaust					Remington
	3250, // ID 1127, Exhaust Slamin Exhaust					Remington
	3340, // ID 1128, Roof Vinyl Hardtop						Blade
	1650, // ID 1129, Exhaust Chrome							Savanna
	3380, // ID 1130, Roof Hardtop								Savanna
	3290, // ID 1131, Roof Softtop								Savanna
	1590, // ID 1132, Exhaust Slamin							Savanna
	830, // ID 1133, Sideskirt Right `Chrome Strip` Sideskirt	Savanna
	800, // ID 1134, SideSkirt Right `Chrome Strip` Sideskirt	Tornado
	1500, // ID 1135, Exhaust Slamin							Tornado
	1000, // ID 1136, Exhaust Chrome							Tornado
	800, // ID 1137, Sideskirt Left `Chrome Strip` Sideskirt	Tornado
	580, // ID 1138, Spoiler Alien								Sultan
	470, // ID 1139, Spoiler X-Flow								Sultan
	870, // ID 1140, Rear Bumper X-Flow							Sultan
	980, // ID 1141, Rear Bumper Alien							Sultan
	150, // ID 1142, Vents Left Oval Vents						Certain Transfender Cars
	150, // ID 1143, Vents Right Oval Vents						Certain Transfender Cars
	100, // ID 1144, Vents Left Square Vents					Certain Transfender Cars
	100, // ID 1145, Vents Right Square Vents					Certain Transfender Cars
	490, // ID 1146, Spoiler X-Flow								Elegy
	600, // ID 1147, Spoiler Alien								Elegy
	890, // ID 1148, Rear Bumper X-Flow							Elegy
	1000, // ID 1149, Rear Bumper Alien							Elegy
	1090, // ID 1150, Rear Bumper Alien							Flash
	840, // ID 1151, Rear Bumper X-Flow							Flash
	910, // ID 1152, Front Bumper X-Flow						Flash
	1200, // ID 1153, Front Bumper Alien						Flash
	1030, // ID 1154, Rear Bumper Alien							Stratum
	1030, // ID 1155, Front Bumper Alien						Stratum
	920, // ID 1156, Rear Bumper X-Flow							Stratum
	930, // ID 1157, Front Bumper X-Flow						Stratum
	550, // ID 1158, Spoiler X-Flow								Jester
	1050, // ID 1159, Rear Bumper Alien							Jester
	1050, // ID 1160, Front Bumper Alien						Jester
	950, // ID 1161, Rear Bumper X-Flow							Jester
	650, // ID 1162, Spoiler Alien								Jester
	450, // ID 1163, Spoiler X-Flow								Uranus
	550, // ID 1164, Spoiler Alien								Uranus
	850, // ID 1165, Front Bumper X-Flow						Uranus
	950, // ID 1166, Front Bumper Alien							Uranus
	850, // ID 1167, Rear Bumper X-Flow							Uranus
	950, // ID 1168, Rear Bumper Alien							Uranus
	970, // ID 1169, Front Bumper Alien							Sultan
	880, // ID 1170, Front Bumper X-Flow						Sultan
	990, // ID 1171, Front Bumper Alien							Elegy
	900, // ID 1172, Front Bumper X-Flow						Elegy
	950, // ID 1173, Front Bumper X-Flow						Jester
	1000, // ID 1174, Front Bumper Chrome						Broadway
	900, // ID 1175, Front Bumper Slamin						Broadway
	1000, // ID 1176, Rear Bumper Chrome						Broadway
	900, // ID 1177, Rear Bumper Slamin							Broadway
	2050, // ID 1178, Rear Bumper Slamin						Remington
	2150, // ID 1179, Front Bumper Chrome						Remington
	2130, // ID 1180, Rear Bumper Chrome						Remington
	2050, // ID 1181, Front Bumper Slamin						Blade
	2130, // ID 1182, Front Bumper Chrome						Blade
	2040, // ID 1183, Rear Bumper Slamin						Blade
	2150, // ID 1184, Rear Bumper Chrome						Blade
	2040, // ID 1185, Front Bumper Slamin						Remington
	2095, // ID 1186, Rear Bumper Slamin						Savanna
	2175, // ID 1187, Rear Bumper Chrome						Savanna
	2080, // ID 1188, Front Bumper Slamin						Savanna
	2200, // ID 1189, Front Bumper Chrome						Savanna
	1200, // ID 1190, Front Bumper Slamin						Tornado
	1040, // ID 1191, Front Bumper Chrome						Tornado
	940, // ID 1192, Rear Bumper Chrome							Tornado
	1100, // ID 1193 Rear Bumper Slamin							Tornado
};

enum TCommands
{
	CommandLevel, // Holds the admin-level required to execute this command
	CommandStructure[128], // Holds the command-structure
	CommandDescription[128] // Holds the description of the command
}
new ACommands[][TCommands] =
{                                                                       
	{0, "/reparar",                                                     "Use o comando em uma oficina para reparar o veículo."},//OK
    {0, "/neon",                                                        "Use o comando em uma oficina para instalar neon."},//OK      
    {0, "/equipe",                                                      "Mostra os responsáveis do server."},//OK  
    {0, "/radio",                                                       "Ouvir músicas"},
    {0, "/novidades",                                   				"Para ver as novidades do servidor."},//OK
	{0, "/assistencia",                                   				"Para chamar um mecanico"},
	{0, "/banco",                                   					"Registrar, logar e administrar sua conta bancaria"},
	{0, "/menuempresa",                                   				"Mostra as opcoes de administracao da sua empresa"},
	{0, "/comprarempresa",                                   			"Compra empresa (deve-se estar encima do pickup)"},
	{0, "/comprarcasa",                                   				"Compra casa (deve-se estar encima do pickup)"},
	{0, "/mudarsenha",                                   			    "Mudar sua senha"},
    {0, "/ouvir",                                                       "Ouvir a música de abertura"},
	{0, "/comandos",                                   					"Displays all the commands"},
	{0, "/cor1",														"Altera a cor primária do seu veículo."},//OK
	{0, "/cor2",														"Altera a cor secundária do seu veículo."},//OK
	{0, "/comboio",                                   					"Lets you start or join a convoy"},
	{0, "/conboiocancelar",                                   			"Cancels the convoy you're in"},
	{0, "/comboiokick [id]",        									"Kicks a member from the convoy"},
	{0, "/conboiosair",                                   				"You leave the convoy"},
	{0, "/comboiomembros",                                   		    "Displays all convoy members"},
	{0, "/desatrelar",                                   				"Detaches your trailer"},
	{0, "/entrar",                                   					"Enter your business or house"},
	{0, "/virar",                                   					"Flips your vehicle back onto it's wheels"},
	{0, "/usarcarro",                                   				"Teleports a house-car to your location"},
	{0, "/dardinheiro <OtherPlayer> <Money>",                           "Give money to another player"},
	{0, "/irempresa",                                   				"Teleport to a business you own"},
	{0, "/irparacasa",                                   				"Teleport to a house you own"},
	{0, "/ajuda",                                   					"Get help information about a specific topic"},
	{0, "/menucasa",                                   			    	"Displays the menu for controlling your house"},
	{0, "/morrer",                                   					"Kill yourself"},
	{0, "/eu <action>",													"removido"},
	{0, "/sobrecarga",                                   				"Lets a trucker to overload his vehicle"},
	{0, "/pintura [paintjob(0-2)]",                                     "Aplica uma pintura no veículo de seu domínio"},//OK
	{0, "/estacionar",                                   				"Park your vehicle where it's standing now"},
	{0, "/pm [id] [messagem]",                                  		"Enviar uma mensagem privada a outro jogador."},//OK
	{0, "/mudar",                                   					"Choose another class"},
	{0, "/alugarcarro",                                   				"Rent a car from a cardealer"},
	{0, "/relato <OtherPlayer> <Your report>",                          "Report a player for breaking the rules"},
	{0, "/resgate",                                   					"Teleports you to a location where your class starts"},
	{0, "/regras",                                   					"Display the rules and get a small gift (only once)"},
	{0, "/cv <message>",                                   		    	"Say something to players that have same class as you"},
	{0, "/tapete",                                   					"Creates a spikestrip (can only be used by cops)"},
	{0, "/status",                                   					"Displays statistics about yourself"},
	{0, "/cancelar",                                   					"Ends the current job"},
	{0, "/liberar",                                   					"Allows a player to un-clamp his vehicles for a price"},
	{0, "/trabalhar",													"Starts a job"},
	{1, "/a <menssagem>",                                   			"Chat de admin"},
    {1, "/tapa [id]",                              	            		"Para dar um tapa em alguém."},//OK    
    {1, "/tapao [id]",                                 		        	"Para dar um tapão em alguém."},//OK
	{1, "/motos",                                   					"Cria uma moto ou bike"},
	{1, "/barcos",                                   					"Cria um barco"},
	{1, "/carros",                                   					"Cria um carro"},
	{1, "/pararespiar",                                   				"Para de espiar"},
	{1, "/motor <(0/1)>",                                               "Liga ou desliga o motor"},
	{1, "/congelar <ID> <Tempo> <Motivo>",                              "Congela o jogador por um certo tempo em segundos"},
	{1, "/combustivel",                                                 "Para abastecer o veiculo em que esta"},
    {1, "/fogo [id]",                                                   "Para queimar alguém."},//OK       
    {1, "/idcasa",                                                      "Para ver o id da casa"},
	{1, "/trazer <ID>",                                   	        	"Teleports another player to your location"},
	{1, "/prender <ID> <Tempo> <Motivo>",                               "Jails another player for a certain time in seconds"},
	{1, "/kick <ID> <Motivo>",                                          "Kick a player"},
	{1, "/calar <ID> <Motivo>",                                         "Mute a player"},
	{1, "/mudos",                                   					"Ve quem está mudo"},
	{1, "/nos",                                   						"Add nitro no seu veiculo"},
	{1, "/plane",                                   					"Cria um aviao"},
	{1, "/ir <ID>",                                   	    	        "Te leva ate um jogador"},
	{1, "/portloc <x> <y> <z>",                                   		"Besteira"},
	{1, "/portvehicle <CarID>",                                   		"Besteira"},
	{1, "/relatorio",                                   				"Mostra os 50 ultimos relatorios enviados a staff"},
	{1, "/reparar",                                   					"Repara seu veiculo"},
	{1, "/respawn <ID-CARRO>",                                   		"Respawna o carro"},
	{1, "/espiar <ID>",                                   	        	"Voce espia um jogador"},
	{1, "/levar <ID-Alvo> <ID-Destino>",                                "Leva um jogador a outro jogador"},
	{1, "/trailer",                                   					"Cria um trailer"},
	{1, "/descalar <ID>",                                       		"Descala alguem"},
	{1, "/aviso <ID> <Motivo>",                                         "Avisa um jogador"},
    {2, "/setint [id] [interior]",                                      "Seta um interior a um jogador."},//OK    
    {2, "/limparchat",                                                   "Limpa o histórico de conversação. (chat)"},//OK
	{2, "/ejetar <OtherPlayer>",                                   		"Ejects a player from his vehicle"},
	{2, "/procurado <PlayerID> <Stars>",                                "Set a player's wanted level"},
    {2, "/limparchat",                                                  "Para limpar o chat"},
	{3, "/ban <PlayerToBan> <Days> <Hours> <Reason>",                   "Ban a player for a certain time"},
	{3, "/painel",                                   			    	"Changes some options for your vehicle"},
	{3, "/limparcarros",                                   				"Removes all spawned vehicles from the map"},
	{3, "/fly",                                   						"Equips yourself with a jetpack"},
	{3, "/darvidatodos",                                   				"Heals all the players"},
	{3, "/banip [id] [Motivo]",                   			        	"Bane o IP do jogador"},
	{3, "/loc",                                   						"Display your current location"},
	{3, "/editarplaca <NumberPlate>",                                   "Changes the plate on your vehicle"},
	{3, "/banirfaixa [ID] [Motivo]",                   		        	"Bane toda a faixa de IP"},
	{3, "/reparartodos",                                   				"Repair all vehicles for free"},
	{3, "/desbanir <PlayerToUnban>",                                   	"Unban a player"},
    {3, "/clima",                                      					"Changes the weather"},
	{4, "/setskin <skin-id (0-299)>",                                   "Lets an admin choose another skin"},
    {5, "/desabilitarchat",                                             "Para calar todos exeto os admins maiores de 3"},
    {5, "/habilitarchat",                                               "Para ativar o chat"}, 
    {5, "/dinheiro <amount>",                                   		"Give cash to yourself"},
	{5, "/criarempresa",                                   		     	"Create a business at your location"},
	{5, "/criarcasa <price> <maxlevel (1-10)>",                  		"Create a new house"},
	{5, "/deletarempresa",                                   			"Delete a business"},
	{5, "/deletarcasa",                                   				"Delete a house"},
	{5, "/gmx",                                   				    	"GMX"},
	{5, "/saveloc <ID> <LocationName>",                                 "Saves your location to a file"},
    {6, "/deletarradar",                                   				"Delete a speedcamera"},
	{6, "/apreender <vehicleid> <reason>",                              "Delete a player-owned vehicle"},
	{6, "/corrigirjogador",                                             "Para restaurar casas e empresas de um jogador"},
	{6, "/score <amount>",                                   			"Give scorepoints to yourself"},
	{6, "/darscore <OtherPlayer> <Score>",                              "Sets another player's score to the given value"},
	{6, "/delobject <ObjectID>",                                   		"Besteira"},
	{6, "/fixplayer <OtherPlayer>",										"Fix a player's property (re-add his houses and buinesses)"},
	{6, "/object <ObjectModel> <x> <y> <z> <Angle>",                    "Create an object"},
	{6, "/pickup <PickupModel> <x> <y> <z> <PickupType>",               "Create a pickup"},
	{6, "/resetarconta <OtherPlayer> <Money (0/1)> <Score (0/1)> <Stats (0/1)> <Reason>",	"Reseta a conta do cara"},
	{6, "/criarradar <max_speed>",                                   	"Create s speedcamera at your location"},
	{6, "/daradmin <ID> <AdminLevel>",                                  "Da admin"}
};



// Help text stuff
#define HelpIDTruckingClass     0 // Defines the ID for getting help about the trucking class
#define HelpIDBusDriverClass    1 // Defines the ID for getting help about the busdriver class
#define HelpIDMafiaClass    	2 // Defines the ID for getting help about the mafia class
#define HelpIDPoliceClass    	3 // Defines the ID for getting help about the police class
#define HelpIDPilotClass    	4 // Defines the ID for getting help about the pilot class
#define HelpIDCourierClass    	5 // Defines the ID for getting help about the courier class
#define HelpIDAssistanceClass   6 // Defines the ID for getting help about the assistance class
#define HelpIDRoadworkerClass   7 // Defines the ID for getting help about the roadworker class
#define HelpIDConvoy            8 // Defines the ID for getting help about convoys
#define HelpIDBonusMissions     9 // Defines the ID for getting help about bonus missions
#define HelpIDHouses            10 // Defines the ID for getting help about the houses
#define HelpIDInsurance         11 // Defines the ID for getting help about insurance
#define HelpIDBuyingVehicles    12 // Defines the ID for getting help about buying vehicles
#define HelpIDRentingVehicles   13 // Defines the ID for getting help about renting vehicles
#define HelpIDBusinesses   		14 // Defines the ID for getting help about businesses

// Define the topics for the help menu
new AHelpTopics[][50] =
{
	{"Caminhoneiro"},
	{"Motorista de Ônibus"},
	{"Mafia"},
	{"Policia"},
	{"Piloto de Avião"},
	{"Agente dos Correios"},
	{"Mecânico"},
	{"DNIT"},
	{"Comboios"},
	{"Missões Bonus"},
	{"Casas"},
	{"Seguro"},
	{"Comprando carros"},
	{"Alugando Carros"},
	{"Empresas"}
};
// Setup a custom type that holds all text-lines for all help-topics
enum THelpItem
{
	HelpID, // Holds the item for which to get help-info
	HelpText[128] // Contains one line for the help-info, every help-item can use multiple lines
}
// This array holds the texts for the /help command
new AHelpText[][THelpItem] =
{
	{HelpIDTruckingClass, "Usando a classe de caminhoneiro, seu trabalho é transportar produtos de um local para outro."},
	{HelpIDTruckingClass, "Para isso, Use um caminhão (FlatBet, DFT-30, LineRunner, Tanker ou Roadtrain) e digite o comando /trabalhar."},
	{HelpIDTruckingClass, "Para os caminhões Tanker linerunner, ou Roadtrain, você vai precisar de um reboque para iniciar um trabalho."},
	{HelpIDTruckingClass, "Quando o trabalho for iniciado, você verá um marcador vermelho no mapa. Esse é o local onde você deve buscar sua carga."},
	{HelpIDTruckingClass, "Quando você chegar a esse local, os produtos serão transferidos para o seu veículo."},
	{HelpIDTruckingClass, "Em seguida, será mostrado o local onde você deverá descarregar os produtos."},
	{HelpIDTruckingClass, "Se você chegar ao destino, os produtos são descarregados e você irá receber 1 score e o valor do frete."},
	{HelpIDTruckingClass, "O pagamento depende da distância entre os pontos de carga e descarga."},
	{HelpIDTruckingClass, " "},
	{HelpIDTruckingClass, "Alguns produtos podem ser procurados pela máfia. Se você tiver esses produtos carregados em seu veículo, a máfia é informada"},
	{HelpIDTruckingClass, "e eles vão persegui-lo para roubar seu veículo ou reboque, por isso tome cuidado."},
	{HelpIDTruckingClass, "Ao realizar a entrega de uma carga máfia no seu destino com sucesso, você ganha um bônus extra."},
	{HelpIDTruckingClass, " "},
	{HelpIDTruckingClass, "Há também a chance do seu veículo poder ser sobrecarregado. Quando isso acontece, a polícia é informada."},
	{HelpIDTruckingClass, "Sendo sobrecarregado você ganha recompensa de bônus extra, se você chegar ao destino."},
	{HelpIDTruckingClass, " "},
	{HelpIDTruckingClass, "Você também terá um pequeno bônus se você transportar os produtos utilizando o seu próprio caminhão."},
	{HelpIDTruckingClass, " "},
	{HelpIDTruckingClass, "Você também pode comprar uma licença de transporte rodoviário, perto da escola de condução em Doherty, San Fierro."},
	{HelpIDTruckingClass, "Isso permitirá que você escolha seu próprio produto, o ponto de carga e descarga ponto para um trabalho."},
	{HelpIDTruckingClass, " "},
	{HelpIDTruckingClass, "Caminhoneiros também pode criar e juntar-se aos comboios."},
	{HelpIDTruckingClass, "Veja o tópico 'Comboios' para obter mais informações sobre eles."},

	{HelpIDBusDriverClass, "Usando a classe motorista do ônibus, seu trabalho é transportar passageiros entre várias paradas de ônibus."},
	{HelpIDBusDriverClass, "Para iniciar um trabalho, entre em um ônibus e use o comando /trabalhar para iniciar um trabalho."},
	{HelpIDBusDriverClass, "Você ser informado a você o primeiro ponto de ônibus como um marcador vermelho no seu mapa."},
	{HelpIDBusDriverClass, "Vá para esse local para carregar seu primeiros passageiros."},
	{HelpIDBusDriverClass, " "},
	{HelpIDBusDriverClass, "Enquanto o onibus estiver pessoas mas não descer, você nao vai ter nenhum pagamento."},
	{HelpIDBusDriverClass, "A partir da segunda paragem, uma quantidade aleatória de passageiros descerá do seu ônibus."},
	{HelpIDBusDriverClass, "Para cada passageiro que sai seu ônibus, você vai receber."},
	{HelpIDBusDriverClass, " "},
	{HelpIDBusDriverClass, "Se você tiver concluído a rota de ônibus inteira, é mostrado a localização do terminal rodoviário."},
	{HelpIDBusDriverClass, "Agora você pode escolher para fazer a rota de ônibus novamente, indo para a primeira parada de ônibus"},
	{HelpIDBusDriverClass, "ou para terminar a rota de ônibus indo para a garagem."},

	{HelpIDMafiaClass, "Usando a classe mafia, seu trabalho é transportar produtos de um local para outro."},
	{HelpIDMafiaClass, "Para trabalhar , esteja em um Sandking ou Moonbeam e use o comando /trabalhar."},
	{HelpIDMafiaClass, "Isto funciona quase da mesma maneira como a classe caminhoneiro."},
	{HelpIDMafiaClass, "Mafia não pode ser sobrecarregado, e você não pode ter mafia cargas."},
	{HelpIDMafiaClass, "Em vez disso, cada trabalho informa a polícia. Você vai ter um nível de procurado de 4 estrelas."},
	{HelpIDMafiaClass, " "},
	{HelpIDMafiaClass, "Uma segunda possibilidade para a máfia de ganhar dinheiro é para roubar as queridas cargas dos caminhoneiros."},
	{HelpIDMafiaClass, "Quando um motorista de caminhão com tal carga a bordo está dirigindo ao redor, você será informado."},
	{HelpIDMafiaClass, "O caminhoneiro vai aparecer como um ponto vermelho em seu radar. Agora você tem que perseguir caminhoneiro roubar a carga."},
	{HelpIDMafiaClass, "Se o motorista está em um FlatBet ou DFT-30, em sua carga a bordo do caminhão, então você vai ter que forçar o caminhoneiro"},
	{HelpIDMafiaClass, "a sair fora de seu veículo para roubá-la."},
	{HelpIDMafiaClass, "Se o motorista está dirigindo um caminhão com reboque, você terá que roubar o trailer."},
	{HelpIDMafiaClass, "Também é possível roubar o caminhão com o reboque ligado a ele."},
	{HelpIDMafiaClass, " "},
	{HelpIDMafiaClass, "A partir do momento que você conseguir separar reboque do caminhoneiro, você tem 60 segundos para pegar a carga."},
	{HelpIDMafiaClass, "Se você não fizer isso, a missão do caminhoneiro falha e a carga é perdida."},
	{HelpIDMafiaClass, "Se você conseguir roubar carga do caminhoneiro, leve-o ao esconderijo da máfia para entregar a carga."},
	{HelpIDMafiaClass, "Quando chegar ao esconderijo da máfia com a carga roubada, você vai receber."},

	{HelpIDPoliceClass, "Usando a classe policial, seu trabalho é multar ou prender eventuais infractores da lei."},
	{HelpIDPoliceClass, "Quando um caminhoneiro está sobrecarregado, ele vai ter 2 estrelas em seu nível de procurado."},
	{HelpIDPoliceClass, "A mafia fazendo um trabalho, recebe 4 estrelas em seu nível de procurado."},
	{HelpIDPoliceClass, "Qualquer excesso de velocidade perto de um radar recebe uma estrela extra em seu nível de procurado."},
	{HelpIDPoliceClass, " "},
	{HelpIDPoliceClass, "Qualquer jogador com um nível de procurado aparece como um ponto vermelho em seu radar."},
	{HelpIDPoliceClass, "Você precisa perseguir o jogador e tentar pará-lo, assim você pode multá-lo."},
	{HelpIDPoliceClass, "Quando você chegar perto do jogador, você pode usar o botão LCTRL no seu teclado para avisá-los."},
	{HelpIDPoliceClass, "O jogador queria será informado que ele está sendo perseguido pela polícia e que ele precisa encostar."},
	{HelpIDPoliceClass, " "},
	{HelpIDPoliceClass, "Se o jogador parar imediatamente, você só pode multá-lo, usando o botão direito do mouse."},
	{HelpIDPoliceClass, "Você precisa estar a pé para multar o infractor."},
	{HelpIDPoliceClass, "Se o jogador não parar dentro de 60 segundos, ele vai ser enviado para a cadeia se você pegá-lo."},
	{HelpIDPoliceClass, "Este receberá também o dobro da multa."},

	{HelpIDPilotClass, "Quando você escolhe a classe piloto, seu trabalho é transportar passageiros ou carga de um local para outro."},
	{HelpIDPilotClass, "Para iniciar um trabalho, esteja em um Shamal Nevada ou avião e use o /trabalhar."},
	{HelpIDPilotClass, "Aviões transportam passageiros ou carga."},
	{HelpIDPilotClass, "Os pilotos também pode usar helicópteros. Esteja em um Maverick ou helicóptero Cargobob para iniciar um trabalho."},
	{HelpIDPilotClass, "Helicopteros transportam somente passageiros."},

	{HelpIDCourierClass, "Se você escolher a classe de correio, seu trabalho é entregar pacotes para casas dos jogadores."},
	{HelpIDCourierClass, "Para iniciar um trabalho, use uma Van Burrito ou Faggio e use o /trabalhar."},
	{HelpIDCourierClass, "Em seguida, você pode escolher quantos pacotes você deseja entregar."},
	{HelpIDCourierClass, " "},
	{HelpIDCourierClass, "As casas dos jogadores são escolhidas aleatoriamente em um determinado intervalo."},
	{HelpIDCourierClass, "Se não há casas de propriedade na vizinhança, você será notificado para procurar outra área para trabalhar em."},
	{HelpIDCourierClass, " "},
	{HelpIDCourierClass, "Quando você chegar a casa, saia de seu veículo e entregue o pacote à porta da casa."},
	{HelpIDCourierClass, "Quando todos os pacotes são entregues, você será pago a quantidade de pacotes que você entregou."},

	{HelpIDAssistanceClass, "Se você escolher a classe de assistência, seu trabalho é ajudar os jogadores quando eles estão sem combustível"},
	{HelpIDAssistanceClass, "ou com o veiculo danificado."},
	{HelpIDAssistanceClass, "Jogadores que precisam de ajuda dos mecânicos podem usar o comando /assistencia para pedir ajuda."},
	{HelpIDAssistanceClass, "Todos os jogadores que necessitam de assistência são marcadas a vermelho no radar."},
	{HelpIDAssistanceClass, " "},
	{HelpIDAssistanceClass, "O Mecanico deve ir a assistência para o jogador que precisa de ajuda e ajudá-los."},
	{HelpIDAssistanceClass, "Você pode ajudá-los a sair de seu veículo usando o botão direito do mouse"},
	{HelpIDAssistanceClass, "quando você está perto de seu veículo."},
	{HelpIDAssistanceClass, " "},
	{HelpIDAssistanceClass, "Você não pode aleatoriamente reparar e reabastecer os veículos de outros jogadores, se não for pedido."},

	{HelpIDRoadworkerClass, "O DNIT tem dois tipos de trabalho diferentes."},
	{HelpIDRoadworkerClass, " "},
	{HelpIDRoadworkerClass, "O primeiro é fazer manutenção nos radares que foram colocados ao redor do mapa."},
	{HelpIDRoadworkerClass, "Use um Ultility Van com um Utility Trailer ligado a ele e use o /trabalhar comando para iniciar um trabalho."},
	{HelpIDRoadworkerClass, "Va para o radár indicada para fazer a manutenção. Você precisa estar a pé perto do radar para concertá-lo."},
	{HelpIDRoadworkerClass, "Depois de ter sido reparado, o próximo é escolhido aleatoriamente."},
	{HelpIDRoadworkerClass, "Agora você tem uma escolha: ou você continua a reparar radares, ou você dirige de volta à base"},
	{HelpIDRoadworkerClass, "para terminar a missão."},
	{HelpIDRoadworkerClass, " "},
	{HelpIDRoadworkerClass, "O segundo trabalho é para rebocar veículos quebrados ao triturador."},
	{HelpIDRoadworkerClass, "Use um Towtruck e use o comando /trabalho para iniciar um trabalho."},
	{HelpIDRoadworkerClass, "Se dirija para o marcador vermelho e haverá um veículo quebrado."},
	{HelpIDRoadworkerClass, "Chegue no Checkpoint para anexar automaticamente o veículo quebrado em seu Towtruck."},
	{HelpIDRoadworkerClass, "Reboque o veículo de volta à base para que possa ser jogado no triturador."},
	{HelpIDRoadworkerClass, " "},
	{HelpIDRoadworkerClass, "Se você perder o veículo quebrado quando regressava à base, mova-se para perto do veículo"},
	{HelpIDRoadworkerClass, "e use o botão esquerdo do mouse para anexá-lo novamente em seu Towtruck."},

	{HelpIDConvoy, "Comboios são usados por vários jogadores, para que eles possam fazer a mesma missão em conjunto."},
	{HelpIDConvoy, "Somente caminhoneiros podem fazer comboios."},
	{HelpIDConvoy, "Cada comboio tem um líder. Este líder determina o trabalho para o comboio inteiro."},
	{HelpIDConvoy, "Como só pode haver cinco comboios, ao mesmo tempo, é aconselhável criar apenas um grande comboio em vez de"},
	{HelpIDConvoy, "vários comboios de pequeno porte. Um grande comboio ganha mais dinheiro do que os comboios pequenos"},
	{HelpIDConvoy, "Cada comboio pode ter no máximo 25 pessoas."},
	{HelpIDConvoy, " "},
	{HelpIDConvoy, "Todos os membros do comboio aumenta o pagamento para cada membro em 25'/. e ganha 5 scores por entrega"},
	{HelpIDConvoy, "Comboios também pode completar as missões de bônus para o dinheiro extra."},
	{HelpIDConvoy, "Para iniciar ou participar de um comboio, use o comando /comboio\" e selecione um espaço."},
	{HelpIDConvoy, " "},
	{HelpIDConvoy, "Uma vez que um comboio começou o trabalho, o comboio está fechado, então os novos membros não podem entrar no meio do trabalho."},
	{HelpIDConvoy, "Assim que todos os membros do comboio descarrega seus produtos no destino,"},
	{HelpIDConvoy, "todos os membros são pagos. O comboio também abre-se para receber novos membros."},

	{HelpIDBonusMissions, "Missões bônus são detectadas automaticamente quando você terminar um trabalho."},
	{HelpIDBonusMissions, "Caminhoneiros só pode fazer as missões bônus. Você é recompensado com o dobro quando você completar a missão."},
	{HelpIDBonusMissions, "Além do duplo pagamento, todas as bonificações são duplicados, bem como, por estar sobrecarregado, entregando mafia carga, ..."},
	{HelpIDBonusMissions, "Missões de bónus só podem ser realizadas por um caminhoneiro ou comboio."},
	{HelpIDBonusMissions, "Assim que a missão do bônus é completado por um jogador, os outros jogadores não podem receber o bônus,"},
	{HelpIDBonusMissions, "mesmo que fazer o mesmo trabalho."},
	{HelpIDBonusMissions, "A missão do bônus permanece a mesma até que tenha sido concluída. Uma vez que está concluída, outra missão bônus é gerada."},

	{HelpIDHouses, "Casas são propriedades que podem ser compradas por jogadores."},
	{HelpIDHouses, "Até 10 casas podem ser compradas por qualquer jogador."},
	{HelpIDHouses, "Cada casa tem um preço de compra e um máximo de atualização em nível de."},
	{HelpIDHouses, "O nível máximo da casa também determina a quantidade de veículos que esta casa pode ter ao estar totalmente atualizada."},
	{HelpIDHouses, "Quando você compra uma casa, será o nível 1. Isto dá-lhe um slot de veículo."},
	{HelpIDHouses, "Toda vez que você atualizar a sua casa mais um nível, um slot veículo adicional é criado."},
	{HelpIDHouses, "Cada casa de nível também tem um interior diferente. Ele se torna maior por todos os níveis."},
	{HelpIDHouses, "O level máximo para uma casa é 10."},
	{HelpIDHouses, "Estas casas são caras, porque eles podem conter até 10 slots veículo quando eles estão totalmente atualizado."},
	{HelpIDHouses, " "},
	{HelpIDHouses, "Quando você comprou sua casa, você pode entrar estando na porta (o ícone girando da casa)"},
	{HelpIDHouses, "e usando o comando /entrar."},
	{HelpIDHouses, "Depois de entrar na sua casa, você pode usar o comando /menucasa para alterar algumas opções para a casa."},
	{HelpIDHouses, "Neste menu, você pode alterar o nome da casa, atualizar a casa a um nível mais alto, comprar e vender veículos,"},
	{HelpIDHouses, "comprar seguro para os veiculos e sair da casa"},
	{HelpIDHouses, "Você também pode vender a casa, se houver veículos ligados à casa."},
	{HelpIDHouses, "Na venda de um veículo o reembolso é de 50% do preço que você pagou por ele."},
	{HelpIDHouses, "Isto exclui qualquer modificação que você tenha aplicado ao veículo."},
	{HelpIDHouses, " "},
	{HelpIDHouses, "Além disso, você pode abrir sua casa ao público. Ao fazer isso, qualquer um pode entrar na sua casa."},
	{HelpIDHouses, "Fechamento da casa só irá permitir que o proprietário entre na casa."},
	{HelpIDHouses, "Desta forma, você pode convidar seus amigos em sua casa. Se eles querem sair de casa, eles também tem que usar"},
	{HelpIDHouses, "o comando /menucasa. Eles são informados o mesmo menu que o proprietário, porém apenas 'Sair de casa' irá funcionar"},
	{HelpIDHouses, "para os visitantes."},

	{HelpIDInsurance, "O seguro do veículo é muito importante para comprar. Isto garante os seus veículos no caso de que eles estão destruídos."},
	{HelpIDInsurance, "O seguro pode ser comprado em sua casa por 10% do preço de compra da casa."},
	{HelpIDInsurance, "Um veículo pode ser destruído por batidas ou cair na água."},
	{HelpIDInsurance, "Se você não tiver seguro, o veículo destruído está perdido, você não recebe de volta."},
	{HelpIDInsurance, "Se você está seguro, o veículo é devolvido com plena saúde e tanque cheio."},
	{HelpIDInsurance, " "},
	{HelpIDInsurance, "Quando você compra um veículo, o veículo é ligado à casa de onde você comprou o veículo."},
	{HelpIDInsurance, "Se você tiver duas casas e só a casa a sua primeira tem seguro, não vai segurar os veículos da segunda casa."},

	{HelpIDBuyingVehicles, "Os jogadores podem comprar veículos, uma vez que ganhou dinheiro suficiente para comprar uma casa em primeiro lugar."},
	{HelpIDBuyingVehicles, "Entrar em sua casa e usando o comando /menucasa permitirá que você veja o menu para comprar veículos."},
	{HelpIDBuyingVehicles, "Os veículos estão conectados à casa da qual você comprou-los."},
	{HelpIDBuyingVehicles, "Uma vez que você comprou um veículo, você pode sair de sua casa e usar o comando /usarcarro para gerar lo."},
	{HelpIDBuyingVehicles, "Agora você pode dirigir seu veículo até o local desejado onde irá estaciona-lo permanetemente com o /estacionar."},
	{HelpIDBuyingVehicles, " "},
	{HelpIDBuyingVehicles, "Veículos comprados também pode ser modificados, com aerofólios, nitro outras rodas, e muito mais."},
	{HelpIDBuyingVehicles, "Basta visitar uma garagem transfender, low-riders, ou wheels-angels para fazer as modificações no seu veículo."},
	{HelpIDBuyingVehicles, "As modificações serão salvas quando você sair do jogo, então não se preocupe em perdê-los."},
	{HelpIDBuyingVehicles, " "},
	{HelpIDBuyingVehicles, "Quando você sair do jogo, os seus veículos será descarregado, então outros jogadores não podem arruiná-los."},
	{HelpIDBuyingVehicles, "Além disso, quando você estiver logado, o seu veículo será carregado novamente."},
	{HelpIDBuyingVehicles, " "},
	{HelpIDBuyingVehicles, "Seus veículos não pode ser conduzido por outros jogadores, eles serão expulsos se não for o proprietário do veículo."},
	{HelpIDBuyingVehicles, "Outros jogadores podem andar como passageiro/carona."},

	{HelpIDRentingVehicles, "Jogadores que não têm uma casa, no entanto, pode alugar um veículo."},
	{HelpIDRentingVehicles, "Basta ir para Wang Cars em Doherty, San Fierro para alugar um veículo."},
	{HelpIDRentingVehicles, " "},
	{HelpIDRentingVehicles, "Quando você alugar um veículo, a propriedade é transferida para você."},
	{HelpIDRentingVehicles, "Isso não significa que você pode manter o veículo."},
	{HelpIDRentingVehicles, "Significa apenas que você pode ser o único motorista do veículo."},
	{HelpIDRentingVehicles, " "},
	{HelpIDRentingVehicles, "Veículos alugados custam 10% do preço de compra de um veículo."},
	{HelpIDRentingVehicles, " "},
	{HelpIDRentingVehicles, "Se você já possui um veículo alugado, o primeiro é apreendido."},
	{HelpIDRentingVehicles, "Você não pode ter dois veículos alugados ao mesmo tempo."},
	{HelpIDRentingVehicles, "Além disso, quando você sair, o veículo alugado será apreendido."},
	{HelpIDRentingVehicles, "Ao logar novamente não vai ser de volta seu."},

	{HelpIDBusinesses, "Os jogadores também podem comprar até 4 empresas."},
	{HelpIDBusinesses, "Como casas, uma empresa pode ser atualizado, o máximo nível de atualização para um negócio é de 5."},
	{HelpIDBusinesses, " "},
	{HelpIDBusinesses, "Possuir um negócio, você ganha uma quantidade constante, mas baixo de dinheiro a cada hora."},
	{HelpIDBusinesses, "Sua empresa também ganha dinheiro quando você estiver offline."},
	{HelpIDBusinesses, "Atualizando um negócio ganha mais dinheiro a cada hora."},
	{HelpIDBusinesses, "Para cada nível, os ganhos por hora são aumentadas."},
	{HelpIDBusinesses, "Para o nível máximo (nível 5), uma empresa ganha 5 vezes o dinheiro que ganhou quando o negócio foi o nível 1."},
	{HelpIDBusinesses, " "},
	{HelpIDBusinesses, "Existem diferentes tipos de empresas. Cada tipo ganha uma quantidade diferente de dinheiro por hora."},
	{HelpIDBusinesses, "O negócio mais rentável é o casino. Este negócio ganha  R$250 por hora, que é R$6000 a cada dia."},
	{HelpIDBusinesses, "Atualizado para o nível 5, esse negócio ganha R$1.250 por hora, ou R$30.000 a cada dia."},
	{HelpIDBusinesses, "A desvantagem é que um casino custa muito dinheiro para comprar."}

};



// This array holds the vehicle-colors
new AVehicleColors[][10] =
{
	{"{000000}"},	{"{f5f5f5}"},	{"{2a77a1}"},	{"{840510}"},	{"{253739}"}, // Colors 0, 1, 2, 3, 4
	{"{87446f}"},	{"{d68f11}"},	{"{4c75b7}"},	{"{bdbdc5}"},	{"{5e7072}"}, // Colors 5, 6, 7, 8, 9

	{"{46597a}"},	{"{66697a}"},	{"{5e7e8d}"},	{"{58595b}"},	{"{d6dbd5}"}, // Colors 10, 11, 12, 13, 14
	{"{9ca1a4}"},	{"{34603f}"},	{"{740e1b}"},	{"{7c0a2b}"},	{"{a09d94}"}, // Colors 15, 16, 17, 18, 19

	{"{3b4e79}"},	{"{732e40}"},	{"{691e3c}"},	{"{96918d}"},	{"{515459}"}, // Colors 20, 21, 22, 23, 24
	{"{3f3e46}"},	{"{a5a9a8}"},	{"{645c5a}"},	{"{3c4969}"},	{"{969591}"}, // Colors 25, 26, 27, 28, 29

	{"{431f21}"},	{"{5f272a}"},	{"{8494ab}"},	{"{757a7d}"},	{"{646464}"}, // Colors 30, 31, 32, 33, 34
	{"{5b5853}"},	{"{252527}"},	{"{2e3a36}"},	{"{93a398}"},	{"{6d7a8a}"}, // Colors 35, 36, 37, 38, 39

	{"{28201e}"},	{"{6f6860}"},	{"{7c1c28}"},	{"{600a15}"},	{"{193828}"}, // Colors 40, 41, 42, 43, 44
	{"{5c1b1f}"},	{"{9c9872}"},	{"{7a7561}"},	{"{989586}"},	{"{acb0b1}"}, // Colors 45, 46, 47, 48, 49

	{"{848a88}"},	{"{305045}"},	{"{4e6368}"},	{"{162248}"},	{"{282f4c}"}, // Colors 50, 51, 52, 53, 54
	{"{7e6257}"},	{"{9fa4aa}"},	{"{9c8d70}"},	{"{6e1821}"},	{"{4e6881}"}, // Colors 55, 56, 57, 58, 59

	{"{9c9d98}"},	{"{907347}"},	{"{661d26}"},	{"{949c9f}"},	{"{a3a8a4}"}, // Colors 60, 61, 62, 63, 64
	{"{8f8c47}"},	{"{331a1d}"},	{"{697a8a}"},	{"{aaad8e}"},	{"{ac988f}"}, // Colors 65, 66, 67, 68, 69

	{"{86202e}"},	{"{708298}"},	{"{585953}"},	{"{9aa68e}"},	{"{601a1a}"}, // Colors 70, 71, 72, 73, 74
	{"{21212d}"},	{"{a4a097}"},	{"{ab9d83}"},	{"{78222b}"},	{"{0e326e}"}, // Colors 75, 76, 77, 78, 79

	{"{722a40}"},	{"{7a715f}"},	{"{741c28}"},	{"{1d2f31}"},	{"{4e322f}"}, // Colors 80, 81, 82, 83, 84
	{"{7d1b44}"},	{"{2f5b20}"},	{"{395a83}"},	{"{6c2837}"},	{"{a7a28f}"}, // Colors 85, 86, 87, 88, 89

	{"{b0b2b1}"},	{"{364155}"},	{"{6d6d6f}"},	{"{0f6a89}"},	{"{204b6d}"}, // Colors 90, 91, 92, 93, 94
	{"{2c3d57}"},	{"{9a9e9d}"},	{"{6d8494}"},	{"{4d5c5f}"},	{"{ac9b7f}"}, // Colors 95, 96, 97, 98, 99

	{"{416c8f}"},	{"{20253b}"},	{"{ac9277}"},	{"{124574}"},	{"{96816c}"}, // Colors 100, 101, 102, 103, 104
	{"{64686b}"},	{"{115083}"},	{"{a19984}"},	{"{385694}"},	{"{525661}"}, // Colors 105, 106, 107, 108, 109

	{"{7e6956}"},	{"{8d919a}"},	{"{596d86}"},	{"{483433}"},	{"{456250}"}, // Colors 110, 111, 112, 113, 114
	{"{730a28}"},	{"{223556}"},	{"{630d1a}"},	{"{a3adc6}"},	{"{6a5854}"}, // Colors 115, 116, 117, 118, 119

	{"{9b8a80}"},	{"{620b1c}"},	{"{5c5d5f}"},	{"{634428}"},	{"{741827}"}, // Colors 120, 121, 122, 123, 124
	{"{1c376e}"},	{"{ed6aae}"}                                                  // Colors 125, 126
};

