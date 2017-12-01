stock FixHouses()
{
	new file[100], File:PFile, Name[24], LineFromFile[100], ParameterName[50], ParameterValue[50];
	new bool:PlayerOwnedTheHouse = true, HousesFixed;
	for (new HouseID = 1; HouseID < MAX_HOUSES; HouseID++)
	{
		if (AHouseData[HouseID][Owned] == true)
		{
			format(Name, 24, AHouseData[HouseID][Owner]);
			format(file, sizeof(file), PlayerFile, Name);
			if (fexist(file))
			{
				PFile = fopen(file, io_read);
				fread(PFile, LineFromFile);
				while (strlen(LineFromFile) > 0)
				{
					StripNewLine(LineFromFile);
					sscanf(LineFromFile, "s[50]s[50]", ParameterName, ParameterValue);
					if (strcmp(ParameterName, "House", false) == 0)
					{
					    if (strval(ParameterValue) == HouseID)
                            PlayerOwnedTheHouse = true;
					}
					fread(PFile, LineFromFile);
				}
				fclose(PFile);
				if (PlayerOwnedTheHouse == false)
				{
					AHouseData[HouseID][Owned] = false;
					AHouseData[HouseID][Owner] = 0;
					AHouseData[HouseID][HouseName] = 0;
					AHouseData[HouseID][HouseLevel] = 1;
					House_UpdateEntrance(HouseID);
					HouseFile_Save(HouseID);
					HousesFixed++;
				}
                PlayerOwnedTheHouse = false;
			}
		}
	}
	printf(TXT_HousesFixed, HousesFixed);
}
GameModeInit_VehiclesPickups()
{
	new LastVehicleMsg[100], LastObjectMsg[100], LastHouseMsg[100], LastBusinessMsg[100], LastCameraMsg[100];
	GameModeInit_TruckDepots();
	GameModeInit_Busses();
	GameModeInit_Busstops();
	GameModeInit_Police();
	GameModeInit_Mafia();
	GameModeInit_Airports();
	GameModeInit_Assistance();
	GameModeInit_Courier();
	GameModeInit_RoadWorker();
	GameModeInit_PickupsIcons();
	GameModeInit_Toll();
	Housing_LoadAll();
	Camera_LoadAll();
    Business_LoadAll();
	SetTimer("Business_TransactionTimer", 1000 * 60 * 60, true);
	IntrestTime_Load();
	SetTimer("Bank_IntrestTimer", 1000 * 60 * 60, true);
	format(LastVehicleMsg, 100, TXT_LastVehicleID, LastVehicleID);
	format(LastObjectMsg, 100, TXT_LastObjectID, LastObjectID);
	format(LastHouseMsg, 100, TXT_TotalHouses, TotalHouses);
	format(LastBusinessMsg, 100, TXT_TotalBusiness, TotalBusiness);
	format(LastCameraMsg, 100, TXT_TotalSpeedCameras, TotalCameras);
	print(TXT_DebugInfo);
	print("-------------------------------------");
	print(LastVehicleMsg);
	print(LastObjectMsg);
	print(LastHouseMsg);
	print(LastBusinessMsg);
	print(LastCameraMsg);
	print("Original - By Brendon");
}
GameModeInit_TruckDepots()
{
	// Add trailers, trucks , Flatbeds and "DFT-30" to Fallen Tree Depot (Class 0)
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerCargo, -475.0, -523.0, 26.0, 90.0, 1, 1, 600); // Cargo trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerOre, -475.0, -518.0, 26.0, 90.0, 1, 1, 600); // Ore trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerFluids, -475.0, -513.0, 26.0, 90.0, 1, 1, 600); // Liquids trailer
	LastVehicleID = Vehicle_AddStatic(VehicleLineRunner, -475.0, -508.0, 26.0, 90.0, random(126), random(126), 600); // LineRunner
	LastVehicleID = Vehicle_AddStatic(VehicleTanker, -475.0, -503.0, 26.0, 90.0, random(126), random(126), 600); // Tanker
	LastVehicleID = Vehicle_AddStatic(VehicleRoadTrain, -475.0, -498.0, 26.0, 90.0, random(126), random(126), 600); // Roadtrain
	LastVehicleID = Vehicle_AddStatic(VehicleDFT30, -475.0, -493.0, 26.0, 90.0, random(126), random(126), 600); // DFT-30
	LastVehicleID = Vehicle_AddStatic(VehicleFlatbed, -475.0, -488.0, 26.0, 90.0, random(126), random(126), 600); // Flatbed
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerCargo, -475.0, -475.0, 26.0, 180.0, 1, 1, 600); // Cargo trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerOre, -480.0, -475.0, 26.0, 180.0, 1, 1, 600); // Ore trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerFluids, -485.0, -475.0, 26.0, 180.0, 1, 1, 600); // Liquids trailer
	LastVehicleID = Vehicle_AddStatic(VehicleLineRunner, -490.0, -475.0, 26.0, 180.0, random(126), random(126), 600); // LineRunner
	LastVehicleID = Vehicle_AddStatic(VehicleTanker, -495.0, -475.0, 26.0, 180.0, random(126), random(126), 600); // Tanker
	LastVehicleID = Vehicle_AddStatic(VehicleRoadTrain, -500.0, -475.0, 26.0, 180.0, random(126), random(126), 600); // Roadtrain
	LastVehicleID = Vehicle_AddStatic(VehicleDFT30, -505.0, -475.0, 26.0, 180.0, random(126), random(126), 600); // DFT-30
	LastVehicleID = Vehicle_AddStatic(VehicleFlatbed, -510.0, -475.0, 26.0, 180.0, random(126), random(126), 600); // Flatbed
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerCargo, -515.0, -475.0, 26.0, 180.0, 1, 1, 600); // Cargo trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerOre, -520.0, -475.0, 26.0, 180.0, 1, 1, 600); // Ore trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerFluids, -525.0, -475.0, 26.0, 180.0, 1, 1, 600); // Liquids trailer
	LastVehicleID = Vehicle_AddStatic(VehicleLineRunner, -530.0, -475.0, 26.0, 180.0, random(126), random(126), 600); // LineRunner
	LastVehicleID = Vehicle_AddStatic(VehicleTanker, -535.0, -475.0, 26.0, 180.0, random(126), random(126), 600); // Tanker
	LastVehicleID = Vehicle_AddStatic(VehicleRoadTrain, -540.0, -475.0, 26.0, 180.0, random(126), random(126), 600); // Roadtrain
	LastVehicleID = Vehicle_AddStatic(VehicleDFT30, -545.0, -475.0, 26.0, 180.0, random(126), random(126), 600); // DFT-30
	LastVehicleID = Vehicle_AddStatic(VehicleFlatbed, -550.0, -475.0, 26.0, 180.0, random(126), random(126), 600); // Flatbed

	// Add "Flatbed" and "DFT-30" trucks to Flint Trucking Depot (Class 1)
	LastVehicleID = Vehicle_AddStatic(VehicleDFT30, -77.0, -1109.0, 1.25, 160.0, random(126), random(126), 600); // DFT-30
	LastVehicleID = Vehicle_AddStatic(VehicleDFT30, -72.0, -1112.0, 1.25, 160.0, random(126), random(126), 600); // DFT-30
	LastVehicleID = Vehicle_AddStatic(VehicleDFT30, -67.0, -1114.0, 1.25, 160.0, random(126), random(126), 600); // DFT-30
	LastVehicleID = Vehicle_AddStatic(VehicleFlatbed, -30.0, -1128.0, 1.25, 160.0, random(126), random(126), 600); // Flatbed
	LastVehicleID = Vehicle_AddStatic(VehicleFlatbed, -41.0, -1152.0, 1.25, 335.0, random(126), random(126), 600); // Flatbed
	LastVehicleID = Vehicle_AddStatic(VehicleFlatbed, -46.0, -1150.0, 1.25, 335.0, random(126), random(126), 600); // Flatbed
	LastVehicleID = Vehicle_AddStatic(VehicleFlatbed, -51.0, -1148.0, 1.25, 335.0, random(126), random(126), 600); // Flatbed
	LastVehicleID = Vehicle_AddStatic(VehicleFlatbed, -56.0, -1146.0, 1.25, 335.0, random(126), random(126), 600); // Flatbed
	LastVehicleID = Vehicle_AddStatic(VehicleFlatbed, -61.0, -1144.0, 1.25, 335.0, random(126), random(126), 600); // Flatbed

	// Add trailers, trucks , Flatbeds and "DFT-30" to LVA Freight Depot (Class 2)
	LastVehicleID = Vehicle_AddStatic(VehicleDFT30, 1467.0, 975.0, 11.0, 0.0, random(126), random(126), 600); // DFT-30
	LastVehicleID = Vehicle_AddStatic(VehicleFlatbed, 1472.0, 975.0, 11.0, 0.0, random(126), random(126), 600); // Flatbed
	LastVehicleID = Vehicle_AddStatic(VehicleDFT30, 1445.0, 975.0, 11.0, 0.0, random(126), random(126), 600); // DFT-30
	LastVehicleID = Vehicle_AddStatic(VehicleFlatbed, 1440.0, 975.0, 11.0, 0.0, random(126), random(126), 600); // Flatbed
	LastVehicleID = Vehicle_AddStatic(VehicleDFT30, 1435.0, 975.0, 11.0, 0.0, random(126), random(126), 600); // DFT-30
	LastVehicleID = Vehicle_AddStatic(VehicleFlatbed, 1430.0, 975.0, 11.0, 0.0, random(126), random(126), 600); // Flatbed
	LastVehicleID = Vehicle_AddStatic(VehicleDFT30, 1420.0, 975.0, 11.0, 0.0, random(126), random(126), 600); // DFT-30
	LastVehicleID = Vehicle_AddStatic(VehicleFlatbed, 1415.0, 975.0, 11.0, 0.0, random(126), random(126), 600); // Flatbed
	LastVehicleID = Vehicle_AddStatic(VehicleDFT30, 1410.0, 975.0, 11.0, 0.0, random(126), random(126), 600); // DFT-30
	LastVehicleID = Vehicle_AddStatic(VehicleFlatbed, 1405.0, 975.0, 11.0, 0.0, random(126), random(126), 600); // Flatbed
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerCargo, 1490.0, 1015.0, 11.0, 90.0, 1, 1, 600); // Cargo trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerOre, 1490.0, 1020.0, 11.0, 90.0, 1, 1, 600); // Ore trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerFluids, 1490.0, 1025.0, 11.0, 90.0, 1, 1, 600); // Liquids trailer
	LastVehicleID = Vehicle_AddStatic(VehicleLineRunner, 1490.0, 1030.0, 11.0, 90.0, random(126), random(126), 600); // LineRunner
	LastVehicleID = Vehicle_AddStatic(VehicleTanker, 1490.0, 1035.0, 11.0, 90.0, random(126), random(126), 600); // Tanker
	LastVehicleID = Vehicle_AddStatic(VehicleRoadTrain, 1490.0, 1040.0, 11.0, 90.0, random(126), random(126), 600); // Roadtrain
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerCargo, 1490.0, 1045.0, 11.0, 90.0, 1, 1, 600); // Cargo trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerOre, 1490.0, 1050.0, 11.0, 90.0, 1, 1, 600); // Ore trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerFluids, 1490.0, 1055.0, 11.0, 90.0, 1, 1, 600); // Liquids trailer
	LastVehicleID = Vehicle_AddStatic(VehicleLineRunner, 1490.0, 1060.0, 11.0, 90.0, random(126), random(126), 600); // LineRunner
	LastVehicleID = Vehicle_AddStatic(VehicleTanker, 1490.0, 1065.0, 11.0, 90.0, random(126), random(126), 600); // Tanker
	LastVehicleID = Vehicle_AddStatic(VehicleRoadTrain, 1490.0, 1070.0, 11.0, 90.0, random(126), random(126), 600); // Roadtrain

	// Add trailers, trucks , Flatbeds and "DFT-30" to Doherty Depot (Class 3)
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerCargo, -2105.0, -200.0, 35.5, 90.0, 1, 1, 600); // Cargo trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerOre, -2105.0, -205.0, 35.5, 90.0, 1, 1, 600); // Ore trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerFluids, -2105.0, -210.0, 35.5, 90.0, 1, 1, 600); // Liquids trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerCargo, -2105.0, -215.0, 35.5, 90.0, 1, 1, 600); // Cargo trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerOre, -2105.0, -220.0, 35.5, 90.0, 1, 1, 600); // Ore trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerFluids, -2105.0, -225.0, 35.5, 90.0, 1, 1, 600); // Liquids trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerCargo, -2105.0, -230.0, 35.5, 90.0, 1, 1, 600); // Cargo trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerOre, -2105.0, -235.0, 35.5, 90.0, 1, 1, 600); // Ore trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerFluids, -2105.0, -240.0, 35.5, 90.0, 1, 1, 600); // Liquids trailer
	LastVehicleID = Vehicle_AddStatic(VehicleDFT30, -2105.0, -245.0, 35.5, 90.0, random(126), random(126), 600); // DFT-30
	LastVehicleID = Vehicle_AddStatic(VehicleFlatbed, -2105.0, -250.0, 35.5, 90.0, random(126), random(126), 600); // Flatbed
	LastVehicleID = Vehicle_AddStatic(VehicleDFT30, -2105.0, -255.0, 35.5, 90.0, random(126), random(126), 600); // DFT-30
	LastVehicleID = Vehicle_AddStatic(VehicleFlatbed, -2105.0, -260.0, 35.5, 90.0, random(126), random(126), 600); // Flatbed
	LastVehicleID = Vehicle_AddStatic(VehicleDFT30, -2105.0, -265.0, 35.5, 90.0, random(126), random(126), 600); // DFT-30
	LastVehicleID = Vehicle_AddStatic(VehicleFlatbed, -2105.0, -270.0, 35.5, 90.0, random(126), random(126), 600); // Flatbed
	LastVehicleID = Vehicle_AddStatic(VehicleLineRunner, -2144.0, -186.0, 35.5, 270.0, random(126), random(126), 600); // LineRunner
	LastVehicleID = Vehicle_AddStatic(VehicleTanker, -2144.0, -191.0, 35.5, 270.0, random(126), random(126), 600); // Tanker
	LastVehicleID = Vehicle_AddStatic(VehicleRoadTrain, -2144.0, -196.0, 35.5, 270.0, random(126), random(126), 600); // Roadtrain
	LastVehicleID = Vehicle_AddStatic(VehicleLineRunner, -2144.0, -201.0, 35.5, 270.0, random(126), random(126), 600); // LineRunner
	LastVehicleID = Vehicle_AddStatic(VehicleTanker, -2144.0, -206.0, 35.5, 270.0, random(126), random(126), 600); // Tanker
	LastVehicleID = Vehicle_AddStatic(VehicleRoadTrain, -2144.0, -211.0, 35.5, 270.0, random(126), random(126), 600); // Roadtrain

	// Add trailers, trucks , Flatbeds and "DFT-30" to El Corona Depot (Class 4)
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerCargo, 1805.0, -2025.0, 14.0, 90.0, 1, 1, 600); // Cargo trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerOre, 1805.0, -2030.0, 14.0, 90.0, 1, 1, 600); // Ore trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerFluids, 1805.0, -2035.0, 14.0, 90.0, 1, 1, 600); // Liquids trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerCargo, 1805.0, -2040.0, 14.0, 90.0, 1, 1, 600); // Cargo trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerOre, 1805.0, -2045.0, 14.0, 90.0, 1, 1, 600); // Ore trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerFluids, 1805.0, -2050.0, 14.0, 90.0, 1, 1, 600); // Liquids trailer
	LastVehicleID = Vehicle_AddStatic(VehicleDFT30, 1745.0, -2070.0, 14.0, 0.0, random(126), random(126), 600); // DFT-30
	LastVehicleID = Vehicle_AddStatic(VehicleFlatbed, 1750.0, -2070.0, 14.0, 0.0, random(126), random(126), 600); // Flatbed
	LastVehicleID = Vehicle_AddStatic(VehicleDFT30, 1755.0, -2070.0, 14.0, 0.0, random(126), random(126), 600); // DFT-30
	LastVehicleID = Vehicle_AddStatic(VehicleFlatbed, 1760.0, -2070.0, 14.0, 0.0, random(126), random(126), 600); // Flatbed
	LastVehicleID = Vehicle_AddStatic(VehicleLineRunner, 1765.0, -2070.0, 14.0, 0.0, random(126), random(126), 600); // LineRunner
	LastVehicleID = Vehicle_AddStatic(VehicleTanker, 1770.0, -2070.0, 14.0, 0.0, random(126), random(126), 600); // Tanker
	LastVehicleID = Vehicle_AddStatic(VehicleRoadTrain, 1775.0, -2070.0, 14.0, 0.0, random(126), random(126), 600); // Roadtrain

	// Add trailers, trucks , Flatbeds and "DFT-30" to Las Payasdas Depot (Class 5)
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerCargo, -535.0, 2635.0, 54.0, 270.0, 1, 1, 600); // Cargo trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerOre, -535.0, 2630.0, 54.0, 270.0, 1, 1, 600); // Ore trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerFluids, -535.0, 2625.0, 54.0, 270.0, 1, 1, 600); // Liquids trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerCargo, -535.0, 2620.0, 54.0, 270.0, 1, 1, 600); // Cargo trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerOre, -535.0, 2615.0, 54.0, 270.0, 1, 1, 600); // Ore trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerFluids, -535.0, 2610.0, 54.0, 270.0, 1, 1, 600); // Liquids trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerCargo, -535.0, 2605.0, 54.0, 270.0, 1, 1, 600); // Cargo trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerOre, -535.0, 2600.0, 54.0, 270.0, 1, 1, 600); // Ore trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerFluids, -535.0, 2595.0, 54.0, 270.0, 1, 1, 600); // Liquids trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerCargo, -535.0, 2590.0, 54.0, 270.0, 1, 1, 600); // Cargo trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerOre, -535.0, 2585.0, 54.0, 270.0, 1, 1, 600); // Ore trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerFluids, -535.0, 2580.0, 54.0, 270.0, 1, 1, 600); // Liquids trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerCargo, -535.0, 2575.0, 54.0, 270.0, 1, 1, 600); // Cargo trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerOre, -535.0, 2570.0, 54.0, 270.0, 1, 1, 600); // Ore trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerFluids, -535.0, 2565.0, 54.0, 270.0, 1, 1, 600); // Liquids trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerCargo, -535.0, 2560.0, 54.0, 270.0, 1, 1, 600); // Cargo trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerOre, -535.0, 2555.0, 54.0, 270.0, 1, 1, 600); // Ore trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerFluids, -535.0, 2550.0, 54.0, 270.0, 1, 1, 600); // Liquids trailer

	LastVehicleID = Vehicle_AddStatic(VehicleLineRunner, -512.0, 2635.0, 54.0, 90.0, random(126), random(126), 600); // LineRunner
	LastVehicleID = Vehicle_AddStatic(VehicleTanker, -512.0, 2630.0, 54.0, 90.0, random(126), random(126), 600); // Tanker
	LastVehicleID = Vehicle_AddStatic(VehicleRoadTrain, -512.0, 2625.0, 54.0, 90.0, random(126), random(126), 600); // Roadtrain
	LastVehicleID = Vehicle_AddStatic(VehicleLineRunner, -512.0, 2620.0, 54.0, 90.0, random(126), random(126), 600); // LineRunner
	LastVehicleID = Vehicle_AddStatic(VehicleTanker, -512.0, 2615.0, 54.0, 90.0, random(126), random(126), 600); // Tanker
	LastVehicleID = Vehicle_AddStatic(VehicleRoadTrain, -512.0, 2610.0, 54.0, 90.0, random(126), random(126), 600); // Roadtrain
	LastVehicleID = Vehicle_AddStatic(VehicleDFT30, -512.0, 2605.0, 54.0, 90.0, random(126), random(126), 600); // DFT-30
	LastVehicleID = Vehicle_AddStatic(VehicleFlatbed, -512.0, 2600.0, 54.0, 90.0, random(126), random(126), 600); // Flatbed
	LastVehicleID = Vehicle_AddStatic(VehicleDFT30, -512.0, 2585.0, 54.0, 90.0, random(126), random(126), 600); // DFT-30
	LastVehicleID = Vehicle_AddStatic(VehicleFlatbed, -512.0, 2580.0, 54.0, 90.0, random(126), random(126), 600); // Flatbed
	LastVehicleID = Vehicle_AddStatic(VehicleLineRunner, -512.0, 2575.0, 54.0, 90.0, random(126), random(126), 600); // LineRunner
	LastVehicleID = Vehicle_AddStatic(VehicleTanker, -512.0, 2570.0, 54.0, 90.0, random(126), random(126), 600); // Tanker
	LastVehicleID = Vehicle_AddStatic(VehicleRoadTrain, -512.0, 2565.0, 54.0, 90.0, random(126), random(126), 600); // Roadtrain
	LastVehicleID = Vehicle_AddStatic(VehicleLineRunner, -512.0, 2560.0, 54.0, 90.0, random(126), random(126), 600); // LineRunner
	LastVehicleID = Vehicle_AddStatic(VehicleTanker, -512.0, 2555.0, 54.0, 90.0, random(126), random(126), 600); // Tanker
	LastVehicleID = Vehicle_AddStatic(VehicleRoadTrain, -512.0, 2550.0, 54.0, 90.0, random(126), random(126), 600); // Roadtrain

	// Add cement-trucks at Quarry Top (Class 6)
	LastVehicleID = Vehicle_AddStatic(VehicleCementTruck, 340.0, 850.0, 21.0, 0, random(126), random(126), 600); // Cement truck
	LastVehicleID = Vehicle_AddStatic(VehicleCementTruck, 335.0, 860.0, 21.0, 0, random(126), random(126), 600); // Cement truck
	LastVehicleID = Vehicle_AddStatic(VehicleCementTruck, 330.0, 870.0, 21.0, 0, random(126), random(126), 600); // Cement truck
	LastVehicleID = Vehicle_AddStatic(VehicleCementTruck, 325.0, 880.0, 21.0, 0, random(126), random(126), 600); // Cement truck
	LastVehicleID = Vehicle_AddStatic(VehicleCementTruck, 320.0, 890.0, 21.0, 0, random(126), random(126), 600); // Cement truck

	// Add trailers and trucks to Shady Creek Depot (Class 7)
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerCargo, -1545.0, -2737.00, 49.0, 145.0, 1, 1, 600); // Cargo trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerOre, -1540.9, -2739.87, 49.0, 145.0, 1, 1, 600); // Ore trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerFluids, -1536.8, -2742.74, 49.0, 145.0, 1, 1, 600); // Liquids trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerCargo, -1532.7, -2745.61, 49.0, 145.0, 1, 1, 600); // Cargo trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerOre, -1528.6, -2748.48, 49.0, 145.0, 1, 1, 600); // Ore trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerFluids, -1524.5, -2751.35, 49.0, 145.0, 1, 1, 600); // Liquids trailer
	LastVehicleID = Vehicle_AddStatic(VehicleLineRunner, -1557.75, -2744.80, 49.0, 145.0, random(126), random(126), 600); // LineRunner
	LastVehicleID = Vehicle_AddStatic(VehicleTanker, -1561.85, -2741.93, 49.0, 145.0, random(126), random(126), 600); // Tanker
	LastVehicleID = Vehicle_AddStatic(VehicleRoadTrain, -1565.95, -2739.06, 49.0, 145.0, random(126), random(126), 600); // Roadtrain
	LastVehicleID = Vehicle_AddStatic(VehicleLineRunner, -1570.05, -2736.19, 49.0, 145.0, random(126), random(126), 600); // LineRunner
	LastVehicleID = Vehicle_AddStatic(VehicleTanker, -1574.15, -2733.32, 49.0, 145.0, random(126), random(126), 600); // Tanker
	LastVehicleID = Vehicle_AddStatic(VehicleRoadTrain, -1578.25, -2730.45, 49.0, 145.0, random(126), random(126), 600); // Roadtrain

    LastVehicleID = Vehicle_AddStatic(VehicleCementTruck, 388.0690,890.3834,21.5718,90, random(126), random(126), 600);  // cimento 1
	LastVehicleID = Vehicle_AddStatic(VehicleCementTruck, 388.0767,897.3638,21.6998,90, random(126), random(126), 600);  // cimento 2
	LastVehicleID = Vehicle_AddStatic(VehicleCementTruck, 388.2925,904.3020,21.8445,90, random(126), random(126), 600);  // cimento 3
	LastVehicleID = Vehicle_AddStatic(VehicleCementTruck, 388.4624,910.8620,22.2250,90, random(126), random(126), 600);   // cimento 4
	LastVehicleID = Vehicle_AddStatic(VehicleRoadTrain, 587.0102,1637.2920,7.9648,66, random(126), random(126), 600);    // RD
	LastVehicleID = Vehicle_AddStatic(VehicleLineRunner, 590.9781,1640.5923,7.6074,66, random(126), random(126), 600);   // LR
	LastVehicleID = Vehicle_AddStatic(VehicleTanker, 595.7414,1643.9237,7.5788,66, random(126), random(126), 600);       // TK
	LastVehicleID = Vehicle_AddStatic(VehicleRoadTrain, 601.1155,1646.7612,8.0030,66, random(126), random(126), 600);    // RD
	LastVehicleID = Vehicle_AddStatic(VehicleLineRunner, 605.9689,1650.0739,7.6005,66, random(126), random(126), 600);   // LR
	LastVehicleID = Vehicle_AddStatic(VehicleTanker, 610.4166,1653.2623,7.5871,66, random(126), random(126), 600);       // TK
	LastVehicleID = Vehicle_AddStatic(VehicleRoadTrain, 615.8130,1656.0835,8.0307,66, random(126), random(126), 600);    // RD
	LastVehicleID = Vehicle_AddStatic(VehicleLineRunner, 620.1772,1659.1241,7.6016,66, random(126), random(126), 600);   // LR
	LastVehicleID = Vehicle_AddStatic(VehicleTanker, 623.2482,1662.3817,7.5968,66, random(126), random(126), 600);        // TK
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerCargo, 546.0825,1672.5804,7.6242,212, 1, 1, 600); // BAU
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerOre, 549.9156,1674.8506,7.6220,212, 1, 1, 600);   // MINA
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerFluids, 554.0096,1677.1244,8.1397,212, 1, 1, 600); // FLUID
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerCargo, 557.9509,1679.9059,7.6280,212, 1, 1, 600);  // BAU
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerOre, 562.2943,1682.4259,7.6221,212, 1, 1, 600);    // MINA
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerFluids, 567.0844,1684.9845,8.1434,212, 1, 1, 600); // FLUID
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerCargo, 571.7048,1688.0977,7.6347,212, 1, 1, 600);  // BAU
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerOre, 576.5266,1691.7284,7.6202,212, 1, 1, 600);    // MINA
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerFluids, 580.3057,1693.5925,8.1417,212, 1, 1, 600); // FLUID
	LastVehicleID = Vehicle_AddStatic(VehicleTrailerCargo, 585.4935,1696.8278,7.6340,212, 1, 1, 600);  // BAU
}

