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
	mRadioCh(0), mRadioTime(-1.0f), mRoom(0)
{

}

HarbourMode::HarbourMode(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id), mOwner(owner), mBarIsMO(false), mWorkshopIsMO(false), mMarketIsMO(false), mRadioIsMO(false), mMenuButtonIsMO(false), mMenuButtonRot(0.0f),
	mRadioCh(0), mRadioTime(-1.0f), mRoom(0)
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

	//Exit
	glPushMatrix();
		glTranslatef(1.6f, 1.0f, 1.0f);
		glScalef(1/20.0f, 1/20.0f, 1.0f);
		graphics->draw(5, sf::Vector2f(1.0f, 1.0f), 
			sf::Vector2f(0.0f, (mBackButtonIsMO ? (context->getMouseState().isButtonDown(sf::Mouse::Left) ? 2/3.0f : 1/3.0f) : 0.0f)), sf::Vector2f(0.5f, 1/3.0f));
	glPopMatrix();
}

void HarbourMode::mDrawTrade(Angler::Game* context, Angler::Graphics::GraphicsEngine* graphics, float time, float deltaTime)
{
	//Row 1
	glPushMatrix();
		glScalef(1/20.0f, 1/20.0f, 1.0f);
		glTranslatef(8/2.0f, 10/2.0f, 0);
		glPushMatrix();
			graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(550/1500.0f, 0.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));

			for (int i = 0; i < 5; i++)
			{
				glTranslatef(1.0f, 0, 0);
				graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 0.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
			}

			glTranslatef(1.0f, 0, 0);
			graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(650/1500.0f, 0.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
		glPopMatrix();
		glTranslatef(0, 1, 0);

		for (int i = 0; i < 4; i++)
		{
			//Row 2
			glPushMatrix();
				graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(550/1500.0f, 50/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));

				for (int i = 0; i < 5; i++)
				{
					glTranslatef(1.0f, 0, 0);
					graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 50/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
				}

				glTranslatef(1.0f, 0, 0);
				graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(650/1500.0f, 50/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
			glPopMatrix();
			glTranslatef(0, 1, 0);
		}

		//Row 3
		glPushMatrix();
			graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(550/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));

			for (int i = 0; i < 5; i++)
			{
				glTranslatef(1.0f, 0, 0);
				graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
			}

			glTranslatef(1.0f, 0, 0);
			graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(650/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
		glPopMatrix();
	glPopMatrix();

	//Row 1
	glPushMatrix();
		glScalef(1/20.0f, 1/20.0f, 1.0f);
		glTranslatef(24/2.0f, 10/2.0f, 0);
		glPushMatrix();
			graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(550/1500.0f, 0.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));

			for (int i = 0; i < 5; i++)
			{
				glTranslatef(1.0f, 0, 0);
				graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 0.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
			}

			glTranslatef(1.0f, 0, 0);
			graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(650/1500.0f, 0.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
		glPopMatrix();
		glTranslatef(0, 1, 0);

		for (int i = 0; i < 4; i++)
		{
			//Row 2
			glPushMatrix();
				graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(550/1500.0f, 50/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));

				for (int i = 0; i < 5; i++)
				{
					glTranslatef(1.0f, 0, 0);
					graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 50/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
				}

				glTranslatef(1.0f, 0, 0);
				graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(650/1500.0f, 50/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
			glPopMatrix();
			glTranslatef(0, 1, 0);
		}

		//Row 3
		glPushMatrix();
			graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(550/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));

			for (int i = 0; i < 5; i++)
			{
				glTranslatef(1.0f, 0, 0);
				graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
			}

			glTranslatef(1.0f, 0, 0);
			graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(650/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
		glPopMatrix();
	glPopMatrix();

	//Row 1
	glPushMatrix();
		glScalef(1/20.0f, 1/20.0f, 1.0f);

		glTranslatef(8/2.0f, 27/2.0f, 0);
		graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(550/1500.0f, 0.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));

		for (int i = 0; i < 5; i++)
		{
			glTranslatef(1.0f, 0, 0);
			graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 0.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
		}

		glTranslatef(1.0f, 0, 0);
		graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(650/1500.0f, 0.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
	glPopMatrix();

	//Row 2
	glPushMatrix();
		glScalef(1/20.0f, 1/20.0f, 1.0f);
		glTranslatef(8/2.0f, 29/2.0f, 0);
		graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(550/1500.0f, 50/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));

		for (int i = 0; i < 5; i++)
		{
			glTranslatef(1.0f, 0, 0);
			graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 50/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
		}

		glTranslatef(1.0f, 0, 0);
		graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(650/1500.0f, 50/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
	glPopMatrix();

	//Row 3
	glPushMatrix();
		glScalef(1/20.0f, 1/20.0f, 1.0f);
		glTranslatef(8/2.0f, 31/2.0f, 0);
		graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(550/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));

		for (int i = 0; i < 5; i++)
		{
			glTranslatef(1.0f, 0, 0);
			graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
		}

		glTranslatef(1.0f, 0, 0);
		graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(650/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
	glPopMatrix();

	//Row 1
	glPushMatrix();
		glScalef(1/20.0f, 1/20.0f, 1.0f);

		glTranslatef(11/2.0f, 30/2.0f, 0);
		if (mSellButtonIsMO)
			graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(550/1500.0f, 0.0f), sf::Vector2f(50/1500.0f, 50/1600.0f), 1, 0, 0, 1);
		else
			graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(550/1500.0f, 0.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));

		for (int i = 0; i < 2; i++)
		{
			glTranslatef(1.0f, 0, 0);
			if (mSellButtonIsMO)
				graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 0.0f), sf::Vector2f(50/1500.0f, 50/1600.0f), 1, 0, 0, 1);
			else
				graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 0.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
		}

		glTranslatef(1.0f, 0, 0);
		if (mSellButtonIsMO)
			graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(650/1500.0f, 0.0f), sf::Vector2f(50/1500.0f, 50/1600.0f), 1, 0, 0, 1);
		else
			graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(650/1500.0f, 0.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
	glPopMatrix();

	//Row 3
	glPushMatrix();
		glScalef(1/20.0f, 1/20.0f, 1.0f);
		glTranslatef(11/2.0f, 31/2.0f, 0);
		if (mSellButtonIsMO)
			graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(550/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f), 1, 0, 0, 1);
		else
			graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(550/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));

		for (int i = 0; i < 2; i++)
		{
			glTranslatef(1.0f, 0, 0);
			if (mSellButtonIsMO)
				graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f), 1, 0, 0, 1);
			else
				graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
		}

		glTranslatef(1.0f, 0, 0);
		if (mSellButtonIsMO)
			graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(650/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f), 1, 0, 0, 1);
		else
			graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(650/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
	glPopMatrix();

	
	
	glPushMatrix();
		glTranslatef(13/40.0f, 31/40.0f, 0);
		mFont->drawString(graphics, "Sell", 6, 0.85f);
	glPopMatrix();

	char tmp[64];
	int *fc = ((IshavsfiskeGame*)context)->getFishCount();

	glPushMatrix();
		glTranslatef(9/40.0f, 11/40.0f, 0);
		for (int i = 0; i < 4; i++)
		{
			sprintf_s(tmp, "Fish %c x %u", 'A' + i, fc[i]);
			mFont->drawString(graphics, std::string(tmp), 6, 0.85f);
			glTranslatef(0, 1/20.0f, 0);
		}
	glPopMatrix();

	glPushMatrix();
		glTranslatef(25/40.0f, 11/40.0f, 0);
		for (int i = 0; i < 4; i++)
		{
			sprintf_s(tmp, "Fish %c %3u NOK", 'A' + i, (i+1) * 10);
			mFont->drawString(graphics, std::string(tmp), 6, 0.85f);
			glTranslatef(0, 1/20.0f, 0);
		}
	glPopMatrix();

	glPushMatrix();
		sprintf_s(tmp, "%5u", fc[0] * 10 + fc[1] * 20 + fc[2] * 30 + fc[3] * 40);
		glTranslatef(9/40.0f, 28/40.0f, 0);
		mFont->drawString(graphics, "Sum: " + std::string(tmp) + " NOK", 6, 0.85f);
	glPopMatrix();
}

