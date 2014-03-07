//Version: 0.1.4
//Author: Jakob Pipping
//Contributors:

#ifndef ISHAV_0_1_4
#error FishingMode_fishing.cpp: Wrong version 0.1.4
#endif

#include "IshavsfiskeGame.h"
#include "FishingMode.h"

using namespace Ishavsfiske;

void FishingMode::fish(int i, School *school)
{
	((FishingBoat*)mShipFishing)->setFishing(i, school);

//#ifndef _DEBUG
//	if (i == 1)
//		printf("Fishing Right\n");
//	else if (i == 2)
//		printf("Fishing Left\n");
//#endif
}

void FishingMode::repair(int dir)
{
	((FishingBoat*)mShipFishing)->setRepair(dir);
}