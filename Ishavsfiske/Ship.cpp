//Version: 0.1.2
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_2
#error Ship.cpp: Wrong version 0.1.2
#endif

#include "Ship.h"

#include <Angler\DrawNode.h>
#include <Angler\Scale.h>
#include <Angler\CollisionNode.h>

#include <iostream>

using namespace Angler::Nodes;

Ishavsfiske::Ship::Ship(unsigned long id, Angler::Node *parent, sf::Texture *txShip, sf::Texture *txCrane, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id, parent), mTXShip(txShip), mTXCrane(txCrane), mOwner(owner), mVel(0, 0)
{
	mInit();
}

Ishavsfiske::Ship::Ship(unsigned long id, sf::Texture *txShip, sf::Texture *txCrane, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id), mTXShip(txShip), mTXCrane(txCrane), mOwner(owner), mVel(0, 0)
{
	mInit();
}

void Ishavsfiske::Ship::mInit()
{
	unsigned long id = getID();
	mTransl = new Translation(id + 0x0001, this, 0.5, 0.5);
	Scale *s = new Scale(id + 0x0002, mTransl, 1.75/10, 1.75/10);
	mRotation = new Rotation(id + 0x0003, s, 0);
	new DrawNode(id + 0x0004, mRotation, 1, mTXShip, 0.5, 0.5);	
	
	std::vector<sf::Vector2f> pts;
	pts.push_back(sf::Vector2f(-(2/3.5 * 0.5), -0.5));
	pts.push_back(sf::Vector2f(2/3.5 * 0.5, -0.5));
	pts.push_back(sf::Vector2f(2/3.5 * 0.5, 0.5));
	pts.push_back(sf::Vector2f(-(2/3.5 * 0.5), 0.5));
	mCol = new CollisionNode(id + 0x0005, mRotation, pts);

	mRotationA = new Rotation(id + 0x0006, mRotation, 0);
	Scale *s2 = new Scale(id + 0x0007, mRotationA, 1/3.5, 1/3.5);
	new DrawNode(id + 0x0008, s2, 2, mTXCrane, 0.25, 0.5);
}

void Ishavsfiske::Ship::move(float x, float y)
{	
	Scale *s = new Scale(0, 5, 5);
	Rotation r(0, s, mRotation->getRotation());
	sf::Vector2f tv = r.transform(sf::Vector2f(x, y));
	mTransl->translate(tv);
	delete s;
}

void Ishavsfiske::Ship::throttle(float vx, float vy)
{
	mVel.x += vx; mVel.y += vy;
}

void Ishavsfiske::Ship::update(Angler::Game *context, float time, float deltaTime)
{
	mLT = mTransl->getTranslation();
	mLR = mRotation->getRotation();

	move(mVel.x * deltaTime, mVel.y * deltaTime);

	mRotationA->setRotation(-90 + 45 * (2 - sin(time)));

	if (abs(mVel.x) > 0.001)
		mVel.x -= (mVel.x / abs(mVel.x)) * (400*mVel.x*mVel.x) * deltaTime;
	else
		mVel.x = 0;

	if (abs(mVel.y) > 0.001)
		mVel.y -= (mVel.y / abs(mVel.y)) * (400*mVel.y*mVel.y) * deltaTime;
	else
		mVel.y = 0;

	printf("{%06.6f, %06.6f}\n", mVel.x, mVel.y);
}

void Ishavsfiske::Ship::rotate(float r)
{
	mRotation->rotate(r);
}

Angler::Nodes::CollisionNode Ishavsfiske::Ship::getCol()
{
	return *mCol;
}

void Ishavsfiske::Ship::revert()
{
	mTransl->setTranslation(mLT);
	mRotation->setRotation(mLR);
}