void HarbourMode::mDrawRoom(Angler::Game* context, Angler::Graphics::GraphicsEngine* graphics, float time, float deltaTime)
{
	graphics->draw(0);

	if (mInsideIsMO)
		graphics->draw(1);

	if (mTrading)
		mDrawTrade(context, graphics, time, deltaTime);

	//Exit
	glPushMatrix();
		glTranslatef(1.6f, 1.0f, 1.0f);
		glScalef(1/20.0f, 1/20.0f, 1.0f);
		graphics->draw(5, sf::Vector2f(1.0f, 1.0f), 
			sf::Vector2f(0.5f, (mBackButtonIsMO ? (context->getMouseState().isButtonDown(sf::Mouse::Left) ? 2/3.0f : 1/3.0f) : 0.0f)), sf::Vector2f(0.5f, 1/3.0f));
	glPopMatrix();
}

void HarbourMode::draw(Angler::Game* context, Angler::Graphics::GraphicsEngine* graphics, float time, float deltaTime)
{
	if (mVisible)
	{
		if (mRoom == 0)
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

		//Cursor
		glPushMatrix();
			glTranslatef(mousePos.x, mousePos.y, 0);
			glScalef(62/1000.0f, 62/1000.0f, 1.0f);
			graphics->draw(7, sf::Vector2f(0.35f, 0), sf::Vector2f((context->getMouseState().isButtonDown(sf::Mouse::Button::Left) ? 0.5f : 0.0f), 0), sf::Vector2f(0.5f, 1));
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
				if (mRadioCh > 0)
					graphics->draw(4, sf::Vector2f(1, 1), sf::Vector2f(420/1500.0f, 150/1600.0f), sf::Vector2f(140/1500.0f, 75/1600.0f), 0, 1, 0, 1);
				else
					graphics->draw(4, sf::Vector2f(1, 1), sf::Vector2f(420/1500.0f, 150/1600.0f), sf::Vector2f(140/1500.0f, 75/1600.0f));
		glPopMatrix();

		//Row 1
		glPushMatrix();
			glScalef(1/20.0f, 1/20.0f, 1.0f);

			glTranslatef(47/2.0f, 1/2.0f, 0);
			graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(550/1500.0f, 0.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));

			for (int i = 0; i < 6; i++)
			{
				glTranslatef(1.0f, 0, 0);
				graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 0.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
			}

			glTranslatef(1.0f, 0, 0);
			graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(650/1500.0f, 0.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
		glPopMatrix();

		//Row 2
		glPushMatrix();
			glScalef(1/20.0f, 1/20.0f, 1.0f);
			glTranslatef(47/2.0f, 2/2.0f, 0);
			graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(550/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));

			for (int i = 0; i < 6; i++)
			{
				glTranslatef(1.0f, 0, 0);
				graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
			}

			glTranslatef(1.0f, 0, 0);
			graphics->draw(4, sf::Vector2f(0, 0), sf::Vector2f(650/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
		glPopMatrix();

		glPushMatrix();
			char tmp[64];
			sprintf_s(tmp, "%5u", ((IshavsfiskeGame*)context)->getWallet());
			glTranslatef(48/40.0f, 2/40.0f, 0);
			mFont->drawString(graphics, "Wallet: " + std::string(tmp) + " NOK", 6, 0.85f);
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

		//if (mRoom == 0)
		//{
		//	glColor3d(1, 0, 0);
		//	glBegin(GL_POLYGON);
		//		for (int i = 0; i < mBarMOS.size(); i++)
		//		{
		//			glVertex2f(mBarMOS.at(i).x, mBarMOS.at(i).y);
		//		}
		//	glEnd();

		//	glColor3d(0, 1, 0);
		//	glBegin(GL_POLYGON);
		//		for (int i = 0; i < mWorkshopMOS.size(); i++)
		//		{
		//			glVertex2f(mWorkshopMOS.at(i).x, mWorkshopMOS.at(i).y);
		//		}
		//	glEnd();

		//	glColor3d(0, 0, 1);
		//	glBegin(GL_POLYGON);
		//		for (int i = 0; i < mMarketMOS.size(); i++)
		//		{
		//			glVertex2f(mMarketMOS.at(i).x, mMarketMOS.at(i).y);
		//		}
		//	glEnd();
		//}

		//glColor3d(0, 0, 1);
		//glBegin(GL_POLYGON);
		//	for (int i = 0; i < mMenuButtonMOS.size(); i++)
		//	{
		//		glVertex2f(mMenuButtonMOS.at(i).x, mMenuButtonMOS.at(i).y);
		//	}
		//glEnd();

		//glColor3d(0, 0, 1);
		//glBegin(GL_POLYGON);
		//	for (int i = 0; i < mRadioMOS.size(); i++)
		//	{
		//		glVertex2f(mRadioMOS.at(i).x, mRadioMOS.at(i).y);
		//	}
		//glEnd();

		//glColor3d(0, 0, 1);
		//glBegin(GL_POLYGON);
		//	for (int i = 0; i < mBackButtonMOS.size(); i++)
		//	{
		//		glVertex2f(mBackButtonMOS.at(i).x, mBackButtonMOS.at(i).y);
		//	}
		//glEnd();

		//if (mRoom != 0)
		//{
		//	glColor3d(0, 0, 1);
		//	glBegin(GL_POLYGON);
		//		for (int i = 0; i < mInsideMOS.size(); i++)
		//		{
		//			glVertex2f(mInsideMOS.at(i).x, mInsideMOS.at(i).y);
		//		}
		//	glEnd();
		//}

		//if (mRoom != 0)
		//{
		//	glColor3d(0, 0, 1);
		//	glBegin(GL_POLYGON);
		//		for (int i = 0; i < mSellButtonMOS.size(); i++)
		//		{
		//			glVertex2f(mSellButtonMOS.at(i).x, mSellButtonMOS.at(i).y);
		//		}
		//	glEnd();
		//}

		////glColor3d(1, 1, 0);
		////glBegin(GL_POLYGON);
		////	glVertex2f(mousePos.x + 0.01f, mousePos.y + 0.01f);
		////	glVertex2f(mousePos.x, mousePos.y);
		////	glVertex2f(mousePos.x, mousePos.y + 0.015f);
		////	//glVertex2f(mousePos.x + 0.005f, mousePos.y + 0.005f);
		////glEnd();

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		mEndDrawChildren(context, graphics, time, deltaTime);
	}
}

void HarbourMode::mUpdateHarbourMode(Angler::Game* context, float time, float deltaTime)
{
	mBarIsMO = Angler::HelpFunctions::Geometry::pointIsWithinPolygon(&mBarMOS, mousePos);
	mMarketIsMO = Angler::HelpFunctions::Geometry::pointIsWithinPolygon(&mMarketMOS, mousePos);
	mWorkshopIsMO = Angler::HelpFunctions::Geometry::pointIsWithinPolygon(&mWorkshopMOS, mousePos);

	if (mBarIsMO && !mOldBarIsMO)
	{
		mOwner->getSound()->updateState(mSHarbour,		0x11010L + (mRadioCh > 0 ? 0x1000 : 0));
		mOwner->getSound()->updateState(mSBarO,			0x11011L + (mRadioCh > 0 ? 0x1000 : 0));
		mOwner->getSound()->updateState(mSWorkshopO,	0x11012L + (mRadioCh > 0 ? 0x1000 : 0));
		mOwner->getSound()->updateState(mSMarketO,		0x11013L + (mRadioCh > 0 ? 0x1000 : 0));
	}

	if (mWorkshopIsMO && !mOldWorkshopIsMO)
	{
		mOwner->getSound()->updateState(mSHarbour,		0x11020L + (mRadioCh > 0 ? 0x1000 : 0));
		mOwner->getSound()->updateState(mSBarO,			0x11021L + (mRadioCh > 0 ? 0x1000 : 0));
		mOwner->getSound()->updateState(mSWorkshopO,	0x11022L + (mRadioCh > 0 ? 0x1000 : 0));
		mOwner->getSound()->updateState(mSMarketO,		0x11023L + (mRadioCh > 0 ? 0x1000 : 0));
	}

	if (mMarketIsMO && !mOldMarketIsMO)
	{
		mOwner->getSound()->updateState(mSHarbour,		0x11030L + (mRadioCh > 0 ? 0x1000 : 0));
		mOwner->getSound()->updateState(mSBarO,			0x11031L + (mRadioCh > 0 ? 0x1000 : 0));
		mOwner->getSound()->updateState(mSWorkshopO,	0x11032L + (mRadioCh > 0 ? 0x1000 : 0));
		mOwner->getSound()->updateState(mSMarketO,		0x11033L + (mRadioCh > 0 ? 0x1000 : 0));
	}

	if ((!mBarIsMO && mOldBarIsMO) || (!mWorkshopIsMO && mOldWorkshopIsMO) || (!mMarketIsMO && mOldMarketIsMO))
	{
		mOwner->getSound()->updateState(mSHarbour,		0x11000L + (mRadioCh > 0 ? 0x1000 : 0));
		mOwner->getSound()->updateState(mSBarO,			0x11001L + (mRadioCh > 0 ? 0x1000 : 0));
		mOwner->getSound()->updateState(mSWorkshopO,	0x11002L + (mRadioCh > 0 ? 0x1000 : 0));
		mOwner->getSound()->updateState(mSMarketO,		0x11003L + (mRadioCh > 0 ? 0x1000 : 0));
	}
}

void HarbourMode::mUpdateRoom(Angler::Game* context, float time, float deltaTime)
{
	mInsideIsMO = Angler::HelpFunctions::Geometry::pointIsWithinPolygon(&mInsideMOS, mousePos);
	mSellButtonIsMO = Angler::HelpFunctions::Geometry::pointIsWithinPolygon(&mSellButtonMOS, mousePos);
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

		if (context->getMouseState().isButtonDown(sf::Mouse::Button::Left)
				&& !context->getMouseState().wasButtonDown(sf::Mouse::Button::Left))
				context->getSound()->playSound(mClick, false, 0x13000L, false);

		mMenuButtonRot = fmod(mMenuButtonRot, 2*3.1415f);

		if (mRoom == 0)
			mUpdateHarbourMode(context, time, deltaTime);
		else
			mUpdateRoom(context, time, deltaTime);

		if (mRoom != 0)
		{
			if (!mTrading && mBackButtonIsMO && !context->getMouseState().isButtonDown(sf::Mouse::Button::Left)
				&& context->getMouseState().wasButtonDown(sf::Mouse::Button::Left))
			{
				mShowRoom(0);
			}
			if (mTrading && mBackButtonIsMO && !context->getMouseState().isButtonDown(sf::Mouse::Button::Left)
				&& context->getMouseState().wasButtonDown(sf::Mouse::Button::Left))
			{
				mTrading = false;
			}
			if (mTrading && mSellButtonIsMO && !context->getMouseState().isButtonDown(sf::Mouse::Button::Left)
				&& context->getMouseState().wasButtonDown(sf::Mouse::Button::Left))
			{
				int *fc = ((IshavsfiskeGame*)context)->getFishCount();
				int sum = fc[0] * 10 + fc[1] * 20 + fc[2] * 30 + fc[3] * 40;
				fc[0] = fc[1] = fc[2] = fc[3] = 0;
				((IshavsfiskeGame*)context)->addToWallet(sum);
			}
			if (!mTrading && mInsideIsMO && !context->getMouseState().isButtonDown(sf::Mouse::Button::Left)
				&& context->getMouseState().wasButtonDown(sf::Mouse::Button::Left))
			{
				mTrading = true;
			}
		}
		else
		{
			if (mBackButtonIsMO && !context->getMouseState().isButtonDown(sf::Mouse::Button::Left)
				&& context->getMouseState().wasButtonDown(sf::Mouse::Button::Left))
			{
				mOwner->throwEvent(IshavsfiskeGame::Events::HarbourModeHide);
				mOwner->throwEvent(IshavsfiskeGame::Events::FishingModeShow, 0x10);
			}
			if (mBarIsMO && !context->getMouseState().isButtonDown(sf::Mouse::Button::Left)
				&& context->getMouseState().wasButtonDown(sf::Mouse::Button::Left))
			{
				mShowRoom(1);
			}
			else if (mWorkshopIsMO && !context->getMouseState().isButtonDown(sf::Mouse::Button::Left)
				&& context->getMouseState().wasButtonDown(sf::Mouse::Button::Left))
			{
				mShowRoom(2);
			}
			else if (mMarketIsMO && !context->getMouseState().isButtonDown(sf::Mouse::Button::Left)
				&& context->getMouseState().wasButtonDown(sf::Mouse::Button::Left))
			{
				mShowRoom(3);
			}
		}

		/*for (int i = 0; i < 4; i++)
		{
			if ((mRadioCh-1) == i && mRadioTime == -1.0f)
				mMusic[i]->setVolume(100.0f);
			else
				mMusic[i]->setVolume(0.0f);
		}*/

		if (mRadioTime >= 1.0f)
		{
			mRadioTime = -1.0f;

			if (mRadioCh == 0)
			{
				if (mRoom == 0)
				{
					mOwner->getSound()->updateState(mSHarbour,		0x11000L);
					mOwner->getSound()->updateState(mSBarO,			0x11001L);
					mOwner->getSound()->updateState(mSWorkshopO,	0x11002L);
					mOwner->getSound()->updateState(mSMarketO,		0x11003L);
				}
				else
				{
					mOwner->getSound()->updateState(mSBar,			(mRoom == 1 ? 0x11110 : 0x11111));
					mOwner->getSound()->updateState(mSWorkshop,		(mRoom == 2 ? 0x11120 : 0x11121));
					mOwner->getSound()->updateState(mSMarket,		(mRoom == 3 ? 0x11130 : 0x11131));
				}
			}

			for (int i = 0; i < 5; i++)
			{
				mOwner->getSound()->updateState(mMusic[i], 0x14000L + i + mRadioCh * 0x10);
				//printf("%03.0f ", mMusic[i]->getVolume());
			}
			//printf("\n");
		}
		else if (mRadioTime >= 0)	
		{
			mRadioTime += deltaTime;
		}

		if (mRadioIsMO && context->getMouseState().isButtonDown(sf::Mouse::Button::Left)
			&& !context->getMouseState().wasButtonDown(sf::Mouse::Button::Left))
		{
			mRadioTime = 0;
			mRadioCh = (mRadioCh + 1) % 6;

			//printf("%u\n", mRadioCh);

			context->getSound()->playSound(mRadioSound, false, 0x13001L, false);

			if (mRadioCh > 0)
			{
				if (mRoom == 0)
				{
					mOwner->getSound()->updateState(mSHarbour,		0x12000L);
					mOwner->getSound()->updateState(mSBarO,			0x12001L);
					mOwner->getSound()->updateState(mSWorkshopO,	0x12002L);
					mOwner->getSound()->updateState(mSMarketO,		0x12003L);
				}
				else
				{
					mOwner->getSound()->updateState(mSBar,			(mRoom == 1 ? 0x12110 : 0x12111));
					mOwner->getSound()->updateState(mSWorkshop,		(mRoom == 2 ? 0x12120 : 0x12121));
					mOwner->getSound()->updateState(mSMarket,		(mRoom == 3 ? 0x12130 : 0x12131));
				}
			}

			for (int i = 0; i < 5; i++)
			{
				mOwner->getSound()->updateState(mMusic[i], 0x14000L + i);
			}
			//printf("\n");
		}

		mUpdateChildren(context, time, deltaTime);

		mOldBarIsMO = mBarIsMO;
		mOldWorkshopIsMO = mWorkshopIsMO;
		mOldMarketIsMO = mMarketIsMO;
		mOldBackButtonIsMO = mBackButtonIsMO;
		mOldRadioIsMO = mRadioIsMO;
	}
}

