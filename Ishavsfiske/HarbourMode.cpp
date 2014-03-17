//Version: 0.1.5
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_5
#error HarbourMode_init.cpp: Wrong version 0.1.5
#endif

#include <Angler\HelpFunctions.h>

#include "IshavsfiskeGame.h"
#include "HarbourMode.h"

using namespace Ishavsfiske;

HarbourMode::HarbourMode(unsigned long id, Angler::Node *parent, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id, parent), mOwner(owner), mBarIsMO(false), mWorkshopIsMO(false), mMarketIsMO(false), mMenuButtonRot(0.0f)
{

}

HarbourMode::HarbourMode(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id), mOwner(owner), mBarIsMO(false), mWorkshopIsMO(false), mMarketIsMO(false), mMenuButtonRot(0.0f)
{

}

void HarbourMode::draw(Angler::Game* context, Angler::Graphics::GraphicsEngine* graphics, float time, float deltaTime)
{
	if (mVisible)
	{
		graphics->draw(0);

		if (mBarIsMO)
			graphics->draw(1);

		if (mMarketIsMO)
			graphics->draw(2);

		if (mWorkshopIsMO)
			graphics->draw(3);

		//Menu button
		glPushMatrix();
			glScalef(3/20.0f, 3/20.0f, 1.0f);
			glScalef(1/3.0f, 1/3.0f, 1.0f);
				glTranslatef(0.0f, 17.0f, 0);
			glScalef(3.0f, 3.0f, 1.0f);
			graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(400/1500.0f, 0), sf::Vector2f(150/1500.0f, 150/1600.0f));
		glPopMatrix();

		//Menu needle
		glPushMatrix();
			glScalef(3/20.0f, 3/20.0f, 1.0f);
			glScalef(1/3.0f, 1/3.0f, 1.0f);
				glTranslatef(1.5f, 18.5f, 0.0f);
			glScalef(3.0f, 3.0f, 1.0f);
			glRotatef(35.0f * sin(mMenuButtonRot), 0, 0, 1);
			graphics->draw(4, sf::Vector2f(10.0f/20.0f, 55.0f/108.0f), sf::Vector2f(400/1500.0f, 150/1600.0f), sf::Vector2f(20/1500.0f, 108/1600.0f));
		glPopMatrix();

		mDrawChildren(context, graphics, time, deltaTime);
	}
}

sf::Vector2f mousePos;

void HarbourMode::endDraw(Angler::Game* context, Angler::Graphics::GraphicsEngine* graphics, float time, float deltaTime)
{
	if (mVisible)
	{
		glDisable(GL_TEXTURE_2D);

		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		glLineWidth(3);

		/*
		glColor3d(1, 0, 0);
		glBegin(GL_POLYGON);
			for (int i = 0; i < mBarMOS.size(); i++)
			{
				glVertex2f(mBarMOS.at(i).x, mBarMOS.at(i).y);
			}
		glEnd();

		glColor3d(0, 1, 0);
		glBegin(GL_POLYGON);
			for (int i = 0; i < mWorkshopMOS.size(); i++)
			{
				glVertex2f(mWorkshopMOS.at(i).x, mWorkshopMOS.at(i).y);
			}
		glEnd();

		glColor3d(0, 0, 1);
		glBegin(GL_POLYGON);
			for (int i = 0; i < mMarketMOS.size(); i++)
			{
				glVertex2f(mMarketMOS.at(i).x, mMarketMOS.at(i).y);
			}
		glEnd();

		glColor3d(0, 0, 1);
		glBegin(GL_POLYGON);
			for (int i = 0; i < mMenuButtonMOS.size(); i++)
			{
				glVertex2f(mMenuButtonMOS.at(i).x, mMenuButtonMOS.at(i).y);
			}
		glEnd();*/

		glColor3d(1, 1, 0);
		glBegin(GL_POLYGON);
			glVertex2f(mousePos.x + 0.01f, mousePos.y + 0.01f);
			glVertex2f(mousePos.x, mousePos.y);
			glVertex2f(mousePos.x, mousePos.y + 0.015f);
			//glVertex2f(mousePos.x + 0.005f, mousePos.y + 0.005f);
		glEnd();

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		mEndDrawChildren(context, graphics, time, deltaTime);
	}
}

void HarbourMode::update(Angler::Game* context, float time, float deltaTime, bool changed)
{
	if (!mPaused)
	{
		mChanged |= changed;

		mousePos = sf::Vector2f(context->getMouseState().getPos());
		mousePos.x /= context->getHeight();
		mousePos.y /= context->getHeight();

		mBarIsMO = Angler::HelpFunctions::Geometry::pointIsWithinPolygon(&mBarMOS, mousePos);
		mMarketIsMO = Angler::HelpFunctions::Geometry::pointIsWithinPolygon(&mMarketMOS, mousePos);
		mWorkshopIsMO = Angler::HelpFunctions::Geometry::pointIsWithinPolygon(&mWorkshopMOS, mousePos);
		mMenuButtonIsMO = Angler::HelpFunctions::Geometry::pointIsWithinPolygon(&mMenuButtonMOS, mousePos);

		if (mMenuButtonIsMO || fmod(abs(sin(mMenuButtonRot)), 1.0f) > 0.001f)
			mMenuButtonRot += std::min(3.1415f-fmod(mMenuButtonRot, 3.1415f), 4 * deltaTime);

		mMenuButtonRot = fmod(mMenuButtonRot, 2*3.1415f);

		if (mBarIsMO)
		{
			mSBar->setVolume(100.0f);
		}
		else
		{
			mSBar->setVolume(15.0f);
		}

		if (mMarketIsMO)
		{
			mSMarket->setVolume(100.0f);
		}
		else
		{
			mSMarket->setVolume(15.0f);
		}

		if (mWorkshopIsMO)
		{
			mSWorkshop->setVolume(100.0f);
		}
		else
		{
			mSWorkshop->setVolume(15.0f);
		}

		if (mBarIsMO || mMarketIsMO || mWorkshopIsMO)
		{
			mSSea->setVolume(15.0f);
		}
		else
		{
			mSSea->setVolume(80.0f);
		}

		mUpdateChildren(context, time, deltaTime);
	}
}

