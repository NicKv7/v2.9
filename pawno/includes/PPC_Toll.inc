forward Toll();
public Toll()
{
    for(new playerid; playerid < MAX_PLAYERS; playerid++)
	{
        if(APlayerData[playerid][LoggedIn] == false) continue;
		if (GetPlayerVehicleSeat(playerid) == 0)
		{
			for (new TollGate; TollGate < MAX_TOLLGATES; TollGate++)
			{
				if (ATollGates[TollGate][GateID] != 0)
				{
			        if(IsPlayerInRangeOfPoint(playerid, 7.5, ATollGates[TollGate][CloseX], ATollGates[TollGate][CloseY], ATollGates[TollGate][CloseZ]))
			        {
			            if(ATollGates[TollGate][GateStatus] == 0)
						{
			                MoveObject(ATollGates[TollGate][GateID], ATollGates[TollGate][OpenX], ATollGates[TollGate][OpenY], ATollGates[TollGate][OpenZ], 3.0);
			                ATollGates[TollGate][GateStatus] = 1;
			                RewardPlayer(playerid, -ATollGates[TollGate][TollPrice], 0);
			                new string[50];
			                format(string, sizeof(string), TXT_PlayerPaysToll, ATollGates[TollGate][TollPrice]);
			                GameTextForPlayer(playerid, string, 3000, 4);
			                SetTimerEx("CloseGate", 5000, false, "i", TollGate);
						}
			        }
				}
			}
		}
    }
}

forward CloseGate(TollGate);
public CloseGate(TollGate)
{
	MoveObject(ATollGates[TollGate][GateID], ATollGates[TollGate][CloseX], ATollGates[TollGate][CloseY], ATollGates[TollGate][CloseZ], 3.0);
	ATollGates[TollGate][GateStatus] = 0;
}

