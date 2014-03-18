//Version: 0.1.5
//Author: Sihao Li
//Contributors:

#ifndef ISHAV_0_1_5
#error Animal.cpp: Wrong version 0.1.5
#endif

#include "IshavsfiskeGame.h"
#include "Animal.h"
#include "Ship.h"
#include "FishingBoat.h"

#include <Angler\DrawNode.h>
#include <Angler\Scale.h>
#include <iostream>
using namespace Ishavsfiske;
using namespace Angler::Nodes;

Animal::Animal(unsigned long id, Angler::Node *parent, Angler::Game *owner)
	: Node(id, parent), mOwner(owner), mStartX(0.5), mStartY(0.5)
{
	
}

Animal::Animal(unsigned long id, Angler::Game *owner)
	: Node(id), mOwner(owner), mStartX(0), mStartY(0)
{
}

Animal::~Animal()
{
	delete mAnimalRoot;
	delete mRootRotation;
	delete mRootTranslation;

	Node::~Node();
}

void Animal::mInit()
{
	unsigned id = getID();

	mRootTranslation = new Translation(id + 0x0001, this, mStartX, mStartY);
	mRootRotation = new Rotation(id + 0x0003, mRootTranslation, 0);
	mAnimalRoot = new Node(id + 0x0004, mRootRotation);

	/*mBearSprite = new SpriteNode(getID() + 0x1000, this, 1, sf::Vector2f(0, 0), sf::Vector2f(0, 0.25), sf::Vector2f(0.25, 0.25));*/
}

// Ska jag ha detta i seagull update istället?
void Animal::update(Angler::Game *context, float time, float deltaTime, bool changed)
{
	mChanged |= changed;

	mFishPos = ((IshavsfiskeGame*) context)->getShipFishing()->getPosition();

	mDis.x = ((IshavsfiskeGame*) context)->getShipFishing()->getPosition().x - mRootTranslation->getTranslationX();
	mDis.y = ((IshavsfiskeGame*) context)->getShipFishing()->getPosition().y - mRootTranslation->getTranslationY();

	if (!atShip())
	{
		if(!lookAtShip())
		{
			float LoR = mRootRotation->getRotation() - mRotToShip;
			if(LoR < 0)
				rotate(90 * deltaTime);
			else
				rotate(-90 * deltaTime);
		}
		move(0, 1 * deltaTime);
	}
}

void Animal::attack()
{
}


void Animal::rotate(float r)
{
	mRootRotation->rotate(r);
}

void Animal::move(float x, float y)
{
	Rotation r(0, mRootRotation->getRotation());
	sf::Vector2f tv = r.transform(sf::Vector2f(5*x, 5*y));
	mRootTranslation->translate(tv);
}

bool Animal::atShip()
{
	return mRootTranslation->getTranslation() == mFishPos;
}

bool Animal::lookAtShip()
{
	float dx = mFishPos.x - mRootTranslation->getTranslationX();
	float dy = mFishPos.y - mRootTranslation->getTranslationY();
	/*float dis = sqrt(dx * dx + dy * dy);*/

	float angle = atan(dy / dx);
	float mRotToShip = calcRotation(angle);

	return (mRotToShip - 10) < mRootRotation->getRotation() < (mRotToShip + 10);
}

float Animal::calcRotation(float angle)
{
	switch(direction(mFishPos))
	{
	case 9:
		return angle;
		break;
	case 3:
		return angle + 90;
		break;
	case 1:
		return angle + 180;
		break;
	case 7:
		return angle + 270;
		break;
	}
}

void Animal::setSpeed(float vx, float vy)
{
	mVel.x = vx;
	mVel.y = vy;
}

int Animal::direction(sf::Vector2f position)
{
	sf::Vector2f dir = position - mRootTranslation->getTranslation();
	if(dir.x > 0 && dir.y < 0)
		return 9;
	if(dir.x > 0 && dir.y > 0)
		return 3;
	if(dir.x < 0 && dir.y > 0)
		return 1;
	if(dir.x < 0 && dir.y < 0)
		return 7;
}
