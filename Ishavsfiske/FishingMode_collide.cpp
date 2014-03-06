//Version: 0.1.4
//Author: Jakob Pipping
//Contributors:

#ifndef ISHAV_0_1_4
#error FishingMode_rot.cpp: Wrong version 0.1.4
#endif

#include "IshavsfiskeGame.h"
#include "FishingMode.h"

using namespace Angler;
using namespace Ishavsfiske;

void FishingMode::collide(Node *nodeA, Node *nodeB)
{
	if (!mPaused)
	{
		if ((nodeA->getID() >= 0x200005000 && nodeA->getID() <= 0x20005FFF) || (nodeB->getID() >= 0x20005000 && nodeB->getID() <= 0x20005FFF))
		{
			if (nodeA->getID() == 0x00002201 || nodeB->getID() == 0x00002201)
			{
				School *school = nullptr;
				if (nodeA->getID() >= 0x20000000 && nodeA->getID() <= 0x2000FFFF)
					school = (School*)(nodeA->getParent()->getParent()->getParent()->getParent());
				else if (nodeB->getID() >= 0x20000000 && nodeB->getID() <= 0x2000FFFF)
					school = (School*)(nodeB->getParent()->getParent()->getParent()->getParent());
				((FishingBoat*)mShipFishing)->setFishing(1, school);
				printf("Fishing Right\n");
			}
			else if (nodeA->getID() == 0x00002202 || nodeB->getID() == 0x00002202)
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
			if(nodeA->getID() >= 0x00020000 && nodeA->getID() <= 0x0002FFFF)
			{
				int indx = nodeB->getID()& 0xFFF;
				if(mMap->getTile(indx) >= 0x10 && mMap->getTile(indx) <= 0x1F)
				{
					//mShipBreaker->revert();
					mOwner->getSound()->playSound(mCollIceSound);
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
					mShipBreaker->revert();
					mMap->revert();
					mOwner->getSound()->playSound(mCollFishingSound);
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
				mOwner->getSound()->playSound(mCollFishingSound);
				mShipBreaker->revert();
				mOwner->getSound()->playSound(mCollBreakerSound);
	#ifdef _DEBUG
				printf("Fishingboat and Icebreaker collided\n");
	#endif
			}
		}
	}
}