void HarbourMode::loadContent()
{
	mTXHarbour->loadFromFile("staden_6.png");

	mTXBarHO->loadFromFile("bar_Hoverover.png");
	mTXMarketHO->loadFromFile("Market_Hoverover.png");
	mTXWorkshopHO->loadFromFile("Workshop_Hoverover.png");
	mTXUI->loadFromFile("Sheet_1.png");
	mTXBackButton->loadFromFile("knappsheet.png");
	mTXCursor->loadFromFile("cursor_hand_sheet.png");

	mTXFont->loadFromFile("font.png");

	mTXBarInside->loadFromFile("bar_3_stolar.png");
	mTXBarInsideHO->loadFromFile("bar_Olaf_hoverover.png");

	mTXWorkshopInside->loadFromFile("verkstad_3.png");
	mTXWorkshopInsideHO->loadFromFile("workshop_mira_hoverover.png");

	mTXMarketInside->loadFromFile("marknad_3.png");
	mTXMarketInsideHO->loadFromFile("marknad__ThordBirgitte_Hoverover.png");

	mMusicBuffer[0]->loadFromFile("Harbor_Radio_Blues01.ogg");
	mMusicBuffer[1]->loadFromFile("Harbor_Radio_Blues02.ogg");
	mMusicBuffer[2]->loadFromFile("Harbor_Radio_Jazz01.ogg");
	mMusicBuffer[3]->loadFromFile("Harbor_Radio_Jazz02.ogg");
	mMusicBuffer[4]->loadFromFile("Harbor_Radio_Jazz03.ogg");

	mRadioBuffer->loadFromFile("Radio_tuning.ogg");
	mRadioSound->setBuffer(*mRadioBuffer);

	for (int i = 0; i < 5; i++)
	{
		mMusic[i]->setBuffer(*mMusicBuffer[i]);
	}

	mClickBuffer->loadFromFile("Klick.ogg");
	mClick->setBuffer(*mClickBuffer);

	mSBHarbour->loadFromFile("Hamn.ogg");
	mSHarbour->setBuffer(*mSBHarbour);

	mSBBar->loadFromFile("Taverna.ogg");
	mSBar->setBuffer(*mSBBar);

	mSBBarO->loadFromFile("Taverna_Dov.ogg");
	mSBarO->setBuffer(*mSBBarO);

	mSBWorkshop->loadFromFile("Verkstad.ogg");
	mSWorkshop->setBuffer(*mSBWorkshop);

	mSBWorkshopO->loadFromFile("Verkstad_Dov.ogg");
	mSWorkshopO->setBuffer(*mSBWorkshopO);

	mSBMarket->loadFromFile("Fiskmarknad.ogg");
	mSMarket->setBuffer(*mSBMarket);

	mSBMarketO->loadFromFile("Fiskmarknad_Dov.ogg");
	mSMarketO->setBuffer(*mSBMarketO);

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

	//Sell button
	mSellButtonMOS.push_back(sf::Vector2f(19/40.0f, 30/40.0f));
	mSellButtonMOS.push_back(sf::Vector2f(11/40.0f, 30/40.0f));
	mSellButtonMOS.push_back(sf::Vector2f(11/40.0f, 33/40.0f));
	mSellButtonMOS.push_back(sf::Vector2f(19/40.0f, 33/40.0f));

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

	mTXFont = new sf::Texture();

	mTXBarInside = new sf::Texture();
	mTXBarInsideHO = new sf::Texture();

	mTXWorkshopInside = new sf::Texture();
	mTXWorkshopInsideHO = new sf::Texture();

	mTXMarketInside = new sf::Texture();
	mTXMarketInsideHO = new sf::Texture();

	mRadioSound = new sf::Sound();
	mRadioBuffer = new sf::SoundBuffer();
	for (int i = 0; i < 5; i++)
	{
		mMusicBuffer[i] = new sf::SoundBuffer();
		mMusic[i] = new sf::Sound();
	}

	mFont = new Font();

	mClick = new sf::Sound();
	mClickBuffer = new sf::SoundBuffer();

	mSHarbour = new sf::Sound();
	mSBHarbour = new sf::SoundBuffer();

	mSBar = new sf::Sound();
	mSBBar = new sf::SoundBuffer();

	mSBarO = new sf::Sound();
	mSBBarO = new sf::SoundBuffer();

	mSWorkshop = new sf::Sound();
	mSBWorkshop = new sf::SoundBuffer();

	mSWorkshopO = new sf::Sound();
	mSBWorkshopO = new sf::SoundBuffer();

	mSMarket = new sf::Sound();
	mSBMarket = new sf::SoundBuffer();

	mSMarketO = new sf::Sound();
	mSBMarketO = new sf::SoundBuffer();
}

