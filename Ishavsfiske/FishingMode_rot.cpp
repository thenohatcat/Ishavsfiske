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
	: Node(id, parent), mOwner(owner), mSchoolID(0), mTimer(122), mTutorialStage(0), mTutorialStageTime(-1)
{

}

FishingMode::FishingMode(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id), mOwner(owner), mSchoolID(0), mTimer(122), mTutorialStage(0), mTutorialStageTime(-1)
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

void FishingMode::mEnable(bool enabled)
{
	if (enabled)
	{
		int sizes[9] = { 1200, 1200, 32, 64, 64, 64, 128, 512, 1 };
		sf::Texture* textures[9] = { mTXUI, mTXUI, mTXSchool, mTXUI, mTXUI, mTXUI, mTXUI, mUIFont, mTXGameOver };
		mOwner->setupGraphicsLayers(9, sizes, textures);

		mSchoolID = 0;
		mTimer = 122;
		mTutorialStage = 0;
		mTutorialStageTime = -1;

		mSchools.clear();

		mOwner->setCursorVisible(false);

		mOwner->getSound()->playSound(mSeaAmbient, false, 0, 6*60.0f + 6.0f, true);
		mOwner->getSound()->setVolume(mSeaAmbient, 10.0f);

		//mOwner->getSound()->playSound(mMusic, false, -1, -1, true);

		mOwner->getSound()->playSound(mEngineSound, false, 0, 1.46f, true);
		mOwner->getSound()->setVolume(mEngineSound, 30.0f);
	}
	else
	{
		mOwner->getSound()->stopSound(mSeaAmbient);
		//mOwner->getSound()->stopSound(mMusic);
		mOwner->getSound()->stopSound(mEngineSound);

		mOwner->setCursorVisible(true);

		mOwner->clearGraphicsLayers();
	}
}