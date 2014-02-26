//Version: 0.1.4
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_4
#error IshavsfiskeGame_draw.cpp: Wrong version 0.1.4
#endif

#include "IshavsfiskeGame.h"

#include "Ship.h"

#include <glm\glm.hpp>

#include <Angler\Node.h>
#include <Angler\Transformation.h>
#include <Angler\HelpFunctions.h>

#include "Font.h"

using namespace Ishavsfiske;

float avd;
unsigned int frmd;
float fps;

void IshavsfiskeGame::mDrawUI(float time, float deltaTime)
{
	float ar = mGraphics->getWidth() / (float)mGraphics->getHeight();

	if (frmd < 50)
	{
		frmd++;
		avd += deltaTime;
	}
	else
	{
		fps = frmd/avd;
		frmd = 0;
		avd = 0;
	}

	//Draw UI
	glPushMatrix();
		//Left UI
		glPushMatrix();
			mGraphics->draw(5, sf::Vector2f(0, 0), sf::Vector2f(0, 0), sf::Vector2f(200/1500.0f, 1000/1600.0f));
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
				mGraphics->draw(5, sf::Vector2f(0, 0), sf::Vector2f(560/1500.0f, 150/1600.0f), sf::Vector2f(150/1500.0f, 75/1600.0f));
			}
		glPopMatrix();

		//Right UI
		glPushMatrix();
			glTranslated(14/10.0, 0, 0);
			mGraphics->draw(5, sf::Vector2f(0, 0), sf::Vector2f(200/1500.0f, 0), sf::Vector2f(200/1500.0f, 1000/1600.0f));
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
			mGraphics->draw(5, sf::Vector2f(0, 0), sf::Vector2f(400/1500.0f, 0), sf::Vector2f(150/1500.0f, 150/1600.0f));
		glPopMatrix();

		//Menu needle
		glPushMatrix();
			glScalef(3/20.0f, 3/20.0f, 1.0f);
			glScalef(1/3.0f, 1/3.0f, 1.0f);
				glTranslatef(5.5f, 18.5f, 0.0f);
			glScalef(3.0f, 3.0f, 1.0f);
			glRotatef(time / 1.337f * 360.0f, 0, 0, 1);
			mGraphics->draw(5, sf::Vector2f(10.0f/20.0f, 55.0f/108.0f), sf::Vector2f(400/1500.0f, 150/1600.0f), sf::Vector2f(20/1500.0f, 108/1600.0f));
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
			mGraphics->draw(5, sf::Vector2f(1, 1), sf::Vector2f(420/1500.0f, 150/1600.0f), sf::Vector2f(140/1500.0f, 75/1600.0f));
		glPopMatrix();

		char s[32];
		sprintf_s(s, 32, "FPS: %03.0f", fps);
		mFont->drawString(mGraphics, "Ishavsfiske 0.1.4", 6, 1);
		glTranslatef(0, 1/40.0f, 0);
		mFont->drawString(mGraphics, std::string(s), 6, 1);
	glPopMatrix();
}

int tm;

void IshavsfiskeGame::mDraw(float time, float deltaTime)
{
	mGraphics->begin();

	//Draw UI
	mDrawUI(time, deltaTime);

	//Draw SceneRoot
	mSceneRoot->draw(this, mGraphics, time, deltaTime);
	mGraphics->end();

#ifdef _DEBUG
#ifdef _DEBUG_COLL
	tm++;
	//if ((tm % 4) == 0)
	if (1)
	{
		tm %= 16;

		glLoadIdentity();

		gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0);

		glDisable(GL_TEXTURE_2D);

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		//Draw collision boxes
		std::vector<Angler::Node*> nds = Angler::HelpFunctions::Nodes::getDescendants(mSceneRoot);
		glPushMatrix();
		for (int i = 0; i < nds.size(); i++)
		{
			if (typeid(*nds.at(i)) == typeid(Angler::Nodes::CollisionNode))
			{
				Angler::Nodes::CollisionNode* n = (Angler::Nodes::CollisionNode*)nds.at(i);

				std::vector<sf::Vector2f> ov = n->getTransformedPoints();

				sf::Vector2f ul = n->getBoundingUL(), lr = n->getBoundingLR();

				glLineWidth(3);

				glColor3d(1, 1, 0);
				glBegin(GL_POLYGON);
					glVertex2d(lr.x, lr.y);
					glVertex2d(lr.x, ul.y);
					glVertex2d(ul.x, ul.y);
					glVertex2d(ul.x, lr.y);
				glEnd();

				glLineWidth(2);

				glColor3d(1, 0, 0);
				glBegin(GL_POLYGON);
					for (int i = 0; i < ov.size(); i++)
					{
						glVertex2d(ov.at(i).x, ov.at(i).y);
					}
				glEnd();
			}
		}
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glPopMatrix();
	}
#endif
#endif
}