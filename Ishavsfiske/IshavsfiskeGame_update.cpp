//Version: 0.1.0
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_0
#error IshavsfiskeGame_update.cpp: Wrong version 0.1.0
#endif

#include "IshavsfiskeGame.h"
#include "Ship.h"

void Ishavsfiske::IshavsfiskeGame::mUpdate(float time, float deltaTime)
{
	mSceneRoot->update(this, time, deltaTime);

	//Handle Input
	input(time, deltaTime);

	//Collision system collide

}