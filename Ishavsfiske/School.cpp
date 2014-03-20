//Version: 0.1.5
//Author: Marcus Persson
//Contributors: 

#ifndef ISHAV_0_1_5
#error School.cpp: Wrong version 0.1.5
#endif

#include <Angler\Scale.h>
#include <Angler\AnimatedNode.h>

#include "IshavsfiskeGame.h"
#include "School.h"

using namespace Ishavsfiske;
using namespace Angler::Nodes;

School::School(unsigned long id, Angler::Node *parent, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id, parent), mOwner(owner), mStartX(0.5f), mStartY(0.5f), mAmmount(8)
{
	mInit();
}

School::School(unsigned long id, Ishavsfiske::IshavsfiskeGame *owner)
	: Node(id), mOwner(owner), mStartX(0.5f), mStartY(0.5f), mAmmount(8)
{
	mInit();
}

School::~School()
{
	//delete mSchoolRoot;
	//delete mRootTranslation;

	Node::~Node();
}

int School::getType()
{
	return mType;
}

void School::mInit()
{
	mRootTranslation = new Translation(getID() + 0x2000, this, mStartX, mStartY);
	Angler::Nodes::Scale *s = new Angler::Nodes::Scale(getID() + 0x3000, mRootTranslation, 1/20.0f, 1/20.0f);
	mSchoolRoot = new Node(getID() + 0x0004, s);

	std::vector<sf::Vector2f> pts;
	pts.push_back(sf::Vector2f(0.75f, 0.25f));
	pts.push_back(sf::Vector2f(0.25f, 0.25f));
	pts.push_back(sf::Vector2f(0.25f, 0.75f));
	pts.push_back(sf::Vector2f(0.75f ,0.75f));
	new Angler::Nodes::CollisionNode(getID() + 0x5000, mSchoolRoot, pts, 1);

	std::vector<sf::Vector2f> anim;
	anim.push_back(sf::Vector2f(0, mType * 50/651.0f));
	anim.push_back(sf::Vector2f(1/24.0f, mType * 50/651.0f));
	anim.push_back(sf::Vector2f(2/24.0f, mType * 50/651.0f));
	anim.push_back(sf::Vector2f(3/24.0f, mType * 50/651.0f));
	anim.push_back(sf::Vector2f(4/24.0f, mType * 50/651.0f));
	anim.push_back(sf::Vector2f(5/24.0f, mType * 50/651.0f));
	anim.push_back(sf::Vector2f(6/24.0f, mType * 50/651.0f));
	anim.push_back(sf::Vector2f(7/24.0f, mType * 50/651.0f));
	anim.push_back(sf::Vector2f(8/24.0f, mType * 50/651.0f));
	anim.push_back(sf::Vector2f(9/24.0f, mType * 50/651.0f));
	anim.push_back(sf::Vector2f(10/24.0f, mType * 50/651.0f));
	anim.push_back(sf::Vector2f(11/24.0f, mType * 50/651.0f));
	anim.push_back(sf::Vector2f(12/24.0f, mType * 50/651.0f));
	anim.push_back(sf::Vector2f(13/24.0f, mType * 50/651.0f));
	anim.push_back(sf::Vector2f(14/24.0f, mType * 50/651.0f));
	anim.push_back(sf::Vector2f(15/24.0f, mType * 50/651.0f));
	new Angler::Nodes::AnimatedNode(getID() + 0x1000, mSchoolRoot, 2, anim, 1/8.0f, 0, 0, 1/24.0f, 50/651.0f);
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

void School::scaredByBoat(sf::Vector2f shipPos, float deltaTime, bool fast)
{
	sf::Vector2f delta = getPosition();
	delta -= shipPos;

	if(!fast)
		move(delta.x/2.5*deltaTime, delta.y/2.5*deltaTime);
	else if(fast)
		move(delta.x/3*deltaTime, delta.y/3*deltaTime);
}

void School::update(Angler::Game *context, float time, float deltaTime, bool changed)
{
	if (!mPaused)
	{
		mChanged |= changed;
		
		mUpdateChildren(context, time, deltaTime);

		/*if(scaredDistance(((IshavsfiskeGame*)context)->getIceBreaker()->getPosition()))
			scaredByBoat(((IshavsfiskeGame*)context)->getIceBreaker()->getPosition(), deltaTime);
		if(scaredDistance(((IshavsfiskeGame*)context)->getShipFishing()->getPosition()))
			scaredByBoat(((IshavsfiskeGame*)context)->getShipFishing()->getPosition(), deltaTime);

		mUpdateChildren(context, time, deltaTime);*/
	}
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
	return DX * DX + DY * DY < 0.025;
}