void HarbourMode::mEnable(bool enabled)
{
	if (enabled)
	{
		mOwner->setCursorVisible(false);

		mOwner->getSound()->playSound(mMusic[0], false, 0x14000, true);
		mOwner->getSound()->playSound(mMusic[1], false, 0x14001, true);
		mOwner->getSound()->playSound(mMusic[2], false, 0x14002, true);
		mOwner->getSound()->playSound(mMusic[3], false, 0x14003, true);
		mOwner->getSound()->playSound(mMusic[4], false, 0x14004, true);

		mOwner->getSound()->playSound(mSHarbour, false, 0x11000, true);

		mOwner->getSound()->playSound(mSBar, false, 0x10001, true);
		mOwner->getSound()->playSound(mSBarO, false, 0x11001, true);

		mOwner->getSound()->playSound(mSWorkshop, false, 0x10002, true);
		mOwner->getSound()->playSound(mSWorkshopO, false, 0x11002, true);

		mOwner->getSound()->playSound(mSMarket, false, 0x10003, true);
		mOwner->getSound()->playSound(mSMarketO, false, 0x11003, true);

		mBarIsMO = false;
		mWorkshopIsMO = false;
		mMarketIsMO = false; 
		mRadioIsMO = false; 
		mMenuButtonIsMO = false; 
		mMenuButtonRot = 0.0f;
		mRadioCh = 0; 
		mRadioTime =  -1.0f;
		mRoom = 0;

		mShowRoom(0);
	}
	else
	{
		mOwner->setCursorVisible(true);

		mOwner->getSound()->stopSound(mMusic[0]);
		mOwner->getSound()->stopSound(mMusic[1]);
		mOwner->getSound()->stopSound(mMusic[2]);
		mOwner->getSound()->stopSound(mMusic[3]);

		mOwner->getSound()->stopSound(mSHarbour);

		mOwner->getSound()->stopSound(mSBar);
		mOwner->getSound()->stopSound(mSBarO);

		mOwner->getSound()->stopSound(mSWorkshop);
		mOwner->getSound()->stopSound(mSWorkshopO);

		mOwner->getSound()->stopSound(mSMarket);
		mOwner->getSound()->stopSound(mSMarketO);

		mOwner->clearGraphicsLayers();
	}
}

