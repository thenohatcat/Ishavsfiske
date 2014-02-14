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
	//printf("%08X %08X\n", nodeA->getID(), nodeB->getID());

	if (nodeA->getID() & 0x80000000 || nodeB->getID() & 0x80000000)
	{
		unsigned short id;
		if (nodeA->getID() & 0x80000000)
			id = (nodeA->getID() & 0x1FF);
		if (nodeB->getID() & 0x80000000)
			id = (nodeB->getID() & 0x1FF);

		int type = (int)((mTiles[id]->getCropOriginX()) * 2);

		if (type == 1)
		{
			//Fishing and ice
			if (nodeA->getID() >= 0x00010000 && nodeA->getID() <= 0x0001FFFF || 
				nodeB->getID() >= 0x00010000 && nodeB->getID() <= 0x0001FFFF)
			{
				printf("Fishing with ice %03u %03u\n", id % 24, id / 24);
				mShipFishing->revert();
				if (mCollFishingSound->getStatus() != sf::Sound::Status::Playing)
					if (mCollIceSound->getStatus() != sf::Sound::Status::Playing)
					{
						mCollFishingSound->play();
						mCollIceSound->play();
					}
				return;
			}

			//Breaker and ice
			if (nodeA->getID() >= 0x00020000 && nodeA->getID() <= 0x0002FFFF || 
				nodeB->getID() >= 0x00020000 && nodeB->getID() <= 0x0002FFFF)
			{
				printf("Breaker with ice %03u %03u\n", id % 24, id / 24);
				//mShipBreaker->revert();
				if (mCollBreakerSound->getStatus() != sf::Sound::Status::Playing)
					if (mCollIceSound->getStatus() != sf::Sound::Status::Playing)
					{
						mCollBreakerSound->play();
						mCollIceSound->play();
					}
				mTiles[id]->setCropOrigin(0, 0);
				return;
			}
		}
		return;
	}

	//if mShipFishing collides
	if(nodeA->getID() >= 0x00010000 && nodeA->getID() <= 0x0001FFFF || nodeB->getID() >= 0x00010000 && nodeB->getID() <= 0x0001FFFF)
	{
		mShipFishing->revert();
		if (mCollFishingSound->getStatus() != sf::Sound::Status::Playing)
			mCollFishingSound->play();
#ifdef _DEBUG
		//What mShipFishing collides with
		if(nodeA->getID() >= 0x00020000 && nodeA->getID() <= 0x0002FFFF || nodeB->getID() >= 0x00020000 && nodeB->getID() <= 0x0002FFFF)
			printf("Fishingboat collided with Icebreaker\n");
#endif
	}
	
	if(nodeA->getID() >= 0x00020000 && nodeA->getID() <= 0x0002FFFF || nodeB->getID() >= 0x00020000 && nodeB->getID() <= 0x0002FFFF)
	{
		mShipBreaker->revert();
		if (mCollBreakerSound->getStatus() != sf::Sound::Status::Playing)
			mCollBreakerSound->play();
#ifdef _DEBUG
		if (nodeA->getID() >= 0x00010000 && nodeA->getID() <= 0x0001FFFF || nodeB->getID() >= 0x00010000 && nodeB->getID() <= 0x0001FFFF)
			printf("Icebreaker collided with Fishingboat\n");
#endif
	}
}