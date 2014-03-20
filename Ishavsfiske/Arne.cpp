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
	: Animal(id, parent, owner), mVel(0, 0)
{
	mInit();
}

Arne::Arne(unsigned long id, Angler::Game *owner)
	: Animal(id, owner)
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

		if (!mAtShip()/* && !mScared*/)
		{
			if(!mLookAtShip())
			{
				if (abs(mVel.y) > 0.001f)
					mVel.y -= (mVel.y / abs(mVel.y)) * (400*mVel.y*mVel.y) * deltaTime;
				else
					mVel.y = 0;
				rotate(180 * deltaTime);
			}
			if(mVel.y < 0.05f)
				throttle(0, 0.001f);
			if(mVel.y > 0)
				move(0, mVel.y * deltaTime);

		}
		mUpdateChildren(context, time, deltaTime);
	}
}

void Arne::attack()
{

}

void Arne::mInit()
{
	mStartX = 0.5f;
	mStartY = 0.5f;

	Animal::mInit();

	// Arne ID?
	Angler::Nodes::Scale *s = new Angler::Nodes::Scale(getID() + 0x0120, mAnimalRoot, 1/10.0f, 1/10.0f);

	/*std::vector<sf::Vector2f> pts;
	pts.push_back(sf::Vector2f(1, 0));
	pts.push_back(sf::Vector2f(0, 0));
	pts.push_back(sf::Vector2f(0, 1));
	pts.push_back(sf::Vector2f(1, 1));
	new Angler::Nodes::CollisionNode(getID(), s, pts, 0);*/


	std::vector<sf::Vector2f> anime;
	anime.push_back(sf::Vector2f(0, 0));
	anime.push_back(sf::Vector2f(1/5.0f, 0));
	anime.push_back(sf::Vector2f(2/5.0f, 0));
	anime.push_back(sf::Vector2f(3/5.0f, 0));
	anime.push_back(sf::Vector2f(4/5.0f, 0));
	new Angler::Nodes::AnimatedNode(getID() + 0x123, s, 9, anime, 1/5.0f, 0.5f, 0.5f, 1/5.0f, 1); // ID?
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

	cout << mRotToShip << " " << rotation << endl;

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