void HarbourMode::loadContent()
{
	mTXHarbour->loadFromFile("staden_6.png");

	mTXBarHO->loadFromFile("bar_Hoverover.png");
	mTXMarketHO->loadFromFile("Market_Hoverover.png");
	mTXWorkshopHO->loadFromFile("Workshop_Hoverover.png");
	mTXUI->loadFromFile("Sheet_2.png");

	mSBSea->loadFromFile("Hav.wav");
	mSSea->setBuffer(*mSBSea);

	mSBBar->loadFromFile("Taverna.wav");
	mSBar->setBuffer(*mSBBar);

	mSBWorkshop->loadFromFile("Verkstad.wav");
	mSWorkshop->setBuffer(*mSBWorkshop);

	mSBMarket->loadFromFile("Fiskmarknad.wav");
	mSMarket->setBuffer(*mSBMarket);

	//Mouse over
	//Bar
	mBarMOS.push_back(sf::Vector2f(0.713f, 0.240f));
	mBarMOS.push_back(sf::Vector2f(0.665f, 0.232f));
	mBarMOS.push_back(sf::Vector2f(0.640f, 0.232f));
	mBarMOS.push_back(sf::Vector2f(0.576f, 0.246f));
	mBarMOS.push_back(sf::Vector2f(0.523f, 0.293f));
	mBarMOS.push_back(sf::Vector2f(0.539f, 0.323f));
	mBarMOS.push_back(sf::Vector2f(0.563f, 0.345f));
	mBarMOS.push_back(sf::Vector2f(0.652f, 0.346f));
	mBarMOS.push_back(sf::Vector2f(0.730f, 0.344f));
	mBarMOS.push_back(sf::Vector2f(0.757f, 0.290f));

	//Market
	mMarketMOS.push_back(sf::Vector2f(1.577f, 0.421f));
	mMarketMOS.push_back(sf::Vector2f(1.458f, 0.419f));
	mMarketMOS.push_back(sf::Vector2f(1.475f, 0.465f));
	mMarketMOS.push_back(sf::Vector2f(1.570f, 0.466f));
	mMarketMOS.push_back(sf::Vector2f(1.575f, 0.440f));

	//Workshop
	mWorkshopMOS.push_back(sf::Vector2f(1.000f, 0.350f));
	mWorkshopMOS.push_back(sf::Vector2f(0.853f, 0.357f));
	mWorkshopMOS.push_back(sf::Vector2f(0.771f, 0.448f));
	mWorkshopMOS.push_back(sf::Vector2f(0.774f, 0.530f));
	mWorkshopMOS.push_back(sf::Vector2f(0.890f, 0.532f));
	mWorkshopMOS.push_back(sf::Vector2f(1.050f, 0.510f));
	mWorkshopMOS.push_back(sf::Vector2f(1.056f, 0.406f));

	//Menu button
	for (int i = 0; i < 32; i++)
	{
		mMenuButtonMOS.push_back(sf::Vector2f(3/40.0f + 3/40.0f * cos(-i/16.0f * 3.1415f), 37/40.0f + 3/40.0f * sin(-i/16.0f * 3.1415f)));
	}
}

void HarbourMode::init()
{
	mTXHarbour = new sf::Texture();

	mTXBarHO = new sf::Texture();
	mTXMarketHO = new sf::Texture();
	mTXWorkshopHO = new sf::Texture();
	mTXUI = new sf::Texture();

	mSSea = new sf::Sound();
	mSBSea = new sf::SoundBuffer();

	mSBar = new sf::Sound();
	mSBBar = new sf::SoundBuffer();

	mSWorkshop = new sf::Sound();
	mSBWorkshop = new sf::SoundBuffer();

	mSMarket = new sf::Sound();
	mSBMarket = new sf::SoundBuffer();
}

void HarbourMode::mEnable(bool enabled)
{
	if (enabled)
	{
		int sizes[5] = { 1, 1, 1, 1, 5 };
		sf::Texture* textures[5] = { mTXHarbour, mTXBarHO, mTXMarketHO, mTXWorkshopHO, mTXUI };
		mOwner->setupGraphicsLayers(5, sizes, textures);

		mOwner->setCursorVisible(false);

		mSSea->setVolume(80.0f);
		mOwner->getSound()->playSound(mSSea, false, 0, 47.0f, true);

		mSBar->setVolume(15.0f);
		mOwner->getSound()->playSound(mSBar, false, 0, 49.0f, true);

		mSWorkshop->setVolume(15.0f);
		mOwner->getSound()->playSound(mSWorkshop, false, 0, 49.0f, true);

		mSMarket->setVolume(15.0f);
		mOwner->getSound()->playSound(mSMarket, false, 0, 46.0f, true);
	}
	else
	{
		mOwner->setCursorVisible(true);

		mOwner->clearGraphicsLayers();
	}
}

void HarbourMode::showRoom(int ind)
{

}