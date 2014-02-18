//Version: 0.1.4
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_4
#error IceBreaker.cpp: Wrong version 0.1.4
#endif

#include "IceBreaker.h"

#include <Angler\DrawNode.h>
#include <Angler\SpriteNode.h>
#include <Angler\Scale.h>

using namespace Ishavsfiske;

IceBreaker::IceBreaker(unsigned long id, Angler::Node *parent,
					   Ishavsfiske::IshavsfiskeGame *owner)
					   : Ship(id, parent, owner)
{
	mInit();
}

IceBreaker::IceBreaker(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner)
					   : Ship(id, owner)
{
	mInit();
}

void IceBreaker::mInit()
{
	mStartX = 0.7;
	mStartY = 0.5;

	Ship::mInit();

	Angler::Nodes::Scale *s = new Angler::Nodes::Scale(getID() + 0x0100,
		mShipRoot, 3.5/20, 3.5/20);
	new Angler::Nodes::DrawNode(getID() + 0x0101, s, 1, 0.5, 0.5);

	std::vector<sf::Vector2f> pts;
	pts.push_back(sf::Vector2f(2/3.5*(-0.5 + (49.5 / 100.0)), -0.5 + (-1 / 175.0)));
	pts.push_back(sf::Vector2f(2/3.5*(-0.5 + (41 / 100.0)), -0.5 + (2 / 175.0)));
	pts.push_back(sf::Vector2f(2/3.5*(-0.5 + (33 / 100.0)), -0.5 + (10 / 175.0)));
	pts.push_back(sf::Vector2f(2/3.5*(-0.5 + (27 / 100.0)), -0.5 + (22 / 175.0)));
	pts.push_back(sf::Vector2f(2/3.5*(-0.5 + (23 / 100.0)), -0.5 + (41 / 175.0)));
	pts.push_back(sf::Vector2f(2/3.5*(-0.5 + (23 / 100.0)), -0.5 + (121 / 175.0)));
	pts.push_back(sf::Vector2f(2/3.5*(-0.5 + (30 / 100.0)), -0.5 + (147 / 175.0)));
	pts.push_back(sf::Vector2f(2/3.5*(-0.5 + (40 / 100.0)), -0.5 + (167 / 175.0)));

	pts.push_back(sf::Vector2f(2/3.5*(-0.5 + (49.5 / 100.0)), -0.5 + (176 / 175.0)));
	pts.push_back(sf::Vector2f(2/3.5*(-0.5 + (59 / 100.0)), -0.5 + (167 / 175.0)));
	pts.push_back(sf::Vector2f(2/3.5*(-0.5 + (69 / 100.0)), -0.5 + (147 / 175.0)));
	pts.push_back(sf::Vector2f(2/3.5*(-0.5 + (76 / 100.0)), -0.5 + (121 / 175.0)));
	pts.push_back(sf::Vector2f(2/3.5*(-0.5 + (76 / 100.0)), -0.5 + (41 / 175.0)));
	pts.push_back(sf::Vector2f(2/3.5*(-0.5 + (72 / 100.0)), -0.5 + (22 / 175.0)));
	pts.push_back(sf::Vector2f(2/3.5*(-0.5 + (66 / 100.0)), -0.5 + (10 / 175.0)));
	pts.push_back(sf::Vector2f(2/3.5*(-0.5 + (58 / 100.0)), -0.5 + (2 / 175.0)));

	new Angler::Nodes::CollisionNode(getID() + 0x0102, s, pts, 0);
}

void IceBreaker::update(Angler::Game *context, float time, float deltaTime, bool changed)
{
	Ship::update(context, time, deltaTime, changed);
}