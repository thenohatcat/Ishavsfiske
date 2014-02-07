//Version: 0.1.2
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_2
#error IshavsfiskeGame_update.cpp: Wrong version 0.1.2
#endif

#include "IshavsfiskeGame.h"
#include "Ship.h"

#include "MechanicsEngine.h"

#include <Angler\CollisionNode.h>

#include <glm\matrix.hpp>

#include <Angler\HelpFunctions.h>

#include <iostream>

float av;
unsigned int frm;

void Ishavsfiske::IshavsfiskeGame::mUpdate(float time, float deltaTime)
{
#ifdef _DEBUG
	if (frm < 10)
	{
		frm++;
		av += deltaTime;
	}
	else
	{
		printf("FPS: %04.0f\n", frm/av);
		frm = 0;
		av = 0;
	}
	//printf("FPS: %04.0f\n", 1/deltaTime);
#endif

	mSceneRoot->update(this, time, deltaTime);

	//Handle Input
	mInput(time, deltaTime);

	//Collision system collide
	mMechanics->doCollide(mSceneRoot);

	std::vector<sf::Vector2f> shipCol;
	std::vector<Angler::Node*> shp = Angler::HelpFunctions::getDescendants(mShip);
	Angler::Nodes::CollisionNode *nd = nullptr;
	for (int i = 0; i < shp.size(); i++)
	{
		if (typeid(*(shp.at(i))) == typeid(Angler::Nodes::CollisionNode))
		{
			nd = (Angler::Nodes::CollisionNode*)shp.at(i);
			break;
		}
	}

	Angler::Nodes::Transformation::transform(nd, nd->getPoints(), &shipCol);

	//Leaving the frame
	for (int i = 0; i < shipCol.size(); i++)
	{
		if (!Angler::HelpFunctions::Geometry::pointIsWithinPolygon(mFrame, shipCol.at(i)))
		{
#ifdef _DEBUG
			std::cout << "Ship is outside" << std::endl;
#endif
			mShip->revert();
			break;
		}
	}
}