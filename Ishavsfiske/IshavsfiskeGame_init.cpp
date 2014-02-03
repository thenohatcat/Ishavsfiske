//Version: 0.1.0
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_0
#error IshavsfiskeGame_init.cpp: Wrong version 0.1.0
#endif

#include "IshavsfiskeGame.h"

#include "Ship.h"

void Ishavsfiske::IshavsfiskeGame::mLoadContent()
{
	tx->loadFromFile("GasPlanet2.png");
}

void Ishavsfiske::IshavsfiskeGame::mInit()
{
	tx = new sf::Texture();
	mShip = new Ship(0x10000, mSceneRoot, tx, this);
}