// Forward the function used to repair a camera (when the player entered a racecheckpoint)
forward Roadworker_RepairCamera(playerid);



enum TBrokenVehicleLocation
{
	BrokenName[50], // Holds the name of the location where the vehicle is located
	Float:BrokenX, // Holds the X coordinate where the vehicle spawns
	Float:BrokenY, // Holds the Y coordinate where the vehicle spawns
	Float:BrokenZ // Holds the Z coordinate where the vehicle spawns
}
new ABrokenVehicles[][TBrokenVehicleLocation] =
{
	{"Shady Creeks", -2047.5, -1882.25, 52.4},
	{"Angel Pine", -2072.5, -2407.75, 30.7},
	{"Shady Creeks", -1595.25, -2625.0, 52.6},
	{"Back O Beyond", -990.25, -2335.5, 66.8},
	{"Flint County", 46.5, -2654.25, 40.5},
	{"Los Santos Inlet", -313.5, -1959.75, 20.0},
	{"Leafy Hollow", -833.0, -1737.25, 80.8},
	{"Flint Range", -347.5, -1331.0, 17.1},
	{"Flint County", 17.25, -987.75, 28.7},
	{"Fallen Tree", -763.0, -621.25, 61.5},
	{"Foster Valley", -1885.5, -435.5, 25.2},
	{"Missionary Hill", -2451.25, -681.0, 133.6},
	{"Garcia", -2371.5, 118.25, 35.3},
	{"Downtown", -1781.5, 429.25, 16.6},
	{"Palisades", -2905.0, 656.5, 6.3},
	{"Paradiso", -2771.25, 1239.5, 22.6}
//	{"nnnnnnnnnn", xxxxxxx, yyyyyyyy, zzzzzzz},
};



