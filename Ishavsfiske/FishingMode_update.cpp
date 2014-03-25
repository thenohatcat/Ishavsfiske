//Version: 0.1.5
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_5
#error FishingMode_update.cpp: Wrong version 0.1.5
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

void FishingMode::mMoveFrame(float fishingDX, float fishingDY, float breakerDX, float breakerDY, bool fishingX, bool fishingY, bool moveMapX, bool moveMapY)
{
	sf::Vector2i mapPos = mMap->getPos();

	if ((fishingDX > 0 && mapPos.x >= 24) || (fishingDX < 0 && mapPos.x <= 0))
		fishingDX = 0;
	if ((fishingDY > 0 && mapPos.y >= 20) || (fishingDY < 0 && mapPos.y <= 0))
		fishingDY = 0;

	if ((breakerDX > 0 && mapPos.x >= 24) || (breakerDX < 0 && mapPos.x <= 0))
		breakerDX = 0;
	if ((breakerDY > 0 && mapPos.y >= 20) || (breakerDY < 0 && mapPos.y <= 0))
		breakerDY = 0;

	if (!moveMapX)
		mShipBreaker->move(-breakerDX, 0, true, true);
	else
		mShipBreaker->move(-(fishingX ? fishingDX : breakerDX), 0, true, true);
		
	if (!moveMapY)
		mShipBreaker->move(0, -breakerDY, true, true);
	else
		mShipBreaker->move(0, -(fishingY ? fishingDY : breakerDY), true, true);

	if (!moveMapX)
		mShipFishing->move(-fishingDX, 0, true, true);
	else
		mShipFishing->move(-(fishingX ? fishingDX : breakerDX), 0, true, true);
		
	if (!moveMapY)
		mShipFishing->move(0, -fishingDY, true, true);
	else
		mShipFishing->move(0, -(fishingY ? fishingDY : breakerDY), true, true);

	if (moveMapX)
	{
		mFishBase->translate(-(fishingX ? fishingDX : breakerDX), 0);
		mMap->move(sf::Vector2f(20 * (fishingX ? fishingDX : breakerDX), 0));
	}

	if (moveMapY)
	{
		mFishBase->translate(0, -(fishingY ? fishingDY : breakerDY));
		mMap->move(sf::Vector2f(0, 20 * (fishingY ? fishingDY : breakerDY)));
	}

	mChanged = true;

	//printf("Vel: {%03f, %03f}\n", mx, my);
}

