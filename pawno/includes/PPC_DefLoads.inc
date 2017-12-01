/**********************
****[100% REVISADO]****
***********************/
enum TLoad
{
	LoadName[50], 
	bool:Mafia, 
	Float:PayPerUnit, 
	PCV_Required, 
	FromLocations[30], 
	ToLocations[30] 
}

new ALoads[][TLoad] =
{
	{"Dummy", false, 0.00, 0, {0}, {0}}, // LoadID 0

	{"Cascalho", false, 1.00, PCV_TruckerOreTrailer, {11}, {1, 2, 3, 4}}, // LoadID 1
	{"Areia", false, 1.00, PCV_TruckerOreTrailer, {12}, {1, 2, 3, 4}}, // LoadID 2
	{"Pedras", false, 1.00, PCV_TruckerOreTrailer, {11}, {1, 2, 3, 4}}, // LoadID 3
	{"Carvao", false, 1.00, PCV_TruckerOreTrailer, {12}, {6, 7, 8, 18}}, // LoadID 4
	{"Minerio", false, 1.00, PCV_TruckerOreTrailer, {12}, {6, 9}}, // LoadID 5
	{"Tora", false, 1.00, PCV_TruckerOreTrailer, {13}, {7, 10}}, // LoadID 6
	{"Madeira serrada", false, 1.00, PCV_TruckerOreTrailer, {10}, {14}}, // LoadID 7
	{"Residuos secos", false, 1.00, PCV_TruckerOreTrailer, {6, 15, 16}, {17, 18, 19}}, // LoadID 8
	{"Detritos", false, 1.00, PCV_TruckerOreTrailer, {17, 19}, {6, 18, 20}}, // LoadID 9
	{"Barro", false, 1.00, PCV_TruckerOreTrailer, {21, 22}, {18, 23, 24}}, // LoadID 10
    {"Entulhos", false, 1.00, PCV_TruckerOreTrailer, {11}, {1, 2, 3, 4}}, //LoadID 11

	{"Tanque vazio", false, 1.00, PCV_TruckerFluidsTrailer, {8, 25, 26}, {27, 28, 29, 30, 31, 32, 33, 34}}, // LoadID 12
	{"Diesel", true, 1.00, PCV_TruckerFluidsTrailer, {8, 25, 26}, {27, 28, 29, 30, 31, 32, 33, 34}}, // LoadID 13
	{"Querosene", true, 1.00, PCV_TruckerFluidsTrailer, {8, 25, 26}, {35, 36}}, // LoadID 14
	{"Oleo cru", false, 1.00, PCV_TruckerFluidsTrailer, {8, 25, 26}, {6}}, // LoadID 14
	{"Nitrogenio Liquido", false, 1.00, PCV_TruckerFluidsTrailer, {37, 38}, {39, 40}}, // LoadID 15
	{"Produtos Quimicos", false, 1.00, PCV_TruckerFluidsTrailer, {37}, {6, 15, 39, 40}}, // LoadID 16
	{"Agua potavel", false, 1.00, PCV_TruckerFluidsTrailer, {37}, {15, 40, 41}}, // LoadID 17
	{"Graxa", false, 1.00, PCV_TruckerFluidsTrailer, {8, 25}, {6, 10, 14, 42}}, // LoadID 18
	{"Fertilizante", false, 1.00, PCV_TruckerFluidsTrailer, {37, 38}, {21, 22}}, // LoadID 19
	{"Leite", false, 1.00, PCV_TruckerFluidsTrailer, {21, 22}, {43, 44, 45}}, // LoadID 20
	{"Cerveja", true, 1.00, PCV_TruckerFluidsTrailer, {41}, {44, 46}}, // LoadID 21
	{"Etanol", true, 1.00, PCV_TruckerFluidsTrailer, {37, 41}, {26, 39, 40}}, // LoadID 22
    {"Alcool", true, 1.00, PCV_TruckerFluidsTrailer, {37, 41}, {26, 39, 40}}, //LoadID 23

	{"Comida", false, 1.00, PCV_TruckerCargoTrailer, {7, 44, 47, 48}, {49, 50, 51, 52, 53}}, // LoadID 24
	{"Bebidas", false, 1.00, PCV_TruckerCargoTrailer, {15, 54, 55}, {49, 50, 51, 52, 53}}, // LoadID 25
	{"Cerveja engarrafada", true, 1.00, PCV_TruckerCargoTrailer, {56}, {57, 58, 59, 60, 61}}, // LoadID 26
	{"Artigos de Luxo", false, 1.00, PCV_TruckerCargoTrailer, {24, 55}, {47, 48, 50}}, // LoadID 27
	{"Eletronicos", true, 1.00, PCV_TruckerCargoTrailer, {7, 24, 48}, {50, 51, 62, 63}}, // LoadID 28
	{"Equipamentos esportivos", false, 1.00, PCV_TruckerCargoTrailer, {47, 48}, {50, 53, 57}}, // LoadID 29
	{"Placas", false, 1.00, PCV_TruckerCargoTrailer, {10}, {4, 7, 18, 22}}, // LoadID30
	{"Material de Construcao", false, 1.00, PCV_TruckerCargoTrailer, {4}, {1, 2, 3, 5}}, // LoadID 31
	{"Carga Viva", false, 1.00, PCV_TruckerCargoTrailer, {21, 22}, {23, 43, 47}}, // LoadID 32
	{"Carne", false, 1.00, PCV_TruckerCargoTrailer, {43}, {44, 49, 50, 51, 52, 53}}, // LoadID 33
	{"Papel", false, 1.00, PCV_TruckerCargoTrailer, {14}, {9, 62}}, // LoadID 34
    {"Milho", false, 1.00, PCV_TruckerCargoTrailer, {21, 22}, {44, 45, 47, 38, 23}},//LoadID 35

	{"Cimento", false, 1.00, PCV_TruckerCementTruck, {12}, {1, 2, 3, 4}}, // LoadID 36
    {"Cal", false, 1.00, PCV_TruckerCementTruck, {12}, {1, 2, 3, 4}},  //LoadID 37

	{"Comida", false, 0.60, PCV_TruckerNoTrailer, {7, 44, 47, 48}, {49, 50, 51, 52, 53}}, // LoadID 38
	{"Bebidas", false, 0.60, PCV_TruckerNoTrailer, {15, 54, 55}, {49, 50, 51, 52, 53}}, // LoadID 39
	{"Cerveja engarrafada", true, 0.60, PCV_TruckerNoTrailer, {56}, {57, 58, 59, 60, 61}}, // LoadID 40
	{"Artigos de Luxo", false, 0.60, PCV_TruckerNoTrailer, {24, 55}, {47, 48, 50}}, // LoadID 41
	{"Eletronicos", true, 0.60, PCV_TruckerNoTrailer, {7, 24, 48}, {50, 51, 62, 63}}, // LoadID 42
	{"Equipamentos esportivos", false, 0.60, PCV_TruckerNoTrailer, {47, 48}, {50, 53, 57}}, // LoadID 43
	{"Placas", false, 0.60, PCV_TruckerNoTrailer, {10}, {4, 7, 18, 22}}, // LoadID 44
	{"Material de Construcao", false, 0.60, PCV_TruckerNoTrailer, {4}, {1, 2, 3, 5}}, // LoadID 45
	{"Carga Viva", false, 0.60, PCV_TruckerNoTrailer, {21, 22}, {23, 43, 47}}, // LoadID 46
	{"Carne", false, 0.60, PCV_TruckerNoTrailer, {43}, {44, 49, 50, 51, 52, 53}}, // LoadID 47
	{"Papel", false, 0.60, PCV_TruckerNoTrailer, {14}, {9, 62}}, // LoadID 48
    {"Milho", false, 1.00, PCV_TruckerNoTrailer, {21, 22}, {44, 45, 47, 38, 23}}, //LoadID 49

	{"Passageiros", false, 1.00, PCV_PilotPlane, {121, 122, 125, 126, 130, 131, 134}, {121, 122, 125, 126, 130, 131, 134}}, // LoadID 50
	{"Malas", false, 1.00, PCV_PilotPlane, {123, 124, 127, 128, 129, 132, 133, 135}, {123, 124, 127, 128, 129, 132, 133, 135}}, // LoadID 51
	{"Passageiros", false, 1.00, PCV_PilotHelicopter, {121, 122, 125, 126, 130, 131, 134}, {121, 122, 125, 126, 130, 131, 134}}, // LoadID 52

	{"Maconha", false, 1.50, PCV_MafiaVan, {7, 44, 47, 48}, {49, 50, 51, 52, 53}}, // LoadID 53
	{"Cocaina", false, 1.50, PCV_MafiaVan, {15, 54, 55}, {49, 50, 51, 52, 53}}, // LoadID 54
	{"Armas", true, 1.50, PCV_MafiaVan, {56}, {57, 58, 59, 60, 61}}, // LoadID 55
	{"Granadas", false, 1.50, PCV_MafiaVan, {24, 55}, {47, 48, 50}}, // LoadID 56
	{"Heroina", true, 1.50, PCV_MafiaVan, {7, 24, 48}, {50, 51, 62, 63}}, // LoadID 57
	{"Caximbos", false, 1.50, PCV_MafiaVan, {47, 48}, {50, 53, 57}}, // LoadID 58
	{"Fumo", false, 1.50, PCV_MafiaVan, {10}, {4, 7, 18, 22}}, // LoadID 59
	{"Oxi", false, 1.50, PCV_MafiaVan, {4}, {1, 2, 3, 5}}, // LoadID 60
	{"Trevo", false, 1.50, PCV_MafiaVan, {21, 22}, {23, 43, 47}}, // LoadID 61
	{"Extase", false, 1.50, PCV_MafiaVan, {43}, {44, 49, 50, 51, 52, 53}}, // LoadID 62
	{"Cigarros", false, 1.50, PCV_MafiaVan, {14}, {9, 62}} // LoadID 63
};
stock Product_GetList(PCV_Needed, &NumProducts)
{
	new ProductList[50];
	for (new i; i < sizeof(ALoads); i++)
	{
		if (NumProducts < 50)
		{
			if (ALoads[i][PCV_Required] == PCV_Needed)
			{
				ProductList[NumProducts] = i;
				NumProducts++;
			}
		}
	}
	return ProductList;
}
stock Product_GetRandom(PCV_Needed)
{
	new ProductList[50], NumProducts;
	ProductList = Product_GetList(PCV_Needed, NumProducts);
	return ProductList[random(NumProducts)];
}
stock Product_GetRandomStartLoc(ProductID)
{
	new NumProducts;
	for (new i; i < 30; i++)
	{
		if (ALoads[ProductID][FromLocations][i] != 0)
		    NumProducts++;
		else
		    break;
	}
	return ALoads[ProductID][FromLocations][random(NumProducts)];
}
stock Product_GetRandomEndLoc(ProductID)
{
	new NumProducts;
	for (new i; i < 30; i++)
	{
		if (ALoads[ProductID][ToLocations][i] != 0)
		    NumProducts++;
		else
		    break;
	}
	return ALoads[ProductID][ToLocations][random(NumProducts)];
}

