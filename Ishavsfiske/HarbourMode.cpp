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
	: Node(id, parent), mOwner(owner), mBarIsMO(false), mWorkshopIsMO(false), mMarketIsMO(false), mRadioIsMO(false), mMenuButtonIsMO(false), mMenuButtonRot(0.0f),
	mRadioCh(1), mRadioTime(-1.0f), mRoom(-1)
{

}

HarbourMode::HarbourMode(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id), mOwner(owner), mBarIsMO(false), mWorkshopIsMO(false), mMarketIsMO(false), mRadioIsMO(false), mMenuButtonIsMO(false), mMenuButtonRot(0.0f),
	mRadioCh(1), mRadioTime(-1.0f), mRoom(-1)
{

}

sf::Vector2f mousePos;

void HarbourMode::mDrawHarbourRoom(Angler::Game* context, Angler::Graphics::GraphicsEngine* graphics, float time, float deltaTime)
{
	graphics->draw(0);

	if (mBarIsMO)
		graphics->draw(1);

	if (mMarketIsMO)
		graphics->draw(2);

	if (mWorkshopIsMO)
		graphics->draw(3);
}

void HarbourMode::mDrawRoom(Angler::Game* context, Angler::Graphics::GraphicsEngine* graphics, float time, float deltaTime)
{
	graphics->draw(0);

	if (mInsideIsMO)
		graphics->draw(1);
}

void HarbourMode::draw(Angler::Game* context, Angler::Graphics::GraphicsEngine* graphics, float time, float deltaTime)
{
	if (mVisible)
	{
		if (mRoom == -1)
			mDrawHarbourRoom(context, graphics, time, deltaTime);
		else
			mDrawRoom(context, graphics, time, deltaTime);

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

		//Exit
		glPushMatrix();
			glTranslatef(1.6f, 1.0f, 1.0f);
			glScalef(1/20.0f, 1/20.0f, 1.0f);
			graphics->draw(5, sf::Vector2f(1.0f, 1.0f), sf::Vector2f(0.0f, (mBackButtonIsMO ? 1/3.0f : 0.0f)), sf::Vector2f(1.0f, 1/3.0f));
		glPopMatrix();

		//Cursor
		glPushMatrix();
			glTranslatef(mousePos.x, mousePos.y, 0);
			glScalef(62/1000.0f, 62/1000.0f, 1.0f);
			graphics->draw(6, sf::Vector2f(0.35f, 0), sf::Vector2f((context->getMouseState().isButtonDown(sf::Mouse::Button::Left) ? 0.5f : 0.0f), 0), sf::Vector2f(0.5f, 1));
		glPopMatrix();

		//Radio
		glPushMatrix();
			glScalef(1/20.f, 1/20.f, 1);
				glTranslatef(31, 20, 0);
			glScalef(20.f, 20.f, 1);
			glScalef(75/1000.0f, 75/1000.0f, 1);
			if (mRadioIsMO)
				graphics->draw(4, sf::Vector2f(1, 1), sf::Vector2f(420/1500.0f, 150/1600.0f), sf::Vector2f(140/1500.0f, 75/1600.0f), 1, 0, 0, 1);
			else
				graphics->draw(4, sf::Vector2f(1, 1), sf::Vector2f(420/1500.0f, 150/1600.0f), sf::Vector2f(140/1500.0f, 75/1600.0f));
		glPopMatrix();

		mDrawChildren(context, graphics, time, deltaTime);
	}
}

void HarbourMode::endDraw(Angler::Game* context, Angler::Graphics::GraphicsEngine* graphics, float time, float deltaTime)
{
	if (mVisible)
	{
		glDisable(GL_TEXTURE_2D);

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		glLineWidth(3);

		if (mRoom == -1)
		{
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
		}

		glColor3d(0, 0, 1);
		glBegin(GL_POLYGON);
			for (int i = 0; i < mMenuButtonMOS.size(); i++)
			{
				glVertex2f(mMenuButtonMOS.at(i).x, mMenuButtonMOS.at(i).y);
			}
		glEnd();

		glColor3d(0, 0, 1);
		glBegin(GL_POLYGON);
			for (int i = 0; i < mRadioMOS.size(); i++)
			{
				glVertex2f(mRadioMOS.at(i).x, mRadioMOS.at(i).y);
			}
		glEnd();

		glColor3d(0, 0, 1);
		glBegin(GL_POLYGON);
			for (int i = 0; i < mBackButtonMOS.size(); i++)
			{
				glVertex2f(mBackButtonMOS.at(i).x, mBackButtonMOS.at(i).y);
			}
		glEnd();

		if (mRoom != -1)
		{
			glColor3d(0, 0, 1);
			glBegin(GL_POLYGON);
				for (int i = 0; i < mInsideMOS.size(); i++)
				{
					glVertex2f(mInsideMOS.at(i).x, mInsideMOS.at(i).y);
				}
			glEnd();
		}

		//glColor3d(1, 1, 0);
		//glBegin(GL_POLYGON);
		//	glVertex2f(mousePos.x + 0.01f, mousePos.y + 0.01f);
		//	glVertex2f(mousePos.x, mousePos.y);
		//	glVertex2f(mousePos.x, mousePos.y + 0.015f);
		//	//glVertex2f(mousePos.x + 0.005f, mousePos.y + 0.005f);
		//glEnd();

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		mEndDrawChildren(context, graphics, time, deltaTime);
	}
}

