//Version: 0.1.4
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_4
#error FishingMode_update.cpp: Wrong version 0.1.4
#endif

#include "IshavsfiskeGame.h"

#include "Ship.h"
#include "FishingBoat.h"

#include <glm\glm.hpp>

#include <Angler\Node.h>
#include <Angler\Transformation.h>
#include <Angler\HelpFunctions.h>

#include "Font.h"

using namespace Ishavsfiske;

void FishingMode::mMoveFrame(float dx, float dy)
{
	sf::Vector2i mapPos = mMap->getPos();

	if ((dx > 0 && mapPos.x >= 24) || (dx < 0 && mapPos.x <= 0))
		dx = 0;
	if ((dy > 0 && mapPos.y >= 20) || (dy < 0 && mapPos.y <= 0))
		dy = 0;

	mFishBase->translate(-dx, -dy);

	mShipBreaker->move(-dx, -dy, true);
	mShipFishing->move(-dx, -dy, true);

	mMap->move(sf::Vector2f(20 * dx, 20 * dy));

	mChanged = true;

	//printf("Vel: {%03f, %03f}\n", mx, my);
}

void FishingMode::update(Angler::Game* context, float time, float deltaTime, bool changed)
{
	if (!mPaused)
	{
		mChanged |= changed;

		mDoRepair = false;

		input(time, deltaTime);

		mUpdateChildren(context, time, deltaTime);

		float fishingMVX = 0, fishingMVY = 0;
		float breakerMVX = 0, breakerMVY = 0;

		float breakerX = ((mShipBreaker->getPosition().x - 4/20.0f) * 20), breakerY = (mShipBreaker->getPosition().y * 20);
		float fishingX = ((mShipFishing->getPosition().x - 4/20.0f) * 20), fishingY = (mShipFishing->getPosition().y * 20);

		float breakerVX = mShipBreaker->getGlobalVelocity().x, breakerVY = mShipBreaker->getGlobalVelocity().y;
		float fishingVX = mShipFishing->getGlobalVelocity().x, fishingVY = mShipFishing->getGlobalVelocity().y;

		float base;
		if ((breakerX > 18.0f && fishingX > 6.0f) && breakerVX > 0)
		{
			base = ((breakerX - 18.0f) / 1.732);
			breakerMVX = breakerVX / 0.0458f * std::max(std::min(base*base/12.0f, 1.0f), 0.0f);
		}
		else if ((breakerX < 6.0f && fishingX < 18.0f) && breakerVX < 0)
		{
			base = ((-breakerX + 6.0f) / 1.732f);
			breakerMVX = breakerVX / 0.0458f * std::max(std::min(base*base/12.0f, 1.0f), 0.0f);
		}

		if ((breakerY > 15.0f && fishingY > 5.0f) && breakerVY > 0)
		{
			base = ((breakerY - 15.0f) / 1.581f);
			breakerMVY = breakerVY / 0.0458f * std::max(std::min(base*base/10.0f, 1.0f), 0.0f);
		}
		else if ((breakerY < 5.0f && fishingY < 15.0f) && breakerVY < 0)
		{
			base = ((-breakerY + 5.0f) / 1.581f);
			breakerMVY = breakerVY / 0.0458f * std::max(std::min(base*base/10.0f, 1.0f), 0.0f);
		}

		if ((fishingX > 18.0f && breakerX > 6.0f) && fishingVX > 0)
		{
			base = ((fishingX - 18.0f) / 1.732);
			fishingMVX = fishingVX / 0.0458f * std::max(std::min(base*base/12.0f, 1.0f), 0.0f);
		}
		else if ((fishingX < 6.0f && breakerX < 18.0f) && fishingVX < 0)
		{
			base = ((-fishingX + 6.0f) / 1.732f);
			fishingMVX = fishingVX / 0.0458f * std::max(std::min(base*base/12.0f, 1.0f), 0.0f);
		}

		if ((fishingY > 15.0f && breakerY > 5.0f) && fishingVY > 0)
		{
			base = ((fishingY - 15.0f) / 1.581f);
			fishingMVY = fishingVY / 0.0458f * std::max(std::min(base*base/10.0f, 1.0f), 0.0f);
		}
		else if ((fishingY < 5.0f && breakerY < 15.0f) && fishingVY < 0)
		{
			base = ((-fishingY + 5.0f) / 1.581f);
			fishingMVY = fishingVY / 0.0458f * std::max(std::min(base*base/10.0f, 1.0f), 0.0f);
		}

		float mvx = 0, mvy = 0;
		if (fishingMVX > 0 && fishingMVX > breakerMVX)
		{
			mvx = fishingMVX;
		}
		else if (breakerMVX > 0)
		{
			mvx = breakerMVX;
		}
	
		if (fishingMVX < 0 && fishingMVX < breakerMVX)
		{
			mvx = fishingMVX;
		}
		else if (breakerMVX < 0)
		{
			mvx = breakerMVX;
		}

		if (fishingMVY > 0 && fishingMVY > breakerMVY)
		{
			mvy = fishingMVY;
		}
		else if (breakerMVY > 0)
		{
			mvy = breakerMVY;
		}
	
		if (fishingMVY < 0 && fishingMVY < breakerMVY)
		{
			mvy = fishingMVY;
		}
		else if (breakerMVY < 0)
		{
			mvy = breakerMVY;
		}

		mMoveFrame(mvx * deltaTime, mvy * deltaTime);
	
		if (fmod(time, 1) < deltaTime)
			if (mSchools.size() < 25)
			{
				School *s = new School(0x20000000 + mSchoolID++, mFishBase, mOwner);
				float x = (rand() % 1000)/1000.0f * 46/20.0f, y = (rand() % 1000)/1000.0f * 30/20.0f;
				while ((
					x >= mMap->getPos().x && x <= mMap->getPos().x + 24/20.0f && 
					x >= mMap->getPos().x && x <= mMap->getPos().x + 20/20.0f))
				{
					x = (rand() % 1000)/1000.0f * 46/20.0f;
					y = (rand() % 1000)/1000.0f * 30/20.0f;
				}

				s->setPosition(x + 1/10.0f, y + 1/10.0f);
				mSchools.push_back(s);
			}

		for (std::vector<School*>::const_iterator i = mSchools.begin(); i != mSchools.end(); )
		{
			sf::Vector2f pos = (*i)->getPosition();
			if ((*i)->getAmmount() <= 0)
			{
				Angler::Node *n = *i;
				i = mSchools.erase(i);
				delete n;
			}
			else
				i++;
		}

		if (((FishingBoat*)mShipFishing)->getRepairing() && ((IceBreaker*)mShipBreaker)->getHull() < 1)
		{
			((IceBreaker*)mShipBreaker)->repair(0.25 * deltaTime);
			((IceBreaker*)mShipBreaker)->block();
		}
	}
}
