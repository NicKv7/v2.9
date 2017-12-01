/**********************
****[100% REVISADO]****
***********************/
forward Convoy_Timer(Convoy);
Convoys_Init()
{
	for (new i; i < MAX_CONVOYS; i++)
	{
		AConvoys[i][ConvoyTextLeader] = TextDrawCreate(320.0, 1.0, " ");
		TextDrawSetShadow(AConvoys[i][ConvoyTextLeader], 1);
		TextDrawAlignment(AConvoys[i][ConvoyTextLeader], 2);
		TextDrawUseBox(AConvoys[i][ConvoyTextLeader], 1);
		TextDrawBoxColor(AConvoys[i][ConvoyTextLeader] ,0x00000066);

		AConvoys[i][ConvoyTextMember] = TextDrawCreate(320.0, 1.0, " ");
		TextDrawSetShadow(AConvoys[i][ConvoyTextLeader], 1);
		TextDrawAlignment(AConvoys[i][ConvoyTextMember], 2);
		TextDrawUseBox(AConvoys[i][ConvoyTextMember], 1);
		TextDrawBoxColor(AConvoys[i][ConvoyTextMember] ,0x00000066);
	}
}
Convoy_Create(playerid, Convoy)
{
	new Name[24], Msg[128];
	GetPlayerName(playerid, Name, sizeof(Name));
	if (Convoy_PlayerAllowed(playerid))
	{
		AConvoys[Convoy][Status] = CONVOY_OPEN;
		AConvoys[Convoy][Members][0] = playerid;
		APlayerData[playerid][InConvoy] = true;
		APlayerData[playerid][ConvoyID] = Convoy;
		for (new i = 1; i < CONVOY_MAX_MEMBERS; i++)
		    AConvoys[Convoy][Members][i] = -1;
		AConvoys[Convoy][ConvoyTimer] = SetTimerEx("Convoy_Timer", 1000, true, "i", Convoy);
		format(Msg, 128, TXT_PlayerStartsConvoy, Name);
		SendClientMessageToAll(0xFFFFFFFF, Msg);
	}
}
Convoy_Join(playerid, Convoy)
{
	new Name[24], Msg[128];
	GetPlayerName(playerid, Name, sizeof(Name));
	if (Convoy_PlayerAllowed(playerid))
	{
		if (Convoy_CountMembers(Convoy) < CONVOY_MAX_MEMBERS)
		{
			format(Msg, 128, TXT_PlayerJoinedConvoy, Name);
			Convoy_SendMessage(Convoy, Msg);
			SendClientMessage(playerid, 0xFFFFFFFF, TXT_YouJoinedConvoy);
			for (new i; i < CONVOY_MAX_MEMBERS; i++)
			{
			    if (AConvoys[Convoy][Members][i] == -1)
				{
					AConvoys[Convoy][Members][i] = playerid;
					break;
				}
			}
			APlayerData[playerid][InConvoy] = true;
			APlayerData[playerid][ConvoyID] = Convoy;
			if (Convoy_CountMembers(Convoy) == CONVOY_MAX_MEMBERS)
			    AConvoys[Convoy][Status] = CONVOY_FULL;
			TextDrawSetString(APlayerData[playerid][MissionText], TXT_WaitingLeaderJob);
		}
		else
		    SendClientMessage(playerid, 0xFFFFFFFF, TXT_ConvoyFull);
	}
}
Convoy_Leave(playerid)
{
	new Convoy, NumMembers, MemberID;
	if (APlayerData[playerid][InConvoy] == false)
	    return 1;
	Convoy = APlayerData[playerid][ConvoyID];
	NumMembers = Convoy_CountMembers(Convoy);
	if (NumMembers == 1)
	{
		Convoy_Cancel(Convoy);
		return 1;
	}
	APlayerData[playerid][InConvoy] = false;
	APlayerData[playerid][ConvoyID] = 0;
	TextDrawHideForPlayer(playerid, AConvoys[Convoy][ConvoyTextLeader]);
	TextDrawHideForPlayer(playerid, AConvoys[Convoy][ConvoyTextMember]);
	if (APlayerData[playerid][JobStarted] == false)
		TextDrawSetString(APlayerData[playerid][MissionText], Trucker_NoJobText);
	if (AConvoys[Convoy][Members][0] == playerid)
	{
		for (new j = 1; j < CONVOY_MAX_MEMBERS; j++)
		{
			MemberID = AConvoys[Convoy][Members][j];
			if (MemberID != -1)
			{
				TextDrawHideForPlayer(MemberID, AConvoys[Convoy][ConvoyTextMember]);
				AConvoys[Convoy][Members][0] = MemberID;
				AConvoys[Convoy][Members][j] = -1;
				return 1;
			}
		}
	}
	else
	{
		for (new i = 1; i < CONVOY_MAX_MEMBERS; i++)
		{
			if (AConvoys[Convoy][Members][i] == playerid)
			{
			    AConvoys[Convoy][Members][i] = -1;
				Trucker_EndJob(playerid);

				return 1;
			}
		}
	}
	return 1;
}
Convoy_Cancel(Convoy)
{
	new MemberID;
	for (new i; i < CONVOY_MAX_MEMBERS; i++)
	{
	    MemberID = AConvoys[Convoy][Members][i];
		if (MemberID != -1)
		{
			APlayerData[MemberID][InConvoy] = false;
			APlayerData[MemberID][ConvoyID] = 0;
   	        TextDrawHideForPlayer(MemberID, AConvoys[Convoy][ConvoyTextLeader]);
   	        TextDrawHideForPlayer(MemberID, AConvoys[Convoy][ConvoyTextMember]);
			Trucker_EndJob(MemberID);
		    AConvoys[Convoy][Members][i] = -1;
			SendClientMessage(MemberID, 0xFFFFFFFF, TXT_LeaderCancelledConvoy);
		}
	}
	AConvoys[Convoy][LoadID] = 0;
	AConvoys[Convoy][Location1] = 0;
	AConvoys[Convoy][Location2] = 0;
	AConvoys[Convoy][Status] = CONVOY_EMPTY;
	AConvoys[Convoy][ConvoyStep] = 0;
	AConvoys[Convoy][TrailerModel] = 0;
	AConvoys[Convoy][LeaderInformedTrailers] = false;
	KillTimer(AConvoys[Convoy][ConvoyTimer]);
}
Convoy_StartMemberJob(playerid, Convoy)
{
	new StartLoc[50], EndLoc[50], Load[50], RouteText[255], Float:x, Float:y, Float:z, LoadMsg[128];
	APlayerData[playerid][JobStarted] = true;
	APlayerData[playerid][LoadID] = AConvoys[Convoy][LoadID];
	APlayerData[playerid][JobLoc1] = AConvoys[Convoy][Location1];
	APlayerData[playerid][JobLoc2] = AConvoys[Convoy][Location2];
	APlayerData[playerid][VehicleID] = GetPlayerVehicleID(playerid);
	APlayerData[playerid][TrailerID] = GetVehicleTrailer(GetPlayerVehicleID(playerid));
	APlayerData[playerid][JobStep] = 1;
	format(StartLoc, 50, ALocations[APlayerData[playerid][JobLoc1]][LocationName]);
	format(EndLoc, 50, ALocations[APlayerData[playerid][JobLoc2]][LocationName]);
	format(Load, 50, ALoads[APlayerData[playerid][LoadID]][LoadName]);
	format(RouteText, 255, TXT_HaulingCargoFromToPickup, Load, StartLoc, EndLoc);
	TextDrawSetString(APlayerData[playerid][MissionText], RouteText);
	x = ALocations[APlayerData[playerid][JobLoc1]][LocX];
	y = ALocations[APlayerData[playerid][JobLoc1]][LocY];
	z = ALocations[APlayerData[playerid][JobLoc1]][LocZ];
	SetPlayerCheckpoint(playerid, x, y, z, 7);
	APlayerData[playerid][VehicleTimerTime] = Job_TimeToFailMission;
	format(LoadMsg, 128, TXT_PickupCargoAt, Load, StartLoc);
	SendClientMessage(playerid, 0xFFFFFFFF, LoadMsg);
	SendClientMessage(playerid, 0xFFFFFFFF, TXT_MeetOtherConvoyMembers);
}
Convoy_UpdateMemberJob(playerid)
{
	new StartLoc[50], EndLoc[50], Load[50], RouteText[255], Float:x, Float:y, Float:z, UnloadMsg[128];
	APlayerData[playerid][JobStep] = 3;
	format(StartLoc, 50, ALocations[APlayerData[playerid][JobLoc1]][LocationName]);
	format(EndLoc, 50, ALocations[APlayerData[playerid][JobLoc2]][LocationName]);
	format(Load, 50, ALoads[APlayerData[playerid][LoadID]][LoadName]);
	format(RouteText, 255, TXT_HaulingCargoFromToDeliver, Load, StartLoc, EndLoc);
	TextDrawSetString(APlayerData[playerid][MissionText], RouteText);
	x = ALocations[APlayerData[playerid][JobLoc2]][LocX];
	y = ALocations[APlayerData[playerid][JobLoc2]][LocY];
	z = ALocations[APlayerData[playerid][JobLoc2]][LocZ];
	SetPlayerCheckpoint(playerid, x, y, z, 7);
	format(UnloadMsg, 128, TXT_DeliverCargoTo, Load, EndLoc);
	SendClientMessage(playerid, 0xFFFFFFFF, UnloadMsg);
}
public Convoy_Timer(Convoy)
{
	new LeaderID, MemberID;
    Convoy_UpdateTextDraws(Convoy);
	LeaderID = AConvoys[Convoy][Members][0];
	switch (AConvoys[Convoy][ConvoyStep])
	{
		case 0:
		{
			new bool:AllSameTrailer = true;
			if (APlayerData[LeaderID][JobStarted] == true)
			{
				AConvoys[Convoy][LoadID] = APlayerData[LeaderID][LoadID];
				AConvoys[Convoy][Location1] = APlayerData[LeaderID][JobLoc1];
				AConvoys[Convoy][Location2] = APlayerData[LeaderID][JobLoc2];
				AConvoys[Convoy][TrailerModel] = GetVehicleModel(GetVehicleTrailer(GetPlayerVehicleID(LeaderID)));
				if (AConvoys[Convoy][TrailerModel] != 0)
				{
					for (new i = 1; i < CONVOY_MAX_MEMBERS; i++)
					{
						MemberID = AConvoys[Convoy][Members][i];
						if (MemberID != -1)
						{
							if (GetVehicleModel(GetVehicleTrailer(GetPlayerVehicleID(MemberID))) != AConvoys[Convoy][TrailerModel])
							{
							    switch (AConvoys[Convoy][TrailerModel])
							    {
									case VehicleTrailerCargo, VehicleTrailerCargo2: TextDrawSetString(APlayerData[MemberID][MissionText], TXT_MemberNeedsCargoTrailer);
									case VehicleTrailerOre: TextDrawSetString(APlayerData[MemberID][MissionText], TXT_MemberNeedsOreTrailer);
									case VehicleTrailerFluids: TextDrawSetString(APlayerData[MemberID][MissionText], TXT_MemberNeedsFluidsTrailer);
								}
								AllSameTrailer = false;
							}
						}
					}
				}
				else
				{
					for (new i = 1; i < CONVOY_MAX_MEMBERS; i++)
					{
						MemberID = AConvoys[Convoy][Members][i];
						if (MemberID != -1)
						{
						    new vModel = GetVehicleModel(GetPlayerVehicleID(MemberID));
							switch (vModel)
							{
								case VehicleFlatbed, VehicleDFT30: AllSameTrailer = true;
								default:
								{
									TextDrawSetString(APlayerData[MemberID][MissionText], "Você precisa de um Flatbed ou DFT-30");
									AllSameTrailer = false;
								}
							}
						}
					}
				}
				if (AllSameTrailer == true)
				{
					SendClientMessage(LeaderID, 0xFFFFFFFF, TXT_AllMembersSameTrailer);
					for (new i = 1; i < CONVOY_MAX_MEMBERS; i++)
					{
						MemberID = AConvoys[Convoy][Members][i];
						if (MemberID != -1)
							Convoy_StartMemberJob(MemberID, Convoy);
					}
	                AConvoys[Convoy][ConvoyStep] = 1;
				    AConvoys[Convoy][Status] = CONVOY_CLOSED;
				}
				else
				{
					if (AConvoys[Convoy][LeaderInformedTrailers] == false)
					{
						SendClientMessage(LeaderID, 0xFFFFFFFF, TXT_AllMembersNotSameTrailer);
						AConvoys[Convoy][LeaderInformedTrailers] = true;
					}
				}
			}
		}
		case 1:
		{
			new bool:AllMembersLoaded = true;
			for (new i; i < CONVOY_MAX_MEMBERS; i++)
			{
				MemberID = AConvoys[Convoy][Members][i];
				if (MemberID != -1)
					if (APlayerData[MemberID][JobStep] != 2)
					    AllMembersLoaded = false;
			}
			if (AllMembersLoaded == true)
			{
				SendClientMessage(LeaderID, 0xFFFFFFFF, TXT_AllMembersLoadedCargo);
				for (new i; i < CONVOY_MAX_MEMBERS; i++)
				{
					MemberID = AConvoys[Convoy][Members][i];
					if (MemberID != -1)
						Convoy_UpdateMemberJob(MemberID);
				}
                AConvoys[Convoy][ConvoyStep] = 2;
			}
		}
		case 2:
		{
			new bool:AllMembersUnloaded = true;
			for (new i; i < CONVOY_MAX_MEMBERS; i++)
			{
				MemberID = AConvoys[Convoy][Members][i];
				if (MemberID != -1)
					if (APlayerData[MemberID][JobStep] != 4)
					    AllMembersUnloaded = false;
			}
			if (AllMembersUnloaded == true)
				AConvoys[Convoy][ConvoyStep] = 3;
		}
		case 3:
		{
			new Float:x1, Float:y1, Float:x2, Float:y2, Float:Distance, Message[128], Payment, Bonus, NumMembers, Name[24], BonusMsg[128];
			NumMembers = Convoy_CountMembers(Convoy);
			GetPlayerName(LeaderID, Name, sizeof(Name));
			x1 = ALocations[APlayerData[LeaderID][JobLoc1]][LocX];
			y1 = ALocations[APlayerData[LeaderID][JobLoc1]][LocY];
			x2 = ALocations[APlayerData[LeaderID][JobLoc2]][LocX];
			y2 = ALocations[APlayerData[LeaderID][JobLoc2]][LocY];
			Distance = floatsqroot(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
			Payment = floatround((Distance * ALoads[APlayerData[LeaderID][LoadID]][PayPerUnit]), floatround_floor);
			if (RandomBonusMission[MissionFinished] == false)
			{
				if (RandomBonusMission[RandomLoad] == APlayerData[LeaderID][LoadID])
					if (RandomBonusMission[RandomStartLoc] == APlayerData[LeaderID][JobLoc1])
						if (RandomBonusMission[RandomEndLoc] == APlayerData[LeaderID][JobLoc2])
						{
						    Payment = Payment * 2;
                            RandomBonusMission[MissionFinished] = true;
							format(BonusMsg, 128, "{00BBFF}O Comboio do líder {FFBB00}%s{00BBFF} finalizou a missão bonus.", Name);
							SendClientMessageToAll(0xFFFFFFFF, BonusMsg);
						}
			}
		    Bonus = (NumMembers * 30) + 100;
			Payment = (Payment * Bonus) / 100;
			for (new i; i < CONVOY_MAX_MEMBERS; i++)
			{
				MemberID = AConvoys[Convoy][Members][i];
				if (MemberID != -1)
				{
					RewardPlayer(MemberID, Payment, 5);
					APlayerData[MemberID][StatsConvoyJobs]++;
					PlayerFile_Save(MemberID);
					Trucker_EndJob(MemberID);
					format(Message, 128, TXT_FinishedConvoy, Payment);
					SendClientMessage(MemberID, 0xFFFFFFFF, Message);
					if (i != 0)
						TextDrawSetString(APlayerData[MemberID][MissionText], TXT_WaitingLeaderJob);
				}
			}
			AConvoys[Convoy][LoadID] = 0;
			AConvoys[Convoy][Location1] = 0;
			AConvoys[Convoy][Location2] = 0;
			AConvoys[Convoy][Status] = CONVOY_OPEN;
			AConvoys[Convoy][ConvoyStep] = 0;
			AConvoys[Convoy][TrailerModel] = 0;
			AConvoys[Convoy][LeaderInformedTrailers] = false;
		}
	}
	return 1;
}
Convoy_UpdateTextDraws(Convoy)
{
	new LeaderID, MemberID, LeaderName[24], NumMembers, TextLeader[128], TextMember[128], LastMember[24], LastMemberID, Float:Distance;
	LeaderID = AConvoys[Convoy][Members][0];
	GetPlayerName(LeaderID, LeaderName, sizeof(LeaderName));
	NumMembers = Convoy_CountMembers(Convoy);
	if (NumMembers > 1)
	{
	    LastMemberID = Convoy_GetFurthestMember(Convoy);
		GetPlayerName(LastMemberID, LastMember, sizeof(LastMember));
		Distance = PlayerToPlayer(LeaderID, LastMemberID);
	}
	else
	{
		format(LastMember, 24, " - ");
		Distance = 0.0;
	}
	format(TextLeader, 128, TXT_LeaderInfoBar, NumMembers, LastMember, Distance);
	TextDrawSetString(AConvoys[Convoy][ConvoyTextLeader], TextLeader);
	TextDrawShowForPlayer(LeaderID, AConvoys[Convoy][ConvoyTextLeader]);
	for (new i = 1; i < CONVOY_MAX_MEMBERS; i++)
	{
		MemberID = AConvoys[Convoy][Members][i];
		if (MemberID != -1)
		{
			Distance = PlayerToPlayer(LeaderID, MemberID);
			format(TextMember, 128, TXT_MemberInfoBar, LeaderName, Distance, NumMembers);
			TextDrawSetString(AConvoys[Convoy][ConvoyTextMember], TextMember);
			TextDrawShowForPlayer(MemberID, AConvoys[Convoy][ConvoyTextMember]);
		}
	}
}
Convoy_CountMembers(Convoy)
{
	new NumMembers;
	for (new i; i < CONVOY_MAX_MEMBERS; i++)
	{
		if (AConvoys[Convoy][Members][i] != -1)
		    NumMembers++;
	}
	return NumMembers;
}
Convoy_PlayerAllowed(playerid)
{
	if (APlayerData[playerid][PlayerClass] == ClassTruckDriver)
	{
		if (APlayerData[playerid][InConvoy] == false)
		{
			if (APlayerData[playerid][JobStarted] == false)
				return true;
			else
			    SendClientMessage(playerid, 0xFFFFFFFF, TXT_CannotJoinJobStarted);
		}
		else
		    SendClientMessage(playerid, 0xFFFFFFFF, TXT_ConvoyAllreadyJoined);
	}
	else
	    SendClientMessage(playerid, 0xFFFFFFFF, TXT_ConvoyNeedsTruckerClass);
	return false;
}
Convoy_SendMessage(Convoy, Message[])
{
	new MemberID;
	for (new i; i < CONVOY_MAX_MEMBERS; i++)
	{
	    MemberID = AConvoys[Convoy][Members][i];
	    if (MemberID != -1)
		{
			SendClientMessage(MemberID, 0xFFFFFFFF, Message);
		}
	}
}
stock Convoy_IsLeader(playerid, Convoy)
{
	if ((APlayerData[playerid][InConvoy] == true) && (AConvoys[Convoy][Members][0] = playerid))
	    return true;
	else
	    return false;
}
stock Convoy_IsMember(playerid, Convoy)
{
	for (new i = 1; i < CONVOY_MAX_MEMBERS; i++)
	    if (AConvoys[Convoy][Members][i] == playerid)
			return true;
	return false;
}
Convoy_GetFurthestMember(Convoy)
{
	new Float:distance = 0.0, Float:distance2 = 0.0, LeaderID, MemberID, result = -1;
	LeaderID = AConvoys[Convoy][Members][0];
	for(new i = 1; i < CONVOY_MAX_MEMBERS; i++)
	{
		MemberID = AConvoys[Convoy][Members][i];
		if (MemberID != -1)
		{
			distance2 = PlayerToPlayer(LeaderID, MemberID);
			if(distance2 > distance)
			{
				distance = distance2;
				result = MemberID;
			}
		}
	}
	return result;
}
PlayerToPlayer(player1, player2)
{
	new Float:pX, Float:pY, Float:pZ, Float:cX, Float:cY, Float:cZ, Float:distance;
	GetPlayerPos(player1, pX, pY, pZ);
	GetPlayerPos(player2, cX, cY, cZ);
	distance = floatsqroot(floatpower(floatabs(floatsub(cX, pX)), 2) + floatpower(floatabs(floatsub(cY, pY)), 2) + floatpower(floatabs(floatsub(cZ, pZ)), 2));
	return floatround(distance);
}

