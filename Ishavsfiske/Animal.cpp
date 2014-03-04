//Version: 0.1.4
//Author: Sihao Li
//Contributors:

#ifndef ISHAV_0_1_4
#error Animal.cpp: Wrong version 0.1.4
#endif

#include "IshavsfiskeGame.h"
#include "Animal.h"
#include "Ship.h"

#include <Angler\DrawNode.h>
#include <Angler\Scale.h>

using namespace Ishavsfiske;
using namespace Angler::Nodes;

Animal::Animal(unsigned long id, Angler::Node *parent, Angler::Game *owner)
	: Node(id, parent), mOwner(owner), mStartX(0), mStartY(0)
{
	
}

Animal::Animal(unsigned long id, Angler::Game *owner)
	: Node(id), mOwner(owner), mStartX(0), mStartY(0)
{
}

void Animal::mInit()
{
	unsigned id = getID();

	mRootTranslation = new Translation(id + 0x0001, this, mStartX, mStartY);
	mRootRotation = new Rotation(id + 0x0003, mRootTranslation, 0);
	mAnimalRoot = new Node(id + 0x0004, mRootRotation);

	/*mBearSprite = new SpriteNode(getID() + 0x1000, this, 1, sf::Vector2f(0, 0), sf::Vector2f(0, 0.25), sf::Vector2f(0.25, 0.25));*/
}

void Animal::update(Angler::Game *context, float time, float deltaTime, bool changed)
{
	mChanged |= changed;
	
	mOT = mLT;
	mOR = mLR;
	mLT = mRootTranslation->getTranslation();
	mLR = mRootRotation->getRotation();

	mFishPos = ((IshavsfiskeGame*) context)->getFishing()->getPosition();

	mDis.x = ((IshavsfiskeGame*) context)->getFishing()->getPosition().x - mRootTranslation->getTranslationX();
	mDis.y = ((IshavsfiskeGame*) context)->getFishing()->getPosition().y - mRootTranslation->getTranslationY();

	if (!atShip())
	{
		/*switch(direction(mFishPos))
		{
		case 9:
			setSpeed(0, -0.01);
			break;
		case 3:
			setSpeed(0, 0.01);
			break;
		case 1:
			setSpeed(-0.01, 0);
			break;
		case 7:
			setSpeed(0.01, 0);
			break;
		}*/
		switch(direction(mFishPos))
		{
		case 9:
			move(mDis.x * deltaTime, mDis.y * deltaTime);
			break;
		case 3:
			move(mDis.x * deltaTime, mDis.y * deltaTime);
			break;
		case 1:
			move(mDis.x * deltaTime, mDis.y * deltaTime);
			break;
		case 7:
			move(mDis.x * deltaTime, mDis.y * deltaTime);
			break;
		}
		/*move(mVel.x * deltaTime, mVel.y * deltaTime);*/
	}

	if (atShip())
	{
		mVel.x = 0;
		mVel.y = 0;
	}

	mUpdateChildren(context, time, deltaTime);
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
