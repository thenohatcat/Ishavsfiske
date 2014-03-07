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
		pause(true);

		mOwner->getSound()->stopSound(mSeaAmbient);
		mOwner->getSound()->stopSound(mMusic);
		mOwner->getSound()->stopSound(mEngineSound);

		mOwner->throwEvent(IshavsfiskeGame::Events::GameOverScreenShow);
	}

	if (mOwner->getKeyboardState().isKeyDown(sf::Keyboard::Q) &&
		mOwner->getKeyboardState().isKeyDown(sf::Keyboard::E))
	{
		mMap->genMap(1, v = 0);
		mMap->setTile(49, 0x20);
	}
	else if (mOwner->getKeyboardState().isKeyDown(sf::Keyboard::Q) &&
		!mOwner->getKeyboardState().wasKeyDown(sf::Keyboard::Q))
	{
		 mMap->genMap(1, v -= 4);
		 mMap->setTile(49, 0x20);
	}
	else if (mOwner->getKeyboardState().isKeyDown(sf::Keyboard::E) &&
		!mOwner->getKeyboardState().wasKeyDown(sf::Keyboard::E))
	{
		mMap->genMap(1, v += 4);
		mMap->setTile(49, 0x20);
	}

	printf("%u\n", v);

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