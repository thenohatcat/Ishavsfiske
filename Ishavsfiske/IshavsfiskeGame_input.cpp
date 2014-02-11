//Version: 0.1.3
//Author: Sihao Li
//Contributors: 

#ifndef ISHAV_0_1_3
#error IshavsfiskeGame_input.cpp: Wrong version 0.1.3
#endif

#include "IshavsfiskeGame.h"

#include "Ship.h"

#include <Angler\Keyboard.h>

#include <iostream>

using namespace std;


void Ishavsfiske::IshavsfiskeGame::mInput(float time, float deltaTime)
{
	if (getKeyboardState().isKeyDown(sf::Keyboard::W))
	{
		mShipFishing->throttle(0, -1 * deltaTime);
	}
	if (getKeyboardState().isKeyDown(sf::Keyboard::A))
	{
		mShipFishing->rotate(-90 * deltaTime);
	}
	if (getKeyboardState().isKeyDown(sf::Keyboard::S))
	{
		mShipFishing->throttle(0, 1 * deltaTime);
	}
	if (getKeyboardState().isKeyDown(sf::Keyboard::D))
	{
		mShipFishing->rotate(90 * deltaTime);
	}
	if (getKeyboardState().wasKeyDown(sf::Keyboard::Escape))
	{
		mGraphics->close();
	}
}