//Version: 0.1.4
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_4
#error IshavsfiskeGame_rot.cpp: Wrong version 0.1.4
#endif

#include "IshavsfiskeGame.h"

#include <Angler\Mechanics.h>

#include <stdarg.h>

#include <stdarg.h>

#include <iostream>

using namespace Ishavsfiske;
using namespace Angler;
using namespace Angler::Mechanics;
using namespace Angler::Sound;

IshavsfiskeGame::IshavsfiskeGame()
	: Game(), mSchoolID(0)
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
	return (IceBreaker*)mShipBreaker;
}

FishingBoat *IshavsfiskeGame::getShipFishing()
{
	return (FishingBoat*)mShipFishing;
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
	case Game::Events::Collide:
		//Node*, Node*
		Node *nodeA, *nodeB;
		nodeA = va_arg(vl, Node*);
		nodeB = va_arg(vl, Node*);
		collide(nodeA, nodeB);
		break;
	}

	va_end(vl);
}