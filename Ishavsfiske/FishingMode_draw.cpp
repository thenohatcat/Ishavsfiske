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

			//Breaker UI
			glPushMatrix();
				glScalef(1/40.0f, 1/40.0f, 1);
					glTranslatef(1, 24, 0);
				glScalef(40.0f, 40.0f, 1);
				
				//Liquid
				glPushMatrix();
					glScalef(1/40.0f, 1/40.0f, 1);
						glTranslatef(3, 9.8f, 0);
					glScalef(40.0f, 40.0f, 1);	

					//BG
					glPushMatrix();
						glScalef(98/1000.0f, 98/1000.0f, 1);
						graphics->draw(5, sf::Vector2f(0.5f, 1.0f), sf::Vector2f(150/1500.0f, 1190.0f/1600.0f), sf::Vector2f(22/1500.0f, 98/1600.0f));
					glPopMatrix();

					//Liquid
					glPushMatrix();
						glScalef(1/40.0f, 1/40.0f, 1);
							glTranslatef(0, 4 - 4 * ((IceBreaker*)mShipBreaker)->getHull(), 0);
						glScalef(40.0f, 40.0f, 1);
						glScalef(97/1000.0f, 97/1000.0f, 1);
						graphics->draw(5, sf::Vector2f(0.5f, 1.0f), sf::Vector2f(150/1500.0f, 1093.0f/1600.0f), sf::Vector2f(20/1500.0f, 97/1600.0f));
					glPopMatrix();

					//Scale
					glPushMatrix();
						glScalef(95/1000.0f, 95/1000.0f, 1);
						graphics->draw(5, sf::Vector2f(0.5f, 1.0f), sf::Vector2f(170/1500.0f, 1093.0f/1600.0f), sf::Vector2f(15/1500.0f, 95/1600.0f));
					glPopMatrix();
				glPopMatrix();

				//Background
				glPushMatrix();
					glScalef(375/1000.0f, 375/1000.0f, 1);
					graphics->draw(5, sf::Vector2f(0, 0), sf::Vector2f(0, 1000.0f/1600.0f), sf::Vector2f(150/1500.0f, 375/1600.0f));
				glPopMatrix();

				//Speedometer
				glPushMatrix();
					glScalef(1/40.0f, 1/40.0f, 1);
						glTranslatef(3, 1, 0);
					glScalef(40.0f, 40.0f, 1);

					//Needle
					glPushMatrix();
						glScalef(1/40.0f, 1/40.0f, 1);
							glTranslatef(abs(mShipBreaker->getVelocity().y) * 1/0.0458f * 4 - 2, 0, 0);
						glScalef(40.0f, 40.0f, 1);
						glScalef(15/1000.0f, 15/1000.0f, 1);
						graphics->draw(5, sf::Vector2f(0.5f, 0.0f), sf::Vector2f(150/1500.0f, 1071.0f/1600.0f), sf::Vector2f(3/1500.0f, 15/1600.0f));
					glPopMatrix();

					//Cover
					glPushMatrix();
						glScalef(1/40.0f, 1/40.0f, 1);
							glTranslatef(0, 0.45, 0);
						glScalef(40.0f, 40.0f, 1);

						glScalef(4/1000.0f, 4/1000.0f, 1);
						graphics->draw(5, sf::Vector2f(0.5f, 0.0f), sf::Vector2f(150/1500.0f, 1086.0f/1600.0f), sf::Vector2f(10/1500.0f, 4/1600.0f));
					glPopMatrix();
				glPopMatrix();

				//Dial
				glPushMatrix();
					glScalef(1/40.0f, 1/40.0f, 1);
						glTranslatef(3, 12, 0);
					glScalef(40.0f, 40.0f, 1);
					
					//Needle
					glPushMatrix();
						glScalef(66/1000.0f, 66/1000.0f, 1);
						glRotatef(-95 + 190 * ((IceBreaker*)mShipBreaker)->getHealth(), 0, 0, 1);
						graphics->draw(5, sf::Vector2f(0.5f, 38.5/66.0f), sf::Vector2f(150/1500.0f, 1000.0f/1600.0f), sf::Vector2f(11/1500.0f, 66/1600.0f));
					glPopMatrix();

					//Bolt
					glPushMatrix();
						glScalef(5/1000.0f, 5/1000.0f, 1);
						graphics->draw(5, sf::Vector2f(0.5f, 0.5f), sf::Vector2f(150/1500.0f, 1066.0f/1600.0f), sf::Vector2f(5/1500.0f, 5/1600.0f));
					glPopMatrix();

					//Glass
					glPushMatrix();
						glScalef(93/1000.0f, 93/1000.0f, 1);
						graphics->draw(5, sf::Vector2f(0.5f, 0.5f), sf::Vector2f(161/1500.0f, 1000.0f/1600.0f), sf::Vector2f(95/1500.0f, 93/1600.0f));
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();

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
				//glRotatef(time / 1.337f * 360.0f, 0, 0, 1);
				graphics->draw(5, sf::Vector2f(10.0f/20.0f, 55.0f/108.0f), sf::Vector2f(400/1500.0f, 150/1600.0f), sf::Vector2f(20/1500.0f, 108/1600.0f));
			glPopMatrix();

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