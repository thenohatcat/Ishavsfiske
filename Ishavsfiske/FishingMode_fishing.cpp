//Version: 0.1.5
//Author: Jakob Pipping
//Contributors:

#ifndef ISHAV_0_1_5
#error FishingMode_fishing.cpp: Wrong version 0.1.5
#endif

#include "IshavsfiskeGame.h"
#include "FishingMode.h"

using namespace Ishavsfiske;

void FishingMode::fish(int i, School *school)
{
	((FishingBoat*)mShipFishing)->setFishing(i, school);

	if (mTutorialStage == 16)
	{
		mTutorialStage = 17;
		mTutorialStageTime = -1;
	}

#ifndef _DEBUG
	if (i == 1)
		printf("Fishing Right\n");
	else if (i == 2)
		printf("Fishing Left\n");
#endif
}

void FishingMode::repair(int dir)
{
	((FishingBoat*)mShipFishing)->setRepair(dir);
	
	mOwner->getSound()->playSound(mRepair, false, 0x20005L, false);

	if (mTutorialStage == 12)
	{
		mTutorialStage = 13;
		mTutorialStageTime = -1;
	}
}

void FishingMode::breakIce()
{
	((IceBreaker*)mShipBreaker)->damage(0.1f);

	if (mTutorialStage == 6)
	{
		mTutorialStage = 7;
		mTutorialStageTime = -1;
	}
}