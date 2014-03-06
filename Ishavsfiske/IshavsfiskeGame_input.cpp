//Version: 0.1.4
//Author: Sihao Li
//Contributors: 

#ifndef ISHAV_0_1_4
#error IshavsfiskeGame_input.cpp: Wrong version 0.1.4
#endif

#include "IshavsfiskeGame.h"

#include "Ship.h"

#include <Angler\Keyboard.h>

#include <iostream>

using namespace std;


void Ishavsfiske::IshavsfiskeGame::mInput(float time, float deltaTime)
{
	mFishingMode->input(time, deltaTime);
}