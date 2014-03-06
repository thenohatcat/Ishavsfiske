//Version: 0.1.4
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_4
#error IshavsfiskeGame_init.cpp: Wrong version 0.1.4
#endif

#include "IshavsfiskeGame.h"

#include <SFML\Audio.hpp>

#include <Angler\DrawNode.h>
#include <Angler\SpriteNode.h>
#include <Angler\Scale.h>

#include "Ship.h"
#include "FishingBoat.h"
#include "IceBreaker.h"

#include "School.h"
#include "Font.h"

void Ishavsfiske::IshavsfiskeGame::clearGraphicsLayers()
{
	mGraphics->clearLayers();
}

void Ishavsfiske::IshavsfiskeGame::setupGraphicsLayers(int numLayers, int layerSizes[], sf::Texture *layerTextures[])
{
	clearGraphicsLayers();
	for (int i = 0; i < numLayers; i++)
	{
		mGraphics->addLayer(layerSizes[i]);
		mGraphics->getLayer(i)->setTexture(layerTextures[i]);
	}
}

void Ishavsfiske::IshavsfiskeGame::mLoadContent()
{
	mFishingMode->loadContent();

	mFishingMode->enable(true);
}

void Ishavsfiske::IshavsfiskeGame::mInit()
{
	mObjectsRoot = new Angler::Node(0, mSceneRoot);
	mUIRoot = new Angler::Node(0, mSceneRoot);

	mFishingMode = new FishingMode(0, mObjectsRoot, this);
	mFishingMode->init();

	mFont = new Font();
}