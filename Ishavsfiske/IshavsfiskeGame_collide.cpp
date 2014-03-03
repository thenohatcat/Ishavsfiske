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
	if ((nodeA->getID() >= 0x200005000 && nodeA->getID() <= 0x20005FFF) || (nodeB->getID() >= 0x20005000 && nodeB->getID() <= 0x20005FFF))
	{
		if (nodeA->getID() == 0x00012201 || nodeB->getID() == 0x00012201)
		{
			School *school = nullptr;
			if (nodeA->getID() >= 0x20000000 && nodeA->getID() <= 0x2000FFFF)
				school = (School*)(nodeA->getParent()->getParent()->getParent()->getParent());
			else if (nodeB->getID() >= 0x20000000 && nodeB->getID() <= 0x2000FFFF)
				school = (School*)(nodeB->getParent()->getParent()->getParent()->getParent());
			((FishingBoat*)mShipFishing)->setFishing(1, school);
			printf("Fishing Right\n");
		}
		else if (nodeA->getID() == 0x00012202 || nodeB->getID() == 0x00012202)
		{
			School *school = nullptr;
			if (nodeA->getID() >= 0x20000000 && nodeA->getID() <= 0x2000FFFF)
				school = (School*)(nodeA->getParent()->getParent()->getParent()->getParent());
			else if (nodeB->getID() >= 0x20000000 && nodeB->getID() <= 0x2000FFFF)
				school = (School*)(nodeB->getParent()->getParent()->getParent()->getParent());
			((FishingBoat*)mShipFishing)->setFishing(2, school);
			printf("Fishing Left\n");
		}
	}

	if((nodeA->getID() >= 0x80012000 && nodeA->getID() <= 0x80013000) || (nodeB->getID() >= 0x80012000 && nodeB->getID() <= 0x80013000))
	{
		//ice and icebreaker
		if(nodeA->getID() == 0x00022102 || nodeB->getID() == 0x00022102)
		{
			int indx = nodeB->getID()& 0xFFF;
			if(mMap->getTile(indx) >= 0x10 && mMap->getTile(indx) <= 0x1F)
			{
				//mShipBreaker->revert();
				mSound->playSound(mCollIceSound);
				mMap->setTile(indx, 0);
#ifdef _DEBUG
				printf("Icebreaker collide with ice\n");
#endif
			}
		}
		//ice and fishingboat
		if(nodeA->getID() == 0x00012102 || nodeB->getID() == 0x00012102)
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
	if(nodeA->getID() == 0x00012102 || nodeB->getID() == 0x00012102)
	{
		//Fishingboat and iceBreaker
		if(nodeA->getID() == 0x00022102 || nodeB->getID() == 0x00022102)
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