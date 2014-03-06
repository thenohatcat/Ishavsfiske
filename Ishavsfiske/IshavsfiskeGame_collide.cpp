//Version: 0.1.4
//Author: Marcus Persson
//Contributors: 

#ifndef ISHAV_0_1_4
#error IshavsfiskeGame_update.cpp: Wrong version 0.1.4
#endif

#include "IshavsfiskeGame.h"
#include "School.h"

#include "FishingBoat.h"

#include <Angler\Node.h>
#include "Ship.h"

void Ishavsfiske::IshavsfiskeGame::collide(Angler::Node *nodeA, Angler::Node *nodeB)
{
	
	
	//if((nodeA->getID() >= 0x00020000 && nodeA->getID() <= 0x0002FFFF) || (nodeB->getID() >= 0x00020000 && nodeB->getID() <= 0x0002FFFF))
	//{
	//	icebreaker and fishinboat
	//	if (nodeA->getID() >= 0x00010000 && nodeA->getID() <= 0x0001FFFF)
	//	{
	//	}
	//}
}