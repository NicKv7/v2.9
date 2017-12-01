/**********************
****[100% REVISADO]****
***********************/
RewardPlayer(playerid, Money, Points)
{
	APlayerData[playerid][PlayerMoney] = APlayerData[playerid][PlayerMoney] + Money;
	APlayerData[playerid][PlayerScore] = APlayerData[playerid][PlayerScore] + Points;
}
Vehicle_AddStatic(vModel, Float:vX, Float:vY, Float:vZ, Float:vRotation, vC1, vC2, vSpawnDelay)
{
	new vid = AddStaticVehicleEx(vModel, vX, vY, vZ, vRotation, vC1, vC2, vSpawnDelay);
    AVehicleData[vid][Model] = vModel;
    AVehicleData[vid][Fuel] = MaxFuel;
    AVehicleData[vid][Color1] = vC1;
    AVehicleData[vid][Color2] = vC2;
	AVehicleData[vid][StaticVehicle] = true;
	return vid;
}
Vehicle_Create(vModel, Float:vX, Float:vY, Float:vZ, Float:vRotation, vC1, vC2, vSpawnDelay)
{
	new vid = CreateVehicle(vModel, vX, vY, vZ, vRotation, vC1, vC2, vSpawnDelay);
    AVehicleData[vid][Model] = vModel;
    AVehicleData[vid][Fuel] = MaxFuel;
    AVehicleData[vid][Color1] = vC1;
    AVehicleData[vid][Color2] = vC2;

	return vid;
}
Vehicle_Delete(vid)
{
	new HouseID, CarSlot;
	HouseID = AVehicleData[vid][BelongsToHouse];
	if (HouseID != 0)
	{
		for (new i; i < 10; i++)
		{
		    if (AHouseData[HouseID][VehicleIDs][i] == vid)
		    {
		        CarSlot = i;
				break; 
			}
		}
		AHouseData[HouseID][VehicleIDs][CarSlot] = 0;
	}
	DestroyVehicle(vid);
	AVehicleData[vid][Owned] = false;
	AVehicleData[vid][Owner] = 0;
	AVehicleData[vid][Model] = 0;
	AVehicleData[vid][PaintJob] = 0;
	for (new i; i < 14; i++)
	    AVehicleData[vid][Components][i] = 0;
	AVehicleData[vid][Color1] = 0;
	AVehicleData[vid][Color2] = 0;
	AVehicleData[vid][SpawnX] = 0.0;
	AVehicleData[vid][SpawnY] = 0.0;
	AVehicleData[vid][SpawnZ] = 0.0;
	AVehicleData[vid][SpawnRot] = 0.0;
	AVehicleData[vid][BelongsToHouse] = 0;
}
Locations_CheckDistance(LocationA, LocationB, Float:Range)
{
	new Float:Xa, Float:Ya, Float:Xb, Float:Yb, Float:X, Float:Y;
	Xa = ALocations[LocationA][LocX];
	Ya = ALocations[LocationA][LocY];
	Xb = ALocations[LocationB][LocX];
	Yb = ALocations[LocationB][LocY];
	Y = Yb - Ya;
	X = Xb - Xa;
	if (((X * X) + (Y * Y)) > (Range * Range))
		return 1; 
	else
	    return 0; 
}
Player_PortOutAdminZone(playerid, Float:x1, Float:y1, Float:z1, Float:x2, Float:y2, Float:z2, Float:x3, Float:y3, Float:z3)
{
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);
	if (APlayerData[playerid][PlayerLevel] == 0)
		if ((x1 < x) && (x < x2))
		    if ((y1 < y) && (y < y2))
		        if ((z1 < z) && (z < z2))
				{
					SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}Você não tem permissão dentro de uma área da administração.");
					SetPlayerPos(playerid, x3, y3, z3); 
				}
}
SendAdminText(playerid, command[], text[])
{
	new Name[24], Msg[128];
	for (new i; i < MAX_PLAYERS; i++)
	{
        if (APlayerData[i][PlayerLevel] > 0)
		{      
	        GetPlayerName(playerid, Name, sizeof(Name));
		    format(Msg, 128, "{00FFCC}%s : %s %s", Name, command, text);
		    SendClientMessage(i, 0xFFFFFFFF, Msg);
	    }     
    }
	format(Msg, 128, "%s : %s %s", Name, command, text);
	print(Msg);
}
forward Player_FreezeTimer(playerid);
public Player_FreezeTimer(playerid)
{
	new Msg[128];
    APlayerData[playerid][PlayerFrozen]--;
	if (APlayerData[playerid][PlayerFrozen] > 0)
	{
		if (APlayerData[playerid][PlayerFrozen] >= 60)
			format(Msg, 128, "Congelado por %i minutos", APlayerData[playerid][PlayerFrozen] / 60);
		else
			format(Msg, 128, "Congelado por %i segundos", APlayerData[playerid][PlayerFrozen]);
		GameTextForPlayer(playerid, Msg, 1000, 4);
	}
	else 
	    TogglePlayerControllable(playerid, 1);
}
CommandList_Create(playerid)
{
	new Counter, CommandList[1000], DialogTitle[128];
	for (new i = APlayerData[playerid][DialogFirstItem]; i < sizeof(ACommands); i++)
	{
		Counter++;
		if (Counter <= 5)
		{
			if (APlayerData[playerid][PlayerLevel] >= ACommands[i][CommandLevel])
			{
				if (ACommands[i][CommandLevel] == 0)
				{
					format(CommandList, 500, "%s%s{00FF00}%s", CommandList, "\n", ACommands[i][CommandStructure]); 
					format(CommandList, 500, "%s%s\t\t{FFFF00}%s", CommandList, "\n", ACommands[i][CommandDescription]); 
				}
				else
				{
					format(CommandList, 500, "%s%sLevel %i: {00FF00}%s", CommandList, "\n", ACommands[i][CommandLevel], ACommands[i][CommandStructure]); // Add the name of the next command to the list on the next line
					format(CommandList, 500, "%s%s\t\t{FFFF00}%s", CommandList, "\n", ACommands[i][CommandDescription]);
				}
			}
			else
				break;
		}
		else 
		{
			format(CommandList, 500, "%s%s%s", CommandList, "\n \n", TXT_DialogEntryNext);
			break;
		}
	}
	format(DialogTitle, 128, TXT_DialogCommandTitle, (APlayerData[playerid][DialogFirstItem] / 5) + 1);
	ShowPlayerDialog(playerid, DialogPlayerCommands, DIALOG_STYLE_LIST, DialogTitle, CommandList, TXT_DialogButtonSelect, TXT_DialogButtonCancel);
	return 1;
}
IsVehicleAirVehicle(vid)
{
	switch (GetVehicleModel(vid))
	{
		case 592, 577, 511, 512, 593, 520, 553, 476, 519, 460, 513, 548, 425, 417, 487, 488, 497, 563, 447, 469: return 1;
		default: return 0;
	}
	return 0;
}
SetupSpeedCamera(CamID, Float:x, Float:y, Float:z, Float:rot, MaxSpeed)
{
    ACameras[CamID][CamX] = x;
    ACameras[CamID][CamY] = y;
    ACameras[CamID][CamZ] = z;
    ACameras[CamID][CamAngle] = rot;
    ACameras[CamID][CamSpeed] = MaxSpeed;
    ACameras[CamID][CamObj1] = CreateObject(18880, x, y, z, 0.0, 0.0, rot);
    ACameras[CamID][CamObj2] = CreateObject(18880, x, y, z, 0.0, 0.0, rot + 180.0);
    ACameras[CamID][CamIcon] = CreateDynamicMapIcon(x, y, z, 34, 0, 0, 0, -1, 150.0);
}
SendReportToAdmins(OffenderID, Reason[], bool:AutoReport = false)
{
	new Name[24], Msg[128], TxtMsg[128], TotalReason[128];
	GetPlayerName(OffenderID, Name, sizeof(Name));
	if (AutoReport == false)
	{
		format(Msg, 128, "{00FFFF}Relato: %s (%i): %s", Name, OffenderID, Reason);
		format(TxtMsg, 128, "Relatou:~n~~g~%s (%i)~n~~r~%s", Name, OffenderID, Reason);
		format(TotalReason, 128, Reason);
	}
	else
	{
		format(Msg, 128, "{00FFFF}Auto-Relato: %s (%i): %s", Name, OffenderID, Reason);
		format(TxtMsg, 128, "Auto-Relato:~n~~g~%s (%i)~n~~r~%s", Name, OffenderID, Reason);
		format(TotalReason, 128, "%s (by AntiHack)", Reason);
		APlayerData[OffenderID][AutoReportTime] = 120;
	}
	for (new playerid; playerid < MAX_PLAYERS; playerid++)
	{
	    if (APlayerData[playerid][PlayerLevel] > 0)
	    {
			SendClientMessage(playerid, 0xFFFFFFFF, Msg);
			GameTextForPlayer(playerid, TxtMsg, 10000, 4);
	    }
	}
	AddReport(OffenderID, TotalReason);
}
AddReport(OffenderID, Reason[])
{
	new ReportID = -1, Name[24];
	for (new i; i < 50; i++)
	{
		if (AReports[i][ReportUsed] == false)
		{
		    ReportID = i;
		    break;
		}
	}
	if (ReportID == -1)
	{
		for (new i = 1; i < 50; i++)
		{
			AReports[i - 1][ReportUsed] = AReports[i][ReportUsed];
			format(AReports[i - 1][ReportName], 24, "%s", AReports[i][ReportName]);
			format(AReports[i - 1][ReportReason], 128, "%s", AReports[i][ReportReason]);
		}
		ReportID = 49;
	}
	GetPlayerName(OffenderID, Name, sizeof(Name));
	AReports[ReportID][ReportUsed] = true;
	format(AReports[ReportID][ReportName], 24, "%s", Name);
	format(AReports[ReportID][ReportReason], 128, "%s", Reason);
}
GetFirstThreeDigitsFromIP(PlayerIP[])
{
	new Part1, Part2, Part3, DotLoc, RetIP[16];
	Part1 = strval(PlayerIP[0]);
	DotLoc = strfind(PlayerIP, ".", false, 0);
	Part2 = strval(PlayerIP[DotLoc+1]);
	DotLoc = strfind(PlayerIP, ".", false, DotLoc+1);
	Part3 = strval(PlayerIP[DotLoc+1]);
	format(RetIP, 16, "%i.%i.%i.", Part1, Part2, Part3);
	return RetIP;
}
forward Timer_TimedMessages();
public Timer_TimedMessages()
{
	SendClientMessageToAll(0xFFFFFFFF, ATimedMessages[LastTimedMessage]);
    LastTimedMessage++;
	if (LastTimedMessage == sizeof(ATimedMessages))
	    LastTimedMessage = 0; 
	return 1;
}
forward ShowRandomBonusMission();
public ShowRandomBonusMission()
{
	new bool:MissionSet = false, Msg1[128], Msg2[128], Msg3[128], lName[50], sName[50], eName[50], tName[100];
	if ((RandomBonusMission[RandomLoad] == 0) || (RandomBonusMission[MissionFinished] == true))
	{
		while (MissionSet == false)
		{
	        RandomBonusMission[RandomLoad] = random(sizeof(ALoads));
			switch (RandomBonusMission[RandomLoad])
			{
				case 0: MissionSet = false;
				default: 
				{
					switch(ALoads[RandomBonusMission[RandomLoad]][PCV_Required]) 
					{
					    case PCV_TruckerOreTrailer, PCV_TruckerFluidsTrailer, PCV_TruckerCargoTrailer, PCV_TruckerCementTruck, PCV_TruckerNoTrailer:
					    {
							MissionSet = true; 
					    }
					    default: MissionSet = false; 
					}
				}
			}
		}
	    RandomBonusMission[RandomStartLoc] = Product_GetRandomStartLoc(RandomBonusMission[RandomLoad]);
	    RandomBonusMission[RandomEndLoc] = Product_GetRandomEndLoc(RandomBonusMission[RandomLoad]);
		RandomBonusMission[MissionFinished] = false;
	}
	format(lName, 50, ALoads[RandomBonusMission[RandomLoad]][LoadName]);
	format(sName, 50, ALocations[RandomBonusMission[RandomStartLoc]][LocationName]);
	format(eName, 50, ALocations[RandomBonusMission[RandomEndLoc]][LocationName]);
	switch(ALoads[RandomBonusMission[RandomLoad]][PCV_Required])
	{
		case PCV_TruckerOreTrailer: format(tName, 128, "Caminhão {00BBFF}com {FFBB00}trailer de minério");
		case PCV_TruckerFluidsTrailer: format(tName, 128, "Caminhão {00BBFF}com {FFBB00}trailer de fluídos");
		case PCV_TruckerCargoTrailer: format(tName, 128, "Caminhão {00BBFF}com {FFBB00}trailer baú");
		case PCV_TruckerCementTruck: format(tName, 128, "Caminhão de cimento");
		case PCV_TruckerNoTrailer: format(tName, 128, "Flatbed {00BBFF}ou {FFBB00}DFT-30");
	}
	format(Msg1, 128, "{00BBFF}Missão Bonus: Transportar {FFBB00}%s{00BBFF},", lName);
	format(Msg2, 128, "{00BBFF}de {FFBB00}%s{00BBFF} para {FFBB00}%s{00BBFF},", sName, eName);
	format(Msg3, 128, "{00BBFF}Você precisa de um {FFBB00}%s{00BBFF} para completar esta missão.", tName);
	for (new playerid; playerid < MAX_PLAYERS; playerid++)
	{
		if (APlayerData[playerid][LoggedIn] == true)
		{
			if (APlayerData[playerid][PlayerClass] == ClassTruckDriver)
			{
				SendClientMessage(playerid, 0xFFFFFFFF, Msg1);
				SendClientMessage(playerid, 0xFFFFFFFF, Msg2);
				SendClientMessage(playerid, 0xFFFFFFFF, Msg3);
			}
		}
	}

	return 1;
}
ShowBankMenu(playerid)
{
	new BankOptions[256], BankTitle[128];
	format(BankTitle, sizeof(BankTitle), "{FFFFFF}Seus fundos bancários: {00FF00}R$%i", APlayerData[playerid][BankMoney]);
	format(BankOptions, sizeof(BankOptions), "{00FF00}Depositar\n");
	format(BankOptions, sizeof(BankOptions), "%s{00FF00}Sacar\n", BankOptions);
	format(BankOptions, sizeof(BankOptions), "%s{00FF00}Transferir\n", BankOptions);
	format(BankOptions, sizeof(BankOptions), "%s{00FF00}Cancelar conta bancária\n", BankOptions);
	ShowPlayerDialog(playerid, DialogBankOptions, DIALOG_STYLE_LIST, BankTitle, BankOptions, TXT_DialogButtonSelect, TXT_DialogButtonCancel);
}
forward Bank_IntrestTimer();
public Bank_IntrestTimer()
{
	new IntrestAmount, Msg[128];
    CurrentIntrestTime++;
	IntrestTime_Save();
	if (IntrestEnabled == true)
	{
		for (new playerid; playerid < MAX_PLAYERS; playerid++)
		{
			if (APlayerData[playerid][LoggedIn] == true)
			{
				if (APlayerData[playerid][BankMoney] > 0)
				{
					IntrestAmount = floatround(floatmul(APlayerData[playerid][BankMoney], BankIntrest), floatround_floor);
					APlayerData[playerid][BankMoney] = APlayerData[playerid][BankMoney] + IntrestAmount;
					APlayerData[playerid][LastIntrestTime] = CurrentIntrestTime;
					BankFile_Save(playerid);
					format(Msg, 128, "{00FF00}Você recebeu {FFFF00}R$%i{00FF00} de lucros da sua conta bancária.", IntrestAmount);
					SendClientMessage(playerid, 0xFFFFFFFF, Msg);
				}
			}
		}
	}
}
HelpList_Create(playerid)
{
	new HelpList[1000], DialogTitle[128];
	format(DialogTitle, 128, "Aqui você pode obter ajuda sobre qualquer um desses itens:");
	for (new i; i < sizeof(AHelpTopics); i++)
	{
		format(HelpList, 1000, "%s%s\n", HelpList, AHelpTopics[i]);
	}
	ShowPlayerDialog(playerid, DialogHelpItemChosen, DIALOG_STYLE_LIST, DialogTitle, HelpList, TXT_DialogButtonSelect, TXT_DialogButtonCancel);
	return 1;
}

