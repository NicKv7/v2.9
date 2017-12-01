#define Oficina1 IsPlayerInRangeOfPoint(playerid, 2.5, -47.7836, 270.6917, 2.2500) //
#define Oficina2 IsPlayerInRangeOfPoint(playerid, 10.0, 24.6492, 2418.9697, 22.7578)
#define Oficina3 IsPlayerInRangeOfPoint(playerid, 3.0, 1348.4963, 946.5101, 10.5252)
#define Oficina4 IsPlayerInRangeOfPoint(playerid, 4.0, -547.3569,507.0492,2.5933)
#define Oficina5 IsPlayerInRangeOfPoint(playerid, 5.0, -1656.2089,454.5365,7.4053) 
#define Oficina6 IsPlayerInRangeOfPoint(playerid, 5.0, 2096.6445,1120.9552,11.1395)
#define Oficina7 IsPlayerInRangeOfPoint(playerid, 4.0, 825.8396, -2054.9148, 12.6603)
           
COMMAND:reparar(playerid, params[])//OK
{   
	SendAdminText(playerid, "/reparar", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			if(!IsPlayerInAnyVehicle(playerid))
				return SendClientMessage(playerid, 0xFF0000FF, "{FF0000}Você não está em um veículo!");
			RepairVehicle(GetPlayerVehicleID(playerid));
			SendClientMessage(playerid, 0x00FF00FF, "{00FF00}Veículo reparado!");
		}
		else if (Oficina1 || Oficina2 || Oficina3 || Oficina4 || Oficina5 || Oficina6 || Oficina7)
        {          
            if(!IsPlayerInAnyVehicle(playerid))
			return SendClientMessage(playerid, 0xFF0000FF, "{FF0000}Você não está em um veículo!");
			RepairVehicle(GetPlayerVehicleID(playerid));
			SendClientMessage(playerid, 0x00FF00FF, "{00FF00}[Oficina] Veículo reparado!");
            RewardPlayer(playerid, -500, 0);
		}
        else    
        {        
            SendClientMessage(playerid, 0xFF0000FF,"{FF0000}Você não está em uma oficina!");
        }
	}
	else
	    return 0;
	return 1;
}
COMMAND:neon(playerid, params[])//OK
{
	new OptionsList[200], DialogTitle[200];
	SendAdminText(playerid, "/neon", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (GetPlayerVehicleSeat(playerid) == 0)
		{
            if (Oficina1 || Oficina2 || Oficina3 || Oficina4 || Oficina5 || Oficina6 || Oficina7)
			{
			format(DialogTitle, sizeof(DialogTitle), "Selecione o neon:");

			format(OptionsList, sizeof(OptionsList), "%sSirene\n", OptionsList);
			format(OptionsList, sizeof(OptionsList), "%sNeon vermelho\n", OptionsList);
			format(OptionsList, sizeof(OptionsList), "%sNeon azul\n", OptionsList);
			format(OptionsList, sizeof(OptionsList), "%sNeon verde\n", OptionsList);
			format(OptionsList, sizeof(OptionsList), "%sNeon amarelo\n", OptionsList);
			format(OptionsList, sizeof(OptionsList), "%sNeon rosa\n", OptionsList);
			format(OptionsList, sizeof(OptionsList), "%sNeon branco\n", OptionsList);
			format(OptionsList, sizeof(OptionsList), "%sRemover neon\n", OptionsList);
			ShowPlayerDialog(playerid, DialogNeon, DIALOG_STYLE_LIST, DialogTitle, OptionsList, "Selecionar", "Cancelar");
	        }        
            else            
            SendClientMessage(playerid, 0xFF0000FF, "{FF0000}Você não está em uma oficina!");
    	}
		else
		    SendClientMessage(playerid, 0xFF0000FF, "{FF0000}[Oficina] Você não está dirigindo um veículo!");
	}
	else
	    return 0;
	return 1;
}
COMMAND:pintura(playerid, params[])//OK
{
	new paintjobid, vid;
	SendAdminText(playerid, "/pintura", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (GetPlayerVehicleSeat(playerid) == 0)
		{
            if (Oficina1 || Oficina2 || Oficina3 || Oficina4 || Oficina5 || Oficina6 || Oficina7)
			{
	     		if (sscanf(params, "i", paintjobid)) SendClientMessage(playerid, 0xFF0000AA, "{FF0000}Use: pintura [paintjob 0-2]");
			    else
			    {
		    	    if ((paintjobid >= 0) && (paintjobid <= 2))
			    	{
				    	vid = GetPlayerVehicleID(playerid);
				    	if (AVehicleData[vid][Owned] == true)
				    	{
					    	ChangeVehiclePaintjob(vid, paintjobid);
					    	AVehicleData[vid][PaintJob] = paintjobid + 1;
		    				ChangeVehicleColor(vid, 1, 1);
		    				AVehicleData[vid][Color1] = 1;
		    				AVehicleData[vid][Color2] = 1;
		    				RewardPlayer(playerid, -500, 0);
		    				SendClientMessage(playerid, 0x00FF00FF, "{00FF00}[Oficina] Veículo pintado! R${FFFFFF}500{00FF00}.");
		    				PlayerFile_Save(playerid);
		    			}
			    		else
					    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}Você não é proprietário do veículo!");
    			    }
	    	    	else
			    	SendClientMessage(playerid, 0xFF0000AA, "{FF0000}[Oficina] Você precisa digitar uma paintjob. (0 a 2)");
                }
        	}
            else
                SendClientMessage(playerid, 0xFF0000FF, "{FF0000}Você não está em uma oficina!");
		}
		else
			SendClientMessage(playerid, 0xFF0000FF, "{FF0000}[Oficina] Você deve estar dentro de um veículo que você seja dono, para aplicar uma paintjob!");
	}
	else 
	    return 0;
	return 1;
}
COMMAND:cor1(playerid, params[])//OK
{
	new ColorList[1000];
	SendAdminText(playerid, "/cor1", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (GetPlayerVehicleSeat(playerid) == 0)
		{
            if (Oficina1 || Oficina2 || Oficina3 || Oficina4 || Oficina5 || Oficina6 || Oficina7)
			{
			    if (AVehicleData[GetPlayerVehicleID(playerid)][Owned] == true)
			    {
				    format(ColorList, sizeof(ColorList), "%s{FFFFFF}%s\n", ColorList, "Preto"); 
				    format(ColorList, sizeof(ColorList), "%s{FFFFFF}%s\n", ColorList, "Branco"); 

			    	for (new i = 2; i < sizeof(AVehicleColors); i++)
			    		format(ColorList, sizeof(ColorList), "%s%s%s\n", ColorList, AVehicleColors[i], "CarColor");
			    	ShowPlayerDialog(playerid, DialogPrimaryCarColor, DIALOG_STYLE_LIST, "Escolha a cor primária:", ColorList, "Selecionar", "Cancelar");
		    	}
	    		else
	    		    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}Você não é proprietário do veículo!");
	    	}    
            else
	    		    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}Você não está em uma oficina!");
        }
		else
			SendClientMessage(playerid, 0xFF0000FF, "{FF0000}Você deve estar dentro de um veículo que você seja dono, para aplicar uma cor!");
	}
	else
	    return 0;
	return 1;
}
COMMAND:cor2(playerid, params[])//OK
{
	new ColorList[1000];
	SendAdminText(playerid, "/cor2", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (GetPlayerVehicleSeat(playerid) == 0)
		{
			if (Oficina1 || Oficina2 || Oficina3 || Oficina4 || Oficina5 || Oficina6 || Oficina7)
			{
                if (AVehicleData[GetPlayerVehicleID(playerid)][Owned] == true)
		    	{
			    	format(ColorList, sizeof(ColorList), "%s{FFFFFF}%s\n", ColorList, "Preto"); 
			    	format(ColorList, sizeof(ColorList), "%s{FFFFFF}%s\n", ColorList, "Branco"); 

		    		for (new i = 2; i < sizeof(AVehicleColors); i++)
			    		format(ColorList, sizeof(ColorList), "%s%s%s\n", ColorList, AVehicleColors[i], "CarColor");
		    		ShowPlayerDialog(playerid, DialogSedundaryCarColor, DIALOG_STYLE_LIST, "Escolha a cor secundária:", ColorList, "Selecionar", "Cancelar");
    			}
    			else
    		    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}Você não é o proprietário do veículo!");
	        }
    		else
    		    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}Você não está em uma oficina!");
    	}
		else
			SendClientMessage(playerid, 0x00FF00FF, "{FF0000}[Oficina] Você deve estar dentro de um veículo que você seja dono, para aplicar uma cor!");
	}
	else
	    return 0;
	return 1;
}
COMMAND:novidades(playerid, params[])//OK
{
    if(IsPlayerConnected(playerid))
	{
        ShowPlayerDialog(playerid, 8801, DIALOG_STYLE_MSGBOX, "{32FF02}Novidades", "Nova interface.\nRadares indicados no mapa com a letra 'R'.\nNovo sistema de compra de porte de armas.\n\n\nScripter: Brendon\n\n{FF0000}Deixe uma dica ou segestão para o server no blog.\n{FFFFFF}http://transportandoobrasilsamp.blogspot.com", "Ok", "Sair");
		return 1;
	}
    if (APlayerData[playerid][PlayerLevel] == 1)    
    {    
        SendClientMessage(playerid, 0xFFFFFF, " ");  
    }            
    if (APlayerData[playerid][PlayerLevel] == 2)    
    {    
        SendClientMessage(playerid, 0xFFFFFF, "/setint [id] [interior] - Seta um interior a um jogador bugado."); 
        SendClientMessage(playerid, 0xFFFFFF, "/limparchat - Limpa todo o histórico de conversação.");     
    }    
    if (APlayerData[playerid][PlayerLevel] == 3)    
    {    
        SendClientMessage(playerid, 0xFFFFFF, "/setint [id] [interior] - Seta um interior a um jogador bugado."); 
        SendClientMessage(playerid, 0xFFFFFF, "/limparchat - Limpa todo o histórico de conversação.");     
    }    
    if (APlayerData[playerid][PlayerLevel] == 4)    
    {    
        SendClientMessage(playerid, 0xFFFFFF, "/setint [id] [interior] - Seta um interior a um jogador bugado."); 
        SendClientMessage(playerid, 0xFFFFFF, "/limparchat - Limpa todo o histórico de conversação.");     
    }    
    if (APlayerData[playerid][PlayerLevel] == 5)    
    {    
        SendClientMessage(playerid, 0xFFFFFF, "/setint [id] [interior] - Seta um interior a um jogador bugado."); 
        SendClientMessage(playerid, 0xFFFFFF, "/limparchat - Limpa todo o histórico de conversação.");   
    }
    return 1;    
}
COMMAND:equipe(playerid, params[])//OK
{
    if(IsPlayerConnected(playerid))
	{
        ShowPlayerDialog(playerid, 8801, DIALOG_STYLE_MSGBOX, "{32FF02}Equipe Brasil Mega Trucker", "\nDona - administradora/mapper: Jennifer\nDono - fundador: Rennan\n\nServidor hospedado na Hoster Brasil - Hospedagens", "Ok", "Sair");
	}
    return 1;
}
COMMAND:setint(playerid, params[])//OK
{
    if (APlayerData[playerid][PlayerLevel] >= 2)    
    { 
        new id, interid, msgp[80], AdminName[24];
        if (sscanf(params, "ii", id, interid)) SendClientMessage(playerid, 0xFF0000AA, "{FF0000}Use: /setint [id] [interior]");
		else
        if (IsPlayerConnected(id))
		{
            GetPlayerName(playerid, AdminName, sizeof(AdminName));
            SetPlayerInterior(id, interid);
            format(msgp, sizeof msgp, "{FF0000}-| O Administrador %s mudou seu interior para %i |-", AdminName, interid);
            SendClientMessage(id, 0xFFFFFF, msgp);
            SendClientMessage(playerid, 0xFF0000, "{00FF00}Interior setado ao jogador!");
        }             
        else SendClientMessage(playerid, 0xFF0000, "{FF0000}Você não tem permissão para usar esse comando.");
    }    
    return 1;
}
COMMAND:limparchat(playerid, params[])//OK
{
	SendAdminText(playerid, "/limparchat", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 2)
		{
            SendClientMessageToAll(0x00FFFFFF, " "); 
            SendClientMessageToAll(0x00FFFFFF, " ");
            SendClientMessageToAll(0x00FFFFFF, " ");
            SendClientMessageToAll(0x00FFFFFF, " ");
            SendClientMessageToAll(0x00FFFFFF, " ");
            SendClientMessageToAll(0x00FFFFFF, " ");              
            SendClientMessageToAll(0x00FFFFFF, " "); 
            SendClientMessageToAll(0x00FFFFFF, " ");
            SendClientMessageToAll(0x00FFFFFF, " ");
            SendClientMessageToAll(0x00FFFFFF, " ");
            SendClientMessageToAll(0x00FFFFFF, " ");
            SendClientMessageToAll(0x00FFFFFF, " ");             
            SendClientMessageToAll(0x00FFFFFF, " "); 
            SendClientMessageToAll(0x00FFFFFF, " ");
            SendClientMessageToAll(0x00FFFFFF, " ");
            SendClientMessageToAll(0x00FFFFFF, " ");
            SendClientMessageToAll(0x00FFFFFF, " ");
            SendClientMessageToAll(0x00FFFFFF, " ");             
            SendClientMessageToAll(0x00FFFFFF, " "); 
            SendClientMessageToAll(0x00FFFFFF, " ");
            SendClientMessageToAll(0x00FFFFFF, " ");
            SendClientMessageToAll(0x00FFFFFF, " ");
            SendClientMessageToAll(0x00FFFFFF, " ");
            SendClientMessageToAll(0x00FFFFFF, " "); 
        }
        else SendClientMessage(playerid, 0xFF0000AA, "{FF0000}Você não tem permissão para usar esse comando.");
    }
    return 1;
}            
COMMAND:tapa(playerid, params[])//OK
{
	new Msg[128], Name[24], AdminName[24], OtherPlayer;
	SendAdminText(playerid, "/tapa", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			if (sscanf(params, "u", OtherPlayer)) SendClientMessage(playerid, 0xFF0000AA, "{FF0000}Use: /tapa [id]");
			else
			{
				if (IsPlayerConnected(OtherPlayer))
				{
					GetPlayerName(playerid, AdminName, sizeof(AdminName));
					GetPlayerName(OtherPlayer, Name, sizeof(Name));
		        	new player1;
			        player1 = OtherPlayer;
                    new Float:tapax;
                    new Float:tapay;
                    new Float:tapaz;
                    GetPlayerPos(player1, tapax, tapay, tapaz);
                    SetPlayerPos(player1, tapax, tapay, tapaz+10);
					format(Msg, 128, "{FF0000}-| O Administrador %s deu um tapa em %s |-", AdminName, Name);
					SendClientMessageToAll(0xFFFFFFFF, Msg);
					PlayerFile_Save(OtherPlayer);
				}
				else
				    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}Este jogador não se encontra online!");
			}
		}
		else
		    return 0;
	}
	else
	    return 0;
	return 1;
} 
COMMAND:tapao(playerid, params[])//OK
{
	new Msg[128], Name[24], AdminName[24], OtherPlayer;
	SendAdminText(playerid, "/tapao", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			if (sscanf(params, "u", OtherPlayer)) SendClientMessage(playerid, 0xFF0000AA, "{FF0000}Use: /tapao [id]");
			else
			{
				if (IsPlayerConnected(OtherPlayer))
				{
					GetPlayerName(playerid, AdminName, sizeof(AdminName));
					GetPlayerName(OtherPlayer, Name, sizeof(Name));
		        	new player1;
			        player1 = OtherPlayer;
                    new Float:tapax;
                    new Float:tapay;
                    new Float:tapaz;
                    GetPlayerPos(player1, tapax, tapay, tapaz);
                    SetPlayerPos(player1, tapax, tapay, tapaz+40);
					format(Msg, 128, "{FF0000}-| O Administrador %s deu um tapão em %s |-", AdminName, Name);
					SendClientMessageToAll(0xFFFFFFFF, Msg);
					PlayerFile_Save(OtherPlayer);
				}
				else
				    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}Este jogador não se encontra online!");
			}
		}
		else
		    return 0;
	}
	else
	    return 0;
	return 1;
}
COMMAND:fogo(playerid, params[])//OK
{
	new Msg[128], Name[24], AdminName[24], OtherPlayer;
	SendAdminText(playerid, "/fogo", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			if (sscanf(params, "u", OtherPlayer)) SendClientMessage(playerid, 0xFF0000AA, "{FF0000}Use: /fogo [id]");
			else
			{
				if (IsPlayerConnected(OtherPlayer))
				{
					GetPlayerName(playerid, AdminName, sizeof(AdminName));
					GetPlayerName(OtherPlayer, Name, sizeof(Name));
		        	new player1;
			        player1 = OtherPlayer;
                    new Float:burnx;
                    new Float:burny;
                    new Float:burnz;
			        GetPlayerPos(player1,burnx, burny, burnz);
			        CreateExplosion(burnx, burny , burnz + 3, 1, 3);
					format(Msg, 128, "{FF0000}-| O Administrador %s colocou fogo em %s |-", AdminName, Name);
					SendClientMessageToAll(0xFFFFFFFF, Msg);
					PlayerFile_Save(OtherPlayer);
				}
				else
				    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}Este jogador não se encontra online!");
			}
		}
		else
		    return 0;
	}
	else
	    return 0;
	return 1;
}
COMMAND:pm(playerid, params[])//OK
{
	new OtherPlayer, Message[128], Msg1[128], Msg2[128], YourName[24], OtherPlayerName[24];
	SendAdminText(playerid, "/pm", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (sscanf(params, "us[128]", OtherPlayer, Message)) SendClientMessage(playerid, 0xFF0000AA, "{FF0000}Use: /pm [id] [menssagem]");
		else
		{
			if (IsPlayerConnected(OtherPlayer))
			{
			    if (APlayerData[playerid][Muted] == false)
			    {
					GetPlayerName(playerid, YourName, sizeof(YourName));
					GetPlayerName(OtherPlayer, OtherPlayerName, sizeof(OtherPlayerName));
					format(Msg1, 128, "{808080}PM para %s{FFFFFF}: %s", OtherPlayerName, Message);
					format(Msg2, 128, "{A0A0A0}PM de %s{FFFFFF}: %s", YourName, Message);
					SendClientMessage(playerid, 0xFFFFFFFF, Msg1);
					SendClientMessage(OtherPlayer, 0xFFFFFFFF, Msg2);
				}
				else
				    SendClientMessage(playerid, 0xFF0000FF, "{FF0000}Você ainda está mudo!");
			}
			else
			    SendClientMessage(playerid, 0xFF0000FF, "{FF0000}O jogador não está online.");
		}
	}
	else
	 return 0;
	return 1;
}
COMMAND:criarcasa(playerid, params[])//=========================================AKI
{
	new HPrice, MaxLevel, HouseID;
	SendAdminText(playerid, "/criarcasa", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 5)
		{
			if (GetPlayerVehicleSeat(playerid) == -1)
			{
				if (sscanf(params, "ii", HPrice, MaxLevel)) SendClientMessage(playerid, 0xFF0000AA, "Use: /criarcasa [preço] [level]");
				else
				{
					if ((MaxLevel >= 1) && (MaxLevel <= 10))
					{
                        if ((HPrice >= 30000) && (MaxLevel <= 5000000))                        
                        {
    						for (HouseID = 1; HouseID < MAX_HOUSES; HouseID++)
	    						if (AHouseData[HouseID][PickupID] == 0) 
		    					    break; 
			    			if (HouseID < MAX_HOUSES)
				    		{
					    		new Float:x, Float:y, Float:z, Msg[128];
						    	GetPlayerPos(playerid, x, y, z);
    							AHouseData[HouseID][HouseX] = x;
	    						AHouseData[HouseID][HouseY] = y;
		    					AHouseData[HouseID][HouseZ] = z;
			    				AHouseData[HouseID][HouseLevel] = 1;
				    			AHouseData[HouseID][HouseMaxLevel] = MaxLevel;
					    		AHouseData[HouseID][HousePrice] = HPrice;
    							AHouseData[HouseID][Owned] = false;
	    						House_CreateEntrance(HouseID);
		    					HouseFile_Save(HouseID);
			    				format(Msg, 128, "{00FF00}Você criou a casa de ID {FF00FF}%i{00FF00} com sucesso!", HouseID);
				    			SendClientMessage(playerid, 0xFFFFFFFF, Msg);
					    	}
						    else
    				        SendClientMessage(playerid, 0xFF0000FF, "A quantidade máxima de casas criadas, foi atingida!");
	    		        }            
                        else                        
                        SendClientMessage(playerid, 0xFF0000FF, "Valor não permitido!");
                	}
		    		else
				    SendClientMessage(playerid, 0xFF0000FF, "Você deve escolher o Level entre 0 e 10.");
				}
			}
			else
			    SendClientMessage(playerid, 0xFF0000FF, "Você não pode estar dentro de um veículo para criar uma casa!");
		}
	}
	else
	    return 0;
	return 1;
}
COMMAND:idcasa(playerid, params[])
{
	new Msg[128];
	SendAdminText(playerid, "/idcasa", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			if (GetPlayerVehicleID(playerid) == 0)
			{
				for (new HouseID = 1; HouseID < MAX_HOUSES; HouseID++)
				{
					if (AHouseData[HouseID][PickupID] != 0)
					{
						if (AHouseData[HouseID][Owned] == true)
						{
							if (IsPlayerInRangeOfPoint(playerid, 2.5, AHouseData[HouseID][HouseX], AHouseData[HouseID][HouseY], AHouseData[HouseID][HouseZ]))
							{
								format(Msg, 128, "{00FF00} O ID dessa casa é: {FFFF00}%i{00FF00}.", HouseID);
								SendClientMessage(playerid, 0xFFFFFFFF, Msg);
								return 1;
							}
						}
					}
				}
				SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000} Você não está na porta de uma casa para ver o id!");
			}
			else
			    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000} Você não pode ver o id de uma casa estando dentro de um carro!");
		}
		else
		    return 0;
	}
	else
	    return 0;
	return 1;
}
COMMAND:resetarcasa(playerid, params[])
{
	SendAdminText(playerid, "/deletarcasa", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 6)
		{
			if (GetPlayerVehicleID(playerid) == 0)
			{
				for (new HouseID = 1; HouseID < MAX_HOUSES; HouseID++)
				{
					if (AHouseData[HouseID][PickupID] != 0)
					{
	                    AHouseData[HouseID][Owned] = false;
	                    AHouseData[HouseID][Owner] = 0;	
                    }
                }
            }
        }
    }
    return 1;
}                             						
COMMAND:deletarcasa(playerid, params[])
{
	new file[100], Msg[128];
	SendAdminText(playerid, "/deletarcasa", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 5)
		{
			if (GetPlayerVehicleID(playerid) == 0)
			{
				for (new HouseID = 1; HouseID < MAX_HOUSES; HouseID++)
				{
					if (AHouseData[HouseID][PickupID] != 0)
					{
						if (AHouseData[HouseID][Owned] == false)
						{
							if (IsPlayerInRangeOfPoint(playerid, 2.5, AHouseData[HouseID][HouseX], AHouseData[HouseID][HouseY], AHouseData[HouseID][HouseZ]))
							{
	                            AHouseData[HouseID][HouseName] = 0;
	                            AHouseData[HouseID][Insurance] = 0;
	                            AHouseData[HouseID][HouseX] = 0.0;
	                            AHouseData[HouseID][HouseY] = 0.0;
	                            AHouseData[HouseID][HouseZ] = 0.0;
	                            AHouseData[HouseID][HouseLevel] = 0;
	                            AHouseData[HouseID][HouseMaxLevel] = 0;
	                            AHouseData[HouseID][HousePrice] = 0;
	                            AHouseData[HouseID][Owned] = false;
	                            AHouseData[HouseID][Owner] = 0;
	                            AHouseData[HouseID][HouseName] = 0;
	                            AHouseData[HouseID][HouseName] = 0;
	                            AHouseData[HouseID][HouseName] = 0;
								DestroyDynamicPickup(AHouseData[HouseID][PickupID]);
								DestroyDynamicMapIcon(AHouseData[HouseID][MapIconID]);
								DestroyDynamic3DTextLabel(AHouseData[HouseID][DoorText]);
	                            AHouseData[HouseID][PickupID] = 0;
	                            AHouseData[HouseID][MapIconID] = 0;
								format(file, sizeof(file), HouseFile, HouseID);                               
								format(Msg, 128, "{00FF00} Você deletou a casa de ID {FFFF00}%i{00FF00} com sucesso!", HouseID);
								SendClientMessage(playerid, 0xFFFFFFFF, Msg);
								return 1;
							}
						}
					}
				}
				SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000} Você não está na porta de uma casa para apagá-la!");
			}
			else
			    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000} Você não pode deletar uma casa de dentro de um veículo!");
		}
		else
		    return 0;
	}
	else
	    return 0;
	return 1;
}
COMMAND:comprarcasa(playerid, params[])
{
	new Msg[128];
	SendAdminText(playerid, "/comprarcasa", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (GetPlayerVehicleID(playerid) == 0)
		{
			for (new i = 1; i < sizeof(AHouseData); i++)
			{
				if (AHouseData[i][PickupID] != 0)
				{
					if (IsPlayerInRangeOfPoint(playerid, 2.5, AHouseData[i][HouseX], AHouseData[i][HouseY], AHouseData[i][HouseZ]))
					{
					    if (AHouseData[i][Owned] == false)
					    {
					        if (APlayerData[playerid][PlayerMoney] >= AHouseData[i][HousePrice])
					            House_SetOwner(playerid, i); 
					        else
					            SendClientMessage(playerid, 0xFF0000FF, "Você não pode pagar por esta casa.");
					    }
					    else
					    {
					    	format(Msg, 128, "{FF0000} Essa casa tem dono!  Dono:{00FF00}%s{FFFFFF}", AHouseData[i][Owner]);
							SendClientMessage(playerid, 0xFFFFFFFF, Msg);
					    }
					    return 1;
					}
				}
			}
			SendClientMessage(playerid, 0xFF0000FF, "Para comprar esteja na porta da casa desejada(pickup).");
		}
		else
		    SendClientMessage(playerid, 0xFF0000FF, "Você não pode comprar uma casa de dentro de um veículo!");
	}
	else
	    return 0;
	return 1;
}
COMMAND:entrar(playerid, params[])
{
	new HouseID, hLevel, BusID, BusType;
	SendAdminText(playerid, "/entrar", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (GetPlayerVehicleID(playerid) == 0)
		{
			for (HouseID = 1; HouseID < MAX_HOUSES; HouseID++)
			{
				if (AHouseData[HouseID][PickupID] != 0)
				{
					if (IsPlayerInRangeOfPoint(playerid, 2.5, AHouseData[HouseID][HouseX], AHouseData[HouseID][HouseY], AHouseData[HouseID][HouseZ]))
					{
						if (AHouseData[HouseID][HouseOpened] == false)
						{
							if (House_PlayerIsOwner(playerid, HouseID) == 0)
							{
								SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000} Esta casa não é aberta ao público, você não pode entrar!");
							    return 1;
							}
						}
						hLevel = AHouseData[HouseID][HouseLevel];
						SetPlayerVirtualWorld(playerid, 5000 + HouseID);
						SetPlayerInterior(playerid, AHouseInteriors[hLevel][InteriorID]);
						SetPlayerPos(playerid, AHouseInteriors[hLevel][IntX], AHouseInteriors[hLevel][IntY], AHouseInteriors[hLevel][IntZ]);
						APlayerData[playerid][CurrentHouse] = HouseID;
						SendClientMessage(playerid, 0xFFFFFFFF, "{00FF00} Use {FFFF00}/menucasa{00FF00} para selecionar as opções da casa.");
						return 1;
					}
				}
			}
			for (new i; i < MAX_BUSINESSPERPLAYER; i++)
			{
			    BusID = APlayerData[playerid][Business][i];
				if (BusID != 0)
				{
					if (IsPlayerInRangeOfPoint(playerid, 2.5, ABusinessData[BusID][BusinessX], ABusinessData[BusID][BusinessY], ABusinessData[BusID][BusinessZ]))
					{
					    BusType = ABusinessData[BusID][BusinessType];
						SetPlayerVirtualWorld(playerid, 1000 + playerid);
						SetPlayerInterior(playerid, ABusinessInteriors[BusType][InteriorID]);
						SetPlayerPos(playerid, ABusinessInteriors[BusType][IntX], ABusinessInteriors[BusType][IntY], ABusinessInteriors[BusType][IntZ]);
						APlayerData[playerid][CurrentBusiness] = BusID;
						SendClientMessage(playerid, 0xFFFFFFFF, "{00FF00} Use {FFFF00}/menuempresa{00FF00} para selecionar as opções da empresa.");
						return 1;
					}
				}
			}
		}
	}
	else
	    return 0;
	return 1;
}
COMMAND:menucasa(playerid, params[])
{
	new OptionsList[200], DialogTitle[200];
	SendAdminText(playerid, "/menucasa", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][CurrentHouse] != 0)
		{
			format(DialogTitle, sizeof(DialogTitle), "Selecione a opção para: %s", AHouseData[APlayerData[playerid][CurrentHouse]][HouseName]);
		
        	format(OptionsList, sizeof(OptionsList), "%sMudar nome da casa\n", OptionsList);
			format(OptionsList, sizeof(OptionsList), "%sAtualizar casa\n", OptionsList);
			format(OptionsList, sizeof(OptionsList), "%sComprar carro da casa\n", OptionsList);
			format(OptionsList, sizeof(OptionsList), "%sComprar carro da casa seguro\n", OptionsList);
			format(OptionsList, sizeof(OptionsList), "%sVender carro da casa\n", OptionsList);
			format(OptionsList, sizeof(OptionsList), "%sVender casa\n", OptionsList);
			format(OptionsList, sizeof(OptionsList), "%sAbrir casa para o público\n", OptionsList);
			format(OptionsList, sizeof(OptionsList), "%sFechar casa para o público\n", OptionsList);
			format(OptionsList, sizeof(OptionsList), "%sSair da casa\n", OptionsList);
			ShowPlayerDialog(playerid, DialogHouseMenu, DIALOG_STYLE_LIST, DialogTitle, OptionsList, "Selecionar", "Cancelar");
		}
		else
		    SendClientMessage(playerid, 0xFF0000FF, "Você não possui uma casa.");
	}
	else
	    return 0;
	return 1;
}
COMMAND:usarcarro(playerid, params[])
{
	new HouseList[1000];
	SendAdminText(playerid, "/usarcarro", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerJailed] == 0)
		{
			if (GetPlayerVehicleID(playerid) == 0)
			{
				for (new i; i < MAX_HOUSESPERPLAYER; i++)
				{
					if (APlayerData[playerid][Houses][i] != 0)
						format(HouseList, 1000, "%s{00FF00}%s{FFFFFF}\n", HouseList, AHouseData[APlayerData[playerid][Houses][i]][HouseName]);
					else
						format(HouseList, 1000, "%s{FFFFFF}%s{FFFFFF}\n", HouseList, "Slot Vazio");
				}
				ShowPlayerDialog(playerid, DialogGetCarSelectHouse, DIALOG_STYLE_LIST, "Escolha a casa que terá o carro:", HouseList, "Selecionar", "Cancelar");
			}
			else
				SendClientMessage(playerid, 0xFF0000FF, "Você precisa estar a pé, à porta de um veículo para a sua localização!");
		}
		else
		    SendClientMessage(playerid, 0xFF0000FF, "Você não pode usar o comando /usarcarro quando está preso!");
	}
	else
	    return 0;
	return 1;
}
COMMAND:estacionar(playerid, params[])
{
	new Float:x, Float:y, Float:z, Float:rot, vid, HouseID, Msg[128];
	new engine,lights,alarm,doors,bonnet,boot,objective;
	SendAdminText(playerid, "/estacionar", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (GetPlayerVehicleSeat(playerid) == 0)
		{
			vid = GetPlayerVehicleID(playerid);
			HouseID = AVehicleData[vid][BelongsToHouse];
			if ((AVehicleData[vid][Owned] == true) && (HouseID != 0))
			{
				if (IsPlayerInRangeOfPoint(playerid, ParkRange, AHouseData[HouseID][HouseX], AHouseData[HouseID][HouseY], AHouseData[HouseID][HouseZ]))
				{
					GetVehiclePos(vid, x, y, z);
					GetVehicleZAngle(vid, rot);
					AVehicleData[vid][SpawnX] = x;
					AVehicleData[vid][SpawnY] = y;
					AVehicleData[vid][SpawnZ] = z;
					AVehicleData[vid][SpawnRot] = rot;
					for (new i; i < MAX_HOUSESPERPLAYER; i++)
					{
					    HouseID = APlayerData[playerid][Houses][i];
						for (new CarSlot; CarSlot < 10; CarSlot++)
						{
						    if (AHouseData[HouseID][VehicleIDs][CarSlot] == vid)
						    {
			                    House_ReplaceVehicle(HouseID, CarSlot);
			                    PutPlayerInVehicle(playerid, AHouseData[HouseID][VehicleIDs][CarSlot], 0);
								GetVehicleParamsEx(AHouseData[HouseID][VehicleIDs][CarSlot], engine, lights, alarm, doors, bonnet, boot, objective);
								SetVehicleParamsEx(AHouseData[HouseID][VehicleIDs][CarSlot], 1, lights, alarm, doors, bonnet, boot, objective);
			                    break; 
							}
						}
					}
					SendClientMessage(playerid, 0x00FF00FF, "Você estacionou o seu veículo.");
					PlayerFile_Save(playerid);
				}
				else
				{
				    format(Msg, 128, "{FF0000} Você precisa estar dentro do veículo da sua casa para estacioná-lo!", ParkRange);
				    SendClientMessage(playerid, 0xFFFFFFFF, Msg);
				}
			}
			else
			    SendClientMessage(playerid, 0xFF0000FF, "Você não pode estacionar um veículo que não é da sua propriedade!");
		}
		else
		    SendClientMessage(playerid, 0xFF0000FF, "Você deve estar dentro do veículo para estacioná-lo!");
	}
	else
	    return 0;
	return 1;
}
COMMAND:alugarcarro(playerid, params[])
{
	new VehicleClassList[1000];
	SendAdminText(playerid, "/alugarcarro", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (GetPlayerVehicleID(playerid) == 0)
		{
			for (new i; i < sizeof(ACarDealerPickups); i++)
			{
				if (ACarDealerPickups[i][PickupID] != 0)
				{
					if(IsPlayerInRangeOfPoint(playerid, 2.5, ACarDealerPickups[i][pux], ACarDealerPickups[i][puy], ACarDealerPickups[i][puz]))
					{
						format(VehicleClassList, 1000, "%s{00FF00}%s{FFFFFF}\n", VehicleClassList, "Bicicletas e Motos");
						format(VehicleClassList, 1000, "%s{40FF00}%s{FFFFFF}\n", VehicleClassList, "Barcos");
						format(VehicleClassList, 1000, "%s{80FF00}%s{FFFFFF}\n", VehicleClassList, "Converssíveis");
						format(VehicleClassList, 1000, "%s{B0FF00}%s{FFFFFF}\n", VehicleClassList, "Helicópteros");
						format(VehicleClassList, 1000, "%s{FFFF00}%s{FFFFFF}\n", VehicleClassList, "Veículos Industriais");
						format(VehicleClassList, 1000, "%s{B0FF40}%s{FFFFFF}\n", VehicleClassList, "Low-riders");
						format(VehicleClassList, 1000, "%s{80FF80}%s{FFFFFF}\n", VehicleClassList, "Veículos OFF-Road");
						format(VehicleClassList, 1000, "%s{40FFB0}%s{FFFFFF}\n", VehicleClassList, "Aviões");
						format(VehicleClassList, 1000, "%s{00FFFF}%s{FFFFFF}\n", VehicleClassList, "Veículos de Serviço Público");
						format(VehicleClassList, 1000, "%s{00B0FF}%s{FFFFFF}\n", VehicleClassList, "RC");
						format(VehicleClassList, 1000, "%s{0080FF}%s{FFFFFF}\n", VehicleClassList, "Veículos Saloon");
						format(VehicleClassList, 1000, "%s{0040FF}%s{FFFFFF}\n", VehicleClassList, "Veículos Sport");
						format(VehicleClassList, 1000, "%s{0000FF}%s{FFFFFF}\n", VehicleClassList, "Vagões de Estação");
						format(VehicleClassList, 1000, "%s{4000FF}%s{FFFFFF}\n", VehicleClassList, "Reboques");
						format(VehicleClassList, 1000, "%s{8000FF}%s{FFFFFF}\n", VehicleClassList, "Veículos Únicos");
						ShowPlayerDialog(playerid, DialogRentCarClass, DIALOG_STYLE_LIST, "Selecione a classe:", VehicleClassList, "Selecionar", "Cancelar");
						return 1;
					}
				}
			}
			SendClientMessage(playerid, 0xFF0000FF, "Você não pode alugar um veículo quando não está perto de um comerciante.");
		}
		else
		    SendClientMessage(playerid, 0xFF0000FF, "Você não pode alugar um veículo quando estiver dentro de um veículo");
	}
	else
	    return 0;
	return 1;
}
COMMAND:irparacasa(playerid, params[])
{
	new HouseList[1000];
	SendAdminText(playerid, "/irparacasa", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (GetPlayerWantedLevel(playerid) < 3)
		{
			if (APlayerData[playerid][PlayerJailed] == 0)
			{
				if (GetPlayerVehicleID(playerid) == 0)
				{
					for (new i; i < MAX_HOUSESPERPLAYER; i++)
					{
						if (APlayerData[playerid][Houses][i] != 0)
							format(HouseList, 1000, "%s{00FF00}%s{FFFFFF}\n", HouseList, AHouseData[APlayerData[playerid][Houses][i]][HouseName]);
						else
							format(HouseList, 1000, "%s{FFFFFF}%s{FFFFFF}\n", HouseList, "Slot Vazio");
					}
					ShowPlayerDialog(playerid, DialogGoHome, DIALOG_STYLE_LIST, "Selecione a casa que deseja ir:", HouseList, "Selecionar", "Cancelar");
				}
				else
					SendClientMessage(playerid, 0xFF0000FF, "Você precisa estar a pé na porta da sua casa.");
			}
			else
			    SendClientMessage(playerid, 0xFF0000FF, "Você não pode usar o comando /irparacasa quando está preso!");
		}
		else
			SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000} Você não pode usar o comando /irparacasa quando preso!");
	}
	else
	    return 0;
	return 1;
}
COMMAND:dinheiro(playerid, params[])
{
	new Amount, Msg[128];
	SendAdminText(playerid, "/dinheiro", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 5)
		{
			if (sscanf(params, "i", Amount)) SendClientMessage(playerid, 0xFF0000AA, "Use: /dinheiro [quantia]");
			else
			{
				RewardPlayer(playerid, Amount, 0);
				format(Msg, 128, "Você ganhou R$%i", Amount);
				SendClientMessage(playerid, 0x00FF00AA, Msg);
			}
		}
		else
		    return 0;
	}
	else
	    return 0;

	return 1;
}
COMMAND:score(playerid, params[])
{
	new Amount, Msg[128];
	SendAdminText(playerid, "/score", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 6)
		{
			if (sscanf(params, "i", Amount)) SendClientMessage(playerid, 0xFF0000AA, "Usage: /score [quantia]");
			else
			{
				RewardPlayer(playerid, 0, Amount);
				format(Msg, 128, "Você ganhou %i pontos de score", Amount);
				SendClientMessage(playerid, 0x00FF00AA, Msg);
			}
		}
		else
		    return 0;
	}
	else
	    return 0;

	return 1;
}
COMMAND:desatrelar(playerid, params[])
{
	SendAdminText(playerid, "/desatrelar", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		DetachTrailerFromVehicle(GetPlayerVehicleID(playerid));
		SendClientMessage(playerid, 0x0000FFFF, "Você desatrelou a carroceria.");
	}
	else
		return 0;
	return 1;
}
COMMAND:virar(playerid, params[])
{
	SendAdminText(playerid, "/virar", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		new Float:x = 0.0, Float:y = 0.0, Float:z = 0.0;
		if(IsPlayerInAnyVehicle(playerid))
			SetCameraBehindPlayer(playerid);
		GetPlayerPos(playerid, x, y, z);
		SetVehiclePos(GetPlayerVehicleID(playerid), x, y, z);
		SetVehicleZAngle(GetPlayerVehicleID(playerid), 0.0);
	}
	else
	    return 0;
	return 1;
}
COMMAND:reparartodos(playerid, params[])
{
	SendAdminText(playerid, "/reparartodos", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 3)
		{
			for (new i; i < 2000; i++)
				RepairVehicle(i); 
			SendClientMessageToAll(0x00FF00FF, "Todos os Veículos foram reparados pelo admin!");
  }
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// Heals all players
COMMAND:darvidatodos(playerid, params[])
{
	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/darvidatodos", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 3
		if (APlayerData[playerid][PlayerLevel] >= 3)
		{
			// Loop through all players
			for (new i; i < MAX_PLAYERS; i++)
				if (IsPlayerConnected(i)) // Check if the player is connected
				    if (IsPlayerInAnyVehicle(i) == 0) // Check if the player isn't inside a vehicle
				        SetPlayerHealth(i, 100.0); // Heal the player

			// Send all players a message to inform them that all players have been healed
			SendClientMessageToAll(0x00FF00FF, "Todos os jogadores receberam vida máxima!");
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}



// Kills the player
COMMAND:morrer(playerid, params[])
{
	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/morrer", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player has a wanted level of less than 3
		if (GetPlayerWantedLevel(playerid) < 3)
		{
			// Check if the player isn't in jail
			if (APlayerData[playerid][PlayerJailed] == 0)
			{
			    // Force the player back into class-selection
				ForceClassSelection(playerid);
				// Kill the player (required after ForceClassSelection)
				SetPlayerHealth(playerid, 0.0);
			}
			else
			    SendClientMessage(playerid, 0xFF0000FF, "Você não pode usar o comando /morrer quando preso!");
		}
		else
		    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000} Você não pode usar o comando /morrer quando procurado!");
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// Lets the player choose another class
COMMAND:mudar(playerid, params[])
{
	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/mudar", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player has a wanted level of less than 3
		if (GetPlayerWantedLevel(playerid) < 3)
		{
			// Check if the player isn't in jail
			if (APlayerData[playerid][PlayerJailed] == 0)
			{
			    // Force the player back into class-selection
				ForceClassSelection(playerid);
				// Kill the player (required after ForceClassSelection)
				SetPlayerHealth(playerid, 0.0);
			}
			else
			    SendClientMessage(playerid, 0xFF0000FF, "Você não pode usar o comando /reescolher quando preso!");
		}
		else
		    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000} Você não pode usar o comando /reescolher quando procurado!");
	}
	else
	    return 0;
	return 1;
}
COMMAND:trabalhar(playerid, params[])
{
	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/trabalhar", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// First check if the player already has a job
		if (APlayerData[playerid][JobStarted] == false)
		{
		    // Check the player's class
			switch (APlayerData[playerid][PlayerClass])
			{
				case ClassTruckDriver:
				{
					// Get the id of the convoy (if the player is in a convoy)
					new Convoy = APlayerData[playerid][ConvoyID];

					// Check if the player is part of a convoy AND is not the leader
					if ((APlayerData[playerid][InConvoy] == true) && (AConvoys[Convoy][Members][0] != playerid))
					{
						// Let the player know he's not the leader of his convoy and cannot start a job
						SendClientMessage(playerid, 0xFF0000FF, "Você não é o líder do comboio, por tanto não pode iniciar uma missão.");
						// Exit the function
						return 1;
					}

					// A convoy-leader proceeds here, and also a normal player (no convoy-member)

					// Check if the player is the driver of a vehicle
					if (GetPlayerVehicleSeat(playerid) == 0)
					{
						// Check if the player is inside a valid trucking vehicle
						switch (GetVehicleModel(GetPlayerVehicleID(playerid)))
						{
							case VehicleFlatbed, VehicleDFT30, VehicleCementTruck: // Flatbed, DFT-30, CementTruck
								if (APlayerData[playerid][TruckerLicense] == 1) // Check if the player has acquired a truckers license
									ShowPlayerDialog(playerid, DialogTruckerJobMethod, DIALOG_STYLE_LIST, "Selecione o método:", "Configurar sua própria carga e rota\r\nAtribuir auto-carga", "Selecionar", "Cancelar");
								else
								    Trucker_StartRandomJob(playerid); // Start a random job

							case VehicleLineRunner, VehicleTanker, VehicleRoadTrain: // Player is driving a truck which needs a trailer
								if(IsTrailerAttachedToVehicle(GetPlayerVehicleID(playerid))) // Check if there is a trailer attached
									if (APlayerData[playerid][TruckerLicense] == 1) // Check if the player has acquired a truckers license
										ShowPlayerDialog(playerid, DialogTruckerJobMethod, DIALOG_STYLE_LIST, "Selecione o método:", "Configurar sua própria carga e rota\r\nAtribuir auto-carga", "Selecionar", "Cancelar");
									else
									    Trucker_StartRandomJob(playerid); // Start a random job
								else
								    SendClientMessage(playerid, 0xFF0000FF, "Você precisa de um trailer para iniciar o trabalho.");

							default: SendClientMessage(playerid, 0xFF0000FF, "Você precisa estar conduzindo um caminhão para iniciar o trabalho.");
						}
					}
					else
		                SendClientMessage(playerid, 0xFF0000FF, "Você precisa estar conduzindo um caminhão para iniciar o trabalho.");
				}
				case ClassBusDriver:
				{
					// Check if the player is the driver of a vehicle
					if (GetPlayerVehicleSeat(playerid) == 0)
						if (GetVehicleModel(GetPlayerVehicleID(playerid)) == VehicleCoach) // Check if the player is inside a valid busdriver vehicle
							if (APlayerData[playerid][BusLicense] == 1) // Check if the player has acquired a busdriver license
								ShowPlayerDialog(playerid, DialogBusJobMethod, DIALOG_STYLE_LIST, "Selecione o método :", "Escolha sua própria rota de ônibus\r\nAtribuir auto-rota", "Selecionar", "Cancelar");
							else
								BusDriver_StartJob(playerid, random(sizeof(ABusRoutes))); // Start a random job
						else
			                SendClientMessage(playerid, 0xFF0000FF, "Você precisa estar dirigindo um ônibus para iniciar o trabalho!");
					else
		                SendClientMessage(playerid, 0xFF0000FF, "Você precisa estar dirigindo um ônibus para iniciar o trabalho!");
				}
				case ClassPilot:
				{
					// Check if the player is the driver of a vehicle
					if (GetPlayerVehicleSeat(playerid) == 0)
					{
						// Check if the player is inside a valid piloting vehicle
						switch (GetVehicleModel(GetPlayerVehicleID(playerid)))
						{
							case VehicleShamal, VehicleNevada, VehicleMaverick, VehicleCargobob, VehicleAT400, VehicleAndromada, VehicleDodo: // Plane (Shamal), Plane (Nevada), helicopter (Maverick)
								Pilot_StartRandomJob(playerid); // Start a random piloting job
							default: SendClientMessage(playerid, 0xFF0000FF, "Você precisa estar conduzindo um veículo de voo para iniciar o trabalho.");
						}
					}
					else
		                SendClientMessage(playerid, 0xFF0000FF, "Você precisa estar conduzindo um veículo de voo para iniciar o trabalho.");
				}
				case ClassMafia:
				{
					// Check if the player is the driver of a vehicle
					if (GetPlayerVehicleSeat(playerid) == 0)
					{
						// Check if the player is inside a valid piloting vehicle
						switch (GetVehicleModel(GetPlayerVehicleID(playerid)))
						{
							case VehicleSandKing, VehicleMoonbeam: // Sangking, Moonbeam
								Mafia_StartRandomJob(playerid); // Start a random mafia job
							default: SendClientMessage(playerid, 0xFF0000FF, "Você precisa estar conduzindo um veículo da máfia para iniciar o trabalho.");
						}
					}
					else
		                SendClientMessage(playerid, 0xFF0000FF, "Você precisa estar conduzindo um veículo da máfia para iniciar o trabalho.");
				}
				case ClassCourier:
				{
					// Check if the player is the driver of a vehicle
					if (GetPlayerVehicleSeat(playerid) == 0)
					{
						// Check if the player is inside a valid courier vehicle
						switch (GetVehicleModel(GetPlayerVehicleID(playerid)))
						{
							case VehicleBurrito, VehicleFaggio, VehicleBenson: // Van (Burrito), bike (Faggio)
								Courier_StartJob(playerid); // Start a random courier job
							default: SendClientMessage(playerid, 0xFF0000FF, "Você precisa estar conduzindo um veículo dos Correios para iniciar o trabalho.");
						}
					}
					else
		                SendClientMessage(playerid, 0xFF0000FF, "Você precisa estar conduzindo um veículo dos Correios para iniciar o trabalho.");
				}
				case ClassRoadWorker:
				{
					// Check if the player is the driver of a vehicle
					if (GetPlayerVehicleSeat(playerid) == 0)
					{
						// Check if the player is inside a valid courier vehicle
						switch (GetVehicleModel(GetPlayerVehicleID(playerid)))
						{
							case VehicleUtilityVan, VehicleTowTruck: // Utility Van, Towtruck
								Roadworker_StartRandomJob(playerid); // Start a random roadworker job
							default: SendClientMessage(playerid, 0xFF0000FF, "Você precisa estar conduzindo um veículo do DNIT para iniciar o trabalho.");
						}
					}
					else
		                SendClientMessage(playerid, 0xFF0000FF, "Você precisa estar conduzindo um veículo do DNIT para iniciar o trabalho.");
				}
				default: SendClientMessage(playerid, 0xFF0000FF, "A sua classe não pode fazer todos os trabalhos.");
			}
		}
		else // Send a message to let the player know he already has a job
		    SendClientMessage(playerid, 0xFF0000FF, "Você já está realizando um trabalho!");
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// Stops the current job
COMMAND:parartrabalho(playerid, params[])
{
	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/parartrabalho", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
	    // Check if the player has a job started
		if (APlayerData[playerid][JobStarted] == true)
		{
		    // Check the class of the player
			switch (APlayerData[playerid][PlayerClass])
			{
				case ClassTruckDriver: Trucker_EndJob(playerid); // Stop any trucker job
				case ClassBusDriver: BusDriver_EndJob(playerid); // Stop any busdriver job
				case ClassPilot: Pilot_EndJob(playerid); // Stop any pilot job
				case ClassMafia: Mafia_EndJob(playerid); // Stop any mafia job
				case ClassCourier: Courier_EndJob(playerid);
				case ClassRoadWorker: Roadworker_EndJob(playerid);
				default: SendClientMessage(playerid, 0xFF0000FF, "A sua classe não tem trabalho para terminar.");
			}

			// Inform the player that he failed the mission
			GameTextForPlayer(playerid, "~w~Voce ~r~falhou~w~ com seu trabalho. Você perdeu ~y~R$1000~w~ para cobrir as despesas.", 5000, 4);
			// Reduce the player's cash by 1000
			RewardPlayer(playerid, -1000, 0);
		}
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// Displays the player's coordinates on the map
COMMAND:local(playerid, params[])
{
	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/local", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 3
		if (APlayerData[playerid][PlayerLevel] >= 3)
		{
		    // Setup some local variables
			new Message[200], Float:x, Float:y, Float:z, Float:rot, Interior, World;
			// Get the player's position
			GetPlayerPos(playerid, x, y, z);
			// Check if the player is on foot or in a vehicle
			if (GetPlayerVehicleSeat(playerid) == -1)
				GetPlayerFacingAngle(playerid, rot); // Get the player's angle
			else
			    GetVehicleZAngle(GetPlayerVehicleID(playerid), rot);

			// Get the interior where the player is located
			Interior = GetPlayerInterior(playerid);
			// Get the virtual world of the player
			World = GetPlayerVirtualWorld(playerid);
			// combine the position and angle into a proper message
		    format(Message, sizeof(Message), "Localizacao: X=%4.2f, Y=%4.2f, Z=%4.2f, rotacao=%4.2f, interior=%i, world=%i", x, y, z, rot, Interior, World);
		    // Send the message with the coordinates and the angle of the player
			SendClientMessage(playerid, 0xFF0000AA, Message);
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// Saves the location into a file
COMMAND:savelocal(playerid, params[])
{
	new File:LocFile, LineForFile[255], LineMsg[255];
	new Float:x, Float:y, Float:z, LocName[255], ID;

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/savelocal", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 5
		if (APlayerData[playerid][PlayerLevel] >= 5)
		{
			if (sscanf(params, "is[255]", ID, LocName)) SendClientMessage(playerid, 0xFF0000AA, "Use: /savelocal [id] [descrição]");
			else
			{
				if (!fexist("ServerData/Locations.txt"))
				{
				    LocFile = fopen("ServerData/Locations.txt", io_write); // Create the file
					fclose(LocFile); // Close the file
				}

				// Get the player's position
				GetPlayerPos(playerid, x, y, z);
				// Combine all the data in a proper structure, so it can be used directly for setting up the ALocations array
			    format(LineForFile, sizeof(LineForFile), "\t{\"%s\", %4.2f, %4.2f, %4.2f}, // ID = %i", LocName, x, y, z, ID);

				LocFile = fopen("ServerData/Locations.txt", io_append); // Open the locationfile for appending data to it
				fwrite(LocFile, LineForFile); // Append the data to the end of the file
				fwrite(LocFile, "\r\n"); // Start a new line, or all the data is saved in one line
				fclose(LocFile); // Close the file

				// Let the player know what data has been saved
				format(LineMsg, 255, "Localização salva: %s", LineForFile);
				SendClientMessage(playerid, 0x808080FF, LineMsg);
			}
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// Lets the player choose where he wants to respawn (costs $200)
COMMAND:resgate(playerid, params[])
{
	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/resgate", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player has a wanted level of less than 3
		if (GetPlayerWantedLevel(playerid) < 3)
		{
			// Check if the player isn't in jail
			if (APlayerData[playerid][PlayerJailed] == 0)
			{
				if (APlayerData[playerid][JobStarted] == false)
				{
					// Make sure you can't use "/rescue" when you're inside a vehicle (doesn't respawn you at the requested coords
					// and puts a random item (bottle, sigarette, ...) in the player's hands
					if (GetPlayerVehicleID(playerid) == 0)
					{
					    // Create a dialog based on the player's class
						switch (APlayerData[playerid][PlayerClass])
						{
							case ClassTruckDriver: // Ask where the trucker player wants to respawn
								ShowPlayerDialog(playerid, DialogRescue, DIALOG_STYLE_LIST, "Caminhoneiro nascer em:", "Fallen Tree Depot\r\nFlint Trucking Depot\r\nLVA Freight Depot\r\nDoherty Depot\r\nEl Corona Depot\r\nLas Payasdas Depot\r\nQuarry Top\r\nShady Creek Depot", "Spawn", "Cancel");
							case ClassBusDriver: // Ask where the busdriver wants to respawn
								ShowPlayerDialog(playerid, DialogRescue, DIALOG_STYLE_LIST, "Motorista de Ônibus nascer em:", "Los Santos\r\nSan Fierro\r\nLas Venturas", "Spawn", "Cancel");
							case ClassPilot: // Ask where the pilot wants to respawn
								ShowPlayerDialog(playerid, DialogRescue, DIALOG_STYLE_LIST, "Piloto nascer em:", "Los Santos\r\nSan Fierro\r\nLas Venturas", "Spawn", "Cancel");
							case ClassPolice: // Ask where the police player wants to respawn
								ShowPlayerDialog(playerid, DialogRescue, DIALOG_STYLE_LIST, "Policial nascer em:", "Los Santos\r\nSan Fierro\r\nLas Venturas", "Spawn", "Cancel");
							case ClassCourier: // Ask where the courier player wants to respawn
								ShowPlayerDialog(playerid, DialogRescue, DIALOG_STYLE_LIST, "Correios nascer em:", "Los Santos\r\nSan Fierro\r\nLas Venturas", "Spawn", "Cancel");
						}
					}
					else
						SendClientMessage(playerid, 0xFF0000FF, "Você não pode usar o comando /resgate dentro de um veículo."); // "/rescue" doesn't work inside a vehicle
				}
				else
				    SendClientMessage(playerid, 0xFF0000FF, "Você não pode ser resgatado realizando um trabalho!"); // "/rescue" doesn't work during a job
			}
			else
			    SendClientMessage(playerid, 0xFF0000FF, "Você nao pode usar o comando /resgate quando preso.");
		}
		else
		    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000} Você não pode usar o comando /resgate quando procurado.");
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// Increases the player's wanted level by 1
COMMAND:procurado(playerid, params[])
{
	new OtherPlayer, Stars;

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/procurado", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 2
		if (APlayerData[playerid][PlayerLevel] >= 2)
		{
			if (sscanf(params, "ui", OtherPlayer, Stars)) SendClientMessage(playerid, 0xFF0000AA, "Use: /procurado [id] [nivel]");
			else
				if (IsPlayerConnected(OtherPlayer)) // If the player is a valid playerid (he's connected)
					SetPlayerWantedLevel(OtherPlayer, Stars);
				else
				    SendClientMessage(playerid, 0xFF0000FF, "Esse jogador não está online.");
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}



// Lets the player choose a motorcycle to spawn
COMMAND:motos(playerid, params[])
{
	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/motos", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 1
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			// Make sure the player isn't inside a vehicle
			if (GetPlayerVehicleID(playerid) == 0)
			{
				// Ask which motorcycle the player wants to have
				ShowPlayerDialog(playerid, DialogBike, DIALOG_STYLE_LIST, "Escolha a Bike:", "Bike\r\nBMX\r\nMountain Bike\r\nFaggio\r\nPizzaboy\r\nBF-400\r\nNRG-500\r\nPCJ-600\r\nFCR-900\r\nFreeway\r\nWayfarer\r\nSanchez\r\nQuad", "Criar", "Cancelar");
				// Let the server know that this was a valid command
				return 1;
			}
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}



// Lets the player choose a car to spawn (in a split list which shows only 10 cars at a time)
COMMAND:carros(playerid, params[])
{
	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/carros", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 1
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			// Make sure the player isn't inside a vehicle
			if (GetPlayerVehicleID(playerid) == 0)
				CarList_Create(playerid); // Create a list of cars (only the first 10 cars) and show the dialog so the player can choose a car
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}



// Lets the player choose a plane to spawn (in a split list which shows only 10 planes at a time)
COMMAND:avioes(playerid, params[])
{
	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/avioes", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 1
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			// Make sure the player isn't inside a vehicle
			if (GetPlayerVehicleID(playerid) == 0)
				PlaneList_Create(playerid); // Create a list of planes (only the first 10 planes) and show the dialog so the player can choose a plane
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}



// Lets the player choose a trailer to spawn (in a split list which shows only 10 trailers at a time)
COMMAND:trailer(playerid, params[])
{
	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/trailer", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 1
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			// Make sure the player isn't inside a vehicle
			if (GetPlayerVehicleID(playerid) == 0)
				TrailerList_Create(playerid); // Create a list of trailers (only the first 10 trailers) and show the dialog so the player can choose a trailer
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// Lets the player choose a boat to spawn
COMMAND:barcos(playerid, params[])
{
	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/barcos", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 1
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			// Make sure the player isn't inside a vehicle
			if (GetPlayerVehicleID(playerid) == 0)
			{
				// Ask which motorcycle the player wants to have
				ShowPlayerDialog(playerid, DialogBoat, DIALOG_STYLE_LIST, "Escolha o barco:", "Coastguard\nDinghy\nJetmax\nLaunch\nMarquis\nPredator\nReefer\nSpeeder\nSquallo\nTropic", "Criar", "Cancelar");
				// Let the server know that this was a valid command
				return 1;
			}
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}



// Jail a player
COMMAND:prender(playerid, params[])
{
	new PlayerToJail, JailTime, Reason[128], Msg[128], Name[24], AdminName[24];

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/prender", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 1
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			if (sscanf(params, "uis[128]", PlayerToJail, JailTime, Reason)) SendClientMessage(playerid, 0xFF0000AA, "Use: /prender [id] [tempo] [motivo]");
			else
				if (IsPlayerConnected(PlayerToJail)) // If the player is a valid playerid (he's connected)
				{
				    // Jail the player
					Police_JailPlayer(PlayerToJail, JailTime);
					// Get the name of the player who jailed the player
					GetPlayerName(playerid, AdminName, sizeof(AdminName));
					// Get the name of the player who's being sent to jail
					GetPlayerName(PlayerToJail, Name, sizeof(Name));
					// Send the jailed player a message who jailed him, why he's been jailed and how long
					format(Msg, 128, "Você foi preso por %s %s por %i segundos.", AdminLevelName[APlayerData[playerid][PlayerLevel]], AdminName, JailTime);
					SendClientMessage(PlayerToJail, 0xFF0000FF, Msg);
					format(Msg, 128, "Motivo: %s", Reason);
					SendClientMessage(PlayerToJail, 0xFF0000FF, Msg);
					format(Msg, 128, "{00FF00}Você prendeu {FFFF00}%s{00FF00} por {FFFF00}%i{00FF00} segundos.", Name, JailTime);
					SendClientMessage(playerid, 0xFFFFFFFF, Msg);
				}
				else
				    SendClientMessage(playerid, 0xFF0000FF, "Esse jogador não está online.");
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// Warn a player
COMMAND:aviso(playerid, params[])
{
	new PlayerToWarn, Reason[128], ReasonMsg[128], Name[24];
	SendAdminText(playerid, "/aviso", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			if (sscanf(params, "us[128]", PlayerToWarn, Reason)) SendClientMessage(playerid, 0xFF0000AA, "Use: /aviso [id] [motivo]");
			else
				if (IsPlayerConnected(PlayerToWarn)) 
                {
					APlayerData[PlayerToWarn][Warnings]++;
					GetPlayerName(playerid, Name, sizeof(Name));
					format(ReasonMsg, 128, "Você foi avisado por %s %s", AdminLevelName[APlayerData[playerid][PlayerLevel]], Name);
					SendClientMessage(PlayerToWarn, 0xFF0000FF, ReasonMsg);
					format(ReasonMsg, 128, "Motivo: %s", Reason);
					SendClientMessage(PlayerToWarn, 0xFF0000FF, ReasonMsg);
					format(ReasonMsg, 128, "~w~Aviso %i/%i: ~r~%s~w~", APlayerData[PlayerToWarn][Warnings], AutoKickWarnings, Reason);
					GameTextForPlayer(PlayerToWarn, ReasonMsg, 5000, 4);

					GetPlayerName(PlayerToWarn, Name, sizeof(Name));
					format(ReasonMsg, 128, "Você avisou %s (avisos: %i/%i)", Name, APlayerData[PlayerToWarn][Warnings], AutoKickWarnings);
					SendClientMessage(playerid, 0x00FF00FF, ReasonMsg);
					format(ReasonMsg, 128, "Motivo: %s", Reason);
					SendClientMessage(playerid, 0xFF0000FF, ReasonMsg);
					if ((APlayerData[PlayerToWarn][Warnings] == AutoKickWarnings) && (AutoKickAfterWarn == 1))
						Kick(PlayerToWarn);
				}
				else
				    SendClientMessage(playerid, 0xFF0000FF, "Esse jogador não está online.");
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}
COMMAND:kick(playerid, params[])
{
	new PlayerToKick, Reason[128], ReasonMsg[128], Name[24], AdminName[24];
	SendAdminText(playerid, "/kick", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			if (sscanf(params, "us[128]", PlayerToKick, Reason)) SendClientMessage(playerid, 0xFF0000AA, "Use: /kick [id] [motivo]");
			else
				if (IsPlayerConnected(PlayerToKick)) 
				{
                    GetPlayerName(playerid, AdminName, sizeof(AdminName));
	    			GetPlayerName(PlayerToKick, Name, sizeof(Name));          
		    		format(ReasonMsg, 128, "{FF0000}-| %s foi kickado pelo administrador %s. Motivo: %s |-", Name, AdminName, Reason);
			    	SendClientMessageToAll(0xFF0000FF, ReasonMsg);
				    Kick(PlayerToKick);
				}
                else
				    SendClientMessage(playerid, 0xFF0000FF, "Esse jogador não está online.");
		}
		else
		    return 0;
	}
	else
	    return 0;
	return 1;
}
COMMAND:ban(playerid, params[])
{
	new PlayerToBan, Days, Hours, Reason[128], TotalBanTime, Msg[128], Name[24], AdminName[24];
	SendAdminText(playerid, "/ban", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 3)
		{
			if (sscanf(params, "uiis[128]", PlayerToBan, Days, Hours, Reason))
				SendClientMessage(playerid, 0xFF0000AA, "Use: /ban [id] [dias] [horas] [motivo]");
			else
			{
				if (IsPlayerConnected(PlayerToBan))
				{
		    		GetPlayerName(playerid, AdminName, sizeof(AdminName));
			    	GetPlayerName(PlayerToBan, Name, sizeof(Name));
			    	APlayerData[PlayerToBan][Bans]++;
			    	TotalBanTime = (Days * 86400) + (Hours * 3600) + gettime();
			    	if (APlayerData[PlayerToBan][Bans] == 5)
					    APlayerData[PlayerToBan][BanTime] = 2147483640; 
			    	else
			    		APlayerData[PlayerToBan][BanTime] = TotalBanTime; 
		    		if (APlayerData[PlayerToBan][Bans] == 5)
		    		{
			    		format(Msg, 128, "Você foi banido permanentemente por %s, pois ja é o seu 5° banimento.", AdminName);
			    		SendClientMessage(PlayerToBan, 0x808080FF, Msg);
			    	}
		    		else
			    	{
			    		format(Msg, 128, "Você foi banido por %s por %i dias e %i horas.", AdminName, Days, Hours);
				    	SendClientMessage(PlayerToBan, 0x808080FF, Msg);
				    	format(Msg, 128, "Reason: %s", Reason);
				    	SendClientMessage(PlayerToBan, 0x808080FF, Msg);
				    	format(Msg, 128, "Você já foi banido %i vezes, a 5° será permanente.", APlayerData[PlayerToBan][Bans]);
				    	SendClientMessage(PlayerToBan, 0x808080FF, Msg);
			    	}
				}                
                Kick(PlayerToBan);
				format(Msg, 128, "{FF0000}-| O administrador %s %s baniu %s por %i dias e %i horas |-", AdminLevelName[APlayerData[playerid][PlayerLevel]], AdminName, Name, Days, Hours);
				SendClientMessageToAll(0x808080FF, Msg);
			}
		}
		else
		    return 0;
	}
	else
	    return 0;

	return 1;
}
COMMAND:desbanir(playerid, params[])
{
	new PlayerToUnban[24], Msg[128], Name[24];
	new file[100], File:PFile, LineForFile[100];

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/desbanir", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 3
		if (APlayerData[playerid][PlayerLevel] >= 3)
		{
			if (sscanf(params, "s[128]", PlayerToUnban))
				SendClientMessage(playerid, 0xFF0000AA, "Use: /desbanir [nick]");
			else
			{
			    // Get the name of the admin
				GetPlayerName(playerid, Name, sizeof(Name));

				// Construct the complete filename for this player's account
				format(file, sizeof(file), PlayerFile, PlayerToUnban);

				// Check if the file exists
				if (fexist(file))
				{
					PFile = fopen(file, io_append); // Open the playerfile for appending (this command only appends a new line to overwrite the bantime)

					format(LineForFile, 100, "BanTime 0\r\n"); // Construct the line: "BanTime <0>"
					fwrite(PFile, LineForFile); // And save it to the file

					fclose(PFile); // Close the file

					// Inform everybody else which player was unbanned
					format(Msg, 128, "%s %s desbaniu %s", AdminLevelName[APlayerData[playerid][PlayerLevel]], Name, PlayerToUnban);
					SendClientMessageToAll(0x808080FF, Msg);
				}
				else
				    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000} Não existe nenhuma conta com esse nome.");
			}
		}
		else
		    return 0;
	}
	else
	    return 0;

	return 1;
}

// Spawns the object at the location given by the player
COMMAND:objeto(playerid, params[])
{
    // Setup local variables
	new ObjectModel, ObjID, Msg[128], Float:x, Float:y, Float:z, Float:Angle;

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/objeto", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 5
		if (APlayerData[playerid][PlayerLevel] >= 6)
		{
			if (sscanf(params, "iffff", ObjectModel, x, y, z, Angle)) SendClientMessage(playerid, 0xFF0000AA, "Use: /objeto [id-obj] [x] [y] [z] [angulo]");
			else
			{
				// Spawn the object 5 units north of the player
				ObjID = CreateObject(ObjectModel, x, y, z, 0.0, 0.0, Angle, 250.0);
				// Inform the player about it
				format(Msg, 128, "Você criou o objeto id %i (modelo-id = %i) nas coordenadas: x=%4.2f, y=%4.2f, z=%4.2f", ObjID, ObjectModel, x, y, z);
				SendClientMessage(playerid, 0x00FF00FF, Msg);
			}
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// Spawns the pickup at the location given by the player
COMMAND:pickup(playerid, params[])
{
    // Setup local variables
	new PickupModel, PickID, Msg[128], Float:x, Float:y, Float:z, PickupType;

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/pickup", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 5
		if (APlayerData[playerid][PlayerLevel] >= 6)
		{
			if (sscanf(params, "ifffi", PickupModel, x, y, z, PickupType)) SendClientMessage(playerid, 0xFF0000AA, "Use: /pickup [id-pick] [x] [y] [z] [tipo]");
			else
			{
				// Spawn the pickup
				PickID = CreatePickup(PickupModel, PickupType, x, y, z, -1);
				// Inform the player about it
				format(Msg, 128, "Você criou o pickup id %i (modelo-id = %i) nas coordenadas: x=%4.2f, y=%4.2f, z=%4.2f", PickID, PickupModel, x, y, z);
				SendClientMessage(playerid, 0x00FF00FF, Msg);
			}
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// Spawns the vehicle at the location given by the player
COMMAND:setcar(playerid, params[])
{
    // Setup local variables
	new VehicleModel, vID, Msg[128], Float:x, Float:y, Float:z, Float:Angle, SpawnDelay;

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/setcar", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 5
		if (APlayerData[playerid][PlayerLevel] >= 6)
		{
			if (sscanf(params, "iffffi", VehicleModel, x, y, z, Angle, SpawnDelay)) SendClientMessage(playerid, 0xFF0000AA, "Use:/setcar [id] [x] [y] [z] [angulo] [SpawnDelay]");
			else
			{
				// Spawn the vehicle at the location specified by the player (also set max-fuel and save the model for the vehicle)
				vID = Vehicle_Create(VehicleModel, x, y, z, Angle, random(126), random(126), SpawnDelay);
				// Inform the player about it
				format(Msg, 128, "Você criou o veiculo id %i (modelo-id = %i) nas coordenadas: x=%4.2f, y=%4.2f, z=%4.2f", vID, VehicleModel, x, y, z);
				SendClientMessage(playerid, 0x00FF00FF, Msg);
			}
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// Deletes the given vehicle from the game
COMMAND:delveh(playerid, params[])
{
    // Setup local variables
	new vID, Msg[128];

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/delveh", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 5
		if (APlayerData[playerid][PlayerLevel] >= 6)
		{
			if (sscanf(params, "i", vID)) SendClientMessage(playerid, 0xFF0000AA, "Use: \"/delveh [id]");
			else
			{
				// Destroy the given vehicle
				DestroyVehicle(vID);
				// Inform the player about it
				format(Msg, 128, "Você deletou o veículo id %i", vID);
				SendClientMessage(playerid, 0x00FF00FF, Msg);
			}
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// Deletes the given vehicle from the game
COMMAND:deletarobjeto(playerid, params[])
{
    // Setup local variables
	new oID, Msg[128];

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/deletarobjeto", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 5
		if (APlayerData[playerid][PlayerLevel] >= 6)
		{
			if (sscanf(params, "i", oID)) SendClientMessage(playerid, 0xFF0000AA, "Use: /deletarobjeto [id]");
			else
			{
				// Destroy the given vehicle
				DestroyObject(oID);
				// Inform the player about it
				format(Msg, 128, "Você deletou o objeto id %i", oID);
				SendClientMessage(playerid, 0x00FF00FF, Msg);
			}
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// Ports the player to the given coordinates
COMMAND:irpara(playerid, params[])
{
	// Setup local variables
	new Float:x, Float:y, Float:z, PortMsg[128];

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/irpara", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 1
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			// Check if the player has a wanted level of less than 3
			if (GetPlayerWantedLevel(playerid) < 3)
			{
				// Check if the player is not jailed
				if (APlayerData[playerid][PlayerJailed] == 0)
				{
					if (sscanf(params, "fff", x, y, z)) SendClientMessage(playerid, 0xFF0000AA, "Use: /irpara [x] [y] [z]");
					else
					{
						// Port the player to the given location
						SetPlayerPos(playerid, x, y, z);
						// Let the player know about it
						format(PortMsg, 128, "Você foi teleportado para a posição: %4.2f, %4.2f, %4.2f", x, y, z);
						SendClientMessage(playerid, 0x00FF00FF, PortMsg);
					}
				}
				else
				    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000} Você não pode usar o comando /irpara quando preso.");
			}
			else
			    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000} Você não pode usar o comando /irpara quando procurado.");
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// Ports the player to the given player
COMMAND:ir(playerid, params[])
{
	// Setup local variables
	new OtherPlayer, Float:x, Float:y, Float:z, PortMsg[128], IntID, WorldID;

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/ir", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 1
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			// Check if the player has a wanted level of less than 3
			if (GetPlayerWantedLevel(playerid) < 3)
			{
				// Check if the player is not jailed
				if (APlayerData[playerid][PlayerJailed] == 0)
				{
					if (sscanf(params, "u", OtherPlayer)) SendClientMessage(playerid, 0xFF0000AA, "Use: /ir [id]");
					else
					{
						// Check if that other player is online
						if (IsPlayerConnected(OtherPlayer))
						{
							// Get the location of the other player
							GetPlayerPos(OtherPlayer, x, y, z);
							IntID = GetPlayerInterior(OtherPlayer);
							WorldID = GetPlayerVirtualWorld(OtherPlayer);
							// Port the player to the given location
							SetPlayerVirtualWorld(playerid, WorldID);
							SetPlayerInterior(playerid, IntID);
							SetPlayerPos(playerid, x, y, z + 3.0);
							// Let the player know about it
							format(PortMsg, 128, "A posição do jogador é: %4.2f, %4.2f, %4.2f", x, y, z + 3.0);
							SendClientMessage(playerid, 0x00FF00FF, PortMsg);
						}
						else
						    SendClientMessage(playerid, 0xFF0000FF, "Esse jogador não está online.");
					}
				}
				else
				    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000} Você não pode usar o comando /ir quando preso.");
			}
			else
			    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000} Você nao pode usar o comando /ir quando procurado.");
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}
COMMAND:levar(playerid, params[])
{
	new Player1, Player2, Float:x, Float:y, Float:z, PortMsg[128], IntID, WorldID, Name[24], AdminName[24];
	SendAdminText(playerid, "/levar", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			if (sscanf(params, "uu", Player1, Player2)) SendClientMessage(playerid, 0xFF0000AA, "Use: /levar [para] [id]");
			else
			{
				if (APlayerData[Player1][LoggedIn] == true)
				{
					if (APlayerData[Player2][LoggedIn] == true)
					{
					    GetPlayerName(playerid, AdminName, sizeof(AdminName));
					    GetPlayerName(Player2, Name, sizeof(Name)); 
       
     					GetPlayerPos(Player2, x, y, z);
						IntID = GetPlayerInterior(Player2);
						WorldID = GetPlayerVirtualWorld(Player2);
						SetPlayerVirtualWorld(Player1, WorldID);
						SetPlayerInterior(Player1, IntID);
						SetPlayerPos(Player1, x, y, z + 3.0);
						format(PortMsg, 128, "{00FF00} Você foi levado até {FFFF00}%s{00FF00} por {FFFF00}%s{00FF00}.", Name, AdminName);
						SendClientMessage(Player1, 0xFFFFFFFF, PortMsg);
                        format(PortMsg, 128, "{00FF00} Você levou alguem até {FFFF00}%s{00FF00}.", Name);
                        SendClientMessage(playerid, 0xFFFFFFFF, PortMsg);
					}
					else
					    SendClientMessage(playerid, 0xFF0000FF, "Jogador 2 não está online.");
				}
				else
				    SendClientMessage(playerid, 0xFF0000FF, "Jogador 1 não está online.");
			}
		}
		else
		    return 0;
	}
	else
	    return 0;
	return 1;
}

// Ports the player to the given vehicle
COMMAND:ircarro(playerid, params[])
{
	// Setup local variables
	new Car, Float:x, Float:y, Float:z, PortMsg[128];

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/ircarro", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 1
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			// Check if the player has a wanted level of less than 3
			if (GetPlayerWantedLevel(playerid) < 3)
			{
				// Check if the player is not jailed
				if (APlayerData[playerid][PlayerJailed] == 0)
				{
					if (sscanf(params, "i", Car)) SendClientMessage(playerid, 0xFF0000AA, "Use: /ircarro [id]");
					else
					{
						GetVehiclePos(Car, x, y, z);
						SetPlayerPos(playerid, x, y, z + 3.0);
						format(PortMsg, 128, "A localização do carro é: %4.2f, %4.2f, %4.2f", x, y, z + 3.0);
						SendClientMessage(playerid, 0x00FF00FF, PortMsg);
					}
				}
				else
				    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000} Você não pode usar o comando /ircarro quando preso.");
			}
			else
			    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000} Você não pode usar o comando /ircarro quando procurado.");
		}
		else
		    return 0;
	}
	else
	    return 0;
	return 1;
}
COMMAND:daradmin(playerid, params[])
{
	new OtherPlayer, Level, Msg[128], Name[24], AdminName[24], OldLevel;
	SendAdminText(playerid, "/daradmin", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 6)
		{
			if (sscanf(params, "ui", OtherPlayer, Level)) SendClientMessage(playerid, 0xFF0000AA, "Use: /daradmin [id] [nivel]");
			else
			{
				if (IsPlayerConnected(OtherPlayer))
				{
				    OldLevel = APlayerData[OtherPlayer][PlayerLevel];
					GetPlayerName(playerid, AdminName, sizeof(AdminName));
					GetPlayerName(OtherPlayer, Name, sizeof(Name));
					APlayerData[OtherPlayer][PlayerLevel] = Level;
					if (OldLevel != Level)
					{
						if (OldLevel < Level)
							format(Msg, 128, "O jogador %s foi promovido a %s por %s", Name, AdminLevelName[Level], AdminName);
						if (OldLevel > Level)
							format(Msg, 128, "O jogador %s foi rebaixado a %s por %s", Name, AdminLevelName[Level], AdminName);
						SendClientMessageToAll(0x00FF00FF, Msg);
					}
					else
						SendClientMessage(playerid, 0xFF0000FF, "Nivel dos outros jogadores não foram alterados,");
				}
				else
				    SendClientMessage(playerid, 0xFF0000FF, "Esse jogador não está online.");
			}
		}
		else
		    return 0;
	}
	else
	    return 0;
	return 1;
}
COMMAND:jetpack(playerid, params[])
{
	SendAdminText(playerid, "/jetpack", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 5)
		{
			SetPlayerSpecialAction(playerid, 2);
		}
		else
		    return 0;
	}
	else
	    return 0;
	return 1;
}
COMMAND:motor(playerid, params[])
{
	new vehicleid, engine,lights,alarm,doors,bonnet,boot,objective;
	SendAdminText(playerid, "/motor", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			vehicleid = GetPlayerVehicleID(playerid);
			GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
			if (vehicleid != 0)
			{
				if (sscanf(params, "i", engine)) SendClientMessage(playerid, 0xFF0000AA, "Use: /motor [0-1]");
				else
				{
					SetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
				}
			}
			else
				SendClientMessage(playerid, 0x00FF00FF, "Você precisa estar dentro de um veículo para desligá-lo/ligá-lo.");
		}
		else
		    return 0;
	}
	else
	    return 0;
	return 1;
}
COMMAND:editarplaca(playerid, params[])
{
	new vehicleid, engine, lights, alarm, doors, bonnet, boot, objective, Plate[32], Float:x, Float:y, Float:z, Float:Angle, Msg[128];
	SendAdminText(playerid, "/editarplaca", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 3)
		{
			vehicleid = GetPlayerVehicleID(playerid);
			if (vehicleid != 0)
			{
				if (sscanf(params, "s[32]", Plate)) SendClientMessage(playerid, 0xFF0000AA, "Use: /editarplaca [conteúdo]");
				else
				{
    				GetVehiclePos(vehicleid, x, y, z);
				    GetVehicleZAngle(vehicleid, Angle);
					SetVehicleNumberPlate(vehicleid, Plate);
					RemovePlayerFromVehicle(playerid);
					SetVehicleToRespawn(vehicleid);
					PutPlayerInVehicle(playerid, vehicleid, 0);
					GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
					SetVehicleParamsEx(vehicleid, 1, 1, alarm, doors, bonnet, boot, objective);
                    SetVehiclePos(vehicleid, x, y, z);
                    SetVehicleZAngle(vehicleid, Angle);
                    format(Msg, 128,"Você mudou a sua placa para: {0000FF}%s{00FF00}.", Plate);
                    SendClientMessage(playerid, 0x00FF00AA, Msg);
				}
			}
			else
				SendClientMessage(playerid, 0xFF0000, "Você precisa estar em um veículo para alterar a placa.");
		}
		else if (Oficina3 || Oficina4 || Oficina5 || Oficina6)
		{
			vehicleid = GetPlayerVehicleID(playerid);
			if (vehicleid != 0)
			{
				if (sscanf(params, "s[32]", Plate)) SendClientMessage(playerid, 0xFF0000AA, "Use: /editarplaca [conteúdo]");
				else
				{
    				GetVehiclePos(vehicleid, x, y, z);
				    GetVehicleZAngle(vehicleid, Angle);
					SetVehicleNumberPlate(vehicleid, Plate);
					RemovePlayerFromVehicle(playerid);
					SetVehicleToRespawn(vehicleid);
					PutPlayerInVehicle(playerid, vehicleid, 0);
					GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective);
					SetVehicleParamsEx(vehicleid, 1, 1, alarm, doors, bonnet, boot, objective);
                    SetVehiclePos(vehicleid, x, y, z);
                    SetVehicleZAngle(vehicleid, Angle);
                    format(Msg, 128,"Você mudou a sua placa para: {0000FF}%s{00FF00}.", Plate);
                    SendClientMessage(playerid, 0x00FF00AA, Msg);
				}
			}
			else
				SendClientMessage(playerid, 0xFF0000, "Você precisa estar em um veículo para alterar a placa.");
		}
        else
        {
            SendClientMessage(playerid, 0xFF0000AA, "Você não está em uma oficina.");
        }
	}
	else
	    return 0;
	return 1;
}
COMMAND:painel(playerid, params[])
{
	SendAdminText(playerid, "/painel", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 0)
		{
			ShowPlayerDialog(playerid, DialogCarOption, DIALOG_STYLE_LIST, "Selecione a opção:", "Motor\nFaróis\nAlarme\nPortas\nCapo\nPorta Malas\nObjetivo", "OK", "Cancelar");
		}
		else
		    return 0;
	}
	else
	    return 0;
	return 1;
}
COMMAND:clima(playerid, params[])
{
	SendAdminText(playerid, "/clima", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 3)
		{
			ShowPlayerDialog(playerid, DialogWeather, DIALOG_STYLE_LIST, "Selecione o tipo de água:", "Normal\nTempestade\nFoggy\nEscaldante\nDull, nublado, chuvoso\nSandstorm\nVerde Fog\nEscuro, nublado, marrom\nExtremamente brilhante\nTrevas tóxicos céu nuvens\nPreto e branco", "Selecionar", "Cancelar");
		}
		else
		    return 0;
	}
	else
	    return 0;
	return 1;
}
COMMAND:noite(playerid, params[])
{
    if (APlayerData[playerid][PlayerLevel] >= 6)
	{
        SetWorldTime(24);     
    }
    return 1;    
}
COMMAND:dia(playerid, params[])
{
    if (APlayerData[playerid][PlayerLevel] >= 6)
	{
        SetWorldTime(12);     
    }
    return 1;    
}
COMMAND:admins(playerid, params[])
{
	// Setup local variables
	new AdminList[500], Name[24];

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/admins", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Scan through all players
		for (new i; i < MAX_PLAYERS; i++)
		{
			// Check if this player is connected
			if (IsPlayerConnected(i))
			{
				// Get the name of the player
				GetPlayerName(i, Name, sizeof(Name));

				// Check if this player is an RCON admin
				if (IsPlayerAdmin(i))
				{
					// Add all admin players to the list
					format(AdminList, 500, "%s%s: %s (id: %i), Level de admin: %i (RCON admin)\n", AdminList, AdminLevelName[APlayerData[i][PlayerLevel]], Name, i, APlayerData[i][PlayerLevel]); // Add the name of the admin-player to the list
					// Re-start the for loop (skipping the remaining code for this iteration)
					continue;
				}

				//Check if that player is an admin (using the PlayerLevel)
				if (APlayerData[i][PlayerLevel] > 0)
				{
					// Add all admin players to the list
					format(AdminList, 500, "%s%s: %s (id: %i), Level de admin: %i\n", AdminList, AdminLevelName[APlayerData[i][PlayerLevel]], Name, i, APlayerData[i][PlayerLevel]); // Add the name of the admin-player to the list
				}
			}
		}

		// Check if there were admin-names added to the list
		if (strlen(AdminList) > 0)
		    ShowPlayerDialog(playerid, DialogNoResponse, DIALOG_STYLE_LIST, "Admins Online:", AdminList, "OK", "Cancelar");
		else
			SendClientMessage(playerid, 0xFF0000FF, "Não tem admins online!"); // No admins are online
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// This command lists all commands for normal players (admin-level 0)
COMMAND:comandos(playerid, params[])
{
	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/comandos", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		CommandList_Create(playerid); // Create a list of commands (only the first 4 commands) and show the dialog
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

COMMAND:comboio(playerid, params[])
{
	// Setup local variables
	new ConvoyList[750], Name[24], NumMembers, ConvoyStatus[10];

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/comboio", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Create the list of convoys with all their data
		for (new i; i < MAX_CONVOYS; i++)
		{
		    // Check if this is an empty convoy (not created yet by a player)
			if (AConvoys[i][Status] == CONVOY_EMPTY)
			{
				// Setup data for an empty convoy (one which hasn't been chosen yet)
				NumMembers = 0;
				format(Name, 24, "nenhum");
				format(ConvoyStatus, 10, "vazio");
			}
			else
			{
				// Get the name of the convoy-leader
				GetPlayerName(AConvoys[i][Members][0], Name, sizeof(Name));
				// Calculate the members in the convoy
				NumMembers = Convoy_CountMembers(i);
				// Set the status of the convoy
				switch (AConvoys[i][Status])
				{
					case CONVOY_OPEN: format(ConvoyStatus, 10, "Aberto");
					case CONVOY_FULL: format(ConvoyStatus, 10, "Cheio");
					case CONVOY_CLOSED: format(ConvoyStatus, 10, "Fechado");
				}
			}

			// Put all data together to form the content of the entire dialog
			format(ConvoyList, sizeof(ConvoyList), "%sLíder: {00FF00}%s{FFFFFF}, membros: {FF0000}%i{FFFFFF}, Status: {00FF00}%s{FFFFFF}\n", ConvoyList, Name, NumMembers, ConvoyStatus);
		}

		// Show the dialog
		ShowPlayerDialog(playerid, DialogSelectConvoy, DIALOG_STYLE_LIST, "Selecione o comboio:", ConvoyList, "Selecionar", "Cancelar");
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// Allows the leader to kick a member from the convoy
COMMAND:comboiokick(playerid, params[])
{
	// Setup local variables
	new Convoy, LeaderID, OtherPlayer, LeaderName[24], MemberName[24], Msg[128];

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/comboiokick", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		Convoy = APlayerData[playerid][ConvoyID]; // Get the convoy of the player
		LeaderID = AConvoys[Convoy][Members][0]; // Get the leader of his convoy

		// Check if this player is part of a convoy
		if (APlayerData[playerid][InConvoy] == true)
		{
			// Check if this player is the leader of the convoy
			if (LeaderID == playerid)
			{
				if (sscanf(params, "u", OtherPlayer)) SendClientMessage(playerid, 0xFF0000AA, "Use: /comboiokick [id]");
				else
				{
					// Check if that other player is part of the convoy
					if ((APlayerData[OtherPlayer][InConvoy] == true) && (APlayerData[OtherPlayer][ConvoyID] == Convoy))
					{
					    // Kick the other player from the convoy
						Convoy_Leave(OtherPlayer);
						// Get the names of the leader and member
						GetPlayerName(playerid, LeaderName, sizeof(LeaderName));
						GetPlayerName(OtherPlayer, MemberName, sizeof(MemberName));
						// Inform the leader that he has kicked the other player
						format(Msg, 128, "Você kickou {0000FF}%s{00FF00} do comboio.", MemberName);
						SendClientMessage(playerid, 0x00FF00FF, Msg);
						// Inform the leader that he has kicked the other player
						format(Msg, 128, "O líder {0000FF}%s{00FF00} te kickou do comboio.", LeaderName);
						SendClientMessage(OtherPlayer, 0x00FF00FF, Msg);
					}
					else
					    SendClientMessage(playerid, 0xFF0000FF, "Você não pode kickar um jogador que não faz parte do seu comboio.");
				}
			}
			else
			    SendClientMessage(playerid, 0xFF0000FF, "Você precisa ser líder para kickar um membro de um comboio.");
		}
		else
		    SendClientMessage(playerid, 0xFF0000FF, "Você precisa ser líder para kickar um membro de um comboio.");
	}
	else
		return 0;

	// Let the server know that this was a valid command
	return 1;
}

// Allows a convoy-member to leave the convoy
COMMAND:comboiosair(playerid, params[])
{
	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/comboiosair", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if this player is part of a convoy
		if (APlayerData[playerid][InConvoy] == true)
		{
		    // Kick the other player from the convoy
			Convoy_Leave(playerid);
			// Inform the player that he left the convoy
			SendClientMessage(playerid, 0x00FF00FF, "Você saiu do comboio.");
		}
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// Allows the leader to cancel a convoy
COMMAND:comboiocancelar(playerid, params[])
{
	// Setup local variables
	new Convoy, LeaderID;

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/comboiocancelar", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		Convoy = APlayerData[playerid][ConvoyID]; // Get the convoy of the player
		LeaderID = AConvoys[Convoy][Members][0]; // Get the leader of his convoy

		// Check if this player is part of a convoy
		if (APlayerData[playerid][InConvoy] == true)
		{
			// Check if this player is the leader of the convoy
			if (LeaderID == playerid)
				Convoy_Cancel(Convoy); // Cancel the convoy, kicking every other member from it
			else
			    SendClientMessage(playerid, 0xFF0000FF, "Você precisa ser líder do comboio para cancelá-lo.");
		}
		else
		    SendClientMessage(playerid, 0xFF0000FF, "Você precisa ser líder do comboio para cancelá-lo.");
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// Displays all members in the convoy
COMMAND:comboiomembros(playerid, params[])
{
	// Setup local variables
	new Name[24], MemberList[1000], Convoy;

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/comboiomembros", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the member is in a convoy
		if (APlayerData[playerid][InConvoy] == true)
		{
			// Get the convoyID of the member
			Convoy = APlayerData[playerid][ConvoyID];

			// Loop through all members
			for (new i; i < CONVOY_MAX_MEMBERS; i++)
			{
			    if (AConvoys[Convoy][Members][i] != -1) // Check if this member-spot is occupied
				{
					// Get the name of the member
					GetPlayerName(AConvoys[Convoy][Members][i], Name, sizeof(Name));
					// Add the membernames to the list
					format(MemberList, 1000, "%s%s\n", MemberList, Name);
				}
			}

			// Show the dialog
			ShowPlayerDialog(playerid, DialogConvoyMembers, DIALOG_STYLE_LIST, "Membros do comboio", MemberList, "OK", "Cancelar");
		}
		else
		    SendClientMessage(playerid, 0xFF0000FF, "Você não é um mmembro de um comboio.");
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// Displays the statictics of the player
COMMAND:status(playerid, params[])
{
	// Setup local variables
	new StatsMsg[1000], Name[24], TitleMsg[128];

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/status", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Construct the stats
		format(StatsMsg, 1000, "KM rodados: {00FF00}%f{FFFFFF}\n", (APlayerData[playerid][StatsMetersDriven] / 1000));
		format(StatsMsg, 1000, "%sTrabalhos de Caminhoneiro concluídos: {00FF00}%i{FFFFFF}\n", StatsMsg, APlayerData[playerid][StatsTruckerJobs]);
		format(StatsMsg, 1000, "%sTrabalhos em Comboio concluídos: {00FF00}%i{FFFFFF}\n", StatsMsg, APlayerData[playerid][StatsConvoyJobs]);
		format(StatsMsg, 1000, "%sRotas de Ônibus concluídas: {00FF00}%i{FFFFFF}\n", StatsMsg, APlayerData[playerid][StatsBusDriverJobs]);
		format(StatsMsg, 1000, "%sTrabalhos de Voo concluídos: {00FF00}%i{FFFFFF}\n", StatsMsg, APlayerData[playerid][StatsPilotJobs]);
		format(StatsMsg, 1000, "%sTrabalhos nos Correios concluídos: {00FF00}%i{FFFFFF}\n", StatsMsg, APlayerData[playerid][StatsCourierJobs]);
		format(StatsMsg, 1000, "%sTrabalhos no DNIT concluídos: {00FF00}%i{FFFFFF}\n", StatsMsg, APlayerData[playerid][StatsRoadworkerJobs]);
		format(StatsMsg, 1000, "%sTrabalhos de Mecânico concluídos: {00FF00}%i{FFFFFF}\n", StatsMsg, APlayerData[playerid][StatsAssistance]);
		format(StatsMsg, 1000, "%sTrabalhos na Máfia concluídos: {00FF00}%i{FFFFFF}\n", StatsMsg, APlayerData[playerid][StatsMafiaJobs]);
		format(StatsMsg, 1000, "%sCargas-Máfia roubadas e entregadas: {00FF00}%i{FFFFFF}\n", StatsMsg, APlayerData[playerid][StatsMafiaStolen]);
		format(StatsMsg, 1000, "%sJogadores multados: {00FF00}%i{FFFFFF}\n", StatsMsg, APlayerData[playerid][StatsPoliceFined]);
		format(StatsMsg, 1000, "%sJogadores presos: {00FF00}%i{FFFFFF}\n", StatsMsg, APlayerData[playerid][StatsPoliceJailed]);
		// Get the player's name
		GetPlayerName(playerid, Name, sizeof(Name));
		// Construct the title for the dialog
		format(TitleMsg, 128, "Estatisticas para %s:", Name);

		// Show the dialog
		ShowPlayerDialog(playerid, DialogStats, DIALOG_STYLE_LIST, TitleMsg, StatsMsg, "OK", "Cancelar");
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// Restarts the server
COMMAND:gmx(playerid, params[])
{
	SendAdminText(playerid, "/gmx", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 5)
		{
			GameTextForAll("Reiniciando servidor em 2 minutos!", 5000, 3);
			SendClientMessageToAll(0xA0A0A0, "GMX em 2 minutos!");
			SetTimer("Timer_Restart_WarnPlayers", 1000 * 60, false);
		}
		else
		    return 0;
	}
	else
	    return 0;
	return 1;
}
forward Timer_Restart_WarnPlayers();
public Timer_Restart_WarnPlayers()
{
	GameTextForAll("Reiniciando servidor em 1 minuto!", 5000, 3);
	SendClientMessageToAll(0xA0A0A0, "GMX em 1 minuto!");
	SetTimer("Timer_Restart_Kick", 1000 * 60, false);
	SendRconCommand("Reiniciando");
	SendRconCommand("password loafkagakggoagka");

	return 1;
}

forward Timer_Restart_Kick();
public Timer_Restart_Kick()
{
	GameTextForAll("Servidor reiniciando: Todos os players kickados!", 5000, 3);
	for(new i; i < MAX_PLAYERS; i++)
		Kick(i);
	SetTimer("Timer_Restart_Reboot", 1000 * 5, false);

	return 1;
}

forward Timer_Restart_Reboot();
public Timer_Restart_Reboot()
{
	new HostCommand[128];
	SendRconCommand("gmx");
	format(HostCommand, 128, "hostname %s", GameModeName);
	SendRconCommand(HostCommand);
	SendRconCommand("password 0");
	return 1;
}
COMMAND:gmxagora(playerid, params[])
{
    if (APlayerData[playerid][PlayerLevel] >= 5)
	{
	SendRconCommand("gmx");
    }
	return 1;
}
COMMAND:criarradar(playerid, params[])
{
	new Float:x, Float:y, Float:z, Float:Angle, MaxSpeed, file[100], File:PFile, LineForFile[100], Msg[128];
	SendAdminText(playerid, "/criarradar", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 6)
		{
			if (sscanf(params, "i", MaxSpeed)) SendClientMessage(playerid, 0xFF0000AA, "Use: /criarradar [Vel.Max]");
			else
			{
				GetPlayerPos(playerid, x, y, z);
				GetPlayerFacingAngle(playerid, Angle);
				z = z - 1.0;
				SetPlayerPos(playerid, x, y + 1.0, z + 1.0);
				for (new CamID; CamID < MAX_CAMERAS; CamID++)
				{
					if (ACameras[CamID][CamSpeed] == 0)
					{
                        SetupSpeedCamera(CamID, x, y, z, Angle, MaxSpeed);
						format(file, sizeof(file), CameraFile, CamID); 
        				PFile = fopen(file, io_write); 
						format(LineForFile, 100, "CamX %f\r\n", x);
						fwrite(PFile, LineForFile); 
						format(LineForFile, 100, "CamY %f\r\n", y);
						fwrite(PFile, LineForFile); 
						format(LineForFile, 100, "CamZ %f\r\n", z);
						fwrite(PFile, LineForFile); 
						format(LineForFile, 100, "CamAngle %f\r\n", Angle);
						fwrite(PFile, LineForFile); 
						format(LineForFile, 100, "CamSpeed %i\r\n", MaxSpeed);
						fwrite(PFile, LineForFile); 
        				fclose(PFile); 
						format(Msg, 128, "Você criou o radar ID: %i", CamID);
						SendClientMessage(playerid, 0x00FF00FF, Msg);
						return 1;
					}
				}

				// In case all camera-slots are occupied (100 camera's have been created already), let the player know about it
				format(Msg, 128, "{FF0000} Você não pode criar mais de %i radares.", MAX_CAMERAS);
				SendClientMessage(playerid, 0xFFFFFFFF, Msg);
			}
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// This command allows you to delete a speedcamera
COMMAND:deletarradar(playerid, params[])
{
	// Setup local variables
	new file[100], Msg[128];

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/deletarradar", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 5
		if (APlayerData[playerid][PlayerLevel] >= 6)
		{
				// Loop through all camera's
			for (new CamID; CamID < MAX_CAMERAS; CamID++)
			{
				// Check if this index is used
				if (ACameras[CamID][CamSpeed] != 0)
				{
					// Check if the player is in range of the camera
					if (IsPlayerInRangeOfPoint(playerid, 5.0, ACameras[CamID][CamX], ACameras[CamID][CamY], ACameras[CamID][CamZ]))
					{
					    // Delete the file
						format(file, sizeof(file), CameraFile, CamID); // Construct the complete filename for this camera-file
						if (fexist(file)) // Make sure the file exists
							fremove(file); // Delete the file

						// Delete both camera objects
					    DestroyObject(ACameras[CamID][CamObj1]);
					    DestroyObject(ACameras[CamID][CamObj2]);
                        DestroyDynamicMapIcon(ACameras[CamID][CamIcon]);
						// Also clear the data from memory
					    ACameras[CamID][CamX] = 0.0;
					    ACameras[CamID][CamY] = 0.0;
					    ACameras[CamID][CamZ] = 0.0;
					    ACameras[CamID][CamAngle] = 0.0;
					    ACameras[CamID][CamSpeed] = 0;
                        ACameras[CamID][CamObj1] = 0;
                        ACameras[CamID][CamObj2] = 0;
                        ACameras[CamID][CamIcon] = 0;

						// Let the player know he deleted a camera
						format(Msg, 128, "Você deletou o radar %i", CamID);
						SendClientMessage(playerid, 0x00FF00FF, Msg);

						// Exit the function
						return 1;
					}
				}
			}

			// In case the player wasn't near a speedcamera, inform him about it
			SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000} Esteja em um radar para deletá-lo");
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}



// This command ports a player to the player who executed the command
COMMAND:trazer(playerid, params[])
{
	// Setup local variables
	new OtherPlayer, Float:x, Float:y, Float:z, PortMsg[128], IntID, WorldID, Name[24];

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/trazer", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 1
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			if (sscanf(params, "u", OtherPlayer)) SendClientMessage(playerid, 0xFF0000AA, "Use: /trazer [id]");
			else
			{
				// Check if that other player is online
				if (IsPlayerConnected(OtherPlayer))
				{
					// Get the name of the other player
					GetPlayerName(OtherPlayer, Name, sizeof(Name));
					// Get the location of the player
					GetPlayerPos(playerid, x, y, z);
					IntID = GetPlayerInterior(playerid);
					WorldID = GetPlayerVirtualWorld(playerid);
					// Port the other player to this player
					SetPlayerVirtualWorld(OtherPlayer, WorldID);
					SetPlayerInterior(OtherPlayer, IntID);
					SetPlayerPos(OtherPlayer, x, y, z + 3.0);
					// Let the player know about it
					format(PortMsg, 128, "{00FF00}Você trouxe {FFFF00}%s{00FF00} até você.", Name);
					SendClientMessage(playerid, 0xFFFFFFFF, PortMsg);
				}
				else
				    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}Esse jogador não está online.");
			}
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// This command deleted all vehicles that are spawned using /car, /plane, /bike, /trailer
COMMAND:limparcarros(playerid, params[])
{
	// Setup local variables
	new CarsDeleted, Msg[128];

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/limparcarros", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 3
		if (APlayerData[playerid][PlayerLevel] >= 3)
		{
		    // Loop through all vehicles
		    for (new vid; vid < 2000; vid++)
		    {
				// Check if this vehicle exists (check the model), otherwise all empty slots are processed as well
				if (AVehicleData[vid][Model] != 0)
				{
					// Check if the vehicle is NOT a static vehicle
					if (AVehicleData[vid][StaticVehicle] == false)
					{
						// Check if the vehicle is NOT owned by anybody (this leaves all vehicles spawned with /car, /trailer, /plane)
						if (AVehicleData[vid][Owned] == false)
						{
							// Count the cars that have been deleted
							CarsDeleted++;
							// Delete the vehicle and clear the data
							DestroyVehicle(vid);
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
		    }

			// Let the player know how many vehicles have been cleaned up
			format(Msg, 128, "{00FF00}Total de carros limpos da cidade: {FFFF00}%i", CarsDeleted);
			SendClientMessage(playerid, 0xFFFFFFFF, Msg);
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// This command allows the player to call for assistance
COMMAND:assistencia(playerid, params[])
{
	// Setup local variables
	new bool:AssistOnline = false, Msg[128], Name[24];

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/assistencia", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Get the player's name
		GetPlayerName(playerid, Name, sizeof(Name));
		// Preset the message that needs to be sent to assistance players
		format(Msg, 128, "{00FF00}O jogador {FFFF00}%s{00FF00} precisa de assistência mecânica.", Name);

		// Check if there is at least one assistance player online
		for (new i; i < MAX_PLAYERS; i++)
		{
			// Check if this player is connected
			if (IsPlayerConnected(i))
			{
				// Check if this player is assistance class
				if (APlayerData[i][PlayerClass] == ClassAssistance)
				{
					// Set the flag to indicate that at least one assistance player is online
				    AssistOnline = true;
				    // Send the assistance player a message to inform him who needs assistance
				    SendClientMessage(i, 0xFFFFFFFF, Msg);
				}
			}
		}

		// Check if there is at least one assistance player online
		if (AssistOnline == true)
		{
			// Set yourself as "AssistanceNeeded"
			APlayerData[playerid][AssistanceNeeded] = true;
			// Let the player know he called for assistance
			SendClientMessage(playerid, 0xFFFFFFFF, "{00FF00}Você ja pediu ajuda.");
		}
		else // No assistance is online
		{
			// Check if the player is the driver of a vehicle
			if (GetPlayerVehicleSeat(playerid) == 0)
			{
				// Fully repair the vehicle (damage value and bodywork)
				RepairVehicle(GetPlayerVehicleID(playerid));
				// Also re-fuel the vehicle
				AVehicleData[GetPlayerVehicleID(playerid)][Fuel] = MaxFuel;
				// Let the player pay for the repairs and refuel (default $2000)
				RewardPlayer(playerid, -2000, 0);
				// Let the player know he spent $2000 for auto-repair because there were no assistance players online
			    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}Seu veículo foi reparado e abastecido por R$2000.");
			    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}Não hà mecânico online.");
			}
		}
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// This command adds nitro to the player's vehicle
COMMAND:nos(playerid, params[])
{
	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/nos", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 1
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			// Check if the player is the driver of a vehicle
			if (GetPlayerVehicleSeat(playerid) == 0)
			{
				// Check if the vehicle isn't owned (owned vehicle's need to buy nitro at mod garages)
				if (AVehicleData[GetPlayerVehicleID(playerid)][Owned] == false)
					AddVehicleComponent(GetPlayerVehicleID(playerid), 1010); // Add nitro to the player's vehicle
			}
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// This command let's an admin spectate another player
COMMAND:espiar(playerid, params[])
{
	// Setup local variables
	new OtherPlayer, Name[24], Msg[128];

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/espiar", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 1
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			if (sscanf(params, "u", OtherPlayer)) SendClientMessage(playerid, 0xFF0000AA, "Use: /espiar [id]");
			else
			{
				// Check if that other player is online
				if (IsPlayerConnected(OtherPlayer))
				{
					// Get the player's name
					GetPlayerName(OtherPlayer, Name, sizeof(Name));

				    // Turn spectating on
				    TogglePlayerSpectating(playerid, 1);

					// Check if the other player is driving a vehicle
					if (GetPlayerVehicleSeat(OtherPlayer) == -1)
					{
						// The other player is on foot, so spectate him
						PlayerSpectatePlayer(playerid, OtherPlayer);
						SetPlayerInterior(playerid, GetPlayerInterior(OtherPlayer));
						APlayerData[playerid][SpectateID] = OtherPlayer;
						APlayerData[playerid][SpectateType] = ADMIN_SPEC_TYPE_PLAYER;
					}
					else
					{
						// The other player is in a vehicle, so spectate the vehicle
						PlayerSpectateVehicle(playerid, GetPlayerVehicleID(OtherPlayer));
						APlayerData[playerid][SpectateID] = OtherPlayer;
						APlayerData[playerid][SpectateVehicle] = GetPlayerVehicleID(OtherPlayer);
						APlayerData[playerid][SpectateType] = ADMIN_SPEC_TYPE_VEHICLE;
					}

					format(Msg, 128, "{00FF00}Você está espiando {FFFF00}%s.", Name);
					SendClientMessage(playerid, 0xFFFFFFFF, Msg);
				}
				else
				    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}Esse jogador não está online.");
			}
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// This command ends the spectate mode
COMMAND:pararespiar(playerid, params[])
{
	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/pararespiar", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 1
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			// Check if the player is spectating
			if (GetPlayerState(playerid) == PLAYER_STATE_SPECTATING)
			{
			    TogglePlayerSpectating(playerid, 0);
				APlayerData[playerid][SpectateID] = -1;
				APlayerData[playerid][SpectateVehicle] = -1;
				APlayerData[playerid][SpectateType] = ADMIN_SPEC_TYPE_NONE;
			}
			else
			    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}Você não está espiando.");
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}



// Lets the player add new businesses
COMMAND:criarempresa(playerid, params[])
{
	// Setup local variables
	new BusinessList[2000];

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/criarempresa", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 5
		if (APlayerData[playerid][PlayerLevel] >= 5)
		{
			// Check if the player isn't inside a vehicle
			if (GetPlayerVehicleSeat(playerid) == -1)
			{
				// Construct the list of businesses
				for (new BusType = 1; BusType < sizeof(ABusinessInteriors); BusType++)
				{
				    format(BusinessList, sizeof(BusinessList), "%s%s\n", BusinessList, ABusinessInteriors[BusType][InteriorName]);
				}

				// Let the player choose a business-type via a dialog
				ShowPlayerDialog(playerid, DialogCreateBusSelType, DIALOG_STYLE_LIST, "Escolha o tipo de empresa:", BusinessList, "Selecionar", "Cancelar");
			}
			else
			    SendClientMessage(playerid, 0xFF0000FF, "Você não pode criar uma empresa e dentro de um veículo.");
		}
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// This command lets the player delete a business
COMMAND:deletarempresa(playerid, params[])
{
	// Setup local variables
	new file[100], Msg[128];

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/deletarempresa", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 5
		if (APlayerData[playerid][PlayerLevel] >= 5)
		{
			// Make sure the player isn't inside a vehicle
			if (GetPlayerVehicleID(playerid) == 0)
			{
				// Loop through all player-owned businesses
				for (new BusID = 1; BusID < MAX_BUSINESS; BusID++)
				{
					// Check if the business exists
					if (ABusinessData[BusID][PickupID] != 0)
					{
						// Check if the business has no owner
						if (ABusinessData[BusID][Owned] == false)
						{
							// Check if the player is in range of the business-pickup
							if (IsPlayerInRangeOfPoint(playerid, 2.5, ABusinessData[BusID][BusinessX], ABusinessData[BusID][BusinessY], ABusinessData[BusID][BusinessZ]))
							{
								// Clear all data of the business
	                            ABusinessData[BusID][BusinessName] = 0;
	                            ABusinessData[BusID][BusinessX] = 0.0;
	                            ABusinessData[BusID][BusinessY] = 0.0;
	                            ABusinessData[BusID][BusinessZ] = 0.0;
	                            ABusinessData[BusID][BusinessType] = 0;
	                            ABusinessData[BusID][BusinessLevel] = 0;
	                            ABusinessData[BusID][LastTransaction] = 0;
	                            ABusinessData[BusID][Owned] = false;
	                            ABusinessData[BusID][Owner] = 0;
								// Destroy the mapicon, 3DText and pickup for the house
								DestroyDynamicPickup(ABusinessData[BusID][PickupID]);
								DestroyDynamicMapIcon(ABusinessData[BusID][MapIconID]);
								DestroyDynamic3DTextLabel(ABusinessData[BusID][DoorText]);
	                            ABusinessData[BusID][PickupID] = 0;
	                            ABusinessData[BusID][MapIconID] = 0;

								// Delete the business-file
								format(file, sizeof(file), BusinessFile, BusID); // Construct the complete filename for this business-file
								if (fexist(file)) // Make sure the file exists
									fremove(file); // Delete the file

								// Also let the player know he deleted the business
								format(Msg, 128, "{00FF00}Você deletou a empresa ID: {FFFF00}%i", BusID);
								SendClientMessage(playerid, 0xFFFFFFFF, Msg);

								// Exit the function
								return 1;
							}
						}
					}
				}

				// There was no house in range, so let the player know about it
				SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}Esteja na porta da empresa que deseja deletar.");
			}
			else
			    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}Você não pode deletar uma empresa de dentro de um veículo.");
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}
COMMAND:comprarempresa(playerid, params[])
{
	new Msg[128], BusType;
	SendAdminText(playerid, "/comprarempresa", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (GetPlayerVehicleID(playerid) == 0)
		{
			for (new i = 1; i < sizeof(ABusinessData); i++)
			{
				if (ABusinessData[i][PickupID] != 0)
				{
					if (IsPlayerInRangeOfPoint(playerid, 2.5, ABusinessData[i][BusinessX], ABusinessData[i][BusinessY], ABusinessData[i][BusinessZ]))
					{
					    if (ABusinessData[i][Owned] == false)
					    {
							BusType = ABusinessData[i][BusinessType];
					        if (APlayerData[playerid][PlayerMoney] >= ABusinessInteriors[BusType][BusPrice])
					            Business_SetOwner(playerid, i);
					        else
					            SendClientMessage(playerid, 0xFF0000FF, "Você não pode pagar pela empresa.");
					    }
					    else
					    {
							format(Msg, 128, "{FF0000}Este negócio ja pertence à {00FF00}%s{FFFFFF}.", ABusinessData[i][Owner]);
							SendClientMessage(playerid, 0xFFFFFFFF, Msg);
					    }
					    return 1;
					}
				}
				else
				    return 1;
			}
			SendClientMessage(playerid, 0xFF0000FF, "Para comprar uma empresa você precisa estar no pickup da mesma.");
		}
		else
		    SendClientMessage(playerid, 0xFF0000FF, "Você não pode comprar uma empresa de dentro de um veículo.");
	}
	else
	    return 0;
	return 1;
}

// This command opens a menu when you're inside your business to allow to access the options of your business
COMMAND:menuempresa(playerid, params[])
{
	// Setup local variables
	new OptionsList[200], DialogTitle[200];

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/menuempresa", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player is inside a business
		if (APlayerData[playerid][CurrentBusiness] != 0)
		{
			format(DialogTitle, sizeof(DialogTitle), "Selecione a opção para: %s", ABusinessData[APlayerData[playerid][CurrentBusiness]][BusinessName]);

			format(OptionsList, sizeof(OptionsList), "%sMudar nome da empresa\n", OptionsList);
			format(OptionsList, sizeof(OptionsList), "%sAtualizar empresa\n", OptionsList);
			format(OptionsList, sizeof(OptionsList), "%sRetirar ganhos da empresa\n", OptionsList);
			format(OptionsList, sizeof(OptionsList), "%sVender empresa\n", OptionsList);
			format(OptionsList, sizeof(OptionsList), "%sSair da empresa\n", OptionsList);
			// Show the businessmenu
			ShowPlayerDialog(playerid, DialogBusinessMenu, DIALOG_STYLE_LIST, DialogTitle, OptionsList, "Selecionar", "Cancelar");
		}
		else
		    SendClientMessage(playerid, 0xFF0000FF, "Você não está na empresa.");
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// This command teleports you to your selected business
COMMAND:irempresa(playerid, params[])
{
	// Setup local variables
	new BusinessList[1000], BusID, BusType, Earnings;

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/irempresa", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player is not jailed
		if (APlayerData[playerid][PlayerJailed] == 0)
		{
			// Check if the player has a wanted level of less than 3
			if (GetPlayerWantedLevel(playerid) < 3)
			{
				// Check if the player is not inside a vehicle
				if (GetPlayerVehicleID(playerid) == 0)
				{
					// Ask to which business the player wants to port
					for (new i; i < MAX_BUSINESSPERPLAYER; i++)
					{
						// Get the business-id
					    BusID = APlayerData[playerid][Business][i];

						// Check if this businessindex is occupied
						if (BusID != 0)
						{
							// Get the business-type
							BusType = ABusinessData[BusID][BusinessType];
							Earnings = (BusinessTransactionTime - ABusinessData[BusID][LastTransaction]) * ABusinessInteriors[BusType][BusEarnings] * ABusinessData[BusID][BusinessLevel];
							format(BusinessList, 1000, "%s{00FF00}%s{FFFFFF} (ganhos: $%i)\n", BusinessList, ABusinessData[BusID][BusinessName], Earnings);
						}
						else
							format(BusinessList, 1000, "%s{FFFFFF}%s{FFFFFF}\n", BusinessList, "Slot vazio");
					}
					ShowPlayerDialog(playerid, DialogGoBusiness, DIALOG_STYLE_LIST, "Escolha a empresa para ir:", BusinessList, "Selecionar", "Cancelar");
				}
				else
					SendClientMessage(playerid, 0xFF0000FF, "Você precisa estar a pé na porta da empresa.");
			}
			else
			    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}Você não pode usar o comando /irempresa quando procurado");
		}
		else
		    SendClientMessage(playerid, 0xFF0000FF, "Você não pode usar o comando /irempresa quando preso.");
	}
	else
	    return 0;
	return 1;
}
COMMAND:calar(playerid, params[])
{
	new Msg[128], Name[24], AdminName[24], Reason[128], OtherPlayer;
	SendAdminText(playerid, "/calar", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			if (sscanf(params, "us[128]", OtherPlayer, Reason)) SendClientMessage(playerid, 0xFF0000AA, "Use: /calar [id] [motivo]");
			else
			{
				if (IsPlayerConnected(OtherPlayer))
				{
					GetPlayerName(playerid, AdminName, sizeof(AdminName));
					GetPlayerName(OtherPlayer, Name, sizeof(Name));
					APlayerData[OtherPlayer][Muted] = true;
					format(Msg, 128, "{FF0000}-| %s  foi calado por %s. Motivo: %s |-", Name, AdminName, Reason);
					SendClientMessageToAll(0xFFFFFFFF, Msg);
				    PlayerFile_Save(OtherPlayer);
				}
				else
				    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}O jogador não está online.");
			}
		}
		else
		    return 0;
	}
	else
	    return 0;
	return 1;
}                                                
COMMAND:descalar(playerid, params[])
{
	new Msg[128], Name[24], AdminName[24], OtherPlayer;
	SendAdminText(playerid, "/descalar", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			if (sscanf(params, "u", OtherPlayer)) SendClientMessage(playerid, 0xFF0000AA, "Use: /descalar [id]");
			else
			{
				if (IsPlayerConnected(OtherPlayer))
				{
					GetPlayerName(playerid, AdminName, sizeof(AdminName));
					GetPlayerName(OtherPlayer, Name, sizeof(Name));
					APlayerData[OtherPlayer][Muted] = false;
					format(Msg, 128, "{FF0000}-| O administrador %s permitiu que %s volte a falar |-", AdminName, Name);
					SendClientMessageToAll(0xFFFFFFFF, Msg);
					PlayerFile_Save(OtherPlayer);
				}
				else
				    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}O jogador não está online.");
			}
		}
		else
		    return 0;
	}
	else
	    return 0;
	return 1;
}
COMMAND:mudos(playerid, params[])
{
	new PlayerList[1000], Name[24];
	SendAdminText(playerid, "/mudos", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			for (new i; i < MAX_PLAYERS; i++)
			{
				if (IsPlayerConnected(i))
				{
				    if (APlayerData[i][Muted] == true)
					{
						// Get the player's name
						GetPlayerName(i, Name, sizeof(Name));
						// Add his name and ID to the list
						format(PlayerList, sizeof(PlayerList), "%s%s (ID: %i)\n", PlayerList, Name, i);
					}
				}
			}

			// Show the list of muted players to the admin
			if (strlen(PlayerList) != 0)
				ShowPlayerDialog(playerid, DialogNoResponse, DIALOG_STYLE_LIST, "Jogadores calados:", PlayerList, "OK", "Cancelar");
			else
			    SendClientMessage(playerid, 0xFFFFFFFF, "{00FF00}Não ha jogadores calados.");
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}

// Freeze a player (he cannot move anymore)
COMMAND:congelar(playerid, params[])
{
	// Setup local variables
	new Msg[128], Name[24], AdminName[24], Reason[128], OtherPlayer, Duration;

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/congelar", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 1
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			if (sscanf(params, "uis[128]", OtherPlayer, Duration, Reason)) SendClientMessage(playerid, 0xFF0000AA, "Use: /congelar [id] [tempo] [motivo]");
			else
			{
				// Check if the otherplayer is online
				if (IsPlayerConnected(OtherPlayer))
				{
					// Get the player-names
					GetPlayerName(playerid, AdminName, sizeof(AdminName));
					GetPlayerName(OtherPlayer, Name, sizeof(Name));
					// Store the duration for the freeze, freeze him and start the frozentimer
					APlayerData[OtherPlayer][PlayerFrozen] = Duration;
					TogglePlayerControllable(OtherPlayer, 0);
					SetTimerEx("Player_FreezeTimer", 1000, true, "i", OtherPlayer);
					// Let the other player know that he has been muted
					format(Msg, 128, "{FF0000}Você foi congelado por {FFFF00}%s {FF0000}. Motivo: {FFFF00}%s.", AdminName, Reason);
					SendClientMessage(OtherPlayer, 0xFFFFFFFF, Msg);
					// Let the admin know who he has muted
					format(Msg, 128, "{00FF00}Você congelou {FFFF00}%s.", Name);
					SendClientMessage(playerid, 0xFFFFFFFF, Msg);
					// Save the player-stats
					PlayerFile_Save(OtherPlayer);
				}
				else
				    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}Esse jogador não está online.");
			}
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}
COMMAND:pagar(playerid, params[])
{
	new Msg[128], Name[24], OtherName[24], OtherPlayer, Money;

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/dardinheiro", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (sscanf(params, "ui", OtherPlayer, Money)) SendClientMessage(playerid, 0xFF0000AA, "Use: /dardinheiro [id] [quantia]");
		else
		{
			// Check if the otherplayer is online
			if (IsPlayerConnected(OtherPlayer))
			{
				// Get the player-names
				GetPlayerName(playerid, Name, sizeof(Name));
				GetPlayerName(OtherPlayer, OtherName, sizeof(OtherName));

				// Check if the money has a positive value (to prevent stealing money using negative values)
				if (Money > 0)
				{
					// Check if the player has enough money
					if (APlayerData[playerid][PlayerMoney] >= Money)
					{
						// Transfer the money
						RewardPlayer(playerid, -Money, 0);
						RewardPlayer(OtherPlayer, Money, 0);
						// Let the other player know that he has received money
						format(Msg, 128, "{00FF00}Você recebeu {FFFF00}R$%i{00FF00} de {FFFF00}%s.", Money, Name);
						SendClientMessage(OtherPlayer, 0xFFFFFFFF, Msg);
						// Let the player know he gave money to somebody else
						format(Msg, 128, "{00FF00}Você deu {FFFF00}R$%i{00FF00} para {FFFF00}%s.", Money, OtherName);
						SendClientMessage(playerid, 0xFFFFFFFF, Msg);
						// Save the player-stats
						PlayerFile_Save(playerid);
						PlayerFile_Save(OtherPlayer);
					}
					else
					    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}Você não tem dinheiro suficiente.");
				}
				else
				    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}Você deve usar valores maiores que 0.");
			}
			else
			    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}Esse jogador não está online.");
		}
	}
	else
	    return 0;
	return 1;
}
COMMAND:resetarcarros(playerid, params[])
{
	SendAdminText(playerid, "/resetarcarros", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 3)
		{
            SendClientMessageToAll(0x00FF00FF, "Todos os veículos foram resetados pelo admin");    
            for(new i=0; i<MAX_VEHICLES; i++)
			{
                if(!VehicleOccupied(i))
                {
			        SetVehicleToRespawn(i);
				}
			}
		}
		else
		    return 0;
	}
	else
	    return 0;
	return 1;
}
COMMAND:resetarcarro(playerid, params[])
{
	new vid, Msg[128];
	SendAdminText(playerid, "/resetarcarro", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			if (sscanf(params, "i", vid)) SendClientMessage(playerid, 0xFF0000AA, "Use: /resetarcarro [id]");
			else
			{
				if ((vid > 0) && (vid < 2000))
				{
					if (AVehicleData[vid][Model] != 0)
					{
						SetVehicleToRespawn(vid);
						format(Msg, 128, "{00FF00}Você respawnou o veiculo {FFFF00}%i", vid);
						SendClientMessage(playerid, 0xFFFFFFFF, Msg);
					}
				}
				else
				    SendClientMessage(playerid, 0xFFFFFFFF, "{FF0000}O ID do veiculo deve ser entre 1 e 1999.");
			}
		}
		else
		    return 0;
	}
	else
	    return 0;
	return 1;
}
COMMAND:tapete(playerid, params[])
{
	SendAdminText(playerid, "/tapete", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerClass] == ClassPolice || APlayerData[playerid][PlayerLevel] >= 3)
		{
			SpikeStrip_Create(playerid);
		}
		else
			return 0;
	}
	else
	    return 0;
	return 1;
}
COMMAND:ejetar(playerid, params[])
{
	new Name[24], AdminName[24], Msg[128], OtherPlayer;
	SendAdminText(playerid, "/ejetar", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 2)
		{
			if (sscanf(params, "u", OtherPlayer)) SendClientMessage(playerid, 0xFF0000AA, "Use: /ejetar [id]");
			else
			{
				if (APlayerData[OtherPlayer][LoggedIn] == true)
				{
					if (GetPlayerVehicleSeat(OtherPlayer) != -1)
					{
						GetPlayerName(playerid, AdminName, sizeof(AdminName));
						GetPlayerName(OtherPlayer, Name, sizeof(Name));
						RemovePlayerFromVehicle(OtherPlayer);
						format(Msg, 128, "{FF0000}Você foi ejetado do veículo de {FFFF00}%s{FF0000}.", AdminName);
						SendClientMessage(OtherPlayer, 0xFFFFFFFF, Msg);
						format(Msg, 128, "Você ejetou {FFFF00}%s{00FF00} do veículo.", Name);
						SendClientMessage(playerid, 0x00FF00, Msg);
					}
					else
					    SendClientMessage(playerid, 0xFF0000, "O jogador não está dentro de um veículo.");
				}
				else
				    SendClientMessage(playerid, 0xFF0000, "Esse jogador não está conectado.");
			}
		}
		else
			return 0;
	}
	else
	    return 0;
	return 1;
}
COMMAND:cv(playerid, params[])
{
	new Name[24], Msg[128], Message[128];
	SendAdminText(playerid, "/cv", params);
    if (APlayerData[playerid][PlayerLevel] >= 1)
	{
    	GetPlayerName(playerid, Name, sizeof(Name));
    	if (APlayerData[playerid][LoggedIn] == true)
	    {
    		if (sscanf(params, "s[128]", Message)) SendClientMessage(playerid, 0xFF0000AA, "Use: /cv [texto]");
    		else
    		{
    			for (new i; i < MAX_PLAYERS; i++)
    			{
    				if (APlayerData[i][LoggedIn] == true)
	    			{
			    	    if (APlayerData[i][PlayerClass] == APlayerData[playerid][PlayerClass])
				        {
						format(Msg, 128, "{FF00FF}|Anuncio Admin| %s: {FF00FF}%s", Name, Message);
						SendClientMessage(i, 0xFFFFFFFF, Msg);
			    	    }
    				}
    			}
    		}
    	}
    }
  	else
	    return 0;
	return 1;
}
COMMAND:ao(playerid, params[])
{
	new Name[24], Msg[128], Message[128];
	SendAdminText(playerid, "/ao", params);
	GetPlayerName(playerid, Name, sizeof(Name));
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 4)
		{
			if (sscanf(params, "s[128]", Message)) SendClientMessage(playerid, 0xFF0000AA, "Use: /ao [texto]");
			else
			{
				for (new i; i < MAX_PLAYERS; i++)
				{
					if (APlayerData[i][LoggedIn] == true)
					{
					    if (APlayerData[i][PlayerLevel] > 3)
					    {
	            			format(Msg, sizeof(Msg), "~w~%s", Message);
	        	    		GameTextForAll(Msg, 5000, 3);
					    }
					}
				}
			}
		}
		else
		    return 0;
	}
	else
	    return 0;
	return 1;
}
COMMAND:a(playerid, params[])
{
	new Name[24], Msg[128], Message[128];
	SendAdminText(playerid, "/a", params);
	GetPlayerName(playerid, Name, sizeof(Name));
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			if (sscanf(params, "s[128]", Message)) SendClientMessage(playerid, 0xFF0000AA, "Use: /a [texto]");
			else
			{
				for (new i; i < MAX_PLAYERS; i++)
				{
					if (APlayerData[i][LoggedIn] == true)
					{
					    if (APlayerData[i][PlayerLevel] > 0)
					    {
							format(Msg, 128, "{F3BD1B}|Admin Chat| %s: {F3BD1B}%s", Name, Message);
							SendClientMessage(i, 0xFFFFFFFF, Msg);
					    }
					}
				}
			}
		}
		else
		    return 0;
	}
	else
	    return 0;
	return 1;
}
COMMAND:apreender(playerid, params[])
{
	new vid, Reason[128], HouseID, HouseOwner, Name[24], AdminName[24], Msg[128];
	SendAdminText(playerid, "/apreender", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 6)
		{
			if (sscanf(params, "is[128]", vid, Reason)) SendClientMessage(playerid, 0xFF0000AA, "Use: /apreender [id-car] [motivo]");
			else
			{
				HouseID = AVehicleData[vid][BelongsToHouse];
				if (HouseID != 0)
				{
					AVehicleData[vid][SpawnX] = 2585.0;
					AVehicleData[vid][SpawnY] = 2829.0;
					AVehicleData[vid][SpawnZ] = 10.9;
					AVehicleData[vid][SpawnRot] = 0.0;
					for (new i; i < MAX_PLAYERS; i++)
					{
						for(new j; j < MAX_HOUSESPERPLAYER; j++)
						{
							if (APlayerData[i][Houses][j] == HouseID)
							{
							    HouseOwner = i;
								for (new CarSlot; CarSlot < 10; CarSlot++)
								{
									if (AHouseData[HouseID][VehicleIDs][CarSlot] == vid)
									{
										vid = House_ReplaceVehicle(HouseID, CarSlot); 
										AVehicleData[vid][Clamped] = true;
									}
								}

								break;
							}
						}
					}
					GetPlayerName(playerid, AdminName, sizeof(AdminName));
					GetPlayerName(HouseOwner, Name, sizeof(Name));
					format(Msg, 128, "Você apreendeu o veiculo do proprietario: {FFFFFF}%s{00FF00}.", Name);
					SendClientMessage(playerid, 0x00FF00, Msg);
					format(Msg, 128, "O veículo de sua propriedade foi apreendido por {FFFFFF}%s{FF0000}.", AdminName);
					SendClientMessage(HouseOwner, 0xFF0000, Msg);
					format(Msg, 128, "Ele pertence a casa: {FFFFFF}%s{FF0000}.", AHouseData[HouseID][HouseName]);
					SendClientMessage(HouseOwner, 0xFF0000, Msg);
					format(Msg, 128, "Motivo: {FFFFFF}%s{FF0000}.", Reason);
					SendClientMessage(HouseOwner, 0xFF0000, Msg);
					PlayerFile_Save(HouseOwner);
				}
				else
				    SendClientMessage(playerid, 0xFF0000, "Esse veículo não pertence a um jogador, você não pode apreende-lo.");
			}
		}
		else
		    return 0;
	}
	else
	    return 0;
	return 1;
}
COMMAND:liberar(playerid, params[])
{
	new HouseID, vid, ClampedVehicles, UnclampPrice, Msg[128];
	SendAdminText(playerid, "/liberar", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		for (new HouseSlot; HouseSlot < MAX_HOUSESPERPLAYER; HouseSlot++)
		{
			HouseID = APlayerData[playerid][Houses][HouseSlot];
			if (HouseID != 0)
			{
				for (new CarSlot; CarSlot < 10; CarSlot++)
				{
					vid = AHouseData[HouseID][VehicleIDs][CarSlot];
					if (vid != 0)
					{
						if (AVehicleData[vid][Clamped] == true)
						    ClampedVehicles++; 
					}
				}
			}
		}
		if (ClampedVehicles > 0)
		{
			UnclampPrice = ClampedVehicles * UnclampPricePerVehicle;
			format(Msg, 128, "Você tem %i veículos apreendidos, para liberá-los vão lhe custar R$%i.", ClampedVehicles, UnclampPrice);
			ShowPlayerDialog(playerid, DialogUnclampVehicles, DIALOG_STYLE_MSGBOX, TXT_AreYouSure, Msg, "Liberar", TXT_DialogButtonCancel);
		}
		else
		    SendClientMessage(playerid, 0x00FF00, "Você não possui veiculos apreendidos.");
	}
	else
	    return 0;
	return 1;
}
COMMAND:regras(playerid, params[])
{
	new Msg[2000];
	SendAdminText(playerid, "/regras", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		format(Msg, 2000, "%s1. Sempre dirigir do lado direito nas estradas para evitar acidentes.\n", Msg);
		format(Msg, 2000, "%s2. Não chingar ou desrespeitar os outros jogadores, eles são seus companheiros.\n", Msg);
		format(Msg, 2000, "%s3. Usar a linguagem padrão 'Portugues'.\n", Msg);
		format(Msg, 2000, "%s4. Não usar hackers ou será banido permanentemente.\n", Msg);
		format(Msg, 2000, "%s5. Não floodar no chat, pode ser calado por um admin.\n", Msg);
		format(Msg, 2000, "%s6. Não roubar carros, sujeito a prisão caso haja denuncia.\n", Msg);
        format(Msg, 2000, "%s7. Nunca chingue ou desrespeite um administrador, você será banido.\n", Msg);
		ShowPlayerDialog(playerid, DialogRules, DIALOG_STYLE_MSGBOX, "Regras do Brasil Mega Trucker:", Msg, "Aceitar", TXT_DialogButtonCancel);
	}
	else
	    return 0;
	return 1;
}
COMMAND:relato(playerid, params[])
{
	new OtherPlayer, Name[24], Reason[128], Msg[128];
	SendAdminText(playerid, "/relato", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (sscanf(params, "us[128]", OtherPlayer, Reason)) SendClientMessage(playerid, 0xFF0000AA, "Use: /relato [id] [motivo]");
		else
		{
		    if (APlayerData[OtherPlayer][LoggedIn] == true)
		    {
				SendReportToAdmins(OtherPlayer, Reason);
				GetPlayerName(OtherPlayer, Name, sizeof(Name));
				format(Msg, 128, "Você relatou {FFFF00}%s{00FF00}.", Name);
				SendClientMessage(playerid, 0xFF0000, Msg);
			}
			else
			    SendClientMessage(playerid, 0xFF0000, "O jogador nao está conectado.");
		}
	}
	else
	    return 0;
	return 1;
}
COMMAND:relatorio(playerid, params[])
{
	SendAdminText(playerid, "/relatorio", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			if (AReports[0][ReportUsed] == true)
			    format(ReportList, 5000, "%s: %s\n", AReports[0][ReportName], AReports[0][ReportReason]);
			for (new i = 1; i < 50; i++)
			{
				if (AReports[i][ReportUsed] == true)
				{
				    format(ReportList, 5000, "%s%s: %s\n", ReportList, AReports[i][ReportName], AReports[i][ReportReason]);
				}
			}
			ShowPlayerDialog(playerid, DialogReports, DIALOG_STYLE_LIST, "Relatório:", ReportList, "OK", "Cancelar");
		}
		else
		    return 0;
	}
	else
	    return 0;
	return 1;
}
COMMAND:sobrecarga(playerid, params[])
{
	new vModel, bool:ValidOverLoad = false, Float:x, Float:y, Float:z, Name[24], Msg[128];
	SendAdminText(playerid, "/sobrecarga", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerClass] == ClassTruckDriver)
		{
			if (APlayerData[playerid][JobStarted] == true)
			{
				if (APlayerData[playerid][JobStep] == 2)
				{
					if (APlayerData[playerid][Overloaded] == false)
					{
						x = ALocations[APlayerData[playerid][JobLoc1]][LocX];
						y = ALocations[APlayerData[playerid][JobLoc1]][LocY];
						z = ALocations[APlayerData[playerid][JobLoc1]][LocZ];
					    if (IsPlayerInRangeOfPoint(playerid, 25.0, x, y, z))
					    {
							vModel = GetVehicleModel(APlayerData[playerid][VehicleID]);
							switch (vModel)
							{
								case VehicleFlatbed, VehicleDFT30: ValidOverLoad = true; 
								case VehicleLineRunner, VehicleTanker, VehicleRoadTrain:
								{
									switch (GetVehicleModel(APlayerData[playerid][TrailerID]))
									{
										case VehicleTrailerCargo, VehicleTrailerCargo2, VehicleTrailerOre: ValidOverLoad = true; 
									}
								}
							}
							if (ValidOverLoad == true)
							{
							    APlayerData[playerid][Overloaded] = true;
							    SetPlayerWantedLevel(playerid, GetPlayerWantedLevel(playerid) + 2);
							    SendClientMessage(playerid, 0x00FF00, "Você sobrecarregou o seu caminhão, fique atento à policia!");
								GetPlayerName(playerid, Name, sizeof(Name));
								format(Msg, 128, "{FFFFFF}[Boletim] Caminhão de {FF0000}%s{FFFFFF} está sobrecarregado.", Name);
								Police_SendMessage(Msg);
                                format(Msg, 128, "{FFFFFF}[Objetivo] Perseguir e multar.");
                                Police_SendMessage(Msg);
							}
							else
							    SendClientMessage(playerid, 0xFF0000, "Seu veículo nao suporta ser sobrecarregado.");
						}
						else
						    SendClientMessage(playerid, 0xFF0000, "Você precisa estar no ponto de carregamento para sobrecarregar seu caminhão.");
					}
					else
					    SendClientMessage(playerid, 0xFF0000, "Você já está sobrecarregado.");
				}
				else
				    SendClientMessage(playerid, 0xFF0000, "Você deve carregar o seu caminhão primeiro.");
			}
			else
			    SendClientMessage(playerid, 0xFF0000, "Inicie o trabalho primeiro.");
		}
		else
			return 0;
	}
	else
	    return 0;
	return 1;
}
COMMAND:resetarconta(playerid, params[])
{
	new Name[24], AdminName[24], Reason[128], Msg[128], OtherPlayer, ClearMoney, ClearScore, ClearStats;
	SendAdminText(playerid, "/resetarconta", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 6)
		{
			if (sscanf(params, "uiiis[128]", OtherPlayer, ClearMoney, ClearScore, ClearStats, Reason)) SendClientMessage(playerid, 0xFF0000AA, "Use: /resetarconta [id] [dinheiro(0/1)] [score(0/1)] [Status(0/1)] [Motivo]");
			else
			{
				if (APlayerData[OtherPlayer][LoggedIn] == true)
				{
					if ((ClearMoney + ClearScore + ClearStats) == 0)
						return 1;
					GetPlayerName(playerid, AdminName, sizeof(AdminName));
					GetPlayerName(OtherPlayer, Name, sizeof(Name));
					if (ClearMoney == 1)
					{
						APlayerData[OtherPlayer][PlayerMoney] = 0;
						format(Msg, 128, "Seu dinheiro foi resetado por: {FFFF00}%s{FF0000}.", AdminName);
						SendClientMessage(OtherPlayer, 0xFF0000, Msg);
						format(Msg, 128, "Você resetou o dinheiro do jogador: {FFFF00}%s{00FF00}.", Name);
						SendClientMessage(playerid, 0x00FF00, Msg);
					}
					if (ClearScore == 1)
					{
						APlayerData[OtherPlayer][PlayerScore] = 0;
						format(Msg, 128, "Seu score foi resetado por: {FFFF00}%s{FF0000}.", AdminName);
						SendClientMessage(OtherPlayer, 0xFF0000, Msg);
						format(Msg, 128, "Você resetou o score do jogador: {FFFF00}%s{00FF00}.", Name);
						SendClientMessage(playerid, 0x00FF00, Msg);
					}
					if (ClearStats == 1)
					{
						APlayerData[OtherPlayer][StatsTruckerJobs] = 0;
						APlayerData[OtherPlayer][StatsConvoyJobs] = 0;
						APlayerData[OtherPlayer][StatsBusDriverJobs] = 0;
						APlayerData[OtherPlayer][StatsPilotJobs] = 0;
						APlayerData[OtherPlayer][StatsMafiaJobs] = 0;
						APlayerData[OtherPlayer][StatsMafiaStolen] = 0;
						APlayerData[OtherPlayer][StatsPoliceFined] = 0;
						APlayerData[OtherPlayer][StatsPoliceJailed] = 0;
						APlayerData[OtherPlayer][StatsCourierJobs] = 0;
						APlayerData[OtherPlayer][StatsAssistance] = 0;
						APlayerData[OtherPlayer][StatsRoadworkerJobs] = 0;
						APlayerData[OtherPlayer][StatsMetersDriven] = 0.0;
						format(Msg, 128, "Seu status foi resetado por: {FFFF00}%s{FF0000}.", AdminName);
						SendClientMessage(OtherPlayer, 0xFF0000, Msg);
						format(Msg, 128, "Você resetou o status do jogador: {FFFF00}%s{00FF00}.", Name);
						SendClientMessage(playerid, 0x00FF00, Msg);
					}
					format(Msg, 128, "Motivo: {FFFFFF}%s{FF0000}.", Reason);
					SendClientMessage(OtherPlayer, 0xFF0000, Msg);
					PlayerFile_Save(OtherPlayer);
				}
				else
				    SendClientMessage(playerid, 0xFF0000, "Esse jogador não está online.");
			}
		}
		else
			return 0;
	}
	else
	    return 0;
	return 1;
}
COMMAND:corrigirjogador(playerid, params[])
{
	new Name[24], AdminName[24], Msg[128], OtherPlayer;
	SendAdminText(playerid, "/corrigirjogador", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 6)
		{
			if (sscanf(params, "u", OtherPlayer)) SendClientMessage(playerid, 0xFF0000AA, "Use: /corrigirjogador [id]");
			else
			{
				if (APlayerData[OtherPlayer][LoggedIn] == true)
				{
					GetPlayerName(playerid, AdminName, sizeof(AdminName));
					GetPlayerName(OtherPlayer, Name, sizeof(Name));
					for (new i; i < MAX_HOUSESPERPLAYER; i++)
					    APlayerData[OtherPlayer][Houses][i] = 0;

					for (new i; i < MAX_BUSINESSPERPLAYER; i++)
					    APlayerData[OtherPlayer][Business][i] = 0;

					for (new HouseID = 1; HouseID < MAX_HOUSES; HouseID++)
						if (AHouseData[HouseID][Owned] == true) 
							if (strcmp(AHouseData[HouseID][Owner], Name, false) == 0) 
							{
								for (new i; i < MAX_HOUSESPERPLAYER; i++)
								    if (APlayerData[OtherPlayer][Houses][i] == 0) 
								    {
										APlayerData[OtherPlayer][Houses][i] = HouseID; 
										break; 
								    }
							}
					for (new BusID = 1; BusID < MAX_BUSINESS; BusID++)
						if (ABusinessData[BusID][Owned] == true) 
							if (strcmp(ABusinessData[BusID][Owner], Name, false) == 0) 
							{
								for (new i; i < MAX_BUSINESSPERPLAYER; i++) 
								    if (APlayerData[OtherPlayer][Business][i] == 0) 
								    {
										APlayerData[OtherPlayer][Business][i] = BusID; 
										break; 
								    }
							}
					format(Msg, 128, "Sua propriedade foi restaurada por: {FFFF00}%s{00FF00}.", AdminName);
					SendClientMessage(OtherPlayer, 0x00FF00, Msg);
					PlayerFile_Save(OtherPlayer);
				}
				else
				    SendClientMessage(playerid, 0xFF0000, "Esse jogador não está online.");
			}
		}
		else
			return 0;
	}
	else
	    return 0;
	return 1;
}
COMMAND:setskin(playerid, params[])
{
	new Msg[128], Skin;
	SendAdminText(playerid, "/setskin", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 0)
		{
			if (sscanf(params, "i", Skin)) SendClientMessage(playerid, 0xFF0000AA, "Use: /setskin [id(0-299)]");
			else
			{
				if ((Skin >= 0) && (Skin <= 299))
				{
				    SetPlayerSkin(playerid, Skin);
					format(Msg, 128, "Você mudou seu skin para: {FFFF00}%i{00FF00}.", Skin);
					SendClientMessage(playerid, 0x00FF00, Msg);
				}
				else
					SendClientMessage(playerid, 0xFF0000, "Skin inválido, use valores entre 0 e 299.");
			}
		}
		else
			return 0;
	}
	else
	    return 0;
	return 1;
}
COMMAND:banip(playerid, params[])
{
	new PlayerToBan, Reason[128], Msg[128], Name[24], AdminName[24];
	SendAdminText(playerid, "/banip", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 3)
		{
			if (sscanf(params, "us[128]", PlayerToBan, Reason))
				SendClientMessage(playerid, 0xFF0000AA, "Use: /banip [id] [motivo]");
			else
			{
				if (IsPlayerConnected(PlayerToBan))
				{
                    if(APlayerData[PlayerToBan][PlayerLevel] <= 5)                    
                    {
			    		GetPlayerName(playerid, AdminName, sizeof(AdminName));
				    	GetPlayerName(PlayerToBan, Name, sizeof(Name));
			    		format(Msg, 128, "Você teve o IP banido permanentemente por %s.", AdminName);
				    	SendClientMessage(PlayerToBan, 0xFF0000, Msg);
					    format(Msg, 128, "Motivo: {FFFFFF}%s{FF0000}.", Reason);
			    		SendClientMessage(PlayerToBan, 0xFF0000, Msg);
				    	BanEx(PlayerToBan, Reason);
				    	format(Msg, 128, "-| O Administrador %s %s baniu o ip de %s |-", AdminLevelName[APlayerData[playerid][PlayerLevel]], AdminName, Name);
				    	SendClientMessageToAll(0xFF0000, Msg);
				    }
		        }   
		    }
		}
        else
		    return 0;
	}
	else
	    return 0;
	return 1;
}
COMMAND:banfaixa(playerid, params[])
{
	new PlayerToBan, PlayerIP[16], FirstPartsOfIP[16], BanCmd[24], Reason[128], Msg[128], Name[24], AdminName[24];
	SendAdminText(playerid, "/banfaixa", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 3)
		{
			if (sscanf(params, "us[128]", PlayerToBan, Reason))
				SendClientMessage(playerid, 0xFF0000AA, "Use: /banfaixa [id] [motivo]");
			else
			{
				if (IsPlayerConnected(PlayerToBan))
				{
				    if(APlayerData[PlayerToBan][PlayerLevel] <= 5)                    
                    {
		    			GetPlayerName(playerid, AdminName, sizeof(AdminName));
			    		GetPlayerName(PlayerToBan, Name, sizeof(Name));
				    	GetPlayerIp(PlayerToBan, PlayerIP, 16);
			    		format(Msg, 128, "Você teve a faixa de ip banida permanentemente por %s.", AdminName);
				    	SendClientMessage(PlayerToBan, 0xFF0000, Msg);
					    format(Msg, 128, "Motivo: {FFFFFF}%s{FF0000}.", Reason);
		    			SendClientMessage(PlayerToBan, 0xFF0000, Msg);
				    	FirstPartsOfIP = GetFirstThreeDigitsFromIP(PlayerIP);
				    	for (new i; i < 256; i++)
				    	{
					        format(BanCmd, 24, "banip %s%i", FirstPartsOfIP, i); 
                            SendRconCommand(BanCmd); 
					    }
					    Kick(PlayerToBan);
					    format(Msg, 128, "-| O Administrador %s %s baniu a faixa de IP de %s |-", AdminLevelName[APlayerData[playerid][PlayerLevel]], AdminName, Name);
					    SendClientMessageToAll(0xFF0000, Msg);
				   }
			   }
		   }
		}
        else
		    return 0;
	}
	else
	    return 0;
	return 1;
}
COMMAND:darscore(playerid, params[])
{
	new Msg[128], Name[24], OtherName[24], OtherPlayer, pScore;
	SendAdminText(playerid, "/darscore", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 6)
		{
			if (sscanf(params, "ui", OtherPlayer, pScore)) SendClientMessage(playerid, 0xFF0000AA, "Use: /darscore [id] [score]");
			else
			{
				if (IsPlayerConnected(OtherPlayer))
				{
					GetPlayerName(playerid, Name, sizeof(Name));
					GetPlayerName(OtherPlayer, OtherName, sizeof(OtherName));
					APlayerData[OtherPlayer][PlayerScore] = pScore;
					format(Msg, 128, "Seu score foi setado para {FFFF00}%i{00FF00} por {FFFF00}%s{00FF00}.", pScore, Name);
					SendClientMessage(OtherPlayer, 0x00FF00, Msg);
					format(Msg, 128, "Você setou o score de {FFFF00}%s{00FF00} para {FFFF00}%i{00FF00}.", OtherName, pScore);
					SendClientMessage(playerid, 0x00FF00, Msg);
					PlayerFile_Save(OtherPlayer);
				}
				else
				    SendClientMessage(playerid, 0xFF0000, "O jogador não está online.");
			}
		}
		else
		    return 0;
	}
	else
	    return 0;
	return 1;
}
COMMAND:banco(playerid, params[])
{
	new file[100], Name[24];
	SendAdminText(playerid, "/banco", params);
	format(Name, sizeof(Name), APlayerData[playerid][PlayerName]);
	format(file, sizeof(file), BankFile, Name);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (!fexist(file))
		{
			ShowPlayerDialog(playerid, DialogBankPasswordRegister, DIALOG_STYLE_INPUT, "Senha", "Insira uma senha para registrar sua conta bancária 'não esqueça-a!':", TXT_DialogButtonSelect, TXT_DialogButtonCancel);
		}
		else 
        {
			if (APlayerData[playerid][BankLoggedIn] == false)
			{
				ShowPlayerDialog(playerid, DialogBankPasswordLogin, DIALOG_STYLE_PASSWORD, "Senha", "Insira sua senha para logar em sua conta bancária:", TXT_DialogButtonSelect, TXT_DialogButtonCancel);
			}
			else
			{
				ShowBankMenu(playerid);
			}
		}
	}
	else
	    return 0;
	return 1;
}
COMMAND:ajuda(playerid, params[])
{
	SendAdminText(playerid, "/ajuda", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
        HelpList_Create(playerid);
	}
	else
	    return 0;
	return 1;
}
COMMAND:mudarsenha(playerid, params[])
{
	SendAdminText(playerid, "/mudarsenha", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		ShowPlayerDialog(playerid, DialogOldPassword, DIALOG_STYLE_INPUT, "Insira sua senha atual:", "Insira a sua senha atual:", "OK", "Cancelar");
	}
	else
	    return 0;
	return 1;
}
COMMAND:ouvir(playerid, params[])
{
	SendAdminText(playerid, "/ouvir", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
    PlayAudioStreamForPlayer(playerid, "http://dc101.4shared.com:8080/img/107048019/56ca8d17/dlink__2Fdownload_2FQLpEtErJ_3Ftsid_3D20111213-004340-99c271b6/preview.mp3", 258.4893, -41.4008, 1002.0234, 9999999999.0, 1);
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
    SendClientMessage(playerid, 0xFFFFFFFF, "Você está ouvindo: As andorinhas voltaram - Trio Parada Dura.");
    }
    return 1;
}
COMMAND:musicatodos(playerid, params[])
{
	SendAdminText(playerid, "/musicatodos", params);
	if (APlayerData[playerid][LoggedIn] == true)
	{
		if (APlayerData[playerid][PlayerLevel] >= 5)
		{
			for (new i; i < MAX_PLAYERS; i++)
				if (IsPlayerConnected(i))
                PlayAudioStreamForPlayer(i, "http://dc101.4shared.com:8080/img/107048019/56ca8d17/dlink__2Fdownload_2FQLpEtErJ_3Ftsid_3D20111213-004340-99c271b6/preview.mp3", 258.4893, -41.4008, 1002.0234, 9999999999.0, 1);
    		SendClientMessageToAll(0x00FF00FF, "O Administrador colocou todos para ouvir uma rádio, para parar use /surdo !");
		}
		else
		    return 0;
	}
	else
	    return 0;
	return 1;
}
COMMAND:radio(playerid, params[])
{
	SendAdminText(playerid, "/radio", params);
    if (APlayerData[playerid][LoggedIn] == true)
    {
        ShowPlayerDialog(playerid, DialogRadios, DIALOG_STYLE_LIST, "Escolha uma classificação musical:", "Eletronica\r\nSertaneja\r\nForro\r\nFunk Melody\r\nFunk Brasil\r\nRock\r\nAnos 80\r\nDesligar", "Ouvir","Sair");
    }
    return 1;
}
COMMAND:surdo(playerid, params[])
{
	SendAdminText(playerid, "/surdo", params);
	if (APlayerData[playerid][LoggedIn] == true)
    {
        StopAudioStreamForPlayer(playerid);
    }
    return 1;
}
COMMAND:combustivel(playerid, params[])
{
	// Setup local variables
	new vID;

	// Send the command to all admins so they can see it
	SendAdminText(playerid, "/combustivel", params);

	// Check if the player has logged in
	if (APlayerData[playerid][LoggedIn] == true)
	{
		// Check if the player's admin-level is at least 1
		if (APlayerData[playerid][PlayerLevel] >= 1)
		{
			// Check if the player is inside a vehicle
			if (IsPlayerInAnyVehicle(playerid))
			{
			    // Get the vehicleid
			    vID = GetPlayerVehicleID(playerid);
			    // Refuel the vehicle
			    AVehicleData[vID][Fuel] = MaxFuel;
				// Let the player know about it
				SendClientMessage(playerid, 0x00FF00FF, "[INFO] Seu veículo foi abastecido.");
			}
			else
				SendClientMessage(playerid, 0x00FF00FF, "[INFO] Você não está dirigindo um veículo");
		}
		else
		    return 0;
	}
	else
	    return 0;

	// Let the server know that this was a valid command
	return 1;
}
COMMAND:sair(playerid, params[])
{
	SendAdminText(playerid, "/sair", params);
    ShowPlayerDialog(playerid, DialogQ, DIALOG_STYLE_LIST, "Você deseja realmente sair do server?:", "Sim\r\nNão", "Selecionar","Sair");
    return 1;
}

forward VehicleOccupied(vehicleid);
public VehicleOccupied(vehicleid)
{
    for(new i=0;i<MAX_PLAYERS;i++)
    {
        if(IsPlayerInVehicle(i,vehicleid)) return 1;    
    }
    return 0;
}

