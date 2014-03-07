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
	}
}

void StartScreen::loadContent()
{
	mTextureBG->loadFromFile("start_screen.png");
	mTexturePress->loadFromFile("Press_start.png");
	 
	mMusicIntroBuff->loadFromFile("Intro_Music.wav");

	mMusic->setBuffer(*mMusicIntroBuff);
}

void StartScreen::init()
{
	mTextureBG = new sf::Texture();
	mTexturePress = new sf::Texture();

	mMusic = new sf::Sound();

	mMusicIntroBuff = new sf::SoundBuffer();
}

void StartScreen::mEnable(bool enabled)
{
	if (enabled)
	{
		int sizes[2] = { 1, 1 };
		sf::Texture* textures[2] = { mTextureBG, mTexturePress };
		mOwner->setupGraphicsLayers(2, sizes, textures);

		mOwner->getSound()->playSound(mMusic, false, -1, -1, true);
	}
	else
	{
		mOwner->clearGraphicsLayers();

		mOwner->getSound()->stopSound(mMusic);
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
			graphics->draw(1, sf::Vector2f(0.5f, 0.5f), 1, 1, 1, abs(sin(fmod(time * 1.25f, 2*3.1415f))) * 0.75 + 0.25f);
		glPopMatrix();
	}
}