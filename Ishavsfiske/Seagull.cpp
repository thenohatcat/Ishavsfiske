//Version: 0.1.5
//Author: Sihao Li
//Contributors:

#ifndef ISHAV_0_1_5
#error Seagull.cpp: Wrong version 0.1.5
#endif

#define PI 3.14159265

#include "IshavsfiskeGame.h"
#include "Seagull.h"

#include <Angler\AnimatedNode.h>
#include <Angler\Scale.h>
#include <Angler\Translation.h>
#include <Angler\Rotation.h>
#include <Angler\CollisionNode.h>

#include <iostream>

using namespace std;
using namespace Ishavsfiske;
using namespace Angler::Nodes;

Seagull::Seagull(unsigned long id, Angler::Node *parent, Angler::Game *owner)
	: Animal(id, parent, owner), mVel(0, 0.03f), mScared(false), recoverTime(0)
{
	mInit();
}

Seagull::Seagull(unsigned long id, Angler::Game *owner)
	: Animal(id, owner), mVel(0, 0.03f), mScared(false), recoverTime(0)
{
	mInit();
}

Seagull::~Seagull()
{
	Animal::~Animal();
}

void Seagull::update(Angler::Game* context, float time, float deltaTime, bool changed)
{
	if(!mPaused)
	{
		mChanged |= changed;

		mFishPos = ((IshavsfiskeGame*) context)->getShipFishing()->getPosition();

		mShipFishDis.x = mFishPos.x - mRootTranslation->getTranslationX();
		mShipFishDis.y = mFishPos.y - mRootTranslation->getTranslationY();

		if (mTimeDiff > 0.005f && !mBlocked)
		{
			mOldRotations.push_back(mRootRotation->getRotation());
			mOldTranslations.push_back(mRootTranslation->getTranslation());
			cout << "pushed\n";
			if (mOldRotations.size() > 128)
			{
				mOldRotations.erase(mOldRotations.begin());
				mOldTranslations.erase(mOldTranslations.begin());
			}

			mTimeDiff = 0;
		}

		if (!mAtShip() && !mScared)
		{
			if(!mLookAtShip())
			{
				rotate(180 * deltaTime);
			}
			move(0, -mVel.y * deltaTime);
		}

		if(mScared)
		{
			recoverTime += deltaTime;
			if(recoverTime < 5)
				move(0, -mVel.y * deltaTime);
			else
			{
				recoverTime = 0;
				mScared = false;
			}
		}
		mUpdateChildren(context, time, deltaTime);

		mTimeDiff += deltaTime;

		mBlocked = false;
	}
}

void Seagull::mInit()
{
	mStartX = 0.5f;
	mStartY = 0.5f;

	Animal::mInit();

	// Seagull ID?
	Angler::Nodes::Scale *s = new Angler::Nodes::Scale(getID() + 0x0120, mAnimalRoot, 1/10.0f, 1/10.0f);

	std::vector<sf::Vector2f> pts;
	pts.push_back(sf::Vector2f(1, 0));
	pts.push_back(sf::Vector2f(0, 0));
	pts.push_back(sf::Vector2f(0, 1));
	pts.push_back(sf::Vector2f(1, 1));
	new Angler::Nodes::CollisionNode(getID() + 0x2000, s, pts, 2);


	std::vector<sf::Vector2f> anime;
	anime.push_back(sf::Vector2f(0, 0));
	anime.push_back(sf::Vector2f(1/5.0f, 0));
	anime.push_back(sf::Vector2f(2/5.0f, 0));
	anime.push_back(sf::Vector2f(3/5.0f, 0));
	anime.push_back(sf::Vector2f(4/5.0f, 0));
	new Angler::Nodes::AnimatedNode(getID() + 0x123, s, 10, anime, 1/5.0f, 0.5f, 0.5f, 1/5.0f, 1); // ID?
}

bool Seagull::mAtShip()
{
	return mRootTranslation->getTranslation() == mFishPos;
}

bool Seagull::mLookAtShip()
{
	float angle = atan(mShipFishDis.y / mShipFishDis.x) * (180 / PI);
	float mRotToShip = mCalcRotation(angle);

	float rotation = abs(fmod(mRootRotation->getRotation(), 360.0f));

	//cout << mRotToShip << " " << rotation << endl;

	return ((mRotToShip - 10) < rotation) &&  (rotation < (mRotToShip + 10));
}

float Seagull::mCalcRotation(float angle)
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

void Seagull::collide()
{
	revert();
}

void Seagull::setPosition(float x, float y)
{
	mRootTranslation->setTranslation(x, y);
}

void Seagull::getPush()
{
	revert();
}

void Seagull::revert()
{
	if(!mBlocked)
	{
		mRootRotation->setRotation(mOldRotations.back());
		mRootTranslation->setTranslation(mOldTranslations.back());

		mOldRotations.pop_back();
		mOldTranslations.pop_back();

		mVel.x = mVel.y = 0;
		mChanged = true;
	}
}