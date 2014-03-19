//Version: 0.1.5
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_5
#error IshavsfiskeGame_init.cpp: Wrong version 0.1.5
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
	mFishingMode->enable(false);

	mStartScreen->loadContent();
	mStartScreen->enable(false);

	mGameOverScreen->loadContent();
	mGameOverScreen->enable(false);

	mHarbourMode->loadContent();
	mHarbourMode->enable(true);

	mFishingMode->getMap()->load(0, "map_test.txt");
}

void Ishavsfiske::IshavsfiskeGame::mInit()
{
	mObjectsRoot = new Angler::Node(0, mSceneRoot);
	mUIRoot = new Angler::Node(0, mSceneRoot);

	mFishingMode = new FishingMode(0, mObjectsRoot, this);
	mFishingMode->init();

	mStartScreen = new StartScreen(0, mObjectsRoot, this);
	mStartScreen->init();

	mGameOverScreen = new GameOverScreen(0, mObjectsRoot, this);
	mGameOverScreen->init();

	mHarbourMode = new HarbourMode(0, mObjectsRoot, this);
	mHarbourMode->init();

	mFont = new Font();
}