//Version: 0.1.2
//Author: Marcus Persson
//Contributors: 

#ifndef ISHAV_0_1_2
#error IshavsfiskeGame_update.cpp: Wrong version 0.1.2
#endif

#include "IshavsfiskeGame.h"

#include <Angler\Node.h>
#include <Ishavsfiske\Ship.h>

void Ishavsfiske::IshavsfiskeGame::collide(Angler::Node *nodeA, Angler::Node *nodeB)
{
	//if mShip collides
	if(nodeA->getID() >= 0x0001000 && nodeA->getID() <= 0x0001FFFF)
	{
		mShip->revert();
		//What mShip collides with
		if(nodeB->getID() >=0x00020000 && nodeB->getID() <= 0x0002FFFF)
			printf("Ship Collided with wreck1\n", &nodeA, &nodeB);
		if(nodeB->getID() >=0x00030000 && nodeB->getID() <= 0x0003FFFF)
			printf("Ship Collided with wreck2\n", &nodeA, &nodeB);
		if(nodeB->getID() >=0x00040000 && nodeB->getID() <= 0x0004FFFF)
			printf("Ship Collided with wreck3\n", &nodeA, &nodeB);
	}
}