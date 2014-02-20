//Version: 0.1.4
//Author: Marcus Persson
//Contributors: 

#ifndef ISHAV_0_1_4
#error IshavsfiskeGame_update.cpp: Wrong version 0.1.4
#endif

#include "IshavsfiskeGame.h"

#include <Angler\Node.h>
#include "Ship.h"

void Ishavsfiske::IshavsfiskeGame::collide(Angler::Node *nodeA, Angler::Node *nodeB)
{
	if((nodeA->getID() >= 0x80012000 && nodeA->getID() <= 0x80013000) || (nodeB->getID() >= 0x80012000 && nodeB->getID() <= 0x80013000))
	{
		//ice and icebreaker
		if(nodeA->getID() >= 0x00020000 && nodeA->getID() <= 0x0002FFFF)
		{
			int indx = nodeB->getID()& 0xFFF;
			if(mMap->getTile(indx) >= 0x10 && mMap->getTile(indx) <= 0x1F)
			{
				mShipBreaker->revert();
				mSound->playSound(mCollIceSound);
				mMap->setTile(indx, 0);
#ifdef _DEBUG
			printf("Icebreaker collide with ice\n");
#endif
			}
		}
		//ice and fishingboat
		if(nodeA->getID() >= 0x00010000 && nodeA->getID() <= 0x0001FFFF)
		{
			int indx = nodeB->getID()& 0xFFF;
			if(mMap->getTile(indx) >= 0x10 && mMap->getTile(indx) <= 0x1F)
			{
				mShipFishing->revert();
				mSound->playSound(mCollFishingSound);
			}
		}	
	}
	//if mShipFishing collides
	if((nodeA->getID() >= 0x00010000 && nodeA->getID() <= 0x0001FFFF) || (nodeB->getID() >= 0x00010000 && nodeB->getID() <= 0x0001FFFF))
	{
		//Fishingboat and iceBreaker
		if(nodeB->getID() >= 0x00020000 && nodeB->getID() <= 0x0002FFFF)
		{
			mShipFishing->revert();
			mSound->playSound(mCollFishingSound);
			mShipBreaker->revert();
			mSound->playSound(mCollBreakerSound);
#ifdef _DEBUG
			printf("Fishingboat and Icebreaker collided\n");
#endif
		}
	}
	
	//if((nodeA->getID() >= 0x00020000 && nodeA->getID() <= 0x0002FFFF) || (nodeB->getID() >= 0x00020000 && nodeB->getID() <= 0x0002FFFF))
	//{
	//	icebreaker and fishinboat
	//	if (nodeA->getID() >= 0x00010000 && nodeA->getID() <= 0x0001FFFF)
	//	{
	//	}
	//}
}