void HarbourMode::mUpdateHarbourMode(Angler::Game* context, float time, float deltaTime)
{
	mBarIsMO = Angler::HelpFunctions::Geometry::pointIsWithinPolygon(&mBarMOS, mousePos);
	mMarketIsMO = Angler::HelpFunctions::Geometry::pointIsWithinPolygon(&mMarketMOS, mousePos);
	mWorkshopIsMO = Angler::HelpFunctions::Geometry::pointIsWithinPolygon(&mWorkshopMOS, mousePos);

	if (mBarIsMO && mRadioCh == 0 &&  mRadioTime == -1.0f)
	{
		mSBar->setVolume(100.0f);
	}
	else
	{
		mSBar->setVolume(15.0f);
	}

	if (mMarketIsMO && mRadioCh == 0 &&  mRadioTime == -1.0f)
	{
		mSMarket->setVolume(100.0f);
	}
	else
	{
		mSMarket->setVolume(15.0f);
	}

	if (mWorkshopIsMO && mRadioCh == 0 &&  mRadioTime == -1.0f)
	{
		mSWorkshop->setVolume(100.0f);
	}
	else
	{
		mSWorkshop->setVolume(15.0f);
	}

	if (mBarIsMO || mMarketIsMO || mWorkshopIsMO || mRadioCh != 0 || mRadioTime >= 0.0f)
	{
		mSSea->setVolume(15.0f);
	}
	else
	{
		mSSea->setVolume(80.0f);
	}
}

