//Version: 0.1.4
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_4
#error IshavsfiskeGame_update.cpp: Wrong version 0.1.4
#endif

#include "IshavsfiskeGame.h"
#include "Ship.h"

#include <Angler\Mechanics.h>
#include <Angler\CollisionNode.h>

#include <Angler\HelpFunctions.h>

#include <iostream>

float av;
unsigned int frm;

float mx = 0, my = 0;
float lastX, lastY;

void Ishavsfiske::IshavsfiskeGame::mUpdate(float time, float deltaTime)
{
//#ifdef _DEBUG
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
	//printf("FPS: %04.0f\n", 1/deltaTime);
//#endif

	//Handle Input
	mInput(time, deltaTime);

	float mvx = 0, mvy = 0;

	float breakerX = ((mShipBreaker->getPosition().x - 4/20.0f) * 20), breakerY = (mShipBreaker->getPosition().y * 20);
	
	//Left
	if (breakerX < 6.0f)
	{
		mvx = -((6-breakerX) * (6-breakerX)) / 36.0f;
	}
	else if (breakerX > 18.0f)
	{
		mvx = ((6-(24-breakerX)) * (6-(24-breakerX))) / 36.0f;
	}

	if (breakerY < 5.0f)
	{
		mvy = -((5-breakerY) * (5-breakerY)) / 25.0f;
	}
	else if (breakerY > 15.0f)
	{
		mvy = ((5-(20-breakerY)) * (5-(20-breakerY))) / 25.0f;
	}

	mvx *= deltaTime;
	mvy *= deltaTime;

	if (mx <= 0 && mvx < 0)
		mvx = 0;
	else if (mx >= 23 && mvx > 0)
		mvx = 0;

	if (my <= 0 && mvy < 0)
		mvy = 0;
	else if (my >= 19 && mvy > 0)
		mvy = 0;

	if (mx < 0)
		mx = 0;
	else if (mx > 23)
		mx = 23;
	if (my < 0)
		my = 0;
	else if (my > 19)
		my = 19;

	mx += 5 * mvx;
	my += 5 * mvy;

	if (floor(lastX) != floor(mx))
	{
		mShipBreaker->move((floor(lastX) - floor(mx))/20.0f, 0, true);
		mShipFishing->move((floor(lastX) - floor(mx))/20.0f, 0, true);
	}

	mMap->setPos(sf::Vector2i((int)mx, (int)my));

	lastX = mx;
	lastY = my;

	printf("Vel: {%03f, %03f}\n", mx, my);

	//Collision system collide
	mMechanics->doCollide(mSceneRoot);
}