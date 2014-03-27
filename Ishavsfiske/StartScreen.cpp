//Version: 0.1.5
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_5
#error StartScreen_draw.cpp: Wrong version 0.1.5
#endif

#include "StartScreen.h"
#include "IshavsfiskeGame.h"

using namespace Ishavsfiske;

StartScreen::StartScreen(unsigned long id, Angler::Node *parent, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id, parent), mOwner(owner), mStartMO(false), mQuitMO(false)
{

}

StartScreen::StartScreen(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id), mOwner(owner), mStartMO(false), mQuitMO(false)
{

}

void StartScreen::input(float time, float deltaTime)
{
	/*if (mOwner->getKeyboardState().getIsNumKeysDown() > mOwner->getKeyboardState().getWasNumKeysDown())
	{
		mOwner->throwEvent(IshavsfiskeGame::Events::StartScreenHide);
		mOwner->throwEvent(IshavsfiskeGame::Events::HarbourModeShow);
	}*/

	if (mOwner->getMouseState().isButtonDown(sf::Mouse::Button::Left) && !mOwner->getMouseState().wasButtonDown(sf::Mouse::Button::Left))
	{
		if (mStartMO)
		{
			mOwner->throwEvent(IshavsfiskeGame::Events::StartScreenHide);
			mOwner->throwEvent(IshavsfiskeGame::Events::HarbourModeShow);
		}
		else if (mQuitMO)
		{
			mOwner->close();
		}
	}
}

void StartScreen::loadContent()
{
	mTextureBG->loadFromFile("huvdmeny copy.png");
	mTextureMenu->loadFromFile("Meny_Sprite copy.png"); 
	mTextureCursor->loadFromFile("cursor_hand_sheet.png");

	mMusicIntroBuff->loadFromFile("Intro.ogg");

	mMusic->setBuffer(*mMusicIntroBuff);
}

void StartScreen::init()
{
	mTextureBG = new sf::Texture();
	mTextureMenu = new sf::Texture();
	mTextureCursor = new sf::Texture();

	mMusic = new sf::Sound();

	mMusicIntroBuff = new sf::SoundBuffer();
}

void StartScreen::mEnable(bool enabled)
{
	if (enabled)
	{
		int sizes[3] = { 1, 32, 1 };
		sf::Texture* textures[3] = { mTextureBG, mTextureMenu, mTextureCursor };
		mOwner->setupGraphicsLayers(3, sizes, textures);

		mOwner->getGraphics()->setCursorVisible(false);

		mOwner->getSound()->playSound(mMusic, false, 0x00001, true);
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

		sf::Vector2f mousePos = sf::Vector2f(context->getMouseState().getPos()) / (float)context->getHeight();

		mStartMO = (mousePos.x > (0.8f - 365/2000.0f) && mousePos.x < (0.8f + 365/2000.0f)) && (mousePos.y > 0.5f && mousePos.y < (0.5f + 49.75f/1000.0f));
		mQuitMO = (mousePos.x > (0.8f - 365/2000.0f) && mousePos.x < (0.8f + 365/2000.0f)) && (mousePos.y > (0.5f + 49.75f/1000.0f) && mousePos.y < (0.5f + 2 * 49.75f/1000.0f));

		mUpdateChildren(context, time, deltaTime);
	}
}

void StartScreen::draw(Angler::Game* context, Angler::Graphics::GraphicsEngine* graphics, float time, float deltaTime)
{
	if (mVisible)
	{
		graphics->draw(0);

		if (time > 0)
		{
			sf::Vector2f mousePos = sf::Vector2f(context->getMouseState().getPos()) / (float)context->getHeight();

			//Menu
			glPushMatrix();
				glTranslatef(0.8f, 0.5f, 0);
				glScalef(49.75f/1000.0f, 49.75f/1000.0f, 1.0f);
				glTranslatef(0, 0, 0);
				graphics->draw(1, sf::Vector2f(0.5f, 0), 
					sf::Vector2f(0, (mStartMO ? 8 : 0) * 49.75f/1000.0f), 
					sf::Vector2f(365/1600.0f, 49.75f/1000.0f));
			glPopMatrix();

			glPushMatrix();
				glTranslatef(0.8f, 0.5f, 0);
				glScalef(49.75f/1000.0f, 49.75f/1000.0f, 1.0f);
				glTranslatef(0, 1, 0);
				graphics->draw(1, sf::Vector2f(0.5f, 0), 
					sf::Vector2f(0, (mQuitMO ? 12 : 4) * 49.75f/1000.0f), 
					sf::Vector2f(365/1600.0f, 49.75f/1000.0f));
			glPopMatrix();

			//Cursor
			glPushMatrix();
				glTranslatef(mousePos.x, mousePos.y, 0);
				glScalef(62/1000.0f, 62/1000.0f, 1.0f);
				graphics->draw(2, sf::Vector2f(0.35f, 0), sf::Vector2f((context->getMouseState().isButtonDown(sf::Mouse::Button::Left) ? 0.5f : 0.0f), 0), sf::Vector2f(0.5f, 1));
			glPopMatrix();
/*
			glPushMatrix();
				glScalef(1/20.0f, 1/20.0f, 1);
				glTranslatef(16, 12, 0);
				graphics->draw(1, sf::Vector2f(0.5f, 0.5f), 1, 1, 1, abs(sin(fmod(time * 1.25f, 2*3.1415f))) * 0.75f + 0.25f);
			glPopMatrix();*/
		}
	}
}