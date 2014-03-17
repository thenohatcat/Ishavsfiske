//Version: 0.1.5
//Author: Marcus Persson
//Contributors: 

#ifndef ISHAV_0_1_5
#error IshavsfiskeGame_update.cpp: Wrong version 0.1.5
#endif

#include "IshavsfiskeGame.h"
#include "School.h"

#include "FishingBoat.h"

#include <Angler\Node.h>
#include "Ship.h"

void Ishavsfiske::IshavsfiskeGame::collide(Angler::Node *nodeA, Angler::Node *nodeB)
{
	mFishingMode->collide(nodeA, nodeB);
}