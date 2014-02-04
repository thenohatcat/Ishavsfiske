//Version: 0.1.2
//Author: Sihao Li
//Contributors: 

#ifndef ISHAV_0_1_2
#error IshavsfiskeGame_input.cpp: Wrong version 0.1.2
#endif

#include "IshavsfiskeGame.h"

#include "Ship.h"

#include <Angler\Keyboard.h>

void Ishavsfiske::IshavsfiskeGame::mInput(float time, float deltaTime)
{
	if (getKeyboardState().isKeyDown(sf::Keyboard::W))
	{
		mShip->move(0, -0.5 * deltaTime);
	}
	if (getKeyboardState().isKeyDown(sf::Keyboard::A))
	{
		mShip->rotate(-90 * deltaTime);
	}
	if (getKeyboardState().isKeyDown(sf::Keyboard::S))
	{
		mShip->move(0, 0.5 * deltaTime);
	}
	if (getKeyboardState().isKeyDown(sf::Keyboard::D))
	{
		mShip->rotate(90 * deltaTime);
	}
}