// Add busses to the bus-depots
GameModeInit_Busses()
{
	// Add all required busses to the busdepot in Los Santos
	LastVehicleID = Vehicle_AddStatic(VehicleCoach, 1782.0, -1888.0, 13.6, 270.0, random(126), random(126), 600); // Coach
	LastVehicleID = Vehicle_AddStatic(VehicleCoach, 1782.0, -1893.0, 13.6, 270.0, random(126), random(126), 600); // Coach
	LastVehicleID = Vehicle_AddStatic(VehicleCoach, 1782.0, -1898.0, 13.6, 270.0, random(126), random(126), 600); // Coach
	LastVehicleID = Vehicle_AddStatic(VehicleCoach, 1782.0, -1903.0, 13.6, 270.0, random(126), random(126), 600); // Coach
	LastVehicleID = Vehicle_AddStatic(VehicleCoach, 1782.0, -1908.0, 13.6, 270.0, random(126), random(126), 600); // Coach
	LastVehicleID = Vehicle_AddStatic(VehicleCoach, 1782.0, -1913.0, 13.6, 270.0, random(126), random(126), 600); // Coach
	LastVehicleID = Vehicle_AddStatic(VehicleCoach, 1782.0, -1918.0, 13.6, 270.0, random(126), random(126), 600); // Coach

	// Add all required busses to the busdepot in San Fierro
	LastVehicleID = Vehicle_AddStatic(VehicleCoach, -1974.0, 105.0, 27.9, 90.0, random(126), random(126), 600); // Coach
	LastVehicleID = Vehicle_AddStatic(VehicleCoach, -1974.0, 100.0, 27.9, 90.0, random(126), random(126), 600); // Coach
	LastVehicleID = Vehicle_AddStatic(VehicleCoach, -1974.0, 95.0, 27.9, 90.0, random(126), random(126), 600); // Coach
	LastVehicleID = Vehicle_AddStatic(VehicleCoach, -1974.0, 90.0, 27.9, 90.0, random(126), random(126), 600); // Coach
	LastVehicleID = Vehicle_AddStatic(VehicleCoach, -1974.0, 85.0, 27.9, 90.0, random(126), random(126), 600); // Coach
	LastVehicleID = Vehicle_AddStatic(VehicleCoach, -1974.0, 80.0, 27.9, 90.0, random(126), random(126), 600); // Coach

	// Add all required busses to the busdepot in Las Venturas
	LastVehicleID = Vehicle_AddStatic(VehicleCoach, 1085.0, 1230.0, 11.0, 90.0, random(126), random(126), 600); // Coach
	LastVehicleID = Vehicle_AddStatic(VehicleCoach, 1085.0, 1235.0, 11.0, 90.0, random(126), random(126), 600); // Coach
	LastVehicleID = Vehicle_AddStatic(VehicleCoach, 1085.0, 1240.0, 11.0, 90.0, random(126), random(126), 600); // Coach
	LastVehicleID = Vehicle_AddStatic(VehicleCoach, 1085.0, 1245.0, 11.0, 90.0, random(126), random(126), 600); // Coach
	LastVehicleID = Vehicle_AddStatic(VehicleCoach, 1085.0, 1250.0, 11.0, 90.0, random(126), random(126), 600); // Coach
	LastVehicleID = Vehicle_AddStatic(VehicleCoach, 1085.0, 1255.0, 11.0, 90.0, random(126), random(126), 600); // Coach
	LastVehicleID = Vehicle_AddStatic(VehicleCoach, 1085.0, 1260.0, 11.0, 90.0, random(126), random(126), 600); // Coach
	LastVehicleID = Vehicle_AddStatic(VehicleCoach, 1085.0, 1265.0, 11.0, 90.0, random(126), random(126), 600); // Coach
	LastVehicleID = Vehicle_AddStatic(VehicleCoach, 1085.0, 1270.0, 11.0, 90.0, random(126), random(126), 600); // Coach
	LastVehicleID = Vehicle_AddStatic(VehicleCoach, 1085.0, 1275.0, 11.0, 90.0, random(126), random(126), 600); // Coach
	LastVehicleID = Vehicle_AddStatic(VehicleCoach, 1085.0, 1280.0, 11.0, 90.0, random(126), random(126), 600); // Coach
}

