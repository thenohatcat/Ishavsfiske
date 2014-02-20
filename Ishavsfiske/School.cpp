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
	: Node(id, parent), mOwner(owner), mStartX(0.5f), mStartY(0.5f)
{

}

Ishavsfiske::School::School(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id), mOwner(owner), mStartX(0.5f), mStartY(0.5f)
{

}

void Ishavsfiske::School::mInit()
{
	unsigned long id = getID();
	mRootTranslation = new Translation(id + 0x0001, this, mStartX, mStartY);
	mSchoolRoot = new Node(id + 0x0004, mRootTranslation);
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
	return ammount;
}