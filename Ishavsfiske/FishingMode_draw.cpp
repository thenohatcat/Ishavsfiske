//Version: 0.1.4
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_4
#error FishingMode_draw.cpp: Wrong version 0.1.4
#endif

#include "IshavsfiskeGame.h"

#include "Ship.h"
#include "FishingBoat.h"

#include <glm\glm.hpp>

#include <Angler\Node.h>
#include <Angler\Transformation.h>
#include <Angler\HelpFunctions.h>

#include "Font.h"

using namespace Ishavsfiske;

void FishingMode::draw(Angler::Game* context, Angler::Graphics::GraphicsEngine* graphics, float time, float deltaTime)
{
	if (mVisible)
	{
		glPushMatrix();
			//Left UI
			glPushMatrix();
				graphics->draw(5, sf::Vector2f(0, 0), sf::Vector2f(0, 0), sf::Vector2f(200/1500.0f, 1000/1600.0f));
			glPopMatrix();

			// Status Left
			/*glPushMatrix();
				glScaled(15/40.0, 15/40.0, 1);
					glScaled(1/15.0, 1/15.0, 1);
						glTranslated(1, 25, 0);
					glScaled(15.0, 15.0, 1);
				mGraphics->draw(4, sf::Vector2f(0, 0));
			glPopMatrix();*/

			// Upgrades
			glPushMatrix();
				glScaled(3/40.0, 3/40.0, 1);
				glScaled(1/3.0, 1/3.0, 1);
					glTranslated(1, -1, 0);
				glScaled(3.0, 3.0, 1);

				for (int i = 0; i < 7; i++)
				{
						glScaled(1/3.0, 1/3.0, 1);
							glTranslated(0, 3, 0);
						glScaled(3.0, 3.0, 1);
					graphics->draw(5, sf::Vector2f(0, 0), sf::Vector2f(560/1500.0f, 150/1600.0f), sf::Vector2f(150/1500.0f, 75/1600.0f));
				}
			glPopMatrix();

			//Right UI
			glPushMatrix();
				glTranslated(14/10.0, 0, 0);
				graphics->draw(5, sf::Vector2f(0, 0), sf::Vector2f(200/1500.0f, 0), sf::Vector2f(200/1500.0f, 1000/1600.0f));
			glPopMatrix();

			//// Status Right
			//glPushMatrix();
			//	glScaled(15/40.0, 15/40.0, 1);
			//		glScaled(1/15.0, 1/15.0, 1);
			//			glTranslated(14*4 + 1, 25, 0);
			//		glScaled(15.0, 15.0, 1);
			//	mGraphics->draw(4, sf::Vector2f(0, 0));
			//glPopMatrix();

			////Fish Counter
			//glPushMatrix();
			//	glScaled(1/20.0, 1/20.0, 1);
			//	glTranslated(6, 1/2.0, 0);
			//	mGraphics->draw(4, sf::Vector2f(0, 0));
			//glPopMatrix();

			////Timer
			//glPushMatrix();
			//	glScaled(1/20.0, 1/20.0, 1);
			//	glTranslated(14, 1/2.0, 0);
			//	mGraphics->draw(4, sf::Vector2f(0, 0));
			//glPopMatrix();

			////Cash
			//glPushMatrix();
			//	glScaled(1/20.0, 1/20.0, 1);
			//	glTranslated(22, 1/2.0, 0);
			//	mGraphics->draw(4, sf::Vector2f(0, 0));
			//glPopMatrix();

			//Menu button
			glPushMatrix();
				glScalef(3/20.0f, 3/20.0f, 1.0f);
				glScalef(1/3.0f, 1/3.0f, 1.0f);
					glTranslatef(4.0f, 17.0f, 0);
				glScalef(3.0f, 3.0f, 1.0f);
				graphics->draw(5, sf::Vector2f(0, 0), sf::Vector2f(400/1500.0f, 0), sf::Vector2f(150/1500.0f, 150/1600.0f));
			glPopMatrix();

			//Menu needle
			glPushMatrix();
				glScalef(3/20.0f, 3/20.0f, 1.0f);
				glScalef(1/3.0f, 1/3.0f, 1.0f);
					glTranslatef(5.5f, 18.5f, 0.0f);
				glScalef(3.0f, 3.0f, 1.0f);
				glRotatef(time / 1.337f * 360.0f, 0, 0, 1);
				graphics->draw(5, sf::Vector2f(10.0f/20.0f, 55.0f/108.0f), sf::Vector2f(400/1500.0f, 150/1600.0f), sf::Vector2f(20/1500.0f, 108/1600.0f));
			glPopMatrix();

			////Wind Flag
			//glPushMatrix();
			//	glScaled(1/10.0, 1/10.0, 1);
			//	glTranslated(13, 9, 0);
			//	mGraphics->draw(4, sf::Vector2f(0, 0));
			//glPopMatrix();

			//Radio
			glPushMatrix();
				glScalef(1/20.f, 1/20.f, 1);
					glTranslatef(28, 20, 0);
				glScalef(20.f, 20.f, 1);
				glScalef(75/1000.0f, 75/1000.0f, 1);
				graphics->draw(5, sf::Vector2f(1, 1), sf::Vector2f(420/1500.0f, 150/1600.0f), sf::Vector2f(140/1500.0f, 75/1600.0f));
			glPopMatrix();
		glPopMatrix();

	
		mDrawChildren(context, graphics, time, deltaTime);
	}
}