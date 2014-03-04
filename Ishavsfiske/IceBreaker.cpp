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

IceBreaker::~IceBreaker()
{
	Ship::~Ship();
}

void IceBreaker::mInit()
{
	mStartX = 0.8f;
	mStartY = 0.5f;

	Ship::mInit();

	Angler::Nodes::Scale *s = new Angler::Nodes::Scale(getID() + 0x3100,
		mShipRoot, 175/1000.0f, 175/1000.0f);
	//new Angler::Nodes::DrawNode(getID() + 0x0101, s, 1, 0.5f, 0.5f);
	new Angler::Nodes::SpriteNode(getID() + 0x1101, s, 3, sf::Vector2f(0.5f, 0.5f), sf::Vector2f(400/1500.0f, 350/1600.0f), sf::Vector2f(56/1500.0f, 175/1600.0f));

	std::vector<sf::Vector2f> pts;
	pts.push_back(sf::Vector2f(2/3.5f*(-0.5f + (49.5f / 100.0f)), -0.5f + (-1 / 175.0f)));
	pts.push_back(sf::Vector2f(2/3.5f*(-0.5f + (41 / 100.0f)), -0.5f+ (2 / 175.0f)));
	pts.push_back(sf::Vector2f(2/3.5f*(-0.5f + (33 / 100.0f)), -0.5f + (10 / 175.0f)));
	pts.push_back(sf::Vector2f(2/3.5f*(-0.5f + (27 / 100.0f)), -0.5f + (22 / 175.0f)));
	pts.push_back(sf::Vector2f(2/3.5f*(-0.5f + (23 / 100.0f)), -0.5f + (41 / 175.0f)));
	pts.push_back(sf::Vector2f(2/3.5f*(-0.5f + (23 / 100.0f)), -0.5f + (121 / 175.0f)));
	pts.push_back(sf::Vector2f(2/3.5f*(-0.5f + (30 / 100.0f)), -0.5f + (147 / 175.0f)));
	pts.push_back(sf::Vector2f(2/3.5f*(-0.5f + (40 / 100.0f)), -0.5f + (167 / 175.0f)));

	pts.push_back(sf::Vector2f(2/3.5f*(-0.5f + (49.5f / 100.0f)), -0.5f + (176 / 175.0f)));
	pts.push_back(sf::Vector2f(2/3.5f*(-0.5f + (59 / 100.0f)), -0.5f + (167 / 175.0f)));
	pts.push_back(sf::Vector2f(2/3.5f*(-0.5f + (69 / 100.0f)), -0.5f + (147 / 175.0f)));
	pts.push_back(sf::Vector2f(2/3.5f*(-0.5f + (76 / 100.0f)), -0.5f + (121 / 175.0f)));
	pts.push_back(sf::Vector2f(2/3.5f*(-0.5f + (76 / 100.0f)), -0.5f + (41 / 175.0f)));
	pts.push_back(sf::Vector2f(2/3.5f*(-0.5f + (72 / 100.0f)), -0.5f + (22 / 175.0f)));
	pts.push_back(sf::Vector2f(2/3.5f*(-0.5f + (66 / 100.0f)), -0.5f + (10 / 175.0f)));
	pts.push_back(sf::Vector2f(2/3.5f*(-0.5f + (58 / 100.0f)), -0.5f + (2 / 175.0f)));

	new Angler::Nodes::CollisionNode(getID() + 0x2102, s, pts, 0);
}

void IceBreaker::update(Angler::Game *context, float time, float deltaTime, bool changed)
{
	Ship::update(context, time, deltaTime, changed);
}