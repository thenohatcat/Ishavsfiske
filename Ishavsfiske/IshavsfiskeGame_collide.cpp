//Version: 0.1.3
//Author: Marcus Persson
//Contributors: 

#ifndef ISHAV_0_1_3
#error IshavsfiskeGame_update.cpp: Wrong version 0.1.3
#endif

#include "IshavsfiskeGame.h"

#include <Angler\Node.h>
#include "Ship.h"

void Ishavsfiske::IshavsfiskeGame::collide(Angler::Node *nodeA, Angler::Node *nodeB)
{
	//if mShipFishing collides
	if(nodeA->getID() >= 0x00010000 && nodeA->getID() <= 0x0001FFFF || nodeB->getID() >= 0x00010000 && nodeB->getID() <= 0x0001FFFF)
	{
		mShipFishing->revert();
#ifdef _DEBUG
		//What mShipFishing collides with
		if(nodeA->getID() >= 0x00020000 && nodeA->getID() <= 0x0002FFFF || nodeB->getID() >= 0x00020000 && nodeB->getID() <= 0x0002FFFF)
			printf("Fishinboat collided with Icebreaker\n");
#endif
	}
	else if(nodeA->getID() >= 0x00020000 && nodeA->getID() <= 0x0002FFFF || nodeB->getID() >= 0x00020000 && nodeB->getID() <= 0x0002FFFF)
	{
		mShipBreaker->revert();
#ifdef _DEBUG
		if (nodeA->getID() >= 0x00010000 && nodeA->getID() <= 0x0001FFFF || nodeB->getID() >= 0x00010000 && nodeB->getID() <= 0x0001FFFF)
			printf("Icebreaker collided with Fishingboat\n");
#endif
	}
}