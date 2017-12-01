Player_GetFreeHouseSlot(playerid)
{
	for (new HouseIndex; HouseIndex < MAX_HOUSESPERPLAYER; HouseIndex++) 
		if (APlayerData[playerid][Houses][HouseIndex] == 0) 
		    return HouseIndex; 
	return -1;
}
House_GetMaxCarSlots(HouseID)
{
	return AHouseData[HouseID][HouseLevel];
}
House_GetFreeCarSlot(HouseID)
{
	new MaxCarSlots = House_GetMaxCarSlots(HouseID);
	for (new CarSlot; CarSlot < MaxCarSlots; CarSlot++)
	{
		if (AHouseData[HouseID][VehicleIDs][CarSlot] == 0)
		    return CarSlot; 
	}
	return -1;
}
House_SetOwner(playerid, HouseID)
{
	new HouseSlotFree, Name[24], Msg[128], Msg1[128];
	HouseSlotFree = Player_GetFreeHouseSlot(playerid);
	if (HouseSlotFree != -1)
	{
		GetPlayerName(playerid, Name, sizeof(Name));
		APlayerData[playerid][Houses][HouseSlotFree] = HouseID;
		RewardPlayer(playerid, -AHouseData[HouseID][HousePrice], 0);
		AHouseData[HouseID][Owned] = true;
		format(AHouseData[HouseID][Owner], 24, Name);
		AHouseData[HouseID][HouseLevel] = 1;
		format(AHouseData[HouseID][HouseName], 100, TXT_DefaultHouseName, Name);
		House_UpdateEntrance(HouseID);
		PlayerFile_Save(playerid);
		format(Msg, 128, TXT_PlayerBoughtHouse, AHouseData[HouseID][HousePrice]);
		SendClientMessage(playerid, 0xFFFFFFFF, Msg);
		format(Msg1, 128, TXT_PlayerBoughtHouseTxT, AHouseData[HouseID][HousePrice]);
        GameTextForPlayer(playerid, Msg1, 5000, 1);         
        PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);         
	}
	else
	    SendClientMessage(playerid, 0xFFFFFFFF, TXT_PlayerOwnsMaxHouses);

	return 1;
}
House_Exit(playerid, HouseID)
{
	SetPlayerVirtualWorld(playerid, 0);
	SetPlayerInterior(playerid, 0);
	SetPlayerPos(playerid, AHouseData[HouseID][HouseX], AHouseData[HouseID][HouseY], AHouseData[HouseID][HouseZ]);
	APlayerData[playerid][CurrentHouse] = 0;
	if (ExitHouseTimer > 0)
	{
	    TogglePlayerControllable(playerid, 0);
		GameTextForPlayer(playerid, TXT_ExitHouseReloadEnv, ExitHouseTimer, 4);
		SetTimerEx("House_ExitTimer", ExitHouseTimer, false, "ii", playerid, HouseID);
	}

	return 1;
}

