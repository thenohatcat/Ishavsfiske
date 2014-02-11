//Version: 0.1.3
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_3
#error IceBreaker.cpp: Wrong version 0.1.3
#endif

#include "IceBreaker.h"

#include <Angler\DrawNode.h>
#include <Angler\Scale.h>

using namespace Ishavsfiske;

IceBreaker::IceBreaker(unsigned long id, Angler::Node *parent,
			sf::Texture *textureShip, Ishavsfiske::IshavsfiskeGame *owner)
			: Ship(id, parent, owner), mTextureShip(textureShip)
{
	mInit();
}

IceBreaker::IceBreaker(unsigned long id, sf::Texture *textureShip, 
			Ishavsfiske::IshavsfiskeGame *owner)
			: Ship(id, owner), mTextureShip(textureShip)
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
	new Angler::Nodes::DrawNode(getID() + 0x0101, s, 1, mTextureShip, 0.5, 0.5);

	std::vector<sf::Vector2f> pts;
	pts.push_back(sf::Vector2f(-(2/3.5 * 0.5), -0.5));
	pts.push_back(sf::Vector2f(2/3.5 * 0.5, -0.5));
	pts.push_back(sf::Vector2f(2/3.5 * 0.5, 0.5));
	pts.push_back(sf::Vector2f(-(2/3.5 * 0.5), 0.5));
	new Angler::Nodes::CollisionNode(getID() + 0x0102, s, pts);
}

void IceBreaker::update(Angler::Game *context, float time, float deltaTime)
{
	Ship::update(context, time, deltaTime);
}