#pragma tabsize 0

#define GameModeName				"Brasil Mega Trucker"

new PlayersBeforePolice	= 2;

#include <a_samp>
#include <a_objects>
#include <zcmd>
#include <core>
#include <float>
#include <dudb>
#include <udb>
#include <a_players>
#include <cpstream>
#include <dutils>
#include <streamer>
#include <sscanf2>

#include <PPC_DefTexts>
#include <PPC_ServerSettings>
#include <PPC_Defines>
#include <PPC_DefLocations>
#include <PPC_DefLoads>
#include <PPC_DefCars>                                   
#include <PPC_DefPlanes>
#include <PPC_DefTrailers>
#include <PPC_DefBuyableVehicles>
#include <PPC_GlobalTimer>
#include <PPC_Common>
#include <PPC_Housing>
#include <PPC_Business>
#include <PPC_GameModeInit>
#include <PPC_FileOperations>
#include <PPC_Speedometer>
#include <PPC_MissionsTrucking>
#include <PPC_MissionsBus>
#include <PPC_MissionsPilot>
#include <PPC_MissionsPolice>
#include <PPC_MissionsMafia>
#include <PPC_MissionsAssistance>
#include <PPC_MissionsCourier>
#include <PPC_MissionsRoadworker>
#include <PPC_Convoys>
#include <PPC_Dialogs>
#include <PPC_PlayerCommands>
#include <PPC_Toll> 

#define SLOT         1  
#define TimerFlood   3000
#define AlertFlood   4 
#define ColorFlood   0x24B1DBAA
#define CLIMATEMPO   0xFFFFAFAA  
#define AMARELO      0xFFFF00AA
#define VERMELHO     0xFF0000AA
#define AZUL         0x0000FFAA
#define VERDE        0x00FF00AA 
#define BRANCO       0xFFFFFFFF

forward timed();
forward Climas(); 

new	FloodTimer[MAX_PLAYERS];
new FloodAlert[MAX_PLAYERS]; 
//Relógio
new timer1,timer2,timer3;
//Nomezinho
new Text:AberturaP0;
new Text:AberturaP1;
//Abertura
new Text:Abertura0;
new Text:Abertura1;

new Text:txtTimeDisp;

