//Version: 0.1.5
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_5
#error HarbourMode_init.cpp: Wrong version 0.1.5
#endif

#include "IshavsfiskeGame.h"
#include "HarbourMode.h"

using namespace Ishavsfiske;

HarbourMode::HarbourMode(unsigned long id, Angler::Node *parent, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id, parent), mOwner(owner)
{

}

HarbourMode::HarbourMode(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id), mOwner(owner)
{

}

void HarbourMode::draw(Angler::Game* context, Angler::Graphics::GraphicsEngine* graphics, float time, float deltaTime)
{
	if (mVisible)
	{
		graphics->draw(0);

		mDrawChildren(context, graphics, time, deltaTime);
	}
}

void HarbourMode::update(Angler::Game* context, float time, float deltaTime, bool changed)
{
	if (!mPaused)
	{
		mChanged |= changed;

		mUpdateChildren(context, time, deltaTime);
	}
}

void HarbourMode::loadContent()
{
	mTXHarbour->loadFromFile("staden_6.png");
}

void HarbourMode::init()
{
	mTXHarbour = new sf::Texture();
}

void HarbourMode::mEnable(bool enabled)
{
	if (enabled)
	{
		int sizes[1] = { 1 };
		sf::Texture* textures[1] = { mTXHarbour };
		mOwner->setupGraphicsLayers(1, sizes, textures);
	}
	else
	{
		mOwner->clearGraphicsLayers();
	}
}

void HarbourMode::showRoom(int ind)
{

}