forward Pilot_Plane_LoadUnload(playerid);
Pilot_StartRandomJob(playerid)
{
	new PilotJobSet;
	switch (GetVehicleModel(GetPlayerVehicleID(playerid)))
	{
		case VehicleShamal, VehicleNevada, VehicleAT400, VehicleAndromada: 
			PilotJobSet = Pilot_Plane_SetRandomJob(playerid);
		case VehicleMaverick, VehicleDodo: 
		    PilotJobSet = Pilot_Heli_SetRandomJob(playerid);
	}
	switch (PilotJobSet)
	{
		case 1, 2:
		{
			new StartLoc[50], EndLoc[50], Load[50], RouteText[255], Float:x, Float:y, Float:z, LoadMsg[128];
			APlayerData[playerid][JobStarted] = true;
			APlayerData[playerid][JobStep] = 1;
			format(StartLoc, 50, ALocations[APlayerData[playerid][JobLoc1]][LocationName]);
			format(EndLoc, 50, ALocations[APlayerData[playerid][JobLoc2]][LocationName]);
			format(Load, 50, ALoads[APlayerData[playerid][LoadID]][LoadName]);
			format(RouteText, 255, TXT_TransportingFromToPickup, Load, StartLoc, EndLoc);
			TextDrawSetString(APlayerData[playerid][MissionText], RouteText);
			x = ALocations[APlayerData[playerid][JobLoc1]][LocX];
			y = ALocations[APlayerData[playerid][JobLoc1]][LocY];
			z = ALocations[APlayerData[playerid][JobLoc1]][LocZ];
			SetPlayerCheckpoint(playerid, x, y, z, 7);
			format(LoadMsg, 128, TXT_PickupCargoAt, Load, StartLoc);
			SendClientMessage(playerid, 0xFFFFFFFF, LoadMsg);
		}
	}

	return 1;
}
Pilot_Plane_SetRandomJob(playerid)
{
	if (GetPlayerVehicleSeat(playerid) == 0)
	{
		switch (GetVehicleModel(GetPlayerVehicleID(playerid)))
		{
			case VehicleShamal, VehicleNevada, VehicleAT400, VehicleAndromada:
			{
				APlayerData[playerid][LoadID] = Product_GetRandom(PCV_PilotPlane);
				APlayerData[playerid][JobLoc1] = Product_GetRandomStartLoc(APlayerData[playerid][LoadID]);
				APlayerData[playerid][JobLoc2] = Product_GetRandomEndLoc(APlayerData[playerid][LoadID]);
				while (Locations_CheckDistance(APlayerData[playerid][JobLoc1], APlayerData[playerid][JobLoc2], 1000.0) == 0)
				{
				    APlayerData[playerid][JobLoc2] = Product_GetRandomEndLoc(APlayerData[playerid][LoadID]);
				}
				return 1;
			}
		}
	}
	return 0;
}
Pilot_Heli_SetRandomJob(playerid)
{
	if (GetPlayerVehicleSeat(playerid) == 0)
	{
		switch (GetVehicleModel(GetPlayerVehicleID(playerid)))
		{
			case VehicleMaverick, VehicleDodo:
			{
				APlayerData[playerid][LoadID] = Product_GetRandom(PCV_PilotHelicopter);
				APlayerData[playerid][JobLoc1] = Product_GetRandomStartLoc(APlayerData[playerid][LoadID]);
				APlayerData[playerid][JobLoc2] = Product_GetRandomEndLoc(APlayerData[playerid][LoadID]);
				while (Locations_CheckDistance(APlayerData[playerid][JobLoc1], APlayerData[playerid][JobLoc2], 1000.0) == 0)
				{
				    APlayerData[playerid][JobLoc2] = Product_GetRandomEndLoc(APlayerData[playerid][LoadID]);
				}
				return 2;
			}
		}
	}
	return 0;
}
Pilot_OnPlayerEnterCheckpoint(playerid)
{
	new LoadMsg[128];
    switch (APlayerData[playerid][JobStep])
    {
 		case 1: format(LoadMsg, 128, TXT_LoadingGoods, ALoads[APlayerData[playerid][LoadID]][LoadName]);
		case 2: format(LoadMsg, 128, TXT_UnloadingGoods, ALoads[APlayerData[playerid][LoadID]][LoadName]);
    }
	TogglePlayerControllable(playerid, 0);
	new vehicleid = GetPlayerVehicleID(playerid);
	switch (GetVehicleModel(vehicleid))
	{
	    case VehicleShamal, VehicleNevada, VehicleAT400, VehicleAndromada: 
		{
			GameTextForPlayer(playerid, LoadMsg, 5000, 5);
			APlayerData[playerid][LoadingTimer] = SetTimerEx("Pilot_Plane_LoadUnload", 5000, false, "d" , playerid);
		}
	    case VehicleMaverick, VehicleDodo:
	    {
			GameTextForPlayer(playerid, LoadMsg, 3000, 3);
			APlayerData[playerid][LoadingTimer] = SetTimerEx("Pilot_Plane_LoadUnload", 3000, false, "d" , playerid);
			new engine,lights,alarm,doors,bonnet,boot,objective;
			GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
			SetVehicleParamsEx(vehicleid, 0, lights, alarm, doors, bonnet, boot, objective);
	    }
	}

	return 1;
}
public Pilot_Plane_LoadUnload(playerid)
{
	switch (APlayerData[playerid][JobStep])
	{
		case 1: 
		{
			new StartLoc[50], EndLoc[50], Load[50], RouteText[255], Float:x, Float:y, Float:z, UnloadMsg[100];
			APlayerData[playerid][JobStep] = 2;
			DisablePlayerCheckpoint(playerid);
			format(StartLoc, 50, ALocations[APlayerData[playerid][JobLoc1]][LocationName]);
			format(EndLoc, 50, ALocations[APlayerData[playerid][JobLoc2]][LocationName]);
			format(Load, 50, ALoads[APlayerData[playerid][LoadID]][LoadName]);
			format(RouteText, 255, TXT_TransportingFromToDeliver, Load, StartLoc, EndLoc);
			TextDrawSetString(APlayerData[playerid][MissionText], RouteText);
			x = ALocations[APlayerData[playerid][JobLoc2]][LocX];
			y = ALocations[APlayerData[playerid][JobLoc2]][LocY];
			z = ALocations[APlayerData[playerid][JobLoc2]][LocZ];
			SetPlayerCheckpoint(playerid, x, y, z, 7);
			format(UnloadMsg, 100, TXT_DeliverCargoTo, Load, EndLoc);
			SendClientMessage(playerid, 0xFFFFFFFF, UnloadMsg);
		}
		case 2: 
		{
			new StartLoc[50], EndLoc[50], Load[50], Msg1[128], Msg2[128], Name[24];
			GetPlayerName(playerid, Name, sizeof(Name));
			format(StartLoc, 50, ALocations[APlayerData[playerid][JobLoc1]][LocationName]);
			format(EndLoc, 50, ALocations[APlayerData[playerid][JobLoc2]][LocationName]);
			format(Load, 50, ALoads[APlayerData[playerid][LoadID]][LoadName]);
			format(Msg1, 128, TXT_PlayerCompletedPilotJob, Name, Load);
			SendClientMessageToAll(0xFFFFFFFF, Msg1);
            format(Msg2, 128, TXT_PlayerLocationPilotJob, StartLoc, EndLoc);             
            SendClientMessageToAll(0xFFFFFFFF, Msg2);
			new Float:x1, Float:y1, Float:x2, Float:y2, Float:Distance, Message[128], Payment;
			x1 = ALocations[APlayerData[playerid][JobLoc1]][LocX];
			y1 = ALocations[APlayerData[playerid][JobLoc1]][LocY];
			x2 = ALocations[APlayerData[playerid][JobLoc2]][LocX];
			y2 = ALocations[APlayerData[playerid][JobLoc2]][LocY];
			Distance = floatsqroot(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
			Payment = floatround((Distance * ALoads[APlayerData[playerid][LoadID]][PayPerUnit]), floatround_floor);
			RewardPlayer(playerid, Payment, 1);
			format(Message, 128, TXT_RewardJob, Payment);
			SendClientMessage(playerid, 0xFFFFFFFF, Message);
			APlayerData[playerid][StatsPilotJobs]++;
			PlayerFile_Save(playerid);
			Pilot_EndJob(playerid);
		}
	}
	TogglePlayerControllable(playerid, 1);
	new vehicleid = GetPlayerVehicleID(playerid);
	new engine,lights,alarm,doors,bonnet,boot,objective;
	GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
	SetVehicleParamsEx(vehicleid, 1, lights, alarm, doors, bonnet, boot, objective);
	return 1;
}
Pilot_EndJob(playerid)
{
	if (APlayerData[playerid][JobStarted] == true)
	{
		APlayerData[playerid][JobStarted] = false;
		APlayerData[playerid][JobStep] = 0;
		APlayerData[playerid][LoadID] = 0;
		APlayerData[playerid][JobLoc1] = 0;
		APlayerData[playerid][JobLoc2] = 0;
		DisablePlayerCheckpoint(playerid);
		TextDrawSetString(APlayerData[playerid][MissionText], Pilot_NoJobText);
		KillTimer(APlayerData[playerid][LoadingTimer]);
	}
	return 1;
}

