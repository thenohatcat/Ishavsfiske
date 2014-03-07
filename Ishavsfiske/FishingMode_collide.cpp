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

		if (nodeA->getID() == 0x00012201 || nodeB->getID() == 0x00012201)
		{
			if ((nodeA->getID() >= 0x200005000 && nodeA->getID() <= 0x20005FFF) || (nodeB->getID() >= 0x20005000 && nodeB->getID() <= 0x20005FFF))
			{
				School *school = nullptr;
				if (nodeA->getID() >= 0x20000000 && nodeA->getID() <= 0x2000FFFF)
					school = (School*)(nodeA->getParent()->getParent()->getParent()->getParent());
				else if (nodeB->getID() >= 0x20000000 && nodeB->getID() <= 0x2000FFFF)
					school = (School*)(nodeB->getParent()->getParent()->getParent()->getParent());
				mOwner->throwEvent(IshavsfiskeGame::Events::Fishing, 1, school);
			}
			else if (nodeA->getID() == 0x00022102 || nodeB->getID() == 0x00022102)
			{
				if (((IceBreaker*)mShipBreaker)->getHull() < 1)
					mOwner->throwEvent(IshavsfiskeGame::Events::Repairing, 1);
			}
		}
		else if (nodeA->getID() == 0x00012202 || nodeB->getID() == 0x00012202)
		{
			if ((nodeA->getID() >= 0x200005000 && nodeA->getID() <= 0x20005FFF) || (nodeB->getID() >= 0x20005000 && nodeB->getID() <= 0x20005FFF))
			{
				School *school = nullptr;
				if (nodeA->getID() >= 0x20000000 && nodeA->getID() <= 0x2000FFFF)
					school = (School*)(nodeA->getParent()->getParent()->getParent()->getParent());
				else if (nodeB->getID() >= 0x20000000 && nodeB->getID() <= 0x2000FFFF)
					school = (School*)(nodeB->getParent()->getParent()->getParent()->getParent());
				mOwner->throwEvent(IshavsfiskeGame::Events::Fishing, 2, school);
			}
			else if (nodeA->getID() == 0x00022102 || nodeB->getID() == 0x00022102)
			{
				if (((IceBreaker*)mShipBreaker)->getHull() < 1)
					mOwner->throwEvent(IshavsfiskeGame::Events::Repairing, 2);
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
					printf("%u\n", mMap->getTile(indx));
					//mShipBreaker->revert();
					((IceBreaker*)mShipBreaker)->damage(0.1f);
					mOwner->getSound()->playSound(mCollIceSound);
					mMap->setTile(indx, 0);
	#ifdef _DEBUG
					printf("Icebreaker collide with ice\n");
	#endif
				}
				//Unbreakable ice
				else if(mMap->getTile(indx) >= 0x20 && mMap->getTile(indx) <= 0x2F)
				{
					printf("%u\n", mMap->getTile(indx));
					//mShipBreaker->revert();
					mOwner->getSound()->playSound(mCollIceSound);
					mShipBreaker->revert();
					mOwner->getSound()->playSound(mCollBreakerSound);
	#ifdef _DEBUG
					printf("Icebreaker collide with unbreakable ice\n");
	#endif
				}
			}
			//ice and fishingboat
			if(nodeA->getID() == 0x00012102 || nodeB->getID() == 0x00012102)
			{
				int indx = nodeB->getID()& 0xFFF;
				if(mMap->getTile(indx) >= 0x10 && mMap->getTile(indx) <= 0x2F)
				{
					mShipFishing->revert();
//					mShipBreaker->revert();
					mMap->revert();
					mOwner->getSound()->playSound(mCollFishingSound);
				}
			}	
		}
		//if mShipFishing collides
		if (nodeA->getID() == 0x00012102 || nodeB->getID() == 0x00012102)
		{
			//Fishingboat and iceBreaker
			if (nodeB->getID() == 0x00022102 || nodeB->getID() == 0x00022102)
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