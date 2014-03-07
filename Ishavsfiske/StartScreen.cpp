//Version: 0.1.4
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_4
#error StartScreen_draw.cpp: Wrong version 0.1.4
#endif

#include "StartScreen.h"
#include "IshavsfiskeGame.h"

using namespace Ishavsfiske;

StartScreen::StartScreen(unsigned long id, Angler::Node *parent, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id, parent), mOwner(owner)
{

}

StartScreen::StartScreen(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id), mOwner(owner)
{

}

void StartScreen::input(float time, float deltaTime)
{
	if (mOwner->getKeyboardState().getIsNumKeysDown() > mOwner->getKeyboardState().getWasNumKeysDown())
	{
		mOwner->throwEvent(IshavsfiskeGame::Events::StartScreenHide);
		mOwner->throwEvent(IshavsfiskeGame::Events::FishingModeShow);
		mOwner->throwEvent(IshavsfiskeGame::Events::GameOverScreenShow);
	}
}

void StartScreen::loadContent()
{
	mTextureBG->loadFromFile("start_screen.png");
	mTexturePress->loadFromFile("Press_start.png");
}

void StartScreen::init()
{
	mTextureBG = new sf::Texture();
	mTexturePress = new sf::Texture();
}

void StartScreen::mEnable(bool enabled)
{
	if (enabled)
	{
		int sizes[2] = { 1, 1 };
		sf::Texture* textures[2] = { mTextureBG, mTexturePress };
		mOwner->setupGraphicsLayers(2, sizes, textures);
	}
	else
	{
		mOwner->clearGraphicsLayers();
	}
}

void StartScreen::update(Angler::Game* context, float time, float deltaTime, bool changed)
{
	if (!mPaused)
	{
		mChanged |= changed;

		input(time, deltaTime);

		mUpdateChildren(context, time, deltaTime);
	}
}

void StartScreen::draw(Angler::Game* context, Angler::Graphics::GraphicsEngine* graphics, float time, float deltaTime)
{
	if (mVisible)
	{
		graphics->draw(0);

		glPushMatrix();
			glScalef(1/20.0f, 1/20.0f, 1);
			glTranslatef(16, 12, 0);
			graphics->draw(1, sf::Vector2f(0.5f, 0.5f), 1, 1, 1, sin(fmod(time * 1.5f, 3.1415f)) / 2.0f + 0.5f);
		glPopMatrix();
	}
}