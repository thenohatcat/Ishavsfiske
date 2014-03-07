//Version: 0.1.4
//Author: Jakob Pipping
//Contributors:

#ifndef ISHAV_0_1_4
#error FishingMode_rot.cpp: Wrong version 0.1.4
#endif

#include "IshavsfiskeGame.h"
#include "FishingMode.h"

using namespace Ishavsfiske;

FishingMode::FishingMode(unsigned long id, Angler::Node *parent, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id, parent), mOwner(owner), mSchoolID(0)
{

}

FishingMode::FishingMode(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id), mOwner(owner), mSchoolID(0)
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
		int sizes[8] = { 600, 600, 32, 64, 64, 64, 512, 1 };
		sf::Texture* textures[8] = { mTXUI, mTXUI, mTXSchool, mTXUI, mTXUI, mTXUI, mUIFont, mTXGameOver };
		mOwner->setupGraphicsLayers(8, sizes, textures);
	}
	else
	{
		mOwner->clearGraphicsLayers();
	}
}