forward House_ExitTimer(playerid, HouseID);
public House_ExitTimer(playerid, HouseID)
{
    TogglePlayerControllable(playerid, 1);
	for (new CarSlot; CarSlot < 10; CarSlot++)
		if (AHouseData[HouseID][VehicleIDs][CarSlot] != 0)
		    SetVehicleToRespawn(AHouseData[HouseID][VehicleIDs][CarSlot]);

	return 1;
}
House_CreateEntrance(HouseID)
{
	new Msg[128], Float:x, Float:y, Float:z;
	x = AHouseData[HouseID][HouseX];
	y = AHouseData[HouseID][HouseY];
	z = AHouseData[HouseID][HouseZ];
	if (AHouseData[HouseID][Owned] == true)
	{
 		AHouseData[HouseID][PickupID] = CreateDynamicPickup(1272, 1, x, y, z, 0);
		// Create the 3DText that appears above the house-pickup (displays the housename and the name of the owner)
		format(Msg, 128, TXT_PickupHouseOwned, AHouseData[HouseID][HouseName], AHouseData[HouseID][Owner], AHouseData[HouseID][HouseLevel]);
		AHouseData[HouseID][DoorText] = CreateDynamic3DTextLabel(Msg, 0x008080FF, x, y, z + 1.0, 50.0);
		// Add a streamed icon to the map (red house), type = 32, color = 0, world = 0, interior = 0, playerid = -1, drawdist = 150.0
		if (ShowBoughtHouses == true)
			AHouseData[HouseID][MapIconID] = CreateDynamicMapIcon(x, y, z, 32, 0, 0, 0, -1, 150.0);
	}
	else
	{
        // Create a green house-pickup (house is free)
		AHouseData[HouseID][PickupID] = CreateDynamicPickup(1273, 1, x, y, z, 0);
		// Create the 3DText that appears above the house-pickup (displays the price of the house)
		format(Msg, 128, TXT_PickupHouseForSale, AHouseData[HouseID][HousePrice], AHouseData[HouseID][HouseMaxLevel]);
		AHouseData[HouseID][DoorText] = CreateDynamic3DTextLabel(Msg, 0x008080FF, x, y, z + 1.0, 50.0);
		// Add a streamed icon to the map (green house), type = 31, color = 0, world = 0, interior = 0, playerid = -1, drawdist = 150.0
		AHouseData[HouseID][MapIconID] = CreateDynamicMapIcon(x, y, z, 31, 0, 0, 0, -1, 150.0);
	}
}
House_UpdateEntrance(HouseID)
{
	// Setup local variables
	new Msg[128], Float:x, Float:y, Float:z;

	// Get the coordinates of the house's pickup (usually near the door)
	x = AHouseData[HouseID][HouseX];
	y = AHouseData[HouseID][HouseY];
	z = AHouseData[HouseID][HouseZ];

	// Destroy the pickup and map-icon near the house's entrance
	DestroyDynamicPickup(AHouseData[HouseID][PickupID]);
	DestroyDynamicMapIcon(AHouseData[HouseID][MapIconID]);

	// Add a new pickup at the house's location (usually near the door), green = free, blue = owned
	if (AHouseData[HouseID][Owned] == true)
	{
		// Create a blue house-pickup (house is owned)
 		AHouseData[HouseID][PickupID] = CreateDynamicPickup(1272, 1, x, y, z, 0);
		// Update the 3DText that appears above the house-pickup (displays the housename and the name of the owner)
		format(Msg, 128, TXT_PickupHouseOwned, AHouseData[HouseID][HouseName], AHouseData[HouseID][Owner], AHouseData[HouseID][HouseLevel]);
		UpdateDynamic3DTextLabelText(AHouseData[HouseID][DoorText], 0x008080FF, Msg);
		// Add a streamed icon to the map (red house), type = 32, color = 0, world = 0, interior = 0, playerid = -1, drawdist = 150.0
		if (ShowBoughtHouses == true)
			AHouseData[HouseID][MapIconID] = CreateDynamicMapIcon(x, y, z, 32, 0, 0, 0, -1, 150.0);
	}
	else
	{
        // Create a green house-pickup (house is free)
		AHouseData[HouseID][PickupID] = CreateDynamicPickup(1273, 1, x, y, z, 0);
		// Update the 3DText that appears above the house-pickup (displays the price of the house)
		format(Msg, 128, TXT_PickupHouseForSale, AHouseData[HouseID][HousePrice], AHouseData[HouseID][HouseMaxLevel]);
		UpdateDynamic3DTextLabelText(AHouseData[HouseID][DoorText], 0x008080FF, Msg);
		// Add a streamed icon to the map (green house), type = 31, color = 0, world = 0, interior = 0, playerid = -1, drawdist = 150.0
		AHouseData[HouseID][MapIconID] = CreateDynamicMapIcon(x, y, z, 31, 0, 0, 0, -1, 150.0);
	}
}
House_AddVehicle(HouseID, cModel, cPaint, cComponents[], Float:cx, Float:cy, Float:cz, Float:crot, Col1, Col2)
{
	new vid, CarSlot;
	CarSlot = House_GetFreeCarSlot(HouseID);
	if (CarSlot != -1)
	{
		vid = CreateVehicle(cModel, cx, cy, cz, crot, Col1, Col2, 600);
		AHouseData[HouseID][VehicleIDs][CarSlot] = vid;
		AVehicleData[vid][Model] = cModel;
		AVehicleData[vid][PaintJob] = cPaint;
		if (cPaint != 0)
			ChangeVehiclePaintjob(vid, cPaint - 1);
		ChangeVehicleColor(vid, Col1, Col2);
		AVehicleData[vid][Color1] = Col1;
		AVehicleData[vid][Color2] = Col2;
		for (new i; i < 14; i++)
		{
			AVehicleData[vid][Components][i] = cComponents[i];
			if (AVehicleData[vid][Components][i] != 0)
		        AddVehicleComponent(vid, AVehicleData[vid][Components][i]); 
		}
        AVehicleData[vid][SpawnX] = cx;
        AVehicleData[vid][SpawnY] = cy;
        AVehicleData[vid][SpawnZ] = cz;
        AVehicleData[vid][SpawnRot] = crot;
		AVehicleData[vid][Fuel] = MaxFuel;
		AVehicleData[vid][Owned] = true;
		format(AVehicleData[vid][Owner], 24, AHouseData[HouseID][Owner]);
		AVehicleData[vid][BelongsToHouse] = HouseID;
	}
	else
		return 0;
	return vid;
}
House_ReplaceVehicle(HouseID, CarSlot)
{
	// Setup local variables
	new vid, cModel, cPaint, cComponents[14], Float:cx, Float:cy, Float:cz, Float:crot, Col1, Col2, Float:Health, cFuel;
	new panels, doors, lights, tires;

	// Get the data from the already existing vehicle that was parked before
	vid = AHouseData[HouseID][VehicleIDs][CarSlot];
	cModel = AVehicleData[vid][Model];
	cPaint = AVehicleData[vid][PaintJob];
	cFuel = AVehicleData[vid][Fuel];
	for (new i; i < 14; i++)
	    cComponents[i] = AVehicleData[vid][Components][i];
	Col1 = AVehicleData[vid][Color1];
	Col2 = AVehicleData[vid][Color2];
	cx = AVehicleData[vid][SpawnX];
	cy = AVehicleData[vid][SpawnY];
	cz = AVehicleData[vid][SpawnZ];
	crot = AVehicleData[vid][SpawnRot];
	GetVehicleHealth(vid, Health);
	GetVehicleDamageStatus(vid, panels, doors, lights, tires);

	// Delete the vehicle and clear the data
	Vehicle_Delete(vid);

	// Create a new vehicle in the same carslot
	vid = House_AddVehicle(HouseID, cModel, cPaint, cComponents, Float:cx, Float:cy, Float:cz, Float:crot, Col1, Col2);
	// Update the fuel of the vehicle to the previous setting
	AVehicleData[vid][Fuel] = cFuel;
	// Update the health to what it was before and update the bodywork
	SetVehicleHealth(vid, Health);
	UpdateVehicleDamageStatus(vid, panels, doors, lights, tires);

	return vid;
}

