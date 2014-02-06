//Version: 0.1.2
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_2
#error IshavsfiskeGame_update.cpp: Wrong version 0.1.2
#endif

#include "IshavsfiskeGame.h"
#include "Ship.h"

#include <Angler\CollisionNode.h>

#include <glm\matrix.hpp>

#include <Angler\HelpFunctions.h>

#include <iostream>

void Ishavsfiske::IshavsfiskeGame::mUpdate(float time, float deltaTime)
{
	mSceneRoot->update(this, time, deltaTime);

	//Handle Input
	mInput(time, deltaTime);

	if (getKeyboardState().isKeyDown(sf::Keyboard::Up))
	{
		mShip->throttle(0, -0.1 * deltaTime);
	}
	else if (getKeyboardState().isKeyDown(sf::Keyboard::Down))
	{
		mShip->throttle(0, 0.1 * deltaTime);
	}

	//Collision system collide


	//
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
			std::cout << "Ship is outside" << std::endl;
			mShip->revert();
			break;
		}
	}
}