// Add busstops to the map
GameModeInit_Busstops()
{
	LastObjectID = CreateDynamicObject(1257, -2571.25, 2316.0, 5.2, 0.0, 0.0, 180.0);
	LastObjectID = CreateDynamicObject(1257, -2333.25, 2371.5, 6.0, 0.0, 0.0, 320.0);
	LastObjectID = CreateDynamicObject(1257, -1467.0, 2679.0, 56.0, 0.0, 0.0, 90.0);
	LastObjectID = CreateDynamicObject(1257, -1528.5, 2543.0, 56.0, 0.0, 0.0, 270.0);
	LastObjectID = CreateDynamicObject(1257, -800.5, 1562.0, 27.4, 0.0, 0.0, 0.0);
	LastObjectID = CreateDynamicObject(1257, -853.5, 1529.5, 22.4, 0.0, 0.0, 180.0);
	LastObjectID = CreateDynamicObject(1257, -269.0, 2620.5, 63.2, 0.0, 0.0, 270.0);
	LastObjectID = CreateDynamicObject(1257, -45.5, 1206.5, 19.6, 0.0, 0.0, 90.0);
	LastObjectID = CreateDynamicObject(1257, -100.5, 1190.75, 20.0, 0.0, 0.0, 270.0);
	LastObjectID = CreateDynamicObject(1257, -249.5, 1010.75, 20.0, 0.0, 0.0, 270.0);
	LastObjectID = CreateDynamicObject(1257, -2172.5, -2309.5, 30.9, 0.0, 0.0, 230.0);
	LastObjectID = CreateDynamicObject(1257, -2094.25, -2503.0, 30.9, 0.0, 0.0, 322.0);
	LastObjectID = CreateDynamicObject(1257, 2263.75, -35.75, 26.7, 0.0, 0.0, 270.0);
	LastObjectID = CreateDynamicObject(1257, 2456.25, 1.0, 26.5, 0.0, 0.0, 180.0);
	LastObjectID = CreateDynamicObject(1257, 1290.25, 333.5, 19.8, 0.0, 0.0, 65.0);
	LastObjectID = CreateDynamicObject(1257, 1284.75, 319.5, 19.8, 0.0, 0.0, 245.0);
	LastObjectID = CreateDynamicObject(1257, 736.0, -522.5, 16.6, 0.0, 0.0, 90.0);
	LastObjectID = CreateDynamicObject(1257, 736.0, -537.75, 16.6, 0.0, 0.0, 270.0);
    LastObjectID = CreateDynamicObject(16223, -582.7392578125, 295.1982421875, 0.096912786364555, 0, 0, 297.98767089844);
    LastObjectID = CreateDynamicObject(5409, -565.5283203125, 485.2705078125, 6.3825325965881, 0, 0, 273.99353027344);
    LastObjectID = CreateDynamicObject(8947, -552.76257324219, 493.26727294922, 4.8548445701599, 0, 0, 273.74853515625);
    LastObjectID = CreateDynamicObject(8947, -553.8134765625, 507.880859375, 8.4237289428711, 0, 0, 273.9990234375);
    LastObjectID = CreateDynamicObject(8947, -553.8134765625, 507.880859375, 2.3237299919128, 0, 179.99450683594, 273.99353027344);
    LastObjectID = CreateDynamicObject(11393, -546.2744140625, 511.7158203125, 3.4021043777466, 0, 0, 4.4989013671875);
    LastObjectID = CreateDynamicObject(14826, -544.6337890625, 513.2919921875, 2.6353266239166, 0, 0, 183.9990234375);
    LastObjectID = CreateDynamicObject(16776, -601.099609375, 304.685546875, 1.0314757823944, 0, 0, 3.9990234375);
    LastObjectID = CreateDynamicObject(16777, -612.5791015625, 560.5302734375, 1.8709487915039, 0, 0, 93.9990234375);
    LastObjectID = CreateDynamicObject(11417, -569.29437255859, 272.34704589844, 6.7110843658447, 0, 0, 0);
    LastObjectID = CreateDynamicObject(6965, -566.00524902344, 492.84658813477, -1.5915886163712, 0, 0, 0);
    LastObjectID = CreateDynamicObject(6965, -566.03918457031, 493.31948852539, -1.5915886163712, 0, 0, 0);
    LastObjectID = CreateDynamicObject(6965, -565.99420166016, 492.44561767578, -1.5915886163712, 0, 0, 0);
    LastObjectID = CreateDynamicObject(6965, -566.1337890625, 494.4150390625, -1.5915886163712, 0, 0, 0);
    LastObjectID = CreateDynamicObject(6965, -566.18719482422, 495.03759765625, -1.5915886163712, 0, 0, 0);
    LastObjectID = CreateDynamicObject(6965, -565.86242675781, 491.30130004883, -1.5915886163712, 0, 0, 0);
    LastObjectID = CreateDynamicObject(6965, -565.80603027344, 490.65322875977, -1.5915886163712, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3472, -590.9404296875, 423.74835205078, 2.0190954208374, 0, 0, 274);
    LastObjectID = CreateDynamicObject(3472, -588.32897949219, 389.75494384766, 2.0190954208374, 0, 0, 334);
    LastObjectID = CreateDynamicObject(3472, -585.162109375, 347.517578125, 2.0190954208374, 0, 0, 331.99584960938);
    LastObjectID = CreateDynamicObject(1676, -566.00274658203, 462.63800048828, 3.6274619102478, 0, 0, 2.4993896484375);
    LastObjectID = CreateDynamicObject(1676, -563.96630859375, 462.72747802734, 3.6274619102478, 0, 0, 2.493896484375);
    LastObjectID = CreateDynamicObject(1676, -561.93029785156, 462.81799316406, 3.6274619102478, 0, 0, 2.493896484375);
    LastObjectID = CreateDynamicObject(1676, -558.94152832031, 462.9892578125, 3.6274619102478, 0, 0, 2.493896484375);
    LastObjectID = CreateDynamicObject(1676, -556.92596435547, 463.06912231445, 3.6274619102478, 0, 0, 2.493896484375);
    LastObjectID = CreateDynamicObject(1676, -554.90600585938, 463.1686706543, 3.6274619102478, 0, 0, 2.493896484375);
    LastObjectID = CreateDynamicObject(11417, -601.76837158203, 312.67727661133, 15.268731117249, 348.47143554688, 343.66137695313, 314.89306640625);
    LastObjectID = CreateDynamicObject(11081, -546.2626953125, 526.4169921875, 8.5518817901611, 0, 0, 93.9990234375);
    LastObjectID = CreateDynamicObject(11461, -547.1376953125, 482.32421875, 1.8709468841553, 0, 0, 0);
    LastObjectID = CreateDynamicObject(16067, -611.57165527344, 567.3271484375, 1.4721298217773, 0, 0, 3.7462158203125);
    LastObjectID = CreateDynamicObject(16777, -576.17749023438, 408.55676269531, 0.47094905376434, 0, 0, 41.9990234375);
    LastObjectID = CreateDynamicObject(7615, -572.00256347656, 367.36416625977, 3.7900836467743, 0, 0, 274.25);
    LastObjectID = CreateDynamicObject(7615, -572.00573730469, 367.45111083984, 3.5400826931, 0, 0, 274.24621582031);
    LastObjectID = CreateDynamicObject(7615, -601.076171875, 365.7822265625, 3.2900846004486, 359.49462890625, 359.24743652344, 94.235229492188);
    LastObjectID = CreateDynamicObject(7311, -565.7470703125, 492.857421875, 4.0867772102356, 0, 0, 5.745849609375);
    LastObjectID = CreateDynamicObject(3088, -558.35308837891, 500.6130065918, 4.0286173820496, 0, 0, 3.5);
    LastObjectID = CreateDynamicObject(3087, -555.34765625, 500.7975769043, 3.9058077335358, 0, 0, 4);
    LastObjectID = CreateDynamicObject(1238, -549.5478515625, 512.1796875, 2.1891279220581, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1238, -549.68316650391, 513.42449951172, 2.1891279220581, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1238, -549.74304199219, 514.67230224609, 2.1891279220581, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1308, -568.03692626953, 316.72149658203, 1.8480231761932, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1308, -571.93829345703, 363.03536987305, 1.8480231761932, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1308, -575.4375, 418.4501953125, 1.8480231761932, 0, 0, 0);
    LastObjectID = CreateDynamicObject(16223, -594.0859375, 434.2119140625, -16.703067779541, 3.97705078125, 6.009521484375, 119.56970214844);
    LastObjectID = CreateDynamicObject(7522, -582.32421875, 313.31640625, 5.209370136261, 0, 0, 3.9990234375);
    LastObjectID = CreateDynamicObject(1300, -593.8662109375, 304.1796875, 0.54395312070847, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -593.88305664063, 303.46575927734, 0.54395312070847, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -593.87542724609, 302.75381469727, 0.51895314455032, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -593.85894775391, 301.93914794922, 0.51895314455032, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -593.83471679688, 301.32608032227, 0.51895314455032, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -593.84350585938, 300.57528686523, 0.51895314455032, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -593.85229492188, 299.82528686523, 0.51895314455032, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -593.86065673828, 299.1003112793, 0.51895314455032, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -592.98522949219, 299.08856201172, 0.51895314455032, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -592.97546386719, 299.7878112793, 0.51895314455032, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -592.96099853516, 300.5617980957, 0.51895314455032, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -592.95574951172, 301.28671264648, 0.51895314455032, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -592.96081542969, 301.95562744141, 0.51895314455032, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -592.9873046875, 302.7548828125, 0.51895314455032, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -593.01208496094, 303.47952270508, 0.51895314455032, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -592.98657226563, 304.20556640625, 0.51895314455032, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -592.05926513672, 304.20874023438, 0.51895314455032, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -591.07720947266, 304.25805664063, 0.51895314455032, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -590.11688232422, 304.3596496582, 0.51895314455032, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -589.18951416016, 304.33840942383, 0.51895314455032, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -592.01324462891, 303.4762878418, 0.51895314455032, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -592.01776123047, 302.74868774414, 0.51895314455032, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -592.02264404297, 302.02114868164, 0.51895314455032, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -591.05822753906, 303.48300170898, 0.51895314455032, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -591.03991699219, 302.75759887695, 0.51895314455032, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -566.81707763672, 310.15850830078, 0.91895341873169, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -566.81640625, 309.35827636719, 0.91895341873169, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -566.81640625, 308.68258666992, 0.91895341873169, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -566.81640625, 308.00680541992, 0.91895341873169, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -566.81640625, 307.35601806641, 0.91895341873169, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -567.7666015625, 307.35546875, 0.91895341873169, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -568.49230957031, 307.35546875, 0.91895341873169, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -568.4921875, 308.08029174805, 0.91895341873169, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -567.69140625, 308.080078125, 0.91895341873169, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -567.69140625, 308.77990722656, 0.91895341873169, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -567.69140625, 309.45413208008, 0.91895341873169, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -568.51721191406, 309.4541015625, 0.91895341873169, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1300, -568.5166015625, 308.85424804688, 0.91895341873169, 0, 0, 0);  
    //SF perto militares
    LastObjectID = CreateDynamicObject(8661, -1654.7131347656, 444.39883422852, 6.2046856880188, 0, 0, 315.5);
    LastObjectID = CreateDynamicObject(8661, -1669.14453125, 430.55758666992, 6.2046856880188, 0, 0, 315.49987792969);
    LastObjectID = CreateDynamicObject(8661, -1683.0080566406, 416.15637207031, 6.2046856880188, 0, 0, 315.49987792969);
    LastObjectID = CreateDynamicObject(8661, -1697.3336181641, 402.24118041992, 6.2046856880188, 0, 0, 315.49987792969);
    LastObjectID = CreateDynamicObject(8661, -1711.1784667969, 387.85836791992, 6.2046856880188, 0, 0, 315.49987792969);
    LastObjectID = CreateDynamicObject(1080, -1649.6258544922, 422.15789794922, 12.229619979858, 0, 0, 314);
    LastObjectID = CreateDynamicObject(17578, -1719.5556640625, 408.83856201172, 15.138542175293, 0, 0, 47);
    LastObjectID = CreateDynamicObject(1445, -1649.9891357422, 422.49130249023, 14.045322418213, 0, 0, 46);
    LastObjectID = CreateDynamicObject(1444, -1634.6628417969, 433.19451904297, 6.9921875, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1673, -1636.7565917969, 419.0651550293, 10.503444671631, 0, 0, 313);
    LastObjectID = CreateDynamicObject(7415, -1092.8168945313, 1157.0465087891, 46.064067840576, 0, 0, 81.75);
    LastObjectID = CreateDynamicObject(7415, -145.4956817627, 499.82470703125, 19.417835235596, 0, 0, 134);
    LastObjectID = CreateDynamicObject(7415, 406.58825683594, 611.77197265625, 27.518732070923, 0, 0, 186);
    LastObjectID = CreateDynamicObject(7415, 1757.6031494141, 572.14495849609, 33.288749694824, 0, 0, 103.5);
    LastObjectID = CreateDynamicObject(7313, -1639.2436523438, 421.08645629883, 12.82684803009, 0, 0, 313);
    LastObjectID = CreateDynamicObject(7313, -1634.65234375, 416.19799804688, 12.82684803009, 0, 0, 312.99499511719);
    LastObjectID = CreateDynamicObject(7313, -1634.6062011719, 416.23358154297, 12.82684803009, 0, 0, 132.99499511719);
    LastObjectID = CreateDynamicObject(7313, -1639.2092285156, 421.15017700195, 12.82684803009, 0, 0, 132.99499511719);
    LastObjectID = CreateDynamicObject(2643, -1631.2156982422, 412.52951049805, 12.968154907227, 0, 0, 312);
    LastObjectID = CreateDynamicObject(2643, -1631.21484375, 412.529296875, 12.968154907227, 0, 0, 140.24523925781);
    LastObjectID = CreateDynamicObject(966, -1699.5135498047, 371.55624389648, 6.2046856880188, 0, 0, 224);
    LastObjectID = CreateDynamicObject(968, -1699.5430908203, 371.52386474609, 7.0296850204468, 0, 8, 44.5);
    LastObjectID = CreateDynamicObject(10148, -1655.8699951172, 453.32998657227, 8.2482709884644, 0, 0, 224.75);
    LastObjectID = CreateDynamicObject(18266, 2099.2841796875, 1105.0977783203, 14.358480453491, 0, 0, 182);
    LastObjectID = CreateDynamicObject(17324, -2236.2685546875, 2290.5258789063, 3.747124671936, 0, 0, 270);
    LastObjectID = CreateDynamicObject(2932, -1658.5706787109, 448.62280273438, 7.4863376617432, 0, 0, 44);
    LastObjectID = CreateDynamicObject(2932, -1658.5703125, 448.6220703125, 10.311351776123, 0, 0, 43.994750976563);
    LastObjectID = CreateDynamicObject(7508, -1662.38671875, 454.0309753418, 9.9021339416504, 0, 0, 45);
    LastObjectID = CreateDynamicObject(5269, -1661.9705810547, 443.02114868164, 9.1887226104736, 0, 0, 44);
    LastObjectID = CreateDynamicObject(5269, -1667.5998535156, 448.8307800293, 9.2137222290039, 0, 0, 43.994750976563);
    LastObjectID = CreateDynamicObject(7508, -1662.439453125, 453.97680664063, 9.9021339416504, 0, 0, 44.994506835938);
    LastObjectID = CreateDynamicObject(5269, -1661.9523925781, 443.03857421875, 6.8887195587158, 0, 0, 44.244750976563);
    LastObjectID = CreateDynamicObject(5269, -1667.5935058594, 448.85809326172, 6.8887195587158, 0, 0, 44.241943359375);
    LastObjectID = CreateDynamicObject(7508, -1662.4227294922, 453.95794677734, 9.9021339416504, 0, 0, 44.994506835938);
    LastObjectID = CreateDynamicObject(5269, -1670.7332763672, 449.10299682617, 8.5137329101563, 0, 0, 44);
    LastObjectID = CreateDynamicObject(6056, -1648.7972412109, 436.47171020508, 11.775438308716, 0, 0, 315);
    LastObjectID = CreateDynamicObject(11435, -1646.1481933594, 431.54513549805, 5.9909300804138, 270.24945068359, 180.00933837891, 44.259155273438);
    LastObjectID = CreateDynamicObject(11435, -1644.1730957031, 433.82009887695, 5.9909300804138, 270.2470703125, 180.00549316406, 224.50842285156);
    LastObjectID = CreateDynamicObject(1445, -1665.4407958984, 439.91458129883, 6.8140606880188, 0, 0, 0);
    LastObjectID = CreateDynamicObject(2431, -1672.2374267578, 437.88720703125, 8.5400152206421, 0, 0, 48);
    LastObjectID = CreateDynamicObject(3174, -1672.4010009766, 439.12359619141, 6.2046856880188, 0, 0, 318);
    LastObjectID = CreateDynamicObject(13562, 1661.7943115234, -76.426780700684, 37.620166778564, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3534, 1661.8189697266, -76.344261169434, 36.141799926758, 0, 0, 0); 
    //frangao
    LastObjectID = CreateDynamicObject(8404, -599.66870117188, 473.89938354492, 1.8136328458786, 0, 0, 273.75);
    LastObjectID = CreateDynamicObject(8404, -559.77093505859, 476.52416992188, 1.8136328458786, 0, 0, 273.74633789063);
    LastObjectID = CreateDynamicObject(8404, -600.50610351563, 486.55114746094, 1.8136328458786, 0, 0, 93.746337890625);
    LastObjectID = CreateDynamicObject(8404, -560.59564208984, 489.19580078125, 1.8386328220367, 0, 0, 93.740844726563);
    LastObjectID = CreateDynamicObject(8404, -602.82055664063, 521.40710449219, 1.7636328935623, 0, 0, 93.740844726563);
    LastObjectID = CreateDynamicObject(8404, -562.90295410156, 524.02069091797, 1.7386329174042, 0, 0, 93.740844726563);
    LastObjectID = CreateDynamicObject(8404, -601.0625, 494.02972412109, 1.7886328697205, 0, 0, 93.740844726563);
    LastObjectID = CreateDynamicObject(8404, -561.07684326172, 495.30914306641, 1.7886328697205, 0, 0, 93.740844726563);
    LastObjectID = CreateDynamicObject(8649, -616.99560546875, 437.51000976563, 2.6666390895844, 0, 0, 4);
    LastObjectID = CreateDynamicObject(8649, -619.07763671875, 467.13275146484, 2.6666390895844, 0, 0, 3.9990234375);
    LastObjectID = CreateDynamicObject(8649, -621.17022705078, 496.75662231445, 2.6666390895844, 0, 0, 3.9990234375);
    LastObjectID = CreateDynamicObject(8649, -623.25720214844, 526.39465332031, 2.6666390895844, 0, 0, 3.9990234375);
    LastObjectID = CreateDynamicObject(8649, -625.30743408203, 556.01220703125, 2.6666390895844, 0, 0, 3.7490234375);
    LastObjectID = CreateDynamicObject(8649, -611.62847900391, 570.90655517578, 2.6666390895844, 0, 0, 273.49633789063);
    LastObjectID = CreateDynamicObject(8649, -545.52630615234, 560.40753173828, 2.6416389942169, 0, 0, 183.49365234375);
    LastObjectID = CreateDynamicObject(8649, -543.69482421875, 530.78021240234, 2.6416389942169, 0, 0, 183.49365234375);
    LastObjectID = CreateDynamicObject(8649, -539.38543701172, 471.89785766602, 2.6416389942169, 0, 0, 183.49365234375);
    LastObjectID = CreateDynamicObject(8649, -537.55090332031, 442.24685668945, 2.6416389942169, 0, 0, 183.49365234375);
    LastObjectID = CreateDynamicObject(8649, -551.28082275391, 426.78201293945, 2.6416389942169, 0, 0, 93.49365234375);
    LastObjectID = CreateDynamicObject(8649, -560.32305908203, 426.2350769043, 2.6166388988495, 0, 0, 273.48815917969);
    LastObjectID = CreateDynamicObject(7922, -604.97528076172, 423.51315307617, 2.6503844261169, 0, 0, 2);
    LastObjectID = CreateDynamicObject(7922, -607.322265625, 423.40008544922, 2.6503844261169, 0, 0, 1.99951171875);
    LastObjectID = CreateDynamicObject(7922, -609.67059326172, 423.3117980957, 2.6503844261169, 0, 0, 1.99951171875);
    LastObjectID = CreateDynamicObject(7922, -612.01885986328, 423.22402954102, 2.6503844261169, 0, 0, 1.99951171875);
    LastObjectID = CreateDynamicObject(7922, -614.36694335938, 423.16088867188, 2.6503844261169, 0, 0, 1.99951171875);
    LastObjectID = CreateDynamicObject(7922, -604.974609375, 423.5126953125, 2.6503844261169, 0, 0, 181.49951171875);
    LastObjectID = CreateDynamicObject(7922, -607.29736328125, 423.39422607422, 2.6503844261169, 0, 0, 181.494140625);
    LastObjectID = CreateDynamicObject(7922, -609.646484375, 423.27517700195, 2.6503844261169, 0, 0, 181.494140625);
    LastObjectID = CreateDynamicObject(7922, -611.99780273438, 423.18139648438, 2.6503844261169, 0, 0, 181.494140625);
    LastObjectID = CreateDynamicObject(7922, -614.32110595703, 423.11227416992, 2.6503844261169, 0, 0, 181.494140625);
    LastObjectID = CreateDynamicObject(16012, -567.68334960938, 570.41058349609, 1.6999975442886, 0, 0, 183.5);
    LastObjectID = CreateDynamicObject(8649, -601.30352783203, 571.54229736328, 2.6666390895844, 0, 0, 273.49365234375);
    LastObjectID = CreateDynamicObject(8535, -624.68835449219, 535.89184570313, 8.0420637130737, 0, 0, 184);
    LastObjectID = CreateDynamicObject(10032, -601.90307617188, 457.93466186523, 1.5504810810089, 358, 0, 274);
    LastObjectID = CreateDynamicObject(10032, -603.58599853516, 480.84643554688, 1.5504810810089, 357.99499511719, 0, 273.9990234375);
    LastObjectID = CreateDynamicObject(7522, -590.50085449219, 418.26651000977, 5.209370136261, 0, 0, 3.9990234375);
    LastObjectID = CreateDynamicObject(3096, -565.98034667969, 507.65481567383, 10.347405433655, 0, 0, 274);
    LastObjectID = CreateDynamicObject(2780, -600.99621582031, 305.69729614258, 0.56050634384155, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3461, -572.03289794922, 363.08486938477, 10.530466079712, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3528, -609.87683105469, 536.48974609375, 13.954574584961, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -547.20263671875, 482.35015869141, 23.512212753296, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -569.30883789063, 272.32592773438, 9.63720703125, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -537.02374267578, 284.5771484375, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -539.59765625, 284.50579833984, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -542.14611816406, 284.45043945313, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -544.76904296875, 284.36108398438, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -544.7685546875, 284.3603515625, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -537.06512451172, 290.6799621582, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -540.1865234375, 290.54248046875, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -543.18505859375, 290.44897460938, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -546.68286132813, 290.33972167969, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -552.32897949219, 291.4521484375, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -549.60931396484, 290.73590087891, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -554.87042236328, 293.05645751953, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -557.30609130859, 295.048828125, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -559.72076416016, 297.55725097656, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -563.04205322266, 300.48834228516, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -565.91033935547, 303.20831298828, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -568.88677978516, 306.64099121094, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -581.77490234375, 305.22723388672, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -579.96081542969, 302.30841064453, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -583.17913818359, 302.11212158203, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -581.58129882813, 300.71832275391, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -593.99743652344, 302.89935302734, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -594.7724609375, 298.97412109375, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -596.57727050781, 294.99789428711, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -598.28503417969, 291.51187133789, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -600.82763671875, 288.95617675781, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -603.37060546875, 286.40051269531, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -606.1103515625, 284.13858032227, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -609.45135498047, 283.34515380859, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -612.40100097656, 282.60247802734, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -536.78649902344, 277.78942871094, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -539.05603027344, 277.61010742188, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -542.21734619141, 277.57312011719, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -545.05236816406, 277.5364074707, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -604.94787597656, 277.71731567383, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -603.78881835938, 271.32077026367, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -607.21832275391, 270.62316894531, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -608.37622070313, 277.01910400391, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -612.3115234375, 276.30615234375, 1.4622064828873, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3666, -611.15307617188, 269.90960693359, 1.4622064828873, 0, 0, 0);
    //Ponto Apoio frente fazenda, e frente minerio
    LastObjectID = CreateDynamicObject(14530, 2585.3759765625, -2262.013671875, 3.065322637558, 0, 0, 179.99450683594);
    LastObjectID = CreateDynamicObject(3089, 2585.5764160156, -2257.3093261719, 2.6130750179291, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3089, 2582.7312011719, -2273.9047851563, 2.7068250179291, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1808, 2577.9604492188, -2263.7241210938, 1.284072637558, 0, 0, 132);
    LastObjectID = CreateDynamicObject(2596, 2578.0048828125, -2257.8168945313, 4.4193735122681, 0, 0, 50);
    LastObjectID = CreateDynamicObject(14527, 2581.826171875, -2260.6745605469, 2.5664916038513, 0, 0, 0);
    LastObjectID = CreateDynamicObject(14391, 2592.119140625, -2260.6977539063, 2.2441575527191, 0, 0, 180.75);
    LastObjectID = CreateDynamicObject(11666, 2580.5310058594, -2261.9829101563, 2.9468123912811, 0, 0, 270);
    LastObjectID = CreateDynamicObject(2762, 2582.5744628906, -2260.9162597656, 1.6892601251602, 0, 0, 91.25);
    LastObjectID = CreateDynamicObject(2724, 2582.5466308594, -2259.4699707031, 1.8310751914978, 0, 0, 0);
    LastObjectID = CreateDynamicObject(2724, 2582.0478515625, -2262.4287109375, 1.8310751914978, 0, 0, 142);
    LastObjectID = CreateDynamicObject(3983, 838.052734375, 647.130859375, 12.770000457764, 0, 0, 103.99658203125);
    LastObjectID = CreateDynamicObject(3983, 843.0654296875, 601.2900390625, 12.770000457764, 0, 0, 283.99658203125);
    LastObjectID = CreateDynamicObject(978, 865.79467773438, 673.6953125, 11.496577262878, 0, 0, 74);
    LastObjectID = CreateDynamicObject(978, 869.20697021484, 682.17218017578, 11.496577262878, 0, 0, 61.998413085938);
    LastObjectID = CreateDynamicObject(978, 874.79187011719, 689.13818359375, 11.496577262878, 0, 0, 41.995849609375);
    LastObjectID = CreateDynamicObject(978, 882.11669921875, 694.3671875, 11.496577262878, 0, 0, 29.995239257813);
    LastObjectID = CreateDynamicObject(978, 865.7939453125, 673.6953125, 11.496577262878, 0, 0, 255.99841308594);
    LastObjectID = CreateDynamicObject(978, 869.2060546875, 682.171875, 11.496577262878, 0, 0, 241.99584960938);
    LastObjectID = CreateDynamicObject(978, 874.791015625, 689.1376953125, 11.496577262878, 0, 0, 221.98974609375);
    LastObjectID = CreateDynamicObject(978, 882.1162109375, 694.3671875, 11.496577262878, 0, 0, 209.98718261719);
    LastObjectID = CreateDynamicObject(7191, 874.8837890625, 610.05859375, 12.747971534729, 0, 0, 13.99658203125);
    LastObjectID = CreateDynamicObject(7191, 858.59375, 582.7158203125, 12.747971534729, 0, 0, 283.99658203125);
    LastObjectID = CreateDynamicObject(7191, 840.62475585938, 578.28881835938, 12.747971534729, 0, 0, 283.99658203125);
    LastObjectID = CreateDynamicObject(7191, 816.3486328125, 595.0859375, 12.747971534729, 0, 0, 185.99304199219);
    LastObjectID = CreateDynamicObject(7191, 806.22027587891, 638.36724853516, 12.747971534729, 0, 0, 193.99304199219);
    LastObjectID = CreateDynamicObject(7191, 806.2197265625, 638.3671875, 1.497971534729, 0, 0, 193.99108886719);
    LastObjectID = CreateDynamicObject(7191, 806.2197265625, 638.3671875, 8.997971534729, 0, 0, 193.99108886719);
    LastObjectID = CreateDynamicObject(7191, 806.2197265625, 638.3671875, 5.247971534729, 0, 0, 193.99108886719);
    LastObjectID = CreateDynamicObject(7191, 816.3486328125, 595.0859375, 1.497971534729, 0, 0, 185.99304199219);
    LastObjectID = CreateDynamicObject(7191, 825.49206542969, 620.22094726563, 8.247971534729, 0, 0, 103.99304199219);
    LastObjectID = CreateDynamicObject(7191, 809.12414550781, 592.99633789063, 8.997971534729, 0, 0, 193.99304199219);
    LastObjectID = CreateDynamicObject(7191, 840.6240234375, 578.2880859375, 0.997971534729, 0, 0, 283.99658203125);
    LastObjectID = CreateDynamicObject(7191, 840.6240234375, 578.2880859375, 4.747971534729, 0, 0, 283.99658203125);
    LastObjectID = CreateDynamicObject(7191, 840.6240234375, 578.2880859375, 8.747971534729, 0, 0, 283.99658203125);
    LastObjectID = CreateDynamicObject(7191, 858.59375, 582.7158203125, 1.247971534729, 0, 0, 283.99658203125);
    LastObjectID = CreateDynamicObject(7191, 858.59375, 582.7158203125, 4.997971534729, 0, 0, 283.99658203125);
    LastObjectID = CreateDynamicObject(7191, 858.59375, 582.7158203125, 8.997971534729, 0, 0, 283.99658203125);
    LastObjectID = CreateDynamicObject(7191, 874.8837890625, 610.05859375, 0.747971534729, 0, 0, 13.99658203125);
    LastObjectID = CreateDynamicObject(7191, 874.8837890625, 610.05859375, 4.747971534729, 0, 0, 13.99658203125);
    LastObjectID = CreateDynamicObject(7191, 874.8837890625, 610.05859375, 8.747971534729, 0, 0, 13.99658203125);
    LastObjectID = CreateDynamicObject(7191, 864.740234375, 650.525390625, 8.747971534729, 0, 0, 13.99658203125);
    LastObjectID = CreateDynamicObject(7191, 864.740234375, 650.525390625, 4.747971534729, 0, 0, 13.992065429688);
    LastObjectID = CreateDynamicObject(7191, 864.740234375, 650.525390625, 0.747971534729, 0, 0, 13.992065429688);
    LastObjectID = CreateDynamicObject(7191, 813.60400390625, 595.25915527344, 12.497971534729, 0, 0, 185.99304199219);
    LastObjectID = CreateDynamicObject(7504, 929.6142578125, 712.1494140625, 11.82750415802, 0, 0, 19.9951171875);
    LastObjectID = CreateDynamicObject(13296, 155.20330810547, 168.34701538086, 440.92614746094, 0, 0, 0);
    LastObjectID = CreateDynamicObject(7520, 830.01672363281, 597.02203369141, 10.746562957764, 0, 0, 104);
    LastObjectID = CreateDynamicObject(7520, 822.28802490234, 594.97052001953, 10.746562957764, 0, 0, 103.99658203125);
    LastObjectID = CreateDynamicObject(7191, 809.1240234375, 592.99609375, 5.247971534729, 0, 0, 193.99108886719);
    LastObjectID = CreateDynamicObject(7191, 809.1240234375, 592.99609375, 1.497971534729, 0, 0, 193.99108886719);
    LastObjectID = CreateDynamicObject(7191, 809.1240234375, 592.99609375, -2.252028465271, 0, 0, 191.99108886719);
    LastObjectID = CreateDynamicObject(7191, 825.4912109375, 620.220703125, 4.997971534729, 0, 0, 103.99108886719);
    LastObjectID = CreateDynamicObject(7191, 825.4912109375, 620.220703125, 0.997971534729, 0, 0, 103.99108886719);
    LastObjectID = CreateDynamicObject(8947, 824.77886962891, 586.99365234375, 13.602531433105, 0, 0, 194);
    LastObjectID = CreateDynamicObject(8947, 818.669921875, 585.66796875, 13.602531433105, 0, 0, 193.99108886719);
    LastObjectID = CreateDynamicObject(8947, 818.669921875, 585.66796875, 7.6025314331055, 0, 0, 193.99658203125);
    LastObjectID = CreateDynamicObject(8947, 818.669921875, 585.66796875, 2.1025314331055, 0, 0, 193.99658203125);
    LastObjectID = CreateDynamicObject(18452, 850.82385253906, 648.86199951172, 13.695293426514, 0, 0, 284);
    LastObjectID = CreateDynamicObject(3997, 18.41015625, 240.216796875, 1.25, 0, 0, 331.99035644531);
    LastObjectID = CreateDynamicObject(16668, 73.131942749023, 242.03660583496, 2, 0, 0, 152.75);
    LastObjectID = CreateDynamicObject(16668, -34.753486633301, 241.6467590332, 1.874999165535, 0, 0, 332.24841308594);
    LastObjectID = CreateDynamicObject(11091, -14.703687667847, 299.03305053711, 3.0637445449829, 0, 0, 61.75);
    LastObjectID = CreateDynamicObject(9482, 39.340793609619, 164.81909179688, 6.3802242279053, 0, 0, 60);
    LastObjectID = CreateDynamicObject(9339, 68.140289306641, 163.52214050293, 1.9490766525269, 0, 0, 332);
    LastObjectID = CreateDynamicObject(7615, -20.287109375, 195.5068359375, 3.6552400588989, 0, 0, 331.49597167969);
    LastObjectID = CreateDynamicObject(7615, -27.818359375, 199.478515625, 3.6552400588989, 0, 0, 331.49597167969);
    LastObjectID = CreateDynamicObject(7423, 7.8144760131836, 218.53944396973, 1.3686319589615, 0, 0, 241.75);
    LastObjectID = CreateDynamicObject(7418, -1222.6259765625, 33.7119140625, 13.348438262939, 0, 0, 135);
    LastObjectID = CreateDynamicObject(7191, 52.44021987915, 183.3249206543, 0.72467851638794, 0, 0, 61.75);
    LastObjectID = CreateDynamicObject(7191, 52.524875640869, 183.47695922852, 0.72467851638794, 0, 0, 61.995849609375);
    LastObjectID = CreateDynamicObject(7191, 52.597633361816, 183.60748291016, 0.72467851638794, 0, 0, 61.995849609375);
    LastObjectID = CreateDynamicObject(7191, 52.670806884766, 183.76593017578, 0.72467851638794, 0, 0, 61.995849609375);
    LastObjectID = CreateDynamicObject(7191, 52.754638671875, 183.94677734375, 0.72467851638794, 0, 0, 61.995849609375);
    LastObjectID = CreateDynamicObject(7615, 95.7685546875, 132.142578125, 3.6552400588989, 0, 0, 331.49597167969);
    LastObjectID = CreateDynamicObject(7615, 201.6404876709, 84.123115539551, 3.6552400588989, 0, 0, 339.49597167969);
    LastObjectID = CreateDynamicObject(9193, 17.238945007324, 174.81976318359, 6.5106735229492, 0, 0, 0);
    LastObjectID = CreateDynamicObject(16002, 21.7041015625, 136.193359375, 1.4296875, 0, 0, 231.99829101563);
    LastObjectID = CreateDynamicObject(10838, 4.7103514671326, 212.77200317383, 18.802410125732, 0, 0, 62);
    LastObjectID = CreateDynamicObject(10837, 96.23127746582, 105.23368835449, 5.7594513893127, 0, 0, 142);
    LastObjectID = CreateDynamicObject(10281, 20.505311965942, 136.50332641602, 5.4189434051514, 0, 346, 232);
    LastObjectID = CreateDynamicObject(10281, 22.407342910767, 135.21002197266, 5.4189434051514, 0, 345.99792480469, 51.998291015625);
    LastObjectID = CreateDynamicObject(10236, -14.254653930664, 223.02874755859, 12.788612365723, 0, 0, 330);
    LastObjectID = CreateDynamicObject(8294, -24.010995864868, 306.09765625, 2.2060089111328, 0, 0, 332);
    LastObjectID = CreateDynamicObject(7306, 94.291030883789, 213.84880065918, 4.1378726959229, 0, 0, 287);
    LastObjectID = CreateDynamicObject(7304, 41.966484069824, 293.98040771484, 4.5632309913635, 0, 0, 62.25);
    LastObjectID = CreateDynamicObject(6958, -55.009536743164, 244.5325012207, 10.146564483643, 0, 0, 60);
    LastObjectID = CreateDynamicObject(3554, -45.666679382324, 238.47308349609, -3.728443145752, 0, 0, 152);
    LastObjectID = CreateDynamicObject(3554, -60.728675842285, 246.51028442383, -3.728443145752, 0, 0, 151.99584960938);
    LastObjectID = CreateDynamicObject(2714, 34.315185546875, 167.23170471191, 3.9569787979126, 0, 0, 330);
    LastObjectID = CreateDynamicObject(2714, 43.929485321045, 161.72718811035, 3.9569787979126, 0, 0, 329.99633789063);
    LastObjectID = CreateDynamicObject(8839, 159.7882232666, -2796.6064453125, 44.674808502197, 0, 0, 164.75);
    LastObjectID = CreateDynamicObject(18237, 93.022026062012, 246.34385681152, 1.4035258293152, 0, 0, 279.5);
    LastObjectID = CreateDynamicObject(3089, 85.588859558105, 247.23355102539, 2.5153398513794, 0, 0, 333);
    LastObjectID = CreateDynamicObject(16098, -34.644309997559, 283.39016723633, 6.2385358810425, 0, 0, 330);
    LastObjectID = CreateDynamicObject(9131, -21.472587585449, 300.58096313477, 1.2039157152176, 80, 0, 241);
    LastObjectID = CreateDynamicObject(9131, -25.861404418945, 305.96493530273, 1.8039155006409, 90, 180, 60.996124267578);
    LastObjectID = CreateDynamicObject(9131, -26.999433517456, 303.69094848633, 1.8039155006409, 90, 180.00549316406, 60.979644775391);
    LastObjectID = CreateDynamicObject(9131, -28.96854019165, 304.78289794922, 1.8039155006409, 90, 179.99450683594, 61.240600585938);
    LastObjectID = CreateDynamicObject(9131, -27.821678161621, 307.04321289063, 1.8039155006409, 90, 180.00549316406, 60.979644775391);
    LastObjectID = CreateDynamicObject(9131, -29.792524337769, 308.12802124023, 1.8039155006409, 90, 180.00549316406, 60.979614257813);
    LastObjectID = CreateDynamicObject(9131, -30.962589263916, 305.87628173828, 1.8039155006409, 90, 179.99450683594, 61.23779296875);
    LastObjectID = CreateDynamicObject(9131, -23.3873462677, 301.6598815918, 1.6039153337479, 79.996948242188, 0, 240.99609375);
    LastObjectID = CreateDynamicObject(9131, -25.254173278809, 302.71011352539, 1.8039155006409, 90, 180.00549316406, 60.979644775391);
    LastObjectID = CreateDynamicObject(9131, -19.524362564087, 299.5244140625, 0.77891612052917, 79.996948242188, 0, 240.99609375);
    LastObjectID = CreateDynamicObject(9131, -23.910400390625, 304.87265014648, 1.8039155006409, 90, 179.99450683594, 60.990600585938);
    LastObjectID = CreateDynamicObject(9131, -22.099678039551, 303.88998413086, 1.6039153337479, 79.996948242188, 0, 240.99609375);
    LastObjectID = CreateDynamicObject(9131, -20.201301574707, 302.84802246094, 1.2039157152176, 79.996948242188, 0, 240.99609375);
    LastObjectID = CreateDynamicObject(9131, -18.275249481201, 301.80648803711, 0.77891612052917, 79.996948242188, 0, 240.99609375);
    LastObjectID = CreateDynamicObject(14826, -36.421417236328, 294.52655029297, 2.014378786087, 0, 0, 0);
    LastObjectID = CreateDynamicObject(17055, -33.885757446289, 301.45739746094, 3.5921740531921, 0, 0, 243.25);
    LastObjectID = CreateDynamicObject(929, -48.98104095459, 263.12161254883, 2.70339012146, 0, 0, 332);
    LastObjectID = CreateDynamicObject(920, -49.807521820068, 261.03274536133, 2.1348087787628, 0, 0, 60.5);
    LastObjectID = CreateDynamicObject(958, -50.291576385498, 265.16763305664, 2.6191458702087, 0, 0, 332);
    LastObjectID = CreateDynamicObject(959, -50.34627532959, 265.18643188477, 2.6082668304443, 0, 0, 332.25);
    LastObjectID = CreateDynamicObject(1689, -49.039180755615, 267.65924072266, 2.4608788490295, 0, 0, 332);
    LastObjectID = CreateDynamicObject(1689, -45.556610107422, 273.47009277344, 2.4608788490295, 0, 0, 147.99584960938);
    LastObjectID = CreateDynamicObject(1691, -50.873611450195, 272.64114379883, 0.84632301330566, 0, 0, 330);
    LastObjectID = CreateDynamicObject(1691, -47.633201599121, 270.82638549805, 0.84632277488708, 0, 0, 329.99633789063);
    LastObjectID = CreateDynamicObject(1691, -44.840679168701, 269.15939331055, 0.84632277488708, 0, 0, 329.99633789063);
    LastObjectID = CreateDynamicObject(3287, -46.130340576172, 277.76794433594, 4.0890393257141, 0, 0, 62);
    LastObjectID = CreateDynamicObject(1348, -46.180614471436, 263.99130249023, 1.9525265693665, 0, 0, 61);
    LastObjectID = CreateDynamicObject(6450, 75.784599304199, -2769.4094238281, 31.818206787109, 0, 0, 254.75);
    LastObjectID = CreateDynamicObject(8832, 35.076080322266, 155.46527099609, -2.0091519355774, 0, 0, 60.75);
    LastObjectID = CreateDynamicObject(7615, 84.65966796875, 135.10166931152, 2.2802395820618, 0, 0, 331.49597167969);
    LastObjectID = CreateDynamicObject(1676, -27.321063995361, 301.47146606445, 2.8308668136597, 0, 0, 328);
    LastObjectID = CreateDynamicObject(2707, 21.189249038696, 137.92231750488, 5.5830063819885, 0, 91.999969482422, 321.25003051758);
    LastObjectID = CreateDynamicObject(2707, 19.296394348145, 135.49584960938, 5.5580062866211, 0, 91.999481201172, 321.24572753906);
    LastObjectID = CreateDynamicObject(6300, 181.98358154297, -2777.7036132813, 31.820819854736, 0, 0, 75.25);
    LastObjectID = CreateDynamicObject(6300, 198.05694580078, -2787.6740722656, 31.820190429688, 0, 0, 344.75);
    LastObjectID = CreateDynamicObject(6450, 151.25688171387, -2794.9111328125, 31.641426086426, 0, 0, 74.75);
    LastObjectID = CreateDynamicObject(6300, 207.85841369629, -2790.330078125, 31.820190429688, 0, 0, 344.74548339844);
    LastObjectID = CreateDynamicObject(3578, 151.47166442871, -2815.474609375, 40.474147796631, 0, 0, 345);
    LastObjectID = CreateDynamicObject(3578, 161.25735473633, -2818.1091308594, 40.474147796631, 0, 0, 344.99816894531);
    LastObjectID = CreateDynamicObject(3578, 163.26480102539, -2818.6408691406, 40.474147796631, 0, 0, 344.99816894531);
    LastObjectID = CreateDynamicObject(3578, 203.88342285156, -2829.3576660156, 40.474147796631, 0, 0, 344.99816894531);
    LastObjectID = CreateDynamicObject(3578, 213.86663818359, -2831.9924316406, 40.474147796631, 0, 0, 344.99816894531);
    LastObjectID = CreateDynamicObject(8038, 191.52952575684, -2770.1105957031, 59.990787506104, 0, 0, 74.5);
    LastObjectID = CreateDynamicObject(3578, 225.79748535156, -2789.9191894531, 39.874111175537, 0, 0, 296.99816894531);
    LastObjectID = CreateDynamicObject(16409, 1348.2048339844, 947.3798828125, 9.7453136444092, 0, 0, 350.75);
    //Aeroporto e Ponto Apoio lado Chuckup   e casas da montanha
    LastObjectID = CreateDynamicObject(9192, 1225.8026123047, 985.07238769531, 10.400408744812, 0, 0, 288);
    LastObjectID = CreateDynamicObject(7313, 1340.6789550781, 947.62255859375, 13.34531211853, 0, 0, 260.75);
    LastObjectID = CreateDynamicObject(7290, 1341.41796875, 945.1416015625, 4.7896122932434, 0, 0, 350);
    LastObjectID = CreateDynamicObject(7290, 1342.1707763672, 949.62493896484, 4.7896122932434, 0, 0, 349.99694824219);
    LastObjectID = CreateDynamicObject(7290, 1341.8619384766, 947.6728515625, 4.7896122932434, 0, 0, 349.99694824219);
    LastObjectID = CreateDynamicObject(2728, 1340.2062988281, 942.3505859375, 11.3203125, 0, 270, 350.74987792969);
    LastObjectID = CreateDynamicObject(2728, 1341.8970947266, 952.69036865234, 11.3203125, 0, 270, 350.74951171875);
    LastObjectID = CreateDynamicObject(11435, 1226.2741699219, 985.18627929688, 10.637349128723, 0, 0, 18);
    LastObjectID = CreateDynamicObject(11500, 1244.6960449219, 997.60919189453, 6.1859817504883, 0, 0, 0);
    LastObjectID = CreateDynamicObject(9527, 1244.7078857422, 997.43719482422, 13.788460731506, 0, 0, 0);
    LastObjectID = CreateDynamicObject(10236, 1244.9156494141, 1081.8468017578, 34.757362365723, 0, 0, 324);
    LastObjectID = CreateDynamicObject(10271, 1286.7098388672, 1001.5084838867, -7.3062925338745, 0, 90, 358.75);
    LastObjectID = CreateDynamicObject(10281, 1337.4102783203, 948.35748291016, 16.611125946045, 0, 344, 254.25);
    LastObjectID = CreateDynamicObject(10837, 1276.9155273438, 925.98278808594, 10.537673950195, 0, 0, 101);
    LastObjectID = CreateDynamicObject(4199, 1342.0994873047, 973.62738037109, 11.932789802551, 0, 0, 193.25);
    LastObjectID = CreateDynamicObject(5409, 1279.0260009766, 1008.7241821289, 14.32578086853, 0, 0, 268);
    LastObjectID = CreateDynamicObject(11392, 1348.5659179688, 943.06884765625, 9.8203125, 0, 0, 80);
    LastObjectID = CreateDynamicObject(11480, 1341.4108886719, 936.42401123047, 12.0140209198, 0, 0, 334);
    LastObjectID = CreateDynamicObject(11480, 1339.6867675781, 932.91461181641, 12.0140209198, 0, 0, 333.99536132813);
    LastObjectID = CreateDynamicObject(14826, 1347.0202636719, 941.86212158203, 11.014024734497, 0, 0, 342);
    LastObjectID = CreateDynamicObject(3096, 1353.5386962891, 945.14538574219, 11.633007049561, 0, 0, 80.25);
    LastObjectID = CreateDynamicObject(1676, 1275.8637695313, 986.00787353516, 11.57071018219, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1676, 1280.0573730469, 986.08984375, 11.57071018219, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1676, 1283.0773925781, 985.841796875, 11.57071018219, 0, 0, 0);
    LastObjectID = CreateDynamicObject(1676, 1287.3170166016, 985.65997314453, 11.57071018219, 0, 0, 0);
    LastObjectID = CreateDynamicObject(2780, 1279.1159667969, 1016.5081787109, 9.3203125, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3426, 658.53051757813, 275.08905029297, 18.835004806519, 0, 0, 276);
    LastObjectID = CreateDynamicObject(3877, 1273.1303710938, 986.07342529297, 11.493673324585, 0, 0, 0);
    LastObjectID = CreateDynamicObject(7073, 1249.8349609375, 1077.4561767578, 25.433206558228, 0, 0, 38);
    LastObjectID = CreateDynamicObject(8240, 28.228515625, 2418.681640625, 34.107597351074, 0, 0, 0);
    LastObjectID = CreateDynamicObject(8171, 153.0390625, 2502.9697265625, 15.80421257019, 0, 0, 90.247192382813);
    LastObjectID = CreateDynamicObject(8172, 3.3048737049103, 2502.6418457031, 15.814548492432, 0, 0, 270);
    LastObjectID = CreateDynamicObject(8171, 291.28125, 2503.583984375, 15.80421257019, 0, 0, 90.247192382813);
    LastObjectID = CreateDynamicObject(8171, 429.40405273438, 2504.1787109375, 15.80421257019, 0, 0, 90.247192382813);
    LastObjectID = CreateDynamicObject(10766, 30.456777572632, 2495.83984375, 11.991701126099, 351, 0, 359.53308105469);
    LastObjectID = CreateDynamicObject(8038, 20.70189666748, 2408.583984375, 31.635526657104, 0, 0, 0);
    LastObjectID = CreateDynamicObject(8038, 0.022127268835902, 2408.599609375, 31.635614395142, 0, 0, 0);
    LastObjectID = CreateDynamicObject(8038, 47.700775146484, 2408.5205078125, 31.63565826416, 0, 0, 359.5);
    LastObjectID = CreateDynamicObject(3987, 47.916542053223, 2432.462890625, 13.287544250488, 0, 180, 0);
    LastObjectID = CreateDynamicObject(3987, 47.947395324707, 2403.939453125, 13.287544250488, 0, 179.99450683594, 0);
    LastObjectID = CreateDynamicObject(3987, 5.9869651794434, 2406.4243164063, 13.287544250488, 0, 179.99450683594, 270);
    LastObjectID = CreateDynamicObject(3987, 6.0106382369995, 2429.8781738281, 13.287544250488, 0, 179.99450683594, 270);
    LastObjectID = CreateDynamicObject(3987, 46.895671844482, 2432.92578125, 13.287544250488, 0, 179.99450683594, 178.75);
    LastObjectID = CreateDynamicObject(3987, 8.5405941009521, 2432.4223632813, 13.287544250488, 0, 179.99450683594, 179.99755859375);
    LastObjectID = CreateDynamicObject(3096, 32.814147949219, 2404.6489257813, 22.343782424927, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3096, 36.973293304443, 2404.6884765625, 22.374532699585, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3426, 107.44275665283, 2451.8483886719, 15.164358139038, 0, 0, 340);
    LastObjectID = CreateDynamicObject(3515, 110.55871582031, 2461.349609375, 14.350940704346, 0, 0, 0);
    LastObjectID = CreateDynamicObject(3877, 436.10772705078, 2523.8723144531, 15.394985198975, 0, 0, 1.5);
    LastObjectID = CreateDynamicObject(3877, 436.36651611328, 2520.67578125, 15.394985198975, 0, 0, 1);
    LastObjectID = CreateDynamicObject(3877, 436.63589477539, 2517.205078125, 15.394985198975, 0, 0, 0.999755859375);
    LastObjectID = CreateDynamicObject(3877, 436.91622924805, 2513.95703125, 15.394985198975, 0, 0, 0.999755859375);
    LastObjectID = CreateDynamicObject(3877, 437.21780395508, 2510.6779785156, 15.394985198975, 0, 0, 0.999755859375);
    LastObjectID = CreateDynamicObject(3877, 437.44293212891, 2507.1752929688, 15.394985198975, 0, 0, 0.999755859375);
    LastObjectID = CreateDynamicObject(3877, 437.36785888672, 2503.69921875, 15.394985198975, 0, 0, 0.999755859375);
    LastObjectID = CreateDynamicObject(3877, 437.33837890625, 2499.6235351563, 15.394985198975, 0, 0, 0.999755859375);
    LastObjectID = CreateDynamicObject(3877, 437.31158447266, 2495.9248046875, 15.394985198975, 0, 0, 0.999755859375);
    LastObjectID = CreateDynamicObject(3877, 437.283203125, 2491.9248046875, 15.394985198975, 0, 0, 0.999755859375);
    LastObjectID = CreateDynamicObject(3877, 437.25842285156, 2488.4248046875, 15.394985198975, 0, 0, 0.999755859375);
    LastObjectID = CreateDynamicObject(3877, 437.23126220703, 2484.6748046875, 15.394985198975, 0, 0, 0.999755859375);
    LastObjectID = CreateDynamicObject(8678, -2136.6254882813, 1376.306640625, 7.3189735412598, 0, 0, 180);
    LastObjectID = CreateDynamicObject(16061, -10.83111000061, 2542.7338867188, 15.484375, 0, 0, 270);
    LastObjectID = CreateDynamicObject(16061, 56.538597106934, 2542.0639648438, 15.484375, 0, 0, 270);
    LastObjectID = CreateDynamicObject(16061, 122.31860351563, 2541.6772460938, 15.484375, 0, 0, 270);
    LastObjectID = CreateDynamicObject(16061, 189.55909729004, 2541.6950683594, 15.484375, 0, 0, 270);
    LastObjectID = CreateDynamicObject(3308, -790.689453125, 2463.798828125, 157.10565185547, 0, 0, 276);
    LastObjectID = CreateDynamicObject(3309, -819.87548828125, 2450.4272460938, 157.37817382813, 0, 0, 316);
    LastObjectID = CreateDynamicObject(3310, -761.25262451172, 2452.818359375, 157.97061157227, 0, 0, 42);
    LastObjectID = CreateDynamicObject(3313, -748.33648681641, 2424.6127929688, 158.80006408691, 0, 0, 276);
    LastObjectID = CreateDynamicObject(3314, -749.10491943359, 2391.6108398438, 156.65859985352, 0, 0, 226);
    LastObjectID = CreateDynamicObject(1337, -716.39453125, 2399.8671875, 127.53034973145, 0, 0, 0);
    LastObjectID = CreateDynamicObject(16097, -750.38885498047, 2360.3122558594, 88.088043212891, 0, 0, 0);
    LastObjectID = CreateDynamicObject(16097, -772.43786621094, 2344.1704101563, 88.088043212891, 0, 0, 298);
    LastObjectID = CreateDynamicObject(16097, -770.78955078125, 2369.677734375, 88.088043212891, 0, 0, 297.99868774414);
    LastObjectID = CreateDynamicObject(16097, -770.46557617188, 2390.2021484375, 88.088043212891, 0, 0, 297.99868774414);
    LastObjectID = CreateDynamicObject(16097, -781.4140625, 2409.5578613281, 88.088043212891, 0, 0, 297.99868774414);
    LastObjectID = CreateDynamicObject(16097, -798.00213623047, 2418.8005371094, 88.088043212891, 0, 0, 297.99868774414);
    LastObjectID = CreateDynamicObject(16097, -811.03070068359, 2424.4790039063, 88.088043212891, 0, 0, 297.99868774414);
    LastObjectID = CreateDynamicObject(16097, -831.11181640625, 2404.1557617188, 88.088043212891, 0, 0, 297.99865722656);
    LastObjectID = CreateDynamicObject(16161, -703.33752441406, 2362.9736328125, 35.922775268555, 0, 175.99993896484, 43.999908447266);
    
     //===================================================CONDOMÍNIO=======================================
    LastObjectID = CreateDynamicObject(6956,867.646,-2147.779,11.902,0.0,0.0,-90.000);
	LastObjectID = CreateDynamicObject(6956,774.461,-2147.715,11.900,0.0,0.0,-270.000);
	LastObjectID = CreateDynamicObject(3306,904.489,-2101.034,13.406,0.0,0.0,90.000);
	LastObjectID = CreateDynamicObject(3307,879.618,-2100.990,14.201,0.0,3.438,90.000);
	LastObjectID = CreateDynamicObject(3308,856.199,-2101.004,14.015,0.0,2.578,90.000);
	LastObjectID = CreateDynamicObject(3309,831.224,-2100.937,13.395,0.0,0.0,90.000);
	LastObjectID = CreateDynamicObject(3310,805.753,-2100.133,14.004,0.0,0.0,-90.000);
	LastObjectID = CreateDynamicObject(3311,780.723,-2100.112,14.873,0.0,0.0,-180.000);
	LastObjectID = CreateDynamicObject(3312,755.768,-2100.081,14.897,0.0,0.0,-90.000);
	LastObjectID = CreateDynamicObject(3314,898.499,-2134.094,12.934,0.0,0.0,-270.000);
	LastObjectID = CreateDynamicObject(3315,847.271,-2136.270,13.032,0.0,0.0,0.0);
	LastObjectID = CreateDynamicObject(3316,899.004,-2182.998,15.404,0.0,0.0,90.000);
	LastObjectID = CreateDynamicObject(3317,867.591,-2189.127,15.296,0.0,0.0,0.0);
	LastObjectID = CreateDynamicObject(3351,842.545,-2189.064,15.276,0.0,0.0,0.0);
	LastObjectID = CreateDynamicObject(3353,821.558,-2188.610,12.931,0.0,0.0,0.0);
	LastObjectID = CreateDynamicObject(3442,787.542,-2190.163,16.174,0.0,0.0,0.0);
	LastObjectID = CreateDynamicObject(3444,758.280,-2192.720,14.492,0.0,0.0,-270.000);
	LastObjectID = CreateDynamicObject(3486,741.359,-2157.972,19.169,0.859,0.0,-90.000);
	LastObjectID = CreateDynamicObject(3487,734.914,-2190.625,18.589,0.0,0.0,0.0);
	LastObjectID = CreateDynamicObject(7929,734.778,-2104.807,18.592,0.0,0.0,-180.000);
	LastObjectID = CreateDynamicObject(7929,741.350,-2132.374,18.566,0.0,0.0,-90.000);
	LastObjectID = CreateDynamicObject(3749,836.478,-2065.870,17.726,0.0,0.0,0.0);
	LastObjectID = CreateDynamicObject(985,849.460,-2067.909,13.689,0.0,0.0,0.0);
	LastObjectID = CreateDynamicObject(986,823.506,-2067.915,13.689,0.0,0.0,0.0);
	LastObjectID = CreateDynamicObject(10766,825.720,-2095.678,2.978,0.0,13.751,-90.000);
	LastObjectID = CreateDynamicObject(10766,816.674,-2095.368,2.973,0.0,-13.751,-270.000);
	LastObjectID = CreateDynamicObject(10766,731.941,-2115.472,3.218,0.0,-13.751,-540.000);
	LastObjectID = CreateDynamicObject(10766,816.773,-2199.530,4.252,0.0,11.173,-990.000);
	LastObjectID = CreateDynamicObject(10766,825.084,-2199.850,4.202,0.0,-11.173,-1170.000);
	LastObjectID = CreateDynamicObject(10766,909.702,-2180.649,4.224,0.0,-11.173,-1080.000);
	LastObjectID = CreateDynamicObject(1507,817.734,-2193.395,13.610,0.0,0.0,0.0);
	LastObjectID = CreateDynamicObject(8417,917.056,-2206.555,11.445,180.482,-0.859,-181.100);
	LastObjectID = CreateDynamicObject(8417,916.991,-2087.991,11.651,179.622,0.0,-180.241);
	LastObjectID = CreateDynamicObject(8417,725.530,-2088.547,11.680,179.622,0.0,-450.241);
	LastObjectID = CreateDynamicObject(8417,725.242,-2207.776,11.519,179.622,-0.859,-360.241);
	LastObjectID = CreateDynamicObject(10766,732.257,-2179.785,3.171,0.0,13.751,0.0);
	LastObjectID = CreateDynamicObject(10766,909.273,-2115.042,2.661,0.0,13.751,-180.000);
	LastObjectID = CreateDynamicObject(4871,832.252,-2160.680,11.978,0.0,0.0,0.0);
	LastObjectID = CreateDynamicObject(3308,867.079,-2142.322,13.460,0.0,0.0,-90.000);
	LastObjectID = CreateDynamicObject(3351,818.169,-2136.728,15.404,0.0,0.0,0.0);
	LastObjectID = CreateDynamicObject(9241,789.783,-2139.406,13.848,0.0,0.0,90.000);
	LastObjectID = CreateDynamicObject(3487,766.753,-2138.106,18.739,0.0,0.0,0.0);
	LastObjectID = CreateDynamicObject(973,759.132,-2165.602,12.882,0.0,0.0,-90.000);
	LastObjectID = CreateDynamicObject(982,789.555,-2155.284,12.747,0.0,0.0,-90.000);
	LastObjectID = CreateDynamicObject(982,792.895,-2123.450,12.804,0.0,0.0,-90.000);
	LastObjectID = CreateDynamicObject(983,780.072,-2123.442,12.804,0.0,0.0,-90.000);
	LastObjectID = CreateDynamicObject(8417,745.020,-2190.274,11.477,178.763,0.0,-180.241);
	LastObjectID = CreateDynamicObject(8417,784.618,-2190.371,11.585,178.763,0.0,-180.241);
	LastObjectID = CreateDynamicObject(8417,799.466,-2132.337,11.736,178.763,0.0,-180.241);
	LastObjectID = CreateDynamicObject(8417,758.880,-2132.805,11.723,179.622,0.859,-270.241);
	LastObjectID = CreateDynamicObject(8417,838.609,-2115.053,12.150,179.622,0.859,-270.241);
	LastObjectID = CreateDynamicObject(8417,860.322,-2105.944,12.284,179.622,-1.719,-270.241);
	LastObjectID = CreateDynamicObject(8417,900.761,-2188.052,11.775,179.622,0.0,-360.241);
	LastObjectID = CreateDynamicObject(973,759.266,-2160.013,12.954,0.0,0.0,-90.000);
	LastObjectID = CreateDynamicObject(8659,790.310,-2170.485,12.914,0.0,0.0,-180.000);
	LastObjectID = CreateDynamicObject(8659,773.265,-2170.490,12.914,0.0,0.0,-180.000);
	LastObjectID = CreateDynamicObject(8657,937.066,-2211.557,12.702,0.0,0.0,-180.000);
	LastObjectID = CreateDynamicObject(8657,937.063,-2181.750,12.692,0.0,0.0,-180.000);
	LastObjectID = CreateDynamicObject(8657,937.047,-2150.736,12.685,0.0,0.0,-180.000);
	LastObjectID = CreateDynamicObject(8657,937.021,-2119.715,12.684,0.0,0.0,-180.000);
	LastObjectID = CreateDynamicObject(8657,937.021,-2088.721,12.687,0.0,0.0,-180.000);
	LastObjectID = CreateDynamicObject(8657,937.026,-2084.332,12.691,0.0,0.0,-180.000);
	LastObjectID = CreateDynamicObject(8657,922.034,-2068.300,12.752,0.0,0.0,-270.000);
	LastObjectID = CreateDynamicObject(8657,891.044,-2068.322,12.802,0.0,0.0,-270.000);
	LastObjectID = CreateDynamicObject(8657,811.326,-2068.228,12.827,0.0,0.0,-270.000);
	LastObjectID = CreateDynamicObject(986,819.527,-2063.937,13.703,0.0,0.0,-90.000);
	LastObjectID = CreateDynamicObject(985,853.114,-2064.219,13.703,0.0,0.0,90.000);
	LastObjectID = CreateDynamicObject(8657,780.403,-2068.247,12.850,0.0,0.0,-270.000);
	LastObjectID = CreateDynamicObject(8657,749.423,-2068.242,12.850,0.0,0.0,-270.000);
	LastObjectID = CreateDynamicObject(8657,719.992,-2068.249,12.859,0.0,0.0,-270.000);
	LastObjectID = CreateDynamicObject(8657,704.988,-2083.578,12.844,0.0,0.0,-360.000);
	LastObjectID = CreateDynamicObject(8657,705.001,-2114.115,12.840,0.0,0.0,-360.000);
	LastObjectID = CreateDynamicObject(8657,704.989,-2145.123,12.829,0.0,0.0,-360.000);
	LastObjectID = CreateDynamicObject(8657,704.984,-2176.107,12.807,0.0,0.0,-360.000);
	LastObjectID = CreateDynamicObject(8657,704.981,-2207.151,12.809,0.0,0.0,-360.000);
	LastObjectID = CreateDynamicObject(8657,704.988,-2212.156,12.807,0.0,0.0,-360.000);
	LastObjectID = CreateDynamicObject(8657,720.688,-2227.057,12.784,0.0,0.0,-270.000);
	LastObjectID = CreateDynamicObject(8657,751.679,-2227.051,12.775,0.0,0.0,-270.000);
	LastObjectID = CreateDynamicObject(8657,782.484,-2227.053,12.775,0.0,0.0,-270.000);
	LastObjectID = CreateDynamicObject(8657,813.509,-2227.059,12.775,0.0,0.0,-270.000);
	LastObjectID = CreateDynamicObject(8657,843.946,-2227.052,12.750,0.0,0.0,-270.000);
	LastObjectID = CreateDynamicObject(8657,874.387,-2227.048,12.727,0.0,0.0,-270.000);
	LastObjectID = CreateDynamicObject(8657,904.827,-2227.058,12.727,0.0,0.0,-270.000);
	LastObjectID = CreateDynamicObject(8657,916.250,-2227.054,12.727,0.0,0.0,-270.000);
	LastObjectID = CreateDynamicObject(6356,900.075,-2133.544,22.599,0.0,0.0,-28.516);
	LastObjectID = CreateDynamicObject(6356,876.852,-2132.130,22.845,0.0,-0.859,-211.094);
	LastObjectID = CreateDynamicObject(671,900.446,-2146.803,12.074,0.0,0.0,0.0);
	LastObjectID = CreateDynamicObject(1280,907.054,-2143.039,12.276,0.0,0.0,90.000);
	LastObjectID = CreateDynamicObject(1280,883.700,-2142.952,12.236,0.0,0.0,90.000);
	LastObjectID = CreateDynamicObject(967,825.938,-2064.505,11.867,0.0,0.0,-270.000);
	LastObjectID = CreateDynamicObject(3886,921.281,-2232.184,0.345,0.0,0.0,-90.000);
	LastObjectID = CreateDynamicObject(3886,910.819,-2232.194,0.356,0.0,0.0,-90.000);
	LastObjectID = CreateDynamicObject(5152,932.717,-2227.829,11.871,0.859,17.189,-450.000);
	LastObjectID = CreateDynamicObject(5152,935.871,-2227.818,11.927,0.859,16.329,-450.000);
	LastObjectID = CreateDynamicObject(5152,934.024,-2227.830,11.904,0.859,16.329,-450.000);
	LastObjectID = CreateDynamicObject(5072,873.712,-2244.260,1.780,0.0,0.0,-180.000);
	LastObjectID = CreateDynamicObject(8657,861.811,-2068.330,12.802,0.0,0.0,-270.000);
	LastObjectID = CreateDynamicObject(3558,887.416,-2201.415,14.862,0.0,0.0,-180.000);
	LastObjectID = CreateDynamicObject(3558,906.396,-2201.465,14.847,0.0,0.0,-180.000);
	LastObjectID = CreateDynamicObject(1408,917.590,-2198.202,12.475,0.0,0.0,90.000);
	LastObjectID = CreateDynamicObject(1408,917.578,-2203.471,12.510,0.0,0.0,90.000);
	LastObjectID = CreateDynamicObject(1408,901.901,-2207.921,12.538,0.0,0.0,0.0);
	LastObjectID = CreateDynamicObject(1408,899.223,-2205.175,12.525,0.0,0.0,-90.000);
	
	// ================================================ Condomínio Aurora (SF) ======================================= //
    LastObjectID = CreateDynamicObject(17671,-3033.60009766,471.39999390,1.39999998,0.00000000,0.00000000,0.00000000); //object(lae2_roads67) (1)
	LastObjectID = CreateDynamicObject(18449,-3104.60009766,471.29998779,1.79999995,0.00000000,0.00000000,0.00000000); //object(cs_roadbridge01) (1)
	LastObjectID = CreateDynamicObject(18449,-3180.50000000,471.29998779,1.79999995,0.00000000,0.00000000,0.00000000); //object(cs_roadbridge01) (2)
	LastObjectID = CreateDynamicObject(18449,-3259.60009766,471.29998779,1.79999995,0.00000000,0.00000000,0.00000000); //object(cs_roadbridge01) (3)
	LastObjectID = CreateDynamicObject(18449,-3339.00000000,471.29998779,1.79999995,0.00000000,0.00000000,0.00000000); //object(cs_roadbridge01) (4)
	LastObjectID = CreateDynamicObject(18449,-3418.50000000,471.29998779,1.79999995,0.00000000,0.00000000,0.00000000); //object(cs_roadbridge01) (5)
	LastObjectID = CreateDynamicObject(18449,-3497.89990234,471.29998779,1.79999995,0.00000000,0.00000000,0.00000000); //object(cs_roadbridge01) (6)
	LastObjectID = CreateDynamicObject(18449,-3577.69995117,471.29998779,1.79999995,0.00000000,0.00000000,0.00000000); //object(cs_roadbridge01) (7)
	LastObjectID = CreateDynamicObject(18449,-3657.39990234,471.29998779,1.79999995,0.00000000,0.00000000,0.00000000); //object(cs_roadbridge01) (8)
	LastObjectID = CreateDynamicObject(18449,-3737.10009766,471.29998779,1.79999995,0.00000000,0.00000000,0.00000000); //object(cs_roadbridge01) (9)
	LastObjectID = CreateDynamicObject(18449,-3814.80004883,471.29998779,1.79999995,0.00000000,0.00000000,0.00000000); //object(cs_roadbridge01) (10)
	LastObjectID = CreateDynamicObject(18449,-3894.19995117,471.29998779,1.79999995,0.00000000,0.00000000,0.00000000); //object(cs_roadbridge01) (11)
	LastObjectID = CreateDynamicObject(5141,-3984.80004883,502.39999390,2.09999990,0.00000000,0.00000000,0.00000000); //object(btoroadxtra_las2) (1)
	LastObjectID = CreateDynamicObject(8133,-3971.19995117,463.50000000,2.40000010,0.00000000,0.00000000,0.00000000); //object(vegassland59) (1)
	LastObjectID = CreateDynamicObject(8133,-4010.89990234,463.50000000,2.40000010,0.00000000,0.00000000,0.00000000); //object(vegassland59) (2)
	LastObjectID = CreateDynamicObject(3996,-4040.60009766,494.39999390,1.89999998,0.00000000,0.00000000,270.00000000); //object(roads08_lan) (1)
	LastObjectID = CreateDynamicObject(3996,-4040.60009766,393.79998779,1.89999998,0.00000000,0.00000000,90.00000000); //object(roads08_lan) (2)
	LastObjectID = CreateDynamicObject(3996,-4040.50000000,293.50000000,1.89999998,0.00000000,0.00000000,90.00000000); //object(roads08_lan) (3)
	LastObjectID = CreateDynamicObject(8133,-3971.30004883,329.00000000,2.40000010,0.00000000,0.00000000,0.00000000); //object(vegassland59) (3)
	LastObjectID = CreateDynamicObject(8133,-4011.00000000,329.00000000,2.40000010,0.00000000,0.00000000,0.00000000); //object(vegassland59) (4)
	LastObjectID = CreateDynamicObject(3996,-3984.10009766,252.00000000,2.00000000,0.00000000,0.00000000,0.00000000); //object(roads08_lan) (4)
	LastObjectID = CreateDynamicObject(1337,-3957.52148438,275.07714844,-5.26808929,0.00000000,0.00000000,0.00000000); //object(binnt07_la) (7)
	LastObjectID = CreateDynamicObject(3996,-3942.69995117,312.50000000,2.09999990,0.00000000,0.00000000,90.00000000); //object(roads08_lan) (5)
	LastObjectID = CreateDynamicObject(3996,-3942.69995117,412.70001221,2.09999990,0.00000000,0.00000000,90.00000000); //object(roads08_lan) (6)
	LastObjectID = CreateDynamicObject(8133,-4070.10009766,463.39999390,2.20000005,0.00000000,0.00000000,0.00000000); //object(vegassland59) (5)
	LastObjectID = CreateDynamicObject(8133,-4110.00000000,463.39999390,2.20000005,0.00000000,0.00000000,0.00000000); //object(vegassland59) (6)
	LastObjectID = CreateDynamicObject(8133,-4110.10009766,328.89999390,2.20000005,0.00000000,0.00000000,0.00000000); //object(vegassland59) (7)
	LastObjectID = CreateDynamicObject(8133,-4070.10009766,328.89999390,2.20000005,0.00000000,0.00000000,0.00000000); //object(vegassland59) (8)
	LastObjectID = CreateDynamicObject(3996,-4078.39990234,251.89999390,2.00000000,0.00000000,0.00000000,0.00000000); //object(roads08_lan) (7)
	LastObjectID = CreateDynamicObject(3996,-4138.89990234,293.50000000,1.89999998,0.00000000,0.00000000,90.00000000); //object(roads08_lan) (8)
	LastObjectID = CreateDynamicObject(3996,-4138.70019531,362.60000610,1.89999998,0.00000000,0.00000000,90.00000000); //object(roads08_lan) (9)
	LastObjectID = CreateDynamicObject(3996,-4138.70019531,462.50000000,1.89999998,0.00000000,0.00000000,90.00000000); //object(roads08_lan) (10)
	LastObjectID = CreateDynamicObject(3996,-4096.89990234,535.79998779,1.89999998,0.00000000,0.00000000,0.00000000); //object(roads08_lan) (11)
	LastObjectID = CreateDynamicObject(3996,-4138.70019531,478.89999390,2.00000000,0.00000000,0.00000000,270.00000000); //object(roads08_lan) (12)


	//--------------------------------escadas de LVDP e atualização do AERO LV------------------------------------------------
    LastObjectID = CreateDynamicObject(4726, 2281.5, 2466.1000976563, 36.799999237061, 0, 0, 0);
	LastObjectID = CreateDynamicObject(6976, 2358.3000488281, 2481.8999023438, 28.799999237061, 0, 0, 268);
	LastObjectID = CreateDynamicObject(6976, 2340.6000976563, 2487.3000488281, 17.39999961853, 0, 0, 359.5);
	LastObjectID = CreateDynamicObject(10245, 2285.6000976563, 2486.5, 12.199999809265, 0, 0, 45.25);
	LastObjectID = CreateDynamicObject(10245, 2242.8000488281, 2490.8000488281, 9.6000003814697, 0, 0, 43);
	LastObjectID = CreateDynamicObject(1683, 1676.4000244141, 1450.0999755859, 48.799999237061, 0, 336, 0);

	//================================================ CASA ====================================================================
	LastObjectID = CreateDynamicObject(3605,-1276.80004883,2297.00000000,137.10000610,0.00000000,0.00000000,312.00000000);
	LastObjectID = CreateDynamicObject(621,-1299.80004883,2311.69995117,130.39999390,0.00000000,0.00000000,0.00000000);
	LastObjectID = CreateDynamicObject(621,-1265.40002441,2274.10009766,132.00000000,0.00000000,0.00000000,0.00000000);
	LastObjectID = CreateDynamicObject(656,-1295.09997559,2320.50000000,130.10000610,0.00000000,0.00000000,0.00000000);
	LastObjectID = CreateDynamicObject(669,-1310.40002441,2320.10009766,129.39999390,0.00000000,0.00000000,0.00000000);
	LastObjectID = CreateDynamicObject(673,-1260.50000000,2272.80004883,131.19999695,0.00000000,0.00000000,0.00000000);
	LastObjectID = CreateDynamicObject(673,-1248.59997559,2284.50000000,130.80000305,0.00000000,0.00000000,0.00000000);
	LastObjectID = CreateDynamicObject(673,-1255.50000000,2274.69995117,130.39999390,0.00000000,0.00000000,0.00000000);
	LastObjectID = CreateDynamicObject(778,-1286.19995117,2323.00000000,130.19999695,0.00000000,0.00000000,0.00000000);
	LastObjectID = CreateDynamicObject(15038,-1278.19995117,2320.80004883,130.69999695,0.00000000,0.00000000,0.00000000);
	LastObjectID = CreateDynamicObject(15038,-1277.00000000,2319.69995117,130.69999695,0.00000000,0.00000000,0.00000000);
	LastObjectID = CreateDynamicObject(15038,-1275.59997559,2318.50000000,130.69999695,0.00000000,0.00000000,0.00000000);
	LastObjectID = CreateDynamicObject(744,-1248.30004883,2303.19995117,128.10000610,0.00000000,0.00000000,0.00000000);
	LastObjectID = CreateDynamicObject(745,-1249.80004883,2306.10009766,128.00000000,0.00000000,0.00000000,0.00000000);
	LastObjectID = CreateDynamicObject(632,-1273.69995117,2317.10009766,130.19999695,0.00000000,0.00000000,0.00000000);
	LastObjectID = CreateDynamicObject(892,-1251.50000000,2289.39990234,130.69999695,0.00000000,0.00000000,0.00000000);
	
	//===================================QUEBRA MOLAS ============================================================
	LastObjectID = CreateDynamicObject(3502,1529.341,-1714.890,10.711,0.0,0.0,-90.000); //quebra molas (0)
    LastObjectID = CreateDynamicObject(3502,1529.835,-1714.896,10.692,0.0,0.0,-270.000); //quebra molas (1)
    LastObjectID = CreateDynamicObject(3502,1529.293,-1607.369,10.736,0.0,0.0,-90.000); //quebra molas (2)
    LastObjectID = CreateDynamicObject(3502,1530.028,-1607.379,10.717,0.0,0.0,-270.000); //quebra molas (3)
    LastObjectID = CreateDynamicObject(3502,1515.591,-1732.529,10.736,0.0,0.0,0.0); //quebra molas (4)
    LastObjectID = CreateDynamicObject(3502,1515.623,-1731.942,10.631,0.0,0.0,-180.000); //quebra molast (5)
    LastObjectID = CreateDynamicObject(3502,1545.537,-1732.469,10.736,0.0,0.0,0.0); //quebra molas (6)
    LastObjectID = CreateDynamicObject(3502,1586.256,-1732.557,10.786,0.0,0.0,0.0); //quebra molas (7)
    LastObjectID = CreateDynamicObject(3502,1569.704,-1746.847,10.761,0.0,0.0,-90.000); //quebra molas (8)
    LastObjectID = CreateDynamicObject(3502,1569.550,-1854.856,10.786,0.0,0.0,-90.000); //quebra molas (9)
    LastObjectID = CreateDynamicObject(3502,1556.843,-1872.263,10.786,0.0,0.0,0.0); //quebra molas(10)
    LastObjectID = CreateDynamicObject(3502,1583.254,-1872.456,10.936,0.0,0.0,0.0); //quebra molas(11)
    LastObjectID = CreateDynamicObject(3502,1530.095,-1884.332,10.942,0.0,0.0,-90.000); // quebra molas (12)
    LastObjectID = CreateDynamicObject(3502,1426.765,-1884.234,11.192,0.0,0.0,90.000); // quebra molas (13)
    LastObjectID = CreateDynamicObject(3502,1407.935,-1872.280,10.886,0.0,0.0,0.0); // quebra molas (14)
    LastObjectID = CreateDynamicObject(3502,1376.822,-1871.954,11.036,0.0,0.0,0.0); // quebra molas (15)
    LastObjectID = CreateDynamicObject(3502,1389.352,-1860.611,10.986,0.0,0.0,-90.000); //quebra molas (16)
    LastObjectID = CreateDynamicObject(3502,1389.299,-1746.523,10.986,0.0,0.0,-90.000); //quebra molas (17)
    LastObjectID = CreateDynamicObject(3502,1376.573,-1732.542,10.861,0.0,0.0,0.0); //quebra molas (18)
    LastObjectID = CreateDynamicObject(3502,1400.885,-1731.849,10.794,0.0,0.0,0.0); //quebra molas (19)
    LastObjectID = CreateDynamicObject(3502,1429.403,-1715.647,10.936,0.0,0.0,-90.000); //quebra molas (20)
	//==============================================ILHA=====================================================
	LastObjectID = CreateDynamicObject(11560, 772.929565, -3275.812012, 5.225586, 0.0000, 0.0000, 22.5000);
	LastObjectID = CreateDynamicObject(18334, 661.874878, -3354.844727, 36.048553, 0.0000, 0.0000, 202.5000);
	LastObjectID = CreateDynamicObject(897, 837.220459, -3233.821289, 0.020218, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(897, 836.789063, -3241.708740, -0.025249, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(897, 833.291077, -3244.815186, 8.960587, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(897, 835.015442, -3237.344482, 9.034321, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(17026, 730.863464, -3401.923340, -1.690964, 0.0000, 0.0000, 236.2501);
	LastObjectID = CreateDynamicObject(17026, 613.300598, -3273.555664, -1.823250, 0.0000, 0.0000, 135.0000);
	LastObjectID = CreateDynamicObject(17026, 632.952454, -3227.818115, 1.621338, 0.0000, 0.0000, 101.2500);
	LastObjectID = CreateDynamicObject(17026, 665.596130, -3201.981934, 0.158596, 0.0000, 0.0000, 67.5000);
	LastObjectID = CreateDynamicObject(17026, 705.200256, -3188.572754, -3.071518, 0.0000, 0.0000, 78.7500);
	LastObjectID = CreateDynamicObject(16114, 687.556702, -3280.621826, 19.867908, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(16114, 713.322266, -3364.558838, 15.197235, 0.0000, 0.0000, 45.0000);
	LastObjectID = CreateDynamicObject(16114, 671.730713, -3259.084961, 30.724480, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(17029, 614.004272, -3327.426758, 3.157038, 0.0000, 0.0000, 123.7500);
	LastObjectID = CreateDynamicObject(17071, 595.254395, -3412.289551, 2.454308, 0.0000, 0.0000, 33.7500);
	LastObjectID = CreateDynamicObject(17071, 573.179810, -3173.306885, 2.454330, 0.0000, 0.0000, 326.2500);
	LastObjectID = CreateDynamicObject(16133, 635.127563, -3285.142578, 12.655060, 0.0000, 0.0000, 270.0000);
	LastObjectID = CreateDynamicObject(899, 652.607117, -3272.895020, 31.478554, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(899, 633.083740, -3274.881836, 21.861332, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(899, 622.144165, -3266.344971, 11.674145, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(899, 625.360229, -3250.059326, 12.777840, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(899, 640.374756, -3242.555420, 19.372696, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(899, 644.196960, -3227.623291, 15.355526, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(899, 655.337402, -3218.656006, 21.096159, 0.0000, 0.0000, 78.7500);
	LastObjectID = CreateDynamicObject(899, 654.283508, -3244.283936, 31.363527, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(899, 634.147888, -3263.330322, 23.460911, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(899, 648.112915, -3257.225098, 31.789131, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(899, 646.908997, -3231.269287, 30.995806, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(899, 663.559753, -3225.076416, 34.455872, 0.0000, 0.0000, 303.7500);
	LastObjectID = CreateDynamicObject(899, 690.662170, -3198.527832, 22.762749, 0.0000, 0.0000, 191.2499);
	LastObjectID = CreateDynamicObject(899, 671.327881, -3209.115723, 23.932623, 0.0000, 0.0000, 45.0000);
	LastObjectID = CreateDynamicObject(899, 657.383972, -3202.736816, 23.122314, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(899, 646.205505, -3256.175293, 29.514702, 0.0000, 0.0000, 343.6707);
	LastObjectID = CreateDynamicObject(899, 649.449524, -3234.641602, 30.488651, 0.0000, 49.8473, 344.5301);
	LastObjectID = CreateDynamicObject(899, 658.136719, -3222.046143, 36.534409, 0.0000, 68.7549, 351.4056);
	LastObjectID = CreateDynamicObject(899, 674.610352, -3220.436523, 36.336544, 0.0000, 47.2690, 0.0000);
	LastObjectID = CreateDynamicObject(899, 690.169678, -3210.627930, 35.988159, 0.0000, 75.6304, 349.6868);
	LastObjectID = CreateDynamicObject(898, 682.822998, -3207.900879, 37.660831, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(898, 695.079041, -3212.351318, 33.096066, 0.0000, 289.6301, 30.9397);
	LastObjectID = CreateDynamicObject(898, 700.594482, -3204.474121, 29.859921, 0.0000, 351.4056, 0.0000);
	LastObjectID = CreateDynamicObject(898, 676.518433, -3236.542969, 30.235893, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(898, 664.562805, -3255.400635, 39.415241, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(898, 624.571411, -3266.145508, 18.153774, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(898, 622.125916, -3275.606445, 17.830048, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(898, 617.117798, -3281.706543, 11.077788, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(898, 697.786926, -3191.848145, 10.672441, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(898, 695.459106, -3254.221191, 33.739647, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(898, 689.898621, -3246.235352, 31.143566, 0.0000, 8.5943, 121.9361);
	LastObjectID = CreateDynamicObject(898, 683.597717, -3241.597656, 29.576672, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(897, 740.169373, -3387.448486, 16.129227, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(897, 735.786804, -3395.300293, 17.534166, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(897, 741.676941, -3393.256592, 12.050045, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(897, 738.371704, -3399.667969, 11.824997, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(897, 739.783020, -3382.183105, 16.122578, 0.0000, 98.8352, 345.3896);
	LastObjectID = CreateDynamicObject(900, 737.812195, -3365.075928, 13.810233, 0.0000, 0.0000, 90.0000);
	LastObjectID = CreateDynamicObject(900, 737.431580, -3381.284668, 13.810233, 0.0000, 0.0000, 67.5000);
	LastObjectID = CreateDynamicObject(899, 613.740479, -3353.510742, -0.077389, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(896, 753.888245, -3400.060303, 9.086002, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(896, 768.215027, -3398.879639, 7.964291, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(896, 778.151978, -3393.925537, 8.546452, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(18228, 819.296265, -3372.365723, -3.987377, 0.0000, 0.0000, 348.7500);
	LastObjectID = CreateDynamicObject(18228, 779.403442, -3394.970947, -3.435417, 0.0000, 0.0000, 348.7500);
	LastObjectID = CreateDynamicObject(16112, 691.337708, -3332.687744, 16.356323, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(16112, 687.385376, -3311.649658, 14.658367, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(901, 730.062927, -3341.408691, 14.032450, 0.0000, 0.0000, 270.0000);
	LastObjectID = CreateDynamicObject(901, 722.261780, -3329.763916, 13.762456, 0.0000, 0.0000, 270.0000);
	LastObjectID = CreateDynamicObject(901, 718.394287, -3319.310547, 15.755778, 0.0000, 0.0000, 337.5000);
	LastObjectID = CreateDynamicObject(901, 720.287903, -3312.207275, 16.814415, 0.0000, 0.0000, 281.2500);
	LastObjectID = CreateDynamicObject(901, 733.526428, -3174.863525, 7.665144, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(901, 737.173706, -3171.388184, 2.392782, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(901, 743.585205, -3170.940918, 6.926971, 0.0000, 0.0000, 315.0000);
	LastObjectID = CreateDynamicObject(901, 762.267212, -3174.534180, 1.448797, 0.0000, 0.0000, 292.5000);
	LastObjectID = CreateDynamicObject(901, 750.709595, -3175.556396, 5.866066, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(901, 749.337097, -3168.918701, 4.851196, 0.0000, 0.0000, 326.2500);
	LastObjectID = CreateDynamicObject(901, 747.941284, -3169.487549, 2.728609, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(901, 706.343201, -3406.280518, 8.812924, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(901, 708.067505, -3410.845215, 3.754503, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(901, 672.056274, -3291.267822, 27.892626, 0.0000, 0.0000, 326.2500);
	LastObjectID = CreateDynamicObject(901, 663.340088, -3287.250977, 25.999269, 0.0000, 0.0000, 343.6707);
	LastObjectID = CreateDynamicObject(901, 664.230408, -3292.402832, 28.726984, 0.0000, 0.0000, 331.6386);
	LastObjectID = CreateDynamicObject(901, 646.457458, -3272.435059, 26.764627, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(901, 634.121460, -3251.157227, 21.007221, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(901, 633.634888, -3234.504639, 15.299093, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(901, 682.600037, -3208.791260, 27.036192, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(11496, 839.575684, -3321.049316, 2.017316, 0.0000, 0.0000, 270.0000);
	LastObjectID = CreateDynamicObject(1243, 545.075500, -3389.812988, -2.341063, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(3524, 598.218018, -3410.796875, 6.978723, 0.0000, 0.0000, 101.2500);
	LastObjectID = CreateDynamicObject(3524, 698.040466, -3391.455078, 18.362429, 0.0000, 0.0000, 292.5000);
	LastObjectID = CreateDynamicObject(3524, 658.393250, -3364.859619, 13.354616, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(3524, 656.683777, -3303.760986, 25.854973, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(3524, 847.061523, -3319.095459, 5.102655, 0.0000, 0.0000, 101.2500);
	LastObjectID = CreateDynamicObject(3524, 846.632751, -3324.301270, 5.102655, 0.0000, 0.0000, 101.2500);
	LastObjectID = CreateDynamicObject(3524, 801.531677, -3347.835938, 10.856251, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(3524, 812.278381, -3256.794434, 11.596668, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(3524, 720.292297, -3265.246338, 17.795431, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(3524, 741.324036, -3184.728516, 9.752270, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(18565, 774.514160, -3329.329834, 10.926549, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(18566, 796.506958, -3340.380859, 9.109228, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(18566, 777.669006, -3282.559570, 10.173091, 0.0000, 0.0000, 67.5000);
	LastObjectID = CreateDynamicObject(18566, 739.319946, -3242.364258, 12.947044, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(18566, 818.370239, -3239.683594, 9.765997, 0.0000, 0.0000, 78.7500);
	LastObjectID = CreateDynamicObject(615, 789.591187, -3221.038330, 8.742133, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(615, 770.388367, -3280.181396, 9.547888, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(615, 759.303955, -3252.700684, 11.634764, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(615, 788.851318, -3295.332520, 9.160009, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(615, 741.721130, -3208.817871, 9.284422, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(615, 708.714905, -3238.988037, 18.549513, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(615, 749.219177, -3341.736816, 9.986212, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(615, 731.744141, -3273.634766, 13.522425, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(615, 809.111145, -3333.606445, 7.392569, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(615, 824.947266, -3252.509033, 8.558882, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(615, 813.750610, -3293.609131, 7.267176, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(615, 765.288147, -3310.878418, 10.182848, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(615, 771.355164, -3239.079102, 9.142118, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(615, 729.679077, -3231.248535, 12.060907, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(615, 736.874756, -3295.862061, 12.073946, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(615, 779.867859, -3362.129639, 9.737326, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(615, 630.223083, -3304.811279, 14.173906, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(615, 661.617737, -3311.610840, 22.226322, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(615, 668.468079, -3345.893066, 16.996992, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(615, 698.563293, -3387.514893, 16.349234, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(615, 633.916321, -3334.437500, 9.198805, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(615, 652.356323, -3364.872070, 8.436319, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(1608, 620.932495, -3410.685303, -0.678468, 0.0000, 0.0000, 311.8716);
	LastObjectID = CreateDynamicObject(1608, 615.340332, -3398.696533, -0.853410, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(6295, 683.072632, -3372.962158, 37.667820, 0.0000, 0.0000, 124.5137);
	LastObjectID = CreateDynamicObject(8493, 664.792053, -3409.395508, 16.768005, 0.0000, 0.0000, 22.5000);
	LastObjectID = CreateDynamicObject(8493, 647.988464, -3440.452881, 16.527809, 0.0000, 0.0000, 236.2501);
	LastObjectID = CreateDynamicObject(1254, 660.656555, -3400.360352, 6.487508, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(2057, 663.116882, -3404.765137, 6.430646, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(2045, 663.030701, -3402.983643, 6.353069, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(2045, 663.089050, -3402.624512, 6.353069, 0.0000, 0.0000, 67.5000);
	LastObjectID = CreateDynamicObject(2045, 663.047852, -3403.288330, 6.353069, 0.0000, 0.0000, 67.5000);
	LastObjectID = CreateDynamicObject(8483, 723.084106, -3330.165771, 16.530252, 0.0000, 0.0000, 22.5000);
	LastObjectID = CreateDynamicObject(901, 720.394958, -3325.263672, 21.347008, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(901, 724.407410, -3330.479980, 21.274256, 0.0000, 0.0000, 258.7500);
	LastObjectID = CreateDynamicObject(623, 827.960571, -3314.078613, 8.163243, 0.0000, 0.0000, 303.7500);
	LastObjectID = CreateDynamicObject(623, 826.373962, -3319.548096, 8.024624, 0.0000, 0.0000, 236.2501);
	LastObjectID = CreateDynamicObject(623, 825.303894, -3291.889893, 6.045450, 0.0000, 0.0000, 326.2500);
	LastObjectID = CreateDynamicObject(623, 828.322693, -3345.838135, 5.941618, 0.0000, 0.0000, 281.2500);
	LastObjectID = CreateDynamicObject(623, 831.696228, -3261.382568, 7.922915, 0.0000, 0.0000, 326.2500);
	LastObjectID = CreateDynamicObject(624, 823.075623, -3306.157959, 6.432722, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(624, 787.943420, -3318.710938, 8.254641, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(624, 752.766602, -3278.322021, 11.070447, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(624, 710.853455, -3291.994385, 16.718771, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(624, 721.472656, -3208.799316, 11.436818, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(624, 635.979858, -3320.037109, 12.670601, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(624, 692.747131, -3403.435791, 11.167578, 0.0000, 0.0000, 0.0000);
	LastObjectID = CreateDynamicObject(624, 651.505981, -3310.791748, 20.025764, 0.0000, 0.0000, 0.0000);
	// --------------------------------------Oficina de condiminio--------------------------------------
	LastObjectID = CreateDynamicObject(8873, 823.70001220703, -2064.1999511719, 18, 0, 0, 0);
	LastObjectID = CreateDynamicObject(8873, 849.20001220703, -2063.3000488281, 18, 0, 0, 306);
	LastObjectID = CreateDynamicObject(8878, 826.20001220703, -2070.6999511719, 19.5, 0, 8, 67.5);
	LastObjectID = CreateDynamicObject(8876, 847.20001220703, -2067.8000488281, 18.60000038147, 0, 358, 66);
	LastObjectID = CreateDynamicObject(16409, 826.20001220703, -2055.1999511719, 11.89999961853, 0, 0, 180);
	LastObjectID = CreateDynamicObject(7313, 833.59997558594, -2054.1999511719, 15.5, 0, 0, 90.5);
	LastObjectID = CreateDynamicObject(2714, 833.79998779297, -2049.8999023438, 14.699999809265, 0, 0, 88.75);
	LastObjectID = CreateDynamicObject(6986, 826.59997558594, -2043.9000244141, 28.5, 0, 0, 176);
	LastObjectID = CreateDynamicObject(1673, 826.79998779297, -2043.3000488281, 16.299999237061, 0, 89.749755859375, 270.00018310547);
	LastObjectID = CreateDynamicObject(10281, 828.09997558594, -2045.3000488281, 22.60000038147, 0, 0, 86.500030517578);
	LastObjectID = CreateDynamicObject(10837, 808.59997558594, -1786.9000244141, 16.799999237061, 0, 0, 353);
	LastObjectID = CreateDynamicObject(14467, 2854.6999511719, 900.59997558594, 12.5, 0, 0, 181.49462890625);
	LastObjectID = CreateDynamicObject(14467, 2827.1000976563, 900.59997558594, 12.5, 0, 358, 178.24719238281);
	LastObjectID = CreateDynamicObject(14467, 2817.8000488281, 900.59997558594, 12.5, 0, 0, 179.74682617188);
	LastObjectID = CreateDynamicObject(16002, 843.70001220703, -1795.8000488281, 12.89999961853, 0, 0, 89.75);
	LastObjectID = CreateDynamicObject(914, 831.40002441406, -2058.3999023438, 15.199999809265, 0, 0, 0);
	LastObjectID = CreateDynamicObject(920, 827.90002441406, -2050.6999511719, 12.39999961853, 0, 0, 0);
	LastObjectID = CreateDynamicObject(929, 822.59997558594, -2050.8000488281, 12.89999961853, 0, 0, 272.75006103516);
	LastObjectID = CreateDynamicObject(1617, 831, -2061.1000976563, 13.800000190735, 0, 0, 92);
	LastObjectID = CreateDynamicObject(1690, 826.09997558594, -2057.6000976563, 12.60000038147, 0, 359.25, 89);
	LastObjectID = CreateDynamicObject(1690, 826.09997558594, -2052.1999511719, 12.60000038147, 0, 0, 266);
	LastObjectID = CreateDynamicObject(3675, 819.29998779297, -2050.5, 9.6000003814697, 0, 0, 270);
	LastObjectID = CreateDynamicObject(968, 842.40002441406, -2061.6000976563, 11.89999961853, 0, 0, 0);
	LastObjectID = CreateDynamicObject(967, 843.79998779297, -2062.3000488281, 11.89999961853, 0, 0, 90);
	LastObjectID = CreateDynamicObject(2612, 831, -2050.1999511719, 13.89999961853, 0, 0, 0);
	LastObjectID = CreateDynamicObject(1486, 831.79998779297, -2058, 12.10000038147, 0, 0, 0);
	LastObjectID = CreateDynamicObject(1486, 831.5, -2057.8999023438, 12.10000038147, 0, 0, 0);
	LastObjectID = CreateDynamicObject(1488, 830.5, -2058.3000488281, 14, 0, 0, 178);
 // ==================================ícones, Carros, e outras coisitas================================== //
    LastObjectID = CreateDynamicObject(12957,1453.69995117,825.20001221,6.69999981,0.00000000,0.00000000,88.00000000); //object(sw_pickupwreck01) (1)
	LastObjectID = CreateDynamicObject(3594,-91.80000305,-415.89999390,0.69999999,0.00000000,0.00000000,237.99998474); //object(la_fuckcar1) (1)
	LastObjectID = CreateDynamicObject(2985,2875.60009766,911.90002441,9.80000019,0.00000000,0.00000000,180.00000000); //object(minigun_base) (1)
	LastObjectID = CreateDynamicObject(2985,2875.60009766,913.90002441,9.80000019,0.00000000,0.00000000,174.00000000); //object(minigun_base) (2)
	LastObjectID = CreateDynamicObject(2985,2875.60009766,915.79998779,9.80000019,0.00000000,0.00000000,179.99993896); //object(minigun_base) (3)
	LastObjectID = CreateDynamicObject(3091,1441.09997559,825.90002441,6.50000000,0.00000000,0.00000000,266.00000000); //object(imy_track_barrier) (1)
	LastObjectID = CreateDynamicObject(16442,-33.79999924,171.00000000,3.29999995,0.00000000,0.00000000,0.00000000); //object(desn2_stripsigs1) (1)
	LastObjectID = CreateDynamicObject(16442,-18.20000076,162.60000610,3.20000005,0.00000000,0.00000000,124.00000000); //object(desn2_stripsigs1) (2)
	LastObjectID = CreateDynamicObject(1238,1408.59997559,825.70001221,6.19999981,0.00000000,0.00000000,0.00000000); //object(trafficcone) (1)
	LastObjectID = CreateDynamicObject(1238,1418.09997559,825.59997559,6.19999981,0.00000000,0.00000000,0.00000000); //object(trafficcone) (2)
	LastObjectID = CreateDynamicObject(1238,1433.00000000,828.09997559,6.09999990,0.00000000,0.00000000,0.00000000); //object(trafficcone) (3)
	LastObjectID = CreateDynamicObject(1238,1443.40002441,828.20001221,6.09999990,0.00000000,0.00000000,0.00000000); //object(trafficcone) (4)
	LastObjectID = CreateDynamicObject(1238,1455.19995117,828.20001221,6.09999990,0.00000000,0.00000000,0.00000000); //object(trafficcone) (5)
	LastObjectID = CreateDynamicObject(1238,1466.00000000,828.20001221,6.09999990,0.00000000,0.00000000,0.00000000); //object(trafficcone) (6)
	LastObjectID = CreateDynamicObject(1238,-75.30000305,-424.70001221,0.40000001,0.00000000,0.00000000,0.00000000); //object(trafficcone) (7)
	LastObjectID = CreateDynamicObject(1238,-81.00000000,-421.39999390,0.40000001,0.00000000,0.00000000,0.00000000); //object(trafficcone) (8)
	LastObjectID = CreateDynamicObject(1238,-89.00000000,-420.39999390,0.40000001,0.00000000,0.00000000,0.00000000); //object(trafficcone) (9)
	LastObjectID = CreateDynamicObject(1238,-94.30000305,-417.00000000,0.40000001,0.00000000,0.00000000,0.00000000); //object(trafficcone) (10)
	LastObjectID = CreateDynamicObject(1238,-97.50000000,-414.79998779,0.40000001,0.00000000,0.00000000,0.00000000); //object(trafficcone) (11)
	LastObjectID = CreateDynamicObject(1238,-97.50000000,-410.89999390,0.40000001,0.00000000,0.00000000,0.00000000); //object(trafficcone) (12)
	LastObjectID = CreateDynamicObject(1238,-100.69999695,-408.60000610,0.40000001,0.00000000,0.00000000,0.00000000); //object(trafficcone) (13)
	// ====================================================== rampa =================================================//
	LastObjectID = CreateDynamicObject(1655,1047.30004883,-1790.59997559,14.10000038,0.00000000,0.00000000,0.00000000); //object(waterjumpx2) (1)
	LastObjectID = CreateDynamicObject(18451,1144.90002441,-933.20001221,42.59999847,0.00000000,0.00000000,303.00000000); //object(cs_oldcarjmp) (1)
	LastObjectID = CreateDynamicObject(1632,2375.89990234,-1886.69995117,13.80000019,0.00000000,0.00000000,0.00000000); //object(waterjump1) (1)
	LastObjectID = CreateDynamicObject(1245,2915.10009766,-1229.69995117,11.50000000,0.00000000,0.00000000,309.00000000); //object(newramp) (1)
	LastObjectID = CreateDynamicObject(16401,2781.50000000,-675.50000000,64.59999847,0.00000000,0.00000000,0.00000000); //object(desn2_peckjump) (1)
	LastObjectID = CreateDynamicObject(7885,-255.80000305,2340.19995117,108.69999695,0.00000000,0.00000000,352.00000000); //object(vegasglfhse1) (1)

	
// LastObjectID = CreateObject(1257, 0000, 0000, 000, 0.0, 0.0, 000.0);
}

GameModeInit_Police()
{
	// Carros da policia de Los Santos
	LastVehicleID = Vehicle_AddStatic(VehiclePoliceLSPD, 1555.0, -1710.75, 6.0, 0, 1, 0, 600); // Police Car LSPD
	LastVehicleID = Vehicle_AddStatic(VehicleHPV1000, 1560.0, -1710.75, 6.0, 0, 1, 0, 600); // Police MotorCycle
	LastVehicleID = Vehicle_AddStatic(VehiclePoliceRanger, 1565.0, -1710.75, 6.0, 0, 1, 0, 600); // Police Ranger
	LastVehicleID = Vehicle_AddStatic(VehiclePoliceLSPD, 1570.0, -1710.75, 6.0, 0, 1, 0, 600); // Police Car LSPD
	LastVehicleID = Vehicle_AddStatic(VehicleHPV1000, 1575.0, -1710.75, 6.0, 0, 1, 0, 600); // Police MotorCycle
	LastVehicleID = Vehicle_AddStatic(VehiclePoliceRanger, 1580.0, -1710.75, 6.0, 0, 1, 0, 600); // Police Ranger
	LastVehicleID = Vehicle_AddStatic(VehiclePoliceLSPD, 1585.0, -1710.75, 6.0, 0, 1, 0, 600); // Police Car LSPD
	LastVehicleID = Vehicle_AddStatic(VehicleHPV1000, 1590.0, -1710.75, 6.0, 0, 1, 0, 600); // Police MotorCycle
	LastVehicleID = Vehicle_AddStatic(VehiclePoliceRanger, 1595.0, -1710.75, 6.0, 0, 1, 0, 600); // Police Ranger

	// C   arros da policia de San Fierro
	LastVehicleID = Vehicle_AddStatic(VehiclePoliceSFPD, -1573.0, 701.0, -5.0, 90, 1, 0, 600); // Police Car SFPD
	LastVehicleID = Vehicle_AddStatic(VehicleHPV1000, -1573.0, 706.0, -5.0, 90, 1, 0, 600); // Police MotorCycle
	LastVehicleID = Vehicle_AddStatic(VehiclePoliceRanger, -1573.0, 711.0, -5.0, 90, 1, 0, 600); // Police Ranger
	LastVehicleID = Vehicle_AddStatic(VehiclePoliceSFPD, -1573.0, 716.0, -5.0, 90, 1, 0, 600); // Police Car SFPD
	LastVehicleID = Vehicle_AddStatic(VehicleHPV1000, -1573.0, 721.0, -5.0, 90, 1, 0, 600); // Police MotorCycle
	LastVehicleID = Vehicle_AddStatic(VehiclePoliceRanger, -1573.0, 726.0, -5.0, 90, 1, 0, 600); // Police Ranger
	LastVehicleID = Vehicle_AddStatic(VehiclePoliceSFPD, -1573.0, 731.0, -5.0, 90, 1, 0, 600); // Police Car SFPD
	LastVehicleID = Vehicle_AddStatic(VehicleHPV1000, -1573.0, 736.0, -5.0, 90, 1, 0, 600); // Police MotorCycle
	LastVehicleID = Vehicle_AddStatic(VehiclePoliceRanger, -1573.0, 741.0, -5.0, 90, 1, 0, 600); // Police Ranger

	// C   arros da policia de Las Venturas
	LastVehicleID = Vehicle_AddStatic(VehiclePoliceLVPD, 2282.0, 2477.0, 11.0, 180, 1, 0, 600); // Police Car LVPD
	LastVehicleID = Vehicle_AddStatic(VehicleHPV1000, 2277.0, 2477.0, 11.0, 180, 1, 0, 600); // Police MotorCycle
	LastVehicleID = Vehicle_AddStatic(VehiclePoliceRanger, 2272.0, 2477.0, 11.0, 180, 1, 0, 600); // Police Ranger
	LastVehicleID = Vehicle_AddStatic(VehiclePoliceLVPD, 2262.0, 2477.0, 11.0, 180, 1, 0, 600); // Police Car LVPD
	LastVehicleID = Vehicle_AddStatic(VehicleHPV1000, 2257.0, 2477.0, 11.0, 180, 1, 0, 600); // Police MotorCycle
	LastVehicleID = Vehicle_AddStatic(VehiclePoliceRanger, 2252.0, 2477.0, 11.0, 180, 1, 0, 600); // Police Ranger

	LastVehicleID = Vehicle_AddStatic(VehiclePoliceLVPD, 2282.0, 2443.0, 11.0, 0, 1, 0, 600); // Police Car LVPD
	LastVehicleID = Vehicle_AddStatic(VehicleHPV1000, 2277.0, 2443.0, 11.0, 0, 1, 0, 600); // Police MotorCycle
	LastVehicleID = Vehicle_AddStatic(VehiclePoliceRanger, 2272.0, 2443.0, 11.0, 0, 1, 0, 600); // Police Ranger
	LastVehicleID = Vehicle_AddStatic(VehiclePoliceLVPD, 2262.0, 2443.0, 11.0, 0, 1, 0, 600); // Police Car LVPD
	LastVehicleID = Vehicle_AddStatic(VehicleHPV1000, 2257.0, 2443.0, 11.0, 0, 1, 0, 600); // Police MotorCycle
	LastVehicleID = Vehicle_AddStatic(VehiclePoliceRanger, 2252.0, 2443.0, 11.0, 0, 1, 0, 600); // Police Ranger
}

// Add mafia-vehicles to the mafia-hideout
GameModeInit_Mafia()
{
	LastVehicleID = Vehicle_AddStatic(VehicleSandKing, 2811.0, 900.0, 10.8, 0.0, 0, 0, 600); // Mafia Sandking
	LastVehicleID = Vehicle_AddStatic(VehicleSandKing, 2806.0, 900.0, 10.8, 0.0, 0, 0, 600); // Mafia Sandking
	LastVehicleID = Vehicle_AddStatic(VehicleSandKing, 2801.0, 900.0, 10.8, 0.0, 0, 0, 600); // Mafia Sandking
	LastVehicleID = Vehicle_AddStatic(VehicleSandKing, 2796.0, 900.0, 10.8, 0.0, 0, 0, 600); // Mafia Sandking

	LastVehicleID = Vehicle_AddStatic(VehicleMoonbeam, 2833.0, 900.0, 10.8, 0.0, 0, 0, 600); // Mafia Moonbeam
	LastVehicleID = Vehicle_AddStatic(VehicleMoonbeam, 2838.0, 900.0, 10.8, 0.0, 0, 0, 600); // Mafia Moonbeam
	LastVehicleID = Vehicle_AddStatic(VehicleMoonbeam, 2843.0, 900.0, 10.8, 0.0, 0, 0, 600); // Mafia Moonbeam
	LastVehicleID = Vehicle_AddStatic(VehicleMoonbeam, 2848.0, 900.0, 10.8, 0.0, 0, 0, 600); // Mafia Moonbeam

	LastVehicleID = Vehicle_AddStatic(VehicleRoadTrain, 2802, 966.0, 10.8, 180.0, 0, 0, 600); // Mafia RoadTrain
	LastVehicleID = Vehicle_AddStatic(VehicleRoadTrain, 2807, 966.0, 10.8, 180.0, 0, 0, 600); // Mafia RoadTrain
	LastVehicleID = Vehicle_AddStatic(VehicleRoadTrain, 2812, 966.0, 10.8, 180.0, 0, 0, 600); // Mafia RoadTrain
	LastVehicleID = Vehicle_AddStatic(VehicleRoadTrain, 2817, 966.0, 10.8, 180.0, 0, 0, 600); // Mafia RoadTrain
	LastVehicleID = Vehicle_AddStatic(VehicleRoadTrain, 2822, 966.0, 10.8, 180.0, 0, 0, 600); // Mafia RoadTrain
	LastVehicleID = Vehicle_AddStatic(VehicleRoadTrain, 2827, 966.0, 10.8, 180.0, 0, 0, 600); // Mafia RoadTrain
}

// Add planes and helicopters to the airports
GameModeInit_Airports()
{
	// Add planes and helicopters to Los Santos airport
	LastVehicleID = Vehicle_AddStatic(VehicleShamal, 1990.0, -2295.0, 14.5, 90.0, random(126), random(126), 300); // Plane: Shamal
	LastVehicleID = Vehicle_AddStatic(VehicleShamal, 1990.0, -2320.0, 14.5, 90.0, random(126), random(126), 300); // Plane: Shamal
	LastVehicleID = Vehicle_AddStatic(VehicleShamal, 1990.0, -2345.0, 14.5, 90.0, random(126), random(126), 300); // Plane: Shamal
	LastVehicleID = Vehicle_AddStatic(VehicleShamal, 1990.0, -2370.0, 14.5, 90.0, random(126), random(126), 300); // Plane: Shamal
	LastVehicleID = Vehicle_AddStatic(VehicleNevada, 1920.0, -2265.0, 14.5, 180.0, random(126), random(126), 300); // Plane: Nevada
	LastVehicleID = Vehicle_AddStatic(VehicleNevada, 1890.0, -2295.0, 14.5, 270.0, random(126), random(126), 300); // Plane: Nevada
	LastVehicleID = Vehicle_AddStatic(VehicleMaverick, 1940.0, -2265.0, 13.6, 180.0, 1, 1, 300); // Helicopter: Maverick
	LastVehicleID = Vehicle_AddStatic(VehicleMaverick, 1955.0, -2265.0, 13.6, 180.0, 1, 1, 300); // Helicopter: Maverick
	LastVehicleID = Vehicle_AddStatic(VehicleMaverick, 1970.0, -2265.0, 13.6, 180.0, 1, 1, 300); // Helicopter: Maverick
	LastVehicleID = Vehicle_AddStatic(VehicleMaverick, 1985.0, -2265.0, 13.6, 180.0, 1, 1, 300); // Helicopter: Maverick

	// Add planes and helicopters to San Fierro airport
	LastVehicleID = Vehicle_AddStatic(VehicleShamal, -1197.0, -153.0, 15.1, 135.0, random(126), random(126), 300); // Plane: Shamal
	LastVehicleID = Vehicle_AddStatic(VehicleShamal, -1214.0, -137.5, 15.1, 135.0, random(126), random(126), 300); // Plane: Shamal
	LastVehicleID = Vehicle_AddStatic(VehicleShamal, -1230.0, -120.0, 15.1, 135.0, random(126), random(126), 300); // Plane: Shamal
	LastVehicleID = Vehicle_AddStatic(VehicleShamal, -1246.0, -103.5, 15.1, 135.0, random(126), random(126), 300); // Plane: Shamal
	LastVehicleID = Vehicle_AddStatic(VehicleNevada, -1287.0, -52.0, 15.1, 135.0, random(126), random(126), 300); // Plane: Nevada
	LastVehicleID = Vehicle_AddStatic(VehicleNevada, -1312.0, -27.0, 15.1, 135.0, random(126), random(126), 300); // Plane: Nevada
	LastVehicleID = Vehicle_AddStatic(VehicleMaverick, -1262.0, -88.5, 14.2, 135.0, 1, 1, 300); // Helicopter: Maverick
	LastVehicleID = Vehicle_AddStatic(VehicleMaverick, -1277.0, -74.5, 14.2, 90.0, 1, 1, 300); // Helicopter: Maverick
	LastVehicleID = Vehicle_AddStatic(VehicleMaverick, -1264.0, -61.5, 14.2, 45.0, 1, 1, 300); // Helicopter: Maverick

	// Add planes and helicopters to Las Venturas airport
	LastVehicleID = Vehicle_AddStatic(VehicleShamal, 1615.0, 1630.0, 11.8, 180.0, random(126), random(126), 300); // Plane: Shamal
	LastVehicleID = Vehicle_AddStatic(VehicleShamal, 1590.0, 1630.0, 11.8, 180.0, random(126), random(126), 300); // Plane: Shamal
	LastVehicleID = Vehicle_AddStatic(VehicleShamal, 1565.0, 1630.0, 11.8, 180.0, random(126), random(126), 300); // Plane: Shamal
	LastVehicleID = Vehicle_AddStatic(VehicleNevada, 1545.0, 1640.0, 11.8, 90.0, random(126), random(126), 300); // Plane: Nevada
	LastVehicleID = Vehicle_AddStatic(VehicleNevada, 1545.0, 1675.0, 11.8, 90.0, random(126), random(126), 300); // Plane: Nevada
	LastVehicleID = Vehicle_AddStatic(VehicleNevada, 1545.0, 1710.0, 11.8, 90.0, random(126), random(126), 300); // Plane: Nevada
	LastVehicleID = Vehicle_AddStatic(VehicleMaverick, 1650.0, 1557, 10.9, 90.0, 1, 1, 300); // Helicopter: Maverick
	LastVehicleID = Vehicle_AddStatic(VehicleMaverick, 1650.0, 1542, 10.9, 90.0, 1, 1, 300); // Helicopter: Maverick
	LastVehicleID = Vehicle_AddStatic(VehicleMaverick, 1635.0, 1534, 10.9, 0.0, 1, 1, 300); // Helicopter: Maverick
}

// This function adds towtrucks used for the assistance class
GameModeInit_Assistance()
{
	LastVehicleID = Vehicle_AddStatic(VehicleTowTruck, 220.0, 34.0, 2.6, 270.0, random(126), random(126), 300); // Towtruck
	LastVehicleID = Vehicle_AddStatic(VehicleTowTruck, 220.0, 29.0, 2.6, 270.0, random(126), random(126), 300); // Towtruck
	LastVehicleID = Vehicle_AddStatic(VehicleTowTruck, 220.0, 24.0, 2.6, 270.0, random(126), random(126), 300); // Towtruck
	LastVehicleID = Vehicle_AddStatic(VehicleTowTruck, 220.0, 19.0, 2.6, 270.0, random(126), random(126), 300); // Towtruck
	LastVehicleID = Vehicle_AddStatic(VehicleTowTruck, 220.0, 14.0, 2.6, 270.0, random(126), random(126), 300); // Towtruck
	LastVehicleID = Vehicle_AddStatic(VehicleTowTruck, 220.0, 9.0, 2.6, 270.0, random(126), random(126), 300); // Towtruck
	LastVehicleID = Vehicle_AddStatic(VehicleTowTruck, 220.0, 4.0, 2.6, 270.0, random(126), random(126), 300); // Towtruck
	LastVehicleID = Vehicle_AddStatic(VehicleTowTruck, 220.0, -1.0, 2.6, 270.0, random(126), random(126), 300); // Towtruck
}

// This function adds all vehicles needed for courier class
GameModeInit_Courier()
{
	// Los Santos
	LastVehicleID = Vehicle_AddStatic(VehicleBurrito, 784.0, -610.0, 16.4, 0.0, random(126), random(126), 300); // Burrito
	LastVehicleID = Vehicle_AddStatic(VehicleBurrito, 794.0, -610.0, 16.4, 0.0, random(126), random(126), 300); // Burrito
	LastVehicleID = Vehicle_AddStatic(VehicleBurrito, 804.0, -610.0, 16.4, 0.0, random(126), random(126), 300); // Burrito
	LastVehicleID = Vehicle_AddStatic(VehicleBurrito, 814.0, -610.0, 16.4, 0.0, random(126), random(126), 300); // Burrito
	LastVehicleID = Vehicle_AddStatic(VehicleBurrito, 824.0, -610.0, 16.4, 0.0, random(126), random(126), 300); // Burrito
	LastVehicleID = Vehicle_AddStatic(VehicleFaggio, 789.0, -610.0, 16.4, 0.0, random(126), random(126), 300); // Faggio
	LastVehicleID = Vehicle_AddStatic(VehicleFaggio, 799.0, -610.0, 16.4, 0.0, random(126), random(126), 300); // Faggio
	LastVehicleID = Vehicle_AddStatic(VehicleFaggio, 809.0, -610.0, 16.4, 0.0, random(126), random(126), 300); // Faggio
	LastVehicleID = Vehicle_AddStatic(VehicleFaggio, 819.0, -610.0, 16.4, 0.0, random(126), random(126), 300); // Faggio
	LastVehicleID = Vehicle_AddStatic(VehicleFaggio, 829.0, -610.0, 16.4, 0.0, random(126), random(126), 300); // Faggio
	// San Fierro
	LastVehicleID = Vehicle_AddStatic(VehicleBurrito, -1851.0, -142.5, 12.0, 0.0, random(126), random(126), 300); // Burrito
	LastVehicleID = Vehicle_AddStatic(VehicleBurrito, -1856.0, -142.5, 12.0, 0.0, random(126), random(126), 300); // Burrito
	LastVehicleID = Vehicle_AddStatic(VehicleBurrito, -1861.0, -142.5, 12.0, 0.0, random(126), random(126), 300); // Burrito
	LastVehicleID = Vehicle_AddStatic(VehicleBurrito, -1866.0, -142.5, 12.0, 0.0, random(126), random(126), 300); // Burrito
	LastVehicleID = Vehicle_AddStatic(VehicleBurrito, -1871.0, -142.5, 12.0, 0.0, random(126), random(126), 300); // Burrito
	LastVehicleID = Vehicle_AddStatic(VehicleFaggio, -1851.0, -129.5, 12.0, 180.0, random(126), random(126), 300); // Faggio
	LastVehicleID = Vehicle_AddStatic(VehicleFaggio, -1856.0, -129.5, 12.0, 180.0, random(126), random(126), 300); // Faggio
	LastVehicleID = Vehicle_AddStatic(VehicleFaggio, -1861.0, -129.5, 12.0, 180.0, random(126), random(126), 300); // Faggio
	LastVehicleID = Vehicle_AddStatic(VehicleFaggio, -1866.0, -129.5, 12.0, 180.0, random(126), random(126), 300); // Faggio
	// Las Venturas
	LastVehicleID = Vehicle_AddStatic(VehicleBurrito, 1052.5, 1915.25, 10.9, 0.0, random(126), random(126), 300); // Burrito
	LastVehicleID = Vehicle_AddStatic(VehicleBurrito, 1062.5, 1915.25, 10.9, 0.0, random(126), random(126), 300); // Burrito
	LastVehicleID = Vehicle_AddStatic(VehicleBurrito, 1072.5, 1915.25, 10.9, 0.0, random(126), random(126), 300); // Burrito
	LastVehicleID = Vehicle_AddStatic(VehicleBurrito, 1082.5, 1915.25, 10.9, 0.0, random(126), random(126), 300); // Burrito
	LastVehicleID = Vehicle_AddStatic(VehicleBurrito, 1092.5, 1915.25, 10.9, 0.0, random(126), random(126), 300); // Burrito
	LastVehicleID = Vehicle_AddStatic(VehicleFaggio, 1057.5, 1915.25, 10.9, 0.0, random(126), random(126), 300); // Faggio
	LastVehicleID = Vehicle_AddStatic(VehicleFaggio, 1067.5, 1915.25, 10.9, 0.0, random(126), random(126), 300); // Faggio
	LastVehicleID = Vehicle_AddStatic(VehicleFaggio, 1077.5, 1915.25, 10.9, 0.0, random(126), random(126), 300); // Faggio
	LastVehicleID = Vehicle_AddStatic(VehicleFaggio, 1087.5, 1915.25, 10.9, 0.0, random(126), random(126), 300); // Faggio
}

// This function adds all vehicles needed for roadworker class
GameModeInit_RoadWorker()
{
	// Quarry top
	LastVehicleID = Vehicle_AddStatic(VehicleUtilityVan, -1895.0, -1705.0, 21.5, 180.0, 7, 7, 300); // Utility Van
	LastVehicleID = Vehicle_AddStatic(VehicleUtilityVan, -1900.0, -1705.0, 21.5, 180.0, 7, 7, 300); // Utility Van
	LastVehicleID = Vehicle_AddStatic(VehicleUtilityVan, -1905.0, -1705.0, 21.5, 180.0, 7, 7, 300); // Utility Van
	LastVehicleID = Vehicle_AddStatic(VehicleUtilityVan, -1910.0, -1705.0, 21.5, 180.0, 7, 7, 300); // Utility Van
	LastVehicleID = Vehicle_AddStatic(VehicleUtilityVan, -1915.0, -1705.0, 21.5, 180.0, 7, 7, 300); // Utility Van
	LastVehicleID = Vehicle_AddStatic(VehicleUtilityVan, -1920.0, -1705.0, 21.5, 180.0, 7, 7, 300); // Utility Van
	LastVehicleID = Vehicle_AddStatic(VehicleUtilityTrailer, -1895.0, -1700.0, 21.5, 180.0, random(126), random(126), 300); // Utility Trailer
	LastVehicleID = Vehicle_AddStatic(VehicleUtilityTrailer, -1900.0, -1700.0, 21.5, 180.0, random(126), random(126), 300); // Utility Trailer
	LastVehicleID = Vehicle_AddStatic(VehicleUtilityTrailer, -1905.0, -1700.0, 21.5, 180.0, random(126), random(126), 300); // Utility Trailer
	LastVehicleID = Vehicle_AddStatic(VehicleUtilityTrailer, -1910.0, -1700.0, 21.5, 180.0, random(126), random(126), 300); // Utility Trailer
	LastVehicleID = Vehicle_AddStatic(VehicleUtilityTrailer, -1915.0, -1700.0, 21.5, 180.0, random(126), random(126), 300); // Utility Trailer
	LastVehicleID = Vehicle_AddStatic(VehicleUtilityTrailer, -1920.0, -1700.0, 21.5, 180.0, random(126), random(126), 300); // Utility Trailer
	LastVehicleID = Vehicle_AddStatic(VehicleTowTruck, -1866.5, -1731.75, 21.7, 30.0, random(126), random(126), 300); // Towtruck
	LastVehicleID = Vehicle_AddStatic(VehicleTowTruck, -1870.5, -1734.25, 21.7, 30.0, random(126), random(126), 300); // Towtruck
	LastVehicleID = Vehicle_AddStatic(VehicleTowTruck, -1874.5, -1736.75, 21.7, 30.0, random(126), random(126), 300); // Towtruck
	LastVehicleID = Vehicle_AddStatic(VehicleTowTruck, -1878.5, -1739.25, 21.7, 30.0, random(126), random(126), 300); // Towtruck
	LastVehicleID = Vehicle_AddStatic(VehicleTowTruck, -1882.5, -1741.75, 21.7, 30.0, random(126), random(126), 300); // Towtruck
	LastVehicleID = Vehicle_AddStatic(VehicleTowTruck, -1886.5, -1744.25, 21.7, 30.0, random(126), random(126), 300); // Towtruck
}
GameModeInit_PickupsIcons()
{
	Pickup_License = CreatePickup(1274, 2, -2033.0, -100.0, 35.2, 0);
	Create3DTextLabel(TXT_PickupText, 0x008080FF, -2033.0, -100.0, 36.0, 30.0, 0);

	AddRefuelPickup(-1471.5, 1863.75, 32.7);
	AddRefuelPickup(-1326.5, 2677.5, 50.1);
	AddRefuelPickup(611.5, 1694.5, 7.0);
	AddRefuelPickup(-2249.25, -2559.0, 32.0);
	AddRefuelPickup(-1606.5, -2714.0, 48.6);
	AddRefuelPickup(-93.5, -1175.0, 2.3);
	AddRefuelPickup(1377.5, 457.0, 19.9);
	AddRefuelPickup(651.5, -565.5, 16.4);
	AddRefuelPickup(-1675.75, 412.75, 7.2);
	AddRefuelPickup(-2405.50, 976.25, 45.3);
	AddRefuelPickup(-2023.25, 156.75, 28.9);
	AddRefuelPickup(-1131.75, -204.25, 14.2);
	AddRefuelPickup(66.50, 1220.50, 18.9);
	AddRefuelPickup(350.50, 2537.50, 16.8);
	AddRefuelPickup(2147.00, 2747.75, 10.9);
	AddRefuelPickup(2639.75, 1106.00, 10.9);
	AddRefuelPickup(2115.00, 920.00, 10.9);
	AddRefuelPickup(2202.00, 2475.00, 10.9);
	AddRefuelPickup(1596.50, 2199.75, 10.9);
	AddRefuelPickup(1584.25, 1448.25, 10.9);
	AddRefuelPickup(1004.25, -940.50, 42.2);
	AddRefuelPickup(1935.00, -1772.75, 13.4);
    AddRefuelPickup(850.93, 649.39, 11.74);    
    AddRefuelPickup(-28.32, 306.02, 2.75);      
    AddRefuelPickup(1280.20, 989.99, 10.53);    
    AddRefuelPickup(-560.2151,459.1780,2.5190);    
    AddRefuelPickup(-560.8548,467.9357,2.5309);

	AddCarDealerPickup(-1972.5, 288.5, 35.2); // Wang cars in Doherty (San Fierro)
	CreateDynamicMapIcon(1039, -1032, 32, 27, 0, 0, 0, -1, 150.0); // Transfender, Los Santos
	CreateDynamicMapIcon(-1936, 235, 34, 27, 0, 0, 0, -1, 150.0); // Transfender, San Fierro
	CreateDynamicMapIcon(2385, 1034, 11, 27, 0, 0, 0, -1, 150.0); // Transfender, Las Venturas
	CreateDynamicMapIcon(2646, -2025, 14, 27, 0, 0, 0, -1, 150.0); // Loco Low Co, Los Santos
	CreateDynamicMapIcon(-2712, 218, 4, 27, 0, 0, 0, -1, 150.0); // Wheel Arch Angels, San Fierro
    CreateDynamicMapIcon(-47.7973, 270.4586, 1.9668, 27, 0, 0, 0, -1, 300.0);     
    CreateDynamicMapIcon(-547.3569, 507.0492, 2.5933, 27, 0, 0, 0, -1, 300.0);    
    CreateDynamicMapIcon(1348.0941, 946.8349, 10.5367, 27, 0, 0, 0, -1, 300.0);
}
GameModeInit_Toll()
{
	CreateObject(9623, 1787.00, 695.50, 17.40, -3.5, 0.0, 350.25); //object(toll_sfw) (1)

	AddTollGate(3578, 1801.00, 692.66, 10.00, 1801.00, 692.66, 15.00, 0.0, 0.0, 350.25, 30);
	AddTollGate(3578, 1791.33, 694.44, 10.00, 1791.33, 694.44, 15.00, 0.0, 0.0, 350.25, 30);
	AddTollGate(3578, 1781.66, 696.22, 10.00, 1781.66, 696.22, 15.00, 0.0, 0.0, 350.25, 30);
	AddTollGate(3578, 1772.00, 698.00, 10.00, 1772.00, 698.00, 15.00, 0.0, 0.0, 350.25, 30);

	AddTollGate(3578, -2668.25, 1274.50, 50.0, -2668.25, 1274.50, 55.0, 0.0, 0.0, 0.0, 30);
	AddTollGate(3578, -2677.75, 1274.50, 50.0, -2677.75, 1274.50, 55.0, 0.0, 0.0, 0.0, 30);
	AddTollGate(3578, -2686.25, 1274.50, 50.0, -2686.25, 1274.50, 55.0, 0.0, 0.0, 0.0, 30);
	AddTollGate(3578, -2694.75, 1274.50, 50.0, -2694.75, 1274.50, 55.0, 0.0, 0.0, 0.0, 30);

}

GameModeInit_Classes()
{
	AddPlayerClass(59, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0); // Class 0 = Truck driver
	AddPlayerClass(101, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0); // Class 1 = Truck driver
	AddPlayerClass(5, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0); // Class 2 = Truck driver
	AddPlayerClass(4, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0); // Class 3 = Truck driver
	AddPlayerClass(201, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0); // Class 4 = Truck driver
	AddPlayerClass(262, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0); // Class 5 = Truck driver
	AddPlayerClass(242, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0); // Class 6 = Truck driver
	AddPlayerClass(240, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0); // Class 7 = Truck driver

	AddPlayerClass(189, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0); // Class 8 = Bus driver
	AddPlayerClass(171, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0); // Class 9 = Bus driver

	AddPlayerClass(61, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0); // Class 10 = Pilot

	AddPlayerClass(284, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0); // Class 11 = Police
	AddPlayerClass(266, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0); // Class 12 = Police
	AddPlayerClass(285, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0); // Class 13 = Police

	AddPlayerClass(163, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0); // Class 14 = Mafia
	AddPlayerClass(164, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0); // Class 15 = Mafia
	AddPlayerClass(165, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0); // Class 16 = Mafia

	AddPlayerClass(217, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0); // Class 17 = Courier
	AddPlayerClass(211, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0); // Class 18 = Courier

	AddPlayerClass(268, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0); // Class 19 = Assistance

	AddPlayerClass(16, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0); // Class 20 = Roadworker
	AddPlayerClass(27, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0); // Class 21 = Roadworker
	AddPlayerClass(260, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, 0, 0, 0); // Class 22 = Roadworker
}



AddRefuelPickup(Float:x, Float:y, Float:z)
{
	for (new i; i < sizeof(ARefuelPickups); i++)
	{
		if (ARefuelPickups[i][PickupID] == 0)
		{
			ARefuelPickups[i][PickupID] = CreatePickup(1244, 1, x, y, z, 0); 
			ARefuelPickups[i][pux] = x;
			ARefuelPickups[i][puy] = y;
			ARefuelPickups[i][puz] = z;
			Create3DTextLabel(TXT_PickupRefuel, 0x008080FF, x, y, z + 0.8, 30.0, 0);
			CreateDynamicMapIcon(x, y, z, 56, 0, 0, 0, -1, 300.0);
			break;
		}
	}
}
AddCarDealerPickup(Float:x, Float:y, Float:z)
{
	for (new i; i < sizeof(ACarDealerPickups); i++)
	{
		if (ACarDealerPickups[i][PickupID] == 0)
		{
			ACarDealerPickups[i][PickupID] = CreatePickup(1274, 1, x, y, z, 0);
			ACarDealerPickups[i][pux] = x;
			ACarDealerPickups[i][puy] = y;
			ACarDealerPickups[i][puz] = z;
			Create3DTextLabel(TXT_PickupCarDealer, 0x008080FF, x, y, z + 0.8, 30.0, 0);
			CreateDynamicMapIcon(x, y, z, 55, 0, 0, 0, -1, 300.0);
			break;
		}
	}
}
AddTollGate(GateModel, Float:OX, Float:OY, Float:OZ, Float:CX, Float:CY, Float:CZ, Float:RX, Float:RY, Float:RZ, TollMoney)
{
	for (new TollGate; TollGate < MAX_TOLLGATES; TollGate++)
	{
		if (ATollGates[TollGate][GateID] == 0)
		{
			ATollGates[TollGate][GateID] = CreateObject(GateModel, CX, CY, CZ, RX, RY, RZ);
			ATollGates[TollGate][TollPrice] = TollMoney;
			ATollGates[TollGate][GateStatus] = 0; // Set the status to CLOSED
			ATollGates[TollGate][OpenX] = OX; // Save the OpenX coordinates
			ATollGates[TollGate][OpenY] = OY; // Save the OpenY coordinates
			ATollGates[TollGate][OpenZ] = OZ; // Save the OpenZ coordinates
			ATollGates[TollGate][CloseX] = CX; // Save the CloseX coordinates
			ATollGates[TollGate][CloseY] = CY; // Save the CloseY coordinates
			ATollGates[TollGate][CloseZ] = CZ; // Save the CloseZ coordinates
			break;
		}
	}
} 

