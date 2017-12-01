#undef MAX_PLAYERS
#define MAX_PLAYERS 500

new bool:IntrestEnabled = true; 
new Float:BankIntrest = 0.001; 

new ExitHouseTimer = 1000;
new ExitBusinessTimer = 1000;

new bool:ShowBoughtHouses = false;

new MaxFuel = 6000;
new RefuelMaxPrice = 2500;

#define MAX_HOUSES					3000 
#define MAX_HOUSESPERPLAYER         10
#define HouseUpgradePercent         50 
#define ParkRange                   200.0 

#define MAX_BUSINESS                2000 
#define MAX_BUSINESSPERPLAYER		4 

#define MAX_TOLLGATES				50

#define MAX_SPIKESTRIPS             50

#define MAX_CAMERAS					200

new APoliceWeapons[12] = {3, 22, 25, 29, 31, 34, 41, 46};
new PoliceWeaponsAmmo = 5000;

new DefaultJailTime = 120; 
new DefaultFinePerStar = 1000; 
new DefaultWarnTimeBeforeJail = 60; 

new Float:CourierJobRange = 9999999.0;
new PaymentPerPackage = 500;

new UnclampPricePerVehicle = 20000;

