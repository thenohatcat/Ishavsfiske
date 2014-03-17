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
		int sizes[9] = { 600, 600, 32, 64, 64, 64, 128, 512, 1 };
		sf::Texture* textures[9] = { mTXUI, mTXUI, mTXSchool, mTXUI, mTXUI, mTXUI, mTXUI, mUIFont, mTXGameOver };
		mOwner->setupGraphicsLayers(9, sizes, textures);

		mOwner->getSound()->playSound(mSeaAmbient, false, -1, -1, true);
		mOwner->getSound()->setVolume(mSeaAmbient, 10.0f);

		//mOwner->getSound()->playSound(mMusic, false, -1, -1, true);

		mOwner->getSound()->playSound(mEngineSound, false, 0, 1.46f, true);
		mOwner->getSound()->setVolume(mEngineSound, 30.0f);

		mMap->setPos(sf::Vector2i(12, 10));
		mFishBase->setTranslation(-12/20.0f, -10/20.0f);

		mMap->genMap(1);
	}
	else
	{
		mOwner->getSound()->stopSound(mSeaAmbient);
		//mOwner->getSound()->stopSound(mMusic);
		mOwner->getSound()->stopSound(mEngineSound);

		mOwner->clearGraphicsLayers();
	}
}