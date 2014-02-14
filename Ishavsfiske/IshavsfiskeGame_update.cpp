//Version: 0.1.3
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_3
#error IshavsfiskeGame_update.cpp: Wrong version 0.1.3
#endif

#include "IshavsfiskeGame.h"
#include "Ship.h"

#include <Angler\Mechanics.h>
#include <Angler\CollisionNode.h>

#include <Angler\HelpFunctions.h>

#include <iostream>

float av;
unsigned int frm;

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

	mSceneRoot->update(this, time, deltaTime);

	//Handle Input
	mInput(time, deltaTime);

	sf::Vector2f va = mShipBreaker->getVelocity();
	float vel = sqrt(va.x*va.x + va.y*va.y);

	if (vel > 0.025)
	{
		if (mEngineSound->getPlayingOffset().asSeconds() > 3.295)
		{
			mEngineSound->setPlayingOffset(sf::Time(sf::seconds(1.843)));
		}
		else if (mEngineSound->getPlayingOffset().asSeconds() < 1.843)
		{
			mEngineSound->setPlayingOffset(sf::Time(sf::seconds(1.843)));
		}
	}
	else
	{
		if (mEngineSound->getPlayingOffset().asSeconds() > 1.45)
		{
			mEngineSound->setPlayingOffset(sf::Time(sf::seconds(0)));
		}
	}


	//Collision system collide
	mMechanics->doCollide(mSceneRoot);
}