//Version: 0.1.5
//Author: Sihao Li
//Contributors:

#ifndef ISHAV_0_1_5
#error Seagull.cpp: Wrong version 0.1.5
#endif

#define PI 3.14159265f

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

		mShipFishDis = mFishPos - mRootTranslation->getTranslation();

		if (!mScared && !mIsClose())
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
		else if(mIsClose())
		{
			int r = rand() % 2;
			switch(r)
			{
			case 0:
				rotate(-180 * deltaTime);
				move(0, -mVel.y * deltaTime);
				break;
			case 1:
				rotate(180 * deltaTime);
				move(0, -mVel.y * deltaTime);
				break;
			}
		}

		mUpdateChildren(context, time, deltaTime);

		mBlocked = false;

		mDTime = deltaTime;
	}
}

void Seagull::mInit()
{
	Animal::mInit();

	// Seagull ID?
	Angler::Nodes::Scale *s = new Angler::Nodes::Scale(getID() + 0x0120, mAnimalRoot, 1/10.0f, 1/10.0f);

	/*std::vector<sf::Vector2f> pts;
	pts.push_back(sf::Vector2f(1/2.0f, 20/100.0f));
	pts.push_back(sf::Vector2f(40/100.0f, 35/100.0f));
	pts.push_back(sf::Vector2f(15/100.0f, 40/100.0f));
	pts.push_back(sf::Vector2f(45/100.0f, 50/100.0f));
	pts.push_back(sf::Vector2f(45/100.0f, 60/100.0f));
	pts.push_back(sf::Vector2f(60/100.0f, 60/100.0f));
	pts.push_back(sf::Vector2f(60/100.0f, 50/100.0f));
	pts.push_back(sf::Vector2f(85/100.0f, 40/100.0f));
	pts.push_back(sf::Vector2f(60/100.0f, 35/100.0f));
	new Angler::Nodes::CollisionNode(getID() + 0x2000, s, pts, 2);*/


	std::vector<sf::Vector2f> anime;
	anime.push_back(sf::Vector2f(0, 0));
	anime.push_back(sf::Vector2f(1/5.0f, 0));
	anime.push_back(sf::Vector2f(2/5.0f, 0));
	anime.push_back(sf::Vector2f(3/5.0f, 0));
	anime.push_back(sf::Vector2f(4/5.0f, 0));
	new Angler::Nodes::AnimatedNode(getID() + 0x123, s, 10, anime, 1/5.0f, 0.5f, 0.5f, 1/5.0f, 1); // ID?
}

//bool Seagull::mAtShip()
//{
//	return mRootTranslation->getTranslation() == mFishPos;
//}

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
	
}

void Seagull::setPosition(float x, float y)
{
	mRootTranslation->setTranslation(x, y);
}

void Seagull::getPush()
{
	
}

bool Seagull::mIsClose()
{
	float dis = sqrt((mShipFishDis.x * mShipFishDis.x) + (mShipFishDis.y * mShipFishDis.y));
	/*cout << dis << endl;*/
	return abs(dis) < 0.05f;
}
