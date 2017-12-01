forward Speedometer_Update(playerid);
forward RefuelVehicle(playerid);
Speedometer_Setup(playerid)
{
	APlayerData[playerid][SpeedometerText] = TextDrawCreate(473.0, 395.0, " ");
	APlayerData[playerid][FuelGauge] = TextDrawCreate(473.0, 410.0, " ");
	TextDrawShowForPlayer(playerid, APlayerData[playerid][SpeedometerText]);
	TextDrawShowForPlayer(playerid, APlayerData[playerid][FuelGauge]);
	APlayerData[playerid][SpeedometerTimer] = SetTimerEx("Speedometer_Update", 500, true, "i", playerid);
	return 1;
}
Speedometer_Cleanup(playerid)
{
	TextDrawDestroy(APlayerData[playerid][SpeedometerText]);
	TextDrawDestroy(APlayerData[playerid][FuelGauge]);
	KillTimer(APlayerData[playerid][SpeedometerTimer]);
	APlayerData[playerid][PlayerSpeed] = 0;
	return 1;
}
public Speedometer_Update(playerid)
{
	new vehicleid, Float:speed_x, Float:speed_y, Float:speed_z, Float:final_speed, speed_string[50], final_speed_int, Float:vehiclehealth;
	new FuelString[50], FuelStatus[20];
	new Msg[128], Name[24];
	vehicleid = GetPlayerVehicleID(playerid);
	AntiHack(playerid);
	if (GetPlayerState(playerid) == PLAYER_STATE_SPECTATING)
	{
	    new OtherPlayer = APlayerData[playerid][SpectateID];
		GetPlayerName(OtherPlayer, Name, sizeof(Name));
		SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(OtherPlayer));
		SetPlayerInterior(playerid, GetPlayerInterior(OtherPlayer));
		if (APlayerData[playerid][SpectateType] == ADMIN_SPEC_TYPE_PLAYER)
		{
		    if (GetPlayerVehicleSeat(OtherPlayer) != -1)
		    {
				PlayerSpectateVehicle(playerid, GetPlayerVehicleID(OtherPlayer));
				APlayerData[playerid][SpectateID] = OtherPlayer;
				APlayerData[playerid][SpectateVehicle] = GetPlayerVehicleID(OtherPlayer);
				APlayerData[playerid][SpectateType] = ADMIN_SPEC_TYPE_VEHICLE;
				format(Msg, 128, "{FFFFFF}[ESPIAR]: {FF0000}%s{FFFFFF} entrou num veiculo, modo de espiar alterado.", Name);
				SendClientMessage(playerid, 0x00FF00, Msg);
		    }
		}
		else
		{
		    if (GetPlayerVehicleSeat(OtherPlayer) == -1)
		    {
				PlayerSpectatePlayer(playerid, OtherPlayer);
				SetPlayerInterior(playerid, GetPlayerInterior(OtherPlayer));
				APlayerData[playerid][SpectateID] = OtherPlayer;
				APlayerData[playerid][SpectateType] = ADMIN_SPEC_TYPE_PLAYER;
				format(Msg, 128, "{FFFFFF}[ESPIAR]: {FF0000}%s{FFFFFF} saiu do veiculo, modo de espiar alterado.", Name);
				SendClientMessage(playerid, 0xFFFFFFFF, Msg);
		    }
		}
	}
	if (APlayerData[playerid][PoliceWarnedMe] == true)
	{
		if (GetPlayerWantedLevel(playerid) == 0)
		{
			APlayerData[playerid][PoliceCanJailMe] = false; 
			APlayerData[playerid][PoliceWarnedMe] = false; 
			APlayerData[playerid][Value_PoliceCanJailMe] = 0; 
			KillTimer(APlayerData[playerid][Timer_PoliceCanJailMe]); 
		}
	}
	if(vehicleid != 0)
	{
		GetVehicleVelocity(vehicleid, speed_x, speed_y, speed_z);
		final_speed = floatsqroot(((speed_x * speed_x) + (speed_y * speed_y)) + (speed_z * speed_z)) * 158.179;
		final_speed_int = floatround(final_speed, floatround_round);
		APlayerData[playerid][PlayerSpeed] = final_speed_int;
		format(speed_string, 50, TXT_SpeedometerSpeed, final_speed_int);
		TextDrawSetString(APlayerData[playerid][SpeedometerText], speed_string);
		APlayerData[playerid][StatsMetersDriven] = APlayerData[playerid][StatsMetersDriven] + (final_speed / 7.2);
		GetVehicleHealth(vehicleid, vehiclehealth);
		SetPlayerHealth(playerid, vehiclehealth / 10.0);
		if ((final_speed_int > 10) && (AVehicleData[vehicleid][Fuel] > 0))
			AVehicleData[vehicleid][Fuel] = AVehicleData[vehicleid][Fuel] - 1; 

		if ((AVehicleData[vehicleid][Fuel] > 0) && (AVehicleData[vehicleid][Fuel] < 100000))
			format(FuelStatus, 20, "~g~%s~r~%s", "I", "IIIIIIIII"); // Fuel is between 0% and 10% full

		if ((AVehicleData[vehicleid][Fuel] >= ((MaxFuel / 10) * 1)) && (AVehicleData[vehicleid][Fuel] < ((MaxFuel / 10) * 2)))
			format(FuelStatus, 20, "~g~%s~r~%s", "II", "IIIIIIII"); // Fuel is between 10% and 20% full

		if ((AVehicleData[vehicleid][Fuel] >= ((MaxFuel / 10) * 2)) && (AVehicleData[vehicleid][Fuel] < ((MaxFuel / 10) * 3)))
			format(FuelStatus, 20, "~g~%s~r~%s", "III", "IIIIIII"); // Fuel is between 20% and 30% full

		if ((AVehicleData[vehicleid][Fuel] >= ((MaxFuel / 10) * 3)) && (AVehicleData[vehicleid][Fuel] < ((MaxFuel / 10) * 4)))
			format(FuelStatus, 20, "~g~%s~y~%s", "IIII", "IIIIII"); // Fuel is between 30% and 40% full

		if ((AVehicleData[vehicleid][Fuel] >= ((MaxFuel / 10) * 4)) && (AVehicleData[vehicleid][Fuel] < ((MaxFuel / 10) * 5)))
			format(FuelStatus, 20, "~g~%s~y~%s", "IIIII", "IIIII"); // Fuel is between 40% and 50% full

		if ((AVehicleData[vehicleid][Fuel] >= ((MaxFuel / 10) * 5)) && (AVehicleData[vehicleid][Fuel] < ((MaxFuel / 10) * 6)))
			format(FuelStatus, 20, "~g~%s~y~%s", "IIIIII", "IIII"); // Fuel is between 50% and 60% full

		if ((AVehicleData[vehicleid][Fuel] >= ((MaxFuel / 10) * 6)) && (AVehicleData[vehicleid][Fuel] < ((MaxFuel / 10) * 7)))
			format(FuelStatus, 20, "~g~%s~y~%s", "IIIIIII", "III"); // Fuel is between 60% and 70% full

		if ((AVehicleData[vehicleid][Fuel] >= ((MaxFuel / 10) * 7)) && (AVehicleData[vehicleid][Fuel] < ((MaxFuel / 10) * 8)))
			format(FuelStatus, 20, "~g~%s~y~%s", "IIIIIIII", "II"); // Fuel is between 70% and 80% full

		if ((AVehicleData[vehicleid][Fuel] >= ((MaxFuel / 10) * 8)) && (AVehicleData[vehicleid][Fuel] < ((MaxFuel / 10) * 9)))
			format(FuelStatus, 20, "~g~%s~y~%s", "IIIIIIIII", "I"); // Fuel is between 80% and 90% full

		if ((AVehicleData[vehicleid][Fuel] >= ((MaxFuel / 10) * 9)) && (AVehicleData[vehicleid][Fuel] <= MaxFuel))
			format(FuelStatus, 20, "~g~%s", "IIIIIIIIII"); // Fuel is between 90% and 100% full (all bars are green)

		if (AVehicleData[vehicleid][Fuel] == 0)
			format(FuelStatus, 20, "~r~%s", "acabou");

		format(FuelString, 50, TXT_SpeedometerFuel, FuelStatus);
		TextDrawSetString(APlayerData[playerid][FuelGauge], FuelString);
		if (AVehicleData[vehicleid][Fuel] == 0)
		{
			new engine,lights,alarm,doors,bonnet,boot,objective;
			GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
			SetVehicleParamsEx(vehicleid, 0, 0, alarm, doors, bonnet, boot, objective);
		}
		if (IsVehicleAirVehicle(vehicleid) == 0)
			if (APlayerData[playerid][PlayerClass] != ClassPolice) 
				CheckPlayerSpeeding(playerid);
	}
	else
	{
		TextDrawSetString(APlayerData[playerid][SpeedometerText], " ");
		TextDrawSetString(APlayerData[playerid][FuelGauge], " ");
		APlayerData[playerid][PlayerSpeed] = 0;
	}
}
public RefuelVehicle(playerid)
{
	new RefuelMsg[128];
	new vID = GetPlayerVehicleID(playerid);
	new Amount = MaxFuel - AVehicleData[vID][Fuel];
	new RefuelPrice = (Amount * RefuelMaxPrice) / MaxFuel;
	if (APlayerData[playerid][PlayerMoney] >= RefuelPrice)
	{
		AVehicleData[vID][Fuel] = MaxFuel;
		RewardPlayer(playerid, -RefuelPrice, 0);
		format(RefuelMsg, 128, TXT_RefuelledVehicle, RefuelPrice);
		SendClientMessage(playerid, 0xFFFFFFFF, RefuelMsg);
	}
	else
	    SendClientMessage(playerid, 0xFFFFFFFF, TXT_CannotRefuelVehicle);
	TogglePlayerControllable(playerid, 1);

	return 1;
}
CheckPlayerSpeeding(playerid)
{
	new Name[24], Msg[128];
	if (APlayerData[playerid][PlayerCaughtSpeeding] == 0)
	{
		for (new CamID; CamID < MAX_CAMERAS; CamID++)
		{
		    if (ACameras[CamID][CamSpeed] != 0)
		    {
				if (GetPlayerVehicleSeat(playerid) == 0)
				{
					if (APlayerData[playerid][PlayerSpeed] > ACameras[CamID][CamSpeed])
					{
						if (IsPlayerInRangeOfPoint(playerid, 50.0, ACameras[CamID][CamX], ACameras[CamID][CamY], ACameras[CamID][CamZ]))
						{
						    APlayerData[playerid][PlayerCaughtSpeeding] = 20;
						    SetPlayerWantedLevel(playerid, GetPlayerWantedLevel(playerid) + 1);     
                            PlayerPlaySound(playerid, 1132, 0.0, 0.0, 0.0); 
                            GameTextForPlayer(playerid, "~r~Flagrado pelo radar", 6000, 1);                              
						    SendClientMessage(playerid, 0xFFFFFFFF, TXT_PlayerCaughtSpeeding);
							GetPlayerName(playerid, Name, sizeof(Name));
							format(Msg, 128, "{0000FF}[Departamento de Polícia] O suspeito {FFFFFF}%s {0000FF}foi pêgo em alta velocidade!", Name);
							Police_SendMessage(Msg);
                            Police_SendMessage("{0000FF}[Objetivo]: {FFFFFF}Perseguir e multar{0000FF}.");                              
						}
					}
				}
		    }
		}
	}
	else 
	    APlayerData[playerid][PlayerCaughtSpeeding]--;
}
stock AntiHack(playerid)
{
	new Float:Armour;
	if (APlayerData[playerid][AutoReportTime] > 0)
	{
	    APlayerData[playerid][AutoReportTime]--;
	    return 1;
	}
	if (GetPVarInt(playerid, "PVarMoney") != 0)
	{
		APlayerData[playerid][PlayerMoney] = APlayerData[playerid][PlayerMoney] + GetPVarInt(playerid, "PVarMoney");
		SetPVarInt(playerid, "PVarMoney", 0);
	}
	if (GetPVarInt(playerid, "PVarScore") != 0)
	{
		APlayerData[playerid][PlayerScore] = APlayerData[playerid][PlayerScore] + GetPVarInt(playerid, "PVarScore");
		SetPVarInt(playerid, "PVarScore", 0);
	}
	ResetPlayerMoney(playerid);
	GivePlayerMoney(playerid, APlayerData[playerid][PlayerMoney]);
	SetPlayerScore(playerid, APlayerData[playerid][PlayerScore]);
	Player_PortOutAdminZone(playerid, 106.0, 1805.0, -50.0, 285.0, 1940.0, 40.0, 15.0, 1732.0, 25.0);

	if (APlayerData[playerid][PlayerLevel] <= 1)
    {
        if (Armour > 1.0)
        SendReportToAdmins(playerid, "Health-hack", true);        

	    if (APlayerData[playerid][PlayerSpeed] > 300)
        SendReportToAdmins(playerid, "Speed-hack", true);

	    if (APlayerData[playerid][PlayerLevel] < 3)
	    {
		    if (GetPlayerSpecialAction(playerid) == 2)
	        SendReportToAdmins(playerid, "Jetpack-hack", true);
	    }    
     }
	if (GetPlayerVehicleSeat(playerid) == 0)
	{
		if (APlayerData[playerid][PlayerSpeed] < 10)
		{
			if (GetPlayerInterior(playerid) != APlayerData[playerid][PreviousInt])
			{
			    switch (GetPlayerInterior(playerid))
				{
					case 0, 1, 2, 3: 
					{
						GetPlayerPos(playerid, APlayerData[playerid][PreviousX], APlayerData[playerid][PreviousY], APlayerData[playerid][PreviousZ]);
						APlayerData[playerid][PreviousInt] = GetPlayerInterior(playerid);
						return 1;
					}
				}
			}
			if (IsPlayerInRangeOfPoint(playerid, 7.5, APlayerData[playerid][PreviousX], APlayerData[playerid][PreviousY], APlayerData[playerid][PreviousZ]))
			{
			}
			else 
            	if (APlayerData[playerid][PlayerLevel] <= 1)
		        SendReportToAdmins(playerid, "Airbreak-hack", true);
		}
	}
	GetPlayerPos(playerid, APlayerData[playerid][PreviousX], APlayerData[playerid][PreviousY], APlayerData[playerid][PreviousZ]);
	APlayerData[playerid][PreviousInt] = GetPlayerInterior(playerid);
	return 1;
}

