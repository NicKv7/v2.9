/**********************
****[100% REVISADO]****
***********************/
enum TPlane
{
	PlaneName[50], // Holds the name of the Plane
	PlaneModel // Holds the model-ID of the Plane
}
new APlanes[][TPlane] =
{
	{"Andromada", 592},		{"AT400", 577}, 	{"Beagle", 511},				{"Cargobob", 548},          // ID 0, 1, 2, 3
	{"Cropduster", 512},	{"Dodo", 593},		{"Hunter", 425},				{"Hydra", 520},             // ID 4, 5, 6, 7
	{"Leviathan", 417},		{"Maverick", 487},	{"Nevada", 553},				{"Police Maverick", 497},   // ID 8, 9, 10, 11
	{"Raindance", 563},		{"Rustler", 476},	{"SAN News Maverick", 488},		{"Seasparrow", 447},        // ID 12, 13, 14, 15
	{"Shamal", 519},		{"Skimmer", 460},	{"Sparrow", 469},				{"Stuntplane", 513}         // ID 16, 17, 18, 19
};
PlaneList_Create(playerid)
{
	new Counter, PlaneList[500], DialogTitle[128];
	for (new i = APlayerData[playerid][DialogPlaneFirstPlane]; i < sizeof(APlanes); i++)
	{
		Counter++;
		if (Counter <= 10)
		{
		    if (strlen(PlaneList) == 0)
				format(PlaneList, 500, "%s", APlanes[i][PlaneName]);
		    else
				format(PlaneList, 500, "%s%s%s", PlaneList, "\n", APlanes[i][PlaneName]);
		}
		else
		{
			format(PlaneList, 500, "%s%s%s", PlaneList, "\n \n", TXT_DialogEntryNext);
			break;
		}
	}
	format(DialogTitle, 128, TXT_DialogPlaneTitle, (APlayerData[playerid][DialogPlaneFirstPlane] / 10) + 1);
	ShowPlayerDialog(playerid, DialogPlane, DIALOG_STYLE_LIST, DialogTitle, PlaneList, TXT_DialogButtonSpawn, TXT_DialogButtonCancel);
	return 1;
}

