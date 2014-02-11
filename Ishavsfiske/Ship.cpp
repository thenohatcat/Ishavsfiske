//Version: 0.1.3
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_3
#error Ship.cpp: Wrong version 0.1.3
#endif

#include "IshavsfiskeGame.h"
#include "Ship.h"

#include <Angler\DrawNode.h>
#include <Angler\SpriteNode.h>
#include <Angler\Scale.h>
#include <Angler\CollisionNode.h>

#include <iostream>

using namespace Angler::Nodes;

Ishavsfiske::Ship::Ship(unsigned long id, Angler::Node *parent, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id, parent), mOwner(owner), mVel(0, 0), mStartX(0.5), mStartY(0.5)
{
	
}

Ishavsfiske::Ship::Ship(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id), mOwner(owner), mVel(0, 0), mStartX(0.5), mStartY(0.5)
{
	
}

void Ishavsfiske::Ship::mInit()
{
	unsigned long id = getID();
	mRootTranslation = new Translation(id + 0x0001, this, mStartX, mStartY);
	mRootRotation = new Rotation(id + 0x0003, mRootTranslation, 0);
	mShipRoot = new Node(id + 0x0004, mRootRotation);
}

void Ishavsfiske::Ship::move(float x, float y)
{	
	Scale *s = new Scale(0, 5, 5);
	Rotation r(0, s, mRootRotation->getRotation());
	sf::Vector2f tv = r.transform(sf::Vector2f(x, y));
	mRootTranslation->translate(tv);
	delete s;
}

void Ishavsfiske::Ship::throttle(float vx, float vy)
{
	mVel.x += vx; mVel.y += vy;
}

void Ishavsfiske::Ship::update(Angler::Game *context, float time, float deltaTime)
{
	mLT = mRootTranslation->getTranslation();
	mLR = mRootRotation->getRotation();

	if (abs(mVel.x) > 0 || abs(mVel.y) > 0)
		move(mVel.x * deltaTime, mVel.y * deltaTime);

	if (abs(mVel.x) > 0.001)
		mVel.x -= (mVel.x / abs(mVel.x)) * (400*mVel.x*mVel.x) * deltaTime;
	else
		mVel.x = 0;

	if (abs(mVel.y) > 0.001)
		mVel.y -= (mVel.y / abs(mVel.y)) * (400*mVel.y*mVel.y) * deltaTime;
	else
		mVel.y = 0;
}

void Ishavsfiske::Ship::rotate(float r)
{
	mRootRotation->rotate(r);
}

void Ishavsfiske::Ship::revert()
{
	mRootTranslation->setTranslation(mLT);
	mRootRotation->setRotation(mLR);
	mVel.x = mVel.y = 0;
}