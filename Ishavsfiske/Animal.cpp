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
#include "IceBreaker.h"

#include <Angler\DrawNode.h>
#include <Angler\Scale.h>
#include <iostream>

using namespace std;

using namespace Ishavsfiske;
using namespace Angler::Nodes;

#define PI 3.14159265

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

// Ska jag ha detta i seagull update ist�llet?
void Animal::update(Angler::Game *context, float time, float deltaTime, bool changed)
{
	if(!mPaused)
	{
		mChanged |= changed;

		mFishPos = ((IshavsfiskeGame*) context)->getShipFishing()->getPosition();

		mShipFishDis.x = mFishPos.x - mRootTranslation->getTranslationX();
		mShipFishDis.y = mFishPos.y - mRootTranslation->getTranslationY();

		mIceBPos = ((IshavsfiskeGame*) context)->getIceBreaker()->getPosition();
		mShipIceBDis = mIceBPos - mRootTranslation->getTranslation();

		if (!mAtShip()/* && !mScared*/)
		{
			if(!mLookAtShip())
			{
				/*cout << "rotate\n";
				float LoR = mRootRotation->getRotation() - mRotToShip;
				if(LoR < 0)
					rotate(90 * deltaTime);
				else*/
					rotate(180 * deltaTime);
			}
			move(0, -0.03 * deltaTime);
		}
		mUpdateChildren(context, time, deltaTime);
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

bool Animal::mAtShip()
{
	return mRootTranslation->getTranslation() == mFishPos;
}

bool Animal::mLookAtShip()
{
	float dx = mFishPos.x - mRootTranslation->getTranslationX();
	float dy = mFishPos.y - mRootTranslation->getTranslationY();
	/*float dis = sqrt(dx * dx + dy * dy);*/

	float angle = atan(dy / dx) * (180 / PI);
	float mRotToShip = mCalcRotation(angle);

	float rotation = abs(fmod(mRootRotation->getRotation(), 360.0f));

	cout << mRotToShip << " " << rotation << endl;

	return ((mRotToShip - 3) < rotation) &&  (rotation < (mRotToShip + 3));
}

float Animal::mCalcRotation(float angle)
{
	switch(mDirection(mFishPos))
	{
	case 9:
		return angle + 90;
		break;
	case 3:
		return angle + 90;
		break;
	case 1:
		return angle + 270;
		break;
	case 7:
		return angle + 270;
		break;
	}
}

void Animal::mSetSpeed(float vx, float vy)
{
	mVel.x = vx;
	mVel.y = vy;
}

int Animal::mDirection(sf::Vector2f position)
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

void Animal::collide()
{

}
