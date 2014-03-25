//Version: 0.1.5
//Author: Jakob Pipping
//Contributors:

#ifndef ISHAV_0_1_5
#error FishingMode_rot.cpp: Wrong version 0.1.5
#endif

#include "IshavsfiskeGame.h"
#include "FishingMode.h"

#include <Angler\HelpFunctions.h>
#include <iostream>

using namespace Angler;
using namespace Ishavsfiske;

void FishingMode::collide(Node *nodeA, Node *nodeB)
{
	if (!mPaused)
	{
		if (nodeA->getID() == 0x00012201 || nodeB->getID() == 0x00012201)
		{
			if (!((FishingBoat*)mShipFishing)->getRepairing())
			{
				if (nodeA->getID() == 0x00022102 || nodeB->getID() == 0x00022102)
				{
					if (mDoRepair)
						if (((IceBreaker*)mShipBreaker)->getHull() < 1)
							mOwner->throwEvent(IshavsfiskeGame::Events::Repairing, 1);
				}
				else if (((nodeA->getID() >= 0x200005000 && nodeA->getID() <= 0x20005FFF) || 
					(nodeB->getID() >= 0x20005000 && nodeB->getID() <= 0x20005FFF)) && mDoFish)
				{
					School *school = nullptr;
					if (nodeA->getID() >= 0x20000000 && nodeA->getID() <= 0x2000FFFF)
						school = (School*)(nodeA->getParent()->getParent()->getParent()->getParent());
					else if (nodeB->getID() >= 0x20000000 && nodeB->getID() <= 0x2000FFFF)
						school = (School*)(nodeB->getParent()->getParent()->getParent()->getParent());
					mOwner->throwEvent(IshavsfiskeGame::Events::Fishing, 1, school);
				}
			}
		}
		else if (nodeA->getID() == 0x00012202 || nodeB->getID() == 0x00012202)
		{
			if (!((FishingBoat*)mShipFishing)->getRepairing())
			{
				if ((nodeA->getID() == 0x00022102 || nodeB->getID() == 0x00022102) && mDoRepair)
				{
						if (((IceBreaker*)mShipBreaker)->getHull() < 1)
							mOwner->throwEvent(IshavsfiskeGame::Events::Repairing, 2);
				}
				else if (((nodeA->getID() >= 0x200005000 && nodeA->getID() <= 0x20005FFF) || 
					(nodeB->getID() >= 0x20005000 && nodeB->getID() <= 0x20005FFF)) && mDoFish)
				{
					School *school = nullptr;
					if (nodeA->getID() >= 0x20000000 && nodeA->getID() <= 0x2000FFFF)
						school = (School*)(nodeA->getParent()->getParent()->getParent()->getParent());
					else if (nodeB->getID() >= 0x20000000 && nodeB->getID() <= 0x2000FFFF)
						school = (School*)(nodeB->getParent()->getParent()->getParent()->getParent());
					mOwner->throwEvent(IshavsfiskeGame::Events::Fishing, 2, school);
				}
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
					mOwner->throwEvent(IshavsfiskeGame::Events::Breaking);
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
				if(mMap->getTile(indx) >= 0x10 && mMap->getTile(indx) <= 0x1F)
				{
					if (mShipFishing->getVelocity().y != 0)
					{
						mOwner->getSound()->playSound(mCollFishingSound);
						mOwner->getSound()->playSound(mCollIceSound);
					}
					mShipFishing->block();
					mMap->revert();
				}
				//Unbreakable ice
				if(mMap->getTile(indx) >= 0x20 && mMap->getTile(indx) <= 0x2F)
				{
					mShipFishing->revert();
					mMap->revert();
					mOwner->getSound()->playSound(mCollFishingSound);
					mOwner->getSound()->playSound(mCollIceSound);
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
		//// if mArne collides
		//if((nodeA->getID() >= 0x60000000 && nodeA->getID() <= 0x69000000) || (nodeA->getID() >= 0x60000000 && nodeA->getID() <= 0x69000000))
		//{
		//	if (nodeB->getID() == 0x00022102 || nodeB->getID() == 0x00022102)
		//	{
		//		mShipBreaker
		//	}
		//}

		//// if mSeagull collides
		//if((nodeA->getID() && 0xF000FFFF == 0x40002000) && (nodeB->getID() && 0xF000FFFF == 0x40002000))
		//{
		//	Seagull *seagull = nullptr;
		//	if (nodeB->getID() && 0xF000FFFF == 0x40002000)/* && nodeB->getID() && 0xF000FFFF == 0x40002000)*/
		//	{
		//		seagull = (Seagull*)(nodeA);
		//		seagull->revert();
		//	}
		//	else if(nodeB->getID() && 0xF000FFFF == 0x40002000)/* && nodeB->getID() <= 0x4FFFFFFF)*/
		//	{
		//		seagull = (Seagull*)(nodeB);
		//		seagull->revert();
		//	}
		//}

		if(((nodeA->getID() & 0xF000FFFF) == 0x40002000) && ((nodeB->getID() & 0xF000FFFF) == 0x40002000))
		{
			Seagull *seagullA, *seagullB;
			seagullA = (Seagull*)Angler::HelpFunctions::Nodes::getNode(nodeA->getID() & 0xFFFF0000, this);
			seagullB = (Seagull*)Angler::HelpFunctions::Nodes::getNode(nodeB->getID() & 0xFFFF0000, this);
			seagullA->revert();
			seagullB->revert();
			std::cout << "collided" << std::endl;
		}
	}
}