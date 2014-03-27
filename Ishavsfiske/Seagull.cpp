//Version: 0.1.5
//Author: Sihao Li
//Contributors:

#ifndef ISHAV_0_1_5
#error Seagull.cpp: Wrong version 0.1.5
#endif

#define PI 3.14159265f

#include "IshavsfiskeGame.h"
#include "Seagull.h"

#include <Angler\DrawNode.h>
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
	: Animal(id, parent, owner)
{
	mInit();
}

Seagull::Seagull(unsigned long id, Angler::Game *owner)
	: Animal(id, owner)
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

		if (!mAtShip()/* && !mScared*/)
		{
			if(!mLookAtShip())
			{
				/*if(mRootRotation->getRotation() > mRotToShip)
					rotate(-180 * deltaTime);
				else*/
					rotate(180 * deltaTime);
			}
			move(0, -0.03f * deltaTime);
		}
		mUpdateChildren(context, time, deltaTime);
	}
}

void Seagull::attack()
{

}

void Seagull::mInit()
{
	mStartX = 0.5f;
	mStartY = 0.5f;

	Animal::mInit();

	// Seagull ID?
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

	return ((mRotToShip - 3) < rotation) &&  (rotation < (mRotToShip + 3));
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

void Seagull::mSetSpeed(float vx, float vy)
{
	mVel.x = vx;
	mVel.y = vy;
}

int Seagull::mDirection(sf::Vector2f position)
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

void Seagull::collide()
{

}