// This function is used only when a player logs out (the vehicles are unloaded)
House_RemoveVehicles(HouseID)
{
	new vid;
	for (new CarSlot; CarSlot < 10; CarSlot++)
	{
		vid = AHouseData[HouseID][VehicleIDs][CarSlot];
		if (vid != 0)
		{
			DestroyVehicle(vid);
			AHouseData[HouseID][VehicleIDs][CarSlot] = 0;
			AVehicleData[vid][Owned] = false;
			AVehicleData[vid][Owner] = 0;
			AVehicleData[vid][Model] = 0;
			AVehicleData[vid][PaintJob] = 0;
			for (new i; i < 14; i++)
			    AVehicleData[vid][Components][i] = 0;
			AVehicleData[vid][SpawnX] = 0.0;
			AVehicleData[vid][SpawnY] = 0.0;
			AVehicleData[vid][SpawnZ] = 0.0;
			AVehicleData[vid][SpawnRot] = 0.0;
			AVehicleData[vid][BelongsToHouse] = 0;
		}
	}
}
House_CalcSellPrice(HouseID)
{
	new SellPrice, NumUpgrades, UpgradePrice;
	SellPrice = AHouseData[HouseID][HousePrice] / 2;
	NumUpgrades = AHouseData[HouseID][HouseLevel] - 1;
	UpgradePrice = ((AHouseData[HouseID][HousePrice] / 100) * HouseUpgradePercent) * NumUpgrades;
	SellPrice = SellPrice + UpgradePrice;
	return SellPrice;
}

House_PlayerIsOwner(playerid, HouseID)
{
	for (new i; i < MAX_HOUSESPERPLAYER; i++)
	{
		if (APlayerData[playerid][Houses][i] == HouseID)
		    return 1;
	}
	return 0;
}

