//Version: 0.1.4
//Author: Jakob Pipping
//Contributors: 

#ifndef ISHAV_0_1_4
#error Ship.cpp: Wrong version 0.1.4
#endif

#include "IshavsfiskeGame.h"
#include "Ship.h"

#include <Angler\DrawNode.h>
#include <Angler\SpriteNode.h>
#include <Angler\Scale.h>
#include <Angler\CollisionNode.h>

#include <iostream>

using namespace Ishavsfiske;
using namespace Angler::Nodes;

Ship::Ship(unsigned long id, Angler::Node *parent, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id, parent), mOwner(owner), mVel(0, 0), mStartX(0.5f), mStartY(0.5f), mTimeDiff(0)
{
	
}

Ship::Ship(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id), mOwner(owner), mVel(0, 0), mStartX(0.5f), mStartY(0.5f), mTimeDiff(0)
{
	
}

Ship::~Ship()
{
	delete mShipRoot;
	delete mRootRotation;
	delete mRootTranslation;

	Node::~Node();
}

void Ship::mInit()
{
	unsigned long id = getID();
	mRootTranslation = new Translation(id + 0x0001, this, mStartX, mStartY);
	mRootRotation = new Rotation(id + 0x0003, mRootTranslation, 0);
	mShipRoot = new Node(id + 0x0004, mRootRotation);
}

void Ship::move(float x, float y, bool global)
{	
	if (global)
	{
		mRootTranslation->translate(x, y);
		mChanged = true;
	}
	else
	{
		Rotation r(0, mRootRotation->getRotation());
		sf::Vector2f tv = r.transform(sf::Vector2f(5*x, 5*y));
		mRootTranslation->translate(tv);
		mChanged = true;
	}
}

void Ship::throttle(float vx, float vy)
{
	mVel.x += vx; mVel.y += vy;
}

void Ship::update(Angler::Game *context, float time, float deltaTime, bool changed)
{
	if (!mPaused)
	{
		mChanged |= changed;
	
		if (mTimeDiff > 0.005f)
		{
			mOldRotations.push_back(mRootRotation->getRotation());
			mOldTranslations.push_back(mRootTranslation->getTranslation());

			if (mOldRotations.size() > 128)
			{
				mOldRotations.erase(mOldRotations.begin());
				mOldTranslations.erase(mOldTranslations.begin());
			}

			mTimeDiff = 0;
		}

		if (abs(mVel.x) > 0 || abs(mVel.y) > 0)
			move(mVel.x * deltaTime, mVel.y * deltaTime);

		if (abs(mVel.x) > 0.001f)
			mVel.x -= (mVel.x / abs(mVel.x)) * (400*mVel.x*mVel.x) * deltaTime;
		else
			mVel.x = 0;

		if (abs(mVel.y) > 0.001f)
			mVel.y -= (mVel.y / abs(mVel.y)) * (400*mVel.y*mVel.y) * deltaTime;
		else
			mVel.y = 0;

		mUpdateChildren(context, time, deltaTime);

		mTimeDiff += deltaTime;
	}
}

void Ship::rotate(float r)
{
	mRootRotation->rotate(r);
	mChanged = true;
}

void Ship::revert()
{
	mRootRotation->setRotation(mOldRotations.back());
	mRootTranslation->setTranslation(mOldTranslations.back());
	mOldRotations.pop_back();
	mOldTranslations.pop_back();

	mVel.x = mVel.y = 0;
	mChanged = true;
}

sf::Vector2f Ship::getVelocity()
{
	return sf::Vector2f(mVel.x, mVel.y);
}

sf::Vector2f Ship::getGlobalVelocity()
{
	Rotation r(0, mRootRotation->getRotation());
	return r.transform(mVel);
}

sf::Vector2f Ship::getPosition()
{
	return mRootTranslation->getTranslation();
}

float Ship::getRotation()
{
	return mRootRotation->getRotation();
}