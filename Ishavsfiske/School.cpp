//Version: 0.1.4
//Author: Marcus Persson
//Contributors: 

#ifndef ISHAV_0_1_4
#error Ship.cpp: Wrong version 0.1.4
#endif

#include "IshavsfiskeGame.h"
#include "School.h"

using namespace Angler::Nodes;

Ishavsfiske::School::School(unsigned long id, Angler::Node *parent, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id, parent), mOwner(owner), mStartX(0.5f), mStartY(0.5f), mAmmount(10)
{

}

Ishavsfiske::School::School(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id), mOwner(owner), mStartX(0.5f), mStartY(0.5f), mAmmount(10)
{

}

void Ishavsfiske::School::mInit()
{
	mRootTranslation = new Translation(getID() + 0x2000, this, mStartX, mStartY);
	mSchoolRoot = new Node(getID() + 0x0004, mRootTranslation);

	std::vector<sf::Vector2f> pts;
	pts.push_back(sf::Vector2f(1, 0));
	pts.push_back(sf::Vector2f(0, 0));
	pts.push_back(sf::Vector2f(0, 1));
	pts.push_back(sf::Vector2f(1 ,1));

	new Angler::Nodes::CollisionNode(getID() + 0x5000, this, pts, 0);
}

void Ishavsfiske::School::move(float x, float y)
{
	mRootTranslation->translate(sf::Vector2f(5*x, 5*y));
}

sf::Vector2f Ishavsfiske::School::getPosition()
{
	return mRootTranslation->getTranslation();
}

void Ishavsfiske::School::setPosition(float x, float y)
{
	mRootTranslation->setTranslation(sf::Vector2f(x, y));
}

int Ishavsfiske::School::fish(int ammount)
{
	if(ammount <= mAmmount)
	{
		mAmmount -= ammount;
		return ammount;
	}
	else
	{
		ammount = mAmmount;
		mAmmount = 0;
		return ammount;
	}
}

void Ishavsfiske::School::update(Angler::Game *context, float time, float deltaTime, bool changed)
{
	mChanged |= changed;

	mUpdateChildren(context, time, deltaTime);
}