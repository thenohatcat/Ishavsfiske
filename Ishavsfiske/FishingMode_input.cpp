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

using namespace Ishavsfiske;

int v;

void FishingMode::input(float time, float deltaTime)
{
	// Fishing boat key inputs
	if (mOwner->getKeyboardState().isKeyDown(sf::Keyboard::W))
	{
		mShipFishing->throttle(0, -1 * deltaTime);
	}
	if (mOwner->getKeyboardState().isKeyDown(sf::Keyboard::A))
	{
		mShipFishing->rotate(-90 * deltaTime);
	}
	if (mOwner->getKeyboardState().isKeyDown(sf::Keyboard::S))
	{
		mShipFishing->throttle(0, 1 * deltaTime);
	}
	if (mOwner->getKeyboardState().isKeyDown(sf::Keyboard::D))
	{
		mShipFishing->rotate(90 * deltaTime);
	}

	if (mOwner->getKeyboardState().isKeyDown(sf::Keyboard::Return) && 
		!mOwner->getKeyboardState().wasKeyDown(sf::Keyboard::Return))
	{
		mTutorial->show("A\nB\nC\nD\nE", 2);
	}
	if (mOwner->getKeyboardState().isKeyDown(sf::Keyboard::Space) && 
		!mOwner->getKeyboardState().wasKeyDown(sf::Keyboard::Space))
	{
		mDoRepair = true;
	}

	// Close game key
	if (mOwner->getKeyboardState().wasKeyDown(sf::Keyboard::Escape))
	{
		mOwner->close();
	}
	// Icebreaker key inputs
	if(mOwner->getKeyboardState().isKeyDown(sf::Keyboard::Up))
	{
		mShipBreaker->throttle(0, -1 * deltaTime);
	}
	if(mOwner->getKeyboardState().isKeyDown(sf::Keyboard::Down))
	{
		mShipBreaker->throttle(0, 1 * deltaTime);
	}
	if(mOwner->getKeyboardState().isKeyDown(sf::Keyboard::Left))
	{
		mShipBreaker->rotate(-90 * deltaTime);
	}
	if(mOwner->getKeyboardState().isKeyDown(sf::Keyboard::Right))
	{
		mShipBreaker->rotate(90 * deltaTime);
	}
}