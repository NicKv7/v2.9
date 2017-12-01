/**********************
****[100% REVISADO]****
***********************/
enum TLocation
{
	LocationName[50], 
	Float:LocX,
	Float:LocY, 
	Float:LocZ 
}
new ALocations[][TLocation] =
{
	{"Dummy location", 0.0, 0.0, 0.0}, // Location 0 = dummy location (never used)

	{"Construcao (LS)", 1859.0, -1314.0, 14.0}, // Location 1
	{"Construcao (SF)", -2083.0, 209.0, 35.5}, // Location 2
	{"Construcao (LV)", 2708.0, 878.0, 10.0}, // Location 3
	{"Construcao (Avery)", 312.25, -233.75, 1.6}, // Location 4
	{"Construcao (Clown's Pocket)", 2467.0, 1923.0, 9.8}, // Location 5
	{"Industrias Solarin", -1822.5, 41.25, 15.25}, // Location 6
	{"Terminal Caminhoneiro", 52.75, -278.0, 1.7}, // Location 7
	{"Petrobras", 2708.5, 2641.25, 11.0}, // Location 8
	{"Federal Mint", -2441.0, 521.5, 30.0}, // Location 9
	{"Serralheria", -1965.75, -2436.0, 30.7}, // Location 10
	{"Pedreira", 587.25, 844.75, -42.5}, // Location 11
	{"Pedreira Top", 370.0, 874.0, 20.5}, // Location 12
	{"Deposito de Madeira", -763.5, -136.0, 65.7}, // Location 13
	{"Papeis Mill", 2331.5, -2071.5, 13.6}, // Location 14
	{"Fabrica Sprunk", 1334.75, 287.0, 19.6}, // Location 15
	{"Centro Medico (SF)", -2607.0, 684.0, 27.9}, // Location 16
	{"Ferro Velho", -1873.0, -1685.0, 21.8}, // Location 17
	{"Deposito de Cargas (LV)", 599.5, 1224.75, 11.8}, // Location 18
	{"Deposito de Lixo (LS)", 2181.0, -1980.5, 13.6}, // Location 19
	{"Industrias Estate (LV)", 1635.75, 750.5, 11.0}, // Location 20
	{"Fazenda EasterBoard", -69.5, -35.75, 3.2}, // Location 21
	{"Fazenda HillFarm", -1423.5, -1469.0, 101.7}, // Location 22
	{"Leste sementes & racoes", -310.5, 2669.5, 62.7}, // Location 23
	{"Porto (SF)", -1691.0, 31.5, 3.6}, // Location 24
	{"Refinaria (LV)", 262.5, 1453.75, 10.6}, // Location 25
	{"Refinaria (LS)", 2484.0, -2085.0, 13.6}, // Location 26
	{"Posto Countryside", -86.0, -1192.75, 2.0}, // Location 27
	{"Posto Xoomer (SF)", -1659.0, 444.0, 7.2}, // Location 28
	{"Posto (SF)", -2421.5, 953.25, 45.3}, // Location 29
	{"Posto (LS)", 1926.0, -1791.5, 13.5}, // Location 30
	{"Posto Xoomer", -1488.75, 1875.25, 32.7}, // Location 31
	{"Posto Whetstone", -1629.0, -2700.0, 48.6}, // Location 32
	{"Posto Deserto", -1309.5, 2703.75, 50.1}, // Location 33
	{"Posto Dilimore", 664.5, -583.75, 16.4}, // Location 34
	{"Posto Aeroporto", 387.9, 2590.25, 16.5}, // Location 35
	{"International SF", -1152.25, -146.5, 14.2}, // Location 36
	{"Laboratorio Easter Bay", -1033.75, -625.25, 32.1}, // Location 37
	{"Docas Ocean", 2466.0, -2219.25, 13.6}, // Location 38
	{"Corp. BioCombustivel", 1347.5, 349.5, 20.0}, // Location 39
	{"Faculdade Vidro Verde", 999.0, 1086.75, 11.0}, // Location 40
	{"Cervejaria Fleischberg", -149.75, -220.25, 1.5}, // Location 41
	{"Estaleiro Naval", -2430.75, 2310.5, 5.0}, // Location 42
	{"Deposito (LV)", 977.5, 2096.75, 11.0}, // Location 43
	{"Catering LTDA (SF)", -1945.75, -1073.5, 31.0}, // Location 44
	{"Padaria (LS)", 1025.75, -1355.0, 13.8}, // Location 45
	{"Casas Porter's", 2439.75, 114.5, 26.5}, // Location 46
	{"Chuckup LTDA", 1470.5, 1017.5, 10.9}, // Location 47
	{"Armazem (LS)", 2178.5, -2279.75, 13.6}, // Location 48
	{"Supa Save (SF)", -2463.5, 782.0, 35.2}, // Location 49
	{"Shopping Verona", 1044.75, -1548.75, 13.6}, // Location 50
	{"Shopping Las Venturas", 2867.25, 2586.0, 10.7}, // Location 51
	{"Vank Hoff Hotel", -2490.75, 337.5, 33.4}, // Location 52
	{"Shopping Esmeralda", 2056.75, 2251.25, 10.7}, // Location 53
	{"Docas Ocean", 2574.25, -2223.75, 13.4}, // Location 54
	{"Armazem BaySide", -2285.0, 2281.5, 5.0}, // Location 55
	{"Fabrica SKOL", -18.5, -282.0, 5.5}, // Location 56
	{"Estadio Las Venturas", 1377.5, 2245.75, 10.9}, // Location 57
	{"P. Creek Comercio Geral", 2318.0, -92.5, 26.5}, // Location 58
	{"Estadio Dirty Ring (LV)", 1112.0, 1451.75, 5.9}, // Location 59
	{"Cupula do Prazer", -2697.0, 1402.5, 7.2}, // Location 60
	{"Casino 4 Dragons", 1903.75, 960.5, 10.9}, // Location 61
	{"Centro Financeiro (SF)", -2039.5, 467.5, 35.2}, // Location 62
	{"Area 69", 134.54, 1945.79, 19.00}, // Location 63
    {"Usina DISA", -170.3889, 94.7059, 3.7083}, //Location 64

	{"Ponto 2 El Quebrados", -1528.50, 2548.00,   55.68}, // Location 106
	{"Ponto 1 Las Barrancas", -805.64, 1562.30,   26.96}, // Location 107
	{"Ponto 2 Las Barrancas", -847.00, 1529.50,   21.66}, // Location 108
	{"Ponto Las Payasdas", -269.00, 2625.75,   62.64}, // Location 109
	{"Ponto 1 Fort Carson",  -45.37, 1200.68,   19.21}, // Location 110
	{"Ponto 2 Fort Carson", -100.50, 1195.75,   19.58}, // Location 111
	{"Ponto 3 Fort Carson", -249.50, 1016.00,   19.59}, // Location 112
	{"Ponto 1 Angel Pine", -2169.75, -2305.75,   30.46}, // Location 113
	{"Ponto 2 Angel Pine", -2098.25, -2499.50,   30.46}, // Location 114
	{"Ponto 1 Palomino Creek", 2263.75,  -30.75,   26.33}, // Location 115
	{"Ponto 2 Palomino Creek", 2461.75,    1.00,   26.33}, // Location 116
	{"Ponto 1 Montgomery", 1288.50,  329.00,   19.40}, // Location 117        	{"Ponto", 1067.00, 1357.75, 10.7}, // Location 64
	{"Ponto", 1324.75, 1190.75, 10.7}, // Location 65
	{"Ponto", 1544.00, 1135.50, 10.7}, // Location 66
	{"Ponto", 1603.50, 1130.50, 10.7}, // Location 67
	{"Ponto", 1722.50, 1373.25, 10.5}, // Location 68
	{"Ponto", 1714.25, 1421.75, 10.5}, // Location 69
	{"Ponto", 1010.00, 1411.25, 10.7}, // Location 70
	{"Ponto", 1726.50, 1481.75, 10.7}, // Location 71
	{"Ponto", 1729.50, 1529.50, 10.7}, // Location 72
	{"Ponto", 1705.00, 1965.00, 10.7}, // Location 73
	{"Ponto", 1385.00, 1920.00, 10.7}, // Location 74
	{"Ponto", 1335.25, 2055.50, 10.7}, // Location 75
	{"Ponto", 1073.00, 2055.50, 10.7}, // Location 76
	{"Ponto", 1502.25, 2055.50, 10.7}, // Location 77
	{"Ponto", 1565.00, 2200.25, 10.7}, // Location 78
	{"Ponto", 1636.25, 2175.50, 10.7}, // Location 79
	{"Ponto", 1503.50, 2311.00, 10.7}, // Location 80
	{"Ponto", 1564.75, 2345.75, 10.7}, // Location 81
	{"Ponto", 1725.00, 2247.75, 10.7}, // Location 82
	{"Ponto", 1894.50, 2175.50, 10.7}, // Location 83
	{"Ponto", 1925.25, 2314.75, 10.7}, // Location 84
	{"Ponto", 1925.25, 2115.75, 10.8}, // Location 85
	{"Ponto", 2083.50, 2455.50, 10.7}, // Location 86
	{"Ponto", 2285.00, 2315.00, 10.7}, // Location 87
	{"Ponto", 2305.00, 2515.50, 10.7}, // Location 88
	{"Ponto", 2392.00, 2415.50, 10.7}, // Location 89
	{"Ponto", 2425.00, 2285.00, 10.7}, // Location 90
	{"Ponto", 2449.75, 2235.50, 10.7}, // Location 91
	{"Ponto", 2580.25, 2115.50, 10.7}, // Location 92
	{"Ponto", 2447.50, 2055.50, 10.7}, // Location 93
	{"Ponto", 2115.00, 755.50, 10.7}, // Location 94
	{"Ponto", 2019.75, 750.50, 10.7}, // Location 95
	{"Ponto", 1975.00, 775.50, 10.7}, // Location 96
	{"Ponto", 1885.00, 770.75, 10.7}, // Location 97
	{"Ponto", 1894.00, 635.75, 10.7}, // Location 98
	{"Ponto", 1974.25, 631.00, 10.7}, // Location 99
	{"Ponto", 2020.50, 670.50, 10.7}, // Location 100
	{"Ponto", 2114.75, 675.75, 10.7}, // Location 101
	{"Ponto", 1084.75, 1196.00, 10.7}, // Location 102

	{"Ponto 1 Bayside", -2565.75, 2315.25,    4.83}, // Location 103
	{"Ponto 2 Bayside", -2337.00, 2375.00,    5.59}, // Location 104
	{"Ponto 1 El Quebrados", -1467.00, 2674.00,   55.68}, // Location 105
	{"Ponto 2 Montgomery", 1286.75,  323.75,   19.40}, // Location 118
	{"Ponto 1 Dillimore",  736.00, -527.50,   16.18}, // Location 119
	{"Ponto 2 Dillimore",  736.00, -532.50,   16.18}, // Location 120

	{"Portao 1 SF", -1337.94, -222.79,   14.14}, // ID = 121
	{"Portao 2 SF", -1395.26, -104.20,   14.14}, // ID = 122
	{"Compartimento 1 SF", -1337.16, -542.29,   14.14}, // ID = 123
	{"Compartimento 2 SF", -1412.96, -579.85,   14.14}, // ID = 124

	{"Portao 1 LS", 1747.04, -2441.04,   13.55}, // ID = 125
	{"Portao 2 LS", 1902.16, -2350.11,   13.54}, // ID = 126
	{"Compartimento 1 LS", 1889.10, -2625.49,   13.54}, // ID = 127
	{"Compartimento 2 LS", 1754.74, -2622.69,   13.54}, // ID = 128
	{"Compartimento 3 LS", 1617.61, -2622.30,   13.54}, // ID = 129

	{"Portao 1 LV", 1564.77, 1536.77,   10.82}, // ID = 130
	{"Portao 2 LV", 1569.85, 1358.58,   10.86}, // ID = 131
	{"Compartimento 1 LV", 1307.41, 1324.01,   10.82}, // ID = 132
	{"Compartimento 2 LV", 1308.47, 1361.32,   10.82}, // ID = 133

	{"Portao Verdant Meadows", 392.13, 2531.27, 16.54}, // ID = 134
	{"Compartimento Verdant Meadows", 291.08, 2525.75, 16.79}, // ID = 135

	{"TestRock", 351.5, 1008.75, 28.4}, // ID = 136
	{"TestCP", 344.75, 1020.5, 28.3} // ID = 137
};

