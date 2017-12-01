/**********************
****[100% REVISADO]****
***********************/
enum TTrailer
{
	TrailerName[50],
	TrailerModel
}
new ATrailers[][TTrailer] =
{
	{"Bau", 435}, {"Caçamba", 450}, {"Bau compacto", 591},	{"Bauzinho aeroporto", 606},// ID 0, 1, 2, 3
	{"Prancha aeroporto", 607},	{"Arador", 610}, {"Trailer de Fluidos", 584}, {"Trailer Escada", 608},// ID 4, 5, 6, 7
	{"Trailer DNIT", 611}// ID 8
};
TrailerList_Create(playerid)
{
	new Counter, TrailerList[500], DialogTitle[128];
	for (new i = APlayerData[playerid][DialogTrailerFirstTrailer]; i < sizeof(ATrailers); i++)
	{
		Counter++;
		if (Counter <= 10)
		{
		    if (strlen(TrailerList) == 0) 
				format(TrailerList, 500, "%s", ATrailers[i][TrailerName]); 
		    else
				format(TrailerList, 500, "%s%s%s", TrailerList, "\n", ATrailers[i][TrailerName]); 
		}
		else 
		{
			format(TrailerList, 500, "%s%s%s", TrailerList, "\n \n", TXT_DialogEntryNext);
			break;
		}
	}
	format(DialogTitle, 128, TXT_DialogTrailerTitle, (APlayerData[playerid][DialogTrailerFirstTrailer] / 10) + 1);
	ShowPlayerDialog(playerid, DialogTrailer, DIALOG_STYLE_LIST, DialogTitle, TrailerList, TXT_DialogButtonSpawn, TXT_DialogButtonCancel);
	return 1;
}

