//Version: 0.1.4
//Author: Jakob Pipping
//Contributors: Oskar Engblad

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
			/*glPushMatrix();
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
			glPopMatrix();*/

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
				/*
				glPushMatrix();
					glScalef(1/40.0f, 1/40.0f, 1);
						glTranslatef(3, 9.8f, 0);
					glScalef(40.0f, 40.0f, 1);	
					*/

					//BG
					glPushMatrix();
						glScalef(98/1000.0f, 98/1000.0f, 1);
						graphics->draw(5, sf::Vector2f(0.5f, 1.0f), sf::Vector2f(150/1500.0f, 1190.0f/1600.0f), sf::Vector2f(22/1500.0f, 98/1600.0f));
					glPopMatrix();

					//Liquid
					/*
					glPushMatrix();
						glScalef(1/40.0f, 1/40.0f, 1);
							glTranslatef(0, 4 - 4 * ((IceBreaker*)mShipBreaker)->getHull(), 0);
						glScalef(40.0f, 40.0f, 1);
						glScalef(97/1000.0f, 97/1000.0f, 1);
						graphics->draw(5, sf::Vector2f(0.5f, 1.0f), sf::Vector2f(150/1500.0f, 1093.0f/1600.0f), sf::Vector2f(20/1500.0f, 97/1600.0f));
					glPopMatrix();
					*/

					//Scale
					/*
					glPushMatrix();
						glScalef(95/1000.0f, 95/1000.0f, 1);
						graphics->draw(5, sf::Vector2f(0.5f, 1.0f), sf::Vector2f(170/1500.0f, 1093.0f/1600.0f), sf::Vector2f(15/1500.0f, 95/1600.0f));
					glPopMatrix();
				glPopMatrix();
				*/

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
						graphics->draw(5, sf::Vector2f(11/24.0f, 65/95.0f), sf::Vector2f(0, 1375.0f/1600.0f), sf::Vector2f(24/1500.0f, 95/1600.0f));
					glPopMatrix();

					//Bolt
					glPushMatrix();
						glScalef(5/1000.0f, 5/1000.0f, 1);
						graphics->draw(5, sf::Vector2f(0.5f, 0.5f), sf::Vector2f(24/1500.0f, 1375.0f/1600.0f), sf::Vector2f(11/1500.0f, 11/1600.0f));
					glPopMatrix();
					

					//Glass
					glPushMatrix();
						glScalef(93/1000.0f, 93/1000.0f, 1);
						graphics->draw(5, sf::Vector2f(0.5f, 0.5f), sf::Vector2f(161/1500.0f, 1000.0f/1600.0f), sf::Vector2f(95/1500.0f, 93/1600.0f));
					glPopMatrix();

					//Hull Armor
					//Left Half
					glPushMatrix();
						glScalef(15/1000.0f, 15/1000.0f, 1);
						glTranslated(-5, -1, 1);
						if(((IceBreaker*)mShipBreaker)->getHull() >= 1/19.0f)
						{
						//Piece 1
						graphics->draw(5, sf::Vector2f(0, 0), sf::Vector2f(34/1500.0f, 1375/1600.0f), sf::Vector2f(11/1500.0f, 14/1600.0f));
						glTranslatef(0, -0.75f, 1);
						glScalef(0.65f, 0.75f, 1);
						}
						if(((IceBreaker*)mShipBreaker)->getHull() >= 2/19.0f)
						{
						//Piece 2
						graphics->draw(5, sf::Vector2f(0, 0), sf::Vector2f(46/1500.0f, 1375/1600.0f), sf::Vector2f(13/1500.0f, 9/1600.0f));
						glTranslatef(0, -1, 1);
						glScalef(1.35f, 1.25f, 1);
						}
						if(((IceBreaker*)mShipBreaker)->getHull() >= 3/19.0f)
						{
						//Piece 3
						graphics->draw(5, sf::Vector2f(0, 0), sf::Vector2f(59/1500.0f, 1375/1600.0f), sf::Vector2f(14/1500.0f, 12/1600.0f));
						glTranslatef(0.45f, -0.85f, 1);
						}
						if(((IceBreaker*)mShipBreaker)->getHull() >= 4/19.0f)
						{
						//Piece 4
						graphics->draw(5, sf::Vector2f(0, 0), sf::Vector2f(74/1500.0f, 1375/1600.0f), sf::Vector2f(13/1500.0f, 12/1600.0f));
						glTranslatef(0.65f, -0.55f, 1);
						}
						if(((IceBreaker*)mShipBreaker)->getHull() >= 5/19.0f)
						{
						//Piece 5
						graphics->draw(5, sf::Vector2f(0, 0), sf::Vector2f(88/1500.0f, 1375/1600.0f), sf::Vector2f(15/1500.0f, 15/1600.0f));
						glTranslatef(0.6f, -0.55f, 1);
						}
						if(((IceBreaker*)mShipBreaker)->getHull() >= 6/19.0f)
						{
						//Piece 6
						graphics->draw(5, sf::Vector2f(0, 0), sf::Vector2f(104/1500.0f, 1375/1600.0f), sf::Vector2f(14/1500.0f, 13/1600.0f));
						glTranslatef(0.7f, -0.45f, 1);
						}
						if(((IceBreaker*)mShipBreaker)->getHull() >= 7/19.0f)
						{
						//Piece 7
						graphics->draw(5, sf::Vector2f(0, 0), sf::Vector2f(119/1500.0f, 1375/1600.0f), sf::Vector2f(14/1500.0f, 13/1600.0f));
						glTranslatef(0.8f, -0.35f, 1);
						}
						if(((IceBreaker*)mShipBreaker)->getHull() >= 8/19.0f)
						{
						//Piece 8
						graphics->draw(5, sf::Vector2f(0, 0), sf::Vector2f(134/1500.0f, 1375/1600.0f), sf::Vector2f(11/1500.0f, 14/1600.0f));
						glTranslatef(0.75f, 0, 1);
						}
						if(((IceBreaker*)mShipBreaker)->getHull()>= 9/19.0f)
						{
						//Piece 9
						glScalef(1, 0.8f, 1);
						graphics->draw(5, sf::Vector2f(0, 0), sf::Vector2f(146/1500.0f, 1375/1600.0f), sf::Vector2f(11/1500.0f, 12/1600.0f));
						glTranslatef(0.9f, 0.1f, 1);
						glScalef(1, 1.2f, 1);
						glScalef(1.1f, 0.7f, 1);
						}
						if(((IceBreaker*)mShipBreaker)->getHull() >= 10/19.0f)
						{
						//Piece 10
						graphics->draw(5, sf::Vector2f(0, 0), sf::Vector2f(158/1500.0f, 1375/1600.0f), sf::Vector2f(11/1500.0f, 10/1600.0f));
						glTranslatef(1.1f, -0.1f, 1);
						glScalef(1, 1.3f, 1);
						}
						if(((IceBreaker*)mShipBreaker)->getHull()>= 11/19.0f)
						{
						//Piece 11
						graphics->draw(5, sf::Vector2f(0, 0), sf::Vector2f(170/1500.0f, 1375/1600.0f), sf::Vector2f(12/1500.0f, 12/1600.0f));
						glTranslatef(0.9f, 0.15f, 1);
						}
						if(((IceBreaker*)mShipBreaker)->getHull() >= 12/19.0f)
						{
						//Piece 12
						graphics->draw(5, sf::Vector2f(0, 0), sf::Vector2f(183/1500.0f, 1375/1600.0f), sf::Vector2f(10/1500.0f, 13/1600.0f));
						glTranslatef(0.6f, 0.3f, 1);
						}
						if(((IceBreaker*)mShipBreaker)->getHull() >= 13/19.0f)
						{
						//Piece 13
						graphics->draw(5, sf::Vector2f(0, 0), sf::Vector2f(194/1500.0f, 1375/1600.0f), sf::Vector2f(13/1500.0f, 13/1600.0f));
						glTranslatef(0.65f, 0.45f, 1);
						}
						if(((IceBreaker*)mShipBreaker)->getHull() >= 14/19.0f)
						{
						//Piece 14
						graphics->draw(5, sf::Vector2f(0, 0), sf::Vector2f(208/1500.0f, 1375/1600.0f), sf::Vector2f(14/1500.0f, 14/1600.0f));
						glTranslatef(0.5f, 0.55f, 1);
						}
						if(((IceBreaker*)mShipBreaker)->getHull() >= 15/19.0f)
						{
						//Piece 15
						graphics->draw(5, sf::Vector2f(0, 0), sf::Vector2f(223/1500.0f, 1375/1600.0f), sf::Vector2f(15/1500.0f, 16/1600.0f));
						glTranslatef(0.45f, 0.55f, 1);
						}else if(((IceBreaker*)mShipBreaker)->getHull() >= 16/19.0f)
						{
						//Piece 16
						graphics->draw(5, sf::Vector2f(0, 0), sf::Vector2f(239/1500.0f, 1375/1600.0f), sf::Vector2f(13/1500.0f, 13/1600.0f));
						glScalef(0.8f, 1.1f, 1);
						glTranslatef(0.5f, 0.65f, 1);
						}
						if(((IceBreaker*)mShipBreaker)->getHull() >= 17/19.0f)
						{
						//Piece 17
						graphics->draw(5, sf::Vector2f(0, 0), sf::Vector2f(253/1500.0f, 1375/1600.0f), sf::Vector2f(14/1500.0f, 12/1600.0f));
						glTranslatef(0.3f, 1, 1);
						glScalef(0.8f, 1, 1);
						}
						if(((IceBreaker*)mShipBreaker)->getHull() >= 18/19.0f)
						{
						//Piece 18
						graphics->draw(5, sf::Vector2f(0, 0), sf::Vector2f(268/1500.0f, 1375/1600.0f), sf::Vector2f(14/1500.0f, 9/1600.0f));
						glTranslatef(0.3, 1, 1);
						glScalef(1.4f, 1.2f, 1);
						}
						if(((IceBreaker*)mShipBreaker)->getHull() == 1)
						{
						//Piece 19
						graphics->draw(5, sf::Vector2f(0, 0), sf::Vector2f(283/1500.0f, 1375/1600.0f), sf::Vector2f(11/1500.0f, 13/1600.0f));
						}
					glPopMatrix();
					//Right Half
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

			if (mShowCounter)
			{
				//Fish
				glPushMatrix();
					glScalef(1/40.0, 1/40.0f, 1);

					glTranslatef(9.0f, 1.0f, 0);

					glPushMatrix();
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(550/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(650/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
					glPopMatrix();

					glTranslatef(0, 1, 0);

					glPushMatrix();
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(550/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(650/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
					glPopMatrix();

					glTranslatef(0.5, -0.5f, 0);
					glScalef(40.0, 40.0f, 1);
					char c[32];
					sprintf_s(c, "Fish: %4u", ((FishingBoat*)mShipFishing)->getAmmount());
					mFont->drawString(graphics, c, 7, 0.9f);

				glPopMatrix();
			}

			if (mShowTimer)
			{
				//Timer
				glPushMatrix();
					glScalef(1/40.0, 1/40.0f, 1);

					glTranslatef(43.0f, 1.0f, 0);

					glPushMatrix();
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(550/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(650/1500.0f, 0), sf::Vector2f(50/1500.0f, 50/1600.0f));
					glPopMatrix();

					glTranslatef(0, 1, 0);

					glPushMatrix();
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(550/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(600/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
						glTranslatef(1, 0, 0);
						graphics->draw(6, sf::Vector2f(0, 0), sf::Vector2f(650/1500.0f, 100/1600.0f), sf::Vector2f(50/1500.0f, 50/1600.0f));
					glPopMatrix();

					glTranslatef(0.5, -0.5f, 0);
					glScalef(40.0, 40.0f, 1);
					char c[32];
					sprintf_s(c, "Timer: %02u:%02u", (int)floor(mTimer/60), (int)floor(fmod(mTimer,60)));
					mFont->drawString(graphics, c, 7, 0.9f);

				glPopMatrix();
			}
		glPopMatrix();

	
		mDrawChildren(context, graphics, time, deltaTime);
	}
}