void FishingMode::update(Angler::Game* context, float time, float deltaTime, bool changed)
{
	if (!mPaused)
	{
		mChanged |= changed;

		mDoRepair = false;
		mDoFish = false;

		input(time, deltaTime);

		mUpdateChildren(context, time, deltaTime);

		sf::Vector2f mousePos = sf::Vector2f(context->getMouseState().getPos());
		mousePos.x /= context->getHeight();
		mousePos.y /= context->getHeight();

		mMenuButtonIsMO = Angler::HelpFunctions::Geometry::pointIsWithinPolygon(&mMenuButtonMOS, mousePos);
		mBackButtonIsMO = Angler::HelpFunctions::Geometry::pointIsWithinPolygon(&mBackButtonMOS, mousePos);

		if (mBackButtonIsMO && !context->getMouseState().isButtonDown(sf::Mouse::Button::Left)
				&& context->getMouseState().wasButtonDown(sf::Mouse::Button::Left))
		{
			mOwner->throwEvent(IshavsfiskeGame::Events::FishingModeHide);
			mOwner->throwEvent(IshavsfiskeGame::Events::HarbourModeShow);
		}

		if (mMenuButtonIsMO || fmod(abs(sin(mMenuButtonRot)), 1.0f) > 0.001f)
			mMenuButtonRot += std::min(3.1415f-fmod(mMenuButtonRot, 3.1415f), 4 * deltaTime);

		mMenuButtonRot = fmod(mMenuButtonRot, 2*3.1415f);

		float fishingMVX = 0, fishingMVY = 0;
		float breakerMVX = 0, breakerMVY = 0;

		float breakerX = ((mShipBreaker->getPosition().x - 4/20.0f) * 20), breakerY = (mShipBreaker->getPosition().y * 20);
		float fishingX = ((mShipFishing->getPosition().x - 4/20.0f) * 20), fishingY = (mShipFishing->getPosition().y * 20);

		float breakerVX = mShipBreaker->getGlobalVelocity().x, breakerVY = mShipBreaker->getGlobalVelocity().y;
		float fishingVX = mShipFishing->getGlobalVelocity().x, fishingVY = mShipFishing->getGlobalVelocity().y;

		bool moveMapX = true, moveMapY = true;

		float base;
		if ((breakerX > 18.0f) && breakerVX > 0)
		{
			base = ((breakerX - 18.0f) / 1.732);
			breakerMVX = breakerVX / 0.0458f * std::max(std::min(base*base/12.0f, 1.0f), 0.0f);
		}
		else if ((breakerX < 6.0f) && breakerVX < 0)
		{
			base = ((-breakerX + 6.0f) / 1.732f);
			breakerMVX = breakerVX / 0.0458f * std::max(std::min(base*base/12.0f, 1.0f), 0.0f);
		}

		if ((breakerY > 15.0f) && breakerVY > 0)
		{
			base = ((breakerY - 15.0f) / 1.581f);
			breakerMVY = breakerVY / 0.0458f * std::max(std::min(base*base/10.0f, 1.0f), 0.0f);
		}
		else if ((breakerY < 5.0f) && breakerVY < 0)
		{
			base = ((-breakerY + 5.0f) / 1.581f);
			breakerMVY = breakerVY / 0.0458f * std::max(std::min(base*base/10.0f, 1.0f), 0.0f);
		}

		if ((fishingX > 18.0f /*&& breakerX > 6.0f*/) && fishingVX > 0)
		{
			base = ((fishingX - 18.0f) / 1.732);
			fishingMVX = fishingVX / 0.0458f * std::max(std::min(base*base/12.0f, 1.0f), 0.0f);
		}
		else if ((fishingX < 6.0f) && fishingVX < 0)
		{
			base = ((-fishingX + 6.0f) / 1.732f);
			fishingMVX = fishingVX / 0.0458f * std::max(std::min(base*base/12.0f, 1.0f), 0.0f);
		}

		if ((fishingY > 15.0f) && fishingVY > 0)
		{
			base = ((fishingY - 15.0f) / 1.581f);
			fishingMVY = fishingVY / 0.0458f * std::max(std::min(base*base/10.0f, 1.0f), 0.0f);
		}
		else if ((fishingY < 5.0f) && fishingVY < 0)
		{
			base = ((-fishingY + 5.0f) / 1.581f);
			fishingMVY = fishingVY / 0.0458f * std::max(std::min(base*base/10.0f, 1.0f), 0.0f);
		}

		if ((fishingY < 5.0f && breakerY > 15.0f) || (fishingY > 15.0f && breakerY < 5.0f) ||
			(breakerY < 5.0f && fishingY > 15.0f) || (breakerY > 15.0f && fishingY < 5.0f))
		{
			moveMapY = false;
		}

		if ((fishingX < 6.0f && breakerX > 18.0f) || (fishingX > 18.0f && breakerX < 6.0f) ||
			(breakerX < 6.0f && fishingX > 18.0f) || (breakerX > 18.0f && fishingX < 6.0f))
		{
			moveMapX = false;
		}

		bool dFishingX = false, dFishingY = false;
		float mvx = 0, mvy = 0;
		
		if ((fishingMVX > 0 && breakerMVX >= 0 && fishingMVX > breakerMVX) || (fishingMVX < 0 && breakerMVX <= 0 && fishingMVX < breakerMVX))
		{
			dFishingX = true;
		}
		else if ((fishingMVX < 0 && breakerMVX > 0) || (fishingMVX > 0 && breakerMVX < 0))
		{
			moveMapX = false;
		}

		if ((fishingMVY > 0 && breakerMVY >= 0 && fishingMVY > breakerMVY) || (fishingMVY < 0 && breakerMVY <= 0 && fishingMVY < breakerMVY))
		{
			dFishingY = true;
		}
		else if ((fishingMVY < 0 && breakerMVY > 0) || (fishingMVY > 0 && breakerMVY < 0))
		{
			moveMapY = false;
		}

		if (!mMapFrozen)
		{
			mMoveFrame(
				fishingMVX * deltaTime, fishingMVY * deltaTime,
				breakerMVX * deltaTime, breakerMVY * deltaTime, 
				dFishingX, dFishingY, moveMapX, moveMapY);
		}
	
		if (((IceBreaker*)mShipBreaker)->getHealth() <= 0 || mTimer <= 0)
		{
			pause(true);
			mOwner->throwEvent(IshavsfiskeGame::GameOverScreenShow);
		}

		if (mSpawnFish)
			if (fmod(time, 1) < deltaTime)
				if (mSchools.size() < 25)
				{
					School *s = new School(0x20000000 + mSchoolID++, mFishBase, mOwner);
					float x = (rand() % 1000)/1000.0f * 46/20.0f, y = (rand() % 1000)/1000.0f * 30/20.0f;
					/*while ((
						x >= mMap->getPos().x/20.0f && x <= mMap->getPos().x/20.0f + 24/20.0f && 
						y >= mMap->getPos().y/20.0f && y <= mMap->getPos().y/20.0f + 20/20.0f))
					{
						x = (rand() % 1000)/1000.0f * 46/20.0f;
						y = (rand() % 1000)/1000.0f * 30/20.0f;
					}*/

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

		if(mSpawnSeagull)
		{
			if(fmod(time, 1) < deltaTime)
				if(mSeagulls.size() < 20)
				{
					Seagull *sg = new Seagull(0x40000000 + 0x10000 * mSeagullID++, mSeagullBase, mOwner);
					float x = (rand() % 1000)/1000.0f * 46/20.0f, y = (rand() % 1000)/1000.0f * 30/20.0f;

					
					sg->setPosition(x + 1/10.0f, y + 1/10.0f);
					mSeagulls.push_back(sg);
				}
		}

		if (mRunTimer)
			mTimer = std::max(0.0f, mTimer - deltaTime);

#ifdef _TUTORIAL
		mUpdateTutorial(context, time, deltaTime);
#else
		mCanFish = true;
		mCanRepair = true;
		mShowCounter = true;
		mShowTimer = true;
		mMapFrozen = false;
		mRunTimer = true;
		mSpawnFish = true;
		mSpawnSeagull = true;
#endif

		if (((FishingBoat*)mShipFishing)->getRepairing() && ((IceBreaker*)mShipBreaker)->getHull() < 1)
		{
			((IceBreaker*)mShipBreaker)->repair(0.25 * deltaTime);
			((IceBreaker*)mShipBreaker)->block();
		}
	}
}