main ()
{
	print("\n-------------------------------------------");
	print("Brasil Mega Trucker");
	print("--------------------------------------------\n");
}
public OnGameModeInit()
{  
    Create3DTextLabel("{FFFFFF}/cor1\n{FF0000}/cor2\n{FFFFFF}/pintura\n{FF0000}/neon\n{FFFFFF}/reparar\n{FF0000}/editarplaca", 0xFFFFFFFF, 2096.6445, 1120.9552, 11.13951, 30.0, 0, 0);  //6 Avenida
    Create3DTextLabel("{FFFFFF}/cor1\n{FF0000}/cor2\n{FFFFFF}/pintura\n{FF0000}/neon\n{FFFFFF}/reparar", 0xFFFFFFFF, -47.7836, 270.6917, 2.2500, 30.0, 0, 0);     //1  parking fazenda
    Create3DTextLabel("{FFFFFF}/cor1\n{FF0000}/cor2\n{FFFFFF}/pintura\n{FF0000}/neon\n{FFFFFF}/reparar", 0xFFFFFFFF, 24.6492, 2418.9697, 22.7578, 30.0, 0, 0);    //2  aero
    Create3DTextLabel("{FFFFFF}/cor1\n{FF0000}/cor2\n{FFFFFF}/pintura\n{FF0000}/neon\n{FFFFFF}/reparar\n{FF0000}/editarplaca", 0xFFFFFFFF, 1348.4963, 946.5101, 10.5252, 30.0, 0, 0);   //3  chuckup
    Create3DTextLabel("{FFFFFF}/cor1\n{FF0000}/cor2\n{FFFFFF}/pintura\n{FF0000}/neon\n{FFFFFF}/reparar", 0xFFFFFFFF, -547.3569,507.0492,2.5933, 30.0, 0, 0); //4   Dragao
    Create3DTextLabel("{FFFFFF}/cor1\n{FF0000}/cor2\n{FFFFFF}/pintura\n{FF0000}/neon\n{FFFFFF}/reparar\n{FF0000}/editarplaca", 0xFFFFFFFF, -1656.2089,454.5365,7.4053, 30.0, 0, 0); //5   SF

	txtTimeDisp = TextDrawCreate(549.000000, 23.000000, "--:--:--");
	TextDrawBackgroundColor(txtTimeDisp, 255);
	TextDrawFont(txtTimeDisp, 2);
	TextDrawLetterSize(txtTimeDisp, 0.300000, 1.000000);
	TextDrawColor(txtTimeDisp, -1);
	TextDrawSetOutline(txtTimeDisp, 0);
	TextDrawSetProportional(txtTimeDisp, 1);
    TextDrawSetShadow(txtTimeDisp, 1);

	AberturaP0 = TextDrawCreate(486.000000, 125.000000, "Brasil Mega Trucker");
	TextDrawBackgroundColor(AberturaP0, 255);
	TextDrawFont(AberturaP0, 3);
	TextDrawLetterSize(AberturaP0, 0.329999, 1.000000);
	TextDrawColor(AberturaP0, -1);
	TextDrawSetOutline(AberturaP0, 1);
	TextDrawSetProportional(AberturaP0, 1);

	AberturaP1 = TextDrawCreate(603.000000, 133.000000, "v2.9");
	TextDrawBackgroundColor(AberturaP1, 255);
	TextDrawFont(AberturaP1, 3);
	TextDrawLetterSize(AberturaP1, 0.310000, 1.000000);
	TextDrawColor(AberturaP1, -16776961);
	TextDrawSetOutline(AberturaP1, 1);
	TextDrawSetProportional(AberturaP1, 1);

    Abertura0 = TextDrawCreate(210.000000, 105.000000, "Brasil Mega Trucker");
	TextDrawBackgroundColor(Abertura0, 255);
	TextDrawFont(Abertura0, 3);
	TextDrawLetterSize(Abertura0, 0.519999, 3.400000);
	TextDrawColor(Abertura0, -1);
	TextDrawSetOutline(Abertura0, 1);
	TextDrawSetProportional(Abertura0, 1);

	Abertura1 = TextDrawCreate(403.000000, 134.000000, "v2.9");
	TextDrawBackgroundColor(Abertura1, 255);
	TextDrawFont(Abertura1, 3);
	TextDrawLetterSize(Abertura1, 0.340000, 1.500000);
	TextDrawColor(Abertura1, -16776961);
	TextDrawSetOutline(Abertura1, 1);
	TextDrawSetProportional(Abertura1, 1);


    SetTimer("timed",1000, 1);
    SetTimer("Climas",600000, 1);    

	SetGameModeText(GameModeName);
	GameModeInit_VehiclesPickups();
	GameModeInit_Classes(); 
	Convoys_Init(); 

	ShowPlayerMarkers(1); 
	ShowNameTags(1); 
	ManualVehicleEngineAndLights(); 
	EnableStuntBonusForAll(0); 
	DisableInteriorEnterExits(); 
	UsePlayerPedAnims(); 
	SetTimer("Timer_TimedMessages", 1000 * 60 * 2, true);
	SetTimer("ShowRandomBonusMission", 1000 * 60 * 5, true);
	SetTimer("Toll", 1000, true);
	FixHouses();
	SetTimer("GlobalTimer", 1000, true);    

    for(new i; i < MAX_PLAYERS; i ++)
	{
		if(IsPlayerConnected(i))
		{
			TextDrawShowForPlayer(i, AberturaP0);
			TextDrawShowForPlayer(i, AberturaP1);
		}
	}
	Objetos();
	return 1;
}
public OnGameModeExit()
{
	KillTimer(timer1);
	KillTimer(timer2);
	KillTimer(timer3);
	TextDrawHideForAll(txtTimeDisp);
	TextDrawDestroy(txtTimeDisp);
	TextDrawHideForAll(AberturaP0);
	TextDrawDestroy(AberturaP0);
	TextDrawHideForAll(AberturaP1);
	TextDrawDestroy(AberturaP1);
	return 1;
}
public OnPlayerConnect(playerid)
{
    APlayerData[playerid][Logado] = 0;
    TextDrawShowForPlayer(playerid, txtTimeDisp);      
    TextDrawShowForPlayer(playerid, Abertura0);
	TextDrawShowForPlayer(playerid, Abertura1); 
    //PlayAudioStreamForPlayer(playerid, "http://dc367.4shared.com/img/1164928174/f2b46aa2/dlink__2Fdownload_2Fq5CeVkQA_3Ftsid_3D20120225-231343-741a2f44/preview.mp3", 258.4893, -41.4008, 1002.0234, 9999999999.0, 1);
    SendClientMessage(playerid, 0xFFFFFFFF, " ");
    SendClientMessage(playerid, 0xFFFFFFFF, " ");
    SendClientMessage(playerid, 0xFFFFFFFF, " ");
    SendClientMessage(playerid, 0xFFFFFFFF, " ");
    SendClientMessage(playerid, 0xFFFFFFFF, " ");
    SendClientMessage(playerid, 0xFFFFFFFF, " ");
    SendClientMessage(playerid, 0xFFFFFFFF, " ");
    SendClientMessage(playerid, 0xFFFFFFFF, " ");
    SendClientMessage(playerid, 0xFFFFFFFF, " ");
    SendClientMessage(playerid, 0xFFFFFFFF, " ");
    SendClientMessage(playerid, 0xFFFFFFFF, " ");
    SendClientMessage(playerid, BRANCO, "Música de Abertura:  X.");

	new Name[MAX_PLAYER_NAME], NewPlayerMsg[128], HouseID;
	SetPVarInt(playerid, "PVarMoney", 0);
	SetPVarInt(playerid, "PVarScore", 0);
	GetPlayerName(playerid, Name, sizeof(Name));
	GetPlayerName(playerid, APlayerData[playerid][PlayerName], 24);
	format(NewPlayerMsg, 128, TXT_PlayerJoinedServer, Name, playerid);
	SendClientMessageToAll(0xFFFFFFFF, NewPlayerMsg);
	Speedometer_Setup(playerid);
	APlayerData[playerid][MissionText] = TextDrawCreate(320.0, 430.0, " ");
	TextDrawAlignment(APlayerData[playerid][MissionText], 2);
	TextDrawUseBox(APlayerData[playerid][MissionText], 1);
	TextDrawBoxColor(APlayerData[playerid][MissionText], 0x00000066);
	if (PlayerFile_Load(playerid) == 1)
	{
		if (APlayerData[playerid][BanTime] < gettime()) 
			ShowPlayerDialog(playerid, DialogLogin, DIALOG_STYLE_PASSWORD, TXT_DialogLoginTitle, TXT_DialogLoginMsg, TXT_DialogLoginButton1, TXT_DialogButtonCancel);
		else 
		{
			ShowRemainingBanTime(playerid); 
			Kick(playerid); 
		}
	}
	else
		ShowPlayerDialog(playerid, DialogRegister, DIALOG_STYLE_PASSWORD, TXT_DialogRegisterTitle, TXT_DialogRegisterMsg, TXT_DialogRegisterButton1, TXT_DialogButtonCancel);
	for (new HouseSlot; HouseSlot < MAX_HOUSESPERPLAYER; HouseSlot++)
	{
	    HouseID = APlayerData[playerid][Houses][HouseSlot];
		if (HouseID != 0)
		    HouseFile_Load(HouseID, true); 
	}
   	return 1;
}
ShowRemainingBanTime(playerid)
{
	new TotalBanTime, Days, Hours, Minutes, Seconds, Msg[128];
	TotalBanTime = APlayerData[playerid][BanTime] - gettime();
	if (TotalBanTime >= 86400)
	{
		Days = TotalBanTime / 86400;
		TotalBanTime = TotalBanTime - (Days * 86400);
	}
	if (TotalBanTime >= 3600)
	{
		Hours = TotalBanTime / 3600;
		TotalBanTime = TotalBanTime - (Hours * 3600);
	}
	if (TotalBanTime >= 60)
	{
		Minutes = TotalBanTime / 60;
		TotalBanTime = TotalBanTime - (Minutes * 60);
	}
	Seconds = TotalBanTime;
	SendClientMessage(playerid, 0xFFFFFFFF, TXT_StillBanned);
	format(Msg, 128, TXT_BannedDuration, Days, Hours, Minutes, Seconds);
	SendClientMessage(playerid, 0xFFFFFFFF, Msg);
}
public OnPlayerDisconnect(playerid, reason)
{   
    TextDrawHideForPlayer(playerid, Text:txtTimeDisp);
	if (IsPlayerNPC(playerid))
		return 1;
	new Name[24], Msg[128], HouseID;
	GetPlayerName(playerid, Name, sizeof(Name));
	for (new i; i < MAX_PLAYERS; i++)
	    if (IsPlayerConnected(i)) 
	        if (GetPlayerState(i) == PLAYER_STATE_SPECTATING)
	            if (APlayerData[i][SpectateID] == playerid) 
		   		{
					TogglePlayerSpectating(i, 0); 
					APlayerData[i][SpectateID] = INVALID_PLAYER_ID;
					APlayerData[i][SpectateType] = ADMIN_SPEC_TYPE_NONE;
					SendClientMessage(i, VERMELHO, "O jogador que você estava espiando saiu do server, modo espião terminado!");
				}
	format(Msg, 128, TXT_PlayerLeftServer, Name, playerid);
	SendClientMessageToAll(0xFFFFFFFF, Msg);
	if (strlen(APlayerData[playerid][PlayerPassword]) != 0)
	{
		PlayerFile_Save(playerid);
	}
	switch (APlayerData[playerid][PlayerClass])
	{
		case ClassTruckDriver: Trucker_EndJob(playerid); 
		case ClassBusDriver: BusDriver_EndJob(playerid);                                        
		case ClassPilot: Pilot_EndJob(playerid); 
		case ClassPolice: Police_EndJob(playerid); 
		case ClassMafia: Mafia_EndJob(playerid); 
		case ClassAssistance: Assistance_EndJob(playerid);
		case ClassRoadWorker: Roadworker_EndJob(playerid);
	}
	Convoy_Leave(playerid);
	for (new HouseSlot; HouseSlot < MAX_HOUSESPERPLAYER; HouseSlot++)
	{
	    HouseID = APlayerData[playerid][Houses][HouseSlot];
		if (HouseID != 0)
		{
		    House_RemoveVehicles(HouseID);
			AHouseData[HouseID][HouseOpened] = false;
		}
	}
	APlayerData[playerid][SpectateID] = -1;
	APlayerData[playerid][SpectateVehicle] = -1;
	APlayerData[playerid][SpectateType] = ADMIN_SPEC_TYPE_NONE;
	APlayerData[playerid][LoggedIn] = false;
	APlayerData[playerid][AssistanceNeeded] = false;
	APlayerData[playerid][PlayerPassword] = 0;
	APlayerData[playerid][PlayerLevel] = 0;
	APlayerData[playerid][PlayerJailed] = 0;
	APlayerData[playerid][PlayerFrozen] = 0; 
	APlayerData[playerid][Bans] = 0;
	APlayerData[playerid][BanTime] = 0;
	APlayerData[playerid][Muted] = false;
	APlayerData[playerid][RulesRead] = false;
	APlayerData[playerid][AutoReportTime] = 0;
	APlayerData[playerid][TruckerLicense] = 0;
    APlayerData[playerid][WeaponLicense] = 0;
	APlayerData[playerid][BusLicense] = 0;
	APlayerData[playerid][PlayerClass] = 0;
	APlayerData[playerid][Warnings] = 0;
	APlayerData[playerid][PlayerMoney] = 0;
	APlayerData[playerid][PlayerScore] = 0;
	for (new HouseSlot; HouseSlot < MAX_HOUSESPERPLAYER; HouseSlot++)
		APlayerData[playerid][Houses][HouseSlot] = 0;
	for (new BusSlot; BusSlot < MAX_BUSINESSPERPLAYER; BusSlot++)
		APlayerData[playerid][Business][BusSlot] = 0;
	APlayerData[playerid][CurrentHouse] = 0;
	APlayerData[playerid][BankPassword] = 0;
	APlayerData[playerid][BankLoggedIn] = false;
	APlayerData[playerid][BankMoney] = 0;
	APlayerData[playerid][StatsTruckerJobs] = 0;
	APlayerData[playerid][StatsConvoyJobs] = 0;
	APlayerData[playerid][StatsBusDriverJobs] = 0;
	APlayerData[playerid][StatsPilotJobs] = 0;
	APlayerData[playerid][StatsMafiaJobs] = 0;
	APlayerData[playerid][StatsMafiaStolen] = 0;
	APlayerData[playerid][StatsPoliceFined] = 0;
	APlayerData[playerid][StatsPoliceJailed] = 0;
	APlayerData[playerid][StatsCourierJobs] = 0;
	APlayerData[playerid][StatsRoadworkerJobs] = 0;
	APlayerData[playerid][StatsAssistance] = 0;
	APlayerData[playerid][StatsMetersDriven] = 0.0;
	APlayerData[playerid][PoliceCanJailMe] = false;
	APlayerData[playerid][PoliceWarnedMe] = false;
	APlayerData[playerid][Value_PoliceCanJailMe] = 0;
	KillTimer(APlayerData[playerid][PlayerJailedTimer]);
	KillTimer(APlayerData[playerid][Timer_PoliceCanJailMe]);
	Speedometer_Cleanup(playerid);
	TextDrawDestroy(APlayerData[playerid][MissionText]);
	if (APlayerData[playerid][RentedVehicleID] != 0)
	{
		AVehicleData[APlayerData[playerid][RentedVehicleID]][Model] = 0;
		AVehicleData[APlayerData[playerid][RentedVehicleID]][Fuel] = 0;
		AVehicleData[APlayerData[playerid][RentedVehicleID]][Owned] = false;
		AVehicleData[APlayerData[playerid][RentedVehicleID]][Owner] = 0;
		AVehicleData[APlayerData[playerid][RentedVehicleID]][PaintJob] = 0;
		for (new j; j < 14; j++)
		{
			AVehicleData[APlayerData[playerid][RentedVehicleID]][Components][j] = 0;
		}
		DestroyVehicle(APlayerData[playerid][RentedVehicleID]);
		APlayerData[playerid][RentedVehicleID] = 0;
	}
	return 1;
}
public OnPlayerText(playerid, text[])
{    
    new string[126];
	if(GetTickCount() > FloodTimer[playerid])
	{
		FloodAlert[playerid] = 0;
	}
	FloodTimer[playerid] = GetTickCount() + TimerFlood;
	FloodAlert[playerid] ++;
	if(FloodAlert[playerid] > 1 && FloodAlert[playerid] < AlertFlood-1)
	{
	}
	else if(FloodAlert[playerid] == AlertFlood-1)
	{
	}
	else if(FloodAlert[playerid] == AlertFlood)
	{
		new pname[MAX_PLAYER_NAME]; GetPlayerName(playerid, pname, sizeof(pname));
		format(string, sizeof(string), "-| %s foi calado automaticamente por floodar no chat |-.", pname);
		SendClientMessageToAll(VERMELHO, string);
        APlayerData[playerid][Muted] = true;
		return 0;
	} 
    if (APlayerData[playerid][Muted] == true)
	{
		SendClientMessage(playerid, VERMELHO, "Você está mudo!");
		return 0;
	}
    return 1;
}
public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	switch (dialogid)
	{
		case DialogRegister: Dialog_Register(playerid, response, inputtext);
		case DialogLogin: Dialog_Login(playerid, response, inputtext); 
		case DialogStatsOtherPlayer: Dialog_StatsOtherPlayer(playerid, response, listitem);
		case DialogStatsHouse: Dialog_StatsHouse(playerid, response, listitem);
		case DialogStatsGoHouse: Dialog_StatsGoHouse(playerid, response, listitem);
		case DialogStatsGoBusiness: Dialog_StatsGoBusiness(playerid, response, listitem);
		case DialogRescue: Dialog_Rescue(playerid, response, listitem); // The rescue-dialog
        case DialogRadios: Dialog_Radios(playerid, response, listitem); // The radios-dialog          
		case DialogQ: Dialog_Q(playerid, response, listitem); //sair do server
        case DialogBuyLicenses: Dialog_BuyLicenses(playerid, response, listitem); // The license-dialog (allows the player to buy trucker/busdriver licenses)
		case DialogRules: Dialog_Rules(playerid, response);
		case DialogTruckerJobMethod: Dialog_TruckerSelectJobMethod(playerid, response, listitem); // The work-dialog for truckers (shows the loads he can carry and lets the player choose the load)
		case DialogTruckerSelectLoad: Dialog_TruckerSelectLoad(playerid, response, listitem); // The load-selection dialog for truckers (shows the startlocations for the selected load and let the player choose his startlocation)
		case DialogTruckerStartLoc: Dialog_TruckerSelectStartLoc(playerid, response, listitem); // The start-location dialog for truckers (shows the endlocations for the selected load and let the player choose his endlocation)
		case DialogTruckerEndLoc: Dialog_TruckerSelectEndLoc(playerid, response, listitem); // The end-location dialog for truckers (processes the selected endlocation and starts the job)
		case DialogBusJobMethod: Dialog_BusSelectJobMethod(playerid, response, listitem); // The work-dialog for busdrivers (process the options to choose own busroute or auto-assigned busroute)
		case DialogBusSelectRoute: Dialog_BusSelectRoute(playerid, response, listitem); // Choose the busroute and start the job
		case DialogCourierSelectQuant: Dialog_CourierSelectQuant(playerid, response, listitem);
		case DialogBike: Dialog_Bike(playerid, response, listitem); // The bike-dialog
		case DialogCar: Dialog_Car(playerid, response, listitem); // The car-dialog (which uses a split dialog structure)
		case DialogPlane: Dialog_Plane(playerid, response, listitem); // The plane-dialog (which uses a split dialog structure)
		case DialogTrailer: Dialog_Trailer(playerid, response, listitem); // The trailer-dialog (which uses a split dialog structure)
		case DialogBoat: Dialog_Boat(playerid, response, listitem); // The boat-dialog
		case DialogNeon: Dialog_Neon(playerid, response, listitem); // The neon-dialog
		case DialogRentCarClass: Dialog_RentProcessClass(playerid, response, listitem); // The player chose a vehicleclass from where he can rent a vehicle
		case DialogRentCar: Dialog_RentCar(playerid, response, listitem); // The player chose a vehicle from the list of vehicles from the vehicleclass he chose before
		case DialogPlayerCommands: Dialog_PlayerCommands(playerid, response, listitem); // Displays all commands in a split-dialog structure
		case DialogPrimaryCarColor: Dialog_PrimaryCarColor(playerid, response, listitem);
		case DialogSedundaryCarColor: Dialog_SedundaryCarColor(playerid, response, listitem);
		case DialogWeather: Dialog_Weather(playerid, response, listitem); // The weather dialog
		case DialogCarOption: Dialog_CarOption(playerid, response, listitem); // The caroption dialog
		case DialogSelectConvoy: Dialog_SelectConvoy(playerid, response, listitem);
		case DialogHouseMenu: Dialog_HouseMenu(playerid, response, listitem); // Process the main housemenu
		case DialogUpgradeHouse: Dialog_UpgradeHouse(playerid, response, listitem); // Process the house-upgrade menu
		case DialogGoHome: Dialog_GoHome(playerid, response, listitem); // Port to one of your houses
		case DialogHouseNameChange: Dialog_ChangeHouseName(playerid, response, inputtext); // Change the name of your house
		case DialogSellHouse: Dialog_SellHouse(playerid, response); // Sell the house
		case DialogBuyCarClass: Dialog_BuyCarClass(playerid, response, listitem); // The player chose a vehicleclass from where he can buy a vehicle
		case DialogBuyCar: Dialog_BuyCar(playerid, response, listitem); // The player chose a vehicle from the list of vehicles from the vehicleclass he chose before
		case DialogSellCar: Dialog_SellCar(playerid, response, listitem);
		case DialogBuyInsurance: Dialog_BuyInsurance(playerid, response);
		case DialogGetCarSelectHouse: Dialog_GetCarSelectHouse(playerid, response, listitem);
		case DialogGetCarSelectCar: Dialog_GetCarSelectCar(playerid, response, listitem);
		case DialogUnclampVehicles: Dialog_UnclampVehicles(playerid, response);
		case DialogCreateBusSelType: Dialog_CreateBusSelType(playerid, response, listitem);
		case DialogBusinessMenu: Dialog_BusinessMenu(playerid, response, listitem);
		case DialogGoBusiness: Dialog_GoBusiness(playerid, response, listitem);
		case DialogBusinessNameChange: Dialog_ChangeBusinessName(playerid, response, inputtext); // Change the name of your business
		case DialogSellBusiness: Dialog_SellBusiness(playerid, response); // Sell the business
		case DialogBankPasswordRegister: Dialog_BankPasswordRegister(playerid, response, inputtext);
		case DialogBankPasswordLogin: Dialog_BankPasswordLogin(playerid, response, inputtext);
		case DialogBankOptions: Dialog_BankOptions(playerid, response, listitem);
		case DialogBankDeposit: Dialog_BankDeposit(playerid, response, inputtext);
		case DialogBankWithdraw: Dialog_BankWithdraw(playerid, response, inputtext);
		case DialogBankTransferMoney: Dialog_BankTransferMoney(playerid, response, inputtext);
		case DialogBankTransferName: Dialog_BankTransferName(playerid, response, inputtext);
		case DialogBankCancel: Dialog_BankCancel(playerid, response);
		case DialogHelpItemChosen: Dialog_HelpItemChosen(playerid, response, listitem);
		case DialogHelpItem: Dialog_HelpItem(playerid, response);
		case DialogOldPassword: Dialog_OldPassword(playerid, response, inputtext);
		case DialogNewPassword: Dialog_NewPassword(playerid, response, inputtext);
		case DialogConfirmPassword: Dialog_ConfirmPassword(playerid, response);
	}
    return 1;
}
public OnPlayerClickPlayer(playerid, clickedplayerid, source)
{
	if (APlayerData[playerid][PlayerLevel] >= 1)
	{
		if (APlayerData[playerid][Logado] == 1)
		{
		new Name[24], DialogTitle[128], PlayerStatList[3000], PlayerIP[16], NumHouses, NumBusinesses;
		GetPlayerName(clickedplayerid, Name, sizeof(Name));
		format(DialogTitle, 128, "Statisticas do jogador: %s", Name);
	    GetPlayerIp(clickedplayerid, PlayerIP, sizeof(PlayerIP));
		format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}IP: {00FF00}%s\n", PlayerStatList, PlayerIP);
		format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Level de Admin: {00FF00}%i\n", PlayerStatList, APlayerData[clickedplayerid][PlayerLevel]);
		switch(APlayerData[clickedplayerid][PlayerClass])
		{
			case ClassTruckDriver: format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Classe: {00FF00}Caminhoneiro\n", PlayerStatList);
			case ClassBusDriver: format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Classe: {00FF00}Motorista de Ônibus\n", PlayerStatList);
			case ClassPilot: format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Classe: {00FF00}Piloto de Avião\n", PlayerStatList);
			case ClassPolice: format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Classe: {00FF00}Policial\n", PlayerStatList);
			case ClassMafia: format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Classe: {00FF00}Mafia\n", PlayerStatList);
			case ClassCourier: format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Classe: {00FF00}Correios\n", PlayerStatList);
			case ClassAssistance: format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Classe: {00FF00}Mecânico\n", PlayerStatList);
            case ClassRoadWorker: format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Classe: {00FF00}DNIT\n", PlayerStatList);
		}
		format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Dinheiro: {00FF00}%i\n", PlayerStatList, APlayerData[clickedplayerid][PlayerMoney]);
		format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Banco: {00FF00}%i\n", PlayerStatList, APlayerData[clickedplayerid][BankMoney]);
        format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Score: {00FF00}%i\n", PlayerStatList, APlayerData[clickedplayerid][PlayerScore]);
		format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Procurado: {00FF00}%i\n", PlayerStatList, GetPlayerWantedLevel(clickedplayerid));
		if (APlayerData[clickedplayerid][TruckerLicense] == 1)
			format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Licença de Caminhão: {00FF00}Sim\n", PlayerStatList);
		else
			format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Licença de Caminhão: {FF0000}Não\n", PlayerStatList);

		if (APlayerData[clickedplayerid][BusLicense] == 1)
			format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Licença de Ônibus: {00FF00}Sim\n", PlayerStatList);
		else
			format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Licença de Ônibus: {FF0000}Não\n", PlayerStatList);
        if (APlayerData[clickedplayerid][WeaponLicense] == 1)
            format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Porte de Armas: {00FF00}Sim\n", PlayerStatList);
        else
            format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Porte de Armas: {FF0000}Não\n", PlayerStatList);
		format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Trabalhos de Caminhoneiro: {00FF00}%i\n", PlayerStatList, APlayerData[clickedplayerid][StatsTruckerJobs]);
		format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Trabalhos em Comboio: {00FF00}%i\n", PlayerStatList, APlayerData[clickedplayerid][StatsConvoyJobs]);
		format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Trabalhos de Motorista de Ônibus: {00FF00}%i\n", PlayerStatList, APlayerData[clickedplayerid][StatsBusDriverJobs]);
		format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Trabalhos de Piloto: {00FF00}%i\n", PlayerStatList, APlayerData[clickedplayerid][StatsPilotJobs]);
		format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Trabalhos de Máfia: {00FF00}%i\n", PlayerStatList, APlayerData[clickedplayerid][StatsMafiaJobs]);
		format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Cargas-Máfia Roubadas: {00FF00}%i\n", PlayerStatList, APlayerData[clickedplayerid][StatsMafiaStolen]);
		format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Jogadores Multados: {00FF00}%i\n", PlayerStatList, APlayerData[clickedplayerid][StatsPoliceFined]);
		format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Jogadores Presos: {00FF00}%i\n", PlayerStatList, APlayerData[clickedplayerid][StatsPoliceJailed]);
		format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Trabalhos de Correios: {00FF00}%i\n", PlayerStatList, APlayerData[clickedplayerid][StatsCourierJobs]);
		format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Trabalhos de DNIT: {00FF00}%i\n", PlayerStatList, APlayerData[clickedplayerid][StatsRoadworkerJobs]);
		format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Jogadores Socorridos: {00FF00}%i\n", PlayerStatList, APlayerData[clickedplayerid][StatsAssistance]);
		format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Distância Percorrida: {00FF00}%f\n", PlayerStatList, APlayerData[clickedplayerid][StatsMetersDriven]);
		for (new i; i < MAX_HOUSESPERPLAYER; i++)
			if (APlayerData[clickedplayerid][Houses][i] != 0)
			    NumHouses++;
		for (new i; i < MAX_BUSINESSPERPLAYER; i++)
			if (APlayerData[clickedplayerid][Business][i] != 0)
			    NumBusinesses++;
		format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Casas: {00FF00}%i (dois clicks para ver)\n", PlayerStatList, NumHouses);
		format(PlayerStatList, sizeof(PlayerStatList), "%s{FFFFFF}Empresas: {00FF00}%i (dois clicks para ver)\n", PlayerStatList, NumBusinesses);
		APlayerData[playerid][DialogOtherPlayer] = clickedplayerid;
		ShowPlayerDialog(playerid, DialogStatsOtherPlayer, DIALOG_STYLE_LIST, DialogTitle, PlayerStatList, TXT_DialogButtonSelect, TXT_DialogButtonCancel); // Let the player buy a license
		}
	}
	return 1;
}
public OnPlayerPickUpPickup(playerid, pickupid)
{
	if (pickupid == Pickup_License)
		ShowPlayerDialog(playerid, DialogBuyLicenses, DIALOG_STYLE_LIST, TXT_DialogLicenseTitle, TXT_DialogLicenseList, TXT_DialogButtonBuy, TXT_DialogButtonCancel); // Let the player buy a license
	return 1;
}
public OnPlayerSpawn(playerid)
{
	APlayerData[playerid][Logado] = 1;
    StopAudioStreamForPlayer(playerid);          
	if (APlayerData[playerid][RulesRead] == false)
	{
        new Msg[2000];
		format(Msg, 2000, "%s1. Sempre dirigir do lado direito nas estradas para evitar acidentes.\n", Msg);
		format(Msg, 2000, "%s2. Não chingar ou desrespeitar os outros jogadores, eles são seus companheiros.\n", Msg);
		format(Msg, 2000, "%s3. Usar a linguagem padrão 'Português'.\n", Msg);
		format(Msg, 2000, "%s4. Não usar hackers ou será banido permanentemente.\n", Msg);
		format(Msg, 2000, "%s5. Não floodar no chat, pode ser calado por um admin.\n", Msg);
		format(Msg, 2000, "%s6. Não roubar carros, sujeito a prisão caso haja denuncia.\n", Msg);
        format(Msg, 2000, "%s7. Nunca chingue ou desrespeite um administrador, você será banido.\n", Msg);
		ShowPlayerDialog(playerid, DialogRules, DIALOG_STYLE_MSGBOX, "Regras do Brasil Mega Trucker:", Msg, "Aceitar", TXT_DialogButtonCancel);
	}
	if (IsPlayerNPC(playerid))
		return 1;
	if (APlayerData[playerid][LoggedIn] == false)
	{
		SendClientMessage(playerid, 0xFFFFFFFF, TXT_FailedLoginProperly);
	    Kick(playerid); 
    }
	new missiontext[200];
    SetPlayerVirtualWorld(playerid, 0);
	SetPlayerInterior(playerid, 0);
	APlayerData[playerid][CurrentHouse] = 0;
	TogglePlayerClock(playerid, 0);
	ResetPlayerWeapons(playerid);
	switch (APlayerData[playerid][PlayerClass])
	{
		case ClassTruckDriver:
		{
			format(missiontext, sizeof(missiontext), Trucker_NoJobText); 
			SetPlayerColor(playerid, ColorClassTruckDriver); 
	        if (APlayerData[playerid][WeaponLicense] == 1)
			{
				for (new i; i < 12; i++)
			    GivePlayerWeapon(playerid, APoliceWeapons[i], PoliceWeaponsAmmo);
			}
            else
            {
                ResetPlayerWeapons(playerid);
            }
        }
		case ClassBusDriver: 
		{
			format(missiontext, sizeof(missiontext), BusDriver_NoJobText); 
			SetPlayerColor(playerid, ColorClassBusDriver); 
	        if (APlayerData[playerid][WeaponLicense] == 1)
			{
				for (new i; i < 12; i++)
			    GivePlayerWeapon(playerid, APoliceWeapons[i], PoliceWeaponsAmmo);
			}
            else
            {
                ResetPlayerWeapons(playerid);
            }
		}
		case ClassPilot: 
		{
			format(missiontext, sizeof(missiontext), Pilot_NoJobText); 
			SetPlayerColor(playerid, ColorClassPilot);
	        if (APlayerData[playerid][WeaponLicense] == 1)
			{
				for (new i; i < 12; i++)
			    GivePlayerWeapon(playerid, APoliceWeapons[i], PoliceWeaponsAmmo);
			}
            else
            {
                ResetPlayerWeapons(playerid);
            }
		}
        case ClassPolice: 
		{
			format(missiontext, sizeof(missiontext), Police_NoJobText);
			SetPlayerColor(playerid, ColorClassPolice); 
			KillTimer(APlayerData[playerid][PlayerCheckTimer]);
			APlayerData[playerid][PlayerCheckTimer] = SetTimerEx("Police_CheckWantedPlayers", 1000, true, "i", playerid);
			for (new i; i < 12; i++)
			GivePlayerWeapon(playerid, APoliceWeapons[i], PoliceWeaponsAmmo);
		}
		case ClassMafia: 
		{
			format(missiontext, sizeof(missiontext), Mafia_NoJobText);
			SetPlayerColor(playerid, ColorClassMafia);
			KillTimer(APlayerData[playerid][PlayerCheckTimer]);
			APlayerData[playerid][PlayerCheckTimer] = SetTimerEx("Mafia_CheckMafiaLoads", 1000, true, "i", playerid);
			for (new i; i < 12; i++)
			GivePlayerWeapon(playerid, APoliceWeapons[i], PoliceWeaponsAmmo);
    	}
		case ClassCourier: 
		{
			format(missiontext, sizeof(missiontext), Courier_NoJobText);
			SetPlayerColor(playerid, ColorClassCourier);
	        if (APlayerData[playerid][WeaponLicense] == 1)
			{
				for (new i; i < 12; i++)
			    GivePlayerWeapon(playerid, APoliceWeapons[i], PoliceWeaponsAmmo);
			}
            else
            {
                ResetPlayerWeapons(playerid);
            }
		}
		case ClassAssistance: // Assistance class
		{
			format(missiontext, sizeof(missiontext), Assistance_NoJobText); // Preset the missiontext
			SetPlayerColor(playerid, ColorClassAssistance); // Set the playercolor (chatcolor for the player and color on the map)
	        if (APlayerData[playerid][WeaponLicense] == 1)
			{
				for (new i; i < 12; i++)
			    GivePlayerWeapon(playerid, APoliceWeapons[i], PoliceWeaponsAmmo);
			}
            else
            {
                ResetPlayerWeapons(playerid);
            }
			KillTimer(APlayerData[playerid][PlayerCheckTimer]);
			APlayerData[playerid][PlayerCheckTimer] = SetTimerEx("Assistance_CheckPlayers", 1000, true, "i", playerid);
		}
		case ClassRoadWorker: // Roadworker class
		{
			format(missiontext, sizeof(missiontext), RoadWorker_NoJobText); // Preset the missiontext
			SetPlayerColor(playerid, ColorClassRoadWorker); // Set the playercolor (chatcolor for the player and color on the map)
	        if (APlayerData[playerid][WeaponLicense] == 1)
			{
				for (new i; i < 12; i++)
			    GivePlayerWeapon(playerid, APoliceWeapons[i], PoliceWeaponsAmmo);
			}
            else
            {
                ResetPlayerWeapons(playerid);
            }
        }
	}
	TextDrawSetString(APlayerData[playerid][MissionText], missiontext);
	TextDrawShowForPlayer(playerid, APlayerData[playerid][MissionText]);
	if (APlayerData[playerid][PlayerJailed] != 0)
	    Police_JailPlayer(playerid, APlayerData[playerid][PlayerJailed]);

	return 1;
}
public OnPlayerEnterCheckpoint(playerid)
{
	switch (APlayerData[playerid][PlayerClass])
	{
		case ClassTruckDriver: 
			Trucker_OnPlayerEnterCheckpoint(playerid); 
		case ClassBusDriver:
		{
			GameTextForPlayer(playerid, TXT_BusDriverMissionPassed, 3000, 4); 
			BusDriver_EndJob(playerid); 
		}
		case ClassPilot: 
			Pilot_OnPlayerEnterCheckpoint(playerid); 
		case ClassMafia: 
			Mafia_OnPlayerEnterCheckpoint(playerid);
		case ClassCourier: 
			Courier_OnPlayerEnterCheckpoint(playerid);
		case ClassRoadWorker: 
		{
			if (APlayerData[playerid][JobID] == 1) 
			{
				GameTextForPlayer(playerid, TXT_RoadworkerMissionPassed, 3000, 4); 
				Roadworker_EndJob(playerid);
			}
			if (APlayerData[playerid][JobID] == 2) 
                Roadworker_EnterCheckpoint(playerid);
		}
	}

	return 1;
}
public OnPlayerEnterRaceCheckpoint(playerid)
{
	switch (APlayerData[playerid][PlayerClass])
	{
		case ClassBusDriver: 
		    Bus_EnterRaceCheckpoint(playerid); 
		case ClassRoadWorker:
			Roadworker_EnterRaceCheckpoint(playerid);
	}
	return 1;
}
public OnPlayerDeath(playerid, killerid, reason)
{
	new VictimName[24], KillerName[24], Msg[128];
	TextDrawSetString(APlayerData[playerid][MissionText], " ");
	TextDrawHideForPlayer(playerid, APlayerData[playerid][MissionText]);
	switch (APlayerData[playerid][PlayerClass])
	{
		case ClassTruckDriver: Trucker_EndJob(playerid);
		case ClassBusDriver: BusDriver_EndJob(playerid);
		case ClassPilot: Pilot_EndJob(playerid);
		case ClassPolice: Police_EndJob(playerid);
		case ClassMafia: Mafia_EndJob(playerid);
		case ClassCourier: Courier_EndJob(playerid);
		case ClassAssistance: Assistance_EndJob(playerid);
		case ClassRoadWorker: Roadworker_EndJob(playerid);
	}
	Convoy_Leave(playerid);
	if (killerid != INVALID_PLAYER_ID)
	{
	    SetPlayerWantedLevel(killerid, GetPlayerWantedLevel(killerid) + 1);
	    GetPlayerName(playerid, VictimName, sizeof(VictimName));
	    GetPlayerName(killerid, KillerName, sizeof(KillerName));
		format(Msg, 128, "Você matou {FFFFFF}%s{FF0000}, e agora está sendo procurado pela polícia!", VictimName);
		SendClientMessage(killerid, VERMELHO, Msg);
		format(Msg, 128, "{0000FF}[Departamento de Polícia] O jogador {FFFFFF}%s{0000FF} matou {FFFFFF}%s{0000FF}.", KillerName, VictimName);
		Police_SendMessage(Msg);
        format(Msg, 128, "{0000FF}[Objetivo] {FFFFFF}Perseguir e multar.");        
        Police_SendMessage(Msg);
	}
	return 1;
}
public OnPlayerRequestClass(playerid, classid)
{
    TextDrawHideForPlayer(playerid, Abertura0);
	TextDrawHideForPlayer(playerid, Abertura1);
 	TextDrawShowForPlayer(playerid, AberturaP0);
	TextDrawShowForPlayer(playerid, AberturaP1);
 	SetPlayerInterior(playerid,14);
	SetPlayerPos(playerid,258.4893,-41.4008,1002.0234);
	SetPlayerFacingAngle(playerid, 270.0);
	SetPlayerCameraPos(playerid,256.0815,-43.0475,1004.0234);
	SetPlayerCameraLookAt(playerid,258.4893,-41.4008,1002.0234);
	switch (classid)
	{
		case 0, 1, 2, 3, 4, 5, 6, 7: 
		{
            GameTextForPlayer(playerid, TXT_ClassTrucker, 3000, 4);
			APlayerData[playerid][PlayerClass] = ClassTruckDriver;
		}
		case 8, 9: 
		{
            GameTextForPlayer(playerid, TXT_ClassBusDriver, 3000, 4);
			APlayerData[playerid][PlayerClass] = ClassBusDriver;
		}
		case 10: 
		{
            GameTextForPlayer(playerid, TXT_ClassPilot, 3000, 4);
			APlayerData[playerid][PlayerClass] = ClassPilot;
		}
		case 11, 12, 13: 
		{
            GameTextForPlayer(playerid, TXT_ClassPolice, 3000, 4);
			APlayerData[playerid][PlayerClass] = ClassPolice;
		}
		case 14, 15, 16:
		{
			GameTextForPlayer(playerid, TXT_ClassMafia, 3000, 4);
			APlayerData[playerid][PlayerClass] = ClassMafia;
		}
		case 17, 18: 
		{
			GameTextForPlayer(playerid, TXT_ClassCourier, 3000, 4);
			APlayerData[playerid][PlayerClass] = ClassCourier;
		}
		case 19: 
		{
			GameTextForPlayer(playerid, TXT_ClassAssistance, 3000, 4);
			APlayerData[playerid][PlayerClass] = ClassAssistance;
		}
		case 20, 21, 22:
		{
			GameTextForPlayer(playerid, TXT_ClassRoadWorker, 3000, 4);
			APlayerData[playerid][PlayerClass] = ClassRoadWorker;
		}
	}
	return 1;
}
public OnPlayerRequestSpawn(playerid)
{
	new Index, Float:x, Float:y, Float:z, Float:Angle, Name[24], Msg[128];
	GetPlayerName(playerid, Name, sizeof(Name));
	switch (APlayerData[playerid][PlayerClass])
	{
		case ClassTruckDriver:
		{
			Index = random(sizeof(ASpawnLocationsTrucker)); 
			x = ASpawnLocationsTrucker[Index][SpawnX]; 
			y = ASpawnLocationsTrucker[Index][SpawnY]; 
			z = ASpawnLocationsTrucker[Index][SpawnZ]; 
			Angle = ASpawnLocationsTrucker[Index][SpawnAngle]; 
			format(Msg, 128, "{FF8000}O Jogador {FFFFFF}%s {FF8000}entrou no server como caminhoneiro.", Name);
		}
		case ClassBusDriver:
		{
			Index = random(sizeof(ASpawnLocationsBusDriver));
			x = ASpawnLocationsBusDriver[Index][SpawnX]; // Get the X-position for the spawnlocation
			y = ASpawnLocationsBusDriver[Index][SpawnY]; // Get the Y-position for the spawnlocation
			z = ASpawnLocationsBusDriver[Index][SpawnZ]; // Get the Z-position for the spawnlocation
			Angle = ASpawnLocationsBusDriver[Index][SpawnAngle]; // Get the rotation-angle for the spawnlocation
			format(Msg, 128, "{00FFFF}O Jogador {FFFFFF}%s {00FFFF}entrou no server como motorista de ônibus.", Name);
		}
		case ClassPilot:
		{
			Index = random(sizeof(ASpawnLocationsPilot));
			x = ASpawnLocationsPilot[Index][SpawnX];
			y = ASpawnLocationsPilot[Index][SpawnY];
			z = ASpawnLocationsPilot[Index][SpawnZ]; 
			Angle = ASpawnLocationsPilot[Index][SpawnAngle]; 
			format(Msg, 128, "{008080}O Jogador {FFFFFF}%s {008080}entrou no server como piloto de avião.", Name);
		}
		case ClassPolice:
		{
		    new NormalPlayers, PolicePlayers, bool:CanSpawnAsCop = false;
			if (PlayersBeforePolice > 8)
			{
				for (new pid; pid < MAX_PLAYERS; pid++)
				{
					if (pid != playerid)
					{
					    if (GetPlayerInterior(pid) != 14)
					    {
							if (APlayerData[pid][LoggedIn] == true)
							{
								switch (APlayerData[pid][PlayerClass])
								{
									case ClassPolice:
									    PolicePlayers++;
									case ClassTruckDriver, ClassBusDriver, ClassPilot, ClassMafia, ClassCourier, ClassAssistance, ClassRoadWorker:
								    	NormalPlayers++;
								}
							}
						}
					}
				}
				if (PolicePlayers < (NormalPlayers / PlayersBeforePolice))
				    CanSpawnAsCop = true;
				else
				    CanSpawnAsCop = false; 
				if (CanSpawnAsCop == false)
				{
					GameTextForPlayer(playerid, "~r~O numero maximo de policiais online foi atingido.", 5000, 4);
					return 0;
				}
			}
		    if (APlayerData[playerid][PlayerScore] < 200)
		    {
				GameTextForPlayer(playerid, "~r~Voce precisa de ~w~200 ~r~pontos de score, para ser um ~b~policial~r~.", 5000, 4);
				return 0;
		    }
		    if (GetPlayerWantedLevel(playerid) > 0)
		    {
				GameTextForPlayer(playerid, "~r~Voce nao pode ser um policial enquanto estiver sendo procurado.", 5000, 4);
				return 0; 
		    }

			Index = random(sizeof(ASpawnLocationsPolice));
			x = ASpawnLocationsPolice[Index][SpawnX]; 
			y = ASpawnLocationsPolice[Index][SpawnY]; 
			z = ASpawnLocationsPolice[Index][SpawnZ]; 
			Angle = ASpawnLocationsPolice[Index][SpawnAngle]; 
			format(Msg, 128, "{0000FF}O Jogador {FFFFFF}%s {0000FF}entrou no server como policial.", Name);
		}
		case ClassMafia:
		{
			Index = random(sizeof(ASpawnLocationsMafia));
			x = ASpawnLocationsMafia[Index][SpawnX]; 
			y = ASpawnLocationsMafia[Index][SpawnY]; 
			z = ASpawnLocationsMafia[Index][SpawnZ]; 
			Angle = ASpawnLocationsMafia[Index][SpawnAngle];
			format(Msg, 128, "{8000FF}O Jogador {FFFFFF}%s {8000FF}entrou no server como mafioso.", Name);
		}
		case ClassCourier:
		{
			Index = random(sizeof(ASpawnLocationsCourier));
			x = ASpawnLocationsCourier[Index][SpawnX]; 
			y = ASpawnLocationsCourier[Index][SpawnY]; 
			z = ASpawnLocationsCourier[Index][SpawnZ];
			Angle = ASpawnLocationsCourier[Index][SpawnAngle]; 
			format(Msg, 128, "{FF00FF}O Jogador {FFFFFF}%s {FF00FF}entrou no server como agente dos correios.", Name);
		}
		case ClassAssistance:
		{
			Index = random(sizeof(ASpawnLocationsAssistance));
			x = ASpawnLocationsAssistance[Index][SpawnX]; 
			y = ASpawnLocationsAssistance[Index][SpawnY]; 
			z = ASpawnLocationsAssistance[Index][SpawnZ]; 
			Angle = ASpawnLocationsAssistance[Index][SpawnAngle];
			format(Msg, 128, "{A5ED54}O Jogador {FFFFFF}%s {A5ED54}entrou no server como mecânico.", Name);
		}
		case ClassRoadWorker:
		{
			Index = random(sizeof(ASpawnLocationsRoadWorker));
			x = ASpawnLocationsRoadWorker[Index][SpawnX]; 
			y = ASpawnLocationsRoadWorker[Index][SpawnY]; 
			z = ASpawnLocationsRoadWorker[Index][SpawnZ]; 
			Angle = ASpawnLocationsRoadWorker[Index][SpawnAngle]; 
			format(Msg, 128, "{FFFF80}O Jogador {FFFFFF}%s {FFFF80}entrou no server como operário do DNIT.", Name);
        }
	}
	SetSpawnInfo(playerid, 0, GetPlayerSkin(playerid), x, y, z, Angle, 0, 0, 0, 0, 0, 0);
	SendClientMessageToAll(0xFFFFFFFF, Msg);
    return 1;
}
public OnVehicleSpawn(vehicleid)
{
	AVehicleData[vehicleid][MafiaLoad] = false;
	if (AVehicleData[vehicleid][Owned] == false)
		AVehicleData[vehicleid][Fuel] = MaxFuel;
	if (AVehicleData[vehicleid][PaintJob] != 0)
	{
		ChangeVehiclePaintjob(vehicleid, AVehicleData[vehicleid][PaintJob] - 1);
	}
	ChangeVehicleColor(vehicleid, AVehicleData[vehicleid][Color1], AVehicleData[vehicleid][Color2]);
	for (new i; i < 14; i++)
	{
        RemoveVehicleComponent(vehicleid, GetVehicleComponentInSlot(vehicleid, i));
		if (AVehicleData[vehicleid][Components][i] != 0)
	        AddVehicleComponent(vehicleid, AVehicleData[vehicleid][Components][i]); 
	}

    return 1;
}
public OnVehicleRespray(playerid, vehicleid, color1, color2)
{
	if ((AVehicleData[vehicleid][Color1] != color1) || (AVehicleData[vehicleid][Color2] != color2))
	{
		RewardPlayer(playerid, -150, 0);
		SendClientMessage(playerid, 0x00FF00FF, "Veículo pintado!");
	}
	AVehicleData[vehicleid][Color1] = color1;
	AVehicleData[vehicleid][Color2] = color2;
	if (color1 == 0)
		AVehicleData[vehicleid][PaintJob] = 0;

	return 1;
}
public OnEnterExitModShop(playerid, enterexit, interiorid)
{
	return 1;
}
public OnVehicleMod(playerid, vehicleid, componentid)
{
	APlayerData[playerid][PlayerMoney] = APlayerData[playerid][PlayerMoney] - AVehicleModPrices[componentid - 1000];
	AVehicleData[vehicleid][Components][GetVehicleComponentType(componentid)] = componentid;
	return 1;
} 
public OnVehiclePaintjob(playerid, vehicleid, paintjobid)
{
    AVehicleData[vehicleid][PaintJob] = paintjobid + 1;

	return 1;
}
public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	new engine, lights, alarm, doors, bonnet, boot, objective;
 	if (AVehicleData[vehicleid][Fuel] > 0)
	{
		GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
		SetVehicleParamsEx(vehicleid, 1, 1, alarm, doors, bonnet, boot, objective);
	}
	GetPlayerPos(playerid, APlayerData[playerid][PreviousX], APlayerData[playerid][PreviousY], APlayerData[playerid][PreviousZ]);
	APlayerData[playerid][PreviousInt] = GetPlayerInterior(playerid);

	return 1;
}
public OnPlayerExitVehicle(playerid, vehicleid)
{
    StopAudioStreamForPlayer(playerid);
    if(IsABike(GetPlayerVehicleID(playerid)))
	{
        RemovePlayerAttachedObject(playerid, SLOT);
    }   
	new engine, lights, alarm, doors, bonnet, boot, objective;
	if (GetPlayerVehicleSeat(playerid) == 0)
	{
		GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
		SetVehicleParamsEx(vehicleid, 0, 0, alarm, doors, bonnet, boot, objective);
	}
	if (APlayerData[playerid][PlayerClass] == ClassPilot)
	{
		if (APlayerData[playerid][JobStarted] == true)
		{
			Pilot_EndJob(playerid);
			GameTextForPlayer(playerid, TXT_FailedMission, 5000, 4);
			RewardPlayer(playerid, -1000, 0);
		}
	}

	return 1;
}
public OnVehicleDeath(vehicleid)
{
	new HouseID = AVehicleData[vehicleid][BelongsToHouse];
	if (HouseID != 0)
	{
		if (AHouseData[HouseID][Insurance] == 0)
		{
			Vehicle_Delete(vehicleid);
		    HouseFile_Save(HouseID);
		}
	}

	return 1;
}
public OnPlayerStateChange(playerid,newstate,oldstate)
{   
    if(newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER)
	{
	    if(IsABike(GetPlayerVehicleID(playerid)))
	    {
			switch(GetPlayerSkin(playerid))
			{
		        #define SPAO{%0,%1,%2,%3,%4,%5} SetPlayerAttachedObject(playerid, SLOT, 18645, 2, (%0), (%1), (%2), (%3), (%4), (%5));
				case 0, 65, 74, 149, 208, 273:  SPAO{0.070000, 0.000000, 0.000000, 88.000000, 75.000000, 0.000000}
				case 1..6, 8, 14, 16, 22, 27, 29, 33, 41..49, 82..84, 86, 87, 119, 289: SPAO{0.070000, 0.000000, 0.000000, 88.000000, 77.000000, 0.000000}
				case 7, 10: SPAO{0.090000, 0.019999, 0.000000, 88.000000, 90.000000, 0.000000}
				case 9: SPAO{0.059999, 0.019999, 0.000000, 88.000000, 90.000000, 0.000000}
				case 11..13: SPAO{0.070000, 0.019999, 0.000000, 88.000000, 90.000000, 0.000000}
				case 15: SPAO{0.059999, 0.000000, 0.000000, 88.000000, 82.000000, 0.000000}
				case 17..21: SPAO{0.059999, 0.019999, 0.000000, 88.000000, 82.000000, 0.000000}
				case 23..26, 28, 30..32, 34..39, 57, 58, 98, 99, 104..118, 120..131: SPAO{0.079999, 0.019999, 0.000000, 88.000000, 82.000000, 0.000000}
				case 40: SPAO{0.050000, 0.009999, 0.000000, 88.000000, 82.000000, 0.000000}
				case 50, 100..103, 148, 150..189, 222: SPAO{0.070000, 0.009999, 0.000000, 88.000000, 82.000000, 0.000000}
				case 51..54: SPAO{0.100000, 0.009999, 0.000000, 88.000000, 82.000000, 0.000000}
				case 55, 56, 63, 64, 66..73, 75, 76, 78..81, 133..143, 147, 190..207, 209..219, 221, 247..272, 274..288, 290..293: SPAO{0.070000, 0.019999, 0.000000, 88.000000, 82.000000, 0.000000}
				case 59..62: SPAO{0.079999, 0.029999, 0.000000, 88.000000, 82.000000, 0.000000}
				case 77: SPAO{0.059999, 0.019999, 0.000000, 87.000000, 82.000000, 0.000000}
				case 85, 88, 89: SPAO{0.070000, 0.039999, 0.000000, 88.000000, 82.000000, 0.000000}
				case 90..97: SPAO{0.050000, 0.019999, 0.000000, 88.000000, 82.000000, 0.000000}
				case 132: SPAO{0.000000, 0.019999, 0.000000, 88.000000, 82.000000, 0.000000}
				case 144..146: SPAO{0.090000, 0.000000, 0.000000, 88.000000, 82.000000, 0.000000}
				case 220: SPAO{0.029999, 0.019999, 0.000000, 88.000000, 82.000000, 0.000000}
				case 223, 246: SPAO{0.070000, 0.050000, 0.000000, 88.000000, 82.000000, 0.000000}
				case 224..245: SPAO{0.070000, 0.029999, 0.000000, 88.000000, 82.000000, 0.000000}
				case 294: SPAO{0.070000, 0.019999, 0.000000, 91.000000, 84.000000, 0.000000}
				case 295: SPAO{0.050000, 0.019998, 0.000000, 86.000000, 82.000000, 0.000000}
				case 296..298: SPAO{0.064999, 0.009999, 0.000000, 88.000000, 82.000000, 0.000000}
				case 299: SPAO{0.064998, 0.019999, 0.000000, 88.000000, 82.000000, 0.000000}
		    }
		}
	}
	new vid, Name[24], Msg[128], engine, lights, alarm, doors, bonnet, boot, objective;
	switch (newstate)
	{
		case PLAYER_STATE_DRIVER:
		{
			vid = GetPlayerVehicleID(playerid);
			GetPlayerName(playerid, Name, sizeof(Name));
			if (AVehicleData[vid][Owned] == true)
			{
				if (strcmp(AVehicleData[vid][Owner], Name, false) != 0)
				{
					RemovePlayerFromVehicle(playerid);
					GetVehicleParamsEx(vid, engine, lights, alarm, doors, bonnet, boot, objective);
					SetVehicleParamsEx(vid, 0, 0, alarm, doors, bonnet, boot, objective);
					format(Msg, 128, TXT_SpeedometerCannotUseVehicle, AVehicleData[vid][Owner]);
					SendClientMessage(playerid, 0xFFFFFFFF, Msg);
				}
				if (AVehicleData[vid][Clamped] == true)
				{
					RemovePlayerFromVehicle(playerid);
					GetVehicleParamsEx(vid, engine, lights, alarm, doors, bonnet, boot, objective);
					SetVehicleParamsEx(vid, 0, 0, alarm, doors, bonnet, boot, objective);
					format(Msg, 128, TXT_SpeedometerClampedVehicle);
					SendClientMessage(playerid, 0xFFFFFFFF, Msg);
					format(Msg, 128, TXT_SpeedometerClampedVehicle2);
					SendClientMessage(playerid, 0xFFFFFFFF, Msg);
				}
			}
			if (APlayerData[playerid][PlayerClass] != ClassPolice)
			{
				if (AVehicleData[vid][StaticVehicle] == true)
				{
					switch (GetVehicleModel(vid))
					{
						case VehiclePoliceLSPD, VehiclePoliceSFPD, VehiclePoliceLVPD, VehicleHPV1000, VehiclePoliceRanger:
						{
							RemovePlayerFromVehicle(playerid);
							GetVehicleParamsEx(vid, engine, lights, alarm, doors, bonnet, boot, objective);
							SetVehicleParamsEx(vid, 0, 0, alarm, doors, bonnet, boot, objective);
							SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}Você não pode usar um veículo da classe dos: policiais.");
						}
					}
				}
			}
			if (APlayerData[playerid][PlayerClass] != ClassPilot)
			{
				if (AVehicleData[vid][StaticVehicle] == true)
				{
					switch (GetVehicleModel(vid))
					{
						case VehicleShamal, VehicleNevada, VehicleStuntPlane, VehicleDodo, VehicleMaverick, VehicleCargobob:
						{
							RemovePlayerFromVehicle(playerid);
							GetVehicleParamsEx(vid, engine, lights, alarm, doors, bonnet, boot, objective);
							SetVehicleParamsEx(vid, 0, 0, alarm, doors, bonnet, boot, objective);
							SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}Você não pode usar um veículo da classe dos: pilotos.");
						}
					}
				}
			}
		}
	}

	return 1;
}
public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	switch (APlayerData[playerid][PlayerClass])
	{
		case ClassPolice:
		{
			if (((newkeys & KEY_HANDBRAKE) && !(oldkeys & KEY_HANDBRAKE)) && (GetPlayerVehicleID(playerid) == 0))
				Police_FineNearbyPlayers(playerid);
			if (((newkeys & KEY_ACTION) && !(oldkeys & KEY_ACTION)) && (GetPlayerVehicleID(playerid) != 0))
				Police_WarnNearbyPlayers(playerid);
		}
		case ClassAssistance:
		{
			if (((newkeys & KEY_HANDBRAKE) && !(oldkeys & KEY_HANDBRAKE)) && (GetPlayerVehicleID(playerid) == 0))
				Assistance_FixVehicle(playerid);
			if (((newkeys & KEY_ACTION) && !(oldkeys & KEY_ACTION)) && (GetPlayerVehicleID(playerid) != 0))
				Assistance_FixOwnVehicle(playerid);
		}
	}
	if(GetVehicleModel(GetPlayerVehicleID(playerid)) == VehicleTowTruck)
	{
		if(newkeys & KEY_FIRE)
		{
			new closest = GetClosestVehicle(playerid);
			if(VehicleToPlayer(playerid, closest) < 10) 
				AttachTrailerToVehicle(closest, GetPlayerVehicleID(playerid));
		}
	}
	if ((newkeys & KEY_CROUCH) && !(oldkeys & KEY_CROUCH))
	{
		if (GetPlayerVehicleSeat(playerid) == 0)
		{
			for (new i; i < sizeof(ARefuelPickups); i++)
			{
				if(IsPlayerInRangeOfPoint(playerid, 2.5, ARefuelPickups[i][pux], ARefuelPickups[i][puy], ARefuelPickups[i][puz]))
				{
					GameTextForPlayer(playerid, TXT_Refuelling, 3000, 4);
					TogglePlayerControllable(playerid, 0);
				    SetTimerEx("RefuelVehicle", 5000, false, "i", playerid);
					break;
				}
			}
		}
	}
    return 1;
}
forward VehicleToPlayer(playerid,vehicleid);
public VehicleToPlayer(playerid, vehicleid)
{
	new Float:pX, Float:pY, Float:pZ, Float:cX, Float:cY, Float:cZ, Float:distance;
	GetPlayerPos(playerid, pX, pY, pZ);
	GetVehiclePos(vehicleid, cX, cY, cZ);
	distance = floatsqroot(floatpower(floatabs(floatsub(cX, pX)), 2) + floatpower(floatabs(floatsub(cY, pY)), 2) + floatpower(floatabs(floatsub(cZ, pZ)), 2));
	return floatround(distance);
}
forward GetClosestVehicle(playerid);
public GetClosestVehicle(playerid)
{
	new Float:distance = 99999.000+1, Float:distance2, result = -1;
	for(new i = 0; i < MAX_VEHICLES; i++)
	{
		if (GetPlayerVehicleID(playerid) != i)
		{
			distance2 = VehicleToPlayer(playerid, i);
			if(distance2 < distance)
			{
				distance = distance2;
				result = i;
			}
		}
	}
	return result;
}
stock DebugKeys(playerid, newkeys, oldkeys)
{
	if ((newkeys & KEY_FIRE) && !(oldkeys & KEY_FIRE))
		SendClientMessage(playerid, 0x0000FFFF, "You pressed the KEY_FIRE key");
	if ((newkeys & KEY_ACTION) && !(oldkeys & KEY_ACTION))
		SendClientMessage(playerid, 0x0000FFFF, "You pressed the KEY_ACTION key");
	if ((newkeys & KEY_CROUCH) && !(oldkeys & KEY_CROUCH))
		SendClientMessage(playerid, 0x0000FFFF, "You pressed the KEY_CROUCH key");
	if ((newkeys & KEY_SPRINT) && !(oldkeys & KEY_SPRINT))
		SendClientMessage(playerid, 0x0000FFFF, "You pressed the KEY_SPRINT key");
	if ((newkeys & KEY_SECONDARY_ATTACK) && !(oldkeys & KEY_SECONDARY_ATTACK))
		SendClientMessage(playerid, 0x0000FFFF, "You pressed the KEY_SECONDARY_ATTACK key");
	if ((newkeys & KEY_JUMP) && !(oldkeys & KEY_JUMP))
		SendClientMessage(playerid, 0x0000FFFF, "You pressed the KEY_JUMP key");
	if ((newkeys & KEY_LOOK_RIGHT) && !(oldkeys & KEY_LOOK_RIGHT))
		SendClientMessage(playerid, 0x0000FFFF, "You pressed the KEY_LOOK_RIGHT key");
	if ((newkeys & KEY_HANDBRAKE) && !(oldkeys & KEY_HANDBRAKE))
		SendClientMessage(playerid, 0x0000FFFF, "You pressed the KEY_HANDBRAKE key");
	if ((newkeys & KEY_LOOK_LEFT) && !(oldkeys & KEY_LOOK_LEFT))
		SendClientMessage(playerid, 0x0000FFFF, "You pressed the KEY_LOOK_LEFT key");
	if ((newkeys & KEY_SUBMISSION) && !(oldkeys & KEY_SUBMISSION))
		SendClientMessage(playerid, 0x0000FFFF, "You pressed the KEY_SUBMISSION key");
	if ((newkeys & KEY_LOOK_BEHIND) && !(oldkeys & KEY_LOOK_BEHIND))
		SendClientMessage(playerid, 0x0000FFFF, "You pressed the KEY_LOOK_BEHIND key");
	if ((newkeys & KEY_WALK) && !(oldkeys & KEY_WALK))
		SendClientMessage(playerid, 0x0000FFFF, "You pressed the KEY_WALK key");
	if ((newkeys & KEY_ANALOG_UP) && !(oldkeys & KEY_ANALOG_UP))
		SendClientMessage(playerid, 0x0000FFFF, "You pressed the KEY_ANALOG_UP key");
	if ((newkeys & KEY_ANALOG_DOWN) && !(oldkeys & KEY_ANALOG_DOWN))
		SendClientMessage(playerid, 0x0000FFFF, "You pressed the KEY_ANALOG_DOWN key");
	if ((newkeys & KEY_ANALOG_LEFT) && !(oldkeys & KEY_ANALOG_LEFT))
		SendClientMessage(playerid, 0x0000FFFF, "You pressed the KEY_ANALOG_LEFT key");
	if ((newkeys & KEY_ANALOG_RIGHT) && !(oldkeys & KEY_ANALOG_RIGHT))
		SendClientMessage(playerid, 0x0000FFFF, "You pressed the KEY_ANALOG_RIGHT key");
	if ((newkeys & KEY_UP) && !(oldkeys & KEY_UP))
		SendClientMessage(playerid, 0x0000FFFF, "You pressed the KEY_UP key");
	if ((newkeys & KEY_DOWN) && !(oldkeys & KEY_DOWN))
		SendClientMessage(playerid, 0x0000FFFF, "You pressed the KEY_DOWN key");
	if ((newkeys & KEY_LEFT) && !(oldkeys & KEY_LEFT))
		SendClientMessage(playerid, 0x0000FFFF, "You pressed the KEY_LEFT key");
	if ((newkeys & KEY_RIGHT) && !(oldkeys & KEY_RIGHT))
		SendClientMessage(playerid, 0x0000FFFF, "You pressed the KEY_RIGHT key");

	return 1;
} 
public timed()
{
new str2[128];
new hour;
new minute;
new second;

gettime(hour,minute,second);
format(str2, sizeof(str2), "%d:%d:%d", hour, minute, second);
TextDrawSetString(Text:txtTimeDisp, str2);
SetWorldTime(hour+3);
} 
stock IsABike(vehicleid) 
{
	new result;
	new model = GetVehicleModel(vehicleid);
    switch(model)
    {
        case 509, 481, 510, 462, 448, 581, 522, 461, 521, 523, 463, 586, 468, 471: result = model;
        default: result = 0;
    }
	return result;
}
public Climas()
{
 new cl = random(13);		 
 if(cl == 0) { SetWeather(0);SendClientMessageToAll(CLIMATEMPO, "[Rádio] Dia Limpo, Mínima de {0342F8}22°C{FFFFAF}, Máxima de {F80303}26°C{FFFFAF}."); }
 if(cl == 1) { SetWeather(1);SendClientMessageToAll(CLIMATEMPO, "[Rádio] Clima Seco, Mínima de {0342F8}24°C{FFFFAF}, Máxima de {F80303}28°C{FFFFAF}."); }
 if(cl == 2) { SetWeather(3);SendClientMessageToAll(CLIMATEMPO, "[Rádio] Ventos Fortes, Mínima de {0342F8}19°C{FFFFAF}, Máxima de {F80303}22°C{FFFFAF}."); }
 if(cl == 3) { SetWeather(7);SendClientMessageToAll(CLIMATEMPO, "[Rádio] Tempo Nublado com Ventos fortes, Mínima de {0342F8}15°C{FFFFAF}, Máxima de {F80303}18°C{FFFFAF}."); }
 if(cl == 4) { SetWeather(8);SendClientMessageToAll(CLIMATEMPO, "[Rádio] Tempo Chuvoso com Ventos fortes, Mínima de {0342F8}12°C{FFFFAF}, Máxima de {F80303}15°C{FFFFAF}."); }
 if(cl == 5) { SetWeather(9);SendClientMessageToAll(CLIMATEMPO, "[Rádio] Neblina forte, Mínima de {0342F8}2°C{FFFFAF}, Máxima de {F80303}5°C{FFFFAF}."); }
 if(cl == 6) { SetWeather(11);SendClientMessageToAll(CLIMATEMPO, "[Rádio] Céu Limpo, Mínima de {0342F8}22°C{FFFFAF}, Máxima de {F80303}26°C{FFFFAF}."); }
 if(cl == 7) { SetWeather(12);SendClientMessageToAll(CLIMATEMPO, "[Rádio] Nublado com Ventos fracos, Mínima de {0342F8}15°C{FFFFAF}, Máxima de {F80303}18°C{FFFFAF}."); }
 if(cl == 8) { SetWeather(13);SendClientMessageToAll(CLIMATEMPO, "[Rádio] Céu amarelado, Mínima de {0342F8}19°C{FFFFAF}, Máxima de {F80303}21°C{FFFFAF}."); }
 if(cl == 9) { SetWeather(15);SendClientMessageToAll(CLIMATEMPO, "[Rádio] Tempo Nublado, Mínima de {0342F8}12°C{FFFFAF}, Máxima de {F80303}15°C{FFFFAF}."); }
 if(cl == 10) { SetWeather(16);SendClientMessageToAll(CLIMATEMPO, "[Rádio] Chuva Forte, Cuidado com a pista escorregadia, Mínima de {0342F8}4°C{FFFFAF}, Máxima de {F80303}7°C{FFFFAF}."); }
 if(cl == 11) { SetWeather(17);SendClientMessageToAll(CLIMATEMPO, "[Rádio] Céu Alaranjado, Mínima de {0342F8}11°C{FFFFAF}, Máxima de {F80303}14°C{FFFFAF}."); }
 if(cl == 12) { SetWeather(19);SendClientMessageToAll(CLIMATEMPO, "[Rádio] Neblina Densa com Vento forte, Mínima de {0342F8}-2°C{FFFFAF}, Máxima de {F80303}1°C{FFFFAF}."); }
}
stock GetOnLinePlayers()
{
	new OnLine;
	for(new i, g = GetMaxPlayers(); i < g; i++)
		if(IsPlayerConnected(i))
			OnLine++;
	return OnLine;
}
Objetos()
{
// Big City
CreateDynamicObject(18483, 2953.3994140625, -780.7998046875, 10, 0, 0, 0);
CreateDynamicObject(18477, 3030, -754.7998046875, 9.8999996185303, 0, 0, 90.252685546875);
CreateDynamicObject(18477, 3084.1999511719, -736.20001220703, 9.8999996185303, 0, 0, 269.74490356445);
CreateDynamicObject(3996, 3176, -710.69921875, 9.8999996185303, 0, 0, 0);
CreateDynamicObject(4644, 3264.8994140625, -672.2998046875, 15, 0, 0, 269.74182128906);
CreateDynamicObject(4644, 3340.099609375, -750.099609375, 15, 0, 0, 89.280395507813);
CreateDynamicObject(3486, 3208.3999023438, -638, 17, 0, 0, 90.255096435547);
CreateDynamicObject(3485, 3208.1000976563, -667.90002441406, 16.799999237061, 0, 0, 88.775024414063);
CreateDynamicObject(3597, 3214.3999023438, -691.90002441406, 12.60000038147, 0, 0, 88.775512695313);
CreateDynamicObject(3313, 3187.1999511719, -688.90002441406, 12.800000190735, 0, 0, 358.51684570313);
CreateDynamicObject(6039, 3049, -744.5, 18.299999237061, 0, 0, 0);
CreateDynamicObject(6039, 3066.5, -744.5, 18.299999237061, 0, 0, 0);
CreateDynamicObject(8650, 3013.1999511719, -755.40002441406, 11.10000038147, 0, 0, 0);
CreateDynamicObject(8650, 3013.1999511719, -733.40002441406, 11.10000038147, 0, 0, 0);
CreateDynamicObject(5655, 3331.5, -695.90002441406, 14.300000190735, 0, 0, 193.82629394531);
CreateDynamicObject(3653, 3287.6000976563, -725.29998779297, 23.5, 0, 0, 268.26531982422);
CreateDynamicObject(3619, 3249, -639.3994140625, 13.300000190735, 0, 0, 88.775024414063);
CreateDynamicObject(3603, 3255.1999511719, -670.40002441406, 15.300000190735, 0, 0, 269.74490356445);
CreateDynamicObject(3604, 3249.3000488281, -693.59997558594, 12.300000190735, 0, 0, 269.74182128906);
CreateDynamicObject(8650, 3262.3000488281, -720.40002441406, 13.89999961853, 10.354614257813, 0, 269.74182128906);
CreateDynamicObject(8650, 3233, -720.29998779297, 11.10000038147, 0, 0, 269.74182128906);
CreateDynamicObject(8650, 3288.1000976563, -701.09997558594, 18.700000762939, 10.357147216797, 0, 269.74487304688);
CreateDynamicObject(8650, 3268.1000976563, -701, 15.10000038147, 10.357147216797, 0, 269.74490356445);
CreateDynamicObject(3316, 3161.8999023438, -682.09997558594, 13.199999809265, 0, 0, 0);
CreateDynamicObject(3584, 3194, -727.09997558594, 14.60000038147, 0, 0, 269.74490356445);
CreateDynamicObject(4825, 3368.599609375, -861.3994140625, 7.4000000953674, 0, 0, 89.219970703125);
CreateDynamicObject(6522, 3324.1000976563, -849.40002441406, 18.299999237061, 0, 0, 180.50537109375);
CreateDynamicObject(7885, 3412.3000488281, -846.20001220703, 9.8999996185303, 0, 0, 0);
CreateDynamicObject(987, 3325.8000488281, -807.59997558594, 9.8999996185303, 0, 0, 267.806640625);
CreateDynamicObject(987, 3326.1999511719, -796.5, 9.8999996185303, 0, 0, 268.26531982422);
CreateDynamicObject(987, 3338.1000976563, -796.59997558594, 9.8999996185303, 0, 0, 180.5104675293);
CreateDynamicObject(987, 3350.1000976563, -796.59997558594, 9.8999996185303, 0, 0, 179.48950195313);
CreateDynamicObject(987, 3359.1000976563, -796.59997558594, 9.8999996185303, 0, 0, 179.03088378906);
CreateDynamicObject(987, 3390.6999511719, -797, 9.8999996185303, 0, 358.5205078125, 179.03088378906);
CreateDynamicObject(987, 3401.6000976563, -797.20001220703, 9.8999996185303, 0, 0, 179.03088378906);
CreateDynamicObject(987, 3413.1000976563, -797.29998779297, 9.8999996185303, 0, 0, 179.03082275391);
CreateDynamicObject(987, 3412.8000488281, -808.79998779297, 9.8999996185303, 0, 358.52041625977, 88.775451660156);
CreateDynamicObject(3749, 3369.3000488281, -797.79998779297, 15.800000190735, 0, 0, 0);
CreateDynamicObject(8659, 3360, -781.20001220703, 11, 0, 0, 269.04815673828);
CreateDynamicObject(8659, 3360.5, -752.09997558594, 11, 0, 0.000244140625, 268.81622314453);
CreateDynamicObject(8659, 3360.6999511719, -736.70001220703, 11, 0, 0, 269.74490356445);
CreateDynamicObject(3598, 3311.5, -725.29998779297, 22, 0, 4.4387817382813, 0);
CreateDynamicObject(3617, 3333.6999511719, -723.70001220703, 17.5, 0, 348.16223144531, 178.00598144531);
CreateDynamicObject(8657, 3345.6000976563, -721.59997558594, 13.39999961853, 11.832733154297, 358.48828125, 87.605926513672);
CreateDynamicObject(8657, 3361.8999023438, -701.90002441406, 10.60000038147, 0, 0, 269.74182128906);
CreateDynamicObject(8657, 3379.8999023438, -738.20001220703, 10.60000038147, 0, 0, 358.51684570313);
CreateDynamicObject(8657, 3379.1000976563, -769, 10.60000038147, 0, 0, 358.51684570313);
CreateDynamicObject(8657, 3378.8000488281, -780.70001220703, 10.60000038147, 0, 0, 358.51684570313);
CreateDynamicObject(8657, 3066.3000488281, -770.59997558594, 11.199999809265, 0, 0, 88.775512695313);
CreateDynamicObject(8657, 3049.8999023438, -770.90002441406, 11.199999809265, 0, 0, 90.234680175781);
CreateDynamicObject(8040, 3236.19921875, -583.69921875, 10.60000038147, 0, 0, 269.55505371094);
CreateDynamicObject(8841, 3236.1999511719, -581.5, 12.39999961853, 0, 0, 90.255096435547);
CreateDynamicObject(4639, 3228.2998046875, -622.599609375, 11.5, 0, 0, 358.12133789063);
CreateDynamicObject(8390, 3099.5, -632.19921875, 29.299999237061, 0, 0, 0.0164794921875);
CreateDynamicObject(8657, 3015, -713.3994140625, 11.199999809265, 0, 0, 337.80377197266);
CreateDynamicObject(8657, 3023.1999511719, -703.40002441406, 11.199999809265, 0, 0, 117.24487304688);
CreateDynamicObject(8657, 3041.3000488281, -700.40002441406, 11, 0, 0, 89.132629394531);
CreateDynamicObject(10606, 3149.3994140625, -745, 18.799999237061, 0, 0, 0);
CreateDynamicObject(3311, 3117.19921875, -732.7998046875, 12.89999961853, 0, 0, 180.48889160156);
CreateDynamicObject(1337, 3143.0869140625, -788.9716796875, -25.899772644043, 0, 0, 0);
CreateDynamicObject(8657, 3101, -735.90002441406, 11.10000038147, 0, 0, 0);
CreateDynamicObject(8657, 3101, -756.79998779297, 11.10000038147, 0, 0, 0);
CreateDynamicObject(8657, 3103.3999023438, -766.5, 11.199999809265, 0, 0, 339.28570556641);
CreateDynamicObject(8657, 3098.6000976563, -780.40002441406, 11, 0, 0, 306.01022338867);
CreateDynamicObject(8657, 3071.6999511719, -789.70001220703, 11, 0, 0, 269.74490356445);
CreateDynamicObject(8657, 3041.3999023438, -789.5, 11.10000038147, 0, 0, 269.74487304688);
CreateDynamicObject(8657, 3010.6000976563, -789.40002441406, 11.10000038147, 0, 0, 269.74487304688);
CreateDynamicObject(8657, 2997.69921875, -771.19921875, 11, 0, 0, 269.74182128906);
CreateDynamicObject(9131, 3101.8999023438, -720.70001220703, 11.10000038147, 0, 0, 0);
CreateDynamicObject(9131, 3102.6000976563, -720.70001220703, 11.10000038147, 0, 0, 0);
CreateDynamicObject(9131, 3103.3000488281, -720.70001220703, 11.10000038147, 0, 0, 0);
CreateDynamicObject(9131, 3104, -720.70001220703, 11.10000038147, 0, 0, 0);
CreateDynamicObject(9131, 3104.6999511719, -720.70001220703, 11.10000038147, 0, 0, 0);
CreateDynamicObject(9131, 3104.6999511719, -721.40002441406, 11.10000038147, 0, 0, 0);
CreateDynamicObject(9131, 3104.6999511719, -722.09997558594, 11.10000038147, 0, 0, 0);
CreateDynamicObject(9131, 3104.6999511719, -722.79998779297, 11.10000038147, 0, 0, 0);
CreateDynamicObject(9131, 3104.6999511719, -723.5, 11.10000038147, 0, 0, 0);
CreateDynamicObject(1423, 3235.1999511719, -624, 10.5, 0, 0, 269.74490356445);
CreateDynamicObject(1423, 3240.3000488281, -625.09997558594, 10.699999809265, 0, 0, 269.74490356445);
CreateDynamicObject(1423, 3230.2998046875, -623.8994140625, 10.5, 0, 0, 271.21948242188);
CreateDynamicObject(3749, 2923.3999023438, -780.59997558594, 15.699999809265, 0, 0, 269.74490356445);
CreateDynamicObject(2773, 3104.3000488281, -701.09997558594, 10.5, 0, 0, 0);
CreateDynamicObject(2773, 3089.8000488281, -701.40002441406, 10.5, 0, 0, 0);
CreateDynamicObject(2773, 3093.6000976563, -701.40002441406, 10.5, 0, 0, 0);
CreateDynamicObject(2773, 3100.8999023438, -701.40002441406, 10.5, 0, 0, 0);
CreateDynamicObject(2773, 3097.5, -701.40002441406, 10.5, 0, 0, 0);
CreateDynamicObject(1231, 3362.1999511719, -788.20001220703, 12.5, 0, 0, 0);
CreateDynamicObject(1231, 3376.6999511719, -769.5, 12.699999809265, 0, 0, 0);
CreateDynamicObject(1231, 3362.8000488281, -756.59997558594, 12.699999809265, 0, 0, 0);
CreateDynamicObject(1231, 3377.1999511719, -747.70001220703, 12.699999809265, 0, 0, 0);
CreateDynamicObject(1231, 3363.3000488281, -732.20001220703, 12.699999809265, 0, 0, 0);
CreateDynamicObject(1231, 3378.5, -722.5, 12.699999809265, 0, 0, 0);
CreateDynamicObject(1290, 3350.3999023438, -716.90002441406, 17.5, 0, 0, 278.62246704102);
CreateDynamicObject(1290, 3302.1999511719, -705.59997558594, 26.299999237061, 0, 0, 268.26531982422);
CreateDynamicObject(1315, 3014.3000488281, -776.59997558594, 13.199999809265, 0, 0, 91.346801757813);
CreateDynamicObject(1363, 3133.6999511719, -719.40002441406, 10.89999961853, 0, 0, 0);
CreateDynamicObject(1231, 3282, -716.5, 19.60000038147, 0, 0, 262.3469543457);
CreateDynamicObject(1231, 3249.6999511719, -705.09997558594, 13.300000190735, 5.9183654785156, 0, 269.74182128906);
CreateDynamicObject(1231, 3244.3000488281, -716.79998779297, 12.60000038147, 0, 0, 274.18029785156);
CreateDynamicObject(1231, 3229.5, -671.90002441406, 12.699999809265, 0, 0, 0);
CreateDynamicObject(1231, 3241.1999511719, -630.40002441406, 12.699999809265, 0, 0, 0);
CreateDynamicObject(1231, 3196, -704.79998779297, 12.699999809265, 0, 0, 0);
CreateDynamicObject(1231, 3169.3000488281, -716.59997558594, 12.699999809265, 0, 0, 266.78573608398);
CreateDynamicObject(1231, 3084.3999023438, -717.20001220703, 12.699999809265, 0, 0, 330.40817260742);
CreateDynamicObject(3091, 3097.8999023438, -562.59997558594, 10.60000038147, 0, 0, 0);
CreateDynamicObject(3091, 3102.3999023438, -562.79998779297, 10.60000038147, 0, 0, 0);
CreateDynamicObject(3091, 3107, -562.79998779297, 10.60000038147, 0, 0, 0);
CreateDynamicObject(4206, 1479.5546875, -1639.609375, 13.6484375, 0, 0, 0);
CreateDynamicObject(1609, 3370.8000488281, -882.29998779297, 11.199999809265, 0, 0, 0);
CreateDynamicObject(4165, 3413.6000976563, -712, 9.8000001907349, 0, 0, 0);
CreateDynamicObject(3607, 3401, -734.09997558594, 15.199999809265, 0, 0, 0);
CreateDynamicObject(3619, 3392, -698.90002441406, 13.60000038147, 0, 0, 0);
CreateDynamicObject(6137, 3419.1999511719, -695.59997558594, 14.5, 0, 0, 271.22143554688);
CreateDynamicObject(7929, 3429.6000976563, -736.40002441406, 16.60000038147, 0, 0, 177.55126953125);
CreateDynamicObject(9259, 3441.5, -697.70001220703, 16, 0, 0, 91.730346679688);
CreateDynamicObject(13681, 3468.8999023438, -693.90002441406, 14.699999809265, 0, 0, 1.4776611328125);
CreateDynamicObject(6285, 3461.8994140625, -733.099609375, 15.300000190735, 0, 0, 181.21398925781);
CreateDynamicObject(8659, 3439, -739.5, 10.89999961853, 0, 0, 88.387756347656);
CreateDynamicObject(8659, 3439.1000976563, -734.79998779297, 10.89999961853, 0, 0, 88.765258789063);
CreateDynamicObject(3666, 2981.5, -780.70001220703, 10.199999809265, 0, 0, 0);
CreateDynamicObject(3666, 3056.6000976563, -780.40002441406, 10.10000038147, 0, 0, 0);
CreateDynamicObject(3666, 3127, -710.70001220703, 10.10000038147, 0, 0, 0);
CreateDynamicObject(3666, 3412.3999023438, -711.90002441406, 9.8000001907349, 0, 0, 0);
CreateDynamicObject(3666, 3369.8999023438, -758.59997558594, 10, 0, 0, 0);
CreateDynamicObject(3666, 3336.8000488281, -711.59997558594, 14.10000038147, 0, 0, 0);
CreateDynamicObject(3666, 3235, -665.79998779297, 10.10000038147, 0, 0, 0);
CreateDynamicObject(9829, 3540, -709.19921875, -55.5, 0, 0, 181.57653808594);
CreateDynamicObject(7191, 3482.6999511719, -680.5, 11.89999961853, 0, 0, 0);
CreateDynamicObject(7191, 3477.1999511719, -748.79998779297, 12.10000038147, 0, 0, 0);
CreateDynamicObject(4638, 3480.8000488281, -705.90002441406, 11.60000038147, 0, 0, 180.10217285156);
CreateDynamicObject(1423, 3483, -712.09997558594, 10.39999961853, 0, 0, 0);
CreateDynamicObject(990, 3479.3000488281, -701.79998779297, 11.39999961853, 0, 0, 93.214263916016);
CreateDynamicObject(4100, 3484, -723.79998779297, 11.39999961853, 0, 0, 51.785705566406);
CreateDynamicObject(1423, 3483, -717, 10.5, 0, 0, 0);
CreateDynamicObject(1423, 3483, -706.79998779297, 10.39999961853, 0, 0, 0);
CreateDynamicObject(4726, 3499.6999511719, -684.09997558594, 8.8999996185303, 0, 0, 179.35717773438);
CreateDynamicObject(5154, 3573.1999511719, -756.20001220703, -3, 0, 0, 1.4795837402344);
CreateDynamicObject(1320, 3228.6999511719, -703.59997558594, 11.5, 0, 0, 349.66333007813);
CreateDynamicObject(1321, 3228.6000976563, -716.40002441406, 11.39999961853, 0, 0, 172.33685302734);
CreateDynamicObject(3521, 3030.5, -770.5, 11.5, 0, 0, 281.97961425781);
CreateDynamicObject(8406, 3096.1000976563, -702.29998779297, 15.5, 0, 0, 0);
CreateDynamicObject(10236, 3224.8999023438, -622, 20.700000762939, 0, 0, 358.52041625977);
CreateDynamicObject(11395, 3368.6999511719, -831.40002441406, 18, 0, 0, 179.16314697266);
CreateDynamicObject(5817, 3571.8000488281, -742.40002441406, 3.7000000476837, 0, 0, 0);
CreateDynamicObject(5817, 3600.6000976563, -743.90002441406, 3.7999999523163, 0, 0, 0);
CreateDynamicObject(5154, 3601, -755, -3, 0, 0, 1.4795837402344);
CreateDynamicObject(1280, 3554.3000488281, -733.20001220703, 10.199999809265, 0, 0, 270.50003051758);
CreateDynamicObject(1280, 3557.8000488281, -733, 10.199999809265, 0, 0, 270.51022338867);
CreateDynamicObject(1280, 3555.3000488281, -702.59997558594, 10.199999809265, 0, 0, 92.081634521484);
CreateDynamicObject(1280, 3559.3999023438, -702.5, 10.199999809265, 0, 0, 91.346923828125);
CreateDynamicObject(1281, 3557.8000488281, -731.20001220703, 10.60000038147, 0, 0, 0);
CreateDynamicObject(1281, 3554, -730.90002441406, 10.60000038147, 0, 0, 0);
CreateDynamicObject(1281, 3555, -704.5, 10.60000038147, 0, 0, 0);
CreateDynamicObject(1281, 3559.1000976563, -704.5, 10.60000038147, 0, 0, 0);
CreateDynamicObject(618, 3610.5, -724.79998779297, 9.8000001907349, 0, 0, 0);
CreateDynamicObject(618, 3611.1000976563, -718.20001220703, 9.8000001907349, 0, 0, 0);
CreateDynamicObject(619, 3613.5, -707.09997558594, 9.8000001907349, 0, 0, 78.765289306641);
CreateDynamicObject(623, 3611.1000976563, -703.40002441406, 9.8000001907349, 0, 0, 0);
CreateDynamicObject(624, 3611, -703.29998779297, 10.5, 0, 0, 272.72448730469);
CreateDynamicObject(629, 3613.6000976563, -706.70001220703, 9.8000001907349, 0, 0, 275.67346191406);
CreateDynamicObject(645, 3601.8000488281, -702.40002441406, 9.8000001907349, 0, 0, 0);
CreateDynamicObject(669, 3612.3999023438, -729.40002441406, 9.8000001907349, 0, 0, 0);
CreateDynamicObject(673, 3461.6000976563, -718.29998779297, 9.8999996185303, 0, 0, 0);
CreateDynamicObject(673, 3409.6000976563, -706, 9.8999996185303, 0, 0, 0);
CreateDynamicObject(673, 3355, -718.59997558594, 10.699999809265, 0, 0, 0);
CreateDynamicObject(673, 3312.3999023438, -717.29998779297, 19, 0, 0, 0);
CreateDynamicObject(673, 3169.8999023438, -704.70001220703, 10, 0, 0, 0);
CreateDynamicObject(673, 3098.3999023438, -721, 10, 0, 0, 0);
CreateDynamicObject(673, 3097.8999023438, -733.79998779297, 10, 0, 0, 0);
CreateDynamicObject(673, 3097.6000976563, -757.90002441406, 10, 0, 0, 0);
CreateDynamicObject(673, 3097.3000488281, -774.59997558594, 10, 0, 0, 0);
CreateDynamicObject(673, 3088.5, -785, 10, 0, 0, 0);
CreateDynamicObject(673, 3073.1000976563, -787, 10, 0, 0, 0);
CreateDynamicObject(673, 3056.3999023438, -786.20001220703, 10, 0, 0, 0);
CreateDynamicObject(673, 3075, -774.70001220703, 10, 0, 0, 0);
CreateDynamicObject(673, 3054.3000488281, -774.40002441406, 10, 0, 0, 0);
CreateDynamicObject(673, 3039.3000488281, -786.09997558594, 10, 0, 0, 0);
CreateDynamicObject(673, 3016, -765.20001220703, 10, 0, 0, 0);
CreateDynamicObject(673, 3016.1000976563, -741.40002441406, 10, 0, 0, 0);
CreateDynamicObject(673, 3016.5, -719.5, 10, 0, 0, 0);
CreateDynamicObject(673, 3030.8000488281, -704.90002441406, 10, 0, 0, 0);
}
