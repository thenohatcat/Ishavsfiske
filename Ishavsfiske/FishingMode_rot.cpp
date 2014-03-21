//Version: 0.1.5
//Author: Jakob Pipping
//Contributors:

#ifndef ISHAV_0_1_5
#error FishingMode_rot.cpp: Wrong version 0.1.5
#endif

#include "IshavsfiskeGame.h"
#include "FishingMode.h"

using namespace Ishavsfiske;

FishingMode::FishingMode(unsigned long id, Angler::Node *parent, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id, parent), mOwner(owner), mSchoolID(0), mTimer(122), mTutorialStage(0), mTutorialStageTime(-1),
	mFishMaximum(150)
{

}

FishingMode::FishingMode(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id), mOwner(owner), mSchoolID(0), mTimer(122), mTutorialStage(0), mTutorialStageTime(-1),
	mFishMaximum(150)
{

}

IceBreaker *FishingMode::getIceBreaker()
{
	return (IceBreaker*)mShipBreaker;
}

FishingBoat *FishingMode::getShipFishing()
{
	return (FishingBoat*)mShipFishing;
}

Map *FishingMode::getMap()
{
	return mMap;
}

void FishingMode::mSchoolsClear()
{
	for (std::vector<School*>::const_iterator i = mSchools.begin(); i != mSchools.end(); )
	{
		Angler::Node *n = *i;
		i = mSchools.erase(i);
		delete n;
	}
}

float FishingMode::mGetFish()
{
	float ft = ((FishingBoat*)mShipFishing)->getAmmount()[0] + ((FishingBoat*)mShipFishing)->getAmmount()[1] + ((FishingBoat*)mShipFishing)->getAmmount()[2] + ((FishingBoat*)mShipFishing)->getAmmount()[3];
	return ft / (float)mFishMaximum;
}

void FishingMode::mReset()
{
	mSchoolID = 0;
	mTimer = 122;
	mTutorialStage = 0;
	mTutorialStageTime = -1;

	mMap->setPos(sf::Vector2i(12, 10));
	mFishBase->setTranslation(-12/20.0f, -10/20.0f);

	mShipFishing->setPosition(sf::Vector2f(0.4f, 0.5f));
	mShipFishing->setRotation(0);

	mShipBreaker->setPosition(sf::Vector2f(0.6f, 0.5f));
	mShipBreaker->setRotation(0);

	mMap->updateMap();

	mSchoolsClear();
}

void FishingMode::mEnable(bool enabled)
{
	if (enabled)
	{
		int sizes[12] = { 1200, 1200, 64, 64, 64, 64, 128, 512, 1, 1, 32, 1 };
		sf::Texture* textures[12] = { mTXUI, mTXUI, mTXSchool, mTXUI, mTXUI, mTXUI, mTXUI, mUIFont, mTXBackButton, mTXCursor, mTXSeagull, mTXGameOver };
		mOwner->setupGraphicsLayers(12, sizes, textures);

		mReset();

		mOwner->setCursorVisible(false);

		mOwner->getSound()->playSound(mSeaAmbient, false, 0, 6*60.0f + 6.0f, true);
		mOwner->getSound()->setVolume(mSeaAmbient, 10.0f);

		mOwner->getSound()->playSound(mMusic, false, 0, 1*60.0f + 6.0f, true);

		mOwner->getSound()->playSound(mEngineSound, false, 0, 1.46f, true);
		mOwner->getSound()->setVolume(mEngineSound, 30.0f);
	}
	else
	{
		mOwner->getSound()->stopSound(mSeaAmbient);
		//mOwner->getSound()->stopSound(mMusic);
		mOwner->getSound()->stopSound(mEngineSound);

		int *fc = mOwner->getFishCount();
		int *fcs = ((FishingBoat*)mShipFishing)->getAmmount();
		for (int i = 0; i < 4; i++)
		{
			fc[i] += fcs[i];
			fcs[i] = 0;
		}

		mOwner->setCursorVisible(true);

		mOwner->clearGraphicsLayers();
	}
}