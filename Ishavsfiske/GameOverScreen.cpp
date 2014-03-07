//Version: 0.1.4
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_4
#error GameOverScreen_draw.cpp: Wrong version 0.1.4
#endif

#include "GameOverScreen.h"
#include "IshavsfiskeGame.h"

using namespace Ishavsfiske;

GameOverScreen::GameOverScreen(unsigned long id, Angler::Node *parent, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id, parent), mOwner(owner)
{

}

GameOverScreen::GameOverScreen(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id), mOwner(owner)
{

}

void GameOverScreen::input(float time, float deltaTime)
{
	// Close game key
	if (mOwner->getKeyboardState().wasKeyDown(sf::Keyboard::Escape))
	{
		mOwner->close();
	}
}

void GameOverScreen::loadContent()
{

}

void GameOverScreen::init()
{
	
}

void GameOverScreen::mEnable(bool enabled)
{

}

void GameOverScreen::update(Angler::Game* context, float time, float deltaTime, bool changed)
{
	if (!mPaused)
	{
		mChanged |= changed;

		input(time, deltaTime);

		mUpdateChildren(context, time, deltaTime);
	}
}

void GameOverScreen::draw(Angler::Game* context, Angler::Graphics::GraphicsEngine* graphics, float time, float deltaTime)
{
	if (mVisible)
	{
		graphics->draw(8);
	}
}