void HarbourMode::mShowRoom(int ind)
{
	mRoom = ind;

	for (int i = 0; i < 5; i++)
	{
		mOwner->getSound()->updateState(mMusic[i], 0x14000L + i + mRadioCh * 0x10);
	}

	int sizes[8] = { 1, 1, 1, 1, 256, 1, 256, 1 };
	sf::Texture* textures[8] = { mTXHarbour, mTXBarHO, mTXMarketHO, mTXWorkshopHO, mTXUI, mTXBackButton, mTXFont, mTXCursor };
	if (ind == 0)
	{
		mOwner->setupGraphicsLayers(8, sizes, textures);

		if (mRadioCh > 0)
		{
			mOwner->getSound()->updateState(mSHarbour,		0x12000L);
			mOwner->getSound()->updateState(mSBarO,			0x12001L);
			mOwner->getSound()->updateState(mSWorkshopO,	0x12002L);
			mOwner->getSound()->updateState(mSMarketO,		0x12003L);
		}
		else
		{
			mOwner->getSound()->updateState(mSHarbour,		0x11000L);
			mOwner->getSound()->updateState(mSBarO,			0x11001L);
			mOwner->getSound()->updateState(mSWorkshopO,	0x11002L);
			mOwner->getSound()->updateState(mSMarketO,		0x11003L);
		}
	}
	else
	{
		mInsideMOS.clear();

		if (mRadioCh > 0)
		{
			mOwner->getSound()->updateState(mSHarbour,		0x11100L);
			mOwner->getSound()->updateState(mSBarO,			0x11101L);
			mOwner->getSound()->updateState(mSWorkshopO,	0x11102L);
			mOwner->getSound()->updateState(mSMarketO,		0x11103L);

			mOwner->getSound()->updateState(mSBar,			(ind == 1 ? 0x11110 : 0x11111));
			mOwner->getSound()->updateState(mSWorkshop,		(ind == 2 ? 0x11120 : 0x11121));
			mOwner->getSound()->updateState(mSMarket,		(ind == 3 ? 0x11130 : 0x11131));
		}
		else
		{
			mOwner->getSound()->updateState(mSHarbour,		0x11100L);
			mOwner->getSound()->updateState(mSBarO,			0x11101L);
			mOwner->getSound()->updateState(mSWorkshopO,	0x11102L);
			mOwner->getSound()->updateState(mSMarketO,		0x11103L);

			mOwner->getSound()->updateState(mSBar,			(ind == 1 ? 0x12110 : 0x12111));
			mOwner->getSound()->updateState(mSWorkshop,		(ind == 2 ? 0x12120 : 0x12121));
			mOwner->getSound()->updateState(mSMarket,		(ind == 3 ? 0x12130 : 0x12131));
		}

		if (ind == 1)
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
		else if (ind == 2)
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
		else if (ind == 3)
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

		mOwner->setupGraphicsLayers(8, sizes, textures);
	}
}