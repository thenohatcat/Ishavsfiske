//Version: 0.1.5
//Author: Sihao Li
//Contributors:

#ifndef ISHAV_0_1_5
#error PolarBear.cpp: Wrong version 0.1.5
#endif

#include "PolarBear.h"

#include <Angler\DrawNode.h>
#include <Angler\Scale.h>
#include <Angler\CollisionNode.h>

using namespace Ishavsfiske;

PolarBear::PolarBear(unsigned long id, Angler::Node *parent, Angler::Game *owner)
	: Animal(id, parent, owner)
{
	mInit();
}

PolarBear::PolarBear(unsigned long id, Angler::Game *owner)
	: Animal(id, owner)
{
	mInit();
}

void PolarBear::update(Angler::Game* context, float time, float deltaTime, bool changed)
{
	Animal::update(context, time, deltaTime, changed);
}

//void PolarBear::attack()
//{
//
//}
//
//void PolarBear::move(float x, float y)
//{
//	
//}

void PolarBear::mInit()
{
	mStartX = 0.5;
	mStartY = 0.2;

	Animal::mInit();

	Angler::Nodes::Scale *s = new Angler::Nodes::Scale(getID() + 0x0100, mAnimalRoot, 1.0f/20, 1.0f/20);
	new Angler::Nodes::DrawNode(getID() + 0x000000001, s, 7, 0.5, 0.5);

	/*std::vector<sf::Vector2f> pts;
	pts.push_back(sf::Vector2f(1, 0));
	pts.push_back(sf::Vector2f(0, 0));
	pts.push_back(sf::Vector2f(0, 1));
	pts.push_back(sf::Vector2f(1, 1));
	new Angler::Nodes::CollisionNode(getID(), s, pts, 0);*/
}