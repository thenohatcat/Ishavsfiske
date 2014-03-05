//Version: 0.1.4
//Author: Marcus Persson
//Contributors: 

#ifndef ISHAV_0_1_4
#error School.cpp: Wrong version 0.1.4
#endif

#include <Angler\Scale.h>
#include <Angler\AnimatedNode.h>

#include "IshavsfiskeGame.h"
#include "School.h"
#include "IceBreaker.h"
#include "FishingBoat.h"

using namespace Ishavsfiske;
using namespace Angler::Nodes;

School::School(unsigned long id, Angler::Node *parent, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id, parent), mOwner(owner), mStartX(0.5f), mStartY(0.5f), mAmmount(10)
{
	mInit();
}

School::School(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id), mOwner(owner), mStartX(0.5f), mStartY(0.5f), mAmmount(10)
{
	mInit();
}

void School::mInit()
{
	mRootTranslation = new Translation(getID() + 0x2000, this, mStartX, mStartY);
	Angler::Nodes::Scale *s = new Angler::Nodes::Scale(getID() + 0x3000, mRootTranslation, 1/20.0f, 1/20.0f);
	mSchoolRoot = new Node(getID() + 0x0004, s);

	std::vector<sf::Vector2f> pts;
	pts.push_back(sf::Vector2f(1, 0));
	pts.push_back(sf::Vector2f(0, 0));
	pts.push_back(sf::Vector2f(0, 1));
	pts.push_back(sf::Vector2f(1 ,1));
	new Angler::Nodes::CollisionNode(getID() + 0x5000, mSchoolRoot, pts, 1);

	std::vector<sf::Vector2f> anim;
	anim.push_back(sf::Vector2f(0, 0));
	anim.push_back(sf::Vector2f(1/16.0f, 0));
	anim.push_back(sf::Vector2f(2/16.0f, 0));
	anim.push_back(sf::Vector2f(3/16.0f, 0));
	anim.push_back(sf::Vector2f(4/16.0f, 0));
	anim.push_back(sf::Vector2f(5/16.0f, 0));
	anim.push_back(sf::Vector2f(6/16.0f, 0));
	anim.push_back(sf::Vector2f(7/16.0f, 0));
	anim.push_back(sf::Vector2f(8/16.0f, 0));
	anim.push_back(sf::Vector2f(9/16.0f, 0));
	anim.push_back(sf::Vector2f(10/16.0f, 0));
	anim.push_back(sf::Vector2f(11/16.0f, 0));
	anim.push_back(sf::Vector2f(12/16.0f, 0));
	anim.push_back(sf::Vector2f(13/16.0f, 0));
	anim.push_back(sf::Vector2f(14/16.0f, 0));
	anim.push_back(sf::Vector2f(15/16.0f, 0));
	new Angler::Nodes::AnimatedNode(getID() + 0x1000, mSchoolRoot, 2, anim, 1/8.0f, 0, 0, 1/16.0f, 1);
}

void School::move(float x, float y)
{
	mRootTranslation->translate(sf::Vector2f(x, y));
}

sf::Vector2f School::getPosition()
{
	return mRootTranslation->getTranslation();
}

void School::setPosition(float x, float y)
{
	mRootTranslation->setTranslation(sf::Vector2f(x, y));
}

int School::getAmmount()
{
	return mAmmount;
}

int School::fish(int ammount)
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

void School::scaredByBoat(sf::Vector2f shipPos, float deltaTime)
{
	sf::Vector2f delta = getPosition();
	delta -= shipPos;

	move(delta.x/2*deltaTime, delta.y/2*deltaTime);
}

void School::update(Angler::Game *context, float time, float deltaTime, bool changed)
{
	mChanged |= changed;

	if(scaredDistance(((IshavsfiskeGame*)context)->getBreaker()->getPosition()))
		scaredByBoat(((IshavsfiskeGame*)context)->getBreaker()->getPosition(), deltaTime);
	if(scaredDistance(((IshavsfiskeGame*)context)->getFishing()->getPosition()))
		scaredByBoat(((IshavsfiskeGame*)context)->getFishing()->getPosition(), deltaTime);

	mUpdateChildren(context, time, deltaTime);
}

bool School::scaredDistance(sf::Vector2f pos)
{
	sf::Vector2f schoolPos = getPosition();
	float X0 = schoolPos.x;
	float Y0 = schoolPos.y;
	sf::Vector2f shipPos = pos;
	float X1 = shipPos.x;
	float Y1 = shipPos.y;
	float DX = X0 - X1;
	float DY = Y0 - Y1;
	return DX * DX + DY * DY < 0.03;
}