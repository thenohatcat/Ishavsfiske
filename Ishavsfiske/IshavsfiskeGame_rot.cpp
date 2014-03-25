//Version: 0.1.5
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_5
#error IshavsfiskeGame_rot.cpp: Wrong version 0.1.5
#endif

#include "IshavsfiskeGame.h"

#include <Angler\Mechanics.h>

#include <stdarg.h>

#include <stdarg.h>

#include <iostream>

using namespace Ishavsfiske;
using namespace Angler;
using namespace Angler::Graphics;
using namespace Angler::Mechanics;
using namespace Angler::Sound;

IshavsfiskeGame::IshavsfiskeGame()
	: Game()
{
	mTitle = "Ishavsfiske v0.1.3";
	mNumLayers = 8;
	mWidth = 1600;
	mHeight = 1000;
	//mWidth = 1089;
	//mHeight = 687;
}

IshavsfiskeGame::~IshavsfiskeGame()
{

}

IceBreaker *IshavsfiskeGame::getIceBreaker()
{
	return mFishingMode->getIceBreaker();
}

FishingBoat *IshavsfiskeGame::getShipFishing()
{
	return mFishingMode->getShipFishing();
}

FishingMode *IshavsfiskeGame::getFishingMode()
{
	return mFishingMode;
}

void IshavsfiskeGame::pause(bool paused)
{
	mObjectsRoot->pause(paused);
}

bool IshavsfiskeGame::getPaused()
{
	return mObjectsRoot->getPaused();
}

void IshavsfiskeGame::throwEvent(int type, ... )
{
	va_list vl;

	va_start(vl, type);

	switch (type)
	{
	case Events::Collide:
		//Node*, Node*
		Node *nodeA, *nodeB;
		nodeA = va_arg(vl, Node*);
		nodeB = va_arg(vl, Node*);
		collide(nodeA, nodeB);
		break;
	case Events::Fishing:
		int dir;
		School *school;
		dir = va_arg(vl, int);
		school = va_arg(vl, School*);
		mFishingMode->fish(dir, school);
		break;
	case Events::Repairing:
		int rdir;
		rdir = va_arg(vl, int);
		mFishingMode->repair(rdir);
		break;
	case Events::Breaking:
		mFishingMode->breakIce();
		break;
	case Events::StartScreenShow:
		mStartScreen->enable(true);
		break;
	case Events::StartScreenHide:
		mStartScreen->enable(false);
		break;
	case Events::GameOverScreenShow:
		mFishingMode->pause(true);
		mGameOverScreen->enable(true);
		break;
	case Events::GameOverScreenHide:
		mGameOverScreen->enable(false);
		break;
	case Events::FishingModeShow:
		int map;
		map = va_arg(vl, int);
		mFishingMode->getMap()->genMap(map);
		mFishingMode->enable(true);
		break;
	case Events::FishingModeHide:
		mFishingMode->enable(false);
		break;
	case Events::HarbourModeShow:
		mHarbourMode->enable(true);
		break;
	case Events::HarbourModeHide:
		mHarbourMode->enable(false);
		break;
	}

	va_end(vl);
}

int *IshavsfiskeGame::getFishCount()
{
	return mFishCount;
}

int IshavsfiskeGame::getWallet()
{
	return mWallet;
}

void IshavsfiskeGame::addToWallet(int i)
{
	mWallet += i;
}

// Getting Arne
Arne *IshavsfiskeGame::getArne()
{
	return mFishingMode->getArne();
}