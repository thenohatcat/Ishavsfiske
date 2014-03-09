//Version: 0.1.4
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_4
#error IshavsfiskeGame_draw.cpp: Wrong version 0.1.4
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
		std::vector<Angler::Node*> nds = std::vector<Angler::Node*>(Angler::HelpFunctions::Nodes::getDescendants(mSceneRoot));
		glPushMatrix();
		for (int i = 0; i < nds.size(); i++)
		{
			if (typeid(*nds.at(i)) == typeid(Angler::Nodes::CollisionNode))
			{
				Angler::Nodes::CollisionNode* n = (Angler::Nodes::CollisionNode*)nds.at(i);

				std::vector<sf::Vector2f> ov = n->getTransformedPoints();

				sf::Vector2f ul = n->getBoundingUL(), lr = n->getBoundingLR();

				if (lr == ul)
					break;

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