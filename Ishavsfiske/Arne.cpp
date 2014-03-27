//Version: 0.1.5
//Author: Sihao Li
//Contributors:

#ifndef ISHAV_0_1_5
#error Arne.cpp: Wrong version 0.1.5
#endif

#define PI 3.14159265

#include "IshavsfiskeGame.h"
#include "Arne.h"

#include <Angler\AnimatedNode.h>
#include <Angler\Scale.h>
#include <Angler\Translation.h>
#include <Angler\Rotation.h>
#include <Angler\CollisionNode.h>

#include <iostream>

using namespace std;
using namespace Ishavsfiske;
using namespace Angler::Nodes;

Arne::Arne(unsigned long id, Angler::Node *parent, Angler::Game *owner)
	: Animal(id, parent, owner), mVel(0, -0.05), mTimeDiff(0), mScared(false)/*, mAttack(false), mAttacked(false), mSwim(false)*/
{
	mInit();
}

Arne::Arne(unsigned long id, Angler::Game *owner)
	: Animal(id, owner), mVel(0, -0.05), mTimeDiff(0), mScared(false)/*, mAttack(false), mAttacked(false), mSwim(false)*/
{
	mInit();
}

Arne::~Arne()
{
	Animal::~Animal();
}

void Arne::update(Angler::Game* context, float time, float deltaTime, bool changed)
{
	if(!mPaused)
	{
		mChanged |= changed;

		mIceBPos = ((IshavsfiskeGame*) context)->getIceBreaker()->getPosition();

		mShipIceBDis = mIceBPos - mRootTranslation->getTranslation();

		/*if (mTimeDiff > 0.005f && !mBlocked)
		{
			mOldRotations.push_back(mRootRotation->getRotation());
			mOldTranslations.push_back(mRootTranslation->getTranslation());

			if (mOldRotations.size() > 128)
			{
				mOldRotations.erase(mOldRotations.begin());
				mOldTranslations.erase(mOldTranslations.begin());
			}

			mTimeDiff = 0;
		}*/

		if (!mIsClose() && !mScared)
		{
			if(!mLookAtShip())
			{
				rotate(180 * deltaTime);
			}
			/*cout << abs(mVel.y) << endl;*/
			move(0, mVel.y * deltaTime);
			/*mAttack = false;
			mAttacked = false;
			if(mSwim)
			{
				mInit();
				mSwim = false;
			}*/
		}
		mUpdateChildren(context, time, deltaTime);

		mTimeDiff += deltaTime;

		mBlocked = false;
	}
}

void Arne::attack()
{
	/*mAttack = true;
	if(!mAttacked)
	{
		mInit();
		setPosition(mIceBPos.x, mIceBPos.y);
		mAttacked = true;
		mSwim = true;
	}*/

	mAniAttack->show(true);
	mAniSwim->show(false);
}

void Arne::mInit()
{
	mStartX = 0.8f;
	mStartY = 0.5f;

	Animal::mInit();

	// Arne ID?
	Angler::Nodes::Scale *s = new Angler::Nodes::Scale(getID() + 0x0120, mAnimalRoot, 1/10.0f, 1/10.0f);

	std::vector<sf::Vector2f> pts;
	pts.push_back(sf::Vector2f(1, 0));
	pts.push_back(sf::Vector2f(0, 0));
	pts.push_back(sf::Vector2f(0, 70/200.0f));
	pts.push_back(sf::Vector2f(1, 70/200.0f));
	new Angler::Nodes::CollisionNode(getID() + 0x3000, s, pts, 0);

	std::vector<sf::Vector2f> anime;
	anime.push_back(sf::Vector2f(0, 4/13.0f));
	anime.push_back(sf::Vector2f(1/8.0f, 4/13.0f));
	anime.push_back(sf::Vector2f(2/8.0f, 4/13.0f));
	anime.push_back(sf::Vector2f(3/8.0f, 4/13.0f));
	anime.push_back(sf::Vector2f(4/8.0f, 4/13.0f));
	anime.push_back(sf::Vector2f(5/8.0f, 4/13.0f));
	anime.push_back(sf::Vector2f(6/8.0f, 4/13.0f));
	anime.push_back(sf::Vector2f(7/8.0f, 4/13.0f));
	mAniSwim = new Angler::Nodes::AnimatedNode(getID() + 0x678, s, 12, anime, 1/8.0f, 0.5f, 0.5f, 1/8.0f, 6/13.0f); // ID?


	std::vector<sf::Vector2f> pts1;
	pts.push_back(sf::Vector2f(1, 0));
	pts.push_back(sf::Vector2f(0, 0));
	pts.push_back(sf::Vector2f(0, 1));
	pts.push_back(sf::Vector2f(1, 1));
	new Angler::Nodes::CollisionNode(getID() + 0x3000, s, pts1, 0);

	std::vector<sf::Vector2f> anime1;
	anime.push_back(sf::Vector2f(0, 500/650.0f));
	anime.push_back(sf::Vector2f(75/1200.0f, 500/650.0f));
	anime.push_back(sf::Vector2f(150/1200.0f, 500/650.0f));
	anime.push_back(sf::Vector2f(225/1200.0f, 500/650.0f));
	mAniAttack = new Angler::Nodes::AnimatedNode(getID() + 0x678, s, 12, anime1, 1/4.0f, 0.5f, 0.5f, 75/1200.0f, 125/650.0f); // ID?
	mAniAttack->show(false);
}

bool Arne::mAtShip()
{
	return mRootTranslation->getTranslation() == mIceBPos;
}

bool Arne::mLookAtShip()
{
	float angle = atan(mShipIceBDis.y / mShipIceBDis.x) * (180 / PI);
	float mRotToShip = mCalcRotation(angle);

	float rotation = abs(fmod(mRootRotation->getRotation(), 360.0f));

	/*cout << mRotToShip << " " << rotation << endl;*/

	return ((mRotToShip - 3) < rotation) &&  (rotation < (mRotToShip + 3));
}

float Arne::mCalcRotation(float angle)
{
	switch(mDirection(mIceBPos))
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

void Arne::collide()
{
	
}

void Arne::throttle(float vx, float vy)
{
	mVel.x += vx;
	mVel.y += vy;
}

//void Arne::revert()
//{
//	if(!mBlocked)
//	{
//		mRootRotation->setRotation(mOldRotations.back());
//		mRootTranslation->setTranslation(mOldTranslations.back());
//
//		mOldRotations.pop_back();
//		mOldTranslations.pop_back();
//
//		mVel.x = mVel.y = 0;
//		mChanged = true;
//	}
//}

sf::Vector2f Arne::getVel()
{
	return mVel;
}

void Arne::block()
{
	mOldRotations.push_back(mRootRotation->getRotation());
	mOldTranslations.push_back(mRootTranslation->getTranslation());

	if (mOldRotations.size() > 128)
	{
		mOldRotations.erase(mOldRotations.begin());
		mOldTranslations.erase(mOldTranslations.begin());
	}

	mBlocked = true;
	mVel = sf::Vector2f(0, 0);
}

void Arne::setPosition(float x, float y)
{
	mRootTranslation->setTranslation(x, y);
}

bool Arne::mIsClose()
{
	float dis = sqrt((mShipIceBDis.x * mShipIceBDis.x) + (mShipIceBDis.y * mShipIceBDis.y));
	return abs(dis) < 0.05f;
}