void HarbourMode::mUpdateRoom(Angler::Game* context, float time, float deltaTime)
{
	mInsideIsMO = Angler::HelpFunctions::Geometry::pointIsWithinPolygon(&mInsideMOS, mousePos);

	mSSea->setVolume(0.0f);

	if (mRoom == 0 && mRadioCh == 0 &&  mRadioTime == -1.0f)
	{
		mSBar->setVolume(100.0f);
	}
	else
	{
		mSBar->setVolume(0.0f);
	}
	
	if (mRoom == 1 && mRadioCh == 0 &&  mRadioTime == -1.0f)
	{
		mSWorkshop->setVolume(100.0f);
	}
	else
	{
		mSWorkshop->setVolume(0.0f);
	}

	if (mRoom == 2 && mRadioCh == 0 &&  mRadioTime == -1.0f)
	{
		mSMarket->setVolume(100.0f);
	}
	else
	{
		mSMarket->setVolume(0.0f);
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

		mRadioIsMO = Angler::HelpFunctions::Geometry::pointIsWithinPolygon(&mRadioMOS, mousePos);
		mMenuButtonIsMO = Angler::HelpFunctions::Geometry::pointIsWithinPolygon(&mMenuButtonMOS, mousePos);
		mBackButtonIsMO = Angler::HelpFunctions::Geometry::pointIsWithinPolygon(&mBackButtonMOS, mousePos);

		if (mMenuButtonIsMO || fmod(abs(sin(mMenuButtonRot)), 1.0f) > 0.001f)
			mMenuButtonRot += std::min(3.1415f-fmod(mMenuButtonRot, 3.1415f), 4 * deltaTime);

		mMenuButtonRot = fmod(mMenuButtonRot, 2*3.1415f);

		if (mRoom == -1)
			mUpdateHarbourMode(context, time, deltaTime);
		else
			mUpdateRoom(context, time, deltaTime);

		if (mRoom != -1)
		{
			if (mBackButtonIsMO && !context->getMouseState().isButtonDown(sf::Mouse::Button::Left)
				&& context->getMouseState().wasButtonDown(sf::Mouse::Button::Left))
			{
				mShowRoom(-1);
			}
		}
		else
		{
			if (mBarIsMO && !context->getMouseState().isButtonDown(sf::Mouse::Button::Left)
				&& context->getMouseState().wasButtonDown(sf::Mouse::Button::Left))
			{
				mShowRoom(0);
			}
			if (mWorkshopIsMO && !context->getMouseState().isButtonDown(sf::Mouse::Button::Left)
				&& context->getMouseState().wasButtonDown(sf::Mouse::Button::Left))
			{
				mShowRoom(1);
			}
			if (mMarketIsMO && !context->getMouseState().isButtonDown(sf::Mouse::Button::Left)
				&& context->getMouseState().wasButtonDown(sf::Mouse::Button::Left))
			{
				mShowRoom(2);
			}
		}

		for (int i = 0; i < 4; i++)
		{
			if ((mRadioCh-1) == i && mRadioTime == -1.0f)
				mMusic[i]->setVolume(100.0f);
			else
				mMusic[i]->setVolume(0.0f);
		}

		if (mRadioTime >= 1.0f)
		{
			mRadioTime = -1.0f;
		}
		else if (mRadioTime >= 0)	
		{
			mRadioTime += deltaTime;
		}

		if (mRadioIsMO && context->getMouseState().isButtonDown(sf::Mouse::Button::Left)
			&& !context->getMouseState().wasButtonDown(sf::Mouse::Button::Left))
		{
			mRadioCh = (mRadioCh + 1) % 5;
			mRadioTime = 0;
			context->getSound()->playSound(mRadioSound, false, 0, 1.0f, false);
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
	mTXBackButton->loadFromFile("backknapp.png");
	mTXCursor->loadFromFile("cursor_hand_sheet.png");

	mTXBarInside->loadFromFile("bar_3_stolar.png");
	mTXBarInsideHO->loadFromFile("bar_Olaf_hoverover.png");

	mTXWorkshopInside->loadFromFile("verkstad_3.png");
	mTXWorkshopInsideHO->loadFromFile("workshop_mira_hoverover.png");

	mTXMarketInside->loadFromFile("marknad_3.png");
	mTXMarketInsideHO->loadFromFile("marknad__ThordBirgitte_Hoverover.png");

	mMusicBuffer[0]->loadFromFile("Hamn_Radio_Blues01.wav");
	mMusicBuffer[1]->loadFromFile("Hamn_Radio_Jazz01.wav");
	mMusicBuffer[2]->loadFromFile("Hamn_Radio_Jazz02.wav");
	mMusicBuffer[3]->loadFromFile("Hamn_Radio_Jazz03.wav");

	mRadioBuffer->loadFromFile("radio_1.wav");
	mRadioSound->setBuffer(*mRadioBuffer);

	for (int i = 0; i < 4; i++)
	{
		mMusic[i]->setBuffer(*mMusicBuffer[i]);
	}

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

	//Back button
	for (int i = 0; i < 32; i++)
	{
		mBackButtonMOS.push_back(sf::Vector2f(63/40.0f + 1/40.0f * cos(-i/16.0f * 3.1415f), 39/40.0f + 1/40.0f * sin(-i/16.0f * 3.1415f)));
	}

	//Radio
	mRadioMOS.push_back(sf::Vector2f(1.55f, 0.950f));
	mRadioMOS.push_back(sf::Vector2f(1.54f, 0.925f));

	mRadioMOS.push_back(sf::Vector2f(1.42f, 0.925f));
	mRadioMOS.push_back(sf::Vector2f(1.41f, 0.950f));

	mRadioMOS.push_back(sf::Vector2f(1.41f, 0.975f));
	mRadioMOS.push_back(sf::Vector2f(1.42f, 1.0f));

	mRadioMOS.push_back(sf::Vector2f(1.54f, 1.0f));
	mRadioMOS.push_back(sf::Vector2f(1.55f, 0.975f));
}

void HarbourMode::init()
{
	mTXHarbour = new sf::Texture();

	mTXBarHO = new sf::Texture();
	mTXMarketHO = new sf::Texture();
	mTXWorkshopHO = new sf::Texture();
	mTXUI = new sf::Texture();
	mTXBackButton = new sf::Texture();
	mTXCursor = new sf::Texture();

	mTXBarInside = new sf::Texture();
	mTXBarInsideHO = new sf::Texture();

	mTXWorkshopInside = new sf::Texture();
	mTXWorkshopInsideHO = new sf::Texture();

	mTXMarketInside = new sf::Texture();
	mTXMarketInsideHO = new sf::Texture();

	mRadioSound = new sf::Sound();
	mRadioBuffer = new sf::SoundBuffer();
	for (int i = 0; i < 4; i++)
	{
		mMusicBuffer[i] = new sf::SoundBuffer();
		mMusic[i] = new sf::Sound();
	}

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
		mOwner->setCursorVisible(false);

		for (int i = 0; i < 4; i++)
		{
			mMusic[i]->setVolume(0.0f);
		}
		
		mOwner->getSound()->playSound(mMusic[0], false, 0, 1*60.0f + 43.0f, true);
		mOwner->getSound()->playSound(mMusic[1], false, 0, 1*60.0f + 52.0f, true);
		mOwner->getSound()->playSound(mMusic[2], false, 0, 30.0f, true);
		mOwner->getSound()->playSound(mMusic[3], false, 0, 1*60.0f + 9.0f, true);

		mSSea->setVolume(80.0f);
		mOwner->getSound()->playSound(mSSea, false, 0, 47.0f, true);

		mSBar->setVolume(15.0f);
		mOwner->getSound()->playSound(mSBar, false, 0, 49.0f, true);

		mSWorkshop->setVolume(15.0f);
		mOwner->getSound()->playSound(mSWorkshop, false, 0, 49.0f, true);

		mSMarket->setVolume(15.0f);
		mOwner->getSound()->playSound(mSMarket, false, 0, 46.0f, true);

		mShowRoom(0);
	}
	else
	{
		mOwner->setCursorVisible(true);

		mOwner->clearGraphicsLayers();
	}
}

void HarbourMode::mShowRoom(int ind)
{
	mRoom = ind;

	if (ind == -1)
	{
		int sizes[7] = { 1, 1, 1, 1, 5, 1, 1 };
		sf::Texture* textures[7] = { mTXHarbour, mTXBarHO, mTXMarketHO, mTXWorkshopHO, mTXUI, mTXBackButton, mTXCursor };
		mOwner->setupGraphicsLayers(7, sizes, textures);
	}
	else
	{
		int sizes[7] = { 1, 1, 0, 0, 5, 1, 1 };
		sf::Texture* textures[7] = { mTXHarbour, mTXHarbour, mTXHarbour, mTXHarbour, mTXUI, mTXBackButton, mTXCursor };

		mInsideMOS.clear();

		if (ind == 0)
		{
			textures[0] = mTXBarInside;
			textures[1] = mTXBarInsideHO;

			mInsideMOS.push_back(sf::Vector2f(1.177f, 0.223f));
			mInsideMOS.push_back(sf::Vector2f(1.149f, 0.228f));
			mInsideMOS.push_back(sf::Vector2f(1.131f, 0.241f));
			mInsideMOS.push_back(sf::Vector2f(1.119f, 0.267f));
			mInsideMOS.push_back(sf::Vector2f(1.103f, 0.491f));
			mInsideMOS.push_back(sf::Vector2f(1.342f, 0.491f));
			mInsideMOS.push_back(sf::Vector2f(1.224f, 0.270f));
			mInsideMOS.push_back(sf::Vector2f(1.197f, 0.228f));
		}
		else if (ind == 1)
		{
			textures[0] = mTXWorkshopInside;
			textures[1] = mTXWorkshopInsideHO;

			mInsideMOS.push_back(sf::Vector2f(0.648f, 0.293f));
			mInsideMOS.push_back(sf::Vector2f(0.602f, 0.321f));
			mInsideMOS.push_back(sf::Vector2f(0.575f, 0.371f));
			mInsideMOS.push_back(sf::Vector2f(0.498f, 0.591f));
			mInsideMOS.push_back(sf::Vector2f(0.451f, 0.826f));
			mInsideMOS.push_back(sf::Vector2f(0.457f, 0.896f));
			mInsideMOS.push_back(sf::Vector2f(0.505f, 1.000f));
			mInsideMOS.push_back(sf::Vector2f(0.921f, 1.000f));
			mInsideMOS.push_back(sf::Vector2f(0.930f, 0.862f));
			mInsideMOS.push_back(sf::Vector2f(0.881f, 0.605f));
			mInsideMOS.push_back(sf::Vector2f(0.734f, 0.313f));
		}
		else if (ind == 2)
		{
			textures[0] = mTXMarketInside;
			textures[1] = mTXMarketInsideHO;

			mInsideMOS.push_back(sf::Vector2f(0.928f, 0.194f));
			mInsideMOS.push_back(sf::Vector2f(0.886f, 0.214f));
			mInsideMOS.push_back(sf::Vector2f(0.805f, 0.380f));
			mInsideMOS.push_back(sf::Vector2f(0.798f, 0.405f));
			mInsideMOS.push_back(sf::Vector2f(0.808f, 0.465f));
			mInsideMOS.push_back(sf::Vector2f(0.878f, 0.593f));
			mInsideMOS.push_back(sf::Vector2f(0.936f, 0.603f));
			mInsideMOS.push_back(sf::Vector2f(1.207f, 0.528f));
			mInsideMOS.push_back(sf::Vector2f(1.206f, 0.429f));
			mInsideMOS.push_back(sf::Vector2f(1.168f, 0.303f));
			mInsideMOS.push_back(sf::Vector2f(1.147f, 0.279f));
		}

		mOwner->setupGraphicsLayers(7, sizes, textures);
	}
}