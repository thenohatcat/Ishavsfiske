//Version: 0.1.2
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_2
#error IshavsfiskeGame_init.cpp: Wrong version 0.1.2
#endif

#include "IshavsfiskeGame.h"

#include "Ship.h"

void Ishavsfiske::IshavsfiskeGame::mLoadContent()
{
	mTX->loadFromFile("GasPlanet2.png");
}

void Ishavsfiske::IshavsfiskeGame::mInit()
{
	mTX = new sf::Texture();
	mShip = new Ship(0x10000, mSceneRoot, mTX, this);
}