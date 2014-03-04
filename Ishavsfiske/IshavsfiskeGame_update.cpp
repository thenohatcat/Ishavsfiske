//Version: 0.1.4
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_4
#error IshavsfiskeGame_update.cpp: Wrong version 0.1.4
#endif

#include "IshavsfiskeGame.h"
#include "Ship.h"
#include "FishingBoat.h"

#include <Angler\Mechanics.h>
#include <Angler\CollisionNode.h>

#include <Angler\HelpFunctions.h>

#include <iostream>

float av;
unsigned int frm;

float mx = 0, my = 0;
float lastX, lastY;

void Ishavsfiske::IshavsfiskeGame::mMoveFrame(float dx, float dy)
{
	if (mx <= 0 && dx < 0)
		dx = 0;
	else if (mx >= 23 && dx > 0)
		dx = 0;

	if (my <= 0 && dy < 0)
		dy = 0;
	else if (my >= 19 && dy > 0)
		dy = 0;

	if (mx < 0)
		mx = 0;
	else if (mx > 23)
		mx = 23;
	if (my < 0)
		my = 0;
	else if (my > 19)
		my = 19;

	mx += 5 * dx;
	my += 5 * dy;

	if (floor(lastX) != floor(mx))
	{
		mShipBreaker->move((floor(lastX) - floor(mx))/20.0f, 0, true);
		mShipFishing->move((floor(lastX) - floor(mx))/20.0f, 0, true);
		mMap->setPos(sf::Vector2i((int)mx, (int)my));
	}

	lastX = mx;
	lastY = my;

	//printf("Vel: {%03f, %03f}\n", mx, my);
}

void Ishavsfiske::IshavsfiskeGame::mUpdate(float time, float deltaTime)
{
#ifdef _DEBUG
	if (frm < 50)
	{
		frm++;
		av += deltaTime;
	}
	else
	{
		printf("FPS: %04.0f\n", frm/av);
		frm = 0;
		av = 0;
	}
#endif

	//Handle Input
	mInput(time, deltaTime);

	float mvx = 0, mvy = 0;

	float breakerX = ((mShipBreaker->getPosition().x - 4/20.0f) * 20), breakerY = (mShipBreaker->getPosition().y * 20);
	float fishingX = ((mShipFishing->getPosition().x - 4/20.0f) * 20), fishingY = (mShipFishing->getPosition().y * 20);

	mvx = ((breakerX < 6.0f && fishingX < 18.0f) ? -((6-breakerX) * (6-breakerX)) / 36.0f : 0) + 
		((breakerX > 18.0f && fishingX > 6.0f) ? ((6-(24-breakerX)) * (6-(24-breakerX))) / 36.0f : 0) +
		((fishingX < 6.0f && breakerX < 18.0f) ? -((6-fishingX) * (6-fishingX)) / 36.0f : 0) + 
		((fishingX > 18.0f && breakerX > 6.0f) ? ((6-(24-fishingX)) * (6-(24-fishingX))) / 36.0f : 0);
	mvy = ((breakerY < 5.0f && fishingY < 15.0f) ? -((5-breakerY) * (5-breakerY)) / 25.0f : 0) + 
		((breakerY > 15.0f && fishingY > 5.0f) ? ((5-(20-breakerY)) * (5-(20-breakerY))) / 25.0f : 0) +
		((fishingY < 5.0f && breakerY < 15.0f) ? -((5-fishingY) * (5-fishingY)) / 25.0f : 0) + 
		((fishingY > 15.0f && breakerY > 5.0f) ? ((5-(20-fishingY)) * (5-(20-fishingY))) / 25.0f : 0);

	mMoveFrame(mvx * deltaTime, mvy * deltaTime);

	if (fmod(time, 1) < deltaTime)
		if (mSchools.size() < 5)
		{
			School *s = new School(0x20000000 + mSchoolID++, mObjectsRoot, this);
			s->setPosition(((rand() % 1000)/1000.0f) * 12/10.0f + 2/10.0f, (rand() % 1000)/1000.0f);
			mSchools.push_back(s);
			printf("Added school: %04X { %04.2f, %04.2f }\n", s->getID(), s->getPosition().x * 10, s->getPosition().y * 10);
		}

	for (std::vector<School*>::const_iterator i = mSchools.begin(); i != mSchools.end(); )
	{
		if ((*i)->getAmmount() == 0)
		{
			Angler::Node *n = *i;
			i = mSchools.erase(i);
			delete n;
		}
		else
			i++;
	}

	((FishingBoat*)mShipFishing)->setFishing(0, nullptr);
	//Collision system collide
	mMechanics->doCollide(mObjectsRoot);
}