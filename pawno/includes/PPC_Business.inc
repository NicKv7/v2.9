/**********************
****[100% REVISADO]****
***********************/
forward Business_TransactionTimer();
public Business_TransactionTimer()
{
    BusinessTransactionTime++;
	BusinessTime_Save();
}
Player_GetFreeBusinessSlot(playerid)
{
	for (new BusIndex; BusIndex < MAX_BUSINESSPERPLAYER; BusIndex++) 
		if (APlayerData[playerid][Business][BusIndex] == 0) 
		    return BusIndex;
	return -1;
}
Business_SetOwner(playerid, BusID)
{
	new BusSlotFree, Name[24], Msg[128], Msg1[128], BusType;
	BusSlotFree = Player_GetFreeBusinessSlot(playerid);
	if (BusSlotFree != -1)
	{
		GetPlayerName(playerid, Name, sizeof(Name));
		APlayerData[playerid][Business][BusSlotFree] = BusID;
		BusType = ABusinessData[BusID][BusinessType];
		RewardPlayer(playerid, -ABusinessInteriors[BusType][BusPrice], 0);
		ABusinessData[BusID][Owned] = true;
		format(ABusinessData[BusID][Owner], 24, Name);
		ABusinessData[BusID][BusinessLevel] = 1;
		format(ABusinessData[BusID][BusinessName], 100, ABusinessInteriors[BusType][InteriorName]);
		ABusinessData[BusID][LastTransaction] = BusinessTransactionTime;
		Business_UpdateEntrance(BusID);
		PlayerFile_Save(playerid);
		format(Msg, 128, TXT_PlayerBoughtBusiness, ABusinessInteriors[BusType][BusPrice]);
		SendClientMessage(playerid, 0xFFFFFFFF, Msg);
		format(Msg1, 128, TXT_PlayerBoughtBusinessTxT, ABusinessInteriors[BusType][BusPrice]);
        GameTextForPlayer(playerid, Msg1, 5000, 1);         
        PlayerPlaySound(playerid, 1149, 0.0, 0.0, 0.0);   
	}
	else
	    SendClientMessage(playerid, 0xFFFFFFFF, TXT_PlayerOwnsMaxBusinesses);
	return 1;
}

Business_Exit(playerid, BusID)
{
	SetPlayerVirtualWorld(playerid, 0);
	SetPlayerInterior(playerid, 0);
	SetPlayerPos(playerid, ABusinessData[BusID][BusinessX], ABusinessData[BusID][BusinessY], ABusinessData[BusID][BusinessZ]);
	APlayerData[playerid][CurrentBusiness] = 0;
	if (ExitBusinessTimer > 0)
	{
	    TogglePlayerControllable(playerid, 0);
		GameTextForPlayer(playerid, TXT_ExitHouseReloadEnv, ExitBusinessTimer, 4);
		SetTimerEx("Business_ExitTimer", ExitBusinessTimer, false, "ii", playerid, BusID);
	}

	return 1;
}

forward Business_ExitTimer(playerid, BusID);
public Business_ExitTimer(playerid, BusID)
{
    TogglePlayerControllable(playerid, 1);
	return 1;
}
Business_CreateEntrance(BusID)
{
	new Msg[128], Float:x, Float:y, Float:z, BusType, Icon;
	x = ABusinessData[BusID][BusinessX];
	y = ABusinessData[BusID][BusinessY];
	z = ABusinessData[BusID][BusinessZ];
	BusType = ABusinessData[BusID][BusinessType];
	Icon = ABusinessInteriors[BusType][IconID];
	ABusinessData[BusID][PickupID] = CreateDynamicPickup(1274, 1, x, y, z, 0);
	ABusinessData[BusID][MapIconID] = CreateDynamicMapIcon(x, y, z, Icon, 0, 0, 0, -1, 150.0);
	if (ABusinessData[BusID][Owned] == true)
	{
		format(Msg, 128, TXT_PickupBusinessOwned, ABusinessData[BusID][BusinessName], ABusinessData[BusID][Owner], ABusinessData[BusID][BusinessLevel]);
		ABusinessData[BusID][DoorText] = CreateDynamic3DTextLabel(Msg, 0x008080FF, x, y, z + 1.0, 50.0);
	}
	else
	{
		format(Msg, 128, TXT_PickupBusinessForSale, ABusinessInteriors[BusType][InteriorName], ABusinessInteriors[BusType][BusPrice], ABusinessInteriors[BusType][BusEarnings]);
		ABusinessData[BusID][DoorText] = CreateDynamic3DTextLabel(Msg, 0x008080FF, x, y, z + 1.0, 50.0);
	}
}
Business_UpdateEntrance(BusID)
{
	new Msg[128], BusType;
	BusType = ABusinessData[BusID][BusinessType];
	if (ABusinessData[BusID][Owned] == true)
	{
		format(Msg, 128, TXT_PickupBusinessOwned, ABusinessData[BusID][BusinessName], ABusinessData[BusID][Owner], ABusinessData[BusID][BusinessLevel]);
		UpdateDynamic3DTextLabelText(ABusinessData[BusID][DoorText], 0x008080FF, Msg);
	}
	else
	{
		format(Msg, 128, TXT_PickupBusinessForSale, ABusinessInteriors[BusType][InteriorName], ABusinessInteriors[BusType][BusPrice], ABusinessInteriors[BusType][BusEarnings]);
		UpdateDynamic3DTextLabelText(ABusinessData[BusID][DoorText], 0x008080FF, Msg);
	}
}
Business_PayEarnings(playerid, BusID)
{
	new Msg[128];
	new BusType = ABusinessData[BusID][BusinessType];
	new Earnings = (BusinessTransactionTime - ABusinessData[BusID][LastTransaction]) * ABusinessInteriors[BusType][BusEarnings] * ABusinessData[BusID][BusinessLevel];
	ABusinessData[BusID][LastTransaction] = BusinessTransactionTime;
	RewardPlayer(playerid, Earnings, 0);
	format(Msg, 128, "{00FF00}Sua empresa lucrou {FFFF00}R$%i{00FF00} desde a sua última retirada.", Earnings);
	SendClientMessage(playerid, 0xFFFFFFFF, Msg);
}

