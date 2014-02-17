//Version: 0.1.3
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_3
#error IshavsfiskeGame_draw.cpp: Wrong version 0.1.3
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
		mGraphics->draw(3, sf::Vector2f(0, 0));

		// Status Left
		glPushMatrix();
			glScaled(15/40.0, 15/40.0, 1);
				glScaled(1/15.0, 1/15.0, 1);
					glTranslated(1, 25, 0);
				glScaled(15.0, 15.0, 1);
			mGraphics->draw(3, sf::Vector2f(0, 0));
		glPopMatrix();

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
				mGraphics->draw(3, sf::Vector2f(0, 0));
			}
		glPopMatrix();

		//Right UI
		glPushMatrix();
			glTranslated(14/10.0, 0, 0);
			glScaled(-1, 1, 1);
			mGraphics->draw(3, sf::Vector2f(1, 0));
		glPopMatrix();

		// Status Right
		glPushMatrix();
			glScaled(15/40.0, 15/40.0, 1);
				glScaled(1/15.0, 1/15.0, 1);
					glTranslated(14*4 + 1, 25, 0);
				glScaled(15.0, 15.0, 1);
			mGraphics->draw(3, sf::Vector2f(0, 0));
		glPopMatrix();

		//Fish Counter
		glPushMatrix();
			glScaled(1/20.0, 1/20.0, 1);
			glTranslated(6, 1/2.0, 0);
			mGraphics->draw(3, sf::Vector2f(0, 0));
		glPopMatrix();

		//Timer
		glPushMatrix();
			glScaled(1/20.0, 1/20.0, 1);
			glTranslated(14, 1/2.0, 0);
			mGraphics->draw(3, sf::Vector2f(0, 0));
		glPopMatrix();

		//Cash
		glPushMatrix();
			glScaled(1/20.0, 1/20.0, 1);
			glTranslated(22, 1/2.0, 0);
			mGraphics->draw(3, sf::Vector2f(0, 0));
		glPopMatrix();

		//Menu button
		glPushMatrix();
			glScaled(3/20.0, 3/20.0, 1);
			glScaled(1/3.0, 1/3.0, 1);
				glTranslated(4, 17, 0);
			glScaled(3, 3, 1);
			mGraphics->draw(3, sf::Vector2f(0, 0));
		glPopMatrix();

		//Wind Flag
		glPushMatrix();
			glScaled(1/10.0, 1/10.0, 1);
			glTranslated(13, 9, 0);
			mGraphics->draw(3, sf::Vector2f(0, 0));
		glPopMatrix();

		char *s = new char[32];
		sprintf_s(s, 32, "FPS: %03.0f", fps);
		mFont->drawString(mGraphics, "Ishavsfiske 0.1.3", 4, 1);
		glTranslatef(0, 1/40.0, 0);
		mFont->drawString(mGraphics, std::string(s), 4, 1);
	glPopMatrix();
}

int tm;

void IshavsfiskeGame::mDraw(float time, float deltaTime)
{
	mGraphics->begin();

	//Draw UI
	mDrawUI(time, deltaTime);

	//Draw Map

	//Draw SceneRoot
	mSceneRoot->draw(this, mGraphics, time, deltaTime);
	mGraphics->end();

#ifdef _DEBUG
	tm++;
	if ((tm % 4) == 0)
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
				/*Angler::Nodes::Transformation::transform(n, n->getPoints(), &ov);*/

				sf::Vector2f ul = n->getBoundingUL(), lr = n->getBoundingLR();

				/*Angler::HelpFunctions::Geometry::getBoundingPoints(&ov, &ul, &lr);*/

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
}