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

	//Collision system collide
	mMechanics->doCollide(mSceneRoot);
}