// This function is called when a roadworker wants to start a job by entering "/work"
Roadworker_StartRandomJob(playerid)
{
	// Setup local variables
	new vid, trailerid;

	// If the player is the driver of the vehicle (GetPlayerVehicleSeat returns -1 if the player is not in a vehicle)
	if (GetPlayerVehicleSeat(playerid) == 0)
	{
		// Get the vehicle-id
		vid = GetPlayerVehicleID(playerid);
		// Get the trailer-id
		trailerid = GetVehicleTrailer(vid);

		switch (GetVehicleModel(vid))
		{
		    case VehicleUtilityVan: // With a Utility Van, you're gonna do "repair speedcamera" job-type
		    {
			    // Check if the player has a utility trailer attached
			    if (trailerid != 0)
				{
					// Check if there is a utility trailer attached
			        if (GetVehicleModel(trailerid) == VehicleUtilityTrailer)
					{
					    // Setup local variables
						new Float:x, Float:y, Float:z, CamID;
						// Get a random speedcamera (no previous camera has been fixed yet, so Exception = -1 (invalid camera))
						CamID = GetRandomCamera(-1);
						// Check if there are no speedcamera's
						if (CamID == -1)
						{
							SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}Unable to start a job, there are no speedcamera's created");
							return 1;
						}

						// Job has started
						APlayerData[playerid][JobStarted] = true;
						// Set job-type
						APlayerData[playerid][JobID] = 1; // Job-type: "repair speedcameras"
						// Store the CamID
						APlayerData[playerid][JobLoc1] = CamID;
						// Set the TextDraw so the player can see it
						TextDrawSetString(APlayerData[playerid][MissionText], TXT_RepairSpeedcamera);

						// Grab the x, y, z positions for the checkpoint
						x = ACameras[CamID][CamX];
						y = ACameras[CamID][CamY];
						z = ACameras[CamID][CamZ];
						// Create a racecheckpoint where the player should repair a speedcamera
	                    SetPlayerRaceCheckpoint(playerid, 1, x, y, z, 0.0, 0.0, 0.0, 2.5);
						// Create a checkpoint to indicate the base
						SetPlayerCheckpoint(playerid, -1870.0, -1710.0, 21.8, 7.0);

						// Store the vehicleID (required to be able to check if the player left his vehicle)
						APlayerData[playerid][VehicleID] = vid;
						APlayerData[playerid][TrailerID] = trailerid;
						// Start a timer that ticks every second to see if the player is still inside his vehicle
						APlayerData[playerid][VehicleTimerTime] = Job_TimeToFailMission;
						// Inform the player what he must do
						SendClientMessage(playerid, 0xFFFFFFFF, "{00FF00}Repare o radar indicado no mapa, ou retorne para a base para terminar o trabalho.");
					}
					else
					    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}Você precisa ter um Ultility Trailer atrelado a seu Ultility Van.");
				}
				else
				    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}Você precisa ter um Ultility Trailer atrelado a seu Ultility Van..");
			}
			case VehicleTowTruck: 
			{
				new Float:x, Float:y, Float:z, RouteText[128];
				APlayerData[playerid][JobStarted] = true;
				APlayerData[playerid][JobID] = 2;
				APlayerData[playerid][JobLoc1] = random(sizeof(ABrokenVehicles));
				APlayerData[playerid][JobStep] = 1;
				format(RouteText, 128, TXT_TowBrokenVehicle, ABrokenVehicles[APlayerData[playerid][JobLoc1]][BrokenName]);
				TextDrawSetString(APlayerData[playerid][MissionText], RouteText);
				x = ABrokenVehicles[APlayerData[playerid][JobLoc1]][BrokenX];
				y = ABrokenVehicles[APlayerData[playerid][JobLoc1]][BrokenY];
				z = ABrokenVehicles[APlayerData[playerid][JobLoc1]][BrokenZ];
				SetPlayerCheckpoint(playerid, x, y, z, 10.0);
				APlayerData[playerid][LoadID] = CreateBrokenVehicle(x, y, z);
				APlayerData[playerid][VehicleID] = vid;
				APlayerData[playerid][VehicleTimerTime] = Job_TimeToFailMission;
				SendClientMessage(playerid, 0xFFFFFFFF, "{00FF00}Leve o veículo quebrado para o triturador.");
			}
		}
	}

	return 1;
}
Roadworker_EnterCheckpoint(playerid)
{
	new RouteText[128];
	if (APlayerData[playerid][JobID] == 2)
	{
		if (GetPlayerVehicleID(playerid) == APlayerData[playerid][VehicleID])
		{
			switch (APlayerData[playerid][JobStep])
			{
			    case 1: 
			    {
					DisablePlayerCheckpoint(playerid);
					AttachTrailerToVehicle(APlayerData[playerid][LoadID], GetPlayerVehicleID(playerid));
					format(RouteText, 128, TXT_DeliverBrokenVehicle, ABrokenVehicles[APlayerData[playerid][JobLoc1]][BrokenName]);
					TextDrawSetString(APlayerData[playerid][MissionText], RouteText);
					SetPlayerCheckpoint(playerid, -1868.5, -1684.0, 21.8, 10.0);
					APlayerData[playerid][JobStep] = 2;
					APlayerData[playerid][VehicleID] = GetPlayerVehicleID(playerid);
					APlayerData[playerid][TrailerID] = APlayerData[playerid][LoadID];
					SendClientMessage(playerid, 0xFFFFFFFF, "{00FF00}Tow the broken vehicle to the shredder");
			    }
			    case 2: 
			    {
			        AVehicleData[APlayerData[playerid][LoadID]][Owned] = false;
			        DetachTrailerFromVehicle(GetPlayerVehicleID(playerid));
			        DestroyVehicle(APlayerData[playerid][LoadID]);
			        APlayerData[playerid][LoadID] = 0;
					Roadworker_EndJob(playerid);
					RewardPlayer(playerid, 3500, 1);
					SendClientMessage(playerid, 0xFFFFFFFF, "{00FF00}Você ganhou {FFFF00}R$3500{00FF00} por entregar esse veículo quebrado no triturador.");
					APlayerData[playerid][StatsRoadworkerJobs]++;
					PlayerFile_Save(playerid);
			    }
			}
		}
		else
			SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}Você precisa de um Towtruck para continuar.");
	}

	return 1;
}
Roadworker_EnterRaceCheckpoint(playerid)
{
	if (APlayerData[playerid][JobID] == 1) 
	{
		if (GetPlayerVehicleSeat(playerid) == -1)
		{
	 		GameTextForPlayer(playerid, "fazendo manutencao~n~no radar...", 5000, 4);
			TogglePlayerControllable(playerid, 0);
			APlayerData[playerid][LoadingTimer] = SetTimerEx("Roadworker_RepairCamera", 5000, false, "d" , playerid);
		}
		else
		    SendClientMessage(playerid, 0xFFFFFFFF, TXT_NeedOnFootToProceed);
	}
	return 1;
}
public Roadworker_RepairCamera(playerid)
{
	new Float:x, Float:y, Float:z, CamID;
	RewardPlayer(playerid, 2500, 1);
	DisablePlayerRaceCheckpoint(playerid);
    TogglePlayerControllable(playerid, 1);
	SendClientMessage(playerid, 0xFFFFFFFF, "{00FF00}Você ganhou {FFFF00}R$2500{00FF00} por fazer a manutenção desse radar.");
	APlayerData[playerid][StatsRoadworkerJobs]++;
	PlayerFile_Save(playerid);
	CamID = GetRandomCamera(APlayerData[playerid][JobLoc1]);
	APlayerData[playerid][JobLoc1] = CamID;
	TextDrawSetString(APlayerData[playerid][MissionText], TXT_RepairSpeedcamera);
	x = ACameras[CamID][CamX];
	y = ACameras[CamID][CamY];
	z = ACameras[CamID][CamZ];
	SetPlayerRaceCheckpoint(playerid, 1, x, y, z, 0.0, 0.0, 0.0, 2.5);
	SendClientMessage(playerid, 0xFFFFFFFF, "{00FF00}Repare o próximo radar indicado no mapa, ou retorne para a base para terminar o trabalho.");
}
GetRandomCamera(Exception)
{
	new CameraList[100], CamCount = -1, CamID;
	for (CamID = 0; CamID < 100; CamID++)
	{
		if (ACameras[CamID][CamSpeed] > 0)
		{
			CamCount++;
			CameraList[CamCount] = CamID;
		}
	}
	if (CamCount == -1)
	    return -1;
	CamID = CameraList[random(CamCount + 1)];
	while (CamID == Exception)
		CamID = CameraList[random(CamCount + 1)];
	return CamID;
}
Roadworker_EndJob(playerid)
{
	if (APlayerData[playerid][JobStarted] == true)
	{
		APlayerData[playerid][JobStarted] = false;
		APlayerData[playerid][JobStep] = 0;
		APlayerData[playerid][JobID] = 0;
		APlayerData[playerid][VehicleTimerTime] = 0;
		APlayerData[playerid][VehicleID] = 0;
		APlayerData[playerid][TrailerID] = 0;
		APlayerData[playerid][JobLoc1] = 0;
		APlayerData[playerid][JobLoc2] = 0;
		if (APlayerData[playerid][LoadID] != 0)
		{
			DestroyVehicle(APlayerData[playerid][LoadID]);
			APlayerData[playerid][LoadID] = 0; 
		}
		DisablePlayerCheckpoint(playerid);
		DisablePlayerRaceCheckpoint(playerid);
		TextDrawSetString(APlayerData[playerid][MissionText], RoadWorker_NoJobText);
		KillTimer(APlayerData[playerid][LoadingTimer]);
	}
	return 1;
}
CreateBrokenVehicle(Float:x, Float:y, Float:z)
{
	new vid, panels, doors, lights, tires;
	new paramsengine, paramslights, paramsalarm, paramsdoors, paramsbonnet, paramsboot, paramsobjective;
	new BrokenVids[] = {400, 401, 402, 404, 405, 409, 410, 411, 412, 415, 419, 420, 421, 424, 426, 429, 434, 436, 438, 439, 442, 445, 451, 458, 466, 467, 474, 475, 477, 479, 480, 489, 490, 491, 492, 494, 495, 496, 500, 502, 503, 504, 505, 506, 507, 516, 517, 518, 526, 527, 528, 529, 533, 534, 535, 536, 540, 541, 542, 543, 545, 546, 547, 549, 550, 551, 552, 554, 555, 558, 559, 560, 561, 562, 565, 566, 567, 568, 575, 576, 579, 580, 582, 585, 587, 588, 589, 596, 597, 598, 599, 600, 602, 603};
    vid = CreateVehicle(BrokenVids[random(sizeof(BrokenVids))], x, y, z, random(360), random(126), random(126), 3600);
	AVehicleData[vid][Owned] = true;
	GetVehicleParamsEx(vid, paramsengine, paramslights, paramsalarm, paramsdoors, paramsbonnet, paramsboot, paramsobjective);
	SetVehicleParamsEx(vid, paramsengine, paramslights, paramsalarm, true, paramsbonnet, paramsboot, true);
	tires = encode_tires(1, 1, 1, 1); 
	panels = encode_panels(3, 3, 3, 3, 3, 3, 3); 
	doors = encode_doors(4, 4, 4, 4, 4, 4); 
	lights = encode_lights(1, 1, 1, 1);
	UpdateVehicleDamageStatus(vid, panels, doors, lights, tires);
	SetVehicleHealth(vid, 300.0);
	return vid;
}
encode_tires(tire1, tire2, tire3, tire4)
{
	return tire1 | (tire2 << 1) | (tire3 << 2) | (tire4 << 3);
}
encode_panels(flp, frp, rlp, rrp, windshield, front_bumper, rear_bumper)
{
    return flp | (frp << 4) | (rlp << 8) | (rrp << 12) | (windshield << 16) | (front_bumper << 20) | (rear_bumper << 24);
}
encode_doors(bonnet, boot, driver_door, passenger_door, behind_driver_door, behind_passenger_door)
{
    #pragma unused behind_driver_door
    #pragma unused behind_passenger_door
    return bonnet | (boot << 8) | (driver_door << 16) | (passenger_door << 24);
}
encode_lights(light1, light2, light3, light4)
{
    return light1 | (light2 << 1) | (light3 << 2) | (light4 << 3);
}

