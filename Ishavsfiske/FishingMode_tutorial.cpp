//Version: 0.1.5
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_5
#error FishingMode_tutorial.cpp: Wrong version 0.1.5
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

void FishingMode::mUpdateTutorial(Angler::Game* context, float time, float deltaTime)
{
	//Wait 5 sec
	if (mTutorialStage == 0)
	{
		if (mTutorialStageTime <= 0)
		{
			mShipBreaker->setPosition(sf::Vector2f(0.0f, 0.0f));

			mShipFishing->setPosition(sf::Vector2f(0.8f, 0.5f));

			mMap->setPos(sf::Vector2i(12, 10));
			mFishBase->setTranslation(-12/20.0f, -10/20.0f);

			mMap->genMap(3);

			mTutorialStageTime = 0;
		}

		mShipBreaker->block();
		mShipFishing->block();

		if (mTutorialStageTime >= 0.5f)
		{
			mTutorialStage = 1;
			mTutorialStageTime = -1;
		}
		mTutorialStageTime += deltaTime;
	}
	//Show first slide
	else if (mTutorialStage == 1)
	{
		mShipBreaker->block();
		mShipFishing->block();

		if (mTutorialStageTime <= 0)
		{
			((IshavsfiskeGame*)context)->getMSGBox()->show(
				"Lars: I take it you know how to turn the boat at \nleast?\n"
				"Elias: Of course I do, watch this!\n"
				" (Use WASD to steer the Fishing Boat)\n\n"
				"                              (Space to continue)", 6, 7, 3600.0f);
			mTutorialStageTime = 0;
		}
		else if (mTutorialStageTime >= 0.5f)
		{
			mTutorialStage = 2;
		}

		mTutorialStageTime += deltaTime;
	}
	else if (mTutorialStage == 2)
	{
		mShipBreaker->block();
		mShipFishing->block();

		mTutorialStageTime += deltaTime;
	}
	else if (mTutorialStage == 3)
	{
		mShipBreaker->block();

		if (mTutorialStageTime <= 0)
		{
			((IshavsfiskeGame*)context)->getMSGBox()->hide();
			mTutorialStageTime = 0;
		}
		else if (mTutorialStageTime >= 5.0f)
		{
			mTutorialStage = 4;
			mTutorialStageTime = -1;
		}

		mTutorialStageTime += deltaTime;
	}
	else if (mTutorialStage == 4)
	{
		mShipBreaker->block();
		mShipFishing->block();

		if (mTutorialStageTime <= 0)
		{
			mShipFishing->setPosition(sf::Vector2f(-0.2f, 0.0f));
			mShipFishing->setRotation(0);
			mShipBreaker->setPosition(sf::Vector2f(0.8f, 0.5f));
			mShipBreaker->setRotation(0);

			((IshavsfiskeGame*)context)->getMSGBox()->show(
				"Lars: Check this out, I´ll aim for the ice!?\n"
				" (Use the arrow keys to steer the Ice Breaker)\n\n\n\n"
				"                              (Space to continue)", 6, 7, 3600.0f);

			mMap->setTile(12 + (24+2)*5 + 1, 0x10);

			mTutorialStageTime = 0;
		}
		else if (mTutorialStageTime >= 0.5f)
		{
			mTutorialStage = 5;
		}

		mTutorialStageTime += deltaTime;
	}
	else if (mTutorialStage == 5)
	{
		mShipBreaker->block();
		mShipFishing->block();

		mTutorialStageTime += deltaTime;
	}
	else if (mTutorialStage == 6)
	{
		mShipFishing->block();

		if (mTutorialStageTime <= 0)
		{
			((IshavsfiskeGame*)context)->getMSGBox()->hide();
			mTutorialStageTime = 0;
		}

		mTutorialStageTime += deltaTime;
	}
	else if (mTutorialStage == 7)
	{
		mShipBreaker->block();

		if (mTutorialStageTime <= 0)
		{
			mTutorialStageTime = 0;
		}
		if (mTutorialStageTime >= 1.0f)
		{
			mTutorialStage = 8;
			mTutorialStageTime = -1;
		}

		mTutorialStageTime += deltaTime;
	}
	else if (mTutorialStage == 8)
	{
		mShipBreaker->block();
		mShipFishing->block();

		mShipBreaker->setPosition(sf::Vector2f(0.8f, 0.5f));
		mShipBreaker->setRotation(0);

		if (mTutorialStageTime <= 0)
		{
			mMap->genMap(1);

			mShipFishing->setPosition(sf::Vector2f(0.7f, 0.5f));
			mShipFishing->setRotation(0);
			mShipBreaker->setPosition(sf::Vector2f(0.9f, 0.5f));
			mShipBreaker->setRotation(0);

			((IshavsfiskeGame*)context)->getMSGBox()->show(
				"Lars: &#¤%!!!\n"
				"Elias: What is it?\n"
				"Lars: I think I overdid it, something broke..\n"
				"Elias: Should we turn back?\n"
				"Lars: Turn back?! It´s just a minor setback.\n"
				"                              (Space to continue)", 6, 7, 3600.0f);

			mTutorialStageTime = 0;
		}
		else if (mTutorialStageTime >= 0.5f)
		{
			mTutorialStage = 9;
		}

		mTutorialStageTime += deltaTime;
	}
	else if (mTutorialStage == 9)
	{
		mShipBreaker->block();
		mShipFishing->block();

		mTutorialStageTime += deltaTime;
	}
	else if (mTutorialStage == 10)
	{
		mShipBreaker->block();
		mShipFishing->block();

		mShipBreaker->setPosition(sf::Vector2f(0.8f, 0.5f));
		mShipBreaker->setRotation(0);

		if (mTutorialStageTime <= 0)
		{
			((IshavsfiskeGame*)context)->getMSGBox()->show(
				"The tool box is on your boat, come over here and \nfix me up!\n"
				" (Press SPACE next to the Breaker to repair)\n\n\n"
				"                              (Space to continue)", 6, 7, 3600.0f);

			mTutorialStageTime = 0;
		}
		else if (mTutorialStageTime >= 0.5f)
		{
			mTutorialStage = 11;
		}

		mTutorialStageTime += deltaTime;
	}
	else if (mTutorialStage == 11)
	{
		mShipBreaker->block();
		mShipFishing->block();

		mTutorialStageTime += deltaTime;
	}
	else if (mTutorialStage == 12)
	{
		mShipBreaker->block();

		if (mTutorialStageTime <= 0)
		{
			((IshavsfiskeGame*)context)->getMSGBox()->hide();
			mTutorialStageTime = 0;
		}

		mTutorialStageTime += deltaTime;
	}
	else if (mTutorialStage == 13)
	{
		mShipBreaker->block();

		if (mTutorialStageTime <= 0)
		{
			mTutorialStageTime = 0;
		}
		if (mTutorialStageTime >= 1.0f)
		{
			mTutorialStage = 14;
			mTutorialStageTime = -1;
		}

		mTutorialStageTime += deltaTime;
	}
	else if (mTutorialStage == 14)
	{
		mShipBreaker->block();
		mShipFishing->block();

		if (mTutorialStageTime <= 0)
		{
			mShipBreaker->setPosition(sf::Vector2f(-0.2f, 0.0f));
			mShipBreaker->setRotation(0);
			mShipFishing->setPosition(sf::Vector2f(0.8f, 0.5f));
			mShipFishing->setRotation(0);

			School *s = new School(0x20000000 + mSchoolID++, mFishBase, mOwner);
			s->setPosition(0.8f, 0.3f);
			mSchools.push_back(s);

			((IshavsfiskeGame*)context)->getMSGBox()->show(
				"Lars: Time to earn some money! Don´t just sit \nthere, get fishing!\n"
				" (Press SPACE next to some fish)\n\n\n"
				"                              (Space to continue)", 6, 7, 3600.0f);

			mTutorialStageTime = 0;
		}
		else if (mTutorialStageTime >= 0.5f)
		{
			mTutorialStage = 15;
		}

		mTutorialStageTime += deltaTime;
	}
	else if (mTutorialStage == 15)
	{
		mShipBreaker->block();
		mShipFishing->block();

		mTutorialStageTime += deltaTime;
	}
	else if (mTutorialStage == 16)
	{
		mShipBreaker->block();

		if (mTutorialStageTime <= 0)
		{
			((IshavsfiskeGame*)context)->getMSGBox()->hide();
			mTutorialStageTime = 0;
		}

		mTutorialStageTime += deltaTime;
	}
	else if (mTutorialStage == 17)
	{
		mShipBreaker->block();

		if (mTutorialStageTime <= 0)
		{
			mTutorialStageTime = 0;
		}
		if (mTutorialStageTime >= 2.0f)
		{
			mTutorialStage = 18;
			mTutorialStageTime = -1;
		}

		mTutorialStageTime += deltaTime;
	}
	else if (mTutorialStage == 18)
	{
		if (mTutorialStageTime <= 0)
		{
			mShipFishing->setPosition(sf::Vector2f(0.7f, 0.5f));
			mShipFishing->setRotation(0);
			mShipBreaker->setPosition(sf::Vector2f(0.9f, 0.5f));
			mShipBreaker->setRotation(0);

			while (mSchools.size() > 0)
			{
				delete mSchools.back();
				mSchools.pop_back();
			}

			mMap->genMap(3);
			mMap->setTile(27, 0x10);

			mTimer = 120;

			mTutorialStageTime = 0;
		}

		mTutorialStageTime += deltaTime;
	}

	if (((FishingBoat*)mShipFishing)->getRepairing() && ((IceBreaker*)mShipBreaker)->getHull() < 1)
	{
		((IceBreaker*)mShipBreaker)->repair(0.25f * deltaTime);
		((IceBreaker*)mShipBreaker)->block();
	}
}
